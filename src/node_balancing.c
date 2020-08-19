#include <stdio.h>
#include <stdlib.h>
#include "avltree.h"

// Calculate the height of the height of the node
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

// Calculate the balance of the node
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
