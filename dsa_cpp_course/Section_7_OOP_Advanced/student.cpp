#include<iostream>
#include<string.h>
using namespace std;

class Student{
    int age;

    public:
        char *name;

        Student(Student const &s){
            this->age = s.age;
            // this->name = s.name;           /// shallow copy
            
            // deep copy
            this->name = new char[strlen(s.name)+1];
            strcpy(this->name, s.name);
        }

        Student(int age, char *name){
            this->age = age;
            // this->name = name;          /// this is a shallow copy (copy of only the address of the array)
            
            // deep copy
            this->name = new char[strlen(name)+1];
            strcpy(this->name,name);
        }
        void display(){
            cout<<name<<" "<<age<<endl;
        }
};

int main(){
    char name[]= "abcd";
    Student s1(20,name);
    s1.display();

    name[3] = 'e';
    Student s2(30,name);
    s2.display();

    s1.display();

    return 0;
}