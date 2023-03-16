//12) Programar una funcion recursiva que calcule la suma de los nodos internos de un AB de enteros

#include <stdlib.h>
using namespace std;


struct Node {
    int key;
    Node* left, *right;
};
 

/* utility that allocates a new Node with the given key  */
Node* newNode(int key)
{
    Node* node = new Node;
    node->key = key;
    node->left = node->right = NULL;
    return (node);
}
 
/* Function to find sum of all the elements*/
int addBT(Node* root)
{
    if (root == NULL)
        return 0;
    return (root->key + addBT(root->left) + addBT(root->right));
}
 