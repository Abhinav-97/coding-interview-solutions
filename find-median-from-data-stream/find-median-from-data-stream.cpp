class MedianFinder {
private:
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int> > minHeap;
public:
    /** initialize your data structure here. */
    
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(maxHeap.empty() || num < maxHeap.top())
        {
            maxHeap.push(num);
        }
        else{
            minHeap.push(num);
        }
        if(maxHeap.size() > minHeap.size()+1) // if size difference is greater than 1 then push maxHeap element to minHeap;
        {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }
        else if(minHeap.size() > maxHeap.size()+1) // if size difference is greater than 1 then push maxHeap element to minHeap;
        {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }
    
    double findMedian() {
        if(maxHeap.size() == minHeap.size())
        {
            return (double)(maxHeap.top()+minHeap.top())/2;
        }
        else if(maxHeap.size() > minHeap.size())
        {
            return (double)maxHeap.top();
        }
            
        return (double)minHeap.top();
    }
};
​
/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
