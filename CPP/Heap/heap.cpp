#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main()
{
    vector<vector<int>> a = {
        {0,1,1},
        {1,1,1},
        {0,0,1}
    };
    sort(a.begin() , a.end());

    for(auto i : a){
        for(auto j : i){
            cout<<j<<" ";
        }
        cout<<endl;
    }


    return 0;
}