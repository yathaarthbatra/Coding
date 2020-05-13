#include <iostream>
#include "solution.h"
using namespace std;

void Merge(int input[],int si,int mid,int ei){
    //first we have to create two temp array which
    //will contain the elements of the two sub arrays
    // remember that the lements in the particular sub-arrays
    //are sorted
    int n1=mid-si+1;//index of the left sub array
    int n2=ei-mid;//index of the right sub array
    int left[n1],right[n2];//created Left and right arrays

    /*Now we have to copy the elements of the sub arrays into
    left and right arrays which we have created*/
    int i,j;
    for(i=0;i<n1;i++){
        left[i]=input[si+i];
    }
    for(j=0;j<n2;j++){
        right[j]=input[mid+j+1];
    }

    //now we have created and shifted elements into left and right arrays
    //now we have to merge it into the original array
    i=0;//pointer index to the left array
    j=0;//pointer index to the right array
    int k=si;//pointer index to the original array


    while(i<n1 && j<n2){
        if(left[i]<=right[j]){
            input[k]=left[i];
            i++;
        }
        else{
            input[k]=right[j];
            j++;
        }
        k++;
    }

    /*Now we have to insert the remaining elements into
    the original array*/
    while(i<n1){
        input[k]=left[i];
        i++;
        k++;
    }

    while(j<n2){
        input[k]=right[j];
        j++;
        k++;
    }


}
void MergeSort(int input[],int s,int e){


    //base condition:
    if(s>=e)
        return ;  //aleady sorted if the array has one or zero elements

    int mid=(s+e-1)/2;
     //recursion starts
    MergeSort(input,s,mid); //it will bring us the sub array sorted
    MergeSort(input,mid+1,e);//   "
    Merge(input,s,mid,e);//called the fn to merge the two arrays


}



void mergeSort(int input[], int size){
	// Write your code here
    int start=0;
    int end=size-1;
    MergeSort(input,start,end);

}

int main() {
  int input[1000],length;
  cin >> length;
  for(int i=0; i < length; i++)
    cin >> input[i];
  mergeSort(input, length);
  for(int i = 0; i < length; i++) {
    cout << input[i] << " ";
  }
}
