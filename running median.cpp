#include <iostream>
#include<bits/stdc++.h>

using namespace std;
#include <queue>
using namespace std;

//******************************APPROACH****************************
// the basic approach which one would think at first would be like insertion sort or 
// take a vector and keep on sorting and calculating its median...but this has huge 
// time complexity which is O(n*n) which we should improve.
// *******Problem: we are req. to sort the element which is increasing our time complexity.
// and then only actually we can calculate our median.
// So the solution of the problem is to cal median in a different way
// so we will have two heap which are min heap and max heap 
// now min heap will give me the smallest one and the max heap would give 
// me the laregst and we can calculte the median by adding it and dividing it by 2.
// Also we have to check that the heaps contain nearly equal elements by having abs =1 condition
// we will keeep on inserting the element in the heap according to the condition that which is smaller
// and whcih is larger...
// the time complexity would be nlogn because of n insertion in two heaps 

void findMedian(int arr[], int n)
{
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;
    for(int i = 0; i < n; i++)
    {
        if(maxHeap.size() == 0)
        {
            maxHeap.push(arr[i]);
        }
        else
        {
            if(arr[i] > maxHeap.top())
            {
                minHeap.push(arr[i]);
            }
            else
            {
                maxHeap.push(arr[i]);   
            }
        }
        
        int a = maxHeap.size();
        int b = minHeap.size();
        
        if(std::abs(a - b) > 1)
        {
            if(maxHeap.size() > minHeap.size())
            {
                minHeap.push(maxHeap.top());
                maxHeap.pop();
            } 
            else
            {
                maxHeap.push(minHeap.top());
                minHeap.pop();
            }
        }
        if((maxHeap.size() + minHeap.size())%2 == 0)
        {
            cout<<(maxHeap.top() + minHeap.top())/2<<endl; 
        }
        else
        {
            cout<< (maxHeap.size() > minHeap.size() ? maxHeap.top() : minHeap.top())<<endl;
        }
    }
}
            
            
    int main(){
    int n;
    cin >> n;
    int *arr = new int[n];
    for(int i = 0; i < n; i++){
        cin>>arr[i];
    }
    findMedian(arr, n);
    
    delete [] arr;
    
}
