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
        }

        int setDenominator(int d){
            numerator = d;
        }

        void print(){
            cout<<this->numerator<<"/"<<denominator<<endl;              /// this-> optional (rest of below are all optional)
        }

        void add(Fraction const &f2){
            int lcm = this->denominator * f2.denominator;
            int x = lcm/this->denominator;
            int y = lcm/f2.denominator;
            int num = x*numerator + y*f2.numerator;

            /// store add result in f1 (f1 = f1 + f2)
            this->numerator = num;                                  
            this->denominator = lcm;

            simplify();
        }

        void multiply(Fraction const &f2){
            numerator = numerator * f2.numerator;
            denominator = denominator * f2.denominator;
            simplify();
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

    Fraction const f3;                                  /// constant object created
    cout<<f3.getNumerator()<<" "<<f3.getDenominator();  /// const obj can call the const functions, unable to call non-const funcs

    f3.setNumerator(10);
    return 0;
}