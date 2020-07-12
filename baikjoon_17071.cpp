#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

int N, K;
bool visited[2][500001] = { false };

void input()
{
	cin >> N >> K;
}

int main()
{
	input();
	if (N == K)
	{
		cout << 0 << endl;
		return 0;
	}
	queue<int> q;
	q.push(N);
	visited[0][N] = true;
	int ans = 1;
	while (int s = q.size()) 
	{
		K += ans;
		if (K > 500000)
		{
			ans = -1;
			break;
		}
		while (s--) 
		{
			int now = q.front();
			q.pop();
			for (int i = 0; i<3; i++) 
			{
				int next = now;
				if (i == 0) next -= 1;
				else if (i == 1) next += 1;
				else next *= 2;
				if (0 <= next && next <= 500000 && !visited[ans % 2][next]) 
				{
					visited[ans % 2][next] = true; 
					q.push(next);
				}
			}
		}
		if (visited[ans % 2][K]) 
		{
			cout << ans << endl;
			return 0;
		}
		ans += 1;
	}
	cout << ans << endl;
	return 0;
}