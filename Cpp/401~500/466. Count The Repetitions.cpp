class Solution {
public:
    //same as 418
    int getMaxRepetitions(string s1, int n1, string s2, int n2) {
	    int n = s2.length();
        // s2中 每个字符开头，能在 s1中 重复多少次
	    vector<int> repeatNum(n);
	    // s2中 每个字符开头，尽可能重复，下一次在 s1中 出现的第一个字符的索引
	    vector<int> nextChar(n);

	    for (int i = 0; i < n; i++) {
		    int cnt = 0, idx = i;
		    for (auto c : s1) {
			    if (c == s2[idx]) {
				    if (++idx == n) {
					    idx = 0;
					    cnt++;
				    } 
			    }
		    }
		    nextChar[i] = idx;
		    repeatNum[i] = cnt;
    	}

	    int res = 0, next = 0;

	    while (n1--) {
		    res += repeatNum[next];
		    next = nextChar[next];
	    }
        return res / n2;
    }
};