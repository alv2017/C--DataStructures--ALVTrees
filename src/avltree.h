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

#endif
