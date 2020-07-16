#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<memory.h>

using namespace std;

int N, answer;
int order[10];
int game[51][10];
bool selected[10];

void input()
{
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j < 10; j++)
		{
			cin >> game[i][j];
		}
	}
}
void Play_game()
{
	int score = 0;
	int Start_player = 1;
	int base_state[4];
	for (int i = 1; i <= N; i++)
	{
		int out_count = 0;
		bool Next_ining = false;
		memset(base_state, 0, sizeof(base_state));

		while (1)
		{
			for (int j = Start_player; j < 10; j++)
			{
				int Player = game[i][order[j]];
				if (Player == 0)
					out_count++;
				else if (Player == 1)
				{
					for (int k = 3; k >= 1; k--)
					{
						if (base_state[k] == 1)
						{
							if (k == 3)
							{
								base_state[k] = 0;
								score++;
							}

							else
							{
								base_state[k + 1] = 1;
								base_state[k] = 0;
							}
						}
					}
					base_state[1] = 1;
				}
				else if (Player == 2)
				{
					for (int k = 3; k >= 1; k--)
					{
						if (base_state[k] == 1)
						{
							if (k == 3 || k == 2)
							{
								base_state[k] = 0;
								score++;
							}
							else
							{
								base_state[k + 2] = 1;
								base_state[k] = 0;
							}
						}
					}
					base_state[2] = 1;
				}
				else if (Player == 3)
				{
					for (int k = 3; k >= 1; k--)
					{
						if (base_state[k] == 1)
						{						
							base_state[k] = 0;
							score++;
						}
					}
					base_state[3] = 1;
				}
				else
				{
					for (int k = 1; k <= 3; k++)
					{
						if (base_state[k] == 1)
						{
							base_state[k] = 0;
							score++;
						}
					}
					score++;
				}
				if (out_count == 3)
				{
					Start_player = j+1;
					if (Start_player == 10)
						Start_player = 1;
					Next_ining = true;
					break;
				}
			}
			if (Next_ining == true)
				break;
			Start_player = 1;
		}
	}
	answer = max(answer, score);
}

void DFS(int count)
{
	if (count == 10)
	{
		Play_game();
		return;
	}
	for (int i = 1; i < 10; i++)
	{
		if (selected[i] == true)
			continue;
		selected[i] = true;
		order[i] = count;
		DFS(count + 1);
		selected[i] = false;
	}
}

void solution()
{
	selected[4] = true;
	order[4] = 1;
	DFS(2);
	cout << answer << endl;
}

int main()
{
	input();
	solution();
	return 0;
}