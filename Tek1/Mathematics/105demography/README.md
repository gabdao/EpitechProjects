# 105demography

## Description
Population analysis and prediction program using linear regression on demographic data. The program processes country population data from 1960 onwards to establish linear regression models and predict future population growth.

## Objective
Implement a `105demography` program that must:
- Read population data from CSV file (105demography_data.csv)
- Perform linear least squares regression analysis on selected countries
- Calculate two different linear fits and their statistical measures
- Predict population for the year 2050 using both regression models

### Regression Analysis
The program computes two linear regression models:

**Fit 1: Y = aₓX + bₓ** (Population as function of Year)
- Linear coefficients aₓ and bₓ
- Root-mean-square deviation
- Population prediction for 2050

**Fit 2: X = aᵧY + bᵧ** (Year as function of Population)  
- Linear coefficients aᵧ and bᵧ
- Root-mean-square deviation
- Population prediction for 2050 (inverse calculation)

**Additional Statistics:**
- Correlation coefficient between X (year) and Y (population)

### Parameters
- `[code]+`: One or more country codes to analyze

### Usage
```bash
./105demography [code]+
```

## Constraints
- Language: Python
- Compilation via Makefile with `re`, `clean`, `fclean` rules
- Error code 84 on error, 0 otherwise
- Manual implementation required - regression/statistical libraries prohibited
- Must work with provided CSV data file (105demography_data.csv)
- Population values in millions of people
