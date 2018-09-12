#include <iostream>
#include <climits>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
};

Node* newNode(int key)
{
    Node* node = new Node;
    node->data = key;
    node->left = node->right = nullptr;

    return node;
}

void inorder(Node* root)
{
    if (root == nullptr)
        return;

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

Node* insert(Node* root, int key)
{
    if (root == nullptr)
        return newNode(key);

    if (key < root->data)
        root->left = insert(root->left, key);

    else
        root->right = insert(root->right, key);

    return root;
}

int kLargest(Node* root, int *i, int k)
{
    if (root == nullptr)
        return INT_MAX;

    int left = kLargest(root->right, i, k);

    if (left != INT_MAX)
        return left;

    if (++*i == k)
        return root->data;

    return kLargest(root->left, i, k);
}

int kLargest(Node* root, int k)
{
    int i = 0;
    return kLargest(root, &i, k);
}

int main()
{
    Node* root = nullptr;

    cout << "Enter the number of elements in the tree : ";
    int n;
    cin >> n;

    int key;

    cout << "Enter the elements of the tree : ";
    for (int i = 0; i < n; i++){
    	cin >> key;
    	root = insert(root, key);
    }

    int k;
    cout << "Enter the value of k to find the kth largest element in the tree : ";
    cin >> k;

    int res = kLargest(root, k);

    if (res != INT_MAX)
        cout <<"The k-th largest value is"<< res << endl;
    else
        cout << "Invalid Input" << endl;

    return 0;
}
