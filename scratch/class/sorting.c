#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct reports
{
    int counts;
    const char* sickness;
} reports;

int compare(const void* left, const void* right)
{
    const reports* a = (const reports*) left;
    const reports* b = (const reports*) right;

    if (a->counts > b-> counts)
    {
        return -1;
    }

    if (a->counts < b->counts)
    {
        return 1;
    }
    else
    {
        return &right - &left;
        //return 0;
    }
}

int main(int argc, char** argv)
{
    struct reports log[] = {
        {30, "sniffles"},
        {100, "flu"},
        {50, "food poisoning"},
        {70, "heart ache"},
        {70, "fed up"},
        {70, "corona virus"},
        {70, "miller lite virus"},
        {100, "headache"}
    };

    // Get the length of log
    // Option 1: Iterate until null and count
    // Option 2: Divide the ouptut by the size

    int length = sizeof(log) / sizeof(log[0]);

    for (int i = 0; i < length; ++i)
    {
        dprintf(STDERR_FILENO, "%d>>%s\n", log[i].counts, log[i].sickness);
    }

    dprintf(STDERR_FILENO, "----------------------\n");

    qsort(log, length, sizeof(reports), compare);

    for (int i = 0; i < length; ++i)
    {
        dprintf(STDERR_FILENO, "%d>>%s\n", log[i].counts, log[i].sickness);
    }

    exit(EXIT_SUCCESS);
}
