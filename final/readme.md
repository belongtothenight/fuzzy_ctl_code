# Development Environment Setup Steps

This project is to create a GUI for parameter tuning of Fuzzy Logic Controllers (FLC).

Use standard format to receive input, output, logic and rules. Export eFLL code to generate result and display it in GUI, lastly, export the params to c code format.

## Dependencies

1. Debian based Linux
2. [alvesoaj/eFLL](https://github.com/alvesoaj/eFLL/tree/master)
    1. [google/googletest](https://github.com/google/googletest/tree/main/googletest)

## Steps

1. Adjust parameters in ```./setup.sh``` to your need.
2. Execute ```bash ./setup.sh```.

## References

1. https://gist.github.com/Cartexius/4c437c084d6e388288201aadf9c8cdd5?permalink_comment_id=4757070#gistcomment-4757070
2. https://github.com/rorotsai/grad/tree/main/src/logic_test
