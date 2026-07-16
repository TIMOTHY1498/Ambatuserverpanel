#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct {
    unsigned long long user;
    unsigned long long nice;
    unsigned long long system;
    unsigned long long idle;
    unsigned long long iowait;
    unsigned long long irq;
    unsigned long long softirq;
    unsigned long long steal;
} CPU_Stats;

int get_cpu_stats(CPU_Stats *stats) {
    FILE *fp = fopen("/proc/stat", "r");
    if (!fp) {
        perror("Error opening /proc/stat");
        return -1;
    }

    char buffer[256];
    if (fgets(buffer, sizeof(buffer), fp)) {
        int parsed = sscanf(buffer, "cpu  %llu %llu %llu %llu %llu %llu %llu %llu",
                            &stats->user, &stats->nice, &stats->system,
                            &stats->idle, &stats->iowait, &stats->irq,
                            &stats->softirq, &stats->steal);
        if (parsed < 8) {
            fclose(fp);
            return -1;
        }
    }
    fclose(fp);
    return 0;
}

double get_cpu_usage() {
    CPU_Stats s1, s2;
    if (get_cpu_stats(&s1) != 0) return 0.0;
    sleep(1);
    if (get_cpu_stats(&s2) != 0) return 0.0;

    unsigned long long s1_idle = s1.idle + s1.iowait;
    unsigned long long s2_idle = s2.idle + s2.iowait;

    unsigned long long s1_total = s1.user + s1.nice + s1.system + s1.idle +
                                  s1.iowait + s1.irq + s1.softirq + s1.steal;
                                  
    unsigned long long s2_total = s2.user + s2.nice + s2.system + s2.idle +
                                  s2.iowait + s2.irq + s2.softirq + s2.steal;
    unsigned long long delta_total = s2_total - s1_total;
    unsigned long long delta_idle = s2_idle - s1_idle;

    if (delta_total == 0) {
        printf("CPU Usage: 0.00%%\n");
        return 0.0;
    }

    double cpu_usage = ((double)(delta_total - delta_idle) / delta_total) * 100.0;

    printf("Total System CPU Usage: %.2f%%\n", cpu_usage);
    return cpu_usage;
}
