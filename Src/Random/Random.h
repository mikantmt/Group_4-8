#pragma once
#include "DxLib.h"

class Random {
public:
	//下限と上限を設定し,指定範囲から乱数を取得する関数
	//引数(下限,上限)
	float ScopingRand(float min, float max);

	//下限と上限を設定,さらにその範囲から取得したくない範囲を設定し指定範囲から乱数を取得する関数
	//引数(下限,上限,除外範囲の下限,除外範囲の上限)
	float OutRand(float min, float max, float out_min, float out_max);
};