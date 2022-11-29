class RandomizedSet {
private:
    int n = 0;
    vector<int> s;
    unordered_map<int, int> m; // val, idx
public:
    RandomizedSet() {
        srand(time(0));
    }
    
    bool insert(int val) {
        if (m.find(val) == m.end())
        {
            m[val] = n;
            n++;
            if (s.size() == n-1)
            {
                s.push_back(val);
            }
            else
            {
                s[n-1] = val;
            }
            // cout << "insert n=" << n << " ";
            // for (int it: s) cout << it << " "; cout << endl;
            return true;
        }
        return false;
    }
    
    bool remove(int val) {
        if (m.find(val) == m.end())
        {
            return false;
        }
        n--;
        int idx = m[val];
        m[s[n]] = idx;
        swap(s[idx], s[n]);
        
        m.erase(val);
        // cout << "remove n=" << n << " ";
        // for (int it: s) cout << it << " "; cout << endl;
        return true;
    }
    
    int getRandom() {
        
        return s[int(rand())%n];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */