#include "iostream"
#include "vector"
#include "algorithm"

using namespace std;

int* tmp;
int Num = -1;
int cnt = 0;
int N;
int K;

void Merge(int A[], int p, int q, int r)
{
	int i = p;
	int j = q + 1;
	int t = 1;

	while (i <= q && j <= r)
	{
		if (A[i] <= A[j])
		{
			tmp[t++] = A[i++];
			cnt++;
			if (K == cnt)
			{
				Num = tmp[t - 1];
			}
		}
		else
		{
			tmp[t++] = A[j++];
			cnt++;
			if (K == cnt)
			{
				Num = tmp[t - 1];
			}
		}
	}
	while (i <= q)
	{
		tmp[t++] = A[i++];
		cnt++;
		if (K == cnt)
		{
			Num = tmp[t - 1];
		}
	}
	while (j <= r)
	{
		tmp[t++] = A[j++];
		cnt++;
		if (K == cnt)
		{
			Num = tmp[t - 1];
		}
	}
	i = p;
	t = 1;

	while (i <= r)
	{
		A[i++] = tmp[t++];
	}
}

void MergeSort(int A[], int p, int r)
{
	if (p >= r) return;

	int q = (p + r) / 2;
	MergeSort(A, p, q);
	MergeSort(A, q + 1, r);
	Merge(A, p, q, r);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	/*

	병합 정렬

	*/
	
	cin >> N >> K;
	int* A = new int[N];
	tmp = new int[N];

	for (int i = 0; i < N; i++)
	{
		cin >> A[i];
	}


	MergeSort(A, 0, N - 1);

	cout << Num;

	delete[] A, tmp;


	return 0;
}
