class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        vector<double> res;
        unordered_map<int, int> hash;
        priority_queue<int, vector<int>> low;
        priority_queue<int, vector<int>, greater<int>> high;
        
        int i = 0;
        
        while (i < k) low.push(nums[i++]);
        for (int i = k/2; i > 0; --i) {
            high.push(low.top());
            low.pop();
        }
        
        auto pop_invalid_element = [&hash](auto &pq) {
            while (!pq.empty() && hash[pq.top()])  { 
                --hash[pq.top()]; 
                pq.pop(); 
            }
        };
        
        while (true) {
            pop_invalid_element(low);
            pop_invalid_element(high);
            
            if (k % 2) res.push_back(low.top());
            else res.push_back(((double)low.top() + high.top()) / 2);
            
            if (i == nums.size()) break;
            int out = nums[i-k], in = nums[i++], balance = 0;
            
            hash[out]++;
            if (out <= low.top()) {
                --balance;
                pop_invalid_element(low);
            } 
            else {
                ++balance; 
                pop_invalid_element(high);
            }
            
            // now the top element is always valid
            // the reason when low is empty we put 'in' into high is
            // high is not always empty, and we should put it in high
            // to sort it
            if (!low.empty() && in <= low.top())  { 
                ++balance; low.push(in); 
            }
            else {
                --balance; high.push(in); 
            }
            
            //note: balance == -2 or 2 or 0
            //now the top element is always valid
            if (balance < 0)  {
                low.push(high.top()); high.pop();
            }
            else if (balance > 0)  {
                high.push(low.top()); low.pop();
            }
        }
        return res;
    }
};



/*
multiset插入相同数，为upper_bound返回值之前插入，即插入数在相同数的最后面
删除数为lower_bound，即删除数为相同数的最前面
*/
class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        vector<double> res;
        multiset<int> window(nums.begin(), nums.begin() + k);
        auto mid = next(window.begin(), k / 2);
       
        for (int i = k;; i++) {
            res.push_back(((double)(*mid) + *next(mid, k % 2 - 1)) * 0.5);

            if (i == nums.size()) break;

            window.insert(nums[i]);
            if (nums[i] < *mid)  mid--;                

            if (nums[i - k] <= *mid) mid++;
            window.erase(window.lower_bound(nums[i - k]));
        }

        return res;
    }
};

//一个复杂但易懂的版本
class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        vector<double> res;
        multiset<int> window(nums.begin(), nums.begin() + k);
        auto mid = next(window.begin(), k / 2);
       
        for (int i = k;; i++) {
            res.push_back(((double)(*mid) + *prev(mid, 1 - k % 2)) * 0.5);
            if (i == nums.size()) break;
            
            window.insert(nums[i]);
            
            if (nums[i] < *mid && nums.size() % 2 == 1) --mid;
            else if (nums[i] >= *mid && nums.size() % 2 == 0) ++mid;
            
            auto it = window.lower_bound(nums[i - k]);
            
            if (it == mid)  (nums.size() % 2 == 1) ? ++mid : --mid;
            else if (nums[i-k] <= *mid && nums.size() % 2 == 1) ++mid;
            else if (nums[i-k] > *mid && nums.size() % 2 == 0) --mid;                          
            
            window.erase(it);
        }

        return res;
    }
};