#include <net-snmp/net-snmp-config.h>
#include <net-snmp/net-snmp-includes.h>
#include <net-snmp/agent/net-snmp-agent-includes.h>

#include <stdio.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <stdlib.h>

#include "ftnc_notifications.h"

void shm_handler_create(Monitor *pt_monitor_struct);
Monitor *pt_monitor_struct;

/*
 * our initialization routine
 * (to get called, the function name must match init_FILENAME() 
 */
void init_ftnc_notifications(void)
{
   /*
    * LOAD MONITOR SHARED MEMORY
   */

   DEBUGMSGTL(("ftnc_notifications", "initializing (loading shared memory)\n"));

   shm_handler_create(pt_monitor_struct);

    DEBUGMSGTL(("ftnc_notifications", "initializing (setting callback alarm)\n"));

    /* ***************** EDFA function register ***************** */
    snmp_alarm_register(period, SA_REPEAT, send_edfaAmpStatusAlarm_notification, NULL);
    snmp_alarm_register(period, SA_REPEAT, send_edfaInputPowerAlarm_notification, NULL);
    snmp_alarm_register(period, SA_REPEAT, send_edfaLopAlarm_notification, NULL);
    snmp_alarm_register(period, SA_REPEAT, send_edfaLosAlarm_notification, NULL);
    snmp_alarm_register(period, SA_REPEAT, send_edfaOutputPowerAlarm_notification, NULL);
    snmp_alarm_register(period, SA_REPEAT, send_edfaTemperatureAlarm_notification, NULL);

    /* ***************** TXP function register ***************** */

    snmp_alarm_register(period, SA_REPEAT, send_txpEolAlarm_notification, NULL);
    snmp_alarm_register(period, SA_REPEAT, send_txpModTempAlarm_notification, NULL);
    snmp_alarm_register(period, SA_REPEAT, send_txpTxooaAlarm_notification, NULL);
    snmp_alarm_register(period, SA_REPEAT, send_txpTxLofAlarm_notification, NULL);
	snmp_alarm_register(period, SA_REPEAT, send_txpTxDscAlarm_notification, NULL);
	snmp_alarm_register(period, SA_REPEAT, send_txpLsWavAlarm_notification, NULL);
	snmp_alarm_register(period, SA_REPEAT, send_txpLsBiasAlarm_notification, NULL);
	snmp_alarm_register(period, SA_REPEAT, send_txpLsTempAlarm_notification, NULL);
	snmp_alarm_register(period, SA_REPEAT, send_txpTxLockAlarm_notification, NULL);
	snmp_alarm_register(period, SA_REPEAT, send_txpLsPowAlarm_notification, NULL);
	snmp_alarm_register(period, SA_REPEAT, send_txpModBiasAlarm_notification, NULL);
	snmp_alarm_register(period, SA_REPEAT, send_txpLatchedTxFifoAlarm_notification, NULL);
	snmp_alarm_register(period, SA_REPEAT, send_txpRxPowAlarm_notification, NULL);
	snmp_alarm_register(period, SA_REPEAT, send_txpRxLosAlarm_notification, NULL);
	snmp_alarm_register(period, SA_REPEAT, send_txpRxLockAlarm_notification, NULL);
	snmp_alarm_register(period, SA_REPEAT, send_txpRxsAlarm_notification, NULL);
	snmp_alarm_register(period, SA_REPEAT, send_txpPrbsErrAlarm_notification, NULL);
	snmp_alarm_register(period, SA_REPEAT, send_txpPsummaryAlarm_notification, NULL);
	snmp_alarm_register(period, SA_REPEAT, send_txpP5vAnalogAlarm_notification, NULL);
	snmp_alarm_register(period, SA_REPEAT, send_txpN5v2AnalogAlarm_notification, NULL);
	snmp_alarm_register(period, SA_REPEAT, send_txpP3p3vAnalogAlarm_notification, NULL);
	snmp_alarm_register(period, SA_REPEAT, send_txpP3p3vDigitalAlarm_notification, NULL);
	snmp_alarm_register(period, SA_REPEAT, send_txpLvDigitalAlarm_notification, NULL);
	snmp_alarm_register(period, SA_REPEAT, send_txpN5p2vDigitalAlarm_notification, NULL);

	/* ***************** XFP1 function register ***************** */
	snmp_alarm_register(period, SA_REPEAT, send_xfp1Presence_notification, NULL);
	snmp_alarm_register(period, SA_REPEAT, send_xfp1RxLoss_notification, NULL);
	snmp_alarm_register(period, SA_REPEAT, send_xfp1Ready_notification, NULL);
	snmp_alarm_register(period, SA_REPEAT, send_xfp1TxPower_notification, NULL);
	snmp_alarm_register(period, SA_REPEAT, send_xfp1RxPower_notification, NULL);
	snmp_alarm_register(period, SA_REPEAT, send_xfp1Temperature_notification, NULL);
	snmp_alarm_register(period, SA_REPEAT, send_xfp1LowTxPower_notification, NULL);
	snmp_alarm_register(period, SA_REPEAT, send_xfp1HighTxPower_notification, NULL);
	snmp_alarm_register(period, SA_REPEAT, send_xfp1LowRxPower_notification, NULL);
	snmp_alarm_register(period, SA_REPEAT, send_xfp1HighRxPower_notification, NULL);
	snmp_alarm_register(period, SA_REPEAT, send_xfp1RxCdrLOL_notification, NULL);
	snmp_alarm_register(period, SA_REPEAT, send_xfp1TxCdrLOL_notification, NULL);
	snmp_alarm_register(period, SA_REPEAT, send_xfp1LaserFault_notification, NULL);

	/* ***************** XFP2 function register ***************** */
    snmp_alarm_register(period, SA_REPEAT, send_xfp2Presence_notification, NULL);
	snmp_alarm_register(period, SA_REPEAT, send_xfp2RxLoss_notification, NULL);
	snmp_alarm_register(period, SA_REPEAT, send_xfp2Ready_notification, NULL);
	snmp_alarm_register(period, SA_REPEAT, send_xfp2TxPower_notification, NULL);
	snmp_alarm_register(period, SA_REPEAT, send_xfp2RxPower_notification, NULL);
	snmp_alarm_register(period, SA_REPEAT, send_xfp2Temperature_notification, NULL);
	snmp_alarm_register(period, SA_REPEAT, send_xfp2LowTxPower_notification, NULL);
	snmp_alarm_register(period, SA_REPEAT, send_xfp2HighTxPower_notification, NULL);
	snmp_alarm_register(period, SA_REPEAT, send_xfp2LowRxPower_notification, NULL);
	snmp_alarm_register(period, SA_REPEAT, send_xfp2HighRxPower_notification, NULL);
	snmp_alarm_register(period, SA_REPEAT, send_xfp2RxCdrLOL_notification, NULL);
	snmp_alarm_register(period, SA_REPEAT, send_xfp2TxCdrLOL_notification, NULL);
	snmp_alarm_register(period, SA_REPEAT, send_xfp2LaserFault_notification, NULL);

	/* ***************** XFP3 function register ***************** */
    snmp_alarm_register(period, SA_REPEAT, send_xfp3Presence_notification, NULL);
	snmp_alarm_register(period, SA_REPEAT, send_xfp3RxLoss_notification, NULL);
	snmp_alarm_register(period, SA_REPEAT, send_xfp3Ready_notification, NULL);
	snmp_alarm_register(period, SA_REPEAT, send_xfp3TxPower_notification, NULL);
	snmp_alarm_register(period, SA_REPEAT, send_xfp3RxPower_notification, NULL);
	snmp_alarm_register(period, SA_REPEAT, send_xfp3Temperature_notification, NULL);
	snmp_alarm_register(period, SA_REPEAT, send_xfp3LowTxPower_notification, NULL);
	snmp_alarm_register(period, SA_REPEAT, send_xfp3HighTxPower_notification, NULL);
	snmp_alarm_register(period, SA_REPEAT, send_xfp3LowRxPower_notification, NULL);
	snmp_alarm_register(period, SA_REPEAT, send_xfp3HighRxPower_notification, NULL);
	snmp_alarm_register(period, SA_REPEAT, send_xfp3RxCdrLOL_notification, NULL);
	snmp_alarm_register(period, SA_REPEAT, send_xfp3TxCdrLOL_notification, NULL);
	snmp_alarm_register(period, SA_REPEAT, send_xfp3LaserFault_notification, NULL);

	/* ***************** XFP4 function register ***************** */
    snmp_alarm_register(period, SA_REPEAT, send_xfp4Presence_notification, NULL);
	snmp_alarm_register(period, SA_REPEAT, send_xfp4RxLoss_notification, NULL);
	snmp_alarm_register(period, SA_REPEAT, send_xfp4Ready_notification, NULL);
	snmp_alarm_register(period, SA_REPEAT, send_xfp4TxPower_notification, NULL);
	snmp_alarm_register(period, SA_REPEAT, send_xfp4RxPower_notification, NULL);
	snmp_alarm_register(period, SA_REPEAT, send_xfp4Temperature_notification, NULL);
	snmp_alarm_register(period, SA_REPEAT, send_xfp4LowTxPower_notification, NULL);
	snmp_alarm_register(period, SA_REPEAT, send_xfp4HighTxPower_notification, NULL);
	snmp_alarm_register(period, SA_REPEAT, send_xfp4LowRxPower_notification, NULL);
	snmp_alarm_register(period, SA_REPEAT, send_xfp4HighRxPower_notification, NULL);
	snmp_alarm_register(period, SA_REPEAT, send_xfp4RxCdrLOL_notification, NULL);
	snmp_alarm_register(period, SA_REPEAT, send_xfp4TxCdrLOL_notification, NULL);
	snmp_alarm_register(period, SA_REPEAT, send_xfp4LaserFault_notification, NULL);

	/* ***************** TP function register ***************** */
	snmp_alarm_register(period, SA_REPEAT, send_tp_lineFramerFssmmtrb3s_notification, NULL);
	snmp_alarm_register(period, SA_REPEAT, send_tp_lineFramerFssmmtrb2s_notification, NULL);
	snmp_alarm_register(period, SA_REPEAT, send_tp_lineFramerFssmmtrb1s_notification, NULL);
	snmp_alarm_register(period, SA_REPEAT, send_tp_lineFramerFsmms_notification, NULL);
	snmp_alarm_register(period, SA_REPEAT, send_tp_lineFramerSif_notification, NULL);
	snmp_alarm_register(period, SA_REPEAT, send_tp_lineFramerSoof_notification, NULL);
	snmp_alarm_register(period, SA_REPEAT, send_tp_lineFramerSlof_notification, NULL);
	snmp_alarm_register(period, SA_REPEAT, send_tp_lineLosstatLosf_notification, NULL);
	snmp_alarm_register(period, SA_REPEAT, send_tp_lineSecmonFlom_notification, NULL);
	snmp_alarm_register(period, SA_REPEAT, send_tp_lineSecmonBipsfs_notification, NULL);
	snmp_alarm_register(period, SA_REPEAT, send_tp_lineSecmonDiae_notification, NULL);
	snmp_alarm_register(period, SA_REPEAT, send_tp_lineSecmonDbdi_notification, NULL);
	snmp_alarm_register(period, SA_REPEAT, send_tp_lineSecmonLom_notification, NULL);
	snmp_alarm_register(period, SA_REPEAT, send_tp_linePathmonAccstat_notification, NULL);
	snmp_alarm_register(period, SA_REPEAT, send_tp_linePathmonMsiunst_notification, NULL);
	snmp_alarm_register(period, SA_REPEAT, send_tp_linePathmonDais_notification, NULL);
	snmp_alarm_register(period, SA_REPEAT, send_tp_linePathmonDlck_notification, NULL);
	snmp_alarm_register(period, SA_REPEAT, send_tp_linePathmonDbdi_notification, NULL);

	snmp_alarm_register(period, SA_REPEAT, send_tp_client1FramerFsmms_notification, NULL);
	snmp_alarm_register(period, SA_REPEAT, send_tp_client1FramerFssusts_notification, NULL);
	snmp_alarm_register(period, SA_REPEAT, send_tp_client1FramerSif_notification, NULL);
	snmp_alarm_register(period, SA_REPEAT, send_tp_client1FramerSoof_notification, NULL);
	snmp_alarm_register(period, SA_REPEAT, send_tp_client1FramerSlof_notification, NULL);
	snmp_alarm_register(period, SA_REPEAT, send_tp_client1FramerFst_notification, NULL);
	snmp_alarm_register(period, SA_REPEAT, send_tp_client1LosstatLosf_notification, NULL);
	snmp_alarm_register(period, SA_REPEAT, send_tp_client1SecmonFlom_notification, NULL);
	snmp_alarm_register(period, SA_REPEAT, send_tp_client1SecmonBipsfs_notification, NULL);
	snmp_alarm_register(period, SA_REPEAT, send_tp_client1SecmonDiae_notification, NULL);
	snmp_alarm_register(period, SA_REPEAT, send_tp_client1SecmonDbdi_notification, NULL);
	snmp_alarm_register(period, SA_REPEAT, send_tp_client1SecmonLom_notification, NULL);
	snmp_alarm_register(period, SA_REPEAT, send_tp_client1PathmonAccstat_notification, NULL);
	snmp_alarm_register(period, SA_REPEAT, send_tp_client1PathmonMsiunst_notification, NULL);
	snmp_alarm_register(period, SA_REPEAT, send_tp_client1PathmonDais_notification, NULL);
	snmp_alarm_register(period, SA_REPEAT, send_tp_client1PathmonDlck_notification, NULL);
	snmp_alarm_register(period, SA_REPEAT, send_tp_client1PathmonDbdi_notification, NULL);

	snmp_alarm_register(period, SA_REPEAT, send_tp_client2FramerFsmms_notification, NULL);
	snmp_alarm_register(period, SA_REPEAT, send_tp_client2FramerFssusts_notification, NULL);
	snmp_alarm_register(period, SA_REPEAT, send_tp_client2FramerSif_notification, NULL);
	snmp_alarm_register(period, SA_REPEAT, send_tp_client2FramerSoof_notification, NULL);
	snmp_alarm_register(period, SA_REPEAT, send_tp_client2FramerSlof_notification, NULL);
	snmp_alarm_register(period, SA_REPEAT, send_tp_client2FramerFst_notification, NULL);
	snmp_alarm_register(period, SA_REPEAT, send_tp_client2LosstatLosf_notification, NULL);
	snmp_alarm_register(period, SA_REPEAT, send_tp_client2SecmonFlom_notification, NULL);
	snmp_alarm_register(period, SA_REPEAT, send_tp_client2SecmonBipsfs_notification, NULL);
	snmp_alarm_register(period, SA_REPEAT, send_tp_client2SecmonDiae_notification, NULL);
	snmp_alarm_register(period, SA_REPEAT, send_tp_client2SecmonDbdi_notification, NULL);
	snmp_alarm_register(period, SA_REPEAT, send_tp_client2SecmonLom_notification, NULL);
	snmp_alarm_register(period, SA_REPEAT, send_tp_client2PathmonAccstat_notification, NULL);
	snmp_alarm_register(period, SA_REPEAT, send_tp_client2PathmonMsiunst_notification, NULL);
	snmp_alarm_register(period, SA_REPEAT, send_tp_client2PathmonDais_notification, NULL);
	snmp_alarm_register(period, SA_REPEAT, send_tp_client2PathmonDlck_notification, NULL);
	snmp_alarm_register(period, SA_REPEAT, send_tp_client2PathmonDbdi_notification, NULL);

	snmp_alarm_register(period, SA_REPEAT, send_tp_client3FramerFsmms_notification, NULL);
	snmp_alarm_register(period, SA_REPEAT, send_tp_client3FramerFssusts_notification, NULL);
	snmp_alarm_register(period, SA_REPEAT, send_tp_client3FramerSif_notification, NULL);
	snmp_alarm_register(period, SA_REPEAT, send_tp_client3FramerSoof_notification, NULL);
	snmp_alarm_register(period, SA_REPEAT, send_tp_client3FramerSlof_notification, NULL);
	snmp_alarm_register(period, SA_REPEAT, send_tp_client3FramerFst_notification, NULL);
	snmp_alarm_register(period, SA_REPEAT, send_tp_client3LosstatLosf_notification, NULL);
	snmp_alarm_register(period, SA_REPEAT, send_tp_client3SecmonFlom_notification, NULL);
	snmp_alarm_register(period, SA_REPEAT, send_tp_client3SecmonBipsfs_notification, NULL);
	snmp_alarm_register(period, SA_REPEAT, send_tp_client3SecmonDiae_notification, NULL);
	snmp_alarm_register(period, SA_REPEAT, send_tp_client3SecmonDbdi_notification, NULL);
	snmp_alarm_register(period, SA_REPEAT, send_tp_client3SecmonLom_notification, NULL);
	snmp_alarm_register(period, SA_REPEAT, send_tp_client3PathmonAccstat_notification, NULL);
	snmp_alarm_register(period, SA_REPEAT, send_tp_client3PathmonMsiunst_notification, NULL);
	snmp_alarm_register(period, SA_REPEAT, send_tp_client3PathmonDais_notification, NULL);
	snmp_alarm_register(period, SA_REPEAT, send_tp_client3PathmonDlck_notification, NULL);
	snmp_alarm_register(period, SA_REPEAT, send_tp_client3PathmonDbdi_notification, NULL);

	snmp_alarm_register(period, SA_REPEAT, send_tp_client4FramerFsmms_notification, NULL);
	snmp_alarm_register(period, SA_REPEAT, send_tp_client4FramerFssusts_notification, NULL);
	snmp_alarm_register(period, SA_REPEAT, send_tp_client4FramerSif_notification, NULL);
	snmp_alarm_register(period, SA_REPEAT, send_tp_client4FramerSoof_notification, NULL);
	snmp_alarm_register(period, SA_REPEAT, send_tp_client4FramerSlof_notification, NULL);
	snmp_alarm_register(period, SA_REPEAT, send_tp_client4FramerFst_notification, NULL);
	snmp_alarm_register(period, SA_REPEAT, send_tp_client4LosstatLosf_notification, NULL);
	snmp_alarm_register(period, SA_REPEAT, send_tp_client4SecmonFlom_notification, NULL);
	snmp_alarm_register(period, SA_REPEAT, send_tp_client4SecmonBipsfs_notification, NULL);
	snmp_alarm_register(period, SA_REPEAT, send_tp_client4SecmonDiae_notification, NULL);
	snmp_alarm_register(period, SA_REPEAT, send_tp_client4SecmonDbdi_notification, NULL);
	snmp_alarm_register(period, SA_REPEAT, send_tp_client4SecmonLom_notification, NULL);
	snmp_alarm_register(period, SA_REPEAT, send_tp_client4PathmonAccstat_notification, NULL);
	snmp_alarm_register(period, SA_REPEAT, send_tp_client4PathmonMsiunst_notification, NULL);
	snmp_alarm_register(period, SA_REPEAT, send_tp_client4PathmonDais_notification, NULL);
	snmp_alarm_register(period, SA_REPEAT, send_tp_client4PathmonDlck_notification, NULL);
	snmp_alarm_register(period, SA_REPEAT, send_tp_client4PathmonDbdi_notification, NULL);
}

/* ***************** Implementation of EDFA methods ***************** */

void send_edfaAmpStatusAlarm_notification(unsigned int clientreg, void *clientarg)
{
	DEBUGMSGTL(("token", "send_edfaAmpStatusAlarm_notification.\n"));

   oid		notification_oid[] = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 2, 2, 0, 1 };
   size_t	notification_oid_len = OID_LENGTH(notification_oid);
   oid		objid_snmptrap[] = { 1, 3, 6, 1, 6, 3, 1, 1, 4, 1, 0 };
   size_t   objid_snmptrap_len = OID_LENGTH(objid_snmptrap);
   oid      edfaAmpStatusAlarm_oid[]   = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 2, 2, 1, 1, 1, 2 };
   size_t   edfaAmpStatusAlarm_oid_len = OID_LENGTH(edfaAmpStatusAlarm_oid);
   oid      edfaAmpStatusAlarmSev_oid[]   = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 3, 3, 1, 1, 2 };
   size_t   edfaAmpStatusAlarmSev_oid_len = OID_LENGTH(edfaAmpStatusAlarmSev_oid);

   netsnmp_variable_list *notification_vars = NULL;
   static u_long  edfaAmpStatusCount = 0;

   unsigned int edfaAmpStatusAlarm = 0;
   unsigned int send_edfaAmpStatusAlarm = 0;
   
   char edfaAmpStatus[100];
   strcpy (edfaAmpStatus, pt_monitor_struct->edfa_struct.edfa_amp_status);

   unsigned int edfaAmpStatusAlarmSev = 0;
   edfaAmpStatusAlarmSev = pt_monitor_struct->edfa_struct.severity.amp_status;

   if ((strcmp(edfaAmpStatusTemp, "OK") == 0) && (strcmp(edfaAmpStatus, "OK") != 0)){
      edfaAmpStatusAlarm = 1; send_edfaAmpStatusAlarm = 1;
   }
   else if ((strcmp(edfaAmpStatusTemp, "OK") != 0) && (strcmp(edfaAmpStatus, "OK") == 0)){
      edfaAmpStatusAlarm = 2; send_edfaAmpStatusAlarm = 1;
   }
   strcpy(edfaAmpStatusTemp, edfaAmpStatus);

   snmp_varlist_add_variable(&notification_vars, objid_snmptrap, objid_snmptrap_len, ASN_OBJECT_ID, (u_char *) notification_oid, notification_oid_len * sizeof(oid));
   snmp_varlist_add_variable(&notification_vars, edfaAmpStatusAlarm_oid, edfaAmpStatusAlarm_oid_len, ASN_INTEGER, (u_char *)&edfaAmpStatusAlarm, sizeof(edfaAmpStatusAlarm));
   snmp_varlist_add_variable(&notification_vars, edfaAmpStatusAlarmSev_oid, edfaAmpStatusAlarmSev_oid_len, ASN_INTEGER, (u_char *)&edfaAmpStatusAlarmSev, sizeof(edfaAmpStatusAlarmSev));

   if(send_edfaAmpStatusAlarm == 1)
   { 
       ++edfaAmpStatusCount;
       DEBUGMSGTL(("ftnc_notifications", "edfaAmpStatusCount sending trap %ld\n", edfaAmpStatusCount));
       send_v2trap(notification_vars);
   }

   snmp_free_varbind(notification_vars);
}
 
void send_edfaInputPowerAlarm_notification(unsigned int clientreg, void *clientarg)
{
	DEBUGMSGTL(("token", "send_edfaInputPowerAlarm_notification.\n"));

    oid      notification_oid[] = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 2, 2, 0, 2 };
    size_t   notification_oid_len = OID_LENGTH(notification_oid);
    oid      objid_snmptrap[] = { 1, 3, 6, 1, 6, 3, 1, 1, 4, 1, 0 };
    size_t   objid_snmptrap_len = OID_LENGTH(objid_snmptrap);
    oid      edfaInputPowerAlarm_oid[]   = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 2, 2, 1, 1, 1, 3 };
    size_t   edfaInputPowerAlarm_oid_len = OID_LENGTH(edfaInputPowerAlarm_oid);
    oid      edfaInputPowerAlarmSev_oid[]   = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 3, 3, 1, 1, 3 };
    size_t   edfaInputPowerAlarmSev_oid_len = OID_LENGTH(edfaInputPowerAlarmSev_oid);
 
    netsnmp_variable_list *notification_vars = NULL;
    static u_long edfaInputPowerCount = 0;

   unsigned int edfaInputPowerInt = 0;
   unsigned int edfaInputPowerAlarm = 0;
   unsigned int send_edfaInputPowerAlarm = 0;

   float edfaInputPower = 0.0;
   float edfaInputPowerMin = -8.0;
   float edfaInputPowerMax = 2.0;
   edfaInputPower = atof(pt_monitor_struct->edfa_struct.edfa_input_power);
   
   unsigned int edfaInputPowerAlarmSev = 0;
   edfaInputPowerAlarmSev = pt_monitor_struct->edfa_struct.severity.input_power;

   if (edfaInputPower < edfaInputPowerMin || edfaInputPower > edfaInputPowerMax)
   {
      edfaInputPowerInt = 1;}
   else {
      edfaInputPowerInt = 0;}
 
   if (edfaInputPowerTemp==0 && edfaInputPowerInt==1){
      edfaInputPowerAlarm = 1;
      send_edfaInputPowerAlarm = 1;
   }
   else if (edfaInputPowerTemp==1 && edfaInputPowerInt==0){
      edfaInputPowerAlarm = 2;
      send_edfaInputPowerAlarm = 1;
   }
   edfaInputPowerTemp = edfaInputPowerInt;

   snmp_varlist_add_variable(&notification_vars, objid_snmptrap, objid_snmptrap_len, ASN_OBJECT_ID, (u_char *) notification_oid, notification_oid_len * sizeof(oid));
   snmp_varlist_add_variable(&notification_vars, edfaInputPowerAlarm_oid, edfaInputPowerAlarm_oid_len, ASN_INTEGER, (u_char *)&edfaInputPowerAlarm, sizeof(edfaInputPowerAlarm));
   snmp_varlist_add_variable(&notification_vars, edfaInputPowerAlarmSev_oid, edfaInputPowerAlarmSev_oid_len, ASN_INTEGER, (u_char *)&edfaInputPowerAlarmSev, sizeof(edfaInputPowerAlarmSev));

    if(send_edfaInputPowerAlarm == 1)
    { 
       ++edfaInputPowerCount;
       DEBUGMSGTL(("ftnc_notifications", "edfaInputPowerCount sending trap %ld\n",edfaInputPowerCount));
       send_v2trap(notification_vars);
    }

    snmp_free_varbind(notification_vars);
} 

void send_edfaLopAlarm_notification(unsigned int clientreg, void *clientarg)
{
	DEBUGMSGTL(("token", "send_edfaLopAlarm_notification.\n"));

   oid      notification_oid[] = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 2, 2, 0, 3 };
   size_t   notification_oid_len = OID_LENGTH(notification_oid);
   oid      objid_snmptrap[] = { 1, 3, 6, 1, 6, 3, 1, 1, 4, 1, 0 };
   size_t   objid_snmptrap_len = OID_LENGTH(objid_snmptrap);
   oid      edfaLopAlarm_oid[]   = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 2, 2, 1, 1, 1, 4 };
   size_t   edfaLopAlarm_oid_len = OID_LENGTH(edfaLopAlarm_oid);
   oid      edfaLopAlarmSev_oid[]   = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 3, 3, 1, 1, 4 };
   size_t   edfaLopAlarmSev_oid_len = OID_LENGTH(edfaLopAlarmSev_oid);

   netsnmp_variable_list *notification_vars = NULL;
   static u_long  edfaLopCount = 0;

   unsigned int edfaLopAlarm = 0;
   unsigned int send_edfaLopAlarm = 0;

   char edfaLop[100];
   strcpy (edfaLop, pt_monitor_struct->edfa_struct.edfa_lop);
   
   unsigned int edfaLopAlarmSev = 0;
   edfaLopAlarmSev = pt_monitor_struct->edfa_struct.severity.lop;

   if ((strcmp(edfaLopTemp,"OFF")==0) && (strcmp(edfaLop,"ON")==0))
   {
      edfaLopAlarm = 1;
      send_edfaLopAlarm = 1;
   }
   else if ((strcmp(edfaLopTemp,"ON")==0) && (strcmp(edfaLop,"OFF")==0))
   {
      edfaLopAlarm = 2;
      send_edfaLopAlarm = 1;
   }
   strcpy (edfaLopTemp, edfaLop);

   snmp_varlist_add_variable(&notification_vars, objid_snmptrap, objid_snmptrap_len, ASN_OBJECT_ID, (u_char *) notification_oid, notification_oid_len * sizeof(oid));
   snmp_varlist_add_variable(&notification_vars, edfaLopAlarm_oid, edfaLopAlarm_oid_len, ASN_INTEGER, (u_char *)&edfaLopAlarm, sizeof(edfaLopAlarm));
   snmp_varlist_add_variable(&notification_vars, edfaLopAlarmSev_oid, edfaLopAlarmSev_oid_len, ASN_INTEGER, (u_char *)&edfaLopAlarmSev, sizeof(edfaLopAlarmSev));

   if(send_edfaLopAlarm == 1)
   { 
       ++edfaLopCount;
       DEBUGMSGTL(("ftnc_notifications", "edfaLopCount sending trap %ld\n",edfaLopCount));
       send_v2trap(notification_vars);
   }

   snmp_free_varbind(notification_vars);
}

void send_edfaLosAlarm_notification(unsigned int clientreg, void *clientarg)
{
	DEBUGMSGTL(("token", "send_edfaLosAlarm_notification.\n"));

   oid      notification_oid[] = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 2, 2, 0, 4 };
   size_t   notification_oid_len = OID_LENGTH(notification_oid);
   oid      objid_snmptrap[] = { 1, 3, 6, 1, 6, 3, 1, 1, 4, 1, 0 };
   size_t   objid_snmptrap_len = OID_LENGTH(objid_snmptrap);
   oid      edfaLosAlarm_oid[]   = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 2, 2, 1, 1, 1, 5 };
   size_t   edfaLosAlarm_oid_len = OID_LENGTH(edfaLosAlarm_oid);
   oid      edfaLosAlarmSev_oid[]   = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 3, 3, 1, 1, 5 };
   size_t   edfaLosAlarmSev_oid_len = OID_LENGTH(edfaLosAlarmSev_oid);

   netsnmp_variable_list *notification_vars = NULL;
   static u_long  edfaLosCount = 0;

   unsigned int edfaLosAlarm = 0;
   unsigned int send_edfaLosAlarm = 0;

   char edfaLos[100];
   strcpy (edfaLos, pt_monitor_struct->edfa_struct.edfa_los);

   unsigned int edfaLosAlarmSev = 0;
   edfaLosAlarmSev = pt_monitor_struct->edfa_struct.severity.los;

   if ((strcmp(edfaLosTemp,"OFF")==0) &&  (strcmp(edfaLos,"ON")==0))
   {
      edfaLosAlarm = 1;
      send_edfaLosAlarm = 1;
   }
   else if ((strcmp(edfaLosTemp,"ON")==0) &&  (strcmp(edfaLos,"OFF")==0))
   {
      edfaLosAlarm = 2;
      send_edfaLosAlarm = 1;
   }
   strcpy( edfaLosTemp, edfaLos);

   snmp_varlist_add_variable(&notification_vars, objid_snmptrap, objid_snmptrap_len, ASN_OBJECT_ID, (u_char *) notification_oid, notification_oid_len * sizeof(oid));
   snmp_varlist_add_variable(&notification_vars, edfaLosAlarm_oid, edfaLosAlarm_oid_len, ASN_INTEGER, (u_char *)&edfaLosAlarm, sizeof(edfaLosAlarm));
   snmp_varlist_add_variable(&notification_vars, edfaLosAlarmSev_oid, edfaLosAlarmSev_oid_len, ASN_INTEGER, (u_char *)&edfaLosAlarmSev, sizeof(edfaLosAlarmSev));

   if(send_edfaLosAlarm == 1)
   { 
       ++edfaLosCount;
       DEBUGMSGTL(("ftnc_notifications", "edfaLosCount sending trap %ld\n",edfaLosCount));
       send_v2trap(notification_vars);
   }

   snmp_free_varbind(notification_vars);
}

void send_edfaOutputPowerAlarm_notification(unsigned int clientreg, void *clientarg)
{
	DEBUGMSGTL(("token", "send_edfaOutputPowerAlarm_notification.\n"));

   oid      notification_oid[] =  { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 2, 2, 0, 5 };
   size_t   notification_oid_len = OID_LENGTH(notification_oid);
   oid      objid_snmptrap[] = { 1, 3, 6, 1, 6, 3, 1, 1, 4, 1, 0 };
   size_t   objid_snmptrap_len = OID_LENGTH(objid_snmptrap);
   oid      edfaOutputPowerAlarm_oid[]   = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 2, 2, 1, 1, 1, 6 };
   size_t   edfaOutputPowerAlarm_oid_len = OID_LENGTH(edfaOutputPowerAlarm_oid);
   oid      edfaOutputPowerAlarmSev_oid[]   = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 3, 3, 1, 1, 6 };
   size_t   edfaOutputPowerAlarmSev_oid_len = OID_LENGTH(edfaOutputPowerAlarmSev_oid);

   netsnmp_variable_list *notification_vars = NULL;
   static u_long  edfaOutputPowerCount = 0;

   unsigned int edfaOutputPowerInt = 0;
   unsigned int edfaOutputPowerAlarm = 0;
   unsigned int send_edfaOutputPowerAlarm = 0;

   float edfaOutputPower = 0.0;
   float edfaOutputPowerMin = 0.0;
   float edfaOutputPowerMax = 10.0;

   edfaOutputPower = atof(pt_monitor_struct->edfa_struct.edfa_output_power);

   unsigned int edfaOutputPowerAlarmSev = 0;
   edfaOutputPowerAlarmSev = pt_monitor_struct->edfa_struct.severity.output_power;

   if (edfaOutputPower < edfaOutputPowerMin || edfaOutputPower > edfaOutputPowerMax)
   {
	   edfaOutputPowerInt = 1;}
   else
   {
	   edfaOutputPowerInt = 0;}

   if (edfaOutputPowerTemp==0 && edfaOutputPowerInt==1) {
	   edfaOutputPowerAlarm = 1;
	   send_edfaOutputPowerAlarm = 1;
   }
   else if (edfaOutputPowerTemp==1 && edfaOutputPowerInt==0) {
	   edfaOutputPowerAlarm = 2;
	   send_edfaOutputPowerAlarm = 1;
   }
   edfaOutputPowerTemp = edfaOutputPowerInt;

   snmp_varlist_add_variable(&notification_vars, objid_snmptrap, objid_snmptrap_len, ASN_OBJECT_ID, (u_char *) notification_oid, notification_oid_len * sizeof(oid));
   snmp_varlist_add_variable(&notification_vars,  edfaOutputPowerAlarm_oid, edfaOutputPowerAlarm_oid_len, ASN_INTEGER, (u_char *)&edfaOutputPowerAlarm, sizeof(edfaOutputPowerAlarm));
   snmp_varlist_add_variable(&notification_vars, edfaOutputPowerAlarmSev_oid, edfaOutputPowerAlarmSev_oid_len, ASN_INTEGER, (u_char *)&edfaOutputPowerAlarmSev, sizeof(edfaOutputPowerAlarmSev));

   if(send_edfaOutputPowerAlarm == 1) {
       ++edfaOutputPowerCount;
       DEBUGMSGTL(("ftnc_notifications", "edfaOutputPowerCount sending trap %ld\n",edfaOutputPowerCount));
       send_v2trap(notification_vars);
   }

   snmp_free_varbind(notification_vars);
} 

void send_edfaTemperatureAlarm_notification(unsigned int clientreg, void *clientarg)
{
	DEBUGMSGTL(("token", "send_edfaTemperatureAlarm_notification.\n"));

   oid      notification_oid[] =  { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 2, 2, 0, 6 };
   size_t   notification_oid_len = OID_LENGTH(notification_oid);
   oid      objid_snmptrap[] = { 1, 3, 6, 1, 6, 3, 1, 1, 4, 1, 0 };
   size_t   objid_snmptrap_len = OID_LENGTH(objid_snmptrap);
   oid      edfaTemperatureAlarm_oid[]   = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 2, 2, 1, 1, 1, 7 };
   size_t   edfaTemperatureAlarm_oid_len = OID_LENGTH(edfaTemperatureAlarm_oid);
   oid      edfaTemperatureAlarmSev_oid[]   = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 3, 3, 1, 1, 7 };
   size_t   edfaTemperatureAlarmSev_oid_len = OID_LENGTH(edfaTemperatureAlarmSev_oid);

   netsnmp_variable_list *notification_vars = NULL;
   static u_long  edfaTemperatureCount = 0;

   unsigned int edfaTemperatureInt = 0;
   unsigned int edfaTemperatureAlarm = 0;
   unsigned int send_edfaTemperatureAlarm = 0;

   float edfaTemperature = 0.0;
   float edfaTemperatureMin = 2.0;
   float edfaTemperatureMax = 35.0;

   edfaTemperature = atof(pt_monitor_struct->edfa_struct.edfa_temperature);

   unsigned int edfaTemperatureAlarmSev = 0;
   edfaTemperatureAlarmSev = pt_monitor_struct->edfa_struct.severity.temperature;

   if (edfaTemperature < edfaTemperatureMin || edfaTemperature > edfaTemperatureMax)
   {
	   edfaTemperatureInt = 1;}
   else
   {
	   edfaTemperatureInt = 0;}

   if (edfaTemperatureTemp==0 && edfaTemperatureInt==1)
   {
      edfaTemperatureAlarm = 1;
      send_edfaTemperatureAlarm = 1;
   }
   else if (edfaTemperatureTemp==1 && edfaTemperatureInt==0)
   {
      edfaTemperatureAlarm = 2;
      send_edfaTemperatureAlarm = 1;
   }
   edfaTemperatureTemp = edfaTemperatureInt;

   snmp_varlist_add_variable(&notification_vars, objid_snmptrap, objid_snmptrap_len, ASN_OBJECT_ID, (u_char *) notification_oid, notification_oid_len * sizeof(oid));
   snmp_varlist_add_variable(&notification_vars,  edfaTemperatureAlarm_oid, edfaTemperatureAlarm_oid_len, ASN_INTEGER, (u_char *)&edfaTemperatureAlarm, sizeof(edfaTemperatureAlarm));
   snmp_varlist_add_variable(&notification_vars, edfaTemperatureAlarmSev_oid, edfaTemperatureAlarmSev_oid_len, ASN_INTEGER, (u_char *)&edfaTemperatureAlarmSev, sizeof(edfaTemperatureAlarmSev));

   if(send_edfaTemperatureAlarm == 1)
   { 
       ++edfaTemperatureCount;
       DEBUGMSGTL(("ftnc_notifications", "edfaTemperatureCount sending trap %ld\n",edfaTemperatureCount));
       send_v2trap(notification_vars);
   }

   snmp_free_varbind(notification_vars);
} 

/* ***************** Implementation of TXP methods ***************** */

void send_txpEolAlarm_notification(unsigned int clientreg, void *clientarg)
{
	DEBUGMSGTL(("token", "send_txpEolAlarm_notification.\n"));

   oid      notification_oid[] =  { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 2, 2, 0, 7 };
   size_t   notification_oid_len = OID_LENGTH(notification_oid);
   oid      objid_snmptrap[] = { 1, 3, 6, 1, 6, 3, 1, 1, 4, 1, 0 };
   size_t   objid_snmptrap_len = OID_LENGTH(objid_snmptrap);
   oid      txpEolAlarm_oid[]   = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 2, 2, 1, 2, 1, 2 };
   size_t   txpEolAlarm_oid_len = OID_LENGTH(txpEolAlarm_oid);
   oid      txpEolAlarmSev_oid[]   = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 3, 4, 1, 1, 2 };
   size_t   txpEolAlarmSev_oid_len = OID_LENGTH(txpEolAlarmSev_oid);

   netsnmp_variable_list *notification_vars = NULL;
   static u_long txpEolCount = 0;

   unsigned int txpEolAlarm = 0;
   unsigned int send_txpEolAlarm = 0;

   unsigned char txpEol[100];
   strcpy (txpEol, alarm_Alarm_no[pt_monitor_struct->txp_struct.txp_tx_alarm.fields.eolalm]);

   unsigned int txpEolAlarmSev = 0;
   txpEolAlarmSev = pt_monitor_struct->txp_struct.severity.eol;

   if ((strcmp(txpEolTemp, "--") == 0) && (strcmp(txpEol, "Alarm") == 0))
   {
      txpEolAlarm = 1;
      send_txpEolAlarm = 1;
   }
   else if ((strcmp(txpEolTemp, "Alarm") == 0) && (strcmp(txpEol, "--") == 0))
   {
      txpEolAlarm = 2;
      send_txpEolAlarm = 1;
   }

   strcpy(txpEolTemp, txpEol);

   snmp_varlist_add_variable(&notification_vars, objid_snmptrap, objid_snmptrap_len, ASN_OBJECT_ID, (u_char *) notification_oid, notification_oid_len * sizeof(oid));
   snmp_varlist_add_variable(&notification_vars,  txpEolAlarm_oid, txpEolAlarm_oid_len, ASN_INTEGER, (u_char *)&txpEolAlarm, sizeof(txpEolAlarm));
   snmp_varlist_add_variable(&notification_vars, txpEolAlarmSev_oid, txpEolAlarmSev_oid_len, ASN_INTEGER, (u_char *)&txpEolAlarmSev, sizeof(txpEolAlarmSev));

   if(send_txpEolAlarm == 1)
   {
       ++txpEolCount;
       DEBUGMSGTL(("ftnc_notifications", "txpEolCount sending trap %ld\n", txpEolCount));
       send_v2trap(notification_vars);
   }

   snmp_free_varbind(notification_vars);
}

void send_txpModTempAlarm_notification(unsigned int clientreg, void *clientarg)
{
	DEBUGMSGTL(("token", "send_txpModTempAlarm_notification.\n"));

   oid      notification_oid[] =  { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 2, 2, 0, 8 };
   size_t   notification_oid_len = OID_LENGTH(notification_oid);
   oid      objid_snmptrap[] = { 1, 3, 6, 1, 6, 3, 1, 1, 4, 1, 0 };
   size_t   objid_snmptrap_len = OID_LENGTH(objid_snmptrap);
   oid      txpModTempAlarm_oid[]   = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 2, 2, 1, 2, 1, 3 };
   size_t   txpModTempAlarm_oid_len = OID_LENGTH(txpModTempAlarm_oid);
   oid      txpModTempAlarmSev_oid[]   = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 3, 4, 1, 1, 3 };
   size_t   txpModTempAlarmSev_oid_len = OID_LENGTH(txpModTempAlarmSev_oid);

   netsnmp_variable_list *notification_vars = NULL;
   static u_long txpModTempCount = 0;

   unsigned int txpModTempAlarm = 0;
   unsigned int send_txpModTempAlarm = 0;

   unsigned char txpModTemp[100];
   strcpy(txpModTemp, alarm_Alarm_no[pt_monitor_struct->txp_struct.txp_tx_alarm.fields.modtempalm]);

   unsigned int txpModTempAlarmSev = 0;
   txpModTempAlarmSev = pt_monitor_struct->txp_struct.severity.mod_temp;

   if ((strcmp(txpModTempTemp, "--") == 0) && (strcmp(txpModTemp, "Alarm") == 0))
   {
      txpModTempAlarm = 1;
      send_txpModTempAlarm = 1;
   }
   else if ((strcmp(txpModTempTemp, "Alarm") == 0) && (strcmp(txpModTemp, "--") == 0))
   {
      txpModTempAlarm = 2;
      send_txpModTempAlarm = 1;
   }
   strcpy(txpModTempTemp, txpModTemp);

   snmp_varlist_add_variable(&notification_vars, objid_snmptrap, objid_snmptrap_len, ASN_OBJECT_ID, (u_char *) notification_oid, notification_oid_len * sizeof(oid));
   snmp_varlist_add_variable(&notification_vars,  txpModTempAlarm_oid, txpModTempAlarm_oid_len, ASN_INTEGER, (u_char *)&txpModTempAlarm, sizeof(txpModTempAlarm));
   snmp_varlist_add_variable(&notification_vars, txpModTempAlarmSev_oid, txpModTempAlarmSev_oid_len, ASN_INTEGER, (u_char *)&txpModTempAlarmSev, sizeof(txpModTempAlarmSev));

   if(send_txpModTempAlarm == 1)
   {
       ++txpModTempCount;
       DEBUGMSGTL(("ftnc_notifications", "txpModTempCount sending trap %ld\n", txpModTempCount));
       send_v2trap(notification_vars);
   }

   snmp_free_varbind(notification_vars);
}

void send_txpTxooaAlarm_notification(unsigned int clientreg, void *clientarg)
{
	DEBUGMSGTL(("token", "send_txpTxooaAlarm_notification.\n"));

   oid            notification_oid[] =  { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 2, 2, 0, 9 };
   size_t         notification_oid_len = OID_LENGTH(notification_oid);
   oid             objid_snmptrap[] = { 1, 3, 6, 1, 6, 3, 1, 1, 4, 1, 0 };
   size_t          objid_snmptrap_len = OID_LENGTH(objid_snmptrap);
   oid      txpTxooaAlarm_oid[]   = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 2, 2, 1, 2, 1, 4 };
   size_t   txpTxooaAlarm_oid_len = OID_LENGTH(txpTxooaAlarm_oid);
   oid      txpTxooaAlarmSev_oid[]   = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 3, 4, 1, 1, 4 };
   size_t   txpTxooaAlarmSev_oid_len = OID_LENGTH(txpTxooaAlarmSev_oid);

   netsnmp_variable_list *notification_vars = NULL;
   static u_long txpTxooaCount = 0;

   unsigned int txpTxooaAlarm = 0;
   unsigned int send_txpTxooaAlarm = 0;

   unsigned char txpTxooa[100];
   strcpy(txpTxooa, alarm_Alarm_no[pt_monitor_struct->txp_struct.txp_tx_alarm.fields.txooa]);

   unsigned int txpTxooaAlarmSev = 0;
   txpTxooaAlarmSev = pt_monitor_struct->txp_struct.severity.eol;

   if ((strcmp(txpTxooaTemp, "--") == 0) && (strcmp(txpTxooa, "Alarm") == 0))
   {
      txpTxooaAlarm = 1;
      send_txpTxooaAlarm = 1;
   }
   else if ((strcmp(txpTxooaTemp, "Alarm") == 0) && (strcmp(txpTxooa, "--") == 0))
   {
      txpTxooaAlarm = 2;
      send_txpTxooaAlarm = 1;
   }
   strcpy(txpTxooaTemp, txpTxooa);

   snmp_varlist_add_variable(&notification_vars, objid_snmptrap, objid_snmptrap_len, ASN_OBJECT_ID, (u_char *) notification_oid, notification_oid_len * sizeof(oid));
   snmp_varlist_add_variable(&notification_vars,  txpTxooaAlarm_oid, txpTxooaAlarm_oid_len, ASN_INTEGER, (u_char *)&txpTxooaAlarm, sizeof(txpTxooaAlarm));
   snmp_varlist_add_variable(&notification_vars, txpTxooaAlarmSev_oid, txpTxooaAlarmSev_oid_len, ASN_INTEGER, (u_char *)&txpTxooaAlarmSev, sizeof(txpTxooaAlarmSev));

   if(send_txpTxooaAlarm == 1)
   {
       ++txpTxooaCount;
       DEBUGMSGTL(("ftnc_notifications", "txpTxooaCount sending trap %ld\n", txpTxooaCount));
       send_v2trap(notification_vars);
   }

   snmp_free_varbind(notification_vars);
}

void send_txpTxLofAlarm_notification(unsigned int clientreg, void *clientarg)
{
	DEBUGMSGTL(("token", "send_txpTxLofAlarm_notification.\n"));

   oid      notification_oid[] =  { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 2, 2, 0, 10 };
   size_t   notification_oid_len = OID_LENGTH(notification_oid);
   oid      objid_snmptrap[] = { 1, 3, 6, 1, 6, 3, 1, 1, 4, 1, 0 };
   size_t   objid_snmptrap_len = OID_LENGTH(objid_snmptrap);
   oid      txpTxLofAlarm_oid[]   = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 2, 2, 1, 2, 1, 5 };
   size_t   txpTxLofAlarm_oid_len = OID_LENGTH(txpTxLofAlarm_oid);
   oid      txpTxLofAlarmSev_oid[]   = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 3, 4, 1, 1, 5 };
   size_t   txpTxLofAlarmSev_oid_len = OID_LENGTH(txpTxLofAlarmSev_oid);

   netsnmp_variable_list *notification_vars = NULL;
   static u_long txpTxLofCount = 0;

   unsigned int txpTxLofAlarm = 0;
   unsigned int send_txpTxLofAlarm = 0;

   unsigned char txpTxLof[100];
   strcpy(txpTxLof, alarm_Alarm_no[pt_monitor_struct->txp_struct.txp_tx_alarm.fields.txlofalm]);

   unsigned int txpTxLofAlarmSev = 0;
   txpTxLofAlarmSev = pt_monitor_struct->txp_struct.severity.tx_lof;

   if ((strcmp(txpTxLofTemp, "--") == 0) && (strcmp(txpTxLof, "Alarm") == 0))
   {
      txpTxLofAlarm = 1;
      send_txpTxLofAlarm = 1;
   }
   else if ((strcmp(txpTxLofTemp, "Alarm") == 0) && (strcmp(txpTxLof, "--") == 0))
   {
      txpTxLofAlarm = 2;
      send_txpTxLofAlarm = 1;
   }
   strcpy(txpTxLofTemp, txpTxLof);

   snmp_varlist_add_variable(&notification_vars, objid_snmptrap, objid_snmptrap_len, ASN_OBJECT_ID, (u_char *) notification_oid, notification_oid_len * sizeof(oid));
   snmp_varlist_add_variable(&notification_vars,  txpTxLofAlarm_oid, txpTxLofAlarm_oid_len, ASN_INTEGER, (u_char *)&txpTxLofAlarm, sizeof(txpTxLofAlarm));
   snmp_varlist_add_variable(&notification_vars, txpTxLofAlarmSev_oid, txpTxLofAlarmSev_oid_len, ASN_INTEGER, (u_char *)&txpTxLofAlarmSev, sizeof(txpTxLofAlarmSev));

   if(send_txpTxLofAlarm == 1)
   {
       ++txpTxLofCount;
       DEBUGMSGTL(("ftnc_notifications", "txpTxLofCount sending trap %ld\n", txpTxLofCount));
       send_v2trap(notification_vars);
   }
   snmp_free_varbind(notification_vars);
}

void send_txpTxDscAlarm_notification(unsigned int clientreg, void *clientarg)
{
	DEBUGMSGTL(("token", "send_txpTxDscAlarm_notification.\n"));

   oid      notification_oid[] =  { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 2, 2, 0, 11 };
   size_t   notification_oid_len = OID_LENGTH(notification_oid);
   oid      objid_snmptrap[] = { 1, 3, 6, 1, 6, 3, 1, 1, 4, 1, 0 };
   size_t   objid_snmptrap_len = OID_LENGTH(objid_snmptrap);
   oid      txpTxDscAlarm_oid[]   = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 2, 2, 1, 2, 1, 6 };
   size_t   txpTxDscAlarm_oid_len = OID_LENGTH(txpTxDscAlarm_oid);
   oid      txpTxDscAlarmSev_oid[]   = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 3, 4, 1, 1, 6 };
   size_t   txpTxDscAlarmSev_oid_len = OID_LENGTH(txpTxDscAlarmSev_oid);

   netsnmp_variable_list *notification_vars = NULL;
   static u_long txpTxDscCount = 0;

   unsigned int txpTxDscAlarm = 0;
   unsigned int send_txpTxDscAlarm = 0;

   unsigned char txpTxDsc[100];
   strcpy(txpTxDsc, alarm_Alarm_no[pt_monitor_struct->txp_struct.txp_tx_alarm.fields.txdscerr]);

   unsigned int txpTxDscAlarmSev = 0;
   txpTxDscAlarmSev = pt_monitor_struct->txp_struct.severity.tx_dsc;

   if ((strcmp(txpTxDscTemp, "--") == 0) && (strcmp(txpTxDsc, "Alarm") == 0))
   {
      txpTxDscAlarm = 1;
      send_txpTxDscAlarm = 1;
   }
   else if ((strcmp(txpTxDscTemp, "Alarm") == 0) && (strcmp(txpTxDsc, "--") == 0))
   {
      txpTxDscAlarm = 2;
      send_txpTxDscAlarm = 1;
   }
   strcpy(txpTxDscTemp, txpTxDsc);

   snmp_varlist_add_variable(&notification_vars, objid_snmptrap, objid_snmptrap_len, ASN_OBJECT_ID, (u_char *) notification_oid, notification_oid_len * sizeof(oid));
   snmp_varlist_add_variable(&notification_vars,  txpTxDscAlarm_oid, txpTxDscAlarm_oid_len, ASN_INTEGER, (u_char *)&txpTxDscAlarm, sizeof(txpTxDscAlarm));
   snmp_varlist_add_variable(&notification_vars, txpTxDscAlarmSev_oid, txpTxDscAlarmSev_oid_len, ASN_INTEGER, (u_char *)&txpTxDscAlarmSev, sizeof(txpTxDscAlarmSev));

   if(send_txpTxDscAlarm == 1)
   {
       ++txpTxDscCount;
       DEBUGMSGTL(("ftnc_notifications", "txpTxDscCount sending trap %ld\n", txpTxDscCount));
       send_v2trap(notification_vars);
   }

   snmp_free_varbind(notification_vars);
}

void send_txpLsWavAlarm_notification(unsigned int clientreg, void *clientarg)
{
	DEBUGMSGTL(("token", "send_txpLsWavAlarm_notification.\n"));

   oid      notification_oid[] =  { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 2, 2, 0, 12 };
   size_t   notification_oid_len = OID_LENGTH(notification_oid);
   oid      objid_snmptrap[] = { 1, 3, 6, 1, 6, 3, 1, 1, 4, 1, 0 };
   size_t   objid_snmptrap_len = OID_LENGTH(objid_snmptrap);
   oid      txpLsWavAlarm_oid[]   = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 2, 2, 1, 2, 1, 7 };
   size_t   txpLsWavAlarm_oid_len = OID_LENGTH(txpLsWavAlarm_oid);
   oid      txpLsWavAlarmSev_oid[]   = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 3, 4, 1, 1, 7 };
   size_t   txpLsWavAlarmSev_oid_len = OID_LENGTH(txpLsWavAlarmSev_oid);

   netsnmp_variable_list *notification_vars = NULL;
   static u_long txpLsWavCount = 0;

   unsigned int txpLsWavAlarm = 0;
   unsigned int send_txpLsWavAlarm = 0;

   unsigned char txpLsWav[100];
   strcpy(txpLsWav, alarm_Alarm_no[pt_monitor_struct->txp_struct.txp_tx_alarm.fields.lswavalm]);

   unsigned int txpLsWavAlarmSev = 0;
   txpLsWavAlarmSev = pt_monitor_struct->txp_struct.severity.ls_wav;

   if ((strcmp(txpLsWavTemp, "--") == 0) && (strcmp(txpLsWav, "Alarm") == 0))
   {
      txpLsWavAlarm = 1;
      send_txpLsWavAlarm = 1;
   }
   else if ((strcmp(txpLsWavTemp, "Alarm") == 0) && (strcmp(txpLsWav, "--") == 0))
   {
      txpLsWavAlarm = 2;
      send_txpLsWavAlarm = 1;
   }
   strcpy(txpLsWavTemp, txpLsWav);

   snmp_varlist_add_variable(&notification_vars, objid_snmptrap, objid_snmptrap_len, ASN_OBJECT_ID, (u_char *) notification_oid, notification_oid_len * sizeof(oid));
   snmp_varlist_add_variable(&notification_vars,  txpLsWavAlarm_oid, txpLsWavAlarm_oid_len, ASN_INTEGER, (u_char *)&txpLsWavAlarm, sizeof(txpLsWavAlarm));
   snmp_varlist_add_variable(&notification_vars, txpLsWavAlarmSev_oid, txpLsWavAlarmSev_oid_len, ASN_INTEGER, (u_char *)&txpLsWavAlarmSev, sizeof(txpLsWavAlarmSev));

   if(send_txpLsWavAlarm == 1)
   {
       ++txpLsWavCount;
       DEBUGMSGTL(("ftnc_notifications", "txpLsWavCount sending trap %ld\n", txpLsWavCount));
       send_v2trap(notification_vars);
   }

   snmp_free_varbind(notification_vars);
}

void send_txpLsBiasAlarm_notification(unsigned int clientreg, void *clientarg)
{
	DEBUGMSGTL(("token", "send_txpLsBiasAlarm_notification.\n"));

   oid      notification_oid[] =  { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 2, 2, 0, 13 };
   size_t   notification_oid_len = OID_LENGTH(notification_oid);
   oid      objid_snmptrap[] = { 1, 3, 6, 1, 6, 3, 1, 1, 4, 1, 0 };
   size_t   objid_snmptrap_len = OID_LENGTH(objid_snmptrap);
   oid      txpLsBiasAlarm_oid[]   = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 2, 2, 1, 2, 1, 8 };
   size_t   txpLsBiasAlarm_oid_len = OID_LENGTH(txpLsBiasAlarm_oid);
   oid      txpLsBiasAlarmSev_oid[]   = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 3, 4, 1, 1, 8 };
   size_t   txpLsBiasAlarmSev_oid_len = OID_LENGTH(txpLsBiasAlarmSev_oid);

   netsnmp_variable_list *notification_vars = NULL;
   static u_long txpLsBiasCount = 0;

   unsigned int txpLsBiasAlarm = 0;
   unsigned int send_txpLsBiasAlarm = 0;

   unsigned char txpLsBias[100];
   strcpy(txpLsBias, alarm_Alarm_no[pt_monitor_struct->txp_struct.txp_tx_alarm.fields.lsbiasalm]);

   unsigned int txpLsBiasAlarmSev = 0;
   txpLsBiasAlarmSev = pt_monitor_struct->txp_struct.severity.ls_bias;

   if ((strcmp(txpLsBiasTemp, "--") == 0) && (strcmp(txpLsBias, "Alarm") == 0))
   {
      txpLsBiasAlarm = 1;
      send_txpLsBiasAlarm = 1;
   }
   else if ((strcmp(txpLsBiasTemp, "Alarm") == 0) && (strcmp(txpLsBias, "--") == 0))
   {
      txpLsBiasAlarm = 2;
      send_txpLsBiasAlarm = 1;
   }
   strcpy(txpLsBiasTemp, txpLsBias);

   snmp_varlist_add_variable(&notification_vars, objid_snmptrap, objid_snmptrap_len, ASN_OBJECT_ID, (u_char *) notification_oid, notification_oid_len * sizeof(oid));
   snmp_varlist_add_variable(&notification_vars,  txpLsBiasAlarm_oid, txpLsBiasAlarm_oid_len, ASN_INTEGER, (u_char *)&txpLsBiasAlarm, sizeof(txpLsBiasAlarm));
   snmp_varlist_add_variable(&notification_vars, txpLsBiasAlarmSev_oid, txpLsBiasAlarmSev_oid_len, ASN_INTEGER, (u_char *)&txpLsBiasAlarmSev, sizeof(txpLsBiasAlarmSev));

   if(send_txpLsBiasAlarm == 1)
   {
       ++txpLsBiasCount;
       DEBUGMSGTL(("ftnc_notifications", "txpLsBiasCount sending trap %ld\n", txpLsBiasCount));
       send_v2trap(notification_vars);
   }

   snmp_free_varbind(notification_vars);
}

void send_txpLsTempAlarm_notification(unsigned int clientreg, void *clientarg)
{
	DEBUGMSGTL(("token", "send_txpLsTempAlarm_notification.\n"));

   oid      notification_oid[] =  { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 2, 2, 0, 14 };
   size_t   notification_oid_len = OID_LENGTH(notification_oid);
   oid      objid_snmptrap[] = { 1, 3, 6, 1, 6, 3, 1, 1, 4, 1, 0 };
   size_t   objid_snmptrap_len = OID_LENGTH(objid_snmptrap);
   oid      txpLsTempAlarm_oid[]   = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 2, 2, 1, 2, 1, 9 };
   size_t   txpLsTempAlarm_oid_len = OID_LENGTH(txpLsTempAlarm_oid);
   oid      txpLsTempAlarmSev_oid[]   = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 3, 4, 1, 1, 9 };
   size_t   txpLsTempAlarmSev_oid_len = OID_LENGTH(txpLsTempAlarmSev_oid);

   netsnmp_variable_list *notification_vars = NULL;
   static u_long txpLsTempCount = 0;

   unsigned int txpLsTempAlarm = 0;
   unsigned int send_txpLsTempAlarm = 0;

   unsigned char txpLsTemp[100];
   strcpy(txpLsTemp, alarm_Alarm_no[pt_monitor_struct->txp_struct.txp_tx_alarm.fields.lstempalm]);

   unsigned int txpLsTempAlarmSev = 0;
   txpLsTempAlarmSev = pt_monitor_struct->txp_struct.severity.ls_temp;

   if ((strcmp(txpLsTempTemp, "--") == 0) && (strcmp(txpLsTemp, "Alarm") == 0))
   {
      txpLsTempAlarm = 1;
      send_txpLsTempAlarm = 1;
   }
   else if ((strcmp(txpLsTempTemp, "Alarm") == 0) && (strcmp(txpLsTemp, "--") == 0))
   {
      txpLsTempAlarm = 2;
      send_txpLsTempAlarm = 1;
   }
   strcpy(txpLsTempTemp, txpLsTemp);

   snmp_varlist_add_variable(&notification_vars, objid_snmptrap, objid_snmptrap_len, ASN_OBJECT_ID, (u_char *) notification_oid, notification_oid_len * sizeof(oid));
   snmp_varlist_add_variable(&notification_vars,  txpLsTempAlarm_oid, txpLsTempAlarm_oid_len, ASN_INTEGER, (u_char *)&txpLsTempAlarm, sizeof(txpLsTempAlarm));
   snmp_varlist_add_variable(&notification_vars, txpLsTempAlarmSev_oid, txpLsTempAlarmSev_oid_len, ASN_INTEGER, (u_char *)&txpLsTempAlarmSev, sizeof(txpLsTempAlarmSev));

   if(send_txpLsTempAlarm == 1)
   {
       ++txpLsTempCount;
       DEBUGMSGTL(("ftnc_notifications", "txpLsTempCount sending trap %ld\n", txpLsTempCount));
       send_v2trap(notification_vars);
   }

   snmp_free_varbind(notification_vars);
}

void send_txpTxLockAlarm_notification(unsigned int clientreg, void *clientarg)
{
	DEBUGMSGTL(("token", "send_txpTxLockAlarm_notification."));

   oid      notification_oid[] =  { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 2, 2, 0, 15 };
   size_t   notification_oid_len = OID_LENGTH(notification_oid);
   oid      objid_snmptrap[] = { 1, 3, 6, 1, 6, 3, 1, 1, 4, 1, 0 };
   size_t   objid_snmptrap_len = OID_LENGTH(objid_snmptrap);
   oid      txpTxLockAlarm_oid[]   = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 2, 2, 1, 2, 1, 10 };
   size_t   txpTxLockAlarm_oid_len = OID_LENGTH(txpTxLockAlarm_oid);
   oid      txpTxLockAlarmSev_oid[]   = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 3, 4, 1, 1, 10 };
   size_t   txpTxLockAlarmSev_oid_len = OID_LENGTH(txpTxLockAlarmSev_oid);

   netsnmp_variable_list *notification_vars = NULL;
   static u_long txpTxLockCount = 0;

   unsigned int txpTxLockAlarm = 0;
   unsigned int send_txpTxLockAlarm = 0;

   unsigned char txpTxLock[100];
   strcpy(txpTxLock, alarm_Alarm_no[pt_monitor_struct->txp_struct.txp_tx_alarm.fields.txlockerr]);

   unsigned int txpTxLockAlarmSev = 0;
   txpTxLockAlarmSev = pt_monitor_struct->txp_struct.severity.tx_lock;

   if ((strcmp(txpTxLockTemp, "--") == 0) && (strcmp(txpTxLock, "Alarm") == 0))
   {
      txpTxLockAlarm = 1;
      send_txpTxLockAlarm = 1;
   }
   else if ((strcmp(txpTxLockTemp, "Alarm") == 0) && (strcmp(txpTxLock, "--") == 0))
   {
      txpTxLockAlarm = 2;
      send_txpTxLockAlarm = 1;
   }
   strcpy(txpTxLockTemp, txpTxLock);

   snmp_varlist_add_variable(&notification_vars, objid_snmptrap, objid_snmptrap_len, ASN_OBJECT_ID, (u_char *) notification_oid, notification_oid_len * sizeof(oid));
   snmp_varlist_add_variable(&notification_vars,  txpTxLockAlarm_oid, txpTxLockAlarm_oid_len, ASN_INTEGER, (u_char *)&txpTxLockAlarm, sizeof(txpTxLockAlarm));
   snmp_varlist_add_variable(&notification_vars, txpTxLockAlarmSev_oid, txpTxLockAlarmSev_oid_len, ASN_INTEGER, (u_char *)&txpTxLockAlarmSev, sizeof(txpTxLockAlarmSev));

   if(send_txpTxLockAlarm == 1)
   {
       ++txpTxLockCount;
       DEBUGMSGTL(("ftnc_notifications", "txpTxLockCount sending trap %ld\n", txpTxLockCount));
       send_v2trap(notification_vars);
   }

   snmp_free_varbind(notification_vars);
}

void send_txpLsPowAlarm_notification(unsigned int clientreg, void *clientarg)
{
	DEBUGMSGTL(("token", "send_txpLsPowAlarm_notification.\n"));

   oid      notification_oid[] =  { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 2, 2, 0, 16 };
   size_t   notification_oid_len = OID_LENGTH(notification_oid);
   oid      objid_snmptrap[] = { 1, 3, 6, 1, 6, 3, 1, 1, 4, 1, 0 };
   size_t   objid_snmptrap_len = OID_LENGTH(objid_snmptrap);
   oid      txpLsPowAlarm_oid[]   = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 2, 2, 1, 2, 1, 11 };
   size_t   txpLsPowAlarm_oid_len = OID_LENGTH(txpLsPowAlarm_oid);
   oid      txpLsPowAlarmSev_oid[]   = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 3, 4, 1, 1, 11 };
   size_t   txpLsPowAlarmSev_oid_len = OID_LENGTH(txpLsPowAlarmSev_oid);

   netsnmp_variable_list *notification_vars = NULL;
   static u_long txpLsPowCount = 0;

   unsigned int txpLsPowAlarm = 0;
   unsigned int send_txpLsPowAlarm = 0;

   unsigned char txpLsPow[100];
   strcpy(txpLsPow, alarm_Alarm_no[pt_monitor_struct->txp_struct.txp_tx_alarm.fields.lspowalm]);

   unsigned int txpLsPowAlarmSev = 0;
   txpLsPowAlarmSev = pt_monitor_struct->txp_struct.severity.ls_pow;

   if ((strcmp(txpLsPowTemp, "--") == 0) && (strcmp(txpLsPow, "Alarm") == 0))
   {
      txpLsPowAlarm = 1;
      send_txpLsPowAlarm = 1;
   }
   else if ((strcmp(txpLsPowTemp, "Alarm") == 0) && (strcmp(txpLsPow, "--") == 0))
   {
      txpLsPowAlarm = 2;
      send_txpLsPowAlarm = 1;
   }
   strcpy(txpLsPowTemp, txpLsPow);

   snmp_varlist_add_variable(&notification_vars, objid_snmptrap, objid_snmptrap_len, ASN_OBJECT_ID, (u_char *) notification_oid, notification_oid_len * sizeof(oid));
   snmp_varlist_add_variable(&notification_vars,  txpLsPowAlarm_oid, txpLsPowAlarm_oid_len, ASN_INTEGER, (u_char *)&txpLsPowAlarm, sizeof(txpLsPowAlarm));
   snmp_varlist_add_variable(&notification_vars, txpLsPowAlarmSev_oid, txpLsPowAlarmSev_oid_len, ASN_INTEGER, (u_char *)&txpLsPowAlarmSev, sizeof(txpLsPowAlarmSev));

   if(send_txpLsPowAlarm == 1)
   {
       ++txpLsPowCount;
       DEBUGMSGTL(("ftnc_notifications", "txpLsPowCount sending trap %ld\n", txpLsPowCount));
       send_v2trap(notification_vars);
   }
   snmp_free_varbind(notification_vars);
}

void send_txpModBiasAlarm_notification(unsigned int clientreg, void *clientarg)
{
	DEBUGMSGTL(("token", "send_txpModBiasAlarm_notification.\n"));

   oid      notification_oid[] =  { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 2, 2, 0, 17 };
   size_t   notification_oid_len = OID_LENGTH(notification_oid);
   oid      objid_snmptrap[] = { 1, 3, 6, 1, 6, 3, 1, 1, 4, 1, 0 };
   size_t   objid_snmptrap_len = OID_LENGTH(objid_snmptrap);
   oid      txpModBiasAlarm_oid[]   = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 2, 2, 1, 2, 1, 12 };
   size_t   txpModBiasAlarm_oid_len = OID_LENGTH(txpModBiasAlarm_oid);
   oid      txpModBiasAlarmSev_oid[]   = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 3, 4, 1, 1, 12 };
   size_t   txpModBiasAlarmSev_oid_len = OID_LENGTH(txpModBiasAlarmSev_oid);

   netsnmp_variable_list *notification_vars = NULL;
   static u_long txpModBiasCount = 0;

   unsigned int txpModBiasAlarm = 0;
   unsigned int send_txpModBiasAlarm = 0;

   unsigned char txpModBias[100];
   strcpy(txpModBias, alarm_Alarm_no[pt_monitor_struct->txp_struct.txp_tx_alarm.fields.modbiasalm]);

   unsigned int txpModBiasAlarmSev = 0;
   txpModBiasAlarmSev = pt_monitor_struct->txp_struct.severity.mod_bias;

   if ((strcmp(txpModBiasTemp, "--") == 0) && (strcmp(txpModBias, "Alarm") == 0))
   {
      txpModBiasAlarm = 1;
      send_txpModBiasAlarm = 1;
   }
   else if ( (strcmp(txpModBiasTemp, "Alarm") == 0) && (strcmp(txpModBias, "--") == 0))
   {
      txpModBiasAlarm = 2;
      send_txpModBiasAlarm = 1;
   }

   strcpy(txpModBiasTemp, txpModBias);

   snmp_varlist_add_variable(&notification_vars, objid_snmptrap, objid_snmptrap_len, ASN_OBJECT_ID, (u_char *) notification_oid, notification_oid_len * sizeof(oid));
   snmp_varlist_add_variable(&notification_vars,  txpModBiasAlarm_oid, txpModBiasAlarm_oid_len, ASN_INTEGER, (u_char *)&txpModBiasAlarm, sizeof(txpModBiasAlarm));
   snmp_varlist_add_variable(&notification_vars, txpModBiasAlarmSev_oid, txpModBiasAlarmSev_oid_len, ASN_INTEGER, (u_char *)&txpModBiasAlarmSev, sizeof(txpModBiasAlarmSev));

   if(send_txpModBiasAlarm == 1)
   {
       ++txpModBiasCount;
       DEBUGMSGTL(("ftnc_notifications", "txpModBiasCount sending trap %ld\n", txpModBiasCount));
       send_v2trap(notification_vars);
   }

   snmp_free_varbind(notification_vars);
}

void send_txpLatchedTxFifoAlarm_notification(unsigned int clientreg, void *clientarg)
{
	DEBUGMSGTL(("token", "send_txpLatchedTxFifoAlarm_notification.\n"));

   oid      notification_oid[] =  { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 2, 2, 0, 18 };
   size_t   notification_oid_len = OID_LENGTH(notification_oid);
   oid      objid_snmptrap[] = { 1, 3, 6, 1, 6, 3, 1, 1, 4, 1, 0 };
   size_t   objid_snmptrap_len = OID_LENGTH(objid_snmptrap);
   oid      txpLatchedTxFifoAlarm_oid[]   = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 2, 2, 1, 2, 1, 13 };
   size_t   txpLatchedTxFifoAlarm_oid_len = OID_LENGTH(txpLatchedTxFifoAlarm_oid);
   oid      txpLatchedTxFifoAlarmSev_oid[]   = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 3, 4, 1, 1, 13 };
   size_t   txpLatchedTxFifoAlarmSev_oid_len = OID_LENGTH(txpLatchedTxFifoAlarmSev_oid);

   netsnmp_variable_list *notification_vars = NULL;
   static u_long txpLatchedTxFifoCount = 0;

   unsigned int txpLatchedTxFifoAlarm = 0;
   unsigned int send_txpLatchedTxFifoAlarm = 0;

   unsigned char txpLatchedTxFifo[100];
   strcpy(txpLatchedTxFifo, alarm_Alarm_no[pt_monitor_struct->txp_struct.txp_tx_alarm.fields.latchedtxfifoerr]);

   unsigned int txpLatchedTxFifoAlarmSev = 0;
   txpLatchedTxFifoAlarmSev = pt_monitor_struct->txp_struct.severity.latched_tx_fifo;

   if ((strcmp(txpLatchedTxFifoTemp, "--") == 0) && (strcmp(txpLatchedTxFifo, "Alarm") == 0))
   {
      txpLatchedTxFifoAlarm = 1;
      send_txpLatchedTxFifoAlarm = 1;
   }
   else if ((strcmp(txpLatchedTxFifoTemp, "Alarm") == 0) && (strcmp(txpLatchedTxFifo, "--") == 0))
   {
      txpLatchedTxFifoAlarm = 2;
      send_txpLatchedTxFifoAlarm = 1;
   }
   strcpy(txpLatchedTxFifoTemp, txpLatchedTxFifo);

   snmp_varlist_add_variable(&notification_vars, objid_snmptrap, objid_snmptrap_len, ASN_OBJECT_ID, (u_char *) notification_oid, notification_oid_len * sizeof(oid));
   snmp_varlist_add_variable(&notification_vars,  txpLatchedTxFifoAlarm_oid, txpLatchedTxFifoAlarm_oid_len, ASN_INTEGER, (u_char *)&txpLatchedTxFifoAlarm, sizeof(txpLatchedTxFifoAlarm));
   snmp_varlist_add_variable(&notification_vars, txpLatchedTxFifoAlarmSev_oid, txpLatchedTxFifoAlarmSev_oid_len, ASN_INTEGER, (u_char *)&txpLatchedTxFifoAlarmSev, sizeof(txpLatchedTxFifoAlarmSev));

   if(send_txpLatchedTxFifoAlarm == 1)
   {
       ++txpLatchedTxFifoCount;
       DEBUGMSGTL(("ftnc_notifications", "txpLatchedTxFifoCount sending trap %ld\n", txpLatchedTxFifoCount));
       send_v2trap(notification_vars);
   }

   snmp_free_varbind(notification_vars);
}

void send_txpRxPowAlarm_notification(unsigned int clientreg, void *clientarg)
{
	DEBUGMSGTL(("token", "send_txpRxPowAlarm_notification."));

   oid      notification_oid[] =  { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 2, 2, 0, 19 };
   size_t   notification_oid_len = OID_LENGTH(notification_oid);
   oid      objid_snmptrap[] = { 1, 3, 6, 1, 6, 3, 1, 1, 4, 1, 0 };
   size_t   objid_snmptrap_len = OID_LENGTH(objid_snmptrap);
   oid      txpRxPowAlarm_oid[]   = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 2, 2, 1, 2, 1, 14 };
   size_t   txpRxPowAlarm_oid_len = OID_LENGTH(txpRxPowAlarm_oid);
   oid      txpRxPowAlarmSev_oid[]   = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 3, 4, 1, 1, 14 };
   size_t   txpRxPowAlarmSev_oid_len = OID_LENGTH(txpRxPowAlarmSev_oid);

   netsnmp_variable_list *notification_vars = NULL;
   static u_long txpRxPowCount = 0;

   unsigned int txpRxPowAlarm = 0;
   unsigned int send_txpRxPowAlarm = 0;

   unsigned char txpRxPow[100];
   strcpy(txpRxPow, alarm_Alarm_no[pt_monitor_struct->txp_struct.txp_rx_alarm.fields.rxpowalm]);

   unsigned int txpRxPowAlarmSev = 0;
   txpRxPowAlarmSev = pt_monitor_struct->txp_struct.severity.rx_pow;

   if ((strcmp(txpRxPowTemp, "--") == 0) && (strcmp(txpRxPow, "Alarm") == 0))
   {
      txpRxPowAlarm = 1;
      send_txpRxPowAlarm = 1;
   }
   else if ((strcmp(txpRxPowTemp, "Alarm") == 0) && (strcmp(txpRxPow, "--") == 0))
   {
      txpRxPowAlarm = 2;
      send_txpRxPowAlarm = 1;
   }
   strcpy(txpRxPowTemp, txpRxPow);

   snmp_varlist_add_variable(&notification_vars, objid_snmptrap, objid_snmptrap_len, ASN_OBJECT_ID, (u_char *) notification_oid, notification_oid_len * sizeof(oid));
   snmp_varlist_add_variable(&notification_vars,  txpRxPowAlarm_oid, txpRxPowAlarm_oid_len, ASN_INTEGER, (u_char *)&txpRxPowAlarm, sizeof(txpRxPowAlarm));
   snmp_varlist_add_variable(&notification_vars, txpRxPowAlarmSev_oid, txpRxPowAlarmSev_oid_len, ASN_INTEGER, (u_char *)&txpRxPowAlarmSev, sizeof(txpRxPowAlarmSev));

   if(send_txpRxPowAlarm == 1)
   {
       ++txpRxPowCount;
       DEBUGMSGTL(("ftnc_notifications", "txpRxPowCount sending trap %ld\n", txpRxPowCount));
       send_v2trap(notification_vars);
   }

   snmp_free_varbind(notification_vars);
}

void send_txpRxLosAlarm_notification(unsigned int clientreg, void *clientarg)
{
	DEBUGMSGTL(("token", "send_txpRxLosAlarm_notification.\n"));

   oid      notification_oid[] =  { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 2, 2, 0, 20 };
   size_t   notification_oid_len = OID_LENGTH(notification_oid);
   oid      objid_snmptrap[] = { 1, 3, 6, 1, 6, 3, 1, 1, 4, 1, 0 };
   size_t   objid_snmptrap_len = OID_LENGTH(objid_snmptrap);
   oid      txpRxLosAlarm_oid[]   = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 2, 2, 1, 2, 1, 15 };
   size_t   txpRxLosAlarm_oid_len = OID_LENGTH(txpRxLosAlarm_oid);
   oid      txpRxLosAlarmSev_oid[]   = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 3, 4, 1, 1, 15 };
   size_t   txpRxLosAlarmSev_oid_len = OID_LENGTH(txpRxLosAlarmSev_oid);

   netsnmp_variable_list *notification_vars = NULL;
   static u_long txpRxLosCount = 0;

   unsigned int txpRxLosAlarm = 0;
   unsigned int send_txpRxLosAlarm = 0;

   unsigned char txpRxLos[100];
   strcpy(txpRxLos, alarm_Alarm_no[pt_monitor_struct->txp_struct.txp_rx_alarm.fields.rxlos]);

   unsigned int txpRxLosAlarmSev = 0;
   txpRxLosAlarmSev = pt_monitor_struct->txp_struct.severity.rx_los;

   if ( (strcmp(txpRxLosTemp, "--") == 0) && (strcmp(txpRxLos, "Alarm") == 0))
   {
      txpRxLosAlarm = 1;
      send_txpRxLosAlarm = 1;
   }
   else if ( (strcmp(txpRxLosTemp, "Alarm") == 0) && (strcmp(txpRxLos, "--") == 0))
   {
      txpRxLosAlarm = 2;
      send_txpRxLosAlarm = 1;
   }
   strcpy(txpRxLosTemp, txpRxLos);

   snmp_varlist_add_variable(&notification_vars, objid_snmptrap, objid_snmptrap_len, ASN_OBJECT_ID, (u_char *) notification_oid, notification_oid_len * sizeof(oid));
   snmp_varlist_add_variable(&notification_vars,  txpRxLosAlarm_oid, txpRxLosAlarm_oid_len, ASN_INTEGER, (u_char *)&txpRxLosAlarm, sizeof(txpRxLosAlarm));
   snmp_varlist_add_variable(&notification_vars, txpRxLosAlarmSev_oid, txpRxLosAlarmSev_oid_len, ASN_INTEGER, (u_char *)&txpRxLosAlarmSev, sizeof(txpRxLosAlarmSev));

   if(send_txpRxLosAlarm == 1)
   {
       ++txpRxLosCount;
       DEBUGMSGTL(("ftnc_notifications", "txpRxLosCount sending trap %ld\n", txpRxLosCount));
       send_v2trap(notification_vars);
   }

   snmp_free_varbind(notification_vars);
}

void send_txpRxLockAlarm_notification(unsigned int clientreg, void *clientarg)
{
	DEBUGMSGTL(("token", "send_txpRxLockAlarm_notification.\n"));

   oid      notification_oid[] =  { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 2, 2, 0, 21 };
   size_t   notification_oid_len = OID_LENGTH(notification_oid);
   oid      objid_snmptrap[] = { 1, 3, 6, 1, 6, 3, 1, 1, 4, 1, 0 };
   size_t   objid_snmptrap_len = OID_LENGTH(objid_snmptrap);
   oid      txpRxLockAlarm_oid[]   = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 2, 2, 1, 2, 1, 16 };
   size_t   txpRxLockAlarm_oid_len = OID_LENGTH(txpRxLockAlarm_oid);
   oid      txpRxLockAlarmSev_oid[]   = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 3, 4, 1, 1, 16 };
   size_t   txpRxLockAlarmSev_oid_len = OID_LENGTH(txpRxLockAlarmSev_oid);

   netsnmp_variable_list *notification_vars = NULL;
   static u_long txpRxLockCount = 0;

   unsigned int txpRxLockAlarm = 0;
   unsigned int send_txpRxLockAlarm = 0;

   unsigned char txpRxLock[100];
   strcpy(txpRxLock, alarm_Alarm_no[pt_monitor_struct->txp_struct.txp_rx_alarm.fields.rxlockerr]);

   unsigned int txpRxLockAlarmSev = 0;
   txpRxLockAlarmSev = pt_monitor_struct->txp_struct.severity.rx_lock;

   if ((strcmp(txpRxLockTemp, "--") == 0) && (strcmp(txpRxLock, "Alarm") == 0))
   {
      txpRxLockAlarm = 1;
      send_txpRxLockAlarm = 1;
   }
   else if ((strcmp(txpRxLockTemp, "Alarm") == 0) && (strcmp(txpRxLock, "--") == 0))
   {
      txpRxLockAlarm = 2;
      send_txpRxLockAlarm = 1;
   }
   strcpy(txpRxLockTemp, txpRxLock);

   snmp_varlist_add_variable(&notification_vars, objid_snmptrap, objid_snmptrap_len, ASN_OBJECT_ID, (u_char *) notification_oid, notification_oid_len * sizeof(oid));
   snmp_varlist_add_variable(&notification_vars,  txpRxLockAlarm_oid, txpRxLockAlarm_oid_len, ASN_INTEGER, (u_char *)&txpRxLockAlarm, sizeof(txpRxLockAlarm));
   snmp_varlist_add_variable(&notification_vars, txpRxLockAlarmSev_oid, txpRxLockAlarmSev_oid_len, ASN_INTEGER, (u_char *)&txpRxLockAlarmSev, sizeof(txpRxLockAlarmSev));

   if(send_txpRxLockAlarm == 1)
   {
       ++txpRxLockCount;
       DEBUGMSGTL(("ftnc_notifications", "txpRxLockCount sending trap %ld\n", txpRxLockCount));
       send_v2trap(notification_vars);
   }

   snmp_free_varbind(notification_vars);
}

void send_txpRxsAlarm_notification(unsigned int clientreg, void *clientarg)
{
	DEBUGMSGTL(("token", "send_txpRxsAlarm_notification.\n"));

   oid      notification_oid[] =  { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 2, 2, 0, 22 };
   size_t   notification_oid_len = OID_LENGTH(notification_oid);
   oid      objid_snmptrap[] = { 1, 3, 6, 1, 6, 3, 1, 1, 4, 1, 0 };
   size_t   objid_snmptrap_len = OID_LENGTH(objid_snmptrap);
   oid      txpRxsAlarm_oid[]   = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 2, 2, 1, 2, 1, 17 };
   size_t   txpRxsAlarm_oid_len = OID_LENGTH(txpRxsAlarm_oid);
   oid      txpRxsAlarmSev_oid[]   = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 3, 4, 1, 1, 17 };
   size_t   txpRxsAlarmSev_oid_len = OID_LENGTH(txpRxsAlarmSev_oid);

   netsnmp_variable_list *notification_vars = NULL;
   static u_long txpRxsCount = 0;

   unsigned int txpRxsAlarm = 0;
   unsigned int send_txpRxsAlarm = 0;

   unsigned char txpRxs[100];
   strcpy(txpRxs, alarm_Alarm_no[pt_monitor_struct->txp_struct.txp_rx_alarm.fields.rxs]);

   unsigned int txpRxsAlarmSev = 0;
   txpRxsAlarmSev = pt_monitor_struct->txp_struct.severity.rxs;

   if ((strcmp(txpRxsTemp, "--") == 0) && (strcmp(txpRxs, "Alarm") == 0))
   {
      txpRxsAlarm = 1;
      send_txpRxsAlarm = 1;
   }
   else if ((strcmp(txpRxsTemp, "Alarm") == 0) && (strcmp(txpRxs, "--") == 0))
   {
      txpRxsAlarm = 2;
      send_txpRxsAlarm = 1;
   }
   strcpy(txpRxsTemp, txpRxs);

   snmp_varlist_add_variable(&notification_vars, objid_snmptrap, objid_snmptrap_len, ASN_OBJECT_ID, (u_char *) notification_oid, notification_oid_len * sizeof(oid));
   snmp_varlist_add_variable(&notification_vars,  txpRxsAlarm_oid, txpRxsAlarm_oid_len, ASN_INTEGER, (u_char *)&txpRxsAlarm, sizeof(txpRxsAlarm));
   snmp_varlist_add_variable(&notification_vars, txpRxsAlarmSev_oid, txpRxsAlarmSev_oid_len, ASN_INTEGER, (u_char *)&txpRxsAlarmSev, sizeof(txpRxsAlarmSev));

   if(send_txpRxsAlarm == 1)
   {
       ++txpRxsCount;
       DEBUGMSGTL(("ftnc_notifications", "txpRxsCount sending trap %ld\n", txpRxsCount));
       send_v2trap(notification_vars);
   }

   snmp_free_varbind(notification_vars);
}

void send_txpPrbsErrAlarm_notification(unsigned int clientreg, void *clientarg)
{
	DEBUGMSGTL(("token", "send_txpPrbsErrAlarm_notification.\n"));

   oid      notification_oid[] =  { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 2, 2, 0, 23 };
   size_t   notification_oid_len = OID_LENGTH(notification_oid);
   oid      objid_snmptrap[] = { 1, 3, 6, 1, 6, 3, 1, 1, 4, 1, 0 };
   size_t   objid_snmptrap_len = OID_LENGTH(objid_snmptrap);
   oid      txpPrbsErrAlarm_oid[]   = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 2, 2, 1, 2, 1, 18 };
   size_t   txpPrbsErrAlarm_oid_len = OID_LENGTH(txpPrbsErrAlarm_oid);
   oid      txpPrbsErrAlarmSev_oid[]   = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 3, 4, 1, 1, 18 };
   size_t   txpPrbsErrAlarmSev_oid_len = OID_LENGTH(txpPrbsErrAlarmSev_oid);

   netsnmp_variable_list *notification_vars = NULL;
   static u_long txpPrbsErrCount = 0;

   unsigned int txpPrbsErrAlarm = 0;
   unsigned int send_txpPrbsErrAlarm = 0;

   unsigned char txpPrbsErr[100];
   strcpy(txpPrbsErr, alarm_Alarm_no[pt_monitor_struct->txp_struct.txp_rx_alarm.fields.prbserrdet]);

   unsigned int txpPrbsErrAlarmSev = 0;
   txpPrbsErrAlarmSev = pt_monitor_struct->txp_struct.severity.prbs_err;

   if ((strcmp(txpPrbsErrTemp, "--") == 0) && (strcmp(txpPrbsErr, "Alarm") == 0))
   {
      txpPrbsErrAlarm = 1;
      send_txpPrbsErrAlarm = 1;
   }
   else if ((strcmp(txpPrbsErrTemp, "Alarm") == 0) && (strcmp(txpPrbsErr, "--") == 0))
   {
      txpPrbsErrAlarm = 2;
      send_txpPrbsErrAlarm = 1;
   }
   strcpy(txpPrbsErrTemp, txpPrbsErr);

   snmp_varlist_add_variable(&notification_vars, objid_snmptrap, objid_snmptrap_len, ASN_OBJECT_ID, (u_char *) notification_oid, notification_oid_len * sizeof(oid));
   snmp_varlist_add_variable(&notification_vars,  txpPrbsErrAlarm_oid, txpPrbsErrAlarm_oid_len, ASN_INTEGER, (u_char *)&txpPrbsErrAlarm, sizeof(txpPrbsErrAlarm));
   snmp_varlist_add_variable(&notification_vars, txpPrbsErrAlarmSev_oid, txpPrbsErrAlarmSev_oid_len, ASN_INTEGER, (u_char *)&txpPrbsErrAlarmSev, sizeof(txpPrbsErrAlarmSev));

   if(send_txpPrbsErrAlarm == 1)
   {
       ++txpPrbsErrCount;
       DEBUGMSGTL(("ftnc_notifications", "txpPrbsErrCount sending trap %ld\n", txpPrbsErrCount));
       send_v2trap(notification_vars);
   }

   snmp_free_varbind(notification_vars);
}

void send_txpPsummaryAlarm_notification(unsigned int clientreg, void *clientarg)
{
	DEBUGMSGTL(("token", "send_txpPsummaryAlarm_notification.\n"));

   oid      notification_oid[] =  { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 2, 2, 0, 24 };
   size_t   notification_oid_len = OID_LENGTH(notification_oid);
   oid      objid_snmptrap[] = { 1, 3, 6, 1, 6, 3, 1, 1, 4, 1, 0 };
   size_t   objid_snmptrap_len = OID_LENGTH(objid_snmptrap);
   oid      txpPsummaryAlarm_oid[]   = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 2, 2, 1, 2, 1, 19 };
   size_t   txpPsummaryAlarm_oid_len = OID_LENGTH(txpPsummaryAlarm_oid);
   oid      txpPsummaryAlarmSev_oid[]   = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 3, 4, 1, 1, 19 };
   size_t   txpPsummaryAlarmSev_oid_len = OID_LENGTH(txpPsummaryAlarmSev_oid);

   netsnmp_variable_list *notification_vars = NULL;
   static u_long txpPsummaryCount = 0;

   unsigned int txpPsummaryAlarm = 0;
   unsigned int send_txpPsummaryAlarm = 0;

   unsigned char txpPsummary[100];
   strcpy(txpPsummary, alarm_Alarm_no[pt_monitor_struct->txp_struct.txp_power_alarm.fields.psummary]);

   unsigned int txpPsummaryAlarmSev = 0;
   txpPsummaryAlarmSev = pt_monitor_struct->txp_struct.severity.psummary;

   if ((strcmp(txpPsummaryTemp, "--") == 0) && (strcmp(txpPsummary, "Alarm") == 0))
   {
      txpPsummaryAlarm = 1;
      send_txpPsummaryAlarm = 1;
   }
   else if ((strcmp(txpPsummaryTemp, "Alarm") == 0) && (strcmp(txpPsummary, "--") == 0))
   {
      txpPsummaryAlarm = 2;
      send_txpPsummaryAlarm = 1;
   }

   strcpy(txpPsummaryTemp, txpPsummary);

   snmp_varlist_add_variable(&notification_vars, objid_snmptrap, objid_snmptrap_len, ASN_OBJECT_ID, (u_char *) notification_oid, notification_oid_len * sizeof(oid));
   snmp_varlist_add_variable(&notification_vars,  txpPsummaryAlarm_oid, txpPsummaryAlarm_oid_len, ASN_INTEGER, (u_char *)&txpPsummaryAlarm, sizeof(txpPsummaryAlarm));
   snmp_varlist_add_variable(&notification_vars, txpPsummaryAlarmSev_oid, txpPsummaryAlarmSev_oid_len, ASN_INTEGER, (u_char *)&txpPsummaryAlarmSev, sizeof(txpPsummaryAlarmSev));

   if(send_txpPsummaryAlarm == 1)
   {
       ++txpPsummaryCount;
       DEBUGMSGTL(("ftnc_notifications", "txpPsummaryCount sending trap %ld\n", txpPsummaryCount));
       send_v2trap(notification_vars);
   }

   snmp_free_varbind(notification_vars);
}

void send_txpP5vAnalogAlarm_notification(unsigned int clientreg, void *clientarg)
{
	DEBUGMSGTL(("token", "send_txpP5vAnalogAlarm_notification.\n"));

   oid      notification_oid[] =  { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 2, 2, 0, 25 };
   size_t   notification_oid_len = OID_LENGTH(notification_oid);
   oid      objid_snmptrap[] = { 1, 3, 6, 1, 6, 3, 1, 1, 4, 1, 0 };
   size_t   objid_snmptrap_len = OID_LENGTH(objid_snmptrap);
   oid      txpP5vAnalogAlarm_oid[]   = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 2, 2, 1, 2, 1, 20 };
   size_t   txpP5vAnalogAlarm_oid_len = OID_LENGTH(txpP5vAnalogAlarm_oid);
   oid      txpP5vAnalogAlarmSev_oid[]   = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 3, 4, 1, 1, 20 };
   size_t   txpP5vAnalogAlarmSev_oid_len = OID_LENGTH(txpP5vAnalogAlarmSev_oid);

   netsnmp_variable_list *notification_vars = NULL;
   static u_long txpP5vAnalogCount = 0;

   unsigned int txpP5vAnalogAlarm = 0;
   unsigned int send_txpP5vAnalogAlarm = 0;

   unsigned char txpP5vAnalog[100];
   strcpy(txpP5vAnalog, alarm_Alarm_no[pt_monitor_struct->txp_struct.txp_power_alarm.fields.p5vanalog]);

   unsigned int txpP5vAnalogAlarmSev = 0;
   txpP5vAnalogAlarmSev = pt_monitor_struct->txp_struct.severity.p5vanalog;

   if ((strcmp(txpP5vAnalogTemp, "--") == 0) && (strcmp(txpP5vAnalog, "Alarm") == 0))
   {
      txpP5vAnalogAlarm = 1;
      send_txpP5vAnalogAlarm = 1;
   }
   else if ((strcmp(txpP5vAnalogTemp, "Alarm") == 0) && (strcmp(txpP5vAnalog, "--") == 0))
   {
      txpP5vAnalogAlarm = 2;
      send_txpP5vAnalogAlarm = 1;
   }
   strcpy(txpP5vAnalogTemp, txpP5vAnalog);

   snmp_varlist_add_variable(&notification_vars, objid_snmptrap, objid_snmptrap_len, ASN_OBJECT_ID, (u_char *) notification_oid, notification_oid_len * sizeof(oid));
   snmp_varlist_add_variable(&notification_vars,  txpP5vAnalogAlarm_oid, txpP5vAnalogAlarm_oid_len, ASN_INTEGER, (u_char *)&txpP5vAnalogAlarm, sizeof(txpP5vAnalogAlarm));
   snmp_varlist_add_variable(&notification_vars, txpP5vAnalogAlarmSev_oid, txpP5vAnalogAlarmSev_oid_len, ASN_INTEGER, (u_char *)&txpP5vAnalogAlarmSev, sizeof(txpP5vAnalogAlarmSev));

   if(send_txpP5vAnalogAlarm == 1)
   {
       ++txpP5vAnalogCount;
       DEBUGMSGTL(("ftnc_notifications", "txpP5vAnalogCount sending trap %ld\n", txpP5vAnalogCount));
       send_v2trap(notification_vars);
   }

   snmp_free_varbind(notification_vars);
}

void send_txpN5v2AnalogAlarm_notification(unsigned int clientreg, void *clientarg)
{
	DEBUGMSGTL(("token", "send_txpN5v2AnalogAlarm_notification.\n"));

   oid      notification_oid[] =  { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 2, 2, 0, 26 };
   size_t   notification_oid_len = OID_LENGTH(notification_oid);
   oid      objid_snmptrap[] = { 1, 3, 6, 1, 6, 3, 1, 1, 4, 1, 0 };
   size_t   objid_snmptrap_len = OID_LENGTH(objid_snmptrap);
   oid      txpN5v2AnalogAlarm_oid[]   = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 2, 2, 1, 2, 1, 21 };
   size_t   txpN5v2AnalogAlarm_oid_len = OID_LENGTH(txpN5v2AnalogAlarm_oid);
   oid      txpN5v2AnalogAlarmSev_oid[]   = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 3, 4, 1, 1, 21 };
   size_t   txpN5v2AnalogAlarmSev_oid_len = OID_LENGTH(txpN5v2AnalogAlarmSev_oid);

   netsnmp_variable_list *notification_vars = NULL;
   static u_long txpN5v2AnalogCount = 0;

   unsigned int txpN5v2AnalogAlarm = 0;
   unsigned int send_txpN5v2AnalogAlarm = 0;

   unsigned char txpN5v2Analog[100];
   strcpy(txpN5v2Analog, alarm_Alarm_no[pt_monitor_struct->txp_struct.txp_power_alarm.fields.n5v2analog]);

   unsigned int txpN5v2AnalogAlarmSev = 0;
   txpN5v2AnalogAlarmSev = pt_monitor_struct->txp_struct.severity.n5v2analog;

   if ((strcmp(txpN5v2AnalogTemp, "--") == 0) && (strcmp(txpN5v2Analog, "Alarm") == 0))
   {
      txpN5v2AnalogAlarm = 1;
      send_txpN5v2AnalogAlarm = 1;
   }
   else if ((strcmp(txpN5v2AnalogTemp, "Alarm") == 0) && (strcmp(txpN5v2Analog, "--") == 0))
   {
      txpN5v2AnalogAlarm = 2;
      send_txpN5v2AnalogAlarm = 1;
   }
   strcpy(txpN5v2AnalogTemp, txpN5v2Analog);

   snmp_varlist_add_variable(&notification_vars, objid_snmptrap, objid_snmptrap_len, ASN_OBJECT_ID, (u_char *) notification_oid, notification_oid_len * sizeof(oid));
   snmp_varlist_add_variable(&notification_vars,  txpN5v2AnalogAlarm_oid, txpN5v2AnalogAlarm_oid_len, ASN_INTEGER, (u_char *)&txpN5v2AnalogAlarm, sizeof(txpN5v2AnalogAlarm));
   snmp_varlist_add_variable(&notification_vars, txpN5v2AnalogAlarmSev_oid, txpN5v2AnalogAlarmSev_oid_len, ASN_INTEGER, (u_char *)&txpN5v2AnalogAlarmSev, sizeof(txpN5v2AnalogAlarmSev));

   if(send_txpN5v2AnalogAlarm == 1)
   {
       ++txpN5v2AnalogCount;
       DEBUGMSGTL(("ftnc_notifications", "txpN5v2AnalogCount sending trap %ld\n", txpN5v2AnalogCount));
       send_v2trap(notification_vars);
   }

   snmp_free_varbind(notification_vars);
}

void send_txpP3p3vAnalogAlarm_notification(unsigned int clientreg, void *clientarg)
{
	DEBUGMSGTL(("token", "send_txpP3p3vAnalogAlarm_notification.\n"));

   oid      notification_oid[] =  { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 2, 2, 0, 27 };
   size_t   notification_oid_len = OID_LENGTH(notification_oid);
   oid      objid_snmptrap[] = { 1, 3, 6, 1, 6, 3, 1, 1, 4, 1, 0 };
   size_t   objid_snmptrap_len = OID_LENGTH(objid_snmptrap);
   oid      txpP3p3vAnalogAlarm_oid[]   = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 2, 2, 1, 2, 1, 22 };
   size_t   txpP3p3vAnalogAlarm_oid_len = OID_LENGTH(txpP3p3vAnalogAlarm_oid);
   oid      txpP3p3vAnalogAlarmSev_oid[]   = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 3, 4, 1, 1, 22 };
   size_t   txpP3p3vAnalogAlarmSev_oid_len = OID_LENGTH(txpP3p3vAnalogAlarmSev_oid);

   netsnmp_variable_list *notification_vars = NULL;
   static u_long txpP3p3vAnalogCount = 0;

   unsigned int txpP3p3vAnalogAlarm = 0;
   unsigned int send_txpP3p3vAnalogAlarm = 0;

   unsigned char txpP3p3vAnalog[100];
   strcpy(txpP3p3vAnalog, alarm_Alarm_no[pt_monitor_struct->txp_struct.txp_power_alarm.fields.p3p3vanalog]);

   unsigned int txpP3p3vAnalogAlarmSev = 0;
   txpP3p3vAnalogAlarmSev = pt_monitor_struct->txp_struct.severity.p3p3vanalog;

   if ((strcmp(txpP3p3vAnalogTemp, "--") == 0) && (strcmp(txpP3p3vAnalog, "Alarm") == 0))
   {
      txpP3p3vAnalogAlarm = 1;
      send_txpP3p3vAnalogAlarm = 1;
   }
   else if ((strcmp(txpP3p3vAnalogTemp, "Alarm") == 0) && (strcmp(txpP3p3vAnalog, "--") == 0))
   {
      txpP3p3vAnalogAlarm = 2;
      send_txpP3p3vAnalogAlarm = 1;
   }
   strcpy(txpP3p3vAnalogTemp, txpP3p3vAnalog);

   snmp_varlist_add_variable(&notification_vars, objid_snmptrap, objid_snmptrap_len, ASN_OBJECT_ID, (u_char *) notification_oid, notification_oid_len * sizeof(oid));
   snmp_varlist_add_variable(&notification_vars,  txpP3p3vAnalogAlarm_oid, txpP3p3vAnalogAlarm_oid_len, ASN_INTEGER, (u_char *)&txpP3p3vAnalogAlarm, sizeof(txpP3p3vAnalogAlarm));
   snmp_varlist_add_variable(&notification_vars, txpP3p3vAnalogAlarmSev_oid, txpP3p3vAnalogAlarmSev_oid_len, ASN_INTEGER, (u_char *)&txpP3p3vAnalogAlarmSev, sizeof(txpP3p3vAnalogAlarmSev));

   if(send_txpP3p3vAnalogAlarm == 1)
   {
       ++txpP3p3vAnalogCount;
       DEBUGMSGTL(("ftnc_notifications", "txpP3p3vAnalogCount sending trap %ld\n", txpP3p3vAnalogCount));
       send_v2trap(notification_vars);
   }

   snmp_free_varbind(notification_vars);
}

void send_txpP3p3vDigitalAlarm_notification(unsigned int clientreg, void *clientarg)
{
	DEBUGMSGTL(("token", "send_txpP3p3vDigitalAlarm_notification.\n"));

   oid      notification_oid[] =  { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 2, 2, 0, 28 };
   size_t   notification_oid_len = OID_LENGTH(notification_oid);
   oid      objid_snmptrap[] = { 1, 3, 6, 1, 6, 3, 1, 1, 4, 1, 0 };
   size_t   objid_snmptrap_len = OID_LENGTH(objid_snmptrap);
   oid      txpP3p3vDigitalAlarm_oid[]   = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 2, 2, 1, 2, 1, 23 };
   size_t   txpP3p3vDigitalAlarm_oid_len = OID_LENGTH(txpP3p3vDigitalAlarm_oid);
   oid      txpP3p3vDigitalAlarmSev_oid[]   = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 3, 4, 1, 1, 23 };
   size_t   txpP3p3vDigitalAlarmSev_oid_len = OID_LENGTH(txpP3p3vDigitalAlarmSev_oid);

   netsnmp_variable_list *notification_vars = NULL;
   static u_long txpP3p3vDigitalCount = 0;

   unsigned int txpP3p3vDigitalAlarm = 0;
   unsigned int send_txpP3p3vDigitalAlarm = 0;

   unsigned char txpP3p3vDigital[100];
   strcpy(txpP3p3vDigital, alarm_Alarm_no[pt_monitor_struct->txp_struct.txp_power_alarm.fields.p3p3vdigital]);

   unsigned int txpP3p3vDigitalAlarmSev = 0;
   txpP3p3vDigitalAlarmSev = pt_monitor_struct->txp_struct.severity.p3p3vdigital;

   if ((strcmp(txpP3p3vDigitalTemp, "--") == 0) && (strcmp(txpP3p3vDigital, "Alarm") == 0))
   {
      txpP3p3vDigitalAlarm = 1;
      send_txpP3p3vDigitalAlarm = 1;
   }
   else if ((strcmp(txpP3p3vDigitalTemp, "Alarm") == 0) && (strcmp(txpP3p3vDigital, "--") == 0))
   {
      txpP3p3vDigitalAlarm = 2;
      send_txpP3p3vDigitalAlarm = 1;
   }
   strcpy(txpP3p3vDigitalTemp, txpP3p3vDigital);

   snmp_varlist_add_variable(&notification_vars, objid_snmptrap, objid_snmptrap_len, ASN_OBJECT_ID, (u_char *) notification_oid, notification_oid_len * sizeof(oid));
   snmp_varlist_add_variable(&notification_vars,  txpP3p3vDigitalAlarm_oid, txpP3p3vDigitalAlarm_oid_len, ASN_INTEGER, (u_char *)&txpP3p3vDigitalAlarm, sizeof(txpP3p3vDigitalAlarm));
   snmp_varlist_add_variable(&notification_vars, txpP3p3vDigitalAlarmSev_oid, txpP3p3vDigitalAlarmSev_oid_len, ASN_INTEGER, (u_char *)&txpP3p3vDigitalAlarmSev, sizeof(txpP3p3vDigitalAlarmSev));

   if(send_txpP3p3vDigitalAlarm == 1)
   {
       ++txpP3p3vDigitalCount;
       DEBUGMSGTL(("ftnc_notifications", "txpP3p3vDigitalCount sending trap %ld\n",txpP3p3vDigitalCount));
       send_v2trap(notification_vars);
   }

   snmp_free_varbind(notification_vars);
}

void send_txpLvDigitalAlarm_notification(unsigned int clientreg, void *clientarg)
{
	DEBUGMSGTL(("token", "send_txpLvDigitalAlarm_notification.\n"));

   oid      notification_oid[] =  { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 2, 2, 0, 29 };
   size_t   notification_oid_len = OID_LENGTH(notification_oid);
   oid      objid_snmptrap[] = { 1, 3, 6, 1, 6, 3, 1, 1, 4, 1, 0 };
   size_t   objid_snmptrap_len = OID_LENGTH(objid_snmptrap);
   oid      txpLvDigitalAlarm_oid[]   = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 2, 2, 1, 2, 1, 24 };
   size_t   txpLvDigitalAlarm_oid_len = OID_LENGTH(txpLvDigitalAlarm_oid);
   oid      txpLvDigitalAlarmSev_oid[]   = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 3, 4, 1, 1, 24 };
   size_t   txpLvDigitalAlarmSev_oid_len = OID_LENGTH(txpLvDigitalAlarmSev_oid);

   netsnmp_variable_list *notification_vars = NULL;
   static u_long txpLvDigitalCount = 0;

   unsigned int txpLvDigitalAlarm = 0;
   unsigned int send_txpLvDigitalAlarm = 0;

   unsigned char txpLvDigital[100];
   strcpy(txpLvDigital, alarm_Alarm_no[pt_monitor_struct->txp_struct.txp_power_alarm.fields.lvdigital]);

   unsigned int txpLvDigitalAlarmSev = 0;
   txpLvDigitalAlarmSev = pt_monitor_struct->txp_struct.severity.lvdigital;

   if ((strcmp(txpLvDigitalTemp, "--") == 0) && (strcmp(txpLvDigital, "Alarm") == 0))
   {
      txpLvDigitalAlarm = 1;
      send_txpLvDigitalAlarm = 1;
   }
   else if ((strcmp(txpLvDigitalTemp, "Alarm") == 0) && (strcmp(txpLvDigital, "--") == 0))
   {
      txpLvDigitalAlarm = 2;
      send_txpLvDigitalAlarm = 1;
   }
   strcpy(txpLvDigitalTemp, txpLvDigital);

   snmp_varlist_add_variable(&notification_vars, objid_snmptrap, objid_snmptrap_len, ASN_OBJECT_ID, (u_char *) notification_oid, notification_oid_len * sizeof(oid));
   snmp_varlist_add_variable(&notification_vars,  txpLvDigitalAlarm_oid, txpLvDigitalAlarm_oid_len, ASN_INTEGER, (u_char *)&txpLvDigitalAlarm, sizeof(txpLvDigitalAlarm));
   snmp_varlist_add_variable(&notification_vars, txpLvDigitalAlarmSev_oid, txpLvDigitalAlarmSev_oid_len, ASN_INTEGER, (u_char *)&txpLvDigitalAlarmSev, sizeof(txpLvDigitalAlarmSev));

   if(send_txpLvDigitalAlarm == 1)
   {
       ++txpLvDigitalCount;
       DEBUGMSGTL(("ftnc_notifications", "txpLvDigitalCount sending trap %ld\n",txpLvDigitalCount));
       send_v2trap(notification_vars);
   }

   snmp_free_varbind(notification_vars);
}

void send_txpN5p2vDigitalAlarm_notification(unsigned int clientreg, void *clientarg)
{
	DEBUGMSGTL(("token", "send_txpN5p2vDigitalAlarm_notification.\n"));

   oid      notification_oid[] =  { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 2, 2, 0, 30 };
   size_t   notification_oid_len = OID_LENGTH(notification_oid);
   oid      objid_snmptrap[] = { 1, 3, 6, 1, 6, 3, 1, 1, 4, 1, 0 };
   size_t   objid_snmptrap_len = OID_LENGTH(objid_snmptrap);
   oid      txpN5p2vDigitalAlarm_oid[]   = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 2, 2, 1, 2, 1, 25 };
   size_t   txpN5p2vDigitalAlarm_oid_len = OID_LENGTH(txpN5p2vDigitalAlarm_oid);
   oid      txpN5p2vDigitalAlarmSev_oid[]   = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 3, 4, 1, 1, 25 };
   size_t   txpN5p2vDigitalAlarmSev_oid_len = OID_LENGTH(txpN5p2vDigitalAlarmSev_oid);

   netsnmp_variable_list *notification_vars = NULL;
   static u_long txpN5p2vDigitalCount = 0;

   unsigned int txpN5p2vDigitalAlarm = 0;
   unsigned int send_txpN5p2vDigitalAlarm = 0;

   unsigned char txpN5p2vDigital[100];
   strcpy(txpN5p2vDigital, alarm_Alarm_no[pt_monitor_struct->txp_struct.txp_power_alarm.fields.n5p2vdigital]);

   unsigned int txpN5p2vDigitalAlarmSev = 0;
   txpN5p2vDigitalAlarmSev = pt_monitor_struct->txp_struct.severity.n5p2vdigital;

   if ((strcmp(txpN5p2vDigitalTemp, "--") == 0) && (strcmp(txpN5p2vDigital, "Alarm") == 0))
   {
      txpN5p2vDigitalAlarm = 1;
      send_txpN5p2vDigitalAlarm = 1;
   }
   else if ((strcmp(txpN5p2vDigitalTemp, "Alarm") == 0) && (strcmp(txpN5p2vDigital, "--") == 0))
   {
      txpN5p2vDigitalAlarm = 2;
      send_txpN5p2vDigitalAlarm = 1;
   }
   strcpy(txpN5p2vDigitalTemp, txpN5p2vDigital);

   snmp_varlist_add_variable(&notification_vars, objid_snmptrap, objid_snmptrap_len, ASN_OBJECT_ID, (u_char *) notification_oid, notification_oid_len * sizeof(oid));
   snmp_varlist_add_variable(&notification_vars,  txpN5p2vDigitalAlarm_oid, txpN5p2vDigitalAlarm_oid_len, ASN_INTEGER, (u_char *)&txpN5p2vDigitalAlarm, sizeof(txpN5p2vDigitalAlarm));
   snmp_varlist_add_variable(&notification_vars, txpN5p2vDigitalAlarmSev_oid, txpN5p2vDigitalAlarmSev_oid_len, ASN_INTEGER, (u_char *)&txpN5p2vDigitalAlarmSev, sizeof(txpN5p2vDigitalAlarmSev));

   if(send_txpN5p2vDigitalAlarm == 1)
   {
       ++txpN5p2vDigitalCount;
       DEBUGMSGTL(("ftnc_notifications", "txpN5p2vDigitalCount sending trap %ld\n",txpN5p2vDigitalCount));
       send_v2trap(notification_vars);
   }

   snmp_free_varbind(notification_vars);
}

/* ***************** Implementation of XFP1 methods ***************** */

void send_xfp1Presence_notification(unsigned int clientreg, void *clientarg)
{
	DEBUGMSGTL(("token", "send_xfp1Presence_notification.\n"));

	oid 	notification_oid[] = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 2, 2, 0, 31 };
	size_t 	notification_oid_len = OID_LENGTH(notification_oid);
	oid 	objid_snmptrap[] = { 1, 3, 6, 1, 6, 3, 1, 1, 4, 1, 0 };
	size_t 	objid_snmptrap_len = OID_LENGTH(objid_snmptrap);
	oid 	xfp1Presence_oid[]   = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 2, 2, 1, 3, 1, 2 };
	size_t  xfp1Presence_oid_len = OID_LENGTH(xfp1Presence_oid);
	oid     xfp1PresenceAlarmSev_oid[]   = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 3, 5, 1, 1, 2 };
	size_t	xfp1PresenceAlarmSev_oid_len = OID_LENGTH(xfp1PresenceAlarmSev_oid);

	netsnmp_variable_list *notification_vars = NULL;
	static u_long xfp1PresenceCount = 0;

	unsigned int xfp1PresenceAlarm = 0;
	unsigned int xfp1Presence = 0;
	//xfp1Presence = 0 is present; xfp1Presence = 1 is not present.
	xfp1Presence = pt_monitor_struct->xfp_struct.xfp_presence[0];

	unsigned int xfp1PresenceAlarmSev = 0;
	xfp1PresenceAlarmSev = pt_monitor_struct->xfp_struct.severity[0].presence;

	unsigned int send_xfp1PresenceAlarm = 0;
	if (xfp1PresenceTemp==0 && xfp1Presence==1) //The alarm was activated.
   {
		xfp1PresenceAlarm = 1; //The alarm was activated.
		send_xfp1PresenceAlarm = 1; // Send notification.
   }
   else if (xfp1PresenceTemp==1 && xfp1Presence==0) //The alarm is deactivated.
   {
	   xfp1PresenceAlarm = 2; //The alarm is deactivated.
      send_xfp1PresenceAlarm = 1; //Send notification.
   }
	xfp1PresenceTemp = xfp1Presence;

	snmp_varlist_add_variable(&notification_vars, objid_snmptrap, objid_snmptrap_len, ASN_OBJECT_ID, (u_char *) notification_oid, notification_oid_len * sizeof(oid));
	snmp_varlist_add_variable(&notification_vars, xfp1Presence_oid, xfp1Presence_oid_len, ASN_INTEGER, (u_char *)&xfp1PresenceAlarm, sizeof(xfp1PresenceAlarm));
	snmp_varlist_add_variable(&notification_vars, xfp1PresenceAlarmSev_oid, xfp1PresenceAlarmSev_oid_len, ASN_INTEGER, (u_char *)&xfp1PresenceAlarmSev, sizeof(xfp1PresenceAlarmSev));

	if(send_xfp1PresenceAlarm == 1)
	{
		++xfp1PresenceCount;
		DEBUGMSGTL(("ftnc_notifications", "xfp1PresenceCount sending trap %ld\n",xfp1PresenceCount));
		send_v2trap(notification_vars);
	}

	snmp_free_varbind(notification_vars);
}

void send_xfp1RxLoss_notification(unsigned int clientreg, void *clientarg)
{
	DEBUGMSGTL(("token", "send_xfp1RxLoss_notification.\n"));

	oid 	notification_oid[] = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 2, 2, 0, 32 };
	size_t 	notification_oid_len = OID_LENGTH(notification_oid);
	oid 	objid_snmptrap[] = { 1, 3, 6, 1, 6, 3, 1, 1, 4, 1, 0 };
	size_t 	objid_snmptrap_len = OID_LENGTH(objid_snmptrap);
	oid 	xfp1RxLoss_oid[]   = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 2, 2, 1, 3, 1, 3 };
	size_t 	xfp1RxLoss_oid_len = OID_LENGTH(xfp1RxLoss_oid);
	oid     xfp1RxLossAlarmSev_oid[]   = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 3, 5, 1, 1, 3 };
	size_t	xfp1RxLossAlarmSev_oid_len = OID_LENGTH(xfp1RxLossAlarmSev_oid);

	netsnmp_variable_list *notification_vars = NULL;
	static u_long xfp1RxLossCount = 0;

	unsigned int xfp1RxLossAlarm = 0;

	unsigned int xfp1RxLoss = 0;
	xfp1RxLoss = pt_monitor_struct->xfp_struct.xfp_presence[0];

	unsigned int xfp1RxLossAlarmSev = 0;
	xfp1RxLossAlarmSev = pt_monitor_struct->xfp_struct.severity[0].rx_loss;

	unsigned int send_xfp1RxLossAlarm = 0;
	if (xfp1RxLossTemp==0 && xfp1RxLoss==1)
   {
		xfp1RxLossAlarm = 1;
		send_xfp1RxLossAlarm = 1;
   }
   else if (xfp1RxLossTemp==1 && xfp1RxLoss==0)
   {
	   xfp1RxLossAlarm = 2;
      send_xfp1RxLossAlarm = 1;
   }
	xfp1RxLossTemp = xfp1RxLoss;

	snmp_varlist_add_variable(&notification_vars, objid_snmptrap, objid_snmptrap_len, ASN_OBJECT_ID, (u_char *) notification_oid, notification_oid_len * sizeof(oid));
	snmp_varlist_add_variable(&notification_vars, xfp1RxLoss_oid, xfp1RxLoss_oid_len, ASN_INTEGER, (u_char *)&xfp1RxLossAlarm, sizeof(xfp1RxLossAlarm));
	snmp_varlist_add_variable(&notification_vars, xfp1RxLossAlarmSev_oid, xfp1RxLossAlarmSev_oid_len, ASN_INTEGER, (u_char *)&xfp1RxLossAlarmSev, sizeof(xfp1RxLossAlarmSev));

	if(send_xfp1RxLossAlarm == 1)
	{
		++xfp1RxLossCount;
		DEBUGMSGTL(("ftnc_notifications", "sending trap %ld\n",xfp1RxLossCount));
		send_v2trap(notification_vars);
	}

	snmp_free_varbind(notification_vars);
}

void send_xfp1Ready_notification(unsigned int clientreg, void *clientarg)
{
	DEBUGMSGTL(("token", "send_xfp1Ready_notification.\n"));

	oid 	notification_oid[] = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 2, 2, 0, 33 };
	size_t 	notification_oid_len = OID_LENGTH(notification_oid);
	oid 	objid_snmptrap[] = { 1, 3, 6, 1, 6, 3, 1, 1, 4, 1, 0 };
	size_t 	objid_snmptrap_len = OID_LENGTH(objid_snmptrap);
	oid 	xfp1Ready_oid[]   = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 2, 2, 1, 3, 1, 4 };
	size_t 	xfp1Ready_oid_len = OID_LENGTH(xfp1Ready_oid);
	oid     xfp1ReadyAlarmSev_oid[]   = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 3, 5, 1, 1, 4 };
	size_t	xfp1ReadyAlarmSev_oid_len = OID_LENGTH(xfp1ReadyAlarmSev_oid);

	netsnmp_variable_list *notification_vars = NULL;
	static u_long xfp1ReadyCount = 0;

	unsigned int xfp1ReadyAlarm = 0;

	unsigned int xfp1Ready = 0;
	xfp1Ready = pt_monitor_struct->xfp_struct.xfp_ready[0];

	unsigned int xfp1ReadyAlarmSev = 0;
	xfp1ReadyAlarmSev = pt_monitor_struct->xfp_struct.severity[0].ready;

	unsigned int send_xfp1ReadyAlarm = 0;
	if (xfp1ReadyTemp==0 && xfp1Ready==1)
   {
		xfp1ReadyAlarm = 1;
		send_xfp1ReadyAlarm = 1;
   }
   else if (xfp1ReadyTemp==1 && xfp1Ready==0)
   {
	  xfp1ReadyAlarm = 2;
      send_xfp1ReadyAlarm = 1;
   }
	xfp1ReadyTemp = xfp1Ready;

	snmp_varlist_add_variable(&notification_vars, objid_snmptrap, objid_snmptrap_len, ASN_OBJECT_ID, (u_char *) notification_oid, notification_oid_len * sizeof(oid));
	snmp_varlist_add_variable(&notification_vars, xfp1Ready_oid, xfp1Ready_oid_len, ASN_INTEGER, (u_char *)&xfp1ReadyAlarm, sizeof(xfp1ReadyAlarm));
	snmp_varlist_add_variable(&notification_vars, xfp1ReadyAlarmSev_oid, xfp1ReadyAlarmSev_oid_len, ASN_INTEGER, (u_char *)&xfp1ReadyAlarmSev, sizeof(xfp1ReadyAlarmSev));

	if(send_xfp1ReadyAlarm == 1)
	{
		++xfp1ReadyCount;
		DEBUGMSGTL(("ftnc_notifications", "sending trap %ld\n",xfp1ReadyCount));
		send_v2trap(notification_vars);
	}

	snmp_free_varbind(notification_vars);
}

void send_xfp1TxPower_notification(unsigned int clientreg, void *clientarg)
{
	DEBUGMSGTL(("token", "send_xfp1TxPower_notification.\n"));

   oid      notification_oid[] =  { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 2, 2, 0, 34 };
   size_t   notification_oid_len = OID_LENGTH(notification_oid);
   oid      objid_snmptrap[] = { 1, 3, 6, 1, 6, 3, 1, 1, 4, 1, 0 };
   size_t   objid_snmptrap_len = OID_LENGTH(objid_snmptrap);
   oid		xfp1TxPowerAlarm_oid[]   = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 2, 2, 1, 3, 1, 5 };
   size_t	xfp1TxPowerAlarm_oid_len = OID_LENGTH(xfp1TxPowerAlarm_oid);
   oid	xfp1TxPowerAlarmSev_oid[]   = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 3, 5, 1, 1, 5 };
   size_t	xfp1TxPowerAlarmSev_oid_len = OID_LENGTH(xfp1TxPowerAlarmSev_oid);

   netsnmp_variable_list *notification_vars = NULL;
   static u_long  xfp1TxPowerCount = 0;

   unsigned int xfp1TxPowerInt = 0;
   unsigned int xfp1TxPowerAlarm = 0;

   unsigned int send_xfp1TxPowerAlarm = 0;

   float xfp1TxPower;
   xfp1TxPower = pt_monitor_struct->xfp_struct.xfp_tx_power[0];

   unsigned int xfp1TxPowerAlarmSev = 0;
   xfp1TxPowerAlarmSev = pt_monitor_struct->xfp_struct.severity[0].tx_power;

   if (xfp1TxPower < -3 || xfp1TxPower > 0)
   { xfp1TxPowerInt = 1; }
   else
   { xfp1TxPowerInt = 0; }

   if (xfp1TxPowerTemp==0 && xfp1TxPowerInt==1)
   {
	   xfp1TxPowerAlarm = 1;
	   send_xfp1TxPowerAlarm = 1;
   }
   else if (xfp1TxPowerTemp==1 && xfp1TxPowerInt==0)
   {
	   xfp1TxPowerAlarm = 2;
	   send_xfp1TxPowerAlarm = 1;
   }
   xfp1TxPowerTemp = xfp1TxPowerInt;

   snmp_varlist_add_variable(&notification_vars, objid_snmptrap, objid_snmptrap_len, ASN_OBJECT_ID, (u_char *) notification_oid, notification_oid_len * sizeof(oid));
   snmp_varlist_add_variable(&notification_vars,  xfp1TxPowerAlarm_oid, xfp1TxPowerAlarm_oid_len, ASN_INTEGER, (u_char *)&xfp1TxPowerAlarm, sizeof(xfp1TxPowerAlarm));
   snmp_varlist_add_variable(&notification_vars, xfp1TxPowerAlarmSev_oid, xfp1TxPowerAlarmSev_oid_len, ASN_INTEGER, (u_char *)&xfp1TxPowerAlarmSev, sizeof(xfp1TxPowerAlarmSev));

   if(send_xfp1TxPowerAlarm == 1)
   {
       ++xfp1TxPowerCount;
       DEBUGMSGTL(("ftnc_notifications", "sending trap %ld\n",xfp1TxPowerCount));
       send_v2trap(notification_vars);
   }

   snmp_free_varbind(notification_vars);
}

void send_xfp1RxPower_notification(unsigned int clientreg, void *clientarg)
{
	DEBUGMSGTL(("token", "send_xfp1RxPower_notification.\n"));

   oid      notification_oid[] =  { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 2, 2, 0, 35 };
   size_t   notification_oid_len = OID_LENGTH(notification_oid);
   oid      objid_snmptrap[] = { 1, 3, 6, 1, 6, 3, 1, 1, 4, 1, 0 };
   size_t   objid_snmptrap_len = OID_LENGTH(objid_snmptrap);
   oid      xfp1RxPowerAlarm_oid[]   = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 2, 2, 1, 3, 1, 6 };
   size_t	xfp1RxPowerAlarm_oid_len = OID_LENGTH(xfp1RxPowerAlarm_oid);
   oid      xfp1RxPowerAlarmSev_oid[]   = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 3, 5, 1, 1, 6 };
   size_t   xfp1RxPowerAlarmSev_oid_len = OID_LENGTH(xfp1RxPowerAlarmSev_oid);

   netsnmp_variable_list *notification_vars = NULL;
   static u_long  xfp1RxPowerCount = 0;

   unsigned int xfp1RxPowerInt = 0;
   unsigned int xfp1RxPowerAlarm = 0;

   unsigned int send_xfp1RxPowerAlarm = 0;

   float xfp1RxPower;
   xfp1RxPower = pt_monitor_struct->xfp_struct.xfp_rx_power[0];

   unsigned int xfp1RxPowerAlarmSev = 0;
   xfp1RxPowerAlarmSev = pt_monitor_struct->xfp_struct.severity[0].rx_power;

   if (xfp1RxPower < -3 || xfp1RxPower > 0)
   { xfp1RxPowerInt = 1; }
   else
   { xfp1RxPowerInt = 0; }

   if (xfp1RxPowerTemp==0 && xfp1RxPowerInt==1)
   {
	   xfp1RxPowerAlarm = 1;
	   send_xfp1RxPowerAlarm = 1;
   }
   else if (xfp1RxPowerTemp==1 && xfp1RxPowerInt==0)
   {
	   xfp1RxPowerAlarm = 2;
	   send_xfp1RxPowerAlarm = 1;
   }
   xfp1RxPowerTemp = xfp1RxPowerInt;

   snmp_varlist_add_variable(&notification_vars, objid_snmptrap, objid_snmptrap_len, ASN_OBJECT_ID, (u_char *) notification_oid, notification_oid_len * sizeof(oid));
   snmp_varlist_add_variable(&notification_vars,  xfp1RxPowerAlarm_oid, xfp1RxPowerAlarm_oid_len, ASN_INTEGER, (u_char *)&xfp1RxPowerAlarm, sizeof(xfp1RxPowerAlarm));
   snmp_varlist_add_variable(&notification_vars, xfp1RxPowerAlarmSev_oid, xfp1RxPowerAlarmSev_oid_len, ASN_INTEGER, (u_char *)&xfp1RxPowerAlarmSev, sizeof(xfp1RxPowerAlarmSev));

   if(send_xfp1RxPowerAlarm == 1)
   {
       ++xfp1RxPowerCount;
       DEBUGMSGTL(("ftnc_notifications", "sending trap %ld\n",xfp1RxPowerCount));
       send_v2trap(notification_vars);
   }

   snmp_free_varbind(notification_vars);
}

void send_xfp1Temperature_notification(unsigned int clientreg, void *clientarg)
{
	DEBUGMSGTL(("token", "send_xfp1Temperature_notification.\n"));

   oid      notification_oid[] =  { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 2, 2, 0, 36 };
   size_t   notification_oid_len = OID_LENGTH(notification_oid);
   oid      objid_snmptrap[] = { 1, 3, 6, 1, 6, 3, 1, 1, 4, 1, 0 };
   size_t   objid_snmptrap_len = OID_LENGTH(objid_snmptrap);
   oid      xfp1TemperatureAlarm_oid[]   = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 2, 2, 1, 3, 1, 7 };
   size_t   xfp1TemperatureAlarm_oid_len = OID_LENGTH(xfp1TemperatureAlarm_oid);
   oid      xfp1TemperatureAlarmSev_oid[]   = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 3, 5, 1, 1, 7 };
   size_t   xfp1TemperatureAlarmSev_oid_len = OID_LENGTH(xfp1TemperatureAlarmSev_oid);

   netsnmp_variable_list *notification_vars = NULL;
   static u_long  xfp1TemperatureCount = 0;

   unsigned int xfp1TemperatureInt = 0;
   unsigned int xfp1TemperatureAlarm = 0;

   unsigned int send_xfp1TemperatureAlarm = 0;

   float xfp1Temperature;
   xfp1Temperature = pt_monitor_struct->xfp_struct.xfp_temperature[0];

   unsigned int xfp1TemperatureAlarmSev = 0;
   xfp1TemperatureAlarmSev = pt_monitor_struct->xfp_struct.severity[0].temperature;

   if (xfp1Temperature < 10 || xfp1Temperature > 30)
   { xfp1TemperatureInt = 1; }
   else
   { xfp1TemperatureInt = 0; }

   if (xfp1TemperatureTemp==0 && xfp1TemperatureInt==1)
   {
	   xfp1TemperatureAlarm = 1;
	   send_xfp1TemperatureAlarm = 1;
   }
   else if (xfp1TemperatureTemp==1 && xfp1TemperatureInt==0)
   {
	   xfp1TemperatureAlarm = 2;
	   send_xfp1TemperatureAlarm = 1;
   }
   xfp1TemperatureTemp = xfp1TemperatureInt;

   snmp_varlist_add_variable(&notification_vars, objid_snmptrap, objid_snmptrap_len, ASN_OBJECT_ID, (u_char *) notification_oid, notification_oid_len * sizeof(oid));
   snmp_varlist_add_variable(&notification_vars,  xfp1TemperatureAlarm_oid, xfp1TemperatureAlarm_oid_len, ASN_INTEGER, (u_char *)&xfp1TemperatureAlarm, sizeof(xfp1TemperatureAlarm));
   snmp_varlist_add_variable(&notification_vars, xfp1TemperatureAlarmSev_oid, xfp1TemperatureAlarmSev_oid_len, ASN_INTEGER, (u_char *)&xfp1TemperatureAlarmSev, sizeof(xfp1TemperatureAlarmSev));

   if(send_xfp1TemperatureAlarm == 1)
   {
       ++xfp1TemperatureCount;
       DEBUGMSGTL(("ftnc_notifications", "sending trap %ld\n",xfp1TemperatureCount));
       send_v2trap(notification_vars);
   }

   snmp_free_varbind(notification_vars);
}

void send_xfp1LowTxPower_notification(unsigned int clientreg, void *clientarg)
{
	DEBUGMSGTL(("token", "send_xfp1LowTxPower_notification.\n"));

	oid 	notification_oid[] = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 2, 2, 0, 37 };
	size_t 	notification_oid_len = OID_LENGTH(notification_oid);
	oid 	objid_snmptrap[] = { 1, 3, 6, 1, 6, 3, 1, 1, 4, 1, 0 };
	size_t 	objid_snmptrap_len = OID_LENGTH(objid_snmptrap);
	oid 	xfp1LowTxPower_oid[]   = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 2, 2, 1, 3, 1, 8 };
	size_t 	xfp1LowTxPower_oid_len = OID_LENGTH(xfp1LowTxPower_oid);
	oid     xfp1LowTxPowerAlarmSev_oid[]   = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 3, 5, 1, 1, 8 };
	size_t  xfp1LowTxPowerAlarmSev_oid_len = OID_LENGTH(xfp1LowTxPowerAlarmSev_oid);

	netsnmp_variable_list *notification_vars = NULL;
	static u_long xfp1LowTxPowerCount = 0;

	unsigned int xfp1LowTxPowerAlarm = 0;

	unsigned int xfp1LowTxPower = 0;
	xfp1LowTxPower = pt_monitor_struct->xfp_struct.xfp_interruption_flags[0][0];

	unsigned int xfp1LowTxPowerAlarmSev = 0;
	xfp1LowTxPowerAlarmSev = pt_monitor_struct->xfp_struct.severity[0].low_tx_power;

	unsigned int send_xfp1LowTxPowerAlarm = 0;
	if (xfp1LowTxPowerTemp==0 && xfp1LowTxPower==1)
   {
		xfp1LowTxPowerAlarm = 1;
		send_xfp1LowTxPowerAlarm = 1;
   }
   else if (xfp1LowTxPowerTemp==1 && xfp1LowTxPower==0)
   {
	  xfp1LowTxPowerAlarm = 2;
      send_xfp1LowTxPowerAlarm = 1;
   }
	xfp1LowTxPowerTemp = xfp1LowTxPower;

	snmp_varlist_add_variable(&notification_vars, objid_snmptrap, objid_snmptrap_len, ASN_OBJECT_ID, (u_char *) notification_oid, notification_oid_len * sizeof(oid));
	snmp_varlist_add_variable(&notification_vars, xfp1LowTxPower_oid, xfp1LowTxPower_oid_len, ASN_INTEGER, (u_char *)&xfp1LowTxPowerAlarm, sizeof(xfp1LowTxPowerAlarm));
	snmp_varlist_add_variable(&notification_vars, xfp1LowTxPowerAlarmSev_oid, xfp1LowTxPowerAlarmSev_oid_len, ASN_INTEGER, (u_char *)&xfp1LowTxPowerAlarmSev, sizeof(xfp1LowTxPowerAlarmSev));

	if(send_xfp1LowTxPowerAlarm == 1)
	{
		++xfp1LowTxPowerCount;
		DEBUGMSGTL(("ftnc_notifications", "sending trap %ld\n",xfp1LowTxPowerCount));
		send_v2trap(notification_vars);
	}

	snmp_free_varbind(notification_vars);
}

void send_xfp1HighTxPower_notification(unsigned int clientreg, void *clientarg)
{
	DEBUGMSGTL(("token", "send_xfp1HighTxPower_notification.\n"));

	oid 	notification_oid[] = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 2, 2, 0, 38 };
	size_t  notification_oid_len = OID_LENGTH(notification_oid);
	oid 	objid_snmptrap[] = { 1, 3, 6, 1, 6, 3, 1, 1, 4, 1, 0 };
	size_t 	objid_snmptrap_len = OID_LENGTH(objid_snmptrap);
	oid 	xfp1HighTxPower_oid[]   = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 2, 2, 1, 3, 1, 9 };
	size_t 	xfp1HighTxPower_oid_len = OID_LENGTH(xfp1HighTxPower_oid);
	oid     xfp1HighTxPowerAlarmSev_oid[]   = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 3, 5, 1, 1, 9 };
	size_t	xfp1HighTxPowerAlarmSev_oid_len = OID_LENGTH(xfp1HighTxPowerAlarmSev_oid);

	netsnmp_variable_list *notification_vars = NULL;
	static u_long xfp1HighTxPowerCount = 0;

	unsigned int xfp1HighTxPowerAlarm = 0;

	unsigned int xfp1HighTxPower = 0;
	xfp1HighTxPower = pt_monitor_struct->xfp_struct.xfp_interruption_flags[0][1];

	unsigned int xfp1HighTxPowerAlarmSev = 0;
	xfp1HighTxPowerAlarmSev = pt_monitor_struct->xfp_struct.severity[0].high_tx_power;

	unsigned int send_xfp1HighTxPowerAlarm = 0;
	if (xfp1HighTxPowerTemp==0 && xfp1HighTxPower==1)
   {
		xfp1HighTxPowerAlarm = 1;
		send_xfp1HighTxPowerAlarm = 1;
   }
   else if (xfp1HighTxPowerTemp==1 && xfp1HighTxPower==0)
   {
	  xfp1HighTxPowerAlarm = 2;
      send_xfp1HighTxPowerAlarm = 1;
   }
	xfp1HighTxPowerTemp = xfp1HighTxPower;

	snmp_varlist_add_variable(&notification_vars, objid_snmptrap, objid_snmptrap_len, ASN_OBJECT_ID, (u_char *) notification_oid, notification_oid_len * sizeof(oid));
	snmp_varlist_add_variable(&notification_vars, xfp1HighTxPower_oid, xfp1HighTxPower_oid_len, ASN_INTEGER, (u_char *)&xfp1HighTxPowerAlarm, sizeof(xfp1HighTxPowerAlarm));
	snmp_varlist_add_variable(&notification_vars, xfp1HighTxPowerAlarmSev_oid, xfp1HighTxPowerAlarmSev_oid_len, ASN_INTEGER, (u_char *)&xfp1HighTxPowerAlarmSev, sizeof(xfp1HighTxPowerAlarmSev));

	if(send_xfp1HighTxPowerAlarm == 1)
	{
		++xfp1HighTxPowerCount;
		DEBUGMSGTL(("ftnc_notifications", "sending trap %ld\n",xfp1HighTxPowerCount));
		send_v2trap(notification_vars);
	}

	snmp_free_varbind(notification_vars);
}

void send_xfp1LowRxPower_notification(unsigned int clientreg, void *clientarg)
{
	DEBUGMSGTL(("token", "send_xfp1LowRxPower_notification.\n"));

	oid 	notification_oid[] = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 2, 2, 0, 39 };
	size_t 	notification_oid_len = OID_LENGTH(notification_oid);
	oid 	objid_snmptrap[] = { 1, 3, 6, 1, 6, 3, 1, 1, 4, 1, 0 };
	size_t 	objid_snmptrap_len = OID_LENGTH(objid_snmptrap);
	oid 	xfp1LowRxPower_oid[]   = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 2, 2, 1, 3, 1, 10 };
	size_t 	xfp1LowRxPower_oid_len = OID_LENGTH(xfp1LowRxPower_oid);
	oid     xfp1LowRxPowerAlarmSev_oid[]   = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 3, 5, 1, 1, 10 };
	size_t	xfp1LowRxPowerAlarmSev_oid_len = OID_LENGTH(xfp1LowRxPowerAlarmSev_oid);

	netsnmp_variable_list *notification_vars = NULL;
	static u_long xfp1LowRxPowerCount = 0;

	unsigned int xfp1LowRxPowerAlarm = 0;

	unsigned int xfp1LowRxPower = 0;
	xfp1LowRxPower = pt_monitor_struct->xfp_struct.xfp_interruption_flags[0][2];

	unsigned int xfp1LowRxPowerAlarmSev = 0;
	xfp1LowRxPowerAlarmSev = pt_monitor_struct->xfp_struct.severity[0].low_rx_power;

	unsigned int send_xfp1LowRxPowerAlarm = 0;
	if (xfp1LowRxPowerTemp==0 && xfp1LowRxPower==1)
   {
		xfp1LowRxPowerAlarm = 1;
		send_xfp1LowRxPowerAlarm = 1;
   }
   else if (xfp1LowRxPowerTemp==1 && xfp1LowRxPower==0)
   {
	  xfp1LowRxPowerAlarm = 2;
      send_xfp1LowRxPowerAlarm = 1;
   }
	xfp1LowRxPowerTemp = xfp1LowRxPower;

	snmp_varlist_add_variable(&notification_vars, objid_snmptrap, objid_snmptrap_len, ASN_OBJECT_ID, (u_char *) notification_oid, notification_oid_len * sizeof(oid));

	snmp_varlist_add_variable(&notification_vars, xfp1LowRxPower_oid, xfp1LowRxPower_oid_len, ASN_INTEGER, (u_char *)&xfp1LowRxPowerAlarm, sizeof(xfp1LowRxPowerAlarm));
	snmp_varlist_add_variable(&notification_vars, xfp1LowRxPowerAlarmSev_oid, xfp1LowRxPowerAlarmSev_oid_len, ASN_INTEGER, (u_char *)&xfp1LowRxPowerAlarmSev, sizeof(xfp1LowRxPowerAlarmSev));

	if(send_xfp1LowRxPowerAlarm == 1)
	{
		++xfp1LowRxPowerCount;
		DEBUGMSGTL(("ftnc_notifications", "sending trap %ld\n",xfp1LowRxPowerCount));
		send_v2trap(notification_vars);
	}

	snmp_free_varbind(notification_vars);
}

void send_xfp1HighRxPower_notification(unsigned int clientreg, void *clientarg)
{
	DEBUGMSGTL(("token", "send_xfp1HighRxPower_notification.\n"));

	oid notification_oid[] = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 2, 2, 0, 40 };
	size_t notification_oid_len = OID_LENGTH(notification_oid);
	oid 	objid_snmptrap[] = { 1, 3, 6, 1, 6, 3, 1, 1, 4, 1, 0 };
	size_t 	objid_snmptrap_len = OID_LENGTH(objid_snmptrap);
	oid 	xfp1HighRxPower_oid[]   = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 2, 2, 1, 3, 1, 11 };
	size_t 	xfp1HighRxPower_oid_len = OID_LENGTH(xfp1HighRxPower_oid);
	oid     xfp1HighRxPowerAlarmSev_oid[]   = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 3, 5, 1, 1, 11 };
	size_t	xfp1HighRxPowerAlarmSev_oid_len = OID_LENGTH(xfp1HighRxPowerAlarmSev_oid);

	netsnmp_variable_list *notification_vars = NULL;
	static u_long xfp1HighRxPowerCount = 0;

	unsigned int xfp1HighRxPowerAlarm = 0;

	unsigned int xfp1HighRxPower = 0;
	xfp1HighRxPower = pt_monitor_struct->xfp_struct.xfp_interruption_flags[0][3];

	unsigned int xfp1HighRxPowerAlarmSev = 0;
	xfp1HighRxPowerAlarmSev = pt_monitor_struct->xfp_struct.severity[0].high_rx_power;

	unsigned int send_xfp1HighRxPowerAlarm = 0;
	if (xfp1HighRxPowerTemp==0 && xfp1HighRxPower==1) //The alarm was activated.
   {
		xfp1HighRxPowerAlarm = 1; //The alarm was activated.
		send_xfp1HighRxPowerAlarm = 1; // Send notification.
   }
   else if (xfp1HighRxPowerTemp==1 && xfp1HighRxPower==0) //The alarm is deactivated.
   {
	  xfp1HighRxPowerAlarm = 2; //The alarm is deactivated.
      send_xfp1HighRxPowerAlarm = 1; //Send notification.
   }
	xfp1HighRxPowerTemp = xfp1HighRxPower;

	snmp_varlist_add_variable(&notification_vars, objid_snmptrap, objid_snmptrap_len, ASN_OBJECT_ID, (u_char *) notification_oid, notification_oid_len * sizeof(oid));
	snmp_varlist_add_variable(&notification_vars, xfp1HighRxPower_oid, xfp1HighRxPower_oid_len, ASN_INTEGER, (u_char *)&xfp1HighRxPowerAlarm, sizeof(xfp1HighRxPowerAlarm));
	snmp_varlist_add_variable(&notification_vars, xfp1HighRxPowerAlarmSev_oid, xfp1HighRxPowerAlarmSev_oid_len, ASN_INTEGER, (u_char *)&xfp1HighRxPowerAlarmSev, sizeof(xfp1HighRxPowerAlarmSev));

	if(send_xfp1HighRxPowerAlarm == 1)
	{
		++xfp1HighRxPowerCount;
		DEBUGMSGTL(("ftnc_notifications", "sending trap %ld\n",xfp1HighRxPowerCount));
		send_v2trap(notification_vars);
	}

	snmp_free_varbind(notification_vars);
}

void send_xfp1RxCdrLOL_notification(unsigned int clientreg, void *clientarg)
{
	DEBUGMSGTL(("token", "send_xfp1RxCdrLOL_notification.\n"));

	oid 	notification_oid[] = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 2, 2, 0, 41 };
	size_t 	notification_oid_len = OID_LENGTH(notification_oid);
	oid 	objid_snmptrap[] = { 1, 3, 6, 1, 6, 3, 1, 1, 4, 1, 0 };
	size_t 	objid_snmptrap_len = OID_LENGTH(objid_snmptrap);
	oid 	xfp1RxCdrLOL_oid[]   = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 2, 2, 1, 3, 1, 12 };
	size_t 	xfp1RxCdrLOL_oid_len = OID_LENGTH(xfp1RxCdrLOL_oid);
	oid     xfp1RxCdrLOLAlarmSev_oid[]   = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 3, 5, 1, 1, 12 };
	size_t  xfp1RxCdrLOLAlarmSev_oid_len = OID_LENGTH(xfp1RxCdrLOLAlarmSev_oid);

	netsnmp_variable_list *notification_vars = NULL;
	static u_long xfp1RxCdrLOLCount = 0;

	unsigned int xfp1RxCdrLOLAlarm = 0;

	unsigned int xfp1RxCdrLOL = 0;
	xfp1RxCdrLOL = pt_monitor_struct->xfp_struct.xfp_interruption_flags[0][4];

	unsigned int xfp1RxCdrLOLAlarmSev = 0;
	xfp1RxCdrLOLAlarmSev = pt_monitor_struct->xfp_struct.severity[0].rx_cdr_loss_of_lock;

	unsigned int send_xfp1RxCdrLOLAlarm = 0;
	if (xfp1RxCdrLOLTemp==0 && xfp1RxCdrLOL==1)
   {
		xfp1RxCdrLOLAlarm = 1;
		send_xfp1RxCdrLOLAlarm = 1;
   }
   else if (xfp1RxCdrLOLTemp==1 && xfp1RxCdrLOL==0)
   {
	   xfp1RxCdrLOLAlarm = 2;
      send_xfp1RxCdrLOLAlarm = 1;
   }
	xfp1RxCdrLOLTemp = xfp1RxCdrLOL;

	snmp_varlist_add_variable(&notification_vars, objid_snmptrap, objid_snmptrap_len, ASN_OBJECT_ID, (u_char *) notification_oid, notification_oid_len * sizeof(oid));
	snmp_varlist_add_variable(&notification_vars, xfp1RxCdrLOL_oid, xfp1RxCdrLOL_oid_len, ASN_INTEGER, (u_char *)&xfp1RxCdrLOLAlarm, sizeof(xfp1RxCdrLOLAlarm));
	snmp_varlist_add_variable(&notification_vars, xfp1RxCdrLOLAlarmSev_oid, xfp1RxCdrLOLAlarmSev_oid_len, ASN_INTEGER, (u_char *)&xfp1RxCdrLOLAlarmSev, sizeof(xfp1RxCdrLOLAlarmSev));

	if(send_xfp1RxCdrLOLAlarm == 1)
	{
		++xfp1RxCdrLOLCount;
		DEBUGMSGTL(("ftnc_notifications", "sending trap %ld\n",xfp1RxCdrLOLCount));
		send_v2trap(notification_vars);
	}

	snmp_free_varbind(notification_vars);
}

void send_xfp1TxCdrLOL_notification(unsigned int clientreg, void *clientarg)
{
	DEBUGMSGTL(("token", "send_xfp1TxCdrLOL_notification.\n"));

	oid notification_oid[] = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 2, 2, 0, 42 };
	size_t 	notification_oid_len = OID_LENGTH(notification_oid);
	oid 	objid_snmptrap[] = { 1, 3, 6, 1, 6, 3, 1, 1, 4, 1, 0 };
	size_t 	objid_snmptrap_len = OID_LENGTH(objid_snmptrap);
	oid 	xfp1TxCdrLOL_oid[]   = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 2, 2, 1, 3, 1, 13 };
	size_t 	xfp1TxCdrLOL_oid_len = OID_LENGTH(xfp1TxCdrLOL_oid);
	oid     xfp1TxCdrLOLAlarmSev_oid[]   = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 3, 5, 1, 1, 13 };
	size_t	xfp1TxCdrLOLAlarmSev_oid_len = OID_LENGTH(xfp1TxCdrLOLAlarmSev_oid);

	netsnmp_variable_list *notification_vars = NULL;
	static u_long xfp1TxCdrLOLCount = 0;

	unsigned int xfp1TxCdrLOLAlarm = 0;

	unsigned int xfp1TxCdrLOL = 0;
	xfp1TxCdrLOL = pt_monitor_struct->xfp_struct.xfp_interruption_flags[0][5];

	unsigned int xfp1TxCdrLOLAlarmSev = 0;
	xfp1TxCdrLOLAlarmSev = pt_monitor_struct->xfp_struct.severity[0].tx_cdr_loss_of_lock;

	unsigned int send_xfp1TxCdrLOLAlarm = 0;
	if (xfp1TxCdrLOLTemp==0 && xfp1TxCdrLOL==1)
   {
		xfp1TxCdrLOLAlarm = 1;
		send_xfp1TxCdrLOLAlarm = 1;
   }
   else if (xfp1TxCdrLOLTemp==1 && xfp1TxCdrLOL==0)
   {
	   xfp1TxCdrLOLAlarm = 2;
      send_xfp1TxCdrLOLAlarm = 1;
   }
	xfp1TxCdrLOLTemp = xfp1TxCdrLOL;

	snmp_varlist_add_variable(&notification_vars, objid_snmptrap, objid_snmptrap_len, ASN_OBJECT_ID, (u_char *) notification_oid, notification_oid_len * sizeof(oid));
	snmp_varlist_add_variable(&notification_vars, xfp1TxCdrLOL_oid, xfp1TxCdrLOL_oid_len, ASN_INTEGER, (u_char *)&xfp1TxCdrLOLAlarm, sizeof(xfp1TxCdrLOLAlarm));
	snmp_varlist_add_variable(&notification_vars, xfp1TxCdrLOLAlarmSev_oid, xfp1TxCdrLOLAlarmSev_oid_len, ASN_INTEGER, (u_char *)&xfp1TxCdrLOLAlarmSev, sizeof(xfp1TxCdrLOLAlarmSev));

	if(send_xfp1TxCdrLOLAlarm == 1)
	{
		++xfp1TxCdrLOLCount;
		DEBUGMSGTL(("ftnc_notifications", "sending trap %ld\n",xfp1TxCdrLOLCount));
		send_v2trap(notification_vars);
	}

	snmp_free_varbind(notification_vars);
}

void send_xfp1LaserFault_notification(unsigned int clientreg, void *clientarg)
{
	DEBUGMSGTL(("token", "send_xfp1LaserFault_notification.\n"));

	oid notification_oid[] = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 2, 2, 0, 43 };
	size_t notification_oid_len = OID_LENGTH(notification_oid);
	oid objid_snmptrap[] = { 1, 3, 6, 1, 6, 3, 1, 1, 4, 1, 0 };
	size_t objid_snmptrap_len = OID_LENGTH(objid_snmptrap);
	oid xfp1LaserFault_oid[]   = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 2, 2, 1, 3, 1, 14 };
	size_t xfp1LaserFault_oid_len = OID_LENGTH(xfp1LaserFault_oid);
	oid      xfp1xfp1LaserFaultAlarmSev_oid[]   = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 3, 5, 1, 1, 14 };
	size_t   xfp1xfp1LaserFaultAlarmSev_oid_len = OID_LENGTH(xfp1xfp1LaserFaultAlarmSev_oid);

	netsnmp_variable_list *notification_vars = NULL;
	static u_long xfp1LaserFaultCount = 0;

	unsigned int xfp1LaserFaultAlarm = 0;

	unsigned int xfp1LaserFault = 0;
	xfp1LaserFault = pt_monitor_struct->xfp_struct.xfp_interruption_flags[0][6];

	unsigned int xfp1xfp1LaserFaultAlarmSev = 0;
	xfp1xfp1LaserFaultAlarmSev = pt_monitor_struct->xfp_struct.severity[0].laser_fault;

	unsigned int send_xfp1LaserFaultAlarm = 0;
	if (xfp1LaserFaultTemp==0 && xfp1LaserFault==1)
   {
		xfp1LaserFaultAlarm = 1;
		send_xfp1LaserFaultAlarm = 1;
   }
   else if (xfp1LaserFaultTemp==1 && xfp1LaserFault==0)
   {
	   xfp1LaserFaultAlarm = 2;
      send_xfp1LaserFaultAlarm = 1;
   }
	xfp1LaserFaultTemp = xfp1LaserFault;

	snmp_varlist_add_variable(&notification_vars, objid_snmptrap, objid_snmptrap_len, ASN_OBJECT_ID, (u_char *) notification_oid, notification_oid_len * sizeof(oid));
	snmp_varlist_add_variable(&notification_vars, xfp1LaserFault_oid, xfp1LaserFault_oid_len, ASN_INTEGER, (u_char *)&xfp1LaserFaultAlarm, sizeof(xfp1LaserFaultAlarm));
	snmp_varlist_add_variable(&notification_vars, xfp1xfp1LaserFaultAlarmSev_oid, xfp1xfp1LaserFaultAlarmSev_oid_len, ASN_INTEGER, (u_char *)&xfp1xfp1LaserFaultAlarmSev, sizeof(xfp1xfp1LaserFaultAlarmSev));

	if(send_xfp1LaserFaultAlarm == 1)
	{
		++xfp1LaserFaultCount;
		DEBUGMSGTL(("ftnc_notifications", "sending trap %ld\n",xfp1LaserFaultCount));
		send_v2trap(notification_vars);
	}

	snmp_free_varbind(notification_vars);
}

/* ***************** Implementation of XFP2 methods ***************** */

void send_xfp2Presence_notification(unsigned int clientreg, void *clientarg)
{
	DEBUGMSGTL(("token", "send_xfp2Presence_notification.\n"));

	oid 	notification_oid[] = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 2, 2, 0, 44 };
	size_t 	notification_oid_len = OID_LENGTH(notification_oid);
	oid 	objid_snmptrap[] = { 1, 3, 6, 1, 6, 3, 1, 1, 4, 1, 0 };
	size_t 	objid_snmptrap_len = OID_LENGTH(objid_snmptrap);
	oid 	xfp2Presence_oid[]   = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 2, 2, 1, 4, 1, 2 };
	size_t  xfp2Presence_oid_len = OID_LENGTH(xfp2Presence_oid);
	oid     xfp2PresenceAlarmSev_oid[]   = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 3, 5, 2, 1, 2 };
	size_t	xfp2PresenceAlarmSev_oid_len = OID_LENGTH(xfp2PresenceAlarmSev_oid);

	netsnmp_variable_list *notification_vars = NULL;
	static u_long xfp2PresenceCount = 0;

	unsigned int xfp2PresenceAlarm = 0;
	unsigned int xfp2Presence = 0;
	//xfp2Presence = 0 is present; xfp2Presence = 1 is not present.
	xfp2Presence = pt_monitor_struct->xfp_struct.xfp_presence[1];

	unsigned int xfp2PresenceAlarmSev = 0;
	xfp2PresenceAlarmSev = pt_monitor_struct->xfp_struct.severity[1].presence;

	unsigned int send_xfp2PresenceAlarm = 0;
	if (xfp2PresenceTemp==0 && xfp2Presence==1) //The alarm was activated.
   {
		xfp2PresenceAlarm = 1; //The alarm was activated.
		send_xfp2PresenceAlarm = 1; // Send notification.
   }
   else if (xfp2PresenceTemp==1 && xfp2Presence==0) //The alarm is deactivated.
   {
	   xfp2PresenceAlarm = 2; //The alarm is deactivated.
      send_xfp2PresenceAlarm = 1; //Send notification.
   }
	xfp2PresenceTemp = xfp2Presence;

	snmp_varlist_add_variable(&notification_vars, objid_snmptrap, objid_snmptrap_len, ASN_OBJECT_ID, (u_char *) notification_oid, notification_oid_len * sizeof(oid));
	snmp_varlist_add_variable(&notification_vars, xfp2Presence_oid, xfp2Presence_oid_len, ASN_INTEGER, (u_char *)&xfp2PresenceAlarm, sizeof(xfp2PresenceAlarm));
	snmp_varlist_add_variable(&notification_vars, xfp2PresenceAlarmSev_oid, xfp2PresenceAlarmSev_oid_len, ASN_INTEGER, (u_char *)&xfp2PresenceAlarmSev, sizeof(xfp2PresenceAlarmSev));

	if(send_xfp2PresenceAlarm == 1)
	{
		++xfp2PresenceCount;
		DEBUGMSGTL(("ftnc_notifications", "xfp2PresenceCount sending trap %ld\n",xfp2PresenceCount));
		send_v2trap(notification_vars);
	}

	snmp_free_varbind(notification_vars);
}

void send_xfp2RxLoss_notification(unsigned int clientreg, void *clientarg)
{
	DEBUGMSGTL(("token", "send_xfp2RxLoss_notification.\n"));

	oid 	notification_oid[] = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 2, 2, 0, 45 };
	size_t 	notification_oid_len = OID_LENGTH(notification_oid);
	oid 	objid_snmptrap[] = { 1, 3, 6, 1, 6, 3, 1, 1, 4, 1, 0 };
	size_t 	objid_snmptrap_len = OID_LENGTH(objid_snmptrap);
	oid 	xfp2RxLoss_oid[]   = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 2, 2, 1, 4, 1, 3 };
	size_t 	xfp2RxLoss_oid_len = OID_LENGTH(xfp2RxLoss_oid);
	oid     xfp2RxLossAlarmSev_oid[]   = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 3, 5, 2, 1, 3 };
	size_t	xfp2RxLossAlarmSev_oid_len = OID_LENGTH(xfp2RxLossAlarmSev_oid);

	netsnmp_variable_list *notification_vars = NULL;
	static u_long xfp2RxLossCount = 0;

	unsigned int xfp2RxLossAlarm = 0;

	unsigned int xfp2RxLoss = 0;
	xfp2RxLoss = pt_monitor_struct->xfp_struct.xfp_presence[1];

	unsigned int xfp2RxLossAlarmSev = 0;
	xfp2RxLossAlarmSev = pt_monitor_struct->xfp_struct.severity[1].rx_loss;

	unsigned int send_xfp2RxLossAlarm = 0;
	if (xfp2RxLossTemp==0 && xfp2RxLoss==1)
   {
		xfp2RxLossAlarm = 1;
		send_xfp2RxLossAlarm = 1;
   }
   else if (xfp2RxLossTemp==1 && xfp2RxLoss==0)
   {
	   xfp2RxLossAlarm = 2;
      send_xfp2RxLossAlarm = 1;
   }
	xfp2RxLossTemp = xfp2RxLoss;

	snmp_varlist_add_variable(&notification_vars, objid_snmptrap, objid_snmptrap_len, ASN_OBJECT_ID, (u_char *) notification_oid, notification_oid_len * sizeof(oid));
	snmp_varlist_add_variable(&notification_vars, xfp2RxLoss_oid, xfp2RxLoss_oid_len, ASN_INTEGER, (u_char *)&xfp2RxLossAlarm, sizeof(xfp2RxLossAlarm));
	snmp_varlist_add_variable(&notification_vars, xfp2RxLossAlarmSev_oid, xfp2RxLossAlarmSev_oid_len, ASN_INTEGER, (u_char *)&xfp2RxLossAlarmSev, sizeof(xfp2RxLossAlarmSev));

	if(send_xfp2RxLossAlarm == 1)
	{
		++xfp2RxLossCount;
		DEBUGMSGTL(("ftnc_notifications", "sending trap %ld\n",xfp2RxLossCount));
		send_v2trap(notification_vars);
	}

	snmp_free_varbind(notification_vars);
}

void send_xfp2Ready_notification(unsigned int clientreg, void *clientarg)
{
	DEBUGMSGTL(("token", "send_xfp2Ready_notification.\n"));

	oid 	notification_oid[] = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 2, 2, 0, 46 };
	size_t 	notification_oid_len = OID_LENGTH(notification_oid);
	oid 	objid_snmptrap[] = { 1, 3, 6, 1, 6, 3, 1, 1, 4, 1, 0 };
	size_t 	objid_snmptrap_len = OID_LENGTH(objid_snmptrap);
	oid 	xfp2Ready_oid[]   = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 2, 2, 1, 4, 1, 4 };
	size_t 	xfp2Ready_oid_len = OID_LENGTH(xfp2Ready_oid);
	oid     xfp2ReadyAlarmSev_oid[]   = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 3, 5, 2, 1, 4 };
	size_t	xfp2ReadyAlarmSev_oid_len = OID_LENGTH(xfp2ReadyAlarmSev_oid);

	netsnmp_variable_list *notification_vars = NULL;
	static u_long xfp2ReadyCount = 0;

	unsigned int xfp2ReadyAlarm = 0;

	unsigned int xfp2Ready = 0;
	xfp2Ready = pt_monitor_struct->xfp_struct.xfp_ready[1];

	unsigned int xfp2ReadyAlarmSev = 0;
	xfp2ReadyAlarmSev = pt_monitor_struct->xfp_struct.severity[1].ready;

	unsigned int send_xfp2ReadyAlarm = 0;
	if (xfp2ReadyTemp==0 && xfp2Ready==1)
   {
		xfp2ReadyAlarm = 1;
		send_xfp2ReadyAlarm = 1;
   }
   else if (xfp2ReadyTemp==1 && xfp2Ready==0)
   {
	  xfp2ReadyAlarm = 2;
      send_xfp2ReadyAlarm = 1;
   }
	xfp2ReadyTemp = xfp2Ready;

	snmp_varlist_add_variable(&notification_vars, objid_snmptrap, objid_snmptrap_len, ASN_OBJECT_ID, (u_char *) notification_oid, notification_oid_len * sizeof(oid));
	snmp_varlist_add_variable(&notification_vars, xfp2Ready_oid, xfp2Ready_oid_len, ASN_INTEGER, (u_char *)&xfp2ReadyAlarm, sizeof(xfp2ReadyAlarm));
	snmp_varlist_add_variable(&notification_vars, xfp2ReadyAlarmSev_oid, xfp2ReadyAlarmSev_oid_len, ASN_INTEGER, (u_char *)&xfp2ReadyAlarmSev, sizeof(xfp2ReadyAlarmSev));

	if(send_xfp2ReadyAlarm == 1)
	{
		++xfp2ReadyCount;
		DEBUGMSGTL(("ftnc_notifications", "sending trap %ld\n",xfp2ReadyCount));
		send_v2trap(notification_vars);
	}

	snmp_free_varbind(notification_vars);
}

void send_xfp2TxPower_notification(unsigned int clientreg, void *clientarg)
{
	DEBUGMSGTL(("token", "send_xfp2TxPower_notification.\n"));

   oid      notification_oid[] =  { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 2, 2, 0, 47 };
   size_t   notification_oid_len = OID_LENGTH(notification_oid);
   oid      objid_snmptrap[] = { 1, 3, 6, 1, 6, 3, 1, 1, 4, 1, 0 };
   size_t   objid_snmptrap_len = OID_LENGTH(objid_snmptrap);
   oid		xfp2TxPowerAlarm_oid[]   = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 2, 2, 1, 4, 1, 5 };
   size_t	xfp2TxPowerAlarm_oid_len = OID_LENGTH(xfp2TxPowerAlarm_oid);
   oid	xfp2TxPowerAlarmSev_oid[]   = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 3, 5, 2, 1, 5 };
   size_t	xfp2TxPowerAlarmSev_oid_len = OID_LENGTH(xfp2TxPowerAlarmSev_oid);

   netsnmp_variable_list *notification_vars = NULL;
   static u_long  xfp2TxPowerCount = 0;

   unsigned int xfp2TxPowerInt = 0;
   unsigned int xfp2TxPowerAlarm = 0;

   unsigned int send_xfp2TxPowerAlarm = 0;

   float xfp2TxPower;
   xfp2TxPower = pt_monitor_struct->xfp_struct.xfp_tx_power[1];

   unsigned int xfp2TxPowerAlarmSev = 0;
   xfp2TxPowerAlarmSev = pt_monitor_struct->xfp_struct.severity[1].tx_power;

   if (xfp2TxPower < -3 || xfp2TxPower > 0)
   { xfp2TxPowerInt = 1; }
   else
   { xfp2TxPowerInt = 0; }

   if (xfp2TxPowerTemp==0 && xfp2TxPowerInt==1)
   {
	   xfp2TxPowerAlarm = 1;
	   send_xfp2TxPowerAlarm = 1;
   }
   else if (xfp2TxPowerTemp==1 && xfp2TxPowerInt==0)
   {
	   xfp2TxPowerAlarm = 2;
	   send_xfp2TxPowerAlarm = 1;
   }
   xfp2TxPowerTemp = xfp2TxPowerInt;

   snmp_varlist_add_variable(&notification_vars, objid_snmptrap, objid_snmptrap_len, ASN_OBJECT_ID, (u_char *) notification_oid, notification_oid_len * sizeof(oid));
   snmp_varlist_add_variable(&notification_vars,  xfp2TxPowerAlarm_oid, xfp2TxPowerAlarm_oid_len, ASN_INTEGER, (u_char *)&xfp2TxPowerAlarm, sizeof(xfp2TxPowerAlarm));
   snmp_varlist_add_variable(&notification_vars, xfp2TxPowerAlarmSev_oid, xfp2TxPowerAlarmSev_oid_len, ASN_INTEGER, (u_char *)&xfp2TxPowerAlarmSev, sizeof(xfp2TxPowerAlarmSev));

   if(send_xfp2TxPowerAlarm == 1)
   {
       ++xfp2TxPowerCount;
       DEBUGMSGTL(("ftnc_notifications", "sending trap %ld\n",xfp2TxPowerCount));
       send_v2trap(notification_vars);
   }

   snmp_free_varbind(notification_vars);
}

void send_xfp2RxPower_notification(unsigned int clientreg, void *clientarg)
{
	DEBUGMSGTL(("token", "send_xfp2RxPower_notification.\n"));

   oid      notification_oid[] =  { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 2, 2, 0, 48 };
   size_t   notification_oid_len = OID_LENGTH(notification_oid);
   oid      objid_snmptrap[] = { 1, 3, 6, 1, 6, 3, 1, 1, 4, 1, 0 };
   size_t   objid_snmptrap_len = OID_LENGTH(objid_snmptrap);
   oid      xfp2RxPowerAlarm_oid[]   = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 2, 2, 1, 4, 1, 6 };
   size_t	xfp2RxPowerAlarm_oid_len = OID_LENGTH(xfp2RxPowerAlarm_oid);
   oid      xfp2RxPowerAlarmSev_oid[]   = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 3, 5, 2, 1, 6 };
   size_t   xfp2RxPowerAlarmSev_oid_len = OID_LENGTH(xfp2RxPowerAlarmSev_oid);

   netsnmp_variable_list *notification_vars = NULL;
   static u_long  xfp2RxPowerCount = 0;

   unsigned int xfp2RxPowerInt = 0;
   unsigned int xfp2RxPowerAlarm = 0;

   unsigned int send_xfp2RxPowerAlarm = 0;

   float xfp2RxPower;
   xfp2RxPower = pt_monitor_struct->xfp_struct.xfp_rx_power[1];

   unsigned int xfp2RxPowerAlarmSev = 0;
   xfp2RxPowerAlarmSev = pt_monitor_struct->xfp_struct.severity[1].rx_power;

   if (xfp2RxPower < -3 || xfp2RxPower > 0)
   { xfp2RxPowerInt = 1; }
   else
   { xfp2RxPowerInt = 0; }

   if (xfp2RxPowerTemp==0 && xfp2RxPowerInt==1)
   {
	   xfp2RxPowerAlarm = 1;
	   send_xfp2RxPowerAlarm = 1;
   }
   else if (xfp2RxPowerTemp==1 && xfp2RxPowerInt==0)
   {
	   xfp2RxPowerAlarm = 2;
	   send_xfp2RxPowerAlarm = 1;
   }
   xfp2RxPowerTemp = xfp2RxPowerInt;

   snmp_varlist_add_variable(&notification_vars, objid_snmptrap, objid_snmptrap_len, ASN_OBJECT_ID, (u_char *) notification_oid, notification_oid_len * sizeof(oid));
   snmp_varlist_add_variable(&notification_vars,  xfp2RxPowerAlarm_oid, xfp2RxPowerAlarm_oid_len, ASN_INTEGER, (u_char *)&xfp2RxPowerAlarm, sizeof(xfp2RxPowerAlarm));
   snmp_varlist_add_variable(&notification_vars, xfp2RxPowerAlarmSev_oid, xfp2RxPowerAlarmSev_oid_len, ASN_INTEGER, (u_char *)&xfp2RxPowerAlarmSev, sizeof(xfp2RxPowerAlarmSev));

   if(send_xfp2RxPowerAlarm == 1)
   {
       ++xfp2RxPowerCount;
       DEBUGMSGTL(("ftnc_notifications", "sending trap %ld\n",xfp2RxPowerCount));
       send_v2trap(notification_vars);
   }

   snmp_free_varbind(notification_vars);
}

void send_xfp2Temperature_notification(unsigned int clientreg, void *clientarg)
{
	DEBUGMSGTL(("token", "send_xfp2Temperature_notification.\n"));

   oid      notification_oid[] =  { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 2, 2, 0, 49 };
   size_t   notification_oid_len = OID_LENGTH(notification_oid);
   oid      objid_snmptrap[] = { 1, 3, 6, 1, 6, 3, 1, 1, 4, 1, 0 };
   size_t   objid_snmptrap_len = OID_LENGTH(objid_snmptrap);
   oid      xfp2TemperatureAlarm_oid[]   = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 2, 2, 1, 4, 1, 7 };
   size_t   xfp2TemperatureAlarm_oid_len = OID_LENGTH(xfp2TemperatureAlarm_oid);
   oid      xfp2TemperatureAlarmSev_oid[]   = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 3, 5, 2, 1, 7 };
   size_t   xfp2TemperatureAlarmSev_oid_len = OID_LENGTH(xfp2TemperatureAlarmSev_oid);

   netsnmp_variable_list *notification_vars = NULL;
   static u_long  xfp2TemperatureCount = 0;

   unsigned int xfp2TemperatureInt = 0;
   unsigned int xfp2TemperatureAlarm = 0;

   unsigned int send_xfp2TemperatureAlarm = 0;

   float xfp2Temperature;
   xfp2Temperature = pt_monitor_struct->xfp_struct.xfp_temperature[1];

   unsigned int xfp2TemperatureAlarmSev = 0;
   xfp2TemperatureAlarmSev = pt_monitor_struct->xfp_struct.severity[1].temperature;

   if (xfp2Temperature < 10 || xfp2Temperature > 30)
   { xfp2TemperatureInt = 1; }
   else
   { xfp2TemperatureInt = 0; }

   if (xfp2TemperatureTemp==0 && xfp2TemperatureInt==1)
   {
	   xfp2TemperatureAlarm = 1;
	   send_xfp2TemperatureAlarm = 1;
   }
   else if (xfp2TemperatureTemp==1 && xfp2TemperatureInt==0)
   {
	   xfp2TemperatureAlarm = 2;
	   send_xfp2TemperatureAlarm = 1;
   }
   xfp2TemperatureTemp = xfp2TemperatureInt;

   snmp_varlist_add_variable(&notification_vars, objid_snmptrap, objid_snmptrap_len, ASN_OBJECT_ID, (u_char *) notification_oid, notification_oid_len * sizeof(oid));
   snmp_varlist_add_variable(&notification_vars,  xfp2TemperatureAlarm_oid, xfp2TemperatureAlarm_oid_len, ASN_INTEGER, (u_char *)&xfp2TemperatureAlarm, sizeof(xfp2TemperatureAlarm));
   snmp_varlist_add_variable(&notification_vars, xfp2TemperatureAlarmSev_oid, xfp2TemperatureAlarmSev_oid_len, ASN_INTEGER, (u_char *)&xfp2TemperatureAlarmSev, sizeof(xfp2TemperatureAlarmSev));

   if(send_xfp2TemperatureAlarm == 1)
   {
       ++xfp2TemperatureCount;
       DEBUGMSGTL(("ftnc_notifications", "sending trap %ld\n",xfp2TemperatureCount));
       send_v2trap(notification_vars);
   }

   snmp_free_varbind(notification_vars);
}

void send_xfp2LowTxPower_notification(unsigned int clientreg, void *clientarg)
{
	DEBUGMSGTL(("token", "send_xfp2LowTxPower_notification.\n"));

	oid 	notification_oid[] = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 2, 2, 0, 50 };
	size_t 	notification_oid_len = OID_LENGTH(notification_oid);
	oid 	objid_snmptrap[] = { 1, 3, 6, 1, 6, 3, 1, 1, 4, 1, 0 };
	size_t 	objid_snmptrap_len = OID_LENGTH(objid_snmptrap);
	oid 	xfp2LowTxPower_oid[]   = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 2, 2, 1, 4, 1, 8 };
	size_t 	xfp2LowTxPower_oid_len = OID_LENGTH(xfp2LowTxPower_oid);
	oid     xfp2LowTxPowerAlarmSev_oid[]   = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 3, 5, 2, 1, 8 };
	size_t  xfp2LowTxPowerAlarmSev_oid_len = OID_LENGTH(xfp2LowTxPowerAlarmSev_oid);

	netsnmp_variable_list *notification_vars = NULL;
	static u_long xfp2LowTxPowerCount = 0;

	unsigned int xfp2LowTxPowerAlarm = 0;

	unsigned int xfp2LowTxPower = 0;
	xfp2LowTxPower = pt_monitor_struct->xfp_struct.xfp_interruption_flags[1][0];

	unsigned int xfp2LowTxPowerAlarmSev = 0;
	xfp2LowTxPowerAlarmSev = pt_monitor_struct->xfp_struct.severity[1].low_tx_power;

	unsigned int send_xfp2LowTxPowerAlarm = 0;
	if (xfp2LowTxPowerTemp==0 && xfp2LowTxPower==1)
   {
		xfp2LowTxPowerAlarm = 1;
		send_xfp2LowTxPowerAlarm = 1;
   }
   else if (xfp2LowTxPowerTemp==1 && xfp2LowTxPower==0)
   {
	  xfp2LowTxPowerAlarm = 2;
      send_xfp2LowTxPowerAlarm = 1;
   }
	xfp2LowTxPowerTemp = xfp2LowTxPower;

	snmp_varlist_add_variable(&notification_vars, objid_snmptrap, objid_snmptrap_len, ASN_OBJECT_ID, (u_char *) notification_oid, notification_oid_len * sizeof(oid));
	snmp_varlist_add_variable(&notification_vars, xfp2LowTxPower_oid, xfp2LowTxPower_oid_len, ASN_INTEGER, (u_char *)&xfp2LowTxPowerAlarm, sizeof(xfp2LowTxPowerAlarm));
	snmp_varlist_add_variable(&notification_vars, xfp2LowTxPowerAlarmSev_oid, xfp2LowTxPowerAlarmSev_oid_len, ASN_INTEGER, (u_char *)&xfp2LowTxPowerAlarmSev, sizeof(xfp2LowTxPowerAlarmSev));

	if(send_xfp2LowTxPowerAlarm == 1)
	{
		++xfp2LowTxPowerCount;
		DEBUGMSGTL(("ftnc_notifications", "sending trap %ld\n",xfp2LowTxPowerCount));
		send_v2trap(notification_vars);
	}

	snmp_free_varbind(notification_vars);
}

void send_xfp2HighTxPower_notification(unsigned int clientreg, void *clientarg)
{
	DEBUGMSGTL(("token", "send_xfp2HighTxPower_notification.\n"));

	oid 	notification_oid[] = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 2, 2, 0, 51 };
	size_t  notification_oid_len = OID_LENGTH(notification_oid);
	oid 	objid_snmptrap[] = { 1, 3, 6, 1, 6, 3, 1, 1, 4, 1, 0 };
	size_t 	objid_snmptrap_len = OID_LENGTH(objid_snmptrap);
	oid 	xfp2HighTxPower_oid[]   = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 2, 2, 1, 4, 1, 9 };
	size_t 	xfp2HighTxPower_oid_len = OID_LENGTH(xfp2HighTxPower_oid);
	oid     xfp2HighTxPowerAlarmSev_oid[]   = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 3, 5, 2, 1, 9 };
	size_t	xfp2HighTxPowerAlarmSev_oid_len = OID_LENGTH(xfp2HighTxPowerAlarmSev_oid);

	netsnmp_variable_list *notification_vars = NULL;
	static u_long xfp2HighTxPowerCount = 0;

	unsigned int xfp2HighTxPowerAlarm = 0;

	unsigned int xfp2HighTxPower = 0;
	xfp2HighTxPower = pt_monitor_struct->xfp_struct.xfp_interruption_flags[1][1];

	unsigned int xfp2HighTxPowerAlarmSev = 0;
	xfp2HighTxPowerAlarmSev = pt_monitor_struct->xfp_struct.severity[1].high_tx_power;

	unsigned int send_xfp2HighTxPowerAlarm = 0;
	if (xfp2HighTxPowerTemp==0 && xfp2HighTxPower==1)
   {
		xfp2HighTxPowerAlarm = 1;
		send_xfp2HighTxPowerAlarm = 1;
   }
   else if (xfp2HighTxPowerTemp==1 && xfp2HighTxPower==0)
   {
	  xfp2HighTxPowerAlarm = 2;
      send_xfp2HighTxPowerAlarm = 1;
   }
	xfp2HighTxPowerTemp = xfp2HighTxPower;

	snmp_varlist_add_variable(&notification_vars, objid_snmptrap, objid_snmptrap_len, ASN_OBJECT_ID, (u_char *) notification_oid, notification_oid_len * sizeof(oid));
	snmp_varlist_add_variable(&notification_vars, xfp2HighTxPower_oid, xfp2HighTxPower_oid_len, ASN_INTEGER, (u_char *)&xfp2HighTxPowerAlarm, sizeof(xfp2HighTxPowerAlarm));
	snmp_varlist_add_variable(&notification_vars, xfp2HighTxPowerAlarmSev_oid, xfp2HighTxPowerAlarmSev_oid_len, ASN_INTEGER, (u_char *)&xfp2HighTxPowerAlarmSev, sizeof(xfp2HighTxPowerAlarmSev));

	if(send_xfp2HighTxPowerAlarm == 1)
	{
		++xfp2HighTxPowerCount;
		DEBUGMSGTL(("ftnc_notifications", "sending trap %ld\n",xfp2HighTxPowerCount));
		send_v2trap(notification_vars);
	}

	snmp_free_varbind(notification_vars);
}

void send_xfp2LowRxPower_notification(unsigned int clientreg, void *clientarg)
{
	DEBUGMSGTL(("token", "send_xfp2LowRxPower_notification.\n"));

	oid 	notification_oid[] = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 2, 2, 0, 52 };
	size_t 	notification_oid_len = OID_LENGTH(notification_oid);
	oid 	objid_snmptrap[] = { 1, 3, 6, 1, 6, 3, 1, 1, 4, 1, 0 };
	size_t 	objid_snmptrap_len = OID_LENGTH(objid_snmptrap);
	oid 	xfp2LowRxPower_oid[]   = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 2, 2, 1, 4, 1, 10 };
	size_t 	xfp2LowRxPower_oid_len = OID_LENGTH(xfp2LowRxPower_oid);
	oid     xfp2LowRxPowerAlarmSev_oid[]   = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 3, 5, 2, 1, 10 };
	size_t	xfp2LowRxPowerAlarmSev_oid_len = OID_LENGTH(xfp2LowRxPowerAlarmSev_oid);

	netsnmp_variable_list *notification_vars = NULL;
	static u_long xfp2LowRxPowerCount = 0;

	unsigned int xfp2LowRxPowerAlarm = 0;

	unsigned int xfp2LowRxPower = 0;
	xfp2LowRxPower = pt_monitor_struct->xfp_struct.xfp_interruption_flags[1][2];

	unsigned int xfp2LowRxPowerAlarmSev = 0;
	xfp2LowRxPowerAlarmSev = pt_monitor_struct->xfp_struct.severity[1].low_rx_power;

	unsigned int send_xfp2LowRxPowerAlarm = 0;
	if (xfp2LowRxPowerTemp==0 && xfp2LowRxPower==1)
   {
		xfp2LowRxPowerAlarm = 1;
		send_xfp2LowRxPowerAlarm = 1;
   }
   else if (xfp2LowRxPowerTemp==1 && xfp2LowRxPower==0)
   {
	  xfp2LowRxPowerAlarm = 2;
      send_xfp2LowRxPowerAlarm = 1;
   }
	xfp2LowRxPowerTemp = xfp2LowRxPower;

	snmp_varlist_add_variable(&notification_vars, objid_snmptrap, objid_snmptrap_len, ASN_OBJECT_ID, (u_char *) notification_oid, notification_oid_len * sizeof(oid));

	snmp_varlist_add_variable(&notification_vars, xfp2LowRxPower_oid, xfp2LowRxPower_oid_len, ASN_INTEGER, (u_char *)&xfp2LowRxPowerAlarm, sizeof(xfp2LowRxPowerAlarm));
	snmp_varlist_add_variable(&notification_vars, xfp2LowRxPowerAlarmSev_oid, xfp2LowRxPowerAlarmSev_oid_len, ASN_INTEGER, (u_char *)&xfp2LowRxPowerAlarmSev, sizeof(xfp2LowRxPowerAlarmSev));

	if(send_xfp2LowRxPowerAlarm == 1)
	{
		++xfp2LowRxPowerCount;
		DEBUGMSGTL(("ftnc_notifications", "sending trap %ld\n",xfp2LowRxPowerCount));
		send_v2trap(notification_vars);
	}

	snmp_free_varbind(notification_vars);
}

void send_xfp2HighRxPower_notification(unsigned int clientreg, void *clientarg)
{
	DEBUGMSGTL(("token", "send_xfp2HighRxPower_notification.\n"));

	oid notification_oid[] = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 2, 2, 0, 53 };
	size_t notification_oid_len = OID_LENGTH(notification_oid);
	oid 	objid_snmptrap[] = { 1, 3, 6, 1, 6, 3, 1, 1, 4, 1, 0 };
	size_t 	objid_snmptrap_len = OID_LENGTH(objid_snmptrap);
	oid 	xfp2HighRxPower_oid[]   = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 2, 2, 1, 4, 1, 11 };
	size_t 	xfp2HighRxPower_oid_len = OID_LENGTH(xfp2HighRxPower_oid);
	oid     xfp2HighRxPowerAlarmSev_oid[]   = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 3, 5, 2, 1, 11 };
	size_t	xfp2HighRxPowerAlarmSev_oid_len = OID_LENGTH(xfp2HighRxPowerAlarmSev_oid);

	netsnmp_variable_list *notification_vars = NULL;
	static u_long xfp2HighRxPowerCount = 0;

	unsigned int xfp2HighRxPowerAlarm = 0;

	unsigned int xfp2HighRxPower = 0;
	xfp2HighRxPower = pt_monitor_struct->xfp_struct.xfp_interruption_flags[1][3];

	unsigned int xfp2HighRxPowerAlarmSev = 0;
	xfp2HighRxPowerAlarmSev = pt_monitor_struct->xfp_struct.severity[1].high_rx_power;

	unsigned int send_xfp2HighRxPowerAlarm = 0;
	if (xfp2HighRxPowerTemp==0 && xfp2HighRxPower==1) //The alarm was activated.
   {
		xfp2HighRxPowerAlarm = 1; //The alarm was activated.
		send_xfp2HighRxPowerAlarm = 1; // Send notification.
   }
   else if (xfp2HighRxPowerTemp==1 && xfp2HighRxPower==0) //The alarm is deactivated.
   {
	  xfp2HighRxPowerAlarm = 2; //The alarm is deactivated.
      send_xfp2HighRxPowerAlarm = 1; //Send notification.
   }
	xfp2HighRxPowerTemp = xfp2HighRxPower;

	snmp_varlist_add_variable(&notification_vars, objid_snmptrap, objid_snmptrap_len, ASN_OBJECT_ID, (u_char *) notification_oid, notification_oid_len * sizeof(oid));
	snmp_varlist_add_variable(&notification_vars, xfp2HighRxPower_oid, xfp2HighRxPower_oid_len, ASN_INTEGER, (u_char *)&xfp2HighRxPowerAlarm, sizeof(xfp2HighRxPowerAlarm));
	snmp_varlist_add_variable(&notification_vars, xfp2HighRxPowerAlarmSev_oid, xfp2HighRxPowerAlarmSev_oid_len, ASN_INTEGER, (u_char *)&xfp2HighRxPowerAlarmSev, sizeof(xfp2HighRxPowerAlarmSev));

	if(send_xfp2HighRxPowerAlarm == 1)
	{
		++xfp2HighRxPowerCount;
		DEBUGMSGTL(("ftnc_notifications", "sending trap %ld\n",xfp2HighRxPowerCount));
		send_v2trap(notification_vars);
	}

	snmp_free_varbind(notification_vars);
}

void send_xfp2RxCdrLOL_notification(unsigned int clientreg, void *clientarg)
{
	DEBUGMSGTL(("token", "send_xfp2RxCdrLOL_notification.\n"));

	oid 	notification_oid[] = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 2, 2, 0, 54 };
	size_t 	notification_oid_len = OID_LENGTH(notification_oid);
	oid 	objid_snmptrap[] = { 1, 3, 6, 1, 6, 3, 1, 1, 4, 1, 0 };
	size_t 	objid_snmptrap_len = OID_LENGTH(objid_snmptrap);
	oid 	xfp2RxCdrLOL_oid[]   = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 2, 2, 1, 4, 1, 12 };
	size_t 	xfp2RxCdrLOL_oid_len = OID_LENGTH(xfp2RxCdrLOL_oid);
	oid     xfp2RxCdrLOLAlarmSev_oid[]   = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 3, 5, 2, 1, 12 };
	size_t  xfp2RxCdrLOLAlarmSev_oid_len = OID_LENGTH(xfp2RxCdrLOLAlarmSev_oid);

	netsnmp_variable_list *notification_vars = NULL;
	static u_long xfp2RxCdrLOLCount = 0;

	unsigned int xfp2RxCdrLOLAlarm = 0;

	unsigned int xfp2RxCdrLOL = 0;
	xfp2RxCdrLOL = pt_monitor_struct->xfp_struct.xfp_interruption_flags[1][4];

	unsigned int xfp2RxCdrLOLAlarmSev = 0;
	xfp2RxCdrLOLAlarmSev = pt_monitor_struct->xfp_struct.severity[1].rx_cdr_loss_of_lock;

	unsigned int send_xfp2RxCdrLOLAlarm = 0;
	if (xfp2RxCdrLOLTemp==0 && xfp2RxCdrLOL==1)
   {
		xfp2RxCdrLOLAlarm = 1;
		send_xfp2RxCdrLOLAlarm = 1;
   }
   else if (xfp2RxCdrLOLTemp==1 && xfp2RxCdrLOL==0)
   {
	   xfp2RxCdrLOLAlarm = 2;
      send_xfp2RxCdrLOLAlarm = 1;
   }
	xfp2RxCdrLOLTemp = xfp2RxCdrLOL;

	snmp_varlist_add_variable(&notification_vars, objid_snmptrap, objid_snmptrap_len, ASN_OBJECT_ID, (u_char *) notification_oid, notification_oid_len * sizeof(oid));
	snmp_varlist_add_variable(&notification_vars, xfp2RxCdrLOL_oid, xfp2RxCdrLOL_oid_len, ASN_INTEGER, (u_char *)&xfp2RxCdrLOLAlarm, sizeof(xfp2RxCdrLOLAlarm));
	snmp_varlist_add_variable(&notification_vars, xfp2RxCdrLOLAlarmSev_oid, xfp2RxCdrLOLAlarmSev_oid_len, ASN_INTEGER, (u_char *)&xfp2RxCdrLOLAlarmSev, sizeof(xfp2RxCdrLOLAlarmSev));

	if(send_xfp2RxCdrLOLAlarm == 1)
	{
		++xfp2RxCdrLOLCount;
		DEBUGMSGTL(("ftnc_notifications", "sending trap %ld\n",xfp2RxCdrLOLCount));
		send_v2trap(notification_vars);
	}

	snmp_free_varbind(notification_vars);
}

void send_xfp2TxCdrLOL_notification(unsigned int clientreg, void *clientarg)
{
	DEBUGMSGTL(("token", "send_xfp2TxCdrLOL_notification.\n"));

	oid notification_oid[] = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 2, 2, 0, 55 };
	size_t 	notification_oid_len = OID_LENGTH(notification_oid);
	oid 	objid_snmptrap[] = { 1, 3, 6, 1, 6, 3, 1, 1, 4, 1, 0 };
	size_t 	objid_snmptrap_len = OID_LENGTH(objid_snmptrap);
	oid 	xfp2TxCdrLOL_oid[]   = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 2, 2, 1, 4, 1, 13 };
	size_t 	xfp2TxCdrLOL_oid_len = OID_LENGTH(xfp2TxCdrLOL_oid);
	oid     xfp2TxCdrLOLAlarmSev_oid[]   = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 3, 5, 2, 1, 13 };
	size_t	xfp2TxCdrLOLAlarmSev_oid_len = OID_LENGTH(xfp2TxCdrLOLAlarmSev_oid);

	netsnmp_variable_list *notification_vars = NULL;
	static u_long xfp2TxCdrLOLCount = 0;

	unsigned int xfp2TxCdrLOLAlarm = 0;

	unsigned int xfp2TxCdrLOL = 0;
	xfp2TxCdrLOL = pt_monitor_struct->xfp_struct.xfp_interruption_flags[1][5];

	unsigned int xfp2TxCdrLOLAlarmSev = 0;
	xfp2TxCdrLOLAlarmSev = pt_monitor_struct->xfp_struct.severity[1].tx_cdr_loss_of_lock;

	unsigned int send_xfp2TxCdrLOLAlarm = 0;
	if (xfp2TxCdrLOLTemp==0 && xfp2TxCdrLOL==1)
   {
		xfp2TxCdrLOLAlarm = 1;
		send_xfp2TxCdrLOLAlarm = 1;
   }
   else if (xfp2TxCdrLOLTemp==1 && xfp2TxCdrLOL==0)
   {
	   xfp2TxCdrLOLAlarm = 2;
      send_xfp2TxCdrLOLAlarm = 1;
   }
	xfp2TxCdrLOLTemp = xfp2TxCdrLOL;

	snmp_varlist_add_variable(&notification_vars, objid_snmptrap, objid_snmptrap_len, ASN_OBJECT_ID, (u_char *) notification_oid, notification_oid_len * sizeof(oid));
	snmp_varlist_add_variable(&notification_vars, xfp2TxCdrLOL_oid, xfp2TxCdrLOL_oid_len, ASN_INTEGER, (u_char *)&xfp2TxCdrLOLAlarm, sizeof(xfp2TxCdrLOLAlarm));
	snmp_varlist_add_variable(&notification_vars, xfp2TxCdrLOLAlarmSev_oid, xfp2TxCdrLOLAlarmSev_oid_len, ASN_INTEGER, (u_char *)&xfp2TxCdrLOLAlarmSev, sizeof(xfp2TxCdrLOLAlarmSev));

	if(send_xfp2TxCdrLOLAlarm == 1)
	{
		++xfp2TxCdrLOLCount;
		DEBUGMSGTL(("ftnc_notifications", "sending trap %ld\n",xfp2TxCdrLOLCount));
		send_v2trap(notification_vars);
	}

	snmp_free_varbind(notification_vars);
}

void send_xfp2LaserFault_notification(unsigned int clientreg, void *clientarg)
{
	DEBUGMSGTL(("token", "send_xfp2LaserFault_notification.\n"));

	oid notification_oid[] = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 2, 2, 0, 56 };
	size_t notification_oid_len = OID_LENGTH(notification_oid);
	oid objid_snmptrap[] = { 1, 3, 6, 1, 6, 3, 1, 1, 4, 1, 0 };
	size_t objid_snmptrap_len = OID_LENGTH(objid_snmptrap);
	oid xfp2LaserFault_oid[]   = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 2, 2, 1, 4, 1, 14 };
	size_t xfp2LaserFault_oid_len = OID_LENGTH(xfp2LaserFault_oid);
	oid      xfp2xfp2LaserFaultAlarmSev_oid[]   = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 3, 5, 2, 1, 14 };
	size_t   xfp2xfp2LaserFaultAlarmSev_oid_len = OID_LENGTH(xfp2xfp2LaserFaultAlarmSev_oid);

	netsnmp_variable_list *notification_vars = NULL;
	static u_long xfp2LaserFaultCount = 0;

	unsigned int xfp2LaserFaultAlarm = 0;

	unsigned int xfp2LaserFault = 0;
	xfp2LaserFault = pt_monitor_struct->xfp_struct.xfp_interruption_flags[1][6];

	unsigned int xfp2xfp2LaserFaultAlarmSev = 0;
	xfp2xfp2LaserFaultAlarmSev = pt_monitor_struct->xfp_struct.severity[1].laser_fault;

	unsigned int send_xfp2LaserFaultAlarm = 0;
	if (xfp2LaserFaultTemp==0 && xfp2LaserFault==1)
   {
		xfp2LaserFaultAlarm = 1;
		send_xfp2LaserFaultAlarm = 1;
   }
   else if (xfp2LaserFaultTemp==1 && xfp2LaserFault==0)
   {
	   xfp2LaserFaultAlarm = 2;
      send_xfp2LaserFaultAlarm = 1;
   }
	xfp2LaserFaultTemp = xfp2LaserFault;

	snmp_varlist_add_variable(&notification_vars, objid_snmptrap, objid_snmptrap_len, ASN_OBJECT_ID, (u_char *) notification_oid, notification_oid_len * sizeof(oid));
	snmp_varlist_add_variable(&notification_vars, xfp2LaserFault_oid, xfp2LaserFault_oid_len, ASN_INTEGER, (u_char *)&xfp2LaserFaultAlarm, sizeof(xfp2LaserFaultAlarm));
	snmp_varlist_add_variable(&notification_vars, xfp2xfp2LaserFaultAlarmSev_oid, xfp2xfp2LaserFaultAlarmSev_oid_len, ASN_INTEGER, (u_char *)&xfp2xfp2LaserFaultAlarmSev, sizeof(xfp2xfp2LaserFaultAlarmSev));

	if(send_xfp2LaserFaultAlarm == 1)
	{
		++xfp2LaserFaultCount;
		DEBUGMSGTL(("ftnc_notifications", "sending trap %ld\n",xfp2LaserFaultCount));
		send_v2trap(notification_vars);
	}

	snmp_free_varbind(notification_vars);
}

/* ***************** Implementation of XFP3 methods ***************** */

void send_xfp3Presence_notification(unsigned int clientreg, void *clientarg)
{
	DEBUGMSGTL(("token", "send_xfp3Presence_notification.\n"));

	oid 	notification_oid[] = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 2, 2, 0, 57 };
	size_t 	notification_oid_len = OID_LENGTH(notification_oid);
	oid 	objid_snmptrap[] = { 1, 3, 6, 1, 6, 3, 1, 1, 4, 1, 0 };
	size_t 	objid_snmptrap_len = OID_LENGTH(objid_snmptrap);
	oid 	xfp3Presence_oid[]   = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 2, 2, 1, 5, 1, 2 };
	size_t  xfp3Presence_oid_len = OID_LENGTH(xfp3Presence_oid);
	oid     xfp3PresenceAlarmSev_oid[]   = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 3, 5, 3, 1, 2 };
	size_t	xfp3PresenceAlarmSev_oid_len = OID_LENGTH(xfp3PresenceAlarmSev_oid);

	netsnmp_variable_list *notification_vars = NULL;
	static u_long xfp3PresenceCount = 0;

	unsigned int xfp3PresenceAlarm = 0;
	unsigned int xfp3Presence = 0;
	//xfp3Presence = 0 is present; xfp3Presence = 1 is not present.
	xfp3Presence = pt_monitor_struct->xfp_struct.xfp_presence[2];

	unsigned int xfp3PresenceAlarmSev = 0;
	xfp3PresenceAlarmSev = pt_monitor_struct->xfp_struct.severity[2].presence;

	unsigned int send_xfp3PresenceAlarm = 0;
	if (xfp3PresenceTemp==0 && xfp3Presence==1) //The alarm was activated.
   {
		xfp3PresenceAlarm = 1; //The alarm was activated.
		send_xfp3PresenceAlarm = 1; // Send notification.
   }
   else if (xfp3PresenceTemp==1 && xfp3Presence==0) //The alarm is deactivated.
   {
	   xfp3PresenceAlarm = 2; //The alarm is deactivated.
      send_xfp3PresenceAlarm = 1; //Send notification.
   }
	xfp3PresenceTemp = xfp3Presence;

	snmp_varlist_add_variable(&notification_vars, objid_snmptrap, objid_snmptrap_len, ASN_OBJECT_ID, (u_char *) notification_oid, notification_oid_len * sizeof(oid));
	snmp_varlist_add_variable(&notification_vars, xfp3Presence_oid, xfp3Presence_oid_len, ASN_INTEGER, (u_char *)&xfp3PresenceAlarm, sizeof(xfp3PresenceAlarm));
	snmp_varlist_add_variable(&notification_vars, xfp3PresenceAlarmSev_oid, xfp3PresenceAlarmSev_oid_len, ASN_INTEGER, (u_char *)&xfp3PresenceAlarmSev, sizeof(xfp3PresenceAlarmSev));

	if(send_xfp3PresenceAlarm == 1)
	{
		++xfp3PresenceCount;
		DEBUGMSGTL(("ftnc_notifications", "xfp3PresenceCount sending trap %ld\n",xfp3PresenceCount));
		send_v2trap(notification_vars);
	}

	snmp_free_varbind(notification_vars);
}

void send_xfp3RxLoss_notification(unsigned int clientreg, void *clientarg)
{
	DEBUGMSGTL(("token", "send_xfp3RxLoss_notification.\n"));

	oid 	notification_oid[] = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 2, 2, 0, 58 };
	size_t 	notification_oid_len = OID_LENGTH(notification_oid);
	oid 	objid_snmptrap[] = { 1, 3, 6, 1, 6, 3, 1, 1, 4, 1, 0 };
	size_t 	objid_snmptrap_len = OID_LENGTH(objid_snmptrap);
	oid 	xfp3RxLoss_oid[]   = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 2, 2, 1, 5, 1, 3 };
	size_t 	xfp3RxLoss_oid_len = OID_LENGTH(xfp3RxLoss_oid);
	oid     xfp3RxLossAlarmSev_oid[]   = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 3, 5, 3, 1, 3 };
	size_t	xfp3RxLossAlarmSev_oid_len = OID_LENGTH(xfp3RxLossAlarmSev_oid);

	netsnmp_variable_list *notification_vars = NULL;
	static u_long xfp3RxLossCount = 0;

	unsigned int xfp3RxLossAlarm = 0;

	unsigned int xfp3RxLoss = 0;
	xfp3RxLoss = pt_monitor_struct->xfp_struct.xfp_presence[2];

	unsigned int xfp3RxLossAlarmSev = 0;
	xfp3RxLossAlarmSev = pt_monitor_struct->xfp_struct.severity[2].rx_loss;

	unsigned int send_xfp3RxLossAlarm = 0;
	if (xfp3RxLossTemp==0 && xfp3RxLoss==1)
   {
		xfp3RxLossAlarm = 1;
		send_xfp3RxLossAlarm = 1;
   }
   else if (xfp3RxLossTemp==1 && xfp3RxLoss==0)
   {
	   xfp3RxLossAlarm = 2;
      send_xfp3RxLossAlarm = 1;
   }
	xfp3RxLossTemp = xfp3RxLoss;

	snmp_varlist_add_variable(&notification_vars, objid_snmptrap, objid_snmptrap_len, ASN_OBJECT_ID, (u_char *) notification_oid, notification_oid_len * sizeof(oid));
	snmp_varlist_add_variable(&notification_vars, xfp3RxLoss_oid, xfp3RxLoss_oid_len, ASN_INTEGER, (u_char *)&xfp3RxLossAlarm, sizeof(xfp3RxLossAlarm));
	snmp_varlist_add_variable(&notification_vars, xfp3RxLossAlarmSev_oid, xfp3RxLossAlarmSev_oid_len, ASN_INTEGER, (u_char *)&xfp3RxLossAlarmSev, sizeof(xfp3RxLossAlarmSev));

	if(send_xfp3RxLossAlarm == 1)
	{
		++xfp3RxLossCount;
		DEBUGMSGTL(("ftnc_notifications", "sending trap %ld\n",xfp3RxLossCount));
		send_v2trap(notification_vars);
	}

	snmp_free_varbind(notification_vars);
}

void send_xfp3Ready_notification(unsigned int clientreg, void *clientarg)
{
	DEBUGMSGTL(("token", "send_xfp3Ready_notification.\n"));

	oid 	notification_oid[] = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 2, 2, 0, 59 };
	size_t 	notification_oid_len = OID_LENGTH(notification_oid);
	oid 	objid_snmptrap[] = { 1, 3, 6, 1, 6, 3, 1, 1, 4, 1, 0 };
	size_t 	objid_snmptrap_len = OID_LENGTH(objid_snmptrap);
	oid 	xfp3Ready_oid[]   = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 2, 2, 1, 5, 1, 4 };
	size_t 	xfp3Ready_oid_len = OID_LENGTH(xfp3Ready_oid);
	oid     xfp3ReadyAlarmSev_oid[]   = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 3, 5, 3, 1, 4 };
	size_t	xfp3ReadyAlarmSev_oid_len = OID_LENGTH(xfp3ReadyAlarmSev_oid);

	netsnmp_variable_list *notification_vars = NULL;
	static u_long xfp3ReadyCount = 0;

	unsigned int xfp3ReadyAlarm = 0;

	unsigned int xfp3Ready = 0;
	xfp3Ready = pt_monitor_struct->xfp_struct.xfp_ready[2];

	unsigned int xfp3ReadyAlarmSev = 0;
	xfp3ReadyAlarmSev = pt_monitor_struct->xfp_struct.severity[2].ready;

	unsigned int send_xfp3ReadyAlarm = 0;
	if (xfp3ReadyTemp==0 && xfp3Ready==1)
   {
		xfp3ReadyAlarm = 1;
		send_xfp3ReadyAlarm = 1;
   }
   else if (xfp3ReadyTemp==1 && xfp3Ready==0)
   {
	  xfp3ReadyAlarm = 2;
      send_xfp3ReadyAlarm = 1;
   }
	xfp3ReadyTemp = xfp3Ready;

	snmp_varlist_add_variable(&notification_vars, objid_snmptrap, objid_snmptrap_len, ASN_OBJECT_ID, (u_char *) notification_oid, notification_oid_len * sizeof(oid));
	snmp_varlist_add_variable(&notification_vars, xfp3Ready_oid, xfp3Ready_oid_len, ASN_INTEGER, (u_char *)&xfp3ReadyAlarm, sizeof(xfp3ReadyAlarm));
	snmp_varlist_add_variable(&notification_vars, xfp3ReadyAlarmSev_oid, xfp3ReadyAlarmSev_oid_len, ASN_INTEGER, (u_char *)&xfp3ReadyAlarmSev, sizeof(xfp3ReadyAlarmSev));

	if(send_xfp3ReadyAlarm == 1)
	{
		++xfp3ReadyCount;
		DEBUGMSGTL(("ftnc_notifications", "sending trap %ld\n",xfp3ReadyCount));
		send_v2trap(notification_vars);
	}

	snmp_free_varbind(notification_vars);
}

void send_xfp3TxPower_notification(unsigned int clientreg, void *clientarg)
{
	DEBUGMSGTL(("token", "send_xfp3TxPower_notification.\n"));

   oid      notification_oid[] =  { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 2, 2, 0, 60 };
   size_t   notification_oid_len = OID_LENGTH(notification_oid);
   oid      objid_snmptrap[] = { 1, 3, 6, 1, 6, 3, 1, 1, 4, 1, 0 };
   size_t   objid_snmptrap_len = OID_LENGTH(objid_snmptrap);
   oid		xfp3TxPowerAlarm_oid[]   = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 2, 2, 1, 5, 1, 5 };
   size_t	xfp3TxPowerAlarm_oid_len = OID_LENGTH(xfp3TxPowerAlarm_oid);
   oid	xfp3TxPowerAlarmSev_oid[]   = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 3, 5, 3, 1, 5 };
   size_t	xfp3TxPowerAlarmSev_oid_len = OID_LENGTH(xfp3TxPowerAlarmSev_oid);

   netsnmp_variable_list *notification_vars = NULL;
   static u_long  xfp3TxPowerCount = 0;

   unsigned int xfp3TxPowerInt = 0;
   unsigned int xfp3TxPowerAlarm = 0;

   unsigned int send_xfp3TxPowerAlarm = 0;

   float xfp3TxPower;
   xfp3TxPower = pt_monitor_struct->xfp_struct.xfp_tx_power[2];

   unsigned int xfp3TxPowerAlarmSev = 0;
   xfp3TxPowerAlarmSev = pt_monitor_struct->xfp_struct.severity[2].tx_power;

   if (xfp3TxPower < -3 || xfp3TxPower > 0)
   { xfp3TxPowerInt = 1; }
   else
   { xfp3TxPowerInt = 0; }

   if (xfp3TxPowerTemp==0 && xfp3TxPowerInt==1)
   {
	   xfp3TxPowerAlarm = 1;
	   send_xfp3TxPowerAlarm = 1;
   }
   else if (xfp3TxPowerTemp==1 && xfp3TxPowerInt==0)
   {
	   xfp3TxPowerAlarm = 2;
	   send_xfp3TxPowerAlarm = 1;
   }
   xfp3TxPowerTemp = xfp3TxPowerInt;

   snmp_varlist_add_variable(&notification_vars, objid_snmptrap, objid_snmptrap_len, ASN_OBJECT_ID, (u_char *) notification_oid, notification_oid_len * sizeof(oid));
   snmp_varlist_add_variable(&notification_vars,  xfp3TxPowerAlarm_oid, xfp3TxPowerAlarm_oid_len, ASN_INTEGER, (u_char *)&xfp3TxPowerAlarm, sizeof(xfp3TxPowerAlarm));
   snmp_varlist_add_variable(&notification_vars, xfp3TxPowerAlarmSev_oid, xfp3TxPowerAlarmSev_oid_len, ASN_INTEGER, (u_char *)&xfp3TxPowerAlarmSev, sizeof(xfp3TxPowerAlarmSev));

   if(send_xfp3TxPowerAlarm == 1)
   {
       ++xfp3TxPowerCount;
       DEBUGMSGTL(("ftnc_notifications", "sending trap %ld\n",xfp3TxPowerCount));
       send_v2trap(notification_vars);
   }

   snmp_free_varbind(notification_vars);
}

void send_xfp3RxPower_notification(unsigned int clientreg, void *clientarg)
{
	DEBUGMSGTL(("token", "send_xfp3RxPower_notification.\n"));

   oid      notification_oid[] =  { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 2, 2, 0, 61 };
   size_t   notification_oid_len = OID_LENGTH(notification_oid);
   oid      objid_snmptrap[] = { 1, 3, 6, 1, 6, 3, 1, 1, 4, 1, 0 };
   size_t   objid_snmptrap_len = OID_LENGTH(objid_snmptrap);
   oid      xfp3RxPowerAlarm_oid[]   = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 2, 2, 1, 5, 1, 6 };
   size_t	xfp3RxPowerAlarm_oid_len = OID_LENGTH(xfp3RxPowerAlarm_oid);
   oid      xfp3RxPowerAlarmSev_oid[]   = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 3, 5, 3, 1, 6 };
   size_t   xfp3RxPowerAlarmSev_oid_len = OID_LENGTH(xfp3RxPowerAlarmSev_oid);

   netsnmp_variable_list *notification_vars = NULL;
   static u_long  xfp3RxPowerCount = 0;

   unsigned int xfp3RxPowerInt = 0;
   unsigned int xfp3RxPowerAlarm = 0;

   unsigned int send_xfp3RxPowerAlarm = 0;

   float xfp3RxPower;
   xfp3RxPower = pt_monitor_struct->xfp_struct.xfp_rx_power[2];

   unsigned int xfp3RxPowerAlarmSev = 0;
   xfp3RxPowerAlarmSev = pt_monitor_struct->xfp_struct.severity[2].rx_power;

   if (xfp3RxPower < -3 || xfp3RxPower > 0)
   { xfp3RxPowerInt = 1; }
   else
   { xfp3RxPowerInt = 0; }

   if (xfp3RxPowerTemp==0 && xfp3RxPowerInt==1)
   {
	   xfp3RxPowerAlarm = 1;
	   send_xfp3RxPowerAlarm = 1;
   }
   else if (xfp3RxPowerTemp==1 && xfp3RxPowerInt==0)
   {
	   xfp3RxPowerAlarm = 2;
	   send_xfp3RxPowerAlarm = 1;
   }
   xfp3RxPowerTemp = xfp3RxPowerInt;

   snmp_varlist_add_variable(&notification_vars, objid_snmptrap, objid_snmptrap_len, ASN_OBJECT_ID, (u_char *) notification_oid, notification_oid_len * sizeof(oid));
   snmp_varlist_add_variable(&notification_vars,  xfp3RxPowerAlarm_oid, xfp3RxPowerAlarm_oid_len, ASN_INTEGER, (u_char *)&xfp3RxPowerAlarm, sizeof(xfp3RxPowerAlarm));
   snmp_varlist_add_variable(&notification_vars, xfp3RxPowerAlarmSev_oid, xfp3RxPowerAlarmSev_oid_len, ASN_INTEGER, (u_char *)&xfp3RxPowerAlarmSev, sizeof(xfp3RxPowerAlarmSev));

   if(send_xfp3RxPowerAlarm == 1)
   {
       ++xfp3RxPowerCount;
       DEBUGMSGTL(("ftnc_notifications", "sending trap %ld\n",xfp3RxPowerCount));
       send_v2trap(notification_vars);
   }

   snmp_free_varbind(notification_vars);
}

void send_xfp3Temperature_notification(unsigned int clientreg, void *clientarg)
{
	DEBUGMSGTL(("token", "send_xfp3Temperature_notification.\n"));

   oid      notification_oid[] =  { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 2, 2, 0, 62 };
   size_t   notification_oid_len = OID_LENGTH(notification_oid);
   oid      objid_snmptrap[] = { 1, 3, 6, 1, 6, 3, 1, 1, 4, 1, 0 };
   size_t   objid_snmptrap_len = OID_LENGTH(objid_snmptrap);
   oid      xfp3TemperatureAlarm_oid[]   = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 2, 2, 1, 5, 1, 7 };
   size_t   xfp3TemperatureAlarm_oid_len = OID_LENGTH(xfp3TemperatureAlarm_oid);
   oid      xfp3TemperatureAlarmSev_oid[]   = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 3, 5, 3, 1, 7 };
   size_t   xfp3TemperatureAlarmSev_oid_len = OID_LENGTH(xfp3TemperatureAlarmSev_oid);

   netsnmp_variable_list *notification_vars = NULL;
   static u_long  xfp3TemperatureCount = 0;

   unsigned int xfp3TemperatureInt = 0;
   unsigned int xfp3TemperatureAlarm = 0;

   unsigned int send_xfp3TemperatureAlarm = 0;

   float xfp3Temperature;
   xfp3Temperature = pt_monitor_struct->xfp_struct.xfp_temperature[2];

   unsigned int xfp3TemperatureAlarmSev = 0;
   xfp3TemperatureAlarmSev = pt_monitor_struct->xfp_struct.severity[2].temperature;

   if (xfp3Temperature < 10 || xfp3Temperature > 30)
   { xfp3TemperatureInt = 1; }
   else
   { xfp3TemperatureInt = 0; }

   if (xfp3TemperatureTemp==0 && xfp3TemperatureInt==1)
   {
	   xfp3TemperatureAlarm = 1;
	   send_xfp3TemperatureAlarm = 1;
   }
   else if (xfp3TemperatureTemp==1 && xfp3TemperatureInt==0)
   {
	   xfp3TemperatureAlarm = 2;
	   send_xfp3TemperatureAlarm = 1;
   }
   xfp3TemperatureTemp = xfp3TemperatureInt;

   snmp_varlist_add_variable(&notification_vars, objid_snmptrap, objid_snmptrap_len, ASN_OBJECT_ID, (u_char *) notification_oid, notification_oid_len * sizeof(oid));
   snmp_varlist_add_variable(&notification_vars,  xfp3TemperatureAlarm_oid, xfp3TemperatureAlarm_oid_len, ASN_INTEGER, (u_char *)&xfp3TemperatureAlarm, sizeof(xfp3TemperatureAlarm));
   snmp_varlist_add_variable(&notification_vars, xfp3TemperatureAlarmSev_oid, xfp3TemperatureAlarmSev_oid_len, ASN_INTEGER, (u_char *)&xfp3TemperatureAlarmSev, sizeof(xfp3TemperatureAlarmSev));

   if(send_xfp3TemperatureAlarm == 1)
   {
       ++xfp3TemperatureCount;
       DEBUGMSGTL(("ftnc_notifications", "sending trap %ld\n",xfp3TemperatureCount));
       send_v2trap(notification_vars);
   }

   snmp_free_varbind(notification_vars);
}

void send_xfp3LowTxPower_notification(unsigned int clientreg, void *clientarg)
{
	DEBUGMSGTL(("token", "send_xfp3LowTxPower_notification.\n"));

	oid 	notification_oid[] = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 2, 2, 0, 63 };
	size_t 	notification_oid_len = OID_LENGTH(notification_oid);
	oid 	objid_snmptrap[] = { 1, 3, 6, 1, 6, 3, 1, 1, 4, 1, 0 };
	size_t 	objid_snmptrap_len = OID_LENGTH(objid_snmptrap);
	oid 	xfp3LowTxPower_oid[]   = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 2, 2, 1, 5, 1, 8 };
	size_t 	xfp3LowTxPower_oid_len = OID_LENGTH(xfp3LowTxPower_oid);
	oid     xfp3LowTxPowerAlarmSev_oid[]   = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 3, 5, 3, 1, 8 };
	size_t  xfp3LowTxPowerAlarmSev_oid_len = OID_LENGTH(xfp3LowTxPowerAlarmSev_oid);

	netsnmp_variable_list *notification_vars = NULL;
	static u_long xfp3LowTxPowerCount = 0;

	unsigned int xfp3LowTxPowerAlarm = 0;

	unsigned int xfp3LowTxPower = 0;
	xfp3LowTxPower = pt_monitor_struct->xfp_struct.xfp_interruption_flags[2][0];

	unsigned int xfp3LowTxPowerAlarmSev = 0;
	xfp3LowTxPowerAlarmSev = pt_monitor_struct->xfp_struct.severity[2].low_tx_power;

	unsigned int send_xfp3LowTxPowerAlarm = 0;
	if (xfp3LowTxPowerTemp==0 && xfp3LowTxPower==1)
   {
		xfp3LowTxPowerAlarm = 1;
		send_xfp3LowTxPowerAlarm = 1;
   }
   else if (xfp3LowTxPowerTemp==1 && xfp3LowTxPower==0)
   {
	  xfp3LowTxPowerAlarm = 2;
      send_xfp3LowTxPowerAlarm = 1;
   }
	xfp3LowTxPowerTemp = xfp3LowTxPower;

	snmp_varlist_add_variable(&notification_vars, objid_snmptrap, objid_snmptrap_len, ASN_OBJECT_ID, (u_char *) notification_oid, notification_oid_len * sizeof(oid));
	snmp_varlist_add_variable(&notification_vars, xfp3LowTxPower_oid, xfp3LowTxPower_oid_len, ASN_INTEGER, (u_char *)&xfp3LowTxPowerAlarm, sizeof(xfp3LowTxPowerAlarm));
	snmp_varlist_add_variable(&notification_vars, xfp3LowTxPowerAlarmSev_oid, xfp3LowTxPowerAlarmSev_oid_len, ASN_INTEGER, (u_char *)&xfp3LowTxPowerAlarmSev, sizeof(xfp3LowTxPowerAlarmSev));

	if(send_xfp3LowTxPowerAlarm == 1)
	{
		++xfp3LowTxPowerCount;
		DEBUGMSGTL(("ftnc_notifications", "sending trap %ld\n",xfp3LowTxPowerCount));
		send_v2trap(notification_vars);
	}

	snmp_free_varbind(notification_vars);
}

void send_xfp3HighTxPower_notification(unsigned int clientreg, void *clientarg)
{
	DEBUGMSGTL(("token", "send_xfp3HighTxPower_notification.\n"));

	oid 	notification_oid[] = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 2, 2, 0, 64 };
	size_t  notification_oid_len = OID_LENGTH(notification_oid);
	oid 	objid_snmptrap[] = { 1, 3, 6, 1, 6, 3, 1, 1, 4, 1, 0 };
	size_t 	objid_snmptrap_len = OID_LENGTH(objid_snmptrap);
	oid 	xfp3HighTxPower_oid[]   = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 2, 2, 1, 3, 1, 9 };
	size_t 	xfp3HighTxPower_oid_len = OID_LENGTH(xfp3HighTxPower_oid);
	oid     xfp3HighTxPowerAlarmSev_oid[]   = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 3, 5, 3, 1, 9 };
	size_t	xfp3HighTxPowerAlarmSev_oid_len = OID_LENGTH(xfp3HighTxPowerAlarmSev_oid);

	netsnmp_variable_list *notification_vars = NULL;
	static u_long xfp3HighTxPowerCount = 0;

	unsigned int xfp3HighTxPowerAlarm = 0;

	unsigned int xfp3HighTxPower = 0;
	xfp3HighTxPower = pt_monitor_struct->xfp_struct.xfp_interruption_flags[2][1];

	unsigned int xfp3HighTxPowerAlarmSev = 0;
	xfp3HighTxPowerAlarmSev = pt_monitor_struct->xfp_struct.severity[2].high_tx_power;

	unsigned int send_xfp3HighTxPowerAlarm = 0;
	if (xfp3HighTxPowerTemp==0 && xfp3HighTxPower==1)
   {
		xfp3HighTxPowerAlarm = 1;
		send_xfp3HighTxPowerAlarm = 1;
   }
   else if (xfp3HighTxPowerTemp==1 && xfp3HighTxPower==0)
   {
	  xfp3HighTxPowerAlarm = 2;
      send_xfp3HighTxPowerAlarm = 1;
   }
	xfp3HighTxPowerTemp = xfp3HighTxPower;

	snmp_varlist_add_variable(&notification_vars, objid_snmptrap, objid_snmptrap_len, ASN_OBJECT_ID, (u_char *) notification_oid, notification_oid_len * sizeof(oid));
	snmp_varlist_add_variable(&notification_vars, xfp3HighTxPower_oid, xfp3HighTxPower_oid_len, ASN_INTEGER, (u_char *)&xfp3HighTxPowerAlarm, sizeof(xfp3HighTxPowerAlarm));
	snmp_varlist_add_variable(&notification_vars, xfp3HighTxPowerAlarmSev_oid, xfp3HighTxPowerAlarmSev_oid_len, ASN_INTEGER, (u_char *)&xfp3HighTxPowerAlarmSev, sizeof(xfp3HighTxPowerAlarmSev));

	if(send_xfp3HighTxPowerAlarm == 1)
	{
		++xfp3HighTxPowerCount;
		DEBUGMSGTL(("ftnc_notifications", "sending trap %ld\n",xfp3HighTxPowerCount));
		send_v2trap(notification_vars);
	}

	snmp_free_varbind(notification_vars);
}

void send_xfp3LowRxPower_notification(unsigned int clientreg, void *clientarg)
{
	DEBUGMSGTL(("token", "send_xfp3LowRxPower_notification.\n"));

	oid 	notification_oid[] = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 2, 2, 0, 65 };
	size_t 	notification_oid_len = OID_LENGTH(notification_oid);
	oid 	objid_snmptrap[] = { 1, 3, 6, 1, 6, 3, 1, 1, 4, 1, 0 };
	size_t 	objid_snmptrap_len = OID_LENGTH(objid_snmptrap);
	oid 	xfp3LowRxPower_oid[]   = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 2, 2, 1, 5, 1, 10 };
	size_t 	xfp3LowRxPower_oid_len = OID_LENGTH(xfp3LowRxPower_oid);
	oid     xfp3LowRxPowerAlarmSev_oid[]   = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 3, 5, 3, 1, 10 };
	size_t	xfp3LowRxPowerAlarmSev_oid_len = OID_LENGTH(xfp3LowRxPowerAlarmSev_oid);

	netsnmp_variable_list *notification_vars = NULL;
	static u_long xfp3LowRxPowerCount = 0;

	unsigned int xfp3LowRxPowerAlarm = 0;

	unsigned int xfp3LowRxPower = 0;
	xfp3LowRxPower = pt_monitor_struct->xfp_struct.xfp_interruption_flags[2][2];

	unsigned int xfp3LowRxPowerAlarmSev = 0;
	xfp3LowRxPowerAlarmSev = pt_monitor_struct->xfp_struct.severity[2].low_rx_power;

	unsigned int send_xfp3LowRxPowerAlarm = 0;
	if (xfp3LowRxPowerTemp==0 && xfp3LowRxPower==1)
   {
		xfp3LowRxPowerAlarm = 1;
		send_xfp3LowRxPowerAlarm = 1;
   }
   else if (xfp3LowRxPowerTemp==1 && xfp3LowRxPower==0)
   {
	  xfp3LowRxPowerAlarm = 2;
      send_xfp3LowRxPowerAlarm = 1;
   }
	xfp3LowRxPowerTemp = xfp3LowRxPower;

	snmp_varlist_add_variable(&notification_vars, objid_snmptrap, objid_snmptrap_len, ASN_OBJECT_ID, (u_char *) notification_oid, notification_oid_len * sizeof(oid));

	snmp_varlist_add_variable(&notification_vars, xfp3LowRxPower_oid, xfp3LowRxPower_oid_len, ASN_INTEGER, (u_char *)&xfp3LowRxPowerAlarm, sizeof(xfp3LowRxPowerAlarm));
	snmp_varlist_add_variable(&notification_vars, xfp3LowRxPowerAlarmSev_oid, xfp3LowRxPowerAlarmSev_oid_len, ASN_INTEGER, (u_char *)&xfp3LowRxPowerAlarmSev, sizeof(xfp3LowRxPowerAlarmSev));

	if(send_xfp3LowRxPowerAlarm == 1)
	{
		++xfp3LowRxPowerCount;
		DEBUGMSGTL(("ftnc_notifications", "sending trap %ld\n",xfp3LowRxPowerCount));
		send_v2trap(notification_vars);
	}

	snmp_free_varbind(notification_vars);
}

void send_xfp3HighRxPower_notification(unsigned int clientreg, void *clientarg)
{
	DEBUGMSGTL(("token", "send_xfp3HighRxPower_notification.\n"));

	oid notification_oid[] = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 2, 2, 0, 66 };
	size_t notification_oid_len = OID_LENGTH(notification_oid);
	oid 	objid_snmptrap[] = { 1, 3, 6, 1, 6, 3, 1, 1, 4, 1, 0 };
	size_t 	objid_snmptrap_len = OID_LENGTH(objid_snmptrap);
	oid 	xfp3HighRxPower_oid[]   = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 2, 2, 1, 5, 1, 11 };
	size_t 	xfp3HighRxPower_oid_len = OID_LENGTH(xfp3HighRxPower_oid);
	oid     xfp3HighRxPowerAlarmSev_oid[]   = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 3, 5, 3, 1, 11 };
	size_t	xfp3HighRxPowerAlarmSev_oid_len = OID_LENGTH(xfp3HighRxPowerAlarmSev_oid);

	netsnmp_variable_list *notification_vars = NULL;
	static u_long xfp3HighRxPowerCount = 0;

	unsigned int xfp3HighRxPowerAlarm = 0;

	unsigned int xfp3HighRxPower = 0;
	xfp3HighRxPower = pt_monitor_struct->xfp_struct.xfp_interruption_flags[2][3];

	unsigned int xfp3HighRxPowerAlarmSev = 0;
	xfp3HighRxPowerAlarmSev = pt_monitor_struct->xfp_struct.severity[2].high_rx_power;

	unsigned int send_xfp3HighRxPowerAlarm = 0;
	if (xfp3HighRxPowerTemp==0 && xfp3HighRxPower==1) //The alarm was activated.
   {
		xfp3HighRxPowerAlarm = 1; //The alarm was activated.
		send_xfp3HighRxPowerAlarm = 1; // Send notification.
   }
   else if (xfp3HighRxPowerTemp==1 && xfp3HighRxPower==0) //The alarm is deactivated.
   {
	  xfp3HighRxPowerAlarm = 2; //The alarm is deactivated.
      send_xfp3HighRxPowerAlarm = 1; //Send notification.
   }
	xfp3HighRxPowerTemp = xfp3HighRxPower;

	snmp_varlist_add_variable(&notification_vars, objid_snmptrap, objid_snmptrap_len, ASN_OBJECT_ID, (u_char *) notification_oid, notification_oid_len * sizeof(oid));
	snmp_varlist_add_variable(&notification_vars, xfp3HighRxPower_oid, xfp3HighRxPower_oid_len, ASN_INTEGER, (u_char *)&xfp3HighRxPowerAlarm, sizeof(xfp3HighRxPowerAlarm));
	snmp_varlist_add_variable(&notification_vars, xfp3HighRxPowerAlarmSev_oid, xfp3HighRxPowerAlarmSev_oid_len, ASN_INTEGER, (u_char *)&xfp3HighRxPowerAlarmSev, sizeof(xfp3HighRxPowerAlarmSev));

	if(send_xfp3HighRxPowerAlarm == 1)
	{
		++xfp3HighRxPowerCount;
		DEBUGMSGTL(("ftnc_notifications", "sending trap %ld\n",xfp3HighRxPowerCount));
		send_v2trap(notification_vars);
	}

	snmp_free_varbind(notification_vars);
}

void send_xfp3RxCdrLOL_notification(unsigned int clientreg, void *clientarg)
{
	DEBUGMSGTL(("token", "send_xfp3RxCdrLOL_notification.\n"));

	oid 	notification_oid[] = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 2, 2, 0, 67 };
	size_t 	notification_oid_len = OID_LENGTH(notification_oid);
	oid 	objid_snmptrap[] = { 1, 3, 6, 1, 6, 3, 1, 1, 4, 1, 0 };
	size_t 	objid_snmptrap_len = OID_LENGTH(objid_snmptrap);
	oid 	xfp3RxCdrLOL_oid[]   = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 2, 2, 1, 5, 1, 12 };
	size_t 	xfp3RxCdrLOL_oid_len = OID_LENGTH(xfp3RxCdrLOL_oid);
	oid     xfp3RxCdrLOLAlarmSev_oid[]   = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 3, 5, 3, 1, 12 };
	size_t  xfp3RxCdrLOLAlarmSev_oid_len = OID_LENGTH(xfp3RxCdrLOLAlarmSev_oid);

	netsnmp_variable_list *notification_vars = NULL;
	static u_long xfp3RxCdrLOLCount = 0;

	unsigned int xfp3RxCdrLOLAlarm = 0;

	unsigned int xfp3RxCdrLOL = 0;
	xfp3RxCdrLOL = pt_monitor_struct->xfp_struct.xfp_interruption_flags[2][4];

	unsigned int xfp3RxCdrLOLAlarmSev = 0;
	xfp3RxCdrLOLAlarmSev = pt_monitor_struct->xfp_struct.severity[2].rx_cdr_loss_of_lock;

	unsigned int send_xfp3RxCdrLOLAlarm = 0;
	if (xfp3RxCdrLOLTemp==0 && xfp3RxCdrLOL==1)
   {
		xfp3RxCdrLOLAlarm = 1;
		send_xfp3RxCdrLOLAlarm = 1;
   }
   else if (xfp3RxCdrLOLTemp==1 && xfp3RxCdrLOL==0)
   {
	   xfp3RxCdrLOLAlarm = 2;
      send_xfp3RxCdrLOLAlarm = 1;
   }
	xfp3RxCdrLOLTemp = xfp3RxCdrLOL;

	snmp_varlist_add_variable(&notification_vars, objid_snmptrap, objid_snmptrap_len, ASN_OBJECT_ID, (u_char *) notification_oid, notification_oid_len * sizeof(oid));
	snmp_varlist_add_variable(&notification_vars, xfp3RxCdrLOL_oid, xfp3RxCdrLOL_oid_len, ASN_INTEGER, (u_char *)&xfp3RxCdrLOLAlarm, sizeof(xfp3RxCdrLOLAlarm));
	snmp_varlist_add_variable(&notification_vars, xfp3RxCdrLOLAlarmSev_oid, xfp3RxCdrLOLAlarmSev_oid_len, ASN_INTEGER, (u_char *)&xfp3RxCdrLOLAlarmSev, sizeof(xfp3RxCdrLOLAlarmSev));

	if(send_xfp3RxCdrLOLAlarm == 1)
	{
		++xfp3RxCdrLOLCount;
		DEBUGMSGTL(("ftnc_notifications", "sending trap %ld\n",xfp3RxCdrLOLCount));
		send_v2trap(notification_vars);
	}

	snmp_free_varbind(notification_vars);
}

void send_xfp3TxCdrLOL_notification(unsigned int clientreg, void *clientarg)
{
	DEBUGMSGTL(("token", "send_xfp3TxCdrLOL_notification.\n"));

	oid notification_oid[] = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 2, 2, 0, 68 };
	size_t 	notification_oid_len = OID_LENGTH(notification_oid);
	oid 	objid_snmptrap[] = { 1, 3, 6, 1, 6, 3, 1, 1, 4, 1, 0 };
	size_t 	objid_snmptrap_len = OID_LENGTH(objid_snmptrap);
	oid 	xfp3TxCdrLOL_oid[]   = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 2, 2, 1, 5, 1, 13 };
	size_t 	xfp3TxCdrLOL_oid_len = OID_LENGTH(xfp3TxCdrLOL_oid);
	oid     xfp3TxCdrLOLAlarmSev_oid[]   = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 3, 5, 3, 1, 13 };
	size_t	xfp3TxCdrLOLAlarmSev_oid_len = OID_LENGTH(xfp3TxCdrLOLAlarmSev_oid);

	netsnmp_variable_list *notification_vars = NULL;
	static u_long xfp3TxCdrLOLCount = 0;

	unsigned int xfp3TxCdrLOLAlarm = 0;

	unsigned int xfp3TxCdrLOL = 0;
	xfp3TxCdrLOL = pt_monitor_struct->xfp_struct.xfp_interruption_flags[2][5];

	unsigned int xfp3TxCdrLOLAlarmSev = 0;
	xfp3TxCdrLOLAlarmSev = pt_monitor_struct->xfp_struct.severity[2].tx_cdr_loss_of_lock;

	unsigned int send_xfp3TxCdrLOLAlarm = 0;
	if (xfp3TxCdrLOLTemp==0 && xfp3TxCdrLOL==1)
   {
		xfp3TxCdrLOLAlarm = 1;
		send_xfp3TxCdrLOLAlarm = 1;
   }
   else if (xfp3TxCdrLOLTemp==1 && xfp3TxCdrLOL==0)
   {
	   xfp3TxCdrLOLAlarm = 2;
      send_xfp3TxCdrLOLAlarm = 1;
   }
	xfp3TxCdrLOLTemp = xfp3TxCdrLOL;

	snmp_varlist_add_variable(&notification_vars, objid_snmptrap, objid_snmptrap_len, ASN_OBJECT_ID, (u_char *) notification_oid, notification_oid_len * sizeof(oid));
	snmp_varlist_add_variable(&notification_vars, xfp3TxCdrLOL_oid, xfp3TxCdrLOL_oid_len, ASN_INTEGER, (u_char *)&xfp3TxCdrLOLAlarm, sizeof(xfp3TxCdrLOLAlarm));
	snmp_varlist_add_variable(&notification_vars, xfp3TxCdrLOLAlarmSev_oid, xfp3TxCdrLOLAlarmSev_oid_len, ASN_INTEGER, (u_char *)&xfp3TxCdrLOLAlarmSev, sizeof(xfp3TxCdrLOLAlarmSev));

	if(send_xfp3TxCdrLOLAlarm == 1)
	{
		++xfp3TxCdrLOLCount;
		DEBUGMSGTL(("ftnc_notifications", "sending trap %ld\n",xfp3TxCdrLOLCount));
		send_v2trap(notification_vars);
	}

	snmp_free_varbind(notification_vars);
}

void send_xfp3LaserFault_notification(unsigned int clientreg, void *clientarg)
{
	DEBUGMSGTL(("token", "send_xfp3LaserFault_notification.\n"));

	oid notification_oid[] = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 2, 2, 0, 69 };
	size_t notification_oid_len = OID_LENGTH(notification_oid);
	oid objid_snmptrap[] = { 1, 3, 6, 1, 6, 3, 1, 1, 4, 1, 0 };
	size_t objid_snmptrap_len = OID_LENGTH(objid_snmptrap);
	oid xfp3LaserFault_oid[]   = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 2, 2, 1, 5, 1, 14 };
	size_t xfp3LaserFault_oid_len = OID_LENGTH(xfp3LaserFault_oid);
	oid      xfp3xfp3LaserFaultAlarmSev_oid[]   = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 3, 5, 3, 1, 14 };
	size_t   xfp3xfp3LaserFaultAlarmSev_oid_len = OID_LENGTH(xfp3xfp3LaserFaultAlarmSev_oid);

	netsnmp_variable_list *notification_vars = NULL;
	static u_long xfp3LaserFaultCount = 0;

	unsigned int xfp3LaserFaultAlarm = 0;

	unsigned int xfp3LaserFault = 0;
	xfp3LaserFault = pt_monitor_struct->xfp_struct.xfp_interruption_flags[2][6];

	unsigned int xfp3xfp3LaserFaultAlarmSev = 0;
	xfp3xfp3LaserFaultAlarmSev = pt_monitor_struct->xfp_struct.severity[2].laser_fault;

	unsigned int send_xfp3LaserFaultAlarm = 0;
	if (xfp3LaserFaultTemp==0 && xfp3LaserFault==1)
   {
		xfp3LaserFaultAlarm = 1;
		send_xfp3LaserFaultAlarm = 1;
   }
   else if (xfp3LaserFaultTemp==1 && xfp3LaserFault==0)
   {
	   xfp3LaserFaultAlarm = 2;
      send_xfp3LaserFaultAlarm = 1;
   }
	xfp3LaserFaultTemp = xfp3LaserFault;

	snmp_varlist_add_variable(&notification_vars, objid_snmptrap, objid_snmptrap_len, ASN_OBJECT_ID, (u_char *) notification_oid, notification_oid_len * sizeof(oid));
	snmp_varlist_add_variable(&notification_vars, xfp3LaserFault_oid, xfp3LaserFault_oid_len, ASN_INTEGER, (u_char *)&xfp3LaserFaultAlarm, sizeof(xfp3LaserFaultAlarm));
	snmp_varlist_add_variable(&notification_vars, xfp3xfp3LaserFaultAlarmSev_oid, xfp3xfp3LaserFaultAlarmSev_oid_len, ASN_INTEGER, (u_char *)&xfp3xfp3LaserFaultAlarmSev, sizeof(xfp3xfp3LaserFaultAlarmSev));

	if(send_xfp3LaserFaultAlarm == 1)
	{
		++xfp3LaserFaultCount;
		DEBUGMSGTL(("ftnc_notifications", "sending trap %ld\n",xfp3LaserFaultCount));
		send_v2trap(notification_vars);
	}

	snmp_free_varbind(notification_vars);
}

/* ***************** Implementation of XFP4 methods ***************** */

void send_xfp4Presence_notification(unsigned int clientreg, void *clientarg)
{
	DEBUGMSGTL(("token", "send_xfp4Presence_notification.\n"));

	oid 	notification_oid[] = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 2, 2, 0, 70 };
	size_t 	notification_oid_len = OID_LENGTH(notification_oid);
	oid 	objid_snmptrap[] = { 1, 3, 6, 1, 6, 3, 1, 1, 4, 1, 0 };
	size_t 	objid_snmptrap_len = OID_LENGTH(objid_snmptrap);
	oid 	xfp4Presence_oid[]   = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 2, 2, 1, 6, 1, 2 };
	size_t  xfp4Presence_oid_len = OID_LENGTH(xfp4Presence_oid);
	oid     xfp4PresenceAlarmSev_oid[]   = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 3, 5, 4, 1, 2 };
	size_t	xfp4PresenceAlarmSev_oid_len = OID_LENGTH(xfp4PresenceAlarmSev_oid);

	netsnmp_variable_list *notification_vars = NULL;
	static u_long xfp4PresenceCount = 0;

	unsigned int xfp4PresenceAlarm = 0;
	unsigned int xfp4Presence = 0;
	//xfp4Presence = 0 is present; xfp4Presence = 1 is not present.
	xfp4Presence = pt_monitor_struct->xfp_struct.xfp_presence[3];

	unsigned int xfp4PresenceAlarmSev = 0;
	xfp4PresenceAlarmSev = pt_monitor_struct->xfp_struct.severity[3].presence;

	unsigned int send_xfp4PresenceAlarm = 0;
	if (xfp4PresenceTemp==0 && xfp4Presence==1) //The alarm was activated.
   {
		xfp4PresenceAlarm = 1; //The alarm was activated.
		send_xfp4PresenceAlarm = 1; // Send notification.
   }
   else if (xfp4PresenceTemp==1 && xfp4Presence==0) //The alarm is deactivated.
   {
	   xfp4PresenceAlarm = 2; //The alarm is deactivated.
      send_xfp4PresenceAlarm = 1; //Send notification.
   }
	xfp4PresenceTemp = xfp4Presence;

	snmp_varlist_add_variable(&notification_vars, objid_snmptrap, objid_snmptrap_len, ASN_OBJECT_ID, (u_char *) notification_oid, notification_oid_len * sizeof(oid));
	snmp_varlist_add_variable(&notification_vars, xfp4Presence_oid, xfp4Presence_oid_len, ASN_INTEGER, (u_char *)&xfp4PresenceAlarm, sizeof(xfp4PresenceAlarm));
	snmp_varlist_add_variable(&notification_vars, xfp4PresenceAlarmSev_oid, xfp4PresenceAlarmSev_oid_len, ASN_INTEGER, (u_char *)&xfp4PresenceAlarmSev, sizeof(xfp4PresenceAlarmSev));

	if(send_xfp4PresenceAlarm == 1)
	{
		++xfp4PresenceCount;
		DEBUGMSGTL(("ftnc_notifications", "xfp4PresenceCount sending trap %ld\n",xfp4PresenceCount));
		send_v2trap(notification_vars);
	}

	snmp_free_varbind(notification_vars);
}

void send_xfp4RxLoss_notification(unsigned int clientreg, void *clientarg)
{
	DEBUGMSGTL(("token", "send_xfp4RxLoss_notification.\n"));

	oid 	notification_oid[] = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 2, 2, 0, 71 };
	size_t 	notification_oid_len = OID_LENGTH(notification_oid);
	oid 	objid_snmptrap[] = { 1, 3, 6, 1, 6, 3, 1, 1, 4, 1, 0 };
	size_t 	objid_snmptrap_len = OID_LENGTH(objid_snmptrap);
	oid 	xfp4RxLoss_oid[]   = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 2, 2, 1, 6, 1, 3 };
	size_t 	xfp4RxLoss_oid_len = OID_LENGTH(xfp4RxLoss_oid);
	oid     xfp4RxLossAlarmSev_oid[]   = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 3, 5, 4, 1, 3 };
	size_t	xfp4RxLossAlarmSev_oid_len = OID_LENGTH(xfp4RxLossAlarmSev_oid);

	netsnmp_variable_list *notification_vars = NULL;
	static u_long xfp4RxLossCount = 0;

	unsigned int xfp4RxLossAlarm = 0;

	unsigned int xfp4RxLoss = 0;
	xfp4RxLoss = pt_monitor_struct->xfp_struct.xfp_presence[3];

	unsigned int xfp4RxLossAlarmSev = 0;
	xfp4RxLossAlarmSev = pt_monitor_struct->xfp_struct.severity[3].rx_loss;

	unsigned int send_xfp4RxLossAlarm = 0;
	if (xfp4RxLossTemp==0 && xfp4RxLoss==1)
   {
		xfp4RxLossAlarm = 1;
		send_xfp4RxLossAlarm = 1;
   }
   else if (xfp4RxLossTemp==1 && xfp4RxLoss==0)
   {
	   xfp4RxLossAlarm = 2;
      send_xfp4RxLossAlarm = 1;
   }
	xfp4RxLossTemp = xfp4RxLoss;

	snmp_varlist_add_variable(&notification_vars, objid_snmptrap, objid_snmptrap_len, ASN_OBJECT_ID, (u_char *) notification_oid, notification_oid_len * sizeof(oid));
	snmp_varlist_add_variable(&notification_vars, xfp4RxLoss_oid, xfp4RxLoss_oid_len, ASN_INTEGER, (u_char *)&xfp4RxLossAlarm, sizeof(xfp4RxLossAlarm));
	snmp_varlist_add_variable(&notification_vars, xfp4RxLossAlarmSev_oid, xfp4RxLossAlarmSev_oid_len, ASN_INTEGER, (u_char *)&xfp4RxLossAlarmSev, sizeof(xfp4RxLossAlarmSev));

	if(send_xfp4RxLossAlarm == 1)
	{
		++xfp4RxLossCount;
		DEBUGMSGTL(("ftnc_notifications", "sending trap %ld\n",xfp4RxLossCount));
		send_v2trap(notification_vars);
	}

	snmp_free_varbind(notification_vars);
}

void send_xfp4Ready_notification(unsigned int clientreg, void *clientarg)
{
	DEBUGMSGTL(("token", "send_xfp4Ready_notification.\n"));

	oid 	notification_oid[] = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 2, 2, 0, 72 };
	size_t 	notification_oid_len = OID_LENGTH(notification_oid);
	oid 	objid_snmptrap[] = { 1, 3, 6, 1, 6, 3, 1, 1, 4, 1, 0 };
	size_t 	objid_snmptrap_len = OID_LENGTH(objid_snmptrap);
	oid 	xfp4Ready_oid[]   = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 2, 2, 1, 6, 1, 4 };
	size_t 	xfp4Ready_oid_len = OID_LENGTH(xfp4Ready_oid);
	oid     xfp4ReadyAlarmSev_oid[]   = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 3, 5, 4, 1, 4 };
	size_t	xfp4ReadyAlarmSev_oid_len = OID_LENGTH(xfp4ReadyAlarmSev_oid);

	netsnmp_variable_list *notification_vars = NULL;
	static u_long xfp4ReadyCount = 0;

	unsigned int xfp4ReadyAlarm = 0;

	unsigned int xfp4Ready = 0;
	xfp4Ready = pt_monitor_struct->xfp_struct.xfp_ready[3];

	unsigned int xfp4ReadyAlarmSev = 0;
	xfp4ReadyAlarmSev = pt_monitor_struct->xfp_struct.severity[3].ready;

	unsigned int send_xfp4ReadyAlarm = 0;
	if (xfp4ReadyTemp==0 && xfp4Ready==1)
   {
		xfp4ReadyAlarm = 1;
		send_xfp4ReadyAlarm = 1;
   }
   else if (xfp4ReadyTemp==1 && xfp4Ready==0)
   {
	  xfp4ReadyAlarm = 2;
      send_xfp4ReadyAlarm = 1;
   }
	xfp4ReadyTemp = xfp4Ready;

	snmp_varlist_add_variable(&notification_vars, objid_snmptrap, objid_snmptrap_len, ASN_OBJECT_ID, (u_char *) notification_oid, notification_oid_len * sizeof(oid));
	snmp_varlist_add_variable(&notification_vars, xfp4Ready_oid, xfp4Ready_oid_len, ASN_INTEGER, (u_char *)&xfp4ReadyAlarm, sizeof(xfp4ReadyAlarm));
	snmp_varlist_add_variable(&notification_vars, xfp4ReadyAlarmSev_oid, xfp4ReadyAlarmSev_oid_len, ASN_INTEGER, (u_char *)&xfp4ReadyAlarmSev, sizeof(xfp4ReadyAlarmSev));

	if(send_xfp4ReadyAlarm == 1)
	{
		++xfp4ReadyCount;
		DEBUGMSGTL(("ftnc_notifications", "sending trap %ld\n",xfp4ReadyCount));
		send_v2trap(notification_vars);
	}

	snmp_free_varbind(notification_vars);
}

void send_xfp4TxPower_notification(unsigned int clientreg, void *clientarg)
{
	DEBUGMSGTL(("token", "send_xfp4TxPower_notification.\n"));

   oid      notification_oid[] =  { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 2, 2, 0, 73 };
   size_t   notification_oid_len = OID_LENGTH(notification_oid);
   oid      objid_snmptrap[] = { 1, 3, 6, 1, 6, 3, 1, 1, 4, 1, 0 };
   size_t   objid_snmptrap_len = OID_LENGTH(objid_snmptrap);
   oid		xfp4TxPowerAlarm_oid[]   = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 2, 2, 1, 6, 1, 5 };
   size_t	xfp4TxPowerAlarm_oid_len = OID_LENGTH(xfp4TxPowerAlarm_oid);
   oid	xfp4TxPowerAlarmSev_oid[]   = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 3, 5, 4, 1, 5 };
   size_t	xfp4TxPowerAlarmSev_oid_len = OID_LENGTH(xfp4TxPowerAlarmSev_oid);

   netsnmp_variable_list *notification_vars = NULL;
   static u_long  xfp4TxPowerCount = 0;

   unsigned int xfp4TxPowerInt = 0;
   unsigned int xfp4TxPowerAlarm = 0;

   unsigned int send_xfp4TxPowerAlarm = 0;

   float xfp4TxPower;
   xfp4TxPower = pt_monitor_struct->xfp_struct.xfp_tx_power[3];

   unsigned int xfp4TxPowerAlarmSev = 0;
   xfp4TxPowerAlarmSev = pt_monitor_struct->xfp_struct.severity[3].tx_power;

   if (xfp4TxPower < -3 || xfp4TxPower > 0)
   { xfp4TxPowerInt = 1; }
   else
   { xfp4TxPowerInt = 0; }

   if (xfp4TxPowerTemp==0 && xfp4TxPowerInt==1)
   {
	   xfp4TxPowerAlarm = 1;
	   send_xfp4TxPowerAlarm = 1;
   }
   else if (xfp4TxPowerTemp==1 && xfp4TxPowerInt==0)
   {
	   xfp4TxPowerAlarm = 2;
	   send_xfp4TxPowerAlarm = 1;
   }
   xfp4TxPowerTemp = xfp4TxPowerInt;

   snmp_varlist_add_variable(&notification_vars, objid_snmptrap, objid_snmptrap_len, ASN_OBJECT_ID, (u_char *) notification_oid, notification_oid_len * sizeof(oid));
   snmp_varlist_add_variable(&notification_vars,  xfp4TxPowerAlarm_oid, xfp4TxPowerAlarm_oid_len, ASN_INTEGER, (u_char *)&xfp4TxPowerAlarm, sizeof(xfp4TxPowerAlarm));
   snmp_varlist_add_variable(&notification_vars, xfp4TxPowerAlarmSev_oid, xfp4TxPowerAlarmSev_oid_len, ASN_INTEGER, (u_char *)&xfp4TxPowerAlarmSev, sizeof(xfp4TxPowerAlarmSev));

   if(send_xfp4TxPowerAlarm == 1)
   {
       ++xfp4TxPowerCount;
       DEBUGMSGTL(("ftnc_notifications", "sending trap %ld\n",xfp4TxPowerCount));
       send_v2trap(notification_vars);
   }

   snmp_free_varbind(notification_vars);
}

void send_xfp4RxPower_notification(unsigned int clientreg, void *clientarg)
{
	DEBUGMSGTL(("token", "send_xfp4RxPower_notification.\n"));

   oid      notification_oid[] =  { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 2, 2, 0, 74 };
   size_t   notification_oid_len = OID_LENGTH(notification_oid);
   oid      objid_snmptrap[] = { 1, 3, 6, 1, 6, 3, 1, 1, 4, 1, 0 };
   size_t   objid_snmptrap_len = OID_LENGTH(objid_snmptrap);
   oid      xfp4RxPowerAlarm_oid[]   = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 2, 2, 1, 6, 1, 6 };
   size_t	xfp4RxPowerAlarm_oid_len = OID_LENGTH(xfp4RxPowerAlarm_oid);
   oid      xfp4RxPowerAlarmSev_oid[]   = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 3, 5, 4, 1, 6 };
   size_t   xfp4RxPowerAlarmSev_oid_len = OID_LENGTH(xfp4RxPowerAlarmSev_oid);

   netsnmp_variable_list *notification_vars = NULL;
   static u_long  xfp4RxPowerCount = 0;

   unsigned int xfp4RxPowerInt = 0;
   unsigned int xfp4RxPowerAlarm = 0;

   unsigned int send_xfp4RxPowerAlarm = 0;

   float xfp4RxPower;
   xfp4RxPower = pt_monitor_struct->xfp_struct.xfp_rx_power[3];

   unsigned int xfp4RxPowerAlarmSev = 0;
   xfp4RxPowerAlarmSev = pt_monitor_struct->xfp_struct.severity[3].rx_power;

   if (xfp4RxPower < -3 || xfp4RxPower > 0)
   { xfp4RxPowerInt = 1; }
   else
   { xfp4RxPowerInt = 0; }

   if (xfp4RxPowerTemp==0 && xfp4RxPowerInt==1)
   {
	   xfp4RxPowerAlarm = 1;
	   send_xfp4RxPowerAlarm = 1;
   }
   else if (xfp4RxPowerTemp==1 && xfp4RxPowerInt==0)
   {
	   xfp4RxPowerAlarm = 2;
	   send_xfp4RxPowerAlarm = 1;
   }
   xfp4RxPowerTemp = xfp4RxPowerInt;

   snmp_varlist_add_variable(&notification_vars, objid_snmptrap, objid_snmptrap_len, ASN_OBJECT_ID, (u_char *) notification_oid, notification_oid_len * sizeof(oid));
   snmp_varlist_add_variable(&notification_vars,  xfp4RxPowerAlarm_oid, xfp4RxPowerAlarm_oid_len, ASN_INTEGER, (u_char *)&xfp4RxPowerAlarm, sizeof(xfp4RxPowerAlarm));
   snmp_varlist_add_variable(&notification_vars, xfp4RxPowerAlarmSev_oid, xfp4RxPowerAlarmSev_oid_len, ASN_INTEGER, (u_char *)&xfp4RxPowerAlarmSev, sizeof(xfp4RxPowerAlarmSev));

   if(send_xfp4RxPowerAlarm == 1)
   {
       ++xfp4RxPowerCount;
       DEBUGMSGTL(("ftnc_notifications", "sending trap %ld\n",xfp4RxPowerCount));
       send_v2trap(notification_vars);
   }

   snmp_free_varbind(notification_vars);
}

void send_xfp4Temperature_notification(unsigned int clientreg, void *clientarg)
{
	DEBUGMSGTL(("token", "send_xfp4Temperature_notification.\n"));

   oid      notification_oid[] =  { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 2, 2, 0, 75 };
   size_t   notification_oid_len = OID_LENGTH(notification_oid);
   oid      objid_snmptrap[] = { 1, 3, 6, 1, 6, 3, 1, 1, 4, 1, 0 };
   size_t   objid_snmptrap_len = OID_LENGTH(objid_snmptrap);
   oid      xfp4TemperatureAlarm_oid[]   = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 2, 2, 1, 6, 1, 7 };
   size_t   xfp4TemperatureAlarm_oid_len = OID_LENGTH(xfp4TemperatureAlarm_oid);
   oid      xfp4TemperatureAlarmSev_oid[]   = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 3, 5, 4, 1, 7 };
   size_t   xfp4TemperatureAlarmSev_oid_len = OID_LENGTH(xfp4TemperatureAlarmSev_oid);

   netsnmp_variable_list *notification_vars = NULL;
   static u_long  xfp4TemperatureCount = 0;

   unsigned int xfp4TemperatureInt = 0;
   unsigned int xfp4TemperatureAlarm = 0;

   unsigned int send_xfp4TemperatureAlarm = 0;

   float xfp4Temperature;
   xfp4Temperature = pt_monitor_struct->xfp_struct.xfp_temperature[3];

   unsigned int xfp4TemperatureAlarmSev = 0;
   xfp4TemperatureAlarmSev = pt_monitor_struct->xfp_struct.severity[3].temperature;

   if (xfp4Temperature < 10 || xfp4Temperature > 30)
   { xfp4TemperatureInt = 1; }
   else
   { xfp4TemperatureInt = 0; }

   if (xfp4TemperatureTemp==0 && xfp4TemperatureInt==1)
   {
	   xfp4TemperatureAlarm = 1;
	   send_xfp4TemperatureAlarm = 1;
   }
   else if (xfp4TemperatureTemp==1 && xfp4TemperatureInt==0)
   {
	   xfp4TemperatureAlarm = 2;
	   send_xfp4TemperatureAlarm = 1;
   }
   xfp4TemperatureTemp = xfp4TemperatureInt;

   snmp_varlist_add_variable(&notification_vars, objid_snmptrap, objid_snmptrap_len, ASN_OBJECT_ID, (u_char *) notification_oid, notification_oid_len * sizeof(oid));
   snmp_varlist_add_variable(&notification_vars,  xfp4TemperatureAlarm_oid, xfp4TemperatureAlarm_oid_len, ASN_INTEGER, (u_char *)&xfp4TemperatureAlarm, sizeof(xfp4TemperatureAlarm));
   snmp_varlist_add_variable(&notification_vars, xfp4TemperatureAlarmSev_oid, xfp4TemperatureAlarmSev_oid_len, ASN_INTEGER, (u_char *)&xfp4TemperatureAlarmSev, sizeof(xfp4TemperatureAlarmSev));

   if(send_xfp4TemperatureAlarm == 1)
   {
       ++xfp4TemperatureCount;
       DEBUGMSGTL(("ftnc_notifications", "sending trap %ld\n",xfp4TemperatureCount));
       send_v2trap(notification_vars);
   }

   snmp_free_varbind(notification_vars);
}

void send_xfp4LowTxPower_notification(unsigned int clientreg, void *clientarg)
{
	DEBUGMSGTL(("token", "send_xfp4LowTxPower_notification.\n"));

	oid 	notification_oid[] = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 2, 2, 0, 76 };
	size_t 	notification_oid_len = OID_LENGTH(notification_oid);
	oid 	objid_snmptrap[] = { 1, 3, 6, 1, 6, 3, 1, 1, 4, 1, 0 };
	size_t 	objid_snmptrap_len = OID_LENGTH(objid_snmptrap);
	oid 	xfp4LowTxPower_oid[]   = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 2, 2, 1, 6, 1, 8 };
	size_t 	xfp4LowTxPower_oid_len = OID_LENGTH(xfp4LowTxPower_oid);
	oid     xfp4LowTxPowerAlarmSev_oid[]   = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 3, 5, 4, 1, 8 };
	size_t  xfp4LowTxPowerAlarmSev_oid_len = OID_LENGTH(xfp4LowTxPowerAlarmSev_oid);

	netsnmp_variable_list *notification_vars = NULL;
	static u_long xfp4LowTxPowerCount = 0;

	unsigned int xfp4LowTxPowerAlarm = 0;

	unsigned int xfp4LowTxPower = 0;
	xfp4LowTxPower = pt_monitor_struct->xfp_struct.xfp_interruption_flags[3][0];

	unsigned int xfp4LowTxPowerAlarmSev = 0;
	xfp4LowTxPowerAlarmSev = pt_monitor_struct->xfp_struct.severity[3].low_tx_power;

	unsigned int send_xfp4LowTxPowerAlarm = 0;
	if (xfp4LowTxPowerTemp==0 && xfp4LowTxPower==1)
   {
		xfp4LowTxPowerAlarm = 1;
		send_xfp4LowTxPowerAlarm = 1;
   }
   else if (xfp4LowTxPowerTemp==1 && xfp4LowTxPower==0)
   {
	  xfp4LowTxPowerAlarm = 2;
      send_xfp4LowTxPowerAlarm = 1;
   }
	xfp4LowTxPowerTemp = xfp4LowTxPower;

	snmp_varlist_add_variable(&notification_vars, objid_snmptrap, objid_snmptrap_len, ASN_OBJECT_ID, (u_char *) notification_oid, notification_oid_len * sizeof(oid));
	snmp_varlist_add_variable(&notification_vars, xfp4LowTxPower_oid, xfp4LowTxPower_oid_len, ASN_INTEGER, (u_char *)&xfp4LowTxPowerAlarm, sizeof(xfp4LowTxPowerAlarm));
	snmp_varlist_add_variable(&notification_vars, xfp4LowTxPowerAlarmSev_oid, xfp4LowTxPowerAlarmSev_oid_len, ASN_INTEGER, (u_char *)&xfp4LowTxPowerAlarmSev, sizeof(xfp4LowTxPowerAlarmSev));

	if(send_xfp4LowTxPowerAlarm == 1)
	{
		++xfp4LowTxPowerCount;
		DEBUGMSGTL(("ftnc_notifications", "sending trap %ld\n",xfp4LowTxPowerCount));
		send_v2trap(notification_vars);
	}

	snmp_free_varbind(notification_vars);
}

void send_xfp4HighTxPower_notification(unsigned int clientreg, void *clientarg)
{
	DEBUGMSGTL(("token", "send_xfp4HighTxPower_notification.\n"));

	oid 	notification_oid[] = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 2, 2, 0, 77 };
	size_t  notification_oid_len = OID_LENGTH(notification_oid);
	oid 	objid_snmptrap[] = { 1, 3, 6, 1, 6, 3, 1, 1, 4, 1, 0 };
	size_t 	objid_snmptrap_len = OID_LENGTH(objid_snmptrap);
	oid 	xfp4HighTxPower_oid[]   = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 2, 2, 1, 6, 1, 9 };
	size_t 	xfp4HighTxPower_oid_len = OID_LENGTH(xfp4HighTxPower_oid);
	oid     xfp4HighTxPowerAlarmSev_oid[]   = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 3, 5, 4, 1, 9 };
	size_t	xfp4HighTxPowerAlarmSev_oid_len = OID_LENGTH(xfp4HighTxPowerAlarmSev_oid);

	netsnmp_variable_list *notification_vars = NULL;
	static u_long xfp4HighTxPowerCount = 0;

	unsigned int xfp4HighTxPowerAlarm = 0;

	unsigned int xfp4HighTxPower = 0;
	xfp4HighTxPower = pt_monitor_struct->xfp_struct.xfp_interruption_flags[3][1];

	unsigned int xfp4HighTxPowerAlarmSev = 0;
	xfp4HighTxPowerAlarmSev = pt_monitor_struct->xfp_struct.severity[3].high_tx_power;

	unsigned int send_xfp4HighTxPowerAlarm = 0;
	if (xfp4HighTxPowerTemp==0 && xfp4HighTxPower==1)
   {
		xfp4HighTxPowerAlarm = 1;
		send_xfp4HighTxPowerAlarm = 1;
   }
   else if (xfp4HighTxPowerTemp==1 && xfp4HighTxPower==0)
   {
	  xfp4HighTxPowerAlarm = 2;
      send_xfp4HighTxPowerAlarm = 1;
   }
	xfp4HighTxPowerTemp = xfp4HighTxPower;

	snmp_varlist_add_variable(&notification_vars, objid_snmptrap, objid_snmptrap_len, ASN_OBJECT_ID, (u_char *) notification_oid, notification_oid_len * sizeof(oid));
	snmp_varlist_add_variable(&notification_vars, xfp4HighTxPower_oid, xfp4HighTxPower_oid_len, ASN_INTEGER, (u_char *)&xfp4HighTxPowerAlarm, sizeof(xfp4HighTxPowerAlarm));
	snmp_varlist_add_variable(&notification_vars, xfp4HighTxPowerAlarmSev_oid, xfp4HighTxPowerAlarmSev_oid_len, ASN_INTEGER, (u_char *)&xfp4HighTxPowerAlarmSev, sizeof(xfp4HighTxPowerAlarmSev));

	if(send_xfp4HighTxPowerAlarm == 1)
	{
		++xfp4HighTxPowerCount;
		DEBUGMSGTL(("ftnc_notifications", "sending trap %ld\n",xfp4HighTxPowerCount));
		send_v2trap(notification_vars);
	}

	snmp_free_varbind(notification_vars);
}

void send_xfp4LowRxPower_notification(unsigned int clientreg, void *clientarg)
{
	DEBUGMSGTL(("token", "send_xfp4LowRxPower_notification.\n"));

	oid 	notification_oid[] = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 2, 2, 0, 78 };
	size_t 	notification_oid_len = OID_LENGTH(notification_oid);
	oid 	objid_snmptrap[] = { 1, 3, 6, 1, 6, 3, 1, 1, 4, 1, 0 };
	size_t 	objid_snmptrap_len = OID_LENGTH(objid_snmptrap);
	oid 	xfp4LowRxPower_oid[]   = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 2, 2, 1, 6, 1, 10 };
	size_t 	xfp4LowRxPower_oid_len = OID_LENGTH(xfp4LowRxPower_oid);
	oid     xfp4LowRxPowerAlarmSev_oid[]   = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 3, 5, 4, 1, 10 };
	size_t	xfp4LowRxPowerAlarmSev_oid_len = OID_LENGTH(xfp4LowRxPowerAlarmSev_oid);

	netsnmp_variable_list *notification_vars = NULL;
	static u_long xfp4LowRxPowerCount = 0;

	unsigned int xfp4LowRxPowerAlarm = 0;

	unsigned int xfp4LowRxPower = 0;
	xfp4LowRxPower = pt_monitor_struct->xfp_struct.xfp_interruption_flags[3][2];

	unsigned int xfp4LowRxPowerAlarmSev = 0;
	xfp4LowRxPowerAlarmSev = pt_monitor_struct->xfp_struct.severity[3].low_rx_power;

	unsigned int send_xfp4LowRxPowerAlarm = 0;
	if (xfp4LowRxPowerTemp==0 && xfp4LowRxPower==1)
   {
		xfp4LowRxPowerAlarm = 1;
		send_xfp4LowRxPowerAlarm = 1;
   }
   else if (xfp4LowRxPowerTemp==1 && xfp4LowRxPower==0)
   {
	  xfp4LowRxPowerAlarm = 2;
      send_xfp4LowRxPowerAlarm = 1;
   }
	xfp4LowRxPowerTemp = xfp4LowRxPower;

	snmp_varlist_add_variable(&notification_vars, objid_snmptrap, objid_snmptrap_len, ASN_OBJECT_ID, (u_char *) notification_oid, notification_oid_len * sizeof(oid));

	snmp_varlist_add_variable(&notification_vars, xfp4LowRxPower_oid, xfp4LowRxPower_oid_len, ASN_INTEGER, (u_char *)&xfp4LowRxPowerAlarm, sizeof(xfp4LowRxPowerAlarm));
	snmp_varlist_add_variable(&notification_vars, xfp4LowRxPowerAlarmSev_oid, xfp4LowRxPowerAlarmSev_oid_len, ASN_INTEGER, (u_char *)&xfp4LowRxPowerAlarmSev, sizeof(xfp4LowRxPowerAlarmSev));

	if(send_xfp4LowRxPowerAlarm == 1)
	{
		++xfp4LowRxPowerCount;
		DEBUGMSGTL(("ftnc_notifications", "sending trap %ld\n",xfp4LowRxPowerCount));
		send_v2trap(notification_vars);
	}

	snmp_free_varbind(notification_vars);
}

void send_xfp4HighRxPower_notification(unsigned int clientreg, void *clientarg)
{
	DEBUGMSGTL(("token", "send_xfp4HighRxPower_notification.\n"));

	oid notification_oid[] = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 2, 2, 0, 79 };
	size_t notification_oid_len = OID_LENGTH(notification_oid);
	oid 	objid_snmptrap[] = { 1, 3, 6, 1, 6, 3, 1, 1, 4, 1, 0 };
	size_t 	objid_snmptrap_len = OID_LENGTH(objid_snmptrap);
	oid 	xfp4HighRxPower_oid[]   = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 2, 2, 1, 6, 1, 11 };
	size_t 	xfp4HighRxPower_oid_len = OID_LENGTH(xfp4HighRxPower_oid);
	oid     xfp4HighRxPowerAlarmSev_oid[]   = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 3, 5, 4, 1, 11 };
	size_t	xfp4HighRxPowerAlarmSev_oid_len = OID_LENGTH(xfp4HighRxPowerAlarmSev_oid);

	netsnmp_variable_list *notification_vars = NULL;
	static u_long xfp4HighRxPowerCount = 0;

	unsigned int xfp4HighRxPowerAlarm = 0;

	unsigned int xfp4HighRxPower = 0;
	xfp4HighRxPower = pt_monitor_struct->xfp_struct.xfp_interruption_flags[3][3];

	unsigned int xfp4HighRxPowerAlarmSev = 0;
	xfp4HighRxPowerAlarmSev = pt_monitor_struct->xfp_struct.severity[3].high_rx_power;

	unsigned int send_xfp4HighRxPowerAlarm = 0;
	if (xfp4HighRxPowerTemp==0 && xfp4HighRxPower==1) //The alarm was activated.
   {
		xfp4HighRxPowerAlarm = 1; //The alarm was activated.
		send_xfp4HighRxPowerAlarm = 1; // Send notification.
   }
   else if (xfp4HighRxPowerTemp==1 && xfp4HighRxPower==0) //The alarm is deactivated.
   {
	  xfp4HighRxPowerAlarm = 2; //The alarm is deactivated.
      send_xfp4HighRxPowerAlarm = 1; //Send notification.
   }
	xfp4HighRxPowerTemp = xfp4HighRxPower;

	snmp_varlist_add_variable(&notification_vars, objid_snmptrap, objid_snmptrap_len, ASN_OBJECT_ID, (u_char *) notification_oid, notification_oid_len * sizeof(oid));
	snmp_varlist_add_variable(&notification_vars, xfp4HighRxPower_oid, xfp4HighRxPower_oid_len, ASN_INTEGER, (u_char *)&xfp4HighRxPowerAlarm, sizeof(xfp4HighRxPowerAlarm));
	snmp_varlist_add_variable(&notification_vars, xfp4HighRxPowerAlarmSev_oid, xfp4HighRxPowerAlarmSev_oid_len, ASN_INTEGER, (u_char *)&xfp4HighRxPowerAlarmSev, sizeof(xfp4HighRxPowerAlarmSev));

	if(send_xfp4HighRxPowerAlarm == 1)
	{
		++xfp4HighRxPowerCount;
		DEBUGMSGTL(("ftnc_notifications", "sending trap %ld\n",xfp4HighRxPowerCount));
		send_v2trap(notification_vars);
	}

	snmp_free_varbind(notification_vars);
}

void send_xfp4RxCdrLOL_notification(unsigned int clientreg, void *clientarg)
{
	DEBUGMSGTL(("token", "send_xfp4RxCdrLOL_notification.\n"));

	oid 	notification_oid[] = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 2, 2, 0, 80 };
	size_t 	notification_oid_len = OID_LENGTH(notification_oid);
	oid 	objid_snmptrap[] = { 1, 3, 6, 1, 6, 3, 1, 1, 4, 1, 0 };
	size_t 	objid_snmptrap_len = OID_LENGTH(objid_snmptrap);
	oid 	xfp4RxCdrLOL_oid[]   = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 2, 2, 1, 6, 1, 12 };
	size_t 	xfp4RxCdrLOL_oid_len = OID_LENGTH(xfp4RxCdrLOL_oid);
	oid     xfp4RxCdrLOLAlarmSev_oid[]   = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 3, 5, 4, 1, 12 };
	size_t  xfp4RxCdrLOLAlarmSev_oid_len = OID_LENGTH(xfp4RxCdrLOLAlarmSev_oid);

	netsnmp_variable_list *notification_vars = NULL;
	static u_long xfp4RxCdrLOLCount = 0;

	unsigned int xfp4RxCdrLOLAlarm = 0;

	unsigned int xfp4RxCdrLOL = 0;
	xfp4RxCdrLOL = pt_monitor_struct->xfp_struct.xfp_interruption_flags[3][4];

	unsigned int xfp4RxCdrLOLAlarmSev = 0;
	xfp4RxCdrLOLAlarmSev = pt_monitor_struct->xfp_struct.severity[3].rx_cdr_loss_of_lock;

	unsigned int send_xfp4RxCdrLOLAlarm = 0;
	if (xfp4RxCdrLOLTemp==0 && xfp4RxCdrLOL==1)
   {
		xfp4RxCdrLOLAlarm = 1;
		send_xfp4RxCdrLOLAlarm = 1;
   }
   else if (xfp4RxCdrLOLTemp==1 && xfp4RxCdrLOL==0)
   {
	   xfp4RxCdrLOLAlarm = 2;
      send_xfp4RxCdrLOLAlarm = 1;
   }
	xfp4RxCdrLOLTemp = xfp4RxCdrLOL;

	snmp_varlist_add_variable(&notification_vars, objid_snmptrap, objid_snmptrap_len, ASN_OBJECT_ID, (u_char *) notification_oid, notification_oid_len * sizeof(oid));
	snmp_varlist_add_variable(&notification_vars, xfp4RxCdrLOL_oid, xfp4RxCdrLOL_oid_len, ASN_INTEGER, (u_char *)&xfp4RxCdrLOLAlarm, sizeof(xfp4RxCdrLOLAlarm));
	snmp_varlist_add_variable(&notification_vars, xfp4RxCdrLOLAlarmSev_oid, xfp4RxCdrLOLAlarmSev_oid_len, ASN_INTEGER, (u_char *)&xfp4RxCdrLOLAlarmSev, sizeof(xfp4RxCdrLOLAlarmSev));

	if(send_xfp4RxCdrLOLAlarm == 1)
	{
		++xfp4RxCdrLOLCount;
		DEBUGMSGTL(("ftnc_notifications", "sending trap %ld\n",xfp4RxCdrLOLCount));
		send_v2trap(notification_vars);
	}

	snmp_free_varbind(notification_vars);
}

void send_xfp4TxCdrLOL_notification(unsigned int clientreg, void *clientarg)
{
	DEBUGMSGTL(("token", "send_xfp4TxCdrLOL_notification.\n"));

	oid notification_oid[] = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 2, 2, 0, 81 };
	size_t 	notification_oid_len = OID_LENGTH(notification_oid);
	oid 	objid_snmptrap[] = { 1, 3, 6, 1, 6, 3, 1, 1, 4, 1, 0 };
	size_t 	objid_snmptrap_len = OID_LENGTH(objid_snmptrap);
	oid 	xfp4TxCdrLOL_oid[]   = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 2, 2, 1, 6, 1, 13 };
	size_t 	xfp4TxCdrLOL_oid_len = OID_LENGTH(xfp4TxCdrLOL_oid);
	oid     xfp4TxCdrLOLAlarmSev_oid[]   = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 3, 5, 4, 1, 13 };
	size_t	xfp4TxCdrLOLAlarmSev_oid_len = OID_LENGTH(xfp4TxCdrLOLAlarmSev_oid);

	netsnmp_variable_list *notification_vars = NULL;
	static u_long xfp4TxCdrLOLCount = 0;

	unsigned int xfp4TxCdrLOLAlarm = 0;

	unsigned int xfp4TxCdrLOL = 0;
	xfp4TxCdrLOL = pt_monitor_struct->xfp_struct.xfp_interruption_flags[3][5];

	unsigned int xfp4TxCdrLOLAlarmSev = 0;
	xfp4TxCdrLOLAlarmSev = pt_monitor_struct->xfp_struct.severity[3].tx_cdr_loss_of_lock;

	unsigned int send_xfp4TxCdrLOLAlarm = 0;
	if (xfp4TxCdrLOLTemp==0 && xfp4TxCdrLOL==1)
   {
		xfp4TxCdrLOLAlarm = 1;
		send_xfp4TxCdrLOLAlarm = 1;
   }
   else if (xfp4TxCdrLOLTemp==1 && xfp4TxCdrLOL==0)
   {
	   xfp4TxCdrLOLAlarm = 2;
      send_xfp4TxCdrLOLAlarm = 1;
   }
	xfp4TxCdrLOLTemp = xfp4TxCdrLOL;

	snmp_varlist_add_variable(&notification_vars, objid_snmptrap, objid_snmptrap_len, ASN_OBJECT_ID, (u_char *) notification_oid, notification_oid_len * sizeof(oid));
	snmp_varlist_add_variable(&notification_vars, xfp4TxCdrLOL_oid, xfp4TxCdrLOL_oid_len, ASN_INTEGER, (u_char *)&xfp4TxCdrLOLAlarm, sizeof(xfp4TxCdrLOLAlarm));
	snmp_varlist_add_variable(&notification_vars, xfp4TxCdrLOLAlarmSev_oid, xfp4TxCdrLOLAlarmSev_oid_len, ASN_INTEGER, (u_char *)&xfp4TxCdrLOLAlarmSev, sizeof(xfp4TxCdrLOLAlarmSev));

	if(send_xfp4TxCdrLOLAlarm == 1)
	{
		++xfp4TxCdrLOLCount;
		DEBUGMSGTL(("ftnc_notifications", "sending trap %ld\n",xfp4TxCdrLOLCount));
		send_v2trap(notification_vars);
	}

	snmp_free_varbind(notification_vars);
}

void send_xfp4LaserFault_notification(unsigned int clientreg, void *clientarg)
{
	DEBUGMSGTL(("token", "send_xfp4LaserFault_notification.\n"));

	oid notification_oid[] = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 2, 2, 0, 82 };
	size_t notification_oid_len = OID_LENGTH(notification_oid);
	oid objid_snmptrap[] = { 1, 3, 6, 1, 6, 3, 1, 1, 4, 1, 0 };
	size_t objid_snmptrap_len = OID_LENGTH(objid_snmptrap);
	oid xfp4LaserFault_oid[]   = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 2, 2, 1, 6, 1, 14 };
	size_t xfp4LaserFault_oid_len = OID_LENGTH(xfp4LaserFault_oid);
	oid      xfp4xfp4LaserFaultAlarmSev_oid[]   = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 3, 5, 4, 1, 14 };
	size_t   xfp4xfp4LaserFaultAlarmSev_oid_len = OID_LENGTH(xfp4xfp4LaserFaultAlarmSev_oid);

	netsnmp_variable_list *notification_vars = NULL;
	static u_long xfp4LaserFaultCount = 0;

	unsigned int xfp4LaserFaultAlarm = 0;

	unsigned int xfp4LaserFault = 0;
	xfp4LaserFault = pt_monitor_struct->xfp_struct.xfp_interruption_flags[3][6];

	unsigned int xfp4xfp4LaserFaultAlarmSev = 0;
	xfp4xfp4LaserFaultAlarmSev = pt_monitor_struct->xfp_struct.severity[3].laser_fault;

	unsigned int send_xfp4LaserFaultAlarm = 0;
	if (xfp4LaserFaultTemp==0 && xfp4LaserFault==1)
   {
		xfp4LaserFaultAlarm = 1;
		send_xfp4LaserFaultAlarm = 1;
   }
   else if (xfp4LaserFaultTemp==1 && xfp4LaserFault==0)
   {
	   xfp4LaserFaultAlarm = 2;
      send_xfp4LaserFaultAlarm = 1;
   }
	xfp4LaserFaultTemp = xfp4LaserFault;

	snmp_varlist_add_variable(&notification_vars, objid_snmptrap, objid_snmptrap_len, ASN_OBJECT_ID, (u_char *) notification_oid, notification_oid_len * sizeof(oid));
	snmp_varlist_add_variable(&notification_vars, xfp4LaserFault_oid, xfp4LaserFault_oid_len, ASN_INTEGER, (u_char *)&xfp4LaserFaultAlarm, sizeof(xfp4LaserFaultAlarm));
	snmp_varlist_add_variable(&notification_vars, xfp4xfp4LaserFaultAlarmSev_oid, xfp4xfp4LaserFaultAlarmSev_oid_len, ASN_INTEGER, (u_char *)&xfp4xfp4LaserFaultAlarmSev, sizeof(xfp4xfp4LaserFaultAlarmSev));

	if(send_xfp4LaserFaultAlarm == 1)
	{
		++xfp4LaserFaultCount;
		DEBUGMSGTL(("ftnc_notifications", "sending trap %ld\n",xfp4LaserFaultCount));
		send_v2trap(notification_vars);
	}

	snmp_free_varbind(notification_vars);
}


// TRAFFIC PROCESSOR NOTIFICATIONS
//Traffic Processor Line Notifications

void send_tp_lineFramerFssmmtrb3s_notification(unsigned int clientreg, void *clientarg)
{
	DEBUGMSGTL(("token", "send_tplineFramerFssmmtrb3s_notification.\n"));

	oid notification_oid[] = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 2, 2, 0, 83 };
	size_t notification_oid_len = OID_LENGTH(notification_oid);
	oid objid_snmptrap[] = { 1, 3, 6, 1, 6, 3, 1, 1, 4, 1, 0 };
	size_t objid_snmptrap_len = OID_LENGTH(objid_snmptrap);
	oid lineFramerFssmmtrb3s_oid[]   = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 2, 2, 1, 7, 1, 2 };
	size_t lineFramerFssmmtrb3s_oid_len = OID_LENGTH(lineFramerFssmmtrb3s_oid);
	oid      lineFramerFssmmtrb3sAlarmSev_oid[]   = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 3, 6, 1, 1, 5 };
	size_t   lineFramerFssmmtrb3sAlarmSev_oid_len = OID_LENGTH(lineFramerFssmmtrb3sAlarmSev_oid);

	netsnmp_variable_list *notification_vars = NULL;
	static u_long lineFramerFssmmtrb3sCount = 0;

	unsigned int lineFramerFssmmtrb3sAlarm = 0;

	unsigned int lineFramerFssmmtrb3s = 0;
	lineFramerFssmmtrb3s = pt_monitor_struct->tp_defects_struct.tp_line_framer_status.fields.fsmmtrb3s;

	unsigned int lineFramerFssmmtrb3sAlarmSev = 0;
	lineFramerFssmmtrb3sAlarmSev = pt_monitor_struct->tp_defects_struct.severity.severity_line.FramerFsmmtrb3s;

	unsigned int send_lineFramerFssmmtrb3sAlarm = 0;
	if (lineFramerFssmmtrb3sTemp==0 && lineFramerFssmmtrb3s==1)
   {
		lineFramerFssmmtrb3sAlarm = 1;
		send_lineFramerFssmmtrb3sAlarm = 1;
   }
   else if (lineFramerFssmmtrb3sTemp==1 && lineFramerFssmmtrb3s==0)
   {
	   lineFramerFssmmtrb3sAlarm = 2;
      send_lineFramerFssmmtrb3sAlarm = 1;
   }
	lineFramerFssmmtrb3sTemp = lineFramerFssmmtrb3s;

	snmp_varlist_add_variable(&notification_vars, objid_snmptrap, objid_snmptrap_len, ASN_OBJECT_ID, (u_char *) notification_oid, notification_oid_len * sizeof(oid));
	snmp_varlist_add_variable(&notification_vars, lineFramerFssmmtrb3s_oid, lineFramerFssmmtrb3s_oid_len, ASN_INTEGER, (u_char *)&lineFramerFssmmtrb3sAlarm, sizeof(lineFramerFssmmtrb3sAlarm));
	snmp_varlist_add_variable(&notification_vars, lineFramerFssmmtrb3sAlarmSev_oid, lineFramerFssmmtrb3sAlarmSev_oid_len, ASN_INTEGER, (u_char *)&lineFramerFssmmtrb3sAlarmSev, sizeof(lineFramerFssmmtrb3sAlarmSev));

	if(send_lineFramerFssmmtrb3sAlarm == 1)
	{
		++lineFramerFssmmtrb3sCount;
		DEBUGMSGTL(("ftnc_notifications", "sending trap %ld\n",lineFramerFssmmtrb3sCount));
		send_v2trap(notification_vars);
	}

	snmp_free_varbind(notification_vars);
}

void send_tp_lineFramerFssmmtrb2s_notification(unsigned int clientreg, void *clientarg)
{
	DEBUGMSGTL(("token", "send_tplineFramerFssmmtrb2s_notification.\n"));

	oid notification_oid[] = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 2, 2, 0, 84 };
	size_t notification_oid_len = OID_LENGTH(notification_oid);
	oid objid_snmptrap[] = { 1, 3, 6, 1, 6, 3, 1, 1, 4, 1, 0 };
	size_t objid_snmptrap_len = OID_LENGTH(objid_snmptrap);
	oid lineFramerFssmmtrb2s_oid[]   = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 2, 2, 1, 7, 1, 3 };
	size_t lineFramerFssmmtrb2s_oid_len = OID_LENGTH(lineFramerFssmmtrb2s_oid);
	oid      lineFramerFssmmtrb2sAlarmSev_oid[]   = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 3, 6, 1, 1, 4 };
	size_t   lineFramerFssmmtrb2sAlarmSev_oid_len = OID_LENGTH(lineFramerFssmmtrb2sAlarmSev_oid);

	netsnmp_variable_list *notification_vars = NULL;
	static u_long lineFramerFssmmtrb2sCount = 0;

	unsigned int lineFramerFssmmtrb2sAlarm = 0;

	unsigned int lineFramerFssmmtrb2s = 0;
	lineFramerFssmmtrb2s = pt_monitor_struct->tp_defects_struct.tp_line_framer_status.fields.fsmmtrb2s;

	unsigned int lineFramerFssmmtrb2sAlarmSev = 0;
	lineFramerFssmmtrb2sAlarmSev = pt_monitor_struct->tp_defects_struct.severity.severity_line.FramerFsmmtrb2s;

	unsigned int send_lineFramerFssmmtrb2sAlarm = 0;
	if (lineFramerFssmmtrb2sTemp==0 && lineFramerFssmmtrb2s==1)
   {
		lineFramerFssmmtrb2sAlarm = 1;
		send_lineFramerFssmmtrb2sAlarm = 1;
   }
   else if (lineFramerFssmmtrb2sTemp==1 && lineFramerFssmmtrb2s==0)
   {
	   lineFramerFssmmtrb2sAlarm = 2;
      send_lineFramerFssmmtrb2sAlarm = 1;
   }
	lineFramerFssmmtrb2sTemp = lineFramerFssmmtrb2s;

	snmp_varlist_add_variable(&notification_vars, objid_snmptrap, objid_snmptrap_len, ASN_OBJECT_ID, (u_char *) notification_oid, notification_oid_len * sizeof(oid));
	snmp_varlist_add_variable(&notification_vars, lineFramerFssmmtrb2s_oid, lineFramerFssmmtrb2s_oid_len, ASN_INTEGER, (u_char *)&lineFramerFssmmtrb2sAlarm, sizeof(lineFramerFssmmtrb2sAlarm));
	snmp_varlist_add_variable(&notification_vars, lineFramerFssmmtrb2sAlarmSev_oid, lineFramerFssmmtrb2sAlarmSev_oid_len, ASN_INTEGER, (u_char *)&lineFramerFssmmtrb2sAlarmSev, sizeof(lineFramerFssmmtrb2sAlarmSev));

	if(send_lineFramerFssmmtrb2sAlarm == 1)
	{
		++lineFramerFssmmtrb2sCount;
		DEBUGMSGTL(("ftnc_notifications", "sending trap %ld\n",lineFramerFssmmtrb2sCount));
		send_v2trap(notification_vars);
	}

	snmp_free_varbind(notification_vars);
}

void send_tp_lineFramerFssmmtrb1s_notification(unsigned int clientreg, void *clientarg)
{
	DEBUGMSGTL(("token", "send_tplineFramerFssmmtrb1s_notification.\n"));

	oid notification_oid[] = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 2, 2, 0, 85 };
	size_t notification_oid_len = OID_LENGTH(notification_oid);
	oid objid_snmptrap[] = { 1, 3, 6, 1, 6, 3, 1, 1, 4, 1, 0 };
	size_t objid_snmptrap_len = OID_LENGTH(objid_snmptrap);
	oid lineFramerFssmmtrb1s_oid[]   = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 2, 2, 1, 7, 1, 4 };
	size_t lineFramerFssmmtrb1s_oid_len = OID_LENGTH(lineFramerFssmmtrb1s_oid);
	oid      lineFramerFssmmtrb1sAlarmSev_oid[]   = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 3, 6, 1, 1, 3 };
	size_t   lineFramerFssmmtrb1sAlarmSev_oid_len = OID_LENGTH(lineFramerFssmmtrb1sAlarmSev_oid);

	netsnmp_variable_list *notification_vars = NULL;
	static u_long lineFramerFssmmtrb1sCount = 0;

	unsigned int lineFramerFssmmtrb1sAlarm = 0;

	unsigned int lineFramerFssmmtrb1s = 0;
	lineFramerFssmmtrb1s = pt_monitor_struct->tp_defects_struct.tp_line_framer_status.fields.fsmmtrb1s;

	unsigned int lineFramerFssmmtrb1sAlarmSev = 0;
	lineFramerFssmmtrb1sAlarmSev = pt_monitor_struct->tp_defects_struct.severity.severity_line.FramerFsmmtrb1s;

	unsigned int send_lineFramerFssmmtrb1sAlarm = 0;
	if (lineFramerFssmmtrb1sTemp==0 && lineFramerFssmmtrb1s==1)
   {
		lineFramerFssmmtrb1sAlarm = 1;
		send_lineFramerFssmmtrb1sAlarm = 1;
   }
   else if (lineFramerFssmmtrb1sTemp==1 && lineFramerFssmmtrb1s==0)
   {
	   lineFramerFssmmtrb1sAlarm = 2;
      send_lineFramerFssmmtrb1sAlarm = 1;
   }
	lineFramerFssmmtrb1sTemp = lineFramerFssmmtrb1s;

	snmp_varlist_add_variable(&notification_vars, objid_snmptrap, objid_snmptrap_len, ASN_OBJECT_ID, (u_char *) notification_oid, notification_oid_len * sizeof(oid));
	snmp_varlist_add_variable(&notification_vars, lineFramerFssmmtrb1s_oid, lineFramerFssmmtrb1s_oid_len, ASN_INTEGER, (u_char *)&lineFramerFssmmtrb1sAlarm, sizeof(lineFramerFssmmtrb1sAlarm));
	snmp_varlist_add_variable(&notification_vars, lineFramerFssmmtrb1sAlarmSev_oid, lineFramerFssmmtrb1sAlarmSev_oid_len, ASN_INTEGER, (u_char *)&lineFramerFssmmtrb1sAlarmSev, sizeof(lineFramerFssmmtrb1sAlarmSev));

	if(send_lineFramerFssmmtrb1sAlarm == 1)
	{
		++lineFramerFssmmtrb1sCount;
		DEBUGMSGTL(("ftnc_notifications", "sending trap %ld\n",lineFramerFssmmtrb1sCount));
		send_v2trap(notification_vars);
	}

	snmp_free_varbind(notification_vars);
}

void send_tp_lineFramerFsmms_notification(unsigned int clientreg, void *clientarg)
{
	DEBUGMSGTL(("token", "send_tplineFramerFsmms_notification.\n"));

	oid notification_oid[] = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 2, 2, 0, 86 };
	size_t notification_oid_len = OID_LENGTH(notification_oid);
	oid objid_snmptrap[] = { 1, 3, 6, 1, 6, 3, 1, 1, 4, 1, 0 };
	size_t objid_snmptrap_len = OID_LENGTH(objid_snmptrap);
	oid lineFramerFsmms_oid[]   = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 2, 2, 1, 7, 1, 5 };
	size_t lineFramerFsmms_oid_len = OID_LENGTH(lineFramerFsmms_oid);
	oid      lineFramerFsmmsAlarmSev_oid[]   = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 3, 6, 1, 1, 2 };
	size_t   lineFramerFsmmsAlarmSev_oid_len = OID_LENGTH(lineFramerFsmmsAlarmSev_oid);

	netsnmp_variable_list *notification_vars = NULL;
	static u_long lineFramerFsmmsCount = 0;

	unsigned int lineFramerFsmmsAlarm = 0;

	unsigned int lineFramerFsmms = 0;
	lineFramerFsmms = pt_monitor_struct->tp_defects_struct.tp_line_framer_status.fields.fsmms;

	unsigned int lineFramerFsmmsAlarmSev = 0;
	lineFramerFsmmsAlarmSev = pt_monitor_struct->tp_defects_struct.severity.severity_line.FramerFsmms;

	unsigned int send_lineFramerFsmmsAlarm = 0;
	if (lineFramerFsmmsTemp==0 && lineFramerFsmms==1)
   {
		lineFramerFsmmsAlarm = 1;
		send_lineFramerFsmmsAlarm = 1;
   }
   else if (lineFramerFsmmsTemp==1 && lineFramerFsmms==0)
   {
	   lineFramerFsmmsAlarm = 2;
      send_lineFramerFsmmsAlarm = 1;
   }
	lineFramerFsmmsTemp = lineFramerFsmms;

	snmp_varlist_add_variable(&notification_vars, objid_snmptrap, objid_snmptrap_len, ASN_OBJECT_ID, (u_char *) notification_oid, notification_oid_len * sizeof(oid));
	snmp_varlist_add_variable(&notification_vars, lineFramerFsmms_oid, lineFramerFsmms_oid_len, ASN_INTEGER, (u_char *)&lineFramerFsmmsAlarm, sizeof(lineFramerFsmmsAlarm));
	snmp_varlist_add_variable(&notification_vars, lineFramerFsmmsAlarmSev_oid, lineFramerFsmmsAlarmSev_oid_len, ASN_INTEGER, (u_char *)&lineFramerFsmmsAlarmSev, sizeof(lineFramerFsmmsAlarmSev));

	if(send_lineFramerFsmmsAlarm == 1)
	{
		++lineFramerFsmmsCount;
		DEBUGMSGTL(("ftnc_notifications", "sending trap %ld\n",lineFramerFsmmsCount));
		send_v2trap(notification_vars);
	}

	snmp_free_varbind(notification_vars);
}


void send_tp_lineFramerSif_notification(unsigned int clientreg, void *clientarg)
{
	DEBUGMSGTL(("token", "send_tplineFramerSif_notification.\n"));

	oid notification_oid[] = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 2, 2, 0, 87 };
	size_t notification_oid_len = OID_LENGTH(notification_oid);
	oid objid_snmptrap[] = { 1, 3, 6, 1, 6, 3, 1, 1, 4, 1, 0 };
	size_t objid_snmptrap_len = OID_LENGTH(objid_snmptrap);
	oid lineFramerSif_oid[]   = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 2, 2, 1, 7, 1, 6 };
	size_t lineFramerSif_oid_len = OID_LENGTH(lineFramerSif_oid);
	oid      lineFramerSifAlarmSev_oid[]   = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 3, 6, 1, 1, 8 };
	size_t   lineFramerSifAlarmSev_oid_len = OID_LENGTH(lineFramerSifAlarmSev_oid);

	netsnmp_variable_list *notification_vars = NULL;
	static u_long lineFramerSifCount = 0;

	unsigned int lineFramerSifAlarm = 0;

	unsigned int lineFramerSif = 0;
	lineFramerSif = pt_monitor_struct->tp_defects_struct.tp_line_framer_status.fields.sif;

	unsigned int lineFramerSifAlarmSev = 0;
	lineFramerSifAlarmSev = pt_monitor_struct->tp_defects_struct.severity.severity_line.FramerSif;

	unsigned int send_lineFramerSifAlarm = 0;
	if (lineFramerSifTemp==0 && lineFramerSif==1)
   {
		lineFramerSifAlarm = 1;
		send_lineFramerSifAlarm = 1;
   }
   else if (lineFramerSifTemp==1 && lineFramerSif==0)
   {
	   lineFramerSifAlarm = 2;
      send_lineFramerSifAlarm = 1;
   }
	lineFramerSifTemp = lineFramerSif;

	snmp_varlist_add_variable(&notification_vars, objid_snmptrap, objid_snmptrap_len, ASN_OBJECT_ID, (u_char *) notification_oid, notification_oid_len * sizeof(oid));
	snmp_varlist_add_variable(&notification_vars, lineFramerSif_oid, lineFramerSif_oid_len, ASN_INTEGER, (u_char *)&lineFramerSifAlarm, sizeof(lineFramerSifAlarm));
	snmp_varlist_add_variable(&notification_vars, lineFramerSifAlarmSev_oid, lineFramerSifAlarmSev_oid_len, ASN_INTEGER, (u_char *)&lineFramerSifAlarmSev, sizeof(lineFramerSifAlarmSev));

	if(send_lineFramerSifAlarm == 1)
	{
		++lineFramerSifCount;
		DEBUGMSGTL(("ftnc_notifications", "sending trap %ld\n",lineFramerSifCount));
		send_v2trap(notification_vars);
	}

	snmp_free_varbind(notification_vars);
}

void send_tp_lineFramerSoof_notification(unsigned int clientreg, void *clientarg)
{
	DEBUGMSGTL(("token", "send_tplineFramerSoof_notification.\n"));

	oid notification_oid[] = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 2, 2, 0, 88 };
	size_t notification_oid_len = OID_LENGTH(notification_oid);
	oid objid_snmptrap[] = { 1, 3, 6, 1, 6, 3, 1, 1, 4, 1, 0 };
	size_t objid_snmptrap_len = OID_LENGTH(objid_snmptrap);
	oid lineFramerSoof_oid[]   = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 2, 2, 1, 7, 1, 7 };
	size_t lineFramerSoof_oid_len = OID_LENGTH(lineFramerSoof_oid);
	oid      lineFramerSoofAlarmSev_oid[]   = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 3, 6, 1, 1, 6 };
	size_t   lineFramerSoofAlarmSev_oid_len = OID_LENGTH(lineFramerSoofAlarmSev_oid);

	netsnmp_variable_list *notification_vars = NULL;
	static u_long lineFramerSoofCount = 0;

	unsigned int lineFramerSoofAlarm = 0;

	unsigned int lineFramerSoof = 0;
	lineFramerSoof = pt_monitor_struct->tp_defects_struct.tp_line_framer_status.fields.soof;

	unsigned int lineFramerSoofAlarmSev = 0;
	lineFramerSoofAlarmSev = pt_monitor_struct->tp_defects_struct.severity.severity_line.FramerSoof;

	unsigned int send_lineFramerSoofAlarm = 0;
	if (lineFramerSoofTemp==0 && lineFramerSoof==1)
   {
		lineFramerSoofAlarm = 1;
		send_lineFramerSoofAlarm = 1;
   }
   else if (lineFramerSoofTemp==1 && lineFramerSoof==0)
   {
	   lineFramerSoofAlarm = 2;
      send_lineFramerSoofAlarm = 1;
   }
	lineFramerSoofTemp = lineFramerSoof;

	snmp_varlist_add_variable(&notification_vars, objid_snmptrap, objid_snmptrap_len, ASN_OBJECT_ID, (u_char *) notification_oid, notification_oid_len * sizeof(oid));
	snmp_varlist_add_variable(&notification_vars, lineFramerSoof_oid, lineFramerSoof_oid_len, ASN_INTEGER, (u_char *)&lineFramerSoofAlarm, sizeof(lineFramerSoofAlarm));
	snmp_varlist_add_variable(&notification_vars, lineFramerSoofAlarmSev_oid, lineFramerSoofAlarmSev_oid_len, ASN_INTEGER, (u_char *)&lineFramerSoofAlarmSev, sizeof(lineFramerSoofAlarmSev));

	if(send_lineFramerSoofAlarm == 1)
	{
		++lineFramerSoofCount;
		DEBUGMSGTL(("ftnc_notifications", "sending trap %ld\n",lineFramerSoofCount));
		send_v2trap(notification_vars);
	}

	snmp_free_varbind(notification_vars);
}

void send_tp_lineFramerSlof_notification(unsigned int clientreg, void *clientarg)
{
	DEBUGMSGTL(("token", "send_tplineFramerSlof_notification.\n"));

	oid notification_oid[] = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 2, 2, 0, 89 };
	size_t notification_oid_len = OID_LENGTH(notification_oid);
	oid objid_snmptrap[] = { 1, 3, 6, 1, 6, 3, 1, 1, 4, 1, 0 };
	size_t objid_snmptrap_len = OID_LENGTH(objid_snmptrap);
	oid lineFramerSlof_oid[]   = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 2, 2, 1, 7, 1, 8 };
	size_t lineFramerSlof_oid_len = OID_LENGTH(lineFramerSlof_oid);
	oid      lineFramerSlofAlarmSev_oid[]   = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 3, 6, 1, 1, 7 };
	size_t   lineFramerSlofAlarmSev_oid_len = OID_LENGTH(lineFramerSlofAlarmSev_oid);

	netsnmp_variable_list *notification_vars = NULL;
	static u_long lineFramerSlofCount = 0;

	unsigned int lineFramerSlofAlarm = 0;

	unsigned int lineFramerSlof = 0;
	lineFramerSlof = pt_monitor_struct->tp_defects_struct.tp_line_framer_status.fields.slof;

	unsigned int lineFramerSlofAlarmSev = 0;
	lineFramerSlofAlarmSev = pt_monitor_struct->tp_defects_struct.severity.severity_line.FramerSlof;

	unsigned int send_lineFramerSlofAlarm = 0;
	if (lineFramerSlofTemp==0 && lineFramerSlof==1)
   {
		lineFramerSlofAlarm = 1;
		send_lineFramerSlofAlarm = 1;
   }
   else if (lineFramerSlofTemp==1 && lineFramerSlof==0)
   {
	   lineFramerSlofAlarm = 2;
      send_lineFramerSlofAlarm = 1;
   }
	lineFramerSlofTemp = lineFramerSlof;

	snmp_varlist_add_variable(&notification_vars, objid_snmptrap, objid_snmptrap_len, ASN_OBJECT_ID, (u_char *) notification_oid, notification_oid_len * sizeof(oid));
	snmp_varlist_add_variable(&notification_vars, lineFramerSlof_oid, lineFramerSlof_oid_len, ASN_INTEGER, (u_char *)&lineFramerSlofAlarm, sizeof(lineFramerSlofAlarm));
	snmp_varlist_add_variable(&notification_vars, lineFramerSlofAlarmSev_oid, lineFramerSlofAlarmSev_oid_len, ASN_INTEGER, (u_char *)&lineFramerSlofAlarmSev, sizeof(lineFramerSlofAlarmSev));

	if(send_lineFramerSlofAlarm == 1)
	{
		++lineFramerSlofCount;
		DEBUGMSGTL(("ftnc_notifications", "sending trap %ld\n",lineFramerSlofCount));
		send_v2trap(notification_vars);
	}

	snmp_free_varbind(notification_vars);
}

void send_tp_lineFramerFst_notification(unsigned int clientreg, void *clientarg)
{
	DEBUGMSGTL(("token", "send_tplineFramerFst_notification.\n"));

	oid notification_oid[] = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 2, 2, 0, 90 };
	size_t notification_oid_len = OID_LENGTH(notification_oid);
	oid objid_snmptrap[] = { 1, 3, 6, 1, 6, 3, 1, 1, 4, 1, 0 };
	size_t objid_snmptrap_len = OID_LENGTH(objid_snmptrap);
	oid lineFramerFst_oid[]   = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 2, 2, 1, 7, 1, 9 };
	size_t lineFramerFst_oid_len = OID_LENGTH(lineFramerFst_oid);
	oid      lineFramerFstAlarmSev_oid[]   = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 3, 6, 1, 1, 9 };
	size_t   lineFramerFstAlarmSev_oid_len = OID_LENGTH(lineFramerFstAlarmSev_oid);

	netsnmp_variable_list *notification_vars = NULL;
	static u_long lineFramerFstCount = 0;

	unsigned int lineFramerFstAlarm = 0;

	unsigned int lineFramerFst = 0;
	lineFramerFst = pt_monitor_struct->tp_defects_struct.tp_line_framer_status.fields.fst;

	unsigned int lineFramerFstAlarmSev = 0;
	lineFramerFstAlarmSev = pt_monitor_struct->tp_defects_struct.severity.severity_line.FramerFst;

	unsigned int send_lineFramerFstAlarm = 0;
	if (lineFramerFstTemp==0 && lineFramerFst==1)
   {
		lineFramerFstAlarm = 1;
		send_lineFramerFstAlarm = 1;
   }
   else if (lineFramerFstTemp==1 && lineFramerFst==0)
   {
	   lineFramerFstAlarm = 2;
      send_lineFramerFstAlarm = 1;
   }
	lineFramerFstTemp = lineFramerFst;

	snmp_varlist_add_variable(&notification_vars, objid_snmptrap, objid_snmptrap_len, ASN_OBJECT_ID, (u_char *) notification_oid, notification_oid_len * sizeof(oid));
	snmp_varlist_add_variable(&notification_vars, lineFramerFst_oid, lineFramerFst_oid_len, ASN_INTEGER, (u_char *)&lineFramerFstAlarm, sizeof(lineFramerFstAlarm));
	snmp_varlist_add_variable(&notification_vars, lineFramerFstAlarmSev_oid, lineFramerFstAlarmSev_oid_len, ASN_INTEGER, (u_char *)&lineFramerFstAlarmSev, sizeof(lineFramerFstAlarmSev));

	if(send_lineFramerFstAlarm == 1)
	{
		++lineFramerFstCount;
		DEBUGMSGTL(("ftnc_notifications", "sending trap %ld\n",lineFramerFstCount));
		send_v2trap(notification_vars);
	}

	snmp_free_varbind(notification_vars);
}

void send_tp_lineLosstatLosf_notification(unsigned int clientreg, void *clientarg)
{
	DEBUGMSGTL(("token", "send_tplineLosstatLosf_notification.\n"));

	oid notification_oid[] = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 2, 2, 0, 91 };
	size_t notification_oid_len = OID_LENGTH(notification_oid);
	oid objid_snmptrap[] = { 1, 3, 6, 1, 6, 3, 1, 1, 4, 1, 0 };
	size_t objid_snmptrap_len = OID_LENGTH(objid_snmptrap);
	oid lineLosstatLosf_oid[]   = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 2, 2, 1, 7, 1, 10 };
	size_t lineLosstatLosf_oid_len = OID_LENGTH(lineLosstatLosf_oid);
	oid      lineLosstatLosfAlarmSev_oid[]   = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 3, 6, 1, 1, 10 };
	size_t   lineLosstatLosfAlarmSev_oid_len = OID_LENGTH(lineLosstatLosfAlarmSev_oid);

	netsnmp_variable_list *notification_vars = NULL;
	static u_long lineLosstatLosfCount = 0;

	unsigned int lineLosstatLosfAlarm = 0;

	unsigned int lineLosstatLosf = 0;
	lineLosstatLosf = pt_monitor_struct->tp_defects_struct.tp_line_los_status.fields.losf;

	unsigned int lineLosstatLosfAlarmSev = 0;
	lineLosstatLosfAlarmSev = pt_monitor_struct->tp_defects_struct.severity.severity_line.LosstatLosf;

	unsigned int send_lineLosstatLosfAlarm = 0;
	if (lineLosstatLosfTemp==0 && lineLosstatLosf==1)
   {
		lineLosstatLosfAlarm = 1;
		send_lineLosstatLosfAlarm = 1;
   }
   else if (lineLosstatLosfTemp==1 && lineLosstatLosf==0)
   {
	   lineLosstatLosfAlarm = 2;
      send_lineLosstatLosfAlarm = 1;
   }
	lineLosstatLosfTemp = lineLosstatLosf;

	snmp_varlist_add_variable(&notification_vars, objid_snmptrap, objid_snmptrap_len, ASN_OBJECT_ID, (u_char *) notification_oid, notification_oid_len * sizeof(oid));
	snmp_varlist_add_variable(&notification_vars, lineLosstatLosf_oid, lineLosstatLosf_oid_len, ASN_INTEGER, (u_char *)&lineLosstatLosfAlarm, sizeof(lineLosstatLosfAlarm));
	snmp_varlist_add_variable(&notification_vars, lineLosstatLosfAlarmSev_oid, lineLosstatLosfAlarmSev_oid_len, ASN_INTEGER, (u_char *)&lineLosstatLosfAlarmSev, sizeof(lineLosstatLosfAlarmSev));

	if(send_lineLosstatLosfAlarm == 1)
	{
		++lineLosstatLosfCount;
		DEBUGMSGTL(("ftnc_notifications", "sending trap %ld\n",lineLosstatLosfCount));
		send_v2trap(notification_vars);
	}

	snmp_free_varbind(notification_vars);
}

void send_tp_lineSecmonFlom_notification(unsigned int clientreg, void *clientarg)
{
	DEBUGMSGTL(("token", "send_tplineSecmonFlom_notification.\n"));

	oid notification_oid[] = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 2, 2, 0, 92 };
	size_t notification_oid_len = OID_LENGTH(notification_oid);
	oid objid_snmptrap[] = { 1, 3, 6, 1, 6, 3, 1, 1, 4, 1, 0 };
	size_t objid_snmptrap_len = OID_LENGTH(objid_snmptrap);
	oid lineSecmonFlom_oid[]   = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 2, 2, 1, 7, 1, 11 };
	size_t lineSecmonFlom_oid_len = OID_LENGTH(lineSecmonFlom_oid);
	oid      lineSecmonFlomAlarmSev_oid[]   = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 3, 6, 1, 1, 19 };
	size_t   lineSecmonFlomAlarmSev_oid_len = OID_LENGTH(lineSecmonFlomAlarmSev_oid);

	netsnmp_variable_list *notification_vars = NULL;
	static u_long lineSecmonFlomCount = 0;

	unsigned int lineSecmonFlomAlarm = 0;

	unsigned int lineSecmonFlom = 0;
	lineSecmonFlom = pt_monitor_struct->tp_defects_struct.tp_line_section_mon.fields.flom;

	unsigned int lineSecmonFlomAlarmSev = 0;
	lineSecmonFlomAlarmSev = pt_monitor_struct->tp_defects_struct.severity.severity_line.SecmonFlom;

	unsigned int send_lineSecmonFlomAlarm = 0;
	if (lineSecmonFlomTemp==0 && lineSecmonFlom==1)
   {
		lineSecmonFlomAlarm = 1;
		send_lineSecmonFlomAlarm = 1;
   }
   else if (lineSecmonFlomTemp==1 && lineSecmonFlom==0)
   {
	   lineSecmonFlomAlarm = 2;
      send_lineSecmonFlomAlarm = 1;
   }
	lineSecmonFlomTemp = lineSecmonFlom;

	snmp_varlist_add_variable(&notification_vars, objid_snmptrap, objid_snmptrap_len, ASN_OBJECT_ID, (u_char *) notification_oid, notification_oid_len * sizeof(oid));
	snmp_varlist_add_variable(&notification_vars, lineSecmonFlom_oid, lineSecmonFlom_oid_len, ASN_INTEGER, (u_char *)&lineSecmonFlomAlarm, sizeof(lineSecmonFlomAlarm));
	snmp_varlist_add_variable(&notification_vars, lineSecmonFlomAlarmSev_oid, lineSecmonFlomAlarmSev_oid_len, ASN_INTEGER, (u_char *)&lineSecmonFlomAlarmSev, sizeof(lineSecmonFlomAlarmSev));

	if(send_lineSecmonFlomAlarm == 1)
	{
		++lineSecmonFlomCount;
		DEBUGMSGTL(("ftnc_notifications", "sending trap %ld\n",lineSecmonFlomCount));
		send_v2trap(notification_vars);
	}

	snmp_free_varbind(notification_vars);
}

void send_tp_lineSecmonBipsfs_notification(unsigned int clientreg, void *clientarg)
{
	DEBUGMSGTL(("token", "send_tplineSecmonBipsfs_notification.\n"));

	oid notification_oid[] = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 2, 2, 0, 93 };
	size_t notification_oid_len = OID_LENGTH(notification_oid);
	oid objid_snmptrap[] = { 1, 3, 6, 1, 6, 3, 1, 1, 4, 1, 0 };
	size_t objid_snmptrap_len = OID_LENGTH(objid_snmptrap);
	oid lineSecmonBipsfs_oid[]   = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 2, 2, 1, 7, 1, 12 };
	size_t lineSecmonBipsfs_oid_len = OID_LENGTH(lineSecmonBipsfs_oid);
	oid      lineSecmonBipsfsAlarmSev_oid[]   = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 3, 6, 1, 1, 16 };
	size_t   lineSecmonBipsfsAlarmSev_oid_len = OID_LENGTH(lineSecmonBipsfsAlarmSev_oid);

	netsnmp_variable_list *notification_vars = NULL;
	static u_long lineSecmonBipsfsCount = 0;

	unsigned int lineSecmonBipsfsAlarm = 0;

	unsigned int lineSecmonBipsfs = 0;
	lineSecmonBipsfs = pt_monitor_struct->tp_defects_struct.tp_line_section_mon.fields.bipsfs;

	unsigned int lineSecmonBipsfsAlarmSev = 0;
	lineSecmonBipsfsAlarmSev = pt_monitor_struct->tp_defects_struct.severity.severity_line.SecmonBipsfs;

	unsigned int send_lineSecmonBipsfsAlarm = 0;
	if (lineSecmonBipsfsTemp==0 && lineSecmonBipsfs==1)
   {
		lineSecmonBipsfsAlarm = 1;
		send_lineSecmonBipsfsAlarm = 1;
   }
   else if (lineSecmonBipsfsTemp==1 && lineSecmonBipsfs==0)
   {
	   lineSecmonBipsfsAlarm = 2;
      send_lineSecmonBipsfsAlarm = 1;
   }
	lineSecmonBipsfsTemp = lineSecmonBipsfs;

	snmp_varlist_add_variable(&notification_vars, objid_snmptrap, objid_snmptrap_len, ASN_OBJECT_ID, (u_char *) notification_oid, notification_oid_len * sizeof(oid));
	snmp_varlist_add_variable(&notification_vars, lineSecmonBipsfs_oid, lineSecmonBipsfs_oid_len, ASN_INTEGER, (u_char *)&lineSecmonBipsfsAlarm, sizeof(lineSecmonBipsfsAlarm));
	snmp_varlist_add_variable(&notification_vars, lineSecmonBipsfsAlarmSev_oid, lineSecmonBipsfsAlarmSev_oid_len, ASN_INTEGER, (u_char *)&lineSecmonBipsfsAlarmSev, sizeof(lineSecmonBipsfsAlarmSev));

	if(send_lineSecmonBipsfsAlarm == 1)
	{
		++lineSecmonBipsfsCount;
		DEBUGMSGTL(("ftnc_notifications", "sending trap %ld\n",lineSecmonBipsfsCount));
		send_v2trap(notification_vars);
	}

	snmp_free_varbind(notification_vars);
}

void send_tp_lineSecmonDiae_notification(unsigned int clientreg, void *clientarg)
{
	DEBUGMSGTL(("token", "send_tplineSecmonDiae_notification.\n"));

	oid notification_oid[] = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 2, 2, 0, 94 };
	size_t notification_oid_len = OID_LENGTH(notification_oid);
	oid objid_snmptrap[] = { 1, 3, 6, 1, 6, 3, 1, 1, 4, 1, 0 };
	size_t objid_snmptrap_len = OID_LENGTH(objid_snmptrap);
	oid lineSecmonDiae_oid[]   = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 2, 2, 1, 7, 1, 13 };
	size_t lineSecmonDiae_oid_len = OID_LENGTH(lineSecmonDiae_oid);
	oid      lineSecmonDiaeAlarmSev_oid[]   = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 3, 6, 1, 1, 18 };
	size_t   lineSecmonDiaeAlarmSev_oid_len = OID_LENGTH(lineSecmonDiaeAlarmSev_oid);

	netsnmp_variable_list *notification_vars = NULL;
	static u_long lineSecmonDiaeCount = 0;

	unsigned int lineSecmonDiaeAlarm = 0;

	unsigned int lineSecmonDiae = 0;
	lineSecmonDiae = pt_monitor_struct->tp_defects_struct.tp_line_section_mon.fields.diae;

	unsigned int lineSecmonDiaeAlarmSev = 0;
	lineSecmonDiaeAlarmSev = pt_monitor_struct->tp_defects_struct.severity.severity_line.SecmonDiae;

	unsigned int send_lineSecmonDiaeAlarm = 0;
	if (lineSecmonDiaeTemp==0 && lineSecmonDiae==1)
   {
		lineSecmonDiaeAlarm = 1;
		send_lineSecmonDiaeAlarm = 1;
   }
   else if (lineSecmonDiaeTemp==1 && lineSecmonDiae==0)
   {
	   lineSecmonDiaeAlarm = 2;
      send_lineSecmonDiaeAlarm = 1;
   }
	lineSecmonDiaeTemp = lineSecmonDiae;

	snmp_varlist_add_variable(&notification_vars, objid_snmptrap, objid_snmptrap_len, ASN_OBJECT_ID, (u_char *) notification_oid, notification_oid_len * sizeof(oid));
	snmp_varlist_add_variable(&notification_vars, lineSecmonDiae_oid, lineSecmonDiae_oid_len, ASN_INTEGER, (u_char *)&lineSecmonDiaeAlarm, sizeof(lineSecmonDiaeAlarm));
	snmp_varlist_add_variable(&notification_vars, lineSecmonDiaeAlarmSev_oid, lineSecmonDiaeAlarmSev_oid_len, ASN_INTEGER, (u_char *)&lineSecmonDiaeAlarmSev, sizeof(lineSecmonDiaeAlarmSev));

	if(send_lineSecmonDiaeAlarm == 1)
	{
		++lineSecmonDiaeCount;
		DEBUGMSGTL(("ftnc_notifications", "sending trap %ld\n",lineSecmonDiaeCount));
		send_v2trap(notification_vars);
	}

	snmp_free_varbind(notification_vars);
}

void send_tp_lineSecmonDbdi_notification(unsigned int clientreg, void *clientarg)
{
	DEBUGMSGTL(("token", "send_tplineSecmonDbdi_notification.\n"));

	oid notification_oid[] = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 2, 2, 0, 95 };
	size_t notification_oid_len = OID_LENGTH(notification_oid);
	oid objid_snmptrap[] = { 1, 3, 6, 1, 6, 3, 1, 1, 4, 1, 0 };
	size_t objid_snmptrap_len = OID_LENGTH(objid_snmptrap);
	oid lineSecmonDbdi_oid[]   = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 2, 2, 1, 7, 1, 14 };
	size_t lineSecmonDbdi_oid_len = OID_LENGTH(lineSecmonDbdi_oid);
	oid      lineSecmonDbdiAlarmSev_oid[]   = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 3, 6, 1, 1, 17 };
	size_t   lineSecmonDbdiAlarmSev_oid_len = OID_LENGTH(lineSecmonDbdiAlarmSev_oid);

	netsnmp_variable_list *notification_vars = NULL;
	static u_long lineSecmonDbdiCount = 0;

	unsigned int lineSecmonDbdiAlarm = 0;

	unsigned int lineSecmonDbdi = 0;
	lineSecmonDbdi = pt_monitor_struct->tp_defects_struct.tp_line_section_mon.fields.dbdi;

	unsigned int lineSecmonDbdiAlarmSev = 0;
	lineSecmonDbdiAlarmSev = pt_monitor_struct->tp_defects_struct.severity.severity_line.SecmonDbdi;

	unsigned int send_lineSecmonDbdiAlarm = 0;
	if (lineSecmonDbdiTemp==0 && lineSecmonDbdi==1)
   {
		lineSecmonDbdiAlarm = 1;
		send_lineSecmonDbdiAlarm = 1;
   }
   else if (lineSecmonDbdiTemp==1 && lineSecmonDbdi==0)
   {
	   lineSecmonDbdiAlarm = 2;
      send_lineSecmonDbdiAlarm = 1;
   }
	lineSecmonDbdiTemp = lineSecmonDbdi;

	snmp_varlist_add_variable(&notification_vars, objid_snmptrap, objid_snmptrap_len, ASN_OBJECT_ID, (u_char *) notification_oid, notification_oid_len * sizeof(oid));
	snmp_varlist_add_variable(&notification_vars, lineSecmonDbdi_oid, lineSecmonDbdi_oid_len, ASN_INTEGER, (u_char *)&lineSecmonDbdiAlarm, sizeof(lineSecmonDbdiAlarm));
	snmp_varlist_add_variable(&notification_vars, lineSecmonDbdiAlarmSev_oid, lineSecmonDbdiAlarmSev_oid_len, ASN_INTEGER, (u_char *)&lineSecmonDbdiAlarmSev, sizeof(lineSecmonDbdiAlarmSev));

	if(send_lineSecmonDbdiAlarm == 1)
	{
		++lineSecmonDbdiCount;
		DEBUGMSGTL(("ftnc_notifications", "sending trap %ld\n",lineSecmonDbdiCount));
		send_v2trap(notification_vars);
	}

	snmp_free_varbind(notification_vars);
}

void send_tp_lineSecmonLom_notification(unsigned int clientreg, void *clientarg)
{
	DEBUGMSGTL(("token", "send_tplineSecmonLom_notification.\n"));

	oid notification_oid[] = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 2, 2, 0, 96 };
	size_t notification_oid_len = OID_LENGTH(notification_oid);
	oid objid_snmptrap[] = { 1, 3, 6, 1, 6, 3, 1, 1, 4, 1, 0 };
	size_t objid_snmptrap_len = OID_LENGTH(objid_snmptrap);
	oid lineSecmonLom_oid[]   = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 2, 2, 1, 7, 1, 15 };
	size_t lineSecmonLom_oid_len = OID_LENGTH(lineSecmonLom_oid);
	oid      lineSecmonLomAlarmSev_oid[]   = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 3, 6, 1, 1, 20 };
	size_t   lineSecmonLomAlarmSev_oid_len = OID_LENGTH(lineSecmonLomAlarmSev_oid);

	netsnmp_variable_list *notification_vars = NULL;
	static u_long lineSecmonLomCount = 0;

	unsigned int lineSecmonLomAlarm = 0;

	unsigned int lineSecmonLom = 0;
	lineSecmonLom = pt_monitor_struct->tp_defects_struct.tp_line_section_mon.fields.lom;

	unsigned int lineSecmonLomAlarmSev = 0;
	lineSecmonLomAlarmSev = pt_monitor_struct->tp_defects_struct.severity.severity_line.SecmonLom;

	unsigned int send_lineSecmonLomAlarm = 0;
	if (lineSecmonLomTemp==0 && lineSecmonLom==1)
   {
		lineSecmonLomAlarm = 1;
		send_lineSecmonLomAlarm = 1;
   }
   else if (lineSecmonLomTemp==1 && lineSecmonLom==0)
   {
	   lineSecmonLomAlarm = 2;
      send_lineSecmonLomAlarm = 1;
   }
	lineSecmonLomTemp = lineSecmonLom;

	snmp_varlist_add_variable(&notification_vars, objid_snmptrap, objid_snmptrap_len, ASN_OBJECT_ID, (u_char *) notification_oid, notification_oid_len * sizeof(oid));
	snmp_varlist_add_variable(&notification_vars, lineSecmonLom_oid, lineSecmonLom_oid_len, ASN_INTEGER, (u_char *)&lineSecmonLomAlarm, sizeof(lineSecmonLomAlarm));
	snmp_varlist_add_variable(&notification_vars, lineSecmonLomAlarmSev_oid, lineSecmonLomAlarmSev_oid_len, ASN_INTEGER, (u_char *)&lineSecmonLomAlarmSev, sizeof(lineSecmonLomAlarmSev));

	if(send_lineSecmonLomAlarm == 1)
	{
		++lineSecmonLomCount;
		DEBUGMSGTL(("ftnc_notifications", "sending trap %ld\n",lineSecmonLomCount));
		send_v2trap(notification_vars);
	}

	snmp_free_varbind(notification_vars);
}

void send_tp_linePathmonAccstat_notification(unsigned int clientreg, void *clientarg)
{
	DEBUGMSGTL(("token", "send_tplinePathmonAccstat_notification.\n"));

	oid notification_oid[] = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 2, 2, 0, 97 };
	size_t notification_oid_len = OID_LENGTH(notification_oid);
	oid objid_snmptrap[] = { 1, 3, 6, 1, 6, 3, 1, 1, 4, 1, 0 };
	size_t objid_snmptrap_len = OID_LENGTH(objid_snmptrap);
	oid linePathmonAccstat_oid[]   = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 2, 2, 1, 7, 1, 16 };
	size_t linePathmonAccstat_oid_len = OID_LENGTH(linePathmonAccstat_oid);
	oid      linePathmonAccstatAlarmSev_oid[]   = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 3, 6, 1, 1, 11 };
	size_t   linePathmonAccstatAlarmSev_oid_len = OID_LENGTH(linePathmonAccstatAlarmSev_oid);

	netsnmp_variable_list *notification_vars = NULL;
	static u_long linePathmonAccstatCount = 0;

	unsigned int linePathmonAccstatAlarm = 0;

	unsigned int linePathmonAccstat = 0;
	linePathmonAccstat = pt_monitor_struct->tp_defects_struct.tp_line_path_mon.fields.accstat;

	unsigned int linePathmonAccstatAlarmSev = 0;
	linePathmonAccstatAlarmSev = pt_monitor_struct->tp_defects_struct.severity.severity_line.PathmonAccstat;

	unsigned int send_linePathmonAccstatAlarm = 0;
	if (linePathmonAccstatTemp==0 && linePathmonAccstat==1)
   {
		linePathmonAccstatAlarm = 1;
		send_linePathmonAccstatAlarm = 1;
   }
   else if (linePathmonAccstatTemp==1 && linePathmonAccstat==0)
   {
	   linePathmonAccstatAlarm = 2;
      send_linePathmonAccstatAlarm = 1;
   }
	linePathmonAccstatTemp = linePathmonAccstat;

	snmp_varlist_add_variable(&notification_vars, objid_snmptrap, objid_snmptrap_len, ASN_OBJECT_ID, (u_char *) notification_oid, notification_oid_len * sizeof(oid));
	snmp_varlist_add_variable(&notification_vars, linePathmonAccstat_oid, linePathmonAccstat_oid_len, ASN_INTEGER, (u_char *)&linePathmonAccstatAlarm, sizeof(linePathmonAccstatAlarm));
	snmp_varlist_add_variable(&notification_vars, linePathmonAccstatAlarmSev_oid, linePathmonAccstatAlarmSev_oid_len, ASN_INTEGER, (u_char *)&linePathmonAccstatAlarmSev, sizeof(linePathmonAccstatAlarmSev));

	if(send_linePathmonAccstatAlarm == 1)
	{
		++linePathmonAccstatCount;
		DEBUGMSGTL(("ftnc_notifications", "sending trap %ld\n",linePathmonAccstatCount));
		send_v2trap(notification_vars);
	}

	snmp_free_varbind(notification_vars);
}

void send_tp_linePathmonMsiunst_notification(unsigned int clientreg, void *clientarg)
{
	DEBUGMSGTL(("token", "send_tplinePathmonMsiunst_notification.\n"));

	oid notification_oid[] = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 2, 2, 0, 98 };
	size_t notification_oid_len = OID_LENGTH(notification_oid);
	oid objid_snmptrap[] = { 1, 3, 6, 1, 6, 3, 1, 1, 4, 1, 0 };
	size_t objid_snmptrap_len = OID_LENGTH(objid_snmptrap);
	oid linePathmonMsiunst_oid[]   = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 2, 2, 1, 7, 1, 17 };
	size_t linePathmonMsiunst_oid_len = OID_LENGTH(linePathmonMsiunst_oid);
	oid      linePathmonMsiunstAlarmSev_oid[]   = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 3, 6, 1, 1, 15 };
	size_t   linePathmonMsiunstAlarmSev_oid_len = OID_LENGTH(linePathmonMsiunstAlarmSev_oid);

	netsnmp_variable_list *notification_vars = NULL;
	static u_long linePathmonMsiunstCount = 0;

	unsigned int linePathmonMsiunstAlarm = 0;

	unsigned int linePathmonMsiunst = 0;
	linePathmonMsiunst = pt_monitor_struct->tp_defects_struct.tp_line_path_mon.fields.msiunst;

	unsigned int linePathmonMsiunstAlarmSev = 0;
	linePathmonMsiunstAlarmSev = pt_monitor_struct->tp_defects_struct.severity.severity_line.PathmonMsiunst;

	unsigned int send_linePathmonMsiunstAlarm = 0;
	if (linePathmonMsiunstTemp==0 && linePathmonMsiunst==1)
   {
		linePathmonMsiunstAlarm = 1;
		send_linePathmonMsiunstAlarm = 1;
   }
   else if (linePathmonMsiunstTemp==1 && linePathmonMsiunst==0)
   {
	   linePathmonMsiunstAlarm = 2;
      send_linePathmonMsiunstAlarm = 1;
   }
	linePathmonMsiunstTemp = linePathmonMsiunst;

	snmp_varlist_add_variable(&notification_vars, objid_snmptrap, objid_snmptrap_len, ASN_OBJECT_ID, (u_char *) notification_oid, notification_oid_len * sizeof(oid));
	snmp_varlist_add_variable(&notification_vars, linePathmonMsiunst_oid, linePathmonMsiunst_oid_len, ASN_INTEGER, (u_char *)&linePathmonMsiunstAlarm, sizeof(linePathmonMsiunstAlarm));
	snmp_varlist_add_variable(&notification_vars, linePathmonMsiunstAlarmSev_oid, linePathmonMsiunstAlarmSev_oid_len, ASN_INTEGER, (u_char *)&linePathmonMsiunstAlarmSev, sizeof(linePathmonMsiunstAlarmSev));

	if(send_linePathmonMsiunstAlarm == 1)
	{
		++linePathmonMsiunstCount;
		DEBUGMSGTL(("ftnc_notifications", "sending trap %ld\n",linePathmonMsiunstCount));
		send_v2trap(notification_vars);
	}

	snmp_free_varbind(notification_vars);
}

void send_tp_linePathmonDais_notification(unsigned int clientreg, void *clientarg)
{
	DEBUGMSGTL(("token", "send_tplinePathmonDais_notification.\n"));

	oid notification_oid[] = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 2, 2, 0, 99 };
	size_t notification_oid_len = OID_LENGTH(notification_oid);
	oid objid_snmptrap[] = { 1, 3, 6, 1, 6, 3, 1, 1, 4, 1, 0 };
	size_t objid_snmptrap_len = OID_LENGTH(objid_snmptrap);
	oid linePathmonDais_oid[]   = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 2, 2, 1, 7, 1, 18 };
	size_t linePathmonDais_oid_len = OID_LENGTH(linePathmonDais_oid);
	oid      linePathmonDaisAlarmSev_oid[]   = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 3, 6, 1, 1, 12 };
	size_t   linePathmonDaisAlarmSev_oid_len = OID_LENGTH(linePathmonDaisAlarmSev_oid);

	netsnmp_variable_list *notification_vars = NULL;
	static u_long linePathmonDaisCount = 0;

	unsigned int linePathmonDaisAlarm = 0;

	unsigned int linePathmonDais = 0;
	linePathmonDais = pt_monitor_struct->tp_defects_struct.tp_line_path_mon.fields.dais;

	unsigned int linePathmonDaisAlarmSev = 0;
	linePathmonDaisAlarmSev = pt_monitor_struct->tp_defects_struct.severity.severity_line.PathmonDais;

	unsigned int send_linePathmonDaisAlarm = 0;
	if (linePathmonDaisTemp==0 && linePathmonDais==1)
   {
		linePathmonDaisAlarm = 1;
		send_linePathmonDaisAlarm = 1;
   }
   else if (linePathmonDaisTemp==1 && linePathmonDais==0)
   {
	   linePathmonDaisAlarm = 2;
      send_linePathmonDaisAlarm = 1;
   }
	linePathmonDaisTemp = linePathmonDais;

	snmp_varlist_add_variable(&notification_vars, objid_snmptrap, objid_snmptrap_len, ASN_OBJECT_ID, (u_char *) notification_oid, notification_oid_len * sizeof(oid));
	snmp_varlist_add_variable(&notification_vars, linePathmonDais_oid, linePathmonDais_oid_len, ASN_INTEGER, (u_char *)&linePathmonDaisAlarm, sizeof(linePathmonDaisAlarm));
	snmp_varlist_add_variable(&notification_vars, linePathmonDaisAlarmSev_oid, linePathmonDaisAlarmSev_oid_len, ASN_INTEGER, (u_char *)&linePathmonDaisAlarmSev, sizeof(linePathmonDaisAlarmSev));

	if(send_linePathmonDaisAlarm == 1)
	{
		++linePathmonDaisCount;
		DEBUGMSGTL(("ftnc_notifications", "sending trap %ld\n",linePathmonDaisCount));
		send_v2trap(notification_vars);
	}

	snmp_free_varbind(notification_vars);
}

void send_tp_linePathmonDlck_notification(unsigned int clientreg, void *clientarg)
{
	DEBUGMSGTL(("token", "send_tplinePathmonDlck_notification.\n"));

	oid notification_oid[] = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 2, 2, 0, 100 };
	size_t notification_oid_len = OID_LENGTH(notification_oid);
	oid objid_snmptrap[] = { 1, 3, 6, 1, 6, 3, 1, 1, 4, 1, 0 };
	size_t objid_snmptrap_len = OID_LENGTH(objid_snmptrap);
	oid linePathmonDlck_oid[]   = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 2, 2, 1, 7, 1, 19 };
	size_t linePathmonDlck_oid_len = OID_LENGTH(linePathmonDlck_oid);
	oid      linePathmonDlckAlarmSev_oid[]   = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 3, 6, 1, 1, 14 };
	size_t   linePathmonDlckAlarmSev_oid_len = OID_LENGTH(linePathmonDlckAlarmSev_oid);

	netsnmp_variable_list *notification_vars = NULL;
	static u_long linePathmonDlckCount = 0;

	unsigned int linePathmonDlckAlarm = 0;

	unsigned int linePathmonDlck = 0;
	linePathmonDlck = pt_monitor_struct->tp_defects_struct.tp_line_path_mon.fields.dlck;

	unsigned int linePathmonDlckAlarmSev = 0;
	linePathmonDlckAlarmSev = pt_monitor_struct->tp_defects_struct.severity.severity_line.PathmonDlck;

	unsigned int send_linePathmonDlckAlarm = 0;
	if (linePathmonDlckTemp==0 && linePathmonDlck==1)
   {
		linePathmonDlckAlarm = 1;
		send_linePathmonDlckAlarm = 1;
   }
   else if (linePathmonDlckTemp==1 && linePathmonDlck==0)
   {
	   linePathmonDlckAlarm = 2;
      send_linePathmonDlckAlarm = 1;
   }
	linePathmonDlckTemp = linePathmonDlck;

	snmp_varlist_add_variable(&notification_vars, objid_snmptrap, objid_snmptrap_len, ASN_OBJECT_ID, (u_char *) notification_oid, notification_oid_len * sizeof(oid));
	snmp_varlist_add_variable(&notification_vars, linePathmonDlck_oid, linePathmonDlck_oid_len, ASN_INTEGER, (u_char *)&linePathmonDlckAlarm, sizeof(linePathmonDlckAlarm));
	snmp_varlist_add_variable(&notification_vars, linePathmonDlckAlarmSev_oid, linePathmonDlckAlarmSev_oid_len, ASN_INTEGER, (u_char *)&linePathmonDlckAlarmSev, sizeof(linePathmonDlckAlarmSev));

	if(send_linePathmonDlckAlarm == 1)
	{
		++linePathmonDlckCount;
		DEBUGMSGTL(("ftnc_notifications", "sending trap %ld\n",linePathmonDlckCount));
		send_v2trap(notification_vars);
	}

	snmp_free_varbind(notification_vars);
}

void send_tp_linePathmonDbdi_notification(unsigned int clientreg, void *clientarg)
{
	DEBUGMSGTL(("token", "send_tplinePathmonDbdi_notification.\n"));

	oid notification_oid[] = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 2, 2, 0, 101 };
	size_t notification_oid_len = OID_LENGTH(notification_oid);
	oid objid_snmptrap[] = { 1, 3, 6, 1, 6, 3, 1, 1, 4, 1, 0 };
	size_t objid_snmptrap_len = OID_LENGTH(objid_snmptrap);
	oid linePathmonDbdi_oid[]   = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 2, 2, 1, 7, 1, 20 };
	size_t linePathmonDbdi_oid_len = OID_LENGTH(linePathmonDbdi_oid);
	oid      linePathmonDbdiAlarmSev_oid[]   = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 3, 6, 1, 1, 13 };
	size_t   linePathmonDbdiAlarmSev_oid_len = OID_LENGTH(linePathmonDbdiAlarmSev_oid);

	netsnmp_variable_list *notification_vars = NULL;
	static u_long linePathmonDbdiCount = 0;

	unsigned int linePathmonDbdiAlarm = 0;

	unsigned int linePathmonDbdi = 0;
	linePathmonDbdi = pt_monitor_struct->tp_defects_struct.tp_line_path_mon.fields.dbdi;

	unsigned int linePathmonDbdiAlarmSev = 0;
	linePathmonDbdiAlarmSev = pt_monitor_struct->tp_defects_struct.severity.severity_line.PathmonDbdi;

	unsigned int send_linePathmonDbdiAlarm = 0;
	if (linePathmonDbdiTemp==0 && linePathmonDbdi==1)
   {
		linePathmonDbdiAlarm = 1;
		send_linePathmonDbdiAlarm = 1;
   }
   else if (linePathmonDbdiTemp==1 && linePathmonDbdi==0)
   {
	   linePathmonDbdiAlarm = 2;
      send_linePathmonDbdiAlarm = 1;
   }
	linePathmonDbdiTemp = linePathmonDbdi;

	snmp_varlist_add_variable(&notification_vars, objid_snmptrap, objid_snmptrap_len, ASN_OBJECT_ID, (u_char *) notification_oid, notification_oid_len * sizeof(oid));
	snmp_varlist_add_variable(&notification_vars, linePathmonDbdi_oid, linePathmonDbdi_oid_len, ASN_INTEGER, (u_char *)&linePathmonDbdiAlarm, sizeof(linePathmonDbdiAlarm));
	snmp_varlist_add_variable(&notification_vars, linePathmonDbdiAlarmSev_oid, linePathmonDbdiAlarmSev_oid_len, ASN_INTEGER, (u_char *)&linePathmonDbdiAlarmSev, sizeof(linePathmonDbdiAlarmSev));

	if(send_linePathmonDbdiAlarm == 1)
	{
		++linePathmonDbdiCount;
		DEBUGMSGTL(("ftnc_notifications", "sending trap %ld\n",linePathmonDbdiCount));
		send_v2trap(notification_vars);
	}

	snmp_free_varbind(notification_vars);
}

//Traffic Processor Client 1 Notifications
void send_tp_client1FramerFsmms_notification(unsigned int clientreg, void *clientarg)
{
	DEBUGMSGTL(("token", "send_tp_client1FramerFsmms_notification.\n"));

	oid notification_oid[] = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 2, 2, 0, 102 };
	size_t notification_oid_len = OID_LENGTH(notification_oid);
	oid objid_snmptrap[] = { 1, 3, 6, 1, 6, 3, 1, 1, 4, 1, 0 };
	size_t objid_snmptrap_len = OID_LENGTH(objid_snmptrap);
	oid client1FramerFsmms_oid[]   = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 2, 2, 1, 7, 1, 21 };
	size_t client1FramerFsmms_oid_len = OID_LENGTH(client1FramerFsmms_oid);
	oid      client1FramerFsmmsAlarmSev_oid[]   = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 3, 6, 2, 1, 2 };
	size_t   client1FramerFsmmsAlarmSev_oid_len = OID_LENGTH(client1FramerFsmmsAlarmSev_oid);

	netsnmp_variable_list *notification_vars = NULL;
	static u_long client1FramerFsmmsCount = 0;

	unsigned int client1FramerFsmmsAlarm = 0;

	unsigned int client1FramerFsmms = 0;
	client1FramerFsmms = pt_monitor_struct->tp_defects_struct.tp_client_framer_status[0].fields.fsmms;

	unsigned int client1FramerFsmmsAlarmSev = 0;
	client1FramerFsmmsAlarmSev = pt_monitor_struct->tp_defects_struct.severity.severity_client[0].FramerFsmms;

	unsigned int send_client1FramerFsmmsAlarm = 0;
	if (client1FramerFsmmsTemp==0 && client1FramerFsmms==1)
   {
		client1FramerFsmmsAlarm = 1;
		send_client1FramerFsmmsAlarm = 1;
   }
   else if (client1FramerFsmmsTemp==1 && client1FramerFsmms==0)
   {
	   client1FramerFsmmsAlarm = 2;
      send_client1FramerFsmmsAlarm = 1;
   }
	client1FramerFsmmsTemp = client1FramerFsmms;

	snmp_varlist_add_variable(&notification_vars, objid_snmptrap, objid_snmptrap_len, ASN_OBJECT_ID, (u_char *) notification_oid, notification_oid_len * sizeof(oid));
	snmp_varlist_add_variable(&notification_vars, client1FramerFsmms_oid, client1FramerFsmms_oid_len, ASN_INTEGER, (u_char *)&client1FramerFsmmsAlarm, sizeof(client1FramerFsmmsAlarm));
	snmp_varlist_add_variable(&notification_vars, client1FramerFsmmsAlarmSev_oid, client1FramerFsmmsAlarmSev_oid_len, ASN_INTEGER, (u_char *)&client1FramerFsmmsAlarmSev, sizeof(client1FramerFsmmsAlarmSev));

	if(send_client1FramerFsmmsAlarm == 1)
	{
		++client1FramerFsmmsCount;
		DEBUGMSGTL(("ftnc_notifications", "sending trap %ld\n",client1FramerFsmmsCount));
		send_v2trap(notification_vars);
	}

	snmp_free_varbind(notification_vars);
}

void send_tp_client1FramerFssusts_notification(unsigned int clientreg, void *clientarg)
{
	DEBUGMSGTL(("token", "send_tp_client1FramerFssusts_notification.\n"));

	oid notification_oid[] = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 2, 2, 0, 103 };
	size_t notification_oid_len = OID_LENGTH(notification_oid);
	oid objid_snmptrap[] = { 1, 3, 6, 1, 6, 3, 1, 1, 4, 1, 0 };
	size_t objid_snmptrap_len = OID_LENGTH(objid_snmptrap);
	oid client1FramerFssusts_oid[]   = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 2, 2, 1, 7, 1, 22 };
	size_t client1FramerFssusts_oid_len = OID_LENGTH(client1FramerFssusts_oid);
	oid      client1FramerFssustsAlarmSev_oid[]   = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 3, 6, 2, 1, 3 };
	size_t   client1FramerFssustsAlarmSev_oid_len = OID_LENGTH(client1FramerFssustsAlarmSev_oid);

	netsnmp_variable_list *notification_vars = NULL;
	static u_long client1FramerFssustsCount = 0;

	unsigned int client1FramerFssustsAlarm = 0;

	unsigned int client1FramerFssusts = 0;
	client1FramerFssusts = pt_monitor_struct->tp_defects_struct.tp_client_framer_status[0].fields.fsusts;

	unsigned int client1FramerFssustsAlarmSev = 0;
	client1FramerFssustsAlarmSev = pt_monitor_struct->tp_defects_struct.severity.severity_client[0].FramerFssusts;

	unsigned int send_client1FramerFssustsAlarm = 0;
	if (client1FramerFssustsTemp==0 && client1FramerFssusts==1)
   {
		client1FramerFssustsAlarm = 1;
		send_client1FramerFssustsAlarm = 1;
   }
   else if (client1FramerFssustsTemp==1 && client1FramerFssusts==0)
   {
	   client1FramerFssustsAlarm = 2;
      send_client1FramerFssustsAlarm = 1;
   }
	client1FramerFssustsTemp = client1FramerFssusts;

	snmp_varlist_add_variable(&notification_vars, objid_snmptrap, objid_snmptrap_len, ASN_OBJECT_ID, (u_char *) notification_oid, notification_oid_len * sizeof(oid));
	snmp_varlist_add_variable(&notification_vars, client1FramerFssusts_oid, client1FramerFssusts_oid_len, ASN_INTEGER, (u_char *)&client1FramerFssustsAlarm, sizeof(client1FramerFssustsAlarm));
	snmp_varlist_add_variable(&notification_vars, client1FramerFssustsAlarmSev_oid, client1FramerFssustsAlarmSev_oid_len, ASN_INTEGER, (u_char *)&client1FramerFssustsAlarmSev, sizeof(client1FramerFssustsAlarmSev));

	if(send_client1FramerFssustsAlarm == 1)
	{
		++client1FramerFssustsCount;
		DEBUGMSGTL(("ftnc_notifications", "sending trap %ld\n",client1FramerFssustsCount));
		send_v2trap(notification_vars);
	}

	snmp_free_varbind(notification_vars);
}

void send_tp_client1FramerSif_notification(unsigned int clientreg, void *clientarg)
{
	DEBUGMSGTL(("token", "send_tp_client1FramerSif_notification.\n"));

	oid notification_oid[] = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 2, 2, 0, 104 };
	size_t notification_oid_len = OID_LENGTH(notification_oid);
	oid objid_snmptrap[] = { 1, 3, 6, 1, 6, 3, 1, 1, 4, 1, 0 };
	size_t objid_snmptrap_len = OID_LENGTH(objid_snmptrap);
	oid client1FramerSif_oid[]   = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 2, 2, 1, 7, 1, 23 };
	size_t client1FramerSif_oid_len = OID_LENGTH(client1FramerSif_oid);
	oid      client1FramerSifAlarmSev_oid[]   = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 3, 6, 2, 1, 6 };
	size_t   client1FramerSifAlarmSev_oid_len = OID_LENGTH(client1FramerSifAlarmSev_oid);

	netsnmp_variable_list *notification_vars = NULL;
	static u_long client1FramerSifCount = 0;

	unsigned int client1FramerSifAlarm = 0;

	unsigned int client1FramerSif = 0;
	client1FramerSif = pt_monitor_struct->tp_defects_struct.tp_client_framer_status[0].fields.sif;

	unsigned int client1FramerSifAlarmSev = 0;
	client1FramerSifAlarmSev = pt_monitor_struct->tp_defects_struct.severity.severity_client[0].FramerSif;

	unsigned int send_client1FramerSifAlarm = 0;
	if (client1FramerSifTemp==0 && client1FramerSif==1)
   {
		client1FramerSifAlarm = 1;
		send_client1FramerSifAlarm = 1;
   }
   else if (client1FramerSifTemp==1 && client1FramerSif==0)
   {
	   client1FramerSifAlarm = 2;
      send_client1FramerSifAlarm = 1;
   }
	client1FramerSifTemp = client1FramerSif;

	snmp_varlist_add_variable(&notification_vars, objid_snmptrap, objid_snmptrap_len, ASN_OBJECT_ID, (u_char *) notification_oid, notification_oid_len * sizeof(oid));
	snmp_varlist_add_variable(&notification_vars, client1FramerSif_oid, client1FramerSif_oid_len, ASN_INTEGER, (u_char *)&client1FramerSifAlarm, sizeof(client1FramerSifAlarm));
	snmp_varlist_add_variable(&notification_vars, client1FramerSifAlarmSev_oid, client1FramerSifAlarmSev_oid_len, ASN_INTEGER, (u_char *)&client1FramerSifAlarmSev, sizeof(client1FramerSifAlarmSev));

	if(send_client1FramerSifAlarm == 1)
	{
		++client1FramerSifCount;
		DEBUGMSGTL(("ftnc_notifications", "sending trap %ld\n",client1FramerSifCount));
		send_v2trap(notification_vars);
	}

	snmp_free_varbind(notification_vars);
}

void send_tp_client1FramerSoof_notification(unsigned int clientreg, void *clientarg)
{
	DEBUGMSGTL(("token", "send_tp_client1FramerSoof_notification.\n"));

	oid notification_oid[] = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 2, 2, 0, 105 };
	size_t notification_oid_len = OID_LENGTH(notification_oid);
	oid objid_snmptrap[] = { 1, 3, 6, 1, 6, 3, 1, 1, 4, 1, 0 };
	size_t objid_snmptrap_len = OID_LENGTH(objid_snmptrap);
	oid client1FramerSoof_oid[]   = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 2, 2, 1, 7, 1, 24 };
	size_t client1FramerSoof_oid_len = OID_LENGTH(client1FramerSoof_oid);
	oid      client1FramerSoofAlarmSev_oid[]   = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 3, 6, 2, 1, 4 };
	size_t   client1FramerSoofAlarmSev_oid_len = OID_LENGTH(client1FramerSoofAlarmSev_oid);

	netsnmp_variable_list *notification_vars = NULL;
	static u_long client1FramerSoofCount = 0;

	unsigned int client1FramerSoofAlarm = 0;

	unsigned int client1FramerSoof = 0;
	client1FramerSoof = pt_monitor_struct->tp_defects_struct.tp_client_framer_status[0].fields.soof;

	unsigned int client1FramerSoofAlarmSev = 0;
	client1FramerSoofAlarmSev = pt_monitor_struct->tp_defects_struct.severity.severity_client[0].FramerSoof;

	unsigned int send_client1FramerSoofAlarm = 0;
	if (client1FramerSoofTemp==0 && client1FramerSoof==1)
   {
		client1FramerSoofAlarm = 1;
		send_client1FramerSoofAlarm = 1;
   }
   else if (client1FramerSoofTemp==1 && client1FramerSoof==0)
   {
	   client1FramerSoofAlarm = 2;
      send_client1FramerSoofAlarm = 1;
   }
	client1FramerSoofTemp = client1FramerSoof;

	snmp_varlist_add_variable(&notification_vars, objid_snmptrap, objid_snmptrap_len, ASN_OBJECT_ID, (u_char *) notification_oid, notification_oid_len * sizeof(oid));
	snmp_varlist_add_variable(&notification_vars, client1FramerSoof_oid, client1FramerSoof_oid_len, ASN_INTEGER, (u_char *)&client1FramerSoofAlarm, sizeof(client1FramerSoofAlarm));
	snmp_varlist_add_variable(&notification_vars, client1FramerSoofAlarmSev_oid, client1FramerSoofAlarmSev_oid_len, ASN_INTEGER, (u_char *)&client1FramerSoofAlarmSev, sizeof(client1FramerSoofAlarmSev));

	if(send_client1FramerSoofAlarm == 1)
	{
		++client1FramerSoofCount;
		DEBUGMSGTL(("ftnc_notifications", "sending trap %ld\n",client1FramerSoofCount));
		send_v2trap(notification_vars);
	}

	snmp_free_varbind(notification_vars);
}

void send_tp_client1FramerSlof_notification(unsigned int clientreg, void *clientarg)
{
	DEBUGMSGTL(("token", "send_tp_client1FramerSlof_notification.\n"));

	oid notification_oid[] = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 2, 2, 0, 106 };
	size_t notification_oid_len = OID_LENGTH(notification_oid);
	oid objid_snmptrap[] = { 1, 3, 6, 1, 6, 3, 1, 1, 4, 1, 0 };
	size_t objid_snmptrap_len = OID_LENGTH(objid_snmptrap);
	oid client1FramerSlof_oid[]   = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 2, 2, 1, 7, 1, 25 };
	size_t client1FramerSlof_oid_len = OID_LENGTH(client1FramerSlof_oid);
	oid      client1FramerSlofAlarmSev_oid[]   = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 3, 6, 2, 1, 5 };
	size_t   client1FramerSlofAlarmSev_oid_len = OID_LENGTH(client1FramerSlofAlarmSev_oid);

	netsnmp_variable_list *notification_vars = NULL;
	static u_long client1FramerSlofCount = 0;

	unsigned int client1FramerSlofAlarm = 0;

	unsigned int client1FramerSlof = 0;
	client1FramerSlof = pt_monitor_struct->tp_defects_struct.tp_client_framer_status[0].fields.slof;

	unsigned int client1FramerSlofAlarmSev = 0;
	client1FramerSlofAlarmSev = pt_monitor_struct->tp_defects_struct.severity.severity_client[0].FramerSlof;

	unsigned int send_client1FramerSlofAlarm = 0;
	if (client1FramerSlofTemp==0 && client1FramerSlof==1)
   {
		client1FramerSlofAlarm = 1;
		send_client1FramerSlofAlarm = 1;
   }
   else if (client1FramerSlofTemp==1 && client1FramerSlof==0)
   {
	   client1FramerSlofAlarm = 2;
      send_client1FramerSlofAlarm = 1;
   }
	client1FramerSlofTemp = client1FramerSlof;

	snmp_varlist_add_variable(&notification_vars, objid_snmptrap, objid_snmptrap_len, ASN_OBJECT_ID, (u_char *) notification_oid, notification_oid_len * sizeof(oid));
	snmp_varlist_add_variable(&notification_vars, client1FramerSlof_oid, client1FramerSlof_oid_len, ASN_INTEGER, (u_char *)&client1FramerSlofAlarm, sizeof(client1FramerSlofAlarm));
	snmp_varlist_add_variable(&notification_vars, client1FramerSlofAlarmSev_oid, client1FramerSlofAlarmSev_oid_len, ASN_INTEGER, (u_char *)&client1FramerSlofAlarmSev, sizeof(client1FramerSlofAlarmSev));

	if(send_client1FramerSlofAlarm == 1)
	{
		++client1FramerSlofCount;
		DEBUGMSGTL(("ftnc_notifications", "sending trap %ld\n",client1FramerSlofCount));
		send_v2trap(notification_vars);
	}

	snmp_free_varbind(notification_vars);
}

void send_tp_client1FramerFst_notification(unsigned int clientreg, void *clientarg)
{
	DEBUGMSGTL(("token", "send_tp_client1FramerFst_notification.\n"));

	oid notification_oid[] = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 2, 2, 0, 107 };
	size_t notification_oid_len = OID_LENGTH(notification_oid);
	oid objid_snmptrap[] = { 1, 3, 6, 1, 6, 3, 1, 1, 4, 1, 0 };
	size_t objid_snmptrap_len = OID_LENGTH(objid_snmptrap);
	oid client1FramerFst_oid[]   = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 2, 2, 1, 7, 1, 26 };
	size_t client1FramerFst_oid_len = OID_LENGTH(client1FramerFst_oid);
	oid      client1FramerFstAlarmSev_oid[]   = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 3, 6, 2, 1, 7 };
	size_t   client1FramerFstAlarmSev_oid_len = OID_LENGTH(client1FramerFstAlarmSev_oid);

	netsnmp_variable_list *notification_vars = NULL;
	static u_long client1FramerFstCount = 0;

	unsigned int client1FramerFstAlarm = 0;

	unsigned int client1FramerFst = 0;
	client1FramerFst = pt_monitor_struct->tp_defects_struct.tp_client_framer_status[0].fields.fst;

	unsigned int client1FramerFstAlarmSev = 0;
	client1FramerFstAlarmSev = pt_monitor_struct->tp_defects_struct.severity.severity_client[0].FramerFst;

	unsigned int send_client1FramerFstAlarm = 0;
	if (client1FramerFstTemp==0 && client1FramerFst==1)
   {
		client1FramerFstAlarm = 1;
		send_client1FramerFstAlarm = 1;
   }
   else if (client1FramerFstTemp==1 && client1FramerFst==0)
   {
	   client1FramerFstAlarm = 2;
      send_client1FramerFstAlarm = 1;
   }
	client1FramerFstTemp = client1FramerFst;

	snmp_varlist_add_variable(&notification_vars, objid_snmptrap, objid_snmptrap_len, ASN_OBJECT_ID, (u_char *) notification_oid, notification_oid_len * sizeof(oid));
	snmp_varlist_add_variable(&notification_vars, client1FramerFst_oid, client1FramerFst_oid_len, ASN_INTEGER, (u_char *)&client1FramerFstAlarm, sizeof(client1FramerFstAlarm));
	snmp_varlist_add_variable(&notification_vars, client1FramerFstAlarmSev_oid, client1FramerFstAlarmSev_oid_len, ASN_INTEGER, (u_char *)&client1FramerFstAlarmSev, sizeof(client1FramerFstAlarmSev));

	if(send_client1FramerFstAlarm == 1)
	{
		++client1FramerFstCount;
		DEBUGMSGTL(("ftnc_notifications", "sending trap %ld\n",client1FramerFstCount));
		send_v2trap(notification_vars);
	}

	snmp_free_varbind(notification_vars);
}

void send_tp_client1LosstatLosf_notification(unsigned int clientreg, void *clientarg)
{
	DEBUGMSGTL(("token", "send_tp_client1LosstatLosf_notification.\n"));

	oid notification_oid[] = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 2, 2, 0, 108 };
	size_t notification_oid_len = OID_LENGTH(notification_oid);
	oid objid_snmptrap[] = { 1, 3, 6, 1, 6, 3, 1, 1, 4, 1, 0 };
	size_t objid_snmptrap_len = OID_LENGTH(objid_snmptrap);
	oid client1LosstatLosf_oid[]   = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 2, 2, 1, 7, 1, 27 };
	size_t client1LosstatLosf_oid_len = OID_LENGTH(client1LosstatLosf_oid);
	oid      client1LosstatLosfAlarmSev_oid[]   = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 3, 6, 2, 1, 8 };
	size_t   client1LosstatLosfAlarmSev_oid_len = OID_LENGTH(client1LosstatLosfAlarmSev_oid);

	netsnmp_variable_list *notification_vars = NULL;
	static u_long client1LosstatLosfCount = 0;

	unsigned int client1LosstatLosfAlarm = 0;

	unsigned int client1LosstatLosf = 0;
	client1LosstatLosf = pt_monitor_struct->tp_defects_struct.tp_client_los_status[0].fields.losf;

	unsigned int client1LosstatLosfAlarmSev = 0;
	client1LosstatLosfAlarmSev = pt_monitor_struct->tp_defects_struct.severity.severity_client[0].LosstatLosf;

	unsigned int send_client1LosstatLosfAlarm = 0;
	if (client1LosstatLosfTemp==0 && client1LosstatLosf==1)
   {
		client1LosstatLosfAlarm = 1;
		send_client1LosstatLosfAlarm = 1;
   }
   else if (client1LosstatLosfTemp==1 && client1LosstatLosf==0)
   {
	   client1LosstatLosfAlarm = 2;
      send_client1LosstatLosfAlarm = 1;
   }
	client1LosstatLosfTemp = client1LosstatLosf;

	snmp_varlist_add_variable(&notification_vars, objid_snmptrap, objid_snmptrap_len, ASN_OBJECT_ID, (u_char *) notification_oid, notification_oid_len * sizeof(oid));
	snmp_varlist_add_variable(&notification_vars, client1LosstatLosf_oid, client1LosstatLosf_oid_len, ASN_INTEGER, (u_char *)&client1LosstatLosfAlarm, sizeof(client1LosstatLosfAlarm));
	snmp_varlist_add_variable(&notification_vars, client1LosstatLosfAlarmSev_oid, client1LosstatLosfAlarmSev_oid_len, ASN_INTEGER, (u_char *)&client1LosstatLosfAlarmSev, sizeof(client1LosstatLosfAlarmSev));

	if(send_client1LosstatLosfAlarm == 1)
	{
		++client1LosstatLosfCount;
		DEBUGMSGTL(("ftnc_notifications", "sending trap %ld\n",client1LosstatLosfCount));
		send_v2trap(notification_vars);
	}

	snmp_free_varbind(notification_vars);
}

void send_tp_client1SecmonFlom_notification(unsigned int clientreg, void *clientarg)
{
	DEBUGMSGTL(("token", "send_tp_client1SecmonFlom_notification.\n"));

	oid notification_oid[] = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 2, 2, 0, 109 };
	size_t notification_oid_len = OID_LENGTH(notification_oid);
	oid objid_snmptrap[] = { 1, 3, 6, 1, 6, 3, 1, 1, 4, 1, 0 };
	size_t objid_snmptrap_len = OID_LENGTH(objid_snmptrap);
	oid client1SecmonFlom_oid[]   = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 2, 2, 1, 7, 1, 28 };
	size_t client1SecmonFlom_oid_len = OID_LENGTH(client1SecmonFlom_oid);
	oid      client1SecmonFlomAlarmSev_oid[]   = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 3, 6, 2, 1, 17 };
	size_t   client1SecmonFlomAlarmSev_oid_len = OID_LENGTH(client1SecmonFlomAlarmSev_oid);

	netsnmp_variable_list *notification_vars = NULL;
	static u_long client1SecmonFlomCount = 0;

	unsigned int client1SecmonFlomAlarm = 0;

	unsigned int client1SecmonFlom = 0;
	client1SecmonFlom = pt_monitor_struct->tp_defects_struct.tp_client_section_mon[0].fields.flom;

	unsigned int client1SecmonFlomAlarmSev = 0;
	client1SecmonFlomAlarmSev = pt_monitor_struct->tp_defects_struct.severity.severity_client[0].SecmonFlom;

	unsigned int send_client1SecmonFlomAlarm = 0;
	if (client1SecmonFlomTemp==0 && client1SecmonFlom==1)
   {
		client1SecmonFlomAlarm = 1;
		send_client1SecmonFlomAlarm = 1;
   }
   else if (client1SecmonFlomTemp==1 && client1SecmonFlom==0)
   {
	   client1SecmonFlomAlarm = 2;
      send_client1SecmonFlomAlarm = 1;
   }
	client1SecmonFlomTemp = client1SecmonFlom;

	snmp_varlist_add_variable(&notification_vars, objid_snmptrap, objid_snmptrap_len, ASN_OBJECT_ID, (u_char *) notification_oid, notification_oid_len * sizeof(oid));
	snmp_varlist_add_variable(&notification_vars, client1SecmonFlom_oid, client1SecmonFlom_oid_len, ASN_INTEGER, (u_char *)&client1SecmonFlomAlarm, sizeof(client1SecmonFlomAlarm));
	snmp_varlist_add_variable(&notification_vars, client1SecmonFlomAlarmSev_oid, client1SecmonFlomAlarmSev_oid_len, ASN_INTEGER, (u_char *)&client1SecmonFlomAlarmSev, sizeof(client1SecmonFlomAlarmSev));

	if(send_client1SecmonFlomAlarm == 1)
	{
		++client1SecmonFlomCount;
		DEBUGMSGTL(("ftnc_notifications", "sending trap %ld\n",client1SecmonFlomCount));
		send_v2trap(notification_vars);
	}

	snmp_free_varbind(notification_vars);
}

void send_tp_client1SecmonBipsfs_notification(unsigned int clientreg, void *clientarg)
{
	DEBUGMSGTL(("token", "send_tp_client1SecmonBipsfs_notification.\n"));

	oid notification_oid[] = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 2, 2, 0, 110 };
	size_t notification_oid_len = OID_LENGTH(notification_oid);
	oid objid_snmptrap[] = { 1, 3, 6, 1, 6, 3, 1, 1, 4, 1, 0 };
	size_t objid_snmptrap_len = OID_LENGTH(objid_snmptrap);
	oid client1SecmonBipsfs_oid[]   = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 2, 2, 1, 7, 1, 29 };
	size_t client1SecmonBipsfs_oid_len = OID_LENGTH(client1SecmonBipsfs_oid);
	oid      client1SecmonBipsfsAlarmSev_oid[]   = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 3, 6, 2, 1, 14 };
	size_t   client1SecmonBipsfsAlarmSev_oid_len = OID_LENGTH(client1SecmonBipsfsAlarmSev_oid);

	netsnmp_variable_list *notification_vars = NULL;
	static u_long client1SecmonBipsfsCount = 0;

	unsigned int client1SecmonBipsfsAlarm = 0;

	unsigned int client1SecmonBipsfs = 0;
	client1SecmonBipsfs = pt_monitor_struct->tp_defects_struct.tp_client_section_mon[0].fields.bipsfs;

	unsigned int client1SecmonBipsfsAlarmSev = 0;
	client1SecmonBipsfsAlarmSev = pt_monitor_struct->tp_defects_struct.severity.severity_client[0].SecmonBipsfs;

	unsigned int send_client1SecmonBipsfsAlarm = 0;
	if (client1SecmonBipsfsTemp==0 && client1SecmonBipsfs==1)
   {
		client1SecmonBipsfsAlarm = 1;
		send_client1SecmonBipsfsAlarm = 1;
   }
   else if (client1SecmonBipsfsTemp==1 && client1SecmonBipsfs==0)
   {
	   client1SecmonBipsfsAlarm = 2;
      send_client1SecmonBipsfsAlarm = 1;
   }
	client1SecmonBipsfsTemp = client1SecmonBipsfs;

	snmp_varlist_add_variable(&notification_vars, objid_snmptrap, objid_snmptrap_len, ASN_OBJECT_ID, (u_char *) notification_oid, notification_oid_len * sizeof(oid));
	snmp_varlist_add_variable(&notification_vars, client1SecmonBipsfs_oid, client1SecmonBipsfs_oid_len, ASN_INTEGER, (u_char *)&client1SecmonBipsfsAlarm, sizeof(client1SecmonBipsfsAlarm));
	snmp_varlist_add_variable(&notification_vars, client1SecmonBipsfsAlarmSev_oid, client1SecmonBipsfsAlarmSev_oid_len, ASN_INTEGER, (u_char *)&client1SecmonBipsfsAlarmSev, sizeof(client1SecmonBipsfsAlarmSev));

	if(send_client1SecmonBipsfsAlarm == 1)
	{
		++client1SecmonBipsfsCount;
		DEBUGMSGTL(("ftnc_notifications", "sending trap %ld\n",client1SecmonBipsfsCount));
		send_v2trap(notification_vars);
	}

	snmp_free_varbind(notification_vars);
}

void send_tp_client1SecmonDiae_notification(unsigned int clientreg, void *clientarg)
{
	DEBUGMSGTL(("token", "send_tp_client1SecmonDiae_notification.\n"));

	oid notification_oid[] = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 2, 2, 0, 111 };
	size_t notification_oid_len = OID_LENGTH(notification_oid);
	oid objid_snmptrap[] = { 1, 3, 6, 1, 6, 3, 1, 1, 4, 1, 0 };
	size_t objid_snmptrap_len = OID_LENGTH(objid_snmptrap);
	oid client1SecmonDiae_oid[]   = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 2, 2, 1, 7, 1, 30 };
	size_t client1SecmonDiae_oid_len = OID_LENGTH(client1SecmonDiae_oid);
	oid      client1SecmonDiaeAlarmSev_oid[]   = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 3, 6, 2, 1, 16 };
	size_t   client1SecmonDiaeAlarmSev_oid_len = OID_LENGTH(client1SecmonDiaeAlarmSev_oid);

	netsnmp_variable_list *notification_vars = NULL;
	static u_long client1SecmonDiaeCount = 0;

	unsigned int client1SecmonDiaeAlarm = 0;

	unsigned int client1SecmonDiae = 0;
	client1SecmonDiae = pt_monitor_struct->tp_defects_struct.tp_client_section_mon[0].fields.diae;

	unsigned int client1SecmonDiaeAlarmSev = 0;
	client1SecmonDiaeAlarmSev = pt_monitor_struct->tp_defects_struct.severity.severity_client[0].SecmonDiae;

	unsigned int send_client1SecmonDiaeAlarm = 0;
	if (client1SecmonDiaeTemp==0 && client1SecmonDiae==1)
   {
		client1SecmonDiaeAlarm = 1;
		send_client1SecmonDiaeAlarm = 1;
   }
   else if (client1SecmonDiaeTemp==1 && client1SecmonDiae==0)
   {
	   client1SecmonDiaeAlarm = 2;
      send_client1SecmonDiaeAlarm = 1;
   }
	client1SecmonDiaeTemp = client1SecmonDiae;

	snmp_varlist_add_variable(&notification_vars, objid_snmptrap, objid_snmptrap_len, ASN_OBJECT_ID, (u_char *) notification_oid, notification_oid_len * sizeof(oid));
	snmp_varlist_add_variable(&notification_vars, client1SecmonDiae_oid, client1SecmonDiae_oid_len, ASN_INTEGER, (u_char *)&client1SecmonDiaeAlarm, sizeof(client1SecmonDiaeAlarm));
	snmp_varlist_add_variable(&notification_vars, client1SecmonDiaeAlarmSev_oid, client1SecmonDiaeAlarmSev_oid_len, ASN_INTEGER, (u_char *)&client1SecmonDiaeAlarmSev, sizeof(client1SecmonDiaeAlarmSev));

	if(send_client1SecmonDiaeAlarm == 1)
	{
		++client1SecmonDiaeCount;
		DEBUGMSGTL(("ftnc_notifications", "sending trap %ld\n",client1SecmonDiaeCount));
		send_v2trap(notification_vars);
	}

	snmp_free_varbind(notification_vars);
}

void send_tp_client1SecmonDbdi_notification(unsigned int clientreg, void *clientarg)
{
	DEBUGMSGTL(("token", "send_tp_client1SecmonDbdi_notification.\n"));

	oid notification_oid[] = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 2, 2, 0, 112 };
	size_t notification_oid_len = OID_LENGTH(notification_oid);
	oid objid_snmptrap[] = { 1, 3, 6, 1, 6, 3, 1, 1, 4, 1, 0 };
	size_t objid_snmptrap_len = OID_LENGTH(objid_snmptrap);
	oid client1SecmonDbdi_oid[]   = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 2, 2, 1, 7, 1, 31 };
	size_t client1SecmonDbdi_oid_len = OID_LENGTH(client1SecmonDbdi_oid);
	oid      client1SecmonDbdiAlarmSev_oid[]   = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 3, 6, 2, 1, 15 };
	size_t   client1SecmonDbdiAlarmSev_oid_len = OID_LENGTH(client1SecmonDbdiAlarmSev_oid);

	netsnmp_variable_list *notification_vars = NULL;
	static u_long client1SecmonDbdiCount = 0;

	unsigned int client1SecmonDbdiAlarm = 0;

	unsigned int client1SecmonDbdi = 0;
	client1SecmonDbdi = pt_monitor_struct->tp_defects_struct.tp_client_section_mon[0].fields.dbdi;

	unsigned int client1SecmonDbdiAlarmSev = 0;
	client1SecmonDbdiAlarmSev = pt_monitor_struct->tp_defects_struct.severity.severity_client[0].SecmonDbdi;

	unsigned int send_client1SecmonDbdiAlarm = 0;
	if (client1SecmonDbdiTemp==0 && client1SecmonDbdi==1)
   {
		client1SecmonDbdiAlarm = 1;
		send_client1SecmonDbdiAlarm = 1;
   }
   else if (client1SecmonDbdiTemp==1 && client1SecmonDbdi==0)
   {
	   client1SecmonDbdiAlarm = 2;
      send_client1SecmonDbdiAlarm = 1;
   }
	client1SecmonDbdiTemp = client1SecmonDbdi;

	snmp_varlist_add_variable(&notification_vars, objid_snmptrap, objid_snmptrap_len, ASN_OBJECT_ID, (u_char *) notification_oid, notification_oid_len * sizeof(oid));
	snmp_varlist_add_variable(&notification_vars, client1SecmonDbdi_oid, client1SecmonDbdi_oid_len, ASN_INTEGER, (u_char *)&client1SecmonDbdiAlarm, sizeof(client1SecmonDbdiAlarm));
	snmp_varlist_add_variable(&notification_vars, client1SecmonDbdiAlarmSev_oid, client1SecmonDbdiAlarmSev_oid_len, ASN_INTEGER, (u_char *)&client1SecmonDbdiAlarmSev, sizeof(client1SecmonDbdiAlarmSev));

	if(send_client1SecmonDbdiAlarm == 1)
	{
		++client1SecmonDbdiCount;
		DEBUGMSGTL(("ftnc_notifications", "sending trap %ld\n",client1SecmonDbdiCount));
		send_v2trap(notification_vars);
	}

	snmp_free_varbind(notification_vars);
}

void send_tp_client1SecmonLom_notification(unsigned int clientreg, void *clientarg)
{
	DEBUGMSGTL(("token", "send_tp_client1SecmonLom_notification.\n"));

	oid notification_oid[] = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 2, 2, 0, 113 };
	size_t notification_oid_len = OID_LENGTH(notification_oid);
	oid objid_snmptrap[] = { 1, 3, 6, 1, 6, 3, 1, 1, 4, 1, 0 };
	size_t objid_snmptrap_len = OID_LENGTH(objid_snmptrap);
	oid client1SecmonLom_oid[]   = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 2, 2, 1, 7, 1, 32 };
	size_t client1SecmonLom_oid_len = OID_LENGTH(client1SecmonLom_oid);
	oid      client1SecmonLomAlarmSev_oid[]   = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 3, 6, 2, 1, 18 };
	size_t   client1SecmonLomAlarmSev_oid_len = OID_LENGTH(client1SecmonLomAlarmSev_oid);

	netsnmp_variable_list *notification_vars = NULL;
	static u_long client1SecmonLomCount = 0;

	unsigned int client1SecmonLomAlarm = 0;

	unsigned int client1SecmonLom = 0;
	client1SecmonLom = pt_monitor_struct->tp_defects_struct.tp_client_section_mon[0].fields.lom;

	unsigned int client1SecmonLomAlarmSev = 0;
	client1SecmonLomAlarmSev = pt_monitor_struct->tp_defects_struct.severity.severity_client[0].SecmonLom;

	unsigned int send_client1SecmonLomAlarm = 0;
	if (client1SecmonLomTemp==0 && client1SecmonLom==1)
   {
		client1SecmonLomAlarm = 1;
		send_client1SecmonLomAlarm = 1;
   }
   else if (client1SecmonLomTemp==1 && client1SecmonLom==0)
   {
	   client1SecmonLomAlarm = 2;
      send_client1SecmonLomAlarm = 1;
   }
	client1SecmonLomTemp = client1SecmonLom;

	snmp_varlist_add_variable(&notification_vars, objid_snmptrap, objid_snmptrap_len, ASN_OBJECT_ID, (u_char *) notification_oid, notification_oid_len * sizeof(oid));
	snmp_varlist_add_variable(&notification_vars, client1SecmonLom_oid, client1SecmonLom_oid_len, ASN_INTEGER, (u_char *)&client1SecmonLomAlarm, sizeof(client1SecmonLomAlarm));
	snmp_varlist_add_variable(&notification_vars, client1SecmonLomAlarmSev_oid, client1SecmonLomAlarmSev_oid_len, ASN_INTEGER, (u_char *)&client1SecmonLomAlarmSev, sizeof(client1SecmonLomAlarmSev));

	if(send_client1SecmonLomAlarm == 1)
	{
		++client1SecmonLomCount;
		DEBUGMSGTL(("ftnc_notifications", "sending trap %ld\n",client1SecmonLomCount));
		send_v2trap(notification_vars);
	}

	snmp_free_varbind(notification_vars);
}

void send_tp_client1PathmonAccstat_notification(unsigned int clientreg, void *clientarg)
{
	DEBUGMSGTL(("token", "send_tp_client1PathmonAccstat_notification.\n"));

	oid notification_oid[] = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 2, 2, 0, 114 };
	size_t notification_oid_len = OID_LENGTH(notification_oid);
	oid objid_snmptrap[] = { 1, 3, 6, 1, 6, 3, 1, 1, 4, 1, 0 };
	size_t objid_snmptrap_len = OID_LENGTH(objid_snmptrap);
	oid client1PathmonAccstat_oid[]   = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 2, 2, 1, 7, 1, 33 };
	size_t client1PathmonAccstat_oid_len = OID_LENGTH(client1PathmonAccstat_oid);
	oid      client1PathmonAccstatAlarmSev_oid[]   = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 3, 6, 2, 1, 9 };
	size_t   client1PathmonAccstatAlarmSev_oid_len = OID_LENGTH(client1PathmonAccstatAlarmSev_oid);

	netsnmp_variable_list *notification_vars = NULL;
	static u_long client1PathmonAccstatCount = 0;

	unsigned int client1PathmonAccstatAlarm = 0;

	unsigned int client1PathmonAccstat = 0;
	client1PathmonAccstat = pt_monitor_struct->tp_defects_struct.tp_client_path_mon[0].fields.accstat;

	unsigned int client1PathmonAccstatAlarmSev = 0;
	client1PathmonAccstatAlarmSev = pt_monitor_struct->tp_defects_struct.severity.severity_client[0].PathmonAccstat;

	unsigned int send_client1PathmonAccstatAlarm = 0;
	if (client1PathmonAccstatTemp==0 && client1PathmonAccstat==1)
   {
		client1PathmonAccstatAlarm = 1;
		send_client1PathmonAccstatAlarm = 1;
   }
   else if (client1PathmonAccstatTemp==1 && client1PathmonAccstat==0)
   {
	   client1PathmonAccstatAlarm = 2;
      send_client1PathmonAccstatAlarm = 1;
   }
	client1PathmonAccstatTemp = client1PathmonAccstat;

	snmp_varlist_add_variable(&notification_vars, objid_snmptrap, objid_snmptrap_len, ASN_OBJECT_ID, (u_char *) notification_oid, notification_oid_len * sizeof(oid));
	snmp_varlist_add_variable(&notification_vars, client1PathmonAccstat_oid, client1PathmonAccstat_oid_len, ASN_INTEGER, (u_char *)&client1PathmonAccstatAlarm, sizeof(client1PathmonAccstatAlarm));
	snmp_varlist_add_variable(&notification_vars, client1PathmonAccstatAlarmSev_oid, client1PathmonAccstatAlarmSev_oid_len, ASN_INTEGER, (u_char *)&client1PathmonAccstatAlarmSev, sizeof(client1PathmonAccstatAlarmSev));

	if(send_client1PathmonAccstatAlarm == 1)
	{
		++client1PathmonAccstatCount;
		DEBUGMSGTL(("ftnc_notifications", "sending trap %ld\n",client1PathmonAccstatCount));
		send_v2trap(notification_vars);
	}

	snmp_free_varbind(notification_vars);
}

void send_tp_client1PathmonMsiunst_notification(unsigned int clientreg, void *clientarg)
{
	DEBUGMSGTL(("token", "send_tp_client1PathmonMsiunst_notification.\n"));

	oid notification_oid[] = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 2, 2, 0, 115 };
	size_t notification_oid_len = OID_LENGTH(notification_oid);
	oid objid_snmptrap[] = { 1, 3, 6, 1, 6, 3, 1, 1, 4, 1, 0 };
	size_t objid_snmptrap_len = OID_LENGTH(objid_snmptrap);
	oid client1PathmonMsiunst_oid[]   = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 2, 2, 1, 7, 1, 34 };
	size_t client1PathmonMsiunst_oid_len = OID_LENGTH(client1PathmonMsiunst_oid);
	oid      client1PathmonMsiunstAlarmSev_oid[]   = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 3, 6, 2, 1, 13 };
	size_t   client1PathmonMsiunstAlarmSev_oid_len = OID_LENGTH(client1PathmonMsiunstAlarmSev_oid);

	netsnmp_variable_list *notification_vars = NULL;
	static u_long client1PathmonMsiunstCount = 0;

	unsigned int client1PathmonMsiunstAlarm = 0;

	unsigned int client1PathmonMsiunst = 0;
	client1PathmonMsiunst = pt_monitor_struct->tp_defects_struct.tp_client_path_mon[0].fields.msiunst;

	unsigned int client1PathmonMsiunstAlarmSev = 0;
	client1PathmonMsiunstAlarmSev = pt_monitor_struct->tp_defects_struct.severity.severity_client[0].PathmonMsiunst;

	unsigned int send_client1PathmonMsiunstAlarm = 0;
	if (client1PathmonMsiunstTemp==0 && client1PathmonMsiunst==1)
   {
		client1PathmonMsiunstAlarm = 1;
		send_client1PathmonMsiunstAlarm = 1;
   }
   else if (client1PathmonMsiunstTemp==1 && client1PathmonMsiunst==0)
   {
	   client1PathmonMsiunstAlarm = 2;
      send_client1PathmonMsiunstAlarm = 1;
   }
	client1PathmonMsiunstTemp = client1PathmonMsiunst;

	snmp_varlist_add_variable(&notification_vars, objid_snmptrap, objid_snmptrap_len, ASN_OBJECT_ID, (u_char *) notification_oid, notification_oid_len * sizeof(oid));
	snmp_varlist_add_variable(&notification_vars, client1PathmonMsiunst_oid, client1PathmonMsiunst_oid_len, ASN_INTEGER, (u_char *)&client1PathmonMsiunstAlarm, sizeof(client1PathmonMsiunstAlarm));
	snmp_varlist_add_variable(&notification_vars, client1PathmonMsiunstAlarmSev_oid, client1PathmonMsiunstAlarmSev_oid_len, ASN_INTEGER, (u_char *)&client1PathmonMsiunstAlarmSev, sizeof(client1PathmonMsiunstAlarmSev));

	if(send_client1PathmonMsiunstAlarm == 1)
	{
		++client1PathmonMsiunstCount;
		DEBUGMSGTL(("ftnc_notifications", "sending trap %ld\n",client1PathmonMsiunstCount));
		send_v2trap(notification_vars);
	}

	snmp_free_varbind(notification_vars);
}

void send_tp_client1PathmonDais_notification(unsigned int clientreg, void *clientarg)
{
	DEBUGMSGTL(("token", "send_tp_client1PathmonDais_notification.\n"));

	oid notification_oid[] = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 2, 2, 0, 116 };
	size_t notification_oid_len = OID_LENGTH(notification_oid);
	oid objid_snmptrap[] = { 1, 3, 6, 1, 6, 3, 1, 1, 4, 1, 0 };
	size_t objid_snmptrap_len = OID_LENGTH(objid_snmptrap);
	oid client1PathmonDais_oid[]   = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 2, 2, 1, 7, 1, 35 };
	size_t client1PathmonDais_oid_len = OID_LENGTH(client1PathmonDais_oid);
	oid      client1PathmonDaisAlarmSev_oid[]   = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 3, 6, 2, 1, 10 };
	size_t   client1PathmonDaisAlarmSev_oid_len = OID_LENGTH(client1PathmonDaisAlarmSev_oid);

	netsnmp_variable_list *notification_vars = NULL;
	static u_long client1PathmonDaisCount = 0;

	unsigned int client1PathmonDaisAlarm = 0;

	unsigned int client1PathmonDais = 0;
	client1PathmonDais = pt_monitor_struct->tp_defects_struct.tp_client_path_mon[0].fields.dais;

	unsigned int client1PathmonDaisAlarmSev = 0;
	client1PathmonDaisAlarmSev = pt_monitor_struct->tp_defects_struct.severity.severity_client[0].PathmonDais;

	unsigned int send_client1PathmonDaisAlarm = 0;
	if (client1PathmonDaisTemp==0 && client1PathmonDais==1)
   {
		client1PathmonDaisAlarm = 1;
		send_client1PathmonDaisAlarm = 1;
   }
   else if (client1PathmonDaisTemp==1 && client1PathmonDais==0)
   {
	   client1PathmonDaisAlarm = 2;
      send_client1PathmonDaisAlarm = 1;
   }
	client1PathmonDaisTemp = client1PathmonDais;

	snmp_varlist_add_variable(&notification_vars, objid_snmptrap, objid_snmptrap_len, ASN_OBJECT_ID, (u_char *) notification_oid, notification_oid_len * sizeof(oid));
	snmp_varlist_add_variable(&notification_vars, client1PathmonDais_oid, client1PathmonDais_oid_len, ASN_INTEGER, (u_char *)&client1PathmonDaisAlarm, sizeof(client1PathmonDaisAlarm));
	snmp_varlist_add_variable(&notification_vars, client1PathmonDaisAlarmSev_oid, client1PathmonDaisAlarmSev_oid_len, ASN_INTEGER, (u_char *)&client1PathmonDaisAlarmSev, sizeof(client1PathmonDaisAlarmSev));

	if(send_client1PathmonDaisAlarm == 1)
	{
		++client1PathmonDaisCount;
		DEBUGMSGTL(("ftnc_notifications", "sending trap %ld\n",client1PathmonDaisCount));
		send_v2trap(notification_vars);
	}

	snmp_free_varbind(notification_vars);
}

void send_tp_client1PathmonDlck_notification(unsigned int clientreg, void *clientarg)
{
	DEBUGMSGTL(("token", "send_tp_client1PathmonDlck_notification.\n"));

	oid notification_oid[] = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 2, 2, 0, 117 };
	size_t notification_oid_len = OID_LENGTH(notification_oid);
	oid objid_snmptrap[] = { 1, 3, 6, 1, 6, 3, 1, 1, 4, 1, 0 };
	size_t objid_snmptrap_len = OID_LENGTH(objid_snmptrap);
	oid client1PathmonDlck_oid[]   = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 2, 2, 1, 7, 1, 36 };
	size_t client1PathmonDlck_oid_len = OID_LENGTH(client1PathmonDlck_oid);
	oid      client1PathmonDlckAlarmSev_oid[]   = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 3, 6, 2, 1, 12 };
	size_t   client1PathmonDlckAlarmSev_oid_len = OID_LENGTH(client1PathmonDlckAlarmSev_oid);

	netsnmp_variable_list *notification_vars = NULL;
	static u_long client1PathmonDlckCount = 0;

	unsigned int client1PathmonDlckAlarm = 0;

	unsigned int client1PathmonDlck = 0;
	client1PathmonDlck = pt_monitor_struct->tp_defects_struct.tp_client_path_mon[0].fields.dlck;

	unsigned int client1PathmonDlckAlarmSev = 0;
	client1PathmonDlckAlarmSev = pt_monitor_struct->tp_defects_struct.severity.severity_client[0].PathmonDlck;

	unsigned int send_client1PathmonDlckAlarm = 0;
	if (client1PathmonDlckTemp==0 && client1PathmonDlck==1)
   {
		client1PathmonDlckAlarm = 1;
		send_client1PathmonDlckAlarm = 1;
   }
   else if (client1PathmonDlckTemp==1 && client1PathmonDlck==0)
   {
	   client1PathmonDlckAlarm = 2;
      send_client1PathmonDlckAlarm = 1;
   }
	client1PathmonDlckTemp = client1PathmonDlck;

	snmp_varlist_add_variable(&notification_vars, objid_snmptrap, objid_snmptrap_len, ASN_OBJECT_ID, (u_char *) notification_oid, notification_oid_len * sizeof(oid));
	snmp_varlist_add_variable(&notification_vars, client1PathmonDlck_oid, client1PathmonDlck_oid_len, ASN_INTEGER, (u_char *)&client1PathmonDlckAlarm, sizeof(client1PathmonDlckAlarm));
	snmp_varlist_add_variable(&notification_vars, client1PathmonDlckAlarmSev_oid, client1PathmonDlckAlarmSev_oid_len, ASN_INTEGER, (u_char *)&client1PathmonDlckAlarmSev, sizeof(client1PathmonDlckAlarmSev));

	if(send_client1PathmonDlckAlarm == 1)
	{
		++client1PathmonDlckCount;
		DEBUGMSGTL(("ftnc_notifications", "sending trap %ld\n",client1PathmonDlckCount));
		send_v2trap(notification_vars);
	}

	snmp_free_varbind(notification_vars);
}

void send_tp_client1PathmonDbdi_notification(unsigned int clientreg, void *clientarg)
{
	DEBUGMSGTL(("token", "send_tp_client1PathmonDbdi_notification.\n"));

	oid notification_oid[] = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 2, 2, 0, 118 };
	size_t notification_oid_len = OID_LENGTH(notification_oid);
	oid objid_snmptrap[] = { 1, 3, 6, 1, 6, 3, 1, 1, 4, 1, 0 };
	size_t objid_snmptrap_len = OID_LENGTH(objid_snmptrap);
	oid client1PathmonDbdi_oid[]   = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 2, 2, 1, 7, 1, 37 };
	size_t client1PathmonDbdi_oid_len = OID_LENGTH(client1PathmonDbdi_oid);
	oid      client1PathmonDbdiAlarmSev_oid[]   = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 3, 6, 2, 1, 11 };
	size_t   client1PathmonDbdiAlarmSev_oid_len = OID_LENGTH(client1PathmonDbdiAlarmSev_oid);

	netsnmp_variable_list *notification_vars = NULL;
	static u_long client1PathmonDbdiCount = 0;

	unsigned int client1PathmonDbdiAlarm = 0;

	unsigned int client1PathmonDbdi = 0;
	client1PathmonDbdi = pt_monitor_struct->tp_defects_struct.tp_client_path_mon[0].fields.dbdi;

	unsigned int client1PathmonDbdiAlarmSev = 0;
	client1PathmonDbdiAlarmSev = pt_monitor_struct->tp_defects_struct.severity.severity_client[0].PathmonDbdi;

	unsigned int send_client1PathmonDbdiAlarm = 0;
	if (client1PathmonDbdiTemp==0 && client1PathmonDbdi==1)
   {
		client1PathmonDbdiAlarm = 1;
		send_client1PathmonDbdiAlarm = 1;
   }
   else if (client1PathmonDbdiTemp==1 && client1PathmonDbdi==0)
   {
	   client1PathmonDbdiAlarm = 2;
      send_client1PathmonDbdiAlarm = 1;
   }
	client1PathmonDbdiTemp = client1PathmonDbdi;

	snmp_varlist_add_variable(&notification_vars, objid_snmptrap, objid_snmptrap_len, ASN_OBJECT_ID, (u_char *) notification_oid, notification_oid_len * sizeof(oid));
	snmp_varlist_add_variable(&notification_vars, client1PathmonDbdi_oid, client1PathmonDbdi_oid_len, ASN_INTEGER, (u_char *)&client1PathmonDbdiAlarm, sizeof(client1PathmonDbdiAlarm));
	snmp_varlist_add_variable(&notification_vars, client1PathmonDbdiAlarmSev_oid, client1PathmonDbdiAlarmSev_oid_len, ASN_INTEGER, (u_char *)&client1PathmonDbdiAlarmSev, sizeof(client1PathmonDbdiAlarmSev));

	if(send_client1PathmonDbdiAlarm == 1)
	{
		++client1PathmonDbdiCount;
		DEBUGMSGTL(("ftnc_notifications", "sending trap %ld\n",client1PathmonDbdiCount));
		send_v2trap(notification_vars);
	}

	snmp_free_varbind(notification_vars);
}

//Traffic Processor Client 2 Notifications
void send_tp_client2FramerFsmms_notification(unsigned int clientreg, void *clientarg)
{
	DEBUGMSGTL(("token", "send_tp_client2FramerFsmms_notification.\n"));

	oid notification_oid[] = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 2, 2, 0, 119 };
	size_t notification_oid_len = OID_LENGTH(notification_oid);
	oid objid_snmptrap[] = { 1, 3, 6, 1, 6, 3, 1, 1, 4, 1, 0 };
	size_t objid_snmptrap_len = OID_LENGTH(objid_snmptrap);
	oid client2FramerFsmms_oid[]   = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 2, 2, 1, 7, 1, 38 };
	size_t client2FramerFsmms_oid_len = OID_LENGTH(client2FramerFsmms_oid);
	oid      client2FramerFsmmsAlarmSev_oid[]   = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 3, 6, 3, 1, 2 };
	size_t   client2FramerFsmmsAlarmSev_oid_len = OID_LENGTH(client2FramerFsmmsAlarmSev_oid);

	netsnmp_variable_list *notification_vars = NULL;
	static u_long client2FramerFsmmsCount = 0;

	unsigned int client2FramerFsmmsAlarm = 0;

	unsigned int client2FramerFsmms = 0;
	client2FramerFsmms = pt_monitor_struct->tp_defects_struct.tp_client_framer_status[1].fields.fsmms;

	unsigned int client2FramerFsmmsAlarmSev = 0;
	client2FramerFsmmsAlarmSev = pt_monitor_struct->tp_defects_struct.severity.severity_client[1].FramerFsmms;

	unsigned int send_client2FramerFsmmsAlarm = 0;
	if (client2FramerFsmmsTemp==0 && client2FramerFsmms==1)
   {
		client2FramerFsmmsAlarm = 1;
		send_client2FramerFsmmsAlarm = 1;
   }
   else if (client2FramerFsmmsTemp==1 && client2FramerFsmms==0)
   {
	   client2FramerFsmmsAlarm = 2;
      send_client2FramerFsmmsAlarm = 1;
   }
	client2FramerFsmmsTemp = client2FramerFsmms;

	snmp_varlist_add_variable(&notification_vars, objid_snmptrap, objid_snmptrap_len, ASN_OBJECT_ID, (u_char *) notification_oid, notification_oid_len * sizeof(oid));
	snmp_varlist_add_variable(&notification_vars, client2FramerFsmms_oid, client2FramerFsmms_oid_len, ASN_INTEGER, (u_char *)&client2FramerFsmmsAlarm, sizeof(client2FramerFsmmsAlarm));
	snmp_varlist_add_variable(&notification_vars, client2FramerFsmmsAlarmSev_oid, client2FramerFsmmsAlarmSev_oid_len, ASN_INTEGER, (u_char *)&client2FramerFsmmsAlarmSev, sizeof(client2FramerFsmmsAlarmSev));

	if(send_client2FramerFsmmsAlarm == 1)
	{
		++client2FramerFsmmsCount;
		DEBUGMSGTL(("ftnc_notifications", "sending trap %ld\n",client2FramerFsmmsCount));
		send_v2trap(notification_vars);
	}

	snmp_free_varbind(notification_vars);
}

void send_tp_client2FramerFssusts_notification(unsigned int clientreg, void *clientarg)
{
	DEBUGMSGTL(("token", "send_tp_client2FramerFssusts_notification.\n"));

	oid notification_oid[] = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 2, 2, 0, 120 };
	size_t notification_oid_len = OID_LENGTH(notification_oid);
	oid objid_snmptrap[] = { 1, 3, 6, 1, 6, 3, 1, 1, 4, 1, 0 };
	size_t objid_snmptrap_len = OID_LENGTH(objid_snmptrap);
	oid client2FramerFssusts_oid[]   = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 2, 2, 1, 7, 1, 39 };
	size_t client2FramerFssusts_oid_len = OID_LENGTH(client2FramerFssusts_oid);
	oid      client2FramerFssustsAlarmSev_oid[]   = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 3, 6, 3, 1, 3 };
	size_t   client2FramerFssustsAlarmSev_oid_len = OID_LENGTH(client2FramerFssustsAlarmSev_oid);

	netsnmp_variable_list *notification_vars = NULL;
	static u_long client2FramerFssustsCount = 0;

	unsigned int client2FramerFssustsAlarm = 0;

	unsigned int client2FramerFssusts = 0;
	client2FramerFssusts = pt_monitor_struct->tp_defects_struct.tp_client_framer_status[1].fields.fsusts;

	unsigned int client2FramerFssustsAlarmSev = 0;
	client2FramerFssustsAlarmSev = pt_monitor_struct->tp_defects_struct.severity.severity_client[1].FramerFssusts;

	unsigned int send_client2FramerFssustsAlarm = 0;
	if (client2FramerFssustsTemp==0 && client2FramerFssusts==1)
   {
		client2FramerFssustsAlarm = 1;
		send_client2FramerFssustsAlarm = 1;
   }
   else if (client2FramerFssustsTemp==1 && client2FramerFssusts==0)
   {
	   client2FramerFssustsAlarm = 2;
      send_client2FramerFssustsAlarm = 1;
   }
	client2FramerFssustsTemp = client2FramerFssusts;

	snmp_varlist_add_variable(&notification_vars, objid_snmptrap, objid_snmptrap_len, ASN_OBJECT_ID, (u_char *) notification_oid, notification_oid_len * sizeof(oid));
	snmp_varlist_add_variable(&notification_vars, client2FramerFssusts_oid, client2FramerFssusts_oid_len, ASN_INTEGER, (u_char *)&client2FramerFssustsAlarm, sizeof(client2FramerFssustsAlarm));
	snmp_varlist_add_variable(&notification_vars, client2FramerFssustsAlarmSev_oid, client2FramerFssustsAlarmSev_oid_len, ASN_INTEGER, (u_char *)&client2FramerFssustsAlarmSev, sizeof(client2FramerFssustsAlarmSev));

	if(send_client2FramerFssustsAlarm == 1)
	{
		++client2FramerFssustsCount;
		DEBUGMSGTL(("ftnc_notifications", "sending trap %ld\n",client2FramerFssustsCount));
		send_v2trap(notification_vars);
	}

	snmp_free_varbind(notification_vars);
}

void send_tp_client2FramerSif_notification(unsigned int clientreg, void *clientarg)
{
	DEBUGMSGTL(("token", "send_tp_client2FramerSif_notification.\n"));

	oid notification_oid[] = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 2, 2, 0, 121 };
	size_t notification_oid_len = OID_LENGTH(notification_oid);
	oid objid_snmptrap[] = { 1, 3, 6, 1, 6, 3, 1, 1, 4, 1, 0 };
	size_t objid_snmptrap_len = OID_LENGTH(objid_snmptrap);
	oid client2FramerSif_oid[]   = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 2, 2, 1, 7, 1, 40 };
	size_t client2FramerSif_oid_len = OID_LENGTH(client2FramerSif_oid);
	oid      client2FramerSifAlarmSev_oid[]   = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 3, 6, 3, 1, 6 };
	size_t   client2FramerSifAlarmSev_oid_len = OID_LENGTH(client2FramerSifAlarmSev_oid);

	netsnmp_variable_list *notification_vars = NULL;
	static u_long client2FramerSifCount = 0;

	unsigned int client2FramerSifAlarm = 0;

	unsigned int client2FramerSif = 0;
	client2FramerSif = pt_monitor_struct->tp_defects_struct.tp_client_framer_status[1].fields.sif;

	unsigned int client2FramerSifAlarmSev = 0;
	client2FramerSifAlarmSev = pt_monitor_struct->tp_defects_struct.severity.severity_client[1].FramerSif;

	unsigned int send_client2FramerSifAlarm = 0;
	if (client2FramerSifTemp==0 && client2FramerSif==1)
   {
		client2FramerSifAlarm = 1;
		send_client2FramerSifAlarm = 1;
   }
   else if (client2FramerSifTemp==1 && client2FramerSif==0)
   {
	   client2FramerSifAlarm = 2;
      send_client2FramerSifAlarm = 1;
   }
	client2FramerSifTemp = client2FramerSif;

	snmp_varlist_add_variable(&notification_vars, objid_snmptrap, objid_snmptrap_len, ASN_OBJECT_ID, (u_char *) notification_oid, notification_oid_len * sizeof(oid));
	snmp_varlist_add_variable(&notification_vars, client2FramerSif_oid, client2FramerSif_oid_len, ASN_INTEGER, (u_char *)&client2FramerSifAlarm, sizeof(client2FramerSifAlarm));
	snmp_varlist_add_variable(&notification_vars, client2FramerSifAlarmSev_oid, client2FramerSifAlarmSev_oid_len, ASN_INTEGER, (u_char *)&client2FramerSifAlarmSev, sizeof(client2FramerSifAlarmSev));

	if(send_client2FramerSifAlarm == 1)
	{
		++client2FramerSifCount;
		DEBUGMSGTL(("ftnc_notifications", "sending trap %ld\n",client2FramerSifCount));
		send_v2trap(notification_vars);
	}

	snmp_free_varbind(notification_vars);
}

void send_tp_client2FramerSoof_notification(unsigned int clientreg, void *clientarg)
{
	DEBUGMSGTL(("token", "send_tp_client2FramerSoof_notification.\n"));

	oid notification_oid[] = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 2, 2, 0, 122 };
	size_t notification_oid_len = OID_LENGTH(notification_oid);
	oid objid_snmptrap[] = { 1, 3, 6, 1, 6, 3, 1, 1, 4, 1, 0 };
	size_t objid_snmptrap_len = OID_LENGTH(objid_snmptrap);
	oid client2FramerSoof_oid[]   = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 2, 2, 1, 7, 1, 41 };
	size_t client2FramerSoof_oid_len = OID_LENGTH(client2FramerSoof_oid);
	oid      client2FramerSoofAlarmSev_oid[]   = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 3, 6, 3, 1, 4 };
	size_t   client2FramerSoofAlarmSev_oid_len = OID_LENGTH(client2FramerSoofAlarmSev_oid);

	netsnmp_variable_list *notification_vars = NULL;
	static u_long client2FramerSoofCount = 0;

	unsigned int client2FramerSoofAlarm = 0;

	unsigned int client2FramerSoof = 0;
	client2FramerSoof = pt_monitor_struct->tp_defects_struct.tp_client_framer_status[1].fields.soof;

	unsigned int client2FramerSoofAlarmSev = 0;
	client2FramerSoofAlarmSev = pt_monitor_struct->tp_defects_struct.severity.severity_client[1].FramerSoof;

	unsigned int send_client2FramerSoofAlarm = 0;
	if (client2FramerSoofTemp==0 && client2FramerSoof==1)
   {
		client2FramerSoofAlarm = 1;
		send_client2FramerSoofAlarm = 1;
   }
   else if (client2FramerSoofTemp==1 && client2FramerSoof==0)
   {
	   client2FramerSoofAlarm = 2;
      send_client2FramerSoofAlarm = 1;
   }
	client2FramerSoofTemp = client2FramerSoof;

	snmp_varlist_add_variable(&notification_vars, objid_snmptrap, objid_snmptrap_len, ASN_OBJECT_ID, (u_char *) notification_oid, notification_oid_len * sizeof(oid));
	snmp_varlist_add_variable(&notification_vars, client2FramerSoof_oid, client2FramerSoof_oid_len, ASN_INTEGER, (u_char *)&client2FramerSoofAlarm, sizeof(client2FramerSoofAlarm));
	snmp_varlist_add_variable(&notification_vars, client2FramerSoofAlarmSev_oid, client2FramerSoofAlarmSev_oid_len, ASN_INTEGER, (u_char *)&client2FramerSoofAlarmSev, sizeof(client2FramerSoofAlarmSev));

	if(send_client2FramerSoofAlarm == 1)
	{
		++client2FramerSoofCount;
		DEBUGMSGTL(("ftnc_notifications", "sending trap %ld\n",client2FramerSoofCount));
		send_v2trap(notification_vars);
	}

	snmp_free_varbind(notification_vars);
}

void send_tp_client2FramerSlof_notification(unsigned int clientreg, void *clientarg)
{
	DEBUGMSGTL(("token", "send_tp_client2FramerSlof_notification.\n"));

	oid notification_oid[] = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 2, 2, 0, 123 };
	size_t notification_oid_len = OID_LENGTH(notification_oid);
	oid objid_snmptrap[] = { 1, 3, 6, 1, 6, 3, 1, 1, 4, 1, 0 };
	size_t objid_snmptrap_len = OID_LENGTH(objid_snmptrap);
	oid client2FramerSlof_oid[]   = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 2, 2, 1, 7, 1, 42 };
	size_t client2FramerSlof_oid_len = OID_LENGTH(client2FramerSlof_oid);
	oid      client2FramerSlofAlarmSev_oid[]   = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 3, 6, 3, 1, 5 };
	size_t   client2FramerSlofAlarmSev_oid_len = OID_LENGTH(client2FramerSlofAlarmSev_oid);

	netsnmp_variable_list *notification_vars = NULL;
	static u_long client2FramerSlofCount = 0;

	unsigned int client2FramerSlofAlarm = 0;

	unsigned int client2FramerSlof = 0;
	client2FramerSlof = pt_monitor_struct->tp_defects_struct.tp_client_framer_status[1].fields.slof;

	unsigned int client2FramerSlofAlarmSev = 0;
	client2FramerSlofAlarmSev = pt_monitor_struct->tp_defects_struct.severity.severity_client[1].FramerSlof;

	unsigned int send_client2FramerSlofAlarm = 0;
	if (client2FramerSlofTemp==0 && client2FramerSlof==1)
   {
		client2FramerSlofAlarm = 1;
		send_client2FramerSlofAlarm = 1;
   }
   else if (client2FramerSlofTemp==1 && client2FramerSlof==0)
   {
	   client2FramerSlofAlarm = 2;
      send_client2FramerSlofAlarm = 1;
   }
	client2FramerSlofTemp = client2FramerSlof;

	snmp_varlist_add_variable(&notification_vars, objid_snmptrap, objid_snmptrap_len, ASN_OBJECT_ID, (u_char *) notification_oid, notification_oid_len * sizeof(oid));
	snmp_varlist_add_variable(&notification_vars, client2FramerSlof_oid, client2FramerSlof_oid_len, ASN_INTEGER, (u_char *)&client2FramerSlofAlarm, sizeof(client2FramerSlofAlarm));
	snmp_varlist_add_variable(&notification_vars, client2FramerSlofAlarmSev_oid, client2FramerSlofAlarmSev_oid_len, ASN_INTEGER, (u_char *)&client2FramerSlofAlarmSev, sizeof(client2FramerSlofAlarmSev));

	if(send_client2FramerSlofAlarm == 1)
	{
		++client2FramerSlofCount;
		DEBUGMSGTL(("ftnc_notifications", "sending trap %ld\n",client2FramerSlofCount));
		send_v2trap(notification_vars);
	}

	snmp_free_varbind(notification_vars);
}

void send_tp_client2FramerFst_notification(unsigned int clientreg, void *clientarg)
{
	DEBUGMSGTL(("token", "send_tp_client2FramerFst_notification.\n"));

	oid notification_oid[] = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 2, 2, 0, 124 };
	size_t notification_oid_len = OID_LENGTH(notification_oid);
	oid objid_snmptrap[] = { 1, 3, 6, 1, 6, 3, 1, 1, 4, 1, 0 };
	size_t objid_snmptrap_len = OID_LENGTH(objid_snmptrap);
	oid client2FramerFst_oid[]   = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 2, 2, 1, 7, 1, 43 };
	size_t client2FramerFst_oid_len = OID_LENGTH(client2FramerFst_oid);
	oid      client2FramerFstAlarmSev_oid[]   = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 3, 6, 3, 1, 7 };
	size_t   client2FramerFstAlarmSev_oid_len = OID_LENGTH(client2FramerFstAlarmSev_oid);

	netsnmp_variable_list *notification_vars = NULL;
	static u_long client2FramerFstCount = 0;

	unsigned int client2FramerFstAlarm = 0;

	unsigned int client2FramerFst = 0;
	client2FramerFst = pt_monitor_struct->tp_defects_struct.tp_client_framer_status[1].fields.fst;

	unsigned int client2FramerFstAlarmSev = 0;
	client2FramerFstAlarmSev = pt_monitor_struct->tp_defects_struct.severity.severity_client[1].FramerFst;

	unsigned int send_client2FramerFstAlarm = 0;
	if (client2FramerFstTemp==0 && client2FramerFst==1)
   {
		client2FramerFstAlarm = 1;
		send_client2FramerFstAlarm = 1;
   }
   else if (client2FramerFstTemp==1 && client2FramerFst==0)
   {
	   client2FramerFstAlarm = 2;
      send_client2FramerFstAlarm = 1;
   }
	client2FramerFstTemp = client2FramerFst;

	snmp_varlist_add_variable(&notification_vars, objid_snmptrap, objid_snmptrap_len, ASN_OBJECT_ID, (u_char *) notification_oid, notification_oid_len * sizeof(oid));
	snmp_varlist_add_variable(&notification_vars, client2FramerFst_oid, client2FramerFst_oid_len, ASN_INTEGER, (u_char *)&client2FramerFstAlarm, sizeof(client2FramerFstAlarm));
	snmp_varlist_add_variable(&notification_vars, client2FramerFstAlarmSev_oid, client2FramerFstAlarmSev_oid_len, ASN_INTEGER, (u_char *)&client2FramerFstAlarmSev, sizeof(client2FramerFstAlarmSev));

	if(send_client2FramerFstAlarm == 1)
	{
		++client2FramerFstCount;
		DEBUGMSGTL(("ftnc_notifications", "sending trap %ld\n",client2FramerFstCount));
		send_v2trap(notification_vars);
	}

	snmp_free_varbind(notification_vars);
}

void send_tp_client2LosstatLosf_notification(unsigned int clientreg, void *clientarg)
{
	DEBUGMSGTL(("token", "send_tp_client2LosstatLosf_notification.\n"));

	oid notification_oid[] = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 2, 2, 0, 125 };
	size_t notification_oid_len = OID_LENGTH(notification_oid);
	oid objid_snmptrap[] = { 1, 3, 6, 1, 6, 3, 1, 1, 4, 1, 0 };
	size_t objid_snmptrap_len = OID_LENGTH(objid_snmptrap);
	oid client2LosstatLosf_oid[]   = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 2, 2, 1, 7, 1, 44 };
	size_t client2LosstatLosf_oid_len = OID_LENGTH(client2LosstatLosf_oid);
	oid      client2LosstatLosfAlarmSev_oid[]   = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 3, 6, 3, 1, 8 };
	size_t   client2LosstatLosfAlarmSev_oid_len = OID_LENGTH(client2LosstatLosfAlarmSev_oid);

	netsnmp_variable_list *notification_vars = NULL;
	static u_long client2LosstatLosfCount = 0;

	unsigned int client2LosstatLosfAlarm = 0;

	unsigned int client2LosstatLosf = 0;
	client2LosstatLosf = pt_monitor_struct->tp_defects_struct.tp_client_los_status[1].fields.losf;

	unsigned int client2LosstatLosfAlarmSev = 0;
	client2LosstatLosfAlarmSev = pt_monitor_struct->tp_defects_struct.severity.severity_client[1].LosstatLosf;

	unsigned int send_client2LosstatLosfAlarm = 0;
	if (client2LosstatLosfTemp==0 && client2LosstatLosf==1)
   {
		client2LosstatLosfAlarm = 1;
		send_client2LosstatLosfAlarm = 1;
   }
   else if (client2LosstatLosfTemp==1 && client2LosstatLosf==0)
   {
	   client2LosstatLosfAlarm = 2;
      send_client2LosstatLosfAlarm = 1;
   }
	client2LosstatLosfTemp = client2LosstatLosf;

	snmp_varlist_add_variable(&notification_vars, objid_snmptrap, objid_snmptrap_len, ASN_OBJECT_ID, (u_char *) notification_oid, notification_oid_len * sizeof(oid));
	snmp_varlist_add_variable(&notification_vars, client2LosstatLosf_oid, client2LosstatLosf_oid_len, ASN_INTEGER, (u_char *)&client2LosstatLosfAlarm, sizeof(client2LosstatLosfAlarm));
	snmp_varlist_add_variable(&notification_vars, client2LosstatLosfAlarmSev_oid, client2LosstatLosfAlarmSev_oid_len, ASN_INTEGER, (u_char *)&client2LosstatLosfAlarmSev, sizeof(client2LosstatLosfAlarmSev));

	if(send_client2LosstatLosfAlarm == 1)
	{
		++client2LosstatLosfCount;
		DEBUGMSGTL(("ftnc_notifications", "sending trap %ld\n",client2LosstatLosfCount));
		send_v2trap(notification_vars);
	}

	snmp_free_varbind(notification_vars);
}

void send_tp_client2SecmonFlom_notification(unsigned int clientreg, void *clientarg)
{
	DEBUGMSGTL(("token", "send_tp_client2SecmonFlom_notification.\n"));

	oid notification_oid[] = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 2, 2, 0, 126 };
	size_t notification_oid_len = OID_LENGTH(notification_oid);
	oid objid_snmptrap[] = { 1, 3, 6, 1, 6, 3, 1, 1, 4, 1, 0 };
	size_t objid_snmptrap_len = OID_LENGTH(objid_snmptrap);
	oid client2SecmonFlom_oid[]   = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 2, 2, 1, 7, 1, 45 };
	size_t client2SecmonFlom_oid_len = OID_LENGTH(client2SecmonFlom_oid);
	oid      client2SecmonFlomAlarmSev_oid[]   = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 3, 6, 3, 1, 17 };
	size_t   client2SecmonFlomAlarmSev_oid_len = OID_LENGTH(client2SecmonFlomAlarmSev_oid);

	netsnmp_variable_list *notification_vars = NULL;
	static u_long client2SecmonFlomCount = 0;

	unsigned int client2SecmonFlomAlarm = 0;

	unsigned int client2SecmonFlom = 0;
	client2SecmonFlom = pt_monitor_struct->tp_defects_struct.tp_client_section_mon[1].fields.flom;

	unsigned int client2SecmonFlomAlarmSev = 0;
	client2SecmonFlomAlarmSev = pt_monitor_struct->tp_defects_struct.severity.severity_client[1].SecmonFlom;

	unsigned int send_client2SecmonFlomAlarm = 0;
	if (client2SecmonFlomTemp==0 && client2SecmonFlom==1)
   {
		client2SecmonFlomAlarm = 1;
		send_client2SecmonFlomAlarm = 1;
   }
   else if (client2SecmonFlomTemp==1 && client2SecmonFlom==0)
   {
	   client2SecmonFlomAlarm = 2;
      send_client2SecmonFlomAlarm = 1;
   }
	client2SecmonFlomTemp = client2SecmonFlom;

	snmp_varlist_add_variable(&notification_vars, objid_snmptrap, objid_snmptrap_len, ASN_OBJECT_ID, (u_char *) notification_oid, notification_oid_len * sizeof(oid));
	snmp_varlist_add_variable(&notification_vars, client2SecmonFlom_oid, client2SecmonFlom_oid_len, ASN_INTEGER, (u_char *)&client2SecmonFlomAlarm, sizeof(client2SecmonFlomAlarm));
	snmp_varlist_add_variable(&notification_vars, client2SecmonFlomAlarmSev_oid, client2SecmonFlomAlarmSev_oid_len, ASN_INTEGER, (u_char *)&client2SecmonFlomAlarmSev, sizeof(client2SecmonFlomAlarmSev));

	if(send_client2SecmonFlomAlarm == 1)
	{
		++client2SecmonFlomCount;
		DEBUGMSGTL(("ftnc_notifications", "sending trap %ld\n",client2SecmonFlomCount));
		send_v2trap(notification_vars);
	}

	snmp_free_varbind(notification_vars);
}

void send_tp_client2SecmonBipsfs_notification(unsigned int clientreg, void *clientarg)
{
	DEBUGMSGTL(("token", "send_tp_client2SecmonBipsfs_notification.\n"));

	oid notification_oid[] = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 2, 2, 0, 127 };
	size_t notification_oid_len = OID_LENGTH(notification_oid);
	oid objid_snmptrap[] = { 1, 3, 6, 1, 6, 3, 1, 1, 4, 1, 0 };
	size_t objid_snmptrap_len = OID_LENGTH(objid_snmptrap);
	oid client2SecmonBipsfs_oid[]   = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 2, 2, 1, 7, 1, 46 };
	size_t client2SecmonBipsfs_oid_len = OID_LENGTH(client2SecmonBipsfs_oid);
	oid      client2SecmonBipsfsAlarmSev_oid[]   = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 3, 6, 3, 1, 14 };
	size_t   client2SecmonBipsfsAlarmSev_oid_len = OID_LENGTH(client2SecmonBipsfsAlarmSev_oid);

	netsnmp_variable_list *notification_vars = NULL;
	static u_long client2SecmonBipsfsCount = 0;

	unsigned int client2SecmonBipsfsAlarm = 0;

	unsigned int client2SecmonBipsfs = 0;
	client2SecmonBipsfs = pt_monitor_struct->tp_defects_struct.tp_client_section_mon[1].fields.bipsfs;

	unsigned int client2SecmonBipsfsAlarmSev = 0;
	client2SecmonBipsfsAlarmSev = pt_monitor_struct->tp_defects_struct.severity.severity_client[1].SecmonBipsfs;

	unsigned int send_client2SecmonBipsfsAlarm = 0;
	if (client2SecmonBipsfsTemp==0 && client2SecmonBipsfs==1)
   {
		client2SecmonBipsfsAlarm = 1;
		send_client2SecmonBipsfsAlarm = 1;
   }
   else if (client2SecmonBipsfsTemp==1 && client2SecmonBipsfs==0)
   {
	   client2SecmonBipsfsAlarm = 2;
      send_client2SecmonBipsfsAlarm = 1;
   }
	client2SecmonBipsfsTemp = client2SecmonBipsfs;

	snmp_varlist_add_variable(&notification_vars, objid_snmptrap, objid_snmptrap_len, ASN_OBJECT_ID, (u_char *) notification_oid, notification_oid_len * sizeof(oid));
	snmp_varlist_add_variable(&notification_vars, client2SecmonBipsfs_oid, client2SecmonBipsfs_oid_len, ASN_INTEGER, (u_char *)&client2SecmonBipsfsAlarm, sizeof(client2SecmonBipsfsAlarm));
	snmp_varlist_add_variable(&notification_vars, client2SecmonBipsfsAlarmSev_oid, client2SecmonBipsfsAlarmSev_oid_len, ASN_INTEGER, (u_char *)&client2SecmonBipsfsAlarmSev, sizeof(client2SecmonBipsfsAlarmSev));

	if(send_client2SecmonBipsfsAlarm == 1)
	{
		++client2SecmonBipsfsCount;
		DEBUGMSGTL(("ftnc_notifications", "sending trap %ld\n",client2SecmonBipsfsCount));
		send_v2trap(notification_vars);
	}

	snmp_free_varbind(notification_vars);
}

void send_tp_client2SecmonDiae_notification(unsigned int clientreg, void *clientarg)
{
	DEBUGMSGTL(("token", "send_tp_client2SecmonDiae_notification.\n"));

	oid notification_oid[] = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 2, 2, 0, 128 };
	size_t notification_oid_len = OID_LENGTH(notification_oid);
	oid objid_snmptrap[] = { 1, 3, 6, 1, 6, 3, 1, 1, 4, 1, 0 };
	size_t objid_snmptrap_len = OID_LENGTH(objid_snmptrap);
	oid client2SecmonDiae_oid[]   = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 2, 2, 1, 7, 1, 47 };
	size_t client2SecmonDiae_oid_len = OID_LENGTH(client2SecmonDiae_oid);
	oid      client2SecmonDiaeAlarmSev_oid[]   = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 3, 6, 3, 1, 16 };
	size_t   client2SecmonDiaeAlarmSev_oid_len = OID_LENGTH(client2SecmonDiaeAlarmSev_oid);

	netsnmp_variable_list *notification_vars = NULL;
	static u_long client2SecmonDiaeCount = 0;

	unsigned int client2SecmonDiaeAlarm = 0;

	unsigned int client2SecmonDiae = 0;
	client2SecmonDiae = pt_monitor_struct->tp_defects_struct.tp_client_section_mon[1].fields.diae;

	unsigned int client2SecmonDiaeAlarmSev = 0;
	client2SecmonDiaeAlarmSev = pt_monitor_struct->tp_defects_struct.severity.severity_client[1].SecmonDiae;

	unsigned int send_client2SecmonDiaeAlarm = 0;
	if (client2SecmonDiaeTemp==0 && client2SecmonDiae==1)
   {
		client2SecmonDiaeAlarm = 1;
		send_client2SecmonDiaeAlarm = 1;
   }
   else if (client2SecmonDiaeTemp==1 && client2SecmonDiae==0)
   {
	   client2SecmonDiaeAlarm = 2;
      send_client2SecmonDiaeAlarm = 1;
   }
	client2SecmonDiaeTemp = client2SecmonDiae;

	snmp_varlist_add_variable(&notification_vars, objid_snmptrap, objid_snmptrap_len, ASN_OBJECT_ID, (u_char *) notification_oid, notification_oid_len * sizeof(oid));
	snmp_varlist_add_variable(&notification_vars, client2SecmonDiae_oid, client2SecmonDiae_oid_len, ASN_INTEGER, (u_char *)&client2SecmonDiaeAlarm, sizeof(client2SecmonDiaeAlarm));
	snmp_varlist_add_variable(&notification_vars, client2SecmonDiaeAlarmSev_oid, client2SecmonDiaeAlarmSev_oid_len, ASN_INTEGER, (u_char *)&client2SecmonDiaeAlarmSev, sizeof(client2SecmonDiaeAlarmSev));

	if(send_client2SecmonDiaeAlarm == 1)
	{
		++client2SecmonDiaeCount;
		DEBUGMSGTL(("ftnc_notifications", "sending trap %ld\n",client2SecmonDiaeCount));
		send_v2trap(notification_vars);
	}

	snmp_free_varbind(notification_vars);
}

void send_tp_client2SecmonDbdi_notification(unsigned int clientreg, void *clientarg)
{
	DEBUGMSGTL(("token", "send_tp_client2SecmonDbdi_notification.\n"));

	oid notification_oid[] = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 2, 2, 0, 129 };
	size_t notification_oid_len = OID_LENGTH(notification_oid);
	oid objid_snmptrap[] = { 1, 3, 6, 1, 6, 3, 1, 1, 4, 1, 0 };
	size_t objid_snmptrap_len = OID_LENGTH(objid_snmptrap);
	oid client2SecmonDbdi_oid[]   = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 2, 2, 1, 7, 1, 48 };
	size_t client2SecmonDbdi_oid_len = OID_LENGTH(client2SecmonDbdi_oid);
	oid      client2SecmonDbdiAlarmSev_oid[]   = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 3, 6, 3, 1, 15 };
	size_t   client2SecmonDbdiAlarmSev_oid_len = OID_LENGTH(client2SecmonDbdiAlarmSev_oid);

	netsnmp_variable_list *notification_vars = NULL;
	static u_long client2SecmonDbdiCount = 0;

	unsigned int client2SecmonDbdiAlarm = 0;

	unsigned int client2SecmonDbdi = 0;
	client2SecmonDbdi = pt_monitor_struct->tp_defects_struct.tp_client_section_mon[1].fields.dbdi;

	unsigned int client2SecmonDbdiAlarmSev = 0;
	client2SecmonDbdiAlarmSev = pt_monitor_struct->tp_defects_struct.severity.severity_client[1].SecmonDbdi;

	unsigned int send_client2SecmonDbdiAlarm = 0;
	if (client2SecmonDbdiTemp==0 && client2SecmonDbdi==1)
   {
		client2SecmonDbdiAlarm = 1;
		send_client2SecmonDbdiAlarm = 1;
   }
   else if (client2SecmonDbdiTemp==1 && client2SecmonDbdi==0)
   {
	   client2SecmonDbdiAlarm = 2;
      send_client2SecmonDbdiAlarm = 1;
   }
	client2SecmonDbdiTemp = client2SecmonDbdi;

	snmp_varlist_add_variable(&notification_vars, objid_snmptrap, objid_snmptrap_len, ASN_OBJECT_ID, (u_char *) notification_oid, notification_oid_len * sizeof(oid));
	snmp_varlist_add_variable(&notification_vars, client2SecmonDbdi_oid, client2SecmonDbdi_oid_len, ASN_INTEGER, (u_char *)&client2SecmonDbdiAlarm, sizeof(client2SecmonDbdiAlarm));
	snmp_varlist_add_variable(&notification_vars, client2SecmonDbdiAlarmSev_oid, client2SecmonDbdiAlarmSev_oid_len, ASN_INTEGER, (u_char *)&client2SecmonDbdiAlarmSev, sizeof(client2SecmonDbdiAlarmSev));

	if(send_client2SecmonDbdiAlarm == 1)
	{
		++client2SecmonDbdiCount;
		DEBUGMSGTL(("ftnc_notifications", "sending trap %ld\n",client2SecmonDbdiCount));
		send_v2trap(notification_vars);
	}

	snmp_free_varbind(notification_vars);
}

void send_tp_client2SecmonLom_notification(unsigned int clientreg, void *clientarg)
{
	DEBUGMSGTL(("token", "send_tp_client2SecmonLom_notification.\n"));

	oid notification_oid[] = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 2, 2, 0, 130 };
	size_t notification_oid_len = OID_LENGTH(notification_oid);
	oid objid_snmptrap[] = { 1, 3, 6, 1, 6, 3, 1, 1, 4, 1, 0 };
	size_t objid_snmptrap_len = OID_LENGTH(objid_snmptrap);
	oid client2SecmonLom_oid[]   = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 2, 2, 1, 7, 1, 49 };
	size_t client2SecmonLom_oid_len = OID_LENGTH(client2SecmonLom_oid);
	oid      client2SecmonLomAlarmSev_oid[]   = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 3, 6, 3, 1, 18 };
	size_t   client2SecmonLomAlarmSev_oid_len = OID_LENGTH(client2SecmonLomAlarmSev_oid);

	netsnmp_variable_list *notification_vars = NULL;
	static u_long client2SecmonLomCount = 0;

	unsigned int client2SecmonLomAlarm = 0;

	unsigned int client2SecmonLom = 0;
	client2SecmonLom = pt_monitor_struct->tp_defects_struct.tp_client_section_mon[1].fields.lom;

	unsigned int client2SecmonLomAlarmSev = 0;
	client2SecmonLomAlarmSev = pt_monitor_struct->tp_defects_struct.severity.severity_client[1].SecmonLom;

	unsigned int send_client2SecmonLomAlarm = 0;
	if (client2SecmonLomTemp==0 && client2SecmonLom==1)
   {
		client2SecmonLomAlarm = 1;
		send_client2SecmonLomAlarm = 1;
   }
   else if (client2SecmonLomTemp==1 && client2SecmonLom==0)
   {
	   client2SecmonLomAlarm = 2;
      send_client2SecmonLomAlarm = 1;
   }
	client2SecmonLomTemp = client2SecmonLom;

	snmp_varlist_add_variable(&notification_vars, objid_snmptrap, objid_snmptrap_len, ASN_OBJECT_ID, (u_char *) notification_oid, notification_oid_len * sizeof(oid));
	snmp_varlist_add_variable(&notification_vars, client2SecmonLom_oid, client2SecmonLom_oid_len, ASN_INTEGER, (u_char *)&client2SecmonLomAlarm, sizeof(client2SecmonLomAlarm));
	snmp_varlist_add_variable(&notification_vars, client2SecmonLomAlarmSev_oid, client2SecmonLomAlarmSev_oid_len, ASN_INTEGER, (u_char *)&client2SecmonLomAlarmSev, sizeof(client2SecmonLomAlarmSev));

	if(send_client2SecmonLomAlarm == 1)
	{
		++client2SecmonLomCount;
		DEBUGMSGTL(("ftnc_notifications", "sending trap %ld\n",client2SecmonLomCount));
		send_v2trap(notification_vars);
	}

	snmp_free_varbind(notification_vars);
}

void send_tp_client2PathmonAccstat_notification(unsigned int clientreg, void *clientarg)
{
	DEBUGMSGTL(("token", "send_tp_client2PathmonAccstat_notification.\n"));

	oid notification_oid[] = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 2, 2, 0, 131 };
	size_t notification_oid_len = OID_LENGTH(notification_oid);
	oid objid_snmptrap[] = { 1, 3, 6, 1, 6, 3, 1, 1, 4, 1, 0 };
	size_t objid_snmptrap_len = OID_LENGTH(objid_snmptrap);
	oid client2PathmonAccstat_oid[]   = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 2, 2, 1, 7, 1, 50 };
	size_t client2PathmonAccstat_oid_len = OID_LENGTH(client2PathmonAccstat_oid);
	oid      client2PathmonAccstatAlarmSev_oid[]   = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 3, 6, 3, 1, 9 };
	size_t   client2PathmonAccstatAlarmSev_oid_len = OID_LENGTH(client2PathmonAccstatAlarmSev_oid);

	netsnmp_variable_list *notification_vars = NULL;
	static u_long client2PathmonAccstatCount = 0;

	unsigned int client2PathmonAccstatAlarm = 0;

	unsigned int client2PathmonAccstat = 0;
	client2PathmonAccstat = pt_monitor_struct->tp_defects_struct.tp_client_path_mon[1].fields.accstat;

	unsigned int client2PathmonAccstatAlarmSev = 0;
	client2PathmonAccstatAlarmSev = pt_monitor_struct->tp_defects_struct.severity.severity_client[1].PathmonAccstat;

	unsigned int send_client2PathmonAccstatAlarm = 0;
	if (client2PathmonAccstatTemp==0 && client2PathmonAccstat==1)
   {
		client2PathmonAccstatAlarm = 1;
		send_client2PathmonAccstatAlarm = 1;
   }
   else if (client2PathmonAccstatTemp==1 && client2PathmonAccstat==0)
   {
	   client2PathmonAccstatAlarm = 2;
      send_client2PathmonAccstatAlarm = 1;
   }
	client2PathmonAccstatTemp = client2PathmonAccstat;

	snmp_varlist_add_variable(&notification_vars, objid_snmptrap, objid_snmptrap_len, ASN_OBJECT_ID, (u_char *) notification_oid, notification_oid_len * sizeof(oid));
	snmp_varlist_add_variable(&notification_vars, client2PathmonAccstat_oid, client2PathmonAccstat_oid_len, ASN_INTEGER, (u_char *)&client2PathmonAccstatAlarm, sizeof(client2PathmonAccstatAlarm));
	snmp_varlist_add_variable(&notification_vars, client2PathmonAccstatAlarmSev_oid, client2PathmonAccstatAlarmSev_oid_len, ASN_INTEGER, (u_char *)&client2PathmonAccstatAlarmSev, sizeof(client2PathmonAccstatAlarmSev));

	if(send_client2PathmonAccstatAlarm == 1)
	{
		++client2PathmonAccstatCount;
		DEBUGMSGTL(("ftnc_notifications", "sending trap %ld\n",client2PathmonAccstatCount));
		send_v2trap(notification_vars);
	}

	snmp_free_varbind(notification_vars);
}

void send_tp_client2PathmonMsiunst_notification(unsigned int clientreg, void *clientarg)
{
	DEBUGMSGTL(("token", "send_tp_client2PathmonMsiunst_notification.\n"));

	oid notification_oid[] = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 2, 2, 0, 132 };
	size_t notification_oid_len = OID_LENGTH(notification_oid);
	oid objid_snmptrap[] = { 1, 3, 6, 1, 6, 3, 1, 1, 4, 1, 0 };
	size_t objid_snmptrap_len = OID_LENGTH(objid_snmptrap);
	oid client2PathmonMsiunst_oid[]   = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 2, 2, 1, 7, 1, 51 };
	size_t client2PathmonMsiunst_oid_len = OID_LENGTH(client2PathmonMsiunst_oid);
	oid      client2PathmonMsiunstAlarmSev_oid[]   = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 3, 6, 3, 1, 13 };
	size_t   client2PathmonMsiunstAlarmSev_oid_len = OID_LENGTH(client2PathmonMsiunstAlarmSev_oid);

	netsnmp_variable_list *notification_vars = NULL;
	static u_long client2PathmonMsiunstCount = 0;

	unsigned int client2PathmonMsiunstAlarm = 0;

	unsigned int client2PathmonMsiunst = 0;
	client2PathmonMsiunst = pt_monitor_struct->tp_defects_struct.tp_client_path_mon[1].fields.msiunst;

	unsigned int client2PathmonMsiunstAlarmSev = 0;
	client2PathmonMsiunstAlarmSev = pt_monitor_struct->tp_defects_struct.severity.severity_client[1].PathmonMsiunst;

	unsigned int send_client2PathmonMsiunstAlarm = 0;
	if (client2PathmonMsiunstTemp==0 && client2PathmonMsiunst==1)
   {
		client2PathmonMsiunstAlarm = 1;
		send_client2PathmonMsiunstAlarm = 1;
   }
   else if (client2PathmonMsiunstTemp==1 && client2PathmonMsiunst==0)
   {
	   client2PathmonMsiunstAlarm = 2;
      send_client2PathmonMsiunstAlarm = 1;
   }
	client2PathmonMsiunstTemp = client2PathmonMsiunst;

	snmp_varlist_add_variable(&notification_vars, objid_snmptrap, objid_snmptrap_len, ASN_OBJECT_ID, (u_char *) notification_oid, notification_oid_len * sizeof(oid));
	snmp_varlist_add_variable(&notification_vars, client2PathmonMsiunst_oid, client2PathmonMsiunst_oid_len, ASN_INTEGER, (u_char *)&client2PathmonMsiunstAlarm, sizeof(client2PathmonMsiunstAlarm));
	snmp_varlist_add_variable(&notification_vars, client2PathmonMsiunstAlarmSev_oid, client2PathmonMsiunstAlarmSev_oid_len, ASN_INTEGER, (u_char *)&client2PathmonMsiunstAlarmSev, sizeof(client2PathmonMsiunstAlarmSev));

	if(send_client2PathmonMsiunstAlarm == 1)
	{
		++client2PathmonMsiunstCount;
		DEBUGMSGTL(("ftnc_notifications", "sending trap %ld\n",client2PathmonMsiunstCount));
		send_v2trap(notification_vars);
	}

	snmp_free_varbind(notification_vars);
}

void send_tp_client2PathmonDais_notification(unsigned int clientreg, void *clientarg)
{
	DEBUGMSGTL(("token", "send_tp_client2PathmonDais_notification.\n"));

	oid notification_oid[] = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 2, 2, 0, 133 };
	size_t notification_oid_len = OID_LENGTH(notification_oid);
	oid objid_snmptrap[] = { 1, 3, 6, 1, 6, 3, 1, 1, 4, 1, 0 };
	size_t objid_snmptrap_len = OID_LENGTH(objid_snmptrap);
	oid client2PathmonDais_oid[]   = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 2, 2, 1, 7, 1, 52 };
	size_t client2PathmonDais_oid_len = OID_LENGTH(client2PathmonDais_oid);
	oid      client2PathmonDaisAlarmSev_oid[]   = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 3, 6, 3, 1, 10 };
	size_t   client2PathmonDaisAlarmSev_oid_len = OID_LENGTH(client2PathmonDaisAlarmSev_oid);

	netsnmp_variable_list *notification_vars = NULL;
	static u_long client2PathmonDaisCount = 0;

	unsigned int client2PathmonDaisAlarm = 0;

	unsigned int client2PathmonDais = 0;
	client2PathmonDais = pt_monitor_struct->tp_defects_struct.tp_client_path_mon[1].fields.dais;

	unsigned int client2PathmonDaisAlarmSev = 0;
	client2PathmonDaisAlarmSev = pt_monitor_struct->tp_defects_struct.severity.severity_client[1].PathmonDais;

	unsigned int send_client2PathmonDaisAlarm = 0;
	if (client2PathmonDaisTemp==0 && client2PathmonDais==1)
   {
		client2PathmonDaisAlarm = 1;
		send_client2PathmonDaisAlarm = 1;
   }
   else if (client2PathmonDaisTemp==1 && client2PathmonDais==0)
   {
	   client2PathmonDaisAlarm = 2;
      send_client2PathmonDaisAlarm = 1;
   }
	client2PathmonDaisTemp = client2PathmonDais;

	snmp_varlist_add_variable(&notification_vars, objid_snmptrap, objid_snmptrap_len, ASN_OBJECT_ID, (u_char *) notification_oid, notification_oid_len * sizeof(oid));
	snmp_varlist_add_variable(&notification_vars, client2PathmonDais_oid, client2PathmonDais_oid_len, ASN_INTEGER, (u_char *)&client2PathmonDaisAlarm, sizeof(client2PathmonDaisAlarm));
	snmp_varlist_add_variable(&notification_vars, client2PathmonDaisAlarmSev_oid, client2PathmonDaisAlarmSev_oid_len, ASN_INTEGER, (u_char *)&client2PathmonDaisAlarmSev, sizeof(client2PathmonDaisAlarmSev));

	if(send_client2PathmonDaisAlarm == 1)
	{
		++client2PathmonDaisCount;
		DEBUGMSGTL(("ftnc_notifications", "sending trap %ld\n",client2PathmonDaisCount));
		send_v2trap(notification_vars);
	}

	snmp_free_varbind(notification_vars);
}

void send_tp_client2PathmonDlck_notification(unsigned int clientreg, void *clientarg)
{
	DEBUGMSGTL(("token", "send_tp_client2PathmonDlck_notification.\n"));

	oid notification_oid[] = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 2, 2, 0, 134 };
	size_t notification_oid_len = OID_LENGTH(notification_oid);
	oid objid_snmptrap[] = { 1, 3, 6, 1, 6, 3, 1, 1, 4, 1, 0 };
	size_t objid_snmptrap_len = OID_LENGTH(objid_snmptrap);
	oid client2PathmonDlck_oid[]   = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 2, 2, 1, 7, 1, 53 };
	size_t client2PathmonDlck_oid_len = OID_LENGTH(client2PathmonDlck_oid);
	oid      client2PathmonDlckAlarmSev_oid[]   = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 3, 6, 3, 1, 12 };
	size_t   client2PathmonDlckAlarmSev_oid_len = OID_LENGTH(client2PathmonDlckAlarmSev_oid);

	netsnmp_variable_list *notification_vars = NULL;
	static u_long client2PathmonDlckCount = 0;

	unsigned int client2PathmonDlckAlarm = 0;

	unsigned int client2PathmonDlck = 0;
	client2PathmonDlck = pt_monitor_struct->tp_defects_struct.tp_client_path_mon[1].fields.dlck;

	unsigned int client2PathmonDlckAlarmSev = 0;
	client2PathmonDlckAlarmSev = pt_monitor_struct->tp_defects_struct.severity.severity_client[1].PathmonDlck;

	unsigned int send_client2PathmonDlckAlarm = 0;
	if (client2PathmonDlckTemp==0 && client2PathmonDlck==1)
   {
		client2PathmonDlckAlarm = 1;
		send_client2PathmonDlckAlarm = 1;
   }
   else if (client2PathmonDlckTemp==1 && client2PathmonDlck==0)
   {
	   client2PathmonDlckAlarm = 2;
      send_client2PathmonDlckAlarm = 1;
   }
	client2PathmonDlckTemp = client2PathmonDlck;

	snmp_varlist_add_variable(&notification_vars, objid_snmptrap, objid_snmptrap_len, ASN_OBJECT_ID, (u_char *) notification_oid, notification_oid_len * sizeof(oid));
	snmp_varlist_add_variable(&notification_vars, client2PathmonDlck_oid, client2PathmonDlck_oid_len, ASN_INTEGER, (u_char *)&client2PathmonDlckAlarm, sizeof(client2PathmonDlckAlarm));
	snmp_varlist_add_variable(&notification_vars, client2PathmonDlckAlarmSev_oid, client2PathmonDlckAlarmSev_oid_len, ASN_INTEGER, (u_char *)&client2PathmonDlckAlarmSev, sizeof(client2PathmonDlckAlarmSev));

	if(send_client2PathmonDlckAlarm == 1)
	{
		++client2PathmonDlckCount;
		DEBUGMSGTL(("ftnc_notifications", "sending trap %ld\n",client2PathmonDlckCount));
		send_v2trap(notification_vars);
	}

	snmp_free_varbind(notification_vars);
}

void send_tp_client2PathmonDbdi_notification(unsigned int clientreg, void *clientarg)
{
	DEBUGMSGTL(("token", "send_tp_client2PathmonDbdi_notification.\n"));

	oid notification_oid[] = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 2, 2, 0, 135 };
	size_t notification_oid_len = OID_LENGTH(notification_oid);
	oid objid_snmptrap[] = { 1, 3, 6, 1, 6, 3, 1, 1, 4, 1, 0 };
	size_t objid_snmptrap_len = OID_LENGTH(objid_snmptrap);
	oid client2PathmonDbdi_oid[]   = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 2, 2, 1, 7, 1, 54 };
	size_t client2PathmonDbdi_oid_len = OID_LENGTH(client2PathmonDbdi_oid);
	oid      client2PathmonDbdiAlarmSev_oid[]   = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 3, 6, 3, 1, 111 };
	size_t   client2PathmonDbdiAlarmSev_oid_len = OID_LENGTH(client2PathmonDbdiAlarmSev_oid);

	netsnmp_variable_list *notification_vars = NULL;
	static u_long client2PathmonDbdiCount = 0;

	unsigned int client2PathmonDbdiAlarm = 0;

	unsigned int client2PathmonDbdi = 0;
	client2PathmonDbdi = pt_monitor_struct->tp_defects_struct.tp_client_path_mon[1].fields.dbdi;

	unsigned int client2PathmonDbdiAlarmSev = 0;
	client2PathmonDbdiAlarmSev = pt_monitor_struct->tp_defects_struct.severity.severity_client[1].PathmonDbdi;

	unsigned int send_client2PathmonDbdiAlarm = 0;
	if (client2PathmonDbdiTemp==0 && client2PathmonDbdi==1)
   {
		client2PathmonDbdiAlarm = 1;
		send_client2PathmonDbdiAlarm = 1;
   }
   else if (client2PathmonDbdiTemp==1 && client2PathmonDbdi==0)
   {
	   client2PathmonDbdiAlarm = 2;
      send_client2PathmonDbdiAlarm = 1;
   }
	client2PathmonDbdiTemp = client2PathmonDbdi;

	snmp_varlist_add_variable(&notification_vars, objid_snmptrap, objid_snmptrap_len, ASN_OBJECT_ID, (u_char *) notification_oid, notification_oid_len * sizeof(oid));
	snmp_varlist_add_variable(&notification_vars, client2PathmonDbdi_oid, client2PathmonDbdi_oid_len, ASN_INTEGER, (u_char *)&client2PathmonDbdiAlarm, sizeof(client2PathmonDbdiAlarm));
	snmp_varlist_add_variable(&notification_vars, client2PathmonDbdiAlarmSev_oid, client2PathmonDbdiAlarmSev_oid_len, ASN_INTEGER, (u_char *)&client2PathmonDbdiAlarmSev, sizeof(client2PathmonDbdiAlarmSev));

	if(send_client2PathmonDbdiAlarm == 1)
	{
		++client2PathmonDbdiCount;
		DEBUGMSGTL(("ftnc_notifications", "sending trap %ld\n",client2PathmonDbdiCount));
		send_v2trap(notification_vars);
	}

	snmp_free_varbind(notification_vars);
}

//Traffic Processor Client 3 Notifications
void send_tp_client3FramerFsmms_notification(unsigned int clientreg, void *clientarg)
{
	DEBUGMSGTL(("token", "send_tp_client3FramerFsmms_notification.\n"));

	oid notification_oid[] = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 2, 2, 0, 136 };
	size_t notification_oid_len = OID_LENGTH(notification_oid);
	oid objid_snmptrap[] = { 1, 3, 6, 1, 6, 3, 1, 1, 4, 1, 0 };
	size_t objid_snmptrap_len = OID_LENGTH(objid_snmptrap);
	oid client3FramerFsmms_oid[]   = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 2, 2, 1, 7, 1, 55 };
	size_t client3FramerFsmms_oid_len = OID_LENGTH(client3FramerFsmms_oid);
	oid      client3FramerFsmmsAlarmSev_oid[]   = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 3, 6, 4, 1, 2 };
	size_t   client3FramerFsmmsAlarmSev_oid_len = OID_LENGTH(client3FramerFsmmsAlarmSev_oid);

	netsnmp_variable_list *notification_vars = NULL;
	static u_long client3FramerFsmmsCount = 0;

	unsigned int client3FramerFsmmsAlarm = 0;

	unsigned int client3FramerFsmms = 0;
	client3FramerFsmms = pt_monitor_struct->tp_defects_struct.tp_client_framer_status[2].fields.fsmms;

	unsigned int client3FramerFsmmsAlarmSev = 0;
	client3FramerFsmmsAlarmSev = pt_monitor_struct->tp_defects_struct.severity.severity_client[2].FramerFsmms;

	unsigned int send_client3FramerFsmmsAlarm = 0;
	if (client3FramerFsmmsTemp==0 && client3FramerFsmms==1)
   {
		client3FramerFsmmsAlarm = 1;
		send_client3FramerFsmmsAlarm = 1;
   }
   else if (client3FramerFsmmsTemp==1 && client3FramerFsmms==0)
   {
	   client3FramerFsmmsAlarm = 2;
      send_client3FramerFsmmsAlarm = 1;
   }
	client3FramerFsmmsTemp = client3FramerFsmms;

	snmp_varlist_add_variable(&notification_vars, objid_snmptrap, objid_snmptrap_len, ASN_OBJECT_ID, (u_char *) notification_oid, notification_oid_len * sizeof(oid));
	snmp_varlist_add_variable(&notification_vars, client3FramerFsmms_oid, client3FramerFsmms_oid_len, ASN_INTEGER, (u_char *)&client3FramerFsmmsAlarm, sizeof(client3FramerFsmmsAlarm));
	snmp_varlist_add_variable(&notification_vars, client3FramerFsmmsAlarmSev_oid, client3FramerFsmmsAlarmSev_oid_len, ASN_INTEGER, (u_char *)&client3FramerFsmmsAlarmSev, sizeof(client3FramerFsmmsAlarmSev));

	if(send_client3FramerFsmmsAlarm == 1)
	{
		++client3FramerFsmmsCount;
		DEBUGMSGTL(("ftnc_notifications", "sending trap %ld\n",client3FramerFsmmsCount));
		send_v2trap(notification_vars);
	}

	snmp_free_varbind(notification_vars);
}

void send_tp_client3FramerFssusts_notification(unsigned int clientreg, void *clientarg)
{
	DEBUGMSGTL(("token", "send_tp_client3FramerFssusts_notification.\n"));

	oid notification_oid[] = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 2, 2, 0, 137 };
	size_t notification_oid_len = OID_LENGTH(notification_oid);
	oid objid_snmptrap[] = { 1, 3, 6, 1, 6, 3, 1, 1, 4, 1, 0 };
	size_t objid_snmptrap_len = OID_LENGTH(objid_snmptrap);
	oid client3FramerFssusts_oid[]   = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 2, 2, 1, 7, 1, 56 };
	size_t client3FramerFssusts_oid_len = OID_LENGTH(client3FramerFssusts_oid);
	oid      client3FramerFssustsAlarmSev_oid[]   = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 3, 6, 4, 1, 3 };
	size_t   client3FramerFssustsAlarmSev_oid_len = OID_LENGTH(client3FramerFssustsAlarmSev_oid);

	netsnmp_variable_list *notification_vars = NULL;
	static u_long client3FramerFssustsCount = 0;

	unsigned int client3FramerFssustsAlarm = 0;

	unsigned int client3FramerFssusts = 0;
	client3FramerFssusts = pt_monitor_struct->tp_defects_struct.tp_client_framer_status[2].fields.fsusts;

	unsigned int client3FramerFssustsAlarmSev = 0;
	client3FramerFssustsAlarmSev = pt_monitor_struct->tp_defects_struct.severity.severity_client[2].FramerFssusts;

	unsigned int send_client3FramerFssustsAlarm = 0;
	if (client3FramerFssustsTemp==0 && client3FramerFssusts==1)
   {
		client3FramerFssustsAlarm = 1;
		send_client3FramerFssustsAlarm = 1;
   }
   else if (client3FramerFssustsTemp==1 && client3FramerFssusts==0)
   {
	   client3FramerFssustsAlarm = 2;
      send_client3FramerFssustsAlarm = 1;
   }
	client3FramerFssustsTemp = client3FramerFssusts;

	snmp_varlist_add_variable(&notification_vars, objid_snmptrap, objid_snmptrap_len, ASN_OBJECT_ID, (u_char *) notification_oid, notification_oid_len * sizeof(oid));
	snmp_varlist_add_variable(&notification_vars, client3FramerFssusts_oid, client3FramerFssusts_oid_len, ASN_INTEGER, (u_char *)&client3FramerFssustsAlarm, sizeof(client3FramerFssustsAlarm));
	snmp_varlist_add_variable(&notification_vars, client3FramerFssustsAlarmSev_oid, client3FramerFssustsAlarmSev_oid_len, ASN_INTEGER, (u_char *)&client3FramerFssustsAlarmSev, sizeof(client3FramerFssustsAlarmSev));

	if(send_client3FramerFssustsAlarm == 1)
	{
		++client3FramerFssustsCount;
		DEBUGMSGTL(("ftnc_notifications", "sending trap %ld\n",client3FramerFssustsCount));
		send_v2trap(notification_vars);
	}

	snmp_free_varbind(notification_vars);
}

void send_tp_client3FramerSif_notification(unsigned int clientreg, void *clientarg)
{
	DEBUGMSGTL(("token", "send_tp_client3FramerSif_notification.\n"));

	oid notification_oid[] = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 2, 2, 0, 138 };
	size_t notification_oid_len = OID_LENGTH(notification_oid);
	oid objid_snmptrap[] = { 1, 3, 6, 1, 6, 3, 1, 1, 4, 1, 0 };
	size_t objid_snmptrap_len = OID_LENGTH(objid_snmptrap);
	oid client3FramerSif_oid[]   = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 2, 2, 1, 7, 1, 57 };
	size_t client3FramerSif_oid_len = OID_LENGTH(client3FramerSif_oid);
	oid      client3FramerSifAlarmSev_oid[]   = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 3, 6, 4, 1, 6 };
	size_t   client3FramerSifAlarmSev_oid_len = OID_LENGTH(client3FramerSifAlarmSev_oid);

	netsnmp_variable_list *notification_vars = NULL;
	static u_long client3FramerSifCount = 0;

	unsigned int client3FramerSifAlarm = 0;

	unsigned int client3FramerSif = 0;
	client3FramerSif = pt_monitor_struct->tp_defects_struct.tp_client_framer_status[2].fields.sif;

	unsigned int client3FramerSifAlarmSev = 0;
	client3FramerSifAlarmSev = pt_monitor_struct->tp_defects_struct.severity.severity_client[2].FramerSif;

	unsigned int send_client3FramerSifAlarm = 0;
	if (client3FramerSifTemp==0 && client3FramerSif==1)
   {
		client3FramerSifAlarm = 1;
		send_client3FramerSifAlarm = 1;
   }
   else if (client3FramerSifTemp==1 && client3FramerSif==0)
   {
	   client3FramerSifAlarm = 2;
      send_client3FramerSifAlarm = 1;
   }
	client3FramerSifTemp = client3FramerSif;

	snmp_varlist_add_variable(&notification_vars, objid_snmptrap, objid_snmptrap_len, ASN_OBJECT_ID, (u_char *) notification_oid, notification_oid_len * sizeof(oid));
	snmp_varlist_add_variable(&notification_vars, client3FramerSif_oid, client3FramerSif_oid_len, ASN_INTEGER, (u_char *)&client3FramerSifAlarm, sizeof(client3FramerSifAlarm));
	snmp_varlist_add_variable(&notification_vars, client3FramerSifAlarmSev_oid, client3FramerSifAlarmSev_oid_len, ASN_INTEGER, (u_char *)&client3FramerSifAlarmSev, sizeof(client3FramerSifAlarmSev));

	if(send_client3FramerSifAlarm == 1)
	{
		++client3FramerSifCount;
		DEBUGMSGTL(("ftnc_notifications", "sending trap %ld\n",client3FramerSifCount));
		send_v2trap(notification_vars);
	}

	snmp_free_varbind(notification_vars);
}

void send_tp_client3FramerSoof_notification(unsigned int clientreg, void *clientarg)
{
	DEBUGMSGTL(("token", "send_tp_client3FramerSoof_notification.\n"));

	oid notification_oid[] = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 2, 2, 0, 139 };
	size_t notification_oid_len = OID_LENGTH(notification_oid);
	oid objid_snmptrap[] = { 1, 3, 6, 1, 6, 3, 1, 1, 4, 1, 0 };
	size_t objid_snmptrap_len = OID_LENGTH(objid_snmptrap);
	oid client3FramerSoof_oid[]   = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 2, 2, 1, 7, 1, 58 };
	size_t client3FramerSoof_oid_len = OID_LENGTH(client3FramerSoof_oid);
	oid      client3FramerSoofAlarmSev_oid[]   = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 3, 6, 4, 1, 4 };
	size_t   client3FramerSoofAlarmSev_oid_len = OID_LENGTH(client3FramerSoofAlarmSev_oid);

	netsnmp_variable_list *notification_vars = NULL;
	static u_long client3FramerSoofCount = 0;

	unsigned int client3FramerSoofAlarm = 0;

	unsigned int client3FramerSoof = 0;
	client3FramerSoof = pt_monitor_struct->tp_defects_struct.tp_client_framer_status[2].fields.soof;

	unsigned int client3FramerSoofAlarmSev = 0;
	client3FramerSoofAlarmSev = pt_monitor_struct->tp_defects_struct.severity.severity_client[2].FramerSoof;

	unsigned int send_client3FramerSoofAlarm = 0;
	if (client3FramerSoofTemp==0 && client3FramerSoof==1)
   {
		client3FramerSoofAlarm = 1;
		send_client3FramerSoofAlarm = 1;
   }
   else if (client3FramerSoofTemp==1 && client3FramerSoof==0)
   {
	   client3FramerSoofAlarm = 2;
      send_client3FramerSoofAlarm = 1;
   }
	client3FramerSoofTemp = client3FramerSoof;

	snmp_varlist_add_variable(&notification_vars, objid_snmptrap, objid_snmptrap_len, ASN_OBJECT_ID, (u_char *) notification_oid, notification_oid_len * sizeof(oid));
	snmp_varlist_add_variable(&notification_vars, client3FramerSoof_oid, client3FramerSoof_oid_len, ASN_INTEGER, (u_char *)&client3FramerSoofAlarm, sizeof(client3FramerSoofAlarm));
	snmp_varlist_add_variable(&notification_vars, client3FramerSoofAlarmSev_oid, client3FramerSoofAlarmSev_oid_len, ASN_INTEGER, (u_char *)&client3FramerSoofAlarmSev, sizeof(client3FramerSoofAlarmSev));

	if(send_client3FramerSoofAlarm == 1)
	{
		++client3FramerSoofCount;
		DEBUGMSGTL(("ftnc_notifications", "sending trap %ld\n",client3FramerSoofCount));
		send_v2trap(notification_vars);
	}

	snmp_free_varbind(notification_vars);
}

void send_tp_client3FramerSlof_notification(unsigned int clientreg, void *clientarg)
{
	DEBUGMSGTL(("token", "send_tp_client3FramerSlof_notification.\n"));

	oid notification_oid[] = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 2, 2, 0, 140 };
	size_t notification_oid_len = OID_LENGTH(notification_oid);
	oid objid_snmptrap[] = { 1, 3, 6, 1, 6, 3, 1, 1, 4, 1, 0 };
	size_t objid_snmptrap_len = OID_LENGTH(objid_snmptrap);
	oid client3FramerSlof_oid[]   = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 2, 2, 1, 7, 1, 59 };
	size_t client3FramerSlof_oid_len = OID_LENGTH(client3FramerSlof_oid);
	oid      client3FramerSlofAlarmSev_oid[]   = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 3, 6, 4, 1, 5 };
	size_t   client3FramerSlofAlarmSev_oid_len = OID_LENGTH(client3FramerSlofAlarmSev_oid);

	netsnmp_variable_list *notification_vars = NULL;
	static u_long client3FramerSlofCount = 0;

	unsigned int client3FramerSlofAlarm = 0;

	unsigned int client3FramerSlof = 0;
	client3FramerSlof = pt_monitor_struct->tp_defects_struct.tp_client_framer_status[2].fields.slof;

	unsigned int client3FramerSlofAlarmSev = 0;
	client3FramerSlofAlarmSev = pt_monitor_struct->tp_defects_struct.severity.severity_client[2].FramerSlof;

	unsigned int send_client3FramerSlofAlarm = 0;
	if (client3FramerSlofTemp==0 && client3FramerSlof==1)
   {
		client3FramerSlofAlarm = 1;
		send_client3FramerSlofAlarm = 1;
   }
   else if (client3FramerSlofTemp==1 && client3FramerSlof==0)
   {
	   client3FramerSlofAlarm = 2;
      send_client3FramerSlofAlarm = 1;
   }
	client3FramerSlofTemp = client3FramerSlof;

	snmp_varlist_add_variable(&notification_vars, objid_snmptrap, objid_snmptrap_len, ASN_OBJECT_ID, (u_char *) notification_oid, notification_oid_len * sizeof(oid));
	snmp_varlist_add_variable(&notification_vars, client3FramerSlof_oid, client3FramerSlof_oid_len, ASN_INTEGER, (u_char *)&client3FramerSlofAlarm, sizeof(client3FramerSlofAlarm));
	snmp_varlist_add_variable(&notification_vars, client3FramerSlofAlarmSev_oid, client3FramerSlofAlarmSev_oid_len, ASN_INTEGER, (u_char *)&client3FramerSlofAlarmSev, sizeof(client3FramerSlofAlarmSev));

	if(send_client3FramerSlofAlarm == 1)
	{
		++client3FramerSlofCount;
		DEBUGMSGTL(("ftnc_notifications", "sending trap %ld\n",client3FramerSlofCount));
		send_v2trap(notification_vars);
	}

	snmp_free_varbind(notification_vars);
}

void send_tp_client3FramerFst_notification(unsigned int clientreg, void *clientarg)
{
	DEBUGMSGTL(("token", "send_tp_client3FramerFst_notification.\n"));

	oid notification_oid[] = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 2, 2, 0, 141 };
	size_t notification_oid_len = OID_LENGTH(notification_oid);
	oid objid_snmptrap[] = { 1, 3, 6, 1, 6, 3, 1, 1, 4, 1, 0 };
	size_t objid_snmptrap_len = OID_LENGTH(objid_snmptrap);
	oid client3FramerFst_oid[]   = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 2, 2, 1, 7, 1, 60 };
	size_t client3FramerFst_oid_len = OID_LENGTH(client3FramerFst_oid);
	oid      client3FramerFstAlarmSev_oid[]   = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 3, 6, 4, 1, 7 };
	size_t   client3FramerFstAlarmSev_oid_len = OID_LENGTH(client3FramerFstAlarmSev_oid);

	netsnmp_variable_list *notification_vars = NULL;
	static u_long client3FramerFstCount = 0;

	unsigned int client3FramerFstAlarm = 0;

	unsigned int client3FramerFst = 0;
	client3FramerFst = pt_monitor_struct->tp_defects_struct.tp_client_framer_status[2].fields.fst;

	unsigned int client3FramerFstAlarmSev = 0;
	client3FramerFstAlarmSev = pt_monitor_struct->tp_defects_struct.severity.severity_client[2].FramerFst;

	unsigned int send_client3FramerFstAlarm = 0;
	if (client3FramerFstTemp==0 && client3FramerFst==1)
   {
		client3FramerFstAlarm = 1;
		send_client3FramerFstAlarm = 1;
   }
   else if (client3FramerFstTemp==1 && client3FramerFst==0)
   {
	   client3FramerFstAlarm = 2;
      send_client3FramerFstAlarm = 1;
   }
	client3FramerFstTemp = client3FramerFst;

	snmp_varlist_add_variable(&notification_vars, objid_snmptrap, objid_snmptrap_len, ASN_OBJECT_ID, (u_char *) notification_oid, notification_oid_len * sizeof(oid));
	snmp_varlist_add_variable(&notification_vars, client3FramerFst_oid, client3FramerFst_oid_len, ASN_INTEGER, (u_char *)&client3FramerFstAlarm, sizeof(client3FramerFstAlarm));
	snmp_varlist_add_variable(&notification_vars, client3FramerFstAlarmSev_oid, client3FramerFstAlarmSev_oid_len, ASN_INTEGER, (u_char *)&client3FramerFstAlarmSev, sizeof(client3FramerFstAlarmSev));

	if(send_client3FramerFstAlarm == 1)
	{
		++client3FramerFstCount;
		DEBUGMSGTL(("ftnc_notifications", "sending trap %ld\n",client3FramerFstCount));
		send_v2trap(notification_vars);
	}

	snmp_free_varbind(notification_vars);
}

void send_tp_client3LosstatLosf_notification(unsigned int clientreg, void *clientarg)
{
	DEBUGMSGTL(("token", "send_tp_client3LosstatLosf_notification.\n"));

	oid notification_oid[] = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 2, 2, 0, 142 };
	size_t notification_oid_len = OID_LENGTH(notification_oid);
	oid objid_snmptrap[] = { 1, 3, 6, 1, 6, 3, 1, 1, 4, 1, 0 };
	size_t objid_snmptrap_len = OID_LENGTH(objid_snmptrap);
	oid client3LosstatLosf_oid[]   = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 2, 2, 1, 7, 1, 61 };
	size_t client3LosstatLosf_oid_len = OID_LENGTH(client3LosstatLosf_oid);
	oid      client3LosstatLosfAlarmSev_oid[]   = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 3, 6, 4, 1, 8 };
	size_t   client3LosstatLosfAlarmSev_oid_len = OID_LENGTH(client3LosstatLosfAlarmSev_oid);

	netsnmp_variable_list *notification_vars = NULL;
	static u_long client3LosstatLosfCount = 0;

	unsigned int client3LosstatLosfAlarm = 0;

	unsigned int client3LosstatLosf = 0;
	client3LosstatLosf = pt_monitor_struct->tp_defects_struct.tp_client_los_status[2].fields.losf;

	unsigned int client3LosstatLosfAlarmSev = 0;
	client3LosstatLosfAlarmSev = pt_monitor_struct->tp_defects_struct.severity.severity_client[2].LosstatLosf;

	unsigned int send_client3LosstatLosfAlarm = 0;
	if (client3LosstatLosfTemp==0 && client3LosstatLosf==1)
   {
		client3LosstatLosfAlarm = 1;
		send_client3LosstatLosfAlarm = 1;
   }
   else if (client3LosstatLosfTemp==1 && client3LosstatLosf==0)
   {
	   client3LosstatLosfAlarm = 2;
      send_client3LosstatLosfAlarm = 1;
   }
	client3LosstatLosfTemp = client3LosstatLosf;

	snmp_varlist_add_variable(&notification_vars, objid_snmptrap, objid_snmptrap_len, ASN_OBJECT_ID, (u_char *) notification_oid, notification_oid_len * sizeof(oid));
	snmp_varlist_add_variable(&notification_vars, client3LosstatLosf_oid, client3LosstatLosf_oid_len, ASN_INTEGER, (u_char *)&client3LosstatLosfAlarm, sizeof(client3LosstatLosfAlarm));
	snmp_varlist_add_variable(&notification_vars, client3LosstatLosfAlarmSev_oid, client3LosstatLosfAlarmSev_oid_len, ASN_INTEGER, (u_char *)&client3LosstatLosfAlarmSev, sizeof(client3LosstatLosfAlarmSev));

	if(send_client3LosstatLosfAlarm == 1)
	{
		++client3LosstatLosfCount;
		DEBUGMSGTL(("ftnc_notifications", "sending trap %ld\n",client3LosstatLosfCount));
		send_v2trap(notification_vars);
	}

	snmp_free_varbind(notification_vars);
}

void send_tp_client3SecmonFlom_notification(unsigned int clientreg, void *clientarg)
{
	DEBUGMSGTL(("token", "send_tp_client3SecmonFlom_notification.\n"));

	oid notification_oid[] = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 2, 2, 0, 143 };
	size_t notification_oid_len = OID_LENGTH(notification_oid);
	oid objid_snmptrap[] = { 1, 3, 6, 1, 6, 3, 1, 1, 4, 1, 0 };
	size_t objid_snmptrap_len = OID_LENGTH(objid_snmptrap);
	oid client3SecmonFlom_oid[]   = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 2, 2, 1, 7, 1, 62 };
	size_t client3SecmonFlom_oid_len = OID_LENGTH(client3SecmonFlom_oid);
	oid      client3SecmonFlomAlarmSev_oid[]   = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 3, 6, 4, 1, 17 };
	size_t   client3SecmonFlomAlarmSev_oid_len = OID_LENGTH(client3SecmonFlomAlarmSev_oid);

	netsnmp_variable_list *notification_vars = NULL;
	static u_long client3SecmonFlomCount = 0;

	unsigned int client3SecmonFlomAlarm = 0;

	unsigned int client3SecmonFlom = 0;
	client3SecmonFlom = pt_monitor_struct->tp_defects_struct.tp_client_section_mon[2].fields.flom;

	unsigned int client3SecmonFlomAlarmSev = 0;
	client3SecmonFlomAlarmSev = pt_monitor_struct->tp_defects_struct.severity.severity_client[2].SecmonFlom;

	unsigned int send_client3SecmonFlomAlarm = 0;
	if (client3SecmonFlomTemp==0 && client3SecmonFlom==1)
   {
		client3SecmonFlomAlarm = 1;
		send_client3SecmonFlomAlarm = 1;
   }
   else if (client3SecmonFlomTemp==1 && client3SecmonFlom==0)
   {
	   client3SecmonFlomAlarm = 2;
      send_client3SecmonFlomAlarm = 1;
   }
	client3SecmonFlomTemp = client3SecmonFlom;

	snmp_varlist_add_variable(&notification_vars, objid_snmptrap, objid_snmptrap_len, ASN_OBJECT_ID, (u_char *) notification_oid, notification_oid_len * sizeof(oid));
	snmp_varlist_add_variable(&notification_vars, client3SecmonFlom_oid, client3SecmonFlom_oid_len, ASN_INTEGER, (u_char *)&client3SecmonFlomAlarm, sizeof(client3SecmonFlomAlarm));
	snmp_varlist_add_variable(&notification_vars, client3SecmonFlomAlarmSev_oid, client3SecmonFlomAlarmSev_oid_len, ASN_INTEGER, (u_char *)&client3SecmonFlomAlarmSev, sizeof(client3SecmonFlomAlarmSev));

	if(send_client3SecmonFlomAlarm == 1)
	{
		++client3SecmonFlomCount;
		DEBUGMSGTL(("ftnc_notifications", "sending trap %ld\n",client3SecmonFlomCount));
		send_v2trap(notification_vars);
	}

	snmp_free_varbind(notification_vars);
}

void send_tp_client3SecmonBipsfs_notification(unsigned int clientreg, void *clientarg)
{
	DEBUGMSGTL(("token", "send_tp_client3SecmonBipsfs_notification.\n"));

	oid notification_oid[] = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 2, 2, 0, 144 };
	size_t notification_oid_len = OID_LENGTH(notification_oid);
	oid objid_snmptrap[] = { 1, 3, 6, 1, 6, 3, 1, 1, 4, 1, 0 };
	size_t objid_snmptrap_len = OID_LENGTH(objid_snmptrap);
	oid client3SecmonBipsfs_oid[]   = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 2, 2, 1, 7, 1, 63 };
	size_t client3SecmonBipsfs_oid_len = OID_LENGTH(client3SecmonBipsfs_oid);
	oid      client3SecmonBipsfsAlarmSev_oid[]   = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 3, 6, 4, 1, 14 };
	size_t   client3SecmonBipsfsAlarmSev_oid_len = OID_LENGTH(client3SecmonBipsfsAlarmSev_oid);

	netsnmp_variable_list *notification_vars = NULL;
	static u_long client3SecmonBipsfsCount = 0;

	unsigned int client3SecmonBipsfsAlarm = 0;

	unsigned int client3SecmonBipsfs = 0;
	client3SecmonBipsfs = pt_monitor_struct->tp_defects_struct.tp_client_section_mon[2].fields.bipsfs;

	unsigned int client3SecmonBipsfsAlarmSev = 0;
	client3SecmonBipsfsAlarmSev = pt_monitor_struct->tp_defects_struct.severity.severity_client[2].SecmonBipsfs;

	unsigned int send_client3SecmonBipsfsAlarm = 0;
	if (client3SecmonBipsfsTemp==0 && client3SecmonBipsfs==1)
   {
		client3SecmonBipsfsAlarm = 1;
		send_client3SecmonBipsfsAlarm = 1;
   }
   else if (client3SecmonBipsfsTemp==1 && client3SecmonBipsfs==0)
   {
	   client3SecmonBipsfsAlarm = 2;
      send_client3SecmonBipsfsAlarm = 1;
   }
	client3SecmonBipsfsTemp = client3SecmonBipsfs;

	snmp_varlist_add_variable(&notification_vars, objid_snmptrap, objid_snmptrap_len, ASN_OBJECT_ID, (u_char *) notification_oid, notification_oid_len * sizeof(oid));
	snmp_varlist_add_variable(&notification_vars, client3SecmonBipsfs_oid, client3SecmonBipsfs_oid_len, ASN_INTEGER, (u_char *)&client3SecmonBipsfsAlarm, sizeof(client3SecmonBipsfsAlarm));
	snmp_varlist_add_variable(&notification_vars, client3SecmonBipsfsAlarmSev_oid, client3SecmonBipsfsAlarmSev_oid_len, ASN_INTEGER, (u_char *)&client3SecmonBipsfsAlarmSev, sizeof(client3SecmonBipsfsAlarmSev));

	if(send_client3SecmonBipsfsAlarm == 1)
	{
		++client3SecmonBipsfsCount;
		DEBUGMSGTL(("ftnc_notifications", "sending trap %ld\n",client3SecmonBipsfsCount));
		send_v2trap(notification_vars);
	}

	snmp_free_varbind(notification_vars);
}

void send_tp_client3SecmonDiae_notification(unsigned int clientreg, void *clientarg)
{
	DEBUGMSGTL(("token", "send_tp_client3SecmonDiae_notification.\n"));

	oid notification_oid[] = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 2, 2, 0, 145 };
	size_t notification_oid_len = OID_LENGTH(notification_oid);
	oid objid_snmptrap[] = { 1, 3, 6, 1, 6, 3, 1, 1, 4, 1, 0 };
	size_t objid_snmptrap_len = OID_LENGTH(objid_snmptrap);
	oid client3SecmonDiae_oid[]   = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 2, 2, 1, 7, 1, 64 };
	size_t client3SecmonDiae_oid_len = OID_LENGTH(client3SecmonDiae_oid);
	oid      client3SecmonDiaeAlarmSev_oid[]   = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 3, 6, 4, 1, 16 };
	size_t   client3SecmonDiaeAlarmSev_oid_len = OID_LENGTH(client3SecmonDiaeAlarmSev_oid);

	netsnmp_variable_list *notification_vars = NULL;
	static u_long client3SecmonDiaeCount = 0;

	unsigned int client3SecmonDiaeAlarm = 0;

	unsigned int client3SecmonDiae = 0;
	client3SecmonDiae = pt_monitor_struct->tp_defects_struct.tp_client_section_mon[2].fields.diae;

	unsigned int client3SecmonDiaeAlarmSev = 0;
	client3SecmonDiaeAlarmSev = pt_monitor_struct->tp_defects_struct.severity.severity_client[2].SecmonDiae;

	unsigned int send_client3SecmonDiaeAlarm = 0;
	if (client3SecmonDiaeTemp==0 && client3SecmonDiae==1)
   {
		client3SecmonDiaeAlarm = 1;
		send_client3SecmonDiaeAlarm = 1;
   }
   else if (client3SecmonDiaeTemp==1 && client3SecmonDiae==0)
   {
	   client3SecmonDiaeAlarm = 2;
      send_client3SecmonDiaeAlarm = 1;
   }
	client3SecmonDiaeTemp = client3SecmonDiae;

	snmp_varlist_add_variable(&notification_vars, objid_snmptrap, objid_snmptrap_len, ASN_OBJECT_ID, (u_char *) notification_oid, notification_oid_len * sizeof(oid));
	snmp_varlist_add_variable(&notification_vars, client3SecmonDiae_oid, client3SecmonDiae_oid_len, ASN_INTEGER, (u_char *)&client3SecmonDiaeAlarm, sizeof(client3SecmonDiaeAlarm));
	snmp_varlist_add_variable(&notification_vars, client3SecmonDiaeAlarmSev_oid, client3SecmonDiaeAlarmSev_oid_len, ASN_INTEGER, (u_char *)&client3SecmonDiaeAlarmSev, sizeof(client3SecmonDiaeAlarmSev));

	if(send_client3SecmonDiaeAlarm == 1)
	{
		++client3SecmonDiaeCount;
		DEBUGMSGTL(("ftnc_notifications", "sending trap %ld\n",client3SecmonDiaeCount));
		send_v2trap(notification_vars);
	}

	snmp_free_varbind(notification_vars);
}

void send_tp_client3SecmonDbdi_notification(unsigned int clientreg, void *clientarg)
{
	DEBUGMSGTL(("token", "send_tp_client3SecmonDbdi_notification.\n"));

	oid notification_oid[] = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 2, 2, 0, 146 };
	size_t notification_oid_len = OID_LENGTH(notification_oid);
	oid objid_snmptrap[] = { 1, 3, 6, 1, 6, 3, 1, 1, 4, 1, 0 };
	size_t objid_snmptrap_len = OID_LENGTH(objid_snmptrap);
	oid client3SecmonDbdi_oid[]   = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 2, 2, 1, 7, 1, 65 };
	size_t client3SecmonDbdi_oid_len = OID_LENGTH(client3SecmonDbdi_oid);
	oid      client3SecmonDbdiAlarmSev_oid[]   = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 3, 6, 4, 1, 15 };
	size_t   client3SecmonDbdiAlarmSev_oid_len = OID_LENGTH(client3SecmonDbdiAlarmSev_oid);

	netsnmp_variable_list *notification_vars = NULL;
	static u_long client3SecmonDbdiCount = 0;

	unsigned int client3SecmonDbdiAlarm = 0;

	unsigned int client3SecmonDbdi = 0;
	client3SecmonDbdi = pt_monitor_struct->tp_defects_struct.tp_client_section_mon[2].fields.dbdi;

	unsigned int client3SecmonDbdiAlarmSev = 0;
	client3SecmonDbdiAlarmSev = pt_monitor_struct->tp_defects_struct.severity.severity_client[2].SecmonDbdi;

	unsigned int send_client3SecmonDbdiAlarm = 0;
	if (client3SecmonDbdiTemp==0 && client3SecmonDbdi==1)
   {
		client3SecmonDbdiAlarm = 1;
		send_client3SecmonDbdiAlarm = 1;
   }
   else if (client3SecmonDbdiTemp==1 && client3SecmonDbdi==0)
   {
	   client3SecmonDbdiAlarm = 2;
      send_client3SecmonDbdiAlarm = 1;
   }
	client3SecmonDbdiTemp = client3SecmonDbdi;

	snmp_varlist_add_variable(&notification_vars, objid_snmptrap, objid_snmptrap_len, ASN_OBJECT_ID, (u_char *) notification_oid, notification_oid_len * sizeof(oid));
	snmp_varlist_add_variable(&notification_vars, client3SecmonDbdi_oid, client3SecmonDbdi_oid_len, ASN_INTEGER, (u_char *)&client3SecmonDbdiAlarm, sizeof(client3SecmonDbdiAlarm));
	snmp_varlist_add_variable(&notification_vars, client3SecmonDbdiAlarmSev_oid, client3SecmonDbdiAlarmSev_oid_len, ASN_INTEGER, (u_char *)&client3SecmonDbdiAlarmSev, sizeof(client3SecmonDbdiAlarmSev));

	if(send_client3SecmonDbdiAlarm == 1)
	{
		++client3SecmonDbdiCount;
		DEBUGMSGTL(("ftnc_notifications", "sending trap %ld\n",client3SecmonDbdiCount));
		send_v2trap(notification_vars);
	}

	snmp_free_varbind(notification_vars);
}

void send_tp_client3SecmonLom_notification(unsigned int clientreg, void *clientarg)
{
	DEBUGMSGTL(("token", "send_tp_client3SecmonLom_notification.\n"));

	oid notification_oid[] = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 2, 2, 0, 147 };
	size_t notification_oid_len = OID_LENGTH(notification_oid);
	oid objid_snmptrap[] = { 1, 3, 6, 1, 6, 3, 1, 1, 4, 1, 0 };
	size_t objid_snmptrap_len = OID_LENGTH(objid_snmptrap);
	oid client3SecmonLom_oid[]   = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 2, 2, 1, 7, 1, 66 };
	size_t client3SecmonLom_oid_len = OID_LENGTH(client3SecmonLom_oid);
	oid      client3SecmonLomAlarmSev_oid[]   = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 3, 6, 4, 1, 18 };
	size_t   client3SecmonLomAlarmSev_oid_len = OID_LENGTH(client3SecmonLomAlarmSev_oid);

	netsnmp_variable_list *notification_vars = NULL;
	static u_long client3SecmonLomCount = 0;

	unsigned int client3SecmonLomAlarm = 0;

	unsigned int client3SecmonLom = 0;
	client3SecmonLom = pt_monitor_struct->tp_defects_struct.tp_client_section_mon[2].fields.lom;

	unsigned int client3SecmonLomAlarmSev = 0;
	client3SecmonLomAlarmSev = pt_monitor_struct->tp_defects_struct.severity.severity_client[2].SecmonLom;

	unsigned int send_client3SecmonLomAlarm = 0;
	if (client3SecmonLomTemp==0 && client3SecmonLom==1)
   {
		client3SecmonLomAlarm = 1;
		send_client3SecmonLomAlarm = 1;
   }
   else if (client3SecmonLomTemp==1 && client3SecmonLom==0)
   {
	   client3SecmonLomAlarm = 2;
      send_client3SecmonLomAlarm = 1;
   }
	client3SecmonLomTemp = client3SecmonLom;

	snmp_varlist_add_variable(&notification_vars, objid_snmptrap, objid_snmptrap_len, ASN_OBJECT_ID, (u_char *) notification_oid, notification_oid_len * sizeof(oid));
	snmp_varlist_add_variable(&notification_vars, client3SecmonLom_oid, client3SecmonLom_oid_len, ASN_INTEGER, (u_char *)&client3SecmonLomAlarm, sizeof(client3SecmonLomAlarm));
	snmp_varlist_add_variable(&notification_vars, client3SecmonLomAlarmSev_oid, client3SecmonLomAlarmSev_oid_len, ASN_INTEGER, (u_char *)&client3SecmonLomAlarmSev, sizeof(client3SecmonLomAlarmSev));

	if(send_client3SecmonLomAlarm == 1)
	{
		++client3SecmonLomCount;
		DEBUGMSGTL(("ftnc_notifications", "sending trap %ld\n",client3SecmonLomCount));
		send_v2trap(notification_vars);
	}

	snmp_free_varbind(notification_vars);
}

void send_tp_client3PathmonAccstat_notification(unsigned int clientreg, void *clientarg)
{
	DEBUGMSGTL(("token", "send_tp_client3PathmonAccstat_notification.\n"));

	oid notification_oid[] = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 2, 2, 0, 148 };
	size_t notification_oid_len = OID_LENGTH(notification_oid);
	oid objid_snmptrap[] = { 1, 3, 6, 1, 6, 3, 1, 1, 4, 1, 0 };
	size_t objid_snmptrap_len = OID_LENGTH(objid_snmptrap);
	oid client3PathmonAccstat_oid[]   = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 2, 2, 1, 7, 1, 67 };
	size_t client3PathmonAccstat_oid_len = OID_LENGTH(client3PathmonAccstat_oid);
	oid      client3PathmonAccstatAlarmSev_oid[]   = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 3, 6, 4, 1, 9 };
	size_t   client3PathmonAccstatAlarmSev_oid_len = OID_LENGTH(client3PathmonAccstatAlarmSev_oid);

	netsnmp_variable_list *notification_vars = NULL;
	static u_long client3PathmonAccstatCount = 0;

	unsigned int client3PathmonAccstatAlarm = 0;

	unsigned int client3PathmonAccstat = 0;
	client3PathmonAccstat = pt_monitor_struct->tp_defects_struct.tp_client_path_mon[2].fields.accstat;

	unsigned int client3PathmonAccstatAlarmSev = 0;
	client3PathmonAccstatAlarmSev = pt_monitor_struct->tp_defects_struct.severity.severity_client[2].PathmonAccstat;

	unsigned int send_client3PathmonAccstatAlarm = 0;
	if (client3PathmonAccstatTemp==0 && client3PathmonAccstat==1)
   {
		client3PathmonAccstatAlarm = 1;
		send_client3PathmonAccstatAlarm = 1;
   }
   else if (client3PathmonAccstatTemp==1 && client3PathmonAccstat==0)
   {
	   client3PathmonAccstatAlarm = 2;
      send_client3PathmonAccstatAlarm = 1;
   }
	client3PathmonAccstatTemp = client3PathmonAccstat;

	snmp_varlist_add_variable(&notification_vars, objid_snmptrap, objid_snmptrap_len, ASN_OBJECT_ID, (u_char *) notification_oid, notification_oid_len * sizeof(oid));
	snmp_varlist_add_variable(&notification_vars, client3PathmonAccstat_oid, client3PathmonAccstat_oid_len, ASN_INTEGER, (u_char *)&client3PathmonAccstatAlarm, sizeof(client3PathmonAccstatAlarm));
	snmp_varlist_add_variable(&notification_vars, client3PathmonAccstatAlarmSev_oid, client3PathmonAccstatAlarmSev_oid_len, ASN_INTEGER, (u_char *)&client3PathmonAccstatAlarmSev, sizeof(client3PathmonAccstatAlarmSev));

	if(send_client3PathmonAccstatAlarm == 1)
	{
		++client3PathmonAccstatCount;
		DEBUGMSGTL(("ftnc_notifications", "sending trap %ld\n",client3PathmonAccstatCount));
		send_v2trap(notification_vars);
	}

	snmp_free_varbind(notification_vars);
}

void send_tp_client3PathmonMsiunst_notification(unsigned int clientreg, void *clientarg)
{
	DEBUGMSGTL(("token", "send_tp_client3PathmonMsiunst_notification.\n"));

	oid notification_oid[] = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 2, 2, 0, 149 };
	size_t notification_oid_len = OID_LENGTH(notification_oid);
	oid objid_snmptrap[] = { 1, 3, 6, 1, 6, 3, 1, 1, 4, 1, 0 };
	size_t objid_snmptrap_len = OID_LENGTH(objid_snmptrap);
	oid client3PathmonMsiunst_oid[]   = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 2, 2, 1, 7, 1, 68 };
	size_t client3PathmonMsiunst_oid_len = OID_LENGTH(client3PathmonMsiunst_oid);
	oid      client3PathmonMsiunstAlarmSev_oid[]   = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 3, 6, 4, 1, 13 };
	size_t   client3PathmonMsiunstAlarmSev_oid_len = OID_LENGTH(client3PathmonMsiunstAlarmSev_oid);

	netsnmp_variable_list *notification_vars = NULL;
	static u_long client3PathmonMsiunstCount = 0;

	unsigned int client3PathmonMsiunstAlarm = 0;

	unsigned int client3PathmonMsiunst = 0;
	client3PathmonMsiunst = pt_monitor_struct->tp_defects_struct.tp_client_path_mon[2].fields.msiunst;

	unsigned int client3PathmonMsiunstAlarmSev = 0;
	client3PathmonMsiunstAlarmSev = pt_monitor_struct->tp_defects_struct.severity.severity_client[2].PathmonMsiunst;

	unsigned int send_client3PathmonMsiunstAlarm = 0;
	if (client3PathmonMsiunstTemp==0 && client3PathmonMsiunst==1)
   {
		client3PathmonMsiunstAlarm = 1;
		send_client3PathmonMsiunstAlarm = 1;
   }
   else if (client3PathmonMsiunstTemp==1 && client3PathmonMsiunst==0)
   {
	   client3PathmonMsiunstAlarm = 2;
      send_client3PathmonMsiunstAlarm = 1;
   }
	client3PathmonMsiunstTemp = client3PathmonMsiunst;

	snmp_varlist_add_variable(&notification_vars, objid_snmptrap, objid_snmptrap_len, ASN_OBJECT_ID, (u_char *) notification_oid, notification_oid_len * sizeof(oid));
	snmp_varlist_add_variable(&notification_vars, client3PathmonMsiunst_oid, client3PathmonMsiunst_oid_len, ASN_INTEGER, (u_char *)&client3PathmonMsiunstAlarm, sizeof(client3PathmonMsiunstAlarm));
	snmp_varlist_add_variable(&notification_vars, client3PathmonMsiunstAlarmSev_oid, client3PathmonMsiunstAlarmSev_oid_len, ASN_INTEGER, (u_char *)&client3PathmonMsiunstAlarmSev, sizeof(client3PathmonMsiunstAlarmSev));

	if(send_client3PathmonMsiunstAlarm == 1)
	{
		++client3PathmonMsiunstCount;
		DEBUGMSGTL(("ftnc_notifications", "sending trap %ld\n",client3PathmonMsiunstCount));
		send_v2trap(notification_vars);
	}

	snmp_free_varbind(notification_vars);
}

void send_tp_client3PathmonDais_notification(unsigned int clientreg, void *clientarg)
{
	DEBUGMSGTL(("token", "send_tp_client3PathmonDais_notification.\n"));

	oid notification_oid[] = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 2, 2, 0, 150 };
	size_t notification_oid_len = OID_LENGTH(notification_oid);
	oid objid_snmptrap[] = { 1, 3, 6, 1, 6, 3, 1, 1, 4, 1, 0 };
	size_t objid_snmptrap_len = OID_LENGTH(objid_snmptrap);
	oid client3PathmonDais_oid[]   = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 2, 2, 1, 7, 1, 69 };
	size_t client3PathmonDais_oid_len = OID_LENGTH(client3PathmonDais_oid);
	oid      client3PathmonDaisAlarmSev_oid[]   = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 3, 6, 4, 1, 10 };
	size_t   client3PathmonDaisAlarmSev_oid_len = OID_LENGTH(client3PathmonDaisAlarmSev_oid);

	netsnmp_variable_list *notification_vars = NULL;
	static u_long client3PathmonDaisCount = 0;

	unsigned int client3PathmonDaisAlarm = 0;

	unsigned int client3PathmonDais = 0;
	client3PathmonDais = pt_monitor_struct->tp_defects_struct.tp_client_path_mon[2].fields.dais;

	unsigned int client3PathmonDaisAlarmSev = 0;
	client3PathmonDaisAlarmSev = pt_monitor_struct->tp_defects_struct.severity.severity_client[2].PathmonDais;

	unsigned int send_client3PathmonDaisAlarm = 0;
	if (client3PathmonDaisTemp==0 && client3PathmonDais==1)
   {
		client3PathmonDaisAlarm = 1;
		send_client3PathmonDaisAlarm = 1;
   }
   else if (client3PathmonDaisTemp==1 && client3PathmonDais==0)
   {
	   client3PathmonDaisAlarm = 2;
      send_client3PathmonDaisAlarm = 1;
   }
	client3PathmonDaisTemp = client3PathmonDais;

	snmp_varlist_add_variable(&notification_vars, objid_snmptrap, objid_snmptrap_len, ASN_OBJECT_ID, (u_char *) notification_oid, notification_oid_len * sizeof(oid));
	snmp_varlist_add_variable(&notification_vars, client3PathmonDais_oid, client3PathmonDais_oid_len, ASN_INTEGER, (u_char *)&client3PathmonDaisAlarm, sizeof(client3PathmonDaisAlarm));
	snmp_varlist_add_variable(&notification_vars, client3PathmonDaisAlarmSev_oid, client3PathmonDaisAlarmSev_oid_len, ASN_INTEGER, (u_char *)&client3PathmonDaisAlarmSev, sizeof(client3PathmonDaisAlarmSev));

	if(send_client3PathmonDaisAlarm == 1)
	{
		++client3PathmonDaisCount;
		DEBUGMSGTL(("ftnc_notifications", "sending trap %ld\n",client3PathmonDaisCount));
		send_v2trap(notification_vars);
	}

	snmp_free_varbind(notification_vars);
}

void send_tp_client3PathmonDlck_notification(unsigned int clientreg, void *clientarg)
{
	DEBUGMSGTL(("token", "send_tp_client3PathmonDlck_notification.\n"));

	oid notification_oid[] = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 2, 2, 0, 151 };
	size_t notification_oid_len = OID_LENGTH(notification_oid);
	oid objid_snmptrap[] = { 1, 3, 6, 1, 6, 3, 1, 1, 4, 1, 0 };
	size_t objid_snmptrap_len = OID_LENGTH(objid_snmptrap);
	oid client3PathmonDlck_oid[]   = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 2, 2, 1, 7, 1, 70 };
	size_t client3PathmonDlck_oid_len = OID_LENGTH(client3PathmonDlck_oid);
	oid      client3PathmonDlckAlarmSev_oid[]   = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 3, 6, 4, 1, 12 };
	size_t   client3PathmonDlckAlarmSev_oid_len = OID_LENGTH(client3PathmonDlckAlarmSev_oid);

	netsnmp_variable_list *notification_vars = NULL;
	static u_long client3PathmonDlckCount = 0;

	unsigned int client3PathmonDlckAlarm = 0;

	unsigned int client3PathmonDlck = 0;
	client3PathmonDlck = pt_monitor_struct->tp_defects_struct.tp_client_path_mon[2].fields.dlck;

	unsigned int client3PathmonDlckAlarmSev = 0;
	client3PathmonDlckAlarmSev = pt_monitor_struct->tp_defects_struct.severity.severity_client[2].PathmonDlck;

	unsigned int send_client3PathmonDlckAlarm = 0;
	if (client3PathmonDlckTemp==0 && client3PathmonDlck==1)
   {
		client3PathmonDlckAlarm = 1;
		send_client3PathmonDlckAlarm = 1;
   }
   else if (client3PathmonDlckTemp==1 && client3PathmonDlck==0)
   {
	   client3PathmonDlckAlarm = 2;
      send_client3PathmonDlckAlarm = 1;
   }
	client3PathmonDlckTemp = client3PathmonDlck;

	snmp_varlist_add_variable(&notification_vars, objid_snmptrap, objid_snmptrap_len, ASN_OBJECT_ID, (u_char *) notification_oid, notification_oid_len * sizeof(oid));
	snmp_varlist_add_variable(&notification_vars, client3PathmonDlck_oid, client3PathmonDlck_oid_len, ASN_INTEGER, (u_char *)&client3PathmonDlckAlarm, sizeof(client3PathmonDlckAlarm));
	snmp_varlist_add_variable(&notification_vars, client3PathmonDlckAlarmSev_oid, client3PathmonDlckAlarmSev_oid_len, ASN_INTEGER, (u_char *)&client3PathmonDlckAlarmSev, sizeof(client3PathmonDlckAlarmSev));

	if(send_client3PathmonDlckAlarm == 1)
	{
		++client3PathmonDlckCount;
		DEBUGMSGTL(("ftnc_notifications", "sending trap %ld\n",client3PathmonDlckCount));
		send_v2trap(notification_vars);
	}

	snmp_free_varbind(notification_vars);
}

void send_tp_client3PathmonDbdi_notification(unsigned int clientreg, void *clientarg)
{
	DEBUGMSGTL(("token", "send_tp_client3PathmonDbdi_notification.\n"));

	oid notification_oid[] = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 2, 2, 0, 152 };
	size_t notification_oid_len = OID_LENGTH(notification_oid);
	oid objid_snmptrap[] = { 1, 3, 6, 1, 6, 3, 1, 1, 4, 1, 0 };
	size_t objid_snmptrap_len = OID_LENGTH(objid_snmptrap);
	oid client3PathmonDbdi_oid[]   = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 2, 2, 1, 7, 1, 71 };
	size_t client3PathmonDbdi_oid_len = OID_LENGTH(client3PathmonDbdi_oid);
	oid      client3PathmonDbdiAlarmSev_oid[]   = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 3, 6, 4, 1, 11 };
	size_t   client3PathmonDbdiAlarmSev_oid_len = OID_LENGTH(client3PathmonDbdiAlarmSev_oid);

	netsnmp_variable_list *notification_vars = NULL;
	static u_long client3PathmonDbdiCount = 0;

	unsigned int client3PathmonDbdiAlarm = 0;

	unsigned int client3PathmonDbdi = 0;
	client3PathmonDbdi = pt_monitor_struct->tp_defects_struct.tp_client_path_mon[2].fields.dbdi;

	unsigned int client3PathmonDbdiAlarmSev = 0;
	client3PathmonDbdiAlarmSev = pt_monitor_struct->tp_defects_struct.severity.severity_client[2].PathmonDbdi;

	unsigned int send_client3PathmonDbdiAlarm = 0;
	if (client3PathmonDbdiTemp==0 && client3PathmonDbdi==1)
   {
		client3PathmonDbdiAlarm = 1;
		send_client3PathmonDbdiAlarm = 1;
   }
   else if (client3PathmonDbdiTemp==1 && client3PathmonDbdi==0)
   {
	   client3PathmonDbdiAlarm = 2;
      send_client3PathmonDbdiAlarm = 1;
   }
	client3PathmonDbdiTemp = client3PathmonDbdi;

	snmp_varlist_add_variable(&notification_vars, objid_snmptrap, objid_snmptrap_len, ASN_OBJECT_ID, (u_char *) notification_oid, notification_oid_len * sizeof(oid));
	snmp_varlist_add_variable(&notification_vars, client3PathmonDbdi_oid, client3PathmonDbdi_oid_len, ASN_INTEGER, (u_char *)&client3PathmonDbdiAlarm, sizeof(client3PathmonDbdiAlarm));
	snmp_varlist_add_variable(&notification_vars, client3PathmonDbdiAlarmSev_oid, client3PathmonDbdiAlarmSev_oid_len, ASN_INTEGER, (u_char *)&client3PathmonDbdiAlarmSev, sizeof(client3PathmonDbdiAlarmSev));

	if(send_client3PathmonDbdiAlarm == 1)
	{
		++client3PathmonDbdiCount;
		DEBUGMSGTL(("ftnc_notifications", "sending trap %ld\n",client3PathmonDbdiCount));
		send_v2trap(notification_vars);
	}

	snmp_free_varbind(notification_vars);
}

//Traffic Processor Client 4 Notifications
void send_tp_client4FramerFsmms_notification(unsigned int clientreg, void *clientarg)
{
	DEBUGMSGTL(("token", "send_tp_client4FramerFsmms_notification.\n"));

	oid notification_oid[] = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 2, 2, 0, 153 };
	size_t notification_oid_len = OID_LENGTH(notification_oid);
	oid objid_snmptrap[] = { 1, 3, 6, 1, 6, 3, 1, 1, 4, 1, 0 };
	size_t objid_snmptrap_len = OID_LENGTH(objid_snmptrap);
	oid client4FramerFsmms_oid[]   = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 2, 2, 1, 7, 1, 72 };
	size_t client4FramerFsmms_oid_len = OID_LENGTH(client4FramerFsmms_oid);
	oid      client4FramerFsmmsAlarmSev_oid[]   = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 3, 6, 5, 1, 2 };
	size_t   client4FramerFsmmsAlarmSev_oid_len = OID_LENGTH(client4FramerFsmmsAlarmSev_oid);

	netsnmp_variable_list *notification_vars = NULL;
	static u_long client4FramerFsmmsCount = 0;

	unsigned int client4FramerFsmmsAlarm = 0;

	unsigned int client4FramerFsmms = 0;
	client4FramerFsmms = pt_monitor_struct->tp_defects_struct.tp_client_framer_status[3].fields.fsmms;

	unsigned int client4FramerFsmmsAlarmSev = 0;
	client4FramerFsmmsAlarmSev = pt_monitor_struct->tp_defects_struct.severity.severity_client[3].FramerFsmms;

	unsigned int send_client4FramerFsmmsAlarm = 0;
	if (client4FramerFsmmsTemp==0 && client4FramerFsmms==1)
   {
		client4FramerFsmmsAlarm = 1;
		send_client4FramerFsmmsAlarm = 1;
   }
   else if (client4FramerFsmmsTemp==1 && client4FramerFsmms==0)
   {
	   client4FramerFsmmsAlarm = 2;
      send_client4FramerFsmmsAlarm = 1;
   }
	client4FramerFsmmsTemp = client4FramerFsmms;

	snmp_varlist_add_variable(&notification_vars, objid_snmptrap, objid_snmptrap_len, ASN_OBJECT_ID, (u_char *) notification_oid, notification_oid_len * sizeof(oid));
	snmp_varlist_add_variable(&notification_vars, client4FramerFsmms_oid, client4FramerFsmms_oid_len, ASN_INTEGER, (u_char *)&client4FramerFsmmsAlarm, sizeof(client4FramerFsmmsAlarm));
	snmp_varlist_add_variable(&notification_vars, client4FramerFsmmsAlarmSev_oid, client4FramerFsmmsAlarmSev_oid_len, ASN_INTEGER, (u_char *)&client4FramerFsmmsAlarmSev, sizeof(client4FramerFsmmsAlarmSev));

	if(send_client4FramerFsmmsAlarm == 1)
	{
		++client4FramerFsmmsCount;
		DEBUGMSGTL(("ftnc_notifications", "sending trap %ld\n",client4FramerFsmmsCount));
		send_v2trap(notification_vars);
	}

	snmp_free_varbind(notification_vars);
}

void send_tp_client4FramerFssusts_notification(unsigned int clientreg, void *clientarg)
{
	DEBUGMSGTL(("token", "send_tp_client4FramerFssusts_notification.\n"));

	oid notification_oid[] = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 2, 2, 0, 154 };
	size_t notification_oid_len = OID_LENGTH(notification_oid);
	oid objid_snmptrap[] = { 1, 3, 6, 1, 6, 3, 1, 1, 4, 1, 0 };
	size_t objid_snmptrap_len = OID_LENGTH(objid_snmptrap);
	oid client4FramerFssusts_oid[]   = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 2, 2, 1, 7, 1, 73 };
	size_t client4FramerFssusts_oid_len = OID_LENGTH(client4FramerFssusts_oid);
	oid      client4FramerFssustsAlarmSev_oid[]   = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 3, 6, 5, 1, 3 };
	size_t   client4FramerFssustsAlarmSev_oid_len = OID_LENGTH(client4FramerFssustsAlarmSev_oid);

	netsnmp_variable_list *notification_vars = NULL;
	static u_long client4FramerFssustsCount = 0;

	unsigned int client4FramerFssustsAlarm = 0;

	unsigned int client4FramerFssusts = 0;
	client4FramerFssusts = pt_monitor_struct->tp_defects_struct.tp_client_framer_status[3].fields.fsusts;

	unsigned int client4FramerFssustsAlarmSev = 0;
	client4FramerFssustsAlarmSev = pt_monitor_struct->tp_defects_struct.severity.severity_client[3].FramerFssusts;

	unsigned int send_client4FramerFssustsAlarm = 0;
	if (client4FramerFssustsTemp==0 && client4FramerFssusts==1)
   {
		client4FramerFssustsAlarm = 1;
		send_client4FramerFssustsAlarm = 1;
   }
   else if (client4FramerFssustsTemp==1 && client4FramerFssusts==0)
   {
	   client4FramerFssustsAlarm = 2;
      send_client4FramerFssustsAlarm = 1;
   }
	client4FramerFssustsTemp = client4FramerFssusts;

	snmp_varlist_add_variable(&notification_vars, objid_snmptrap, objid_snmptrap_len, ASN_OBJECT_ID, (u_char *) notification_oid, notification_oid_len * sizeof(oid));
	snmp_varlist_add_variable(&notification_vars, client4FramerFssusts_oid, client4FramerFssusts_oid_len, ASN_INTEGER, (u_char *)&client4FramerFssustsAlarm, sizeof(client4FramerFssustsAlarm));
	snmp_varlist_add_variable(&notification_vars, client4FramerFssustsAlarmSev_oid, client4FramerFssustsAlarmSev_oid_len, ASN_INTEGER, (u_char *)&client4FramerFssustsAlarmSev, sizeof(client4FramerFssustsAlarmSev));

	if(send_client4FramerFssustsAlarm == 1)
	{
		++client4FramerFssustsCount;
		DEBUGMSGTL(("ftnc_notifications", "sending trap %ld\n",client4FramerFssustsCount));
		send_v2trap(notification_vars);
	}

	snmp_free_varbind(notification_vars);
}

void send_tp_client4FramerSif_notification(unsigned int clientreg, void *clientarg)
{
	DEBUGMSGTL(("token", "send_tp_client4FramerSif_notification.\n"));

	oid notification_oid[] = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 2, 2, 0, 155 };
	size_t notification_oid_len = OID_LENGTH(notification_oid);
	oid objid_snmptrap[] = { 1, 3, 6, 1, 6, 3, 1, 1, 4, 1, 0 };
	size_t objid_snmptrap_len = OID_LENGTH(objid_snmptrap);
	oid client4FramerSif_oid[]   = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 2, 2, 1, 7, 1, 74 };
	size_t client4FramerSif_oid_len = OID_LENGTH(client4FramerSif_oid);
	oid      client4FramerSifAlarmSev_oid[]   = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 3, 6, 5, 1, 6 };
	size_t   client4FramerSifAlarmSev_oid_len = OID_LENGTH(client4FramerSifAlarmSev_oid);

	netsnmp_variable_list *notification_vars = NULL;
	static u_long client4FramerSifCount = 0;

	unsigned int client4FramerSifAlarm = 0;

	unsigned int client4FramerSif = 0;
	client4FramerSif = pt_monitor_struct->tp_defects_struct.tp_client_framer_status[2].fields.sif;

	unsigned int client4FramerSifAlarmSev = 0;
	client4FramerSifAlarmSev = pt_monitor_struct->tp_defects_struct.severity.severity_client[2].FramerSif;

	unsigned int send_client4FramerSifAlarm = 0;
	if (client4FramerSifTemp==0 && client4FramerSif==1)
   {
		client4FramerSifAlarm = 1;
		send_client4FramerSifAlarm = 1;
   }
   else if (client4FramerSifTemp==1 && client4FramerSif==0)
   {
	   client4FramerSifAlarm = 2;
      send_client4FramerSifAlarm = 1;
   }
	client4FramerSifTemp = client4FramerSif;

	snmp_varlist_add_variable(&notification_vars, objid_snmptrap, objid_snmptrap_len, ASN_OBJECT_ID, (u_char *) notification_oid, notification_oid_len * sizeof(oid));
	snmp_varlist_add_variable(&notification_vars, client4FramerSif_oid, client4FramerSif_oid_len, ASN_INTEGER, (u_char *)&client4FramerSifAlarm, sizeof(client4FramerSifAlarm));
	snmp_varlist_add_variable(&notification_vars, client4FramerSifAlarmSev_oid, client4FramerSifAlarmSev_oid_len, ASN_INTEGER, (u_char *)&client4FramerSifAlarmSev, sizeof(client4FramerSifAlarmSev));

	if(send_client4FramerSifAlarm == 1)
	{
		++client4FramerSifCount;
		DEBUGMSGTL(("ftnc_notifications", "sending trap %ld\n",client4FramerSifCount));
		send_v2trap(notification_vars);
	}

	snmp_free_varbind(notification_vars);
}

void send_tp_client4FramerSoof_notification(unsigned int clientreg, void *clientarg)
{
	DEBUGMSGTL(("token", "send_tp_client4FramerSoof_notification.\n"));

	oid notification_oid[] = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 2, 2, 0, 156 };
	size_t notification_oid_len = OID_LENGTH(notification_oid);
	oid objid_snmptrap[] = { 1, 3, 6, 1, 6, 3, 1, 1, 4, 1, 0 };
	size_t objid_snmptrap_len = OID_LENGTH(objid_snmptrap);
	oid client4FramerSoof_oid[]   = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 2, 2, 1, 7, 1, 75 };
	size_t client4FramerSoof_oid_len = OID_LENGTH(client4FramerSoof_oid);
	oid      client4FramerSoofAlarmSev_oid[]   = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 3, 6, 5, 1, 4 };
	size_t   client4FramerSoofAlarmSev_oid_len = OID_LENGTH(client4FramerSoofAlarmSev_oid);

	netsnmp_variable_list *notification_vars = NULL;
	static u_long client4FramerSoofCount = 0;

	unsigned int client4FramerSoofAlarm = 0;

	unsigned int client4FramerSoof = 0;
	client4FramerSoof = pt_monitor_struct->tp_defects_struct.tp_client_framer_status[3].fields.soof;

	unsigned int client4FramerSoofAlarmSev = 0;
	client4FramerSoofAlarmSev = pt_monitor_struct->tp_defects_struct.severity.severity_client[3].FramerSoof;

	unsigned int send_client4FramerSoofAlarm = 0;
	if (client4FramerSoofTemp==0 && client4FramerSoof==1)
   {
		client4FramerSoofAlarm = 1;
		send_client4FramerSoofAlarm = 1;
   }
   else if (client4FramerSoofTemp==1 && client4FramerSoof==0)
   {
	   client4FramerSoofAlarm = 2;
      send_client4FramerSoofAlarm = 1;
   }
	client4FramerSoofTemp = client4FramerSoof;

	snmp_varlist_add_variable(&notification_vars, objid_snmptrap, objid_snmptrap_len, ASN_OBJECT_ID, (u_char *) notification_oid, notification_oid_len * sizeof(oid));
	snmp_varlist_add_variable(&notification_vars, client4FramerSoof_oid, client4FramerSoof_oid_len, ASN_INTEGER, (u_char *)&client4FramerSoofAlarm, sizeof(client4FramerSoofAlarm));
	snmp_varlist_add_variable(&notification_vars, client4FramerSoofAlarmSev_oid, client4FramerSoofAlarmSev_oid_len, ASN_INTEGER, (u_char *)&client4FramerSoofAlarmSev, sizeof(client4FramerSoofAlarmSev));

	if(send_client4FramerSoofAlarm == 1)
	{
		++client4FramerSoofCount;
		DEBUGMSGTL(("ftnc_notifications", "sending trap %ld\n",client4FramerSoofCount));
		send_v2trap(notification_vars);
	}

	snmp_free_varbind(notification_vars);
}

void send_tp_client4FramerSlof_notification(unsigned int clientreg, void *clientarg)
{
	DEBUGMSGTL(("token", "send_tp_client4FramerSlof_notification.\n"));

	oid notification_oid[] = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 2, 2, 0, 157 };
	size_t notification_oid_len = OID_LENGTH(notification_oid);
	oid objid_snmptrap[] = { 1, 3, 6, 1, 6, 3, 1, 1, 4, 1, 0 };
	size_t objid_snmptrap_len = OID_LENGTH(objid_snmptrap);
	oid client4FramerSlof_oid[]   = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 2, 2, 1, 7, 1, 76 };
	size_t client4FramerSlof_oid_len = OID_LENGTH(client4FramerSlof_oid);
	oid      client4FramerSlofAlarmSev_oid[]   = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 3, 6, 5, 1, 5 };
	size_t   client4FramerSlofAlarmSev_oid_len = OID_LENGTH(client4FramerSlofAlarmSev_oid);

	netsnmp_variable_list *notification_vars = NULL;
	static u_long client4FramerSlofCount = 0;

	unsigned int client4FramerSlofAlarm = 0;

	unsigned int client4FramerSlof = 0;
	client4FramerSlof = pt_monitor_struct->tp_defects_struct.tp_client_framer_status[3].fields.slof;

	unsigned int client4FramerSlofAlarmSev = 0;
	client4FramerSlofAlarmSev = pt_monitor_struct->tp_defects_struct.severity.severity_client[3].FramerSlof;

	unsigned int send_client4FramerSlofAlarm = 0;
	if (client4FramerSlofTemp==0 && client4FramerSlof==1)
   {
		client4FramerSlofAlarm = 1;
		send_client4FramerSlofAlarm = 1;
   }
   else if (client4FramerSlofTemp==1 && client4FramerSlof==0)
   {
	   client4FramerSlofAlarm = 2;
      send_client4FramerSlofAlarm = 1;
   }
	client4FramerSlofTemp = client4FramerSlof;

	snmp_varlist_add_variable(&notification_vars, objid_snmptrap, objid_snmptrap_len, ASN_OBJECT_ID, (u_char *) notification_oid, notification_oid_len * sizeof(oid));
	snmp_varlist_add_variable(&notification_vars, client4FramerSlof_oid, client4FramerSlof_oid_len, ASN_INTEGER, (u_char *)&client4FramerSlofAlarm, sizeof(client4FramerSlofAlarm));
	snmp_varlist_add_variable(&notification_vars, client4FramerSlofAlarmSev_oid, client4FramerSlofAlarmSev_oid_len, ASN_INTEGER, (u_char *)&client4FramerSlofAlarmSev, sizeof(client4FramerSlofAlarmSev));

	if(send_client4FramerSlofAlarm == 1)
	{
		++client4FramerSlofCount;
		DEBUGMSGTL(("ftnc_notifications", "sending trap %ld\n",client4FramerSlofCount));
		send_v2trap(notification_vars);
	}

	snmp_free_varbind(notification_vars);
}

void send_tp_client4FramerFst_notification(unsigned int clientreg, void *clientarg)
{
	DEBUGMSGTL(("token", "send_tp_client4FramerFst_notification.\n"));

	oid notification_oid[] = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 2, 2, 0, 158 };
	size_t notification_oid_len = OID_LENGTH(notification_oid);
	oid objid_snmptrap[] = { 1, 3, 6, 1, 6, 3, 1, 1, 4, 1, 0 };
	size_t objid_snmptrap_len = OID_LENGTH(objid_snmptrap);
	oid client4FramerFst_oid[]   = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 2, 2, 1, 7, 1, 77 };
	size_t client4FramerFst_oid_len = OID_LENGTH(client4FramerFst_oid);
	oid      client4FramerFstAlarmSev_oid[]   = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 3, 6, 5, 1, 7 };
	size_t   client4FramerFstAlarmSev_oid_len = OID_LENGTH(client4FramerFstAlarmSev_oid);

	netsnmp_variable_list *notification_vars = NULL;
	static u_long client4FramerFstCount = 0;

	unsigned int client4FramerFstAlarm = 0;

	unsigned int client4FramerFst = 0;
	client4FramerFst = pt_monitor_struct->tp_defects_struct.tp_client_framer_status[3].fields.fst;

	unsigned int client4FramerFstAlarmSev = 0;
	client4FramerFstAlarmSev = pt_monitor_struct->tp_defects_struct.severity.severity_client[3].FramerFst;

	unsigned int send_client4FramerFstAlarm = 0;
	if (client4FramerFstTemp==0 && client4FramerFst==1)
   {
		client4FramerFstAlarm = 1;
		send_client4FramerFstAlarm = 1;
   }
   else if (client4FramerFstTemp==1 && client4FramerFst==0)
   {
	   client4FramerFstAlarm = 2;
      send_client4FramerFstAlarm = 1;
   }
	client4FramerFstTemp = client4FramerFst;

	snmp_varlist_add_variable(&notification_vars, objid_snmptrap, objid_snmptrap_len, ASN_OBJECT_ID, (u_char *) notification_oid, notification_oid_len * sizeof(oid));
	snmp_varlist_add_variable(&notification_vars, client4FramerFst_oid, client4FramerFst_oid_len, ASN_INTEGER, (u_char *)&client4FramerFstAlarm, sizeof(client4FramerFstAlarm));
	snmp_varlist_add_variable(&notification_vars, client4FramerFstAlarmSev_oid, client4FramerFstAlarmSev_oid_len, ASN_INTEGER, (u_char *)&client4FramerFstAlarmSev, sizeof(client4FramerFstAlarmSev));

	if(send_client4FramerFstAlarm == 1)
	{
		++client4FramerFstCount;
		DEBUGMSGTL(("ftnc_notifications", "sending trap %ld\n",client4FramerFstCount));
		send_v2trap(notification_vars);
	}

	snmp_free_varbind(notification_vars);
}

void send_tp_client4LosstatLosf_notification(unsigned int clientreg, void *clientarg)
{
	DEBUGMSGTL(("token", "send_tp_client4LosstatLosf_notification.\n"));

	oid notification_oid[] = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 2, 2, 0, 159 };
	size_t notification_oid_len = OID_LENGTH(notification_oid);
	oid objid_snmptrap[] = { 1, 3, 6, 1, 6, 3, 1, 1, 4, 1, 0 };
	size_t objid_snmptrap_len = OID_LENGTH(objid_snmptrap);
	oid client4LosstatLosf_oid[]   = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 2, 2, 1, 7, 1, 78 };
	size_t client4LosstatLosf_oid_len = OID_LENGTH(client4LosstatLosf_oid);
	oid      client4LosstatLosfAlarmSev_oid[]   = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 3, 6, 5, 1, 8 };
	size_t   client4LosstatLosfAlarmSev_oid_len = OID_LENGTH(client4LosstatLosfAlarmSev_oid);

	netsnmp_variable_list *notification_vars = NULL;
	static u_long client4LosstatLosfCount = 0;

	unsigned int client4LosstatLosfAlarm = 0;

	unsigned int client4LosstatLosf = 0;
	client4LosstatLosf = pt_monitor_struct->tp_defects_struct.tp_client_los_status[3].fields.losf;

	unsigned int client4LosstatLosfAlarmSev = 0;
	client4LosstatLosfAlarmSev = pt_monitor_struct->tp_defects_struct.severity.severity_client[3].LosstatLosf;

	unsigned int send_client4LosstatLosfAlarm = 0;
	if (client4LosstatLosfTemp==0 && client4LosstatLosf==1)
   {
		client4LosstatLosfAlarm = 1;
		send_client4LosstatLosfAlarm = 1;
   }
   else if (client4LosstatLosfTemp==1 && client4LosstatLosf==0)
   {
	   client4LosstatLosfAlarm = 2;
      send_client4LosstatLosfAlarm = 1;
   }
	client4LosstatLosfTemp = client4LosstatLosf;

	snmp_varlist_add_variable(&notification_vars, objid_snmptrap, objid_snmptrap_len, ASN_OBJECT_ID, (u_char *) notification_oid, notification_oid_len * sizeof(oid));
	snmp_varlist_add_variable(&notification_vars, client4LosstatLosf_oid, client4LosstatLosf_oid_len, ASN_INTEGER, (u_char *)&client4LosstatLosfAlarm, sizeof(client4LosstatLosfAlarm));
	snmp_varlist_add_variable(&notification_vars, client4LosstatLosfAlarmSev_oid, client4LosstatLosfAlarmSev_oid_len, ASN_INTEGER, (u_char *)&client4LosstatLosfAlarmSev, sizeof(client4LosstatLosfAlarmSev));

	if(send_client4LosstatLosfAlarm == 1)
	{
		++client4LosstatLosfCount;
		DEBUGMSGTL(("ftnc_notifications", "sending trap %ld\n",client4LosstatLosfCount));
		send_v2trap(notification_vars);
	}

	snmp_free_varbind(notification_vars);
}

void send_tp_client4SecmonFlom_notification(unsigned int clientreg, void *clientarg)
{
	DEBUGMSGTL(("token", "send_tp_client4SecmonFlom_notification.\n"));

	oid notification_oid[] = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 2, 2, 0, 160 };
	size_t notification_oid_len = OID_LENGTH(notification_oid);
	oid objid_snmptrap[] = { 1, 3, 6, 1, 6, 3, 1, 1, 4, 1, 0 };
	size_t objid_snmptrap_len = OID_LENGTH(objid_snmptrap);
	oid client4SecmonFlom_oid[]   = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 2, 2, 1, 7, 1, 79 };
	size_t client4SecmonFlom_oid_len = OID_LENGTH(client4SecmonFlom_oid);
	oid      client4SecmonFlomAlarmSev_oid[]   = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 3, 6, 5, 1, 17 };
	size_t   client4SecmonFlomAlarmSev_oid_len = OID_LENGTH(client4SecmonFlomAlarmSev_oid);

	netsnmp_variable_list *notification_vars = NULL;
	static u_long client4SecmonFlomCount = 0;

	unsigned int client4SecmonFlomAlarm = 0;

	unsigned int client4SecmonFlom = 0;
	client4SecmonFlom = pt_monitor_struct->tp_defects_struct.tp_client_section_mon[3].fields.flom;

	unsigned int client4SecmonFlomAlarmSev = 0;
	client4SecmonFlomAlarmSev = pt_monitor_struct->tp_defects_struct.severity.severity_client[3].SecmonFlom;

	unsigned int send_client4SecmonFlomAlarm = 0;
	if (client4SecmonFlomTemp==0 && client4SecmonFlom==1)
   {
		client4SecmonFlomAlarm = 1;
		send_client4SecmonFlomAlarm = 1;
   }
   else if (client4SecmonFlomTemp==1 && client4SecmonFlom==0)
   {
	   client4SecmonFlomAlarm = 2;
      send_client4SecmonFlomAlarm = 1;
   }
	client4SecmonFlomTemp = client4SecmonFlom;

	snmp_varlist_add_variable(&notification_vars, objid_snmptrap, objid_snmptrap_len, ASN_OBJECT_ID, (u_char *) notification_oid, notification_oid_len * sizeof(oid));
	snmp_varlist_add_variable(&notification_vars, client4SecmonFlom_oid, client4SecmonFlom_oid_len, ASN_INTEGER, (u_char *)&client4SecmonFlomAlarm, sizeof(client4SecmonFlomAlarm));
	snmp_varlist_add_variable(&notification_vars, client4SecmonFlomAlarmSev_oid, client4SecmonFlomAlarmSev_oid_len, ASN_INTEGER, (u_char *)&client4SecmonFlomAlarmSev, sizeof(client4SecmonFlomAlarmSev));

	if(send_client4SecmonFlomAlarm == 1)
	{
		++client4SecmonFlomCount;
		DEBUGMSGTL(("ftnc_notifications", "sending trap %ld\n",client4SecmonFlomCount));
		send_v2trap(notification_vars);
	}

	snmp_free_varbind(notification_vars);
}

void send_tp_client4SecmonBipsfs_notification(unsigned int clientreg, void *clientarg)
{
	DEBUGMSGTL(("token", "send_tp_client4SecmonBipsfs_notification.\n"));

	oid notification_oid[] = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 2, 2, 0, 161 };
	size_t notification_oid_len = OID_LENGTH(notification_oid);
	oid objid_snmptrap[] = { 1, 3, 6, 1, 6, 3, 1, 1, 4, 1, 0 };
	size_t objid_snmptrap_len = OID_LENGTH(objid_snmptrap);
	oid client4SecmonBipsfs_oid[]   = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 2, 2, 1, 7, 1, 80 };
	size_t client4SecmonBipsfs_oid_len = OID_LENGTH(client4SecmonBipsfs_oid);
	oid      client4SecmonBipsfsAlarmSev_oid[]   = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 3, 6, 5, 1, 14 };
	size_t   client4SecmonBipsfsAlarmSev_oid_len = OID_LENGTH(client4SecmonBipsfsAlarmSev_oid);

	netsnmp_variable_list *notification_vars = NULL;
	static u_long client4SecmonBipsfsCount = 0;

	unsigned int client4SecmonBipsfsAlarm = 0;

	unsigned int client4SecmonBipsfs = 0;
	client4SecmonBipsfs = pt_monitor_struct->tp_defects_struct.tp_client_section_mon[3].fields.bipsfs;

	unsigned int client4SecmonBipsfsAlarmSev = 0;
	client4SecmonBipsfsAlarmSev = pt_monitor_struct->tp_defects_struct.severity.severity_client[3].SecmonBipsfs;

	unsigned int send_client4SecmonBipsfsAlarm = 0;
	if (client4SecmonBipsfsTemp==0 && client4SecmonBipsfs==1)
   {
		client4SecmonBipsfsAlarm = 1;
		send_client4SecmonBipsfsAlarm = 1;
   }
   else if (client4SecmonBipsfsTemp==1 && client4SecmonBipsfs==0)
   {
	   client4SecmonBipsfsAlarm = 2;
      send_client4SecmonBipsfsAlarm = 1;
   }
	client4SecmonBipsfsTemp = client4SecmonBipsfs;

	snmp_varlist_add_variable(&notification_vars, objid_snmptrap, objid_snmptrap_len, ASN_OBJECT_ID, (u_char *) notification_oid, notification_oid_len * sizeof(oid));
	snmp_varlist_add_variable(&notification_vars, client4SecmonBipsfs_oid, client4SecmonBipsfs_oid_len, ASN_INTEGER, (u_char *)&client4SecmonBipsfsAlarm, sizeof(client4SecmonBipsfsAlarm));
	snmp_varlist_add_variable(&notification_vars, client4SecmonBipsfsAlarmSev_oid, client4SecmonBipsfsAlarmSev_oid_len, ASN_INTEGER, (u_char *)&client4SecmonBipsfsAlarmSev, sizeof(client4SecmonBipsfsAlarmSev));

	if(send_client4SecmonBipsfsAlarm == 1)
	{
		++client4SecmonBipsfsCount;
		DEBUGMSGTL(("ftnc_notifications", "sending trap %ld\n",client4SecmonBipsfsCount));
		send_v2trap(notification_vars);
	}

	snmp_free_varbind(notification_vars);
}

void send_tp_client4SecmonDiae_notification(unsigned int clientreg, void *clientarg)
{
	DEBUGMSGTL(("token", "send_tp_client4SecmonDiae_notification.\n"));

	oid notification_oid[] = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 2, 2, 0, 162 };
	size_t notification_oid_len = OID_LENGTH(notification_oid);
	oid objid_snmptrap[] = { 1, 3, 6, 1, 6, 3, 1, 1, 4, 1, 0 };
	size_t objid_snmptrap_len = OID_LENGTH(objid_snmptrap);
	oid client4SecmonDiae_oid[]   = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 2, 2, 1, 7, 1, 81 };
	size_t client4SecmonDiae_oid_len = OID_LENGTH(client4SecmonDiae_oid);
	oid      client4SecmonDiaeAlarmSev_oid[]   = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 3, 6, 5, 1, 16 };
	size_t   client4SecmonDiaeAlarmSev_oid_len = OID_LENGTH(client4SecmonDiaeAlarmSev_oid);

	netsnmp_variable_list *notification_vars = NULL;
	static u_long client4SecmonDiaeCount = 0;

	unsigned int client4SecmonDiaeAlarm = 0;

	unsigned int client4SecmonDiae = 0;
	client4SecmonDiae = pt_monitor_struct->tp_defects_struct.tp_client_section_mon[3].fields.diae;

	unsigned int client4SecmonDiaeAlarmSev = 0;
	client4SecmonDiaeAlarmSev = pt_monitor_struct->tp_defects_struct.severity.severity_client[3].SecmonDiae;

	unsigned int send_client4SecmonDiaeAlarm = 0;
	if (client4SecmonDiaeTemp==0 && client4SecmonDiae==1)
   {
		client4SecmonDiaeAlarm = 1;
		send_client4SecmonDiaeAlarm = 1;
   }
   else if (client4SecmonDiaeTemp==1 && client4SecmonDiae==0)
   {
	   client4SecmonDiaeAlarm = 2;
      send_client4SecmonDiaeAlarm = 1;
   }
	client4SecmonDiaeTemp = client4SecmonDiae;

	snmp_varlist_add_variable(&notification_vars, objid_snmptrap, objid_snmptrap_len, ASN_OBJECT_ID, (u_char *) notification_oid, notification_oid_len * sizeof(oid));
	snmp_varlist_add_variable(&notification_vars, client4SecmonDiae_oid, client4SecmonDiae_oid_len, ASN_INTEGER, (u_char *)&client4SecmonDiaeAlarm, sizeof(client4SecmonDiaeAlarm));
	snmp_varlist_add_variable(&notification_vars, client4SecmonDiaeAlarmSev_oid, client4SecmonDiaeAlarmSev_oid_len, ASN_INTEGER, (u_char *)&client4SecmonDiaeAlarmSev, sizeof(client4SecmonDiaeAlarmSev));

	if(send_client4SecmonDiaeAlarm == 1)
	{
		++client4SecmonDiaeCount;
		DEBUGMSGTL(("ftnc_notifications", "sending trap %ld\n",client4SecmonDiaeCount));
		send_v2trap(notification_vars);
	}

	snmp_free_varbind(notification_vars);
}

void send_tp_client4SecmonDbdi_notification(unsigned int clientreg, void *clientarg)
{
	DEBUGMSGTL(("token", "send_tp_client4SecmonDbdi_notification.\n"));

	oid notification_oid[] = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 2, 2, 0, 163 };
	size_t notification_oid_len = OID_LENGTH(notification_oid);
	oid objid_snmptrap[] = { 1, 3, 6, 1, 6, 3, 1, 1, 4, 1, 0 };
	size_t objid_snmptrap_len = OID_LENGTH(objid_snmptrap);
	oid client4SecmonDbdi_oid[]   = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 2, 2, 1, 7, 1, 82 };
	size_t client4SecmonDbdi_oid_len = OID_LENGTH(client4SecmonDbdi_oid);
	oid      client4SecmonDbdiAlarmSev_oid[]   = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 3, 6, 5, 1, 15 };
	size_t   client4SecmonDbdiAlarmSev_oid_len = OID_LENGTH(client4SecmonDbdiAlarmSev_oid);

	netsnmp_variable_list *notification_vars = NULL;
	static u_long client4SecmonDbdiCount = 0;

	unsigned int client4SecmonDbdiAlarm = 0;

	unsigned int client4SecmonDbdi = 0;
	client4SecmonDbdi = pt_monitor_struct->tp_defects_struct.tp_client_section_mon[3].fields.dbdi;

	unsigned int client4SecmonDbdiAlarmSev = 0;
	client4SecmonDbdiAlarmSev = pt_monitor_struct->tp_defects_struct.severity.severity_client[3].SecmonDbdi;

	unsigned int send_client4SecmonDbdiAlarm = 0;
	if (client4SecmonDbdiTemp==0 && client4SecmonDbdi==1)
   {
		client4SecmonDbdiAlarm = 1;
		send_client4SecmonDbdiAlarm = 1;
   }
   else if (client4SecmonDbdiTemp==1 && client4SecmonDbdi==0)
   {
	   client4SecmonDbdiAlarm = 2;
      send_client4SecmonDbdiAlarm = 1;
   }
	client4SecmonDbdiTemp = client4SecmonDbdi;

	snmp_varlist_add_variable(&notification_vars, objid_snmptrap, objid_snmptrap_len, ASN_OBJECT_ID, (u_char *) notification_oid, notification_oid_len * sizeof(oid));
	snmp_varlist_add_variable(&notification_vars, client4SecmonDbdi_oid, client4SecmonDbdi_oid_len, ASN_INTEGER, (u_char *)&client4SecmonDbdiAlarm, sizeof(client4SecmonDbdiAlarm));
	snmp_varlist_add_variable(&notification_vars, client4SecmonDbdiAlarmSev_oid, client4SecmonDbdiAlarmSev_oid_len, ASN_INTEGER, (u_char *)&client4SecmonDbdiAlarmSev, sizeof(client4SecmonDbdiAlarmSev));

	if(send_client4SecmonDbdiAlarm == 1)
	{
		++client4SecmonDbdiCount;
		DEBUGMSGTL(("ftnc_notifications", "sending trap %ld\n",client4SecmonDbdiCount));
		send_v2trap(notification_vars);
	}

	snmp_free_varbind(notification_vars);
}

void send_tp_client4SecmonLom_notification(unsigned int clientreg, void *clientarg)
{
	DEBUGMSGTL(("token", "send_tp_client4SecmonLom_notification.\n"));

	oid notification_oid[] = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 2, 2, 0, 164 };
	size_t notification_oid_len = OID_LENGTH(notification_oid);
	oid objid_snmptrap[] = { 1, 3, 6, 1, 6, 3, 1, 1, 4, 1, 0 };
	size_t objid_snmptrap_len = OID_LENGTH(objid_snmptrap);
	oid client4SecmonLom_oid[]   = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 2, 2, 1, 7, 1, 83 };
	size_t client4SecmonLom_oid_len = OID_LENGTH(client4SecmonLom_oid);
	oid      client4SecmonLomAlarmSev_oid[]   = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 3, 6, 5, 1, 18 };
	size_t   client4SecmonLomAlarmSev_oid_len = OID_LENGTH(client4SecmonLomAlarmSev_oid);

	netsnmp_variable_list *notification_vars = NULL;
	static u_long client4SecmonLomCount = 0;

	unsigned int client4SecmonLomAlarm = 0;

	unsigned int client4SecmonLom = 0;
	client4SecmonLom = pt_monitor_struct->tp_defects_struct.tp_client_section_mon[3].fields.lom;

	unsigned int client4SecmonLomAlarmSev = 0;
	client4SecmonLomAlarmSev = pt_monitor_struct->tp_defects_struct.severity.severity_client[3].SecmonLom;

	unsigned int send_client4SecmonLomAlarm = 0;
	if (client4SecmonLomTemp==0 && client4SecmonLom==1)
   {
		client4SecmonLomAlarm = 1;
		send_client4SecmonLomAlarm = 1;
   }
   else if (client4SecmonLomTemp==1 && client4SecmonLom==0)
   {
	   client4SecmonLomAlarm = 2;
      send_client4SecmonLomAlarm = 1;
   }
	client4SecmonLomTemp = client4SecmonLom;

	snmp_varlist_add_variable(&notification_vars, objid_snmptrap, objid_snmptrap_len, ASN_OBJECT_ID, (u_char *) notification_oid, notification_oid_len * sizeof(oid));
	snmp_varlist_add_variable(&notification_vars, client4SecmonLom_oid, client4SecmonLom_oid_len, ASN_INTEGER, (u_char *)&client4SecmonLomAlarm, sizeof(client4SecmonLomAlarm));
	snmp_varlist_add_variable(&notification_vars, client4SecmonLomAlarmSev_oid, client4SecmonLomAlarmSev_oid_len, ASN_INTEGER, (u_char *)&client4SecmonLomAlarmSev, sizeof(client4SecmonLomAlarmSev));

	if(send_client4SecmonLomAlarm == 1)
	{
		++client4SecmonLomCount;
		DEBUGMSGTL(("ftnc_notifications", "sending trap %ld\n",client4SecmonLomCount));
		send_v2trap(notification_vars);
	}

	snmp_free_varbind(notification_vars);
}

void send_tp_client4PathmonAccstat_notification(unsigned int clientreg, void *clientarg)
{
	DEBUGMSGTL(("token", "send_tp_client4PathmonAccstat_notification.\n"));

	oid notification_oid[] = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 2, 2, 0, 165 };
	size_t notification_oid_len = OID_LENGTH(notification_oid);
	oid objid_snmptrap[] = { 1, 3, 6, 1, 6, 3, 1, 1, 4, 1, 0 };
	size_t objid_snmptrap_len = OID_LENGTH(objid_snmptrap);
	oid client4PathmonAccstat_oid[]   = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 2, 2, 1, 7, 1, 84 };
	size_t client4PathmonAccstat_oid_len = OID_LENGTH(client4PathmonAccstat_oid);
	oid      client4PathmonAccstatAlarmSev_oid[]   = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 3, 6, 5, 1, 9 };
	size_t   client4PathmonAccstatAlarmSev_oid_len = OID_LENGTH(client4PathmonAccstatAlarmSev_oid);

	netsnmp_variable_list *notification_vars = NULL;
	static u_long client4PathmonAccstatCount = 0;

	unsigned int client4PathmonAccstatAlarm = 0;

	unsigned int client4PathmonAccstat = 0;
	client4PathmonAccstat = pt_monitor_struct->tp_defects_struct.tp_client_path_mon[3].fields.accstat;

	unsigned int client4PathmonAccstatAlarmSev = 0;
	client4PathmonAccstatAlarmSev = pt_monitor_struct->tp_defects_struct.severity.severity_client[3].PathmonAccstat;

	unsigned int send_client4PathmonAccstatAlarm = 0;
	if (client4PathmonAccstatTemp==0 && client4PathmonAccstat==1)
   {
		client4PathmonAccstatAlarm = 1;
		send_client4PathmonAccstatAlarm = 1;
   }
   else if (client4PathmonAccstatTemp==1 && client4PathmonAccstat==0)
   {
	   client4PathmonAccstatAlarm = 2;
      send_client4PathmonAccstatAlarm = 1;
   }
	client4PathmonAccstatTemp = client4PathmonAccstat;

	snmp_varlist_add_variable(&notification_vars, objid_snmptrap, objid_snmptrap_len, ASN_OBJECT_ID, (u_char *) notification_oid, notification_oid_len * sizeof(oid));
	snmp_varlist_add_variable(&notification_vars, client4PathmonAccstat_oid, client4PathmonAccstat_oid_len, ASN_INTEGER, (u_char *)&client4PathmonAccstatAlarm, sizeof(client4PathmonAccstatAlarm));
	snmp_varlist_add_variable(&notification_vars, client4PathmonAccstatAlarmSev_oid, client4PathmonAccstatAlarmSev_oid_len, ASN_INTEGER, (u_char *)&client4PathmonAccstatAlarmSev, sizeof(client4PathmonAccstatAlarmSev));

	if(send_client4PathmonAccstatAlarm == 1)
	{
		++client4PathmonAccstatCount;
		DEBUGMSGTL(("ftnc_notifications", "sending trap %ld\n",client4PathmonAccstatCount));
		send_v2trap(notification_vars);
	}

	snmp_free_varbind(notification_vars);
}

void send_tp_client4PathmonMsiunst_notification(unsigned int clientreg, void *clientarg)
{
	DEBUGMSGTL(("token", "send_tp_client4PathmonMsiunst_notification.\n"));

	oid notification_oid[] = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 2, 2, 0, 166 };
	size_t notification_oid_len = OID_LENGTH(notification_oid);
	oid objid_snmptrap[] = { 1, 3, 6, 1, 6, 3, 1, 1, 4, 1, 0 };
	size_t objid_snmptrap_len = OID_LENGTH(objid_snmptrap);
	oid client4PathmonMsiunst_oid[]   = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 2, 2, 1, 7, 1, 85 };
	size_t client4PathmonMsiunst_oid_len = OID_LENGTH(client4PathmonMsiunst_oid);
	oid      client4PathmonMsiunstAlarmSev_oid[]   = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 3, 6, 5, 1, 13 };
	size_t   client4PathmonMsiunstAlarmSev_oid_len = OID_LENGTH(client4PathmonMsiunstAlarmSev_oid);

	netsnmp_variable_list *notification_vars = NULL;
	static u_long client4PathmonMsiunstCount = 0;

	unsigned int client4PathmonMsiunstAlarm = 0;

	unsigned int client4PathmonMsiunst = 0;
	client4PathmonMsiunst = pt_monitor_struct->tp_defects_struct.tp_client_path_mon[3].fields.msiunst;

	unsigned int client4PathmonMsiunstAlarmSev = 0;
	client4PathmonMsiunstAlarmSev = pt_monitor_struct->tp_defects_struct.severity.severity_client[3].PathmonMsiunst;

	unsigned int send_client4PathmonMsiunstAlarm = 0;
	if (client4PathmonMsiunstTemp==0 && client4PathmonMsiunst==1)
   {
		client4PathmonMsiunstAlarm = 1;
		send_client4PathmonMsiunstAlarm = 1;
   }
   else if (client4PathmonMsiunstTemp==1 && client4PathmonMsiunst==0)
   {
	   client4PathmonMsiunstAlarm = 2;
      send_client4PathmonMsiunstAlarm = 1;
   }
	client4PathmonMsiunstTemp = client4PathmonMsiunst;

	snmp_varlist_add_variable(&notification_vars, objid_snmptrap, objid_snmptrap_len, ASN_OBJECT_ID, (u_char *) notification_oid, notification_oid_len * sizeof(oid));
	snmp_varlist_add_variable(&notification_vars, client4PathmonMsiunst_oid, client4PathmonMsiunst_oid_len, ASN_INTEGER, (u_char *)&client4PathmonMsiunstAlarm, sizeof(client4PathmonMsiunstAlarm));
	snmp_varlist_add_variable(&notification_vars, client4PathmonMsiunstAlarmSev_oid, client4PathmonMsiunstAlarmSev_oid_len, ASN_INTEGER, (u_char *)&client4PathmonMsiunstAlarmSev, sizeof(client4PathmonMsiunstAlarmSev));

	if(send_client4PathmonMsiunstAlarm == 1)
	{
		++client4PathmonMsiunstCount;
		DEBUGMSGTL(("ftnc_notifications", "sending trap %ld\n",client4PathmonMsiunstCount));
		send_v2trap(notification_vars);
	}

	snmp_free_varbind(notification_vars);
}

void send_tp_client4PathmonDais_notification(unsigned int clientreg, void *clientarg)
{
	DEBUGMSGTL(("token", "send_tp_client4PathmonDais_notification.\n"));

	oid notification_oid[] = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 2, 2, 0, 167 };
	size_t notification_oid_len = OID_LENGTH(notification_oid);
	oid objid_snmptrap[] = { 1, 3, 6, 1, 6, 3, 1, 1, 4, 1, 0 };
	size_t objid_snmptrap_len = OID_LENGTH(objid_snmptrap);
	oid client4PathmonDais_oid[]   = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 2, 2, 1, 7, 1, 86 };
	size_t client4PathmonDais_oid_len = OID_LENGTH(client4PathmonDais_oid);
	oid      client4PathmonDaisAlarmSev_oid[]   = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 3, 6, 5, 1, 10 };
	size_t   client4PathmonDaisAlarmSev_oid_len = OID_LENGTH(client4PathmonDaisAlarmSev_oid);

	netsnmp_variable_list *notification_vars = NULL;
	static u_long client4PathmonDaisCount = 0;

	unsigned int client4PathmonDaisAlarm = 0;

	unsigned int client4PathmonDais = 0;
	client4PathmonDais = pt_monitor_struct->tp_defects_struct.tp_client_path_mon[3].fields.dais;

	unsigned int client4PathmonDaisAlarmSev = 0;
	client4PathmonDaisAlarmSev = pt_monitor_struct->tp_defects_struct.severity.severity_client[3].PathmonDais;

	unsigned int send_client4PathmonDaisAlarm = 0;
	if (client4PathmonDaisTemp==0 && client4PathmonDais==1)
   {
		client4PathmonDaisAlarm = 1;
		send_client4PathmonDaisAlarm = 1;
   }
   else if (client4PathmonDaisTemp==1 && client4PathmonDais==0)
   {
	   client4PathmonDaisAlarm = 2;
      send_client4PathmonDaisAlarm = 1;
   }
	client4PathmonDaisTemp = client4PathmonDais;

	snmp_varlist_add_variable(&notification_vars, objid_snmptrap, objid_snmptrap_len, ASN_OBJECT_ID, (u_char *) notification_oid, notification_oid_len * sizeof(oid));
	snmp_varlist_add_variable(&notification_vars, client4PathmonDais_oid, client4PathmonDais_oid_len, ASN_INTEGER, (u_char *)&client4PathmonDaisAlarm, sizeof(client4PathmonDaisAlarm));
	snmp_varlist_add_variable(&notification_vars, client4PathmonDaisAlarmSev_oid, client4PathmonDaisAlarmSev_oid_len, ASN_INTEGER, (u_char *)&client4PathmonDaisAlarmSev, sizeof(client4PathmonDaisAlarmSev));

	if(send_client4PathmonDaisAlarm == 1)
	{
		++client4PathmonDaisCount;
		DEBUGMSGTL(("ftnc_notifications", "sending trap %ld\n",client4PathmonDaisCount));
		send_v2trap(notification_vars);
	}

	snmp_free_varbind(notification_vars);
}

void send_tp_client4PathmonDlck_notification(unsigned int clientreg, void *clientarg)
{
	DEBUGMSGTL(("token", "send_tp_client4PathmonDlck_notification.\n"));

	oid notification_oid[] = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 2, 2, 0, 168 };
	size_t notification_oid_len = OID_LENGTH(notification_oid);
	oid objid_snmptrap[] = { 1, 3, 6, 1, 6, 3, 1, 1, 4, 1, 0 };
	size_t objid_snmptrap_len = OID_LENGTH(objid_snmptrap);
	oid client4PathmonDlck_oid[]   = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 2, 2, 1, 7, 1, 87 };
	size_t client4PathmonDlck_oid_len = OID_LENGTH(client4PathmonDlck_oid);
	oid      client4PathmonDlckAlarmSev_oid[]   = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 3, 6, 5, 1, 12 };
	size_t   client4PathmonDlckAlarmSev_oid_len = OID_LENGTH(client4PathmonDlckAlarmSev_oid);

	netsnmp_variable_list *notification_vars = NULL;
	static u_long client4PathmonDlckCount = 0;

	unsigned int client4PathmonDlckAlarm = 0;

	unsigned int client4PathmonDlck = 0;
	client4PathmonDlck = pt_monitor_struct->tp_defects_struct.tp_client_path_mon[3].fields.dlck;

	unsigned int client4PathmonDlckAlarmSev = 0;
	client4PathmonDlckAlarmSev = pt_monitor_struct->tp_defects_struct.severity.severity_client[3].PathmonDlck;

	unsigned int send_client4PathmonDlckAlarm = 0;
	if (client4PathmonDlckTemp==0 && client4PathmonDlck==1)
   {
		client4PathmonDlckAlarm = 1;
		send_client4PathmonDlckAlarm = 1;
   }
   else if (client4PathmonDlckTemp==1 && client4PathmonDlck==0)
   {
	   client4PathmonDlckAlarm = 2;
      send_client4PathmonDlckAlarm = 1;
   }
	client4PathmonDlckTemp = client4PathmonDlck;

	snmp_varlist_add_variable(&notification_vars, objid_snmptrap, objid_snmptrap_len, ASN_OBJECT_ID, (u_char *) notification_oid, notification_oid_len * sizeof(oid));
	snmp_varlist_add_variable(&notification_vars, client4PathmonDlck_oid, client4PathmonDlck_oid_len, ASN_INTEGER, (u_char *)&client4PathmonDlckAlarm, sizeof(client4PathmonDlckAlarm));
	snmp_varlist_add_variable(&notification_vars, client4PathmonDlckAlarmSev_oid, client4PathmonDlckAlarmSev_oid_len, ASN_INTEGER, (u_char *)&client4PathmonDlckAlarmSev, sizeof(client4PathmonDlckAlarmSev));

	if(send_client4PathmonDlckAlarm == 1)
	{
		++client4PathmonDlckCount;
		DEBUGMSGTL(("ftnc_notifications", "sending trap %ld\n",client4PathmonDlckCount));
		send_v2trap(notification_vars);
	}

	snmp_free_varbind(notification_vars);
}

void send_tp_client4PathmonDbdi_notification(unsigned int clientreg, void *clientarg)
{
	DEBUGMSGTL(("token", "send_tp_client4PathmonDbdi_notification.\n"));

	oid notification_oid[] = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 2, 2, 0, 169 };
	size_t notification_oid_len = OID_LENGTH(notification_oid);
	oid objid_snmptrap[] = { 1, 3, 6, 1, 6, 3, 1, 1, 4, 1, 0 };
	size_t objid_snmptrap_len = OID_LENGTH(objid_snmptrap);
	oid client4PathmonDbdi_oid[]   = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 2, 2, 1, 7, 1, 88 };
	size_t client4PathmonDbdi_oid_len = OID_LENGTH(client4PathmonDbdi_oid);
	oid      client4PathmonDbdiAlarmSev_oid[]   = { 1, 3, 6, 1, 4, 1, 43484, 1, 1, 3, 6, 5, 1, 11 };
	size_t   client4PathmonDbdiAlarmSev_oid_len = OID_LENGTH(client4PathmonDbdiAlarmSev_oid);

	netsnmp_variable_list *notification_vars = NULL;
	static u_long client4PathmonDbdiCount = 0;

	unsigned int client4PathmonDbdiAlarm = 0;

	unsigned int client4PathmonDbdi = 0;
	client4PathmonDbdi = pt_monitor_struct->tp_defects_struct.tp_client_path_mon[3].fields.dbdi;

	unsigned int client4PathmonDbdiAlarmSev = 0;
	client4PathmonDbdiAlarmSev = pt_monitor_struct->tp_defects_struct.severity.severity_client[3].PathmonDbdi;

	unsigned int send_client4PathmonDbdiAlarm = 0;
	if (client4PathmonDbdiTemp==0 && client4PathmonDbdi==1)
   {
		client4PathmonDbdiAlarm = 1;
		send_client4PathmonDbdiAlarm = 1;
   }
   else if (client4PathmonDbdiTemp==1 && client4PathmonDbdi==0)
   {
	   client4PathmonDbdiAlarm = 2;
      send_client4PathmonDbdiAlarm = 1;
   }
	client4PathmonDbdiTemp = client4PathmonDbdi;

	snmp_varlist_add_variable(&notification_vars, objid_snmptrap, objid_snmptrap_len, ASN_OBJECT_ID, (u_char *) notification_oid, notification_oid_len * sizeof(oid));
	snmp_varlist_add_variable(&notification_vars, client4PathmonDbdi_oid, client4PathmonDbdi_oid_len, ASN_INTEGER, (u_char *)&client4PathmonDbdiAlarm, sizeof(client4PathmonDbdiAlarm));
	snmp_varlist_add_variable(&notification_vars, client4PathmonDbdiAlarmSev_oid, client4PathmonDbdiAlarmSev_oid_len, ASN_INTEGER, (u_char *)&client4PathmonDbdiAlarmSev, sizeof(client4PathmonDbdiAlarmSev));

	if(send_client4PathmonDbdiAlarm == 1)
	{
		++client4PathmonDbdiCount;
		DEBUGMSGTL(("ftnc_notifications", "sending trap %ld\n",client4PathmonDbdiCount));
		send_v2trap(notification_vars);
	}

	snmp_free_varbind(notification_vars);
}
