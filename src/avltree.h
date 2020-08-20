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

// Get node height
int get_node_height(struct node *);

// Get node balance
int get_node_balance(struct node *);

// Pre-order traversal
void preorder_traversal(struct node *);

// Post-order traversal
void postorder_traversal(struct node *);

// In-order traversal
void inorder_traversal(struct node *);

// Perform LL Rotation
struct node *ll_rotate(struct node *);

// Perform RR Rotation
struct node *rr_rotate(struct node *);

// Perform LR Rotation
struct node *lr_rotate(struct node *treenode);

// Perform RL Rotation
struct node *rl_rotate(struct node *treenode);

// Find node by value
struct node *find_node(struct node *, int );

// Find the node with the smallest value
struct node *find_smallest(struct node *);

// Find node with the largest value
struct node *find_largest(struct node *tree);

// Count tree nodes
long count_nodes(struct node *subtree);

// Count internal nodes
long count_internal_nodes(struct node *subtree);

// Count external tree nodes
long count_external_nodes(struct node *subtree);

// Insert New Node
struct node *insert_node(struct node *, int, short *);

// Tree Height
int get_tree_height(struct node *subtree);

#endif
