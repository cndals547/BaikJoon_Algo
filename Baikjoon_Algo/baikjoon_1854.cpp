#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#define INF 987654321

using namespace std;

int n, m, k;
vector<pair<int, int>> V[1001];
vector<int> dist[1001];
priority_queue<int> heap[1001];

void input()
{
	cin >> n >> m >> k;
	for (int i = 0; i < m; i++)
	{
		int from, to, val;
		cin >> from >> to >> val;
		V[from].push_back({ to, val });
	}
}

void Dijkstra(int start)
{
	priority_queue<pair<int, int>> pq;
	pq.push({ 0, start });
	heap[1].push(0);
	while (!pq.empty())
	{
		int cost = -pq.top().first;
		int cur = pq.top().second;
		pq.pop();
		for (int i = 0; i < V[cur].size(); i++)
		{
			int next = V[cur][i].first;
			int next_cost = V[cur][i].second;
			if (heap[next].size() < k)
			{
				heap[next].push(next_cost + cost);
				pq.push({ -(next_cost + cost), next });
			}
			else if (heap[next].top() > next_cost + cost)
			{
				heap[next].pop();
				heap[next].push(next_cost + cost);
				pq.push({ -(next_cost + cost), next });
			}
		}
	}
}

int main()
{
	input();
	Dijkstra(1);
	for (int i = 1; i <= n; i++)
	{
		if (heap[i].size() != k)
			cout << -1 << endl;
		else
			cout << heap[i].top() << endl;
	}
	return 0;
}