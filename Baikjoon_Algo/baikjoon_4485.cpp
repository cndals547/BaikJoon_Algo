#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

int N;
int map[125][125];
int dist[125][125];
int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, 1, -1 };
int answer;
int cnt = 1;

void input()
{
	if (N == 0)
		return;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> map[i][j];
			dist[i][j] = 987654321;
		}
	}
}

void initialize()
{
	memset(map, sizeof(map), 0);
	answer = 0;
}

void solution()
{
	queue<pair<int, int>> q;
	q.push({ 0, 0 });
	dist[0][0] = map[0][0];
	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >= 0 && ny >= 0 && nx < N && ny < N)
			{
				if (dist[nx][ny] > dist[x][y] + map[nx][ny])
				{
					dist[nx][ny] = dist[x][y] + map[nx][ny];
					q.push({ nx, ny });
				}
			}
		}
	}
	answer = dist[N - 1][N - 1];
	cout << "Problem " << cnt << ": " << answer << endl;
}

int main()
{
	while (1)
	{
		cin >> N;
		if (N == 0)
			break;
		initialize();
		input();
		solution();
		cnt++;
	}
	return 0;
}
