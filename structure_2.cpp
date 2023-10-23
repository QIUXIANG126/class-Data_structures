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

bool InsertAfter(listnode*p ,int value){
    listnode* Newnode;
    Newnode = new NODE;
    if (Newnode == NULL){
        return false;
    }
    Newnode->data = value;
    Newnode->next = p->next;
    p->next = Newnode;
    return true;
}

listnode* GetPreNode(listnode* head, listnode* Oldnode){
    listnode* p,*q;
    p = head;
    q = head->next;
    while((q != NULL) && (q != Oldnode)){
        p = q;
        q = q->next;
    }if (q != NULL){
        return p;
    }else{
        return NULL;
    }
}

bool DeleteNode(listnode* head, listnode* OldNode){
    listnode* PreNode;
    if(head == OldNode){
        return false;
    }
    PreNode = GetPreNode(head, OldNode);
    if(PreNode ==NULL){
        return false;
    }
    PreNode->next = OldNode->next;
    delete OldNode;
    return true;
}

int main(){
    NODE* listA = new NODE;
    NODE* listB = new NODE;
    listA -> data = 20;
    listA -> next =NULL;
    InsertTail(listB,10);
    InsertTail(listB,20);
    InsertTail(listB,30);
    InsertTail(listB,40);
    ListTraverse(listA);
    cout << endl;
    ListTraverse(listB);
    cout << endl;
    InsertAfter(listB->next->next,25);
    ListTraverse(listB);
    cout << endl;
    DeleteNode(listB,listB->next->next->next);
    ListTraverse(listB);
    delete listA;
    delete listB;
}