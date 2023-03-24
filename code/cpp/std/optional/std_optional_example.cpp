#include <optional>
#include <iostream>

void print_optional(const std::optional<int>& optional_int)
{
    if (optional_int.has_value())
    {
        std::cout << "The value is " << optional_int.value() << std::endl;
    }
    else
    {
        std::cout << "The value is not set" << std::endl;
    }
}

int main() {
    // Call the function with an optional integer value
    print_optional(42);

    // Call the function with no value
    print_optional(std::nullopt);

    return 0;
}
