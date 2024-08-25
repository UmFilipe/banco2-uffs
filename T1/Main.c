#include <stdio.h>
#include "readFile.h"

int main(int argc, char *argv[]) {
    if (argc > 1) {
        readFile(argv[1]);
        return 0;
    }
    printf("Missing parameter: logical file name\n");
    return 1;
}
