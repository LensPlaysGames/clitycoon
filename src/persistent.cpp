#include <bits/types/FILE.h>
#include <persistent.h>

Persistence initialize() {
    Persistence p;

    // LOAD

    FILE* f = fopen("persistent.dat", "rb");
    // NOTE: No persistent data recorded, or a filesystem failure.
    if (not f) return p;

    fread(&p, sizeof(Persistence), 1, f);

    fclose(f);

    // VERIFY

    // Mine strength cannot be zero, otherwise the game couldn't go on (and
    // divide by zero errors when displaying mines left for upgrade).
    if (p.mine_strength == 0) p.mine_strength = 1;

    return p;
}

bool record(Persistence &p) {
    // NOTE: Could backup old persistent data, if it exists.

    FILE* f = fopen("persistent.dat", "wb");
    if (not f) return false;

    fwrite(&p, sizeof(Persistence), 1, f);

    fclose(f);
    return true;
}
