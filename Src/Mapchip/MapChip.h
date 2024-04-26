#pragma once
#include "DxLib.h"

const int MAPCIP_X_SIZE = 32;		//��
const int MAPCIP_Y_SIZE = 32;		//����
const int MAP_SIZE = 32;			//�T�C�Y

const int MAPCIP_X_MAXNUM = 300;	//�������̐�
const int MAPCIP_Y_MAXNUM = 25;		//�c�����̐�

//�}�b�v�̎��
enum MAP_TYPE
{
	MAP_TYPE_1 = 0,	//Map1

	MAP_TYPE_NUM,
};

//�}�b�v�摜�̎��
enum MAPIMAGE_TYPE
{
	MAPIMAGE_TYPE_NONE = -1,	//�����Ȃ�

	MAPIMAGE_TYPE_BLACK = 0,	//��
	MAPIMAGE_TYPE_GRAY,			//�D
	MAPIMAGE_TYPE_TRAP1,		//�g���b�v
	MAPIMAGE_TYPE_TRAP2,		//�g���b�v
	MAPIMAGE_TYPE_NOSHING1,		//�Ȃ�
	MAPIMAGE_TYPE_NOSHING2,		//�Ȃ�
	MAPIMAGE_TYPE_NOSHING3,		//�Ȃ�
	MAPIMAGE_TYPE_NOSHING4,		//�Ȃ�
	MAPIMAGE_TYPE_NOSHING5,		//�Ȃ�


	MAPIMAGE_TYPE_NUM,
};

class MapChip {
private:

	//�}�b�v�`�b�v�̎��
	enum MAPCIP_TYPE
	{
		MAP = 0,	//Map�̃}�b�v�`�b�v

		MAPCIP_TYPE_NUM,
	};

	//csv�̃t�@�C���p�X
	const char CsvFilePath[MAP_TYPE_NUM][256] =
	{
		"Data/map/csv/map1.csv"	//MAP_TYPE_STAGE1
	};

	//�}�b�v�`�b�v�̃t�@�C���p�X
	const char MapCipFilePath[MAPCIP_TYPE_NUM][256] =
	{
		"Data/map/map.png",	//Map�̃}�b�v�`�b�v
	};

	//�e�}�b�v�`�b�v�̐�
	const int MapCipNum[MAPCIP_TYPE_NUM] =
	{
		MAPIMAGE_TYPE_NUM,	//Map
	};

	//�e�}�b�v�`�b�v�̉摜������ [0] = x, [1] = y
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

