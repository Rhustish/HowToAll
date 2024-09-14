#include<bits/stdc++.h>
using namespace std;

int findWildcardMin(vector<string> &vec){
    
    vector<char> v(vec[0].length() , '.');

    for(string &s : vec){
        for(int i = 0 ; i < s.length();i++){
            if(s[i] == '?') continue;
            if(v[i] == '.'){
                v[i] = s[i];
                continue;
            }
            if(v[i]!='?'&& v[i]!=s[i] ) v[i] = '?';
        }
    }
    int count = 0;
    for(char i : v) cout<<i<<" ";
    // for(char &i:v) if(i=='?') count ++;
    return count;
}

int main()
{
    vector<string> temp = {
        "ha?????ank",
        "?a?ker?ank"
    };
    cout << findWildcardMin(temp);
    return 0;
}