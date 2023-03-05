#include <stdio.h>
#include <stdlib.h>
#include "circbuffer.h"

int run_cmd(char cmd, struct circ_buf *cb)
{
    int val;
    switch(cmd) {
        case 'e':
            scanf("%d", &val);
            if (circ_buf_enqueue(cb, val) < 0) {
                printf("enqueue failed: insufficient space in queue\n");
            }
            break;
        case 'd':
            if (circ_buf_dequeue(cb, &val) < 0) {
                printf("dequeue failed: empty queue\n");
            }
            printf("removed: %d\n", val);
            break;
        case 'p':
            circ_buf_print(cb);
            break;
        case 'x':
            return 0;
        default:
            printf("Help:\ne <int>\tenqueue an integer value\nd\tdequeue\np\tprint the buffer\nx\texit\n");
    }
    return 1;
}

int main() 
{
    int bufsz = 0;
    struct circ_buf cb;

    printf("Enter buffer size:\t");
    scanf("%d", &bufsz);
    int* buf = (int*)malloc(sizeof(int)*bufsz);
    circ_buf_init(&cb, buf, bufsz);

    char cmd;
    int cont = 1;
    while (cont) {
        scanf("\n%c", &cmd);
        cont = run_cmd(cmd, &cb);
    }
    free(buf);
    return 0;
}