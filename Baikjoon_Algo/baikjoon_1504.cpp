#include<iostream>
#include<queue>
#include<vector>
#define INF 987654321

using namespace std;

int N, E, v1, v2;
vector<pair<int, int>> V[801];
int dist[801];
int answer;

void input()
{
	cin >> N >> E;
	for (int i = 0; i < E; i++)
	{
		int from, to, val;
		cin >> from >> to >> val;
		V[from].push_back({ to, val });
		V[to].push_back({ from, val });
	}
	cin >> v1 >> v2;
	for (int i = 1; i <= N; i++)
	{
		dist[i] = INF;
	}
}

void Dijkstra(int start)
{
	priority_queue<pair<int, int>> pq;
	dist[start] = 0;
	pq.push({ 0, start });
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
				dist[next] = cost + next_cost;
				pq.push({ -dist[next], next });
			}
		}
	}
}

void solution()
{
	input();
	bool v1_flag, v2_flag;
	v1_flag = v2_flag = true;
	Dijkstra(1);
	int v1_route = dist[v1];
	int v2_route = dist[v2];
	if (v1_route == INF)
		v1_flag = false;
	if (v2_route == INF)
		v2_flag = false;
	for (int i = 1; i <= N; i++)
	{
		dist[i] = INF;
	}
	Dijkstra(v1);
	if (v1_flag == true)
		v1_route += dist[v2];
	if (v2_flag == true)
		v2_route += dist[v2];

	for (int i = 1; i <= N; i++)
	{
		dist[i] = INF;
	}
	Dijkstra(v2);
	if (v1_flag == true)
		v1_route += dist[N];

	for (int i = 1; i <= N; i++)
	{
		dist[i] = INF;
	}
	Dijkstra(v1);
	if (v2_flag == true)
		v2_route += dist[N];
	if (v1_flag == false && v2_flag == false)
		answer = -1;
	else
		answer = min(v1_route, v2_route);
	if (answer == INF)
		answer = -1;
	cout << answer << endl;
}

int main()
{
	solution();
	return 0;
}
