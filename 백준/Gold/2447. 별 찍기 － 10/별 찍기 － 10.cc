#include "iostream"
#include "vector"
#include "algorithm"

using namespace std;

char** stars;

void DrawStar(int startX, int endX, int startY, int endY);
void DrawSpace(int startX, int endX, int startY, int endY);

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	/*

	N 의 패턴은 NxN 정사각형 모양이다.
	
	크기 3의 패턴은 가운데에 공백이 있고, 가운데를 제외한 모든 칸에 별이 하나씩 있는 패턴

	N이 3보다 클 경우, 크기 N의 패턴은 공백으로 채워진
	가운데의 (N/3)x(N/3) 정사각형을 크기 N/3의 패턴으로 둘러싼 형태

	N은 3의 거듭제곱

	1 <= k < 8

	---
	27

	9 9 9
	9 9 9
	9 9 9

	가운데 빼고 각각 재귀 함수 호출

	1일 때 별 그리기.

	*/

	int N;
	cin >> N;

	stars = new char* [N] {};
	for (int i = 0; i < N; i++)
	{
		stars[i] = new char[N] {};
	}

	DrawStar(0, N, 0, N);
	
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cout << stars[i][j];
		}

		cout << "\n";
	}

	for (int i = 0; i < N; i++)
	{
		delete[] stars[i];
	}

	delete[] stars;

	return 0;
}


void DrawStar(int startX, int endX, int startY, int endY)
{
	if (startX + 1 == endX && startY + 1 == endY)
	{
		stars[startX][startY] = '*';
		return;
	}

	int gap = (endX - startX) / 3;
	int midX = startX + gap;
	int midY = startY + gap;

	for (int i = startX; i < endX; i += gap)
	{
		for (int j = startY; j < endY; j += gap)
		{
			if (i == midX && j == midY)
			{
				DrawSpace(i, i + gap, j, j + gap);
			}
			else
			{
				DrawStar(i, i + gap, j, j + gap);
			}
		}
	}
}

void DrawSpace(int startX, int endX, int startY, int endY)
{
	for (int i = startX; i < endX; i++)
	{
		for (int j = startY; j < endY; j++)
		{
			stars[i][j] = ' ';
		}
	}
}