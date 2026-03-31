#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int N;
int** dp;
int* A;
int myMax = 1;

void bitonic()
{
	dp[0][0] = 1;
	dp[0][1] = 1;

	for (int i = 1; i < N; i++)
	{
		dp[i][0] = 1;

		for (int j = 0; j < i; j++)
		{
			if (A[j] < A[i])
			{
				dp[i][0] = max(dp[i][0], dp[j][0] + 1);
				if (myMax < dp[i][0])
				{
					myMax = dp[i][0];
				}
			}
		}
	}

	for (int i = 1; i < N; i++)
	{
		dp[i][1] = 1;

		for (int j = 0; j < i; j++)
		{
			if (A[j] > A[i])
			{
				int maxValue = max(dp[j][0], dp[j][1]);

				dp[i][1] = max(dp[i][1], maxValue + 1);
				if (myMax < dp[i][1])
				{
					myMax = dp[i][1];
				}
			}
		}
	}


}

int main()
{

	/*

	수열 A에서 바이토닉 수열이면서 가장 긴 수열의 길이를 구하여라.

	수열 A의 크기 N
	1 <= N <= 1,000
	1 <= Ai <= 1,000

	1 5 2 1 4 3 4 5 2 1

	[0] : 상승 부분.
	[1] : 하락 부분.

	*/

	N;
	cin >> N;
	A = new int[N];
	dp = new int*[N];

	for (int i = 0; i < N; i++)
	{
		dp[i] = new int[2];
	}

	for (int i = 0; i < N; i++)
	{
		cin >> A[i];
	}

	bitonic();

	cout << myMax;
	
	for (int i = 0; i < N; i++)
	{
		delete[] dp[i];
	}
	delete[] A, dp;
}