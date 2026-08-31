//	課題
#include <stdio.h>

//	typedefを使用しE_ANIMAL_ID列挙型を定義せよ
typedef enum
{
	E_ANIMAL_ID_KIRIN,  //キリン
	E_ANIMAL_ID_TORA,   //トラ
	E_ANIMAL_ID_ZOW,    //ゾウ
	E_ANIMAL_ID_KABA,   //カバ
}E_ANIMAL_ID;

//	構造体は次のものとする
typedef struct
{
	char	jpName[32];   //日本語名
	char	enName[32];   //英語名
} S_Animal;               //新しい型名

int main(void)
{
	//	動物情報の定義は次のものとする
	//[]数字が入っていない理由は増減の可能性がある為
	S_Animal animal[] =
	{
		//jpName     //enName
		{"麒麟",	"Giraffe"	},
		{"虎",		"Tiger"		},
		{"象",		"Elephant"	},
		{"河馬",	"Hippo"		},
	};

	//	表示したい動物IDを初期値として与えよ
	//環境依存のint型でも使える。今回は列挙子を初期化している為、E_ANIMAL_IDの方が分かりやすい。キリンで初期化
	E_ANIMAL_ID	animalID = E_ANIMAL_ID_KIRIN;
	

	//	printfで動物の名称を表示せよ。配列インデックスにはanimalIDを利用せよ
	//「main関数で定義した動物情報のanimalID行目(34行目)のjpName列目にアクセス
	//KIRINの場合animal[0]と同じだが、数値だけ見ると何か分かりずらい為列挙型を用いて読みやすくしている。
	printf("日本語:%s 英語名%s", animal[animalID].jpName, animal[animalID].enName);


	return 0;
}