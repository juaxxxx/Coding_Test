#include "iostream"
#include "vector"
#include "algorithm"

using namespace std;

int main()
{
	/*

	수 정렬

	*/

	int N, x;
	vector<int> arr;

	cin >> N;
	
	for (int i = 0; i < N; i++)
	{
		cin >> x;
		arr.push_back(x);
	}

	sort(arr.begin(), arr.end());

	for (int i = 0; i < N; i++)
	{
		cout << arr[i] << "\n";
	}

}
