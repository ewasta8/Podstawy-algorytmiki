#include <iostream>
#include <algorithm>

using namespace std;

bool czy(int m, int *barn, int N, int C)
{
    int c=1,last=barn[0];
    for(int i=1;i<N;i++){
        if(barn[i]-last>=m){
            last=barn[i];
            c++;
            if(c>=C)
                return true;
        }
    }
    return false;
}

int szukaj(int r, int *barn, int N, int C)
{
    int l=1,odl;
    while(l<=r){
        int m=l+(r-l)/2;
        if(czy(m,barn,N,C)){
            odl=m;
            l=m+1;
        }
        else
            r=m-1;
    }
    return odl;
}

int main()
{
    int t, N, C, l=1, r,odl;
    cin>>t;
    for(int i=0;i<t;i++){
        cin>>N>>C;
        int barn[N];
        for(int j=0;j<N;j++){
            cin>>barn[j];
        }
        sort(barn,barn+N);
        r=barn[N-1]-barn[0];
        odl=szukaj(r,barn,N,C);
        cout<<odl<<endl;
    }
    return 0;
}
