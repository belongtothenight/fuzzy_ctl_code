#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "./error.h"

#include "../../../eFLL/fuzzy.h"

void printUsage (void) {
    printf("Usage: ./main -i <inputs_file> -l <limits_file> -o <output_path> [-v] [-h]\n");
    printf("  -i <inputs_file>   : Path to the inputs file\n");
    printf("  -l <limits_file>   : Path to the limits file\n");
    printf("  -o <output_path>   : Path to the output directory\n");
    printf("  -v                 : Verbose mode\n");
    printf("  -h                 : Print this help message\n");
}

int main(int argc, char *argv[]) {
    EC         ec = 0; /* Error code (handling library error) */
    //int        rc = 0; /* Return code */
    int        i = 0; /* argc index */
    const char *inputs_file = NULL;
    const char *limits_file = NULL;
    const char *output_path = NULL;
    bool       verbose = false;

    setvbuf(stdout, 0, _IONBF, 0); /* output may be going through pipe to log file */

    /* Check for CLI arguments count */
    if (argc < 2) {
        print_ec_message(EC_NO_INPUTS);
        printUsage();
        return 0;
    } else if (argc > 8) {
        print_ec_message(EC_MAX_INPUTS);
        printUsage();
        return 0;
    }

    /* Parse CLI arguments */
    for (i=1 ; (i<argc) && (ec==0) ; i++) {
        /* Check for argument pairs */
        if (strcmp(argv[i], "-i") == 0) {
            i++;
            if (i < argc) {
                inputs_file = argv[i];
            } else {
                ec = EC_NO_INPUTS_FILE_VALUE;
            }
        } else if (strcmp(argv[i], "-l") == 0) {
            i++;
            if (i < argc) {
                 limits_file = argv[i];
            } else {
                ec = EC_NO_LIMITS_FILE_VALUE;
            }
        } else if (strcmp(argv[i], "-o") == 0) {
            i++;
            if (i < argc) {
                output_path = argv[i];
            } else {
                ec = EC_NO_OUTPUT_PATH_VALUE;
            }
        /* Check for single arguments */
        } else if (strcmp(argv[i], "-v") == 0) {
            verbose = true;
        } else if (strcmp(argv[i], "-h") == 0) {
            printUsage();
            return 0;
        } else {
            ec = EC_UNKNOWN_OPTION;
        }
    }
    if (verbose) {
        printf("STEP01 Parsed CLI arguments:\n");
        printf("inputs_file: %s\n", inputs_file);
        printf("limits_file: %s\n", limits_file);
        printf("output_path: %s\n", output_path);
    }

    /* Check for required arguments */
    if (ec == 0) {
        if (inputs_file == NULL) {
            ec = EC_NO_INPUTS_FILE_OPTION;
        } else if (limits_file == NULL) {
            ec = EC_NO_LIMITS_FILE_OPTION;
        } else if (output_path == NULL) {
            ec = EC_NO_OUTPUT_PATH_OPTION;
        }
        if (verbose) {
            printf("STEP02 Checked for required arguments\n");
        }
    }

    /* Check for file types */
    if (ec == 0) {
        if (strstr(inputs_file, ".csv") == NULL) {
            ec = EC_WRONG_INPUTS_FILETYPE;
        } else if (strstr(limits_file, ".csv") == NULL) {
            ec = EC_WRONG_LIMITS_FILETYPE;
        }
        if (verbose) {
            printf("STEP03 Checked for file types\n");
        }
    }

    if (ec == 0) {
        printf("Hello, World!\n");
    }

    /* Error handling */
    if (ec != 0) {
        printf("%s: failed, ec 0x%02x\n", argv[0], ec);
        print_ec_message(ec);
        printUsage();
    }

    return 0;
}
