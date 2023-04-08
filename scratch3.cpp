//This program has examples of using call by reference which is different from
// what we have learnt previously

#include <iostream>
#include <cstddef>
#include <vector>

using namespace std;

void print_vector(vector<int> &vec, string msg="")
{
    cout << msg;
    for(vector<int>::iterator it=vec.begin(); it!=vec.end(); it++)
        cout << *it << ", ";
    cout << endl;
}

//
// void add(int x, int y){
//     cout <<"call by value is called: " ;
//     cout << x+y << endl;
// }

void add(int &x, int &y){
    cout <<"call by reference is called: ";
    cout << x+ y << endl;

}

int main()
{
    vector<int> vec;
    int arr[] = {1,2,3,4,5};
    for(int i=0; i<5; i++){
        vec.push_back(arr[i]);
    }
    print_vector(vec, "vector before deletion: ");
    vec.erase(vec.begin()+2);
    print_vector(vec,"vector after deletion: ");


    return 0;

}
