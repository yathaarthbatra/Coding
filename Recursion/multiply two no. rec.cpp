#include <iostream>
#include "solution.h"
using namespace std;


int multiplyNumbers(int m, int n) {
    // Write your code here
    if(m==0 || n==0)//base cpndition
        return 0;

    int temp=m+n-1;
    int ans=multiplyNumbers(m-1,n-1);
    ans=ans+temp;
    return ans;


}



int main() {
    int m, n;
    cin >> m >> n;
    cout << multiplyNumbers(m, n) << endl;
}
