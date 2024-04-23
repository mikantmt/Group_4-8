#pragma once
#include "DxLib.h"

class Score {
public:
	static FILE* fScore;		//読込用の変数

	static float ScoreNum;		// スコアの値
	static float HighScoreNum;	// ハイスコアの値

	static void Init();		//スコア初期化
	static void Reset();	//ゲーム中に最高スコアをリセットできる
	//得点をスコアに加算
	static void Add(float AddScoreNum);
	static void Update();	//スコアがハイスコアより高ければcsvに保存
	static void Read();		//ハイスコアを読み込む
};
