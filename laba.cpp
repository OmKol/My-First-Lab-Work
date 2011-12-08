/*
 * laba.cpp
 *
 *  Created on: 08.12.2011
 *      Author: omkol
 */

#include <stdio.h>

struct Node
{
	int d;
	Node *next;
	Node *prev;
};

Node *add(Node *e, int val)
{
	Node *n = new Node();

	n->prev = e;
	n->next = e->next;
	if(e->next)
		e->next->prev = n;
	e->next = n;
	n->d = val;
	return n;
}

int main() {
	Node first, *last;
	last = &first;
	first.next = 0;
	first.prev = 0;

	last = add(last, 0);
	last = add(last, 1);
	last = add(last, 2);

	Node *cur = first.next;
	while(cur)
	{
		printf("%d\n", cur->d);
		cur = cur->next;
	}

	cur = first.next;
	while(cur)
	{
		Node *next = cur->next;
		delete cur;
		cur = next;
	}

	return 0;
}
