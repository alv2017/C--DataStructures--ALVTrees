#ifndef AVLTREES_H
#define AVLTREES_H

struct node {
	int data;
	int node_height;
	struct node *parent;
	struct node *left;
	struct node *right;
};

// Operation Status
short op_status;

// Insert New Node
struct node *insert_node(struct node *, int, short *);

// Pre-order traversal
void preorder_traversal(struct node *);

// Post-order traversal
void postorder_traversal(struct node *);

// In-order traversal
void inorder_traversal(struct node *);

#endif
