#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <stack>

using namespace std;

struct Edge{
    int src;
    int des;
    int weight;
    Edge(int s, int d, int w=0): src(s), des(d), weight(w) {}
};

vector<vector<Edge> > get_graph(){
    int vertices = 6;
    vector<vector<Edge> > graph;
    graph.resize(vertices);

    graph[0].push_back(Edge(0,1));
    graph[0].push_back(Edge(0,2));
    graph[0].push_back(Edge(0,3));
    
    graph[1].push_back(Edge(1,0));
    graph[1].push_back(Edge(1,2));

    graph[2].push_back(Edge(2,0));
    graph[2].push_back(Edge(2,1));
    
    graph[3].push_back(Edge(3,0));
    graph[3].push_back(Edge(3,4));
    graph[3].push_back(Edge(3,5));

    graph[4].push_back(Edge(4,3));
    graph[4].push_back(Edge(4,5));

    graph[5].push_back(Edge(5,3));
    graph[5].push_back(Edge(5,4));
    return graph;

}

void dfs(vector<vector<Edge> > &graph, int curr, int parent, int &time, vector<bool> &vis, vector<int> &dt, vector<int> &lowdt){
    vis[curr] = true;
    ++time;
    dt[curr] = time;
    lowdt[curr] = time;
    // scc += to_string(curr);
    // cout << time << endl;
    for(Edge e:graph[curr]){
        // cout << e.des << endl;
        if(e.des == parent){
            continue;
        }else if(!vis[e.des]){
            dfs(graph, e.des, curr, time, vis, dt, lowdt);
            lowdt[curr] = min(lowdt[curr], lowdt[e.des]);
            if(dt[curr] < lowdt[e.des])
                cout << "bridge is present in between: " << curr << " and " << e.des << endl; 
            // dfs(graph, e.des, vis, scc);
        }else if(vis[e.des]){
            lowdt[curr] = min(lowdt[curr], dt[e.des]);
        }
    }
}

void bridgesInGraph(vector<vector<Edge> > &graph, int vertices){
    vector<bool> vis(vertices, false);
    vector<int> dt(vertices, INT32_MAX);
    vector<int> lowdt(vertices, INT32_MAX);
    int time = 1;
    cout << "blah" <<endl;
    for(int i=0; i<vertices;i++){
        if(vis[i] != true)
            dfs(graph, i, -1, time, vis, dt, lowdt);
    }
}


int main(){
    vector<vector<Edge> > graph = get_graph();
    int vertices = 6;
    bridgesInGraph(graph, vertices);
    return 0;
}   