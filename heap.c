#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include "heap.h"

typedef struct nodo{
   void* data;
   int priority;
}heapElem;

typedef struct Heap{
  heapElem* heapArray;
  int size;
  int capac;
} Heap;

Heap* createHeap(){
Heap* HeapAux = (Heap*) malloc(sizeof(Heap));
   HeapAux->heapArray = (heapElem*) malloc(sizeof(heapElem) * 3);
   HeapAux->size = 0;
   HeapAux->capac = 3;
  
   return HeapAux;
}

void* heap_top(Heap* pq){
  if(pq == NULL || pq->size == 0) return NULL;
  
  return pq->heapArray[0].data;
}

void heap_push(Heap* pq, void* data, int priority){
  if(pq->size == pq->capac){
    pq->capac = pq->capac * 2 + 1;
    pq->heapArray = (heapElem *) realloc(pq->heapArray, pq->capac * sizeof(heapElem));
  }

  int pos = pq->size;

   while(pos > 0 && pq->heapArray[(pos-1)/2].priority < priority){
    pq->heapArray[pos] = pq->heapArray[(pos-1)/2];
    pos = (pos-1)/2;
  }

  pq->heapArray[pos].priority = priority;
  pq->heapArray[pos].data = data;
  pq->size++;
}


void heap_pop(Heap* pq){
  pq->size--;
  pq->heapArray[0] = pq->heapArray[pq->size];
  
  int pos = 0;
  int sucesor = 1;
  int sucesor2 = 2;

  while(sucesor < pq->size){
    if(sucesor2 < pq->size && pq->heapArray[sucesor2].priority > pq->heapArray > pq->heapArray[sucesor].priority) sucesor++;
     
  }
}

