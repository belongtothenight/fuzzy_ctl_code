#ifndef ERROR_H
#define ERROR_H

#define RC_NO_INPUTS             0x01 /* No inputs provided */
#define RC_MAX_INPUTS            0x02 /* Too many inputs provided */
#define RC_UNKNOWN_OPTION        0x03 /* Unknown option provided */
#define RC_NO_INPUTS_FILE_OPTION 0x04 /* Doesn't provide -i option */
#define RC_NO_INPUTS_FILE_VALUE  0x05 /* Doesn't provide value for -i option */
#define RC_NO_LIMITS_FILE_OPTION 0x06 /* Doesn't provide -l option */
#define RC_NO_LIMITS_FILE_VALUE  0x07 /* Doesn't provide -l option */
#define RC_NO_OUTPUT_PATH_OPTION 0x08 /* Doesn't provide -o option */
#define RC_NO_OUTPUT_PATH_VALUE  0x09 /* Doesn't provide -o option */
#define RC_WRONG_INPUTS_FILETYPE 0x0a /* Inputs file is not a .csv file */
#define RC_WRONG_LIMITS_FILETYPE 0x0b /* Limits file is not a .csv file */

/*
 * @brief Error codes
 */
typedef int RC;

/*
 * @brief Print error message
 * @param rc Error code
 */
void print_rc_message(int rc);

#endif // ERROR_H
