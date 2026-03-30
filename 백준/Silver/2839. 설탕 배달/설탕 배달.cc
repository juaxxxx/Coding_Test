#include "iostream"

using namespace std;

int main()
{
	/*

	상근상근상근이 설탕 배달

	정확히 N 배달 해야한다.
	봉지는 3 또는 5 있다.
	상근이는 귀찮아
	적어야 된다.

	예) 18 배달 할라면 5-3, 3-1 개

	N 킬로그램 배달해야 할 때, 봉지 몇 개 가져가면 되는지

	3 <= N <= 5000

	정확하게 N 킬로그램을 만들 수 없다면 -1 출력


	---
	18

	1. 단, N을 5로 나눠.
	몫을 기준으로 줄여가면서 3 넣어서 되는지 확인하기.

	*/

	int N;
	cin >> N;

	int result = -1;
	int i = N / 5;

	for (i; i >= 0; i--)
	{
		int fiveGuys = 5 * i;
		int threeGuys = N - fiveGuys;

		if (threeGuys % 3 == 0)
		{
			int three = threeGuys / 3;
			result = i + three;
			break;
		}
	}

	cout << result;
}
