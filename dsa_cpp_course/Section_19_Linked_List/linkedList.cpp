#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node *next;

    Node (int data){
        this->data = data;
        this->next = NULL;
    }
};

void print(Node *&head){

    Node *temp = head;

    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp = temp->next;
    }
    cout<<"NULL"<<endl;
}

int length(Node *&head){

    Node *temp = head;
    int counter = 0;

    while(temp!=NULL){
        counter++;
        temp = temp->next;
    }

    return counter;
}

Node* takeInput(){
    int data;
    cin>>data;
    Node *head = NULL;          // LL is empty
    Node *tail = NULL;          // LL is empty

    while(data != -1){
        // Creating LL
        Node *n = new Node(data);
        if(head == NULL){       // if 1st node
            head = n;
            tail = n;
        } else{
            // inserting at tail
            tail->next = n;     // creates link from current tail location to new Node address
            tail = n;           // then moves tail to new node address
        }

        cin>>data;
    }
    // cout<<tail->data<<endl;
    return head;
}

// Inserting at head (reverse linked list)
Node* takeInput2(){
    int data;
    cin>>data;
    Node *head = NULL;          // LL is empty
    Node *tail = NULL;          // LL is empty

    while(data != -1){
        // Creating LL
        Node *n = new Node(data);
        if(head == NULL){       // if 1st node
            head = n;
            tail = n;
        } else{
            // inserting at head (reversing the link list)
            n->next = head;     // creates link from new node address to current head location
            head = n;           // then moves head to new node address
        }

        cin>>data;
    }
    // cout<<tail->data<<endl;
    return head;
}

void printIthNode(Node *head, int i){

    Node *temp = head;

    int len = length(head);

    if(i<len && i>=0){
        for(int j=0;j<i;j++){
            temp = temp->next;
        }
        cout<<temp->data<<endl;

    } else{
        cout<<"-1"<<endl;
        return;
    }
}

Node* insertIthNode(Node *head, int data, int i){
    if(i<0){
        return head;
    }

    if(i==0){
        Node *n = new Node(data);
        n->next = head;
        head = n;
        return head;
    }
    Node  *copyHead = head;         /// acts the same as a temp value, just so we don't displace the actual head of LL
    int count = 1;
    while(count<=i-1 && head!=NULL){
        head = head->next;
        count++;
    }
    if(head){
        /// First way of doing it
        // Node *n = new Node(data);
        // n->next = head->next;
        // head->next = n;
        
        /// Second way of doing it
        Node *n = new Node(data);
        Node *temp = head->next;
        head->next = n;
        n->next = temp;

        return copyHead;
    }
    return copyHead;
}

// With Memory Leak (not deleting stranded nodes)
Node* DeleteIthNode(Node *head, int i){

    if(i<0){
        return head;
    }

    if(i==0 && head){
        return head->next;      // returns address of second node (stranding first one) 
    }

    Node* curr = head;
    int count = 1;
    while(count<=i-1 && curr!=NULL){
        curr = curr->next;
        count++;
    }
    if(curr && curr->next){
        curr->next = curr->next->next;
        return head;
    }
    return head;
}

// Without memory leak
Node* DeleteIthNode2(Node *head, int i){

    if(i<0){
        return head;
    }

    if(i==0 && head){
        Node *newHead = head->next;
        head->next = NULL;              // isolate node
        delete head;                    // delete node
        return newHead;      // returns address of second node (deleting first one) 
    }

    Node* curr = head;
    int count = 1;
    while(count<=i-1 && curr!=NULL){
        curr = curr->next;
        count++;
    }
    if(curr && curr->next){
        Node *temp = curr->next;
        curr->next = curr->next->next;
        temp->next = NULL;              // isolate node
        delete temp;                    // delete node
        return head;
    }
    return head;
}

int main(){
    // Static objects
    // Node n1(1);
    // Node *head = &n1;

    // Node n2(2);
    // Node n3(3);
    // Node n4(4);
    // Node n5(5);

    // n1.next = &n2;
    // n2.next = &n3;
    // n3.next = &n4;
    // n4.next = &n5;

    // print(head);

    // Dynamic objects
    // Node *n3 = new Node(3);
    // Node *n4 = new Node(4);

    Node *head = takeInput();
    print(head);

    // Node *head2 = takeInput2();
    // print(head2);

    int len = length(head);
    cout<<"Length is: "<<len<<endl;

    int i,data;
    // cin>>i>>data;
    cin>>i;
    // printIthNode(head,i);
    // head = insertIthNode(head, data, i);
    head = DeleteIthNode2(head,i);
    print(head);

    return 0;
}