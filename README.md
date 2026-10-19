# DSA01 Assignment 1

- Name: [fill in]
- Register number: [fill in]
- Repository name: `DSA01-<RegisterNumber>-Assignment1`
- Compiler/version: [fill in after checking locally]
- Build flags: `-std=c++17 -Wall -Wextra -pedantic`

## Contents

- `Assignment_Report_Draft.md`: analysis and write-up for Tasks 1–12; personalize and add your run evidence.
- `FareSystem.h`: shared original fare model.
- `Task04` and `Task05`: output prediction programs.
- `Task06`: completed switch-based fare program.
- `Task07`: procedural/OO comparison.
- `Task08`: safe input retry.
- `Task09`: boundary and fare table cases.
- `Task10`: total scale/range calculation.
- `Task12`: fourth zone, weekend policy and two-zone pass.

## Build and run

From the repository root, compile each source separately, for example:

```sh
g++ -std=c++17 -Wall -Wextra -pedantic Task06/complete_code.cpp -o task06
./task06
```

On Windows PowerShell, run `./task06.exe` after compilation. Repeat for each `.cpp`. Some source files include `../FareSystem.h` and must remain in their task folders.

## Result notes

The source is prepared but has not been compiled in this workspace because no local C++ compiler was detected. Add the actual compiler version, command, terminal output, and screenshots after running. Do not report a test as passed until it has been executed.

## Submission to finish

1. Fill your name, register number and compiler version in this README and report.
2. Confirm the concession amount/eligibility rule with the assessment instructions or faculty; it is not specified in the pasted brief.
3. Compile/run all programs; save input/output evidence in each task folder.
4. Create a GitHub repository with the required exact name, push these files, and share it with faculty.
5. Make at least one authentic commit per task over the work period; a single last-day upload does not meet the brief.
