#include<bits/stdc++.h>

using namespace std;

class Graph {
    int V;
    vector<int> *adj;
public:
    Graph(int V) {
        this->V = V;
        adj = new vector<int>[V];
    }
    void insertEdge(int u, int v);
    void BFS();
};

void Graph::insertEdge(int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void Graph::BFS() {
    int v;
    queue<int> q;
    bool visited[V];
    memset(visited, false, sizeof(visited));
    for(int i = 0; i < V; ++i) {
        if(!visited[i]) {
            q.push(i);
            visited[i] = true;
            while(!q.empty()) {
                v = q.front();
                cout << v << ' ';
                q.pop();
                for(int j = 0; j < adj[v].size(); ++j) {
                    if(!visited[adj[v][j]]) {
                        visited[adj[v][j]] = true;
                        q.push(adj[v][j]);
                    }
                }
            }
        }
    }    
}

int main() {
    int V, E, u, v;
    cin >> V >> E;
    Graph G(V);
    for(int i = 0; i < E;++i) {
        cin >> u >> v;
        G.insertEdge(u, v);
    }

    G.BFS();
    return 0;
}
