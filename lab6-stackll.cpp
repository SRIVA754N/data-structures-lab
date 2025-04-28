//stack implementation using linked list
#include<stdio.h>
#include<stdlib.h>

class stack{
private:
    struct node{
        char data;
        node* next;
    };
    node* top;
public:
    stack(){
        top = NULL;
    };
    void push(char ch);
    void pop();
    void peek();
};

//Declaring main functions and switching choices based on the user's inputs
int main(void){
    stack s;
    int choice;
    char ch;

while(1){
    printf(" Menu:\n 1.Push\n 2.Pop\n 3.Peek\n 4.Exit\n");
    scanf("%d",&choice);

switch(choice){
    case 1:
        printf("Enter a character:\n");
        scanf(" %c",&ch);
        s.push(ch);
        break;
    case 2:
        s.pop();
        break;
    case 3:
        s.peek();
        break;
    case 4:
        printf("Exiting the program.\n");
        return 0;
    default:
        printf("Invalid choice,enter again.\n");
  }
 }
}

//Push function declaration
void stack::push(char ch){
    node* newnode = (node*)malloc(sizeof(node));
    if (newnode == NULL){
        printf("Stack overflow.\n");
        return;
    }
    newnode->data = ch;
    newnode->next = top;
    top = newnode;
    printf("%c is pushed into the stack.",ch);
}

//Pop function declaration
void stack::pop(){
    if(top == NULL){
        printf("Stack underflow.\n");
        return;
    }
    node* temp = top;
    top = top->next;
    printf("%c is popped from the stack.\n",temp->data);
    free(temp);
    return;
}

//Peek function declaration
void stack::peek(){
    if (top == NULL){
        printf("Stack is empty.\n");
        return;
    }
    printf("%c is the peeked value from the stack.",top->data);
    return;
}

