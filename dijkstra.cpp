#include <iostream>
#include <vector>
using namespace std;

struct node {
    int u,d;
    bool operator<(const node &rhs) const {
        return d > rhs.d; // For min-heap based on distance
    }
};
struct edge {
    int v,w;
};
vector<int> dijkstra(vector<vector<edge>> &adj, int n, int s) {   
    vector<int> d(n, INT_MAX);
    vector<int> pi(n, -1);
    d[s] = 0;
    priority_queue<node, vector<node>, greater<node>> pq;
    pq.push({s,0});

    while(!pq.empty()){
        node u = pq.top();
        pq.pop();
        int _u = u.u; //current vertex
        for (auto& e: adj[_u]){
            int v = e.v;
            int w = e.w;
            if (d[v]>d[_u]+w){
                d[v] = d[_u]+w;
                pi[v] = _u;
                pq.push({v,d[v]});
            }
        }
    }
    return d;
}
int main() {
    return 0;
}