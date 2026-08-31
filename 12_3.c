//	課題
#include <stdio.h>

//
//	道路ID(4Byte)と道路種別(2Byte)がビッグエンディアンで次のようにchar型配列で定義されている
//
unsigned char gRoadID[4]	= { 0x12 , 0x34 , 0x56 , 0x78 };	//道路ID	:0x12345678
unsigned char gRoadKind[2]	= { 0x9a, 0xbc};					//道路種別	:0x9abc

int main(void)
{
	unsigned long	road = 0;	//	道路ID:4byte
	unsigned short	kind = 0;	//	道路種別:2byte

	//-----------------------------------
	//	↓この部分のみを編集する↓
	//-----------------------------------

	//	gRoadID[]とgRoadKind[]をそれぞれroad変数とkind変数にエンディアンを意識して取り込むこと
	road = gRoadID[0] << 24 | gRoadID[1] << 16 | gRoadID[2] << 8 | gRoadID[3] << 0;
	kind = gRoadKind[0] << 8 | gRoadKind[1] << 0;


	//-----------------------------------
	//	↑この部分のみを編集する↑
	//-----------------------------------

	//	下記にて正しく道路IDと道路種別が標示されることを確認すること
	printf("道路ID：0x%x\n", road);		//	0x12345678
	printf("道路種別：0x%x\n", kind);	//	0x9abc

	return 0;
}