// PROBLEM: https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/

#include <vector>
#include <iostream>
using namespace std;

/*
 * O(log n) solution to finding the minimum element in a sorted array of distinct elements
 * rotated some number of times
 */
int findMin(const vector<int> &nums) {
    int n = (int) nums.size();

    // no rotations
    if (nums[0] < nums[n - 1]) {
        return nums[0];
    }

    int lo = 0;
    int hi = n - 1;
    int comp = nums[0];

    while (hi - lo > 1) {
        int mid = (lo + hi) / 2;
        if (nums[mid] > comp) {
            lo = mid;
        } else {
            hi = mid;
        }
    }

    if (nums[lo] >= comp) {
        return nums[hi];
    } else {
        return nums[lo];
    }
}