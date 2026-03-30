#include "iostream"
#include "vector"
#include "algorithm"
//#include <stdlib.h>
//#include <cstdlib>

using namespace std;

int main()
{
	/*

	수 정렬

	N 은 10,000,000,000보다 작거나 같은 자연수

	*/

	string Nstr;
	vector<int> arr;

	cin >> Nstr;
	
	for (int i = 0; i < Nstr.size(); i++)
	{
		int x = Nstr[i] - '0';

		arr.push_back(x);
	}

	sort(arr.begin(), arr.end(), greater<int>());

	for (int i = 0; i < arr.size(); i++)
	{
		cout << arr[i];
	}

}
