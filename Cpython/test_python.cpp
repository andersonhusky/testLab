#include<iostream>
#include<opencv2/opencv.hpp>
#include<string>
#include<Python.h>

using namespace std;

void cpython1(){
    Py_Initialize();                                                                                                                    // 初始化python接口 
    PyRun_SimpleString("import sys");
    PyRun_SimpleString("sys.path.append('./')");
    PyObject* pModule = PyImport_ImportModule("hello");
    if( pModule == NULL ){
		cout <<"module not found" << endl;
		return;
	}
    PyObject* pFunc = PyObject_GetAttrString(pModule, "printHello");
    if( !pFunc || !PyCallable_Check(pFunc)){
		cout <<"function not found" << endl;
		return;
	}
    PyEval_CallObject(pFunc, nullptr);
    Py_Finalize();                                                                                                                      // 结束python接口
}

void cpython2(){
    Py_Initialize();
    PyRun_SimpleString("import sys");
    PyRun_SimpleString("sys.path.append('./')");
    PyRun_SimpleString("import hello");
    PyRun_SimpleString("hello.printHello()");
    Py_Finalize();
}

void cpythonWithPra(string& a, string& b){
    Py_Initialize();
    PyRun_SimpleString("import sys");
    PyRun_SimpleString("sys.path.append('./')");
    PyObject* pModule = PyImport_ImportModule("hello");
    if(pModule == NULL){
        cout << "module not found" << endl;
        return;
    }
    PyObject* pFunc = PyObject_GetAttrString(pModule, "printStr");
    if(!pFunc || !PyCallable_Check(pFunc)){
        cout << "function not found" << endl;
        return;
    }
    PyObject* pArgs = PyTuple_New(2);
    PyTuple_SetItem(pArgs, 0, Py_BuildValue("s", a.c_str()));
    PyTuple_SetItem(pArgs, 1, Py_BuildValue("s", b.c_str()));
    PyObject* pReturn = PyEval_CallObject(pFunc, pArgs);

    char* result;
    PyArg_Parse(pReturn, "s", &result);
    cout << "result: " << result << endl;

    Py_Finalize();
}

int main(){
    cout << "cpython1: " << endl;
    cpython1();
    cout << "cpython2: " << endl;
    cpython2();
    string a = "c++";
    string b = "python";
    cpythonWithPra(a, b);
    return 0;
}