#include "iostream"

using namespace std;

int main()
{
	/*

	MN개의 단위 정사각형으로 나누어져 있는 MxN 크기의 보드
	
	8x8 크기의 체스판으로 만들어야 한다.

	검은색, 흰색이 번갈아 있어야 한다.



	*/

	int N, M;
	cin >> N >> M;

	char** chess = new char* [N];
	for (int i = 0; i < N; i++)
	{
		chess[i] = new char[M];
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> chess[i][j];
		}
	}

	// chess[N][M]

	int x = N - 8;
	int y = M - 8;

	int Min = 1000000000;

	for (int i = 0; i <= x; i++)
	{
		for (int j = 0; j <= y; j++)
		{
			int draw1 = 0;
			int draw2 = 0;

			// 시작점 i, j
			for (int a = i; a < i + 8; a++)
			{
				for (int b = j; b < j + 8; b++)
				{
					if ((a + b) % 2 == 0)
					{
						if (chess[a][b] != 'B')
						{
							draw1 += 1;
						}
						if (chess[a][b] != 'W')
						{
							draw2 += 1;
						}
					}
					else
					{
						if (chess[a][b] != 'W')
						{
							draw1 += 1;
						}
						if (chess[a][b] != 'B')
						{
							draw2 += 1;
						}
					}
				}
			}

			int min12 = min(draw1, draw2);
			if (Min > min12)
			{
				Min = min12;
			}
		}
	}

	cout << Min;
}