#include "Score.h"

FILE* Score::fScore;

float Score::ScoreNum;
float Score::HighScoreNum;


void Score::Init()
{
	ScoreNum = 0;
}

void Score::Reset()
{
	//�n�C�X�R�A�����Z�b�g
	HighScoreNum = 0;

	// �t�@�C�����J��
	errno_t err;
	err = fopen_s(&Score::fScore, "Data/File/File.txt", "w+");

	if (Score::fScore != NULL)
	{
		fclose(Score::fScore);
	}
}

void Score::Add(float AddScoreNum){
	ScoreNum += AddScoreNum;
}

// �n�C�X�R�A�̍X�V
void Score::Update()
{
	// �ۑ����ꂽ�n�C�X�R�A���傫��������
	if (ScoreNum > HighScoreNum)
	{
		// �n�C�X�R�A�ɃX�R�A����
		HighScoreNum = ScoreNum;

		// �t�@�C�����J��
		errno_t err;
		err = fopen_s(&Score::fScore, "Data/Score/Score.txt", "w+");

		if (Score::fScore != NULL)
		{
			fprintf_s(Score::fScore, "%f", HighScoreNum);

			// �t�@�C���͕���
			fclose(Score::fScore);
		}
	}
}

void Score::Read() {
	errno_t err;
	err = fopen_s(&Score::fScore, "Data/Score/Score.txt", "r");

	if (Score::fScore != NULL)
	{
		fscanf_s(Score::fScore, "%f", &HighScoreNum);

		// �t�@�C���͕���
		fclose(Score::fScore);
	}
}