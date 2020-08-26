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
	if (parentptr != NULL){
		ptr->parent = parentptr;
		if (val < parentptr->data) {
			parentptr->left = ptr;
		} else {
			parentptr->right = ptr;
		}
	} else {
		ptr->parent = NULL;
	}

	if (tree == NULL) {
		tree = ptr;
		return tree;
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
		tree = parentptr;
		parentptr = parentptr->parent;
	}
	return tree;
}
