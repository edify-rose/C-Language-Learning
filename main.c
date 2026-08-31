//	課題
#include <stdio.h>
#include "cash.h"

//	-------------------------------------------
//		本ファイルは変更する必要はない
//	-------------------------------------------

int main(void)
{
	H_CARD hYamada = NULL;
	H_CARD hSato = NULL;

	//--------------------------------
	//	山田太郎さんのATM

	//	キャッシュカードハンドル生成
	hYamada = createCashcard("山田太郎", 0x1234);
	//戻ってきた部品(作成)を使用してキャッシュカードを作成する

	//	1万円預入れ
	depositCash(hYamada, 10000);

	//	カード情報表示
	printCardInfo(hYamada);

	//	3000円引出し
	withdrawCash(hYamada, 0x1234, 3000);

	//	カード情報表示
	printCardInfo(hYamada);


	//--------------------------------
	//	佐藤次郎さんのATM

	//	キャッシュカードハンドル生成
	hSato = createCashcard("佐藤次郎", 0x1192);

	//	30万円預入れ
	depositCash(hSato, 300000);

	//	カード情報表示
	printCardInfo(hSato);

	//	20万円引出し
	withdrawCash(hSato, 0x1192, 200000);

	//	カード情報表示
	printCardInfo(hSato);


	//--------------------------------
	//	カードの破棄処理

	destroyCashcard(hYamada, 0x1234);
	hYamada = NULL;

	destroyCashcard(hSato, 0x1192);
	hSato = NULL;

	return 0;
}