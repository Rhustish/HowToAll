#include <iostream>
using namespace std;

int sieve(int n){

    int prime[100] = {0};

    for (int i = 2; i <= n ; i++)
    {
        if(prime[i] == 0){
            for (int j = i*i; j < n; j+=i)
            {
                prime[j] = i;
            }  
        }
    }

    for (int i = 2; i < n; i++)
    {
        if(prime[i] == 0){
            cout<<i<<endl;
        }
    }
    



}

int main(int argc, char const *argv[])
{
    int n;
    cin>>n;

    sieve(n);

    return 0;
}
