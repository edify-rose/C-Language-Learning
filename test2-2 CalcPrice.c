//	â€ëË
#include <stdio.h>

void CalcPrice(short calltime);

#define OVERTIME (1800)
#define TIMEBORDER (600)
#define FIXPRICE	(1500)

#define TIMEDIV (10)
#define TIMEROUND (TIMEDIV - 1)

#define DIV_VALUE_1 (10)
#define DIV_VALUE_2 (5)

void CalcPrice(short calltime)
{
	short price = 0;

	if(calltime <= 0)
	{
		printf("ì¸óÕÇ™àŸèÌÇ≈Ç∑ÅB");
	}
	else
	{
		if( calltime > OVERTIME )
		{
			price = FIXPRICE;
		}
		else if( calltime > TIMEBORDER )
		{
			price = ((TIMEBORDER / TIMEDIV) * DIV_VALUE_1) + ((((calltime - TIMEBORDER) + TIMEROUND) / TIMEDIV) * DIV_VALUE_2);
		}
		else
		{
			price = ((calltime + TIMEROUND) / TIMEDIV) * DIV_VALUE_1;
		}
		
		printf("óøã‡ÅF%dâ~",price);
	}
}