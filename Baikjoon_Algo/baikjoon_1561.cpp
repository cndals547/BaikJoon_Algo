#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int N, M;
int arr[10001];

void input()
{
	cin >> N >> M;
	for (int i = 1; i <= M; i++)
	{
		cin >> arr[i];
	}
}

void solution()
{
	long long left = 0;
	long long right = 60000000000;
	long long time = 0;
	if (N <= M)
	{
		cout << N << endl;
		return;
	}
	while (left <= right)
	{
		long long mid = (left + right) / 2;
		long long person = M;
		for (int i = 1; i <= M; i++)
		{
			person += mid / arr[i];
		}
		if (person >= N)
		{
			time = mid;
			right = mid - 1;
		}
		else
			left = mid + 1;
	}
	long long person = M;
	for (int i = 1; i <= M; i++)
	{
		person += ((time - 1) / arr[i]);
	}
	for (int i = 1; i <= M; i++) {
		if (time % arr[i] == 0)
			person++;
		if (person == N) {
			cout << i << '\n';
			break;
		}
	}
}

int main()
{
	input();
	solution();
	return 0;
}