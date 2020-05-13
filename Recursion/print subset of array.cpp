#include <iostream>
using namespace std;
#include "solution.h"

 void Print(int input[],int size,int output[],int m){


    int i,j;
	// Write your code here
    //base condition
    if(size==0){

        for(int k=0;k<m;k++){
            cout<<output[k]<<" ";
        }
        cout<<endl;
        return ;
   }


    Print(input+1,size-1,output,m);
    //making a new array and transferring elemnents to it
    int newArray[100];
    for(i=0;i<m;i++){
        newArray[i]=output[i];
    }
    newArray[i]=input[0];//element ko include kia
    Print(input+1,size-1,newArray,m+1);

}


void printSubsetsOfArray(int input[], int size) {


    int output[100];


    Print(input,size,output,0);
}

int main() {
  int input[1000],length;
  cin >> length;
  for(int i=0; i < length; i++)
  	cin >> input[i];
  printSubsetsOfArray(input, length);
}
