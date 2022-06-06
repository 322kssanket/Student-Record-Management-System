// AVL Tree implementation in C program 

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_SUB 10
#define MAX_DEPT 20
#define MAX_NAME 20

 
// An AVL tree node
struct Node
{
    struct Node *left;
    struct Node *right;
    int height;
    int roll_no;
	char stu_name[MAX_NAME];
	char dept[MAX_DEPT];
	int sem_no; 
	int marks;
	char sub_code[MAX_SUB]; 
	int total;
	struct Node *next;  
};
 
// A utility function to get maximum of two integers
int max(int a, int b);
 
// A utility function to get height of the tree
int height(struct Node *N)
{
    if (N == NULL)
        return 0;
    return N->height;
}
 
// A utility function to get maximum of two integers
int max(int a, int b)
{
    return (a > b)? a : b;
}
 
/* Helper function that allocates a new node with the given key and
    NULL left and right pointers. */
struct Node* newNode(int r,int m,int s,char *dept,char *name,char *sub)
{
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->roll_no = r;
    strcpy(node->stu_name,name);
    node->marks=m;
    node->sem_no=s;
    strcpy(node->dept,dept);
    strcpy(node->sub_code,sub);
    node->left    = NULL;
    node->right   = NULL;
    node->height  = 1;  // new node is initially added at leaf
    return(node);
}
 
// A utility function to right rotate subtree rooted with y
struct Node *rightRotate(struct Node *y)
{
    struct Node *x = y->left;
    struct Node *T2 = x->right;
 
    // Perform rotation
    x->right = y;
    y->left = T2;
 
    // Update heights
    y->height = max(height(y->left), height(y->right))+1;
    x->height = max(height(x->left), height(x->right))+1;
 
    // Return new root
    return x;
}
 
// A utility function to left rotate subtree rooted with x
struct Node *leftRotate(struct Node *x)
{
    struct Node *y = x->right;
    struct Node *T2 = y->left;
 
    // Perform rotation
    y->left = x;
    x->right = T2;
 
    //  Update heights
    x->height = max(height(x->left), height(x->right))+1;
    y->height = max(height(y->left), height(y->right))+1;
 
    // Return new root
    return y;
}
 
// Get Balance factor of node N
int getBalance(struct Node *N)
{
    if (N == NULL)
        return 0;
    return height(N->left) - height(N->right);
}
 
// Recursive function to insert key in subtree rooted
// with node and returns new root of subtree.
struct Node* insert(struct Node* node, int r,int m,int s,char *dept,char *name,char *sub)
{
    /* 1.  Perform the normal BST insertion */
    if (node == NULL)
    {
    	printf("Record is successfully inserted");
	    return(newNode( r, m, s,dept,name,sub));
    }
    if (r < node->roll_no)
    {	
        node->left  = insert(node->left,r,m,s,dept,name,sub );
    }
    else 
	{
		if (r > node->roll_no)
		{		
            node->right = insert(node->right,  r, m, s,dept,name,sub);
        }
        else 
		{		
		    if(strcmp(node->sub_code,sub)<0)
		    {			
                node->right  = insert(node->right, r,m,s,dept,name,sub );
		 	} 
			else
			{
			    if(strcmp(node->sub_code,sub)>0)
				{
				    node->left = insert(node->left,  r, m, s,dept,name,sub);
                } 
				else
				{
				   printf( "Same records are not allowed");
				   return node;
			    }
	        }
    	}
    }
    
      
    /* 2. Update height of this ancestor node */
    node->height = 1 + max(height(node->left),
                           height(node->right));
 
    /* 3. Get the balance factor of this ancestor
          node to check whether this node became
          unbalanced */
    int balance = getBalance(node);
 
    // If this node becomes unbalanced, then
    // there are 4 cases
 
    // Left Left Case
    if (balance > 1 && (r < node->left->roll_no||strcmp(sub,node->left->sub_code)<0))
        return rightRotate(node);
 
    // Right Right Case
    if (balance < -1 && (r > node->right->roll_no||strcmp(sub,node->right->sub_code)>0))
        return leftRotate(node);
 
    // Left Right Case
    if (balance > 1 && (r > node->left->roll_no||strcmp(sub,node->left->sub_code)>0))
    {
        node->left =  leftRotate(node->left);
        return rightRotate(node);
    }
 
    // Right Left Case
    if (balance < -1 && (r < node->right->roll_no||strcmp(node->right->sub_code,sub)<0))
    {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }
    printf("Record is successfully inserted");
    /* return the (unchanged) node pointer */
    return node;
}
//  delete a node from AVL Tree

/* Given a non-empty binary search tree, return the
   node with minimum key value found in that tree.
   Note that the entire tree does not need to be
   searched. */
struct Node * minValueNode(struct Node* node)
{
    struct Node* current = node;
 
    /* loop down to find the leftmost leaf */
    while (current->left != NULL)
        current = current->left;
 
    return current;
}
 
// Recursive function to delete a node with given key
// from subtree with given root. It returns root of
// the modified subtree.
struct Node* deleteNode(struct Node* node, int r,char *sub)
{
    // STEP 1: PERFORM STANDARD BST DELETE
 
    if (node == NULL)
        return node;
 
    // If the key to be deleted is smaller than the
    // root's key, then it lies in left subtree
    if (r < node->roll_no)
    {
        node->left = deleteNode(node->left,r ,sub);
    }
 
    // If the key to be deleted is greater than the
    // root's key, then it lies in right subtree
    else 
	{	
	    if( r > node->roll_no )
	    {
	        node->right = deleteNode(node->right, r ,sub);
	    }
        else
        {
        	if(strcmp(node->sub_code,sub)>0)
			{
			    node->left = deleteNode(node->left,r ,sub);	
	    	}
	    	else
	    	{
	    	    if (strcmp(node->sub_code,sub)<0)
		        {
		        	node->right = deleteNode(node->right, r ,sub);
	            } 
		        // if key is same as root's key, then This is
                // the node to be deleted
                else
                {
                    // node with only one child or no child
                    if( (node->left == NULL) || (node->right == NULL) )
                    {
                        struct Node *temp = node->left ? node->left :node->right;
 
                        // No child case
                        if (temp == NULL)
                        {
                            temp = node;
                            node = NULL;
                        }
                        else // One child case
                            *node = *temp; // Copy the contents of the non-empty child
                        free(temp);
                    }
        
                    else
                    {
                        // node with two children: Get the inorder
                        // successor (smallest in the right subtree)
                        struct Node* temp = minValueNode(node->right);
 
                        // Copy the inorder successor's data to this node
                        node->roll_no = temp->roll_no;
                        strcpy(temp->sub_code,sub);
                        node->height=temp->height;
                        strcpy(temp->dept,node->dept);
                        node->left=temp->left;
                        node->right=temp->right;
                        node->sem_no=temp->sem_no;
                        strcpy(node->stu_name,temp->stu_name);
 
                        // Delete the inorder successor
                        node->right = deleteNode(node->right, temp->roll_no ,temp->sub_code);
                    }
                }
            }
        }
    }
 
    // If the tree had only one node then return
    if (node == NULL)
      return node;
 
    // STEP 2: UPDATE HEIGHT OF THE CURRENT NODE
    node->height = 1 + max(height(node->left),
                           height(node->right));
 
    // STEP 3: GET THE BALANCE FACTOR OF THIS NODE (to
    // check whether this node became unbalanced)
    int balance = getBalance(node);
 
    // If this node becomes unbalanced, then there are 4 cases
 
    // Left Left Case
    if (balance > 1 && getBalance(node->left) >= 0)
        return rightRotate(node);
 
    // Left Right Case
    if (balance > 1 && getBalance(node->left) < 0)
    {
        node->left =  leftRotate(node->left);
        return rightRotate(node);
    }
 
    // Right Right Case
    if (balance < -1 && getBalance(node->right) <= 0)
        return leftRotate(node);
 
    // Right Left Case
    if (balance < -1 && getBalance(node->right) > 0)
    {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }
 
    return node;
}


//function to search a given key 
struct Node* search(struct Node* root, int r,char *sub)
{
    // Base Cases: root is null or key is present at root
    if (root == NULL )
    {
    	printf("Search is unsuccessful");
	}
    
    
    if (r < root->roll_no)
    {
        root->left = search(root->left,r ,sub);
    }
    // Key is smaller than root's key
    else 
	{	
	    if( r > root->roll_no )
	    {
	        root->right = search(root->right, r ,sub);
	    }
        else
        {
        	if(strcmp(sub,root->sub_code)<0)
			{
			    root->left = search(root->left,r ,sub);	
	    	}
	    	else
	    	{
	    	    if (strcmp(sub,root->sub_code)>0)
		        {
		        	root->right = search(root->right, r ,sub);
	            } 
		        // if key is same as root's key, then This is the node to be searched
                else
                {
                	return(root);
                }
            }
        }
    }
}
// A utility function to print preorder traversal
// of the tree.
// The function also prints height of every node
/*void preOrder(struct Node *root)
{
    if(root != NULL)
    {
        printf("%d ", root->key);
        preOrder(root->left);
        preOrder(root->right);
    }*/
void print(struct Node *root)
{
	if(root!=NULL)
	{
		
		
		printf("%d \n %s \n  %s  \n %d \n %s \n %d \n",root->roll_no,root->stu_name,root->sub_code,root->marks,root->dept,root->sem_no);
		print(root->left);
		print(root->right);
	}
}
 
/* Drier program to test above function*
int main()
{
  struct Node *root = NULL;
 
  /* Constructing tree given in the above figure *
  root = insert(root, 10);
  root = insert(root, 20);
  root = insert(root, 30);
  root = insert(root, 40);
  root = insert(root, 50);
  root = insert(root, 25);
 
  /The constructed AVL Tree would be
            30
           /  \
         20   40
        /  \     \
       10  25    50
  
 
  printf("Preorder traversal of the constructed AVL"
         " tree is \n");
  preOrder(root);
 
  return 0;
}*/

//function to calculate height of the tree
int height1(struct Node *root)
{
	int ret_val,right_height,left_height;
	if(root==NULL)
	{
		
	}
	else
	{
		if((root->left==NULL)&&(root->right==NULL))
		{
			ret_val=0;
		}
		else
		{
			left_height=height(root->left);
			right_height=height(root->right);
			if(left_height>right_height)
			{
				ret_val=1+left_height;
			}
			else
			{
			    ret_val=1+left_height;	
			}
		}
	      
	}
	return ret_val;	
}

//function to get the number of records 

int  getNum_Records(struct Node *root)
{
	int ret_val;
	
	if(root==NULL)
	{
		ret_val=0;
	}
	else
	{
		ret_val=1+getNum_Records(root->left)+getNum_Records(root->right);
	} 
	
}

 
/* The functions prints all the keys which in the given range [k1..k2].
    The function assumes than k1 < k2 */
void Range_Search(struct Node *root, int r1, int r2)
{
     
   if ( NULL == root )
      return;
 
    /*Since the desired o/p is sorted, recurse for left subtree first
      If root->data is greater than k1, then only we can get o/p keys
      in left subtree */
   if ( r1 < root->roll_no )
     Range_Search(root->left, r1, r2);
 
   /* if root's data lies in range, then prints root's data*/ 
   if ( r1 <= root->roll_no && r2 >= root->roll_no )
     printf("%d %s %s %d %s %d ",root->roll_no,root->stu_name,root->sub_code,root->marks,root->dept,root->sem_no);
		
 
  /* If root->data is smaller than k2, then only we can get o/p keys*/
      
   if ( r2 > root->roll_no )
     Range_Search(root->right, r1, r2);
}

struct Node*  insert_into_kthmax( struct Node* node, int r,int m,int s,char *dept,char *name,char *sub)
{
    
    if (node == NULL)
    {
    	//printf("Record is successfully inserted");
	    return(newNode( r, m, s,dept,name,sub));
    }
    if (m < node->marks)
    {	
        node->left  = insert_into_kthmax(node->left, r, m, s, dept, name, sub );
    }
    else 
	{
		if (m > node->marks)
		{		
            node->right = insert_into_kthmax(node->right,  r, m, s, dept,name,sub);
        }
        else 
		{		
	        node->right = insert_into_kthmax(node->right, r, m, s,dept,name,sub);
        } 
	}

    
    
      
     
    node->height = 1 + max(height(node->left),height(node->right));
 
    
    int balance = getBalance(node);
 
    // If this node becomes unbalanced, then
    // there are 4 cases
 
    // Left Left Case
    if (balance > 1 && (m < node->marks))
        return rightRotate(node);
 
    // Right Right Case
    if (balance < -1 && (m > node->marks||(m==node->marks)))
        return leftRotate(node);
 
    // Left Right Case
    if (balance > 1 && (m > node->marks||m==node->marks))
    {
        node->left =  leftRotate(node->left);
        return rightRotate(node);
    }
 
    // Right Left Case
    if (balance < -1 && (m < node->marks))
    {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }
    /*printf("Record is successfully inserted");*/
     
    return node;
}


void Kthmax_build(struct Node *root,char *sub,struct Node **kroot)							
{
	
	if(root==NULL)
	{
		return;
	}
	if(root!=NULL)
	{
		Kthmax_build(root->left,sub,kroot);
		if(strcmp(sub,root->sub_code)==0)
		{
		   *kroot=insert_into_kthmax( *kroot, root->roll_no,root->marks ,root->sem_no ,root->dept,root->stu_name ,root->sub_code );
			
		}
		Kthmax_build(root->right,sub,kroot);
    }
    return;
}



int getKthmaxlist(struct Node *root,int k,int count)
{
	if(root==NULL||count>k)
	{
		return;
	}
		getKthmaxlist(root->right, k,count);
		
		if(root->right==NULL)
		{
			count++;
	    }
		if(root->right!=NULL)
		{
			if(root->right->marks > root->marks)
			{
				count++;
			}
		}
		if(count==k)
		{
				 printf("%d %s %s %d %s %d ",root->roll_no,root->stu_name,root->sub_code,root->marks,root->dept,root->sem_no);
		
		}
    
	    getKthmaxlist(root->left, k,count);
	
	return;
}


//function for finding  list of students failing in the particular sub.

void GetListofFailures(struct Node *root,char *sub,int m)
{
	struct Node *lptr=NULL,*head=NULL;

	if(root==NULL)
	{
		return;
	}
	GetListofFailures(root->left,sub, m);
	if(strcmp(root->sub_code,sub)==0&&root->marks<m)
	{
		/*lptr=insertintolink(head,root->roll_no,root->stu_name,root->sub_code,root->marks,root->dept,root->sem_no);*/
		printf("%d %s %s %d %s %d ",root->roll_no,root->stu_name,root->sub_code,root->marks,root->dept,root->sem_no);
	}
	GetListofFailures(root->right,sub, m);
	return ;
	
}
/*insertintolink(struct Node* root,int r,int m,int s,char *dept,char *name,char *sub)
{
	struct Node* nptr;
	nptr=(struct Node* )malloc(sizeof(struct Node));
	nptr->roll_no = r;
    strcpy(nptr->sub_code,sub);
    strcpy(nptr->dept,dept);
    nptr->sem_no=s;
    strcpy(nptr->stu_name,name);
	nptr->next=root;
	root=nptr;
	return root;
}*/
/*struct Node*  Topper(struct Node *root)							
{
	int roll,total=0,flag=0;
	struct Node *left,*total;
	if(root==NULL)
	{
		return;
	}
	if(root!=NULL)
	{
		left=Topper(root->left);
		total=root->marks;
		
		if(left!=NULL)
		{
			if(root->roll_no==left->roll_no)
			{
		        total=left->total+root->marks;
		        total_node->total=total;
		    }
		    else
		    {
		    	insertintototal( left->totalnode, root->roll_no,root->marks ,root->sem_no ,root->dept,root->stu_name ,root->sub_code,root->total );
		    }	
		}
				
		
		if(flag==0)
		{
		    total_node=makenode( root, root->roll_no,root->marks ,root->sem_no ,root->dept,root->stu_name ,root->sub_code,root->total );
		    flag=1;
	    }
		right=Topper(root->right);
		if(right!=NULL)
		{
			if(root->roll_no==right->roll_no)
			{
		        total=right->total+total;
				insertintototal( root, root->roll_no,root->marks ,root->sem_no ,root->dept,root->stu_name ,root->sub_code,root->total );
		    }
			else
		    {
		    	insertintototal( left->totalnode, root->roll_no,root->marks ,root->sem_no ,root->dept,root->stu_name ,root->sub_code,root->total );
		    }	
		}
    }
    return root;
}


struct Node* insertintotopper(struct Node* node, int r,int m,int s,char *dept,char *name,char *sub,int total)
{
     
    if (node == NULL)
    {
    	printf("Record is successfully inserted");
	    return(newNode( r, m, s,dept,name,sub,total));
    }
    if (total < node->total)
    {	
        node->left  = insert(node->left,node->roll_no ,node->marks ,node->sem_no ,node->dept,node->stu_name,node->sub_code,node->total );
    }
    else 
	{
		if (total > node->total)
		{		
            node->right = insert(node->right, node->roll_no ,node->marks ,node->sem_no ,node->dept,node->stu_name,node->sub_code,node->total);
        }
        else 
		{		
	        node->right = insert(node->right, int r,int m,int s,char *dept,char *name,char *sub);
        } 
	}
	node->height = 1 + max(height(node->left),height(node->right));
 
    
    int balance = getBalance(node);
 
    // If this node becomes unbalanced, then
    // there are 4 cases
 
    // Left Left Case
    if (balance > 1 && (r < node->roll_no||strcmp(node->sub_code,sub)<0))
        return rightRotate(node);
 
    // Right Right Case
    if (balance < -1 && (r > node->roll_no||strcmp(node->sub_code,sub)>0))
        return leftRotate(node);
 
    // Left Right Case
    if (balance > 1 && (r > node->roll_no||strcmp(node->sub_code,sub)>0))
    {
        node->left =  leftRotate(node->left);
        return rightRotate(node);
    }
 
    // Right Left Case
    if (balance < -1 && (r < node->roll_no||strcmp(node->sub_code,sub)<0))
    {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }
    printf("Record is successfully inserted");
    /* return the (unchanged) node pointer 
    return node;
}

 
 
{
	if(root==NULL)
	{
		return;
	}
	if(root!=NULL)
	{
		search_into_topper(root->left);
	    if(root->roll_no==r)
	    {
	        return root;	
		}
		search_into_topper(root->right);
	}   
}
struct Node* insert(struct Node *node, struct Node* node, int r,int m,int s,char *dept,char *name,char *sub,int total)
{
    
    if (node == NULL)
        return(newNode( node, root->roll_no,root->marks ,root->sem_no ,root->dept,root->stu_name ,root->sub_code,root->total ) );
 
    if (total < node->total)
        node->left  = insert(node->left, root->roll_no,root->marks ,root->sem_no ,root->dept,root->stu_name ,root->sub_code,root->total );
 
    else if (total > node->total)
        node->right = insert(node->left, root->roll_no,root->marks ,root->sem_no ,root->dept,root->stu_name ,root->sub_code,root->total );
 
    else // Equal keys not allowed
        return node;
 
    
    node->height = 1 + max(height(node->left),
                           height(node->right));
 
    
          node to check whether this node became
          unbalanced 
    int balance = getBalance(node);
 
    // If this node becomes unbalanced, then there are 4 cases
 
    // Left Left Case
    if (balance > 1 && total < node->left->total)
        return rightRotate(node);
 
    // Right Right Case
    if (balance < -1 && total > node->right->total)
        return leftRotate(node);
 
    // Left Right Case
    if (balance > 1 && total > node->left->total)
    {
        node->left =  leftRotate(node->left);
        return rightRotate(node);
    }
     // Right Left Case
    if (balance < -1 && total < node->right->total)
    {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }
 
    
    return node;
}
	*/	

void main()
{
 int operation,t,roll_no,roll_no1,roll_no2,ans,marks,sem,k,P,i,n1,n2;
 
 char str[MAX_SUB],dept[MAX_DEPT],name[MAX_NAME];
 int count = 0;
 
 
 
 t=1;
 struct Node *root = NULL,*ptr;
 struct Node *pnode;
 struct Node *lptr,*tptr;
    printf("Case 0:Quit\n");
 	printf("Case 1:Insert Node\n");
 	printf("Case 2:Delete Node\n");
 	printf("Case 3:Number of Records\n");
 	printf("Case 4:Search\n");
 	printf("Case 5:Height\n");
 	printf("Case 6:Range Search\n");
 	printf("Case 7:Print given lists\n");
 	printf("Case 8:No. of failure students in given no.of sujects \n");
 	printf("Case 9:Kth Highest \n");
 	printf("Case 10:Max marks in the given subject\n");
 	printf("Case 11:Who is topper\n");
 	
 	
 while(t==1)
 {  printf("Enter the case no:\n");
 	scanf("%d",&operation);
 	switch(operation)
 	{
 		case 0:
 			   t=0;
 			   break;
 		case 1:printf("Enter the roll no.");
			   scanf("%d",&roll_no);
			   printf("Enter the subject code");
			   scanf("%s",str);
			   printf("Enter the marks");
			   scanf("%d",&marks);
			   printf("Enter the sem_no");
			   scanf("%d",&sem);
			   printf("Enter the department name");
			   scanf("%s",dept);
			   printf("Enter the name");
			   scanf("%s",name);
		       root=insert( root, roll_no,marks,sem,dept,name,str);
			   break;
		case 2:
		       printf("Enter the roll no.");
			   scanf("%d",&roll_no);
			   printf("Enter the subject code");
			   scanf("%s",str);
			   root=deleteNode( root,roll_no,str);
			   break;
        case 3:
		       ans=getNum_Records(root);
			   printf("No. of active records in the list:%d\n",ans);
			   break;
	    case 4:
	    	    printf("Enter the roll no. and subject code ");
	    	    scanf("%d %s",&roll_no,str);
		        pnode=search( root,roll_no,str);
				printf("%d %s %s %d %s %d ",pnode->roll_no,pnode->stu_name,pnode->sub_code,pnode->marks,pnode->dept,pnode->sem_no);
				break;
		case 5:ans=height1(root);
		       printf("Height:%d\n",ans);
			   break;
		case 6:printf("Enter the roll nos.");
		       scanf("%d %d",&roll_no1,&roll_no2);
		       Range_Search(root, roll_no1,  roll_no2);
			   printf("\n");
			   break;
		case 7:printf("Database is:\n" );
		       print(root);							
			   printf("\n");
			   break;
		case 8:
		       printf("Enter the passing marks and subject code ");
	    	    scanf("%d %s",&P,str);
			   GetListofFailures(root,str, P);
			   tptr=lptr;
			   while(tptr!=NULL)
			   {
			   	    printf("%d %s %s %d %s %d ",tptr->roll_no,tptr->stu_name,tptr->sub_code,tptr->marks,tptr->dept,tptr->sem_no);
			   	    tptr=tptr->next;
			   }
			   printf("\n");
			   break;
	   case 9:	printf("Enter the value of k and subject code ");
	    	    scanf("%d %s",&k,str);
	    	    ptr=NULL;
				Kthmax_build(root,str,&ptr)	;
			    getKthmaxlist(ptr, k,count);
			    printf("\n");
			    break;
	   /* case 10:printf("Enter the no. of nodes in 1st list");
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
				sc=delete_list(&head_list_out);
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
				sc=delete_list(&head_list_out);
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
				sc=delete_list(&head_list_out);
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
				sc=delete_list(&head1);
				sc=delete_list(&head2);
				sc=delete_list(&head_list_out);/
				printf("\n");
				break;
		case 14:
		print_list(lptr);		Which student has the highest total marks in all the subjects					
				printf("\n");
				break;*/	
		
   }
}
}






























