class FreqStack {
public:
priority_queue<tuple<int,int,int>>pq;
int timer;
map<int,int>mp;
    FreqStack() {
        timer=0;
    }
    
    void push(int val) {
        mp[val]++;
        pq.push({mp[val],timer,val});
        timer++;
    }
    int pop() {
      auto [freq,timer,val]=pq.top();
      pq.pop();
      mp[val]--;
      return val;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */