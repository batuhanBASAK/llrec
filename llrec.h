#ifndef LLREC_H
#define LLREC_H

/* llrec.c: The header file of recursive linked list.
 *
 * Author: Batuhan BASAK
 * Date:   29 April 2023
 *
 * License: MIT
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct node_t {
    int data;
    struct node_t *next;
}node;

typedef struct llrec_t {
    node *head;
}llrec;


/* init_node: Initialise a node from scratch and returns the address of it.
 *
 * data: The data of the node.
 * next: The reference, address, of the next node.
 *
 */
node *init_node(int data, node *next);


/* init_llrec: Initialise a llrec from scratch and returns the address of it.
 */
llrec *init_llrec();


/* add_data: Adds a new item to the end of the llrec.
 * 
 * l: The llrec to add on it.
 * data: The data to add it.
 *
 */
void add_data(llrec *l, int data);


/* add_node_next: Adds the node n2 to the next of node n1.
 *
 * n1: The preceding node to add next of it.
 * n2: The node added next to preceding node.
 *
 */
void add_node_next(node *n1, node *n2);


/* remove_data: Removes last data from llrec.
 *
 * l: The llrec, stands for linkedlistrecursively, to remove last item.
 *
 * pre: l must be non-NULL pointer.
 * post: Deletes last item of l.
 *
 */
int remove_data(llrec *l);



/* remove_last_node: Removes last node from given llrec list.
 *
 * l: The list to remove from.
 * 
 * pre: l must be non-NULL pointer.
 *
 */
int remove_last_node(llrec *l);


/* pre_last_node: Finds the preceding node of the last node in a llrec list.
 *
 * n: The current node to move forward.
 *
 * pre: node must be non-NULL pointer.
 *
 */
node *pre_last_node(node *n);


/* print_llrec: Prints each data of llrec line by line.
 *
 * l: The list to print.
 *
 * pre: l must be non-NULL pointer.
 *
 */
void print_llrec(llrec *l);


/* _print_llrec: Helper function call each node and prints data recursively.
 *
 * n: The current node in llrec list.
 *
 */
void _print_llrec(node *n);


/* deallocate_llrec: Deallocates llrec from memory.
 * 
 * lp: The pointer points the address of pointer of llrec to delete it.
 * 
 * pre: lp must be non-NULL pointer.
 * post: frees the allocated memory where value of lp points.
 *
 */
void deallocate_llrec(llrec **lp);


#endif
