#include "gcctx.h"
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

	ten_ohpp_sfu_sreset(mod_a, CS_RESET_DEASSERT);

	cs_uint16 otnohen = 16;
	ten_ohpp_sfu_set_otnohen(mod_a, otnohen);

	cs_uint16 cct1fpl = 0;
	cs_uint16 cct1fpp = 0;
	cs_uint16 cct1col = 0;
	cs_uint16 cct1dol = 0;
	cs_uint16 cct1ln = 0;
	cs_uint16 cct1cmp = 0;
	ten_ohpp_sfu_cct1cfg0(mod_a, cct1fpl, cct1fpp, cct1col, cct1dol, cct1ln, cct1cmp);

	cs_uint16 cct1ss = 8;
	cs_uint16 cct1frq = 2;
	ten_ohpp_sfu_cct1cfg1(mod_a, cct1ss, cct1frq);

	cs_uint16 cct1md = 2;
	cs_uint16 cct1bs = 14;
	ten_ohpp_sfu_cct1cfg2(mod_a, cct1md, cct1bs);

	cs_uint16 ccr1mux = 1;
	ten_ohpp_sfu_cct1cfg1_cct1mux_t41(mod_a, ccr1mux);

	return 0;
}
