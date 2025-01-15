#include <vector>

typedef struct node {
    int data;
    int index;
    struct node* leftChild;
    struct node* rightChild;
} Node;

Node* ROOT = NULL;

// typedef struct node {
//     string data;
//     int index;
//     struct node* leftChild;
//     struct node* rightChild;
// } NodeString;

void sortedArrayToBalancedBST(Node*& root, std::vector<int>& nodeValues, int start, int end)
{
    if (start > end)
    {
        return;
    }

    int median = (start + end) / 2;
    Node* newNode = new Node;
    newNode->data = nodeValues[median];
    newNode->leftChild = NULL;
    newNode->rightChild = NULL;
    root = newNode;
    sortedArrayToBalancedBST(root->leftChild, nodeValues, start, median-1);
    sortedArrayToBalancedBST(root->rightChild, nodeValues, median+1, end);
}

void inOrderStorage(Node* root, std::vector<int>& nodeValues)
{
    if (root != NULL)
    {
        inOrderStorage(root->leftChild, nodeValues);
        nodeValues.push_back(root->data);
        inOrderStorage(root->rightChild, nodeValues);
    }
}

void balanceBST(Node*& root)
{
    std::vector<int> nodeValuesInOrder;
    
    inOrderStorage(root, nodeValuesInOrder);

    sortedArrayToBalancedBST(root, nodeValuesInOrder, 0, nodeValuesInOrder.size()-1);
}