 #include<stdio.h>
#include<stdlib.h>
#include<cstring>
#include<iostream>

using namespace std;

struct node
{
    char* data;
    struct node *left, *right;
};

struct node *newNode(char* item)
{
    struct node *temp =  (struct node *)malloc(sizeof(struct node));
    temp->data = item;
    temp->left = temp->right = NULL;
    return temp;
}

void inorder(struct node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        cout << root->data << endl;
        inorder(root->right);
    }
}

struct node* insertNode(struct node* node, char* key)
{
    int i = 0;
    while (key[i] != '\0'){
        key[i] = tolower(key[i]);
        i++;
    }

    if (node == NULL){
        return newNode(key);
    }

    if (strcmp(key,node->data) < 0){
        node->left = insertNode(node->left, key);
    }
    else if (strcmp(key, node->data) > 0)
        node->right = insertNode(node->right, key);

    return node;
}

int main()
{

    struct node *root = NULL;
    cout << "Press 1 to inserting data." << endl;
    cout << "Press 2 to displaying sorted data." << endl;
    cout << "Enter anything else to quit." << endl;

    char a[] = "";
    root = insertNode(root, a);

    while (true){
        int n;
        cout << "Code : ";
        cin >> n;
        if (n == 1){
            cout << "Enter data : ";
            char* b = new char;
            scanf("%s", b);
            insertNode(root, b);
        }
        else if (n == 2)
        {
            inorder(root);
        }
        else{
            return 0;
        }
    }

    return 0;
}
