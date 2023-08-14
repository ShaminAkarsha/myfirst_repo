#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node *createNode(int data);
struct Node *addNode(struct Node *root, int data);
struct Node *searchNode(struct Node *root, int data);
int kDistanceSum(struct Node *root, int k, int Target_item);

int main()
{
    int data;
    struct Node *root;
    root = NULL;
    printf("Input data for the tree (-1 to stop):\n");
    while (true)
    {
        scanf("%d", &data);
        if (data == -1)
        {
            break;
        }
        root = addNode(root, data);
    }
    int value,k,sum;
    printf("Enter Target value: ");
    scanf("%d",&value);
    printf("Enter K-distance: ");
    scanf("%d",&k);

    sum = kDistanceSum(root,k,value);
    printf("K-Distance Nodes Sum: %d",sum);

    return 0;

}

struct Node *createNode(int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;
    ptr->left = NULL;
    ptr->right = NULL;

    return ptr;
}

struct Node *addNode(struct Node *root, int data)
{
    if (root == NULL)
    {
        root = createNode(data);
    }
    else
    {
        if (root->data > data)
        {
            root->left = addNode(root->left, data);
        }
        else if (root->data < data)
        {
            root->right = addNode(root->right, data);
        }
        else
        {
            printf("The value is already existing\nskip the value\n");
        }
    }
    return root;
}

struct Node *searchNode(struct Node *root, int data)
{
    if (root == NULL || root->data == data)
    {
        return root;
    }
    else if (root->data > data)
    {
        return searchNode(root->left, data);
    }
    else
    {
        return searchNode(root->right, data);
    }
}

int kDistanceSumUtil(struct Node *node, int k)
{
    if (node == NULL)
    {
        return 0;
    }
    if (k == 0)
    {
        return node->data;
        
    }
    return kDistanceSumUtil(node->left, k - 1) + kDistanceSumUtil(node->right, k - 1);
}

int kDistanceSum(struct Node *root, int k, int target_item)
{
    struct Node *target_node = searchNode(root, target_item);
    if (target_node == NULL)
    {
        printf("Target item not found in the tree.\n");
        return 0;
    }
    return kDistanceSumUtil(target_node, k);
}
