#include <iostream>
using namespace std;
#include "Solution.h"

#include<cstring>
void replaceCharacter(char input[], char c1, char c2) {
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * No need to print or return the output.
     * Change in the given input string itself.
     * Taking input and printing output is handled automatically.
     */
    if(strlen(input)==0)
        return ;//base condition 1
    if(strlen(input)==1){
        if(input[0]==c1)
            input[0]=c2;
    }//base condition2
    replaceCharacter(input+1,c1,c2);//this will change the string and except 1st character all characters
    //will be replaced
    if(input[0]==c1)
        input[0]=c2;


}
int main() {
    char input[1000000];
    char c1, c2;
    cin >> input;
    cin >> c1 >> c2;
    replaceCharacter(input, c1, c2);
    cout << input << endl;
}
