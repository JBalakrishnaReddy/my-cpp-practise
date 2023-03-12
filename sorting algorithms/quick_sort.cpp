#include <iostream>
#include <cstddef>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void swap(int *a, int *b)
{
    int temp = *a ;
    *a = *b ;
    *b = temp ;
}

// void swap(int a, int b);
// {
//     temp = vec[i];
//     vec[i] = vec[j];
//     vec[j] = temp;
// }

void print_array(int arr[], int len, string msg=""){
    cout << msg;
    for (int i=0; i<len; i++)
    {
        cout << arr[i] << ", ";
    }
    cout << endl;
}

void print_vector(vector<int> & vec, string msg ="")
{
    cout << msg << endl;
    for(vector<int>:: iterator i = vec.begin(); i!=vec.end();i++)
    {
        cout << *i << ",";
    }
    // for_each(vec.begin(), vec.end(), (int x){cout << x << ", "}); 
    cout << endl;
}

class Sort
{
    public:
    void quick_sort(int arr[], int len)
    {


    }

    void quick_sort_uncleaned(vector<int> &vec)
    {
        int len = vec.size();
        if(len <= 1)
        {
            return;
        }
        // int pivot = vec[vec.end()-1];
        int pivot = vec.at(vec.size()-1);
        // cout << "pivot: " << pivot << endl;
        int i = -1;
        for (int j=0; j< vec.size()-1; j++)
        {
            if (vec[j] >= pivot){
                continue;
            }
            i++;
            swap(&vec[i], &vec[j]);
            // print_vector(vec, "j: "+to_string(j));
        }
        i++;
        // cout <<"i: " << i << endl;
        swap(&vec[i], &vec[vec.size()-1]);
        // print_vector(vec, "i: ");
        vector<int> left(vec.begin(), vec.begin()+i);
        vector<int> right(vec.begin()+i+1, vec.end());
        // print_vector(left, "left: ");
        // print_vector(right, "right: ");
        quick_sort(left);
        quick_sort(right);
        // once we get these sorted vectors we will replace using the swap_ranges function
        if(left.size()>0){
            // cout << "left swapping: " <<endl;
            // print_vector(left, "left for sorting: ");
            swap_ranges(vec.begin(), vec.begin()+i, left.begin());
            // print_vector(vec, "after left swap: ");
        }
        if(right.size()>0)
        {
            // cout << "right swapping: " << endl;
            // print_vector(right, "right for sorting: ");
            swap_ranges(vec.begin()+i+1, vec.end(), right.begin());
            // print_vector(vec, "after right swap: ");
        }
        // print_vector(vec, "don't know: ");
    }

    void quick_sort(vector<int> &vec)
    {
        int len = vec.size();
        if(len <= 1)
        {
            return;
        }
        int pivot = vec.at(vec.size()-1);
        int i = -1;
        for (int j=0; j< vec.size()-1; j++)
        {
            if (vec[j] >= pivot){
                continue;
            }
            i++;
            swap(&vec[i], &vec[j]);
        }
        i++;
        swap(&vec[i], &vec[vec.size()-1]);
        vector<int> left(vec.begin(), vec.begin()+i);
        vector<int> right(vec.begin()+i+1, vec.end());
        quick_sort(left);
        quick_sort(right);
        // once we get these sorted vectors we will replace using the swap_ranges function
        if(left.size()>0){
            swap_ranges(vec.begin(), vec.begin()+i, left.begin());
        }
        if(right.size()>0)
        {
            swap_ranges(vec.begin()+i+1, vec.end(), right.begin());
        }
    }

};

int main(){
    int arr[] = {59, 34, 20, 9, 100, 8, 16, 5, 4, 3, 2, 1, 0, 45, 456, 67, 68,78,89,99, 123, 23, 35, 78, 19};
    int arr2[] = {59, 34, 20, 4, 9, 100, 8, 16, 5, 4};
    // cout <<"length of array: " << sizeof(arr)/sizeof(int) << endl;
    vector <int> vec;
    for(int i=0; i< sizeof(arr)/sizeof(int); i++)
    {
        vec.push_back(arr[i]);
    }

    // vec.assign(arr2, arr2+10);
    // vector<int> left(vec.begin(), vec.begin()+3);
    // vector<int> right(vec.begin()+3, vec.end());
    // print_vector(left, "left: ");
    // print_vector(right, "right: ");
    Sort sort;
    // print_array(arr, sizeof(arr)/sizeof(int), "unsorted array: ");
    // sort.quick_sort(arr, sizeof(arr)/sizeof(int));
    print_vector(vec, "Unsorted vec: ");
    sort.quick_sort(vec);
    print_vector(vec, "Sorted vec: ");

    return 0;
}
