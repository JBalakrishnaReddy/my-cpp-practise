#include <iostream>
#include <cstddef>
#include <stdbool.h>

using namespace std;

struct ListNode
{
    struct ListNode *next;
    int data;
};

void display(struct ListNode *temp)
{
    do {
        if (temp != NULL){
            cout << temp->data << endl;
            temp = temp->next;
        }else{
            cout << "printing list finished" << endl;
            break;
        }
    }while(1);
}

void insert(struct ListNode *temp, int data)
{

}

int pop()
{
    return 0;
}

struct ListNode *create(){
    struct ListNode *new_node1 = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *new_node2 = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *new_node3 = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *new_node4 = (struct ListNode *)malloc(sizeof(struct ListNode));
    new_node1->data = 10;
    new_node1->next = new_node2;
    new_node2->data = 20;
    new_node2->next = new_node3;
    new_node3->data = 30;
    new_node3->next = new_node4;
    new_node4->data = 40;
    new_node4->next = NULL;
    // display(new_node1);
    return new_node1;
}

void blah(struct ListNode **node)
{
    cout << node << *node << endl;
    *node = create();
    cout << *node << endl;
}

int main()
{
    struct ListNode *head = NULL;
    int opt;
    bool exit = false;
    // head = create();
    cout << &head << endl;
    blah(&head);
    cout << &head << head << endl;
    display(head);
    return 0;
    while(!exit)
    {
        cout << "select the option from below "<< endl;
        cout << "1. Display the list \n2. Insert \n3. delete the latest entry \n4. delete the first entry \n5.exit \n";
        cout << "Enter your choice: ";
        cin >> opt;
        cout << opt << endl;
        switch(opt){
            case 1: display(head);
                    break;
            case 2:
                cout << "insert data that needs to be inserted into the list: ";
                int data;
                cin >> data;
                insert(head, data);
                cout << "address of pilot Node" << head << endl;
                break;
            case 3:
                pop();
                break;

            case 5:
                exit = true;
                break;
            default:
                cout << "invalid entry" << endl;
                break;
        }

    }
    cout << "thanks for using the application" << endl;
    return 0;
}