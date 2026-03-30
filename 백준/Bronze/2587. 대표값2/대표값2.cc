#include "iostream"
#include "vector"
#include "algorithm"

using namespace std;

int main()
{
	/*

	중앙값 문제

	평균과 중앙값을 구하라.

	주어지는 자연수는 100 보다 작은 10의 배수이다.

	*/

	vector<int> arr;
	
	int num;
	int average = 0;
	int mid = 0;

	for (int i = 0; i < 5; i++)
	{
		cin >> num;
		arr.push_back(num);

		average += num;
	}

	sort(arr.begin(), arr.end());

	average /= 5;
	mid = arr[2];

	cout << average << "\n" << mid;
}
