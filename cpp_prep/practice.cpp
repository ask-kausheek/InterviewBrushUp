struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// In C++, the NULL macro is often used to represent a null pointer.
// However, it's considered good practice to use nullptr instead, 
// especially in modern C++ (C++11 and beyond), as nullptr is type-safe and more explicit.
class Node { 
public: 
    int data; 
    Node* next; 
  
    // Default constructor 
    Node() 
    { 
        data = 0; 
        next = nullptr; 
    } 
  
    // Parameterised Constructor 
    Node(int data) 
    { 
        this->data = data; 
        this->next = nullptr; 
    } 
}; 

int main() {
    // Example usage
    ListNode* l1 = new ListNode(1);
    l1->next = new ListNode(3);
    delete l1; 
    return 0;
}