#ifndef _MBUFFER_H_
#define _MBUFFER_H_

/* Managed buffer. Both members shouldn't be
 * changed by client code */
struct mbuffer {
  unsigned char *buffer;
  int size;
};

/* Allocate buffer with default size. Returns bufsize or 0 if error. */
int mbuf_init (struct mbuffer *mb);

/* Free buffer */
void mbuf_cleanup (struct mbuffer *mb);

/* Grow buffer by certain amount of memory. Returns new size or 0 if failed to grow.
 * The buffer will not grow if its' size reached a certain limit. */
int mbuf_grow (struct mbuffer *mb);

/* Shrink the buffer to default size */
int mbuf_shrink (struct mbuffer *mb);

#endif /* _MBUFFER_H_ */
