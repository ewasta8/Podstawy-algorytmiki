#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int z,n,maxp=0,p;
    cin>>z;
    for(int i=0;i<z;i++){
        cin>>n;
        vector <string> s(n);
        map<string, int> m;
        for(int j=0;j<n;j++){
            cin>>s[j];
            sort(s[j].begin(), s[j].end());
        }
        for(int j=0;j<n;j++)
            m[s[j]]++;
        for (auto a : m){
            if(a.second>maxp)
                maxp=a.second;
        }
        cout<<maxp<<'\n';
        maxp=0;
    }
    return 0;
}
