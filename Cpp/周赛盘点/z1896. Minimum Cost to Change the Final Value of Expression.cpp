class Solution {
public:
  using pii = pair<int, int>;

  int minOperationsToFlip(string expression) {
    // p.first表示当前状态变为0需要的最少的操作次数
    // p.second表示当前状态变为1需要的最少的操作次数
    stack<pii> nums;
    stack<char> ops;
    for (auto c : expression) {
      if (c == '0' || c == '1' || c == ')') {
        if (c == '0')
          nums.emplace(0, 1);
        else if (c == '1')
          nums.emplace(1, 0);
        else
          ops.pop();

        if (!ops.empty() && ops.top() != '(') {
          auto [p1, q1] = nums.top();
          nums.pop();
          auto [p2, q2] = nums.top();
          nums.pop();
          if (ops.top() == '&')
            nums.emplace(min(p1, p2), min(q1 + q2, 1 + min(q1, q2)));
          else
            nums.emplace(min(p1 + p2, 1 + min(p1, p2)), min(q1, q2));
          ops.pop();
        }
      } else
        ops.push(c);
    }
    return max(nums.top().first, nums.top().second);
  }
};