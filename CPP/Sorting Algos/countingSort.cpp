#include<bits/stdc++.h>
using namespace std;

vector<int> countSort(vector<int> nums){
    vector<int> ans;
    int maxi = INT_MIN;
    for(int i : nums){
        maxi = max(maxi,i);
    }

    int c[maxi+1] = {0};

    for(int i : nums){
        c[i]++;
    }


    for(int i = 0 ; i < maxi+1 ; i++){
        int p = c[i];
        while(p--){
            ans.push_back(i);
        }
    }
    return ans;
}


int main()
{
    vector<int> a = {2,3,4,5,3,3,54,5,6,6,7,67,5,4,3};
    vector<int> sorted = countSort(a);
    for(auto i : sorted){
        cout<< i << " ";
    }   
    return 0;
}