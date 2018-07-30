#include "hl_configs.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <pthread.h>
#include "../cs6041/cs6041.h"

// Threads each of which will execute the XFP initialization function //
pthread_t thread[4];

void mxp_configuration(Muxponder mxp)
{
	txp_reset(); //40G module and register reset. Set the register in default value
	
	T41_t Chips;
	cs_uint16 dev_id = 0;
	cs_uint16 mod_a;
	cs_uint16 mod_b;
	cs_uint8 dyn_repro = 0; /* 0 = static, 1 = DR client only, 2 = DR line and client */
	int sysclk_freq;
	int sysrefclk = 400;
	cs_uint8 slice_line = 0;
	cs_uint8 slice_client = 0;

	int diagloop = 0;
	int laser40 = 0;
	int slice = 0;
	int prot = 0;

	sysclk_freq = sysrefclk * 1000000;

	hl_edfa_init(mxp.edfa_pout);
	
	cs6041_reset(); //cs6041 reset

	int iret[4];
	unsigned int xfp[4];
	unsigned int i;

	for (i = 0; i < 4; i++)
	{
		iret[i] = pthread_create(&thread[i], NULL, thread_function, &mxp);
		if (iret[i])
		{
			fprintf(stderr, "Error - pthread_create() return code: %d\n", iret[i]);
			exit(EXIT_FAILURE);
		}
	}

	/* Wait till threads are complete before continue  */
	for (i = 0; i < 4; i++)
	{
		pthread_join(thread[i], NULL);
	}

	for (slice_client = 0; slice_client < 4; slice_client++)
	{
		prot = mxp.slice_protocol[slice_client];

		dyn_repro = (slice_client == 0) ? 0 : 1;

		// Configure Cortina chip
		if ((dyn_repro == 0) || (dyn_repro == 3))
		{
			cs6041_init(dev_id, &Chips, &mod_a, &mod_b);
		}

		general_client_traffic_config_line_otu3(dev_id, mod_a, mod_b, slice_line, slice_client, sysclk_freq, dyn_repro, mxp);
	}

	cs6041_init_gcc_tx_rx(dev_id, mod_a, mxp.gcc);

	printf("Waiting 40G Module Reset. \n");
	while (txp_reset_time() != 1);

	hl_txp_set_tx_rx_laser_itu_channel(mxp.txp_channel);

	hl_txp_set_bulk_cd_compensation(mxp.txp_min_bulk_cd_comp, mxp.txp_max_bulk_cd_comp);

	hl_txp_config_40g_otu3(mxp.txp_line_loopback, mxp.txp_diagnostic_loopback, mxp.txp_laser_enable);

	if (mxp.fec_monitor)
	{
		cs6041_fecstats_init(2); // Initialize FEC statistics
	}

}

void *thread_function(void *value)
{
	int prot = 0;
	unsigned int i = 0;
	unsigned int slice_client = 0;
	for (i = 0; i < 4; i++)
	{
		if (thread[i] == pthread_self())
		{
			Muxponder mxp1 = *((Muxponder *) value);
			unsigned int j = 0;
			slice_client = i;
			hl_xfp_setup(slice_client, mxp1.xfp_loopback[slice_client], mxp1.slice_protocol[i]);
		}
	}
	return 0;
}

void mxp_reconfiguration(Muxponder mxp)
{

	T41_t Chips;
	cs_uint16 dev_id = 0;
	cs_uint16 mod_a;
	cs_uint16 mod_b;
	cs_uint8 dyn_repro = 0; /* 0 = static, 1 = DR client only, 2 = DR line and client */
	int sysclk_freq;
	int sysrefclk = 400;
	cs_uint8 slice_line = 0;
	cs_uint8 slice_client = 0;

	int diagloop = 0;
	int laser40 = 0;
	int slice = 0;
	int prot = 0;

	int iret[4];
	unsigned int xfp[4];
	unsigned int i;

	for (i = 0; i < 4; i++)
	{
		iret[i] = pthread_create(&thread[i], NULL, thread_function, &mxp);
		if (iret[i])
		{
			fprintf(stderr, "Error - pthread_create() return code: %d\n", iret[i]);
			exit(EXIT_FAILURE);
		}
	}

	/* Wait till threads are complete before continue  */
	for (i = 0; i < 4; i++)
	{
		pthread_join(thread[i], NULL);
	}

	sysclk_freq = sysrefclk * 1000000;

	for (slice_client = 0; slice_client < 4; slice_client++)
	{

		dyn_repro = (slice_client == 0) ? 0 : 1;

		// Configure Cortina chip
		if ((dyn_repro == 0) || (dyn_repro == 3))
		{
			cs6041_reset();
			cs6041_init(dev_id, &Chips, &mod_a, &mod_b);
		}

		general_client_traffic_config_line_otu3(dev_id, mod_a, mod_b, slice_line, slice_client, sysclk_freq, dyn_repro, mxp);
	}

	if (mxp.fec_monitor)
	{
		cs6041_fecstats_init(2); // Initialize FEC statistics
	}

}

void load_configuration_file(Muxponder *mxp)
{
	FILE *pFile;

	pFile = fopen("config.xml", "r");

	if (pFile == NULL)
	{
		printf("No initial configuration file found, a new file will be created with default configuration parameters.\n");
        // Load default data if the file doesn't exist and create it
		Muxponder mux;

		load_default_configuration_parameters(&mux);

		update_initial_configuration_file(mux);

		pFile = fopen("config.xml", "r");
	}

	// xml file load
	mxml_node_t *configuration_tree = mxmlLoadFile(NULL, pFile, MXML_TEXT_CALLBACK);

	// Main configuration node
	mxml_node_t *configuration_collection = mxmlGetFirstChild(configuration_tree);

	// first configuration module
	mxml_node_t *config_node;

	// search for config nodes
	for (config_node = mxmlGetFirstChild(configuration_collection); config_node != NULL; config_node = mxmlGetNextSibling(config_node))
	{
		load_configuration_data(mxp, config_node);
	}
}

void load_configuration_data(Muxponder *mxp, mxml_node_t *config_node)
{
	// first node of the tag
	mxml_node_t *current_node;

	// tag name
	char *config_tag = config_node->value.opaque;

	// index used for eth elements
	int i = 0;

	// Search for configuration parameters
	for (current_node = mxmlGetFirstChild(config_node); current_node != NULL; current_node = mxmlGetNextSibling(current_node))
	{
		if (strcmp(config_tag, "muxponder") == 0)
		{
			load_muxponder_configuration_data(mxp, current_node);
		}
		else if (strcmp(config_tag, "network") == 0)
		{
			// eth element load
			load_eth_parameters(&mxp->network[i], current_node);
			i++;
		}
	}
}

void load_muxponder_configuration_data(Muxponder *mxp, mxml_node_t *current_node)
{
	// get the name of the node
	char *node_name = current_node->value.opaque;

	if (strcmp(node_name, "trafico") == 0)
	{
		int traffic_type = atoi(mxmlGetText(current_node, 0));
		mxp->slice_protocol[0] = traffic_type;
		mxp->slice_protocol[1] = traffic_type;
		mxp->slice_protocol[2] = traffic_type;
		mxp->slice_protocol[3] = traffic_type;
	}
	else if (strcmp(node_name, "canal") == 0)
	{
		mxp->txp_channel = atoi(mxmlGetText(current_node, 0));
	}
	else if (strcmp(node_name, "potencia") == 0)
	{
		mxp->edfa_pout = atof(mxmlGetText(current_node, 0));
	}
	else if (strcmp(node_name, "min_cd_compensacion") == 0)
	{
		mxp->txp_min_bulk_cd_comp = atoi(mxmlGetText(current_node, 0));
	}
	else if (strcmp(node_name, "max_cd_compensacion") == 0)
	{
		mxp->txp_max_bulk_cd_comp = atoi(mxmlGetText(current_node, 0));
	}
	else if (strcmp(node_name, "fec") == 0)
	{
		mxp->cs6041_line_fec = atoi(mxmlGetText(current_node, 0));
	}
	else if (strcmp(node_name, "fec_cliente") == 0)
	{
		mxp->cs6041_client_fec = atoi(mxmlGetText(current_node, 0));
	}
	else if (strcmp(node_name, "canal_gcc") == 0)
	{
		mxp->gcc = atoi(mxmlGetText(current_node, 0));
	}

}

void load_eth_parameters(Network *network, mxml_node_t *network_eth)
{
	//network parameter
	mxml_node_t *network_parameter;

	// Search for configuration parameters
	for (network_parameter = mxmlGetFirstChild(network_eth); network_parameter != NULL; network_parameter = mxmlGetNextSibling(network_parameter))
	{
		char *parameter_name = network_parameter->value.opaque;

		if (strcmp(parameter_name, "auto") == 0)
		{
			network->eth_auto = atoi(mxmlGetText(network_parameter, 0));
		}
		else if (strcmp(parameter_name, "ip") == 0)
		{
			strcpy(network->ip, mxmlGetText(network_parameter, 0));
		}
		else if (strcmp(parameter_name, "netmask") == 0)
		{
			strcpy(network->netmask, mxmlGetText(network_parameter, 0));
		}
		else if (strcmp(parameter_name, "broadcast") == 0)
		{
			strcpy(network->broadcast, mxmlGetText(network_parameter, 0));
		}
		else if (strcmp(parameter_name, "gateway") == 0)
		{
			strcpy(network->gateway, mxmlGetText(network_parameter, 0));
		}
	}
}

void load_default_configuration_parameters(Muxponder *mxp)
{
	mxp->slice_protocol[0] = 0;
	mxp->slice_protocol[1] = 0;
	mxp->slice_protocol[2] = 0;
	mxp->slice_protocol[3] = 0;
	mxp->txp_min_bulk_cd_comp = 0;
	mxp->txp_max_bulk_cd_comp = 0;
	mxp->edfa_pout = 4;
	mxp->cs6041_line_fec = 14;
	mxp->txp_channel = 1;
	mxp->cs6041_client_fec = 16;
	mxp->gcc = 0;

	unsigned int i;
	for (i = 0; i < sizeof(mxp->network) / sizeof(mxp->network[0]); i++)
	{
		mxp->network[i].eth_auto = 1;
		strcpy(mxp->network[i].ip, "0.0.0.0");
		strcpy(mxp->network[i].netmask, "0.0.0.0");
		strcpy(mxp->network[i].broadcast, "0.0.0.0");
		strcpy(mxp->network[i].gateway, "0.0.0.0");
	}
}

void update_initial_configuration_file(Muxponder mxp)
{
	mxml_node_t *xml;
	mxml_node_t *configuration;

	// Configuration file pointer
	FILE *fp;
	fp = fopen("config.xml", "w");

	// creates the xml document
	xml = mxmlNewXML("1.0");

	// main node configuration
	configuration = mxmlNewElement(xml, "configuration");

	// Muxponder node
	mxml_node_t *muxponder = mxmlNewElement(configuration, "muxponder");

	// Network node
	mxml_node_t *network = mxmlNewElement(configuration, "network");

	mxml_node_t *node;

	// Muxponder
	node = mxmlNewElement(muxponder, "trafico");
	mxmlNewInteger(node, mxp.slice_protocol[0]);
	node = mxmlNewElement(muxponder, "canal");
	mxmlNewInteger(node, mxp.txp_channel);
	node = mxmlNewElement(muxponder, "potencia");
	mxmlNewReal(node, mxp.edfa_pout);
	node = mxmlNewElement(muxponder, "min_cd_compensacion");
	mxmlNewInteger(node, mxp.txp_min_bulk_cd_comp);
	node = mxmlNewElement(muxponder, "max_cd_compensacion");
	mxmlNewInteger(node, mxp.txp_max_bulk_cd_comp);
	node = mxmlNewElement(muxponder, "fec");
	mxmlNewInteger(node, mxp.cs6041_line_fec);
	node = mxmlNewElement(muxponder, "fec_cliente");
	mxmlNewInteger(node, mxp.cs6041_client_fec);
	node = mxmlNewElement(muxponder, "canal_gcc");
	mxmlNewInteger(node, mxp.gcc);

	// Network
	unsigned int j;
	for (j = 0; j < sizeof(mxp.network) / sizeof(mxp.network[0]); j++)
	{
		char eth_name[10] = "br";

		char number[5] =
		{ 0 };

		sprintf(number, "%d", j);

		strncat(eth_name, number, sizeof(number));

		// eth node
		mxml_node_t *eth = mxmlNewElement(network, eth_name);
		node = mxmlNewElement(eth, "auto");
		mxmlNewInteger(node, mxp.network[j].eth_auto);
		node = mxmlNewElement(eth, "ip");
		mxmlNewText(node, 0, mxp.network[j].ip);
		node = mxmlNewElement(eth, "netmask");
		mxmlNewText(node, 0, mxp.network[j].netmask);
		node = mxmlNewElement(eth, "broadcast");
		mxmlNewText(node, 0, mxp.network[j].broadcast);
		node = mxmlNewElement(eth, "gateway");
		mxmlNewText(node, 0, mxp.network[j].gateway);
	}

	// Save xml file
	mxmlSaveFile(xml, fp, MXML_NO_CALLBACK);
	fclose(fp);
}

void load_alarm_configuration(Monitor *monitor)
{
	FILE *fp;

	fp = fopen("alarms.xml", "r");

	// Checks if the alarm configuration file exists
	// Creates a new file if no file was found
	if (fp == NULL)
	{
		printf("No initial alarm configuration file found, a new file will be created with default configuration parameters.\n");

// Temporal monitor struct to create default alarm configuration file
		Monitor temp;

// Load default alarm configuration parameters
		load_default_alarm_configuration(&temp);

// Create default alarm configuration file
		update_alarm_configuration_file(temp);

		fp = fopen("alarms.xml", "r");
	}

	mxml_node_t *alarm_tree = mxmlLoadFile(NULL, fp, MXML_TEXT_CALLBACK);

	// alarm collection element
	mxml_node_t *alarm_collection = mxmlGetFirstChild(alarm_tree);

	// first module alarms
	mxml_node_t *module_alarms;

	// search for module alarms
	for (module_alarms = mxmlGetFirstChild(alarm_collection); module_alarms != NULL; module_alarms = mxmlGetNextSibling(module_alarms))
	{
		load_alarm_data(monitor, module_alarms);
	}

	fclose(fp);
}

void load_alarm_data(Monitor *monitor, mxml_node_t *module_alarms)
{
	// first node of the module
	mxml_node_t *current_node;

	// module name
	char *module = module_alarms->value.opaque;

	// Search for module alarms
	for (current_node = mxmlGetFirstChild(module_alarms); current_node != NULL; current_node = mxmlGetNextSibling(current_node))
	{
// get the name of the node
		char *node_name = current_node->value.opaque;

// Get the configuration value of the node
		unsigned int alarm_value;

		if (strcmp(module, "xfp") == 0)
		{
			hl_xfp_load_alarm_data(&monitor->xfp_struct, current_node);
		}
		else if (strcmp(module, "txp") == 0)
		{
			alarm_value = atoi(mxmlGetText(current_node, 0));

			hl_txp_load_alarm_data(&monitor->txp_struct, node_name, alarm_value);
		}
		else if (strcmp(module, "edfa") == 0)
		{
			alarm_value = atoi(mxmlGetText(current_node, 0));

			load_edfa_alarm_data(&monitor->edfa_struct, node_name, alarm_value);
		}
		else if (strcmp(module, "tp") == 0)
		{
			load_tp_alarm_data(&monitor->tp_defects_struct, current_node);
		}
	}
}

void load_tp_alarm_data(TP_defects *tp_defects_struct, mxml_node_t *current_tp_node)
{
	if (strcmp(current_tp_node->value.opaque, "line") == 0)
	{
		load_tp_line_alarm_data(tp_defects_struct, current_tp_node);
	}
	else if (strcmp(current_tp_node->value.opaque, "client") == 0)
	{
		load_tp_client_alarm_data(tp_defects_struct, current_tp_node);
	}
}

void load_tp_line_alarm_data(TP_defects *tp_defects_struct, mxml_node_t *current_tp_node)
{
	mxml_node_t *current_alarm;

	// Search for module alarms
	for (current_alarm = mxmlGetFirstChild(current_tp_node); current_alarm != NULL; current_alarm = mxmlGetNextSibling(current_alarm))
	{
// get the name of the alarm
		char *alarm_name = current_alarm->value.opaque;

// Get the configuration value of the alarm
		int alarm_value = atoi(mxmlGetText(current_alarm, 0));

		if (strcmp(alarm_name, "FramerFsmms") == 0)
		{
			tp_defects_struct->severity.severity_line.FramerFsmms = alarm_value;
		}
		if (strcmp(alarm_name, "FramerFsmmtrb1s") == 0)
		{
			tp_defects_struct->severity.severity_line.FramerFsmmtrb1s = alarm_value;
		}
		if (strcmp(alarm_name, "FramerFsmmtrb2s") == 0)
		{
			tp_defects_struct->severity.severity_line.FramerFsmmtrb2s = alarm_value;
		}
		if (strcmp(alarm_name, "FramerFsmmtrb3s") == 0)
		{
			tp_defects_struct->severity.severity_line.FramerFsmmtrb3s = alarm_value;
		}
		if (strcmp(alarm_name, "FramerSoof") == 0)
		{
			tp_defects_struct->severity.severity_line.FramerSoof = alarm_value;
		}
		if (strcmp(alarm_name, "FramerSlof") == 0)
		{
			tp_defects_struct->severity.severity_line.FramerSlof = alarm_value;
		}
		if (strcmp(alarm_name, "FramerSif") == 0)
		{
			tp_defects_struct->severity.severity_line.FramerSif = alarm_value;
		}
		if (strcmp(alarm_name, "FramerFst") == 0)
		{
			tp_defects_struct->severity.severity_line.FramerFst = alarm_value;
		}
		if (strcmp(alarm_name, "LosstatLosf") == 0)
		{
			tp_defects_struct->severity.severity_line.LosstatLosf = alarm_value;
		}
		if (strcmp(alarm_name, "PathmonAccstat") == 0)
		{
			tp_defects_struct->severity.severity_line.PathmonAccstat = alarm_value;
		}
		if (strcmp(alarm_name, "PathmonDais") == 0)
		{
			tp_defects_struct->severity.severity_line.PathmonDais = alarm_value;
		}
		if (strcmp(alarm_name, "PathmonDbdi") == 0)
		{
			tp_defects_struct->severity.severity_line.PathmonDbdi = alarm_value;
		}
		if (strcmp(alarm_name, "PathmonDlck") == 0)
		{
			tp_defects_struct->severity.severity_line.PathmonDlck = alarm_value;
		}
		if (strcmp(alarm_name, "PathmonMsiunst") == 0)
		{
			tp_defects_struct->severity.severity_line.PathmonMsiunst = alarm_value;
		}
		if (strcmp(alarm_name, "SecmonBipsfs") == 0)
		{
			tp_defects_struct->severity.severity_line.SecmonBipsfs = alarm_value;
		}
		if (strcmp(alarm_name, "SecmonDbdi") == 0)
		{
			tp_defects_struct->severity.severity_line.SecmonDbdi = alarm_value;
		}
		if (strcmp(alarm_name, "SecmonDiae") == 0)
		{
			tp_defects_struct->severity.severity_line.SecmonDiae = alarm_value;
		}
		if (strcmp(alarm_name, "SecmonBipsfs") == 0)
		{
			tp_defects_struct->severity.severity_line.SecmonFlom = alarm_value;
		}
		if (strcmp(alarm_name, "SecmonLom") == 0)
		{
			tp_defects_struct->severity.severity_line.SecmonLom = alarm_value;
		}
	}
}

void load_tp_client_alarm_data(TP_defects *tp_defects_struct, mxml_node_t *current_tp_node)
{
	mxml_node_t *current_client;

	// Search for clients
	for (current_client = mxmlGetFirstChild(current_tp_node); current_client != NULL; current_client = mxmlGetNextSibling(current_client))
	{
// get the number of the client
		char *client_number = current_client->value.opaque;

		int i = atoi(client_number);

		mxml_node_t *current_alarm;

// get alarms for the current client
		for (current_alarm = mxmlGetFirstChild(current_client); current_alarm != NULL; current_alarm = mxmlGetNextSibling(current_alarm))
		{
			// get the name of the alarm
			char *alarm_name = current_alarm->value.opaque;

			// Get the configuration value of the alarm
			int alarm_value = atoi(mxmlGetText(current_alarm, 0));

			if (strcmp(alarm_name, "FramerFsmms") == 0)
			{
				tp_defects_struct->severity.severity_client[i].FramerFsmms = alarm_value;
			}
			if (strcmp(alarm_name, "FramerFssusts") == 0)
			{
				tp_defects_struct->severity.severity_client[i].FramerFssusts = alarm_value;
			}
			if (strcmp(alarm_name, "FramerSoof") == 0)
			{
				tp_defects_struct->severity.severity_client[i].FramerSoof = alarm_value;
			}
			if (strcmp(alarm_name, "FramerSlof") == 0)
			{
				tp_defects_struct->severity.severity_client[i].FramerSlof = alarm_value;
			}
			if (strcmp(alarm_name, "FramerSif") == 0)
			{
				tp_defects_struct->severity.severity_client[i].FramerSif = alarm_value;
			}
			if (strcmp(alarm_name, "FramerFst") == 0)
			{
				tp_defects_struct->severity.severity_client[i].FramerFst = alarm_value;
			}
			if (strcmp(alarm_name, "LosstatLosf") == 0)
			{
				tp_defects_struct->severity.severity_client[i].LosstatLosf = alarm_value;
			}
			if (strcmp(alarm_name, "PathmonAccstat") == 0)
			{
				tp_defects_struct->severity.severity_client[i].PathmonAccstat = alarm_value;
			}
			if (strcmp(alarm_name, "PathmonDais") == 0)
			{
				tp_defects_struct->severity.severity_client[i].PathmonDais = alarm_value;
			}
			if (strcmp(alarm_name, "PathmonDbdi") == 0)
			{
				tp_defects_struct->severity.severity_client[i].PathmonDbdi = alarm_value;
			}
			if (strcmp(alarm_name, "PathmonDlck") == 0)
			{
				tp_defects_struct->severity.severity_client[i].PathmonDlck = alarm_value;
			}
			if (strcmp(alarm_name, "PathmonMsiunst") == 0)
			{
				tp_defects_struct->severity.severity_client[i].PathmonMsiunst = alarm_value;
			}
			if (strcmp(alarm_name, "SecmonBipsfs") == 0)
			{
				tp_defects_struct->severity.severity_client[i].SecmonBipsfs = alarm_value;
			}
			if (strcmp(alarm_name, "SecmonDbdi") == 0)
			{
				tp_defects_struct->severity.severity_client[i].SecmonDbdi = alarm_value;
			}
			if (strcmp(alarm_name, "SecmonDiae") == 0)
			{
				tp_defects_struct->severity.severity_client[i].SecmonDiae = alarm_value;
			}
			if (strcmp(alarm_name, "SecmonFlom") == 0)
			{
				tp_defects_struct->severity.severity_client[i].SecmonFlom = alarm_value;
			}
			if (strcmp(alarm_name, "SecmonLom") == 0)
			{
				tp_defects_struct->severity.severity_client[i].SecmonLom = alarm_value;
			}
		}
	}
}

void load_default_alarm_configuration(Monitor *monitor)
{
// Default txp alarm parameters
	hl_txp_load_default_alarms_parameters(&monitor->txp_struct);

// Default edfa alarm parameters
	load_default_edfa_alarms_parameters(&monitor->edfa_struct);

// Default xfp alarm parameters
	hl_xfp_load_default_alarms_parameters(&monitor->xfp_struct);

// Default tp alarm parameters
	load_default_tp_alarms_parameters(&monitor->tp_defects_struct);
}

void load_default_tp_alarms_parameters(TP_defects *tp_defects_struct)
{
	//Default line severity
	tp_defects_struct->severity.severity_line.FramerFsmms = 1;
	tp_defects_struct->severity.severity_line.FramerFsmmtrb1s = 1;
	tp_defects_struct->severity.severity_line.FramerFsmmtrb2s = 1;
	tp_defects_struct->severity.severity_line.FramerFsmmtrb3s = 1;
	tp_defects_struct->severity.severity_line.FramerSoof = 1;
	tp_defects_struct->severity.severity_line.FramerSlof = 1;
	tp_defects_struct->severity.severity_line.FramerSif = 1;
	tp_defects_struct->severity.severity_line.FramerFst = 1;
	tp_defects_struct->severity.severity_line.LosstatLosf = 1;
	tp_defects_struct->severity.severity_line.PathmonAccstat = 1;
	tp_defects_struct->severity.severity_line.PathmonDais = 1;
	tp_defects_struct->severity.severity_line.PathmonDbdi = 1;
	tp_defects_struct->severity.severity_line.PathmonDlck = 1;
	tp_defects_struct->severity.severity_line.PathmonMsiunst = 1;
	tp_defects_struct->severity.severity_line.SecmonBipsfs = 1;
	tp_defects_struct->severity.severity_line.SecmonDbdi = 1;
	tp_defects_struct->severity.severity_line.SecmonDiae = 1;
	tp_defects_struct->severity.severity_line.SecmonFlom = 1;
	tp_defects_struct->severity.severity_line.SecmonLom = 1;

	//Default client severity
	int i;
	for (i = 0; i < 4; i++)
	{
		tp_defects_struct->severity.severity_client[i].FramerFsmms = 1;
		tp_defects_struct->severity.severity_client[i].FramerFssusts = 1;
		tp_defects_struct->severity.severity_client[i].FramerSoof = 1;
		tp_defects_struct->severity.severity_client[i].FramerSlof = 1;
		tp_defects_struct->severity.severity_client[i].FramerSif = 1;
		tp_defects_struct->severity.severity_client[i].FramerFst = 1;
		tp_defects_struct->severity.severity_client[i].LosstatLosf = 1;
		tp_defects_struct->severity.severity_client[i].PathmonAccstat = 1;
		tp_defects_struct->severity.severity_client[i].PathmonDais = 1;
		tp_defects_struct->severity.severity_client[i].PathmonDbdi = 1;
		tp_defects_struct->severity.severity_client[i].PathmonDlck = 1;
		tp_defects_struct->severity.severity_client[i].PathmonMsiunst = 1;
		tp_defects_struct->severity.severity_client[i].SecmonBipsfs = 1;
		tp_defects_struct->severity.severity_client[i].SecmonDbdi = 1;
		tp_defects_struct->severity.severity_client[i].SecmonDiae = 1;
		tp_defects_struct->severity.severity_client[i].SecmonFlom = 1;
		tp_defects_struct->severity.severity_client[i].SecmonLom = 1;
	}
}

void update_alarm_configuration_file(Monitor monitor)
{
	mxml_node_t *xml;
	mxml_node_t *alarms;

	FILE *fp;
	fp = fopen("alarms.xml", "w");

// creates the xml document
	xml = mxmlNewXML("1.0");

// main node alarms
	alarms = mxmlNewElement(xml, "alarms");

// alarms of the txp module
	hl_txp_update_alarm_configuration(monitor.txp_struct, alarms);

// alarms of the txp module
	update_edfa_alarm_configuration(monitor.edfa_struct, alarms);

// alarms of the xfp module
	hl_xfp_update_alarm_configuration(monitor.xfp_struct, alarms);

// alarms of the tp module
	update_tp_alarm_configuration(monitor.tp_defects_struct, alarms);

// Save xml file
	mxmlSaveFile(xml, fp, MXML_NO_CALLBACK);
	fclose(fp);
}

void update_tp_alarm_configuration(TP_defects tp_defects_struct, mxml_node_t *alarms)
{
	mxml_node_t *tp = mxmlNewElement(alarms, "tp");

	// line
	mxml_node_t *tp_line = mxmlNewElement(tp, "line");

	mxml_node_t *node;
	node = mxmlNewElement(tp_line, "FramerFsmms");
	mxmlNewInteger(node, tp_defects_struct.severity.severity_line.FramerFsmms);
	node = mxmlNewElement(tp_line, "FramerFsmmtrb1s");
	mxmlNewInteger(node, tp_defects_struct.severity.severity_line.FramerFsmmtrb1s);
	node = mxmlNewElement(tp_line, "FramerFsmmtrb2s");
	mxmlNewInteger(node, tp_defects_struct.severity.severity_line.FramerFsmmtrb2s);
	node = mxmlNewElement(tp_line, "FramerFsmmtrb3s");
	mxmlNewInteger(node, tp_defects_struct.severity.severity_line.FramerFsmmtrb3s);
	node = mxmlNewElement(tp_line, "FramerSoof");
	mxmlNewInteger(node, tp_defects_struct.severity.severity_line.FramerSoof);
	node = mxmlNewElement(tp_line, "FramerSlof");
	mxmlNewInteger(node, tp_defects_struct.severity.severity_line.FramerSlof);
	node = mxmlNewElement(tp_line, "FramerSif");
	mxmlNewInteger(node, tp_defects_struct.severity.severity_line.FramerSif);
	node = mxmlNewElement(tp_line, "FramerFst");
	mxmlNewInteger(node, tp_defects_struct.severity.severity_line.FramerFst);
	node = mxmlNewElement(tp_line, "LosstatLosf");
	mxmlNewInteger(node, tp_defects_struct.severity.severity_line.LosstatLosf);
	node = mxmlNewElement(tp_line, "PathmonAccstat");
	mxmlNewInteger(node, tp_defects_struct.severity.severity_line.PathmonAccstat);
	node = mxmlNewElement(tp_line, "PathmonDais");
	mxmlNewInteger(node, tp_defects_struct.severity.severity_line.PathmonDais);
	node = mxmlNewElement(tp_line, "PathmonDbdi");
	mxmlNewInteger(node, tp_defects_struct.severity.severity_line.PathmonDbdi);
	node = mxmlNewElement(tp_line, "PathmonDlck");
	mxmlNewInteger(node, tp_defects_struct.severity.severity_line.PathmonDlck);
	node = mxmlNewElement(tp_line, "PathmonMsiunst");
	mxmlNewInteger(node, tp_defects_struct.severity.severity_line.PathmonMsiunst);
	node = mxmlNewElement(tp_line, "SecmonBipsfs");
	mxmlNewInteger(node, tp_defects_struct.severity.severity_line.SecmonBipsfs);
	node = mxmlNewElement(tp_line, "SecmonDbdi");
	mxmlNewInteger(node, tp_defects_struct.severity.severity_line.SecmonDbdi);
	node = mxmlNewElement(tp_line, "SecmonDiae");
	mxmlNewInteger(node, tp_defects_struct.severity.severity_line.SecmonDiae);
	node = mxmlNewElement(tp_line, "SecmonFlom");
	mxmlNewInteger(node, tp_defects_struct.severity.severity_line.SecmonFlom);
	node = mxmlNewElement(tp_line, "SecmonLom");
	mxmlNewInteger(node, tp_defects_struct.severity.severity_line.SecmonLom);

	//client
	mxml_node_t *tp_client = mxmlNewElement(tp, "client");

	int i;
	for (i = 0; i < 4; i++)
	{
		char client_number[5];
		sprintf(client_number, "%d", i);

		mxml_node_t *client = mxmlNewElement(tp_client, client_number);

		node = mxmlNewElement(client, "FramerFsmms");
		mxmlNewInteger(node, tp_defects_struct.severity.severity_client[i].FramerFsmms);
		node = mxmlNewElement(client, "FramerFssusts");
		mxmlNewInteger(node, tp_defects_struct.severity.severity_client[i].FramerFssusts);
		node = mxmlNewElement(client, "FramerSoof");
		mxmlNewInteger(node, tp_defects_struct.severity.severity_client[i].FramerSoof);
		node = mxmlNewElement(client, "FramerSlof");
		mxmlNewInteger(node, tp_defects_struct.severity.severity_client[i].FramerSlof);
		node = mxmlNewElement(client, "FramerSif");
		mxmlNewInteger(node, tp_defects_struct.severity.severity_client[i].FramerSif);
		node = mxmlNewElement(client, "FramerFst");
		mxmlNewInteger(node, tp_defects_struct.severity.severity_client[i].FramerFst);
		node = mxmlNewElement(client, "LosstatLosf");
		mxmlNewInteger(node, tp_defects_struct.severity.severity_client[i].LosstatLosf);
		node = mxmlNewElement(client, "PathmonAccstat");
		mxmlNewInteger(node, tp_defects_struct.severity.severity_client[i].PathmonAccstat);
		node = mxmlNewElement(client, "PathmonDais");
		mxmlNewInteger(node, tp_defects_struct.severity.severity_client[i].PathmonDais);
		node = mxmlNewElement(client, "PathmonDbdi");
		mxmlNewInteger(node, tp_defects_struct.severity.severity_client[i].PathmonDbdi);
		node = mxmlNewElement(client, "PathmonDlck");
		mxmlNewInteger(node, tp_defects_struct.severity.severity_client[i].PathmonDlck);
		node = mxmlNewElement(client, "PathmonMsiunst");
		mxmlNewInteger(node, tp_defects_struct.severity.severity_client[i].PathmonMsiunst);
		node = mxmlNewElement(client, "SecmonBipsfs");
		mxmlNewInteger(node, tp_defects_struct.severity.severity_client[i].SecmonBipsfs);
		node = mxmlNewElement(client, "SecmonDbdi");
		mxmlNewInteger(node, tp_defects_struct.severity.severity_client[i].SecmonDbdi);
		node = mxmlNewElement(client, "SecmonDiae");
		mxmlNewInteger(node, tp_defects_struct.severity.severity_client[i].SecmonDiae);
		node = mxmlNewElement(client, "SecmonFlom");
		mxmlNewInteger(node, tp_defects_struct.severity.severity_client[i].SecmonFlom);
		node = mxmlNewElement(client, "SecmonLom");
		mxmlNewInteger(node, tp_defects_struct.severity.severity_client[i].SecmonLom);
	}
}

void network_configuration(Muxponder mxp, int eth_port)
{

	char cmd_ifconfig[14];

	typedef struct ip_data
	{
		unsigned int eth_dhcp;
		char eth_ip[16];
		char eth_netmask[16];
		char eth_broadcast[16];
		char eth_gateway[16];
		char eth_port[4];

	} Ethernet_info;

	Ethernet_info info;

	char eth_command[20] = "ifconfig ";

	char port_number[5] = "br";

	char number[5] =
	{ 0 };

	sprintf(number, "%d", eth_port);

	strncat(port_number, number, sizeof(number));

	strcat(port_number, " ");

	strncat(eth_command, port_number, sizeof(port_number));

	strcpy(cmd_ifconfig, eth_command);
	info.eth_dhcp = mxp.network[eth_port].eth_auto;
	strcpy(info.eth_ip, mxp.network[eth_port].ip);
	strcpy(info.eth_netmask, mxp.network[eth_port].netmask);
	strcpy(info.eth_broadcast, mxp.network[eth_port].broadcast);
	strcpy(info.eth_gateway, mxp.network[eth_port].gateway);
	strcpy(info.eth_port, port_number);

// Set the network Configuration
	if (info.eth_dhcp == 1)
	{
		printf("%s DHCP on \n", info.eth_port);
		char cmd_autodhcp[16];
		strcpy(cmd_autodhcp, "dhclient ");
		strncat(cmd_autodhcp, info.eth_port, sizeof(info.eth_port));
		strcat(cmd_autodhcp, " &");
		system(cmd_autodhcp);
	}
	else if (info.eth_dhcp == 0)
	{
		char cmd[100];
		if (strcmp(info.eth_ip, "0.0.0.0") != 0)
		{
			strcpy(cmd, cmd_ifconfig);
			printf("%s IP : %s \n", info.eth_port, info.eth_ip);
			strncat(cmd, info.eth_ip, sizeof(info.eth_ip));
			system(cmd);
		}
		if (strcmp(info.eth_netmask, "0.0.0.0") != 0)
		{
			strcpy(cmd, cmd_ifconfig);
			strcat(cmd, "netmask ");
			strncat(cmd, info.eth_netmask, sizeof(info.eth_netmask));
			printf("%s netmask : %s \n", info.eth_port, info.eth_netmask);
			system(cmd);
		}
		if (strcmp(info.eth_broadcast, "0.0.0.0") != 0)
		{
			strcpy(cmd, cmd_ifconfig);
			strcat(cmd, "broadcast ");
			strncat(cmd, info.eth_broadcast, sizeof(info.eth_broadcast));
			printf("%s broadcast : %s \n", info.eth_port, info.eth_broadcast);
			system(cmd);
		}
		if (strcmp(info.eth_gateway, "0.0.0.0") != 0)
		{
			strcpy(cmd, "route add default gw ");
			strncat(cmd, info.eth_gateway, sizeof(info.eth_gateway));
			strcat(cmd, " ");
			strncat(cmd, info.eth_port, sizeof(info.eth_port));
			printf("%s gateway : %s \n", info.eth_port, info.eth_gateway);
			system(cmd);
		}
	}
}
