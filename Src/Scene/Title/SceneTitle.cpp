#include "SceneTitle.h"

void cTitle::Init()
{
	collision.Init();

	sound.Init();
	sound.Step(TITLE, DX_PLAYTYPE_LOOP, 60);
}

void cTitle::Step()
{
	
	if (input.IsKeyPush(KEY_INPUT_SPACE)) {
		cScene::SceneTypeID = SCENE_TYPE::TYPE_ID_FIN;
	}
}

void cTitle::Draw()
{
	SetFontSize(128);
	DrawFormatString(MID_SCREEN_X - 128, MID_SCREEN_Y - (MID_SCREEN_Y / 2), GetColor(0, 255, 255), "HIDE");
	SetFontSize(16);
}

void cTitle::Fin()
{
	sound.Fin();

	cScene::SceneID = SCENE_ID::SCENE_ID_PLAY;
}