#include <stdio.h>
#include <stdlib.h>

#include "avltree.h"

int get_node_height(struct node *treenode) {
	int hl = 0, hr = 0;
	if (treenode->left != NULL) {
		hl = treenode->left->node_height;
	}
	if (treenode->right != NULL) {
		hr = treenode->right->node_height;
	}
	if (hl>=hr)
		return hl + 1;
	else
	    return hr + 1;
}

int get_node_balance(struct node *treenode){
	int hl = 0;
	int hr = 0;
	if (treenode->left != NULL) {
		hl = treenode->left->node_height;
	}
	if (treenode->right != NULL) {
		hr = treenode->right->node_height;
	}
	return hl - hr;
}

struct node *ll_rotate(struct node *treenode) {
	struct node *ptr = treenode;
	struct node *p = ptr->left;
	struct node *pright = p->right;

	if (ptr->parent != NULL) {
		p->parent = ptr->parent;
		if (ptr->parent->data > p->data) {
			ptr->parent->left = p;
		} else {
			ptr->parent->right = p;
		}
	} else {
		p->parent = NULL;
	}

	p->right = ptr;

	if (pright != NULL){
	    pright->parent = ptr;
	    ptr->left = pright;
	} else {
		ptr->left = NULL;
	}
	ptr->parent = p;

	// height re-calculation after rotation
	ptr->node_height = get_node_height(ptr);
	p->node_height = get_node_height(ptr);
	return p;
}

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
			return NULL;
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
			if (parentptr->left && parentptr->data > ptr->data) {
				printf("LL Rotation node: %d\n", parentptr->data);
				parentptr = ll_rotate(parentptr);
			}
		}
		if (parentptr->parent == NULL) {
			tree = parentptr;
		}
		parentptr = parentptr->parent;
	}
	return tree;
}

// Pre-order traversal
void preorder_traversal(struct node *tree) {
	struct node *ptr = tree;
	int parent_value = 0;
	int left_value = 0, right_value = 0;
	if (ptr != NULL) {
		if (ptr->parent){
			parent_value = ptr->parent->data;
		}
		if (ptr->left) {
			left_value = ptr->left->data;
		}
		if (ptr->right) {
			right_value = ptr->right->data;
		}
		int node_balance = get_node_balance(ptr);
		printf("Node: %d; Parent: %d; Left: %d; Right: %d; Height: %d; Balance: %d.\n",
				ptr->data, parent_value, left_value, right_value,
				ptr->node_height, node_balance);
		getchar();
		preorder_traversal(ptr->left);
		preorder_traversal(ptr->right);
	}
}

// Post-order traversal
void postorder_traversal(struct node *tree) {
	struct node *ptr = tree;
	int parent_value = 0;
	if (ptr != NULL) {
		postorder_traversal(ptr->left);
		postorder_traversal(ptr->right);
		if (ptr->parent){
			parent_value = ptr->parent->data;
		}
		int node_balance = get_node_balance(ptr);
		printf("Node: %d; Parent: %d; Height: %d; Balance: %d.\n",
				ptr->data, parent_value, ptr->node_height, node_balance);
		getchar();
	}
}

// In-order traversal
void inorder_traversal(struct node *tree) {
	struct node *ptr = tree;
	int parent_value = 0;
	if (ptr != NULL) {
		inorder_traversal(ptr->left);
		if (ptr->parent){
			parent_value = ptr->parent->data;
		}
		int node_balance = get_node_balance(ptr);
		printf("Node: %d; Parent: %d; Height: %d; Balance: %d.\n",
				ptr->data, parent_value, ptr->node_height, node_balance);
		inorder_traversal(ptr->right);
	}
}






