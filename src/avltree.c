#include <stdio.h>
#include <stdlib.h>
#include "avltree.h"

// Print node data
void print_node(struct node *pnode) {
	int data = 0;
	int pnode_parent = 0;
	int pnode_left = 0;
	int pnode_right = 0;
	if (pnode != NULL){
		data = pnode->data;
		if (pnode->parent != NULL) {
			pnode_parent = pnode->parent->data;
		}
		if (pnode->left != NULL) {
			pnode_left = pnode->left->data;
		}
		if (pnode->right != NULL) {
			pnode_left = pnode->right->data;
		}
	}
	printf("Node: %d; Parent: %d; Left: %d; Right: %d.\n", data, pnode_parent, pnode_left, pnode_right);
}

// Find node by value
struct node *find_node(struct node *tree, int value) {
	struct node *ptr = tree;

	if (tree == NULL) {
		printf("Unable to find the node with value %d: The tree is empty.", value);
		return NULL;
	}

	while (ptr != NULL) {
		if (ptr->data < value) {
			ptr = ptr->right;
		}
		else if (ptr->data > value) {
			ptr = ptr->left;
		}
		else {
			return ptr;
		}
	}
	printf("Unable to find the node with value %d.\n", value);
	return NULL;
}

// Find node with the smallest value
struct node *find_smallest(struct node *tree) {
	struct node *ptr;
	ptr = tree;

	if (ptr == NULL || ptr->left == NULL) {
		return ptr;
	} else {
		return find_smallest(tree->left);
	}
	return ptr;
}

// Find node with the largest value
struct node *find_largest(struct node *tree) {
	struct node *ptr = tree;
	if (ptr == NULL || ptr->right == NULL) {
		return ptr;
	} else {
		return find_largest(tree->right);
	}
}

// Count tree nodes
long count_nodes(struct node *subtree) {
	if (subtree == NULL) {
		return 0;
	}
	else {
		return count_nodes(subtree->left) + count_nodes(subtree->right) + 1;
	}
}

// Count internal tree nodes
long count_internal_nodes(struct node *subtree) {
	if (subtree == NULL) {
		return 0;
	}
	else if (subtree->left == NULL && subtree->right == NULL) {
		return 0;
	}
	else {
		return count_internal_nodes(subtree->left) + count_internal_nodes(subtree->right) + 1;
	}
}

// Count external tree nodes
long count_external_nodes(struct node *subtree) {
	if (subtree == NULL) {
		return 0;
	}
	else if (subtree->left == NULL && subtree->right == NULL) {
		return 1;
	}
	else {
		return count_external_nodes(subtree->left) + count_external_nodes(subtree->right);
	}
}

// Tree Height
int get_tree_height(struct node *subtree) {
	if (subtree == NULL) {
		return 0;
	}
	else {
		int leftHeight = get_tree_height(subtree->left);
		int rightHeight = get_tree_height(subtree->right);
		if (leftHeight > rightHeight) {
			return leftHeight + 1;
		}
		else {
			return rightHeight + 1;
		}
	}
}

// Delete Tree
struct node *delete_tree(struct node *tree) {
	if (tree != NULL) {
		struct node *ptr = tree;
		delete_tree(tree->left);
		delete_tree(tree->right);
		ptr->right = NULL;
		ptr->left = NULL;
		ptr->data = 0;
		free(ptr);
		return NULL;
	} else
		return NULL;
}



