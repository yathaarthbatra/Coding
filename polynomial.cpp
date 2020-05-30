/* C++ implementation to convert infix expression to postfix*/
// Note that here we use std::stack  for Stack operations
#include <vector>
#include <climits>
#include <iostream>
using namespace std;



class Polynomial {
    int *degCoeff;      // Name of your array (Don't change this)
    int capacity;
    public:
    
	//default constructor
    Polynomial(){
        degCoeff=new int[5];
        capacity=5;
        for(int i=0;i<capacity;i++){
            degCoeff[i]=0;
        }
        
    }
    
    //parameterized constructor
    Polynomial(int *data,int c){
        degCoeff = data;
        this->capacity = c;
    }
    
    //copy constructor
    Polynomial(const Polynomial &p){
        this->capacity=p.capacity;
        //here we will deep copy
        //that is we will create a new array
        degCoeff=new int[p.capacity];
        for(int i=0;i<capacity;i++){
            degCoeff[i]=p.degCoeff[i];
        }
        //so finally we copied the elements
    }

    //now we will use copy assignment operator
    //we will use operator overloading
    void operator=(const Polynomial &p){
        this->capacity=p.capacity;
        //here we will deep copy
        //that is we will create a new array
        degCoeff=new int[p.capacity];
        for(int i=0;i<capacity;i++){
            degCoeff[i]=p.degCoeff[i];
        }
        
    }
    

    Polynomial operator+(const Polynomial &p2){
        //this contains the p1 and p2 is passed by reference
      //  int max_cap = (this->capacity > p2.capacity ? this->capacity : p2.capacity);
        int max_cap = 0;
        int smaller = 0;
        if(this->capacity==p2.capacity){
            max_cap = this->capacity;
            smaller = this->capacity;
        }
        else if(this->capacity>p2.capacity){
            max_cap = capacity;
            smaller = p2.capacity;
        }
        else
        {
            max_cap = p2.capacity;
            smaller = this->capacity;
        }
        
        int *newArray = new int[max_cap];
        for (int i = 0; i < max_cap;i++){
            if(max_cap==this->capacity){
                newArray[i] = degCoeff[i];
            }
            else if(max_cap==p2.capacity)
                newArray[i] = p2.degCoeff[i];
            
        }
        for (int i = 0; i < smaller;i++){
            if(max_cap!=this->capacity){
                if(this->degCoeff[i]!=0){
                    newArray[i] = newArray[i] + degCoeff[i];
                }
                
            }
            else{
                if(p2.degCoeff[i]!=0)
                    newArray[i] = newArray[i] + p2.degCoeff[i];
            }

        }
            Polynomial P3(newArray, max_cap);
        return P3;
    }
    Polynomial operator-(const Polynomial &p2){
        //this contains the p1 and p2 is passed by reference
      //  int max_cap = (this->capacity > p2.capacity ? this->capacity : p2.capacity);
        int max_cap = 0;
        int smaller = 0;
        if(this->capacity==p2.capacity){
            max_cap = this->capacity;
            smaller = this->capacity;
        }
        else if(this->capacity>p2.capacity){
            max_cap = capacity;
            smaller = p2.capacity;
        }
        else
        {
            max_cap = p2.capacity;
            smaller = this->capacity;
        }
        
        int *newArray = new int[max_cap];
        for (int i = 0; i < max_cap;i++){
            if(max_cap==this->capacity){
                newArray[i] = degCoeff[i];
            }
            else if(max_cap==p2.capacity)
                newArray[i] = p2.degCoeff[i];
            
        }
        for (int i = 0; i < smaller;i++){
            if(max_cap!=this->capacity){
                if(this->degCoeff[i]!=0){
                    newArray[i] = newArray[i] - degCoeff[i];
                }
                
            }
            else{
                if(p2.degCoeff[i]!=0)
                    newArray[i] = newArray[i] - p2.degCoeff[i];
            }

        }
        if(this->capacity<p2.capacity){
            for (int i = 0; i < max_cap;i++)
                newArray[i] = newArray[i] * (-1);
        }
            Polynomial P3(newArray, max_cap);
        return P3;
    }
    Polynomial operator*(const Polynomial &p2){
        
    }
    
};





//Driver program to test above functions
int main()
{
    int count1,count2,choice;
    cin >> count1;
    
    int *degree1 = new int[count1];
    int *coeff1 = new int[count1];
    
    for(int i=0;i < count1; i++) {
        cin >> degree1[i];
    }
    
    for(int i=0;i < count1; i++) {
        cin >> coeff1[i];
    }
    
    Polynomial first;
    for(int i = 0; i < count1; i++){
        first.setCoefficient(degree1[i],coeff1[i]);
    }
    
    cin >> count2;
    
    int *degree2 = new int[count2];
    int *coeff2 = new int[count2];
    
    for(int i=0;i < count2; i++) {
        cin >> degree2[i];
    }
    
    for(int i=0;i < count2; i++) {
        cin >> coeff2[i];
    }
    
    Polynomial second;
    for(int i = 0; i < count2; i++){
        second.setCoefficient(degree2[i],coeff2[i]);
    }
    
    cin >> choice;
    
    switch(choice){
            // Add
        case 1:
        {
            Polynomial result1 = first + second;
            result1.print();
            break;
        }
            // Subtract
        case 2 :
        {
            Polynomial result2 = first - second;
            result2.print();
            break;
        }
            // Multiply
        case 3 :
        {
            Polynomial result3 = first * second;
            result3.print();
            break;
        }
        case 4 : // Copy constructor
        {
            Polynomial third(first);
            if(third.degCoeff == first.degCoeff) {
                cout << "false" << endl;
            }
            else {
                cout << "true" << endl;
            }
            break;
        }
            
        case 5 : // Copy assignment operator
        {
            Polynomial fourth(first);
            if(fourth.degCoeff == first.degCoeff) {
                cout << "false" << endl;
            }
            else {
                cout << "true" << endl;
            }
            break;
        }
            
    }
    
    return 0;
}
