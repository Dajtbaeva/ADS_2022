#include <bits/stdc++.h>
using namespace std;

#define ull unsigned long long

const int INF = 1e9;
vector<vector<pair<ull, ull> > > g;
vector<bool> used;
vector<ull> d;


int main() {
	ull n, m;
	cin >> n >> m;

    g.resize(n);
    used.resize(n);
    d.assign(n, INF);
	

	for (ull i = 0; i < m; i++) {
		ull u, v, w;
		cin >> u >> v >> w;
        u--; v--;
		g[u].push_back(make_pair(v, w));
        g[v].push_back(make_pair(u, w));
	}
	ull s, a, b, f;
    cin >> s >> a >> b >> f;
    s--; a--; b--; f--;
	d[s] = 0;

    vector <ull> p1;
    vector <ull> p2;



	priority_queue < pair<int,int> > q;
	q.push (make_pair (0, s));
	while (!q.empty()) {
		int v = q.top().second,  cur_d = -q.top().first;
		q.pop();
		if (cur_d > d[v])  continue;
 
		for (size_t j=0; j<g[v].size(); ++j) {
			int to = g[v][j].first,
				len = g[v][j].second;
			if (d[v] + len < d[to]) {
				d[to] = d[v] + len;
				q.push (make_pair (-d[to], to));
			}
		}
	}

    p1.push_back(d[a]);
    d.assign(n, INF);
    used.assign(n, false);
    while(!q.empty()){
        q.pop();
    }
    d[a] = 0;

    q.push (make_pair (0, a));
	while (!q.empty()) {
		int v = q.top().second,  cur_d = -q.top().first;
		q.pop();
		if (cur_d > d[v])  continue;
 
		for (size_t j=0; j<g[v].size(); ++j) {
			int to = g[v][j].first,
				len = g[v][j].second;
			if (d[v] + len < d[to]) {
				d[to] = d[v] + len;
				q.push (make_pair (-d[to], to));
			}
		}
	}
    p1.push_back(d[b]);
    d.assign(n, INF);
    used.assign(n, false);
    while(!q.empty()){
        q.pop();
    }


    d[b] = 0;
    q.push (make_pair (0, b));
	while (!q.empty()) {
		int v = q.top().second,  cur_d = -q.top().first;
		q.pop();
		if (cur_d > d[v])  continue;
 
		for (size_t j=0; j<g[v].size(); ++j) {
			int to = g[v][j].first,
				len = g[v][j].second;
			if (d[v] + len < d[to]) {
				d[to] = d[v] + len;
				q.push (make_pair (-d[to], to));
			}
		}
	}

    p1.push_back(d[f]);
    d.assign(n, INF);
    used.assign(n, false);
    while(!q.empty()){
        q.pop();
    }




    d[s] = 0;
    q.push (make_pair (0, s));
	while (!q.empty()) {
		int v = q.top().second,  cur_d = -q.top().first;
		q.pop();
		if (cur_d > d[v])  continue;
 
		for (size_t j=0; j<g[v].size(); ++j) {
			int to = g[v][j].first,
				len = g[v][j].second;
			if (d[v] + len < d[to]) {
				d[to] = d[v] + len;
				q.push (make_pair (-d[to], to));
			}
		}
	}

   

    p2.push_back(d[b]);
    d.assign(n, INF);
    used.assign(n, false);
    while(!q.empty()){
        q.pop();
    }

    d[b] = 0;

    q.push (make_pair (0, b));
	while (!q.empty()) {
		int v = q.top().second,  cur_d = -q.top().first;
		q.pop();
		if (cur_d > d[v])  continue;
 
		for (size_t j=0; j<g[v].size(); ++j) {
			int to = g[v][j].first,
				len = g[v][j].second;
			if (d[v] + len < d[to]) {
				d[to] = d[v] + len;
				q.push (make_pair (-d[to], to));
			}
		}
	}

    p2.push_back(d[a]);
    d.assign(n, INF);
    used.assign(n, false);
    while(!q.empty()){
        q.pop();
    }
    d[a] = 0;
    q.push (make_pair (0, a));
	while (!q.empty()) {
		int v = q.top().second,  cur_d = -q.top().first;
		q.pop();
		if (cur_d > d[v])  continue;
 
		for (size_t j=0; j<g[v].size(); ++j) {
			int to = g[v][j].first,
				len = g[v][j].second;
			if (d[v] + len < d[to]) {
				d[to] = d[v] + len;
				q.push (make_pair (-d[to], to));
			}
		}
	}

    p2.push_back(d[f]);
    d.assign(n, INF);
    used.assign(n, false);
    while(!q.empty()){
        q.pop();
    }

    ull sumi1 = 0, sumi2 = 0;
    for(ull i = 0; i < p1.size(); i++){
        if(p1[i] != INF){
            sumi1 += p1[i];
        }
        else{
            sumi1 = -1;
            break;
        }
        
    }

    for( ull i = 0; i < p2.size(); i++){
        if(p2[i] != INF){
            sumi2 += p2[i];
        }
        else{
            sumi2 = -1;
            break;
        }
        
    }
    
    if(sumi1 == -1 && sumi2 == -1){
        cout << -1;
    }
    else{
        cout << min(sumi1, sumi2);
    }

} 