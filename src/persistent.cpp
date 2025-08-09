#include <bits/types/FILE.h>
#include <persistent.h>

Persistence initialize() {
    Persistence p;

    FILE* f = fopen("persistent.dat", "rb");
    // NOTE: No persistent data recorded, or a filesystem failure.
    if (not f) return p;

    fread(&p, sizeof(Persistence), 1, f);

    fclose(f);

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
