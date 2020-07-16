#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

struct sticker
{
	int row;
	int col;
};

int N, M, K;
int map[41][41];
int stickers[100][10][10];
bool avail;
vector<sticker> s;
int answer;

void input()
{
	cin >> N >> M >> K;
	for (int i = 0; i < K; i++)
	{
		int n, m;
		cin >> n >> m;
		s.push_back({ n, m });
		for (int j = 0; j < n; j++)
		{
			for (int k = 0; k < m; k++)
			{
				cin >> stickers[i][j][k];
			}
		}
	}
}

void rotate(int sticker_num)
{
	int temp[10][10];
	int r = s[sticker_num].row;
	int c = s[sticker_num].col;
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			temp[j][r - 1 - i] = stickers[sticker_num][i][j];
			stickers[sticker_num][i][j] = 0;
		}
	}
	for (int i = 0; i < c; i++)
	{
		for (int j = 0; j < r; j++)
		{
			stickers[sticker_num][i][j] = temp[i][j];
		}
	}
	s[sticker_num].row = c;
	s[sticker_num].col = r;
}

void check(int sticker_num)
{
	int sr = s[sticker_num].row;
	int sc = s[sticker_num].col;
	for (int i = 0; i <= N - sr; i++)
	{
		for (int j = 0; j <= M - sc; j++)
		{
			bool add = true;
			for (int k = 0; k < sr; k++)
			{
				for (int m = 0; m < sc; m++)
				{
					if (stickers[sticker_num][k][m] == 1 && map[i + k][j + m] != 0)
					{
						add = false;
						break;
					}
				}
				if (!add)
					break;
			}
			if (add)
			{
				avail = true;
				for (int k = 0; k < sr; k++)
				{
					for (int m = 0; m < sc; m++)
					{
						if (stickers[sticker_num][k][m] == 1)
							map[i + k][j + m] = 1;
					}
				}
				break;
			}
		}
		if (avail)
			break;
	}
}

void solution()
{
	input();
	for (int k = 0; k < K; k++)
	{
		avail = false;
		check(k);
		if (avail)
			continue;
		for (int i = 0; i < 3; i++)
		{
			rotate(k);
			check(k);
			if (avail)
				break;
		}
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (map[i][j] == 1)
				answer++;
		}
	}
	cout << answer << endl;
}

int main()
{
	solution();
	return 0;
}