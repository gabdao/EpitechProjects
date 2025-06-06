# 104neutrinos

## Description
Real-time statistical analysis program for neutrino particle physics research. The program maintains and updates statistical measures (arithmetic mean, harmonic mean, standard deviation, and root mean square) as new particle speed measurements are added to an existing dataset.

## Objective
Implement a `104neutrinos` program that must:
- Take initial dataset statistics as input parameters
- Accept new particle speed values in real-time via standard input
- Dynamically update and display all statistical measures after each new value
- Continue processing until "END" keyword is entered

### Statistical Measures Computed
1. **Arithmetic Mean**: Standard average of all values
2. **Standard Deviation**: Measure of data spread around the mean
3. **Root Mean Square**: Average speed for equivalent total kinetic energy (√(Σv²/n))
4. **Harmonic Mean**: Reciprocal of arithmetic mean of reciprocals

### Parameters
- `n`: Initial number of recorded values
- `a`: Initial arithmetic mean
- `h`: Initial harmonic mean  
- `sd`: Initial standard deviation
