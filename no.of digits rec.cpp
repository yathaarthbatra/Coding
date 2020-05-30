#include<iostream>
#include "Solution.h"
using namespace std;
int count(int n){//n is a no. entered
    if(n == 0){
        return 0;
    }
    int smallAns = count(n / 10);
    return smallAns + 1;
}

int main(){
    int n;
    cin >> n;

    cout << count(n) << endl;
}



