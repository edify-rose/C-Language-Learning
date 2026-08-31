#include <stdio.h>
#include "common.h"
#include "userRegister.h"
#include "bookRegister.h"
#include "search.h"
#if D_STEP >= 4

//-------------------------------------
//	ジャンルの文字列配列
//-------------------------------------
const sint8 genreTable[][32] =
{
	"無効なジャンル",
	"漫画・コミックス",
	"文学・小説",
	"経済",
	"絵本・児童書",
	"理学書",
	"情報・工学書",
	"全てのジャンル",
} ;								// 編集禁止



//*********************************************************
//	関数名	：printSearchBooks
//	機能概要：書籍の検索（ジャンル、発売年）
//*********************************************************
sint8 printSearchBooks(E_GENRE_KIND genre, uint16 year)
{
	uint16 i;
	uint8 foundCount = 0;

	//-1：ジャンルまたは発売年が不正な値
	//不正値＝全てではなくかつ範囲外

	//顧客が指定したgenreが図書館に無い場合は探せない
	//顧客が欲しいジャンルはそもそもうちの図書館にあるのか
	if (genre <= E_GENRE_NONE || genre > E_GENRE_ALL)
	{
		return -1;
	}

	// 年が「0」ではなく、かつ範囲外の場合
	//(year != D_YEAR_ALL)これは0の時だけ認めるという特例で、そのうえで西暦のフィルターにかける
	//D_YEAR_ALLの0は西暦0年ではなく全ての年に対応している。
	//0じゃない西暦の場合...
	if ((year != D_YEAR_ALL) &&((D_TODAY / 10000) < year || 1960 > year))
	{
		return -1;
	}

	//引数のチェックはここまで

	//一冊ずつ検索していく
	for (i = 0;i < D_BOOK_MAXNUM;i++)
	{
		//validFlagが0の場合
		//本棚に本があるか無いか
		if (bookTable[i].validFlag == 0)
		{
			continue; // ifの条件を満たしたら次のループへ進む
		}

		//ループで各書籍のジャンルと発売年を抽出し値に代入する
		// シフトが先になるように()でかこう　　　　　　　　　　　　 						//bookInfo=0x4152の場合（0100 0001 0101 0010）
		uint8 bookgenre = ((bookTable[i].bookInfo >> 12) & 0x000F);                         //大きな木の場合、0100を抽出しbookgenreに代入
		uint8 bookyear = ((bookTable[i].bookInfo >> 5) & 0x007F);                           //大きな木の場合、0001 010を抽出しbookyearに代入

		//三項演算子:[条件] ？ [条件が真の場合の値や処理] ： [条件が偽の場合の値や処理]; 
		//00～59年が2000年代、60～99年が1900年代
		uint16 fullYear = (bookyear < 60) ? (2000 + bookyear) : (1900 + bookyear);     //大きな木の場合西暦の下2桁は10年なので2010となる

		//「?かどうか（真偽値）」を表すプレフィックス (is)
		// isGenreMatch変数には真なら1偽なら0が入る
		//引数のgenreが全て、またはbookgenreと同じなら『真』
		uint8 isGenreMatch = (genre == E_GENRE_ALL) || (bookgenre == genre);

		// 「年が全て」または「年が一致」
		//引数のyearが全て、またはbookyearと同じなら『真』
		uint8 isYearMatch = (year == D_YEAR_ALL) || (year == fullYear);

		//マスク処理により、貸出フラグの状態をstatusに代入した。printfで出力時に使う
		uint8 status = bookTable[i].bookInfo & 0x01;


		// 両方の条件に合致した場合
		if ((isGenreMatch == 1) && (isYearMatch == 1))                                                //2010年かつgenre4の本がみつかれば出力
		{
			printf("\n");
			printf("--------------------------------------------\n");
			//9784の後に9桁入れたいので%09dと記載
			printf("ISBNコード    :9784%09d\n", bookTable[i].bookCode);
			printf("タイトル　　  :%s\n", bookTable[i].title);
			//61行目の三項演算子の結果の値を入れたい
			printf("出版年　　　　:%d\n", fullYear);
			printf("ジャンル　　  :%s\n", genreTable[bookgenre]);
			printf("貸し出し状況  :%s\n", (status == 1) ? "貸し出し中" : "未貸し出し");
			printf("--------------------------------------------\n");
			printf("\n");

			//検索条件と一致して実際に出力された本が何冊あったかcountしていく
			foundCount++;
		}
	}
	// 1冊もヒットしなかった場合エラー

	if (foundCount == 0)
	{
		printf("\n");
		printf("該当する書籍が見つかりませんでした\n");
		printf("\n");
	}
	return 0;

}

#endif

