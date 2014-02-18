#include <stdio.h>
#include <stdlib.h>

struct treenode
{
	int data;
	struct treenode *left;
	struct treenode *right;
};

struct queuenode
{
	struct treenode *value;
	struct queuenode *next;
	struct queuenode *prev;
};

struct queuenode *head = NULL;
struct queuenode *tail = NULL;

void enqueue(struct treenode *node)
{
	struct queuenode *newnode = (struct queuenode *)malloc(sizeof(struct queuenode));
	newnode->value = node;
	if(head == NULL)
	{
		newnode->next = NULL;
		head = newnode;
		tail = newnode;
		newnode->prev = NULL;
		//printf("Enqueue done\n");
		return;
	}
	
	newnode->next = head;
	newnode->prev = NULL;
	head->prev = newnode;
	head = newnode;
	//printf("Enqueue done\n");
}

struct treenode * dequeue()
{
		struct treenode *n; 
		if(tail != NULL)
		{	
			n = tail->value;			
			struct queuenode *tmp = tail;		
			tail = tail->prev;
			if(tail != NULL)
				tail->next = NULL;	
			else
				head = NULL;
			//printf("Dequeue done\n");	
			return n;
		}
		else
		{
			printf("tail returned NULL\n");
			return NULL;
		}
}

void levelordertraversal(struct treenode *root)
{
	
	enqueue(root);
	printf("The level order traversal of tree is:\n");
	while(head != NULL)
	{
		struct treenode *tmp = dequeue();
		printf("%d\t",tmp->data);
		if(tmp->left != NULL)
			enqueue(tmp->left);
		if(tmp->right != NULL)
			enqueue(tmp->right);
	}
}

void inordertraversal(struct treenode *root)
{
	if(root == NULL)
		return;
		
	inordertraversal(root->left);
	printf("%d\t",root->data);
	inordertraversal(root->right);
	
}

void postordertraversal(struct treenode *root)
{
	if(root == NULL)
		return;
		
	postordertraversal(root->left);
	postordertraversal(root->right);
	printf("%d\t",root->data);
}

void preordertraversal(struct treenode *root)
{
	if(root == NULL)
		return;
	
	printf("%d\t",root->data);	
	preordertraversal(root->left);	
	preordertraversal(root->right);

}

struct treenode* newNode(int data)
{
  struct treenode* node = (struct treenode*)
                       malloc(sizeof(struct treenode));
  node->data = data;
  node->left = NULL;
  node->right = NULL;
 
  return(node);
}

int main()
{
	struct treenode *root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);
	root->right->left = newNode(6);
	root->right->right = newNode(7);
	
	levelordertraversal(root);
	printf("\nThe in order traversal of tree is:\n");
	inordertraversal(root);
	printf("\nThe post order traversal of tree is:\n");
	postordertraversal(root);
	printf("\nThe pre order traversal of tree is:\n");
	preordertraversal(root);
	
	return 0;
}
