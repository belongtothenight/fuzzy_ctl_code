#include <stdio.h>
#include <stdlib.h>

#include "./error.h"

void print_rc_message(RC rc) {
    switch (rc) {
        case 0:
            printf("Success\n");
            break;
        case RC_NO_INPUTS:
            printf("ERROR: No inputs provided\n");
            break;
        case RC_MAX_INPUTS:
            printf("ERROR: Too many inputs provided\n");
            break;
        case RC_UNKNOWN_OPTION:
            printf("ERROR: Unknown option provided\n");
            break;
        case RC_NO_INPUTS_FILE:
            printf("ERROR: No inputs file provided (-i option)\n");
            break;
        case RC_NO_LIMITS_FILE:
            printf("ERROR: No limits file provided (-l option)\n");
            break;
        case RC_NO_OUTPUT_PATH:
            printf("ERROR: No output path provided (-o option)\n");
            break;
        case RC_WRONG_INPUTS_FILETYPE:
            printf("ERROR: Wrong inputs file type (expecting .csv)\n");
            break;
        case RC_WRONG_LIMITS_FILETYPE:
            printf("ERROR: Wrong limits file type (expecting .csv)\n");
            break;
        default:
            printf("ERROR: Provided unknown return code: %d\n", rc);
            break;
    }
}
