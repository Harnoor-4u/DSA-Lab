
#include<iostream>
#include <string.h>
#include<bits/stdc++.h>
#include <algorithm>
#include<vector>
#include <cmath>
using namespace std;
/*
Write a program to implement the following graph algorithms:
1. Breadth First Search (BFS)
2. Depth First Search (DFS)
3. Minimum Spanning Tree (Kruskal and Prim)
4. Dijkstra's Shortest Path Algorithm
*/
unordered_map<int, list<pair<int,int>>> graph2(int n,int m,vector<vector<int>> &edges){
    unordered_map <int,list<pair<int,int>>> adj;
    for(int i=0;i<m;i++){
        int u=edges[i][0];
        int v=edges[i][1];
        int w=edges[i][2];
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    return adj;
}

vector<vector<int>> graph1(int n,int m,vector<vector<int>> &edges){
    vector<vector<int>> adj(n);   
    for(int i=0;i<m;i++){
        int u=edges[i][0];
        int v=edges[i][1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    return adj;
}

void printGraph1(const vector<vector<int>> &adj) {
    for(int i = 0; i < adj.size(); i++) {
        cout << i << ": ";
        for(int v : adj[i]) {
            cout << v << " ";
        }
        cout << endl;
    }
}

vector<int> BFS(int start,int n,int m,vector<vector<int>> &edges){
    vector<vector<int>> ans = graph1(n,m,edges);
    unordered_map<int,bool> visit;
    queue<int> q;
    vector<int> result;

    q.push(start);
    visit[start] = true;

    while(!q.empty()){
        int node = q.front();
        q.pop();
        result.push_back(node);

        for(int i : ans[node]){
            if(!visit[i]){
                visit[i] = true;
                q.push(i);
            }
        }
    }
    return result;
}

vector<int> DFS(int start,int n,int m,vector<vector<int>> &edges){
    vector<vector<int>> ans = graph1(n,m,edges);
    unordered_map<int,bool> visit;
    stack<int> s;
    vector<int> result;
    s.push(start);
    visit[start] = true;
    while(!s.empty()){
        int node = s.top();
        s.pop();
        result.push_back(node);
        for(int i : ans[node]){
            if(!visit[i]){
                visit[i] = true;
                s.push(i);
            }
        }
    }
    return result;
}

vector<int> dj_algo(vector<vector<int>> &edges,int vertices,int edge,int source){
    unordered_map <int, list<pair<int,int>>> adj;
    for(int i=0;i<edge;i++){
        int u=edges[i][0];
        int v=edges[i][1];
        int w=edges[i][2];
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    vector<int> dist(vertices, INT_MAX); 
    set<pair<int,int>> st;
    dist[source] = 0;
    st.insert({0, source});
    while(!st.empty()){
        auto top = *st.begin();
        st.erase(st.begin()); 
        int node = top.second;
        int distance = top.first;
        for (auto neighbour : adj[node]){
            int new_dist = distance + neighbour.second;
            if(new_dist < dist[neighbour.first]){
                auto x = st.find({dist[neighbour.first], neighbour.first});
                if(x != st.end()) st.erase(x);
                dist[neighbour.first] = new_dist;
                st.insert({new_dist, neighbour.first});
            }
        }
    }
    return dist;
}
vector<pair<int,int>> prims_algo(int root,int vertex,int edge,vector<vector<int>> &edges){
    unordered_map <int,list<pair<int,int>>> adj;
    for(int i=0;i<edge;i++){
        int u=edges[i][0];
        int v=edges[i][1];
        int w=edges[i][2];
        adj[u].push_back(make_pair(v,w));
        adj[v].push_back(make_pair(u,w));
    }
    set <pair<int,int>> key;            
    vector<bool> mst(vertex, false);
    vector<int> parent(vertex,-1);
    vector<int> minWeight(vertex, INT_MAX);
    minWeight[root] = 0;
    key.insert({0, root});
    vector<pair<int,int>> result;        
    while(!key.empty()){
        auto node = *(key.begin());      
        key.erase(key.begin());
        int u = node.second;
        mst[u] = true;
        if(parent[u] != -1){             
            result.push_back({parent[u], u});
        }
        for(auto nbr: adj[u]){
            int v = nbr.first;
            int w = nbr.second;
            if(!mst[v] && w < minWeight[v]){
                if(minWeight[v] != INT_MAX){
                    key.erase({minWeight[v], v});
                }
                minWeight[v] = w;
                parent[v] = u;
                key.insert({minWeight[v], v});
            }
        }
    }
    return result;
}
void print_prim(const vector<pair<int,int>> &mstEdges) {
    cout << "MST Edges:\n";
    for(auto &p : mstEdges) {
        cout << p.first << " -- " << p.second << "\n";
    }
}
void printGraph2(unordered_map<int, list<pair<int,int>>> &adj) {
    for (auto &node : adj) {
        cout << node.first << " -> ";
        for (auto &nbr : node.second) {
            cout << "(" << nbr.first << ", weight=" << nbr.second << ") ";
        }
        cout << endl;
    }
}
// DISJOINT SET
void makeset(vector<int> &parent,vector<int> &rank,int n){
    for(int i=0;i<n;i++){
        parent[i]=i;
        rank[i]=0;
    }
}
int find_parent(vector<int> &parent,int node){
    if(parent[node]==node){
        return parent[node];
    }
    return parent[node]=find_parent(parent,parent[node]);
}
void union_set(int u,int v,vector<int> &parent,vector<int> &rank){
    u=find_parent(parent,u);
    v=find_parent(parent,v);
    if(rank[u]<rank[v]){
        parent[u]=v;
    }
    else if(rank[v]<rank[u]){
        parent[v]=u;
    }
    else{
        parent[v]=u;
        rank[u]++;
    }
}
#include <algorithm>
bool cmp(const vector<int> &a,const vector<int> &b){
    return a[2]<b[2];
}
int kruskal_algo(vector<vector<int>> &edges,int vertex,int edge){
    sort(edges.begin(),edges.end(),cmp);
    vector<int> parent(vertex);
    vector<int> rank(vertex);
    makeset(parent,rank,vertex);
    int min_weight=0;
    for(int i=0;i<edge;i++){
        int u=find_parent(parent,edges[i][0]);
        int v=find_parent(parent,edges[i][1]);
        int w=edges[i][2];
        if(u!=v){
            min_weight+=w;
            union_set(u,v,parent,rank);
        }
    }
    return min_weight;
}


int main() {

    int vertices = 5;
    int edgesCount = 6;

    vector<vector<int>> edges = {
        {0, 1, 2},
        {0, 2, 4},
        {1, 2, 1},
        {1, 3, 7},
        {2, 4, 3},
        {3, 4, 1}
    };

    cout << "Graph for BFS / DFS:\n";
    auto adj1 = graph1(vertices, edgesCount, edges);
    printGraph1(adj1);

    cout << "\nBFS starting from 0: ";
    vector<int> bfsResult = BFS(0, vertices, edgesCount, edges);
    for (int x : bfsResult) cout << x << " ";

    cout << "\nDFS starting from 0: ";
    vector<int> dfsResult = DFS(0, vertices, edgesCount, edges);
    for (int x : dfsResult) cout << x << " ";

    cout << "\n\nDijkstra's shortest path from 0:\n";
    vector<int> dij = dj_algo(edges, vertices, edgesCount, 0);
    for (int i = 0; i < vertices; i++)
        cout << "Distance to " << i << " = " << dij[i] << endl;

    cout << "\nPrim's MST starting from 0:\n";
    auto primMST = prims_algo(0, vertices, edgesCount, edges);
    print_prim(primMST);

    cout << "\nKruskal MST weight: ";
    cout << kruskal_algo(edges, vertices, edgesCount) << endl;

    return 0;
}

