/* deflate module */

/* This module provides an interface to deflate library. */

/* deflate objects */

#ifndef Py_BUILD_CORE_BUILTIN
#  define Py_BUILD_CORE_MODULE 1
#endif

#include "Python.h"
#include "clinic/deflatemodule.c.h"
#include "libdeflate.h"

/*[clinic input]
module deflate
[clinic start generated code]*/
/*[clinic end generated code: output=da39a3ee5e6b4b0d input=e8fe2232b5d8509a]*/

/*[clinic input]
deflate.crc32 -> unsigned_int

    data: Py_buffer
    value: unsigned_int(bitwise=True) = 0
        Starting value of the checksum.
    /

Compute a CRC-32 checksum of data.

The returned checksum is an integer.
[clinic start generated code]*/

static unsigned int
deflate_crc32_impl(PyObject *module, Py_buffer *data, unsigned int value)
/*[clinic end generated code: output=1509d54a8b6329c0 input=50ff444788572aa2]*/
{
    /* Releasing the GIL for very small buffers is inefficient
       and may lower performance */
    if (data->len > 1024*5) {
        Py_BEGIN_ALLOW_THREADS
        value = libdeflate_crc32((uint32_t)value, data->buf, (size_t)data->len);
        Py_END_ALLOW_THREADS
    } else {
        value = libdeflate_crc32((uint32_t)value, data->buf, (size_t)data->len);
    }
    return value;
}

static PyMethodDef deflate_methods[] = {
    DEFLATE_CRC32_METHODDEF
    {NULL}
};

static struct PyModuleDef deflate_module = {
    PyModuleDef_HEAD_INIT,
    .m_name = "deflate",
    .m_doc = "Module that provides a CRC32 function.",
    .m_size = -1,
    .m_methods = deflate_methods,
};

PyMODINIT_FUNC
PyInit_deflate(void)
{
    return PyModule_Create(&deflate_module);
}
