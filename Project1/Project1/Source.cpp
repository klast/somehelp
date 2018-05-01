#include "combination.h"
#include <conio.h>

int main()
{
	combination comb(6, 4);
	comb.run_and_timer();

	comb.run();

	_getch();
	return 0;
}