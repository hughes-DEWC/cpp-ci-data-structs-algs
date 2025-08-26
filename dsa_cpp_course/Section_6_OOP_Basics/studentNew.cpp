#include <iostream>
#include "student.cpp"
using namespace std;

int main(){

    Student s1(10,100);
    cout<<"Adress of s1 "<<&s1<<endl;
    s1.display();

    Student s2(s1);                         // Copy construction
    cout<<"Copy constructor s2: "<<endl;
    s2.display();

    Student *s3 = new Student(20,200);
    cout<<"Adress of s3 "<<&s1<<endl;
    s3->display();

    Student s4(*s3);                        // Creating static copy of dynamic object
    Student *s5 = new Student(*s3);         // Creating dynamic copy of dynamic object
    Student *s6 = new Student(s1);          // Creating dynamic copy of static object

    Student s7(100,10);
    Student s8(200,20);
    Student *s9 = new Student(30,300);

    s8 = s7;                                // Copy assignment op
    *s9 = s8;
    s9->display();
    delete s3;                              // Calls the destructor for the dynamic object

    // Student s1;
    // Student *s2 = new Student;

    // s1.setAge(20);
    // s2->setAge(30);

    // s1.display();
    // s2->display();

    return 0;
}