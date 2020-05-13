#include <iostream>
#include "solution.h"
using namespace std;

// Change in the given string itself. So no need to return or print anything
#include<cstring>
void removeX(char input[]) {
    int i;
    // Write your code here
    if(strlen(input)==0)
        return ;

    removeX(input+1);
    if(input[0]=='x'){
        for(i=0;i<strlen(input)-1;i++){
            input[i]=input[i+1];
        }
        input[i]='\0';
    }


}

int main() {
    char input[100];
    cin.getline(input, 100);
    removeX(input);
    cout << input << endl;
}
