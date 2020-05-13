#include <iostream>
#include "solution.h"
using namespace std;


int countZeros(int n) {
    // Write your code here

    if(n==0)
        return 0;

    int last=n%10;
    int ans=countZeros(n/10);

    if(last==0){
        ans++;
    }
    return ans;





}



int main() {
    int n;
    cin >> n;
    cout << countZeros(n) << endl;
}
