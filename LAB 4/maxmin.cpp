#include<iostream>
#include<fstream>
#include<cstdlib>
#include<time.h>
using namespace std;
void WriteDataToFile(int i, double avgTime){
    ofstream fout("data.txt", ios::app);
    if(fout.is_open()){
        fout<<i<<","<<avgTime<<endl;
        fout.close();
    }
    else{
        cout<<"Unable to open file for writing data. "<<endl;
    }
}
void WriteToFile(int i, double avgTime){
    ofstream fout("data2.txt", ios::app);
    if(fout.is_open()){
        fout<<i<<","<<avgTime<<endl;
        fout.close();
    }
    else{
        cout<<"Unable to open file for writing data. "<<endl;
    }
}

void MaxMin(int* a, int low, int high){
    int max, min,mid,max1,min1;
    if(low ==high){
        max=a[low];
        min=a[low];
    }
    else{
        mid=(low+high)/2;
        MaxMin(a,low, mid);
    }
    if(low ==high){
        max1=a[low];
        min1=a[low];
    }
    else{
        mid=(low+high)/2;
        MaxMin(a,mid+1,high);
    }
    if(max<max1){
        max=max1;
    }
    if(min>min1){
        min=min1;
    }
    cout<<"Max el  :"<<max<<" Min el :n"<<min<<endl;
}
int main(){
    double avgtime,time1,time2;
    for(int i=100;i<100000;i=i*100){
        int *a = new int [i];
        for(int j=0;j<i;j++){
            a[j]=rand();
        }
        time1 =(double)clock();
        for(int k=0;k<10;k++){
            MaxMin(a,1,i);
        }
        time2=(double)clock();
        avgtime=(double)(time2-time1)/10;
        cout << avgtime<< " ";
        WriteDataToFile(i,(avgtime));
    }
  
    return 0;
}
