#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>

using namespace std;

int n, m;
vector<pair<int, int>> V[1001];
vector<int> v_answer;
int dist[1001];
int route[1001];
int answer;
int s, e;

void input()
{
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int from, to, val;
		cin >> from >> to >> val;
		V[from].push_back({ to, val });
	}
	for (int i = 1; i <= n; i++)
	{
		dist[i] = 987654321;
	}
	cin >> s >> e;
}

void Dijkstra(int start)
{
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
				route[next] = cur;
				dist[next] = cost + next_cost;
				pq.push({ -dist[next], next });
			}
		}
	}
}

void solution()
{
	input();
	Dijkstra(s);
	cout << dist[e] << endl;
	while (e)
	{
		v_answer.push_back(e);
		e = route[e];
	}
	cout << v_answer.size() << endl;
	for (int i = v_answer.size() - 1; i >= 0; i--)
	{
		cout << v_answer[i] << ' ';
	}
	cout << endl;
}

int main()
{
	solution();
	return 0;
}
