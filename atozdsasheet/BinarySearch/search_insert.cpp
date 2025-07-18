/*
Given a sorted array of distinct integers and a target value, return the index
if the target is found. If not, return the index where it would be if it were
inserted in order.

You must write an algorithm with O(log n) runtime complexity.

Example 1:

Input: nums = [1,3,5,6], target = 5
Output: 2

Example 2:

Input: nums = [1,3,5,6], target = 2
Output: 1

Example 3:

Input: nums = [1,3,5,6], target = 7
Output: 4

Constraints:

    1 <= nums.length <= 104
    -104 <= nums[i] <= 104
    nums contains distinct values sorted in ascending order.
    -104 <= target <= 104

*/

#include <iostream>
#include <vector>
class Solution {
public:
  int searchInsert(std::vector<int> &nums, int target) {
    int low = 0;
    int high = nums.size() - 1;
    int mid;
    while (low <= high) {
      mid = (low + high) / 2;
      if (target == nums[mid])
        return mid;
      if (target > nums[mid])
        low = mid + 1;
      if (target < nums[mid])
        high = mid - 1;
    }
    return low;
  }
};
int main(int argc, char *argv[]) {
  Solution s;
  std::vector<int> nums = {1, 3, 5, 6};
  std::cout << s.searchInsert(nums, 7);
  return 0;
}
