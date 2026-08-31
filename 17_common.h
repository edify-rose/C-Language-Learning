#ifndef COMMON_H
#define COMMON_H

//---------------------------------------------------------
//	課題切り替え用：課題ごとに値を切り替えてください
//---------------------------------------------------------
#define D_STEP (5)
#define D_PERSON_MAXNUM (500)
#define D_TODAY (20260727)

#define D_BOOK_MAXNUM (1000)

#define D_YEAR_ALL (0)

typedef char sint8;
typedef unsigned char uint8;
typedef short sint16;
typedef unsigned short uint16;
typedef long sint32;
typedef unsigned long uint32;

typedef void* H_PERSON;

typedef enum
{
	E_GENRE_NONE=0,
	E_GENRE_COMIC,
	E_GENRE_LITERATURE,
	E_GENRE_ECONOMY,
	E_GENRE_PICTUREBOOKS,
	E_GENRE_SCIENCE,
	E_GENRE_ENGINEERING,
	E_GENRE_ALL
}E_GENRE_KIND;




//---------------------------------------------------------
//	以下編集禁止　各機能についてのプロトタイプ宣言
//---------------------------------------------------------
void libraryInit(void);
H_PERSON createFirstStaff(void);

H_PERSON registUser(H_PERSON staff , uint16 staffPin , uint32 userBirth , sint8 * userName , uint16 personalPin);
sint8 deleteUser(H_PERSON staff , uint16 staffPin , H_PERSON user);
uint16 getDateID(uint32 date);


#if D_STEP >= 2

sint8 registBook(H_PERSON staff , uint16 staffPin , uint32 bookCode , E_GENRE_KIND genre , uint16 year , uint16 month , sint8 * title);
sint8 deleteBook(H_PERSON staff , uint16 staffPin , uint32 bookCode);

sint8 lendBook(H_PERSON user , uint16 personalPin  , uint32 bookCode);
sint8 returnBook(H_PERSON user , uint16 personalPin , uint32 bookCode);
sint8 printSearchBooks(E_GENRE_KIND genre , uint16 year);

#endif	// D_STEP >= 2
#endif	// COMMON_H