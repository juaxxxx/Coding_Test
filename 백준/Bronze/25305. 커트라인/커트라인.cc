#include "iostream"
#include "vector"
#include "algorithm"

using namespace std;

int main()
{
	/*

	점수가 가장 높은 k명이 수상한다.
	커트라인 구하기.

	응시자 수: N
	수상 수: k
	각 학생의 점수: x

	1 <= N <= 1000
	1 <= k <= N
	0 <= x <= 10000

	*/

	int N, k, x;
	vector<int> arr;
	int cutLine = -1;

	cin >> N >> k;

	for (int i = 0; i < N; i++)
	{
		cin >> x;
		arr.push_back(x);
	}

	sort(arr.rbegin(), arr.rend());
	
	cutLine = arr[k - 1];

	if (cutLine == -1)
	{
		cout << "CutLine Error: -1";
	}
	else
	{
		cout << cutLine;
	}
}
