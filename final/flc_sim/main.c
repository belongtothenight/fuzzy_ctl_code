#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "./error.h"

void printUsage (void) {
    printf("Usage: ./main -i <inputs_file> -l <limits_file> -o <output_path> [-v] [-h]\n");
}

int main(int argc, char *argv[]) {
    RC         rc = 0; /* Return code */
    int        i = 0; /* argc index */
    const char *inputs_file = NULL;
    const char *limits_file = NULL;
    const char *output_path = NULL;
    bool       verbose = false;

    setvbuf(stdout, 0, _IONBF, 0); /* output may be going through pipe to log file */

    /* Check for CLI arguments count */
    if (argc < 2) {
        print_rc_message(RC_NO_INPUTS);
        printUsage();
        return 0;
    } else if (argc > 7) {
        print_rc_message(RC_MAX_INPUTS);
        printUsage();
        return 0;
    }

    /* Parse CLI arguments */
    for (i=1 ; (i<argc) && (rc==0) ; i++) {
        /* Check for argument pairs */
        if (strcmp(argv[i], "-i") == 0) {
            i++;
            if (i < argc) {
                inputs_file = argv[i];
            } else {
                print_rc_message(RC_NO_INPUTS_FILE);
                printUsage();
            }
        } else if (strcmp(argv[i], "-l") == 0) {
            i++;
            if (i < argc) {
                 limits_file = argv[i];
            } else {
                print_rc_message(RC_NO_LIMITS_FILE);
                printUsage();
            }
        } else if (strcmp(argv[i], "-o") == 0) {
            i++;
            if (i < argc) {
                output_path = argv[i];
            } else {
                print_rc_message(RC_NO_OUTPUT_PATH);
                printUsage();
            }
        /* Check for single arguments */
        } else if (strcmp(argv[i], "-v") == 0) {
            verbose = true;
        } else if (strcmp(argv[i], "-h") == 0) {
            printUsage();
            return 0;
        } else {
            print_rc_message(RC_UNKNOWN_OPTION);
            printUsage();
            return 0;
        }
    }

    if (rc == 0) {
        printf("Hello, World!\n");
    }

    return 0;
}
