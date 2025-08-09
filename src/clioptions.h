#include <vector>
#include <string_view>

struct Options {
    std::vector<std::string_view> commands;
};

Options process(int argc, char** argv);
