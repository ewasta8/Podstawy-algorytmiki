#include <iostream>
#include <set>
#include <algorithm>
#include <ios>

using namespace std;

int main()
{
    int n,k,b,s=0;
    multiset<int>v;
    multiset<int> :: iterator mini,maxi;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>k;
        for(int j=0;j<k;j++){
            cin>>b;
            v.insert(b);
        }
        mini=v.begin();
        maxi=v.end();
        maxi--;
        s+=(*maxi - *mini);
        v.erase(mini);
        v.erase(maxi);
    }
    cout<<s;
    return 0;
}
