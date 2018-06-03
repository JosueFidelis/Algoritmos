#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>
using namespace std;

int id[4], sz[4];

int find (int p, int id[]) {
    if (id[p] == p) {
        return p;
    }
    id[p] = find(id[p], id);
    return id[p];
}

void Union (int p, int q, int id[], int sz[]) {
    p = find(p, id);
    q = find(q, id);
    if (p == q) {
        return;
    } else {
        if (sz[p] >= sz [q]) {
            id[q] = p;
            sz[p] += sz[q];
        } else {
            id[p] = q;
            sz[q] += sz[p];
        }
    }
}

void inserir(vector<pair<int, pair<int,int> > > &graph, int d, int v, int v2) {
    graph.push_back(make_pair(d, make_pair(v, v2)));
}

void kruskal (vector<pair<int, pair<int,int> > > &graphList, int id[], int sz[], vector<pair<int,int> > graph[]) { 
    pair<int,int> u;
    for(int i = 0; i < graphList.size(); i ++) {
        if (find(graphList[i].second.first, id) != find(graphList[i].second.second, id)) {
            u.first = graphList[i].first;
            u.second = graphList[i].second.second;
            graph[graphList[i].second.first].push_back(u);
            //graph[graphList[i].second.second].push_back(graphList[i].second.first);
            Union(graphList[i].second.first, graphList[i].second.second, id, sz);
        }
    }
}

int main() {
    int edge, vertex, v1, v2, d, total, total2;
    while(cin >> vertex >> edge && (vertex || edge)) {
        total = 0;
        total2 = 0;
        vector <pair<int, pair<int, int> > > edgelist;
        vector <pair<int,int> > graph[vertex];
        int id[vertex];
        int sz[vertex];
        for(int i = 0; i < vertex; i ++) {
            id[i] = i;
            sz[i] = 1;
        }
        for (int i = 0; i < edge; i ++) {
            cin >> v1 >> v2 >> d;
            inserir(edgelist, d, v1, v2);
            total += d;
        }
        sort(edgelist.begin(), edgelist.end());
        kruskal(edgelist, id, sz, graph);
        for (int i = 0; i < vertex; i ++) {
            for(int j = 0; j < graph[i].size(); j ++) {
                total2 += graph[i][j].first;
            }
        }
        cout << total - total2 << endl;
    }
    return 0;
}
