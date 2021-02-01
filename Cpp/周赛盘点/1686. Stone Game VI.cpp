/*
假设A选择的石子为a1,a2,...,ak 
A的收益为 A[a1]+A[a2]+...+A[ak]
B的收益为 Sum(Bob)-B[a1]-B[a2]-...-B[ak]
A-B收益：A[a1]+B[a1] + A[a2]+B[a2] + ... + A[ak]+B[ak] - Sum(Bob)
*/
class Solution {
public:
    int stoneGameVI(vector<int>& A, vector<int>& B) {
		int n = A.size(), Sub = 0;
		for(int i = 0; i < n; i++){
			A[i] += B[i];
            Sub -= B[i];
		}
		sort(A.rbegin(), A.rend());
		for (int i = 0; i < n; i++){
			if (i%2 == 0)  Sub += A[i];
		}
		if (Sub == 0) return 0;
		else if(Sub > 0) return 1;
		else return -1;
    }
};