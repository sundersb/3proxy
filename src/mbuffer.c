#include "mbuffer.h"
#include "proxy.h"

#define DEFAULT_SIZE 2048
#define GROW_BY DEFAULT_SIZE
#define MAX_SIZE (DEFAULT_SIZE * 8)

int mbuf_init (struct mbuffer *mb) {
  mb->buffer = (unsigned char *) myalloc (DEFAULT_SIZE);
  mb->size = mb->buffer ? DEFAULT_SIZE : 0;
  return mb->size;
}

void mbuf_cleanup (struct mbuffer *mb) {
  if (mb->buffer && mb->size)
    myfree (mb->buffer);

  mb->size = 0;
  mb->buffer = NULL;
}

int mbuf_grow (struct mbuffer *mb) {
  if (mb->size >= MAX_SIZE) return 0;

  if (!mb->buffer || !mb->size)
    return mbuf_init (mb);

  mb->size += GROW_BY;
  mb->buffer = (unsigned char *) myrealloc(mb->buffer, mb->size);

  if (!mb->buffer) mb->size = 0;

  return mb->size;
}

int mbuf_shrink (struct mbuffer *mb) {
  if (mb->buffer == NULL || mb->size == 0)
    return mbuf_init(mb);

  if (mb->size != DEFAULT_SIZE) {
    myfree(mb->buffer);
    return mbuf_init(mb);
  }

  return mb->size;
}

