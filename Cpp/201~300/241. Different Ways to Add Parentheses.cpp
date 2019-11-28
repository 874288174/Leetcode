class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
        vector<int> output;
        for (int i = 0; i < input.size(); i++) {
            char c = input[i];
            if (ispunct(c)) {
                for (int a : diffWaysToCompute(input.substr(0, i))) {
                    for (int b : diffWaysToCompute(input.substr(i+1))) {
                        output.push_back( c == '+' ? a+b : 
                                                     c == '-' ? a-b : a*b);
                    }
                }
            }
        }
        return output.size() ? output : vector<int> {stoi(input)};
    }
};






////////////////////DP////////////////////////////////////
class Solution {
public:
	vector<int> diffWaysToCompute(string input) {
		unordered_map<string, vector<int>> dpMap;
		return computeWithDP(input, dpMap);
	}

private:
    vector<int> computeWithDP(string input, unordered_map<string, vector<int>> &dpMap) {
		vector<int> result;
		int sz = input.size();
		for (int i = 0; i < sz; i++) {
			char c = input[i];
			if (ispunct(c)) {
				string substr = input.substr(0, i);
				auto res1 = dpMap.find(substr) != dpMap.end() ? dpMap[substr]
		                                                      : computeWithDP(substr, dpMap);
				substr = input.substr(i+1);
				auto res2 = dpMap.find(substr) != dpMap.end() ? dpMap[substr]
		                                                     : computeWithDP(substr, dpMap);
				for (auto n1 : res1) {
					for (auto n2 : res2) {
						result.push_back(c == '+' ? n1+n2
                                                  : c == '-' ? n1-n2 : n1*n2);
					}
				}
			}
		}

		if (result.empty()) result.push_back(atoi(input.c_str()));
		return dpMap[input] = result;
	}
};