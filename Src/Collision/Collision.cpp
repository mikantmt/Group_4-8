#include "Collision.h"

void Collision::Init() {
	click_flag = false;
}


bool Collision::IsHitRect(float Ax, float Ay, float Aw, float Ah, float Bx, float By, float Bw, float Bh) {
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


bool Collision::IsHitCircle(float x1, float y1, float r1, float x2, float y2, float r2){
	//�Q�̔��a�̍��v
	float sum_radius = r1 + r2;
	sum_radius *= sum_radius;

	//�~���m�̒���
	float x_len = x1 - x2;
	x_len *= x_len;

	float y_len = y1 - y2;
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
	float sum_radius = radius1 + radius2;
	sum_radius *= sum_radius;

	//�����m�̒���
	float x_len = Obj1.x - Obj2.x;
	x_len *= x_len;

	float y_len = Obj1.y - Obj2.y;
	y_len *= y_len;

	float z_len = Obj1.z - Obj2.z;
	z_len *= z_len;

	//���̓����蔻��
	if (sum_radius > x_len + y_len + z_len)
	{
		return true;
	}

	return false;
}

bool Collision::RectToMousePofloata(float X,float Y,float W,float H, float MX, float MY) {

	if (X + W >= MX && X <= MX
		&& Y + H >= MY && Y <= MY) {
		return true;
	}
	else
		return false;
}

bool Collision::IsClickOnRect(float X, float Y, float W, float H, float MX, float MY)
{
	//��`�̒��ɂ���

	if (RectToMousePofloata(X,Y,W,H, MX, MY)) {
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