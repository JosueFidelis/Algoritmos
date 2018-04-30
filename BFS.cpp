#include <iostream>
#include <list>

using namespace std;


/*struct Graph {
    int V;
    list<int> *adj;
    Graph (int vertice) {
        this->V = vertice;
        this->adj = new list<int>[vertice];
    }
} typedef Graph;*/

void add_graph (int V, int w, list<int> *graph) {
    graph[V].push_back(w);
    //graph[w].push_back(V);
}

void BFS (int S, list<int> *graph, int V) {
    bool visited [V];
    for (int i = 0; i < V; i ++) {
        visited[i] = false;
    }
    list<int> queue;
    queue.push_back(S);
    visited[S] = true;
    list<int>::iterator i;
    while (!queue.empty()) {
        S = queue.front();
        cout << S << endl;
        queue.pop_front();
        for (i = graph[S].begin(); i != graph[S].end(); i ++) {
            if (!visited[*i]) {
                queue.push_back(*i);
                visited[*i] = true;
            }
        }

    }
} 

int main () {
    //Graph *graph = new Graph(4);
    list<int> graph[4];
    add_graph(0, 1, graph);
    add_graph(0, 2, graph);
    add_graph(1, 2, graph);
    add_graph(2, 0, graph);
    add_graph(2, 3, graph);
    add_graph(3, 3, graph);
    BFS(2, graph, 4);
    return 0;
}
