#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t; cin>>t;
    while(t--){
        string a,b; cin>>a>>b;
        // cout<<a<<"  nnnn "<<b<<endl;
        // if(a == b) cout<<"lol";
        if(b.find(a) < b.length() || a==b){
            cout<<"YES"<<endl;
            continue;
        }
        cout<<"NO"<<endl;
    }
    return 0;
}

