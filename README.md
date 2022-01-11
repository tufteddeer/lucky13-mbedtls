This is an outdated and vulnerable copy of [Mbed TLS](https://github.com/ARMmbed/mbedtls) 1.2.4. to demonstrate padding oracles.

---

The example program demonstrating HMAC-SHA1 timing differences with messages of different lengths can be found in the `hmac-sha1-rounds` branch.

# Building
You need `cmake` and `make`, and a working C Compiler.

```bash

mkdir build && cd build
cmake ..
make ssl_server ssl_client1
```

# Running

Binaries are in `build/programs/ssl/`, just run `ssl_server` and `ssl_client1`

Note that the client will connect to port 9091, while the server listens at 4433. This is because it is intended to be used in combination with a proxy.