#include "iostream"

using namespace std;

int main()
{
	/*
	자연수 N의 분해합은 N과 N을 이루는 각 자리수의 합

	자연수 M의 분해합이 N인 경우 M을 N의 생성자라 한다.

	N의 가장 작은 생성자를 구해라.

	N - 1 부터 하나씩 내려가면서 확인하면 안되지.
	
	일단 1부터 올라가면서 확인하는거로 만들어 보자.
	*/

	int N;
	cin >> N;

	int M = 0;

	int digit = 10;

	for (int i = 1; i < N; i++)
	{
		// 자리수별
		int num = i;
		int sum = 0;

		while (true)
		{
			int rest = num % digit;
			sum += rest;
			num /= digit;

			if (num == 0)
				break;
		}

		if (i + sum == N)
		{
			M = i;
			break;
		}
	}

	cout << M;
}