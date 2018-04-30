#include <iostream>
#include <list>

using namespace std;

void add_graph(int s, int w, list<int> *graph) {
    graph[s].push_back(w);
    //graph[w].push_back(s);
}

void DFSutil (int v, bool visited[], list<int> *graph){
    cout << v << endl;
    visited[v] = true;
    list<int>::iterator i;
    for (i = graph[v].begin(); i != graph[v].end(); i ++) {
        if (!visited[*i]) {
            DFSutil(*i, visited, graph);
        }
    }
}

void DFS (int v, list<int> *graph, int s) {
    bool visited[s];
    for (int i = 0; i < s; i ++) {
        visited[i] = false;
    }
    DFSutil(v, visited, graph);
    for (int i = 0; i < s; i ++) {
        if(!visited[i]) {
            DFSutil(i, visited, graph);   
        }
    }

}

int main () {
    list<int> graph[4];
    add_graph(0, 1, graph);
    add_graph(0, 2, graph);
    add_graph(1, 2, graph);
    add_graph(2, 0, graph);
    add_graph(2, 3, graph);
    add_graph(3, 3, graph);
 
    cout << "Following is Depth First Traversal"
            " (starting from vertex 2) \n";
    DFS(2, graph, 4);
    return 0;
}