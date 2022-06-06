#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_NAME 40
#define MAX_SUB_CODE 10
typedef struct node_tag
{
 int roll_no;
 int marks;
 char sub_code[MAX_SUB_CODE];
 char stu_name[MAX_NAME];
 struct node_tag *next;
}Node;
typedef struct max_node_tag
{
	int roll_no;
	struct max_node_tag *next;
}Max_Node;
typedef struct total_node_tag
{
	int roll_no;
	int total;
	struct total_node_tag *next;
}total_Node;
typedef struct popular_node_tag
{
	char sub_code[MAX_SUB_CODE];
	float avg;
	int count;
	int total;
	struct popular_node_tag *next;
}Popular_Node;
typedef enum {FAILURE,SUCCESS}status_code;
typedef enum {FALSE,TRUE} Boolean;
status_code insert(Node **);
void print_list(Node **);
status_code delete(Node **,int r,char[]);
int getNumRecords(Node **);
Boolean isEmpty(Node **);
Boolean isFull(Node **);
Max_Node* getMaxMarks(Node **,char *str);
Max_Node* Topper(Node **);
Max_Node* Find_Failures(Node **lptr,int K, int P);
void list_unique(Node **lptr);
Node* list_union(Node **lptr1,Node **lptr2);
Node* list_intersection(Node **lptr1,Node **lptr2);
Node* list_difference(Node **lptr1,Node **lptr2);
Node* list_symmetric_difference(Node **lptr1,Node **lptr2);
Popular_Node* Kth_popular_subject(Node **lptr,int K);
Node* insert_duplicate(Node **lptr);
Popular_Node*  Merge_Sort(Popular_Node *head);
Popular_Node* Divide(Popular_Node *head);
Popular_Node* Merge(Popular_Node*head,Popular_Node*ptr);
status_code delete_list(Node **);
void main()
{
 int operation,t,roll_no,ans,k,p,i,n1,n2;
 Boolean result;
 char str[MAX_SUB_CODE];
 Node **lptr,*head1=NULL,*head2=NULL,*head_list_out=NULL;
 Max_Node *op_struct,*ptr,*op_max;
 Popular_Node *tptr,*head_Kthpop,*ptr1,*ptr2;
 status_code sc;
 t=1;
 lptr=(Node**)malloc(sizeof(Node*));
 *lptr=NULL;
    printf("Case 0:Quit\n");
 	printf("Case 1:Insert Node\n");
 	printf("Case 2:Delete Node\n");
 	printf("Case 3:Number of Records\n");
 	printf("Case 4:Record is empty or not\n");
 	printf("Case 5:Record is full or not\n");
 	printf("Case 6:Max marks in the given subject\n");
 	printf("Case 7:Who is topper\n");
 	printf("Case 8:Kth popular subject\n");
 	printf("Case 9:No. of failure students in given no.of sujects \n");
 	printf("Case 10:Union of two given lists \n");
 	printf("Case 11:Intersection of two given lists\n");
 	printf("Case 12:Difference of two given lists\n");
 	printf("Case 13:Symmetric Difference of two given lists\n");
 	printf("Case 14:Print given lists\n");
 	
 while(t==1)
 {  printf("Enter the case no:\n");
 	scanf("%d",&operation);
 	switch(operation)
 	{
 		case 0:
 			   t=0;
 			   break;
 		case 1:
		       sc=insert(lptr);
			   if(sc==SUCCESS)
			   {
			   	printf("Insertion opeartion is successful\n");
			   	printf("\n");
			    
			   }
			   else
			   {
			   	printf("Insertion operation is unsuccessful\n");
		       }
			   break;
		case 2:
		       printf("Enter the roll no.");
			   scanf("%d",&roll_no);
			   printf("Enter the subject code");
			   scanf("%s",str);
			   sc= delete(lptr,roll_no,str);
			   if(sc==SUCCESS)
			   {
			   	printf("Deletion opration is successfull\n");
		       }
			   else
			   {
			   	printf("Deletion opeartion is unsuccessful\n");
		       }
			   break;
        case 3:
		       ans=getNumRecords(lptr);
			   printf("No. of active records in the list:%d\n",ans);
			   break;
	    case 4:
		        result=isEmpty(lptr);
				if(result==TRUE)
				{
				 printf("List is Empty\n");
			    }
				else
				{
			     printf("List is not Empty\n");
				} 
				break;
		case 5:result=isFull(lptr);
		       if(result==TRUE)
			   {
			   	printf("List is Full\n");
			   }
			   else
			   {
			   	printf("List is not Full\n");
			   }
			   break;
		case 6:printf("Enter the subject code\n");
		       scanf("%s",str);
			   op_struct=getMaxMarks(lptr,str);
			   ptr=op_struct;
			   while(ptr!=NULL)
			   {
			   	    printf("%d \n",ptr->roll_no); 
			   	    ptr=ptr->next;
			   }
			   printf("\n");
			   break;
		case 7:printf("Which student has the highest total marks in all the subjects?\n" );
		       op_max=Topper(lptr);
			   while(op_max!=NULL)
			   {
			   	    printf("%d \n",op_max->roll_no); 
			   	    op_max=op_max->next;
			   }
			   printf("\n");
			   break;
		case 8:
		       printf("Enter the value of  K\n");
			   scanf("%d",&k);
			   head_Kthpop=Kth_popular_subject(lptr, k);
			   tptr=head_Kthpop;
			   while(tptr!=NULL)
			   {
			   	    printf("%s \n",tptr->sub_code); 
			   	    tptr=tptr->next;
			   }
			   printf("\n");
			   break;
	    case 9:	printf("Enter the value of  K and P \n");
		        scanf("%d %d",&k,&p);
				op_struct=Find_Failures(lptr, k,  p);
			    ptr=op_struct;
			    while(ptr!=NULL)
			    {
			   	    printf("%d \n",ptr->roll_no); 
			   	    ptr=ptr->next;
			    }
			    printf("\n");
			    break;
	    case 10:printf("Enter the no. of nodes in 1st list");
		        scanf("%d",&n1);
				for(i=0;i<n1;i++)
				{
					printf("Enter the data for data for node %d\n",i+1);
					sc=insert(&head1);
					if(sc==SUCCESS)
					 printf("Insertion operation for  %d SUCCESSFUL\n",i+1);
					else
					 printf("Insertion operation for  %d FAILED\n",i+1);
				}				   
                printf("Enter the no. of nodes in 2nd list\n");
                scanf("%d",&n2);
				for(i=0;i<n2;i++)
				{
					printf("Enter the data for data for node %d\n",i+1);
					sc=insert(&head2);
					if(sc==SUCCESS)
					 printf("Insertion operation for  %d SUCCESSFUL\n",i+1);
					else
					 printf("Insertion operation for  %d FAILED\n",i+1);
				}
				head_list_out=list_union(&head1,&head2);	
				printf("The union list is as follows\n");
				print_list(&head_list_out);
				/*sc=delete_list(&head1);
				sc=delete_list(&head2);
				sc=delete_list(&head_list_out);*/
				printf("\n");
				break;
		case 11:printf("Enter the no. of nodes in 1st list\n");
		        scanf("%d",&n1);
				for(i=0;i<n1;i++)
				{
					printf("Enter the data for data for node %d\n",i+1);
					sc=insert(&head1);
					if(sc==SUCCESS)
					 printf("Insertion operation for  %d SUCCESSFUL\n",i+1);
					else
					 printf("Insertion operation for  %d FAILED\n",i+1);
				}				   
                printf("Enter the no. of nodes in 2nd list\n");
                scanf("%d",&n2);
				for(i=0;i<n2;i++)
				{
					printf("Enter the data for data for node %d\n",i+1);
					sc=insert(&head2);
					if(sc==SUCCESS)
					 printf("Insertion operation for  %d SUCCESSFUL\n",i+1);
					else
					 printf("Insertion operation for  %d FAILED\n",i+1);
				}
				head_list_out=list_intersection(&head1,&head2);	
				printf("The intersection list is as follows\n");
				print_list(&head_list_out);
				/*sc=delete_list(&head1);
				sc=delete_list(&head2);
				sc=delete_list(&head_list_out);*/
				printf("\n");
				break;
		case 12:printf("Enter the no. of nodes in 1st list\n");
		        scanf("%d",&n1);
		        head1=NULL;
		        head2=NULL;
				for(i=0;i<n1;i++)
				{
					printf("Enter the data for data for node %d\n",i+1);
					sc=insert(&head1);
					if(sc==SUCCESS)
					 printf("Insertion operation for  %d SUCCESSFUL\n",i+1);
					else
					 printf("Insertion operation for  %d FAILED\n",i+1);
				}				   
                printf("Enter the no. of nodes in 2nd list\n");
                scanf("%d",&n2);
				for(i=0;i<n2;i++)
				{
					printf("Enter the data for data for node %d\n",i+1);
					sc=insert(&head2);
					if(sc==SUCCESS)
					 printf("Insertion operation for  %d SUCCESSFUL\n",i+1);
					else
					 printf("Insertion operation for  %d FAILED\n",i+1);
				}
				print_list(&head1);
				print_list(&head2);
			   	head_list_out=list_difference(&head1,&head2);	
				printf("The difference list is as follows\n");
				print_list(&head_list_out);
			   /*	sc=delete_list(&head1);
				sc=delete_list(&head2);
				sc=delete_list(&head_list_out);*/
				printf("\n");
				break;
		case 13:printf("Enter the no. of nodes in 1st list\n");
		        scanf("%d",&n1);
				for(i=0;i<n1;i++)
				{
					printf("Enter the data for data for node %d\n",i+1);
					sc=insert(&head1);
					if(sc==SUCCESS)
					 printf("Insertion operation for  %d SUCCESSFUL\n",i+1);
					else
					 printf("Insertion operation for  %d FAILED\n",i+1);
				}				   
                printf("Enter the no. of nodes in 2nd list");
                scanf("%d",&n2);
				for(i=0;i<n2;i++)
				{
					printf("Enter the data for data for node %d\n",i+1);
					sc=insert(&head2);
					if(sc==SUCCESS)
					 printf("Insertion operation for  %d SUCCESSFUL\n",i+1);
					else
					 printf("Insertion operation for  %d FAILED\n",i+1);
				}
				head_list_out=list_symmetric_difference(&head1,&head2);	
				printf("The symmetric_difference list is as follows\n");
				print_list(&head_list_out);
				/*sc=delete_list(&head1);
				sc=delete_list(&head2);
				sc=delete_list(&head_list_out);*/
				printf("\n");
				break;
		case 14:print_list(lptr);							
				printf("\n");
				break;	
			   
			   		   
		default:
		        printf("Enter the correct case no.\n");
		        printf("\n");
		        break;
    }
 }
}
status_code insert(Node **lptr)
{
	status_code retval=SUCCESS;
	int roll,marks,flag=1;
	Node *ptr,*prev,*nptr,*temp;
	char name[MAX_NAME],sub[MAX_SUB_CODE];
	temp=(Node*)malloc(sizeof(Node));
	temp->next=*lptr;
	prev=temp;
	ptr=*lptr;
	printf("Enter the name:\n");
	scanf("%s",name);
    printf("Enter the roll no:\n");
	scanf("%d",&roll);
	printf("Enter the subject code:\n");
	scanf("%s",sub);
	printf("Enter the marks :\n");
	scanf("%d",&marks);
	nptr=(Node*)malloc(sizeof(Node));
	if(nptr==NULL)
	{
		retval=FAILURE;
	}
	strcpy(nptr->stu_name,name);
	nptr->roll_no=roll;
	strcpy(nptr->sub_code,sub);
	nptr->marks=marks;
	while(ptr!=NULL && flag==1)
	{
		if(roll > ptr->roll_no)
		{
			prev=ptr;
			ptr=ptr->next;
		}
		else
		{
			if(ptr->roll_no==roll)
			{
				if(strcmp(ptr->sub_code,sub)==0)
				{
					prev->next=nptr;
					nptr->next=ptr->next;
					free(ptr);
					flag=0;
				}
				else
				{
					if(strcmp(ptr->sub_code,sub)>0)
					{
					  prev->next=nptr;
					  nptr->next=ptr;
					  flag=0;	
					}
					else
					{
					  prev=ptr;
			          ptr=ptr->next;
					}
				}
			}
			else
			{
				prev->next=nptr;
				nptr->next=ptr;
				flag=0;	
			}
		}
	}
	if(flag==1)
	{
	    prev->next=nptr;
		nptr->next=NULL;
	}
	*lptr=temp->next;
	free(temp);
	return(retval);
}	
void print_list(Node **lptr)
{
	Node *ptr;
	ptr=*lptr;
	if(ptr==NULL)
	{
		printf("Empty list\n");
	}
	else
	{
		while(ptr!=NULL)
		{
			printf("%s\n",ptr->stu_name);
			printf("%d\n",ptr->roll_no);
			printf("%s\n",ptr->sub_code);
			printf("%d\n",ptr->marks);
            ptr=ptr->next;
		}
	}
}
status_code delete(Node **lptr,int r,char str[])
{
	status_code sc=FAILURE;
	Node *ptr,*prev;
	ptr=*lptr;
	if(ptr==NULL)
	{
		sc=FAILURE;
	}
	else
	{
		if(ptr->roll_no==r&&strcmp(ptr->sub_code,str)==0)
		{
		  sc=SUCCESS;
		  *lptr=ptr->next;
		  free(ptr);	
		}
		else
		{
			prev=ptr;
			ptr=ptr->next;
			while(ptr!=NULL&&sc==FAILURE)
			{
				if(ptr->roll_no==r&&strcmp(ptr->sub_code,str)==0)
				{
					sc=SUCCESS;
					prev->next=ptr->next;
					free(ptr);
				}
				else
				{
					prev=ptr;
			        ptr=ptr->next;    
				}
			}
		}
    }
	return sc;
}
int getNumRecords(Node **lptr)
{
	Node *ptr;
	int count=0;
	ptr=*lptr;
	while(ptr!=NULL)
	{
		count++;
		ptr=ptr->next;
	}
    return(count);	
	
}
Boolean isEmpty(Node **lptr)
{
  Boolean retval=FALSE;
  if(*lptr==NULL)
  {
    retval=TRUE;
  }
  return(retval);
  	
}
Boolean isFull(Node **lptr)
{
  Boolean retval=FALSE;
  Node *nptr;
  nptr=(Node*)malloc(sizeof(Node));
  if(nptr==NULL)
  {
  	retval=TRUE;
  }
  return(retval);
}
Max_Node* getMaxMarks(Node **lptr,char *str)
{
	Node *ptr;
	Max_Node *nptr,*maxptr,*tmp,*maxhead=NULL;
	int max=0;
	ptr=*lptr;
	while(ptr!=NULL)
	{
		    if(strcmp(ptr->sub_code,str)==0)
		    {
		    	if(ptr->marks>=max)
		        {
		            nptr=(Max_Node*)malloc(sizeof(Max_Node));
		            nptr->roll_no=ptr->roll_no;
		            
		            
		            if(ptr->marks==max)
		            {
		            	nptr->next=maxhead;
		            	maxhead=nptr;
					}
					else
					{
						max=ptr->marks;
					    maxptr=maxhead;
						while(maxptr!=NULL)
						{
						    tmp=maxptr;
							maxptr=maxptr->next;
							free(tmp);	
					    }
						maxhead=NULL;
						nptr->next=maxhead;
						maxhead=nptr;	
					}
				}
			}
			ptr=ptr->next;
	}
	printf("Maximum marks are %d\n",max);	
	return(maxhead);
}
/*Max_Node* getMaxMarks(Node **lptr,char *str)	
{
	Node *ptr,;
	Max_Node *nptr,*max_head=NULL;
	int max=0;
	ptr=*lptr;
	if(ptr!=NULL)
	{
	    while(ptr!=NULL)
	    {
		    if(strcmp(ptr->sub_code,str)==0)
		    {
			    if(max<ptr->marks)
			    {
			        max=ptr->marks;	
			    }
		    }
		    ptr=ptr->next;
	    }
	    printf("Max marks in the subject %s is %d ",str,max);
	    ptr=*lptr;
	    while(ptr!=NULL)
	    {
		    if(ptr->marks==max)
		    {
		        nptr=(Max_Node*)malloc(sizeof(Max_Node));
		        nptr->roll_no=ptr->roll_no;
		        nptr->next=max_head;
		        max_head=nptr;
		    }
		   else
		    {
		        ptr=ptr->next;
		    }
        }
    }
    return(max_head);
}*/
Max_Node* Topper(Node **lptr)
{
	Node *ptr;
	int roll,total=0,max_total=0;
	total_Node *total_head=NULL,*nptr,*tptr;
	Max_Node *max_nptr,*max_head=NULL;
	ptr=*lptr;
	roll=ptr->roll_no;
	total=ptr->marks;
	nptr=(total_Node *)malloc(sizeof(total_Node));
	nptr->total=ptr->marks;
	nptr->roll_no=roll;
	nptr->next=total_head;
	total_head=nptr;
	ptr=ptr->next;
	if(max_total<total)
	{
		max_total=total;
	}
	while(ptr!=NULL)
	{
		if(ptr->roll_no==roll)
		{
			total=total+ptr->marks;
			nptr->total=total;
			if(max_total<total)
			{
				max_total=total;
			}
		}
		else
		{
			roll=ptr->roll_no;
			total=ptr->marks;
			nptr=(total_Node *)malloc(sizeof(total_Node));
			nptr->total=total;
			if(max_total<total)
			{
				max_total=total;
			}
			nptr->roll_no=roll;
			nptr->next=total_head;
			total_head=nptr;
		}
		ptr=ptr->next;
	}
	printf("Highest total marks in all the subjects are %d\n",max_total);
	tptr=total_head;
	while(tptr!=NULL)
	{
		if(tptr->total==max_total)
		{
			max_nptr=(Max_Node*)malloc(sizeof(Max_Node));
			max_nptr->roll_no=tptr->roll_no;
			max_nptr->next=max_head;
			max_head=max_nptr;
		}
		tptr=tptr->next;
	}
	return(max_head);
}
Max_Node* Find_Failures(Node **lptr,int K, int P)
{
	Node *ptr;
	Max_Node *max_nptr,*max_head=NULL;
	ptr=*lptr;
	int roll_no=ptr->roll_no,count=0,flag=1;
	while(ptr!=NULL)
	{
		if(ptr->roll_no==roll_no)
		{
		    if(ptr->marks<P)
			{
				count++;
			}
			if(flag==1&&count>=K)
		    {
		    flag=0;
		    max_nptr=(Max_Node*)malloc(sizeof(Max_Node));
		    max_nptr->roll_no=ptr->roll_no;
			max_nptr->next=max_head;
			max_head=max_nptr;	
			}
	    }
		else
		{
			count=0;
			flag=1;
			roll_no=ptr->roll_no;
			if(ptr->marks<P)
			{
				count++;
			}
			if(flag==1&&count>=K)
		    {
		        flag=0;
		        max_nptr=(Max_Node*)malloc(sizeof(Max_Node));
		        max_nptr->roll_no=ptr->roll_no;
			    max_nptr->next=max_head;
			    max_head=max_nptr;
		    }
		}
		ptr=ptr->next;
	}
	return(max_head);	
}
void list_unique(Node **lptr)
{   Node *sptr;
    sptr=insert_duplicate(lptr);
	int roll;
	char sub[MAX_SUB_CODE];
	Node *ptr,*prev,*dptr;
	ptr=*lptr;
	roll=ptr->roll_no;
	strcpy(sub,ptr->sub_code);
	ptr=ptr->next;
	prev=ptr;
	while(ptr!=NULL)
	{
	    if(ptr->roll_no==roll&&strcmp(ptr->sub_code,sub)==0)
		{
			dptr=ptr;
			prev->next=ptr->next;
			ptr=ptr->next;
			free(dptr);
		}
		prev=ptr;
		ptr=ptr->next;
    }
}
Node* list_union(Node **lptr1,Node **lptr2)
{
  Node *ptr1,*ptr2,*r;
  Node **lptr3;
  ptr1=*lptr1;
  ptr2=*lptr2;
  if(ptr1==NULL)
  {
  	*lptr3=ptr2;
  }
  else
  {
  	if(lptr2==NULL)
  	{
  	    *lptr3=ptr1;
  	}
  	else
  	{
  	    if(ptr1->roll_no<ptr2->roll_no)
  	    {
  	    	*lptr3=ptr1;
  	    	ptr1=ptr1->next;
  	    	
		}
		else
		{
			*lptr3=ptr2;
			ptr2=ptr2->next;
		}
		r=*lptr3;
		while((ptr1!=NULL)&&(ptr2!=NULL))
		{
			if(ptr1->roll_no < ptr2->roll_no)
			{
				r->next=ptr1;
				r=r->next;
				ptr1=ptr1->next;
			}
			else
			{
				if(ptr1->roll_no == ptr2->roll_no)
				{
					if(strcmp(ptr1->sub_code , ptr2->sub_code)<0)
					{
					    r->next=ptr1;
				        r=r->next;
				        ptr1=ptr1->next;       	
					}
					else
					{
					    if(strcmp(ptr1->sub_code , ptr2->sub_code)==0)
					    {
							ptr1=ptr1->next;
						}
						r->next=ptr2;
						r=r->next;
						ptr2=ptr2->next;
					}
				}
				else
				{
				    r->next=ptr2;
				    r=r->next;
				    ptr2=ptr2->next;  	
				}
			}
		}
		if(ptr1!=NULL)
		{
			r->next=ptr1;
		}
		else
		{
		    r->next=ptr2;	
		}
    }
}
    return(*lptr3);
}
/*Node* list_intersection(Node **lptr1,Node **lptr2)
{
  Node *ptr1,*ptr2,*r,*nptr;
  Node **lptr3;
  *lptr3 = NULL;
  ptr1=*lptr1;
  ptr2=*lptr2;
  if(ptr1==NULL)
  {
  	*lptr3=NULL;
  }
  else
  {
  	if(lptr2==NULL)
  	{
  	    *lptr3=NULL;
  	}
  	else
  	{
  	    while((ptr1!=NULL)&&(ptr2!=NULL))
		{
			if(ptr1->roll_no < ptr2->roll_no)
  	        {
  	    	    ptr1=ptr1->next;
					
	        }
	        else
		    {
		    	if(ptr1->roll_no == ptr2->roll_no)
		    	{
		    		if(strcmp(ptr1->sub_code , ptr2->sub_code)<0)
					{
				        ptr1=ptr1->next;       	
					}
					else
					{
					    if(strcmp(ptr1->sub_code , ptr2->sub_code)==0)
					    {
							nptr=(Node*)malloc(sizeof(Node));
							nptr->roll_no = ptr1->roll_no;
							strcpy(nptr->stu_name,ptr1->stu_name);
							strcpy(nptr->sub_code,ptr1->sub_code);
							nptr->marks=ptr1->marks;
							nptr->next=*lptr3;
							*lptr3=nptr;
							ptr1=ptr1->next;
						}
						ptr2=ptr2->next;
					}
				}
				else
				{
				    ptr2=ptr2->next;
		    	}
		    }
	    }
	}
 }
 return(*lptr3);
}*/
/*Node* list_difference(Node **lptr1,Node **lptr2)
{
  Node *ptr1,*ptr2,*nptr;
  Node **lptr3;
  int flag=0;
  *lptr3=NULL;
  ptr1=*lptr1;
  ptr2=*lptr2;
  if(ptr1==NULL)
  {
  	*lptr3=NULL;
  }
  else
  {
  	if(ptr2==NULL)
  	{
  	    *lptr3=ptr1;
  	}
  	else
  	{
  	    while((ptr1!=NULL)&&(ptr2!=NULL))
		{
			if(ptr1->roll_no < ptr2->roll_no)
  	        {
  	    	    
  	    	    flag=1;
  	    	    nptr=(Node*)malloc(sizeof(Node));
			    nptr->roll_no = ptr1->roll_no;
				strcpy(nptr->stu_name,ptr1->stu_name);
				strcpy(nptr->sub_code,ptr1->sub_code);
				nptr->marks=ptr1->marks;
				nptr->next=*lptr3;
				*lptr3=nptr;
				ptr1=ptr1->next;
		    }
	        else
		    {
		    	if(ptr1->roll_no == ptr2->roll_no)
		    	{
		    		if(strcmp(ptr1->sub_code , ptr2->sub_code)<0)
					{
				        
						flag=1;
						nptr=(Node*)malloc(sizeof(Node));
			            nptr->roll_no = ptr1->roll_no;
				        strcpy(nptr->stu_name,ptr1->stu_name);
				        strcpy(nptr->sub_code,ptr1->sub_code);
				        nptr->marks=ptr1->marks;
				        nptr->next=*lptr3;
			            *lptr3=nptr;
			            ptr1=ptr1->next;
				    }
					else
					{
					    if(strcmp(ptr1->sub_code , ptr2->sub_code)==0)
					    {
						    ptr1=ptr1->next;	
				            ptr2=ptr2->next;
				            flag=0;
		                }
		                else
		                {
		                    ptr2=ptr2->next;
							flag=0;	
						}
				    }
		        }
		        else
		        {
		            ptr2=ptr2->next;
					flag=0;	
				}
			}
			if(flag==1)
			{
				nptr=(Node*)malloc(sizeof(Node));
			    nptr->roll_no = ptr1->roll_no;
				strcpy(nptr->stu_name,ptr1->stu_name);
				strcpy(nptr->sub_code,ptr1->sub_code);
				nptr->marks=ptr1->marks;
				nptr->next=*lptr3;
				*lptr3=nptr;
				flag=0;
            }
        }
        
    }
}
    return(*lptr3);
}*/

Node* list_symmetric_difference(Node **lptr1,Node **lptr2)
{
  Node *ptr1,*ptr2,*r;
  Node **lptr3;
  ptr1=*lptr1;
  ptr2=*lptr2;
  if(ptr1==NULL)
  {
  	*lptr3=ptr2;
  }
  else
  {
  	if(lptr2==NULL)
  	{
  	    *lptr3=ptr1;
  	}
  	else
  	{
  	    if(ptr1->roll_no<ptr2->roll_no)
  	    {
  	    	*lptr3=ptr1;
  	    	ptr1=ptr1->next;
  	    	
		}
		else
		{
			*lptr3=ptr2;
			ptr2=ptr2->next;
		}
		r=*lptr3;
		while((ptr1!=NULL)&&(ptr2!=NULL))
		{
			if(ptr1->roll_no < ptr2->roll_no)
			{
				r->next=ptr1;
				r=r->next;
				ptr1=ptr1->next;
			}
			else
			{
				if(ptr1->roll_no == ptr2->roll_no)
				{
					if(strcmp(ptr1->sub_code , ptr2->sub_code)<0)
					{
					    r->next=ptr1;
				        r=r->next;
				        ptr1=ptr1->next;       	
					}
					else
					{
					    if(strcmp(ptr1->sub_code , ptr2->sub_code)==0)
					    {
							ptr1=ptr1->next;
							ptr2=ptr2->next;
						}
						else
						{
						    r->next=ptr2;
						    r=r->next;
						    ptr2=ptr2->next;
					    }
					}
				}
				else
				{
				    r->next=ptr2;
				    r=r->next;
				    ptr2=ptr2->next;  	
				}
			}
		}
		if(ptr1!=NULL)
		{
			r->next=ptr1;
		}
		else
		{
		    r->next=ptr2;	
		}
    }
	}
    return(*lptr3);
}
Popular_Node* Kth_popular_subject(Node **lptr,int K)
{
	Node *ptr=*lptr;
	char sub[MAX_SUB_CODE];
	Popular_Node *nptr,*head=NULL,*ptr1,*sptr;
	int count=0,total=0,found=0;
	float avg=0;
	strcpy(sub,ptr->sub_code);
	nptr=(Popular_Node*)malloc(sizeof(Popular_Node));
	count++;
	strcpy(nptr->sub_code,sub);
	nptr->avg=ptr->marks;
	nptr->count=1;
	nptr->total=ptr->marks;
	nptr->next=head;
	head=nptr;
	ptr=ptr->next;
	while(ptr!=NULL)
	{
		if(strcmp(ptr->sub_code,sub)==0)
		{
		    count++;
		    total=total+ptr->marks;
		    avg=(total/count);
		    nptr->avg=avg;
		}
		else
		{
			strcpy(sub,ptr->sub_code);
			count=1;
			total=ptr->marks;
			ptr1=head;
			while(ptr1!=NULL || found==0)
			{
				if(strcmp(ptr1->sub_code,nptr->sub_code)==0)
				{
				    total=ptr1->total+ptr->marks;
				    count=count+ptr1->count;
				    avg=total/count;
				    ptr1->avg=avg;
				    ptr1->count=count;
				    ptr1->total=total;
				    found=1;
				}
				ptr1=ptr1->next;
			}
			if(found==0)
			{
				count=1;
			    nptr=(Popular_Node*)malloc(sizeof(Popular_Node));
				nptr->avg=ptr->marks;
				nptr->total=ptr->marks;
				nptr->count=1;
				nptr->next=head;
				head=nptr;	
			}
		}
		ptr=ptr->next;
	}
	sptr=Merge_Sort(head);
    return(sptr);	
}
Node* insert_duplicate(Node **lptr)
{
    status_code retval=SUCCESS;
	int roll,marks,flag=1;
	Node *ptr,*prev,*nptr,*temp;
	char name[MAX_NAME],sub[MAX_SUB_CODE];
	temp=(Node*)malloc(sizeof(Node));
	temp->next=*lptr;
	prev=temp;
	ptr=temp->next;
	printf("Enter the name:\n");
	scanf("%s",name);
    printf("Enter the roll no:\n");
	scanf("%d",&roll);
	printf("Enter the subject code:");
	scanf("%s",sub);
	printf("Enter the marks :\n");
	scanf("%d",&marks);
	nptr=(Node*)malloc(sizeof(Node));
	if(nptr==NULL)
	{
		retval=FAILURE;
	}
	strcpy(nptr->stu_name,name);
	nptr->roll_no=roll;
	strcpy(nptr->sub_code,sub);
	nptr->marks=marks;
	while(ptr!=NULL &&flag==1)
	{
		if(roll>ptr->roll_no)
		{
			prev=ptr;
			ptr=ptr->next;
		}
		else
		{
			if(ptr->roll_no==roll)
			{
				if(strcmp(ptr->sub_code,sub)==0)
				{
					nptr->next=ptr->next;
					ptr->next=nptr;
					flag=0;
				}
				else
				{
					if(strcmp(ptr->sub_code,sub)>0)
					{
					  prev->next=nptr;
					  nptr->next=ptr;
					  flag=0;	
					}
					else
					{
					  prev=ptr;
			          ptr=ptr->next;
					}
				}
			}
			else
			{
				prev->next=nptr;
				nptr->next=ptr;
				flag=0;	
			}
		}
	}
	if(flag==1)
	{
	    prev->next=nptr;
		ptr->next=ptr;	
	}
	*lptr=temp->next;
	free(temp);
	return(*lptr);
}

/*void print_list(Node **lptr)
{
	Node *ptr;
	ptr=*lptr;
	if(ptr==NULL)
	{
		printf("Empty list");
	}
	else
	{
		while(ptr!=NULL)
		{
			printf("%s",ptr->stu_name);
			printf("%d",ptr->roll_no);
			printf("%s",ptr->sub_code);
			printf("%d",ptr->marks);
            ptr=ptr->next;
		}
	}
}
*/
Popular_Node*  Merge_Sort(Popular_Node *head)
{
	Popular_Node *lptr,*ptr;
	lptr=head;
	
	if((head!=NULL)&&(head->next!=NULL))
	{
		ptr=Divide(head);
		head=Merge_Sort(head);
		ptr=Merge_Sort(ptr);
		lptr=Merge(head,ptr);
	}
	return lptr;
}
Popular_Node* Divide(Popular_Node *head)
{
	Popular_Node *fast,*slow,*ret_val;
	slow=head;
	fast=head->next->next;
	while(fast!=NULL)
	{
		slow=slow->next;
		fast=fast->next;
		if(fast!=NULL)
		{
			fast=fast->next;
		}
	}
	ret_val=slow->next;
	slow->next=NULL;
	return ret_val;
}
Popular_Node* Merge(Popular_Node*head,Popular_Node*ptr)
{
  Popular_Node *ptr1,*ptr2,*r;
  Popular_Node *lptr3;
  ptr1=head;
  ptr2=ptr;
  if(ptr1==NULL)
  {
  	lptr3=ptr2;
  }
  else
  {
  	if(ptr2==NULL)
  	{
  	    lptr3=ptr;
  	}
  	else
  	{
  	    if(ptr1->avg<ptr2->avg)
  	    {
  	    	lptr3=ptr1;
  	    	ptr1=ptr1->next;
  	    	
		}
		else
       	{
		    lptr3=ptr2;
			ptr2=ptr2->next;
		}
		r=lptr3;
		while((ptr1!=NULL)&&(ptr2!=NULL))
		{
			if(ptr1->avg < ptr2->avg)
			{
				r->next=ptr1;
				r=r->next;
				ptr1=ptr1->next;
			}
			else
			{
				
			    r->next=ptr2;
				r=r->next;
				ptr2=ptr2->next;
			}
				
		}
		if(ptr1!=NULL)
		{
			r->next=ptr1;
		}
		else
		{
		    r->next=ptr2;	
		}
    }
}
    return lptr3;
}	
status_code delete_list(Node **lptr)
{
	status_code sc=FAILURE;
	Node *ptr=*lptr,*tmp;
	while(ptr!=NULL)
	{
	  tmp=ptr;
	  ptr=ptr->next;
	  free(tmp);
	  sc=SUCCESS;	
	}
    return(sc);	
}
Node* list_difference(Node** lptr1,Node** lptr2)
{
	
		Node *ptr1,*ptr2,*tmp,*prev,*nptr;
		tmp=(Node*)malloc(sizeof(Node));
	
  ptr1=*lptr1;
  ptr2=*lptr2;
  prev=tmp;
  prev->next=NULL;
  if(ptr1==NULL)
  {
  	nptr=ptr1;
  }
  else 
  {
  	if(ptr2==NULL)
  	{
  	    nptr=ptr1;
  	}
  	else
  	{
  	    while((ptr1!=NULL)&&(ptr2!=NULL))
		{
			if(ptr1->roll_no < ptr2->roll_no)
  	        {
  	    	    nptr=(Node*)malloc(sizeof(Node));
			    nptr->roll_no = ptr1->roll_no;
				strcpy(nptr->stu_name,ptr1->stu_name);
				strcpy(nptr->sub_code,ptr1->sub_code);
				nptr->marks=ptr1->marks;
				nptr->next=NULL;
				
				ptr1=ptr1->next;
				prev->next=nptr;
				prev=nptr;
		    }
	        else
		    {
		    	if(ptr1->roll_no == ptr2->roll_no)
		    	{
		    		if(strcmp(ptr1->sub_code , ptr2->sub_code)<0)
					{
						nptr=(Node*)malloc(sizeof(Node));
			            nptr->roll_no = ptr1->roll_no;
				        strcpy(nptr->stu_name,ptr1->stu_name);
				        strcpy(nptr->sub_code,ptr1->sub_code);
				        nptr->marks=ptr1->marks;
				        prev->next=nptr;
			            prev=nptr;
			            ptr1=ptr1->next;
			            nptr->next=NULL;
				    }
					else
					{
					    if(strcmp(ptr1->sub_code , ptr2->sub_code)==0)
					    {
						    ptr1=ptr1->next;	
				            ptr2=ptr2->next;
				            
		                }
		                else
		                {
		                    ptr2=ptr2->next;
						
						}
				    }
		        }
		        else
		        {
		            ptr2=ptr2->next;
					
				}
			}
	    }     
			if(ptr2==NULL)
			{
				while(ptr1!=NULL)
				{
				        nptr=(Node*)malloc(sizeof(Node));
			            nptr->roll_no = ptr1->roll_no;
				        strcpy(nptr->stu_name,ptr1->stu_name);
				        strcpy(nptr->sub_code,ptr1->sub_code);
				        nptr->marks=ptr1->marks;
				        prev->next=nptr;
				        nptr->next=NULL;
			            prev=nptr;
			            ptr1=ptr1->next;	
				}
			}
    }
        
        
}
        nptr=tmp->next;
        free(tmp);
        return(nptr);
}
    
 Node* list_intersection(Node **lptr1,Node **lptr2)
{
  Node *ptr1,*ptr2,*head,*tmp,*prev,*nptr;
  
  ptr1=*lptr1;
  ptr2=*lptr2;
  tmp=(Node*)malloc(sizeof(Node));
  prev=tmp;
  
  if(ptr1==NULL||ptr2==NULL)
  {
    head=NULL;
  }
  else
  {
        while((ptr1!=NULL)&&(ptr2!=NULL))
		{
			if(ptr1->roll_no < ptr2->roll_no)
  	        {
  	    	    ptr1=ptr1->next;
					
	        }
	        else
		    {
		    	if(ptr1->roll_no == ptr2->roll_no)
		    	{
		    		if(strcmp(ptr1->sub_code , ptr2->sub_code)<0)
					{
				        ptr1=ptr1->next;       	
					}
					else
					{
					    if(strcmp(ptr1->sub_code , ptr2->sub_code)==0)
					    {
							nptr=(Node*)malloc(sizeof(Node));
							nptr->roll_no = ptr1->roll_no;
							strcpy(nptr->stu_name,ptr1->stu_name);
							strcpy(nptr->sub_code,ptr1->sub_code);
							nptr->marks=ptr1->marks;
							prev->next=nptr;
							nptr->next=NULL;
							prev=nptr;
							
							ptr1=ptr1->next;
							ptr2=ptr2->next;
							
						}
						else
						{
						
						ptr2=ptr2->next;
					    }
					}
				}
				else
				{
					ptr2=ptr2->next;
					
				}
					
			}
		}
	}
					
					head=tmp->next;
					free(tmp);
					return(head);
				}
					
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	

		
					  															   		   								 			 	   	   
	 

