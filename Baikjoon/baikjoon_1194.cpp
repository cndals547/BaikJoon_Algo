#include<iostream>
#include<queue>
#include<string>
#include<vector>
#include<cmath>

using namespace std;

int N, M;
char map[50][50];
bool Visit[50][50][1 << 6];

pair<int, int> Start;
vector<pair<int, int>> End;

int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };

void Input()
{
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		string Inp; cin >> Inp;
		for (int j = 0; j < M; j++)
		{
			map[i][j] = Inp[j];
			if (map[i][j] == '0')
			{
				Start.first = i;
				Start.second = j;
				map[i][j] = '.';
			}
			else if (map[i][j] == '1')
			{
				End.push_back(make_pair(i, j));
			}
		}
	}
}

bool key_check(int Cur_Key, char Door)
{
	int value = Cur_Key & (1 << (int(Door) - 'A'));
	if (value != 0) 
		return true;
	return false;
}

int BFS(int a, int b)
{
	queue<pair<pair<int, int>, pair<int, int>>> Q;
	Q.push(make_pair(make_pair(a, b), make_pair(0, 0)));
	Visit[a][b][0] = true;

	while (Q.empty() == 0)
	{
		int x = Q.front().first.first;
		int y = Q.front().first.second;
		int Cnt = Q.front().second.first;
		int Key = Q.front().second.second;
		Q.pop();

		if (map[x][y] == '1') return Cnt;

		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx >= 0 && ny >= 0 && nx < N && ny< M)
			{
				if (Visit[nx][ny][Key] == false)
				{
					if (map[nx][ny] == '.' || map[nx][ny] == '1')
					{
						Visit[nx][ny][Key] = true;
						Q.push(make_pair(make_pair(nx, ny), make_pair(Cnt + 1, Key)));
					}
					else if ('a' <= map[nx][ny] && map[nx][ny] <= 'f')
					{
						int Tmp_Key = Key | (1 << (int(map[nx][ny] - 'a')));
						Visit[nx][ny][Tmp_Key] = true;
						Q.push(make_pair(make_pair(nx, ny), make_pair(Cnt + 1, Tmp_Key)));
					}
					else if ('A' <= map[nx][ny] && map[nx][ny] <= 'F')
					{
						if (key_check(Key, map[nx][ny]) == true)
						{
							Visit[nx][ny][Key] = true;
							Q.push(make_pair(make_pair(nx, ny), make_pair(Cnt + 1, Key)));
						}
					}
				}
			}
		}
	}
	return -1;
}

int main(void)
{
	Input();
	cout << BFS(Start.first, Start.second) << endl;
	return 0;
}
