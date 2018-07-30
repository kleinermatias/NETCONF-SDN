#include "gccrx.h"
#include "hl_configs.h"

int main(int argc, char **argv)
{
	open_upie();

	T41_t Chips;
	cs_uint16 dev_id = 0;
	cs_uint16 mod_a;
	cs_uint16 mod_b;

	cs_uint16 ccr0fpl = 0;

	cs6041_init(dev_id, &Chips, &mod_a, &mod_b);
	ten_ohpp_sfu_set_doaum(mod_a, 0, 0);

	ten_ohpp_sfu_sreset(mod_a, CS_RESET_DEASSERT);

	cs_uint16 otnohen = 16;
	ten_ohpp_sfu_set_otnohen(mod_a, otnohen);

	cs_uint16 ccr1fpl = 0;
	cs_uint16 ccr1fpp = 0;
	cs_uint16 ccr1col = 0;
	cs_uint16 ccr1dol = 0;
	cs_uint16 ccr1ln = 0;
	cs_uint16 ccr1cmp = 0;
	ten_ohpp_sfu_ccr1cfg0(mod_a, ccr1fpl, ccr1fpp, ccr1col, ccr1dol, ccr1ln, ccr1cmp);

	cs_uint16 ccr1ss = 8;
	cs_uint16 ccr1frq = 2;
	ten_ohpp_sfu_ccr1cfg1(mod_a, ccr1ss, ccr1frq);

	cs_uint16 ccr1md = 2;
	cs_uint16 ccr1bs = 14;
	ten_ohpp_sfu_ccr1cfg2(mod_a, ccr1md, ccr1bs);

	cs_uint16 ccr1mux = 1;
	ten_ohpp_sfu_ccr1cfg1_ccr1mux_t41(mod_a, ccr1mux);

	while(1)
	{
		sleep(3);

		ten_ohpp_print_doe_ram(mod_a, 0);
	}

	return 0;
}
