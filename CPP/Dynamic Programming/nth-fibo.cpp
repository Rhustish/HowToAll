#include<bits/stdc++.h>
using namespace std;


//space optimization in bottom up----------------------------->
int main(){
    int n; cin>>n;

    if(n == 0) return 0;
    
    int prev1 = 1,prev2=0;

    for(int i = 2 ; i <= n ; i++){
        int curr = prev1 + prev2;
        prev2 = prev1;
        prev1 = curr;
    }
    cout<< prev1 <<endl;
    return 0;
}



//bottom up(tabulation)---------------------------------------->
int fib_bu(int n , vector<int> &dp){
    for(int i = 2 ; i <= n ; i++){
        dp[i] = dp[i-1]+dp[i-2];
    }
    return dp[n];
}

int main()
{
    int n; cin>>n;

    //step 1
    vector<int> dp(n+1);
        dp[0] = 0; dp[1] = 1; 
    for( int i : dp) i = -1;
    cout<<fib_td(n,dp)<<endl;
    return 0;
}

//top-down (recursion + memoization) -------------------------->

int fib_td(int n, vector<int> &dp){
    if(n<=1) return n;

    //step 3
    if(dp[n] != -1) return dp[n];

    //step 2
    dp[n] = fib_td(n-1,dp) + fib_td(n-2,dp);

    return dp[n];
}

int main()
{
    int n; cin>>n;

    //step 1
    vector<int> dp(n+1);

    for( int i : dp) i = -1;
    cout<<fib_td(n,dp)<<endl;
    return 0;
}