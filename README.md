# Building
You need `cmake` and `make`, and a working C Compiler.

```bash

mkdir build && cd build
cmake ..
make ssl_server ssl_client1
```

# Running

Binaries are in `build/programs/ssl/`, just run `ssl_server` and `ssl_client1`