#include <iostream>

using namespace std;

int main()
{
    int t;
    long int a,b;
    cin>>t;
    for(int i=0;i<t;i++){
        cin>>a>>b;
        while(a!=b){
            if(a>b)
                a-=b;
            else
                b-=a;
        }
        cout<<a<<endl;
    }
    return 0;
}
