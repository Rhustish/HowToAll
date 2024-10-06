#include <bits/stdc++.h>
using namespace std;
#define loop(i,a,n) for(int i = a ; i < n ; i++)
#define loopr(i,a,n) for(int i = n ; i >= a ; i--)
#define pb push_back

using vi = vector<int>;
using vii = vector<vector<int>>;
using ll = long long;
using pi = pair<int,int>;

class Solution{
  public:
  
  void interimMain(){
    string s,t; cin>>s>>t;
     int j = 0;
    if(s == t){
      cout<<0;
      return;
    }
    if(s.length() < t.length()){
      cout<< s.length() + 1;
      return;
    }else if( s.length() > t.length()){
      cout<<t.length() + 1;
      return;
    }
    while(s[j] == t[j]){
      j++;
    }
    cout<<j;
  }

};

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  Solution obj;
  obj.interimMain();
  return 0;
}
