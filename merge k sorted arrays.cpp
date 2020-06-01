#include <iostream>
using namespace std;

#include <vector>
#include <queue>
using namespace std;

//******************APPROACH*************************
// so the approach came from the merging of two sorted arrays with the help of two pointer 
// method now hwre we have k sorted arrays and now have to generalise the two sorted arrays
// apporach...so how could we calculate the min of the k no. at once?
// so here comes the thought of min heap.
// but the point is that we also have to store the information of the array of the element removed so that 
// we could insert the next element in to the min heap and insert it.
// So finally we come up to a thought i.e. to have min heap of special types of nodes which contain the
// information of array ,its index also...so will make the class.

class Triplet
{
  public:
    int element;
    int arrIndex;
    int elemIndex;
    Triplet(int element, int arrIndex, int elemIndex) : element(element), arrIndex(arrIndex), elemIndex(elemIndex)
    {
    }
};
//For the Implementation of Min Priority Queue on the basis of array element.
class CompareElement
{
  public:
    bool operator()(Triplet const& T1, Triplet const& T2)
    {
        return T1.element > T2.element;
    }
};

vector<int> mergeKSortedArrays(vector<vector<int>*> input)
{
    vector<int> output;
    priority_queue<Triplet, vector<Triplet>, CompareElement> pq;
    for(int i = 0; i < input.size(); i++)
    {
        //we are using zero index as it is a vector pointer 
        // and to access the array we will use 0 index.
        
        Triplet T(input[i][0].at(0), i, 0);
        pq.push(T);
    }

    while(!pq.empty())
    {
        output.push_back(pq.top().element);
        Triplet T = pq.top();
        if(T.elemIndex < (input[T.arrIndex][0].size()-1))
        {
            T.elemIndex++;
            T.element = input[T.arrIndex][0].at(T.elemIndex);
            pq.push(T);
        }
        pq.pop();
    }
    return output;
}

int main() {
	
	int k;
	cin >> k;
    vector<vector<int>*> input;
    for(int j = 1; j <= k; j++) {
        int size;
        cin >> size;
        vector<int> *current = new vector<int>;
        
        for(int i = 0; i < size; i++) {
            int a;
            cin >> a;
            current -> push_back(a);
        }
        input.push_back(current);
    }
	
	
	vector<int> output = mergeKSortedArrays(input);

	for(int i = 0; i < output.size(); i++)
		cout << output[i] << " ";
	
	return 0;
}
