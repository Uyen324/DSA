#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

struct node {
    int value;
    node* next;
    node* random;
    node(int x) : value(x), next(NULL), random(NULL) {}
};

struct list {
    node* head;
    node* tail;
};

void createlist(list& l) {
    l.head = NULL;
    l.tail = NULL;
}

node* createnode(int x) {
    node* tmp = new node(x);
    return tmp;
}

void printlist(list& l) {
    node* temp = l.head;
    while (temp != NULL) {
        cout << temp->value << " ";
        temp = temp->next;
    }
    cout << endl;
}

void addtail(list& l, int x) {
    node* newnode = createnode(x);
    if (l.head == NULL) {
        l.head = newnode;
        l.tail = newnode;
    } else {
        l.tail->next = newnode;
        l.tail = newnode;
    }
}

void addtwonumbers(list& l, int val1, int val2, int position) {
    node* newnode1 = createnode(val1);
    node* newnode2 = createnode(val2);

    if (position == 0) {
        newnode2->next = l.head;
        newnode1->next = newnode2;
        l.head = newnode1;
        if (l.tail == NULL) l.tail = newnode2;
    } else {
        node* temp = l.head;
        for (int i = 0; temp && i < position - 1; ++i) {
            temp = temp->next;
        }
        if (temp != NULL) {
            newnode2->next = temp->next;
            temp->next = newnode1;
            newnode1->next = newnode2;
            if (newnode2->next == NULL) l.tail = newnode2;
        }
    }
}

list copyrandomlist(list& l) {
    list copiedlist;
    createlist(copiedlist);

    if (l.head == NULL) return copiedlist;

    node* temp = l.head;
    while (temp != NULL) {
        node* copy = createnode(temp->value);
        copy->next = temp->next;
        temp->next = copy;
        temp = copy->next;
    }

    temp = l.head;
    while (temp != NULL) {
        if (temp->random != NULL) {
            temp->next->random = temp->random->next;
        }
        temp = temp->next->next;
    }

    node* newhead = l.head->next;
    node* current = l.head;

    while (current != NULL) {
        node* copy = current->next;
        current->next = copy->next;
        if (copy->next != NULL) {
            copy->next = copy->next->next;
        }
        current = current->next;
    }

    copiedlist.head = newhead;
    return copiedlist;
}

void swapnodes(list& l, int k) {
    if (l.head == NULL) return;

    node* first = l.head;
    node* second = l.head;
    node* temp = l.head;
    int length = 0;

    while (temp != NULL) {
        length++;
        temp = temp->next;
    }

    for (int i = 1; i < k; ++i) {
        first = first->next;
    }
    for (int i = 1; i < length - k + 1; ++i) {
        second = second->next;
    }

    int tempvalue = first->value;
    first->value = second->value;
    second->value = tempvalue;
}

void removenthfromend(list& l, int n) {
    if (l.head == NULL) return;

    node* temp1 = l.head;
    node* temp2 = l.head;

    for (int i = 0; i < n; ++i) {
        if (temp1->next == NULL) {
            node* temp3 = l.head;
            l.head = l.head->next;
            delete temp3;
            return;
        }
        temp1 = temp1->next;
    }

    while (temp1->next != NULL) {
        temp1 = temp1->next;
        temp2 = temp2->next;
    }

    node* nodetodelete = temp2->next;
    temp2->next = temp2->next->next;
    delete nodetodelete;
}

void separateoddevennodes(list& l) {
    if (l.head == NULL) return;

    node* odd = l.head;
    node* even = l.head->next;
    node* evenhead = even;

    while (even && even->next) {
        odd->next = even->next;
        odd = odd->next;
        even->next = odd->next;
        even = even->next;
    }

    odd->next = evenhead;
}

void automaticinput(list& l) {
    srand(time(0));
    int numentries = (rand() % 21) + 39;
    for (int i = 0; i < numentries; ++i) {
        int value = (rand() % 199) - 99;
        addtail(l, value); 
    }
}

void menu() {
    list l;
    createlist(l);
    addtail(l, 2);
    addtail(l, 9);
    addtail(l, 12);
    addtail(l, 23);
    addtail(l, 5);
    addtail(l, 7);

    while (true) {
        cout << "\nMenu:\n";
        cout << "1. Add two numbers\n";
        cout << "2. Copy random list\n";
        cout << "3. Swap nodes\n";
        cout << "4. Remove nth node from end\n";
        cout << "5. Separate odd and even nodes\n";
        cout << "6. Automatic input\n";
        cout << "7. Print list\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";

        int choice;
        cin >> choice;

        switch (choice) {
            case 1: {
                int val1, val2, position;
                cout << "Enter first value: ";
                cin >> val1;
                cout << "Enter second value: ";
                cin >> val2;
                cout << "Enter position: ";
                cin >> position;
                addtwonumbers(l, val1, val2, position);
                cout << "List after adding two numbers: ";
                printlist(l);
                break;
            }
            case 2: {
                list copiedlist = copyrandomlist(l);
                cout << "Copied list: ";
                printlist(copiedlist);
                break;
            }
            case 3: {
                int k;
                cout << "Enter the position to swap: ";
                cin >> k;
                swapnodes(l, k);
                cout << "List after swapping nodes: ";
                printlist(l);
                break;
            }
            case 4: {
                int n;
                cout << "Enter the position from the end to remove: ";
                cin >> n;
                removenthfromend(l, n);
                cout << "List after removing nth node from end: ";
                printlist(l);
                break;
            }
            case 5: {
                separateoddevennodes(l);
                cout << "List after separating odd and even nodes: ";
                printlist(l);
                break;
            }
            case 6: {
                automaticinput(l);
                cout << "List after automatic input: ";
                printlist(l);
                break;
            }
            case 7: {
                cout << "Current list: ";
                printlist(l);
                break;
            }
            case 0:
                exit(0);
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }
}

int main() {
    menu();
    return 0;
}

