
//printing the subsequences of the string
#include<iostream>
using namespace std;

void printsub(string input,string output){
  if(input.length()==0){
    cout<<output<<endl;
    return ;
  }

printsub(input.substr(1),output);
printsub(input.substr(1),output+input[0]);



}

int main(){
  string input;
  cin>>input;
  string output="";
  printsub(input,output);
  return 0;
}
