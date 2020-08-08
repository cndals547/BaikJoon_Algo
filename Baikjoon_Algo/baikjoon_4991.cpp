#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<queue>

using namespace std;

int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
int visited[21][21][1 << 11];
int map[21][21];
int n, m;

void initialize()
{
	memset(map, 0, sizeof(map));
	memset(visited, 0, sizeof(visited));
}

int main()
{
	while (1)
	{
		queue<pair<int, pair<int, int>>> q;
		initialize();
		cin >> m >> n;
		if (n == 0 && m == 0)
			break;
		int count = 0;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				char ch;
				cin >> ch;
				if (ch == 'o')
					q.push({ 0,{i,j} });
				else if (ch == '*')
				{
					count++;
					map[i][j] = count;
				}
				else if (ch == 'x')
					map[i][j] = -1;
			}
		}
		int all = (1 << count) - 1;
		int check = 0;
		while (q.size())
		{
			int x = q.front().second.first;
			int y = q.front().second.second;
			int ch = q.front().first;
			q.pop();
			if (ch == all)
			{
				cout << visited[x][y][ch] << endl;
				check = 1;
				break;
			}
			for (int i = 0; i < 4; i++)
			{
				int next_x = x + dx[i];
				int next_y = y + dy[i];
				if (next_x >= 0 && next_x < n && next_y >= 0 && next_y < m && map[next_x][next_y] != -1)
				{
					if (map[next_x][next_y] > 0)
					{
						if (!visited[next_x][next_y][ch | (1 << (map[next_x][next_y] - 1))])
						{
							q.push({ ch | (1 << (map[next_x][next_y] - 1)), {next_x, next_y} });
							visited[next_x][next_y][ch | (1 << (map[next_x][next_y] - 1))] = visited[x][y][ch] + 1;
						}
					}
					if (map[next_x][next_y] == 0)
					{
						if (!visited[next_x][next_y][ch])
						{
							q.push({ ch, {next_x, next_y} });
							visited[next_x][next_y][ch] = visited[x][y][ch] + 1;
						}
					}
				}
			}
		}
		if (check == 0)
		{
			cout << -1 << endl;
		}
	}
}