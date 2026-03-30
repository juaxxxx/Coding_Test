#include "iostream"
#include "vector"
#include "algorithm"
#include "set"

using namespace std;

struct order
{
	bool operator() (const string& left, const string& right) const
	{
		if (left.size() == right.size())
		{
			return left < right;
		}
		else
		{
			return left.size() < right.size();
		}
	}
};

int main()
{
	/*

	알파벳 소문자로 이루어진 N개의 단어가 들어오면 아래와 같은 조건에 따라 정렬

	1. 길이가 짧은 것
	2. 길이가 같으면 사전 순

	3. 중복된 단어는 하나만 남기고 제거

	1 <= N 20,000

	문자열의 길이 < 50

	*/

	int N;
	string str;
	set<string, order> arr;

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> str;
		arr.insert(str);
	}
	
	for (const string& s : arr)
	{
		cout << s << "\n";
	}
}
