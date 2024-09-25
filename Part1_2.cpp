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
bool detectCycle(list& l) {
    if (l.head == NULL) return false;  

    node* slow = l.head;
    node* fast = l.head;
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;            
        fast = fast->next->next;      
        if (slow == fast) {
            return true;
        }
    }
    return false; 
}
int main() {
    list l;
    createlist(l);
    addtail(l, 1);
    addtail(l, 2);
    addtail(l, 3);
    addtail(l, 4);
    addtail(l, 5);
    l.tail->next = l.head->next;
    if (detectCycle(l)) {
        cout << "Danh sach co chu trinh." << endl;
    } else {
        cout << "Danh sach khong co chu trinh." << endl;
    }
    return 0;
}

