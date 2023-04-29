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
    int size;
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



/* insert_data: Insert given data to a specified position.
 *
 * l: The llrec to insert on it.
 * data: The data to insert to.
 * index: The position to insert at.
 * 
 * pre: l and n must be non-NULL pointers.
 * post: data n will be inserted to *index* position on llrec l.
 * 
 */
void insert_data(llrec *l, int data, int index);



/* insert_node: Inserts given node to a specific position in llrec.
 *
 * l: The llrec to insert on.
 * n: The new node to insert it.
 * index: The position to insert at.
 * 
 * pre: l and n must be non-NULL pointers.
 * post: node n will be inserted to *index* position on llrec l.
 *
 */
void insert_node(llrec *l, node *n, int index);


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
int remove_last_data(llrec *l);


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



/* remove_data: Removes a data from specified position.
 * 
 * l: The llrec to remove from.
 * index: The position of data to remove it.
 * 
 * pre: l must be a non-NULL pointer. And index must be in range.
 * post: removes a data, at position *index*, from l.
 */
int remove_data(llrec *l, int index);


/* remove_node: Removes a node from llrec l at given position.
 * 
 * l: The llrec to remove from it.
 * index: The position of removal node.
 * 
 * pre: l must be a non-NULL pointer. And index must be in range.
 * post: removes a data, at position *index*, from l.
 * 
 */
int remove_node(llrec *l, int index);


/* get_node: Finds a node on llrec l at the given position.
 *
 * l: The llrec to search on it.
 * index: The position.
 *
 */
node *get_node(llrec *l, int index);


/* _get_node: Helper function for get_node that finds the node 
 *            at position *index* recursively.
 *
 * n: The current node in recursive calls.
 * index: The number of recursive calls left to reach position of node.
 *
 * pre: n must be non-NULL pointer.
 *
 */
node *_get_node(node *n, int index);



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
