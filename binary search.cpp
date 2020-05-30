#include <iostream>
#include "solution.h"
using namespace std;

// input - input array
// size - length of input array
// element - value to be searched

int BinarySearch(int input[],int start,int end,int element){

    //base conditions
    if(start>end)  //it means there are no elements present in the array
        return -1;
    if(start==end){
        if(input[start]==element)
            return start;
        else
            return -1;
    }


    int mid=(start+end)/2;
    int index=0;

    //our calculation
    if(input[mid]==element)
        return mid;

    else if(input[mid]>element){
        index=BinarySearch(input,start,mid-1,element);
    }
    else
        index=BinarySearch(input,mid+1,end,element);










}

int binarySearch(int input[], int size, int element) {
    // Write your code here
    int start=0;
    int end=size-1;
   int result= BinarySearch(input,start,end,element);
    return result;

}

int main() {
    int input[100000],length,element, ans;
    cin >> length;
    for(int i =0;i<length;i++)
    {
        cin >> input[i];;
    }

    cin>>element;
    ans = binarySearch(input, length, element);
    cout<< ans << endl;
}
