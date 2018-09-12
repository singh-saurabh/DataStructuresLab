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

struct node* insert(struct node* node, char* key)
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
        node->left = insert(node->left, key);
    }
    else if (strcmp(key, node->data) > 0)
        node->right = insert(node->right, key);

    return node;
}

struct node* search(struct node* root, char* key)
{
    int i = 0;
    while (key[i] != '\0'){
        key[i] = tolower(key[i]);
        i++;
    }

    if (root == NULL || strcmp(root->data, key) == 0)
       return root;

    if (strcmp(root->data, key) < 0)
       return search(root->right, key);

    return search(root->left, key);
}

int main()
{

    struct node *root = NULL;
    cout <<endl<< "Press 1 for inserting data from 'info.txt'." << endl;
    cout << "Press 2 for displaying sorted data." << endl;
    cout << "Press 3 for searching data." << endl;
    cout << "Enter anything else to quit." << endl;

    char a[] = "";
    root = insert(root, a);

    while (true){
        int n;
        cout << "Code : ";
        cin >> n;
        if (n == 1){

			FILE* infile = fopen("info.txt", "r");

            while (!feof(infile)){
            	char* data = new char;
				fscanf(infile, "%s", data);
                insert(root, data);
            }
        }
        else if (n == 2)
        {
            inorder(root);
        }
        else if (n == 3)
        {
            cout << "Enter data : ";
            char* b = new char;
            scanf("%s", b);
			if (search(root, b))
				cout << "Found " << b << endl;
			else
				cout << "Not Found " << b << endl;

        }
        else{
            return 0;
        }
    }

    return 0;
}
