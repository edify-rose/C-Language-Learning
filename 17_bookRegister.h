#ifndef BOOKREGISTEAR_H
#define BOOKREGISTEAR_H
#if D_STEP >= 2
#define D_BOOKTITLE_MAXSIZE (64)


typedef struct
{
	uint8 validFlag;
	uint32 bookCode;
	uint16 bookInfo;
	sint8 title[D_BOOKTITLE_MAXSIZE];  //[]の中身にしっかり何文字入れられるか設計しておく
}S_LIBRARY_BOOK;

//--------------------------------
//	書籍テーブルの外部参照
//--------------------------------
extern S_LIBRARY_BOOK bookTable[D_BOOK_MAXNUM];	// 編集禁止

#endif	// D_STEP >= 2
#endif	// BOOKREGISTEAR_H