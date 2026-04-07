#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    long int n,k,x,y,stacja;
    cin>>t;
    for(int i=0;i<t;i++){
        cin>>n>>k;
        vector<long int> stacje(n,0);
        for(long int j=0;j<k;j++){
            cin>>x>>y;
            stacje[x]++;
            stacje[y]--;
        }
        long int osoby=0,maxo=0,stacja=0;
        for(long int j=0;j<n;j++){
            osoby+=stacje[j];
            if(osoby>maxo){
                maxo=osoby;
                stacja=j;
            }
        }
        cout<<stacja<<' '<<maxo<<endl;
    }
    return 0;
}
