/*
217. Contains Duplicate

Given an integer array nums, return true if any value appears at least twice in the array,
and return false if every element is distinct.

Example 1:
Input: nums = [1,2,3,1]
Output: true

Example 2:
Input: nums = [1,2,3,4]
Output: false

Example 3:
Input: nums = [1,1,1,3,3,4,3,2,4,2]
Output: true
*/

//Time complexity:  O(n)
//Space complexity: O(n)
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> seen;
        for(int i =0;i<nums.size();i++){
            if(seen.find(nums[i]) != seen.end())
                return true;
            seen.insert(nums[i]);
        }
        return false;
    }
};

//OR

//Time complexity:  O(n)
//Space complexity: O(n)
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> s(nums.begin(), nums.end());
        return (s.size() != nums.size());
    }
};