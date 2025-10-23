#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left;
    struct node *right;
};

struct node* createNode(int value) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}
// Function to insert a value into the BST
struct node* insert(struct node* root, int value) {
    if (root == NULL) {
        return createNode(value);
    }

    // else, recursively call the left and right to consrtuct the tree
    if (value < root->data) {
        root->left = insert(root->left, value);
    } else if (value > root->data) {
        root->right = insert(root->right, value);
    }
    // no duplicates are allowed so if any value repeats, ignore that value
    
    return root;
}

struct node* search(struct node* root, int value) {
    // Base condition
    if (root == NULL || root->data == value) {
        return root;
    }

    // Value is greater than root's data move to right subtree
    if (value > root->data) {
        return search(root->right, value);
    }

    // Value is smaller than root's data move to left subtree
    return search(root->left, value);
}

    
// In-order traversal (prints the tree in sorted order)
void inorder(struct node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

int main() {
    struct node* root = NULL;

    // --- Insertion ---
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    printf("In-order traversal of the BST: ");
    inorder(root);
    printf("\n\n");

    // --- Search ---
    int search_val = 40;
    struct node* found_node = search(root, search_val);
    if (found_node) {
        printf("Value %d found in the tree.\n", search_val);
    } else {
        printf("Value %d not found in the tree.\n", search_val);
    }

    return 0;
}
