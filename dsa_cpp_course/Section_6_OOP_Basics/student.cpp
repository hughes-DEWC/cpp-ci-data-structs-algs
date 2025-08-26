#include<iostream>
using namespace std;

class Student{       

    int age;

    public :

        /// Destructor (deallocates memory)
        ~Student(){
            cout<<"Destructor called"<<endl;
        }

        /// Default constructor
        Student(){
            cout<<"Constrcutor called"<<endl;
        }

        /// Parameterised constructor
        Student(int roll){
            cout<<"Constructor 2 called"<<endl;
            this->roll = roll;                      // mandatory to use this to diff between the property roll and parameter roll
        }
        Student(int a, int r){
            cout<<"this "<<this<<endl;
            cout<<"Constructor 3 called"<<endl;
            roll = r;                               // this->age = a;  optional (this contains address)
            age = a;                                // this->roll = r; optional
        }

        int roll;

        void display(){
            cout<<age<<" "<<roll<<endl;
        }

        int getAge(){
            return age;
        }
        void setAge(int a){
            age = a;
        }

};