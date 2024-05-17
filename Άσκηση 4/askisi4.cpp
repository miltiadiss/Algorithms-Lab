#include <iostream>
using namespace std;
struct Node
{
 int data;
 struct Node *prev;
 struct Node *next;
};
struct Node* head = NULL; //Create new "node" 
struct and a pointer named head
void put(int newdata) //The function "put" creates 
a new node and stores the new number
{
 struct Node* newnode = (struct Node*) 
malloc(sizeof(struct Node)); //Allocates a "node" 
structure size block of memory, returning a pointer to 
the beginning of the block.
 (*newnode).data = newdata;
 (*newnode).prev = NULL;
 (*newnode).next = head;
 if(head != NULL)
 (*head).prev = newnode ;
 head = newnode;
}
void print() //Displays the list
{
 struct Node* ptr;
 ptr = head;
 while(ptr != NULL)
 {
 cout<< (*ptr).data <<" ";
 ptr = (*ptr).next;
 }
}
void Search(Node **head, int a)
{
 Node *curA = *head;
 Node *prevA = NULL;
 while(curA && curA->data != a)
 {
 prevA = curA;
 curA = curA->next;
 }
 Node *curB = curA->next;
 Node *prevB = curA;
 if (curA->data == a) cout<<endl<<"Number "<<a<<" is 
found in the linked list.";
 if (curA == NULL || curB == NULL) cout<<endl<<"No 
swap occurs because "<<a<<" is the last element of the 
linked list.";
 if (prevA != NULL) prevA->next = curB;
 else *head = curB;
 if (prevB != NULL) prevB->next = curA;
 else *head = curA;
 if (prevA == NULL)
 {
 *head=curB;
 prevB->next = curA;
 }
 
 Node *temp;
 temp = curB->next;
 curB->next = curA->next;
 curA->next = temp;
 cout<<endl<<"The new linked list after the swap is : 
";
 print();
}
int main()
{
 int num;
 put(17);
 put(62);
 put(5);
 put(34);
 put(22);
 put(46);
 cout<<"The stored numbers in the linked list are : ";
 print();
 cout<<endl<<"Please enter a number to be found in the 
linked list : ";
 cin >> num;
 Search(&head, num);
 return 0;
}
