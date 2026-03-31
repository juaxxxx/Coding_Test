#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int N;
int* lines;
int* dp;
int myMax = 1;

bool comp(pair<int, int> left, pair<int, int> right)
{
	return left.first < right.first;
}

void GetAnswer()
{
	dp[0] = 1;
	myMax = 1;

	for (int i = 1; i < N; i++)
	{
		dp[i] = 1;

		for (int j = 0; j < i; j++)
		{
			if (lines[i] > lines[j])
			{
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}

		myMax = myMax < dp[i] ? dp[i] : myMax;
	}
}

int main()
{

	cin >> N;
	lines = new int[N];
	dp = new int[N];
	vector<pair<int, int>> v;
	
	int x, y;
	for (int i = 0; i < N; i++)
	{
		cin >> x >> y;
		
		v.push_back(make_pair(x, y));
	}

	sort(v.begin(), v.end(), comp);

	for (int i = 0; i < N; i++)
	{
		lines[i] = v[i].second;
	}

	GetAnswer();

	cout << N - myMax;

	delete[] lines, dp;
}