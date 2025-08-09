#include <clioptions.h>

Options process(int argc, char **argv) {
    Options o;

    for (int i = 0; i < argc; ++i)
        o.commands.emplace_back(argv[i]);

    return o;
}
