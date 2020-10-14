#include<bits/stdc++.h>
using namespace std;
const int INF = 1e9 + 7;
vector<pair<int, int> > graph[205];
vector<int> p, d;
int S, D, T;
int n, m;
void dijkstra()
{
	d.assign(n, 0);
	p.assign(n, 0);

	d[S] = INF;
	p[S] = -1;
	using pii = pair<int, int>;
	priority_queue<pii> PQ;

	PQ.push({INF, S});

	while (!PQ.empty())
	{
		int v = PQ.top().second;
		int d_v = PQ.top().first;
		PQ.pop();
		if (d_v != d[v]) continue;

		for (auto x : graph[v])
		{
			int to = x.first;
			int len = x.second;
			int mn = min(len, d[v]);
			if (mn > d[to]) {
				d[to] = mn;
				p[to] = v;
				PQ.push({d[to], to});
			}
			// cout << to << " "<<len << " "<<d[to]<<endl;
			//d[to] = min(d[to], max(len, d[v]));
		}
	}
}

https://www.hackerearth.com/practice/algorithms/graphs/shortest-path-algorithms/practice-problems/algorithm/smart-travel-agent/description/

int main()
{
	///*
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	freopen("error.txt", "w", stderr);
#endif
	//*/
	scanf("%d %d", &n, &m);
	d.clear();
	for (int i = 0; i < n; i++)graph[i].clear();
	for (int i = 0; i < m; i++)
	{
		int x, y, z;
		//  cin >> x >> y >> z;
		scanf("%d %d %d", &x, &y, &z);
		--x; --y;
		graph[x].push_back({y, z});
		graph[y].push_back({x, z});
	}
	//cout << "------------------------\n";
	//print();
	scanf("%d %d %d", &S, &D, &T);
	--S; --D;

	for (int i = 0; i < n; i++)sort(graph[i].begin(), graph[i].end());
	dijkstra();
	d[D]--;
	int x = d[D];
	stack<int>path;
	while (p[D] != -1) {
		//cerr << D + 1 << " ";
		path.push(D + 1);
		D = p[D];
	}
	printf("%d", S + 1);
	while (!path.empty()) {
		printf(" %d", path.top());
		path.pop();
	}
	printf("\n%d\n", (T + x - 1) / (x));
	return 0;
}

