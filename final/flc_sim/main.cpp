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

      Fuzzy *fuzzy = new Fuzzy();

  // FuzzyInput
  FuzzyInput *distance = new FuzzyInput(1);

  FuzzySet *near = new FuzzySet(0, 20, 20, 40);
  distance->addFuzzySet(near);
  FuzzySet *safe = new FuzzySet(30, 50, 50, 70);
  distance->addFuzzySet(safe);
  FuzzySet *distant = new FuzzySet(60, 80, 100, 100);
  distance->addFuzzySet(distant);

  fuzzy->addFuzzyInput(distance);

  // FuzzyInput
  FuzzyInput *inputSpeed = new FuzzyInput(2);

  FuzzySet *stopedInput = new FuzzySet(0, 0, 0, 0);
  inputSpeed->addFuzzySet(stopedInput);
  FuzzySet *slowInput = new FuzzySet(1, 10, 10, 20);
  inputSpeed->addFuzzySet(slowInput);
  FuzzySet *normalInput = new FuzzySet(15, 30, 30, 50);
  inputSpeed->addFuzzySet(normalInput);
  FuzzySet *quickInput = new FuzzySet(45, 60, 70, 70);
  inputSpeed->addFuzzySet(quickInput);

  fuzzy->addFuzzyInput(inputSpeed);

  // FuzzyInput
  FuzzyInput *temperature = new FuzzyInput(3);

  FuzzySet *cold = new FuzzySet(-30, -30, -20, -10);
  temperature->addFuzzySet(cold);
  FuzzySet *good = new FuzzySet(-15, 0, 0, 15);
  temperature->addFuzzySet(good);
  FuzzySet *hot = new FuzzySet(10, 20, 30, 30);
  temperature->addFuzzySet(hot);

  fuzzy->addFuzzyInput(temperature);

  // FuzzyOutput
  FuzzyOutput *risk = new FuzzyOutput(1);

  FuzzySet *minimum = new FuzzySet(0, 20, 20, 40);
  risk->addFuzzySet(minimum);
  FuzzySet *average = new FuzzySet(30, 50, 50, 70);
  risk->addFuzzySet(average);
  FuzzySet *maximum = new FuzzySet(60, 80, 80, 100);
  risk->addFuzzySet(maximum);

  fuzzy->addFuzzyOutput(risk);

  // FuzzyOutput
  FuzzyOutput *speedOutput = new FuzzyOutput(2);

  FuzzySet *stopedOutput = new FuzzySet(0, 0, 0, 0);
  speedOutput->addFuzzySet(stopedOutput);
  FuzzySet *slowOutput = new FuzzySet(1, 10, 10, 20);
  speedOutput->addFuzzySet(slowOutput);
  FuzzySet *normalOutput = new FuzzySet(15, 30, 30, 50);
  speedOutput->addFuzzySet(normalOutput);
  FuzzySet *quickOutput = new FuzzySet(45, 60, 70, 70);
  speedOutput->addFuzzySet(quickOutput);

  fuzzy->addFuzzyOutput(speedOutput);

  // Building FuzzyRule
  FuzzyRuleAntecedent *distanceCloseAndSpeedQuick = new FuzzyRuleAntecedent();
  distanceCloseAndSpeedQuick->joinWithAND(near, quickInput);
  FuzzyRuleAntecedent *temperatureCold = new FuzzyRuleAntecedent();
  temperatureCold->joinSingle(cold);
  FuzzyRuleAntecedent *ifDistanceCloseAndSpeedQuickOrTemperatureCold = new FuzzyRuleAntecedent();
  ifDistanceCloseAndSpeedQuickOrTemperatureCold->joinWithOR(distanceCloseAndSpeedQuick, temperatureCold);

  FuzzyRuleConsequent *thenRisMaximumAndSpeedSlow = new FuzzyRuleConsequent();
  thenRisMaximumAndSpeedSlow->addOutput(maximum);
  thenRisMaximumAndSpeedSlow->addOutput(slowOutput);

  FuzzyRule *fuzzyRule1 = new FuzzyRule(1, ifDistanceCloseAndSpeedQuickOrTemperatureCold, thenRisMaximumAndSpeedSlow);
  fuzzy->addFuzzyRule(fuzzyRule1);

  // Building FuzzyRule
  FuzzyRuleAntecedent *distanceSafeAndSpeedNormal = new FuzzyRuleAntecedent();
  distanceSafeAndSpeedNormal->joinWithAND(safe, normalInput);
  FuzzyRuleAntecedent *ifDistanceSafeAndSpeedNormalOrTemperatureGood = new FuzzyRuleAntecedent();
  ifDistanceSafeAndSpeedNormalOrTemperatureGood->joinWithOR(distanceSafeAndSpeedNormal, good);

  FuzzyRuleConsequent *thenRiskAverageAndSpeedNormal = new FuzzyRuleConsequent();
  thenRiskAverageAndSpeedNormal->addOutput(average);
  thenRiskAverageAndSpeedNormal->addOutput(normalOutput);

  FuzzyRule *fuzzyRule2 = new FuzzyRule(2, ifDistanceSafeAndSpeedNormalOrTemperatureGood, thenRiskAverageAndSpeedNormal);
  fuzzy->addFuzzyRule(fuzzyRule2);

  // Building FuzzyRule
  FuzzyRuleAntecedent *distanceDistantAndSpeedSlow = new FuzzyRuleAntecedent();
  distanceDistantAndSpeedSlow->joinWithAND(distant, slowInput);
  FuzzyRuleAntecedent *ifDistanceDistantAndSpeedSlowOrTemperatureHot = new FuzzyRuleAntecedent();
  ifDistanceDistantAndSpeedSlowOrTemperatureHot->joinWithOR(distanceDistantAndSpeedSlow, hot);

  FuzzyRuleConsequent *thenRiskMinimumSpeedQuick = new FuzzyRuleConsequent();
  thenRiskMinimumSpeedQuick->addOutput(minimum);
  thenRiskMinimumSpeedQuick->addOutput(quickOutput);

  FuzzyRule *fuzzyRule3 = new FuzzyRule(3, ifDistanceDistantAndSpeedSlowOrTemperatureHot, thenRiskMinimumSpeedQuick);
  fuzzy->addFuzzyRule(fuzzyRule3);

  float distanceValue = 30;
  float speedValue = 40;
  float temperatureValue = 0;
  printf("Entrance: \nDistance: %f\nSpeed: %f\nTemperature: %f\n", distanceValue, speedValue, temperatureValue);
  fuzzy->setInput(1, distanceValue);
  fuzzy->setInput(2, speedValue);
  fuzzy->setInput(3, temperatureValue);
  float output1 = fuzzy->defuzzify(1);
  float output2 = fuzzy->defuzzify(2);
  printf("Exit: \nRisk: %f\nSpeed: %f\n", output1, output2);

    return 0;
}
