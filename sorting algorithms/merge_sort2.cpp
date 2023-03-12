#include <iostream>
#include <cstddef>
#include <string>


using namespace std;

void print_array(int arr[], int len, string msg=""){
    cout << msg;
    for (int i=0; i<len; i++)
    {
        cout << arr[i] << ", ";
    }
    cout << endl;
}

class Sort
{
public:
    void merge_sort(int arr[], int len)
    {
        if(len == 1){
            return;
        }
        int mid = len/2;
        int left[mid];// = new int[mid];
        int right[len-mid];// = new int[len-mid];
        for(int i=0; i<len; i++)
        {
            if(i<mid){
                left[i] = arr[i];
                continue;
            }
            right[i-mid] = arr[i];
        }
        merge_sort(left, mid);
        merge_sort(right, len-mid);
        merge_sorted_arrays(arr, left, mid, right, len-mid);
    }

    void merge_sorted_arrays(int arr[], int left[], int m, int right[], int n)
    {
        int idx = 0;
        int left_index = 0;
        int right_index = 0;
        while(left_index < m  && right_index < n){
            if(left[left_index]<right[right_index])
            {
                arr[idx] = left[left_index];
                idx++;
                left_index++;
                continue;
            }
            arr[idx] = right[right_index];
            idx++;
            right_index++;
        }
        while(left_index<m){
            arr[idx] = left[left_index];
            idx++;
            left_index++;
        }
        while(right_index<n){
            arr[idx] = right[right_index];
            idx++;
            right_index++;
        }
    }

};

int main()
{
    int arr[10]={0};
    // int arr2[] = {10,10,10,10,10};
    int left[] = {1,3,4,5,6};
    int right[] = {2,5,7,9,10};
    int arr2[] = {59, 34, 20, 4, 9, 100, 8, 16, 5, 4};
    Sort sort;
    // sort.merge_sorted_arrays(arr, left, 5, right, 5);
    sort.merge_sort(arr2, sizeof(arr2)/sizeof(int));
    // print_array(arr, sizeof(arr)/sizeof(int), "sorted array: ");
    print_array(arr2, sizeof(arr2)/sizeof(int), "sorted array: ");
    return 0;
}