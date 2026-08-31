#ifndef USERREGISTER_H
#define USERREGISTER_H
#if D_STEP >= 1

#define D_PERSONAL_NAME_MAX (16)

#define D_BOOLTITLE_MAXSIZE (64)

typedef enum
{
	E_AUTHORITY_NONE=0,
	E_AUTHORITY_USER,
	E_AUTHORITY_STAFF,
}E_LIBRARY_AUTHORITY;

typedef struct
{
	uint8 validFlag;
	E_LIBRARY_AUTHORITY authority;
	uint32 personalID;
	sint8 name[D_PERSONAL_NAME_MAX];
	uint16 personalPin;
	uint8 lendFlag;
	uint32 bookCode;
}S_LIBRARY_PERSON;


//---------------------------------------------------------
//	利用者テーブルの外部参照
//---------------------------------------------------------
extern S_LIBRARY_PERSON personalTable[D_PERSON_MAXNUM] ;	// 編集禁止

#endif	// D_STEP >= 1
#endif	// USERREGISTER_H