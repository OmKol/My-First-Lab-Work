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

Node *insert(Node *pr, Node *ne, int val)
{
	Node *n = new Node();

	n->prev = pr;
	n->next = ne;
	pr->next = n;
	ne->prev = n;
	n->d = val;
	return n;
}

int main() {
	Node first, *last;
	last = &first;
	first.next = 0;
	first.prev = 0;

	last = add(last, 2);
	last = add(last, 5);
	last = add(last, 8);

	Node *cur = first.next;
	while(cur)
	{
		printf("%d\n", cur->d);
		cur = cur->next;
	}

	int temp = 0;
	scanf("%d", &temp);

	bool check = true;
	cur = first.next;
	while(cur)
	{
		if (temp < cur->d)
		{
			insert(cur->prev, cur, temp);
			check = false;
			break;
		}
		cur = cur->next;
	}
	if (check) last = add(last, temp);

	cur = first.next;
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
