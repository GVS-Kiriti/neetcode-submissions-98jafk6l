class MovingAverage {
public:
    queue<int>q;
    int len;
    int curr;
    int tot;
    MovingAverage(int size) {
        len=size;
        tot=size;
        while(!q.empty()){
            q.pop();
        }
        curr=0;
    }
    
    double next(int val) {
        double ret;
        curr+=val;
        len--;
        q.push(val);
        if(len<0){
            curr-=q.front();
            q.pop();
            len++;
        }
        return curr*1.0/(tot-len);
    }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */
