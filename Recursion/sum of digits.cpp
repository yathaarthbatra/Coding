#include <iostream>
#include "solution.h"
using namespace std;

int sumOfDigits(int n) {
    // Write your code here
    //n is a number
    if(n==0)
        return 0;

    int last=n%10;
    int result=sumOfDigits(n/10);
    return result+last;


}



int main() {
   int n;
   cin >> n;
   cout << sumOfDigits(n) << endl;
}
