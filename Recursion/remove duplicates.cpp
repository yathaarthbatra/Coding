#include <iostream>
using namespace std;
#include "solution.h"

#include<cstring>
void removeConsecutiveDuplicates(char *input) {
    int i;
	/* Don't write main().
	* Don't read input, it is passed as function argument.
	* Change in the given string itself.
	* No need to return or print anything
	* Taking input and printing output is handled automatically.
	*/
    if(strlen(input)==0 || strlen(input)==1)
        return ;
    removeConsecutiveDuplicates(input+1);
    if(input[0]==input[1]){
        for(i=1;input[i]!='\0';i++)
            input[i-1]=input[i];
        input[i-1]='\0';//always take care of null character
    }




}
int main() {
    char s[100000];
    cin >> s;
    removeConsecutiveDuplicates(s);
    cout << s << endl;
}
