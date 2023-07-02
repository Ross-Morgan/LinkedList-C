#pragma once

#include<stdio.h>
#include<stdbool.h>

#include<range.h>

typedef struct Node Node;
typedef struct LinkedList LinkedList;

typedef struct LinkedList
{
    Node *head;
    Node *tail;
    size_t len;
    size_t ele_size;
} LinkedList;


typedef struct Node
{
    void *data;
    Node *prev;
    Node *next;
} Node;


// Checks if linked list is empty
bool isEmptyLinkedList(struct LinkedList*);

// Add an item to the end of the linked list
void pushBackLinkedList(struct LinkedList*, void*);
// Add an item to the start of the linked list
void pushFrontLinkedList(struct LinkedList*, void*);

void* popBackLinkedList(struct LinkedList*);
// Remove and return the fist element in the linked list
void* popFrontLinkedList(struct LinkedList*);

void append(struct LinkedList*, struct LinkedList*);
void splice(struct LinkedList*, struct Range, struct LinkedList*);

bool isEmptyLinkedList(struct LinkedList *ll) {
    return ll->len == 0;
}

// Add an item to the end of the linked list
void pushBackLinkedList(struct LinkedList *ll, void *value)
{
    Node new_end_node = {
        .data = value,
        .prev = NULL,
        .next = NULL,
    };

    if (isEmptyLinkedList(ll)) {
        // Linked List is empty
        ll->head = &new_end_node;
    } else {
        new_end_node.prev = ll->tail;
        ll->tail->next = &new_end_node;
    }

    ll->tail = &new_end_node;
    ll->len++;
}

// Add an item to the start of a linked list
void pushFrontLinkedList(struct LinkedList* ll, void* value) {
    Node new_start_node = {
        .data = value,
        .prev = NULL,
        .next = NULL,
    };

    if (isEmptyLinkedList(ll)) {
        ll->tail = &new_start_node;
    } else {
        new_start_node.next = ll->head;
        ll->head->prev = &new_start_node;
    }

    ll->head = &new_start_node;
    ll->len++;
}

// Remove and return the last element in the linked list
void* popBackLinkedList(struct LinkedList* ll) {
    if (isEmptyLinkedList(ll)) {
        return NULL;
    }

    Node* tail_node = ll->tail;

    if (ll->len == 1) {
        ll->head = NULL;
        ll->tail = NULL;
    } else {
        ll->tail = ll->tail->prev;
    }

    ll->len--;

    return tail_node->data;
}

// Remove and return the fist element in the linked list
void* popFrontLinkedList(struct LinkedList* ll) {
    if (isEmptyLinkedList(ll)) {
        return NULL;

        Node* head_node = ll->head;

        if (ll->len == 1) {
            ll->head = NULL;
            ll->tail = NULL;
        } else {
            ll->head = ll->head->next;
        }

        ll->len--;

        return head_node->data;
    }
}

void append(struct LinkedList* ll, struct LinkedList* ll_2) {}
void splice(struct LinkedList* ll, struct Range range, struct LinkedList* ll_2) {}