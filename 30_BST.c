// 30.	Create binary search tree and implement Preorder, Inorder, Postorder and delete an
// element from the tree.

#include <stdio.h>
#include <stdlib.h>

// Structure to represent a node in the binary search tree
typedef struct TreeNode
{
    int key;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

// Function to create a new node with the given key
TreeNode *createNode(int key)
{
    TreeNode *newNode = (TreeNode *)malloc(sizeof(TreeNode));
    newNode->key = key;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert a key into the binary search tree
TreeNode *insert(TreeNode *root, int key)
{
    if (root == NULL)
        return createNode(key);

    if (key < root->key)
        root->left = insert(root->left, key);
    else if (key > root->key)
        root->right = insert(root->right, key);

    return root;
}

// Function to perform preorder traversal of the binary search tree
void preorder(TreeNode *root)
{
    if (root != NULL)
    {
        printf("%d ", root->key);
        preorder(root->left);
        preorder(root->right);
    }
}

// Function to perform inorder traversal of the binary search tree
void inorder(TreeNode *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->key);
        inorder(root->right);
    }
}

// Function to perform postorder traversal of the binary search tree
void postorder(TreeNode *root)
{
    if (root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->key);
    }
}

// Function to find the minimum value node in a subtree
TreeNode *minValueNode(TreeNode *node)
{
    TreeNode *current = node;
    while (current && current->left != NULL)
        current = current->left;
    return current;
}

// Function to delete a key from the binary search tree
TreeNode *deleteNode(TreeNode *root, int key)
{
    if (root == NULL)
        return root;

    if (key < root->key)
        root->left = deleteNode(root->left, key);
    else if (key > root->key)
        root->right = deleteNode(root->right, key);
    else
    {
        if (root->left == NULL)
        {
            TreeNode *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            TreeNode *temp = root->left;
            free(root);
            return temp;
        }

        TreeNode *temp = minValueNode(root->right);
        root->key = temp->key;
        root->right = deleteNode(root->right, temp->key);
    }
    return root;
}

// Function to free memory allocated to BST nodes
void freeBST(TreeNode *root)
{
    if (root != NULL)
    {
        freeBST(root->left);
        freeBST(root->right);
        free(root);
    }
}

int main()
{
    TreeNode *root = NULL;

    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 70);
    root = insert(root, 60);
    root = insert(root, 80);

    printf("Preorder traversal: ");
    preorder(root);
    printf("\n");

    printf("Inorder traversal: ");
    inorder(root);
    printf("\n");

    printf("Postorder traversal: ");
    postorder(root);
    printf("\n");

    root = deleteNode(root, 20);
    printf("Inorder traversal after deleting 20: ");
    inorder(root);
    printf("\n");

    freeBST(root);

    return 0;
}

/*
output:
Preorder traversal: 50 30 20 40 70 60 80
Inorder traversal: 20 30 40 50 60 70 80
Postorder traversal: 20 40 30 60 80 70 50
Inorder traversal after deleting 20: 30 40 50 60 70 80
*/