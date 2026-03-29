#include "iostream"

using namespace std;

int main()
{
	/*
	ax + by = c
	dx + ey = f

	-999 <= a,b,c,d,e,f <= 999

	x,y 는 -999 <= x,y <= 999 가 보장된다.

	방법 1. 부르트 포스
	-999 부터 999 까지 순회

	*/

	int a, b, c, d, e, f;
	cin >> a >> b >> c >> d >> e >> f;
	
	int x = -1;
	int y = -1;

	bool right = false;

	for (int i = -999; i <= 999; i++)
	{
		for (int j = -999; j <= 999; j++)
		{
			int firstFunc = a * i + b * j;
			if (firstFunc != c) continue;

			int secondFunc = d * i + e * j;
			if (secondFunc != f) continue;

			x = i;
			y = j;

			right = true;
			break;
		}

		if (right) break;
	}
	

	cout << x << " " << y;
}