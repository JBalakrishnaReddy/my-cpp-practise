
#include <iostream>
#include <cstddef>
#include <stdbool.h>

using namespace std;

struct ListNode
{
    struct ListNode *next;
    int data;
};

struct ListNode *head = NULL;

void beginsert ();   
void lastinsert ();  
void randominsert();  
void begin_delete();  
void pop();
void random_delete();  
void display();  
void search();

int pop()
{
    struct ListNode *temp = head;
    int data = temp->data;
    head = temp->next;
    free(temp);
    return data;
}

void beginsert(int data)
{
    struct ListNode *temp = (struct ListNode *)malloc(sizeof(struct ListNode));
    temp->data = data;
    temp->next = head;
    head = temp;
}

void display()
{
    struct ListNode *temp = head;
    int count = 1;
    if (temp == NULL)
    {
        cout << "list is empty "<< endl;
        return;
    }
    while(temp != NULL){
        cout << count << ". " << temp->data << endl;
        temp = temp->next;
        count++ ;
    }
    cout << "list printing finished" << endl;
}

int delete_end()
{
    int data = 0;
    
    return data;
}

int main()
{
    // struct ListNode *head = NULL;
    int opt;
    bool exit = false;
    cout << "address of pilot Node" << head << endl;
    while(!exit)
    {
        cout << "select the option from below "<< endl;
        cout << "1. Display the list \n2. Insert \n3. delete top element or pop \n4. delete at the end \n5.exit \n";
        cout << "Enter your choice: ";
        cin >> opt;
        cout << opt << endl;

        switch(opt){
            case 1: display();
                    break;
            case 2:
                cout << "insert data that needs to be inserted into the list: ";
                int data;
                cin >> data;
                beginsert(data);
                cout << "address of pilot Node" << head << endl;
                break;
            case 3:
                cout << "poped element is: " << pop() << endl;
                break;
            case 4:
                cout << "last element that is deleted is :" delete_end() << endl;
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
