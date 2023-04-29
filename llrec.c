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
    l->size = 0;
    
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
    (l->size)++;
}


void insert_data(llrec *l, int data, int index)
{
    node *n = init_node(data, NULL);
    insert_node(l, n, index);
}



void insert_node(llrec *l, node *n, int index)
{
    if (index < 0 || index >= l->size) {
        printf("Error! Index is out of bounds!\n");
    }
    else if (index == 0){
        n->next = l->head;
        l->head = n;
        (l->size)++;
    }
    else {
        node *prev = get_node(l, index - 1);
        n->next = prev->next;
        prev->next = n;
        (l->size)++;
    }
}


void add_node_next(node *n1, node *n2)
{
    if (n1->next == NULL)
        n1->next = n2;
    else
        add_node_next(n1->next, n2);
}


int remove_last_data(llrec *l)
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
        (l->size)--;
        return data;
    }
    else {
        node *tmp = pre_last_node(l->head);
        int data = tmp->next->data;
        free(tmp->next);
        tmp->next = NULL;
        (l->size)--;
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


int remove_data(llrec *l, int index)
{
    if (index < 0 || index >= l->size) {
        fprintf(stderr, "Error! Index is out of bounds!\n");
        return -1;
    }
    else {
        return remove_node(l, index);
    }
}


int remove_node(llrec *l, int index)
{
    if (index == 0) {
        node *tmp = l->head;
        l->head = tmp->next;
        int data = tmp->data;
        free(tmp);
        (l->size)--;
        return data;
    }
    else {
        node *prev = get_node(l, index-1);
        node *tmp = prev->next;
        prev->next = tmp->next;
        int data = tmp->data;
        free(tmp);
        (l->size)--;
        return data;
    }
}


node *get_node(llrec *l, int index)
{
    return _get_node(l->head, index);
}


node *_get_node(node *n, int index)
{
    if (index == 0)
        return n;
    else
        return _get_node(n->next, index - 1);
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


