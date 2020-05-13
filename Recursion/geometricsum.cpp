#include <iostream>
#include <math.h>
#include <iomanip>
#include "solution.h"
using namespace std;


double geometricSum(int k) {
    // Write your code here


    if(k==0)//base condition
        return 1;

    double ans=geometricSum(k-1);
    double res=1/pow(2.0,k);
    ans=ans+res;
    return ans;




}



int main() {
    int k;
    cin >> k;
    cout << fixed << setprecision(5);
    cout << geometricSum(k) << endl;
}
