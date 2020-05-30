#include<iostream>
#include<string.h>
using namespace std;
class student
{
    


    /* data */
    static int age;//
    public:

    student(){
        age++;
    }
    
    static void print(){
        cout << "Age=" << age << endl;
    }
};
int student::age = 0;


