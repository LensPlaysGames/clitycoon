#include <clioptions.h>

#include <cstdio>

int main(int argc, char** argv) {
    Options opts = process(argc, argv);

    for (int i = 0; i < opts.commands.size(); ++i)
        printf("%i: %s\n", i, opts.commands.at(i).data());

    return 0;
}
