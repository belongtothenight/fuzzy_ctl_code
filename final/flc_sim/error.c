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
        case RC_NO_INPUTS_FILE_OPTION:
            printf("ERROR: No inputs file option provided (-i option)\n");
            break;
        case RC_NO_INPUTS_FILE_VALUE:
            printf("ERROR: No inputs file value provided (-i option)\n");
            break;
        case RC_NO_LIMITS_FILE_OPTION:
            printf("ERROR: No limits file option provided (-l option)\n");
            break;
        case RC_NO_LIMITS_FILE_VALUE:
            printf("ERROR: No limits file value provided (-l option)\n");
            break;
        case RC_NO_OUTPUT_PATH_OPTION:
            printf("ERROR: No output path option provided (-o option)\n");
            break;
        case RC_NO_OUTPUT_PATH_VALUE:
            printf("ERROR: No output path value provided (-o option)\n");
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
