#include <iostream>
#include <algorithm>

using namespace std;

int GetRouterCount(int* homes, int arrLen ,int len)
{
	int count = 0;
	int value = 0;

	for (int i = 0; i < arrLen; i++)
	{
		if (i == 0)
		{
			count++;
			value = homes[i];
		}
		else
		{
			if (homes[i] - value >= len)
			{
				count++;
				value = homes[i];
			}
		}

	}

	int rcount = 0;
	int rvalue = 0;

	for (int i = arrLen - 1; i >= 0; i--)
	{
		if (i == arrLen - 1)
		{
			rcount++;
			rvalue = homes[i];
		}
		else
		{
			if (rvalue - homes[i]  >= len)
			{
				rcount++;
				rvalue = homes[i];
			}
		}

	}

	int maxCount = count > rcount ? count : rcount;
	return maxCount;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	/*
	
	1 2 4 8 9

	*/



	int N, C;
	cin >> N >> C;
	
	int* homes = new int[N];
	int startPos;
	int endPos;
	int result = 0;

	for (int i = 0; i < N; i++)
	{
		cin >> homes[i];
	}

	sort(homes, homes + N);

	startPos = 1;
	endPos = homes[N - 1] - homes[0];

	while (startPos <= endPos)
	{
		int mid = (startPos + endPos) / 2;

		if (GetRouterCount(homes, N, mid) >= C)
		{
			result = mid > result ? mid : result;
			startPos = mid + 1;
		}
		else
		{
			endPos = mid - 1;
		}

	}

	cout << result;

	return 0;
}