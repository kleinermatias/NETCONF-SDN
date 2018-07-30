#include "setdate.h"
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <termios.h>
#include <signal.h>

int main(int argc, char **argv)
{
	set_date_from_rtc();

return 0;
}

