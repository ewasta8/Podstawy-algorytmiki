#include <iostream>
#include <string>

using namespace std;

int main()
{
    double z,x,znak,n,l,y;
    string s;
    cin>>z;
    for(int i=0;i<z;i++){
        cin>>s;
        x=0;
        y=0;
        l=0;
        znak=1;
        for(int j=0;j<s.size();j++){
            if(s[j]=='='){
                l=1;
                j++;
                znak=1;
            }
            if(l==1){
                if(s[j]=='-'){
                    znak=-1;
                    j++;
                }
                if(s[j]=='+'){
                    znak=1;
                    j++;
                }
                if(s[j-1]<'0'||s[j-1]>'9')
                    n=0;
                if(s[j]>='0'&&s[j]<='9'){
                    n=n*10+(int)s[j]-48;
                    if((s[j+1]!='x'&&(s[j+1]<'0'||s[j+1]>'9'))||j==s.size()-1)
                        y+=n*znak;
                }
                if(s[j]=='x'){
                    if(s[j-1]<'0'||s[j-1]>'9')
                        n=1;
                    x+=n*znak*(-1);
                }
            }
            else{
                if(s[j]=='-'){
                    znak=-1;
                    j++;
                }
                if(s[j]=='+'){
                    znak=1;
                    j++;
                }
                if(s[j-1]<'0'||s[j-1]>'9'||j==0)
                    n=0;
                if(s[j]>='0'&&s[j]<='9'){
                    n=n*10+(int)s[j]-48;
                    if(s[j+1]!='x'&&(s[j+1]<'0'||s[j+1]>'9'))
                        y+=n*znak*(-1);
                }
                if(s[j]=='x'){
                    if((s[j-1]<'0'||s[j-1]>'9')||j==0)
                        n=1;
                    x+=n*znak;
                }
            }
        }
        if(x==0||l!=1||x==-0)
                cout<<"NO"<<endl;
            else{
                x=y/x;
                if(x==-0)
                    cout<<0<<endl;
                else
                    cout<<x<<endl;
            }
    }
    return 0;
}
