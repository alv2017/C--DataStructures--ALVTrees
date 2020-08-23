#include <stdio.h>
#include <stdlib.h>
#include "avltree.h"

// Deleting a node
struct node *delete_node(struct node *subtree, int value, short *op_status) {
	*op_status = 0;
	if (subtree==NULL) {
		printf("The node with the value %d was not found.\n", value);
		return subtree;
	}
	struct node *ptr = subtree;
	struct node *tmp = NULL;
	struct node *parent = NULL;

	if (ptr->data > value) {
		ptr = delete_node(ptr->left, value, op_status);
	}
	else if (ptr->data < value) {
		ptr = delete_node(ptr->right, value, op_status);
	}
	else if (ptr->left && ptr->right) {
		tmp = find_largest(ptr->left);
		ptr->data = tmp->data;
		ptr = delete_node(ptr->left, tmp->data, op_status);
	}
	else {
		if (ptr->parent != NULL) {
			parent = ptr->parent;
		}
		else {
			parent = NULL;
		}

		if (ptr->left == NULL && ptr->right == NULL) {
			if (parent == NULL) {
				subtree = NULL;
			}
			else if (parent->data >= ptr->data) {
				parent->left = NULL;
			} else if (parent->data < ptr->data) {
				parent->right = NULL;
			}
		}
		else if (ptr->left == NULL) {
			if (parent == NULL) {
				subtree = ptr->right;
				subtree->parent = NULL;
			}
			else if (parent->data >= ptr->data){
				parent->left = ptr->right;
				parent->left->parent = parent;
			} else if (parent->data < ptr->data){
				parent->right = ptr->right;
				parent->right->parent = parent;
			}
		}
		else if (ptr->right == NULL) {
			if (parent==NULL) {
				subtree = ptr->left;
				subtree->parent = NULL;
			}
			else if (parent->data >= ptr->data){
				parent->left = ptr->left;
				parent->left->parent = parent;
			} else if (parent->data < ptr->data){
				parent->right = ptr->left;
				parent->right->parent = parent;
			}
		}
		*op_status = 1;
		free(ptr);
		// Update node heights and rebalance
		while (parent != NULL) {
			parent->node_height = get_node_height(parent);
			int node_balance = get_node_balance(parent);
			if (abs(node_balance) > 1) {
				if (value < parent->data) {
					puts("Right rotation needed.");
				}
				else if (value > parent->data) {
					puts("Left rotation needed.");
				}
			}
			parent = parent->parent;
		}
	}
	return subtree;
}

