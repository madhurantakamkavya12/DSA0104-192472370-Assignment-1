# DSA0104 Assignment 1 — Namma Metro Fare System

- **Name:** [fill in your full name]
- **Register number:** 192472370
- **GitHub repository:** [DSA0104-192472370-Assignment-1](https://github.com/madhurantakamkavya12/DSA0104-192472370-Assignment-1)
- **Compiler:** g++ 16.2.0 (MSYS2 UCRT64)
- **Compile flags:** `-std=c++17 -Wall -Wextra -pedantic`
- **Compile pattern:** `g++ -std=c++17 -Wall -Wextra -pedantic TaskXX/file.cpp -o taskXX.exe`
- **Run pattern in MSYS2 UCRT64:** `./taskXX.exe`

## Repository contents

- `Assignment_Report_Draft.md` — analysis, pseudocode, UML, complexity comparisons, predictions, and observed results for Tasks 1–12.
- `FareSystem.h` — shared original three-zone fare logic and protected smart-card balance.
- `Task01/analysis.md`, `Task02/analysis.md`, and `Task11/analysis.md` — task-specific analysis. These tasks do not ask for executable output screenshots.
- `Task03`–`Task10` and `Task12` — source programs and terminal execution screenshots in `execution.png`.
- `.gitignore` — excludes local `.exe` build outputs.

## How to build and run

Run these commands from the repository root in **MSYS2 UCRT64**. Each source is a separate program:

```bash
g++ -std=c++17 -Wall -Wextra -pedantic Task03/precision_demo.cpp -o task03.exe && ./task03.exe
g++ -std=c++17 -Wall -Wextra -pedantic Task04/predict_conversions.cpp -o task04.exe && ./task04.exe
g++ -std=c++17 -Wall -Wextra -pedantic Task05/predict_operators.cpp -o task05.exe && ./task05.exe
g++ -std=c++17 -Wall -Wextra -pedantic Task06/complete_code.cpp -o task06.exe && ./task06.exe
g++ -std=c++17 -Wall -Wextra -pedantic Task07/two_styles.cpp -o task07.exe && ./task07.exe
g++ -std=c++17 -Wall -Wextra -pedantic Task08/safe_input.cpp -o task08.exe && ./task08.exe
g++ -std=c++17 -Wall -Wextra -pedantic Task09/test_fares.cpp -o task09.exe && ./task09.exe
g++ -std=c++17 -Wall -Wextra -pedantic Task10/totals.cpp -o task10.exe && ./task10.exe
g++ -std=c++17 -Wall -Wextra -pedantic Task12/design_challenge.cpp -o task12.exe && ./task12.exe
```

For Task 8, run the program and enter `abc`, then `9`, to demonstrate recovery from invalid input. Task 6, 7, 8, 9, 10, and 12 were compiled with the flags above. The observed Task 4 warning was `-Wsign-compare`, caused by comparing `int` with `unsigned int`; it is explained in the report.

## Result notes

- **Task 1:** Identified the card, passenger, journey, zone, and fare-table responsibilities; documented invariants, OOP principles, and a conceptual UML class diagram.
- **Task 2:** Explained token categories, identifier conventions, `constexpr`, and `enum class` choices.
- **Task 3:** Measured sizes `1, 1, 4, 8, 4, 8` bytes for `bool`, `char`, `int`, `long long`, `float`, and `double`; demonstrated the repeated-`0.1` floating-point difference.
- **Task 4:** Observed `3 3.5`, `C 68`, `1 true`, `s >= u`; g++ emitted `-Wsign-compare`.
- **Task 5:** All five observed lines matched the predicted operator results.
- **Task 6:** Rs 10 and Rs 36 fares were deducted; the last trip was denied and balance stayed Rs 54.
- **Task 7:** Procedural and object-oriented versions both ended at Rs 64.
- **Task 8:** Invalid `abc` input was rejected; hour 9 was accepted as peak.
- **Task 9:** Ten fare and balance cases matched; unknown zone was rejected; negative recharge was refused; five-trip total was Rs 110.
- **Task 10:** 6,000,000,000 paise exceeds `INT_MAX`; the measured double totals matched for these whole-rupee examples.
- **Task 11:** Recommended a centralized fare policy with exact paise and an encapsulated card balance.
- **Task 12:** Observed Airport weekday peak 7200 paise, Airport weekend 5400 paise, uncovered Middle 2400 paise, and pass-covered Inner 0 paise.

## Finish before submission

1. Replace `[fill in your full name]` here and in the report.
2. Confirm the student/senior concession amount and eligibility with your instructor. The pasted brief mentions a concession but does not specify its value or rule; document the confirmed rule or explicitly record the assumption if no further detail is available.
3. Confirm the screenshots and updated report appear on GitHub, then submit the repository link and report through the course portal.
