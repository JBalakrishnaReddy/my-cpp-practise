#include <iostream>
#include <cstddef>
#include <stdbool.h>

using namespace std;

struct node 
{
    int data;
    struct node *right;
    struct node *left;
};

struct node *create()
{
    char temp_char;
    int temp_data;
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    cout << "enter data for the node:";
    cin >> temp_data;
    new_node->data = temp_data;
    cout << "do you want to create a left node for previously create node " << new_node->data<< " y/n (lower case):";
    cin >> temp_char;
    if(temp_char == 'y'){
        // cin >> temp_data;
        new_node->left = create();
    }
    else{
        new_node->left = NULL;
    }
    cout << "do you want to create a right node for previously create node " << new_node->data<< " y/n (lower case):";
    cin >> temp_char;
    if(temp_char == 'y'){
        new_node->right = create();
    }else{
        new_node->right = NULL;
    }
    return new_node;
}

void display(struct node *node)
{
    if(node != NULL)
    {
        printf("%d", node->data);
    }
}

void display_preorder(struct node *node)
{
    //root left right
    if(node != NULL){
        cout << node->data << ',';
        display_preorder(node->left);
        display_preorder(node->right);
    }
}

void display_inorder(struct node *node)
{
    //left root right
    if (node != NULL){

    }
}

struct node *create_hardcode()
{
    /*              4
            5               10
        7       8               1   */
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = 4;
    new_node->left = (struct node *)malloc(sizeof(struct node));
    new_node->left->data = 5;
    new_node->left->left = (struct node *)malloc(sizeof(struct node));
    new_node->left->left->data = 7;
    new_node->left->left->left = NULL;
    new_node->left->left->right = NULL;
    new_node->left->right = (struct node *)malloc(sizeof(struct node));
    new_node->left->right->data = 8;
    new_node->left->right->left = NULL;
    new_node->left->right->right = NULL;

    new_node->right = (struct node *)malloc(sizeof(struct node));
    new_node->right->data = 10;
    new_node->right->left = NULL;
    new_node->right->right = (struct node *)malloc(sizeof(struct node));
    new_node->right->right->data = 1;
    new_node->right->right->left =NULL;
    new_node->right->right->right = NULL;
    return new_node;
}

int main()
{
    struct node *root = NULL;
    char temp_char;
    // root = create();
    root = create_hardcode();
    display_preorder(root);

    // while(true){
    //     cout << " want to create a node? y/n" << endl;
    //     cin >> temp_char;
    //     if(temp_char == 'y')
    //     {
    //         cout << "creating new node" << endl;
    //     }
    //     if(temp_char == 'n')
    //     {
    //         cout << "exiting the application" << endl;
    //         exit(0);
    //     }
    // }

    return 0;
}