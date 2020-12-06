class Solution {
public:
	int findIntegers(int num) {
		int len = 1;
		while (num >> len) ++len;
		vector<int> f(len + 1, 0);
		f[0] = 1; f[1] = 2;
		for (int i = 2; i <= len; i++) f[i] = f[i-1] + f[i-2];
        return helper(num, f);
	}

    int helper(int num, const vector<int> &f) {
        if (num <= 1) return num + 1;
        int len = 1;
		while (num >> len) ++len;
        //11开头
		if (num >> (len-2) == 3) return f[len];
		else {
			int temp = (1<<(len - 1)) - 1;
			return f[len - 1] + helper(temp&num, f);
		}
    }
};