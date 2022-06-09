class StockSpanner {
private:
    stack<int> s;
    vector<int> all_stocks;
public:
    StockSpanner() {
        
    }
    
    int next(int price) {
        int res = 0;
        if (s.empty())
        {
            all_stocks.push_back(price);
            s.push(0);
            res = 1;
        }
        else
        {
            all_stocks.push_back(price);
            while(!s.empty() && all_stocks[s.top()] <= price)
            {
                s.pop();
            }
            res = s.empty() ? (all_stocks.size()) : (all_stocks.size() - s.top() -1);
            s.push(all_stocks.size()-1);
        }
        return res;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */