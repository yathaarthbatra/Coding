#include <iostream>
#include <string>
#include "solution.h"
using namespace std;

#include <iostream>
#include <string>
using namespace std;
string key[]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
void PrintKeypad(int num,string output){

    //base condition
    if(num==0){
        cout<<output<<endl;
        return ;
    }

    int last=num%10;
    string numtostring=key[last];  //numtostring="def"(3)
    int count=numtostring.length();//count=3
    for(int i=0;i<count;i++){
       PrintKeypad(num/10,numtostring[i]+output);
    }





}
void printKeypad(int num){
    /*
    Given an integer number print all the possible combinations of the keypad. You do not need to return anything just print them.
    */


    string output="";
    PrintKeypad(num,output);



}

int main(){
    int num;
    cin >> num;

    printKeypad(num);

    return 0;
}
