#include <stdio.h>
#include "common.h"
#include "userRegister.h"
#include "bookRegister.h"
#include "lending.h"
#if D_STEP >= 3


//*********************************************************
//	関数名	：lendBook
//	機能概要：書籍の貸し出し
//*********************************************************
sint8 lendBook(H_PERSON person , uint16 personalPin  , uint32 bookCode)
{
	uint16 i;
	sint8 sameCode=-1;

	if (person == NULL)
	{
		return -1;
	}
	S_LIBRARY_PERSON* Person = (S_LIBRARY_PERSON*)person;
	if (Person->validFlag == 0)
	{
		return -2;
	}
	if (Person->authority == E_AUTHORITY_NONE)
	{
		return -3;
	}
	if (Person->personalPin != personalPin)
	{
		return -4;
	}
	if (Person->lendFlag == 1)
	{
		return -5;
	}
	
	//同じ書籍がみつからなければエラー
	//引数で受け取った数字と同じコードがみつかったらメモしておく。最後にメモが出来ず－1のままなら同じコードは無かったことになるのでエラー
	for (i = 0;i < D_BOOK_MAXNUM;i++)
	{
		if (bookTable[i].bookCode == bookCode)
		{
			sameCode = i;
			break;
		}
	}
	if (sameCode == -1)
	{
		return -6;
	}
	//-7：既に書籍が他の利用者に貸し出されている 
	//既に貸し出された書籍番号を指定した場合、貸し出しフラグは1のはずなので、マスク処理で確認

	if((bookTable[sameCode].bookInfo & 0x01) == 0x01)
	{
			return -7;
	}

	//ここから貸し出し手続き

	Person->lendFlag = 1;
	Person->bookCode = bookCode;
	//０ビットめの０に、ビットを立てたいからOR演算子を使う
	//以下は書籍側の処理
	//桁を合わせるために0x0001でビットを立てた　0が1つで4bit
	bookTable[sameCode].bookInfo |= 0x0001;

	return 0;
}



//*********************************************************
//	関数名	：returnBook
//	機能概要：書籍の返却
//*********************************************************
sint8 returnBook(H_PERSON person , uint16 personalPin , uint32 bookCode)
{
	uint8 i;
	sint8 sameCode = -1;

	if (person == NULL)
	{
		return -1;
	}
	S_LIBRARY_PERSON* Person = (S_LIBRARY_PERSON*)person;
	if (Person->validFlag == 0)
	{
		return -2;
	}
	if (Person->authority == E_AUTHORITY_NONE)
	{
		return -3;
	}
	if (Person->personalPin != personalPin)
	{
		return -4;
	}
	if (Person->lendFlag == 0)
	{
		return -5;
	}
	//同じ書籍がみつからなければエラー
	//引数で受け取った数字と同じコードがみつかったらメモしておく。最後にメモが出来ず－1のままなら同じコードは無かったことになるのでエラー
	for (i = 0;i < D_BOOK_MAXNUM;i++)
	{
		if (bookTable[i].bookCode == bookCode)
		{
			sameCode = i;
			break;
		}
	}
	if (sameCode == -1)
	{
		return -6;
	}

	//貸し出されていない書籍を指定した場合、bookInfoの0ビットめは0になるはず
	if ((bookTable[sameCode].bookInfo & 0x01) == 0x00)
	{
		return -7;
	}
	if (Person->bookCode != bookCode)
	{
		return -8;
	}

	//貸し出しの時の処理を初期化する
	Person->lendFlag = 0;
	Person->bookCode = 0;
	//0ビットめのビットを落としたいからAND演算子を使う
	//1111 1111 1111 1110 が0xFFFEの事
	bookTable[sameCode].bookInfo  &= 0xFFFE;

	return 0;
}


#endif