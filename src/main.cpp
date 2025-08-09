#include <clioptions.h>
#include <persistent.h>

#include <cstdio>

/// Calculate dinero cost of mine strength upgrade
long long unsigned int upgrade_cost(long long unsigned int mine_strength) {
    // This means that whatever the mine strength is is how many 'mine'
    // commands it will take to afford the upgrade.
    return mine_strength * mine_strength;
}

void perform_mine(Persistence& data) {
    printf("clitycoon: MINING...\n");
    data.dinero += data.mine_strength;
    printf("clitycoon: DINERO %llu\n", data.dinero);
}

void perform_upgrade(Persistence &data) {
    auto cost = upgrade_cost(data.mine_strength);
    printf("clitycoon: UPGRADING...\n");
    data.mine_strength += 1;
    data.dinero -= cost;
    printf("clitycoon: -%llu DINERO\n", cost);
    printf("clitycoon: DINERO %llu\n", data.dinero);
    printf("clitycoon: MINE STRENGTH %llu\n", data.mine_strength);
    printf("clitycoon: NEXT UPGRADE COST %llu\n", upgrade_cost(data.mine_strength));
}

int main(int argc, char** argv) {
    Options opts = process(argc, argv);
    // for (int i = 0; i < opts.commands.size(); ++i)
    //     printf("%i: %s\n", i, opts.commands.at(i).data());

    Persistence data = initialize();
    printf("clitycoon: DINERO %llu\n", data.dinero);

    if (opts.commands.size() <= 1) {
        printf("clitycoon: NO ARGUMENTS GIVEN, EXITING WITH NO ACTION TAKEN\n");
        printf("clitycoon: TRY SIMPLE COMMANDS: mine, upgrade\n");
        return 0;
    }

    if (opts.commands.size() == 2) {
        std::string_view simple_command = opts.commands.at(1);

        if (simple_command == "mine") {
            perform_mine(data);
        } else if (simple_command == "upgrade") {
            long long unsigned int cost = upgrade_cost(data.mine_strength);
            if (data.dinero >= cost) {
                perform_upgrade(data);
            } else {
                printf("clitycoon: CANNOT PERFORM UPGRADE (insufficient funds)...\n");
                printf("clitycoon: CURRENT MINE STRENGTH %llu\n", data.mine_strength);
                printf("clitycoon: COST OF UPGRADE %llu\n", cost);
                printf("clitycoon: +%llu necessary for upgrade (%llu mines)\n", cost - data.dinero, cost / data.mine_strength);
                return 0;
            }
        } else {
            printf("clitycoon: '%s' IS NOT A SIMPLE COMMAND, EXITING WITH NO ACTION TAKEN\n", simple_command.data());
            return 0;
        }
    }

    record(data);

    return 0;
}
