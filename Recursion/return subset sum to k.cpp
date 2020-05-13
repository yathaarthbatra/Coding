#include <iostream>
#include "solution.h"
using namespace std;

int subsetSumToK(int input[],int n,int output[][50],int k){
    if(n==0){
        if(k==0){
            output[0][0]=0;
            return 1;
        }
        else
            return 0;
    }

    int o1[500][50];
    int o2[500][50];
    int s1=subsetSumToK(input+1,n-1,o1,k-input[0]);
    int s2=subsetSumToK(input+1,n-1,o2,k);
    int row_ta=0;
    for(int i=0;i<s1;i++){
        output[row_ta][0]=o1[i][0]+1;
        output[row_ta][1]=input[0];
        for(int col=1;col<=o1[i][0];col++){
            output[row_ta][col+1]=o1[i][col];
        }
        row_ta++;
    }

    for(int i=0;i<s2;i++){
        for(int col=0;col<=o2[i][0];col++){
            output[row_ta][col]=o2[i][col];
        }
        row_ta++;
    }
    return s1+s2;
}
int main() {
  int input[20],length, output[10000][50], k;
  cin >> length;
  for(int i=0; i < length; i++)
    cin >> input[i];

  cin >> k;

  int size = subsetSumToK(input, length, output, k);

  for( int i = 0; i < size; i++) {
	for( int j = 1; j <= output[i][0]; j++) {
		cout << output[i][j] << " ";
    }
    cout << endl;
  }
}
