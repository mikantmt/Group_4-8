#include "SceneResult.h"

void cResult::Init()
{
	// �^�C�g���̃��[�v�����֑J��
	g_CurrentSceneId = SCENE_ID_LOOP_RESULT;
}

void cResult::Step()
{
	if (input.IsKeyPush(KEY_INPUT_SPACE)) {
		g_CurrentSceneId = SCENE_ID_FIN_RESULT;
	}
}

void cResult::Draw()
{
	DrawFormatString(MID_SCREEN_X, MID_SCREEN_Y, GetColor(255, 255, 255), "���U���g");
}

void cResult::Fin()
{
	// �v���C�V�[���ɑJ��
	g_CurrentSceneId = SCENE_ID_INIT_TITLE;
	
}