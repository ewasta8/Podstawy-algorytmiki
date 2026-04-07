#include <iostream>

using namespace std;

int main()
{
    int n,k,q,d,sum;
    cin>>n>>k>>q;
    int dp[725][725];
    for(int i=0;i<=k;i++)
        dp[0][i]=1;
    for(int i=1;i<=n;i++){
        sum=0;
        for(int j=0;j<=k;j++){
            if(j==0)
                dp[i][j]=dp[i-1][j]+dp[i-1][j+1];
            else if(j==k)
                dp[i][j]=dp[i-1][j-1]+dp[i-1][j];
            else
                dp[i][j]=dp[i-1][j-1]+dp[i-1][j]+dp[i-1][j+1];
            dp[i][j] %= q;
            sum+=dp[i][j];
            sum %= q;
        }
        dp[i][k+1]=sum;
    }
    for(int i=0;i<n;i++){
        cin>>d;
        cout<<dp[d-1][k+1]<<' ';
    }
    return 0;
}
