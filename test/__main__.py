from test import test  # 导入编译后的 C 扩展模块

# 从用户输入中获取两个整数
a = int(input("Enter first number: "))
b = int(input("Enter second number: "))

# 调用 C 扩展模块中的 add 函数
result = test.add(a, b)

# 输出结果
print(f"The sum of {a} and {b} is: {result}")