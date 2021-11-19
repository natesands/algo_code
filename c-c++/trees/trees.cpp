#include <iostream>
#include <queue>
#include <stack>
#include <cstdlib>
#include <vector>

#define NULL_INT -9999999  // for construction trees from an array/vector


/*  Misc utility funcs */
int max(int a, int b) {
  return a >= b ? a : b;
}


/* Definition for a binary tree */
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

/* Visiting all tree nodes via BFS */
void treeBFS(TreeNode* root) {
  std::queue<TreeNode*> q;
  q.push(root);
  while(q.size()) {
    root = q.front();
    q.pop();
    printf("%d\n", root->val);
    if (root->left) 
      q.push(root->left);
    if (root->right)
      q.push(root->right);
  }
}

/* Visiting all tree nodes via DFS */
void treeDFS(TreeNode* root) {
  std::stack<TreeNode*> s;
  s.push(root);
  while (!s.empty()) {
    root = s.top();
    s.pop();
    printf("%d\n", root->val);
    if (root->left) 
      s.push(root->left);
    if (root->right)
      s.push(root->right);
  }
}

/* Create a Tree from vector*/
TreeNode* vectorToTree(const std::vector<int> &a) {
  std::vector<TreeNode*> nodes;
  TreeNode *new_node, *root;
  for (int i=0; i<a.size(); i++) {
    if (a[i] != NULL_INT) {
      new_node = new TreeNode(a[i]);
      nodes.push_back(new_node);
    }
    else
      nodes.push_back(nullptr);
  }
  for (int i=0; i<a.size(); i++) {
    if (nodes[i]) {
      if (2*i+1 < nodes.size() && nodes[2*i+1] != nullptr)
        nodes[i]->left = nodes[2*i+1];
      if (2*i+2 < nodes.size() && nodes[2*i+2] != nullptr)
        nodes[i]->right = nodes[2*i+2];
    }
  }
  return nodes[0];
}

/* Tree Height */
int treeHeight(TreeNode* root) {
  if (!root->left && !root->right) return 0;
  if (!root->left) return 1 + treeHeight(root->right);
  if (!root->right) return 1 + treeHeight(root->left);
  return 1 + max(treeHeight(root->left), treeHeight(root->right));
}

/* Count leaves */
int countLeaves(TreeNode* root) {
  std::stack<TreeNode*> s;
  int count = 0;
  s.push(root);
  while (!s.empty()) {
    root = s.top();
    s.pop();
    if (!root->left && !root->right)
      count++;
    if (root->left)
      s.push(root->left);
    if (root->right)
      s.push(root->right);
  }
  return count;
}

/* Max path from root */

/* Sum of left NODES */
int sumOfLeftNodes(TreeNode* root) {
    printf("val: %d\n", root->val);
    if (root->left != nullptr && root->right != nullptr) 
        return root->left->val + sumOfLeftNodes(root->left) + sumOfLeftNodes(root->right);
    else if (root->left != nullptr)
        return root->left->val + sumOfLeftNodes(root->left);
    else if (root->right != nullptr) 
        return sumOfLeftNodes(root->right);
    else return 0;
}

/* Sum of left LEAVES */ 
int sumOfLeftLeaves(TreeNode* root) {
    if (!root) return 0;
    int ans = 0;
    if (root-> left && !root->left->left && !root->left->right)
      ans += root->left->val;
    if (root->left) 
      ans += sumOfLeftLeaves(root->left);
    if (root->right)
      ans += sumOfLeftLeaves(root->right);

    return ans;
}

/* pre-order traversal*/
void preorderTraversal(TreeNode *root ) {
  if (!root)
    return;
  printf("%d ", root->val);
  //visit(root);
  preorderTraversal(root->left);
  preorderTraversal(root->right);
}

void inorderTraversal(TreeNode *root) {
  if (!root) return;
  inorderTraversal(root->left);
  printf("%d ", root->val);
  inorderTraversal(root->right);
}

void postorderTraversal(TreeNode *root) {
  if (!root) return;
  postorderTraversal(root->left);
  postorderTraversal(root->right);
  printf("%d ", root->val);
}



int main() {
  /* TREES */

  TreeNode *root = new TreeNode(3,new TreeNode(9), new TreeNode(20, new TreeNode(15), new TreeNode(7)));
  TreeNode *root2 = new TreeNode(1, new TreeNode(2, new TreeNode(4), new TreeNode(5)), new TreeNode(3, new TreeNode(6), new TreeNode(7)));
  std::vector<int> tree = {1,2,3,4,5,6,7,8,NULL_INT};
  std::vector<int> tree2 = {3,9,20,NULL_INT, NULL_INT, 16, 7, NULL_INT, NULL_INT, NULL_INT, NULL_INT, NULL_INT, NULL_INT,NULL_INT,8};
  TreeNode *root3 = vectorToTree(tree);
  TreeNode *root4 = vectorToTree(tree2);
  printf("Tree 3:\n");
  treeBFS(root4);
  printf("Tree 1: [3 9 20 null null 15 7 ]\n");
  printf("Return sum of left leaves\n");
  printf("Tree 1: [1 2 3 4 5 6 7]\n");
  printf("sum = %d\n", sumOfLeftLeaves(root));
  printf("Tree 1 BFS:\n");
  treeBFS(root);
  printf("Tree 2 BFS:\n");
  treeBFS(root2);
  printf("Tree 1 DFS:\n");  
  treeDFS(root);
  printf("Tree 2 DFS:\n");  
  treeDFS(root2);
  printf("Count leaves Tree 1:\n");  
  printf("%d\n", countLeaves(root));
  printf("Count leaves Tree 2:\n");  
  printf("%d\n", countLeaves(root2));
  printf("Tree Height 1: %d\n", treeHeight(root));
  printf("Tree Height 2: %d\n", treeHeight(root2));
  printf("Tree Height 3: %d\n", treeHeight(root3));
  printf("Tree Height 4: %d\n", treeHeight(root4));
  printf("Pre-order: \n");
  preorderTraversal(root3);
  printf("\n");
  inorderTraversal(root3);
  printf("\n");
  postorderTraversal(root3);
  printf("\n");
  return 0;

  

}

