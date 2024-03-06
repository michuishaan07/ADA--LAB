#include<iostream>

#include<chrono>
#include<cstdlib>

using namespace std:: chrono;
using std::ofstream;
using namespace std;

 
 int* genlist(int arr[],int k)
{
  int val;
    for(int i=0;i<=k;i++)
    {

     arr[i]=i+1;
  
    }
    return arr;
}



 int binarysearch(int arr[], int l, int r, int x)
{
    if (r >= l) {
        int mid = l + (r - l) / 2;
 
       
        if (arr[mid] == x)
            return mid;
 
      
        if (arr[mid] > x)
            return binarysearch(arr, l, mid - 1, x);
 
   
        return binarysearch(arr, mid + 1, r, x);
    }
 
    return -1;
}


void timecomp(int arr[])

{

for(int i=100;i<=1000000;i=i+1000)
{
    arr=genlist(arr,i);.+
    


auto start=high_resolution_clock :: now();

for(int j=1;j<=10;j++)
{
//    binarysearch(arr,0,i,i/2);
binarysearch(arr,0,i,1000005);
}


auto stop=high_resolution_clock :: now();



auto duration = duration_cast<microseconds>(stop - start)/10;
float dur=duration.count();

cout<<i<<" " << dur<<endl;;



    

}

}
 
int main()
{

int*arr=new int[10000];

timecomp(arr);

    return 0;
}
