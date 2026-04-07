#include <iostream>
#include <vector>

using namespace std;

int unboundedKnapsack(int k, vector<int> arr)
{
    int maxsum=0;
    vector<int>sum(k+1,0);
    //vector<int>poprz(k+1,0);
    for(int i=0;i<arr.size();i++){
        for(int j=arr[i];j<=k;j++){
            if(sum[j-arr[i]]+arr[i]<=j && sum[j-arr[i]]+arr[i]>sum[j])
                sum[j]=sum[j-arr[i]]+arr[i];
            if(sum[j]==k)
                return sum[j];
            if(sum[j]>maxsum)
                maxsum=sum[j];
        }
    }
    return maxsum;
}

int main()
{
    int t,n,k;
    cin>>t;
    for(int i=0;i<t;i++){
        cin>>n>>k;
        vector<int>arr(n);
        for(int j=0;j<n;j++){
        cin>>arr[j];
        }
        cout<<unboundedKnapsack(k,arr)<<'\n';
    }
    return 0;
}
