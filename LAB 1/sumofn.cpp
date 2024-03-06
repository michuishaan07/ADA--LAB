#include<iostream>
#include<chrono>
#include<fstream>
#include<cstdlib>

using namespace std::chrono;
using std::ofstream;
using namespace std;

int sumofn(int arr[], int n)
{
    if (n == 0)
    {
        return arr[0]; 
        }
    else
    {
        return (arr[n] + arr[n - 1]);
    }
}

int* genlist(int arr[],int k)
{
  int val;
    for(int i=1;i<=k;i++)
    {

     arr[i]=i+1;
  
    }
    return arr;
}

void timecomp(int arr[])

{

for(int i=100;i<=1000000;i=i*10)
{
    arr=genlist(arr,i);


auto start=high_resolution_clock :: now();

for(int j=1;j<=10;j++)
{
    int ans=sumofn(arr,i);
    
}

auto stop=high_resolution_clock :: now();



auto duration = duration_cast<microseconds>(stop - start)/10;
float dur=duration.count();
dur=dur*100000;

cout<<i<<" " << dur<<endl;;


}

}

int main()
{
    int* arr = new int[10000000];
  
    
timecomp(arr);
    return 0;
}
