#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
#define INF 987654321

using namespace std;

int n, m, r;
int items[101];
int dist[101];
vector<pair<int, int>> V[101];
int answer;

void input()
{
	cin >> n >> m >> r;
	for (int i = 1; i <= n; i++)
	{
		cin >> items[i];
	}
	for (int i = 1; i <= r; i++)
	{
		int from, to, val;
		cin >> from >> to >> val;
		V[from].push_back({ to, val });
		V[to].push_back({ from, val });
	}
}

int Dijkstra(int start)
{
	for (int i = 1; i <= n; i++)
	{
		dist[i] = INF;
	}
	int count = 0;
	priority_queue<pair<int, int>> q;
	q.push({ 0, start });
	dist[start] = 0;
	while (!q.empty())
	{
		int cost = q.top().first;
		int cur = q.top().second;
		q.pop();
		for (int i = 0; i < V[cur].size(); i++)
		{
			int next = V[cur][i].first;
			int next_cost = V[cur][i].second;
			if (dist[next] > dist[cur] + next_cost)
			{
				dist[next] = dist[cur] + next_cost;
				q.push({ -dist[next], next });
			}
		}
	}
	for (int i = 1; i <= n; i++)
	{
		if (dist[i] <= m)
			count += items[i];
	}
	return count;
}

int main()
{
	input();
	for (int i = 1; i <= n; i++)
	{
		if (Dijkstra(i) > answer)
			answer = Dijkstra(i);
	}
	cout << answer << endl;
	return 0;
}