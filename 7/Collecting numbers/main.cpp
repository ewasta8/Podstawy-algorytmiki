#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n,x;
    cin>>n;
    vector <vector<int>> v(n,vector<int>(n,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>x;
            v[i][j]=x;
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i==0||j==0){
                if(i==0&&j!=0)
                    v[i][j]+=v[i][j-1];
                if(j==0&&i!=0)
                    v[i][j]+=v[i-1][j];
            }
            else{
                if(v[i][j-1]>=v[i-1][j])
                    v[i][j]+=v[i][j-1];
                else
                    v[i][j]+=v[i-1][j];
            }
        }
    }
    cout<<v[n-1][n-1];
    return 0;
}
