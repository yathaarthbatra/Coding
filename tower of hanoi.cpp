#include <iostream>
using namespace std;
#include "solution.h"


void towerOfHanoi(int n, char source, char auxiliary, char destination) {


    // Write your code here
    if(n==0)
        return;

    if(n==1){//base conditiom
        cout<<source<<" "<<destination<<endl;
        return ;
    }

    //n-1 discs will be handled by the recursion and
    //1 disc will be handled by us
    towerOfHanoi(n-1,source,destination,auxiliary);//Shifting n-1 discs to B
    cout<<source<<" "<<destination<<endl;//this step will be done by us and this we have to print(A-C)
    towerOfHanoi(n-1,auxiliary,source,destination);//shifting the n-1 discs to C rod

}

int main() {
    int n;
    cin >> n;
    towerOfHanoi(n, 'a', 'b', 'c');
}
