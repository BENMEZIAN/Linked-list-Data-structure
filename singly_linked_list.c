#include <stdio.h>
#include <stdlib.h>


typedef struct node{
    int info;
    struct node *next;
}node;

     
void create();
void display();
void insert_begin();
void insert_end();
void insert_pos();
void delete_begin();
void delete_end();
void delete_pos();
void count();
void reverse();
void sort();
void removeDuplicates();
int getch();

node *start=NULL;  // global variable which is the head of the list, it's accessible by any function of this program

int main()     
{
        int choice;
        while(1){
        	system("cls");
            printf("------Linked list operations------------\n");
            printf("1.Create\n");
            printf("2.Display\n");
            printf("3.Insert at the beginning\n");
            printf("4.Insert at the end\n");
        	printf("5.Insert at specified position\n");
        	printf("6.Delete from beginning\n");
            printf("7.Delete from the end\n");
            printf("8.Delete from specified position\n");
            printf("9.Count (number of elements)\n");
			printf("10.Reverse list\n");
			printf("11.Sort list\n");
			printf("12.Remove duplicates\n");
			printf("13.Exit\n");
            printf("--------------------------------------\n");
            printf("Enter your choice:");
            scanf("%d",&choice);
            switch(choice){
                case 1: create();
                        break;
                        
				case 2: display();
                        break;
                        
				case 3: insert_begin();
                        break;
                        
				case 4: insert_end();
                        break;
                        
				case 5: insert_pos();
                        break;
                        
				case 6: delete_begin();
						break;
                        
				case 7: delete_end();
                        break;
                        
                case 8: delete_pos();
                        break;
                        
                case 9: count();
                        break;
                        
                case 10: reverse();
                        break;
                
                case 11: sort();
                        break;
                
                case 12: removeDuplicates();
                        break;
                
				case 13: exit(0);
                        break;
						   
                default: printf("Wrong Choice\n");
                        break;
            }
                
            getch();
        }
        
        return 0;
}

void create(){
	
        node *temp,*ptr;
        temp=(node *)malloc(sizeof(node));
        
        if(temp==NULL){
            printf("Out of Memory Space\n");
            exit(0);
        }
        
        printf("Enter the data value for the node:");
        scanf("%d",&temp->info);
		temp->next=NULL;
        
		if(start==NULL) {
            start=temp;
        }else{
            ptr=start;
            
			while(ptr->next!=NULL){
                    ptr=ptr->next;
            }
            
			ptr->next=temp;
        }
}

void display(){
	
        node *ptr;
        if(start==NULL){
			printf("List is empty\n");
            return;
        }else{
            ptr=start;
            printf("The List elements are: ");
            while(ptr!=NULL){
            	printf("%d->",ptr->info);
                ptr=ptr->next ;
            }
            
            printf("NULL\n");
        }
}

void insert_begin(){
	
        node *temp;
        temp=(node *)malloc(sizeof(node));
        
        if(temp==NULL){
            printf("Out of Memory Space\n");
            return;
        }
        
        printf("Enter the data value for the node:");
        scanf("%d",&temp->info);
        temp->next =NULL;
        
		if(start==NULL){
            start=temp;
        }else{
            temp->next=start;
            start=temp;
        }
}

void insert_end(){
	
        node *temp,*ptr;
        temp=(node *)malloc(sizeof(node));
        
        if(temp==NULL){
            printf("Out of Memory Space\n");
            return;
        }
        
        printf("Enter the data value for the node\n");
        scanf("%d",&temp->info );
        temp->next =NULL;
        
		if(start==NULL){
            start=temp;
        }else{
            ptr=start;
            while(ptr->next !=NULL){
                ptr=ptr->next ;
            }
            
			ptr->next =temp;
        }
}

void insert_pos(){
	
        node *ptr,*temp;
        int i,pos;
        temp=(node *)malloc(sizeof(node));
        
        if(temp==NULL){
            printf("Out of Memory Space\n");
            return;
        }
        
        printf("Enter the position for the new node to be inserted\n");
        scanf("%d",&pos);
        
        printf("Enter the data value of the node:");
        scanf("%d",&temp->info);
        temp->next=NULL;
        
        if(pos==0){
            temp->next=start;
            start=temp;
        }else{
            for(i=0,ptr=start;i<pos-1;i++) { 
				ptr=ptr->next;
                if(ptr==NULL){
                    printf("Position not found:[Handle with care]");
                    return;
                }
            }
            
            temp->next =ptr->next ;
            ptr->next=temp;
        }
}

void delete_begin(){
        
		node *ptr;
		
        if(ptr==NULL){
            printf("List is Empty\n");
            return;
        }else{
            ptr=start;
            start=start->next ;
            printf("The deleted element is :%d\n",ptr->info);
            free(ptr);
        }
}

void delete_end(){
        
		node *temp,*ptr;
		
        if(start==NULL){
            printf("List is Empty:\n");
            exit(0);
        }else if(start->next ==NULL){
            ptr=start;
            start=NULL;
            printf("The deleted element is:%d",ptr->info);
            free(ptr);
        }else{
            
			ptr=start;
			while(ptr->next!=NULL){
                temp=ptr;
                ptr=ptr->next;
            }
            
			temp->next=NULL;
            printf("The deleted element is:%d\n",ptr->info);
            free(ptr);
        }
}

void delete_pos(){
	
        int i,pos;
        node *temp,*ptr;
        
        if(start==NULL){
            printf("The List is Empty\n");
            exit(0);
        }else{
            printf("Enter the position of the node to be deleted\n");
            scanf("%d",&pos);
            if(pos==0){
                ptr=start;
                start=start->next ;
                printf("The deleted element is:%d\n",ptr->info  );
                free(ptr);
            }else{
                ptr=start;
                for(i=0;i<pos;i++) { 
					temp=ptr; ptr=ptr->next ;
                    if(ptr==NULL){
                        printf("Position not Found\n");
                        return;
                    }
                }
                
				temp->next =ptr->next ;
                printf("The deleted element is:%d\n",ptr->info );
                free(ptr);
            }
        }
}

void count(){
	
	node* temp = start;
	int cpt = 0;
	
	while(temp!=NULL){
		cpt++;
		temp = temp->next;
	}
	
	printf("Le nombre d'elements est: %d\n",cpt);
}

void reverse(){
	
    node* prev = NULL;
    node* current = start;
    node* next = NULL;
    
    while(current != NULL) {
        // Store next
        next = current->next;
 
        // Reverse current node's pointer
        current->next = prev;
 
        // Move pointers one position ahead.
        prev = current;
        current = next;
    }
    
	start = prev;
}


void sort(){
	
	node* p = start;
	node* q;
	int temp;
	
	while(p->next != NULL){
		node* q = p->next;
		while(q != NULL){
			if(p->info > q->info){
				temp = p->info;
				p->info = q->info;
				q->info = temp;
			}
			q = q->next;
		}
		
		p = p->next;
	}
	
	display();
}

void removeDuplicates(){
    
    node *current, *compare, *duplicate;
    current = start;

    while (current != NULL && current->next != NULL) {
        compare = current;
        while (compare->next != NULL) {
            if (current->info == compare->next->info) {
                duplicate = compare->next;
                compare->next = compare->next->next;
                free(duplicate);
            } else {
                compare = compare->next;
            }
        }

        current = current->next;
    }

    display();
}

