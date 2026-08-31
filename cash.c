//	課題
#include <stdio.h>
#include <stdlib.h>  //malloc関数呼び出し
#include "cash.h"

//秘密のファイルなので以下の構造体はヘッダファイルには書かずcash.cに書く
//キャッシュカードの非公開情報は下記として定義
//外部にハンドル情報として提供する際はヘッダファイルで定義したH_CARDとして型情報を隠蔽すること。
//S_CARD_INFOをそのままみせてしまうと下記の機密データが外部からアクセス可能になってしまう為。

typedef struct
{
	char name[32];         //申込者氏名。生成時の情報で初期化。  //32byte
	unsigned short pin;    //暗証番号。生成時の情報で初期化。    //2byte
	unsigned long cash;    //現金残高。初期値０。                //4byte
}S_CARD_INFO;




H_CARD createCashcard(char* name, unsigned short pin)
{
	//約40byte(構造体1個分)のメモリのサイズを貸してください
	//*card→malloc関数はヒープメモリを確保する関数の為指し示すメモリはヒープメモリ
	//作成したい人の情報を入れる場所またはキャッシュカードの在庫があるかの確認をしている。
	//returnでこのカードを使ってねと返す
	//S_CARD_INFO*個々までが型名　cardが変数名(キャッシュカードハンドル)

	S_CARD_INFO* card = (S_CARD_INFO*)malloc(sizeof(S_CARD_INFO));
	if (card == NULL)
	{
		return NULL;
	}
	//↓場所が用意できている場合。場所にその人の情報を登録する。
	//入れたい場所＝入れたい内容
	
	strcpy(card->name, name);  //nameの正体は配列　
	card->pin = pin;
	card->cash = 0;

	return  card;
}
int printCardInfo(H_CARD handle)
{
	//上の関数でreturnした時データ型はH_CARDなので、情報が隠蔽されるため枠組みもなくなる
	//なので、再度S_CARD_INFO *でキャストして型にはめる(どこから何処までが名前かとか)

	S_CARD_INFO * card = (S_CARD_INFO *)handle;		//	ハンドル情報の参照方法ヒント！
	if (card == NULL )
	{
		return -1;
	}
	printf("氏名:%s\n残高:%d\n", card->name, card->cash);
	return 0;
}

int depositCash(H_CARD handle, unsigned long cash)
{
	S_CARD_INFO* card = (S_CARD_INFO*)handle;
	if (card == NULL)
	{
		return -1;
	}
	if (cash == 0)
	{
		return -2;
	}
	card->cash += cash;
	return 0;
}

int withdrawCash(H_CARD handle, unsigned short pin, unsigned long cash)
{
	S_CARD_INFO* card = (S_CARD_INFO*)handle;
	if(card==NULL)
	{
		return -1;
	}
	if (card->pin != pin)
	{
		return -2;
	}
	if (card->cash < cash)
	{
		return -3;
	}
	card->cash -= cash;
	return 0;
}



int destroyCashcard(H_CARD handle, unsigned short pin)
{
	S_CARD_INFO* card = (S_CARD_INFO*)handle;
	if (card == NULL)
	{
		return -1;
	}
	if (card->pin != pin)
	{
		return -2;
	}
	//free(card);ではメモリの開放を行うが番地はまだ入ったまま
	//Cardの中に入っている番地情報をnullを入れて消去する
	free(card);
	card = NULL;
	return 0;
}