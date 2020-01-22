#include <stdio.h>
#include <stdlib.h>
typedef struct node{
	int key;
	struct node *left,*right;

}node;

typedef struct listOfNumbers{
	
	struct node *node;
	struct listOfNumbers *next;
	
}listOfNumbers;

typedef struct numbers{
	struct listOfNumbers *Linked;
	struct numbers *next;	
}numbers;
listOfNumbers *MaybelistOfNumbers;
void find(listOfNumbers *control){
	
	listOfNumbers *Maybe=NULL;
	listOfNumbers *iter;listOfNumbers *temp;
	iter=control;int controlOf=1;
		while(iter!=NULL){
		if(iter->node->left!=NULL){
				
				temp=control;
				while(temp!=NULL){
				if(temp->node->key==iter->node->left->key){
					controlOf=0;
					break;
					}
					temp=temp->next;
					}
					if(controlOf==1){
						if(Maybe==NULL){
					Maybe=(listOfNumbers*)malloc(sizeof(listOfNumbers));
					Maybe->node=iter->node->left;
					Maybe->next=NULL;
					}
					else{
						temp=Maybe;
					while(temp->next!=NULL){
					temp=temp->next;
						}
					temp->next=(listOfNumbers*)malloc(sizeof(listOfNumbers));
			     	temp->next->node=iter->node->left;
					temp->next->next=NULL;
					}
					}	
			}
			controlOf=1;
			if(iter->node->right!=NULL){
				
				temp=control;
				while(temp!=NULL){
				if(temp->node->key==iter->node->right->key){
				controlOf=0;
				break;
				}
				temp=temp->next;
				}
				if(controlOf==1){
				if(Maybe==NULL){
				Maybe=(listOfNumbers*)malloc(sizeof(listOfNumbers));
				Maybe->node=iter->node->right;
				Maybe->next=NULL;				
				}
				else{
				temp=Maybe;
				while(temp->next!=NULL){
				temp=temp->next;
				}
				temp->next=(listOfNumbers*)malloc(sizeof(listOfNumbers));
				temp->next->node=iter->node->right;
				temp->next->next=NULL;
				}
				}		
				controlOf=1;	
			} 
			iter=iter->next;
		}
	MaybelistOfNumbers=Maybe;
}

struct node *newNode(int item) 
{ 
     node *temp =  (node *)malloc(sizeof(node)); 
    temp->key = item; 
    temp->left = temp->right = NULL; 
    return temp; 
}
int size=0;
struct node* insert(struct node* node, int key) 
{
    if (node == NULL){
    	size++;
    return newNode(key); 	
	}
    if (key < node->key) {
     node->left  = insert(node->left, key);
	}
    else if (key > node->key) {
    node->right = insert(node->right, key);
	}
    return node; 
} 

int count=0;

void findOfSequence(numbers *variables){
	
	listOfNumbers *temp=variables->Linked;
	int LinkedSize=0;
	
	while(temp!=NULL){
		LinkedSize++;
		temp=temp->next;
	}
	
	if(LinkedSize==size){
		numbers *print=variables;
		listOfNumbers *controlOfPrint;
		while(print!=NULL){
			controlOfPrint=print->Linked;
			while(controlOfPrint!=NULL){
				printf("%d ",controlOfPrint->node->key);
				controlOfPrint=controlOfPrint->next;
			}printf("\n");count++;
			print=print->next;
		}
		
	}else {
		listOfNumbers *iter=variables->Linked;
		listOfNumbers *storeage=NULL;
 	    listOfNumbers *tempStorage;  
		while(iter!=NULL){
			if(storeage==NULL){
				storeage=(listOfNumbers*)malloc(sizeof(listOfNumbers));
				storeage->node=iter->node;
				storeage->next=NULL;
			}else{
				tempStorage=storeage;
				while(tempStorage->next!=NULL){
					tempStorage=tempStorage->next;
				}
				tempStorage->next=(listOfNumbers*)malloc(sizeof(listOfNumbers));
				tempStorage->next->node=iter->node;
				tempStorage->next->next=NULL;
			}
			iter=iter->next;
		}
		tempStorage->next->next=(listOfNumbers*)malloc(sizeof(listOfNumbers));
		tempStorage->next->next->node=MaybelistOfNumbers->node;
		tempStorage->next->next->next=NULL;
		
		numbers *addToVariables=variables;
		while(addToVariables->next!=NULL){
			addToVariables=addToVariables->next;
		}
		addToVariables->next=(numbers*)malloc(sizeof(numbers));
		addToVariables->next->Linked=storeage;
		addToVariables->next->next=NULL;

		if(MaybelistOfNumbers->next!=NULL){
			MaybelistOfNumbers=MaybelistOfNumbers->next;
		}else{
			numbers *tempToVariable;
			tempToVariable = variables;
			variables=variables->next;
			free(tempToVariable);
			find(variables->Linked);
		}
		findOfSequence(variables);
		
		
	}
}


int main()
{
node *head;
head = NULL;
int d;
  char temp;
  do {
      scanf("%d%c", &d, &temp);
      if(head == NULL){
	head = insert(head,d);
    }
else{
	insert(head,d);
    }
  } while(temp != '\n');
  
  numbers *variablesOfLeft, *variablesOfRight;
	
	if(head->left == NULL && head->right == NULL){
		printf("%d\n",head->key);
		count=1;
		}
	else if(head->left != NULL && head->right == NULL){
		listOfNumbers *LeftChild=(listOfNumbers*)malloc(sizeof(listOfNumbers));

    	LeftChild->node=head;
		LeftChild->next=(listOfNumbers*)malloc(sizeof(listOfNumbers));
		LeftChild->next->node=head->left;
		LeftChild->next->next=NULL;
	
		variablesOfLeft=(numbers*)malloc(sizeof(numbers));
		variablesOfLeft->Linked=LeftChild;
		variablesOfLeft->next=NULL;
		find(variablesOfLeft->Linked);
		findOfSequence(variablesOfLeft);
		}
	else if(head->left == NULL && head->right != NULL){
		listOfNumbers *RightChild=(listOfNumbers*)malloc(sizeof(listOfNumbers));
		
		RightChild->node=head;
		RightChild->next=(listOfNumbers*)malloc(sizeof(listOfNumbers));
		RightChild->next->node=head->right;
		RightChild->next->next=NULL;
	
		variablesOfRight=(numbers*)malloc(sizeof(numbers));
		variablesOfRight->Linked=RightChild;
		variablesOfRight->next=NULL;
		
		find(variablesOfRight->Linked);
		findOfSequence(variablesOfRight);	
		}
	else if(head->left != NULL && head->right != NULL){
		listOfNumbers *RightChild=(listOfNumbers*)malloc(sizeof(listOfNumbers));
		listOfNumbers *LeftChild=(listOfNumbers*)malloc(sizeof(listOfNumbers));
	
		LeftChild->node=head;
		LeftChild->next=(listOfNumbers*)malloc(sizeof(listOfNumbers));
		LeftChild->next->node=head->left;
		LeftChild->next->next=NULL;
	
		RightChild->node=head;
		RightChild->next=(listOfNumbers*)malloc(sizeof(listOfNumbers));
		RightChild->next->node=head->right;
		RightChild->next->next=NULL;
	
		variablesOfLeft=(numbers*)malloc(sizeof(numbers));
		variablesOfLeft->Linked=LeftChild;
		variablesOfLeft->next=NULL;
		variablesOfRight=(numbers*)malloc(sizeof(numbers));
		variablesOfRight->Linked=RightChild;
		variablesOfRight->next=NULL;
		find(variablesOfLeft->Linked);
    	findOfSequence(variablesOfLeft);
		find(variablesOfRight->Linked);
		findOfSequence(variablesOfRight);	
		}
	
   printf("Total count of numbers : %d",count);

return 0;
}
