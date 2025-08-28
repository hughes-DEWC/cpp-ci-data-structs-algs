#include<iostream>
using namespace std;

class Student{
    public:
        int age;
        const int rollNumber;
        int &x;     /// age reference variable

        /// Initialisation list --> initialise const properties and reference properties at the time of memeory alloc
        Student(int r, int age): rollNumber(r), age(age), x(this->age) {
            /// IL performs following: rollNumber = r, age = age, x = age

        }
};

int main(){
    Student s1(100,10);
    s1.age = 10;
    cout<<s1.rollNumber<<endl;
    return 0;
}