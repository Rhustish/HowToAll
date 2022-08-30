#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    int n,m;
    cin>>n>>m;

    int arr[n][m];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin>>arr[i][j];
        }
        
    }
    //Spiral Travelsal

    int rstart = 0 ,cstart = 0 , rend = n-1 , cend = m-1 ;

    while (rstart <= rend && cstart <= cend)
    {   
        //for rowstart
        for(int col = cstart ; col<=cend ; col++){
            cout<<arr[rstart][col] <<" ";
        }
        rstart++;

        //for column end
        
        for (int row = rstart; row <= rend; row++)
        {
            cout<< arr[row][cend] <<" ";
        }
        cend--;

        //for row end
        for (int col = cend; col >= cstart ; col--)
        {
            cout<<arr[rend][col]<< " ";   
        }
        rend--;

        //for column start

        for (int row = rend; row >= rstart; row--)
        {
            cout<<arr[row][cstart] << " ";
        }
        cstart++;
    }
    

    return 0;
}
