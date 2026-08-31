//	---------------------------------------------------
//		本ファイルは編集禁止
//	---------------------------------------------------

#include <stdio.h>
#include "common.h"
#include "userRegister.h"
#include "bookRegister.h"
#include "system.h"


//*********************************************************
//
//	各パラメータの初回クリア処理
//	
//*********************************************************
void libraryInit(void)
{
	uint32 i;

	/* 利用者テーブルの初回起動時リセット作業 */
	for (i = 0; i < D_PERSON_MAXNUM; i++)
	{
		personalTable[i].validFlag = 0;
		personalTable[i].authority = E_AUTHORITY_NONE;
		personalTable[i].personalID = 0;
		personalTable[i].personalPin = 10000;
		personalTable[i].lendFlag = 0;
		personalTable[i].bookCode = 0;

	}

#if D_STEP >= 2

	/* 書籍テーブルの初回起動時リセット作業 */
	for (i = 8; i < D_BOOK_MAXNUM; i++)
	{
		bookTable[i].validFlag = 0;
		bookTable[i].bookCode = 0;
		bookTable[i].bookInfo = 0;
	}

#endif

}

//*********************************************************
//
//	初期スタッフ作成
//
//	戻り値：初期スタッフのハンドル情報
//	
//*********************************************************
H_PERSON createFirstStaff(void)
{
	/* 初期スタッフ */
	S_LIBRARY_PERSON staff = { 1 , E_AUTHORITY_STAFF , 0xb4953269 , "明智　光秀" , 5677 , 0 , 0 };

	personalTable[0] = staff;

	return &personalTable[0];
}
