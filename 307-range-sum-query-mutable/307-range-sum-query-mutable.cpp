class STNode {
public:
    int sum;
    STNode* left;
    STNode* right;
    int l;
    int r;
    
    STNode (int _sum, int _l, int _r)
    {
        sum = _sum;
        l = _l;
        r = _r;
        left = NULL;
        right = NULL;
    }
};

class NumArray {
private:
    vector<int> prefix_sum;
    STNode* _root;
    vector<int> _nums;
    STNode* buildTree(int l, int r)
    {
        if (l > r) return NULL;

        int sum = prefix_sum[r] - (l==0 ? 0 :prefix_sum[l-1]);
        STNode* curr = new STNode(sum, l, r);
        
        if (l == r) return curr;

        int mid = l+(r-l)/2;

        curr->left = buildTree(l, mid);
        curr->right = buildTree(mid+1, r);
        return curr;
    }
    
    void updateTree(STNode* root, int idx, int val) // val is diff of curr and new
    {
        if (root == NULL)
        {
            return;
        }
        int mid = root->l + (root->r - root->l)/2;
        root->sum += val;
        
        if (root->r == idx && root->l == idx)
        {
            return;
        }
        
        if (mid >= idx)
        {
            updateTree(root->left, idx, val);
        }
        else
        {
            updateTree(root->right, idx, val);
        }
    }
    
    int getSum (STNode* root, int l, int r)
    {
        if (root->l == l && root->r == r)
        {
            return root->sum;
        }
        
        int mid = root->l + (root->r - root->l)/2;
        
        if (mid >= r)
        {
            return getSum(root->left, l, r);
        }
        else if (mid < l)
        {
            return getSum(root->right, l, r);
        }
        return getSum(root->left, l, mid) + getSum(root->right, mid+1, r);
    }
public:
    NumArray(vector<int>& nums) {
        int n = nums.size();
        prefix_sum.push_back(nums[0]);
        for (int i = 1; i < n; i++)
        {
            prefix_sum.push_back(nums[i]+prefix_sum[i-1]);
        }
        _root = buildTree(0, n-1);
        _nums = nums;
    }
    
    void update(int index, int val) {
        updateTree(_root, index, val-_nums[index]);
        _nums[index] = val;
    }
    
    int sumRange(int left, int right) {
        return getSum(_root, left, right);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */