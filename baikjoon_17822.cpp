#include<iostream>
#include<vector>
#include<algorithm>
#include<algorithm>
#include<deque>
#include<queue>
using namespace std;


void check_sum();

struct Turn_Circle_Info
{
	int x;
	int d;
	int k;
};

int map[51][51], c_map[51][51];
int N, M, T;
vector<Turn_Circle_Info> Turn_info;
int answer;

void copy_map()
{
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			c_map[i][j] = map[i][j];
		}
	}
}

void input()
{
	cin >> N >> M >> T;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			cin >> map[i][j];
		}
	}
	for (int i = 0; i < T; i++)
	{
		int x, d, k;
		cin >> x >> d >> k;
		Turn_info.push_back({ x, d, k });
	}
}

void circle()
{
	for (int t = 0; t < T; t++)
	{
		if (Turn_info[t].d == 0) // 시계
		{
			deque<int> dq;
			for (int i = 1; i <= N; i++)
			{
				if (i % Turn_info[t].x == 0)
				{
					for (int j = 1; j <= M; j++)
					{
						dq.push_back(map[i][j]);
					}
					for (int j = 0; j < Turn_info[t].k; j++)
					{
						int temp = dq.back();
						dq.pop_back();
						dq.push_front(temp);
					}
					for (int j = 0; j < M; j++)
					{
						map[i][j+1] = dq.front();
						dq.pop_front();
					}
				}
			}
		}
		else //반시계
		{
			deque<int> dq;
			for (int i = 1; i <= N; i++)
			{
				if (i % Turn_info[t].x == 0)
				{
					for (int j = 1; j <= M; j++)
					{
						dq.push_back(map[i][j]);
					}
					for (int j = 0; j < Turn_info[t].k; j++)
					{
						int temp = dq.front();
						dq.pop_front();
						dq.push_back(temp);
					}
					for (int j = 0; j < M; j++)
					{
						map[i][j + 1] = dq.front();
						dq.pop_front();
					}
				}
			}
		}
		copy_map();
		check_sum();
	}
}

void check_sum()
{
	int num = 0;
	int count = 0;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			count = 0;
			if (c_map[i][j] == 0)
				continue;
			if (i >= 1 && i < N)
			{
				if (c_map[i][j] == c_map[i + 1][j])
				{
					map[i + 1][j] = 0;
					count++;
					num++;
				}
				if (c_map[i][j] == c_map[i][j + 1])
				{
					map[i][j + 1] = 0;
					count++;
					num++;
				}
				if (c_map[i][j] == c_map[i][j - 1])
				{
					map[i][j - 1] = 0;
					count++;
					num++;
				}
				if (count > 0)
					map[i][j] = 0;
			}
			else if (i == N)
			{
				if (c_map[i][j] == c_map[i][j + 1])
				{
					map[i][j + 1] = 0;
					count++;
					num++;
				}
				if (c_map[i][j] == c_map[i][j - 1])
				{
					map[i][j - 1] = 0;
					count++;
					num++;
				}
				if (count > 0)
					map[i][j] = 0;
			}
			if (j == M)
			{
				if (i == N)
				{
					if (c_map[i][j] == c_map[i][1])
					{
						map[i][1] = 0;
						count++;
						num++;
					}
					if (c_map[i][j] == c_map[i][j-1])
					{
						map[i][j - 1] = 0;
						num++;
						count++;
					}
				}
				else
				{
					if (c_map[i][j] == c_map[i][j - 1])
					{
						map[i][j - 1] = 0;
						count++;
						num++;
					}
					if (c_map[i][j] == c_map[i][1])
					{
						map[i][1] = 0;
						count++;
						num++;
					}
					if (c_map[i][j] == c_map[i + 1][j])
					{
						map[i + 1][j] = 0;
						count++;
						num++;
					}
				}
				if (count > 0)
					map[i][j] = 0;
			}
		}
	}
	if (num == 0)
	{
		int num1 = 0;
		int sum = 0;
		double average = 0.0;
		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= M; j++)
			{
				if (map[i][j] != 0)
				{
					sum += map[i][j];
					num1++;
				}
			}
		}
		average = (double)sum / (double)num1;
		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= M; j++)
			{
				if (map[i][j] != 0)
				{
					if (map[i][j] > average)
						map[i][j] -= 1;
					else if(map[i][j] < average)
						map[i][j] += 1;
				}
			}
		}
	}
}

void solution()
{
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			answer += map[i][j];
		}
	}
	cout << answer << endl;
}



int main()
{
	input();
	circle();
	solution();
}