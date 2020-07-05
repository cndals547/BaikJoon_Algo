#include<iostream>
#include<algorithm>
#include<queue>
#include<string>
#include<vector>

using namespace std;

int N;
int visited[25][25];
int map[25][25][5];
int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };

int solution(vector<vector<int>> board) 
{
	int answer = 987654321;
	N = board.size();
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			for (int k = 0; k < 4; k++)
			{
				map[i][j][k] = 987654321;
			}
		}
	}

	for (int i = 0; i < 4; i++)
	{
		map[0][0][i] = 0;
	}

	queue < pair<pair<int, int>, int>> q;
	q.push({{0,0}, 0});
	while (!q.empty())
	{
		int x = q.front().first.second;
		int y = q.front().first.first;
		int dir = q.front().second;
		q.pop();
		visited[y][x] = true;
		for (int i = 0; i < 4; i++)
		{
			int next_x = x + dx[i];
			int next_y = y + dy[i];
			int next_dir = i;
			if (next_x < 0 || next_y < 0 || next_x > N-1 || next_y > N-1)
				continue;
			if (board[next_y][next_x] == 1)
				continue;
			if (dir == next_dir)
			{
				if (map[next_y][next_x][next_dir] > map[y][x][dir] + 100)
				{
					map[next_y][next_x][next_dir] = map[y][x][dir] + 100;
					q.push({ {next_y, next_x}, next_dir });
				}
			}
			else
			{
				if (map[next_y][next_x][next_dir] > map[y][x][dir] + 600)
				{
					map[next_y][next_x][next_dir] = map[y][x][dir] + 600;
					q.push({ { next_y, next_x }, next_dir });
				}
			}
		}
	}
	for (int i = 0; i < 4; i++)
	{
		answer = min(answer, map[N - 1][N - 1][i]);
	}
    answer -= 500;
	return answer;
}