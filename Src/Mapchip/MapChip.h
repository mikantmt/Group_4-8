#pragma once
#include "DxLib.h"

const int MAPCIP_X_SIZE = 32;		//幅
const int MAPCIP_Y_SIZE = 32;		//高さ
const int MAP_SIZE = 32;			//サイズ

const int MAPCIP_X_MAXNUM = 300;	//横方向の数
const int MAPCIP_Y_MAXNUM = 25;		//縦方向の数

//マップの種類
enum MAP_TYPE
{
	MAP_TYPE_1 = 0,	//Map1

	MAP_TYPE_NUM,
};

//マップ画像の種類
enum MAPIMAGE_TYPE
{
	MAPIMAGE_TYPE_NONE = -1,	//何もない

	MAPIMAGE_TYPE_BLACK = 0,	//黒
	MAPIMAGE_TYPE_GRAY,			//灰
	MAPIMAGE_TYPE_TRAP1,		//トラップ
	MAPIMAGE_TYPE_TRAP2,		//トラップ
	MAPIMAGE_TYPE_NOSHING1,		//なし
	MAPIMAGE_TYPE_NOSHING2,		//なし
	MAPIMAGE_TYPE_NOSHING3,		//なし
	MAPIMAGE_TYPE_NOSHING4,		//なし
	MAPIMAGE_TYPE_NOSHING5,		//なし


	MAPIMAGE_TYPE_NUM,
};

class MapChip {
private:

	//マップチップの種類
	enum MAPCIP_TYPE
	{
		MAP = 0,	//Mapのマップチップ

		MAPCIP_TYPE_NUM,
	};

	//csvのファイルパス
	const char CsvFilePath[MAP_TYPE_NUM][256] =
	{
		"Data/map/csv/map1.csv"	//MAP_TYPE_STAGE1
	};

	//マップチップのファイルパス
	const char MapCipFilePath[MAPCIP_TYPE_NUM][256] =
	{
		"Data/map/map.png",	//Mapのマップチップ
	};

	//各マップチップの数
	const int MapCipNum[MAPCIP_TYPE_NUM] =
	{
		MAPIMAGE_TYPE_NUM,	//Map
	};

	//各マップチップの画像分割数 [0] = x, [1] = y
	const int MapCipImageSplitNum[MAPCIP_TYPE_NUM][2] =
	{
		{ 3, 3,},	//Map
	};

	int MapCipHandle[MAPIMAGE_TYPE_NUM];

public:

	int MapID;

	int m_FileReadMapData[MAPCIP_Y_MAXNUM][MAPCIP_X_MAXNUM] = { 0 };

	void Init();
	void Step();
	void Draw(int X);
	void Read();
	void Fin();
};

