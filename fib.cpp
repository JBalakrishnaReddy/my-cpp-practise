#include <iostream>

using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        int arr[] = {0,1};
        // int temp = 0;
        for (int i=0; i<n; i++){
            // temp = arr[0];
            // arr[0] = arr[1];
            // arr[1] = arr[1]+temp;
            arr[0] = arr[0]+arr[1];
            arr[1] = arr[0]-arr[1];
            arr[0] = arr[0]-arr[1];
        }
        return arr[1];
    }
};

int main()
{
    Solution obj;
    cout << obj.climbStairs(3) << endl;
    return 0;
}