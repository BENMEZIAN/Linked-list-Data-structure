#include <stdio.h>
#include <stdlib.h>


typedef struct node{
    int data;
    struct node* next;
}node;


void insertAtBeginning(node** head,int data);
void insertAtEnd(node** head,int data);
void insertAtPosition(node** head,int data,int pos);
void display(node** head);
void deleteAtBeginning(node** head);
void deleteAtEnd(node** head);
void deleteAtPosition(node** head,int pos);
void count(node** head);
void sort(node** head);
void reverse(node** head);
int getch();

node *head=NULL;  // global variable which is the head of the list, it's accessible by any function of this program

int main(){
	
	int choice,n,pos;
        while(1){
        	system("cls");
            printf("------Circular linked list operations------------\n");
            printf("1.Insert at the beginning\n");
            printf("2.Insert at the end\n");
        	printf("3.Insert at specified position\n");
        	printf("4.Delete from beginning\n");
            printf("5.Delete from the end\n");
            printf("6.Delete from specified position\n");
            printf("7.Display\n");
            printf("8.Count (number of elements)\n");
			printf("9.Reverse list\n");
			printf("10.Sort list\n");
			printf("11.Exit\n");
            printf("--------------------------------------\n");
            printf("Enter your choice:");
            scanf("%d",&choice);
            switch(choice){
                case 1: printf("donner une valeur:");
                		scanf("%d",&n);
						insertAtBeginning(&head,n);
                        break;
                        
				case 2: printf("donner une valeur:");
                		scanf("%d",&n);
						insertAtEnd(&head,n);
                        break;
                
                case 3: printf("donner une valeur:");
                		scanf("%d",&n);
                		printf("donner un position:");
                		scanf("%d",&pos);
						insertAtPosition(&head,n,pos);
                        break;
                
                case 4: deleteAtBeginning(&head);
                        break;
                
				case 5: deleteAtEnd(&head);
                        break;
                
                case 6: printf("donner un position:");
                		scanf("%d",&pos);
						deleteAtPosition(&head,pos);
                		break;
                
                case 7: display(&head);
                		break;
                		
                case 8: count(&head);
                		break;
                
                case 9: reverse(&head);
                		break;
                		
                case 10:sort(&head);
                		break;
                		
				case 11:exit(0);
                        break;
						   
                default: printf("Wrong Choice\n");
                        break;
            }
                
            getch();
        }
	    
    return 0;
}

void insertAtBeginning(node** head,int data){

	node *newNode = (node*) malloc(sizeof(node));
	newNode->data = data;
	
	if(*head == NULL){
	    *head = newNode;
	    (*head)->next = *head;
	    return;
	}
	
	node* curr = *head;
	
	while(curr->next != *head){
	    curr = curr->next;
	}
	  
	curr->next = newNode; // assign LL's last node's next as this new node  
	newNode->next = *head; // assign newNode's next as current head
	*head = newNode; // change head to this new node
}

void insertAtEnd(node** head,int data){

	node *newNode = (node*) malloc(sizeof(node));
	newNode->data = data;
	  
	if(*head == NULL){
	    *head = newNode;
	    (*head)->next = *head;
	    return;
	}
	
	node *curr = *head;
	
	while(curr->next != *head){
	    curr = curr->next;
	}
	
	curr->next = newNode; // assign LL's current last node's next as this new node  
	newNode->next = *head; // assign this new node's next as current head of LL
}

void insertAtPosition(node** head,int data,int pos){
	
	node *newnode, *curNode;
	int i;
	
	if(*head == NULL){
	    printf ("List is empty");
	}
	  
	if (pos == 1){
	    insertAtBeginning(head, data); // why we do this
	    return;
	}else{
	    newnode = (node*)malloc(sizeof(node));
	    newnode->data = data;
	    curNode = *head;
	    while (--pos > 1){
		  curNode = curNode->next;
		}
		
	    newnode->next = curNode->next;
	    curNode->next = newnode;
	}
}

void display(node** head){
  
	if(*head == NULL){
		return;
	}
	
	node* temp = *head;
	
	do{
	    printf ("%d->", temp->data);
	    temp = temp->next;
	}while (temp != *head);
	
	printf ("NULL\n");
}

void deleteAtBeginning(node** head){

	node *tempNode = *head;
	  
	if(*head == NULL){
	    printf ("Linked List Empty, nothing to delete");
	    return;
	}
	
	if(tempNode->next == *head){
	    *head = NULL;
	    return;
	}
	
	node *curr = *head;
	
	while (curr->next != *head){
		curr = curr->next;
	}
	  
	curr->next = (*head)->next; // assign last node's next to 2nd node in CLL
	*head = (*head)->next; // move head to next node
	free (tempNode);
}

void deleteAtEnd(node** head){
	
	node *tempNode = *head;
	node *previous;
	
	if(*head == NULL){
	    printf ("Linked List Empty, nothing to delete");
	    return;
	}
	
	if (tempNode->next == *head){
	    *head = NULL;
	    return;
	}
	
	while (tempNode->next != *head){
	    // store previous link node as we need to change its next val
	    previous = tempNode;
	    tempNode = tempNode->next;
	}
	
	previous->next = *head; // Curr assign 2nd last node's next to head
	free (tempNode); // delete the last node
	// 2nd last now becomes the last node
}

void deleteAtPosition(node** head,int pos){
	
	int i;
    node *temp,*ptr;
        
    if(*head==NULL){
        printf("The List is Empty\n");
        exit(0);
    }else{
        if(pos==1){
            deleteAtBeginning(head);
        }else{
            ptr=*head;
            for(i=0;i<pos-1;i++) { 
				temp=ptr; 
				ptr=ptr->next;
                if(ptr==NULL){
                    printf("Position not Found\n");
                    return;
                }
            }
                
			temp->next = ptr->next;
            printf("The deleted element is:%d\n",ptr->data);
            free(ptr);
        }
    }	
}

void count(node** head){
	
	node* temp = *head;
	int cpt = 1;
	
	while(temp->next!=*head){
		temp = temp->next;
		cpt++;
	}
	
	printf("Le nombre d'elements est: %d",cpt);
}

void sort(node** head) {
    
	if (*head == NULL || (*head)->next == *head) {
        // Empty list or single node, no sorting required
        return;
    }
    
    int swapped;
    node* current;
    node* nextNode;

    do{
        swapped = 0;
        current = *head;
        nextNode = current->next;

        while (current->next != *head) {
            if (current->data > nextNode->data) {
                // Swap the nodes' data
                int temp = current->data;
                current->data = nextNode->data;
                nextNode->data = temp;
                swapped = 1;
            }

            current = current->next;
            nextNode = nextNode->next;
        }
    }while(swapped);
    
    display(head);
}

void reverse(node** head) {
    
	if (*head == NULL || (*head)->next == *head) {
        // Empty list or single node, no reversal required
        return;
    }

    node* current = *head;
    node* prev = NULL;
    node* nextNode = (*head)->next;

    do {
        current->next = prev;
        prev = current;
        current = nextNode;
        nextNode = nextNode->next;
    } while (current != *head);

    // Adjust pointers to complete the reversal
    (*head)->next = prev;
    *head = prev;
    
    display(head);
}





