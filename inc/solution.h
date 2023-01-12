#ifndef _SYCLEETCODESOL_H_
#define _SYCLEETCODESOL_H_

#include <vector>
#include <string>
#include <tuple>
#include <map>
#include <queue>
#include <algorithm>

struct ListNode 
{
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
};

struct TreeNode 
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
  template <typename T>
  using Vec = std::vector<T>;
  using String = std::string;
// Methods
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2);                 // #2    Add Two Numbers 
	int       lengthOfLongestSubstring(String s);                        // #3    Longest Substring Without Repeating Characters
	String    longestPalindrome(String s);                               // #5    Longest Palindromic Substring
	bool      isPalindrome(int x);                                       // #9    Palindrome Number
	int       romanToInt(String s);                                      // #13   Roman to Integer 
	String    longestCommonPrefix(Vec<String>& strs);                    // #14   Longest Common Prefix 
	bool      isValid(String s);                                         // #20   Valid Parentheses
	ListNode* mergeTwoLists(ListNode* list1, ListNode* list2);           // #21   Merge Two Sorted Lists
	int       removeDuplicates(Vec<int>& nums);                          // #26   Remove Duplicates from Sorted Array
	int       removeElement(Vec<int>& nums, int val);                    // #27   Remove Element
	int       strStr(String haystack, String needle);                    // #28   Implement strStr()
	int       searchInsert(Vec<int>& nums, int target);                  // #35   Search Insert Position
	int       maxSubArray(Vec<int>& nums);                               // #53   Maximum Subarray	
	int       lengthOfLastWord(String s);                                // #58   Length of Last Word
	Vec<int>  plusOne(Vec<int>& digits);                                 // #66   Plus One
	String    addBinary(String a, String b);                             // #67   Add Binary
	int       mySqrt(int x);                                             // #69   Sqrt(x)	
	int       climbStairs(int n);                                        // #70   Climbing Stairs
	ListNode* deleteDuplicates(ListNode* head);                          // #83   Remove Duplicates from Sorted List
	Vec<int>  inorderTraversal(TreeNode* root);                          // #94   Binary Tree Inorder Traversal
	bool      isSameTree(TreeNode* p, TreeNode* q);                      // #100  Same Tree
	bool      isSymmetric(TreeNode* root);                               // #101  Symmetric Tree 
	int       maxDepth(TreeNode* root);                                  // #104  Maximum Depth of Binary Tree 
	TreeNode* sortedArrayToBST(Vec<int>& nums);                          // #108  Convert Sorted Array to Binary Search Tree
	bool      isBalanced(TreeNode* root);                                // #110  Balanced Binary Tree
	int       minDepth(TreeNode* root);                                  // #111  Minimum Depth of Binary Tree
	int       maxProfit(Vec<int>& prices);                               // #122  Best Time to Buy and Sell Stock II
	void      reverseString(Vec<char>& s);                               // #344  Reverse String
	int       fib(int n);                                                // #509  Fibonacci Number
  Vec<int>  countSubTrees(int n, Vec<Vec<int>>& edges, String labels); // #1519 Number of Nodes in the Sub-Tree With the Same Label

// Comparsion utilities
public:
	bool eq(ListNode* l1, ListNode* l2);
	bool eq(TreeNode* t1, TreeNode* t2);
};

#endif // _SYCLEETCODESOL_H_
