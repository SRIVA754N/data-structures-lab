//stack implementation using array
#include<stdio.h>
#include<stdlib.h>
#define SIZE 5

class stackarray{
private:
    int top;
    char stack[SIZE];
public:
    stackarray(){
        top = -1;
    }
    void push(char ch);
    char pop(char ch);
    void peek();
};

//Declaring main functions and switching choices based on the user's inputs
int main(void){
    stackarray s;
    int choice;
    char ch;

while(1){
    printf("Menu:\n 1.Push\n 2.Pop\n 3.Peek\n 4.Exit\n");
    scanf("%d",&choice);

switch(choice){
    case 1:
        printf("Enter a character:\n");
        scanf(" %c",&ch);
        s.push(ch);
        break;
    case 2:
        s.pop(ch);
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
void stackarray::push(char ch){
    if (top == SIZE-1){
        printf("Memory overflow.\n");
        return;
    } else {
        stack[++top] = ch;
        printf("%c is pushed into the stack.\n",ch);
    }
}

//Pop function declaration
char stackarray::pop(char ch){
    if (top == -1){
        printf("Stack underflow.\n");
        return top;
    } else {
        printf("%c is popped from the stack.\n",ch);
        stack[top] = ' ';
        top--;
        return top;
    }
}

//Peek function declaration
void stackarray::peek(){
    if (top == -1){
        printf("Stack is empty.\n");
        return;
    } 
    printf("Top element: %c ",stack[top]);
    return ;
}