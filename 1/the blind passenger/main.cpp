#include <iostream>

using namespace std;

int main() {
    int x,n,row_number;
    char seat_position,direction;
    cin>>x;
    for(int i=0;i<x;i++){
        cin>>n;
        if(n==1)
            cout<<"poor conductor"<<endl;
        else{
            switch(n%10){
            case 0: row_number=(n/10)*2;seat_position='A';direction='L';break;
            case 1: row_number=(n/10)*2;seat_position='W';direction='L';break;
            case 2: row_number=(n/10)*2+1;seat_position='W';direction='L';break;
            case 3: row_number=(n/10)*2+1;seat_position='A';direction='L';break;
            case 4: row_number=(n/10)*2+1;seat_position='A';direction='R';break;
            case 5: row_number=(n/10)*2+1;seat_position='M';direction='R';break;
            case 6: row_number=(n/10)*2+1;seat_position='W';direction='R';break;
            case 7: row_number=(n/10)*2+2;seat_position='W';direction='R';break;
            case 8: row_number=(n/10)*2+2;seat_position='M';direction='R';break;
            case 9: row_number=(n/10)*2+2;seat_position='A';direction='R';break;
            }

            cout<<row_number<<' '<<seat_position<<' '<<direction<<endl;
        }
    }
    return 0;
}
