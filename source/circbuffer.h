#ifndef _CIRCBUFFER_H_
#define _CIRCBUFFER_H_

struct circ_buf {
    int* buf; // Array for the circular buffer
    int bufsz; // Array size
    int sz; // Number of elements written
    int head; // Back of the queue. Enqueued elements here.
    int tail; // Front of the queue. Dequeue elements here.
};

void circ_buf_init(struct circ_buf *cb, int *buf, int bufsz);
int circ_buf_enqueue(struct circ_buf *cb, int val);
int circ_buf_dequeue(struct circ_buf* cb, int *val);
void circ_buf_print(struct circ_buf* cb);

#endif // _CIRCBUFFER_H_