#include <iostream>
#include <vector>
#include <queue>
#include <map>

using namespace std;

struct Edge{
    int src;
    int des;
    int weight;
    Edge(int s, int d, int w=0): src(s), des(d), weight(w) {}
};

struct cmp{
    bool operator()(Edge x, Edge y){
      return x.weight > y. weight;
    }
};

// struct myComp2{
//     bool operator()(triple x, triple y){
//         if(x.vis == y.vis)  return x.dis > y.dis;
//         return x.vis > y.vis;
//     }

// };

vector<vector<Edge> > get_graph(){
    vector<vector<Edge> > graph;
    graph.resize(4);
    graph[0].push_back(Edge(0, 1, 10));
    graph[0].push_back(Edge(0, 2, 15));
    graph[0].push_back(Edge(0, 3, 30));

    graph[1].push_back(Edge(1, 0, 10));
    graph[1].push_back(Edge(1, 3, 40));
    
    graph[2].push_back(Edge(2, 0, 15));
    graph[2].push_back(Edge(2, 3, 50));
    
    graph[3].push_back(Edge(3, 0, 30));
    graph[3].push_back(Edge(3, 1, 40));
    graph[3].push_back(Edge(3, 2, 50));

    return graph;
}

void primsAlgo(){   // TC = O(EloE)
    vector<vector<Edge> > graph = get_graph();
    priority_queue<Edge, vector<Edge>, cmp> pq;
    int vertices = 4;
    vector<bool> vis(4, false);         // This will hold what nodes are present in MST list
    // vector<bool> mst_list(4, false);
    int startNode = 0;
    int totalWeight = 0;
    pq.push(Edge(0,0,0));
    while(!pq.empty()){
        Edge curr = pq.top();
        pq.pop();
        if(!vis[curr.src]){
            vis[curr.src] = true;
            for(Edge e: graph[curr.src]){
                cout << e.weight << endl;
                totalWeight += e.weight;
                if(!vis[e.des]) pq.push(e); 
            }
        }

        // cout << e.src << ": " << e.des << ": " << e.weight << endl;

        // if(!vis[e.])
    }
    cout << "min weight: " << totalWeight << endl;

}

int main(){
    primsAlgo();
    return 0;
}