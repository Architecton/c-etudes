// binary tree Node structure
typedef struct Node {
	int value;
	struct Node *left;
	struct Node *right;
} *Node;

// tree_size: returns the number of nodes in the binary tree pointed to by root
int tree_size(Node *root) {
   if(root == 0) {
      return 0;
   } else {
      return 1 + tree_size((*root)->left) + tree_size((*root)->right);
   }
}