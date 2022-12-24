#include<iostream>
#include<cstring>
using namespace std;

// coding ninjas doc
// https://www.codingninjas.com/codestudio/guided-paths/basics-of-c/content/118817/offering/1381799

class Hero {
    
    private:
    int health;

    public:
    char level;
    char *name;
    static int timeToCompete;

    Hero(){
        cout << "Default Constructor called" << endl;
        name = new char[100];
    }

    // parameterised constructor
    Hero(int health){
        this -> health = health;
    }

    Hero(int health, char level){
        this -> health = health;
        this -> level = level;
    }

    // copy constructor
    Hero(Hero &temp){

        char *ch = new char[strlen(temp.name) + 1];
        strcpy(ch, temp.name);
        this -> name = ch;

        cout<<"Copy constructor called"<<endl;
        this -> health = temp.health;
        this -> level = temp.level;
    }

    void print(){
        cout << " Name : " << this->name << endl;
        cout << " health : " << this->health <<endl;
        cout << " level : " << this->level <<endl;
        cout << endl;
    }

    int getHealth() {
        return health;
    }

    char getLevel() {
        return level;
    }

    void setHealth(int h) {
        health = h;
    }

    void setLevel(char ch) {
        level = ch;
    } 

    void setName(char name[]){
        strcpy(this -> name, name);
    }

    static int random(){
       return timeToCompete ; 
    }

    // destructor
    ~Hero(){
        cout << "Destructor bhai called" << endl;
    }
    
};

int Hero :: timeToCompete = 5;

int main(){

    // cout << Hero :: timeToCompete << endl;
    cout << Hero :: random() << endl;

    // static
    // Hero a;

    // dynamic
    // Hero *b = new Hero();
    // manually destructor call
    // delete b;
    
    // Hero hero1;
    // hero1.setHealth(12);
    // hero1.setLevel('D');
    // char name[7] = "Babbar";
    // hero1.setName(name);

    // hero1.print();

    // use default copy constructor
    // Hero hero2(hero1);
    // hero2.print();
    
    // hero1.name[0] = 'G';
    // hero1.level = 'A';
    // hero1.print();
    // hero2.print();

    // hero1 = hero2;

    // hero1.print();
    // hero2.print();




/*  
    Hero S(20,'c');
    S.print();

    // copy constructor
    Hero R(S);
    R.print();

*/ 

/*

    // cout<<"size : "<< sizeof(a)<<endl;
    // Static allocation
    Hero a;
    a.setHealth(80);
    a.setLevel('B');
    cout<<"level is "<< a.level<<endl;
    cout<<"health is "<< a.getHealth()<<endl;

    // dynamically 
    Hero *b = new Hero;
    b->setLevel('A');
    b->setHealth(70);
    cout<<"level is "<< (*b).level<<endl;
    cout<<"health is "<< (*b).getHealth()<<endl;

    cout<<"level is "<< b->level<<endl;
    cout<<"health is "<< b->getHealth()<<endl;

*/

    return 0;
}