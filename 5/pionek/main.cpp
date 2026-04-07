#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n,x;
    cin>>n;
    vector <int> p(n);
    vector <int> s(6);
    for(int i=0;i<n;i++){
        cin>>p[i];
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<6 && j<n-i-1;j++){
            if(i==0)
                s[j]=p[i]+p[i+j+1];
            else if(n-i>=6 && j==5)
                s[j]=x+p[i+j+1];
            else
                s[j]=max(x+p[i+j+1],s[j+1]);
        }
        x=s[0];
    }
    cout<<s[0];
    return 0;
}
