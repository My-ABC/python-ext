# python extension

[中文文档](README-zh.md) | [English Document](README.md)

## 1. 介绍

本项目是使用C++编写Python扩展的示例，通过C++实现一个简单的Python扩展，该扩展可以计算两个数的和。

## 2. 编译

在项目根目录下执行以下命令编译Python扩展：

```bash
pip install .
```

## 3. 使用
```python
from test import test
print(test.add(1, 2))  # 输出 3
# print(test.add()) # 抛出test.ArgsError异常
```
或
```bash
python -m test
```
Enter first number: 1

Enter second number: 2

The sum of 1 and 2 is: 3