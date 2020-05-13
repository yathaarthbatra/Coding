
#include<iostream>
using namespace std;
#include<math.h>
int subsequence(string input,string output[]){

   //base condition
   if(input.empty()){
     output[0]="";
     return 1;
   }
   string passing=input.substr(1);
   int smalloutputsize=subsequence(passing,output);//recursion will occur and it will give the appropriate subsequences for the input given
   //now we have to adjust the starting element of the old input
  /* for(int i=0;i<smalloutputsize;i++){
     output[i+smalloutputsize]=input[0]+output[i];
   }*/
   return smalloutputsize;


}
int main()
{
  //subsequences of given string
  /* For eg: "abc",then the sub sequences
  of this string would be "a","b","c","ab","bc",
  "ac","abc"," ".
  substrings are continuous ie they cant be picked randomlike "ac"(they need to be continuous).
  But subsequences can be picked at random positions*/

  string s;
  cin>>s;
  int n=s.length();
  string *output=new string[10000];//dynamically allocating the array of strings
  int length=subsequence(s,output);
  for(int i=0;i<length;i++){
    cout<<output[i]<<endl;
  }



}
