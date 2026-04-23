//single linked list Sorting

#include<iostream>
#include<cstdlib>
using namespace std;

void create();
void display();
void sort();

struct node
{
    int info;
    struct node *next;
};
struct node *start = NULL;

int main()
{
    int ch, i;
    cout << "Create list: First element:";
    create();
    while (1) {
        cout << "\n1.Display\n2.Sort\n3.Exit\n";
        cout << "Enter ur choice:";
        cin >> ch;
        switch (ch) {
        case 1:
            display();
            break;
        case 2:
            sort();
            cout << "\nAfter sorting:\n";
            display();
            break;
        case 3:	
            exit(0);
        }
    }
    return 0;
}

void create()
{
    struct node *newnode, *current;
    int ch;
    do {
        newnode = (struct node *)malloc(sizeof(struct node));
        if (newnode == NULL)
            cout << "\nMemory is Not Available\n";
        else {
            cout << "\nEnter Data :";
            cin >> newnode->info;
            newnode->next = NULL;
            if (start == NULL) {
                start = newnode;
                current = newnode;
            }
            else {
                current->next = newnode;
                current = newnode;
            }
        }
        cout << "Do you want to enter another element?(1/0)";
        cin >> ch;
    } while (ch != 0);
}

void sort()
{ 
    int t;
    struct node *temp1, *temp2;
    for (temp1 = start; temp1 != NULL; temp1 = temp1->next) {
        for (temp2 = temp1->next; temp2 != NULL; temp2 = temp2->next) {	
            if (temp1->info > temp2->info) {	
                t = temp1->info;
                temp1->info = temp2->info;
                temp2->info = t;
            }
        }
    }
}

void display()
{
    struct node *temp;
    
    if (start == NULL)
        cout << "\nList is Empty\n\n";
    else {
        cout << "\n";
        for (temp = start; temp->next != NULL; temp = temp->next)
            cout << temp->info << "-->";
        cout << temp->info << "\n";
    }
    cout << "\n";
}
