Ever wanted to use RAII but didn't want to create a new struct/class every time?

Now you can!

```cpp
#include <iostream>
#include <defer.hpp>

int main()
{
    // Single function calls can be encapsulated in a DEFER call
    DEFER(printf(", World!"));
    printf("Hello");
}
```

```cpp
#include <iostream>
#include <string>
#include <defer.hpp>

int main()
{
    auto *str = new std::string("World!");
    // Blocks can also be encapsulated in a DEFER call
    DEFER({ delete str; printf("\n"); });
    printf("Hello, %s", str->c_str());
}
```

Dual licensed under MIT and The Unlicense
