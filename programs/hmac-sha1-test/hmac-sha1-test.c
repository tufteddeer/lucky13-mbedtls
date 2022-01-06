#include <stdio.h>
#include <string.h>
#include <bits/types/struct_timeval.h>
#include <sys/time.h>
#include "polarssl/sha1.h"

int main(int argc, char *argv[] )
{
    size_t keylen = 20;
    unsigned char key[keylen];
    memset(key, 'K', keylen);

    size_t msglen = 55;
    unsigned char message[msglen];
    memset(message, 'M', msglen);

    printf("payload length is %zu\n", msglen);

    unsigned char out[20];

    // measuring execution time: https://stackoverflow.com/a/45769714
    long start, end;
    struct timeval timecheck;

    gettimeofday(&timecheck, NULL);
    start = (long)timecheck.tv_sec * 1000 + (long)timecheck.tv_usec / 1000;

    int count = 10000000;
    for (int i = 0; i < count; i++) {
        sha1_hmac(key, keylen, message, msglen, out);
    }

    gettimeofday(&timecheck, NULL);
    end = (long)timecheck.tv_sec * 1000 + (long)timecheck.tv_usec / 1000;

    long elapsed = end - start;
    printf("%ld milliseconds elapsed\n", elapsed);
    printf("avg: %Lf\n", (long double) elapsed / (long double)count);

    return 0;
}