
#include<iostream>
#include<string>
#include<vector>
#include<queue>
using namespace std;

int N, M;
int map[1000][1000];
int dx[] = { 0, -1, -1, -1, 0, 1, 1, 1 }; //왼, 왼위, 위, 오위, 오, 오아래, 아래, 왼아래, 
int dy[] = { -1, -1, 0, 1, 1, 1, 0, -1 };
int answer = 0;
queue<pair<int, int>> q;

void input()
{
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			char c;
			cin >> c;
			if (c == '.') 
			{
				q.push({ i,j });
				map[i][j] = 0;
			}
			else
				map[i][j] = c - '0';
		}
	}
}

void bfs()
{
	while (1)
	{
		int len = q.size();
		for (int i = 0; i < len; i++) 
		{
			int x = q.front().first;
			int y = q.front().second;
			q.pop();
			for (int j = 0; j < 8; j++) 
			{
				int nx = x + dx[j];
				int ny = y + dy[j];
				if (nx >= 0 && ny >= 0 && nx < N && ny < M && map[nx][ny]>0)
				{
					map[nx][ny] -= 1;
					if (map[nx][ny] == 0)
					{
						q.push({ nx, ny });
					}
				}
			}
		}
		if (q.empty()) 
			break;
		answer++;
	}
	cout << answer << endl;
}

int main()
{
	input();
	bfs();
}