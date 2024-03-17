#include "bst_algs.h"

#include <stdio.h>
#include <stdbool.h>

void aux_countNodes(Node* cur, int* cont) {
    if (cur == NULL) {
        return;
    }

    aux_countNodes(cur->left, cont);
    (*cont)++;
    aux_countNodes(cur->right, cont);
}

int bst_countNodes(Node *root) {
    int n = 0;
    int* cont = &n;

    aux_countNodes(root, cont);
    return *cont;
}

void aux_countLeaves(Node* cur, int* cont) {
    if (cur == NULL) {
        return;
    }

    if (cur->left == NULL && cur->right == NULL) {
        *cont += 1;
    }

    aux_countLeaves(cur->left, cont);
    aux_countLeaves(cur->right, cont);
}

int bst_countLeaves(Node *root) {
    int n = 0;
    int* cont = &n;

    aux_countLeaves(root, cont);
    return *cont;
}

void aux_countInternalNodes(Node* cur, int* cont) {
    if (cur == NULL) {
        return;
    }

    if (cur->left != NULL || cur->right != NULL) {
        (*cont)++;
    }

    aux_countInternalNodes(cur->left, cont);
    aux_countInternalNodes(cur->right, cont);
}

int bst_countInternalNodes(Node *root) {
    int n = 0;
    int* cont = &n;

    aux_countInternalNodes(root, cont);
    return *cont;
}

void aux_height(Node* cur, int* cont, int* cur_height, int* cur_level) {
    (*cur_level)++;

    if (cur == NULL) {
        (*cur_level)--;
        *cur_height = *cur_level;

        if (*cur_height > *cont) {
            *cont = *cur_height;
        }

        return;
    }

    aux_height(cur->left, cont, cur_height, cur_level);
    aux_height(cur->right, cont, cur_height, cur_level);
    (*cur_level)--;
}

int bst_height(Node *root) {
    int n = 0;
    int* cont = &n;

    int h = 0;
    int* cur_height = &h;

    int l = 0;
    int* cur_level = &l;

    aux_height(root, cont, cur_height, cur_level);
    return *cont;
}

void aux_sum(Node* cur, int* cont) {
    if (cur == NULL) {
        return;
    }

    *cont = *cont + cur->key;

    aux_sum(cur->left, cont);
    aux_sum(cur->right, cont);
}

int bst_sum(Node *root) {
    int sum = 0;
    int* cont = &sum;

    aux_sum(root, cont);
    return *cont;
}

void aux_max(Node* cur, int* cont) {
    if (cur == NULL) {
        return;
    }

    if (cur->key > *cont) {
        *cont = cur->key;
    }

    aux_max(cur->left, cont);
    aux_max(cur->right, cont);
}

int bst_max(Node *root) {
    if (root == NULL) {
        return MINIMUM;
    }

    int max = MINIMUM;
    int* cont = &max;

    aux_max(root, cont);
    return *cont;
}

void aux_min(Node* cur, int* cont) {
    if (cur == NULL) {
        return;
    }

    if (cur->key < *cont) {
        *cont = cur->key;
    }

    aux_min(cur->left, cont);
    aux_min(cur->right, cont);
}

int bst_min(Node *root) {
    if (root == NULL) {
        return MAXIMUM;
    }

    int min = MAXIMUM;
    int* cont = &min;

    aux_min(root, cont);
    return *cont;
}

void aux_countSharedKeys(Node* fixed, Node* temp, int* cont) {
    if (temp == NULL || fixed == NULL) {
        return;
    }

    if (temp->key == fixed->key) {
        (*cont)++;
    }

    aux_countSharedKeys(fixed, temp->left, cont);
    aux_countSharedKeys(fixed, temp->right, cont);
}

int bst_countSharedKeys(Node *root1, Node *root2) {
    if (root1 == NULL || root2 == NULL) {
        return 0;
    }

    int n = 0;
    int* cont = &n;

    aux_countSharedKeys(root1, root2, cont);

    *cont += bst_countSharedKeys(root1->left, root2);
    *cont += bst_countSharedKeys(root1->right, root2);

    return *cont;
}