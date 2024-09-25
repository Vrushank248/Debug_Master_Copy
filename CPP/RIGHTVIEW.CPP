// 3.) RIGHT VIEW OF BINARY TREE
// Given a Binary Tree, find Right view of it. Right view of a Binary Tree is set of nodes visible when tree is viewed from right side. Return the right view as a list.

// C++ Program :

#include <bits/stdc++.h>
using namespace std;

// A Binary Tree Node
struct Node
{
    int data;
    Node *left;
    Node *right;

    // Constructor to initialize the node with data
    Node(int data)
    {
        this->data = data;
        this->left = this->right = NULL;
    }
};

// Function to print Right view of binary tree
void printRightView(Node *root)
{
    if (root == NULL)
        return;

    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        // Get number of nodes for each level
        int n = q.size();

        // Traverse all the nodes of the current level
        while (n--)
        {

            Node *x = q.front();
            q.pop();

            // Print the last node of each level
            if (n == 0)
            {
                cout << x->data << " ";
            }
            // If left child is not null, push it into the queue
            if (x->left)
                q.push(x->left);
            // If right child is not null, push it into the queue
            if (x->right)
                q.push(x->right);
        }
    }
}

// Driver code
int main()
{
    // Let's construct the tree as shown in example
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    root->right->left->right = new Node(8);

    printRightView(root);

    return 0;
}

