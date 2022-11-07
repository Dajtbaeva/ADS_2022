#include <iostream>

using namespace std; 

class Node  
{  
    public: 
    string data;  
    Node* next;  
};  
  
void removeDuplicates(Node** head) 
{  
    Node * cur = * head;
    Node * temp = new Node();
    Node * ans = temp;
    while(cur){
        if(cur -> next && cur -> data == cur -> next -> data){
            Node * del = cur;
            cur = cur -> next;
            delete del;
        }else{
            temp -> next = cur;
            temp = temp -> next;
            cur = cur -> next;
        }
        temp -> next = NULL;
        * head = ans -> next;
    }


}  

int getCount(Node* head)  
{  
    int count = 0; 
    Node * cur = head;
    while(cur){
        count++;
        cur = cur -> next;
    }
    return count;  
}  

void push(Node** head_ref, string new_data)  
{  

    Node* new_node = new Node(); 
              

    new_node->data = new_data;  
                  

    new_node->next = (*head_ref);      
          

    (*head_ref) = new_node;  
}  
 

void printList(Node *node)  
{  
    while (node!=NULL)  
    {  
        cout<<node->data<<"\n";  
        node = node->next;  
    }  
}  

int main()  
{  
    int n;
    string s;
    cin>>n;
    Node* head = NULL;  
    for(int i =0;i<n;i++){
        cin>>s;
        push(&head,s);
    }
                                      
    removeDuplicates(&head);  
    cout<<"All in all: "<<getCount(head);
  
    cout<<"\nStudents:\n";      
    printList(head);              
  
    return 0;  
}