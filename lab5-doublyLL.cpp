// Doubly Linked List

#include <stdio.h>
#include<cstdlib>

//Structure element definition
struct element{
    int node;
    struct element* nextptr;
    struct element* prevptr;
};

// Doubly linked list definition
class DoublyLinkedList{
    private:
    struct element * headptr;
    int current;

    public:
    DoublyLinkedList(){
        headptr=NULL;
        current=0;
    }

    //Function prototypes
    int insertbeg(int);
    int insertend(int);
    int insertpos(int,int);
    int deletebeg();
    int deleteend();
    int deletepos(int);


    int search(int);

    int display();

};

//main function
int main(){

    class DoublyLinkedList dll;
    
    //Initialisation Variables needed for the code
    int choice;
    int result;
    int value;
    int position;

    int flag=1;//flag to control the while loop

    //while loop
    while (flag!=0){
        //Menu
        printf("1.Add element at beginning\n2.Add elemnt at position\n3.Add element at end\n4.Delete element at beginning\n5.Delete element at position\n6.Delete element at end\n7.Search\n8.Display\n9.Exit\n");
        printf("Enter choice\t");
        scanf("%d",&choice);
        switch (choice){
            // Handling of all choices

            case 1:
            printf("Enter the element to be added\t");
            scanf("%d",&value);
            result=dll.insertbeg(value);
            if (result==0){
                printf("Element was not added\n");
            }
            
            break;

            case 2:
            printf("Enter the element to be added\t");
            scanf("%d",&value);
            printf("Enter the positon the element to be added\t");
            scanf("%d",&position);
            result=dll.insertpos(value,position);
            if (result==0){
                printf("Element was not added\n");
            }

            break;

            case 3:
            printf("Enter the element to be added\t");
            scanf("%d",&value);
            result=dll.insertend(value);
            if (result==0){
                printf("Element was not added\n");
            }
            break;

            case 4:
            result=dll.deletebeg();
            if (result==-1){
                printf("Linked List empty\n");
            }
            else{
                printf("%d\n",result);
            }
            break;

            case 5:
            printf("Enter the position to be removed\t");
            scanf("%d",&position);
            result=dll.deletepos(position);
            if (result==-1){
                printf("Linked List empty or position out of range \n");
            }
            else{
                printf("%d\n",result);
            }
            break;

            case 6:
            result=dll.deleteend();
            if (result==-1){
                printf("Linked List empty\n");
            }
            else{
                printf("%d\n",result);
            }
            break;

            case 7:
            printf("Enter the element to be searched\t");
            scanf("%d",&value);
            result=dll.search(value);
            if (result==-1){
                printf("Element not found\n");
            }
            else{
                printf("Element %d found at position %d\n",value,result);
            }
            break;

            case 8:
            result=dll.display();
            if (result==0){
                printf("Linked List Empty\n");
            }
    
            break;

            case 9:
            printf("CODE OVER");
            flag=0;// Flag  marking the end of while loop 
            break;

            default:
            printf("Enter a valid choice between 1 to 9\n");
            break;
        }
    }

}

// Insert at beginning function
int DoublyLinkedList::insertbeg(int value){
    // Structure elemnt to create a new node
    struct element * newnode;
    newnode=(struct element *)malloc(sizeof(struct element));
    newnode->node=value;

    // Checking if  Linked List is empty
    if(headptr==NULL){
        newnode->nextptr=NULL;
        newnode->prevptr=NULL;
        headptr=newnode;
        current+=1;
        return 1;
    }
    // If not empty then
    headptr->prevptr=newnode;
    newnode->nextptr=headptr;
    newnode->prevptr=NULL;
    headptr=newnode;
    current+=1;
    return 1;
}

// Delete at beginning function
int DoublyLinkedList::deletebeg(){
    // If linked list is empty
    if(headptr==NULL){
        return -1;
    }
    
    
    // Else deletion will occur
    int result=headptr->node;

    // If linked list contains only a single element
    if (current==1){
        headptr=NULL;
        current-=1;
        return result;
    }

    headptr->nextptr->prevptr=NULL;
    headptr=headptr->nextptr;
    current-=1;
    //returning the deleted element
    return result;

}

//Insert at end function
int DoublyLinkedList::insertend(int value){
    // Structure elemnt to create a new node
    struct element * newnode;
    newnode=(struct element *)malloc(sizeof(struct element));
    newnode->node=value;

    // Structure elemnt to traverse the Doubly linked list
    struct element * currnode;
    currnode=headptr;

    while(currnode->nextptr!=NULL){
        currnode=currnode->nextptr;
    }

    newnode->nextptr=NULL;
    newnode->prevptr=currnode;
    currnode->nextptr=newnode;
    current+=1;
    return 1;
}

// Insert at position 
int DoublyLinkedList::insertpos(int value,int pos){
    int result;
    if(pos<1 || pos> current+1){
        return 0;
    }

    
    else if (pos==1){
        result=insertbeg(value);
        return result;
    }
    else if (pos == current +1){
        result=insertend(value);
        return result;
    }

    // Structure elemnt to create a new node
    struct element * newnode;
    newnode=(struct element *)malloc(sizeof(struct element));
    newnode->node=value;

    // Structure elemnt to traverse the Doubly linked list
    struct element * currnode;
    currnode=headptr;

    for(int i=2;i<pos;i++){
        currnode=currnode->nextptr;
    }

    currnode->nextptr->prevptr=newnode;
    newnode->nextptr=currnode->nextptr;
    newnode->prevptr=currnode;
    currnode->nextptr=newnode;
    current+=1;
    return 1;

}

// Delete at position
int DoublyLinkedList::deletepos(int pos){
    int result;
    if (pos<1 || pos>current || current<1 ){
        return -1;
    }
    if (pos==1){
        result=deletebeg();
        return result;
    }
    else if (pos==current){
        result=deleteend();
        return result;
    }

    // Structure elemnt to traverse the Doubly linked list
    struct element * currnode;
    currnode=headptr;

    for(int i=2;i<pos;i++){
        currnode=currnode->nextptr;
    }
    result=currnode->nextptr->node;
    currnode->nextptr->nextptr->prevptr=currnode;
    currnode->nextptr=currnode->nextptr->nextptr;
    current-=1;
    return result;




}

//Delete at end function
int DoublyLinkedList::deleteend(){
    // If linked list is empty
    if(headptr==NULL){
        return -1;
    }

    int result;

    // If linked list has only one element
    if (current==1){
        result=deletebeg();
        return result;
    }

    // Else
    // Structure elemnt to traverse the Doubly linked list
    struct element * currnode;
    currnode=headptr;

    while(currnode->nextptr!=NULL){
        currnode=currnode->nextptr;
    }

    result=currnode->node;
    currnode->prevptr->nextptr=NULL;
    current-=1;
    return result;

}

// search function
int DoublyLinkedList::search(int value){
    if (headptr==NULL){
        return -1;
    }
    // Structure elemnt to traverse the Doubly linked list
    struct element * currnode;
    currnode=headptr;

    int pos=1;
    
 
    while(currnode!=NULL){
        if (currnode->node==value){
            return pos;
        }
        pos+=1;
        currnode=currnode->nextptr;
    }
    return -1;
}

// Display function
int DoublyLinkedList::display(){
    if (headptr==NULL){
        return 0;
    }
    // Structure elemnt to traverse the Doubly linked list
    struct element * currnode;
    currnode=headptr;
    
    // Display in forward direction
    while(currnode->nextptr!=NULL){
        printf("%d\t",currnode->node);
        currnode=currnode->nextptr;
    }
    printf("%d\n",currnode->node);

    //Display in backward direction
    while(currnode->prevptr!=NULL){
        printf("%d\t",currnode->node);
        currnode=currnode->prevptr;
    }
    printf("%d\n",currnode->node);
    return 1;

}


