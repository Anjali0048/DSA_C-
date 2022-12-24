// if one thing exist in different forms
// compile time poly. (static)
    // function overloading
    // operator overloading;
// run time poly. (dynamic)

#include<iostream>
using namespace std;

// function overloading
class A {
    public :
        void func() {
            cout << "1st" <<endl;
        }

        void func(int a) {
            cout << "2nd " << endl; 
        }
};

// operator overlading
class B {
    public :
        int a,b ;
    
    public :
        int add(){
            return a+b;
        }
    void operator+ (B &obj) {
        int val1 = this -> a;
        int val2 = obj.a;
        cout << "output : " << val2 - val1 << endl;
    }

    void operator() (){
        cout << "brackets "<< this->a <<endl;
    }
};

// run time polymorphism
// function overriding
class Animal {
    public :
        void speak(){
            cout<<"speaking"<<endl;
        }
};

class Dog : public Animal {
    public :
        void speak(){
            cout<<"Barking"<<endl;
        }
};

int main(){

    A obj;
    obj.func(3);
    
    B obj1, obj2;
    obj1.a = 4;
    obj2.a = 7;

    obj1 + obj2;
    obj1();

    Dog object;
    object.speak();
    return 0;
}