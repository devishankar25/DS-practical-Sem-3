//Write a program for Implementation of tree as Array and Linked 
//lists and Traversal ( Inorder, Preorder, Postorder)
#include <stdio.h>
#include <stdlib.h>
// Structure for a node in the binary tree (linked list 
// implementation)
struct Node {
 int data;
 struct Node* left;
 struct Node* right;
};
// Function to create a new node for the binary tree (linked list 
// implementation)
struct Node* createNode(int data) {
 struct Node* newNode = (struct Node*)malloc(sizeof(struct 
Node));
 newNode->data = data;
 newNode->left = NULL;
 newNode->right = NULL;
 return newNode;
}
// Function to perform in-order traversal
void inOrder(struct Node* root) {
 if (root == NULL) return;
 inOrder(root->left);
 printf("%d ", root->data);
 inOrder(root->right);
}
// Function to perform pre-order traversal
void preOrder(struct Node* root) {
 if (root == NULL) return;
 printf("%d ", root->data);
 preOrder(root->left);
 preOrder(root->right);
}
// Function to perform post-order traversal
void postOrder(struct Node* root) {
 if (root == NULL) return;
 postOrder(root->left);
 postOrder(root->right);
 printf("%d ", root->data);
}
int main() {
 // Binary tree using linked list
 struct Node* root = createNode(1);
 root->left = createNode(2);
 root->right = createNode(3);
 root->left->left = createNode(4);
 root->left->right = createNode(5);
 root->right->left = createNode(6);
 root->right->right = createNode(7);
 printf("In-order traversal: ");
 inOrder(root);
 printf("\n");
 printf("Pre-order traversal: ");
 preOrder(root);
 printf("\n");
 printf("Post-order traversal: ");
 postOrder(root);
 printf("\n");
 return 0;
}