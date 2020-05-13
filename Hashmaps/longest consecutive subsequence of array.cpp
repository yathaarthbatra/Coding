
#include<iostream>
using namespace std;


#include<bits/stdc++.h>
#include <vector>
using namespace std;

vector<int> longestConsecutiveIncreasingSequence(int *arr, int n){
	//Your Code goes here
    
    
    unordered_map<int,bool> hash;
    
    for(int i=0;i<n;i++){
        hash[arr[i]]=true;
    }
    
    
    int start=arr[0];
    int max_len=1;
    
    int j;
    int count;
    for(int i=0;i<n;i++){
    	 count=1;
        j=1;
        if(hash[arr[i]-1]!=true){
            
            while(hash[arr[i]+j]!=false){
                count++;
                j++;
            }
            if(max_len < count){
                max_len=count;
                start=arr[i];
            }
        }
    }
    vector<int> v;
    
    for(int i=0;i<max_len;i++){
        v.push_back(start+i);
    }
    
    return v;
    
    
    
    
    
    
    
}

int main(){
  int size;
  
  cin >> size;
  int* arr = new int[size];
  for(int i = 0; i < size; i++){
    cin >> arr[i];
  }
  vector<int> ans = longestConsecutiveIncreasingSequence(arr,size);
  
  for (auto it = ans.cbegin(); it != ans.cend(); it++) {
	cout << *it <<endl;
  }

  delete arr;
}