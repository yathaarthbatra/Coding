#include<iostream>
using namespace std;


bool isSorted2(int a[],int n){

    if(n==0 || n==1)
        return true;

    bool ismall=isSorted2(a+1,n-1);//we are assuming that it will work and give us the true/false
    if(!ismall) //now if the rest of the array is not sorted then return false
        return false;
    if(a[0]>a[1])//if the array is sorted then we have to check the 1st two elements
        return false;
    else
        return true;


}




bool isSorted(int a[],int n){
 if(n==0 || n==1)//if the size if 0 or 1 then no need to check it is aleardy sorted
    return true;

 if(a[0]>a[1])//if the first 2 elements are not sorted then no need to check the left out array
    return false;
 else
    return isSorted(a+1,n-1);//if first two elements are sorted then we have to check the entire array.
}


int main()
{
    int a[]={1,2,3,4,5};
    bool res=isSorted2(a,5);
    cout<<res<<endl;
    return 0;
}
