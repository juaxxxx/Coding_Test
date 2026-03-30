#include "iostream"
#include "vector"
#include "algorithm"
#include "map"
#include "set"

using namespace std;



int main()
{
	/*

	N 개의 좌표 X1, X2, ... , Xn

	압축이라는게
	정렬 순서대로 0, 1, 2 ... 로 변환하는거 같다.

	1 <= N <= 1,000,000
	-10e9 <= X <= 10e9

	*/

	int N;
	cin >> N;
	vector<int> v(N);

	for (int i = 0; i < N; i++)
	{
		cin >> v[i];
	}

	vector<int> ans(v);
	sort(ans.begin(), ans.end());
	ans.erase(unique(ans.begin(), ans.end()), ans.end());

	for (const auto& val : v)
	{
		auto it = std::lower_bound(ans.begin(), ans.end(), val);
		cout << distance(ans.begin(), it) << ' ';
	}
	return 0;
}
