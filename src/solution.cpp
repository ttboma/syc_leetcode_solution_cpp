#include "solution.h"

bool Solution::eq(ListNode *l1, ListNode *l2) {
  while (l1 != nullptr || l2 != nullptr) {
    if (l1 == nullptr && l2 != nullptr)
      return false;
    if (l1 != nullptr && l2 == nullptr)
      return false;
    if (l1->val != l2->val)
      return false;
    l1 = l1->next;
    l2 = l2->next;
  }
  return true;
}
bool Solution::eq(TreeNode *t1, TreeNode *t2) {
  auto stack1 = std::vector<TreeNode *>{t1};
  auto stack2 = std::vector<TreeNode *>{t2};
  while (!stack1.empty()) {
    auto t1 = stack1.back();
    stack1.pop_back();
    auto t2 = stack2.back();
    stack2.pop_back();
    if (t1 == nullptr) {
      if (t2 != nullptr) {
        return false;
      }
      continue;
    } else if (t2 == nullptr) {
      return false;
    } else if (t1->val != t2->val) {
      return false;
    } else {
      stack1.push_back(t1->left);
      stack1.push_back(t1->right);
      stack2.push_back(t2->left);
      stack2.push_back(t2->right);
    }
  }
  return true;
}
