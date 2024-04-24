#pragma once
#include "DxLib.h"
#include "../../Common.h"
#include "../SceneBase.h"

class cScene {
private:
	cSceneBase* scene;
public:

	static SCENE_TYPE SceneTypeID;
	static SCENE_ID SceneID;

	void SceneLoop();
	void SceneInit();

	int BackGroundHandle;
};