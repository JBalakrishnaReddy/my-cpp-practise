#include <iostream>
#include <string>

#include <queue>
#include <array>
#include <vector>
#include <list>
#include <stack>

using namespace std;

struct Edge{
    int src;
    int des;
    int weight;
    Edge(int s, int d, int w=0): src(s), des(d), weight(w) {}
};

struct triple{
    int node;
    bool vis;
    int dis;
    triple(int x, bool y, int z): node(x), vis(y), dis(z){};
};

struct myComp{
    bool operator()(pair<int, int> x, pair<int, int> y){
        if (x.second == y.second)
            return x.first > y.first;
        return x.second > y.second;
    }

};

struct myComp2{
    bool operator()(triple x, triple y){
        if(x.vis == y.vis)  return x.dis > y.dis;
        return x.vis > y.vis;
    }

};

vector<vector<Edge> > getGraph(){
    vector<vector<Edge> > graph;
    graph.resize(6);

    graph[0].push_back(Edge(0, 1, 2));
    graph[0].push_back(Edge(0, 2, 4));

    graph[1].push_back(Edge(1, 2, 1));
    graph[1].push_back(Edge(1, 3, 7));

    graph[2].push_back(Edge(2, 4, 3));

    graph[3].push_back(Edge(3, 5, 1));

    graph[4].push_back(Edge(4, 3, 2));
    graph[4].push_back(Edge(4, 5, 5));
    return graph;
}

vector<vector<Edge> > getGraphForBF(){
    vector<vector<Edge> > graph;
    graph.resize(5);

    graph[0].push_back(Edge(0, 1, 2));
    graph[0].push_back(Edge(0, 2, 4));
    graph[1].push_back(Edge(1, 2, -4));
    graph[2].push_back(Edge(2, 3, 2));
    graph[3].push_back(Edge(3, 4, 4));
    graph[4].push_back(Edge(4, 1, -1));
    return graph;
}

class DA{

};


void dijkstra(){
    vector<int> dist0(6, INT32_MAX);    dist0[0] = 0; // because of distance from itself will be always zero.
    int vertices = 6;
    vector<vector<Edge> > graph = getGraph();
    vector<bool> vis(6, false);
    priority_queue<pair<int, int>, vector<pair<int, int>>, myComp > pq;
    pq.push({0,0});
    while(!pq.empty()){
        pair<int, int> p = pq.top();    // p -> node number, current weight
        pq.pop();
        if(!vis[p.first])
        {
            vis[p.first] = true;
            for(auto e: graph[p.first]){
                if(dist0[p.first]+e.weight < dist0[e.des]) dist0[e.des] = dist0[p.first]+e.weight;
                pq.push({e.des, dist0[e.des]});
            }
        }
    }
    for(auto dis:dist0){
        cout << dis << ", ";
    }
    cout << endl;
    
}


void BellmanFord(){
    vector<int> dist0(5, INT32_MAX);    dist0[0] = 0; // because of distance from itself will be always zero.
    vector<vector<Edge> > graph = getGraphForBF();
    int vertices = 5;

    for(int k=0; k< vertices-1; k++){
        for(int i=0; i<vertices;i++){
            for(int j=0; j<graph[i].size(); j++){
                Edge e = graph[i][j];
                if(dist0[e.src]!=INT32_MAX && dist0[e.src]+e.weight < dist0[e.des]) dist0[e.des] = dist0[e.src]+e.weight;
                // pq.push({e.des, dist0[e.des]});
            }
        }
        for(auto dis:dist0){
            cout << dis << ", ";
        }
        cout << endl;
    }
    {
        for(int i=0; i<vertices;i++){
            for(int j=0; j<graph[i].size(); j++){
                Edge e = graph[i][j];
                if(dist0[e.src]!=INT32_MAX && dist0[e.src]+e.weight < dist0[e.des]){
                    dist0[e.des] = dist0[e.src]+e.weight;
                    cout << "negative cycle exists" << endl;
                }
                // pq.push({e.des, dist0[e.des]});
            }
        }
        for(auto dis:dist0){
            cout << dis << ", ";
        }
        cout << endl;
    }
}

int main(){
    
    // dijkstra();
    BellmanFord();

}