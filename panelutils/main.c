#include <Python.h>

#include "linux_CPUusage.h"
#include "linux_RAMusage.h"
#include "linux_storageINFO.h"

static PyObject* get_cpu_usage2(PyObject* self, PyObject* args) {    
    double cpu_usage = get_cpu_usage();
    return Py_BuildValue("d", cpu_usage);
}

static PyObject* get_mem_usage2(PyObject* self, PyObject* args) {
    long mem_usage = get_mem_usage();
    return Py_BuildValue("l", mem_usage);
}

static PyObject* get_total_mem2(PyObject* self, PyObject* args) {
    long total_mem = get_total_mem();
    return Py_BuildValue("l", total_mem);
}

static PyObject* get_free_mem2(PyObject* self, PyObject* args) {
    long free_mem = get_free_mem();
    return Py_BuildValue("l", free_mem);
}

static PyObject* get_storage_usage2(PyObject* self, PyObject* args) {
    long storage_usage = get_storage_usage();
    return Py_BuildValue("l", storage_usage);
}

static PyObject* get_total_storage2(PyObject* self, PyObject* args) {
    long total_storage = get_total_storage();
    return Py_BuildValue("l", total_storage);
}

static PyObject* get_free_storage2(PyObject* self, PyObject* args) {
    long free_storage = get_free_storage();
    return Py_BuildValue("l", free_storage);
}

static PyMethodDef METHODS_panelutils[] = {
    {"get_cpu_usage", get_cpu_usage2, METH_NOARGS, "Get CPU usage percentage."},
    {"get_mem_usage", get_mem_usage2, METH_NOARGS, "Get used memory in MB."},
    {"get_total_mem", get_total_mem2, METH_NOARGS, "Get total memory in MB."},
    {"get_free_mem", get_free_mem2, METH_NOARGS, "Get free memory in MB."},
    {"get_storage_usage", get_storage_usage2, METH_NOARGS, "Get used storage in MB."},
    {"get_total_storage", get_total_storage2, METH_NOARGS, "Get total storage in MB."},
    {"get_free_storage", get_free_storage2, METH_NOARGS, "Get free storage in MB."},
    {NULL, NULL, 0, NULL}
};

static struct PyModuleDef panelutilsmodule = {
    PyModuleDef_HEAD_INIT,
    "panelutils",   /* name of module */
    NULL,         /* module documentation, may be NULL */
    -1,           /* size of per-interpreter state of the module,
                     or -1 if the module keeps state in global variables. */
    METHODS_panelutils
};

PyMODINIT_FUNC PyInit_panelutils(void) {
    return PyModule_Create(&panelutilsmodule);
}