/* 
 * Code for basic C skills diagnostic.
 * Developed for courses 15-213/18-213/15-513 by R. E. Bryant, 2017
 * Modified to store strings, 2018
 */

/*
 * This program implements a queue supporting both FIFO and LIFO
 * operations.
 *
 * It uses a singly-linked list to represent the set of queue elements
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "harness.h"
#include "queue.h"

/*
  Create empty queue.
  Return NULL if could not allocate space.
*/
queue_t *q_new()
{
    queue_t *q =  malloc(sizeof(queue_t));
    if (q == NULL)
    {
      printf("q return null\n");
      return NULL;
    }
    else
    {
      q->head = NULL;
      q->tail = NULL;
      q->qsize = 0;
      
      return q;
    }
    
    /* What if malloc returned NULL? */
}

/* Free all storage used by queue */
void q_free(queue_t *q)
{
  // 1st condition q == NULL
  if(q == NULL)
    return;
  //2nd condition q != NULL
  else
  {
    list_ele_t* p = q->head;
    list_ele_t* tmp = NULL;
    /*in fact i should distiguish whether p == NULL and p != NULL
    if distinguish, code will look as follows:
    if( p == NULL){
      free(q);
      return;
    }
    else
    {
      while(p){
        tmp = p->next;
        free(p);
        p = tmp;
      }
      free(q);
      return;
    }
    */
    while(p!=NULL){
      tmp = p->next;
      free(p->value);
      free(p);
      p = tmp;
    }
    free(q);
  }
    /* How about freeing the list elements and the strings? */
    /* Free queue structure */
}

/*
  Attempt to insert element at head of queue.
  Return true if successful.
  Return false if q is NULL or could not allocate space.
  Argument s points to the string to be stored.
  The function must explicitly allocate space and copy the string into it.
 */
bool q_insert_head(queue_t *q, char *s)
{
  if(q == NULL)
  {
    return false;
  }
  else
  {
    list_ele_t *newh;
    /* What should you do if the q is NULL? */
    newh = malloc(sizeof(list_ele_t));
    /* Don't forget to allocate space for the string and copy it */
    /* What if either call to malloc returns NULL? */
    if(newh == NULL)
    {
      return false;
    }
    else
    {
      newh->value = malloc(strlen(s)+1);
      if(newh->value == NULL)
      {
        free(newh);
        return false;
      }
      else
      {
        strcpy(newh->value,s);
        newh->next = NULL;
        // modify q->tail
        if(q->head == NULL)
        {
          q->tail = newh;
        }
        newh->next = q->head;
        q->head = newh;
        q->qsize++;
        return true;
      }
    }
  }
}


/*
  Attempt to insert element at tail of queue.
  Return true if successful.
  Return false if q is NULL or could not allocate space.
  Argument s points to the string to be stored.
  The function must explicitly allocate space and copy the string into it.
 */
bool q_insert_tail(queue_t *q, char *s)
{
    /* What should you do if the q is NULL? */
  if(q == NULL)
  {
    return false;
  }
  else
  {
    list_ele_t *newh;
    newh = malloc(sizeof(list_ele_t));
    if(newh == NULL)
    {
      return false;
    }
    else
    {
    /* Don't forget to allocate space for the string and copy it */
    /* What if either call to malloc returns NULL? */
      newh->value = malloc(strlen(s)+1);
      if(newh->value == NULL)
      {
        free(newh);
        return false;
      }
      else
      {
        strcpy(newh->value,s);
        newh->next = NULL;
        // modify q->tail
        if(q->head == NULL)
        {
          q->head = newh;
          q->tail = newh;
        }
        else
        {
          q->tail->next = newh;
          q->tail = newh;
        }
        q->qsize++;
        return true;
      }
    }
  }
}

/*
  Attempt to remove element from head of queue.
  Return true if successful.
  Return false if queue is NULL or empty.
  If sp is non-NULL and an element is removed, copy the removed string to *sp
  (up to a maximum of bufsize-1 characters, plus a null terminator.)
  The space used by the list element and the string should be freed.
*/
bool q_remove_head(queue_t *q, char *sp, size_t bufsize)
{
  if(q != NULL && q->head != NULL)
  {
    /* You need to fix up this code. */
    if(sp != NULL)
    {
      char* tmp = q->head->value;
      list_ele_t* tmp1 = q->head;
      int len = strlen(tmp);
      //len should <= bufsize-1 这样才能完全放下，如果len大于bufsize-1的话，链表节点里所指的string就要被截断存放
      if(len > (bufsize-1))
      {
        for(int i = 0;i<bufsize-1;i++)
          sp[i] = tmp[i];
        sp[bufsize-1] = '\0';
      }
      else
        strcpy(sp,tmp);

      q->head = q->head->next;
      q->qsize--;
      free(tmp1);
      free(tmp);

      return true;
    }
    else
      return false;
  }
  else
    return false;
}

/*
  Return number of elements in queue.
  Return 0 if q is NULL or empty
 */
int q_size(queue_t *q)
{
    /* You need to write the code for this function */
    /* Remember: It should operate in O(1) time */
  if(q!=NULL)
    return q->qsize;
  else
    return 0;
}

/*
  Reverse elements in queue
  No effect if q is NULL or empty
  This function should not allocate or free any list elements
  (e.g., by calling q_insert_head, q_insert_tail, or q_remove_head).
  It should rearrange the existing ones.
 */
void q_reverse(queue_t *q)
{
    /* You need to write the code for this function */
  if(q != NULL && q->head != NULL)
  {
    list_ele_t* tmp = q->tail;
    list_ele_t* prev = NULL;
    list_ele_t* cur = q->head;

    //swap(q->head,q->tail)
    q->tail = q->head;
    q->head = tmp;

    //reverse
    while(cur != NULL)
    {
      //1st 取出next
      tmp = cur->next;
      //2nd modify next point
      cur->next = prev;
      //3rd move prev and cur
      prev = cur;
      cur = tmp;
    }
  }
}

