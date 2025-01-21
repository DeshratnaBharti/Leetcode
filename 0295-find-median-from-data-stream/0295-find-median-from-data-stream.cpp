class MedianFinder {
public:
    priority_queue<int>lmaxhp;
    priority_queue<int,vector<int>,greater<int>>rmhp;
    MedianFinder() {
       
    }
    
    void addNum(int num) {
         if(lmaxhp.empty() or num<lmaxhp.top()) lmaxhp.push(num);
        else rmhp.push(num);
        if(abs((int)lmaxhp.size()-(int) rmhp.size())>1){
            rmhp.push(lmaxhp.top());
            lmaxhp.pop();
        }else if(lmaxhp.size() < rmhp.size()){
            lmaxhp.push(rmhp.top());
            rmhp.pop();
        }
        
    }
    
    double findMedian() {
        if(lmaxhp.size() == rmhp.size()){
            return (double)(lmaxhp.top()+rmhp.top())/2;
        }
        return lmaxhp.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */