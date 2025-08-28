#include<iostream>
using namespace std;

class Fraction{
    private :
        int numerator;
        int denominator;

    public :
        Fraction(int numerator, int denominator){
            this->numerator = numerator;                                /// this-> mandatory
            this->denominator = denominator;                    
        }

        /// Constant functions
        int getNumerator() const {
            return numerator;
        }

        int getDenominator() const {
            return denominator;
        }

        int setNumerator(int n){
            numerator = n;
            return numerator;
        }

        int setDenominator(int d){
            numerator = d;
            return numerator;
        }

        void print(){
            cout<<this->numerator<<"/"<<denominator<<endl;              /// this-> optional (rest of below are all optional)
        }

        /// Store add result in new object fnew (fnew = f1 + f2)
        Fraction add(Fraction const &f2) const {               /// using reference to avoid using copy constructor, & avoid any illegal changes with const
            int lcm = denominator * f2.denominator;
            int x = lcm / denominator;
            int y = lcm / f2.denominator;

            int num = x*numerator + y*f2.numerator;

            Fraction fnew(num,lcm);     /// parameterised constructor called
            fnew.simplify();
            return fnew;
        }

        /// Operator overloading -- store + result in new object fnew (fnew = f1 + f2)
        Fraction operator+(Fraction const &f2) const {         
            int lcm = denominator * f2.denominator;
            int x = lcm / denominator;
            int y = lcm / f2.denominator;

            int num = x*numerator + y*f2.numerator;

            Fraction fnew(num,lcm);     /// parameterised constructor called
            fnew.simplify();
            return fnew;
        }

        void multiply(Fraction const &f2){
            numerator = numerator * f2.numerator;
            denominator = denominator * f2.denominator;
            simplify();
        }

        /// Operator overloading -- store * result in new object fnew (fnew = f1 * f2)
        Fraction operator*(Fraction const &f2) const {
            int n = numerator * f2.numerator;
            int d = denominator * f2.denominator;

            Fraction fnew(n,d);
            fnew.simplify();
            return fnew;
        }

        /// Operator overloading --- store bool result of == with comparison of f1 == f2  
        bool operator==(Fraction const &f2) const {
            return (numerator == f2.numerator && denominator == f2.denominator);
        }

        /// Operator overloading --- execute (pre increment) ++ result to selected object
        Fraction& operator++(){
            numerator = numerator + denominator;
            simplify();

            return *this;
        }

        /// Operator overloading --- execute (post increment) ++ result to selected object and store in new object
        Fraction operator++(int){
            Fraction fnew(numerator,denominator);
            numerator = numerator + denominator;
            simplify();
            fnew.simplify();
            return fnew;
        }


        void simplify(){
            int gcd = 1;
            int j = min(this->numerator,this->denominator);
            for (int i=1;i<=j;i++){
                if(numerator%i==0 && denominator%i ==0){
                    gcd = i;
                }
            }
        /// simplify
        numerator = numerator/gcd;
        denominator = denominator/gcd; 

        }

};

int main(){

    Fraction f1(10,2);
    Fraction f2(15,4);

    f1.print();
    f2.print();

    Fraction f3 = f1.add(f2);
    Fraction f4 = f1 + f2;      /// operator overloading

    f3.print();
    f4.print();

    Fraction f5 = f1 * f2;
    Fraction f6 = ++(++f1);     /// pre increment

    f5.print();
    f1.print();
    f6.print();

    Fraction f7 = f2++;         /// post increment
    f2.print();
    f7.print();

    if(f1==f1){
        cout<<"equal"<<endl;
    }else{
        cout<<"not equal"<<endl;
    }

    return 0;
}