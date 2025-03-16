from setuptools import setup, Extension

# 定义 C 扩展模块
module = Extension('test.test', sources=['test/test.c'])


setup(
    name='your_project',
    version='0.1',
    packages=['test'],  # 包含 test 包
    ext_modules=[module],
    package_data={'test': ['*.pyi']},  # 包含 .pyi 文件
)
