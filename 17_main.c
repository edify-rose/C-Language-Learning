//	---------------------------------------------------
//		本ファイルは編集禁止
//	---------------------------------------------------

#include <stdio.h>
#include "common.h"
#include "main.h"


int main(void)
{
	H_PERSON firstStaff = NULL;		// 全課題共通：初期スタッフ


#if	D_STEP == 1

	H_PERSON userA1 = NULL;			// 課題1：テスト用利用者①
	H_PERSON userA2 = NULL;			// 課題1：テスト用利用者②
	H_PERSON userA3 = NULL;			// 課題1：テスト用利用者③
	sint8 resultA = 0;				// 課題1：戻り値
	uint16 resultB = 0;				// 課題1：戻り値②

	/* 初期化処理 */
	libraryInit();
	/* 初期スタッフ登録処理（スタッフ名：「明智　光秀」）  */
	firstStaff = createFirstStaff();

	printf("\n***************** 課題1 registUser関数の入出力テスト *****************\n\n");

	printf("テスト①：正常時の動作確認");
	userA1 = registUser(firstStaff, 5677, 19811206, "織田　信長", 1976);

	if (userA1 != NULL)
	{
		printf("							⇒ テスト①：OK\n");
	}
	else
	{
		printf("							⇒ テスト①：NG\n");
	}

	printf("テスト②：スタッフハンドルがNULLの場合の動作確認");
	userA2 = registUser(NULL, 5677, 19810718, "羽柴　秀吉", 3456);		// 正しいハンドル情報：firstStaff

	if (userA2 == NULL)
	{
		printf("					⇒ テスト②：OK\n");
	}
	else
	{
		printf("					⇒ テスト②：NG\n");
	}

	printf("テスト③：スタッフパスワードが異なる場合の動作確認");
	userA2 = registUser(firstStaff, 5687, 19810718, "羽柴　秀吉", 3456);		// 正しいパスワード：5677

	if (userA2 == NULL)
	{
		printf("				⇒ テスト③：OK\n");
	}
	else
	{
		printf("				⇒ テスト③：NG\n");
	}

	printf("テスト④：引数の生年月日が不正値（1960年1月1日よりも前）の場合の動作確認");
	userA2 = registUser(firstStaff, 5677, 18991130, "羽柴　秀吉", 3456);				// 本来設定したい生年月日：19811206

	if (userA2 == NULL)
	{
		printf("		⇒ テスト④：OK\n");
	}
	else
	{
		printf("		⇒ テスト④：NG\n");
	}

	printf("テスト⑤：引数の生年月日が不正値（今日の日付よりも後）の場合の動作確認");
	userA2 = registUser(firstStaff, 5677, 21000921, "羽柴　秀吉", 3456);				// 本来設定したい生年月日：19811206

	if (userA2 == NULL)
	{
		printf("		⇒ テスト⑤：OK\n");
	}
	else
	{
		printf("		⇒ テスト⑤：NG\n");
	}

	printf("テスト⑥：引数の文字列が不正値（NULL）の場合の動作確認");
	userA2 = registUser(firstStaff, 5677, 19810718, NULL, 3456);			// 本来設定したい文字列："羽柴　秀吉"

	if (userA2 == NULL)
	{
		printf("				⇒ テスト⑥：OK\n");
	}
	else
	{
		printf("				⇒ テスト⑥：NG\n");
	}

	printf("テスト⑦：引数の文字列が不正値（1文字も入っていない）の場合の動作確認");
	userA2 = registUser(firstStaff, 5677, 19810718, "\0", 3456);						// 本来設定したい文字列："羽柴　秀吉"

	if (userA2 == NULL)
	{
		printf("		⇒ テスト⑦：OK\n");
	}
	else
	{
		printf("		⇒ テスト⑦：NG\n");
	}

	printf("テスト⑧：引数の文字列が不正値（文字列サイズが最大値を超える）の場合の動作確認");
	userA2 = registUser(firstStaff, 5677, 19810718, "長曾我部どん兵衛", 3456);				// 氏名：全角8文字分　全角1文字は2byte今回は16byte＋"\0"で17文字
	if (userA2 == NULL)
	{
		printf("	⇒ テスト⑧：OK\n");
	}
	else
	{
		printf("	⇒ テスト⑧：NG\n");
	}

	printf("テスト⑨：引数のパスワードが不正値（5桁以上）の場合の動作確認");
	userA2 = registUser(firstStaff, 5677, 19810718, "羽柴　秀吉", 56789);		// 本来設定したいパスワード：3456

	if (userA2 == NULL)
	{
		printf("			⇒ テスト⑨：OK\n");
	}
	else
	{
		printf("			⇒ テスト⑨：NG\n");
	}

	printf("テスト⑩：既に登録済み場合の動作確認");
	userA2 = registUser(firstStaff, 5677, 19811206, "織田　信長", 1976);			// テスト①で登録済み

	if (userA2 == NULL)
	{
		printf("						⇒ テスト⑩：OK\n");
	}
	else
	{
		printf("						⇒ テスト⑩：NG\n");
	}

	printf("テスト⑪：利用者登録数が最大の場合の動作確認");
	userA2 = registUser(firstStaff, 5677, 19810718, "羽柴　秀吉", 3456);		// 登録可能（最大登録数に達した）
	userA3 = registUser(firstStaff, 5677, 19881122, "徳川　家康", 921);			// 登録不可能（既に最大数に達している）

	if ((userA2 != NULL) && (userA3 == NULL))
	{
		printf("					⇒ テスト⑪：OK\n");
	}
	else
	{
		printf("					⇒ テスト⑪：NG\n");
	}

	printf("\n\n***************** 課題1 getDateID関数の入出力テスト *****************\n\n");
	printf("テスト①：正常時の動作確認");
	resultB = getDateID(19940705);

	if (resultB == 0xBCE5)
	{
		printf("							⇒ テスト①：OK\n");
	}
	else
	{
		printf("							⇒ テスト①：NG\n");
	}

	printf("\n\n***************** 課題1 deleteUser関数の入出力テスト *****************\n\n");

	printf("テスト①：正常時の動作確認");
	resultA = deleteUser(firstStaff, 5677, userA2);

	if (resultA == 0)
	{
		printf("							⇒ テスト①：OK\n");
	}
	else
	{
		printf("							⇒ テスト①：NG\n");
	}

	printf("テスト②：スタッフハンドルがNULLの場合の動作確認");
	resultA = deleteUser(NULL, 5677, userA1);		// 正しいスタッフハンドル情報：firstStaff

	if (resultA == -1)
	{
		printf("					⇒ テスト②：OK\n");
	}
	else
	{
		printf("					⇒ テスト②：NG\n");
	}

	printf("テスト③：利用者ハンドルがNULLの場合の動作確認");
	resultA = deleteUser(firstStaff, 5677, NULL);		// 正しい利用者ハンドル情報：userA1

	if (resultA == -1)
	{
		printf("					⇒ テスト③：OK\n");
	}
	else
	{
		printf("					⇒ テスト③：NG\n");
	}

	printf("テスト④：スタッフパスワードが異なる場合の動作確認");
	resultA = deleteUser(firstStaff, 5697, userA1);		// 正しいパスワード：5677

	if (resultA == -4)
	{
		printf("				⇒ テスト④：OK\n");
	}
	else
	{
		printf("				⇒ テスト④：NG\n");
	}




#endif

#if D_STEP == 2

	sint8 resultB1 = 0;				// 課題2：戻り値①
	sint8 resultB2 = 0;				// 課題2：戻り値②

	/* 初期化処理 */
	libraryInit();
	/* 初期スタッフ登録処理（スタッフ名：「明智　光秀」）  */
	firstStaff = createFirstStaff();

	printf("\n***************** 課題2 registBook関数の入出力テスト *****************\n\n");

	printf("テスト①：正常時の動作確認");
	resultB1 = registBook(firstStaff, 5677, 798030142, E_GENRE_ENGINEERING, 2011, 7, "苦しんで覚えるC言語");

	if (resultB1 == 0)
	{
		printf("								⇒ テスト①：OK\n");
	}
	else
	{
		printf("								⇒ テスト①：NG\n");
	}

	printf("テスト②：スタッフハンドルがNULLの場合の動作確認");
	resultB1 = registBook(NULL, 5677, 88716114, E_GENRE_COMIC, 1991, 2, "SLAM DUNK 1");		// 正しいハンドル情報：firstStaff

	if (resultB1 == -1)
	{
		printf("						⇒ テスト②：OK\n");
	}
	else
	{
		printf("						⇒ テスト②：NG\n");
	}

	printf("テスト③：スタッフパスワードが異なる場合の動作確認");
	resultB1 = registBook(firstStaff, 5777, 88716114, E_GENRE_COMIC, 1991, 2, "SLAM DUNK 1");		// 正しいパスワード：5677

	if (resultB1 == -4)
	{
		printf("					⇒ テスト③：OK\n");
	}
	else
	{
		printf("					⇒ テスト③：NG\n");
	}

	printf("テスト④：引数のジャンルが不正値（ジャンルなし）の場合の動作確認");
	resultB1 = registBook(firstStaff, 5677, 88716114, E_GENRE_NONE, 1991, 2, "SLAM DUNK 1");	// 本来設定したいジャンル：E_GENRE_COMIC = 1

	if (resultB1 == -5)
	{
		printf("				⇒ テスト④：OK\n");
	}
	else
	{
		printf("				⇒ テスト④：NG\n");
	}

	printf("テスト⑤：引数のジャンルが不正値（すべてのジャンル）の場合の動作確認");
	resultB1 = registBook(firstStaff, 5677, 88716114, E_GENRE_ALL, 1991, 2, "SLAM DUNK 1");		// 本来設定したいジャンル：E_GENRE_COMIC = 1

	if (resultB1 == -5)
	{
		printf("			⇒ テスト⑤：OK\n");
	}
	else
	{
		printf("			⇒ テスト⑤：NG\n");
	}

	printf("テスト⑥：引数の発売年が不正値（1960年より前）の場合の動作確認");
	resultB1 = registBook(firstStaff, 5677, 88716114, E_GENRE_COMIC, 1900, 2, "SLAM DUNK 1");		// 本来設定したい発売年：1900

	if (resultB1 == -5)
	{
		printf("				⇒ テスト⑥：OK\n");
	}
	else
	{
		printf("				⇒ テスト⑥：NG\n");
	}

	printf("テスト⑦：引数の発売年が不正値（今日の西暦よりも後）の場合の動作確認");
	resultB1 = registBook(firstStaff, 5677, 88716114, E_GENRE_COMIC, 2100, 2, "SLAM DUNK 1");		// 本来設定したい発売年：2100

	if (resultB1 == -5)
	{
		printf("			⇒ テスト⑦：OK\n");
	}
	else
	{
		printf("			⇒ テスト⑦：NG\n");
	}

	printf("テスト⑧：引数のタイトルが不正値（NULL）の場合の動作確認");
	resultB1 = registBook(firstStaff, 5677, 88716114, E_GENRE_COMIC, 1991, 2, NULL);	// 本来設定したい文字列："SLAM DUNK 1"

	if (resultB1 == -5)
	{
		printf("					⇒ テスト⑧：OK\n");
	}
	else
	{
		printf("					⇒ テスト⑧：NG\n");
	}

	printf("テスト⑨：引数のタイトルが不正値（1文字も入っていない）の場合の動作確認");
	resultB1 = registBook(firstStaff, 5677, 88716114, E_GENRE_COMIC, 1991, 2, "");		// 本来設定したい文字列："SLAM DUNK 1"

	if (resultB1 == -5)
	{
		printf("			⇒ テスト⑨：OK\n");
	}
	else
	{
		printf("			⇒ テスト⑨：NG\n");
	}

	printf("テスト⑩：引数のタイトルが不正値（文字列サイズが最大値を超える）の場合の動作確認");
	resultB1 = registBook(firstStaff, 5677, 88716114, E_GENRE_COMIC, 1991, 2, "インフラ/ネットワークエンジニアのためのネットワーク技術&設計入門");				// タイトル：全角32文字分（日本語31文字＋半角記号2文字）

	if (resultB1 == -5)
	{
		printf("		⇒ テスト⑩：OK\n");
	}
	else
	{
		printf("		⇒ テスト⑩：NG\n");
	}

	printf("テスト⑪：既に登録済み場合の動作確認");
	resultB1 = registBook(firstStaff, 5677, 798030142, E_GENRE_ENGINEERING, 2011, 7, "苦しんで覚えるC言語");	// テスト①で登録済み

	if (resultB1 == -6)
	{
		printf("							⇒ テスト⑪：OK\n");
	}
	else
	{
		printf("							⇒ テスト⑪：NG\n");
	}

	printf("テスト⑫：1960年の書籍を登録する場合の動作確認");
	resultB2 = registBook(firstStaff, 5677, 375705151, E_GENRE_LITERATURE, 1960, 2, "宴のあと");
	if (resultB2 == 0)
	{
		printf("						⇒ テスト⑫：OK\n");
	}
	else
	{
		printf("						⇒ テスト⑫：NG\n");
	}

	printf("テスト⑬：1960年未満の書籍を登録失敗する場合の動作確認");
	resultB2 = registBook(firstStaff, 5677, 151001637, E_GENRE_LITERATURE, 1959, 2, "アルジャーノンに花束を");
	if (resultB2 == -5)
	{
		printf("					⇒ テスト⑬：OK\n");
	}
	else
	{
		printf("					⇒ テスト⑬：NG\n");
	}



	printf("テスト⑭：書籍登録数が最大の場合の動作確認");
	resultB1 = registBook(firstStaff, 5677, 88716114, E_GENRE_COMIC, 1991, 2, "SLAM DUNK 1");					// 登録可能（最大登録数に達した）
	resultB2 = registBook(firstStaff, 5677, 87925319, E_GENRE_COMIC, 2018, 6, "SLAM DUNK 新装再編版 1");		// 登録不可能（既に最大数に達している）

	if ((resultB1 == 0) && (resultB2 == -7))
	{
		printf("						⇒ テスト⑭：OK\n");
	}
	else
	{
		printf("						⇒ テスト⑭：NG\n");
	}


	printf("\n***************** 課題2 deleteBook関数の入出力テスト *****************\n\n");

	printf("テスト①：正常時の動作確認");
	resultB1 = deleteBook(firstStaff, 5677, 41090602);		// 「パンどろぼう」を削除

	if (resultB1 == 0)
	{
		printf("								⇒ テスト①：OK\n");
	}
	else
	{
		printf("								⇒ テスト①：NG\n");
	}

	printf("テスト②：スタッフハンドルがNULLの場合の動作確認");
	resultB1 = deleteBook(NULL, 5677, 63259681);		// 正しいハンドル情報：firstStaff

	if (resultB1 == -1)
	{
		printf("						⇒ テスト②：OK\n");
	}
	else
	{
		printf("						⇒ テスト②：NG\n");
	}

	printf("テスト③：スタッフパスワードが異なる場合の動作確認");
	resultB1 = deleteBook(firstStaff, 5671, 63259681);		// 正しいパスワード：5677

	if (resultB1 == -4)
	{
		printf("					⇒ テスト③：OK\n");
	}
	else
	{
		printf("					⇒ テスト③：NG\n");
	}

	printf("テスト④：該当の書籍がない場合の動作確認");
	resultB1 = deleteBook(firstStaff, 5677, 41090602);		// 再度「パンどろぼう」を削除

	if (resultB1 == -5)
	{
		printf("							⇒ テスト④：OK\n");
	}
	else
	{
		printf("							⇒ テスト④：NG\n");
	}


#endif

#if D_STEP == 3

	H_PERSON userC1 = NULL;			// 課題3：テスト用利用者①
	H_PERSON userC2 = NULL;			// 課題3：テスト用利用者②
	sint8 resultC = 0;				// 課題3：戻り値

	/* 初期化処理 */
	libraryInit();
	/* 初期スタッフ登録処理（スタッフ名：「明智　光秀」）  */
	firstStaff = createFirstStaff();

	printf("\n\n***************** 課題3 lendBook関数の入出力テスト *****************\n\n");

	userC1 = registUser(firstStaff, 5677, 19810516, "石田　三成", 2701);
	userC2 = registUser(firstStaff, 5677, 19810718, "羽柴　秀吉", 3456);

	printf("テスト①：正常時（ユーザーが借りる場合）の動作確認");
	resultC = lendBook(userC1, 2701, 167110123);

	if (resultC == 0)
	{
		printf("			⇒ テスト①：OK\n");
	}
	else
	{
		printf("			⇒ テスト①：NG\n");
	}

	printf("テスト②：正常時（スタッフが借りる場合）の動作確認");
	resultC = lendBook(firstStaff, 5677, 91208859);

	if (resultC == 0)
	{
		printf("			⇒ テスト②：OK\n");
	}
	else
	{
		printf("			⇒ テスト②：NG\n");
	}

	printf("テスト③：利用者ハンドルがNULLの場合の動作確認");
	resultC = lendBook(NULL, 3456, 575519945);		// 正しいハンドル情報：firstStaff

	if (resultC == -1)
	{
		printf("				⇒ テスト③：OK\n");
	}
	else
	{
		printf("				⇒ テスト③：NG\n");
	}

	printf("テスト④：利用者パスワードが異なる場合の動作確認");
	resultC = lendBook(userC2, 7456, 575519945);		// 正しいパスワード：3456

	if (resultC == -4)
	{
		printf("				⇒ テスト④：OK\n");
	}
	else
	{
		printf("				⇒ テスト④：NG\n");
	}

	printf("テスト⑤：既に利用者が書籍を借りている場合の動作確認");
	resultC = lendBook(userC1, 2701, 575519945);		// テスト①で貸し出し済み

	if (resultC == -5)
	{
		printf("			⇒ テスト⑤：OK\n");
	}
	else
	{
		printf("			⇒ テスト⑤：NG\n");
	}

	printf("テスト⑥：存在しない書籍番号を指定した場合の動作確認");
	resultC = lendBook(userC2, 3456, 101231761);		// 本来設定したい書籍番号：575519945

	if (resultC == -6)
	{
		printf("			⇒ テスト⑥：OK\n");
	}
	else
	{
		printf("			⇒ テスト⑥：NG\n");
	}

	printf("テスト⑦：既に貸し出されている書籍番号を指定した場合の動作確認");
	resultC = lendBook(userC2, 3456, 91208859);		// テスト②で貸し出し済み

	if (resultC == -7)
	{
		printf("		⇒ テスト⑦：OK\n");
	}
	else
	{
		printf("		⇒ テスト⑦：NG\n");
	}

	printf("\n\n***************** 課題3 returnBook関数の入出力テスト *****************\n\n");

	lendBook(userC2, 3456, 757554894);	// テスト用に貸し出し処理

	printf("テスト①：正常時（ユーザーが返却する場合）の動作確認");
	resultC = returnBook(userC1, 2701, 167110123);

	if (resultC == 0)
	{
		printf("			⇒ テスト①：OK\n");
	}
	else
	{
		printf("			⇒ テスト①：NG\n");
	}

	printf("テスト②：正常時（スタッフが返却する場合）の動作確認");
	resultC = returnBook(firstStaff, 5677, 91208859);

	if (resultC == 0)
	{
		printf("			⇒ テスト②：OK\n");
	}
	else
	{
		printf("			⇒ テスト②：NG\n");
	}


	printf("テスト③：利用者ハンドルがNULLの場合の動作確認");
	resultC = returnBook(NULL, 3456, 757554894);		// 正しいハンドル情報：userC2

	if (resultC == -1)
	{
		printf("				⇒ テスト③：OK\n");
	}
	else
	{
		printf("				⇒ テスト③：NG\n");
	}

	printf("テスト④：利用者パスワードが異なる場合の動作確認");
	resultC = returnBook(userC2, 3956, 757554894);		// 正しいパスワード：3456

	if (resultC == -4)
	{
		printf("				⇒ テスト④：OK\n");
	}
	else
	{
		printf("				⇒ テスト④：NG\n");
	}

	printf("テスト⑤：利用者が書籍を借りていない場合の動作確認");
	resultC = returnBook(userC1, 2701, 167110123);		// テスト①で返却済み

	if (resultC == -5)
	{
		printf("			⇒ テスト⑤：OK\n");
	}
	else
	{
		printf("			⇒ テスト⑤：NG\n");
	}

	printf("テスト⑥：存在しない書籍番号を指定した場合の動作確認");
	resultC = returnBook(userC2, 3456, 101231761);		// 本来設定したい書籍番号：757554894

	if (resultC == -6)
	{
		printf("			⇒ テスト⑥：OK\n");
	}
	else
	{
		printf("			⇒ テスト⑥：NG\n");
	}

	printf("テスト⑦：貸し出されていない書籍を指定した場合の動作確認");
	resultC = returnBook(userC2, 3456, 575519945);		// 本来設定したい書籍番号：757554894

	if (resultC == -7)
	{
		printf("			⇒ テスト⑦：OK\n");
	}
	else
	{
		printf("			⇒ テスト⑦：NG\n");
	}

	lendBook(userC1, 2701, 63259681);	// テスト用に貸し出し処理

	printf("テスト⑧：借りている書籍とは別の書籍番号を指定した場合の動作確認");
	resultC = returnBook(userC2, 3456, 63259681);		// 本来設定したい書籍番号：757554894

	if (resultC == -8)
	{
		printf("		⇒ テスト⑧：OK\n");
	}
	else
	{
		printf("		⇒ テスト⑧：NG\n");
	}


#endif



#if D_STEP == 4

	sint8 resultD = 0;				// 課題4：戻り値

	/* 初期化処理 */
	libraryInit();
	/* 初期スタッフ登録処理（スタッフ名：「明智　光秀」）  */
	firstStaff = createFirstStaff();
	resultD = lendBook(firstStaff, 5677, 91208859);//スタッフが書籍を借りる


	printf("\n\n***************** 課題4 printSearchBooks関数の入出力テスト *****************\n\n");

	printf("テスト①：引数のジャンルが不正値（範囲よりも小さい）の場合の動作確認");
	resultD = printSearchBooks(-1, 2000);

	if (resultD == -1)
	{
		printf("		⇒ テスト①：OK\n");
	}
	else
	{
		printf("		⇒ テスト①：NG\n");
	}

	printf("テスト②：引数のジャンルが不正値（範囲よりも大きい）の場合の動作確認");
	resultD = printSearchBooks(99, 2000);

	if (resultD == -1)
	{
		printf("		⇒ テスト②：OK\n");
	}
	else
	{
		printf("		⇒ テスト②：NG\n");
	}

	printf("テスト③：引数の発売年が不正値（1960年よりも前）の場合の動作確認");
	resultD = printSearchBooks(E_GENRE_PICTUREBOOKS, 1603);

	if (resultD == -1)
	{
		printf("			⇒ テスト③：OK\n");
	}
	else
	{
		printf("			⇒ テスト③：NG\n");
	}

	printf("テスト④：引数の発売年が不正値（今日の西暦よりも後）の場合の動作確認");
	resultD = printSearchBooks(E_GENRE_PICTUREBOOKS, 2738);

	if (resultD == -1)
	{
		printf("		⇒ テスト④：OK\n");
	}
	else
	{
		printf("		⇒ テスト④：NG\n");
	}

	printf("\n以下、正常に指定した場合の動作（該当の書籍が表示されているか）の確認\n\n");

	printf("テスト⑤：指定あり（ジャンル：絵本、発売年：1990年 ⇒ 該当書籍なし）の場合の動作確認");
	printSearchBooks(E_GENRE_PICTUREBOOKS, 1990);

	printf("テスト⑥：指定あり（ジャンル：絵本、発売年：2010年）の場合の動作確認");
	printSearchBooks(E_GENRE_PICTUREBOOKS, 2010);

	printf("テスト⑦：指定あり（ジャンル：漫画・コミックス、発売年：全て）の場合の動作確認");
	printSearchBooks(E_GENRE_COMIC, D_YEAR_ALL);

	printf("テスト⑧：指定あり（ジャンル：全て、発売年：2017年）の場合の動作確認");
	printSearchBooks(E_GENRE_ALL, 2017);

	printf("テスト⑨：指定あり（ジャンル：全て、発売年：全て ⇒ 全ての書籍）の場合の動作確認");
	printSearchBooks(E_GENRE_ALL, D_YEAR_ALL);

#endif

#if D_STEP == 5

	H_PERSON userNobu = NULL;			// 利用者「織田　信長」
	H_PERSON userHide = NULL;			// 利用者「羽柴　秀吉」
	sint8 result = 0;					// 戻り値

	/* 初期化処理 */
	libraryInit();
	/* 初期スタッフ登録処理（スタッフ名：「明智　光秀」）*/
	firstStaff = createFirstStaff();

	//----------------------------------------------
	//	ブレークポイントの設定箇所
	//----------------------------------------------
	printf("最終動作確認を開始\n");

	// 信長：「光秀よ、おれが図書館を利用できるように登録処理をしてくれ」
	// 秀吉：「わしもお願いしたい」
	// 光秀（スタッフ）：「かしこまりました。信長様と秀吉殿のユーザー登録を行いましょう」
	userNobu = registUser(firstStaff, 5677, 19811206, "織田　信長", 1582);
	userHide = registUser(firstStaff, 5677, 19810718, "羽柴　秀吉", 1590);

	if ((userNobu == NULL) || (userHide == NULL))
	{
		printf(" ＞＞　ユーザー登録機能に問題があるため修正しましょう\n");
		return -1;
	}

	// 秀吉：「ありがとう、光秀殿」
	// 信長：「うむ。ではさっそく、『信長協奏曲（コンツェルト）』を借りようではないか」
	result = lendBook(userNobu, 1582, 91221001);

	if (result != -6)
	{
		printf(" ＞＞　書籍の貸し出し機能に問題があるため修正しましょう\n");
		return -1;
	}

	// 信長：「まさか『信長協奏曲』がないというのか」
	//     ：「漫画ジャンルの本を検索してみよう」
	result = printSearchBooks(E_GENRE_COMIC, D_YEAR_ALL);

	if (result != 0)
	{
		printf(" ＞＞　書籍の検索機能に問題があるため修正しましょう\n");
		return -1;
	}

	// 信長：「光秀よ、『信長協奏曲』を置いていないとは何事か」
	// 光秀：「誠に申し訳ございません。ただいま、『信長協奏曲』の登録をいたします」
	result = registBook(firstStaff, 5677, 91221001, E_GENRE_COMIC, 2009, 11, "信長協奏曲 1");
	if (result != 0)
	{
		printf(" ＞＞　書籍の登録機能に問題があるため修正しましょう\n");
		return -1;
	}

	result = registBook(firstStaff, 5677, 91222251, E_GENRE_COMIC, 2010, 3, "信長協奏曲 2");
	if (result != 0)
	{
		printf(" ＞＞　書籍の登録機能に問題があるため修正しましょう\n");
		return -1;
	}

	// 秀吉：「今さっき光秀殿が『信長協奏曲』が追加した様子だ。今のうちに借りておこう」
	result = lendBook(userHide, 1615, 91221001);

	if (result != -4)
	{
		printf(" ＞＞　書籍の貸し出し機能に問題があるため修正しましょう\n");
		return -1;
	}

	// 秀吉：「どうやらパスワードを間違えてしまったようだ」
	// 　　：「パスワードを正しく入力して改めて貸し出し手続きを行おう」
	result = lendBook(userHide, 1590, 91221001);

	if (result != 0)
	{
		printf(" ＞＞　書籍の貸し出し機能に問題があるため修正しましょう\n");
		return -1;
	}

	// 光秀：「信長様、先ほど『信長協奏曲』の1,2巻の登録をいたしました」
	// 信長：「うむ、では『信長協奏曲 1』を借りるとしよう」
	result = lendBook(userNobu, 1582, 91221001);

	if (result != -7)
	{
		printf(" ＞＞　書籍の貸し出し機能に問題があるため修正しましょう\n");
		return -1;
	}

	// 信長：「おい光秀よ、貴様がもたもたしている間に誰かに借りられてしまったではないか」
	// 光秀：「誠に申し訳ございません」
	// 秀吉：「信長様、誰かに借りられぬように、私が『信長協奏曲 1』を前もって借りておきました」
	result = returnBook(userHide, 1590, 91221001);

	if (result != 0)
	{
		printf(" ＞＞　書籍の返却機能に問題があるため修正しましょう\n");
		return -1;
	}

	// 秀吉：「いま返却しましたので、どうぞお借り下さい」
	// 信長：「さすが秀吉、感謝するぞ。光秀も少しは見習って欲しいものだ」
	// 　　：「では、さっそく『信長協奏曲 1』を借りるとするか」
	result = lendBook(userNobu, 1582, 91221001);

	if (result != 0)
	{
		printf(" ＞＞　書籍の貸し出し機能に問題があるため修正しましょう\n");
		return -1;
	}

	// 秀吉：「では代わりに、『容疑者Xの献身』を借りておこう」
	result = lendBook(userHide, 1590, 167110123);

	if (result != 0)
	{
		printf(" ＞＞　書籍の貸し出し機能に問題があるため修正しましょう\n");
		return -1;
	}

	// 光秀：「...信長様の理不尽な言動にはもううんざりだ」
	//	　 ：「そうだ、楽しみにしていた『信長協奏曲 2』を削除してやろう」
	result = deleteBook(firstStaff, 5677, 91221001);

	if (result != -6)
	{
		printf(" ＞＞　書籍の削除機能に問題があるため修正しましょう\n");
		return -1;
	}

	// 光秀：「間違えてまだ信長様が借りている、『信長協奏曲 1』の番号を入力してしまった」
	// 　　：「改めて、『信長協奏曲 2』を削除するぞ」
	result = deleteBook(firstStaff, 5677, 91222251);

	if (result != 0)
	{
		printf(" ＞＞　書籍の削除機能に問題があるため修正しましょう\n");
		return -1;
	}

	// 信長：「よし、読み終わったから『信長協奏曲 1』を返そう」
	result = returnBook(userNobu, 1582, 91221001);

	if (result != 0)
	{
		printf(" ＞＞　書籍の返却機能に問題があるため修正しましょう\n");
		return -1;
	}

	// 信長：「では続けて『信長協奏曲 2』を読もうではないか」
	result = lendBook(userNobu, 1582, 91222251);

	if (result != -6)
	{
		printf(" ＞＞　書籍の貸し出し機能に問題があるため修正しましょう\n");
		return -1;
	}

	// 信長：「おい光秀、『信長協奏曲 2』がないではないか」
	// 光秀：「左様でございますか。私にもなぜ無いのか検討もつきませんね」
	// 信長：「...もうよい！こんな図書館システム二度と使うものか。おれの情報を削除しておけ」
	// 光秀：「かしこまりました」
	result = deleteUser(firstStaff, 5677, userHide);

	if (result != -5)
	{
		printf(" ＞＞　ユーザーの削除機能に問題があるため修正しましょう\n");
		return -1;
	}

	// 光秀：「間違えて秀吉殿の削除をしようとしてしまった」
	// 　　：「改めて、信長様の情報を削除しよう」
	// 　　：（よかった、これで理不尽な言いがかりをつけてくる"魔王"がいなくなる）
	result = deleteUser(firstStaff, 5677, userNobu);

	if (result != 0)
	{
		printf(" ＞＞　ユーザーの削除機能に問題があるため修正しましょう\n");
		return -1;
	}


	printf("総合開発課題クリア!!\n");

#endif

	return 0;
}

