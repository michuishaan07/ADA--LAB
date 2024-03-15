



#include<iostream>
#include<chrono>
#include<fstream>
#include<cstdlib>

using namespace std::chrono;
using std::ofstream;
using namespace std;






int pow(int x,int n)
{
int m=n;
int power=1;
int z=x;

while(m>0)
{

    if(m%2==0)
    {
        m=m/2;
        z=z*z;

    }
    else
    {

        
            power=power*z;
            m=m-1;
                    
    }
}

return power;

}

void timecomp()

{

for(int i=1;i<=1000000;i=i+5)
{
  


auto start=high_resolution_clock :: now();

for(int j=1;j<=10;j++)
{
   int ans= pow(2,i);
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

 

 timecomp();

 return 0;
}
