#include<iostream>
#include<chrono>
#include<vector>
#include<cstdlib>

using namespace std::chrono;
using namespace std;

vector<int> merge(vector<int> arr, int low, int mid, int high) {
    vector<int> result;
    int i = low, j = mid + 1;
    while (i <= mid && j <= high) {
        if (arr[i] <= arr[j]) {
            result.push_back(arr[i]);
            i++;
        } else {
            result.push_back(arr[j]);
            j++;
        }
    }
    while (i <= mid) {
        result.push_back(arr[i]);
        i++;
    }
    while (j <= high) {
        result.push_back(arr[j]);
        j++;
    }
    for (int k = 0; k < result.size(); k++) {
        arr[low + k] = result[k];
    }
    return arr;
}


int* genlist(int arr[],int k)
{
  int val;
    for(int i=1;i<=k;i++)
    {

     arr[i]=rand();
  
    }
    return arr;
}
vector<int> mergesort(vector<int> arr, int low, int high) {
    if (low < high) {
        int mid = (low + high) / 2;
        arr = mergesort(arr, low, mid);
        arr = mergesort(arr, mid + 1, high);
        arr = merge(arr, low, mid, high);
    }
    return arr;
}



void timecomp()

{

for(int i=10;i<=1000000;i=i*10)
{
  


auto start=high_resolution_clock :: now();

for(int j=1;j<=10;j++)
{
   int *ans= mergesort(arr,0,arr.size());
    }

auto stop=high_resolution_clock :: now();



auto duration = duration_cast<microseconds>(stop - start)/10;
float dur=duration.count();
dur=dur*100000;


cout<<i<<" " << dur<<endl;;


}

int main() {
    vector<int> arr(101); // Resize the vector with size 101
    for (int i = 1; i <= 100; i++) {
        arr[i] = rand();
    }
    int size = arr.size() - 1; // Size of arr should be 100, not 101
    arr = mergesort(arr, 1, size); // Pass 1 instead of 0 as the starting index
    for (int i = 1; i <= size; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}
