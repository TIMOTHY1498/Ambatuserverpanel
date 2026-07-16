#include <stdio.h>
#include <sys/sysinfo.h>

long get_storage_usage() {
    struct sysinfo info;

    if (sysinfo(&info) != 0) {
        perror("sysinfo failed");
        return 1;
    }

    unsigned long total_storage = (info.totalram * info.mem_unit) / (1024 * 1024);
    unsigned long free_storage = (info.freeram * info.mem_unit) / (1024 * 1024);
    unsigned long used_storage = total_storage - free_storage;

    // printf("Total System Storage: %lu MB\n", total_storage);
    // printf("Used System Storage:  %lu MB\n", used_storage);
    // printf("Free System Storage:  %lu MB\n", free_storage);

    return used_storage;
}

long get_total_storage() {
    struct sysinfo info;

    if (sysinfo(&info) != 0) {
        perror("sysinfo failed");
        return 1;
    }
    unsigned long total_storage = (info.totalram * info.mem_unit) / (1024 * 1024);
    return total_storage;
}

long get_free_storage() {
    struct sysinfo info;

    if (sysinfo(&info) != 0) {
        perror("sysinfo failed");
        return 1;
    }
    unsigned long free_storage = (info.freeram * info.mem_unit) / (1024 * 1024);
    return free_storage;
}