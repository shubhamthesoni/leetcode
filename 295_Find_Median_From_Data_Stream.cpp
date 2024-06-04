class MedianFinder {
    priority_queue<int> L;
    priority_queue<int, vector<int>, greater<int>> R;
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
      int len1 = L.size();
      int len2 = R.size();

      if((len1 == 0) || (num <= L.top)) { L.push(num); len1++; }
      else { R.push(num); len2++; }

      if(abs(len1-len2) > 1)
      {
        if(len1 > len2) { R.push(L.top()); L.pop(); }
        else { L.push(R.top()); R.pop(); }
      }
    }
    
    double findMedian() {
      int len1 = L.size();
      int len2 = R.size();
      if(len1 == len2) return double(L.top() + R.top())/2;   
      else return (len1 > len2) ? L.top() : R.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
