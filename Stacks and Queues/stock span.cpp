#include<stack>
int* stockSpan(int *price, int size) {
	// Write your code her
    
    int *temp=new int[size];
    int i=0;
    stack<int> s;
    s.push(i);
    temp[i]=1;
    i++;
    
    while(i<size){
         if(price[i]<price[s.top()]){
             temp[i]=1;
             s.push(i);
             i++;
         }
        else{
          int count=0;
            while(!s.empty() && price[s.top()]<price[i]){
                s.pop();
                count++;
            }
            temp[i]=s.empty()?i+1: i-s.top();
            s.push(i);
            i++;
           
        }
        
    }
    
    return temp;
    
}
