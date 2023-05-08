#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <ctime>

using namespace std;

void print_vector(vector<int> & vec, string msg = "")
{
    cout << msg;
    for(vector<int>:: iterator i = vec.begin(); i!=vec.end();i++)
    {
        cout << *i << ",";
    }
    cout << endl;
}

int main()
{
    vector<int> vec; //(1,2,3,4,5);
    vec.reserve(5);
    cout << "vec size: " << vec.size() << " vec max size: " << vec.max_size() << " vec cap: "<< vec.capacity() << endl;
    int arr[] = {1,2,3,4,5};
    for(int i=0; i<5;i++){
        vec.push_back(arr[i]);
        // cout << "vec size: " << vec.size() <<" vec cap: "<< vec.capacity() << endl;
    }
    // cout << "vec size: " << vec.size() << " vec max size: " << vec.max_size() << " vec cap: "<< vec.capacity() << endl;
    // cout << vec.back() << vec.back() << endl;
    int arr2[] = {3,5,6,7,9};
    vector<int> vec2; 
    for(int i=0; i<5;i++)
        vec2.push_back(arr2[i]);

    vec2.insert(vec2.begin()+2, 3, 20);
    // vec2.insert(vec2.begin()+3, 30);
    // Solution blah;// = new Solution();
    // blah.merge(vec, 3, vec2 ,3);
    print_vector(vec);
    print_vector(vec2);

    return 0;
}
