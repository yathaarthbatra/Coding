#include <iostream>
#include "solution.h"
using namespace std;


#include<cstring>


bool helper(char input[],int s,int e){

    if(s==e)
        return true;


    if(input[s]!=input[e])
        return false;

    if(s<e+1){
        return helper(input,s+1,e-1);
    }
    return true;
}


bool checkPalindrome(char input[]) {
    // Write your code here
    int start=0;
    int end=strlen(input)-1;
   bool result=helper(input,start,end);

    return result;


}



int main() {
    char input[50];
    cin >> input;

    if(checkPalindrome(input)) {
        cout << "true" << endl;
    }
    else {
        cout << "false" << endl;
    }
}
