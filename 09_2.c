//	‰Û‘è
#include <stdio.h>

#define D_SHIKI		(0)			//	³‰ªq‹Kƒtƒ‰ƒO
//#define D_BUSON					//	—^Ó•“‘ºƒtƒ‰ƒO

int main(void)
{
#if  0
	//	”o‹å‡@
	printf("ŒÃ’r‚â\n");			/* ¼”ö”mÔ	*/
	printf("Š^”ò‚±‚Ş\n");
	printf("…‚Ì‚¨‚Æ\n\n");
#endif

#if D_SHIKI	
//#if D_SHIKI‚Íƒ}ƒNƒ’è‹`‚µ‚Ä‚¢‚é‚Ì‚Å if 1‚Ì‚±‚Æ
	//	”o‹å‡A
	printf("Š`‚­‚Ö‚Î\n");		/* ³‰ªq‹K */
	printf("à‚ª–Â‚é‚È‚è\n");
	printf("–@—²›\n\n");
#endif

#ifdef D_BUSON	
	//	”o‹å‡B
	printf("Ø‚Ì‰Ô‚â\n");		/* —^Ó•“‘º */
	printf("Œ‚Í“Œ‚É\n");
	printf("“ú‚Í¼‚É\n\n");
#endif

	return 0;
}