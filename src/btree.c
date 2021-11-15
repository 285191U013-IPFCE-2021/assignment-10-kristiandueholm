#include "btree.h"

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>


struct tree_node * Insert (int x, struct tree_node *t)
{
  struct tree_node *new = malloc(sizeof(struct tree_node));
  new->item = x;
  new->left = NULL;
  new->right = NULL;

  struct tree_node *p = t;

  if (t == NULL)
  {
    t = new;
  }

  else while (1)
  {
    // x smaller or equal to item
    if (x <= p->item)
    {
      // Does left exist?
      if (p->left)
      {
        p = p->left;
      }
      else 
      {
        p->left = new;
        break;
      }
    }

    // x is larger than item
    else
    {
      // Does left exist?
      if (p->right)
      {
        p = p->right;
      }
      else 
      {
        p->right = new;
        break;
      }
    }
  }
  
  return t;
}

struct tree_node * Remove (int x, struct tree_node *t)
{
 // Remove one item from the tree t

  return NULL;
}


int Contains (int x, struct tree_node *t)
{

  // Return true if the tree t contains item x. Return false otherwise.

  return NULL;

}


struct tree_node * Initialize (struct tree_node *t)
{
  t = malloc(sizeof(struct tree_node));

  t->item = NULL;
  t->left = NULL;
  t->right = NULL;

  return t;
}

int Empty (struct tree_node *t)
{
  // Test if empty
  return 0;
}

int Full (struct tree_node *t)
{
    // Test if full
    return 0;
}
