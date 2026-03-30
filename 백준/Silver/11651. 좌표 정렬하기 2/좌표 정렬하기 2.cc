#include "iostream"
#include "vector"
#include "algorithm"
//#include <stdlib.h>
//#include <cstdlib>

using namespace std;

bool compare(pair<int, int> a, pair<int, int> b)
{
	if (a.second != b.second)
	{
		return a.second <= b.second;
	}
	else
	{
		return a.first <= b.first;
	}
}

int main()
{
	/*

	좌표 정렬하기

	2차원 평면 위에 점 N개가 주어진다.

	1 <= N <= 100,000

	N개의 줄에는 i번점의 위치 xi와 yi가 주어진다.
	(-100,000 <= xi, yi <= 100,000) 좌표는 항상 정수
	위치가 같은 두 점은 존재하지 않는다.

	*/

	int N, x, y;
	vector<pair<int, int>> arr;

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> x >> y;
		arr.push_back(make_pair(x, y));
	}

	sort(arr.begin(), arr.end(), compare);

	for (int i = 0; i < N; i++)
	{
		cout << arr[i].first << " " << arr[i].second << "\n";
	}
}
