#include <iostream>
#include "solution.h"
using namespace std;

// Change in the given string itself. So no need to return or print the changed string.
#include<cstring>
void pairStar(char input[]) {
    int n;
    // Write your code here
  //we will use the approach of breaking the array as 1 to N-1
    if(strlen(input)==0 || strlen(input)==1)
        return ;//base condition



    pairStar(input+1);//calling recursively the fn
    //Now we will check whether the first element of the
    //returned array and original array are same
    //if same we need to shift the elements to insert the *
    if(input[0]==input[1]){
        n=strlen(input)-1;
        for(int i=n;i>0;i--){
            input[i+1]=input[i];
        }//shifted the elements by one place
        input[1]='*';
        input[n+2]='\0';
    }

}

int main() {
   char input[100];
   cin.getline(input, 100);
   pairStar(input);
   cout << input << endl;
}
