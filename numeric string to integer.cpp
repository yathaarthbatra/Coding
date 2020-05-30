#include <iostream>
#include "solution.h"
using namespace std;

#include<math.h>
#include<cstring>

int stringToNumber(char input[]) {
    // Write your code here
    //to convert the string into integer
    if(strlen(input)==0)
        return 0;
    //if input='1234'
    //result=234(int)
    int result=stringToNumber(input+1);
    //we have input[0]='1'
    int ans=input[0]-48;//ans will give the 1 (ans=1)
    result=ans*(pow(10,strlen(input)-1)) + result;
    //strlen will give 4
    return result;

}



int main() {
    char input[50];
    cin >> input;
    cout << stringToNumber(input) << endl;
}
