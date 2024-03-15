
#include<iostream>
#include<chrono>
#include<vector>
#include<cstdlib>


using namespace std:: chrono;

using namespace std;

vector  <int> genlist(vector<int>arr,int k)
{
  int val;
    for(int i=1;i<=k;i++)
    {

     arr.push_back(rand());
  
    }
    return arr;
}

vector<int> mergelist(vector<int> arr1, vector<int> arr2) {
    vector<int> arr3;
    int i = 0, j = 0;

    while (i < arr1.size() && j < arr2.size()) {
        if (arr1[i] < arr2[j]) {
            arr3.push_back(arr1[i]);
            i++;
        } else {
            arr3.push_back(arr2[j]);
            j++;
        }
    }

 
    while (i < arr1.size()) {
        arr3.push_back(arr1[i]);
        i++;
    }


    while (j < arr2.size()) {
        arr3.push_back(arr2[j]);
        j++;
    }

    return arr3;
}


void timecomp(vector<int> arr1, vector<int> arr2)

{

for(int i=100;i<=1000000;i=i+1000)
{
    arr1=genlist(arr1,i);
    arr2=genlist(arr2,i);


auto start=high_resolution_clock :: now();

for(int j=1;j<=10;j++)
{
    mergelist(arr1,arr2);
}


auto stop=high_resolution_clock :: now();



auto duration = duration_cast<microseconds>(stop - start)/10;
float dur=duration.count();

cout<<i<<"    "<<dur<<endl;;



    

}

}

int main() {
    vector<int> arr1 ;
    vector<int> arr2 ;
   
timecomp(arr1,arr2);

    return 0;
}
