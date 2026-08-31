#include <stdio.h>
#include <string.h>
#include "common.h"
#include "bookRegister.h"
#include "userRegister.h"
#if D_STEP >= 2

//-----------------------------------------------------------------------------
//	書籍テーブル（プログラム下に初期値で与えられた書籍の詳細情報あり）
//-----------------------------------------------------------------------------
S_LIBRARY_BOOK bookTable[D_BOOK_MAXNUM] =
{
	{1, 167110123,	0x2110, "容疑者Xの献身"},
	{1, 91208859,	0x19E8, "うる星やつら"},
	{1, 757554894,	0x1232, "薬屋のひとりごと(1)"},
	{1, 575519945,	0x2228, "君の膵臓をたべたい"},
	{1, 41090602,	0x4288, "パンどろぼう"},
	{1, 63259681,	0x1042, "のだめカンタービレ(1)"},
	{1, 751525401,	0x4152, "おおきな木"},
};														// 編集禁止



//*********************************************************
//	関数名	：registBook
//	機能概要：書籍情報の登録
//*********************************************************
sint8 registBook(H_PERSON staff, uint16 staffPin, uint32 bookCode, E_GENRE_KIND genre, uint16 year, uint16 month, sint8* title)
{
	uint16 i; //書籍は10冊まで　unsigned char
	sint8 insertIndex = -1;
	uint16 count = 0;
	uint16 bookInfo;

	S_LIBRARY_PERSON* Staff = (S_LIBRARY_PERSON*)staff;

	if (staff == NULL)
	{
		return -1;
	}
	if (Staff->validFlag == 0)
	{
		return -2;
	}
	if (Staff->authority != E_AUTHORITY_STAFF)
	{
		return -3;
	}
	if (Staff->personalPin != staffPin)
	{
		return -4;
	}

	//ここからは登録したい書籍情報のチェック


	//登録したい本のジャンルが有効な範囲内で指定されているか     
	if (genre <=E_GENRE_NONE || genre >= E_GENRE_ALL)
	{
		return -5;
	}
	
	//発売日が1960年～今年の西暦の間で指定されているか(年のチェックのみでよい)
	//来年からも対応できるようにする
	if (year < 1960 || year > (D_TODAY /10000)) 
	{
		return -5;
	}
	//タイトルの文字列がNULLではないか、タイトルの文字列が1文字以上入っているか
	if (title == NULL || strlen(title) == 0)
	{
		return -5;
	}
	//タイトルの文字列サイズが最大値を超えていないか
	if (strlen(title) >= D_BOOLTITLE_MAXSIZE)
	{
		return -5;
	}
	//ここまでで、受け取ってもいい引数だと確認できた

	
	
	
	//0bit目そもそも何をいれたかったかよく考える　何の意味の0と1なのか→新規登録の関数なので未貸し出しだから『0』
	bookInfo = ((genre << 12) | (year << 5) | (month << 1) | 0);

#if 0
	//書籍が既に登録されているか
	for (i = 0;i < D_BOOK_MAXNUM;i++)
	{
		//書籍が既に登録されていたらエラーつまり、bookCodeが被っていたらエラー
		if (bookTable[i].bookCode == bookCode)
		{
			return -6;
		}
		if (bookTable[i].validFlag == 1)
		{
			count++;
		}
		else
		{
			if (insertIndex == -1)
			{
				insertIndex = i;
			}
		}
	}
#endif
//
	for (i = 0;i < D_BOOK_MAXNUM;i++)
	{
		if (bookTable[i].bookCode == bookCode)
		{
			return -6;
		}
		//もしその本のvalidFlagが無効で、かつ空き箱のメモが－1としたとき
		if ((bookTable[i].validFlag == 0) && (insertIndex == -1))
		{
			//最後までループしないようにif (insertIndex == -1)で最初の部屋に登録できるようにした。
			insertIndex = i;
		}
	
	}
	//書籍登録数が最大に達していたらエラー
	//insertIndexが－1のままということはつまり、代入できていないから空きがない→書籍登録が最大に達している
	if (insertIndex==-1)
	{
		return -7;
	}

	//ここからbookTableに値をいれていく
	bookTable[insertIndex].validFlag = 1;  //書籍登録
	bookTable[insertIndex].bookCode = bookCode;   //登録時に入力する書籍管理番号
	bookTable[insertIndex].bookInfo = bookInfo;  //登録時に入力される変換した値
	strcpy_s(bookTable[insertIndex].title, D_BOOKTITLE_MAXSIZE, title);   // 書籍タイトルをコピー,strcpy_s(コピー先のアドレス,コピー先の箱のサイズ（byte単位でいくつ欲しいか）,コピー元の文字列)

	return 0;
}
//*********************************************************
//	関数名	：deleteBook
//	機能概要：書籍情報の削除
//*********************************************************
sint8 deleteBook(H_PERSON staff , uint16 staffPin , uint32 bookCode)
	{
	uint8 i;
	uint8 count = 0;

	S_LIBRARY_PERSON* Staff = (S_LIBRARY_PERSON*)staff;

	//本当に届いたか
	if (staff == NULL)
	{
		return -1;
	}

	//ユーザーのハンドルのバリッドフラグが無効
	if (Staff->validFlag == 0)
	{
		return-2;
	}
	//スタッフ以外の人が居座っていないかの確認
	if (Staff->authority != E_AUTHORITY_STAFF)
	{
		return -3;
	}
	//スタッフ情報のパスワードが異なると異常
	if (Staff->personalPin != staffPin)
	{
		return -4;
	}

    //削除処理↓
	//該当の書籍が存在しない
#if 0

	//棚に並んだ本を一冊ずつ確認し、最大登録数とカウントが同じならエラー、同じブックコードが見つかればブレイクしてループから出る

	for (i = 0;i < D_BOOK_MAXNUM;i++)
	{
		if (bookCode != bookTable[i].bookCode)
		{
			count++;
		}
		if (D_BOOK_MAXNUM == count)
		{
			return -5;
		}

		if (bookCode == bookTable[i].bookCode)
		{
			break;
		}
	}
#endif

#if 1
//棚に並んだ本を一冊ずつ確認し、同じコードが見つかったらブレイクでループを抜けもしループ回数iがD_BOOK_MAXNUMと等しければ同じコードが見つからなかったことになるのでエラー
	for (i = 0;i < D_BOOK_MAXNUM;i++)
	{
		if (bookCode == bookTable[i].bookCode)
		{
			break;
		}
	}
	if (i == D_BOOK_MAXNUM)
	{
		return -5;
	} 
#endif


	//ユーザーがまだ書籍を返却していない
	//bookInfoの0bitめを確認したいのでマスク処理をして1か0かを確認し、1と等しければ貸出中でエラー
	if ((bookTable[i].bookInfo & 0x01) == 0x01)
	{
		return -6;
	}
	
	//ここからbookTableに値をいれていく
	bookTable[i].validFlag = 0;  //書籍登録リセット
	bookTable[i].bookCode = 0;   //登録時に入力する書籍管理番号
	bookTable[i].bookInfo = 0;  //登録時に入力される変換した値
	memset(bookTable[i].title, '\0', D_BOOKTITLE_MAXSIZE);  //入っていた文字を全てリセット(ヌル文字にする) memset(入れたい場所,入れたい文字,入れたい文字数);
	
	return 0;
}

/********************************************/
//
//	参考：登録書籍の詳細情報
//
//	------------------------------------
//	タイトル：容疑者Xの献身
//	ISBNコード：978-4-16-711012-3
//	ジャンル：文学・小説
//	発売年月日：2008年8月5日
//	------------------------------------
//	タイトル：うる星やつら
//	ISBNコード：978-4-0912-0885-9
//	ジャンル：漫画・コミックス
//	発売年月日：1979年4月18日
//	------------------------------------
//	タイトル：薬屋のひとりごと(1)
//	ISBNコード：978-4-7575-5489-4
//	ジャンル：漫画・コミックス
//	発売年月日：2017年9月25日
//	------------------------------------
//	タイトル：君の膵臓をたべたい
//	ISBNコード：978-4-575-51994-5
//	ジャンル：文学・小説
//	発売年月日：2017年4月27日
//	------------------------------------
//	タイトル：パンどろぼう
//	ISBNコード：978-4-04-109060-2
//	ジャンル：絵本・児童書
//	発売年月日：2020年4月16日
//	------------------------------------
//	タイトル：のだめカンタービレ(1)
//	ISBNコード：978-4-06-325968-1
//	ジャンル：漫画・コミックス
//	発売年月日：2002年1月8日
//	------------------------------------
//	タイトル：おおきな木
//	ISBNコード：978-4-7515-2540-1
//	ジャンル：絵本・児童書
//	発売年月日：2010年9月1日
//	------------------------------------
//
/********************************************/

#endif