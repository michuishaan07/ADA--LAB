#include<iostream>
#include<vector>
using namespace std;

void sumofsubset(int i,vector<int>set,vector<int>subset,int targetsum,int n)
{
if(targetsum==0)
{

    for(int i=0;i<subset.size();i++)
    {
  
        cout <<subset[i];
        cout<<endl;
      
    }
}

if(i==n)
{
    return ;
}

if(set[i]<=targetsum)
{

subset.push_back(set[i]);


 sumofsubset(i+1,set,subset,targetsum-set[i],n);

subset.pop_back();

}



}

int main()
{
 vector<int>set={2,3,5};
 vector<int>subset;
 int targetsum=5;
 int n=set.size();

sumofsubset(0,set,subset,targetsum,n);



return 0;
}
