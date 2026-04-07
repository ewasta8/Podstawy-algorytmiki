#include <iostream>
#include <vector>

using namespace std;

long long merge(long long first, long long mid, long long last, long long tab[])
{
    long long licz=0,l=first,r=mid+1,res=0;
    vector <long long> pom(last-first+1);
    while(l<=mid && r<=last){
        if(tab[l]<=tab[r]){
            pom[res]=tab[l];
            ++res;
            ++l;
        }
        else{
            licz=licz+mid-l+1;
            pom[res]=tab[r];
            ++res;
            ++r;
        }
    }
    while(l<=mid){
        pom[res]=tab[l];
        ++res;
        ++l;
    }
    while(r<=last){
        pom[res] = tab[r];
        ++res;
        ++r;
    }
    for(long long i=0;i<res;++i)
        tab[first+i]=pom[i];
    return licz;
}

long long merge_sort(long long first, long long last, long long tab[])
{
    long long licz=0;
    if(first<last){
        long long mid=(first+last)/2;
        licz=merge_sort(first, mid, tab);
        licz+=merge_sort(mid+1, last, tab);
        licz+=merge(first, mid, last, tab);
    }
    return licz;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long t,n,licz=0;
    cin>>t;
    while(t--){
        cin>>n;
        long long A[200001];
        for(long long j=1;j<=n;j++){
            cin>>A[j];
        }
        licz=merge_sort(1,n,A);
        cout<<licz<<'\n';
    }
    return 0;
}
