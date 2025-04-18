// This file implements the IApplicationDestinations Interface for Python.
// Generated by makegw.py

#include "shell_pch.h"

#include "PyIApplicationDestinations.h"

// @doc - This file contains autoduck documentation
// ---------------------------------------------------
//
// Interface Implementation

PyIApplicationDestinations::PyIApplicationDestinations(IUnknown *pdisp) : PyIUnknown(pdisp) { ob_type = &type; }

PyIApplicationDestinations::~PyIApplicationDestinations() {}

/* static */ IApplicationDestinations *PyIApplicationDestinations::GetI(PyObject *self)
{
    return (IApplicationDestinations *)PyIUnknown::GetI(self);
}

// @pymethod |PyIApplicationDestinations|SetAppID|Specifies the application whose jump list is to be accessed
// @comm This method is only needed if the application sets its own taskbar identifier
PyObject *PyIApplicationDestinations::SetAppID(PyObject *self, PyObject *args)
{
    IApplicationDestinations *pIAD = GetI(self);
    if (pIAD == NULL)
        return NULL;
    // @pyparm str|AppID||Taskbar identifier for the application
    PyObject *obappid;
    TmpWCHAR appid;
    if (!PyArg_ParseTuple(args, "O:SetAppID", &obappid))
        return NULL;
    if (!PyWinObject_AsWCHAR(obappid, &appid, FALSE))
        return NULL;
    HRESULT hr;
    PY_INTERFACE_PRECALL;
    hr = pIAD->SetAppID(appid);
    PY_INTERFACE_POSTCALL;
    if (FAILED(hr))
        return PyCom_BuildPyException(hr, pIAD, IID_IApplicationDestinations);
    Py_INCREF(Py_None);
    return Py_None;
}

// @pymethod |PyIApplicationDestinations|RemoveDestination|Removes a single entry from the jump lists
// @comm Does not remove pinned items
PyObject *PyIApplicationDestinations::RemoveDestination(PyObject *self, PyObject *args)
{
    IApplicationDestinations *pIAD = GetI(self);
    if (pIAD == NULL)
        return NULL;
    IUnknown *punk;
    PyObject *obpunk;
    // @pyparm <o PyIUnknown>|punk||IShellItem or IShellLink representing an item in the application's jump list
    if (!PyArg_ParseTuple(args, "O:RemoveDestination", &obpunk))
        return NULL;
    if (!PyCom_InterfaceFromPyObject(obpunk, IID_IUnknown, (void **)&punk, FALSE))
        return NULL;
    HRESULT hr;
    PY_INTERFACE_PRECALL;
    hr = pIAD->RemoveDestination(punk);
    punk->Release();
    PY_INTERFACE_POSTCALL;

    if (FAILED(hr))
        return PyCom_BuildPyException(hr, pIAD, IID_IApplicationDestinations);
    Py_INCREF(Py_None);
    return Py_None;
}

// @pymethod |PyIApplicationDestinations|RemoveAllDestinations|Removes all Recent and Frequent jump list entries
PyObject *PyIApplicationDestinations::RemoveAllDestinations(PyObject *self, PyObject *args)
{
    IApplicationDestinations *pIAD = GetI(self);
    if (pIAD == NULL)
        return NULL;
    HRESULT hr;
    PY_INTERFACE_PRECALL;
    hr = pIAD->RemoveAllDestinations();
    PY_INTERFACE_POSTCALL;

    if (FAILED(hr))
        return PyCom_BuildPyException(hr, pIAD, IID_IApplicationDestinations);
    Py_INCREF(Py_None);
    return Py_None;
}

// @object PyIApplicationDestinations|Allows an application to removed items from its jump lists
static struct PyMethodDef PyIApplicationDestinations_methods[] = {
    {"SetAppID", PyIApplicationDestinations::SetAppID,
     1},  // @pymeth SetAppID|Specifies the application whose jump list is to be accessed
    {"RemoveDestination", PyIApplicationDestinations::RemoveDestination,
     1},  // @pymeth RemoveDestination|Removes a single entry from the jump list
    {"RemoveAllDestinations", PyIApplicationDestinations::RemoveAllDestinations,
     METH_NOARGS},  // @pymeth RemoveAllDestinations|Removes all Recent and Frequent jump list entries
    {NULL}};

PyComTypeObject PyIApplicationDestinations::type("PyIApplicationDestinations", &PyIUnknown::type,
                                                 sizeof(PyIApplicationDestinations), PyIApplicationDestinations_methods,
                                                 GET_PYCOM_CTOR(PyIApplicationDestinations));
