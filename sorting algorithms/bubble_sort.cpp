#include <iostream>
#include <cstddef>

using namespace std;

void swap(int *a, int *b)
{
    int temp = *a ;
    *a = *b ;
    *b = temp ;
}

void bubble_sort(int *arr, int len)
{
    int count = 0;
    cout << "unsorted list: " ;
    for (int i=0; i<len; i++)
    {
        cout << arr[i] << ", ";
    }
    
    //it will continuously swap the elements 
    int n = len-1;
    for(int i=0; i<len; i++)
    {
        for(int j=0; j< n; j++)
        {
            count++;    // just to check the time complexity.
            if(arr[j] > arr[j+1])
                swap(&arr[j], &arr[j+1]);
        }
        n--;
    }

    cout << "sorted list: ";
    for (int i=0; i<len; i++)
    {
        cout << arr[i] << ", ";
    }
    cout << "blah" << endl;
    cout << "count: " << count << endl;
}


int main()
{
    int arr[] = {59, 34, 20, 9, 4, 8, 16, 5, 4, 3, 2, 1, 0, 45, 456, 67, 68,78,89,99, 123, 23, 35, 78, 19};
    // int a = 10;
    // int b = 20;
    // swap(&a, &b);
    // cout << "a: " << a << "b: " << b << endl;
    cout <<"length of array: " << sizeof(arr)/sizeof(int) << endl;
    bubble_sort(arr, sizeof(arr)/sizeof(int));
    return 0;
}