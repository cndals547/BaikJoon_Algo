#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#define INF 987654321

using namespace std;

vector<pair<int, int>> V[201];
int dist[201];
int trace[201];
int n, m;

void initialize()
{
	for (int i = 1; i <= n; i++)
	{
		dist[i] = INF;
	}
}

void input()
{
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int from, to, val;
		cin >> from >> to >> val;
		V[from].push_back({ to, val });
		V[to].push_back({ from, val });
	}
}

void Dijkstra(int start)
{
	initialize();
	priority_queue<pair<int, int>> pq;
	pq.push({ 0, start });
	dist[start] = 0;
	while (!pq.empty())
	{
		int cost = -pq.top().first;
		int cur = pq.top().second;
		pq.pop();
		for (int i = 0; i < V[cur].size(); i++)
		{
			int next = V[cur][i].first;
			int next_cost = V[cur][i].second;
			if (dist[next] > cost + next_cost)
			{
				trace[next] = cur;
				dist[next] = cost + next_cost;
				pq.push({ -dist[next], next });
			}
		}
	}
	for (int i = 1; i <= n; i++)
	{
		if (i == start)
			cout << "- ";
		else if (trace[i] == start)
			cout << i << " ";
		else
		{
			int index = i;
			while (1)
			{
				if (trace[index] == start)
				{
					cout << index << " ";
					break;
				}
				else
					index = trace[index];
			}
		}
	}
	cout << endl;
}

int main()
{
	input();
	for (int i = 1; i <= n; i++)
	{
		Dijkstra(i);
	}
	return 0;
}