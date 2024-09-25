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
void printlist(list& l) {
    node* tmp = l.head;
    while (tmp != NULL) {
        cout << tmp->data << " ";
        tmp = tmp->next;
    }
    cout << endl;
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
int main() {
    list l;
    createlist(l);
    addtail(l, 1);
    addtail(l, 2);
    addtail(l, 3);
    addtail(l, 4);
    addtail(l, 5);
    cout << "Danh sach ban dau: ";
    printlist(l);
    reverseList(l);
    cout << "Danh sach sau khi dao nguoc: ";
    printlist(l);
    return 0;
}

