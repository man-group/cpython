/*[clinic input]
preserve
[clinic start generated code]*/

#include "pycore_modsupport.h"    // _PyArg_CheckPositional()

PyDoc_STRVAR(deflate_crc32__doc__,
"crc32($module, data, value=0, /)\n"
"--\n"
"\n"
"Compute a CRC-32 checksum of data.\n"
"\n"
"  value\n"
"    Starting value of the checksum.\n"
"\n"
"The returned checksum is an integer.");

#define DEFLATE_CRC32_METHODDEF    \
    {"crc32", _PyCFunction_CAST(deflate_crc32), METH_FASTCALL, deflate_crc32__doc__},

static unsigned int
deflate_crc32_impl(PyObject *module, Py_buffer *data, unsigned int value);

static PyObject *
deflate_crc32(PyObject *module, PyObject *const *args, Py_ssize_t nargs)
{
    PyObject *return_value = NULL;
    Py_buffer data = {NULL, NULL};
    unsigned int value = 0;
    unsigned int _return_value;

    if (!_PyArg_CheckPositional("crc32", nargs, 1, 2)) {
        goto exit;
    }
    if (PyObject_GetBuffer(args[0], &data, PyBUF_SIMPLE) != 0) {
        goto exit;
    }
    if (nargs < 2) {
        goto skip_optional;
    }
    value = (unsigned int)PyLong_AsUnsignedLongMask(args[1]);
    if (value == (unsigned int)-1 && PyErr_Occurred()) {
        goto exit;
    }
skip_optional:
    _return_value = deflate_crc32_impl(module, &data, value);
    if ((_return_value == (unsigned int)-1) && PyErr_Occurred()) {
        goto exit;
    }
    return_value = PyLong_FromUnsignedLong((unsigned long)_return_value);

exit:
    /* Cleanup for data */
    if (data.obj) {
       PyBuffer_Release(&data);
    }

    return return_value;
}
/*[clinic end generated code: output=a2dc1cf2cd6f93f8 input=a9049054013a1b77]*/
