#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *next;
};
struct node *head=NULL;
struct node *head1=NULL;
struct node *head2=NULL;
int main()
{
       	printf("Enter elemets of First list");
	makeList1();
	
	printf("\nEnter elemets of Second list");
	makeList2();
	
	struct node *list1=head;
	struct node *list2=head1;
	while(list1!=NULL)
	{     
		struct node *newnode=(struct node *) malloc(sizeof(struct node));
	        if(head2==NULL)
		{
                	head2=newnode;
	        }                    
	        else
	        {
                	struct node *list3=head2;
	                while((list3->next)!=NULL)
	                {
	                	list3=list3->next;
	                }
	                        list3->next=newnode;
	        }  
	        newnode->data=list1->data; 
	        newnode->next=NULL;
	        list1=list1->next;
         }
         while(list2!=NULL)
         {
         	struct node *list1=head;
                int flag=0;
                while(list1!=NULL)
                {
                       flag=0;
                       if(list2->data==list1->data)
                       {
                    	   flag=1;
                           break;
                       }
 	               list1=list1->next;
                }
                if(flag==0)
                {
                	struct node *newnode=(struct node *) malloc(sizeof(struct node));
                        struct node *list3=head2;
                        while((list3->next)!=NULL) 
                        {
                        	list3=list3->next; 
                        } 
                        list3->next=newnode;
                        newnode->data=list2->data;
                        newnode->next=NULL;
                }
                list2=list2->next;
         }   
	printf("\nMerged list is  ");
	struct node *r=head2;
	while(r!=NULL)
	{
		printf("%d  ",r->data);
	        r=r->next;
	}   
	return 0;
}

int makeList1()
{
        int i=0,info;
	for(i=0;i<5;i++)
	{
	        struct node *newnode=(struct node *) malloc(sizeof(struct node));
	        scanf("%d", &info);
	        
	        newnode->data=info;
	        newnode->next=NULL;
	        if(head==NULL)
	        {
	                head=newnode; 
	        }
	        else
	        {
	                struct node *p=head;
	                while((p->next)!=NULL)
	                {
	                        p=p->next;       
	                }
	                p->next=newnode;       
	        }
	}  
	printf("Elements of First list are  ");
	struct node *p=head;
	while(p!=NULL)
	{
	        printf("%d  ",p->data);
	        p=p->next;
	}
	return 0;
}

int makeList2()
{       
        int i=0,info;
        for(i=0;i<5;i++)
	{
	        struct node *newnode=(struct node *) malloc(sizeof(struct node));
	        scanf("%d",&info);
	        newnode->data=info;
	        newnode->next=NULL;
	        if(head1==NULL)
	        {
	                head1=newnode;
	        }
	        else
	        {
	                struct node *p=head1;
	                while((p->next!=NULL))
	                {
	                        p=p->next;
	                }
	                p->next=newnode;
	        }
	}
	printf("Elements of Second list are  ");
	struct node *q=head1;
	while(q!=NULL)
	{
	        printf("%d  ",q->data);
	        q=q->next;
	}
	return 0;
}
