// PROBLEM: https://leetcode.com/problems/product-of-array-except-self/description/
#include <vector>
using namespace std;

vector <int> productExceptSelf(const vector<int>& nums) {
    int productOfAll = 1;
    int zeroesCount = 0;

    for (auto num: nums) {
        if (num == 0) {
            ++zeroesCount;
        } else {
            productOfAll *= num;
        }
    }

    if (zeroesCount > 1) {
        return vector<int>(nums.size(), 0);
    }

    vector<int> result(nums.size());
    for (int i = 0; i < nums.size(); ++i) {
        if (nums[i] == 0) {
            result[i] = productOfAll;
        } else {
            if (zeroesCount == 0) {
                result[i] = productOfAll / nums[i];
            } else {
                result[i] = 0;
            }
        }
    }

    return result;
}
