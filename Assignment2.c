#include <stdio.h>
#include <stdlib.h>

struct Node {
    int key;
    struct Node *left, *right;
};

struct Node* createNode(int key) {
    struct Node* p = malloc(sizeof(struct Node));
    p->key = key;
    p->left = p->right = NULL;

    return p;
}

struct Node* insert(struct Node* root, int key) {
    if (root == NULL) return createNode(key);

    if (key < root->key)
        root->left = insert(root->left, key);
    else if (key > root->key)
        root->right = insert(root->right, key);

    return root;
}

void inorder(struct Node* r) {
    if (r) {
        inorder(r->left);
        printf("%d ", r->key);
        inorder(r->right);
    }
}

void preorder(struct Node* r) {
    if (r) {
        printf("%d ", r->key);
        preorder(r->left);
        preorder(r->right);
    }
}

void postorder(struct Node* r) {
    if (r) {
        postorder(r->left);
        postorder(r->right);
        printf("%d ", r->key);
    }
}

int bstSearch(struct Node* r, int key, int *c) {
    while (r) {
        (*c)++;

        if (r->key == key)
            return 1;

        r = (key < r->key) ? r->left : r->right;
    }

    return 0;
}

int linearSearch(int a[], int n, int key, int *c) {
    for (int i = 0; i < n; i++) {
        (*c)++;

        if (a[i] == key)
            return 1;
    }

    return -1;
}

int main() {
    int isbn[] = {45, 20, 60, 10, 30, 50, 70, 25, 55};
    int keys[] = {25, 55, 90};
    int n = 9;

    struct Node *root = NULL;

    for (int i = 0; i < n; i++)
        root = insert(root, isbn[i]);

    printf("Inorder: ");
    inorder(root);

    printf("\nPreorder: ");
    preorder(root);

    printf("\nPostorder: ");
    postorder(root);

    printf("\n\nSEARCH COMPARISON\n");

    for (int i = 0; i < 3; i++) {
        int bc = 0, lc = 0;

        int bf = bstSearch(root, keys[i], &bc);
        int lf = linearSearch(isbn, n, keys[i], &lc);

        printf("\nKey = %d\n", keys[i]);

        printf("BST Search: %s, Comparisons = %d\n",
               bf ? "Found" : "Not Found", bc);

        printf("Linear Search: %s, Comparisons = %d\n",
               lf != -1 ? "Found" : "Not Found", lc);
    }

    return 0;
}