#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#define INF 987654321

using namespace std;

int N, K;
queue<int> q;
int answer;
int visit[100001];

void solution()
{
	cin >> N >> K;
	for (int i = 0; i < 100001; i++)
	{
		visit[i] = INF;
	}
	q.push(N);
	visit[N] = 0;
	while (!q.empty())
	{
		int cur = q.front();
		q.pop();
		if (cur == K)
		{
			answer = visit[K];
			break;
		}
		if (cur + 1 < 100001 && visit[cur + 1] > visit[cur] + 1)
		{
			visit[cur + 1] = visit[cur] + 1;
			q.push(cur + 1);
		}
		if (cur - 1 >= 0 && visit[cur - 1] > visit[cur] + 1)
		{
			visit[cur - 1] = visit[cur] + 1;
			q.push(cur - 1);
		}
		if (cur * 2 < 100001 && visit[cur * 2] > visit[cur])
		{
			visit[cur * 2] = visit[cur];
			q.push(cur * 2);
		}
	}
	cout << answer << endl;
}

int main()
{
	solution();
	return 0;
}
