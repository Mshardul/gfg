"""
Difficulty: Medium

Given an array of integers arr[] representing a permutation, implement the next permutation that rearranges the numbers into the lexicographically next greater permutation. If no such permutation exists, rearrange the numbers into the lowest possible order (i.e., sorted in ascending order). 

Note - A permutation of an array of integers refers to a specific arrangement of its elements in a sequence or linear order.

Examples:

Input: arr = [2, 4, 1, 7, 5, 0]
Output: [2, 4, 5, 0, 1, 7]
Explanation: The next permutation of the given array is {2, 4, 5, 0, 1, 7}.

Input: arr = [3, 2, 1]
Output: [1, 2, 3]
Explanation: As arr[] is the last permutation, the next permutation is the lowest one.

Input: arr = [3, 4, 2, 5, 1]
Output: [3, 4, 5, 1, 2]
Explanation: The next permutation of the given array is {3, 4, 5, 1, 2}.

Constraints:
1 ≤ arr.size() ≤ 10^5
0 ≤ arr[i] ≤ 10^5
"""

class Solution:
    def nextPermutation(self, arr):
        """
        Test Cases Passed: 1110 /1111
        1 TLE
        """

        n = len(arr)
        if n<2:
            return 

        last_ele = arr[-1]
        elements = [last_ele]
        mn = last_ele
        mx = last_ele
        
        ind = n-2
        found = False
        while ind>=0:
            ele = arr[ind]
            
            if ele < mx:  # crux
                ele_to_repl = 10_001
                for temp_ind, element in enumerate(elements):
                    if element>ele and element<ele_to_repl:
                        ele_to_repl = min(ele_to_repl, element)
                        elements[temp_ind] = ele
                        arr[ind] = ele_to_repl
                        found = True
                if found:
                    break
            
            mn = min(mn, ele)
            mx = max(mx, ele)
            elements.append(ele)
            
            ind -= 1

        sorted(elements)
        for element in elements:
            ind += 1
            arr[ind] = element

    def nextPermutation2(self, arr):
        """
        Tried removing `elements` list, but still getting tle
        Test Cases Passed: 1110 /1111
        1 TLE
        """
        n = len(arr)
        if n<2:
            return 

        last_ele = arr[-1]
        mn = last_ele
        mx = last_ele
        
        ind = n-2
        found = False
        while ind>=0:
            ele = arr[ind]
            
            if ele < mx:  # crux
                ele_to_repl = 10_001
                
                temp_ind = n-1
                while temp_ind>ind:
                    element = arr[temp_ind]
                    if element>ele and element<ele_to_repl:
                        found = True
                        break
                    temp_ind -= 1
                if found:
                    arr[ind], arr[temp_ind] = arr[temp_ind], arr[ind]
                    break
            
            mn = min(mn, ele)
            mx = max(mx, ele)
            
            ind -= 1

        arr[ind+1:] = sorted(arr[ind+1:])
