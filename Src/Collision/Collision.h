#include "DxLib.h"

#ifndef __COLLISION_H__
#define __COLLISION_H__

class Collision {
private:
	bool click_flag;
public:
	void Init();
	void Play();
	void Draw();
	void Fin();

	//矩形との当たり判定
	bool IsHitRect(float Ax, float Ay, float Aw, float Ah, float Bx, float By, float Bw, float Bh);

	//箱同士の当たり判定(オブジェクト1の座標,オブジェクト1のサイズ,オブジェクト2の座標,オブジェクト2のサイズ)すべてVECTOR型
	bool IsHitBox(VECTOR Obj1, VECTOR Size1, VECTOR Obj2, VECTOR Size2);

	//円との当たり判定
	bool IsHitCircle(float x1, float y1, float r1, float x2, float y2, float r2);

	//球同士の当たり判定(オブジェクト1の座標,オブジェクト1の半径,オブジェクト2の座標,オブジェクト2の半径)
	bool IsHitSphere(VECTOR Obj1, float radius1, VECTOR Obj2, float radius2);

	//矩形とマウスポインタの当たり判定
	//引数(X座標,Y座標,幅,高さ,マウスのX座標,マウスのY座標)
	bool RectToMousePofloata(float X, float Y, float W, float H,float MX,float MY);

	//矩形とクリック当たり判定
	//引数(X座標,Y座標,幅,高さ,マウスのX座標,マウスのY座標)
	bool IsClickOnRect(float X, float Y, float W, float H, float MX, float MY);
};

#endif
