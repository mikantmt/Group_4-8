#include "SceneResult.h"

void cResult::Init()
{
	// �^�C�g���̃��[�v�����֑J��
}

void cResult::Step()
{
	if (input.IsKeyPush(KEY_INPUT_SPACE)) {
		cScene::SceneTypeID = SCENE_TYPE::TYPE_ID_FIN;
	}
}

void cResult::Draw()
{
	DrawFormatString(MID_SCREEN_X, MID_SCREEN_Y, GetColor(255, 255, 255), "���U���g");
}

void cResult::Fin()
{
	// �v���C�V�[���ɑJ��
	cScene::SceneID = SCENE_ID::SCENE_ID_TITLE;
	
}