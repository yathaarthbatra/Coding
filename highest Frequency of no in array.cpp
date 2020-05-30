#include<iostream>
#include<bits/stdc++.h>//collection of all the files
//#include<unordered_map>
using namespace std;
//1 2 3 4 5 => 1
// 1 1 2 2 2 3=> 2

// 1st method: Travesring each element => O(n2)
//2nd method: sorting then Linear traversing==>O(nlogn + n)=>O(nlogn)
//3rd method: using hashmaps

//hashmaps are key value pairs==>arr[int]...index is of int type
//hashmaps mei hum kisi bhi type ki key/index values store kr sakte hai
//arr[5] = 20;
//arr[100] = "yathaarth";
//arr[7] = 21;
int HighestFreq(int *arr,int size){

    map<int, int> hash;
    //hash==> eg...1 1 2 2 2 3
    
           
           for (int i = 0; i < size;i++){//travesring the array
               hash[arr[i]]++;//hash[arr[0]]=0..but after incrementing it will give 1 i. .e 1:1
           }
           //ourhashmap would be like this:
           //1:2//here 2 is i.second
           //2:3//here 3 is i.second
           //3:1
           //so to do hashmap traversal..we use auto variables
           int max_count = 0;
           int res = 0;
           for(auto i:hash){
               if(max_count < i.second){// i.second=2...i.first =1 for 1st traversal in hashmap
                   max_count = i.second;//max_count=1...
                   res = i.first;//res=1
               }
           }
           return res;
}

int main(){

    int arr[] = {1, 2, 3, 4, 5};
    int max = HighestFreq(arr, 5);

    cout << "Highest Frequency No." << max << endl;

}