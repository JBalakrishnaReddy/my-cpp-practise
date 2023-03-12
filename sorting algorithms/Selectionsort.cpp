#include <iostream>
#include <cstddef>

using namespace std;

void swap(int *a, int *b)
{
    int temp = *a ;
    *a = *b ;
    *b = temp ;
}

class Sort
{
    public:
    void selection_sort(int *arr, int len)
    {
        // swap();
        // int arr2[len];
        int max = arr[0];
        int max_idx=0;
        int n = len;
        int count;
        for(int i=1; i<len; i++)
        {
            max = arr[1];
            max_idx = 1;
            for(int j=0; j<n; j++)
            {
                count ++;
                if(arr[j] > max){
                    max = arr[j];
                    max_idx = j;
                }
            }
            swap(&arr[max_idx], &arr[n-1]);
            // for (int i=0; i<len; i++)
            // {
            //     cout << arr[i] << ", ";
            // }
            // cout << endl;
            n--;
        }
        cout <<"count: " << count << endl;
        cout << "sorted list: ";
        for (int i=0; i<len; i++)
        {
            cout << arr[i] << ", ";
        }
    }

    void selection_sort1(int arr[], int len)
    {
        // swap();
        // int arr2[len];
        int max = arr[0];
        int max_idx=0;
        int n = len;
        int count;
        for(int i=n-1; i>=1; i--)
        {
            int max_idx = i;
            for(int j=0; j<i; j++)
            {
                count++;
                if(arr[j] >= arr[max_idx])
                    max_idx = j;
            }
            swap(&arr[max_idx], &arr[i]);
            
            for (int i=0; i<len; i++)
            {
                cout << arr[i] << ", ";
            }
            cout << endl;
        }
        cout <<"count: " << count << endl;
        cout << "sorted list: ";
        for (int i=0; i<len; i++)
        {
            cout << arr[i] << ", ";
        }

    }
};

int main()
{
    int arr[] = {59, 34, 20, 9, 4, 8, 16, 5, 4, 3, 2, 1, 0, 45, 456, 67, 68,78,89,99, 123, 23, 35, 78, 19};
    cout <<"length of array: " << sizeof(arr)/sizeof(int) << endl;
    // bubble_sort(arr, sizeof(arr)/sizeof(int));
    srand(time(0));
    cout << rand() << endl;
    int a =10, b=14;
    cout << ((a > b )?a:b) << endl;
    Sort sort;
    sort.selection_sort(arr, sizeof(arr)/sizeof(int));
    return 0;
}