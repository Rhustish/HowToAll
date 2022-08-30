#include<iostream>
#include<vector>
using namespace std;

int twoKiPower(int n){

    //base case
    if(!n){
        return 1;
    }

    return 2*twoKiPower(n-1);

}

int factorial(int n){
    //base case
    if(n <= 0){return 1;}

    return n*factorial(n-1);

}

void printreversecounting(int n){  // this is tail recursion
    //base 
    if(!n){cout<<0; return;}
    cout<<n<<endl;
    printreversecounting(n-1);
}

void printcounting(int n){    // this is head recursion
    //base
    if(!n){cout<<0<<endl; return;}
    printcounting(n-1);
    cout<<n<<endl;  
}

int fibonacci(int n){
    //base
    if(n == 1){return 0;}
    else if(n == 2){return 1;}

    return fibonacci(n-1) + fibonacci(n-2);

 }

int numberofwaystoclimbstairs(int n){ // problem problem
    // Question : There are n number of stairs, you can take 1 or 2 steps at a  time, return the total possible number of ways to climb the staircase
    //base
    if (n==0){return 1;} else if(n<0){return 0;}
    
    //processing and recursive call
    return numberofwaystoclimbstairs(n-1) + numberofwaystoclimbstairs(n-2);
}

void saydigits (int n){
    //pre processing
    string arr[10] = {"zero","one","two","three","four","five","six","seven","eight","nine"};

    //base
    if(n<1){
        return;
    }

    //r-call
    saydigits(n/10);

    //processing
    cout<<arr[n%10]<<" ";

}

bool isSorted(int arr[], int n){
    //base
    if(!n || n == 1){return 1;}
    
    if(arr[0]>arr[1]){
        return 0;
    }

    return isSorted(arr+1,n-1);
}

int sumOfArray(int arr[], int n){
    if (n-1<0){return 0;}
    return arr[n-1] + sumOfArray(arr, n-1);
}

int linearSearch(int arr[] , int n , int key, int &idx){
    if(n<=0){return -1;}

    if(arr[0] == key){return idx;}

    idx++;
    return linearSearch(arr+1,n-1,key,idx);

}

int binarySearch(int arr[] ,int s, int e , int key){
    if(s>e){return -1;}

    int mid = (s+e)/2;

    if (arr[mid] == key)    { return mid;}
    else if(arr[mid] > key) {return binarySearch(arr,s,mid-1,key);}
    else if(arr[mid] < key) {return binarySearch(arr,mid+1,e,key);}
    return -1; // remove this for it to work
}

string reversestring(string& str, int i , int j){
    if(i > j){return "" ;}
    
    char temp = str[i];
    str[i] = str[j];
    str[j] = temp;

    reversestring(str,i+1, j-1);
    
    return str;
}

bool checkpalindrome(string& str , int i , int j){
    if(i>j){return 1;}

    if(str[i] != str[j]){return 0;}

    checkpalindrome(str,i+1,j-1);

    return 1; //remove this for it to work
}

int atothepowerb(int a, int b){
    if(b == 1){return a;}/*base case*/else if(!b){return 1;}

    return a*atothepowerb(a,b-1);
}

void bubblesort(int arr[], int n ){
    if(n<=1){return;}

    for (size_t i = 0; i < n-1; i++){
        if (arr[i]>arr[i+1]){
            swap(arr[i],arr[i+1]);
        }
    }
    
    bubblesort(arr,n-1);


    
}

void stringsubsets(string str, int idx , string a[]){
    if(idx >= str.length()) { return;}

    //exclude 
    stringsubsets(str,idx+1,a);
    
    //include
    a->push_back(str[idx]);
    stringsubsets(str,idx+1,a);
}

void powerset(vector<int> nums,vector<vector<int>> & final_answer, vector<int> output, int idx){
    if(idx >= nums.size()){
        final_answer.push_back(output);
        return ;
    }
    //exclude
    powerset(nums,final_answer,output,idx+1);

    //include
    int element = nums[idx];
    output.push_back(element);
    powerset(nums,final_answer,output,idx+1);
}

void phoneKeypad(string map[] , string output , int idx , string digits, vector<string>& answer ){

    if(!digits.length()) return;

    if(idx >= digits.length()){
        answer.push_back(output);\
        return;
    }
    
    int currnum = digits[idx]-'0';
    string value = map[currnum];

    for(char a : value){
        output.push_back(a);
        phoneKeypad(map,output,idx+1,digits,answer);
        output.pop_back();
    }


}

void permutationsOfString(string& str, vector<string> &ans , int idx){ //important
    //base case
    if(idx >= str.length()){
        ans.push_back(str); 
        return ;
    }
    for(int j = idx ; j < str.length() ; j++){
        swap(str[idx],str[j]);
        permutationsOfString(str,ans,idx+1);
        //backtrack
        swap(str[idx],str[j]);
    }

}



int main()
{
    
    return 0;
}