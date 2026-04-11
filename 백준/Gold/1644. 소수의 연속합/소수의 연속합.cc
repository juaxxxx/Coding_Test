#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef unsigned int uint;

vector<uint> IsPrime(uint n)
{
	vector<bool> isprime(n + 1, true);
	vector<uint> prime;
	isprime[0] = false;
	if (n >= 1) isprime[1] = false;

	for (uint i = 2; i <= n; i++)
	{
		if (isprime[i])
		{
			prime.push_back(i);

			for (uint j = i * i; j <= n; j += i)
			{
				isprime[j] = false;
			}
		}
	}

	return prime;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	/*
	
	하나 이상의 연속된 소수의 합으로 나타낼 수 있는 자연수.

	자연수 N 이 주어졌을 때,
	연속된 소수의 합으로 나타낼 수 있는 경우의 수를 구하라.

	1. 소수 판정
	
	2, 3, 5 , 7, 11, 13

	2. N보다 작으면 right++
	3. N보다 크면 left++
	4. N과 같으면 경우의수++, left++, right++

	

	*/
	
	uint N;
	cin >> N;

	vector<uint> prime = IsPrime(N);

	uint pCount = prime.size();
	uint count = 0;
	uint left = 0;
	uint right = 0;
	uint sum = pCount > 0 ? prime[0] : 0;

	while (right >= left && right < pCount && left < pCount)
	{
		if (sum < N)
		{
			if (++right >= pCount)
			{
				continue;
			}
			sum += prime[right];
		}
		else if (sum > N)
		{
			sum -= prime[left++];
		}
		else
		{
			count++;

			sum -= prime[left++];
			if (++right >= pCount)
			{
				continue;
			}
			sum += prime[right];
		}
	}

	cout << count;

	return 0;
}