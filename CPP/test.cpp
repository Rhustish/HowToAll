#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t; scanf("%d",&t);
    while(t--){
        int n,maxDif = -1 ; scanf("%d",&n);
        vector<int> v(n);
        for(int i = 0 ; i < n ; i++) cin>>v[i];
        for(int i = 0 ; i < n-1 ;i++){
            if(v[i+1] > v[i]){
                maxDif = max(maxDif,v[i+1]-v[i]);
            }
        }
        if(maxDif == -1) cout<<"UNFIT"<<endl;
        else cout<<maxDif<<endl;

    }
    return 0;
}