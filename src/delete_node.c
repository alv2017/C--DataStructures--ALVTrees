#include <stdio.h>
#include <stdlib.h>
#include "avltree.h"

// Deleting a node: helper function
struct node *delete_node(struct node *subtree, int value, short *op_status) {
	*op_status = 0;

	struct node *ptr = subtree;
	struct node *tmp = NULL;
	struct node *parent = NULL;

	if (ptr==NULL) {
		printf("The node with the value %d was not found.\n", value);
	}
	else if (ptr->data > value) {
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
		int node_balance = 0;
		int child_balance = 0;
		while (parent != NULL) {
			parent->node_height = get_node_height(parent);
			node_balance = get_node_balance(parent);
			if (abs(node_balance) > 1) {
				if (value > parent->data) {
					child_balance = get_node_balance(parent->left);
					if (child_balance == 1) {
						parent = ll_rotate(parent);
					}
					else if (child_balance == -1 || child_balance == 0) {
						parent = lr_rotate(parent);
					}
				}
				else if (value < parent->data) {
					child_balance = get_node_balance(parent->right);
					if (child_balance == -1) {
						parent = rr_rotate(parent);
					}
					else if (child_balance == 0 || child_balance == 1){
						parent = rl_rotate(parent);
					}
				}
			}
			subtree = parent;
			parent = parent->parent;
		}
	}
	return subtree;
}

// Delete AVL-tree node
struct node *delete_avl_node(struct node *subtree, int value, short *op_status) {
	*op_status = 0;
	struct node *avl_node = delete_node(subtree, value, op_status);
	if (avl_node != NULL) {
		while (avl_node->parent != NULL) {
			avl_node = avl_node->parent;
		}
	}
	return avl_node;
}






