#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* prev;
    struct node* next;
} node;

void insertAtBeginning(node** head, node** tail, int data);
void insertAtEnd(node** head, node** tail, int data);
void insertAtPosition(node** head, node** tail, int data, int position);
void deleteAtBeginning(node** head, node** tail);
void deleteAtEnd(node** head, node** tail);
void deleteAtPosition(node** head, node** tail, int n);
void display(node** head, node** tail);
void count(node** head);
void reverse(node** head, node** tail);
void removeDuplicates(node** head, node** tail);
void sort(node** head, node** tail);
int getch();

node* head = NULL;  // global variable which is the head of the list, it's accessible by any function of this program
node* tail = NULL;

int main() {
	
	int choice,n,pos;
        while(1){
        	system("cls");
            printf("------Doubly linked list operations------------\n");
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
			printf("11.Remove duplicates\n");
			printf("12.Exit\n");
            printf("--------------------------------------\n");
            printf("Enter your choice:");
            scanf("%d",&choice);
            switch(choice){
                case 1: printf("donner une valeur:");
                		scanf("%d",&n);
						insertAtBeginning(&head,&tail,n);
                        break;
                        
				case 2: printf("donner une valeur:");
                		scanf("%d",&n);
						insertAtEnd(&head,&tail,n);
                        break;
                
                case 3: printf("donner une valeur:");
                		scanf("%d",&n);
                		printf("donner un position:");
                		scanf("%d",&pos);
						insertAtPosition(&head,&tail,n,pos);
                        break;
                
                case 4: deleteAtBeginning(&head,&tail);
                        break;
                
				case 5: deleteAtEnd(&head,&tail);
                        break;
                
                case 6: printf("donner un position:");
                		scanf("%d",&pos);
						deleteAtPosition(&head,&tail,pos);
                		break;
                
                case 7: display(&head,&tail);
                		break;
                		
                case 8: count(&head);
                		break;
                
                case 9: reverse(&head,&tail);
                		break;
                		
                case 10:sort(&head,&tail);
                		break;
				
				case 11:removeDuplicates(&head,&tail);
                		break;
                		
				case 12:exit(0);
                        break;
						   
                default: printf("Wrong Choice\n");
                        break;
            }
                
            getch();
        }
	    
    return 0;
}

void insertAtBeginning(node** head, node** tail, int data) {

    node* newNode = (node*)malloc(sizeof(node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
        *tail = newNode;
    } else {
        newNode->next = *head;
        (*head)->prev = newNode;
        *head = newNode;
    }
}

void insertAtEnd(node** head, node** tail, int data) {

    node* newNode = (node*)malloc(sizeof(node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
        *tail = newNode;
    } else {
        (*tail)->next = newNode;
        newNode->prev = *tail;
        *tail = newNode;
    }
}

void insertAtPosition(node** head, node** tail, int data, int position) {

    if (position <= 0) {
        printf("Invalid position\n");
        return;
    }

    if (position == 1) {
        insertAtBeginning(head, tail, data);
        return;
    }

    node* newNode = (node*)malloc(sizeof(node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;

    node* temp = *head;
    int count = 1;
    while (temp != NULL && count < position - 1) {
        temp = temp->next;
        count++;
    }

    if (temp == NULL) {
        printf("Invalid position\n");
        return;
    }

    newNode->next = temp->next;
    newNode->prev = temp;
    if (temp->next != NULL) {
        temp->next->prev = newNode;
    }
    temp->next = newNode;

    if (newNode->next == NULL) {
        *tail = newNode;
    }
}

void deleteAtBeginning(node** head, node** tail) {

    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }

    if ((*head)->next == NULL) {
        free(*head);
        *head = NULL;
        *tail = NULL;
        return;
    }

    node* temp = *head;
    *head = temp->next;
    (*head)->prev = NULL;
    free(temp);
}

void deleteAtEnd(node** head, node** tail) {

    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }

    if ((*head)->next == NULL) {
        free(*head);
        *head = NULL;
        *tail = NULL;
        return;
    }

    node* temp = *tail;
    *tail = temp->prev;
    (*tail)->next = NULL;
    free(temp);
}

void deleteAtPosition(node** head, node** tail, int n) {

    if (n <= 0) {
        printf("Invalid position.\n");
        return;
    }

    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }

    if (n == 1) {
        deleteAtBeginning(head, tail);
        return;
    }

    node* current = *head;
    int count = 1;

    while (current != NULL && count < n) {
        current = current->next;
        count++;
    }

    if (current == NULL) {
        printf("Invalid position.\n");
        return;
    }

    if (current->next == NULL) {
        *tail = current->prev;
        (*tail)->next = NULL;
        free(current);
        return;
    }

    current->prev->next = current->next;
    current->next->prev = current->prev;
    free(current);
}

void display(node** head, node** tail) {

    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }

    node* temp = *head;
    printf("Doubly Linked List: ");

    while (temp != NULL) {
        printf("%d->", temp->data);
        temp = temp->next;
    }

    printf("\n");
}

void count(node** head) {

    int cpt = 0;
    node* temp = *head;

    while (temp != NULL) {
        cpt++;
        temp = temp->next;
    }

    printf("Number of nodes: %d\n", cpt);
}

void reverse(node** head, node** tail) {
    
	node* p = *head;
    node* q = *tail;
    int temp;

    while (p != q && p->prev != q) {
        temp = p->data;
        p->data = q->data;
        q->data = temp;
        p = p->next;
        q = q->prev;
    }
}

void removeDuplicates(node** head, node** tail) {

    node* current = *head;
    node* nextNode;

    while (current != NULL) {
        nextNode = current->next;

        while (nextNode != NULL) {
            if (current->data == nextNode->data) {
                // Duplicate found, remove the duplicate node
                node* duplicate = nextNode;

                if (duplicate->prev != NULL) {
                    duplicate->prev->next = duplicate->next;
                }

                if (duplicate->next != NULL) {
                    duplicate->next->prev = duplicate->prev;
                }

                node* temp = duplicate;
                nextNode = nextNode->next;

                free(temp);
            } else {
                nextNode = nextNode->next;
            }
        }

        current = current->next;
    }
}

void sort(node** head, node** tail){
	
	node* p = *head;
	node* q;
	int temp;
	
	while(p->next != NULL){
		node* q = p->next;
		while(q != NULL){
			if(p->data > q->data){
				temp = p->data;
				p->data = q->data;
				q->data = temp;
			}
			q = q->next;
		}	
		p = p->next;
	}
	
}


