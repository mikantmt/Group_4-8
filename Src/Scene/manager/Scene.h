#pragma once
#include "DxLib.h"
#include "../../Common.h"
#include "../../Collision/Collision.h"
#include "../../Input/Input.h"
#include "../../Sound/Sound.h"

enum SCENE_ID
{
	// �^�C�g���V�[����ID
	SCENE_ID_INIT_TITLE = 100,	// ������
	SCENE_ID_LOOP_TITLE,		// ���[�v
	SCENE_ID_FIN_TITLE,			// �I��

	// �V�[���̏��
	SCENE_ID_INIT_SELECT = 200,	// ������
	SCENE_ID_LOOP_SELECT,			// ���[�v
	SCENE_ID_FIN_SELECT,			// �I��

	// �V�[���̏��
	SCENE_ID_INIT_PLAY = 300,	// ������
	SCENE_ID_LOOP_PLAY,			// ���[�v
	SCENE_ID_FIN_PLAY,			// �I��

	// �V�[���̏��
	SCENE_ID_INIT_RESULT = 400,	// ������
	SCENE_ID_LOOP_RESULT,		// ���[�v
	SCENE_ID_FIN_RESULT,		// �I��
};

class cScene {
	public:
		Collision collision;
		Sound sound;
		Input input;

		virtual void Init() = 0;
		virtual void Step() = 0;
		virtual void Draw() = 0;
		virtual void Fin()  = 0;

		int BackGroundHandle;
};

//�@���݂̃V�[��ID
extern SCENE_ID g_CurrentSceneId;