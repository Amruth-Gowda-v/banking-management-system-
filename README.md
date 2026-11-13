# Banking Management System in C

A menu-driven console program written in C that demonstrates basic bank-account record operations using structures, arrays, and file handling.

## Features visible in the source

- Create an account
- Display all accounts
- Search for an account
- Deposit money
- Withdraw money
- Transfer money between accounts
- Update account details
- Delete an account
- Save account data to a file
- Load account data from a file

Each in-memory account stores a name, account number, phone number, and balance.

## Requirements

- A C compiler such as GCC
- A terminal or command prompt

## Compile

```bash
gcc bms.c -o banking_management
```

## Run

On Linux or macOS:

```bash
./banking_management
```

On Windows:

```powershell
banking_management.exe
```

## Data storage

The program uses a local file named `bank.txt` for saving and loading account records. Run it from a directory where it can create and access this file.

## Important limitation

This is an educational console project, not real banking software. It has no authentication, encryption, database transaction guarantees, audit trail, or production-grade input validation. Do not use it to store real financial or personal information.
