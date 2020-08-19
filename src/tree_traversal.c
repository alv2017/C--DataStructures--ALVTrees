#include <stdio.h>
#include <stdlib.h>
#include "avltree.h"

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
