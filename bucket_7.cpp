#include<bits/stdc++.h>
using namespace std ;
struct Edge {
    int source, destination, weight;

};

class Graph{
    int V;
    vector<Edge> edges;

    public:
    Graph(int V) : V(V){}

    void addedge(int source, int destination, int weight ){
        edges.push_back( source, destination, weight);
    }

    int find (vector<int>& parent, int i){
        if(parent[i] == -1){
            return i;
            return find(parent ,parent[i] );
        }
    }

        void union(vector<int>& parent, int x, int y){
            parent[x] = y;

        }

        void kruskal(){
            sort(edges.begin(),edges.end(),[](const Edge& a, const Edge& b){
                return a.weight<b.weight;
            });
            vector<int> parent(V, -1);
        vector<Edge> result;

        int i = 0, e = 0;
        while (e < V - 1 && i < edges.size()) {
            Edge next_edge = edges[i++];
            int x = find(parent, next_edge.src);
            int y = find(parent, next_edge.dest);
            if (x != y) {
                result.push_back(next_edge);
                Union(parent, x, y);
                e++;
            }
        }
        cout << "Edges in the minimum spanning tree:" << endl;
        for (const auto& edge : result) {
            cout << edge.src << " - " << edge.dest << " : " << edge.weight << endl;
    }
}
    
};

int main(){
    Graph f(4);

    f.addEdge(0, 1, 10);
    f.addEdge(0, 2, 6);
    f.addEdge(0, 3, 5);
    f.addEdge(1, 3, 15);
    f.addEdge(2, 3, 4);
    f.kruskal();
    return 0;
}