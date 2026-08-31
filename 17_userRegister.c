#include <stdio.h>
#include <string.h>
#include "common.h"
#include "userRegister.h"
#if D_STEP >= 1

//--------------------------
//	利用者テーブル
//--------------------------
//3人分のテーブルを用意できるよ
S_LIBRARY_PERSON personalTable[D_PERSON_MAXNUM];		// 編集禁止

//*********************************************************
//	関数名	：registUser
//	機能概要：ユーザー情報の登録
//*********************************************************
H_PERSON registUser(H_PERSON staff, uint16 staffPin, uint32 userBirth, sint8* userName, uint16 personalPin)
{
	uint8 i;
	uint32 personalID;
	uint8 count = 0;
	sint8 insertIndex = -1;
	
	//staffの番地(段)があるか
	if (staff == NULL)
	{
		return NULL;
	}
	//staffが見つかったからstaffをハンドルとし、構造体にアクセルできるようにキャストした
	
	S_LIBRARY_PERSON* Staff = (S_LIBRARY_PERSON*)staff;
	
	//アカウントが使えるか
	if (Staff->validFlag == 0)
	{
		return NULL;
	}
	// 操作している人がスタッフ権限を持っているか確認
	if (Staff->authority != E_AUTHORITY_STAFF)
	{
		return NULL;
	}
	//Staff情報のパスワードと一致するか確認
	if (Staff->personalPin != staffPin)
	{
		return NULL;
	}
	//↑ここまでで第一・二引数のstaffとstaffPinの確認をした

	//↓ここからは申請したい内容
	//ユーザー氏名の文字列がNULLではないか,ユーザー氏名に1文字以上入っているか
	//#include <string.h>をインクルードした
	
	if (userName == NULL || strlen(userName) == 0)
	{
		return NULL;
	}
	//ユーザー氏名の文字列サイズが最大値を超えていないか
	//D_PERSONAL_NAME_MAXはヌル文字ぶんは入っていない為−1する必要がある。
	//strlen(userName)+"\0"が文字数　
	if (strlen(userName) > D_PERSONAL_NAME_MAX-1) //最大16文字
	//if (strlen(userName)+1 > D_PERSONAL_NAME_MAX)
	//if (strlen(userName) >= D_PERSONAL_NAME_MAX)
	{
		
		return NULL;
	}
	//ユーザーパスワードが４桁になっているか
	if (personalPin < 0000 || personalPin >9999)
	{
		return NULL;
	}
	//ユーザー生年月日が、1960年1月1日～今日の間で指定されているか 20260727
	if (userBirth < 19600101 || userBirth > D_TODAY)
	{
		return NULL;
	}
	
	//ここまでで、受け取ってもいい引数だと確認できた。
	
	//呼び出す側では関数のデータ型はすでに決まっているので書かないが、「返ってきた結果を収めるための箱（変数）の型」としている。
	uint16 birthID = getDateID(userBirth);
	uint16 todayID = getDateID(D_TODAY);
	

	personalID = (birthID<<16) | todayID;
	
	//ここから箱の中身を見ていく
	for (i = 0;i < D_PERSON_MAXNUM;i++)
	{
		if (personalTable[i].personalID == personalID)
		{
			return NULL;
		}
		if (personalTable[i].validFlag == 1)
		{
			//登録数者数をカウントする
			count++;
		}
		else
		{
			//validFlag==0の場合、変数insertIndex初期値-1(空き部屋)が-1ならiを代入し場所をキープしたい。
			if (insertIndex == -1)
			{
				insertIndex = i;
			//この処理でinsertIndexはiに書き変わり、他の部屋に空き部屋があったとしてもinsertIndexは-1では無いため上書されない
			//なので、最初に発見したi番目の部屋に新しい人の情報を登録できる。
				break;
			}
		}
	}
	//登録者数が D_PERSON_MAXNUM(最大登録者数)と等しい場合NULL
	if (D_PERSON_MAXNUM == count)
	{
		return NULL;
	}

	//ここからpersonalTableに値をいれていく
	//空きがある場所を見付けてそこに登録情報を入れる
	personalTable[insertIndex].validFlag = 1;    //有効にるす
	personalTable[insertIndex].authority = E_AUTHORITY_USER;//権限の付与
	personalTable[insertIndex].personalID = personalID; //生成したID
	strcpy(personalTable[insertIndex].name, userName); //名前をコピー
	personalTable[insertIndex].personalPin = personalPin;  //PIN
	personalTable[insertIndex].lendFlag = 0;   //貸出フラグ
	personalTable[insertIndex].bookCode = 0;   //書籍コード

	//登録したユーザーハンドルを返却する
	//戻したい物は、新しく登録したデータが入っている場所の『住所（アドレス）』を、外のプログラムでも使えるように『H_PERSON』という形に変えたもの
	return (H_PERSON)&personalTable[insertIndex] ;
}

//*********************************************************
//	関数名	：deleteUser
//	機能概要：ユーザー情報の削除
//*********************************************************
sint8 deleteUser(H_PERSON staff , uint16 staffPin , H_PERSON user)
{
	//荷物が届いた ここは番地の話(データを入れる前)　何処に渡すかまだ決まっていないからNULLチェックは後でよい
	//「誰が操作しているのか」(staff)」と「誰を消すのか(user)」という住所(ポインタ)を受け取る必要がある。
	S_LIBRARY_PERSON* Staff = (S_LIBRARY_PERSON*)staff;
	S_LIBRARY_PERSON* User = (S_LIBRARY_PERSON*)user;
	
	//本当に届いたか
	if (staff == NULL || user == NULL)
	{
		return -1;
	}
	
	//ユーザーまたはスタッフのハンドルのバリッドフラグが無効
	if (Staff->validFlag == 0 || User->validFlag == 0)
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
	//ユーザーがまだ書籍を返却していない
	if (User->lendFlag == 1)
	{
		return -5;
	}
	//ここまでで特殊な条件を弾いた(セキュリティチェック)

    //ここからユーザー登録情報の削除
	User->validFlag = 0;    //無効にるす
	User->authority = E_AUTHORITY_NONE;//権限なし
	User->personalID = 0; //生成したID
	memset(User->name, '\0', D_PERSONAL_NAME_MAX);  //入っていた文字を全てリセット(ヌル文字にする) memset(入れたい場所,入れたい文字,入れたい文字数);
	User->personalPin = 10000;  //PIN
	User->lendFlag = 0;   //貸出フラグ
	User->bookCode = 0;   //書籍コード


	return 0;
}





//*********************************************************
//	関数名	：getDateID
//	機能概要：生年月日を2バイト分のID情報に変換
//*********************************************************
uint16 getDateID(uint32 date)  
{
	uint16 day;
	uint16 month;
	uint16 year;
	uint16 data;
	
	//日付だけを抽出したい場合は　data % 100
	//C言語の割り算（整数同士の割り算）では、小数点以下はすべて切り捨てられるというルールがある。
	// 上位4桁（年）を取り出したあと、さらに 100 で割った余りを求めて下2桁（例：1994なら94）にする
	year = (date / 10000) % 100;
	//日を消すために一度100で割ってから、残った下2桁（月）を % 100 の余りで切り取る。
	month = (date / 100) % 100;
	//下2桁（日）を余りの計算で直接取り出す。
	day = date % 100;


	//生年月日を並べる
	data = ((year << 9) | (month << 5) | day);
	
	return data;
}
	//引数の値を2byteにするための計算
#endif

