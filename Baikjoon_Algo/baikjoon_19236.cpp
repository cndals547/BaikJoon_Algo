#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<memory.h>

using namespace std;

struct FISH
{
	int x;
	int y;
	int dir;
	bool live;
};

int map[4][4];
FISH Fish[17];
int answer;

int dx[] = { 0, -1, -1, 0, 1, 1, 1, 0, -1 };
int dy[] = { 0, 0, -1, -1, -1, 0, 1, 1, 1 };

void input()
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			int a, b;
			cin >> a >> b;
			map[i][j] = a;
			Fish[a] = { i, j, b, true };
		}
	}
}

void swap_fish(int index, int index2)
{
	FISH temp = Fish[index];
	Fish[index].x = Fish[index2].x;
	Fish[index].y = Fish[index2].y;
	Fish[index2].x = temp.x;
	Fish[index2].y = temp.y;
}

void move_fish()
{
	for (int i = 1; i <= 16; i++)
	{
		if (Fish[i].live == true)
		{
			int x = Fish[i].x;
			int y = Fish[i].y;
			int dir = Fish[i].dir;

			int nx = x + dx[dir];
			int ny = y + dy[dir];
			bool flag = false;
			if (nx >= 0 && ny >= 0 && nx < 4 && ny < 4)
			{
				if (map[nx][ny] == 0)
				{
					flag = true;
					map[nx][ny] = i;
					map[x][y] = 0;
					Fish[i].x = nx;
					Fish[i].y = ny;
				}
				else if (map[nx][ny] != -1)
				{
					flag = true;
					swap_fish(i, map[nx][ny]);
					swap(map[x][y], map[nx][ny]);
				}
			}
			if (flag == false)
			{
				int next_dir = dir + 1;
				if (next_dir == 9)
					next_dir = 1;
				int nx = x + dx[next_dir];
				int ny = y + dy[next_dir];
				while (dir != next_dir)
				{
					if (nx >= 0 && ny >= 0 && nx < 4 && ny < 4)
					{
						if (map[nx][ny] == 0)
						{
							map[nx][ny] = i;
							map[x][y] = 0;
							Fish[i].x = nx;
							Fish[i].y = ny;
							Fish[i].dir = next_dir;
							break;
						}
						else if (map[nx][ny] != -1)
						{
							swap_fish(i, map[nx][ny]);
							swap(map[x][y], map[nx][ny]);
							Fish[i].dir = next_dir;
							break;
						}
					}
					next_dir++;
					if (next_dir == 9)
						next_dir = 1;
					nx = x + dx[next_dir];
					ny = y + dy[next_dir];
				}
			}
		}
	}
}

void Make_state(int x, int y, int nx, int ny, int Fish_num, bool flag)
{
	if (flag == true)
	{
		map[x][y] = 0;
		map[nx][ny] = -1;
		Fish[Fish_num].live = false;
	}
	else
	{
		map[x][y] = -1;
		map[nx][ny] = Fish_num;
		Fish[Fish_num].live = true;
	}
}

void copy_state(int A[][4], int B[][4], FISH C[], FISH D[])
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			A[i][j] = B[i][j];
		}
	}
	for (int i = 1; i <= 16; i++)
	{
		C[i] = D[i];
	}
}

void DFS(int x, int y, int dir, int sum)
{
	answer = max(answer, sum);
	int c_map[4][4];
	FISH c_fish[17];
	copy_state(c_map, map, c_fish, Fish);
	move_fish();
	for (int i = 1; i <= 3; i++)
	{
		int nx = x + dx[dir] * i;
		int ny = y + dy[dir] * i;
		if (nx >= 0 && ny >= 0 && nx < 4 && ny < 4)
		{
			if (map[nx][ny] == 0)
				continue;
			int fish_num = map[nx][ny];
			int next_dir = Fish[fish_num].dir;
			Make_state(x, y, nx, ny, fish_num, true);
			DFS(nx, ny, next_dir, sum + fish_num);
			Make_state(x, y, nx, ny, fish_num, false);
		}
		else
			break;
	}
	copy_state(map, c_map, Fish, c_fish);
}

void solution()
{
	int F_num = map[0][0];
	int dir = Fish[F_num].dir;
	Fish[F_num].live = false;
	map[0][0] = -1;
	DFS(0, 0, dir, F_num);
	cout << answer << endl;
}

int main()
{
	input();
	solution();
	return 0;
}
