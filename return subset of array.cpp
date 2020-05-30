#include <iostream>
#include "solution.h"
using namespace std;

/***
You need to save all the subsets in the given 2D output array. And return the number of subsets(i.e. number of rows filled in output) from the given function.

In ith row of output array, 1st column contains length of the ith subset. And from 1st column actual subset follows.
For eg. Input : {1, 2}, then output should contain
	{{0}, 		// Length of this subset is 0
	{1, 2},		// Length of this subset is 1
	{1, 1},		// Length of this subset is also 1
	{2, 1, 2}}	// Length of this subset is 2

Don’t print the subsets, just save them in output.
***/

int subset(int input[], int n, int output[][20]) {
     int i,j;
    // Write your code here
    //1st column in the ith row shoild contain the length of the subset
    if(n==0){
        output[0][0]=0;
        output[0][1]=NULL;
        return 1;
    }//if there is no array then the subset will be 0 ie the lenght of
    //subset will be 0 and no. of subset will be 1;
    int smallsubsets=subset(input+1,n-1,output);
    //now this smallsubsets will contain the no. of subsets
    //for the array not having the first element
    for(i=0;i<smallsubsets;i++){
        output[i+smallsubsets][0]=output[i][0]+1;
       }//increased the size of the rows by one

    //now we have to copy the elements
    for(i=0;i<smallsubsets;i++){
        for(j=output[i+smallsubsets][0];j>=1;j--){
            output[i+smallsubsets][j+1]=output[i][j];
        }
        output[i+smallsubsets][j+1]=input[0];
    }

    return 2*smallsubsets;

}

int main() {
  int input[20],length, output[35000][20];
  cin >> length;
  for(int i=0; i < length; i++)
    cin >> input[i];

  int size = subset(input, length, output);

  for( int i = 0; i < size; i++) {
	for( int j = 1; j <= output[i][0]; j++) {
		cout << output[i][j] << " ";
    }
    cout << endl;
  }
}
