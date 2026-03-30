#include "iostream"
#include "vector"
#include "algorithm"

using namespace std;

int main()
{
	/*

	수 정렬

	1 <= N <= 10,000,000
	x 는 10000보다 작은 자연수

	*/

	int N, x;
	int arr[10001]{0};

	cin >> N;
	
	for (int i = 0; i < 10001; i++)
	{
		arr[i] = 0;
	}

	for (int i = 0; i < N; i++)
	{
		cin >> x;
		arr[x]++;
	}

	for (int i = 0; i < 10001; i++)
	{
		int repeat = arr[i];
		for (int j = 0; j < repeat; j++)
		{
			cout << i << "\n";
		}
	}

}
