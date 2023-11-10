#include <list>

using namespace std;
class FrontMiddleBackQueue {
private:
    list<int> FMBQueue;
public:
    FrontMiddleBackQueue() {
        
    }
    
    void pushFront(int val) {
        FMBQueue.insert(FMBQueue.begin(), val);
    }
    
    void pushMiddle(int val) {
        int m = FMBQueue.size();
        auto it = next(FMBQueue.begin(), int(m/2));
        FMBQueue.insert(it, val);
    }
    
    void pushBack(int val) {
        FMBQueue.insert(FMBQueue.end(), val);
    }
    
    int popFront() {
        if (FMBQueue.size()==0) return -1;
        int value = FMBQueue.front();
        FMBQueue.pop_front();
        return value;
    }
    
    int popMiddle() {
        if (FMBQueue.size()==0) return -1;
        int m = FMBQueue.size()-1;
        auto it = next(FMBQueue.begin(), int(m/2));
        int value = *it;
        FMBQueue.erase(it);
        return value;
    }
    
    int popBack() {
        if (FMBQueue.size()==0) return -1;
        int value = FMBQueue.back();
        FMBQueue.pop_back();
        return value;
    }
};

/**
 * Your FrontMiddleBackQueue object will be instantiated and called as such:
 * FrontMiddleBackQueue* obj = new FrontMiddleBackQueue();
 * obj->pushFront(val);
 * obj->pushMiddle(val);
 * obj->pushBack(val);
 * int param_4 = obj->popFront();
 * int param_5 = obj->popMiddle();
 * int param_6 = obj->popBack();
 */