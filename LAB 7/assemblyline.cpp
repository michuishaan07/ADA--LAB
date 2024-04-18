#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define NUM_LINES 2
int assemblyLine(int a[][NUM_LINES], int t[][NUM_LINES], int e[], int x[], int n) {
   vector<int> dp1(n), dp2(n);
   
   dp1[0] = e[0] + a[0][0];
   dp2[0] = e[1] + a[0][1];
     for (int i = 1; i < n; ++i) {
       dp1[i] = min(dp1[i-1] + a[i][0], dp2[i-1] + t[i-1][1] + a[i][0]);
       dp2[i] = min(dp2[i-1] + a[i][1], dp1[i-1] + t[i-1][0] + a[i][1]);
   }
     return min(dp1[n-1] + x[0], dp2[n-1] + x[1]);
}
int main() {
   int a[][NUM_LINES] = {{4, 5}, {3, 2}, {2, 10}, {6, 1}};
   int t[][NUM_LINES] = {{0, 7}, {4, 0}, {5, 0}};
   int e[] = {10, 12};
   int x[] = {18, 7};
   int n = sizeof(a)/sizeof(a[0]);
   cout << "Minimum time to complete the item: " << assemblyLine(a, t, e, x, n) << endl;
   return 0;
}

