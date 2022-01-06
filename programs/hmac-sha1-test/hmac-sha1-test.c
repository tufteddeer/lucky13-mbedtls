#include <stdio.h>
#include <string.h>
#include "polarssl/sha1.h"

int main(int argc, char *argv[] )
{
    size_t keylen = 20;
    unsigned char key[keylen];
    memset(key, 'K', keylen);

    size_t msglen = 56;
    unsigned char message[msglen];
    memset(message, 'M', msglen);

    printf("payload length is %zu\n", msglen);

    unsigned char out[20];
    sha1_hmac(key, keylen, message, msglen, out);

    return 0;
}