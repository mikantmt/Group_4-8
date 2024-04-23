#pragma once
#include "DxLib.h"

//サウンドの種類
enum SOUND_TYPE
{
	TITLE,

	SOUND_TYPE_NUM,
};

class Sound {
private:

	//サウンドのファイルパス
	const char SoundPath[SOUND_TYPE_NUM][256] =
	{
		"Data/Sound/Title.mp3"
	};

	int Sound[SOUND_TYPE_NUM];

public:
	//LOOPの時はInit,Stepを同時に呼ぶ
	void Init();
	//サウンド再生(サウンドの種類,
	//再生タイプ(ノーマル,バックグラウンド,ループ),音量(%))
	void Step(SOUND_TYPE sound, int playtype,int volume);
	void Fin();
};