bool solve(struct Node* tree) {
    if (tree == NULL) {
        return true;  // An empty tree is a valid heap
    }

    // If the node has no children, it's a valid heap by definition
    if (tree->left == NULL && tree->right == NULL) {
        return true;
    }

    // Check if both left and right children exist
    bool leftValid = (tree->left == NULL || tree->data >= tree->left->data);
    bool rightValid = (tree->right == NULL || tree->data >= tree->right->data);

    // Recursively check the left and right subtrees
    bool leftHeap = solve(tree->left);
    bool rightHeap = solve(tree->right);

    // The current node is part of a heap if the value is larger than both children 
    // and both subtrees are also heaps
    return leftValid && rightValid && leftHeap && rightHeap;
}

bool isHeap(struct Node* tree) {
    return solve(tree);
}
