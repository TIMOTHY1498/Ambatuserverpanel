#include <stdio.h>
#include <sys/statfs.h>

long get_storage_usage() {
    struct statfs info;

    if (statfs("/", &info) != 0) {
        perror("statfs failed");
        return 1;
    }

    unsigned long total_storage = (info.f_blocks * info.f_bsize) / (1024 * 1024);
    unsigned long free_storage = (info.f_bfree * info.f_bsize) / (1024 * 1024);
    unsigned long used_storage = total_storage - free_storage;

    // printf("Total System Storage: %lu MB\n", total_storage);
    // printf("Used System Storage:  %lu MB\n", used_storage);
    // printf("Free System Storage:  %lu MB\n", free_storage);

    return used_storage;
}

long get_total_storage() {
    struct statfs info;

    if (statfs("/", &info) != 0) {
        perror("statfs failed");
        return 1;
    }
    unsigned long total_storage = (info.f_blocks * info.f_bsize) / (1024 * 1024);
    return total_storage;
}

long get_free_storage() {
    struct statfs info;

    if (statfs("/", &info) != 0) {
        perror("statfs failed");
        return 1;
    }
    unsigned long free_storage = (info.f_bfree * info.f_bsize) / (1024 * 1024);
    return free_storage;
}