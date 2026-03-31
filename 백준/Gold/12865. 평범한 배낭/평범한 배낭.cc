#include <string>
#include <iostream>
#include <cstring>

using namespace std;

#define MAX 100001

int N, K, W, V;
int DP[MAX];

int main()
{
	/*
	N 개 물건.
	무게 W, 가치 V

	최대 K 만큼의 무게.

	V의 최댓값 구하기.

	1 <= N <= 100
	1 <= K <= 100,000
	1 <= W <= 100,000
	0 <= V <= 1,000
	*/

	cin >> N >> K;

	for (int i = 0; i < N; i++)
	{
		cin >> W >> V;

		for (int j = K; j >= W; j--)
		{
			DP[j] = max(DP[j], DP[j - W] + V);
		}
	}

	cout << DP[K];
}