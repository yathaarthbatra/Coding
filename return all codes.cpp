#include <iostream>
#include "solution.h"
using namespace std;


void helper(int input[],int size,int k,int output[],int m){

    int i;
    //base condition
    if(size==0){
        if(k==0){
            for(int i=0;i<m;i++){
                cout<<output[i]<<" ";
            }
            cout<<endl;
            return ;
        }
        else
            return ;

    }//base condition gets over
    //now first we will make call excluding the 1st element in the output array
    helper(input+1,size-1,k,output,m);
    //now we have to make call including the first element in the output array
    int newArray[100];
    for(i=0;i<m;i++){
        newArray[i]=output[i];
    }
    newArray[i]=input[0];//element ko include kia
    helper(input+1,size-1,k-input[0],newArray,m+1);

}

void printSubsetSumToK(int input[], int size, int k) {
    // Write your code here
    int output[1000];
    helper(input,size,k,output,0);
}

int main(){
    string input;
    cin >> input;

    string output[10000];
    int count = getCodes(input, output);
    for(int i = 0; i < count && i < 10000; i++)
        cout << output[i] << endl;
    return 0;
}
