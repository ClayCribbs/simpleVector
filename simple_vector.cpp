/*
// Simple Vector 1.0
//
// Clay Cribbs
//
//
*/
#include <iostream>
#include <string>
using namespace std;


template <class Type>

//class template
class SimpleVector{
    
protected:
    
    Type* dynamicArray;
    int size;

public:
    
    //Default empty Constructor
    SimpleVector(){
        size = 0;
        dynamicArray = NULL;
    }
    
    //Constructor with array size argument
    SimpleVector(int arraySize){
        size = arraySize;
        dynamicArray = new Type[arraySize];
    }

    //Copy Constructor
    SimpleVector(const SimpleVector<Type>& v){
        size = v.size;
        dynamicArray = new Type[size];
        for (int i = 0; i < size; i++)
            dynamicArray[i] = v.dynamicArray[i];
    }
    
    //Deconstructor
    ~SimpleVector(){
        size = 0;
        delete[] dynamicArray;
    }
    
    //Getters
    int getSize(){
        return size;
    }
    
    Type getElementAt(int index){
        return dynamicArray[index];
    }
    
    //Overload the operator [] return the element at index
    Type& operator[](int index){
        return dynamicArray[index];
    }
};

template<class T>
//creates Vector filled with data and displays info about it
void castedVector(SimpleVector<T>& thisVector){

    int i;
    //User inputs data
    for (i = 0; i < thisVector.getSize(); i++){
        cout << "Enter data for index " << (i) << ": ";
        cin >> thisVector[i];
    }
    
    //Data output as per assignment
    cout << endl;
    cout <<"---------------------------------------------------------------\n";
    cout << "Enter the index of the element we should return using .getElementAt \n";
    cin >> i;
    //using getElementAt
    cout << "Item at " << i << " is " << thisVector.getElementAt(i) << endl;
    cout <<"---------------------------------------------------------------\n";
    cout << "Enter the index of the element we should return using the overloaded [] method? \n";
    cin >> i;
    //using overloaded []
    cout << "Item at " << i << " is " << thisVector[i] << endl;
    SimpleVector<T> copiedVector(thisVector);
    cout <<"---------------------------------------------------------------\n";
    cout << "Copied vector: ";
    for (i = 0; i < copiedVector.getSize(); i++){
        cout << copiedVector[i] << " ";
    }
    
    cout << endl;
}

int main(){
    
    string v;
    int type;
    int size;
    
    //main loop breaks when user specifies they are done entering data
    do {
        cout << "What type of input?(1 for int, 2 for double, 3 for string): ";
        cin >> type;
        cout << "How many data entries do you have?";
        cin >> size;
    
        //Creates Integer Vector
        if (type == 1){
            SimpleVector<int> thisVector(size);
            castedVector(thisVector);
        }
        //Creates Double Vector
        else if (type == 2){
            SimpleVector<double> thisVector(size);
            castedVector(thisVector);
        }
        //Creates String Vector
        else if (type == 3){
            SimpleVector<string> thisVector(size);
            castedVector(thisVector);
        }
        
        cout << endl;
        //Check if user wants to continue
        cout << "Would you want to enter again(y/n)? ";
        cin >> v;
        
    } while (v == "y");
    
    return 0;
}


