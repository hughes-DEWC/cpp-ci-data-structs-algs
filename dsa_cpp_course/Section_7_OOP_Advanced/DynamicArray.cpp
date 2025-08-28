#include<iostream>
using namespace std;

class DynamicArray{
    int *data;
    int nextIndex;
    int capacity;
    
    public:
    DynamicArray(){
        data = new int[5];
        nextIndex = 0;
        capacity = 5;
    }

    DynamicArray(int c){
        data = new int[c];
        nextIndex = 0;
        capacity = c;
    }

    // Creating our own copy constructor
    DynamicArray(DynamicArray const &d){
        this->nextIndex = d.nextIndex;
        this->capacity = d.capacity;
        /// shallow copy
        /// this-> data = d.data
        /// deep copy: create new array copy old values
        this->data = new int[d.capacity];
        for(int i=0;i<d.nextIndex;i++){
            this->data[i] = d.data[i]; 
        }

    }

    void add(int element){
        if(nextIndex == capacity){
            int *newData = new int[2*capacity];
            for (int i=0;i<capacity;i++){
                newData[i] = data[i];
            }
            delete []data;  /// remember to delete previous array data
            data = newData;
            capacity = capacity * 2;
        }
        data[nextIndex] = element;
        nextIndex++;
    }

    void add(int element, int i){
        if(i<nextIndex){
            data[i] = element;
        } else if(i==nextIndex) {
            add(element);
        }else{
            return;
        }
    }

    int getElement(int i) const {
        if(i>0 && i<nextIndex){
            return data[i];
        } else{
            return -1;
        }
    }

    void print() const {
        for(int i=0;i<nextIndex;i++){
            cout<<data[i]<<" ";
        }
        cout<<endl;
    }

    int getCapacity() const{
        return capacity;
    }

};

int main(){
    DynamicArray d1;
    d1.add(10);
    d1.add(20);
    d1.add(30);
    d1.add(40);
    d1.add(50);
    d1.add(60);

    d1.print();
    cout<<d1.getCapacity()<<endl;

    /// Was using default copy constructor (creates shallow copy)
    DynamicArray d2(d1);    /// created our own copy constructor (deep copy)
    d1.add(100,0);
    d1.print();
    d2.print();

    DynamicArray d3(100);
    d3.add(50);
    d3.add(70);
    d3.add(90);
    d3.print();
    cout<<d3.getCapacity()<<endl;
    cout<<d3.getElement(1)<<endl;


    return 0;
}