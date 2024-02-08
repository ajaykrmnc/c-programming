// dynamic_linking_example.c
#include <stdio.h>
#include <dlfcn.h>

int main() {
    // Load the shared library dynamically
    void* handle = dlopen("./dynamic_linked_library.so", RTLD_LAZY);

    if (!handle) {
        fprintf(stderr, "Error: %s\n", dlerror());
        return 1;
    }

    // Get a function pointer from the loaded library
    void (*dynamic_linked_function)() = dlsym(handle, "dynamic_linked_function");

    if (!dynamic_linked_function) {
        fprintf(stderr, "Error: %s\n", dlerror());
        dlclose(handle);
        return 1;
    }

    // Call the function
    dynamic_linked_function();

    // Unload the shared library
    dlclose(handle);

    return 0;
}
