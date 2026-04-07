#include <iostream>
#include <vector>
#include <string.h>

using namespace std;

int main()
{
    char s,pom;
    int comment1=0,comment2=0,nawias=0,esc=0;
    while(cin.get(s)){
        if(comment1==1){
            if(s=='\n'){
                if(pom!='\''){
                    comment1=0;
                    cout<<s;
                }
            }
        }
        else if(comment2==1){
            if(s=='*'){
                if(cin.get(s)){
                    if(s=='/')
                        comment2=0;
                }
            }
        }
        else{
            if(nawias==0){
                if(s=='"')
                    nawias=1;
                if(s=='/'){
                    pom=s;
                    if(cin.get(s)){
                        if(s=='/')
                            comment1=1;
                        else if(s=='*')
                            comment2=1;
                        else
                            cout<<pom<<s;
                    }
                }
                else
                    cout<<s;
            }
            else{
                if(s=='"' && esc==0)
                    nawias=0;
                if(s=='\\' && esc==0)
                    esc=1;
                else if(esc==1)
                    esc=0;
                cout<<s;
            }
        }
        pom=s;
    }
    return 0;
}
