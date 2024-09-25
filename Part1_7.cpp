#include <iostream>
using namespace std;
struct node {
    int data;
    node* next;
};
struct list {
    node* head;
    node* tail;
};
void createlist(list& l) {
    l.head = NULL;
    l.tail = NULL;
}
void addtail(list& l, int x) {
    node* p = new node();
    p->data = x;
    p->next = NULL;
    if (l.tail == NULL) {
        l.tail = p;
        l.head = l.tail;
    } else {
        l.tail->next = p;
        l.tail = p;
    }
}
void reverseList(list& l) {
    node* prev = NULL;
    node* current = l.head;
    node* next = NULL;
    while (current != NULL) {
        next = current->next;  
        current->next = prev;  
        prev = current;       
        current = next;        
    }
    l.tail = l.head;  
    l.head = prev;    
}

bool compareLists(list& l1, list& l2) {
    node* tmp1 = l1.head;
    node* tmp2 = l2.head;

    while (tmp1 != NULL && tmp2 != NULL) {
        if (tmp1->data != tmp2->data) {
            return false; 
        }
        tmp1 = tmp1->next;
        tmp2 = tmp2->next;
    }
    return (tmp1 == NULL && tmp2 == NULL);
}
list copyList(list& l) {
    list newList;
    createlist(newList);

    node* current = l.head;
    while (current != NULL) {
        addtail(newList, current->data); 
        current = current->next;
    }

    return newList;
}

int main() {
    list l;
    createlist(l);
    addtail(l, 1);
    addtail(l, 1);
    addtail(l, 2);
    addtail(l, 1);
    addtail(l, 1);
    list reversedList = copyList(l);
    reverseList(reversedList);
    if (compareLists(l, reversedList)) {
        cout << "yes" << endl;
    } else {
        cout << "no" << endl;
    }
    return 0;
}

