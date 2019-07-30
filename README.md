Ever wanted to use RAII but didn't want to create a new struct/class every time?

Now you can!

```cpp
#include <iostream>
#include <string>
#include <defer.hpp>

int main
{
    auto *str = new std::string("World!");
    DEFER({ delete str; printf("\n"); })
    printf("Hello, %s", str->c_str());
}
```

Dual licensed under MIT and The Unlicense