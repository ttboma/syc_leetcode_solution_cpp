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
// Methods
public:
	ListNode*        addTwoNumbers( ListNode* l1, ListNode* l2 );           // Problem #2   Add Two Numbers 
	int              lengthOfLongestSubstring( std::string s );             // Problem #3   Longest Substring Without Repeating Characters
	std::string      longestPalindrome( std::string s );                    // Problem #5   Longest Palindromic Substring
	bool             isPalindrome(int x);                                   // Problem #9   Palindrome Number
	int              romanToInt( std::string s );                           // Problem #13  Roman to Integer 
	std::string      longestCommonPrefix( std::vector<std::string>& strs ); // Problem #14  Longest Common Prefix 
	bool             isValid( std::string s );                              // Problem #20  Valid Parentheses
	ListNode*        mergeTwoLists( ListNode* list1, ListNode* list2);      // Problem #21  Merge Two Sorted Lists
	int              removeDuplicates( std::vector<int>& nums );            // Problem #26  Remove Duplicates from Sorted Array
	int              removeElement( std::vector<int>& nums, int val );      // Problem #27  Remove Element
	int              strStr( std::string haystack, std::string needle );    // Problem #28  Implement strStr()
	int              searchInsert( std::vector<int>& nums, int target );    // Problem #35  Search Insert Position
	int              maxSubArray( std::vector<int>& nums );                 // Problem #53  Maximum Subarray	
	int              lengthOfLastWord( std::string s );                     // Problem #58  Length of Last Word
	std::vector<int> plusOne( std::vector<int>& digits );                   // Problem #66  Plus One
	std::string      addBinary( std::string a, std::string b );             // Problem #67  Add Binary
	int              mySqrt( int x );                                       // Problem #69  Sqrt(x)	
	int              climbStairs( int n );                                  // Problem #70  Climbing Stairs
	ListNode*        deleteDuplicates( ListNode* head );                    // Problem #83  Remove Duplicates from Sorted List
	std::vector<int> inorderTraversal( TreeNode* root );                    // Problem #94  Binary Tree Inorder Traversal
	bool             isSameTree( TreeNode* p, TreeNode* q );                // Problem #100 Same Tree
	bool             isSymmetric( TreeNode* root );                         // Problem #101 Symmetric Tree 
	int              maxDepth( TreeNode* root );                            // Problem #104 Maximum Depth of Binary Tree 
	TreeNode*        sortedArrayToBST( std::vector<int>& nums );            // Problem #108 Convert Sorted Array to Binary Search Tree
	bool             isBalanced( TreeNode* root );                          // Problem #110 Balanced Binary Tree
	int              minDepth( TreeNode* root );                            // Problem #111 Minimum Depth of Binary Tree
	int              maxProfit( std::vector<int>& prices );                 // Problem #122 Best Time to Buy and Sell Stock II
	void             reverseString( std::vector<char>& s);                  // Problem #344 Reverse String
    int              fib(int n);                                            // Problem #509 Fibonacci Number

// Comparsion utilities
public:
	bool eq(ListNode* l1, ListNode* l2);
	bool eq(TreeNode* t1, TreeNode* t2);
};

#endif
