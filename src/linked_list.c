#include "linked_list.h"
/*
 * Linked list
 */

#include <stdio.h>		/* printf */
#include <stdlib.h>		/* malloc, free */
#include <assert.h>		/* assert */

/* functions to create lists */
node *make_node (int v, node * q)
{
  node *p = malloc (sizeof (node));
  p->value = v;

  if (q == &SENTINEL_node)
    p->next = &SENTINEL_node;
  else
    p->next = q;
  return p;
}

/* free all nodes in the list p */
void free_list (node * p)
{
  node *q = p;
  while (q != &SENTINEL_node)
    {
      node *t = q->next;
      free (q);
      q = t;
    }
}


/* print list to console */
void print_list (node * p)
{
    printf("%d", p->value);

    if (p->next != NULL)
    {
      print_list(p->next);
    }
    return;
}

int sum_squares (node * p)
{
  int sum = p->value * p->value;

  if (p->next != NULL)
  {
    sum += sum_squares(p->next);
  }

  return sum;
}

node *map (node * p, int (*f) (int))
{
  node *q = malloc(sizeof(node));

  q->value = f(p->value);
  
  if (p->value != NULL)
  {
    q->next = map(p->next, f);
  }

  else
  {
    q->next = NULL;
  }
  
  return q;
}


int square (int x)
{
  return x * x;
}
