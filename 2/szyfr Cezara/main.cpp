#include <iostream>

using namespace std;

int main()
{
    string tekst;
    while(getline(cin, tekst)){
        for(int i=0;i<tekst.size();i++){
            if(tekst[i]==' ')
                cout<<' ';
            else{
                if(tekst[i]>='X')
                    cout<<(char)(tekst[i]-23);
                else
                    cout<<(char)(tekst[i]+3);
            }
        }
        cout<<endl;
    }
    return 0;
}
