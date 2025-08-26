#include<iostream>
#include "student.cpp"
using namespace std;

int main(){
    
    // Static object
    Student s1,s2;

    // Dynamic object
    Student *s3 = new Student;

    // Setting property values
    // s1.age = 24;
    s1.roll = 100;
    // cout<<s1.age<<endl;
    // cout<<s1.roll<<endl;
    s1.setAge(21);

    // (*s3).age = 23;
    (*s3).roll = 50;            // dereference operator
    // shortcut to above
    // s3->age = 23;
    s3->roll = 50;
    // cout<<(*s3).age<<endl;
    // cout<<(*s3).roll<<endl;
    s3->setAge(42);

    s1.display();
    s3->display();

    cout<<"S1 age: "<<s1.getAge()<<endl;
    cout<<"S3 age: "<<s3->getAge()<<endl;


    return 0;
}