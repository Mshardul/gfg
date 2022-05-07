/* 
Problem Statement: Given two sorted arrays A and B of length L1 and L2, we can get a set of sums(add one element from the first and one from second). Find the Nth element in the set considered in sorted order.
Note: Set of sums should have unique elements.

Example1: 
Input: L1 = 2, L2 = 2, A = {1, 2}, B = {3, 4}, N = 3
Output: 6
Explaination: The set of sums are in the order 4, 5, 6.

Example2: 
Input: L1 = 5, L2 = 4, A = {1, 3, 4, 8, 10}, B = {20, 22, 30, 40}, N = 4
Output: 25
Explaination: The numbers before it are 21, 23 and 24.

Example3: 
Input: L1 = 4, L2 = 4, A = {1, 2, 3, 4}, B = {1, 2, 3, 4}, N = 16
Output: -1
Explanation: The set of sums contain only 7 elements: 2, 3, 4, 5, 6, 7, 8
*/

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
  int nthItem(int L1, int L2, int A[], int B[], int N) {
    set<int> setSum;
    priority_queue<int, vector<int>, greater<int> > qSum;
    for(int i=0; i<L1; i++) {
      for (int j=0; j<L2; j++) {
        int temp = A[i] + B[j];
        set<int>::iterator index = setSum.find(temp);
        if (index == setSum.end()) { // temp doesn't exist in the set
          setSum.insert(temp);
          qSum.push(temp);
        }
      }
    }
    if (qSum.size() < N) {
      return -1;
    }
    for(int i=0; i<N-1; i++) {
      qSum.pop();
    }
    return qSum.top();
  }
};

int main() {
  int L1 = 4;
  int L2 = 4;
  int A[5] = {1, 2, 3, 4};
  int B[4] = {1, 2, 3, 4};
  int N = 16;
  Solution s = Solution();
  int x = s.nthItem(L1, L2, A, B, N);
  cout<<x;
  return 0;
}