#include<iostream>
#include<algorithm>
#include<vector>
#include<string>

using namespace std;

int N;
int dp[50001];
pair<int, int> coin[101];
int sum = 0;

void input()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> coin[i].first >> coin[i].second;
		sum += coin[i].first * coin[i].second;
	}
}

void initialize()
{
	sum = 0;
	for (int i = 0; i <= 50000; i++)
	{
		dp[i] = 0;
	}
	dp[0] = 1;
}

int main()
{
	for (int test_case = 0; test_case < 3; test_case++)
	{
		initialize();
		input();
		if (sum % 2 == 1)
		{
			cout << 0 << endl;
			continue;
		}
		sort(coin, coin + N);
		for (int i = 1; i <= coin[0].second; i++) 
		{
			if (coin[0].first * i > sum / 2)
				break;
			dp[i*coin[0].first] = 1;
		}
		if (dp[sum / 2])
		{
			cout << 1 << endl;
			continue;
		}
		for (int i = 1; i < N; i++)
		{
			for (int j = sum / 2; j >= 0; j--)
			{
				if (!dp[j])
					continue;
				for (int k = 1; k <= coin[i].second; k++)
				{
					if (j + k * coin[i].first > sum / 2)
					{
						break;
					}
					dp[j + k * coin[i].first] = 1;
				}
				if (dp[sum / 2])
					break;
			}
			if (dp[sum / 2])
				break;
		}
		cout << dp[sum / 2] << endl;
	}
}