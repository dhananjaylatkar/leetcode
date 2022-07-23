class STNode {
public:
    int start;
    int end;
    int count;
    STNode* left;
    STNode* right;
    
    STNode(int s, int e)
    {
        start = s;
        end = e;
        count = 0;
        left = NULL;
        right = NULL;
    }
};

class Solution {
private:
    STNode* buildST(int s, int e)
    {
        if (s > e)
        {
            return NULL;
        }
        STNode* curr = new STNode(s, e);
        
        if (s == e)
        {
            return curr;
        }
        
        int mid = s + (e-s)/2;
        
        curr->left = buildST(s, mid);
        curr->right = buildST(mid+1, e);
        
        return curr;
    }
    
    void updateST(STNode* root, int idx)
    {
        if (root == NULL)
        {
            return;
        }
        
        if (root->start == idx && root->end == idx)
        {
            root->count += 1;
            return;
        }
        
        int mid = root->start + (root->end - root->start)/2;
        
        if (idx <= mid)
        {
            updateST(root->left, idx);
        }
        else
        {
            updateST(root->right, idx);
        }
        
        root->count = root->left->count + root->right->count;
    }
    
    int countST(STNode* root, int s, int e)
    {
        if (root == NULL || s > e) 
        {
            return 0;
        }
        
        if (root->start == s && root->end == e)
        {
            return root->count;
        }
        
        int mid = root->start + (root->end - root->start)/2;
        
        if (e <= mid)
        {
            return countST(root->left, s, e);
        }
        else if (s > mid)
        {
            return countST(root->right, s, e);
        }
        return countST(root->left, s, mid) + countST(root->right, mid+1, e);
    }
public:
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n, 0);
        
        int _min = nums[0];
        int _max = nums[0];
        
        for (int num: nums)
        {
            _min = min(_min, num);
            _max = max(_max, num);
        }
        
        STNode* root = buildST(_min, _max);
        for (int i = n-1; i >= 0; i--)
        {
            updateST(root, nums[i]);
            res[i] = countST(root, _min, nums[i]-1);
        }
        return res;
    }
};