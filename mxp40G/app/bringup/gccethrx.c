#include "gccethrx.h"
#include "hl_configs.h"
#include <time.h>


int main(int argc, char **argv)
{
	T41_t Chips;
	cs_uint16 dev_id = 0;
	cs_uint16 mod_a;
	cs_uint16 mod_b;
	cs_uint8 dyn_repro = 1; /* 0 = static, 1 = DR client only, 2 = DR line and client */
	int sysclk_freq;
	int sysrefclk = 400;
	cs_uint8 slice_line = 0;
	cs_uint8 slice_client = 0;

	unsigned char gcccnt= 0;
	unsigned int state = 0;
	unsigned int bufsize = 1000;
	unsigned short gccbuf[bufsize];
	unsigned short storecnt=0;
	unsigned short error=0;
//	unsigned short gccdata[4]={0};
	unsigned short gcc0data[2]={0};
	unsigned short gcc1data[2]={0};
	unsigned short gcc2data[2]={0};
	unsigned short dstmac[6]={0};
	unsigned short srcmac[6]={0};
	unsigned char gcc0datah;
	unsigned char gcc0datal;
	unsigned char gcc1datah;
	unsigned char gcc1datal;
	unsigned char gcc2datah;
	unsigned char gcc2datal;
	unsigned char dataloss=0;
	unsigned char datarpt=0;
	unsigned char start_flag = 0;

	union length_union length;
	length.length = 20;

	cs_uint16 chkcnt=0;
	cs_uint16 chkcnttmp=0;

	unsigned int store=0;
	unsigned int i=0;
	unsigned int j=0;
	unsigned int k=0;
	cs_char8 ohdata[64];



	open_upie();

	cs6041_init(dev_id, &Chips, &mod_a, &mod_b);

	ten_ohpp_sfu_set_doaum(mod_a, 0, 0);

	for(i=0; i<1000; i++)
	{
		gccbuf[i]=0;
	}

	i=0;

	time_t start, end;
	struct tm *ts_start;
	char buffer_start[80];
	struct tm *ts_end;
	char buffer_end[80];
	start = time(0);


	while(1)
	{

		sleep(1);

//		ten_ohpp_print_doi_ram(mod_a, 0);
//		ten_ohpp_print_doe_ram(mod_a, 0);
		while(ten_ohpp_sfu_get_state(0, TEN_OHPP_SFU_STATE_DOAIRF)!=CS_OK)
		{
			printf("READ: waiting for TEN_OHPP_SFU_STATE_DOAIRF...\n");
		}

//		gcc0datah=ten_ohpp_get_doe_ram_byte (0, 0, TEN_OTNOH_OTUKOH_BYTE5);
//		gcc0datal=ten_ohpp_get_doe_ram_byte (0, 0, TEN_OTNOH_OTUKOH_BYTE6);
		gcc1data[1]=ten_ohpp_get_doe_ram_byte (0, 0, TEN_OTNOH_GCC1_BYTE1);
		gcc1data[0]=ten_ohpp_get_doe_ram_byte (0, 0, TEN_OTNOH_GCC1_BYTE2);
		gcc2data[1]=ten_ohpp_get_doe_ram_byte (0, 0, TEN_OTNOH_GCC2_BYTE1);
		gcc2data[0]=ten_ohpp_get_doe_ram_byte (0, 0, TEN_OTNOH_GCC2_BYTE2);
		chkcnt=(gcc1data[1]);
		chkcnt=(chkcnt << 8);
		chkcnt=chkcnt|(gcc1data[0]);
		printf("GCC1DATA[0]= %u, GCC1DATA[1]=%u, CHKCNT=%u\n", gcc1data[0], gcc1data[1], chkcnt);

		// Check counters for data loose
		if(chkcnt==chkcnttmp+1)
		{
			dataloss=0;
			datarpt=0;
		}
		else if (chkcnt>(chkcnttmp+1))
		{
			dataloss=1;
		}
		else if (chkcnt==chkcnttmp)
		{
			datarpt=1;
		}


		printf("DATALOSS=%u\n", dataloss);
		printf("DATARPT=%u\n", datarpt);

		chkcnttmp=chkcnt;

		printf("OHPP DOI/DOE RAMs:\n");
//		ten_ohpp_print_doi_ram(mod_a, 0);
//		ten_ohpp_print_doe_ram(mod_a, 0);

//		ten_ohpp_get_doe_ram(0,0,ohdata);
//		gcc0data=ohdata[6];
//		gcc1data=ohdata[25];
//		gcc2data=ohdata[26];

		i=0;
		while(i<2 && dataloss==0 && datarpt==0)
		{
			printf("STATE=%u, GCC2DATA[%u]=%u\n", state, i, gcc2data[i]);

			// Detect Ethernet preamble
			if (state==0)
			{
				printf("==== WAITING FOR PREAMBLE... ====\n");

				if(gcc2data[i] == 0xAA)
				{
					state=1;
				}
			}
			else if (state==1 && gcc2data[i] == 0xAA)
			{
				state=2;
			}
			else if (state==2 && gcc2data[i] == 0xAA)
			{
				state=3;
			}
			else if (state==3 && gcc2data[i] == 0xAA)
			{
				state=4;
			}
			else if (state==4 && gcc2data[i] == 0xAA)
			{
				state=5;
			}
			else if (state==5 && gcc2data[i] == 0xAA)
			{
				state=6;
			}
			else if (state==6 && gcc2data[i] == 0xAA)
			{
				state=7;
				printf("==== PREAMBLE DETECTED ====\n");
			}
			else if (state==7 && gcc2data[i] == 0xAB)
			{
				state=8;
				printf("==== START OF FRAME DETECTED ====\n");
				store=1;
			}
			else if (state==8)
			{
				dstmac[5]= gcc2data[i];
				state = 9;
			}
			else if (state==9)
			{
				dstmac[4]= gcc2data[i];
				state = 10;
			}
			else if (state==10)
			{
				dstmac[3]= gcc2data[i];
				state = 11;
			}
			else if (state==11)
			{
				dstmac[2]= gcc2data[i];
				state = 12;
			}
			else if (state==12)
			{
				dstmac[1]= gcc2data[i];
				state = 13;
			}
			else if (state==13)
			{
				dstmac[0]= gcc2data[i];
				printf("DSTMAC= ");
				for(k=0; k<6; k++)
				{
					printf("%u ", dstmac[k]);
				}
				printf("\n");
				state = 14;
			}
			else if (state==14)
			{
				srcmac[5]= gcc2data[i];
				state = 15;
			}
			else if (state==15)
			{
				srcmac[4]= gcc2data[i];
				state = 16;
			}
			else if (state==16)
			{
				srcmac[3]= gcc2data[i];
				state = 17;
			}
			else if (state==17)
			{
				srcmac[2]= gcc2data[i];
				state = 18;
			}
			else if (state==18)
			{
				srcmac[1]= gcc2data[i];
				state = 19;
			}
			else if (state==19)
			{
				srcmac[0]= gcc2data[i];
				printf("SRCMAC= ");
				for(k=0; k<6; k++)
				{
					printf("%u ", srcmac[k]);
				}
				printf("\n");
				state = 20;
			}
			else if (state==20)
			{
				length.fields.low = gcc2data[i];
				state = 21;
			}
			else if (state==21)
			{
				length.fields.high = gcc2data[i];
				printf("LENGTH=%u\n", length.length);
				state = 22;
			}

			else if(state==22)
			{
				if(j<bufsize)
				{
					if(storecnt<length.length)
					{
						gccbuf[j]=gcc2data[i];
						j++;
						storecnt++;
					}
					else
					{
						printf("==== STORED DATA ====\n");
						for(k=0; k<length.length; k++)
						{
							printf("%u ", gccbuf[k]);
						}
						printf("\n");

						storecnt=0;
						state = 0;
					}
				}
			}
/*
			else if (state==15)
			{
				printf("==== Stored data ====\n");
				for(k=0; k<52; k++)
				{
					printf("%u ", gccbuf[k]);
				}
				printf("\n");
				state=0;
				printf("==== WAITING FOR PREAMBLE... ====\n");
				break;
			}
*/
			i++;
//			printf("\n");

//		sleep(1);
//		clear_screen();
		}
	}

	end = time(0);

	printf("Number of reads:%d\n", i );

	ts_start = localtime(&start);
	strftime(buffer_start, sizeof(buffer_start), "\n Start time:\t %a %Y-%m-%d %H:%M:%S %Z \n", ts_start);
	printf("%s\n", buffer_start);

	ts_end = localtime(&end);
	strftime(buffer_end, sizeof(buffer_end), " End time:\t %a %Y-%m-%d %H:%M:%S %Z \n", ts_end);
	printf("%s\n", buffer_end);

/*
	for(i=0; i<1000; i++)
	{
		printf("%u ", gccbuf[i]);
	}
*/

//	ten_ohpp_get_doe_ram_byte(0, 0, TEN_OTNOH_GCC1_BYTE1);


	close_upie();
	return 0;
}
