#include <iostream>
#include <cstddef>
#include <stdbool.h>

using namespace std;

struct ListNode
{
    struct ListNode *next;
    int data;
};

// struct ListNode *head = NULL;


void display(struct ListNode *temp);

void insert(struct ListNode *addr, int data)
{
    struct ListNode *new_node = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *temp = addr;
    bool task_completed = false;
    cout << " new nnode address: " << new_node << endl;
    if (addr == NULL){
        addr = new_node;
        addr->data = data;
        addr->next = NULL;
    }else{
        do {
            if (temp == NULL){
                new_node->data = data;
                new_node->next = NULL;
                temp = new_node;
                task_completed = true;
            }else{
                temp = temp->next;
            }
        }while(!task_completed);
    }
    display(addr);
}

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

int pop()
{

    return 0;
}

int pop_the_start()
{
    return 0;
}


int main()
{
    struct ListNode *head = NULL;
    int opt;
    bool exit = false;
    // head = (struct ListNode*)malloc(sizeof(struct ListNode));
    // cout << " Hello" << endl;
    // free(head);
    // cout << head << endl;
    cout << "address of pilot Node" << head << endl;
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
}