#include <iostream>
#include <vector>

using namespace std;

int Hash(string key)
{
    int h=0;
    for(int i=0;i<key.size();i++){
        h+=int(key[i])*(i+1);
    }
    return (19*h)%101;
}

bool add(vector <string>&mapa,string key)
{
    int h=Hash(key);
    if(mapa[h]==key)
        return 0;
    for(int i=1;i<20;i++){
        int nh=(h+i*i+23*i)%101;
        if(mapa[nh]==key)
            return 0;
    }
    if(mapa[h]==""){
        mapa[h]=key;
        return 1;
    }
    for(int i=1; i<20; i++){
        int nh=(h+i*i+23*i)%101;
        if(mapa[nh]==""){
            mapa[nh]=key;
            return true;
        }
    }
    return 0;
}

bool del(vector <string>&mapa,string key)
{
    for(int i=1;i<101;i++){
        if(mapa[i]==key){
            mapa[i]="";
            return 1;
        }
    }
    return 0;
}

int main()
{
    int t,n;
    string o,key;
    cin>>t;
    for(int i=0;i<t;i++){
        vector <string> mapa(101,"");
        int licz=0;
        cin>>n;
        for(int j=0;j<n;j++){
            cin>>o;
            if(o.substr(0,3)=="ADD"){
                key=o.substr(4);
                if(add(mapa,key))
                    licz++;
            }
            else if(o.substr(0,3)=="DEL"){
                key=o.substr(4);
                if(del(mapa,key))
                    licz--;
            }
        }
        cout<<licz<<'\n';
        for(int j=0;j<101;j++){
            if(mapa[j]!="")
                cout<<j<<":"<<mapa[j]<<'\n';
        }
    }
    return 0;
}
