#include <iostream>
#include <vector>
#include <deque>
using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        vector<int> res;

        // 1st window
        for (int i = 0; i < k; i++) {
            while (dq.size() > 0 && nums[dq.back()] <= nums[i]) {
                dq.pop_back();
            }
            dq.push_back(i);
        }

        for (int i = k; i < nums.size(); i++) {
            res.push_back(nums[dq.front()]);

            // remove not part of curr window
            while (dq.size() > 0 && dq.front() <= i - k) {
                dq.pop_front();
            }

            // remove the smaller values
            while (dq.size() > 0 && nums[dq.back()] <= nums[i]) {
                dq.pop_back();
            }

            dq.push_back(i);
        }

        res.push_back(nums[dq.front()]);
        return res;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};
    int k = 3;

    vector<int> ans = sol.maxSlidingWindow(nums, k);

    cout << "Sliding Window Maximums: ";
    for (int x : ans) {
        cout << x << " ";
    }
    return 0;
}
