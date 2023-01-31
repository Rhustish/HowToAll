#include<bits/stdc++.h>
using namespace std;

pair<double,double> helper( double a , double b , double c){
    double determinant, root1, root2, real, imag;
    
    determinant = b*b - 4*a*c;
    
    if(determinant >= 0) {
        root1= (-b + sqrt(determinant))/(2 * a);
        root2= (-b - sqrt(determinant))/(2 * a);
        
    } 
    return make_pair(root1,root2);
}


double answer(double x , double  l , double b){
    // cout<<"Ye x h"<<x<<endl;
    return(l-2*x)*(b-2*x)*x;
}

int main()
{
    int t; cin>>t;
    while(t--){
        double w,l; cin>>l>>w;
        double a = 12, b = -4*(w+l), c = w*l;
        pair <double, double> roots = helper(a,b,c);
        double r1ul,r2ul,r1ll,r2ll , selected;
        r1ul = a*(roots.first + 0.1)*(roots.first + 0.1) + b*(roots.first + 0.1) + c;
        r1ll = a*(roots.first - 0.1)*(roots.first - 0.1) + b*(roots.first - 0.1) + c;
        r2ll = a*(roots.second - 0.1)*(roots.second - 0.1) + b*(roots.second - 0.1) + c;
        r2ul = a*(roots.second + 0.1)*(roots.second + 0.1) + b*(roots.second + 0.1) + c;
        
        if(r2ul < r2ll) {
            selected = roots.second;
        }else{
            selected = roots.first;
        }
        cout<<setprecision(10)<<answer(selected , l , w)<<endl;
    }
    return 0;
}