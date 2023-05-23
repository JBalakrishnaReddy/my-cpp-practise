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

vector<vector<Edge> > get_directed_graph(){
    /*  
    */
    vector<vector<Edge> > lis;
    // lis.resize(4);
    // lis[0].push_back(Edge(0, 2));
    // lis[1].push_back(Edge(1, 0));
    // lis[2].push_back(Edge(2, 3));
    // lis[3].push_back(Edge(3, 1));
    lis.resize(5);
    lis[0].push_back(Edge(0,1));
    
    lis[2].push_back(Edge(2,1));
    lis[2].push_back(Edge(2,3));
    
    lis[3].push_back(Edge(3,4));
    lis[4].push_back(Edge(4,2));



    return lis;
}

void print_nodes(vector<vector<Edge> > &lis){
    for(auto i:lis){
        for(auto j:i){
            cout << j.src << "," << j.des << endl;
        }
    }

}

void bfs(vector<vector<Edge> > &lis, int vertices)  // O(V+E)
{
    queue<int> q;
    vector<bool> vis(vertices, false);// {false,false,false,false,false,false,false};
    for(int i=0; i<vertices; i++){
        if(vis[i] == false){
            q.push(lis[i][0].src);
            while(!q.empty()){
                int current = q.front();
                q.pop();
                if(!vis[current]){
                    for(auto j:lis[current])    q.push(j.des);
                    vis[current] = true;
                    cout << current << ", ";
                }
            }
        }
    }
    cout << endl;
}

void dfs(vector<vector <Edge> > &lis, int current, vector<bool>& vis){  // Time complexity O(V+E)
    cout << current << ", ";
    vis[current] = true;
    for(int i=0; i< lis[current].size(); i++)   if( vis[lis[current][i].des] == false)  dfs(lis, lis[current][i].des, vis);
}

void printAllPathstoTarget(vector<vector<Edge> > &lis, vector<bool> &vis, int current, string path, int target){
    // We use dfs algorithm for this problem
    if(current == target){
        cout << path << endl;
        return;
    }
    vis[current] = true;
    for(int i=0; i < lis[current].size(); i++){
        if(vis[lis[current][i].des] == false)
            printAllPathstoTarget(lis, vis, lis[current][i].des, path + to_string(current), target);
    }
    vis[current] = false;

}

bool doesGraphHasCycle(vector<vector<Edge>> &graph, vector<bool> &vis, int current, vector<bool> &recStack){
    vis[current] = true;
    recStack[current] = true;

    for (int i=0; i< graph[current].size(); i++){
        Edge e = graph[current][i];
        if(recStack[e.des] == true) return true;
        if(!vis[e.des] && doesGraphHasCycle(graph, vis, e.des, recStack) == true)  return true;
        // if(doesGraphHasCycle(graph, vis, e.des, recStack)) return true;
    }
    recStack[current] = false;
    return false;
}

int main(){
    {
        // int vertices = 7;
        // vector<vector<Edge> > lis = get_graph();
        // print_nodes(lis);
        // bfs(lis, vertices);
        // vector<bool> vis(vertices, false);
        // dfs(lis, lis[0][0].src, vis);
        // printAllPathstoTarget(lis, vis, 0, "", 5);
    }
    {
        vector<vector<Edge> > graph = get_directed_graph();
        int vertices = 5;
        vector<bool> vis(vertices, false);
        vector<bool> recStack(vertices, false);
        cout << doesGraphHasCycle(graph, vis, 1, recStack) << endl;
    }
    cout << endl;
    return 0;
}