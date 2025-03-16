#define PY_SSIZE_T_CLEAN
#include "C:\Program Files\WindowsApps\PythonSoftwareFoundation.Python.3.13_3.13.752.0_x64__qbz5n2kfra8p0\include\Python.h"
//#include <Python.h>

static PyObject * ArgsError; // 定义错误对象

// C 函数：实现加法
static long add(long a, long b) {
    return a + b; // 返回两个数的和
}

// Python 包装函数
static PyObject* py_add(PyObject* self, PyObject* args, PyObject* kwargs) {
    long a, b; // 定义两个长整型变量
    static char *keywords[] = {"a", "b", NULL}; // 定义关键字参数名称

    // 解析 Python 传递的参数
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, "ll", keywords, &a, &b)) {
        PyErr_SetString(ArgsError, "Invalid arguments"); // 如果解析失败，设置错误信息
        return NULL; // 如果解析失败，返回 NULL
    }

    // 调用 C 函数并返回结果
    return Py_BuildValue("l", add(a, b));
}

// 定义模块的方法表
static PyMethodDef TestMethods[] = {
    {
        "add",                        // 函数名
        (PyCFunction)py_add,          // 函数指针
        METH_VARARGS | METH_KEYWORDS, // 参数类型, 位置参数和关键字参数
        "Add two long integers"       // 函数文档
    },
    {NULL, NULL, 0, NULL} // 结束标志
};

// 定义模块
static struct PyModuleDef testmodule = {
    PyModuleDef_HEAD_INIT,
    "test", // 模块名
    NULL,   // 模块文档（可以为 NULL）
    -1,     // 模块状态大小（-1 表示全局状态）
    TestMethods
};

// 模块初始化函数
PyMODINIT_FUNC PyInit_test(void) {
    PyObject *m; // 定义模块对象

    m = PyModule_Create(&testmodule); // 创建模块对象
    if (m == NULL)
        return NULL; // 如果创建失败，返回 NULL
    
    ArgsError = PyErr_NewException("test.ArgsError", NULL, NULL); // 创建自定义错误对象
    if (PyModule_AddObjectRef(m, "error", ArgsError) < 0) { // 将自定义错误对象添加到模块中
        Py_DECREF(m); // 如果添加失败，释放模块对象
        return NULL; // 返回 NULL
    }

    return m; // 返回模块对象
}