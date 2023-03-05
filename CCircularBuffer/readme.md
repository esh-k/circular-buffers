# Circular Buffers
An efficient data structure to store fixed length queues.

## Build
Build all:
```
make
```
Run circbuffer.*.exe
```
Help:
e <int> enqueue an integer
d       dequeue
p       print the buffer
x       exit
```

## C Implementation
A fixed size circular buffer will enqueue elements in the front and dequeue elements from the back.
```C
struct circ_buf {
    int* buf; // Array for the circular buffer
    int bufsz; // Array size
    int sz; // Number of elements written
    int head; // Back of the queue. Enqueued elements here.
    int tail; // Front of the queue. Dequeue elements here.
};
```
Initially, the head and tail point to the 0th element.

On enqueue, we write the value to the where the head points and move the head to the next element. To prevent head from pointing to any value outside the limits of the `buf` array, we mod the head with `bufsz`.

We notice that _`head` will always point to an empty element in the `buf` array_. However, this is violated when the buffer is full, i.e., `bufsz` == `sz`, in which case we need to resolve the conflict using the `sz` and not enqueue any more elements. So, the updated invariant about `head` would be: _`head` will always point to an empty element in the `buf` array, as long as `buf` has empty elements._

On dequeue, the `tail` will write out the output and point to the next last element. Similar to head, we also need to cover the case when the `buf` is empty. So, `tail` has the invariant: _`tail` will alway point to the last element of the `buf` array, as long as `buf` is not empty._ 