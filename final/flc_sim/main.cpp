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
    int        t = 0; /* mainloop index, for simulation */
    const char *inputs_file = NULL;
    const char *limits_file = NULL;
    const char *output_path = NULL;
    bool       verbose = false;
    Fuzzy      *fuzzy = new Fuzzy(); /* Instantiating a Fuzzy object */
    float      input = 0;
    float      output = 0;
    int        input_len = 8;
    float      input_arr[] = {0, 0.1, 0.2, 0.3, 0.4, 0.5, 1, 2};

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
        printf("inputs_file: \t%s\n", inputs_file);
        printf("limits_file: \t%s\n", limits_file);
        printf("output_path: \t%s\n", output_path);
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

    /* Parse inputs.csv */

    /* Parse limits.csv */

    /* Initialize Fuzzy object */
    if (ec == 0) {

        // Instantiating a FuzzyInput object
        FuzzyInput *distance = new FuzzyInput(1);
        // Instantiating a FuzzySet object
        FuzzySet *small = new FuzzySet(0, 20, 20, 40);
        // Including the FuzzySet into FuzzyInput
        distance->addFuzzySet(small);
        // Instantiating a FuzzySet object
        FuzzySet *safe = new FuzzySet(30, 50, 50, 70);
        // Including the FuzzySet into FuzzyInput
        distance->addFuzzySet(safe);
        // Instantiating a FuzzySet object
        FuzzySet *big = new FuzzySet(60, 80, 80, 80);
        // Including the FuzzySet into FuzzyInput
        distance->addFuzzySet(big);
        // Including the FuzzyInput into Fuzzy
        fuzzy->addFuzzyInput(distance);

        // Instantiating a FuzzyOutput objects
        FuzzyOutput *speed = new FuzzyOutput(1);
        // Instantiating a FuzzySet object
        FuzzySet *slow = new FuzzySet(0, 10, 10, 20);
        // Including the FuzzySet into FuzzyOutput
        speed->addFuzzySet(slow);
        // Instantiating a FuzzySet object
        FuzzySet *average = new FuzzySet(10, 20, 30, 40);
        // Including the FuzzySet into FuzzyOutput
        speed->addFuzzySet(average);
        // Instantiating a FuzzySet object
        FuzzySet *fast = new FuzzySet(30, 40, 40, 50);
        // Including the FuzzySet into FuzzyOutput
        speed->addFuzzySet(fast);
        // Including the FuzzyOutput into Fuzzy
        fuzzy->addFuzzyOutput(speed);

        // Building FuzzyRule "IF distance = small THEN speed = slow"
        // Instantiating a FuzzyRuleAntecedent objects
        FuzzyRuleAntecedent *ifDistanceSmall = new FuzzyRuleAntecedent();
        // Creating a FuzzyRuleAntecedent with just a single FuzzySet
        ifDistanceSmall->joinSingle(small);
        // Instantiating a FuzzyRuleConsequent objects
        FuzzyRuleConsequent *thenSpeedSlow = new FuzzyRuleConsequent();
        // Including a FuzzySet to this FuzzyRuleConsequent
        thenSpeedSlow->addOutput(slow);
        // Instantiating a FuzzyRule objects
        FuzzyRule *fuzzyRule01 = new FuzzyRule(1, ifDistanceSmall, thenSpeedSlow);
        // Including the FuzzyRule into Fuzzy
        fuzzy->addFuzzyRule(fuzzyRule01);

        // Building FuzzyRule "IF distance = safe THEN speed = average"
        // Instantiating a FuzzyRuleAntecedent objects
        FuzzyRuleAntecedent *ifDistanceSafe = new FuzzyRuleAntecedent();
        // Creating a FuzzyRuleAntecedent with just a single FuzzySet
        ifDistanceSafe->joinSingle(safe);
        // Instantiating a FuzzyRuleConsequent objects
        FuzzyRuleConsequent *thenSpeedAverage = new FuzzyRuleConsequent();
        // Including a FuzzySet to this FuzzyRuleConsequent
        thenSpeedAverage->addOutput(average);
        // Instantiating a FuzzyRule objects
        FuzzyRule *fuzzyRule02 = new FuzzyRule(2, ifDistanceSafe, thenSpeedAverage);
        // Including the FuzzyRule into Fuzzy
        fuzzy->addFuzzyRule(fuzzyRule02);

        // Building FuzzyRule "IF distance = big THEN speed = high"
        // Instantiating a FuzzyRuleAntecedent objects
        FuzzyRuleAntecedent *ifDistanceBig = new FuzzyRuleAntecedent();
        // Creating a FuzzyRuleAntecedent with just a single FuzzySet
        ifDistanceBig->joinSingle(big);
        // Instantiating a FuzzyRuleConsequent objects
        FuzzyRuleConsequent *thenSpeedFast = new FuzzyRuleConsequent();
        // Including a FuzzySet to this FuzzyRuleConsequent
        thenSpeedFast->addOutput(fast);
        // Instantiating a FuzzyRule objects
        FuzzyRule *fuzzyRule03 = new FuzzyRule(3, ifDistanceBig, thenSpeedFast);
        // Including the FuzzyRule into Fuzzy
        fuzzy->addFuzzyRule(fuzzyRule03);

        if (verbose) {
            printf("STEP04 Fuzzy object initialized\n");
        }
    }

    /* Main loop */
    for (t=0 ; (t<input_len) && (ec==0) ; t++) {
        /* input modifying */
        input = input_arr[t];
        /* close loop value */
        /* fuzzify and defuzzify */
        if (ec == 0) {
            fuzzy->setInput(1, input);
            fuzzy->fuzzify();
            output = fuzzy->defuzzify(1);
            printf("Entrance: \tDistance: %f \tResult: \tSpeed: %f\n", input, output);
        }
        /* controlling */
        /* storing output */
        /* update plot */
    }

    /* Error handling */
    if (ec != 0) {
        printf("%s: failed, ec 0x%02x\n", argv[0], ec);
        print_ec_message(ec);
        printUsage();
    }
    return 0;
}
