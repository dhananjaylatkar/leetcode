class Node {
public:
    int val;
    Node* next;
    Node(int val)
    {
        this->val = val;
        next = NULL;
    }
};
class MyLinkedList {
public:
    int size = 0;
    Node* head = new Node(0);
    MyLinkedList() {}
    
    int get(int index) {
        if(index >= size) return -1;
        Node* curr = head->next;
        while(index--)
        {
            curr = curr->next;
        }
        return curr->val;
    }
    
    void addAtHead(int val) {
        Node* temp = new Node(val);
        Node* curr = head->next;
        head->next = temp;
        temp->next = curr;
        size++;
    }
    
    void addAtTail(int val) {
        Node* temp = new Node(val);
        Node* curr = head;
        while(curr->next)
        {
            curr = curr->next;
        }
        curr->next = temp;
        size++;
    }
    
    void addAtIndex(int index, int val) {
        if(index > size) return;
        Node* temp = head;
        Node* new_node = new Node(val);
        while(index--)
        {
            temp = temp->next;
        }
        Node* temp1 = temp->next;
        temp->next = new_node;
        new_node->next = temp1;
        size++;
    }
    
    void deleteAtIndex(int index) {
        if(index >= size) return;
        Node* temp = head;
        while(index--)
        {
            temp = temp->next;
        }
        Node* temp1 = temp->next;
        temp->next = temp1->next;
        size--;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */