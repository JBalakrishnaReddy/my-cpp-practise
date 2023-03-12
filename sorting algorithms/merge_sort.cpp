#include <iostream>
#include <cstddef>
#include <string>
#include <stdio.h>

using namespace std;

void swap(int *a, int *b)
{
    int temp = *a ;
    *a = *b ;
    *b = temp ;
}

void print_array(int arr[], int len, string msg=""){
    cout << msg;
    for (int i=0; i<len; i++)
    {
        cout << arr[i] << ", ";
    }
    cout << endl;
}

void merge_sorted_arrays(int arr[], int left[], int m, int right[], int n)
{
    int idx = 0;
    // int j=0;
    int k=0;
    int l=0;
    for (int i=0; i<m;i++){
        for (int j=k; j<n; j++){
            print_array(arr, 10, "");
            // cout << "j: " << right[j] << "i: " << left[i] << endl;
            if(right[j] <= left[i]){
                arr[idx] = right[j];
                k++;
                idx++;
                if(j == n-1 ){
                    memcpy(&arr[idx], &left[l], (m-l)*sizeof(int));
                }
                continue;
            }
            arr[idx] = left[i];
            idx++;
            l++;
            if(i == m-1 ){
                memcpy(&arr[idx], &right[k], (n-k)*sizeof(int));
            }
            break;
        }
        
    }
    // if(k+l < m+n)
    // {
    //     if(k<n){
    //     //fill with right array
    //         memcpy(&arr[k+l], &right[(m+n)-(k-l)], (n-k) * sizeof(int));
    //     }else if(l<m){
    //         memcpy(&arr[k+l], &left[(m+n)-(k-l)], (m-l) * sizeof(int));
    //     }
    // }

    // cout << "idx: " << idx << " " << m-(idx-n) << endl;
    // memcpy(&arr[idx], &left[m-(idx-n)], (m+n-idx)*sizeof(int));
    // memcpy(&arr[7], &left[3], 3*sizeof(int));
}


class Sort
{
    public:
    void merge_sort(int arr[], int len)
    {
        if(len <= 1){
            return;
        }else if(len == 2 ){
            if(arr[1] < arr[0])
            {
                swap(&arr[1], &arr[0]);
            }
            return;
        }
        int mid = len/2;
        merge(arr, len, mid, len-mid);
    }

    void merge(int arr[],int len, int left_arr_len, int right_arr_len)
    {
        int left[left_arr_len];
        memcpy(left, &arr, left_arr_len);
        int right[right_arr_len];
        memcpy(right, &arr[left_arr_len], right_arr_len);
        print_array(left, left_arr_len, "left unsorted array: ");
        print_array(right, right_arr_len, "right unsorted array: ");
        merge_sort(left, left_arr_len);
        merge_sort(right, right_arr_len);
        print_array(left, left_arr_len, "left sorted array: ");
        print_array(right, right_arr_len, "right sorted array: ");
        merge_sorted_arrays(arr, left, left_arr_len, right, right_arr_len);
        // int count = 0;
        // for(int i=0; i<left_arr_len;i++)
        // {
        //     for(int j=0; j<right_arr_len; j++)
        //     {
        //         if(left[i] <= right[j]){}
        //     }
        // }
    }

    void merge_sorted_arrays(int arr[], int left[], int m, int right[], int n)
    {
        int idx = 0;
        // int j=0;
        int k=0;
        int l=0;
        for (int i=0; i<m;i++){
            for (int j=k; j<n; j++){
                // print_array(arr, 10, "");
                // cout << "j: " << right[j] << "i: " << left[i] << endl;
                if(right[j] <= left[i]){
                    arr[idx] = right[j];
                    k++;
                    idx++;
                    if(j == n-1 ){
                        memcpy(&arr[idx], &left[l], (m-l)*sizeof(int));
                    }
                    continue;
                }
                arr[idx] = left[i];
                idx++;
                l++;
                if(i == m-1 ){
                    memcpy(&arr[idx], &right[k], (n-k)*sizeof(int));
                }
                break;
            }
            
        }
        // if(k+l < m+n)
        // {
        //     if(k<n){
        //     //fill with right array
        //         memcpy(&arr[k+l], &right[(m+n)-(k-l)], (n-k) * sizeof(int));
        //     }else if(l<m){
        //         memcpy(&arr[k+l], &left[(m+n)-(k-l)], (m-l) * sizeof(int));
        //     }
        // }

        // cout << "idx: " << idx << " " << m-(idx-n) << endl;
        // memcpy(&arr[idx], &left[m-(idx-n)], (m+n-idx)*sizeof(int));
        // memcpy(&arr[7], &left[3], 3*sizeof(int));
    }

};


int main(){
    int arr[10]={0};
    // int arr2[] = {10,10,10,10,10};
    int left[] = {1,3,4,5,6};
    int right[] = {2,5,7,9,10};

    int arr2[] = {59, 34, 20, 4, 9, 100, 8, 16, 5, 4};
    // merge_sorted_arrays(arr, left, 5, right, 5);
    // memcpy(arr, arr2, 5*sizeof(int));
    // print_array(arr, 10, "sorted array: ");
    Sort sort;
    sort.merge_sort(arr2, sizeof(arr2)/sizeof(int));
    print_array(arr2, sizeof(arr2)/sizeof(int), "sorted array: ");
    return 0;
}
