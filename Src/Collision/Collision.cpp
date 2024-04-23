#include "Collision.h"

void Collision::Init() {
	click_flag = false;
}


bool Collision::IsHitRect(int Ax, int Ay, int Aw, int Ah, int Bx, int By, int Bw, int Bh) {
	if (Bx < Ax + Aw &&
		Bx + Bw > Ax &&
		By + Bh > Ay &&
		By < Ay + Ah)
	{
		// �������Ă���Ƃ��̏���
		return true;
	}
	
	return false;
}

bool Collision::IsHitBox(VECTOR Obj1, VECTOR Size1, VECTOR Obj2, VECTOR Size2) {
	if (Obj2.x < Obj1.x + Size1.x &&
		Obj2.x + Size2.x > Obj1.x &&
		Obj2.y + Size2.y > Obj1.y &&
		Obj2.y < Obj1.y + Size1.y &&
		Obj2.z < Obj1.z + Size1.z &&
		Obj2.z + Size2.z > Obj1.z)
	{
		// �������Ă���Ƃ��̏���
		return true;
	}

	return false;
}


bool Collision::IsHitCircle(int x1, int y1, int r1, int x2, int y2, int r2){
	//�Q�̔��a�̍��v
	int sum_radius = r1 + r2;
	sum_radius *= sum_radius;

	//�~���m�̒���
	int x_len = x1 - x2;
	x_len *= x_len;

	int y_len = y1 - y2;
	y_len *= y_len;

	//�~�̓����蔻��
	if (sum_radius > x_len + y_len)
	{
		return true;
	}

	return false;
}

//IsHitCircle�̒�`
bool Collision::IsHitSphere(VECTOR Obj1, float radius1, VECTOR Obj2, float radius2)
{
	//�Q�̔��a�̍��v
	int sum_radius = radius1 + radius2;
	sum_radius *= sum_radius;

	//�����m�̒���
	int x_len = Obj1.x - Obj2.x;
	x_len *= x_len;

	int y_len = Obj1.y - Obj2.y;
	y_len *= y_len;

	int z_len = Obj1.z - Obj2.z;
	z_len *= z_len;

	//���̓����蔻��
	if (sum_radius > x_len + y_len + z_len)
	{
		return true;
	}

	return false;
}

bool Collision::RectToMousePointa(float X,float Y,float W,float H, int MX, int MY) {

	if (X + W >= MX && X <= MX
		&& Y + H >= MY && Y <= MY) {
		return true;
	}
	else
		return false;
}

bool Collision::IsClickOnRect(float X, float Y, float W, float H, int MX, int MY)
{
	//��`�̒��ɂ���

	if (RectToMousePointa(X,Y,W,H, MX, MY)) {
		if ((GetMouseInput() & MOUSE_INPUT_LEFT) != 0)
		{
			//������Ă���
			if (click_flag == false)
			{
				//������Â��Ă��Ȃ�
				click_flag = true;
				return true;
			}
			return false;
		}
		else
		{
			//������Ă��Ȃ�
			click_flag = false;
			return false;
		}
	}
	else
		return false;
}