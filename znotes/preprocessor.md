```cpp
#include <iostream>
using namespace std;

#define DEBUG_LEVEL 1

int main() {
#if DEBUG_LEVEL >= 1
    cout << "main has started" << endl;
#endif
    cout << "Hello, world!" << endl;
#if DEBUG_LEVEL >= 2
    cout << "About to end main" << endl;
#endif

return 0;
}
```

Can also have definitions in command-line

```cpp
$ cat debug.cc
#include <iostream>
using namespace std;
#ifndef DEBUG_LEVEL
#define DEBUG_LEVEL 0
#endif
int main() {
#if DEBUG_LEVEL >= 1
 cout << "main has started" << endl;
#endif
 cout << "Hello, world!" << endl;
#if DEBUG_LEVEL >= 2
 cout << "About to end main" << endl;
#endif
 return 0;
}
```

```
$ g++ -std=c++14 debug.cc -o debug
$ ./debug
Hello, world!
$ g++ -std=c++14 debug.cc -DDEBUG_LEVEL=2 -o debug
```