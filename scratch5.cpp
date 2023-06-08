// #include <iostream>
// #include <unordered_map>
// #include <algorithm>
// #include <vector>
// #include <map>


// using namespace std;

// class Solution{
// public:
//     vector<int> minDaysPC;
//     unordered_map <int,int> mp;
//     unordered_map<int, int> dp;

//     int minDays(int n) {
//         if (n <= 1)
//             return n;
//         if (dp.count(n) == 0)
//             dp[n] = 1 + min(n % 2 + minDays(n / 2), n % 3 + minDays(n / 3));
//         return dp[n];
//     }
// };


// int main(int argc, char* argv[]){
//     Solution sol;
//     int temp = 0;
//     for(int i=1; i<argc; i++){
//         cout << atoi(argv[i]) << ": " << sol.minDays(atoi(argv[i])) << endl;
//     }

//     cout << 40 << ": " << sol.minDays(40) << endl;
//     cout << 80 << ": " << sol.minDays(80) << endl;
//     cout << 19786 << ": " << sol.minDays(19786) << endl;
//     cout << 84806671 << ": " << sol.minDays(84806671) << endl;
//     return 0;
// }

#include <stdio.h>
int main() {
int i;
for(i=0;i<10;i++){
int c=2;
const int a=2;
static int b= 2;
// a++;
b++;
c++;
printf("value of a : %d",a);
printf("value of b : %d",b);
printf("value of c : %d",c);
}
}