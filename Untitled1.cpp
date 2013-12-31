#include<iostream>
#include <malloc.h>
using namespace std;
int main()
{
    int *L = (int *)malloc(10001*10001*sizeof(int));
    int N,P,C[10001];
    cin>>N;cin>>P;
    int i,j,k;
    for(i=0;i<N;i++)
    {
        cin>>C[i];
    }
    for(i=1;i<=N;i++)
    {
        for(j=1;j<=N;j++)
        {
            if(i==j) L[(i-1)*N+j-1]=0;
            else L[(i-1)*N+j-1]=999999;
        }
    }
    int x,y,z;
    for(i=0;i<P-1;i++)
    {
        cin>>x;cin>>y;cin>>z;
        L[(x-1)*N+y-1]=z+C[y-1];//cout<<(x-1)*N+y-1<<" "<<L[(x-1)*N+y-1]<<endl;
        L[(y-1)*N+x-1]=z+C[x-1];//cout<<(y-1)*N+x-1<<" "<<L[(y-1)*N+x-1]<<endl;
    }
    for(i=1;i<=N;i++)
    {
        for(j=1;j<=N;j++)
        {
            cout<<L[(i-1)*N+j-1]<<" ";
        }
        cout<<endl;
    }
    for(i=1;i<=N;i++)
    {
        for(j=1;j<=N;j++)
        {
            for(k=1;k<=N;k++)
            {
                if((L[(j-1)*N+i-1]+L[(i-1)*N+k-1])<L[(j-1)*N+k-1]) L[(j-1)*N+k-1]=L[(j-1)*N+i-1]+L[(i-1)*N+k-1];
            }
        }
    }
    for(i=1;i<=N;i++)
    {
        for(j=1;j<=N;j++)
        {
            cout<<L[(i-1)*N+j-1]<<" ";
        }
        cout<<endl;
    }
    int min=999999999;


    return 0;
}
