#include <iostream>
#include <vector>  
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
vector<node*> searchNode(list& l, int X) {
    vector<node*> result;  
    node* current = l.head;
    while (current != NULL) {
        if (current->data == X) {
            result.push_back(current);  
        }
        current = current->next;
    }
    return result; 
}
int main() {
    list l;
    createlist(l);
    addtail(l, 1);
    addtail(l, 2);
    addtail(l, 3);
    addtail(l, 2);
    addtail(l, 4);   
    int X;
    cout << "Nhap gia tri can tim: ";
    cin >> X;
    vector<node*> foundNodes = searchNode(l, X);
    if (foundNodes.empty()) {
        cout << "Khong tim thay gia tri " << X << " trong danh sach." << endl;
    } else {
        cout << "Tim thay gia tri " << X << " tai cac dia chi: " << endl;
    
        for (size_t i = 0; i < foundNodes.size(); i++) {
            cout << foundNodes[i] << " ";  
        }
        cout << endl;
    }
    return 0;
}

