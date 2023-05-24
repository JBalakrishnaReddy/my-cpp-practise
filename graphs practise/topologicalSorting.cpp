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


vector<vector<Edge> > get_graph(){
    /*  
           1 --- 3
         /       |  \
        0        |   5 --- 6
         \       |  /
           2 --- 4
    */
    vector<vector<Edge> > lis;
    // lis.reserve(6);
    lis.resize(7);
    lis[0].push_back(Edge(0,1));
    lis[0].push_back(Edge(0,2));

    lis[1].push_back(Edge(1,0));
    lis[1].push_back(Edge(1,3));
    
    lis[2].push_back(Edge(2,0));
    lis[2].push_back(Edge(2,4));
    
    lis[3].push_back(Edge(3,1));
    lis[3].push_back(Edge(3,4));
    lis[3].push_back(Edge(3,5));
    
    lis[4].push_back(Edge(4,2));
    lis[4].push_back(Edge(4,3));
    lis[4].push_back(Edge(4,5));
    
    lis[5].push_back(Edge(5,3));
    lis[5].push_back(Edge(5,4));
    lis[5].push_back(Edge(5,6));
    
    lis[6].push_back(Edge(6,5));
    return lis;
}


vector<vector<Edge> > getDirectedAcyclicGraph(){
    /*  
    */
    vector<vector<Edge> > lis;
    lis.resize(6);
    lis[2].push_back(Edge(2,3));
    lis[3].push_back(Edge(3,1));
    lis[4].push_back(Edge(4,0));
    lis[4].push_back(Edge(4,1));
    lis[5].push_back(Edge(5,0));
    lis[5].push_back(Edge(5,2));
    return lis;
}

void getTopologicalSortingOrder(vector<vector<Edge> > &dag, vector<bool>& vis, int current, stack<int> &stk){
    vis[current] = true;

    for(Edge e: dag[current]){
        if(!vis[e.des])
            getTopologicalSortingOrder(dag, vis, e.des, stk);
    }
    stk.push(current);
    // cout << current << endl;
}
void topSort(vector<vector<Edge> > &dag, int vertices){
    stack<int> stk;
    vector<bool> vis(vertices, false);
    for(int i=0; i<6; i++){
        if(!vis[i])
            getTopologicalSortingOrder(dag, vis, i, stk);
    }
    while(!stk.empty()){
        cout << stk.top() << ", ";
        stk.pop();
    }
    cout << endl;
}

bool doesCycleExist(vector<vector<Edge> > &graph, vector<bool> &vis, int current, int parent){
    // bool cycleExists = false;
    vis[current] = true;
    for(Edge e: graph[current]){
        if(vis[e.des] && e.des != parent){
            return true;
        }else if(!vis[e.des] && doesCycleExist(graph, vis, e.des, current)){
            return true;
        }
    }
    return false;
}

int main(){
    // vector<vector<Edge> > dag = getDirectedAcyclicGraph();
    // topSort(dag, 6);
    vector<vector<Edge> > graph = get_graph();
    int vertices = 7;
    vector<bool> vis(vertices, false);
    vector<bool> recStack(vertices, false);
    bool cycleExists = false;
    for(int i=0; i<vertices;i++){
        if(!vis[i]) {
            cycleExists = doesCycleExist(graph, vis, i, -1);
            if(cycleExists) break;
        }
    }
    cout << "\e[31m exist: \e[0m" << cycleExists << endl;

    return 0;

}