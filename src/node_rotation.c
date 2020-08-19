#include <stdio.h>
#include <stdlib.h>
#include "avltree.h"

// Perform LL Rotation
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
	p->node_height = get_node_height(p);
	return p;
}

// Perform RR Rotation
struct node *rr_rotate(struct node *treenode) {
	struct node *ptr = treenode;
	struct node *p = ptr->right;
	struct node *pleft = p->left;

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
	p->left = ptr;
	if (pleft != NULL){
	    pleft->parent = ptr;
	    ptr->right = pleft;
	} else {
		ptr->right = NULL;
	}
	ptr->parent = p;

	// height re-calculation after rotation
	ptr->node_height = get_node_height(ptr);
	p->node_height = get_node_height(p);
	return p;
}

// Perform LR Rotation
struct node *lr_rotate(struct node *treenode) {
	struct node *ptr = treenode;
	struct node *ptr_left = treenode->left;
	struct node *p = treenode->left->right;
	struct node *pleft = p->left;
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
	p->left = ptr_left;
	ptr_left->parent = p;
	p->right = ptr;
	ptr->parent = p;
	if (pleft != NULL) {
		ptr_left->right = pleft;
		pleft->parent = ptr_left;
	} else {
		ptr_left->right = NULL;
	}
	if (pright != NULL) {
		ptr->left = pright;
		pright->parent = ptr;
	} else {
		ptr->left = NULL;
	}

	// height re-calculation after rotation
	ptr_left->node_height = get_node_height(ptr_left);
	ptr->node_height = get_node_height(ptr);
	p->node_height = get_node_height(p);

	return p;
}

// Perform RL Rotation
struct node *rl_rotate(struct node *treenode) {
	struct node *ptr = treenode;
	struct node *ptr_right = treenode->right;
	struct node *p = treenode->right->left;
	struct node *pleft = p->left;
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
	p->left = ptr;
	ptr->parent = p;
	p->right = ptr_right;
	ptr->right->parent = p;
	if (pleft != NULL) {
		ptr->right = pleft;
		pleft->parent = ptr;
	} else {
		ptr->right = NULL;
	}
	if (pright != NULL) {
		ptr_right->left = pright;
		pright->parent = ptr_right;
	} else {
		ptr_right->left = NULL;
	}

	// height re-calculation after rotation
	ptr->node_height = get_node_height(ptr);
	ptr_right->node_height = get_node_height(ptr_right);
	p->node_height = get_node_height(p);

	return p;
}
