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
	//ハイスコアをリセット
	HighScoreNum = 0;

	// ファイルを開く
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

// ハイスコアの更新
void Score::Update()
{
	// 保存されたハイスコアより大きかったら
	if (ScoreNum > HighScoreNum)
	{
		// ハイスコアにスコアを代入
		HighScoreNum = ScoreNum;

		// ファイルを開く
		errno_t err;
		err = fopen_s(&Score::fScore, "Data/Score/Score.txt", "w+");

		if (Score::fScore != NULL)
		{
			fprintf_s(Score::fScore, "%f", HighScoreNum);

			// ファイルは閉じる
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

		// ファイルは閉じる
		fclose(Score::fScore);
	}
}