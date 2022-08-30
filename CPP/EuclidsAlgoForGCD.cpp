#include <bits/stdc++.h>
using namespace std;

int eugcd(int n1 , int n2){

    while(n2>0){
        int c = n1%n2;
        n1 = n2;
        n2 = c;
    }
    return n1 ;

}

int main(int argc, char const *argv[])
{
    cout<<eugcd(42,24);
    return 0;
}
