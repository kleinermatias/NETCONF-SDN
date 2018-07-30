#include "hl_qsfp.h"


void hl_qsfp_init(void)
{

	int identifier;

	ltc_enable_latch();

	qsfp_reset();
	qsfp_enable_communication();
	qsfp_get_id(&identifier);

	if (identifier == 13)
		printf ("QSFP+ Module Initialization ...... OK \n");
	else
		printf ("QSFP+ Module Initialization ...... FAIL \n");
}
