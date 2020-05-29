class Solution {
public:
   class Bucket {
       public:
       bool used = false;
       int minval = numeric_limits<int>::max();        // same as INT_MAX
       int maxval = numeric_limits<int>::min();        // same as INT_MIN
   
   };

    int maximumGap(vector<int>& nums) {
        if (nums.size() < 2) return 0;
        int Min = *min_element(nums.begin(), nums.end());
        int Max = *max_element(nums.begin(), nums.end());
        int bucketSize = max(1, (Max - Min) / ((int)nums.size() - 1));        
        int bucketNum = (Max - Min) / bucketSize + 1;                         // number of buckets
        vector<Bucket> buckets(bucketNum);
        
        for (auto &num : nums) {
            int bucketIdx = (num - Min) / bucketSize;                          // locating correct bucket
            buckets[bucketIdx].used = true;        
            buckets[bucketIdx].minval = min(num, buckets[bucketIdx].minval);  
            buckets[bucketIdx].maxval = max(num, buckets[bucketIdx].maxval);
        }

        int prevBucketMax = Min, maxGap = 0;
        for (auto &bucket : buckets) {
            if (!bucket.used) continue;
            maxGap = max(maxGap, bucket.minval - prevBucketMax);
            prevBucketMax = bucket.maxval;
        }
        return maxGap;
    }
};