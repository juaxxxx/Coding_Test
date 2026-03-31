#include <string>
#include <iostream>
#include <cstring>

using namespace std;

#define MAX 1001

char A[MAX], B[MAX];
int dp[MAX][MAX];

void lcs()
{
	int Asize = strlen(A);
	int Bsize = strlen(B);

	for (int i = 1; i <= Asize; i++)
	{
		for (int j = 1; j <= Bsize; j++)
		{
			if (A[i - 1] == B[j- 1])
			{
				dp[i][j] = dp[i - 1][j - 1] + 1;
			}
			else
			{
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
		}
	}

	cout << dp[Asize][Bsize];
}


int main()
{
	cin >> A >> B;

	lcs();
}