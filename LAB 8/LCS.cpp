
#include<iostream>
#include<string>
using namespace std;



int LCS(string S1,string S2,int m,int n)
{

    int L[m+1][n+1];
 for (int i = 0; i <= m; i++) { 
        for (int j = 0; j <= n; j++) { 
            if (i == 0 || j == 0) 
                L[i][j] = 0; 
  
            else if (S1[i - 1] == S2[j - 1]) 
                L[i][j] = L[i - 1][j - 1] + 1; 
  
            else
                L[i][j] = max(L[i - 1][j], L[i][j - 1]); 
        } 
    } 
  
   
    return L[m][n]; 
}
int main()
{

string S1="COMPUTER";
string S2="REGISTER";


int m=S1.size();
int n=S2.size();

int ans=LCS(S1,S2,m,n);

cout<<"THE LENGTH OF LCS IS "<<ans<<endl;


return 0;
}
