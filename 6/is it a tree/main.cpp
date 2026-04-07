#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main()
{
    int n,m,u,v;
    cin>>n>>m;
    if(m!=n-1)
        cout<<"NO";
    else{
        vector <vector<int>>a(n);
        for(int i=0;i<m;i++){
            cin>>u>>v;
            a[u-1].push_back(v-1);
            a[v-1].push_back(u-1);
        }
        vector<bool> visited(n, 0);
        stack<int>s;
        s.push(0);
        visited[0]=1;
        while(!s.empty()){
            int x=s.top();
            s.pop();
            for(int j=0;j<a[x].size();j++){
                if(visited[a[x][j]]==0){
                    visited[a[x][j]]=1;
                    s.push(a[x][j]);
                }
            }
        }
        for(int i=0;i<n;i++){
            if(visited[i]==0){
                cout<<"NO";
                return 0;
            }
        }
        cout<<"YES";
    }
    return 0;
}
