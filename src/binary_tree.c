#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../include/binary_tree.h"

Node *construct(int data) {
    Node *this = (Node *) malloc(sizeof(Node));
    this->data = data;
    this->left = NULL;
    this->right = NULL;
    return this;
}

Node *insertRecur(Node *root, int data) {
    if (root == NULL) {
        return construct(data);
    }
    if (data < root->data) {
        root->left = insertRecur(root->left, data);
    } else if (data > root->data) {
        root->right = insertRecur(root->right, data);
    }
    return root;
}

void insertIter(Node **root, int data) {
    Node *newNode = construct(data);
    if (*root == NULL) {
        *root = newNode;
        return;
    }
    Node *ptr = *root, *prev = NULL;
    while (ptr != NULL) {
        prev = ptr;
        if (data < (*root)->data) {
            ptr = ptr->left;
        } else if (data > (*root)->data) {
            ptr = ptr->right;
        } else {
            return;
        }
    }
    if (data < prev->data) {
        prev->left = newNode;
    } else {
        prev->right = newNode;
    }
}

Node *deleteRecur(Node *root, int data) {
    if (root == NULL) {
        return root;
    }
    if (data < root->data) {
        root->left = deleteRecur(root->left, data);
        return root;
    } else if (data > root->data) {
        root->right = deleteRecur(root->right, data);
    }
    Node *dump = root;
    if (root->left == NULL) {
        root = root->right;
        return root;
    } else if (root->right == NULL) {
        root = root->left;
        return root;
    } else {
        Node *newParent = root, *newChild = root->right;
        while (newChild->left != NULL) {
            newParent = newChild;
            newChild = newChild->left;
        }
        if (newParent != NULL) {
            newParent->left = newChild->right;
        } else {
            newParent->right = newChild->right;
        }
        root->data = newChild->data;
        return root;
    }
}

void preOrderRecur(Node *root) {
    if (root == NULL) {
        return;
    }
    printf("%d ", root->data);
    preOrderRecur(root->left);
    preOrderRecur(root->right);
}

void inOrderRecur(Node *root) {
    if (root == NULL) {
        return;
    }
    inOrderRecur(root->left);
    printf("%d ", root->data);
    inOrderRecur(root->right);
}

void postOrderRecur(Node *root) {
    if (root == NULL) {
        return;
    }
    postOrderRecur(root->left);
    postOrderRecur(root->right);
    printf("%d ", root->data);
}

Stack *constructStack(int cpty) {
    Stack *this = (Stack *) malloc(sizeof(Stack));;
    this->top = -1;
    this->cpty = cpty;
    this->arr = (Node **) malloc(this->cpty * sizeof(Node *));
    return this;
}

bool isEmpty(Stack *this) {
    return this->top == -1;
}

bool isFull(Stack *this) {
    return this->top == this->cpty - 1;
}

void push(Stack *this, Node *data) {
    if (isFull(this)) {
        return;
    }
    this->arr[++this->top] = data;
}

Node *pop(Stack *this) {
    if (isEmpty(this)) {
        return NULL;
    }
    return this->arr[this->top--];
}

void preOrderIter(Node *root) {
    Stack *stack = constructStack(10);
    if (root == NULL) {
        return;
    }
    Node *ptr = root;
    push(stack, ptr);
    while (!isEmpty(stack)) {
        ptr = pop(stack);
        printf("%d ", ptr->data);
        if (ptr->right != NULL) {
            push(stack, ptr->right);
        }
        if (ptr->left != NULL) {
            push(stack, ptr->left);
        }
    }
}

void inOrderIter(Node *root) {
    Stack *stack = constructStack(10);
    if (root == NULL) {
        return;
    }
    Node *ptr = root;
    while (!isEmpty(stack) || ptr != NULL) {
        if (ptr != NULL) {
            push(stack, ptr);
            ptr = ptr->left;
        } else {
            ptr = pop(stack);
            printf("%d ", ptr->data);
            ptr = ptr->right;
        }
    }
}

void postOrderIter(Node *root) {
    Stack *s1 = constructStack(10), *s2 = constructStack(10);
    Node *ptr = root;
    push(s1, ptr);
    while (!isEmpty(s1)) {
        ptr = pop(s1);
        push(s2, ptr);
        if (ptr->left != NULL) {
            push(s1, ptr->left);
        }
        if (ptr->right != NULL) {
            push(s1, ptr->right);
        }
    }
    while (!isEmpty(s2)) {
        printf("%d ", pop(s2)->data);
    }
}