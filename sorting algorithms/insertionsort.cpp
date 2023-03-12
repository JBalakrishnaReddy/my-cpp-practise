#include <iostream>
#include <cstddef>
#include <string>

using namespace std;

void swap(int *a, int *b)
{
    int temp = *a ;
    *a = *b ;
    *b = temp ;
}

void push_back()
{


}

void push_at_start()
{


}

class Sort
{
    public:
    void insertion_sort(int arr[], int len)
    {
        // swap();
        int arr2[len];
        int count = 0;
        for(int i=0;i<len-1;i++)
        {
            if(arr[i] > arr[i+1])
            {
                swap(&arr[i], &arr[i+1]);
                // print_array(arr, len, "it-i: "+to_string(i)+ " :");
                for(int j=i; j>0; j--)
                {
                    if(arr[j] < arr[j-1])
                        swap(&arr[j], &arr[j-1]);
                        // print_array(arr, len, "it-j: "+to_string(j)+ " :");
                    count++;
                }
            }
        }
        // cout << "sorted list: ";
        cout << "count: " << count << endl;
        print_array(arr, len, "sorted list: ");
        
    }

    void print_array(int arr[], int len, string msg=""){
        cout << msg;
        for (int i=0; i<len; i++)
        {
            cout << arr[i] << ", ";
        }
        cout << endl;
    }
};

int main()
{
    int arr[] = {59, 34, 20, 9, 4, 8, 16, 5, 4, 3, 2, 1, 0, 45, 456, 67, 68,78,89,99, 123, 23, 35, 78, 19};
    int arr2[] = {59, 34, 20, 9, 4, 8, 16, 5, 4};
    cout <<"length of array: " << sizeof(arr)/sizeof(int) << endl;
    // bubble_sort(arr, sizeof(arr)/sizeof(int));
    // srand(time(0));
    // cout << rand() << endl;

    Sort sort;
    sort.print_array(arr, sizeof(arr)/sizeof(int), "unsorted array: ");
    sort.insertion_sort(arr, sizeof(arr)/sizeof(int));
    return 0;
}