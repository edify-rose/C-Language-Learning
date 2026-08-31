//	‰Û‘è
#include <stdio.h>
void CalcPostage(short weight);

void CalcPostage(short weight)
{
	if( weight <= 0 )
	{
		printf("d—Ê‚ªˆÙí‚Å‚·\n");
	}
	else if( weight < 100 )
	{
		printf("‘——¿F50‰~‚Å‚·\n");
	}
	else if( weight < 1000 )
	{
		printf("‘——¿F200‰~‚Å‚·\n");
	}
	else
	{
		printf("‘——¿F500‰~‚Å‚·\n");
	}
}