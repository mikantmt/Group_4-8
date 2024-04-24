#include "SceneTitle.h"

void cTitle::Init()
{
	collision.Init();

	sound.Init();
}

void cTitle::Step()
{
	if (input.IsKeyPush(KEY_INPUT_SPACE)) {
		cScene::SceneTypeID = SCENE_TYPE::TYPE_ID_FIN;
	}
}

void cTitle::Draw()
{
	DrawFormatString(MID_SCREEN_X, MID_SCREEN_Y, GetColor(0, 255, 255), "ƒ^ƒCƒgƒ‹");
}

void cTitle::Fin()
{
	sound.Fin();

	cScene::SceneID = SCENE_ID::SCENE_ID_PLAY;
}