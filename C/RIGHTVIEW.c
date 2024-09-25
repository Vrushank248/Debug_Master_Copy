// 3.) RIGHT VIEW OF BINARY TREE
// Given a Binary Tree, find Right view of it. Right view of a Binary Tree is set of nodes visible when tree is viewed from right side. Return the right view as a list.


// c program:
#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
} Node;

typedef struct Queue
{
    Node *node;
    struct Queue *next;
} Queue;

void enqueue(Queue **front, Queue **rear, Node *node)
{
    Queue *new_node = (Queue *)malloc(sizeof(Queue));
    new_node->node = node;
    new_node->next = NULL;
    if (*rear)
    {
        (*rear)->next = new_node;
    }
    *rear = new_node;
    if (!(*front))
    {
        *front = *rear;
    }
}

Node *dequeue(Queue **front)
{
    if (*front == NULL)
        return NULL;
    Queue *temp = *front;
    Node *node = temp->node;
    *front = (*front)->next;
    free(temp);
    return node;
}

int isEmpty(Queue *front)
{
    return front == NULL;
}

Node *newNode(int data)
{
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

void rightView(Node *root)
{
    if (root == NULL)
        return;

    Queue *front = NULL;
    Queue *rear = NULL;
    enqueue(&front, &rear, root);

    while (!isEmpty(front))
    {
        int n = 0;
        Queue *temp = front;
        while (temp)
        {
            temp = temp->next;
            n++;
        }

        for (int i = 1; i <= n; i++)
        {
            Node *curr = dequeue(&front);
            if (i == n)
            {
                printf("%d ", curr->data); 
            }
            if (curr->left)
                enqueue(&front, &rear, curr->left);
            if (curr->right)
                enqueue(&front, &rear, curr->right);
        }
    }
}

int main()
{
    Node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->right = newNode(5);
    root->right->right = newNode(4);

    printf("Right view of the binary tree: ");
    rightView(root);
    return 0;
}


