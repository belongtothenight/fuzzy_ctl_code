# Development Environment Setup Steps

This project is to create a GUI for parameter tuning of Fuzzy Logic Controllers (FLC).

Use standard format to receive input, output, logic and rules. Use eFFL to run simulation to see whether it will go out of spec.

## Dependencies

1. Debian based Linux
2. [alvesoaj/eFLL](https://github.com/alvesoaj/eFLL/tree/master)
    1. [google/googletest](https://github.com/google/googletest/tree/main/googletest)

## Steps

1. Adjust parameters in ```./setup.sh``` to your need.
2. Execute ```bash ./setup.sh```.

## Usage

```bash
$ ./flc_sim -h
./flc_sim [-i INPUT SIMULATION RANGE in CSV] [-l OUTPUT LIMITS in CSV] [-o OUTPUT SIMULATION DATA FILEPATH]
$ ./flc_sim -i inputs.csv -l limits.csv -o output.csv
```

inputs.csv
```csv
i1,i2
0  ,1
0.1,1
0.2,1
0.3,1
0.4,1
0.5,1
0.6,1
0.7,1
0.8,1
0.9,1
1  ,1
```

limits.csv
```csv
not finished
```

## Compilation Commands

Windows PowerShell7
```powershell
make clean_win; make; .\flc_sim.exe -i input.csv -l limits.csv -o . -v
```

Linux Bash
```bash
make clean; make; ./flc_sim -i input.csv -l limits.csv -o . -v
```

## References

1. https://gist.github.com/Cartexius/4c437c084d6e388288201aadf9c8cdd5?permalink_comment_id=4757070#gistcomment-4757070
2. https://github.com/rorotsai/grad/tree/main/src/logic_test
