// https://acmp.ru/asp/do/index.asp?main=task&id_course=2&id_section=21&id_topic=48&id_problem=626
// от каждой вершины сколько эджей есть, значит сколько соседей у каждой ноды
#include <iostream>
#include <vector>
using namespace std;
vector<vector<int> > g;

int main() {
	int m, n;
	cin >> m >> n;
	g.resize(m);
	for (int i = 0; i < n; i++) {
		int u, v;
		cin >> u >> v;
		u--;
		v--;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	for (int i = 0; i < m; i++) {
		cout << g[i].size() << " ";
	}

}