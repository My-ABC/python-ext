# Python extension

[中文文档](README-zh.md) | [English Document](README.md)

## 1. Introduction

This project is an example of writing Python extensions in C  . A simple Python extension is implemented in C   that can the sum of two numbers.

## 2. Compilation

To compile the Python extension, execute the following command in the root of the project:

```bash
pip install .
```

## 3. Usage
```python
from test import test
print(test.add(1, 2))  # Prints 3
# print(test.add()) #rows a test.ArgsError exception
```
or
```bash
python -m test
```
Enter first number: 1

Enter second number: 2

The sum of 1 and 2 is: 3