#ifndef ERROR_H
#define ERROR_H

#define EC_NO_INPUTS             0x01 /* No inputs provided */
#define EC_MAX_INPUTS            0x02 /* Too many inputs provided */
#define EC_UNKNOWN_OPTION        0x03 /* Unknown option provided */
#define EC_NO_INPUTS_FILE_OPTION 0x04 /* Doesn't provide -i option */
#define EC_NO_INPUTS_FILE_VALUE  0x05 /* Doesn't provide value for -i option */
#define EC_NO_LIMITS_FILE_OPTION 0x06 /* Doesn't provide -l option */
#define EC_NO_LIMITS_FILE_VALUE  0x07 /* Doesn't provide -l option */
#define EC_NO_OUTPUT_PATH_OPTION 0x08 /* Doesn't provide -o option */
#define EC_NO_OUTPUT_PATH_VALUE  0x09 /* Doesn't provide -o option */
#define EC_WRONG_INPUTS_FILETYPE 0x0a /* Inputs file is not a .csv file */
#define EC_WRONG_LIMITS_FILETYPE 0x0b /* Limits file is not a .csv file */

/*
 * @brief Error codes
 */
typedef int EC;

/*
 * @brief Print error message
 * @param ec Error code
 */
void print_ec_message(int rc);

#endif // ERROR_H
