#include<iostream>
using namespace std;
class dynamic_array
{
private:
    int *data;//this is the array
    int nextindex;//count of the pointer to the array
    int capacity;//total size
    public:
    dynamic_array(){
        data = new int[5];
        nextindex = 0;
        capacity = 5;

    }
    void add(int element){
        if(nextindex==capacity){
            //creating new array of double size
            int *newArray = new int[2 * capacity];
            //now copying the values of old array
            //into new array
            for (int i = 0; i < capacity;i++){
                newArray[i] = data[i];
            }
            //now after if statement the scope of new array is lost 
            //so we have to point data to newArray
            delete[] data;
            data = newArray;
            capacity = 2 * capacity;
        }
        data[nextindex] = element;
        nextindex++;
    }
    int get(int index){
        if(index<nextindex){
            return data[index];
        }
        else
        {
            return -1;
        }
        
    } 
    //now to add the element at particular index
    void add(int i,int element){
        if(i<nextindex){
            data[i] = element;
        }
        else if(i==nextindex){
            add(element);
        }
        else
        {
            return;
        }
        
    }
    dynamic_array(const dynamic_array &d){
        this->capacity = d.capacity;
        this->nextindex = d.nextindex;
        data = new int[d.capacity];
        //now copying the elements into new array
        for (int i = 0; i < nextindex;i++){
            data[i] = d.data[i];
        }
        //so here we have done deep copy
    }
    void operator=(const dynamic_array &d){
        this->capacity = d.capacity;
        this->nextindex = d.nextindex;
        data = new int[d.capacity];
        //now copying the elements into new array
        for (int i = 0; i < nextindex;i++){
            data[i] = d.data[i];
        }
        //so here we have done deep copy

    }

    void print(){
        for (int i = 0; i < nextindex;i++){
            cout << data[i] << " ";
        }
        cout << endl;
    }


};
int main(){
    dynamic_array d1;
    d1.add(10);
    d1.add(20);
    d1.add(30);
    d1.add(40);
    d1.add(50);
    d1.print();

    dynamic_array d2(d1);//shallow copy but
    //now we are creating deep copy constructor
    dynamic_array d3;
    d1.add(0, 100);
    d3 = d1;//this will also do shallow copy 
    //but we will make it to deep copy by opertor overloading
    d2.print();
    d3.print();
}

