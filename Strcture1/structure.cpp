#include <iostream>

using namespace std;

typedef struct listnode{
    int data;
    struct listnode* next;
}NODE;

void ListTraverse(listnode* head){
    listnode* p = head;
    //p = p->next; 給無頭結點用
    while(p!=NULL){
        cout << p->data << " ";
        p = p->next;
    }
}

int InsertTail(NODE* head, int value){
    NODE* Newnode, *p = head;
    Newnode = new NODE;
    if(Newnode == NULL) return false;
    Newnode->data = value;
    Newnode->next = NULL;
    while(p->next != NULL)p = p->next;
        p->next = Newnode;
    return true;
}
NODE* listA = new NODE;
int main(){
    InsertTail(listA,10);
    InsertTail(listA,20);
    InsertTail(listA,30);
    InsertTail(listA,40);
    ListTraverse(listA);
    delete listA;
}