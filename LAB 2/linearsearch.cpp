#include<iostream>

#include<chrono>
#include<cstdlib>

using namespace std:: chrono;
using std::ofstream;
using namespace std;


int linearsearch(int arr[] , int size,int key)
{
     int i;
    for (i = 0; i < size; i++)
        if (arr[i] == key)
            return i;
    return -1;

}


int* genlist(int arr[],int k)
{
  int val;
    for(int i=0;i<=k;i++)
    {

     arr[i]=i+1;
  
    }
    return arr;
}

void timecomp(int arr[])

{

for(int i=100;i<=100000;i=i+500)
{
    arr=genlist(arr,i);
    

auto start=high_resolution_clock :: now();

for(int j=1;j<=10;j++)
{
    linearsearch(arr,i,111111111);
    // linearsearch(arr,i,1);
}


auto stop=high_resolution_clock :: now();



auto duration = duration_cast<microseconds>(stop - start)/10;
float dur=duration.count();

cout<<i<<" " << dur<<endl;;



    

}

}


int main()
{

int *arr=new int[1000];

timecomp(arr);
return 0;
    
}
