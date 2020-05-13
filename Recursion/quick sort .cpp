#include<iostream>
#include "Solution.h"
using namespace std;


     int partition(int input[],int start,int end){
        //pivot element woukld be assigned to start/end or any
        //other element acc. to the need
        //we will assign first element
        int pivot=input[start];
        int count=0;//will be the pivot index
        //nwo to know how many elements are smaller than pivot
        //by this we would come to know that where the pivot element has to be placed
        for(int k=1;k<=end;k++){
            if(pivot>=input[k])
                count++;
        }

        //Now placing the pivot element at its position
        input[start]=input[count];
        input[count]=pivot;
        int i=start;
        int j=end;
        //now we will place the elements smaller on the left hand side and larger on the right hand
        //side of the pivot element
        while(i<count && j>count){
            if(input[i]<=pivot)
                i++;
            else if(input[j]>pivot)
                j--;
            else{
                //swap
                int temp=input[i];
                input[i]=input[j];
                input[j]=temp;
                i++;
                j--;
                }

        }
        return count;

    }


    void QuickSort(int input[],int start,int end){


        //base condition:
        if(start>=end)
            return ;
        /* first we have to do the partitioning i.e placing the
        pivot element in between the array such that elements on the
        left side of pivot element are smaller and right side are larger*/
        int PI=partition(input,start,end);//this will return the index of the
        //pivot element not the pivot element itself.
        /*Now we have done the partitioning ,now we will sort the elements
        at the left hand side and the right hand side of the pivot element*/
        QuickSort(input,start,PI-1);//will sort the left hand side elements
        QuickSort(input,PI+1,end);//will sort the right hand side elements

    }





    void quickSort(int input[], int size) {
      /* Don't write main().
         Don't read input, it is passed as function argument.
         Change in the given array itself.
         Taking input and printing output is handled automatically.
      */

        int start=0;
        int end=size-1;
        QuickSort(input,start,end);


    }

int main(){
    int n;
    cin >> n;

    int *input = new int[n];

    for(int i = 0; i < n; i++) {
        cin >> input[i];
    }

    quickSort(input, n);
    for(int i = 0; i < n; i++) {
        cout << input[i] << " ";
    }

    delete [] input;

}


