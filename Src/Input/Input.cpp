#include "Input.h"

#define KEY_BUF_LEN	(256)

// 現在のフレームのキー情報
char currentKeyBuf[KEY_BUF_LEN] = { 0 };

// 前のフレームのキー情報
char preKeyBuf[KEY_BUF_LEN] = { 0 };

// 入力制御初期化
void Input::InitInput()
{
	for (int index = 0; index < KEY_BUF_LEN; index++)
	{
		currentKeyBuf[index] = '\0';
		preKeyBuf[index] = '\0';
	}
}

// 入力制御ステップ
void Input::StepInput()
{
	// 前フレームのキー情報変数に記録しておく
	for (int index = 0; index < KEY_BUF_LEN; index++)
	{
		preKeyBuf[index] = currentKeyBuf[index];
	}

	// 現在のキー情報を取得
	GetHitKeyStateAll(currentKeyBuf);
}

bool Input::IsKeyPush(int key_code)
{
	// 前フレームで押されていない　かつ　現フレームで押されている
	if (preKeyBuf[key_code] == 0 && currentKeyBuf[key_code] == 1) {
		return true;
	}

	// 押されていないのでfalse
	return false;
}

bool Input::IsKeyKeep(int key_code)
{
	// 前フレームで押されていない　かつ　現フレームで押されている
	if (preKeyBuf[key_code] == 1 && currentKeyBuf[key_code] == 1) {
		return true;
	}

	// 押されていないのでfalse
	return false;
}

//たった今離されたか
bool Input::IsKeyRelease(int key_code)
{
	{
		//前フレで押されている現フレで押されていない
		if (preKeyBuf[key_code] == 1 && currentKeyBuf[key_code] == 0)
			return true;

		//押されていないので false
		return false;
	}
}

//単純に押されているか
bool Input::IsButtonDown(int key_code)
{
	//現フレで押されている（前フレの状態は関係なし）
	if (currentKeyBuf[key_code] == 1)
		return true;

	return false;
}