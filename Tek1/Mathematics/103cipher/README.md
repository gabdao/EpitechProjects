# 103cipher

## Description

Matrix-based cryptography program implementing the Hill cipher encryption and decryption system. The program uses matrix multiplication to encrypt and decrypt messages based on ASCII character conversion.

## Objective

Implement a `103cipher` program that must:
- Encrypt and decrypt messages using matrix-based Hill cipher
- Convert text to ASCII numbers and organize into matrices
- Perform matrix multiplication for encryption/decryption
- Handle matrix inversion for decryption process

### Encryption Process

1. Convert key to ASCII numbers
2. Create smallest possible square matrix from key (fill by rows)
3. Convert message to ASCII numbers
4. Create message matrix with columns matching key matrix size
5. Multiply matrices and output result linearly

### Decryption Process

1. Use inverse of the key matrix
2. Apply same matrix multiplication process
3. Convert result back to ASCII characters

### Parameters

- `message`: ASCII message to encrypt/decrypt
- `key`: ASCII encryption key
- `flag`: 0 for encryption, 1 for decryption

## Constraints
- Error code 84 on error, 0 otherwise
- Matrix calculus libraries (like numpy) prohibited
- Zero padding used to fit proper matrix sizes
- Matrix inversion for sizes >3x3 considered bonus
