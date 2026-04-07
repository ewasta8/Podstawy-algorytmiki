#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool comp(const vector<int>& a, const vector<int>& b)
{
    if(a[0]!=b[0])
        return a[0]<b[0];
    if(a[1]!=b[1])
        return a[1]<b[1];
    return a[2]<b[2];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t,x,y,z;
    vector <vector<int>>punkty;
    cin>>t;
    for(int i=0;i<t;i++){
        cin>>x>>y>>z;
        vector<int>pom{x,y,z};
        punkty.push_back(pom);
        sort(punkty.begin(), punkty.end(), comp);
    }
    for(int i=0;i<punkty.size();i++)
        cout<<punkty[i][0]<<' '<<punkty[i][1]<<' '<<punkty[i][2]<<'\n';
    return 0;
}
