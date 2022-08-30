#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{

    int n; cin>>n; bool p = 1;

    char arr[n+1]; cin>>arr;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] != arr[n-1-i])
        {
            p = 0;
            break;
        }
        
    }

    p == 1 ? cout<<"palindrome":cout<<"not so palindrome";
    


    

    return 0;
}