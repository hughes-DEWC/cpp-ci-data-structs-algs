#include<iostream>
using namespace std;

class Student{

    static int totalStudents;   /// now a private property
    
    public:

    int age;
    int rollNumber;

    Student(){
        totalStudents++;
    }

    int getRollNumber(){            /// this is a non-static function
        return rollNumber;      
    }

    static int getTotalStudents(){  /// this function belongs to the class (not objects)
        return totalStudents;
    }

};

/// to initialise static prop it has to be outside the class
int Student::totalStudents = 0;

int main(){

    Student s1;

    cout<<s1.rollNumber<<" "<<s1.age<<endl;
    cout<<Student::getTotalStudents()<<endl;         /// format: class name (Student), scope resolution operator (::), static property (totalStudents)

    Student s2,s3;
    cout<<Student::getTotalStudents()<<endl;

    return 0;
}