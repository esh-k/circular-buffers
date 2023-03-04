#include <stdio.h>
#include <stdlib.h>
#include "circbuffer.h"

void circ_buf_init(struct circ_buf *cb, int *buf, int bufsz) 
{
    cb->buf = buf;
    cb->bufsz = bufsz;
    cb->sz = 0;
    cb->head = 0;
    cb->tail = 0;
}

int circ_buf_enqueue(struct circ_buf *cb, int val)
{
    if (cb->bufsz > cb->sz) {
        cb->buf[cb->head++] = val;
        cb->head %= cb->bufsz;
        cb->sz++;
        return 0;
    } 
    return -1;
}

int circ_buf_dequeue(struct circ_buf* cb, int *val)
{
    if (cb->sz == 0)
        return -1;
    *val = cb->buf[cb->tail++];
    cb->tail %= cb->bufsz;
    cb->sz--;
    return 0;
}

void circ_buf_print(struct circ_buf* cb)
{
    printf("size: %d\n", cb->sz);
    printf("head: %d, taild: %d\n", cb->head, cb->tail);
    printf("capacity: %d\n{ ", cb->bufsz);
    for (int i = cb->tail, c = 0; c < cb->sz; i++, c++)
        printf("%d ", cb->buf[i%cb->bufsz]);
    printf("}\n");
}