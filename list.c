#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node {
	int val;
};

struct entry {
	struct entry *next;
	struct node node;
};

struct list_head{
	struct entry *next;
};

void list_init(struct list_head *list){
	list->next = NULL;
}


void list_append(struct list_head *list, struct entry *new){
	struct entry *tmp_entry = NULL;

	if(list->next != NULL){
		tmp_entry = list->next;
		while(tmp_entry->next != NULL){
			tmp_entry = tmp_entry->next;
		}
		tmp_entry->next = new;
		new-> next = NULL;
	}
	else{
		list->next = new;
		new->next = NULL;
	}


}

void list_add(struct list_head *list, struct entry *new){
	struct entry *tmp_entry = NULL;
	
	tmp_entry = list->next;
	list->next = new;
	new->next = tmp_entry; 
}
 
void list_del(struct list_head *list, struct entry *del){
	struct entry *tmp_entry = NULL;

	if(list->next != del && list->next != del){
		tmp_entry = list->next;
		while(tmp_entry->next != NULL && tmp_entry ->next != del){
			tmp_entry = tmp_entry->next;
			if(tmp_entry->next == del){
				//tmp_entry2 = tmp_entry->next;
				tmp_entry->next = tmp_entry->next->next;
			}	
		}
	}	

}

bool list_is_last(struct entry *entry){
	return !!(entry->next == NULL);
}
