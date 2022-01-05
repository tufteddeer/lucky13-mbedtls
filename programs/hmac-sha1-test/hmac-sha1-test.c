#include <stdio.h>
#include <string.h>
#include "polarssl/sha1.h"

// copied from ssl_tls.c
static void ssl_mac_sha1( unsigned char *secret,
                          unsigned char *buf, size_t len,
                          unsigned char *ctr, int type )
{
    unsigned char header[11];
    unsigned char padding[40];
    sha1_context sha1;

    memcpy( header, ctr, 8 ); // SQN?
    header[ 8] = (unsigned char)  type;
    header[ 9] = (unsigned char)( len >> 8 );
    header[10] = (unsigned char)( len      );

    memset( padding, 0x36, 40 );
    sha1_starts( &sha1 );
    sha1_update( &sha1, secret,  20 );
    sha1_update( &sha1, padding, 40 );
    sha1_update( &sha1, header,  11 );
    sha1_update( &sha1, buf,  len );
    sha1_finish( &sha1, buf + len );

    memset( padding, 0x5C, 40 );
    sha1_starts( &sha1 );
    sha1_update( &sha1, secret,  20 );
    sha1_update( &sha1, padding, 40 );
    sha1_update( &sha1, buf + len, 20 );
    sha1_finish( &sha1, buf + len );
}

int main(int argc, char *argv[] )
{
    size_t keylen = 20;
    unsigned char key[keylen];
    memset(key, 'K', keylen);

    size_t msglen = 10;
    unsigned char message[msglen];
    memset(message, 'M', msglen);

    printf("payload length is %zu\n", msglen);

    // this is probably the sequence number maintained by both peers
    // so the actual value should not matter here
    unsigned char ctr = 0x1;

    ssl_mac_sha1(key, message, msglen, &ctr, 0x17);

    return 0;
}