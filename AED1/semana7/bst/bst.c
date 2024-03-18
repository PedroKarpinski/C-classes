#include "bst.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node {
    Element key;
    struct Node* left;
    struct Node* right;
} Node;

struct BST {
    Node* root;
};

Node* createNode(Element key) {
    Node* node = malloc(sizeof(Node));

    node->key = key;
    node->left = NULL;
    node->right = NULL;

    return node;
}

Node* makeSampleTree() {
    Node* root = createNode(50);
    root->left = createNode(43);
    root->left->left = createNode(3);
    root->left->right = createNode(48);
    root->right = createNode(61);
    root->right->left = createNode(58);
    root->right->right = createNode(70);

    return root;
}

BST* bst_create() {
    BST* bst = malloc(sizeof(BST));

    bst->root = NULL;
    // bst->root = makeSampleTree();

    return bst;
}

void bst_destroyRecur(Node* node) {
    if (node == NULL) {
        return;
    }

    bst_destroyRecur(node->left);
    bst_destroyRecur(node->right);
    free(node);
}

void bst_destroy(BST* bst) {
    bst_destroyRecur(bst->root);
    free(bst);
}


bool bst_searchRecur(Node* node, Element key) {
    if (node == NULL) {
        return false;
    }
    if (node->key == key) {
        return true;
    }
    if (key < node->key) {
        return bst_searchRecur(node->left, key);
    } 
    
    return bst_searchRecur(node->right, key);
}

bool bst_search(BST* bst, Element key) {
    return bst_searchRecur(bst->root, key);
}

void bst_printInOrderRecur(Node* node) {
    if (node == NULL) {
        return;
    }
    bst_printInOrderRecur(node->left);
    element_print(node->key);
    printf(" ");
    bst_printInOrderRecur(node->right);
}

void bst_printInOrder(BST* bst) {
    bst_printInOrderRecur(bst->root);
    printf("\n");
}

void printPreOrderRecur(Node* node) {
    if (node == NULL) {
        return;
    }
    element_print(node->key);
    printf(" ");
    printPreOrderRecur(node->left);
    printPreOrderRecur(node->right);
}

void bst_printPreOrder(BST* bst) {
    printPreOrderRecur(bst->root);
    printf("\n");
}

void printPostOrderRecur(Node* node) {
    if (node == NULL) {
        return;
    }
    printPostOrderRecur(node->left);
    printPostOrderRecur(node->right);
    element_print(node->key);
    printf(" ");
}

void bst_printPostOrder(BST* bst) {
    printPostOrderRecur(bst->root);
    printf("\n");
}

void bst_printDiagram(Node* node, int level) {
  if (node == NULL) {
      return;
  }
  for (int i = 0; i < level; i++) {
    printf("  ");
  }
  element_print(node->key);
  printf("\n");
  bst_printDiagram(node->left, level + 1);  
  bst_printDiagram(node->right, level + 1);
}

void bst_print(BST* bst) {
  bst_printDiagram(bst->root, 0);
}

void bst_insertRecur1(Node* node, Element key) {
    if (node->left == NULL && node->key > key) {
        node->left = createNode(key);
        return;
    } else if (node->right == NULL && node->key < key) {
        node->right = createNode(key);
        return;
    } else if (node->key == key) {
        return;
    }

    if (node->key > key) {
        bst_insertRecur1(node->left, key);
    } else if (node->key < key) {
        bst_insertRecur1(node->right, key);
    }
}

Node* bst_insertRecur2(Node* node, Element key) {
    if (node == NULL) {
        node = createNode(key);
    }

    if (key < node->key) {
        node->left = bst_insertRecur2(node->left, key);
    } else if (key > node->key) {
        node->right = bst_insertRecur2(node->right, key);
    }

    return node;
}

void bst_insertIte(Node* root, Element key) {
    Node* cur = root;
    Node* parent;

    while (cur != NULL) {
        if (cur->key == key) {
            return;
        }
        if (key < cur->key) {
            parent = cur;
            cur = cur->left;
        } else if ( key > cur->key) {
            parent = cur;
            cur = cur->right;
        }
    }

    if (key < parent->key) {
        parent->left = createNode(key);
    } else {
        parent->right = createNode(key);
    }
}

void bst_insert(BST* bst, Element key) {
    if (bst->root == NULL) {
        bst->root = createNode(key);
        return;
    }

    bst_insertRecur1(bst->root, key);
}