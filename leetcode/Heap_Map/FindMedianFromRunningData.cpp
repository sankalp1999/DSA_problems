/*
Main idea
1. Use a maxheap to maintain the first half of array. This way, you will always have the mid available at the top.
2. Use a minheap to keep track of the second half of the array.

How to do this?
We compare the new element with maxheap.top(), if it is smaller, then it certainly belongs to the lower part of 
the array. Otherwise it goes to the minheap.

Balancing 
If there is a size difference of more than two, then pop out one element from the heap having 
more elements and push that element into the smaller heap.

NOTE: When size is unbalanced, we send the min of minheap or max of maxheap to the other part.
This does not change the answer.

Finding Median
If the size of the list is even, then take half of sum of both the tops.
Otherwise, just return the heap's top which is having more elements.

*/

class MedianFinder {
public:
    /** initialize your data structure here. */
     priority_queue<int> leftHeap; // Max Heap
    priority_queue<int,vector<int>,greater<int>> rightHeap;
    MedianFinder() {
       
    }
    
    void addNum(int num) {
        if(leftHeap.empty())
        {
            leftHeap.push(num);
            return;
        }
        
        if(leftHeap.top() > num) // It belongs to the left half
        {
            leftHeap.push(num);
        }
        else rightHeap.push(num); // right half
        
        
        // If size not equal, then sending the max or min element
        // won't change the structure.
        // 1 3    5 5 6
        if(leftHeap.size() > rightHeap.size() + 1)
        {
            rightHeap.push(leftHeap.top());
            leftHeap.pop();
        }
        else if(rightHeap.size() > leftHeap.size() + 1 )
        {
            leftHeap.push(rightHeap.top());
            rightHeap.pop();
        }
    }
    
    double findMedian() {
        
        if(rightHeap.empty() )return leftHeap.top();
        if(leftHeap.size() != rightHeap.size() )
        {
            return leftHeap.size() > rightHeap.size() ? leftHeap.top() : rightHeap.top();
        }
        int a = leftHeap.top();
        int b= rightHeap.top();
        return ( (a*1.0 + b) / 2.0);
    }
};

