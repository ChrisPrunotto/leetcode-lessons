//https://leetcode.com/problems/two-sum/
//Given an array of numbers, find the pair of numbers that adds up to the target.

//Brute Force Method.
//This is a simple method for looping through each element in the table, and then testing each other number until we find a pair of numbers that adds up to the target.
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        for(int i=0; i<nums.size(); i++)
        {
            for(int j= i+1; j<nums.size();j++)
            {
                if (nums[j] + nums[i] == target) {
                    return {i, j};
                }
            }
        }
        return {};
    }
};
