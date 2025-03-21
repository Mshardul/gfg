"""
Difficulty: Medium

You are given an array of integer arr[] where each number represents a vote to a candidate. Return the candidates that have votes greater than one-third of the total votes, If there's not a majority vote, return an empty array. 

Note: The answer should be returned in an increasing format.

Examples:

Input: arr[] = [2, 1, 5, 5, 5, 5, 6, 6, 6, 6, 6]
Output: [5, 6]
Explanation: 5 and 6 occur more n/3 times.

Input: arr[] = [1, 2, 3, 4, 5]
Output: []
Explanation: o candidate occur more than n/3 times.

Constraint:
1 <= arr.size() <= 10^6
-10^9 <= arr[i] <= 10^9
"""
class Solution:
    # Function to find the majority elements in the array
    def findMajority(self, arr):
        n = len(arr)
        occur = {}
        for ele in arr:
            if ele not in occur:
                occur[ele] = 0
            occur[ele] += 1
        ans = []
        for ele, occ in occur.items():
            if occ>n//3:
                ans.append(ele)
        ans.sort()
        return ans 