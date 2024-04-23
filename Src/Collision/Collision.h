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
	bool IsHitRect(int Ax, int Ay, int Aw, int Ah, int Bx, int By, int Bw, int Bh);

	//�����m�̓����蔻��(�I�u�W�F�N�g1�̍��W,�I�u�W�F�N�g1�̃T�C�Y,�I�u�W�F�N�g2�̍��W,�I�u�W�F�N�g2�̃T�C�Y)���ׂ�VECTOR�^
	bool IsHitBox(VECTOR Obj1, VECTOR Size1, VECTOR Obj2, VECTOR Size2);

	//�~�Ƃ̓����蔻��
	bool IsHitCircle(int x1, int y1, int r1, int x2, int y2, int r2);

	//�����m�̓����蔻��(�I�u�W�F�N�g1�̍��W,�I�u�W�F�N�g1�̔��a,�I�u�W�F�N�g2�̍��W,�I�u�W�F�N�g2�̔��a)
	bool IsHitSphere(VECTOR Obj1, float radius1, VECTOR Obj2, float radius2);

	//��`�ƃ}�E�X�|�C���^�̓����蔻��
	//����(X���W,Y���W,��,����,�}�E�X��X���W,�}�E�X��Y���W)
	bool RectToMousePointa(float X, float Y, float W, float H,int MX,int MY);

	//��`�ƃN���b�N�����蔻��
	//����(X���W,Y���W,��,����,�}�E�X��X���W,�}�E�X��Y���W)
	bool IsClickOnRect(float X, float Y, float W, float H, int MX, int MY);
};

#endif
