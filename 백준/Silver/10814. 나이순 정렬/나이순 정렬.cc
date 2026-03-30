#include "iostream"
#include "vector"
#include "algorithm"
#include "set"

using namespace std;

bool comp(pair<pair<int, int>, string> left, pair<pair<int, int>, string> right)
{
	if (left.first.first == right.first.first)
	{
		return left.first.second < right.first.second;
	}
	else
	{
		return left.first.first < right.first.first;
	}
}

int main()
{
	/*

	1. 나이 증가순.
	2. 먼저 가입한 사람 앞에

	1 <= N <= 100,000
	1 <= 나이 <= 200
	이름 <= 100
	*/

	int N;
	int age;
	string name;
	vector<pair<pair<int, int>, string>> arr;

	cin >> N;

	int order = 1;
	for (int i = 0; i < N; i++)
	{
		cin >> age >> name;
		arr.push_back(make_pair(make_pair(age, order), name));
		order++;
	}

	sort(arr.begin(), arr.end(), comp);

	for (int i = 0; i < N; i++)
	{
		cout << arr[i].first.first << " " << arr[i].second << "\n";
	}

	return 0;
}
