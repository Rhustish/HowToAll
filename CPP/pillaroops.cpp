#include<iostream>
using namespace std;
// operator overloading
// class A{
//     public:
//         int a;

//         A(int n){
//             this->a = n;
//         }

//         void printHello(){
//             cout<< "Jello"<<endl;
//         }

//         void operator+(A obj)   {
//             int n1 = this->a;
//             int n2 = obj.a;
//             cout<<n2-n1<<endl; 
//         }

//         void operator()(){
//             cout<<"bracket"<<endl;
//         }
// };


// int main()
// {
//     A o(10),p(15);
    
    

//     return 0;
// }

//runtime overloading

// class Animal{
//     public:
//         int age;
//         void ageGetter(){
//             cout<<this->age<<endl;
//         }
// };

// class Dog : public Animal{
//     public:
//         int dogage;
//         void ageGetter(){
//             cout<<this->dogage<<endl;
//         }
// };

// int main(){

//     Dog husky;
//     husky.age=100;
//     husky.dogage=10;
//     husky.ageGetter();

//     return 0;
// }

//POINTERS TO DERIVED CLASS

class BaseClass{
    public:
        int var_base;
        virtual void display(){
            cout<<"Base class virtual function"<<endl;
        }

};

class DerivedClass : public BaseClass{
    public:
        int var_der;
        void display()override{
            cout<<"Derived class child function"<<endl;
        }
};

int main(){

    BaseClass * baseclass_poiner;
    BaseClass obj1;
    DerivedClass obj2;
    baseclass_poiner = &obj2;


    return 0;
}