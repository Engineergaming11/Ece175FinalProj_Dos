#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdbool.h>


typedef struct person_s {
	char name[20];
	int age;
	struct person_s *listp;
	//struct person_s *head;
	//struct person_s *tail;

}person;

typedef struct card_s {
	char color[7];
	int value;
	char action[20];
	struct card_s *previous;
	struct card_s *next;

	card* p1head;
	card* p2head;
	card* p1tail;
	card* p2tail;
	card* chead;
	card* tail;

}card;


void addmemeber(person **h, person **t, FILE* inp);
void addcard(card** h, card** t, card s);
void deletecard(card** h, card** t, int cardChoice);
void shuffle();


int main(void) {
	person* head;
	person* tail;
	head = NULL;
	tail = NULL;
	card deck[108];


	FILE* inp = fopen("database.txt", "r");
	while (!feof(inp)) {
		addmember(&head, &tail, inp);
	}
	rewind(inp);




	

	/*
	* adding card body to call to add card function
	* int i = 0;
	addhead(&p1head, &p2head, deck[i]);
	i++;
	addhead(&p2head, &p2head deck[i]);
	i++;
	*/


	fclose(inp);
	return 0;
}

void shuffle() { 

}

void addmember(person **h, person **t, FILE* inp) {
	person* temp;
	temp = (person*)malloc(sizeof(person));
	fscanf(inp, "%s%d", temp->name, &temp->age);
	if (h == NULL) {
		h = temp;
	}
	else{
		t->tail = temp;
	}
	t = temp;
	temp->listp = NULL;

}

void addcard(card** h, card** t, card s, FILE*inp) {
	card* temp;
	temp = (card*)malloc(sizeof(card));
	fscanf(inp, "%s%d%s", temp->color, &temp->value, temp->action);
	if (h == NULL) {

	}
	else {

	}
}


void deletecard(card** h, card** t, int cardchoice) {
	card* p;
	int i;
	p = *h;
	for (i = 1; i < cardchoice; i++) {
		p = p->next;
	}
	if (p == *h) {
		*h = p->next;
	}
	else {
		(p->previous)->next = p->next;
	}
	if (p == *t) {
		*t = p->previous; //if last card is deleted
	}
	else {
		(p->next)->previous = p->previous;
	}
	free(p);

}
