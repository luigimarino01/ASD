#include <iostream>
#include <string.h>
using namespace std;

class AbstractEmployee{
    virtual void AskForPromotion()=0;
};


class Employee:AbstractEmployee{

private:
    string Company;
    int Age;

    protected:
    string Name;

public:
    void AskForPromotion(){
        if (Age>30)
        cout<<Name << " got promoted." <<endl;
        else
        cout<<Name<<", no promotion for you."<< endl;  
        
    }
    void setName(string name){
        Name = name;
    }
    string getName(){return Name;}
    void setCompany(string company){
        Company = company;
    }
    string getCompany(){return Company;}
    void setAge(int age){
        if (age >=18)
        Age = age;
    }
    int getAge(){return Age;}
    Employee(string n, string c, int a){
        Name = n;
        Company = c;
        Age = a;
    }
    void IntroduceYourSelf(){
        cout<<"Hello, my name is " << Name <<endl;
        cout <<"I'm working for " << Company << endl;
        cout <<"My age is " << Age << endl; 
        cout << endl;
    }
   virtual  void Work(){
        cout<<Name<<" is checking email, task backlog, performing tasks..."<<endl;
    }
};


class Developer:public Employee{
public:
    string favouriteLanguage;
    Developer(string n, string c, int a, string FavLan)
    :Employee(n, c, a)
    {
        favouriteLanguage = FavLan;
    }
    void fixBug(){
        cout << Name << " fixed bug using "<< favouriteLanguage << endl;
    }
    void Work(){
        cout << Name <<" is writing " << favouriteLanguage <<" code."<<endl;
    }
};


class Teacher:public Employee{
public:
    string Subject;
    void prepareLesson(){
        cout<<Name<<" is preparing " <<Subject <<" lesson." << endl;
    }
    Teacher(string n, string c, int a, string sub)
    :Employee(n, c, a){
        Subject = sub;
    }
    void Work(){
        cout << Name <<" is teaching " << Subject <<"."<<endl;
    }
    };

int main(){

Developer dev = Developer("Luigi", "PMC", 20, "C++");
Teacher t = Teacher("Nunzia", "School", 50, "English");

Employee* e = &dev;
Employee* e2 = &t;

e->Work();
e2->Work();









}