//	‰Û‘è
#include <stdio.h>

int main(void)
{
	int i;
	int j;

	//for‡@1`9‰ñŒJ‚è•Ô‚·for‡A1‚²‚Æ‚Éi‚Ì’l‚ği‰ñŒJ‚è•Ô‚·¨i‰ñŒJ‚è•Ô‚µ‚½‚ç‰üs(‚±‚ê‚ğƒ‹[ƒv‚·‚é)
	for (i = 1;i <= 9;i++)
	{
		for (j = 0;j < i;j++)
		{
			printf("%d", i);
		}
		printf("\n");
	}
	return 0;
}