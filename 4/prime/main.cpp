#include <iostream>

using namespace std;

bool czy_pierwsza(int n)
{
    if(n==2)
        return true;
    if(n<2)
        return false;
    for(int i=2;i*i<=n;i++){
        if(n%i==0)
            return false;
    }
    return true;
}

int main()
{
    int n,x;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>x;
        if(czy_pierwsza(x))
            cout<<"TAK\n";
        else
            cout<<"NIE\n";
    }
    return 0;
}
