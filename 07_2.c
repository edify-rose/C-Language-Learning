//	‰Û‘è
#include <stdio.h>

int main(void)
{

	short point[] = { 234, 819, 18, -6492, 795, 20302, 2431, 9029, 0, -28009 };

	//	’è‹`‚Æ‹t‡‚É’l‚ð•\Ž¦‚·‚é

	int i;



	for (i = (sizeof(point)/sizeof(point[0]))-1;i>=0;i--)
	{
		printf("%d\n", point[i]);
	}
	return 0;
}