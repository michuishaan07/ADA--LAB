#include<iostream>
#include<chrono>
#include<vector>
#include<cstdlib>


using namespace std:: chrono;

using namespace std;


int partition(int arr[],int low ,int high)
{
    
int i=0;
int j=high-1;
int pivot=arr[low];

do{

    do{
        i=i++;
    }
    while(arr[i]<pivot);


    do{
        j=j--;
    }while(arr[j]>pivot);


if(i<j)
{
   swap(arr[i],arr[j]);
}
}
while(i<j);

arr[low]=arr[j];

arr[j]=pivot;

return j;

}

int main()
{

int arr[5]={13,6,7,8,15};
int k=partition(arr,0,6);
cout<<k;

}
