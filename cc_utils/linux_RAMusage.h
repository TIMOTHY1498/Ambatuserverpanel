#include <stdio.h>
#include <sys/sysinfo.h>

long get_mem_usage() {
    struct sysinfo info;

    if (sysinfo(&info) != 0) {
        perror("sysinfo failed");
        return 1;
    }
    unsigned long total_ram = (info.totalram * info.mem_unit) / (1024 * 1024);
    unsigned long free_ram = (info.freeram * info.mem_unit) / (1024 * 1024);
    unsigned long used_ram = total_ram - free_ram;

    // printf("Total System RAM: %lu MB\n", total_ram);
    // printf("Used System RAM:  %lu MB\n", used_ram);
    // printf("Free System RAM:  %lu MB\n", free_ram);

    return used_ram;
}

long get_total_mem() {
    struct sysinfo info;

    if (sysinfo(&info) != 0) {
        perror("sysinfo failed");
        return 1;
    }
    unsigned long total_ram = (info.totalram * info.mem_unit) / (1024 * 1024);
    return total_ram;
}

long get_free_mem() {
    struct sysinfo info;

    if (sysinfo(&info) != 0) {
        perror("sysinfo failed");
        return 1;
    }
    unsigned long free_ram = (info.freeram * info.mem_unit) / (1024 * 1024);
    return free_ram;
}