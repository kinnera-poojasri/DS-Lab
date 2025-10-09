#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left;
    struct node *right;
};

// Function to create an empty tree
struct node* create_tree() {
    return NULL;
}

// Function to insert an element into the tree
struct node* insertElement(struct node *tree, int val) {
    struct node *ptr, *parentptr, *nodeptr;
    ptr = (struct node*)malloc(sizeof(struct node));
    ptr->data = val;
    ptr->left = NULL;
    ptr->right = NULL;

    if (tree == NULL) {
        tree = ptr;
    } else {
        parentptr = NULL;
        nodeptr = tree;

        while (nodeptr != NULL) {
            parentptr = nodeptr;
            if (val < nodeptr->data)
                nodeptr = nodeptr->left;
            else
                nodeptr = nodeptr->right;
        }

        if (val < parentptr->data)
            parentptr->left = ptr;
        else
            parentptr->right = ptr;
    }

    return tree;
}

void inorder(struct node* root)
{
	if(root != NULL)
	{
		inorder(root->left);
		printf("%d",root->data);
		inorder(root->right);
	}
}

void preorder(struct node* root)
{
	if(root != NULL)
	{
		printf("%d",root->data);
		preorder(root->left);
		preorder(root->right);
	}
}

void postorder(struct node* root)
{
	if(root != NULL)
	{
		postorder(root->left);
		postorder(root->right);
		printf("%d",root->data);
	}
}

int findMin(struct node* root) {
    if (root == NULL) {
        printf("Tree is empty.\n");
        return -1;
    }
    while (root->left != NULL)
        root = root->left;
    return root->data;
}

int findMax(struct node* root) {
    if (root == NULL) {
        printf("Tree is empty.\n");
        return -1;
    }
    while (root->right != NULL)
        root = root->right;
    return root->data;
}

struct node* deleteNode(struct node* root, int key) {
    if (root == NULL)
        return root;

    if (key < root->data)
        root->left = deleteNode(root->left, key);
    else if (key > root->data)
        root->right = deleteNode(root->right, key);
    else {
        // Case 1: No child
        if (root->left == NULL && root->right == NULL) {
            free(root);
            return NULL;
        }
        // Case 2: One child
        else if (root->left == NULL) {
            struct node* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            struct node* temp = root->left;
            free(root);
            return temp;
        }
        
        // Case 3: Two children
        struct node* temp = findMin(root->right);  // Inorder successor
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

// Count total number of nodes
int countNodes(struct node* root) {
    if (root == NULL)
        return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}

// Count internal nodes (nodes with at least one child)
int countInternalNodes(struct node* root) {
    if (root == NULL)
        return 0;
    if (root->left == NULL && root->right == NULL)
        return 0; // Leaf node, not internal
    return 1 + countInternalNodes(root->left) + countInternalNodes(root->right);
}


// Count external (leaf) nodes
int countExternalNodes(struct node* root) {
    if (root == NULL)
        return 0;
    if (root->left == NULL && root->right == NULL)
        return 1;
    return countExternalNodes(root->left) + countExternalNodes(root->right);
}

// Function to find the height of the BST
int findHeight(struct node* root) {
    if (root == NULL)
        return -1; // Height of empty tree is -1 (if counting edges)
    int leftHeight = findHeight(root->left);
    int rightHeight = findHeight(root->right);
    return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
}

// Delete the entire tree
void deleteTree(struct node* root) {
    if (root == NULL)
        return;
    deleteTree(root->left);   // Delete left subtree
    deleteTree(root->right);  // Delete right subtree
    printf("Deleting node: %d\n", root->data);
    free(root);               // Delete current node
}





