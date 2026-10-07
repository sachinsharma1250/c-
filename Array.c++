#include <iostream>
using namespace std;
class Array{
    private:
        int *array;
        int Capacity;
        int size;
    public:
        Array(int ArrayCap=10);
        ~Array();
        bool isFull();
        bool isEmpty();
        int SizeofArray();
        friend istream& operator>>(istream& is,Array &a);
        friend ostream& operator<<(ostream& os,Array &a);     
};
Array::Array(int ArrayCap):Capacity(ArrayCap){
    array=new int [Capacity];
    size=0;
}
Array::~Array(){
    delete [] array;
}
bool Array::isFull(){
    if(size==Capacity){
        return true;
    }
    return false;
}
bool Array::isEmpty(){
    if(size==0){
        return true;
    }
    return false;
}
int Array::SizeofArray(){
    return size;
}
istream& operator>>(istream& is,Array &a){
    cout<<"\nEnter an Element to be inserted in Array....\n";
    is>>a.array[a.size++];
    return is;
}
ostream& operator<<(ostream& os,Array &a){
    for(int i=0;i<a.size;i++){
        os<<a.array[i]<<" ";
    }
    return os;
}
int main() {
    Array a;
    int num;
    cout<<"\nEnter How many Element?... ";
    cin>>num;
    for(int i=0;i<num;++i){
        cin>>a;
    }
    cout<<"\nEntered Elements are...\n"<<a;
    if(a.isFull()){
        cout<<"\nArray is Full.";
    }
    else{
        cout<<"\nArray is Not Full.";
    }
    if(a.isEmpty()){
        cout<<"\nArray is Empty.";
    }
    else{
        cout<<"\nArray is Not Empty.";
    }
    cout<<"\nSize of Array is ..."<<a.SizeofArray();
}