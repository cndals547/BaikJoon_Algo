#include<iostream>
#include<vector>

#define endl "\n"
#define MAX 12
#define CHESS_MAX 10
using namespace std;

struct CHESS
{
	int x;
	int y;
	int dir;
};

int N, K, Answer;
int MAP[MAX][MAX];
vector<int> MAP_State[MAX][MAX];
CHESS Chess[CHESS_MAX];

int dx[] = { 0, 0, 0, -1, 1 };
int dy[] = { 0, 1, -1, 0, 0 };

void Input()
{
	cin >> N >> K;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> MAP[i][j];
		}
	}
	for (int i = 0; i < K; i++)
	{
		int x, y, d; cin >> x >> y >> d;
		x--; y--;
		Chess[i] = { x, y, d };
		MAP_State[x][y].push_back(i);
	}
}

int Find_Delete_Num(int x, int y, int Chess_Num)
{
	/* 해당 말을 옮긴 후, 기존 좌표에서 몇 번 삭제를 해야 하는지 찾는 함수. */
	int Cnt = 0;
	for (int i = MAP_State[x][y].size() - 1; i >= 0; i--)
	{
		if (MAP_State[x][y][i] == Chess_Num) break;
		Cnt++;
	}
	return Cnt + 1;
}

int Reverse_Dir(int Num)
{
	int Dir = Chess[Num].dir;
	if (Dir == 1) return 2;
	else if (Dir == 2) return 1;
	else if (Dir == 3) return 4;
	else if (Dir == 4) return 3;
}

void MoveChess(int x, int y, int nx, int ny, int Chess_Num, int Pos, int Ms)
{
	if (Ms == 0)
	{
		for (int i = Pos; i < MAP_State[x][y].size(); i++)
		{
			MAP_State[nx][ny].push_back(MAP_State[x][y][i]);
			int Idx = MAP_State[x][y][i];
			Chess[Idx].x = nx;
			Chess[Idx].y = ny;
		}
		int Delete_Num = Find_Delete_Num(x, y, Chess_Num);
		for (int i = 0; i < Delete_Num; i++) MAP_State[x][y].pop_back();
	}
	else if (Ms == 1)
	{
		for (int i = MAP_State[x][y].size() - 1; i >= Pos; i--)
		{
			MAP_State[nx][ny].push_back(MAP_State[x][y][i]);
			int Idx = MAP_State[x][y][i];
			Chess[Idx].x = nx;
			Chess[Idx].y = ny;
		}
		int Delete_Num = Find_Delete_Num(x, y, Chess_Num);
		for (int i = 0; i < Delete_Num; i++) MAP_State[x][y].pop_back();
	}
	else if (Ms == 2)
	{
		int Dir = Reverse_Dir(Chess_Num);
		Chess[Chess_Num].dir = Dir;
		int nnx = x + dx[Dir];
		int nny = y + dy[Dir];

		if (nnx >= 0 && nny >= 0 && nnx < N && nny < N)
		{
			if (MAP[nnx][nny] != 2) MoveChess(x, y, nnx, nny, Chess_Num, Pos, MAP[nnx][nny]);
		}
	}
}

int Find_Position(int x, int y, int Idx)
{
	/* 해당 말이 몇 번째에 위치하고 있는지 찾아서 return 하는 함수. */
	for (int i = 0; i < MAP_State[x][y].size(); i++)
	{
		if (MAP_State[x][y][i] == Idx) return i;
	}
}

bool Check_State()
{
	for (int i = 0; i < K; i++)
	{
		int x = Chess[i].x;
		int y = Chess[i].y;
		if (MAP_State[x][y].size() >= 4) return true;
	}
	return false;
}

void Solution()
{
	bool Flag = false;
	int Time = 0;
	while (1)
	{
		if (Time > 1000) break;

		for (int i = 0; i < K; i++)
		{
			int x = Chess[i].x;
			int y = Chess[i].y;
			int dir = Chess[i].dir;

			int nx = x + dx[dir];
			int ny = y + dy[dir];

			int Pos = Find_Position(x, y, i);
			if (nx >= 0 && ny >= 0 && nx < N && ny < N) MoveChess(x, y, nx, ny, i, Pos, MAP[nx][ny]);
			else MoveChess(x, y, nx, ny, i, Pos, 2);

			if (Check_State() == true)
			{
				Flag = true;
				break;
			}
		}
		if (Flag == true) break;
		Time++;
	}

	if (Flag == true) cout << Time + 1 << endl;
	else cout << -1 << endl;
}

void Solve()
{
	Input();
	Solution();
}

int main(void)
{
	Solve();
	return 0;
}