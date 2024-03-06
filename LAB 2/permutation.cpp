#include<iostream>

#include<chrono>
#include<cstdlib>

using namespace std:: chrono;
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

void perm(int arr[],int k,int size)

{

    if(k==size)
    {
        for(int i=0;i<=size-1;i++)
        {

            // cout<<arr[i];
        }
    }
    else
    for(int i=k;i<=size;i++)
    {

        swap(arr[i],arr[k]);
        perm(arr,k+1,size);
        swap(arr[i],arr[k]);


    }

}
void timecomp(int arr[])

{

for(int i=1;i<=100000;i++)
{
    arr=genlist(arr,i);


auto start=high_resolution_clock :: now();

for(int j=1;j<=10;j++)
{
    perm(arr,0,i);
}


auto stop=high_resolution_clock :: now();



auto duration = duration_cast<microseconds>(stop - start)/10;
float dur=duration.count();

cout<<i<<" " << dur<<endl;;



    

}

}

int main()
{

 
 
int *arr=new int[100000];

timecomp(arr);

    
    return 0;
}
