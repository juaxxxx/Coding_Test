#include <iostream>

using namespace std;
typedef unsigned int uint;

int countCable(int* arr, int arrLen, uint len)
{
	int count = 0;

	for (int i = 0; i < arrLen; i++)
	{
		count += arr[i] / len;
	}

	return count;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	/*
	
	N 개의 랜선을 만들어야 한다.

	K개의 랜선을 가지고 있다. 길이는 제각각

	랜선을 모두 N개의 같은 길이의 랜선으로 만들기 위해
	K개의 랜선을 잘라서 만들어야 한다.

	만들 수 있는 최대 랜선의 길이.

	요구하는 랜선 N 개
	가지고 있는 랜선 K 개

	1 <= K <= 10,000
	1 <= N <= 1,000,000

	K <= N

	랜선 길이 <= 2e31 - 1
	
	*/

	int k, n;
	uint start = 1, end = 0;
	uint result = 1;
	uint mid;

	cin >> k >> n;

	int* arr = new int[k];

	for (int i = 0; i < k; i++)
	{
		cin >> arr[i];
		end = arr[i] > end ? arr[i] : end;
	}

	while (start <= end)
	{
		mid = (start + end) / 2;
		if (countCable(arr, k, mid) >= n)
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