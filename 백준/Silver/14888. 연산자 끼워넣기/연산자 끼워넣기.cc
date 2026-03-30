#include "iostream"
#include "vector"
#include "algorithm"

using namespace std;

int N;
int* numbers;
int* operators;
int myMin = 1000000001;
int myMax = -1000000001;

void BackTracking(int result, int cnt)
{
	if (cnt == N)
	{
		if (result < myMin)
		{
			myMin = result;
		}
		if (result > myMax)
		{
			myMax = result;
		}
		return;
	}

	for (int i = 0; i < 4; i++)
	{
		if (operators[i] > 0)
		{
			operators[i]--;
			if (i == 0)
			{
				BackTracking(result + numbers[cnt], cnt + 1);
			}
			else if (i == 1)
			{
				BackTracking(result - numbers[cnt], cnt + 1);
			}
			else if (i == 2)
			{
				BackTracking(result * numbers[cnt], cnt + 1);
			}
			else
			{
				BackTracking(result / numbers[cnt], cnt + 1);
			}
			operators[i]++;
		}
	}
	return;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	numbers = new int[N];
	operators = new int[4];

	for (int i = 0; i < N; i++)
	{
		cin >> numbers[i];
	}
	
	for (int i = 0; i < 4; i++)
	{
		cin >> operators[i];
	}

	BackTracking(numbers[0], 1);

	cout << myMax << "\n" << myMin;

	delete[] numbers, operators;

	return 0;
}

