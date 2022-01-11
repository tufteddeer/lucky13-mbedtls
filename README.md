# Building
You need `cmake` and `make`, and a working C Compiler.

```bash

mkdir build && cd build
cmake ..
make hmac_sha1_test
```

# Running

Execute the `build/programs/hmac_sha1_test/hmac_sha1_test` binary.

You can adjust the message length by changing `msglen` in `programs/hmac-sha1-test/hmac-sha1-test.c`

`sha1_process` calls can be logged by uncommenting the `puts("sha1_process");` line in `library/sha1.c`