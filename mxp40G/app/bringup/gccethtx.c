#include "gccethtx.h"
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
	cs_uint8 chkcntl=0;
	cs_uint8 chkcnth=0;
	cs_uint16 chkcnt=0;

	unsigned char gcccnt= 0;
	unsigned int state = 0;
	unsigned short gccbuf[5000];
	unsigned int bytecnt=0;
	unsigned int framecnt=0;
	unsigned int framesize=64;
	unsigned int numframes=1000;

	// Data for writing of INDIVIDUAL BYTES
	unsigned short framedata[4][64]=
	{{170, 170, 170, 170, 170, 170, 171, 170, 1, 2, 3, 4, 5, 6, 7, 8,  9, 10, 11, 12, 0, 40,    15, 16,  17, 18, 19, 20, 21, 22, 23, 24,  25, 26, 27, 28, 29, 30, 31, 32,  33, 34, 35, 36, 37, 38, 39, 40,  41, 42, 43, 44, 45, 46, 47, 48,  49, 50, 51, 52, 53, 54, 55, 56},
	{170, 170, 170, 170, 170, 170, 171, 170, 9, 10, 11, 12, 13, 14, 15, 16,  17, 18, 19, 20, 0, 30,    23, 24,  25, 26, 27, 28, 29, 30, 31, 32,  33, 34, 35, 36, 37, 38, 39, 40,  41, 42, 43, 44, 45, 46, 47, 48,  49, 50, 51, 52, 53, 54, 55, 56,  57, 58, 59, 60, 61, 62, 63, 64},
	{170, 170, 170, 170, 170, 170, 171, 170, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 0, 20,    31, 32,  33, 34, 35, 36, 37, 38, 39, 40,  41, 42, 43, 44, 45, 46, 47, 48,  49, 50, 51, 52, 53, 54, 55, 56,  57, 58, 59, 60, 61, 62, 63, 64,  65, 66, 67, 68, 69, 70, 71, 72},
    {170, 170, 170, 170, 170, 170, 171, 170, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 0, 10,    39, 40,  41, 42, 43, 44, 45, 46, 47, 48,  49, 50, 51, 52, 53, 54, 55, 56,  57, 58, 59, 60, 61, 62, 63, 64,  65, 66, 67, 68, 69, 70, 71, 72,  73, 74, 75, 76, 77, 78, 79, 80}};

	// Data for writing of whole RAM (too slow)
	cs_uint16 ohdata[16][32]=
	{{0,0,0,0,0,1,0,0, 0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0, 43690,43690,0,0,0,0,0,0},
	 {0,0,0,0,0,2,0,0, 0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0, 43690,43691,0,0,0,0,0,0},
	 {0,0,0,0,0,3,0,0, 0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0, 1,2,0,0,0,0,0,0},
	 {0,0,0,0,0,4,0,0, 0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0, 3,4,0,0,0,0,0,0},

	 {0,0,0,0,0,5,0,0, 0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0, 5,6,0,0,0,0,0,0},
	 {0,0,0,0,0,6,0,0, 0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0, 7,8,0,0,0,0,0,0},
	 {0,0,0,0,0,7,0,0, 0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0, 9,10,0,0,0,0,0,0},
	 {0,0,0,0,0,8,0,0, 0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0, 11,12,0,0,0,0,0,0},

	 {0,0,0,0,0,9,0,0, 0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0, 13,14,0,0,0,0,0,0},
	 {0,0,0,0,0,10,0,0, 0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0, 15,16,0,0,0,0,0,0},
	 {0,0,0,0,0,11,0,0, 0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0, 17,18,0,0,0,0,0,0},
	 {0,0,0,0,0,12,0,0, 0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0, 19,20,0,0,0,0,0,0},

	 {0,0,0,0,0,13,0,0, 0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0, 21,22,0,0,0,0,0,0},
	 {0,0,0,0,0,14,0,0, 0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0, 23,24,0,0,0,0,0,0},
	 {0,0,0,0,0,15,0,0, 0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0, 25,26,0,0,0,0,0,0},
	 {0,0,0,0,0,16,0,0, 0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0, 27,28,0,0,0,0,0,0}
	};

//	 {0,0,0,0,0,0,0,0,0,0, 0,2, 0,0,0,0, 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, 170,170,170,171,0,0,0,0,0,0,0,0,0,0,0,0,},
//  	 {0,0,0,0,0,0,0,0,0,0, 0,3, 0,0,0,0, 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, 1,2,3,4,0,0,0,0,0,0,0,0,0,0,0,0,},
//  	 {0,0,0,0,0,0,0,0,0,0, 0,4, 0,0,0,0, 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, 5,6,7,8,0,0,0,0,0,0,0,0,0,0,0,0,},
//
//  	 {0,0,0,0,0,0,0,0,0,0, 0,5, 0,0,0,0, 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, 9,10,11,12,0,0,0,0,0,0,0,0,0,0,0,0,},
//  	 {0,0,0,0,0,0,0,0,0,0, 0,6, 0,0,0,0, 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, 13,14,15,16,0,0,0,0,0,0,0,0,0,0,0,0,},
//  	 {0,0,0,0,0,0,0,0,0,0, 0,7, 0,0,0,0, 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, 17,18,19,20,0,0,0,0,0,0,0,0,0,0,0,0,},
//  	 {0,0,0,0,0,0,0,0,0,0, 0,8, 0,0,0,0, 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, 21,22,23,24,0,0,0,0,0,0,0,0,0,0,0,0,},
//
//  	 {0,0,0,0,0,0,0,0,0,0, 0,9, 0,0,0,0, 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, 25,26,27,28,0,0,0,0,0,0,0,0,0,0,0,0,},
//  	 {0,0,0,0,0,0,0,0,0,0, 0,10, 0,0,0,0, 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, 29,30,31,32,0,0,0,0,0,0,0,0,0,0,0,0,},
//  	 {0,0,0,0,0,0,0,0,0,0, 0,11, 0,0,0,0, 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, 33,34,35,36,0,0,0,0,0,0,0,0,0,0,0,0,},
//  	 {0,0,0,0,0,0,0,0,0,0, 0,12, 0,0,0,0, 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, 37,38,39,40,0,0,0,0,0,0,0,0,0,0,0,0,},
//
//  	 {0,0,0,0,0,0,0,0,0,0, 0,13, 0,0,0,0, 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, 41,42,43,44,0,0,0,0,0,0,0,0,0,0,0,0,},
//  	 {0,0,0,0,0,0,0,0,0,0, 0,14, 0,0,0,0, 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, 45,46,47,48,0,0,0,0,0,0,0,0,0,0,0,0,},
//  	 {0,0,0,0,0,0,0,0,0,0, 0,15, 0,0,0,0, 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, 49,50,51,52,0,0,0,0,0,0,0,0,0,0,0,0,},
//  	 {0,0,0,0,0,0,0,0,0,0, 0,16, 0,0,0,0, 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, 53,54,55,56,0,0,0,0,0,0,0,0,0,0,0,0,},
//	};

	open_upie();

	cs6041_init(dev_id, &Chips, &mod_a, &mod_b);

	ten_mpif_global_clock_disable_common(dev_id, CS_ENABLE, TEN_MPIF_GLOBAL_CLOCK_DISABLE_COMMON_OHPP_A);
	ten_mpif_global_reset_common(dev_id, CS_RESET_DEASSERT, TEN_MPIF_GLOBAL_RESET_COMMON_OHPP_A );
	ten_ohpp_sfu_sreset(0, CS_RESET_DEASSERT);
	ten_ohpp_sfu_set_otnohen(0, 16);

	ten_n40g_otnt4x_mfmcfg(0, 1, 0, 0); // Configures the specified MFAS Match unit
	ten_ohpp_sfu_set_doaien(0, 1); // Enable Direct Overhead Access Insertion Unit

//	ten_n40g_otnt4x_doaie(0, TEN_OTNOH_OTUKOH_BYTE5, 1); // Configure which bytes are inserted
//	ten_n40g_otnt4x_doaie(0, TEN_OTNOH_OTUKOH_BYTE6, 1);
	ten_n40g_otnt4x_doaie(0, TEN_OTNOH_GCC1_BYTE1, 1);
	ten_n40g_otnt4x_doaie(0, TEN_OTNOH_GCC1_BYTE2, 1);
	ten_n40g_otnt4x_doaie(0, TEN_OTNOH_GCC2_BYTE1, 1);
	ten_n40g_otnt4x_doaie(0, TEN_OTNOH_GCC2_BYTE2, 1);

	bytecnt=0;

	time_t start, end;
	struct tm *ts_start;
	char buffer_start[80];
	struct tm *ts_end;
	char buffer_end[80];
	start = time(0);


	while(framecnt<numframes)
	{
//		printf("FRAME COUNT= %d \t BYTE COUNT= %d \n", framecnt, bytecnt);

		sleep(1);

		while(ten_ohpp_sfu_get_state(0, TEN_OHPP_SFU_STATE_DOAIBFF)!=CS_OK)
		{
			printf("WRITE: waiting for TEN_OHPP_SFU_STATE_DOAIBFF...\n");
		}

		chkcntl = (unsigned char)chkcnt & 0xFF;
		chkcnth=(unsigned char)(chkcnt>>8) & 0xFF;
		doi_write(chkcnth, chkcntl, 0x00, 0x00);
		chkcnt++;

//		ten_ohpp_set_doi_ram(0, 0, ohdata[bytecnt]);

		if(framecnt==0)
		{
			framecnt++;
		}

		else if(framecnt==1)
		{

			if(bytecnt<framesize)
			{
//				ten_ohpp_set_doi_ram(0, 0, ohdata[bytecnt]);
//				ten_ohpp_set_doi_ram_byte (0, 0, TEN_OTNOH_GCC1_BYTE1, framedata[0][bytecnt]);
				doi_write(chkcnth, chkcntl, framedata[0][bytecnt], framedata[0][bytecnt+1]);
//				chkcnt++;
				bytecnt=bytecnt+2;
			}
			else
			{
				bytecnt=0;
				framecnt++;
			}
		}


		else if (framecnt==2)
		{
			if(bytecnt<framesize)
			{
				doi_write(chkcnth, chkcntl, framedata[0][bytecnt], framedata[0][bytecnt+1]);
//				chkcnt++;
				bytecnt=bytecnt+2;

//				ten_ohpp_set_doi_ram_byte (0, 0, TEN_OTNOH_GCC1_BYTE1, framedata[1][bytecnt]);
//				bytecnt++;
			}
			else
			{
				bytecnt=0;
				framecnt++;
			}
		}
		else if (framecnt==3)
		{
			if(bytecnt<framesize)
			{
				doi_write(chkcnth, chkcntl, framedata[0][bytecnt], framedata[0][bytecnt+1]);
//				chkcnt++;
				bytecnt=bytecnt+2;

//				ten_ohpp_set_doi_ram_byte (0, 0, TEN_OTNOH_GCC1_BYTE1, framedata[2][bytecnt]);
//				bytecnt++;
			}
			else
			{
				bytecnt=0;
				framecnt++;
			}
		}
		else if (framecnt==4)
		{
			if(bytecnt<framesize)
			{
				doi_write(chkcnth, chkcntl, framedata[0][bytecnt], framedata[0][bytecnt+1]);
//				chkcnt++;
				bytecnt=bytecnt+2;

//				ten_ohpp_set_doi_ram_byte (0, 0, TEN_OTNOH_GCC1_BYTE1, framedata[3][bytecnt]);
//				bytecnt++;
			}
			else
			{
				bytecnt=0;
				framecnt++;
			}
		}

		printf("\nOHPP DOI/DOE RAMs:\n");
		ten_ohpp_print_doi_ram(mod_a, 0);
//		ten_ohpp_print_doe_ram(mod_a, 0);

	}

	end = time(0);

	printf("Number of writes:%d\n", framecnt-1 );

	ts_start = localtime(&start);
	strftime(buffer_start, sizeof(buffer_start), "\n Start time:\t %a %Y-%m-%d %H:%M:%S %Z \n", ts_start);
	printf("%s\n", buffer_start);

	ts_end = localtime(&end);
	strftime(buffer_end, sizeof(buffer_end), " End time:\t %a %Y-%m-%d %H:%M:%S %Z \n", ts_end);
	printf("%s\n", buffer_end);


//		printf("==== CGG DOI table ====\n");
//		ten_ohpp_print_doi_ram(0, 0);


//	ten_ohpp_get_doe_ram_byte(0, 0, TEN_OTNOH_GCC1_BYTE1);


	close_upie();
	return 0;
}

void doi_write (unsigned char gcc1h, unsigned char gcc1l, unsigned char gcc2h, unsigned char gcc2l)
{
//	ten_ohpp_set_doi_ram_byte (0, 0, TEN_OTNOH_OTUKOH_BYTE5, gcc0h);
//	ten_ohpp_set_doi_ram_byte (0, 0, TEN_OTNOH_OTUKOH_BYTE6, gcc0l);
	ten_ohpp_set_doi_ram_byte (0, 0, TEN_OTNOH_GCC2_BYTE1, gcc2h);
	ten_ohpp_set_doi_ram_byte (0, 0, TEN_OTNOH_GCC2_BYTE2, gcc2l);
	ten_ohpp_set_doi_ram_byte (0, 0, TEN_OTNOH_GCC1_BYTE1, gcc1h);
	ten_ohpp_set_doi_ram_byte (0, 0, TEN_OTNOH_GCC1_BYTE2, gcc1l);
}
