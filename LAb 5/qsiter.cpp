#include<iostream>
#include<stack>
#include<cstdlib>
using namespace std;


int partition(int arr[], int low, int high) {
   int pivot = arr[high];
   int i = (low - 1);


   for (int j = low; j <= high - 1; j++) {
       if (arr[j] <= pivot) {
           i++;
           swap(arr[i], arr[j]);
       }
   }
   swap(arr[i + 1], arr[high]);
   return (i + 1);
}


void quickSortIterative(int arr[], int low, int high) {
   stack<int> s;
   s.push(low);
   s.push(high);


   while (!s.empty()) {
       high = s.top();
       s.pop();
       low = s.top();
       s.pop();


       int pivot = partition(arr, low, high);


       if (pivot - 1 > low) {
           s.push(low);
           s.push(pivot - 1);
       }


       if (pivot + 1 < high) {
           s.push(pivot + 1);
           s.push(high);
       }
   }
}


void printArr(int arr[], int n) {
   for (int i = 0; i < n; ++i) {
       cout << arr[i] << " ";
   }
   cout << endl;
}




void genlist(int arr[], int k) {
   for (int i = 0; i < k; i++) {
       arr[i] = rand();
   }
}


int main() {
   const int n = 100;
   int list[n];


    genlist(list, n);


  
   quickSortIterative(list, 0, n - 1);


    printArr(list, n);


   return 0;
}

