//�E�B���h�E��\������v���O�����i�ЂȌ`�j

#include "DxLib.h"	//DX���C�u�����̃C���N���[�h

#include "Common.h"
#include "Scene/manager/Scene.h"
#include "Scene/Title/SceneTitle.h"
#include "Scene/Play/ScenePlay.h"
#include "Scene/Result/SceneResult.h"
#include "Input/Input.h"

SCENE_ID g_CurrentSceneId = SCENE_ID_INIT_TITLE;

// Win32�A�v���P�[�V������ WinMain�֐� ����n�܂�
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	//�E�B���h�E�̏�Ԃ�ݒ肷��
	ChangeWindowMode(true);

	//DX���C�u�����̏�����
	if (DxLib_Init() == -1) {
		return -1;
	}

	// ��ʃT�C�Y��ύX
	SetGraphMode(SCREEN_SIZE_X, SCREEN_SIZE_Y, 32);

	//�`�悷��X�N���[����ݒ肷��
	SetDrawScreen(DX_SCREEN_BACK);
	
	//-----------------------------------------
	//��ԍŏ��ɂP�񂾂���鏈���������ɏ���

	//�N���X�̐錾
	cScene* Scene = nullptr;
	Input input;

	//-----------------------------------------

	//�Q�[�����C�����[�v
	while (ProcessMessage() != -1)
	{
		if (CheckHitKey(KEY_INPUT_ESCAPE) == 1)
		{
			//�G�X�P�[�v�L�[�������ꂽ��I��
			break;
		}

		//��ʂɕ\�����ꂽ���̂�������
		ClearDrawScreen();

		input.StepInput();

		//-----------------------------------------
		//��������Q�[���̖{�̂��������ƂɂȂ�
		//-----------------------------------------
		
		switch (g_CurrentSceneId)
		{

		case SCENE_ID_INIT_TITLE:

			Scene = new cTitle;
			if (Scene) {
				Scene->Init();
			}

			break;
		case SCENE_ID_LOOP_TITLE:

			if (Scene) {
				Scene->Step();
				Scene->Draw();
			}


			break;
		case SCENE_ID_FIN_TITLE:
			if (Scene) {
				Scene->Fin();
				delete Scene;
				Scene = nullptr;
			}
			break;

		case SCENE_ID_INIT_PLAY:

			Scene = new cPlay;
			if (Scene) {
				Scene->Init();
			}

			break;
		case SCENE_ID_LOOP_PLAY:

			if (Scene) {
				Scene->Step();
				Scene->Draw();
			}


			break;
		case SCENE_ID_FIN_PLAY:
			if (Scene) {
				Scene->Fin();
				delete Scene;
				Scene = nullptr;
			}
			break;

		case SCENE_ID_INIT_RESULT:

			Scene = new cResult;
			if (Scene) {
				Scene->Init();
			}

			break;
		case SCENE_ID_LOOP_RESULT:

			if (Scene) {
				Scene->Step();
				Scene->Draw();
			}


			break;
		case SCENE_ID_FIN_RESULT:
			if (Scene) {
				Scene->Fin();
				delete Scene;
				Scene = nullptr;
			}
			break;
		default:
			break;
		}

		//-----------------------------------------
		//���[�v�̏I����
		//�t���b�v�֐�
		ScreenFlip();

	}

	//-----------------------------------------
	//�Ō�ɂP�񂾂���鏈���������ɏ���


	//-----------------------------------------
	//DX���C�u�����̌㏈��
	DxLib_End();

	return 0;
}

