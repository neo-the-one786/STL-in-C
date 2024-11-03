#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include "../include/bst.h"

Node *construct(int data) {
    Node *this = (Node *) malloc(sizeof(Node));
    this->data = data;
    this->left = NULL;
    this->right = NULL;
    return this;
}

bool isBSTHelper(Node *root, int prev) {
    if (root == NULL) {
        return true;
    }
    if (!isBSTHelper(root->left, prev)) {
        return false;
    }
    if (prev >= root->data) {
        return false;
    }
    prev = root->data;
    return isBSTHelper(root->right, prev);
}

bool isBST(Node *root) {
    int prev = INT_MIN;
    return isBSTHelper(root, prev);
}

Node *search(Node *root, int data) {
    if (root == NULL) {
        return NULL;
    }
    if (data == root->data) {
        return root;
    } else if (data < root->data) {
        return search(root->left, data);
    } else {
        return search(root->right, data);
    }
}

Node *searchIter(Node *root, int data) {
    Node *ptr = root;
    while (ptr != NULL) {
        if (data == ptr->data) {
            return ptr;
        } else if (data < ptr->data) {
            ptr = ptr->left;
        } else {
            ptr = ptr->right;
        }
    }
    return NULL;
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
        if (data < ptr->data) {
            ptr = ptr->left;
        } else if (data > ptr->data) {
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

Node *delete(Node *root) {
    if (root == NULL) {
        return NULL;
    }
    //leaf node
    if (root->left == NULL && root->right == NULL) {
        free(root);
    }
    if (root->left != NULL && root->right == NULL) {
//        Node *dupm
    }
    return NULL;
}

void print(Node *root) {
    if (root == NULL) {
        return;
    }
    print(root->left);
    printf("%d ", root->data);
    print(root->right);
}