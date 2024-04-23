#pragma once
#include "../manager/Scene.h"

class cResult : public cScene {
private:

public:
	// タイトル初期化
	void Init();
	// タイトル通常処理
	void Step();
	// タイトル描画処理
	void Draw();
	// タイトル終了処理
	void Fin();
};
