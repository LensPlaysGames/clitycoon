#include <cstdio>

struct Persistence {
  long long unsigned int dinero{0};
  long long unsigned int mine_strength{1};
};

// Recieve persistent data.
Persistence initialize();

// Update persistent data with data from given persistence.
bool record(Persistence& p);
