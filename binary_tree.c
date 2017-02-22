#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <math.h>


struct node{
	struct node *left;
	struct node *right;
	int val;
};

struct node *new_node(int val){
	struct node *new_node = (struct node *) malloc(sizeof(struct node));
	new_node-> left = NULL;
	new_node-> right = NULL;
	new_node-> val = val;
	
	return new_node;
}

struct node *insert(struct node *node, int val){

	if(node == NULL){
		return new_node(val);
	}
	if( val <= node->val){
		node->left = insert(node->left, val);
	}else{
		node->right =insert(node->right, val);
	}
	return node;
