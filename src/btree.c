#include "..\include\btree.h"

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>

/* Inserts node into BST */
struct tree_node * Insert (int x, struct tree_node *t)
{
  struct tree_node *new_node = malloc(sizeof(struct tree_node));
  new_node->item = x;
  new_node->left = NULL;
  new_node->right = NULL;

  struct tree_node *p = t;

  if (t == NULL)
  {
    t = new_node;
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
        p->left = new_node;
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
        p->right = new_node;
        break;
      }
    }
  }
  
  return t;
}

/* Removes node from BST */
/* 3 cases:
    node has 2 children
    node has 1 child
    node has no children (leaf) 
*/
struct tree_node * Remove (int x, struct tree_node *t)
{
  // Do nothing if x is not in t
  if (Contains(x, t) == 0)
  {
    return t;
  }
  
  struct tree_node *p = t;
  struct tree_node *p_chaser = t;

  // find x in tree, assign p to found position
  while(1)
  {
    // Base case: current node is x
    if (x == p->item)
    {
      break;
    }
    
    // Go left
    else if (x <= p->item)
    {
      if (p->left)
      {
        p_chaser = p;
        p = p->left;
      }
    }

    // Go right
    else if (x > p->item)
    {
      if (p->right)
      {
        p_chaser = p;
        p = p->right;
      }
    }
  }

  // p is pointing on item to be removed

  if (p->left)
  {
    if (p->right)
    {
      // p has two children

      // find inorder successor
      struct tree_node *q = p->right;

      // go left until left no longer exists
      while (q->left)
      {
        q = q->left;
      }

      // q is now pointing to inorder successor

      // Replace p with successor and free successor
      p->item = q->item;
      p->left = q->left;
      p->right = q->right;
      free(q);
    }
    else
    {
      // p has one child (left)
      struct tree_node *q = p->left;
      p->item = q->item;
      p->left = q->left;
      p->right = q->right;
      free(q);
    }
  }
  else if (p->right)
  {
    // p has one child (right)
    struct tree_node *q = p->right;
    p->item = q->item;
    p->left = q->left;
    p->right = q->right;
    free(q);
  }

  // p is a leaf
  else
  {
    // Check if p is root (1 node in tree)
    if (p == t)
    {
      t = NULL;
    }
    
    // Leaf is chasers left child
    else if (x <= p_chaser->item)
    {
      p_chaser->left = NULL;
    }

    // Right child
    else
    {
      p_chaser->right = NULL;
    }
    
    free(p);
  }
  
  return t;
}

/* Returns 1 if x is contained in t */
int Contains (int x, struct tree_node *t)
{
  while(1)
  {
    // Base case: current node is x
    if (x == t->item)
    {
      return 1;
    }
    
    // Go left
    else if (x <= t->item)
    {
      if (t->left)
      {
        t = t->left;
      }

      // No more left exists, exit
      else
      {
        return 0;
      }
    }

    // Go right
    else if (x > t->item)
    {
      if (t->right)
      {
        t = t->right;
      }

      // No more right exists, exit
      else
      {
        return 0;
      }
    }
  }
}

/* Returns empty pointer */
struct tree_node * Initialize (struct tree_node *t)
{
  t = NULL;

  return t;
}

/* Returns 1 if BST is empty */
int Empty (struct tree_node *t)
{
  if (t == NULL)
  {
    return 1;
  }
  else
  {
    return 0;
  }
}

int Full (struct tree_node *t)
{
    // Singly linked lists af never full
    return 0;
}
