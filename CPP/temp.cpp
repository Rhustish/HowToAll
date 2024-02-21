//len    1 2 3 4 
//pro    1 5 8 9
#include <bits/stdc++.h>
using namespace std;


int solve(int x,vector<int> &dp){
    if(x < 0) return -10000;
    if(dp[x]!=-1) return dp[x];
    dp[x] = max((solve(x-1,dp)+2),max((solve(x-2,dp)+5),max((solve(x-3,dp)+8),(solve(x-4,dp)+9))));
    return dp[x];
}


int main (){

    vector<int> dp(10000,-1); 
    // for(auto i:dp)cout<<i;
    

    return 0;
}