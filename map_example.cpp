
#include <iostream>       // std::cout
#include <queue>          // std::priority_queue
#include <vector>         // std::vector
#include <functional>     // std::greater
#include <map>
#include <unordered_map>


using namespace std;

void print_vector(vector<int> & vec, string msg=""){
    cout << msg;
    for (const int &s : vec) /*insides follow this */   cout << s << ", ";
    cout << endl;
}

struct compare {
template <typename T>
   
   bool operator()(const T& a, const T& b) 
   {
      if (a.second != b.second) {
         return a.second < b.second;
      }
      return a.first < b.first;
   }
};

int main(){
    map<int , int, greater<int>> first;
    first[1] = 2;
    first[2] = 5;
    first[40] = 6;
    first[3] = 3;
    first[20] = 10;
    for(map<int,int>::iterator it=first.begin(); it != first.end(); it++){
        cout << it->first << " " << it->second << endl;
    }
    cout << first[10] << endl;
    for(map<int,int>::iterator it=first.begin(); it != first.end(); it++){
        cout << it->first << " " << it->second << endl;
    }
    map<char, int> second;
    second['b'] = 10;
    second['c'] = 5;
    second['a'] = 20;
    for(map<char,int>::iterator it=second.begin(); it != second.end(); it++){
        cout << it->first << " " << it->second << endl;
    }
    vector<int> nums{1,1,1, 1,2,2,3,3, 4,4,4,4};
    // map<int, int, compare> lis;
    map<int, int, greater<int> > lis;
    for(auto i:nums){
        lis[i] = lis[i]+1;
    }
    // map <int,int> lis2(lis);
    for(map<int,int>::iterator it=lis.begin(); it != lis.end(); it++){
        cout << it->first << " " << it->second << endl;
    }
 

    // return ;
}