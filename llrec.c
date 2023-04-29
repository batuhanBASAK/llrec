/* llrec.c: The implementation of linked list recursively.
 *
 * Author: Batuhan BASAK
 * Date:   29 April 2023
 *
 * License: MIT
 *
 */

#include "llrec.h"


node *init_node(int data, node *next)
{
    node *n = (node*)calloc(1, sizeof(node));
    n->data = data;
    n->next = next;

    return n;
}


llrec *init_llrec()
{
    llrec *l = (llrec*) calloc(1, sizeof(llrec));
    l->head = NULL;
    
    return l;
}



void add_data(llrec *l, int data)
{
    if (l->head == NULL) {
        l->head = init_node(data, NULL);
    }
    else {
        node *tmp = init_node(data, NULL);
        add_node_next(l->head, tmp);
    }
}



void add_node_next(node *n1, node *n2)
{
    if (n1->next == NULL)
        n1->next = n2;
    else
        add_node_next(n1->next, n2);
}


int remove_data(llrec *l)
{
    return remove_last_node(l);
}


int remove_last_node(llrec *l)
{
    if (l->head == NULL)
        return -1;
    else if (l->head->next == NULL) {
        int data = l->head->data;
        free(l->head);
        l->head = NULL;
        return data;
    }
    else {
        node *tmp = pre_last_node(l->head);
        int data = tmp->next->data;
        free(tmp->next);
        tmp->next = NULL;
        return data;
    }
}


node *pre_last_node(node *n)
{
    if (n->next->next == NULL)
        return n;
    else
        return pre_last_node(n->next);
}


void print_llrec(llrec *l)
{
    if (l->head == NULL)
        printf("The llrec is empty.\n");
    else
        _print_llrec(l->head);
}


void _print_llrec(node *n)
{
    if (n == NULL)
        return ;
    else {
        printf("%d\n", n->data);
        _print_llrec(n->next);
    }
}



void deallocate_llrec(llrec **lp)
{
    if ((*lp)->head == NULL) {
        free(*lp);
        *lp = NULL;
    }
    else {
        remove_last_node(*lp);
        deallocate_llrec(lp);
    }
}


