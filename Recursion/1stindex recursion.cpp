#include<iostream>

using namespace std;


int firstIndex(int input[], int size, int x) {
  /* Don't write main().
     Don't read input, it is passed as function argument.
     Return output and don't print it.
     Taking input and printing output is handled automatically.
  */

    if(size==0)
        return -1;
    if(input[0]==x)
        return 0;
    int small=firstIndex(input+1,size-1,x);
    cout<<"Small="<<small<<endl;
    if(small==-1)
        return -1;
    else
        return small+1;




}






int main(){
    int input[]={4,6,1,2,1};




    int x=2;



    cout << firstIndex(input, 5, x) << endl;

}



