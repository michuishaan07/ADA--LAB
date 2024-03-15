#include<iostream>
#include<chrono>
#include<fstream>
#include<cstdlib>

using namespace std::chrono;
using std::ofstream;
using namespace std;




int* genlist(int arr[],int k)
{
  int val;
    for(int i=1;i<=k;i++)
    {

     arr[i]=rand();
  
    }
    return arr;
}

int*precise(int arr[],int size)
{

 

int i=0;
int j=size-1;
int pivot=0;
  


       while(i<j)
       {
       while(arr[pivot]>arr[i])
       {

        i++;
       }

       while(arr[pivot]<arr[j])
       {

        j--;
       }

if(i<j)
{
    swap(arr[i],arr[j]);


}                                                                                   

       }     
 

swap(arr[j],arr[pivot]);



return arr;
}

void timecomp(int arr[])

{

for(int i=1;i<=1000000;i=i+2000)
{
    arr=genlist(arr,i);


auto start=high_resolution_clock :: now();

for(int j=1;j<=10;j++)
{
    precise(arr,i);
    
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


 int *arr=new int[100000];
 timecomp(arr);

 return 0;
}
