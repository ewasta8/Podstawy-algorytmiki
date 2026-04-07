#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n,m;
    cin>>n>>m;
    vector <int>a(n);
    vector <int>b(m);
    vector <vector<int>>v(n);
    for(int i=0;i<n;i++)
        cin>>a[i];
    for(int i=0;i<m;i++)
        cin>>b[i];
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(i==0){
                if(b[i]==a[j])
                    v[j].push_back(b[i]);
                else if(j!=0)
                    v[j]=v[j-1];
            }
            else{
                if(j==0){
                    if(b[i]==a[j]){
                        v[j].clear();
                        v[j].push_back(b[i]);
                    }
                }
                else{
                    if(b[i]==a[j]){
                        v[j]=v[j-1];
                        v[j].push_back(b[i]);
                    }
                    else if(v[j].size()>v[j-1].size());//else if(v[j].size()>=v[j-1].size());
                    else
                        v[j]=v[j-1];
                }
            }
        }
    }
    for(int i=0;i<v[n-1].size();i++)
        cout<<v[n-1][i]<<' ';
    return 0;
}
