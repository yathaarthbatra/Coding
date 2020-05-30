#include <iostream>
#include <string>
#include "solution.h"
using namespace std;
#include <string>
using namespace std;

int keypad(int num, string output[]){
    /* Insert all the possible combinations of the integer number into the output string array. You do not need to
    print anything, just return the number of strings inserted into the array.
    */
    //base condition
    if(num==0 || num==1){
        output[0]="";
        return 1;
    }
    string key[]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    //now we will call the recursion so that only last no. is dealt with us
    int smallsize=keypad(num/10,output);//this will give the possibilities of the
    //selection of the no's
    //now acc. to the last no. we have to make copies of the no. with the various strings

    //Now first we will make a copy of our output array and shift into temp. array
    string *temp=new string[smallsize];//dynamically alloacted temp array of small size array
    for(int i=0;i<smallsize;i++){
        temp[i]=output[i];
        }
    int last=num%10;
    string numtochar=key[last];
    //now we will concatenate acc.to the last no.
    for(int j=0;j<numtochar.length();j++){
        for(int k=0;k<smallsize;k++){
            output[j*smallsize+k]=temp[k]+numtochar[j];
        }
    }
    return (smallsize*numtochar.length());
}


int main(){
    int num;
    cin >> num;

    string output[10000];
    int count = keypad(num, output);
    for(int i = 0; i < count && i < 10000; i++){
        cout << output[i] << endl;
    }
    return 0;
}
