//	課題
//多重インクルード防止
#ifndef CASH_H
#define CASH_H

//キャッシュカードハンドルの外部公開の型の定義
typedef void* H_CARD;


//プロトタイプ宣言
//作成
H_CARD createCashcard(char* name, unsigned short pin);

//制御
int depositCash(H_CARD handle, unsigned long cash);
int printCardInfo(H_CARD handle);
int withdrawCash(H_CARD handle, unsigned short pin, unsigned long cash);

//破棄
int destroyCashcard(H_CARD handle, unsigned short pin);



#endif// CASH_H
