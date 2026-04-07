#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'abbreviation' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts following parameters:
 *  1. STRING a
 *  2. STRING b
 */

string abbreviation(string a, string b) 
{
    vector<bool>v(b.size()+1);
    vector<bool>poprz(b.size()+1,0);
    poprz[0]=1;
    for(int i=1;i<=a.size();i++){
        if(a[i-1]>=97 && a[i-1]<=122)
            v[0]=1;
        else
            v[0]=0;
        for(int j=1;j<=b.size();j++){
            if(a[i-1]==b[j-1])
                v[j]=poprz[j-1];
            else if(a[i-1]-32==b[j-1])
                v[j]=(poprz[j-1] || poprz[j]);
            else if(a[i-1]>=65 && a[i-1]<=90)
                v[j]=0;
            else
                v[j]=v[j];
        }
        poprz=v;
    }
    if(v[b.size()])
        return "YES";
    return "NO";
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string q_temp;
    getline(cin, q_temp);

    int q = stoi(ltrim(rtrim(q_temp)));

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string a;
        getline(cin, a);

        string b;
        getline(cin, b);

        string result = abbreviation(a, b);

        fout << result << "\n";
    }

    fout.close();
    
    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}
