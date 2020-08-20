#include <stdio.h>
#include <stdlib.h>
#include "menu/menu.h"
#include "src/avltree.h"

#define clear() printf("\033[H\033[J")

const char *menu[] = {
		" 1. Insert a new node.",
		" 2. Delete a node.",
		" 3. Find node by value.",
		" 4. Find the smallest node value.",
		" 5. Find the largest node value.",
		" 6. Pre-order traversal.",
		" 7. Post-order traversal.",
		" 8. In-order traversal.",
		" 9. Count nodes.",
		"10. Count internal nodes.",
		"11. Count external nodes.",
		"12. Tree height.",
		"13. Print tree root node.",
		"14. Delete tree.",
		"15. Exit.",
		NULL
};

int main(void) {
	op_status = 0;
	// Tree
	struct node *tree = NULL;

	// Menu
	short opt;
	const short MINOPT = 1;
	const short MAXOPT = get_menu_length(menu);
	clear();
	display_menu(menu);
	opt = select_option(MINOPT, MAXOPT);

	while (1) {
		printf("You have selected: %d\n", opt);
		switch (opt) {
			case 1:
				clear();
				puts("Inserting a node:");
				int new_node_value = enter_value();
				tree = insert_node(tree, new_node_value, &op_status);
				if (op_status == 1) {
					puts("New node has been inserted successfully!");
				}
				break;

			case 2:
				clear();
				//puts("Deleting a node.");
				puts("LL Rotate.");

				break;

			case 3:
				clear();
				puts("Searching a node by value.");
				puts("Enter the value of a node you are looking for.");
				int search_value = enter_value();
				struct node *found_node = find_node(tree, search_value);
				if (found_node != NULL) {
					int parent_value = (found_node->parent == NULL)? 0:found_node->parent->data;
					int left_value = (found_node->left == NULL)? 0:found_node->left->data;
					int right_value = (found_node->right == NULL)? 0:found_node->right->data;
					int node_balance = get_node_balance(found_node);


					printf("The node with the value %d is found: \n", search_value);
					printf("Node: %d; Parent: %d; Left: %d; Right: %d; Height: %d; Balance: %d.\n",
									found_node->data, parent_value, left_value, right_value,
									found_node->node_height, node_balance);
				}
				break;

			case 4:
				clear();
				puts("Find node with the smallest value.");
				struct node *smallest_node = find_smallest(tree);
				if (tree == NULL) {
					puts("The tree is empty.");
				} else {
					int parent_value = (smallest_node->parent == NULL)? 0:smallest_node->parent->data;
					int left_value = (smallest_node->left == NULL)? 0:smallest_node->left->data;
					int right_value = (smallest_node->right == NULL)? 0:smallest_node->right->data;
					int node_balance = get_node_balance(smallest_node);

					puts("The smallest node has been found:");
					printf("Node: %d; Parent: %d; Left: %d; Right: %d; Height: %d; Balance: %d.\n",
							smallest_node->data, parent_value, left_value, right_value,
							smallest_node->node_height, node_balance);

				}
				break;

			case 5:
				clear();
				puts("Find node with the largest value.");
				struct node *largest_node = find_largest(tree);
				if (tree == NULL) {
					puts("The tree is empty.");
				} else {
					int parent_value = (largest_node->parent == NULL)? 0:largest_node->parent->data;
					int left_value = (largest_node->left == NULL)? 0:largest_node->left->data;
					int right_value = (largest_node->right == NULL)? 0:largest_node->right->data;
					int node_balance = get_node_balance(largest_node);

					puts("The smallest node has been found:");
					printf("Node: %d; Parent: %d; Left: %d; Right: %d; Height: %d; Balance: %d.\n",
							largest_node->data, parent_value, left_value, right_value,
							largest_node->node_height, node_balance);

				}
				break;

			case 6:
				clear();
				puts("Pre-order traversal:");
				if (tree==NULL) {
					puts("The tree is empty.");
				}
				else {
					preorder_traversal(tree);
				}
				break;

			case 7:
				clear();
				puts("Post-order traversal:");
				if (tree==NULL) {
					puts("The tree is empty.");
				}
				else {
					postorder_traversal(tree);
				}
				break;

			case 8:
				clear();
				puts("In-order traversal:");
				if (tree==NULL) {
					puts("The tree is empty.");
				}
				else {
					postorder_traversal(tree);
				}
				break;

			case 9:
				clear();
				puts("Counting tree nodes.");
				break;

			case 10:
				clear();
				puts("Counting internal nodes.");
				break;


			case 11:
				clear();
				puts("Counting external nodes.");
				break;

			case 12:
				clear();
				puts("Computing the tree height.");
				break;

			case 13:
				clear();
				puts("Displaying the root node of the tree.");
				break;

			case 14:
				clear();
				puts("Deleting a tree.");
				break;

			case 15:
				clear();
				puts("Exiting the Program.");
				return 0;
		}
		// Asking user for further actions;
		display_menu(menu);
		opt = select_option(MINOPT, MAXOPT);
	}
	return 0;
}
