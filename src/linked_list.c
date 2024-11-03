#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "../include/linked_list.h"

Node *construct(int data) {
    Node *this = (Node *) malloc(sizeof(Node));
    this->data = data;
    this->next = NULL;
    return this;
}

void print(Node *this) {
    Node *ptr = this;
    printf("\n");
    while (ptr != NULL) {
        printf("%d -> ", ptr->data);
        ptr = ptr->next;
    }
}

bool isEmpty(Node *this) {
    return this == NULL;
}

int search(Node *this, int data) {
    Node *ptr = this;
    int pos = 0;
    while (ptr != NULL) {
        if (ptr->data == data) {
            return pos;
        }
        pos++;
        ptr = ptr->next;
    }
    return -1;
}

void prepend(Node **this, int data) {
    Node *newNode = construct(data);
    newNode->next = *this;
    *this = newNode;
}

void append(Node **this, int data) {
    Node *newNode = construct(data);
    if (*this == NULL) {
        *this = newNode;
    }
    Node *ptr = *this;
    while (ptr->next != NULL) {
        ptr = ptr->next;
    }
    ptr->next = newNode;
}

void insertAt(Node **this, int data, int pos) {
    Node *ptr = *this;
    Node *newNode = construct(data);
    int count = 0;
    if (pos == 0) {
        newNode->next = *this;
        *this = newNode;
        return;
    }
    while (ptr != NULL) {
        if (count == pos - 1) {
            newNode->next = ptr->next;
            ptr->next = newNode;
            return;
        }
        count++;
        ptr = ptr->next;
    }
}

void insertAfter(Node *this, int data) {
    Node *newNode = construct(data);
    newNode->next = this->next;
    this->next = newNode;
}

void poll(Node **this) {
    if (*this == NULL) {
        fprintf(stderr, "\nNull Pointer\n");
        return;
    }
    Node *ptr = *this;
    *this = (*this)->next;
    free(ptr);
}

void dock(Node **this) {
    if (*this == NULL) {
        fprintf(stderr, "\nNull Pointer\n");
        return;
    }
    if ((*this)->next == NULL) {
        free(*this);
        return;
    }
    Node *ptr = *this;
    while (ptr->next->next != NULL) {
        ptr = ptr->next;
    }
    free(ptr->next);
    ptr->next = NULL;
}

void deleteAt(Node **this, int pos) {
    if (*this == NULL || pos < 0) {
        fprintf(stderr, "\nNull Pointer\n");
        return;
    }
    Node *ptr = *this;
    if (pos == 0) {
        *this = (*this)->next;
        free(ptr);
        return;
    }
    int count = 0;
    while (ptr != NULL) {
        if (count == pos - 1) {
            Node *temp = ptr->next;
            ptr->next = ptr->next->next;
            free(temp);
            return;
        }
        count++;
        ptr = ptr->next;
    }
}

void deleteAfter(Node **this) {
    if (*this == NULL || (*this)->next == NULL) {
        fprintf(stderr, "\nNull Pointer\n");
        return;
    }
    Node *temp = (*this)->next;
    (*this)->next = (*this)->next->next;
    free(temp);
}

void splitList(Node *source, Node **frontRef, Node **backRef) {
    Node *fast;
    Node *slow;
    if (source == NULL || source->next == NULL) {
        *frontRef = source;
        *backRef = NULL;
    } else {
        slow = source;
        fast = source->next;
        while (fast != NULL) {
            fast = fast->next;
            if (fast != NULL) {
                slow = slow->next;
                fast = fast->next;
            }
        }
        *frontRef = source;
        *backRef = slow->next;
        slow->next = NULL;
    }
}

Node *merge(Node *a, Node *b) {
    Node *result = NULL;
    if (a == NULL) {
        return b;
    } else if (b == NULL) {
        return a;
    }
    if (a->data <= b->data) {
        result = a;
        result->next = merge(a->next, b);
    } else {
        result = b;
        result->next = merge(a, b->next);
    }
    return result;
}

void mergeSort(Node **headRef) {
    Node *head = *headRef;
    Node *a, *b;
    if (head == NULL || head->next == NULL) {
        return;
    }
    splitList(head, &a, &b);
    mergeSort(&a);
    mergeSort(&b);
    *headRef = merge(a, b);
}

void sort(Node **this) {
    mergeSort(this);
}