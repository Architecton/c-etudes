// tree_height: computes the height of the binary_tree pointed to by root
int tree_height(Node *root) {
	// define left subtree height and right subtree height
	int left_height;
	int right_height;

	// if tree does not exist, return signal -1
	if(root == 0) {
		return -1;
	} else {
		// compute subtree heights
		left_height = tree_height((*root)->left);
		right_height = tree_height((*root)->right);
		// return 1 + the larger height
		return 1 + (left_height > right_height) ? left_height : right_height;
	}
}