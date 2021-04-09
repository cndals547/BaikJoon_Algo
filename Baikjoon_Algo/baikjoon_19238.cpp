#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<memory.h>
#define MAX 25

using namespace std;

struct Customer
{
	int start_x;
	int start_y;
	int end_x;
	int end_y;
};

struct INFO
{
	int x;
	int y;
	int Dist;
	int idx;
};

int map[MAX][MAX];
bool visit[MAX][MAX];
int N, M, K;
Customer customer[MAX * MAX];
int tx, ty;

int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };

void input()
{
	cin >> N >> M >> K;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> map[i][j];
			if (map[i][j] == 1)
				map[i][j] = -1;
		}
	}
	cin >> tx >> ty;
	tx--; ty--;
	for (int i = 1; i <= M; i++)
	{
		int sx, sy, ex, ey;
		cin >> sx >> sy >> ex >> ey;
		sx--; sy--; ex--; ey--;
		customer[i] = { sx, sy, ex, ey };
		map[sx][sy] = i;
	}
}

bool comp(INFO A, INFO B)
{
	if (A.Dist <= B.Dist)
	{
		if (A.Dist == B.Dist)
		{
			if (A.x <= B.x)
			{
				if (A.x == B.x)
				{
					if (A.y < B.y)
					{
						return true;
					}
					return false;
				}
				return true;
			}
			return false;
		}
		return true;
	}
	return false;
}

bool BFS(int sx, int sy, int ex, int ey, int idx)
{
	memset(visit, false, sizeof(visit));
	queue<pair<pair<int, int>, pair<int, int>>> q;
	q.push({ {sx, sy}, {0, K} });
	visit[sx][sy] = true;
	while (!q.empty())
	{
		int x = q.front().first.first;
		int y = q.front().first.second;
		int dist = q.front().second.first;
		int fuel = q.front().second.second;
		q.pop();
		if (x == ex && y == ey)
		{
			K -= dist;
			K += (dist * 2);
			tx = x;
			ty = y;
			return true;
		}
		if (fuel == 0)
			return false;
		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >= 0 && ny >= 0 && nx < N && ny < N)
			{
				if (map[nx][ny] != -1 && visit[nx][ny] == false)
				{
					visit[nx][ny] = true;
					q.push({ {nx, ny}, {dist + 1, fuel - 1} });
				}
			}
		}
	}
	return false;
}

int Find_Short()
{
	memset(visit, false, sizeof(visit));
	queue<pair<pair<int, int>, pair<int, int>>> q;
	q.push({ {tx, ty} , {0, K}});
	vector<INFO> V;
	visit[tx][ty] = true;
	while (!q.empty())
	{
		int x = q.front().first.first;
		int y = q.front().first.second;
		int distance = q.front().second.first;
		int fuel = q.front().second.second;
		q.pop();

		if (map[x][y] >= 1)
			V.push_back({x, y, distance, map[x][y]});
		if (fuel == 0)
			continue;
		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >= 0 && ny >= 0 && nx < N && ny < N)
			{
				if (map[nx][ny] != -1 && visit[nx][ny] == false)
				{
					visit[nx][ny] = true;
					q.push({ {nx, ny}, {distance + 1, fuel - 1}});
				}
			}
		}
	}
	if (V.size() == 0)
		return -1;
	sort(V.begin(), V.end(), comp);
	map[V[0].x][V[0].y] = 0;
	K -= V[0].Dist;
	return V[0].idx;
}

void solution()
{
	for (int i = 0; i < M; i++)
	{
		int num = Find_Short();
		if (num == -1)
		{
			cout << -1 << endl;
			return;
		}
		bool Can_Move = BFS(customer[num].start_x, customer[num].start_y, customer[num].end_x, customer[num].end_y, num);
		if (Can_Move == false)
		{
			cout << -1 << endl;
			return;
		}
	}
	cout << K << endl;
}

int main()
{
	input();
	solution();
	return 0;
}