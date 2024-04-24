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

	//��`�Ƃ̓����蔻��
	bool IsHitRect(float Ax, float Ay, float Aw, float Ah, float Bx, float By, float Bw, float Bh);

	//�����m�̓����蔻��(�I�u�W�F�N�g1�̍��W,�I�u�W�F�N�g1�̃T�C�Y,�I�u�W�F�N�g2�̍��W,�I�u�W�F�N�g2�̃T�C�Y)���ׂ�VECTOR�^
	bool IsHitBox(VECTOR Obj1, VECTOR Size1, VECTOR Obj2, VECTOR Size2);

	//�~�Ƃ̓����蔻��
	bool IsHitCircle(float x1, float y1, float r1, float x2, float y2, float r2);

	//�����m�̓����蔻��(�I�u�W�F�N�g1�̍��W,�I�u�W�F�N�g1�̔��a,�I�u�W�F�N�g2�̍��W,�I�u�W�F�N�g2�̔��a)
	bool IsHitSphere(VECTOR Obj1, float radius1, VECTOR Obj2, float radius2);

	//��`�ƃ}�E�X�|�C���^�̓����蔻��
	//����(X���W,Y���W,��,����,�}�E�X��X���W,�}�E�X��Y���W)
	bool RectToMousePofloata(float X, float Y, float W, float H,float MX,float MY);

	//��`�ƃN���b�N�����蔻��
	//����(X���W,Y���W,��,����,�}�E�X��X���W,�}�E�X��Y���W)
	bool IsClickOnRect(float X, float Y, float W, float H, float MX, float MY);
};

#endif
