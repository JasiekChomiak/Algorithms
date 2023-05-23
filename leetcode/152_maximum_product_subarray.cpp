// PROBLEM: https://leetcode.com/problems/maximum-product-subarray/description/

#include <vector>
#include <iostream>
using namespace std;

/*
 * This is an ugly solution that runs in 3n + O(1) in the worst case scenario.
 * It is possible (I think) to do it in just one pass, but there are a lot
 * of edge cases and it's generally pretty ugly. It should be possible
 * to get it to 2n + O(1) with some changes and tinkering in the maxProductOfSegment function.
 */
int maxProductOfSegment(const vector<int> &nums, int start, int end) {
    if (start + 1 == end) {
        return nums[start];
    }

    int totalProduct = 1;
    int negativeCount = 0;
    int firstNegativeIndex = -1;
    int lastNegativeIndex = -1;

    for (int i = start; i < end; i++) {
        totalProduct *= nums[i];
        if (nums[i] < 0) {
            if (firstNegativeIndex == -1) {
                firstNegativeIndex = i;
            }

            ++negativeCount;
            lastNegativeIndex = i;
        }
    }

    if (negativeCount % 2 == 0) {
        return totalProduct;
    }

    int withoutFirstProduct = totalProduct;
    for (int i = start; i <= firstNegativeIndex; ++i) {
        withoutFirstProduct /= nums[i];
    }

    int withoutLastProduct = totalProduct;
    for (int i = lastNegativeIndex; i < end; ++i) {
        withoutLastProduct /= nums[i];
    }

    return max(withoutFirstProduct, withoutLastProduct);
}

int maxProductOfSubarray(const vector<int> &nums) {
    int n = (int) nums.size();
    int maxProduct = nums[0];

    int i = 0;
    while (i < n) {
        // skip 0, 0, 0..., x
        while (i < n && nums[i] == 0) {
            maxProduct = max(maxProduct, 0);
            ++i;
        }

        if (i == n) {
            return maxProduct;
        }

        int j = i;

        // find next zero
        while (j < n && nums[j] != 0) {
            ++j;
        }

        if (j != n) {
            maxProduct = max(maxProduct, 0);
        }

        int maxProductSeg = maxProductOfSegment(nums, i, j);
        maxProduct = max(maxProduct, maxProductSeg);
        i = j + 1;
    }

    return maxProduct;
}