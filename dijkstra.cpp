#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#include <limits.h>

using namespace std;

typedef pair<int,int> ii;

void addEdge(int v, int w, int d, vector<pair<int,int> > vec[]) {
    vec[v].push_back(make_pair(d, w));
    vec[w].push_back(make_pair(d, v));
}

void dij(int s, vector<pair<int,int> > graph[], int v) {
    bool visited[v];
    int dist[v];
    priority_queue < pair<int,int>, vector<pair<int,int> >, greater<pair<int, int> > > q; //inicio um heap de pares, onde o primeiro elemento é prioritário na ordenação, logo será a distância
    for (int i = 0; i < v; i ++){
        visited[i] = false;
        dist[i] = - 1;
    }
    pair<int, int> u;
    u.first = 0;
    u.second = s;
    q.push(u);    //pego o vertice de origem e seto a distãncia dele para ele mesmo como 0 e coloco ele na heap, a heap obviamente o selecionará de primeira
    int vertice;
    while(!q.empty()) {
        u = q.top();            //aqui eu pego os vertices que entraram na heap, de tal forma que eu sempre priorizo o menor caminho, não a ordem de aparição
        vertice = u.second;     //logo ele sempre vai pegar a menor distância para um lugar, pois se entre os filhos de um vertice ja visto, tem um que cujo o caminho do avô para esse neto seja do que do seu avô para o irmão de seu pai, eu posso ter um caminho menor no neto para chegar a esse tio
        q.pop();                //aqui eu tiro o elemento selecionado
        if (dist[vertice] == -1) {
            dist[vertice] = u.first;
            for (int i = 0; i < graph[vertice].size(); i ++) { //graph[u.second][i]
                if (dist[graph[vertice][i].second] == - 1) {
                    q.push(make_pair(graph[vertice][i].first + dist[vertice], graph[vertice][i].second));
                }
            }
        }
    }
    cout << dist [2] << endl;
}

int main () {
    vector<pair<int,int> > vec[3];
    addEdge(1, 2, 3, vec);
    addEdge(0, 1, 1, vec);
    //addEdge(0, 2, 2, vec);
    dij(0, vec, 3);
    /*pair <int, int> u(20, 30);
    cout << u.first << endl;
    priority_queue <pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > q;*/
    //vector<pair<int,int> > vec[50];
    return 0;
}