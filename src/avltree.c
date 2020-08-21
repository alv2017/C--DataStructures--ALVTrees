#include <stdio.h>
#include <stdlib.h>
#include "avltree.h"


// Insert a new node
struct node *insert_node(struct node *tree, int val, short *op_status) {
	*op_status = 0;
	struct node *ptr, *nodeptr, *parentptr;

	parentptr = NULL;
	nodeptr = tree;

	while(nodeptr != NULL) {
		parentptr = nodeptr;
		if (val < nodeptr->data) {
			nodeptr = nodeptr->left;
		} else if (val > nodeptr->data){
			nodeptr = nodeptr->right;
		}
		else {
			puts("Node insertion rejected.");
		    printf("Duplicate node value. The node having value %d already exists.", val);
			return tree;
		}
	}
	ptr = (struct node *) malloc(sizeof(struct node));
	if (ptr == NULL) {
		puts("Unable to create a new node. Memory allocation error.");
		return tree;
	}
	*op_status = 1;
	ptr->data = val;
	ptr->node_height = 1;
	ptr->left = NULL;
	ptr->right = NULL;
	ptr->parent = parentptr;

	if (tree == NULL) {
		tree = ptr;
		return tree;
	}
	if (val < parentptr->data) {
		parentptr->left = ptr;
	} else {
		parentptr->right = ptr;
	}

	// Update node heights and rebalance
	while (parentptr != NULL) {
		parentptr->node_height = get_node_height(parentptr);
		int node_balance = get_node_balance(parentptr);
		if (abs(node_balance) > 1) {
			// LL Rotation
			if (parentptr->left && parentptr->data > ptr->data && parentptr->left->data > ptr->data) {
				printf("LL Rotation node: %d\n", parentptr->data);
				parentptr = ll_rotate(parentptr);
			}
			// RR Rotation
			else if (parentptr->right && parentptr->data < ptr->data && parentptr->right->data < ptr->data) {
				printf("RR Rotation node: %d\n", parentptr->data);
				parentptr = rr_rotate(parentptr);
			}
			// LR Rotation
			else if (parentptr->left && parentptr->data > ptr->data && parentptr->left->data < ptr->data) {
				printf("LR Rotation node: %d\n", parentptr->data);
				parentptr = lr_rotate(parentptr);
			}
			// RL Rotation
			else if (parentptr->right && parentptr->data < ptr->data && parentptr->right->data > ptr->data) {
				printf("RL Rotation node: %d\n", parentptr->data);
				parentptr = rl_rotate(parentptr);
			}
		}
		if (parentptr->parent == NULL) {
			parentptr->node_height = get_node_height(parentptr);
			tree = parentptr;
		}
		parentptr = parentptr->parent;
	}
	return tree;
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









