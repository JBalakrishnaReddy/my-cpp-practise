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
    int vertices = 5;
    vector<vector<Edge> > graph;
    graph.resize(5);

    graph[0].push_back(Edge(0,2));
    graph[0].push_back(Edge(0,3));
    
    graph[1].push_back(Edge(1,0));
    graph[2].push_back(Edge(2,1));
    
    graph[3].push_back(Edge(3,4));
    return graph;
}

vector<vector<Edge> > transposeGraphDirections(vector<vector<Edge> > &graph, int vertices){
    vector<vector<Edge> > newGraph;
    newGraph.resize(vertices);
    for(int i=0; i< vertices;i++){
        for(Edge e:graph[i]){
            newGraph[e.des].push_back({e.des, e.src});
        }
    }
    // for(int i=0; i< vertices;i++){
    //     for(Edge e:newGraph[i]){
    //         cout << "src: " << e.src << "des: " << e.des << endl;
    //     }
    // }
    return newGraph;
}

void getTopologicalSortingOrder(vector<vector<Edge> > &dag, vector<bool>& vis, int current, stack<int> &stk){
    vis[current] = true;

    for(Edge e: dag[current]){
        if(!vis[e.des])
            getTopologicalSortingOrder(dag, vis, e.des, stk);
    }
    stk.push(current);
}

void dfs(vector<vector<Edge> > &graph, int curr, vector<bool> &vis, string &scc){
    // string SCC = "";
    vis[curr] = true;
    scc += to_string(curr);
    for(Edge e:graph[curr]){
        if(!vis[e.des]){
            vis[e.des] = true;
            dfs(graph, e.des, vis, scc);
        }
    }

}

void kosaAlgo(){    // TC = 3*O(V+E) i.e O(V+E)
    vector<vector<Edge> > graph = get_graph();
    int vertices = 5;
    vector<bool> vis(vertices, false);
    stack<int> stk;
    {   //Step - 1 O(V+E)
        // This block of code will run the topological sorting and returns us the stk.
        vector<bool> vis(vertices, false);
        for(int i=0; i<vertices; i++){
            if(!vis[i])
                getTopologicalSortingOrder(graph, vis, i, stk);
        }
    }
    // Step - 2
    vector<vector<Edge> > transposeGraph = transposeGraphDirections(graph, vertices); // TC = O(V+E)

    // Step - 3 
    while(!stk.empty()){    //TC= O(V+E)
        int curr = stk.top();
        stk.pop();
        // here we need to run the dfs on the new Graph;
        if(!vis[curr]){
            // vis[curr] = true;
            string scc = "";
            dfs(transposeGraph, curr, vis, scc);
            cout << "scc "<< scc << endl;
        }
    }

}

int main(){
    vector<vector<Edge> > graph = get_graph();
    int vertices = 5;
    // for(int i=0; i< vertices;i++){
    //     for(Edge e:graph[i]){
    //         cout << "src: " << e.src << "des: " << e.des << endl;
    //     }
    // }
    // transposeGraphDirections(graph, vertices);
    kosaAlgo();
    return 0;
}