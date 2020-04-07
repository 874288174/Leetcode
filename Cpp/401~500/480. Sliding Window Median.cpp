class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {    
        vector<double> res;
        unordered_map<int, int> hash_table;
        priority_queue<int> low;                                  // max heap
        priority_queue<int, vector<int>, greater<int> > high;     // min heap

        int i = 0;

        while (i < k) low.push(nums[i++]);

        for (int j = 0; j < k / 2; j++) {
            high.push(low.top());
            low.pop();
        }

        while (1) {
        // get median of current window
            res.push_back(k & 1 ? low.top() : (low.top() + high.top()) * 0.5);
            if (i >= nums.size()) break;                          
            int out_num = nums[i - k], in_num = nums[i++];          
            int balance = out_num <= low.top() ? -1 : 1;
            
            ++hash_table[out_num];
        // in_num enters window
            if (!low.empty() && in_num <= low.top()) {
                ++balance;
                low.push(in_num);
            } else {
                --balance;
                high.push(in_num);
            }

        // re-balance heaps
            if (balance < 0) {                  // `lo` needs more valid elements
                low.push(high.top());
                high.pop();
                balance++;
            }
            if (balance > 0) {                  // `hi` needs more valid elements
                high.push(low.top());
                low.pop();
                balance--;
            }

        // remove invalid numbers that should be discarded from heap tops
            while (hash_table[low.top()]) {
                hash_table[low.top()]--;
                low.pop();
            }
            while (!high.empty() && hash_table[high.top()]) {
               hash_table[high.top()]--;
               high.pop();
            }
        }
        return res;
    }
};




class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        vector<double> res;
        multiset<int> window(nums.begin(), nums.begin() + k);
        auto mid = next(window.begin(), k / 2);
       
        for (int i = k;; i++) {
        // Push the current median
            res.push_back(((double)(*mid) + *next(mid, k % 2 - 1)) * 0.5);

        // If all done, break
            if (i == nums.size()) break;

        // Insert incoming element
            window.insert(nums[i]);
            if (nums[i] < *mid)  mid--;                

        // Remove outgoing element
            if (nums[i - k] <= *mid) mid++;
            window.erase(window.lower_bound(nums[i - k]));
        }

        return res;
    }
};