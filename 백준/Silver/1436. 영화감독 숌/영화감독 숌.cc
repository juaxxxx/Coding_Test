#include "iostream"
#include "string"

using namespace std;

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

	int title;
	string stitle;
	int check = 0;
	int N;

	cin >> N;

	for (title = 666; ; title++)
	{
		stitle = to_string(title);

		if (stitle.find("666") != -1)
		{
			check++;
			if (check == N)
			{
				cout << title;
				break;
			}
		}
	}

	return 0;
}
