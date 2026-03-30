#include "iostream"

using namespace std;

bool Check666Num(int* num, int* count, int i, int N);

int main()
{
	/*

	종말의 수 - 6이 적어도 3개 이상 연속으로 들어가는 수.

	666, 1666, 2666...

	N번째로 작은 종말의 수 구하기

	N <= 10000 (N은 자연수)

	666
	1666....
	
	1. 브루트포스

	666 - 1
	1666 - 2
	부터 하나씩 찾기

	일단 첫번째, 두번째는 고정으로 찾고 다음 브루트 시작.

	*/

	int N;
	cin >> N;
	
	int* num = new int;
	int* count = new int;

	if (N == 1)
	{
		*num = 666;
	}
	else if (N == 2)
	{
		*num = 1666;
	}
	else
	{
		*count = 2;
		
		for (int i = 2666; i < 2147483647; i++)
		{
			if (Check666Num(num, count, i, N))
			{
				break;
			}
		}
	}

	cout << *num;

	return 0;
}

bool Check666Num(int* num, int* count, int i, int N)
{
	int sixCount = 0;
	int maxSixCount = 0;
	int number = i;

	while (true)
	{
		int rest = number % 10;
		if (rest == 6)
		{
			sixCount++;
			maxSixCount = max(maxSixCount, sixCount);
		}
		else
		{
			sixCount = 0;
		}
		number /= 10;
		if (number == 0)
		{
			break;
		}
	}

	if (maxSixCount >= 3)
	{
		(*count)++;
		*num = i;

		if (N == *count)
		{
			return true;
		}
	}

	return false;
}