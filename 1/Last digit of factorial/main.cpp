#include <iostream>

using namespace std;

int l(int n)
{
    int k=n;
    unsigned long p=1;
    for(int i=0;i<k;i++){
        p=(p*n);
        while(p%10==0)
            p/=10;
        p=p%1000000;
        n-=1;
    }
    return p%10;
}

int main()
{
    int t,n;
    cin>>t;
    for(int i=0;i<t;i++){
        cin>>n;
        cout<<l(n)<<endl;
    }
    return 0;
}
