#include "combination.h"
#include <conio.h>

int main()
{
	combination comb(6, 4);
	comb.run();

	comb.set_printFlag(false);
	comb.set_saveFlag(false);
	comb.timer();

	

	_getch();
	return 0;
}