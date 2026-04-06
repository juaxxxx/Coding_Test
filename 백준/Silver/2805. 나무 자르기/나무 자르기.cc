#include <iostream>

using namespace std;
typedef long long ll;
typedef unsigned int uint;

ll CountTree(int* arr, ll arrLen, ll len)
{
	ll count = 0;

	for (int i = 0; i < arrLen; i++)
	{
		ll treeLen = arr[i] > len ? arr[i] - len : 0;
		count += treeLen;
	}
	return count;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	/*
	
	나무 M 미터가 필요하다.

	높이 H를 지정하면 위로 올라감.

	
	
	*/

	ll N, M;
	cin >> N >> M;

	ll start = 0;
	ll end = 0;
	ll result = 0;
	int* arr = new int[N];
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
		end = arr[i] > end ? arr[i] : end;
	}

	while (start <= end)
	{
		ll mid = (start + end) / 2;
		if (CountTree(arr, N, mid) >= M)
		{
			start = mid + 1;
			result = mid;
		}
		else
		{
			end = mid - 1;
		}
	}

	cout << result;

	delete[] arr;
	return 0;
}