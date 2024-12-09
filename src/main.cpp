#include <iostream>

int main(int argc, char **argv) __attribute__((weak));

int main([[maybe_unused]] int argc, [[maybe_unused]] char **argv)
{
    std::cout << "Hello world" << std::endl;
    return 0;
}