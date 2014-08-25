/* File: slibmodule.c
 * This file is auto-generated with f2py (version:2).
 * f2py is a Fortran to Python Interface Generator (FPIG), Second Edition,
 * written by Pearu Peterson <pearu@cens.ioc.ee>.
 * See http://cens.ioc.ee/projects/f2py2e/
 * Generation date: Fri Aug 22 21:01:22 2014
 * $Revision:$
 * $Date:$
 * Do not edit this file directly unless you know what you are doing!!!
 */
#ifdef __cplusplus
extern "C" {
#endif

/*********************** See f2py2e/cfuncs.py: includes ***********************/
#include "Python.h"
#include <stdarg.h>
#include "fortranobject.h"
/*need_includes0*/

/**************** See f2py2e/rules.py: mod_rules['modulebody'] ****************/
static PyObject *slib_error;
static PyObject *slib_module;

/*********************** See f2py2e/cfuncs.py: typedefs ***********************/
typedef struct {double r,i;} complex_double;

/****************** See f2py2e/cfuncs.py: typedefs_generated ******************/
/*need_typedefs_generated*/

/********************** See f2py2e/cfuncs.py: cppmacros **********************/
#if defined(PREPEND_FORTRAN)
#if defined(NO_APPEND_FORTRAN)
#if defined(UPPERCASE_FORTRAN)
#define F_FUNC(f,F) _##F
#else
#define F_FUNC(f,F) _##f
#endif
#else
#if defined(UPPERCASE_FORTRAN)
#define F_FUNC(f,F) _##F##_
#else
#define F_FUNC(f,F) _##f##_
#endif
#endif
#else
#if defined(NO_APPEND_FORTRAN)
#if defined(UPPERCASE_FORTRAN)
#define F_FUNC(f,F) F
#else
#define F_FUNC(f,F) f
#endif
#else
#if defined(UPPERCASE_FORTRAN)
#define F_FUNC(f,F) F##_
#else
#define F_FUNC(f,F) f##_
#endif
#endif
#endif
#if defined(UNDERSCORE_G77)
#define F_FUNC_US(f,F) F_FUNC(f##_,F##_)
#else
#define F_FUNC_US(f,F) F_FUNC(f,F)
#endif

#define rank(var) var ## _Rank
#define shape(var,dim) var ## _Dims[dim]
#define old_rank(var) (((PyArrayObject *)(capi_ ## var ## _tmp))->nd)
#define old_shape(var,dim) (((PyArrayObject *)(capi_ ## var ## _tmp))->dimensions[dim])
#define fshape(var,dim) shape(var,rank(var)-dim-1)
#define len(var) shape(var,0)
#define flen(var) fshape(var,0)
#define old_size(var) PyArray_SIZE((PyArrayObject *)(capi_ ## var ## _tmp))
/* #define index(i) capi_i ## i */
#define slen(var) capi_ ## var ## _len
#define size(var, ...) f2py_size((PyArrayObject *)(capi_ ## var ## _tmp), ## __VA_ARGS__, -1)

#ifdef DEBUGCFUNCS
#define CFUNCSMESS(mess) fprintf(stderr,"debug-capi:"mess);
#define CFUNCSMESSPY(mess,obj) CFUNCSMESS(mess) \
  PyObject_Print((PyObject *)obj,stderr,Py_PRINT_RAW);\
  fprintf(stderr,"\n");
#else
#define CFUNCSMESS(mess)
#define CFUNCSMESSPY(mess,obj)
#endif

#ifndef max
#define max(a,b) ((a > b) ? (a) : (b))
#endif
#ifndef min
#define min(a,b) ((a < b) ? (a) : (b))
#endif
#ifndef MAX
#define MAX(a,b) ((a > b) ? (a) : (b))
#endif
#ifndef MIN
#define MIN(a,b) ((a < b) ? (a) : (b))
#endif


/************************ See f2py2e/cfuncs.py: cfuncs ************************/
static int f2py_size(PyArrayObject* var, ...)
{
  npy_int sz = 0;
  npy_int dim;
  npy_int rank;
  va_list argp;
  va_start(argp, var);
  dim = va_arg(argp, npy_int);
  if (dim==-1)
    {
      sz = PyArray_SIZE(var);
    }
  else
    {
      rank = PyArray_NDIM(var);
      if (dim>=1 && dim<=rank)
        sz = PyArray_DIM(var, dim-1);
      else
        fprintf(stderr, "f2py_size: 2nd argument value=%d fails to satisfy 1<=value<=%d. Result will be 0.\n", dim, rank);
    }
  va_end(argp);
  return sz;
}

static int int_from_pyobj(int* v,PyObject *obj,const char *errmess) {
  PyObject* tmp = NULL;
  if (PyInt_Check(obj)) {
    *v = (int)PyInt_AS_LONG(obj);
    return 1;
  }
  tmp = PyNumber_Int(obj);
  if (tmp) {
    *v = PyInt_AS_LONG(tmp);
    Py_DECREF(tmp);
    return 1;
  }
  if (PyComplex_Check(obj))
    tmp = PyObject_GetAttrString(obj,"real");
  else if (PyString_Check(obj) || PyUnicode_Check(obj))
    /*pass*/;
  else if (PySequence_Check(obj))
    tmp = PySequence_GetItem(obj,0);
  if (tmp) {
    PyErr_Clear();
    if (int_from_pyobj(v,tmp,errmess)) {Py_DECREF(tmp); return 1;}
    Py_DECREF(tmp);
  }
  {
    PyObject* err = PyErr_Occurred();
    if (err==NULL) err = slib_error;
    PyErr_SetString(err,errmess);
  }
  return 0;
}


/********************* See f2py2e/cfuncs.py: userincludes *********************/
/*need_userincludes*/

/********************* See f2py2e/capi_rules.py: usercode *********************/


/* See f2py2e/rules.py */
extern void F_FUNC(ZADD,ZADD)(complex_double*,complex_double*,complex_double*,int*);
/*eof externroutines*/

/******************** See f2py2e/capi_rules.py: usercode1 ********************/


/******************* See f2py2e/cb_rules.py: buildcallback *******************/
/*need_callbacks*/

/*********************** See f2py2e/rules.py: buildapi ***********************/

/************************************ ZADD ************************************/
static char doc_f2py_rout_slib_ZADD[] = "\
ZADD(A,B,C,N)\n\nWrapper for ``ZADD``.\
\n\nParameters\n----------\n"
"A : input rank-1 array('D') with bounds (*)\n"
"B : input rank-1 array('D') with bounds (*)\n"
"C : input rank-1 array('D') with bounds (*)\n"
"N : input int";
/* extern void F_FUNC(ZADD,ZADD)(complex_double*,complex_double*,complex_double*,int*); */
static PyObject *f2py_rout_slib_ZADD(const PyObject *capi_self,
                           PyObject *capi_args,
                           PyObject *capi_keywds,
                           void (*f2py_func)(complex_double*,complex_double*,complex_double*,int*)) {
  PyObject * volatile capi_buildvalue = NULL;
  volatile int f2py_success = 1;
/*decl*/

  complex_double *A = NULL;
  npy_intp A_Dims[1] = {-1};
  const int A_Rank = 1;
  PyArrayObject *capi_A_tmp = NULL;
  int capi_A_intent = 0;
  PyObject *A_capi = Py_None;
  complex_double *B = NULL;
  npy_intp B_Dims[1] = {-1};
  const int B_Rank = 1;
  PyArrayObject *capi_B_tmp = NULL;
  int capi_B_intent = 0;
  PyObject *B_capi = Py_None;
  complex_double *C = NULL;
  npy_intp C_Dims[1] = {-1};
  const int C_Rank = 1;
  PyArrayObject *capi_C_tmp = NULL;
  int capi_C_intent = 0;
  PyObject *C_capi = Py_None;
  int N = 0;
  PyObject *N_capi = Py_None;
  static char *capi_kwlist[] = {"A","B","C","N",NULL};

/*routdebugenter*/
#ifdef F2PY_REPORT_ATEXIT
f2py_start_clock();
#endif
  if (!PyArg_ParseTupleAndKeywords(capi_args,capi_keywds,\
    "OOOO:slib.ZADD",\
    capi_kwlist,&A_capi,&B_capi,&C_capi,&N_capi))
    return NULL;
/*frompyobj*/
  /* Processing variable A */
  ;
  capi_A_intent |= F2PY_INTENT_IN;
  capi_A_tmp = array_from_pyobj(NPY_CDOUBLE,A_Dims,A_Rank,capi_A_intent,A_capi);
  if (capi_A_tmp == NULL) {
    if (!PyErr_Occurred())
      PyErr_SetString(slib_error,"failed in converting 1st argument `A' of slib.ZADD to C/Fortran array" );
  } else {
    A = (complex_double *)(capi_A_tmp->data);

  /* Processing variable C */
  ;
  capi_C_intent |= F2PY_INTENT_IN;
  capi_C_tmp = array_from_pyobj(NPY_CDOUBLE,C_Dims,C_Rank,capi_C_intent,C_capi);
  if (capi_C_tmp == NULL) {
    if (!PyErr_Occurred())
      PyErr_SetString(slib_error,"failed in converting 3rd argument `C' of slib.ZADD to C/Fortran array" );
  } else {
    C = (complex_double *)(capi_C_tmp->data);

  /* Processing variable B */
  ;
  capi_B_intent |= F2PY_INTENT_IN;
  capi_B_tmp = array_from_pyobj(NPY_CDOUBLE,B_Dims,B_Rank,capi_B_intent,B_capi);
  if (capi_B_tmp == NULL) {
    if (!PyErr_Occurred())
      PyErr_SetString(slib_error,"failed in converting 2nd argument `B' of slib.ZADD to C/Fortran array" );
  } else {
    B = (complex_double *)(capi_B_tmp->data);

  /* Processing variable N */
    f2py_success = int_from_pyobj(&N,N_capi,"slib.ZADD() 4th argument (N) can't be converted to int");
  if (f2py_success) {
/*end of frompyobj*/
#ifdef F2PY_REPORT_ATEXIT
f2py_start_call_clock();
#endif
/*callfortranroutine*/
        (*f2py_func)(A,B,C,&N);
if (PyErr_Occurred())
  f2py_success = 0;
#ifdef F2PY_REPORT_ATEXIT
f2py_stop_call_clock();
#endif
/*end of callfortranroutine*/
    if (f2py_success) {
/*pyobjfrom*/
/*end of pyobjfrom*/
    CFUNCSMESS("Building return value.\n");
    capi_buildvalue = Py_BuildValue("");
/*closepyobjfrom*/
/*end of closepyobjfrom*/
    } /*if (f2py_success) after callfortranroutine*/
/*cleanupfrompyobj*/
  } /*if (f2py_success) of N*/
  /* End of cleaning variable N */
  if((PyObject *)capi_B_tmp!=B_capi) {
    Py_XDECREF(capi_B_tmp); }
  }  /*if (capi_B_tmp == NULL) ... else of B*/
  /* End of cleaning variable B */
  if((PyObject *)capi_C_tmp!=C_capi) {
    Py_XDECREF(capi_C_tmp); }
  }  /*if (capi_C_tmp == NULL) ... else of C*/
  /* End of cleaning variable C */
  if((PyObject *)capi_A_tmp!=A_capi) {
    Py_XDECREF(capi_A_tmp); }
  }  /*if (capi_A_tmp == NULL) ... else of A*/
  /* End of cleaning variable A */
/*end of cleanupfrompyobj*/
  if (capi_buildvalue == NULL) {
/*routdebugfailure*/
  } else {
/*routdebugleave*/
  }
  CFUNCSMESS("Freeing memory.\n");
/*freemem*/
#ifdef F2PY_REPORT_ATEXIT
f2py_stop_clock();
#endif
  return capi_buildvalue;
}
/******************************** end of ZADD ********************************/
/*eof body*/

/******************* See f2py2e/f90mod_rules.py: buildhooks *******************/
/*need_f90modhooks*/

/************** See f2py2e/rules.py: module_rules['modulebody'] **************/

/******************* See f2py2e/common_rules.py: buildhooks *******************/

/*need_commonhooks*/

/**************************** See f2py2e/rules.py ****************************/

static FortranDataDef f2py_routine_defs[] = {
  {"ZADD",-1,{{-1}},0,(char *)F_FUNC(ZADD,ZADD),(f2py_init_func)f2py_rout_slib_ZADD,doc_f2py_rout_slib_ZADD},

/*eof routine_defs*/
  {NULL}
};

static PyMethodDef f2py_module_methods[] = {

  {NULL,NULL}
};

#if PY_VERSION_HEX >= 0x03000000
static struct PyModuleDef moduledef = {
  PyModuleDef_HEAD_INIT,
  "slib",
  NULL,
  -1,
  f2py_module_methods,
  NULL,
  NULL,
  NULL,
  NULL
};
#endif

#if PY_VERSION_HEX >= 0x03000000
#define RETVAL m
PyMODINIT_FUNC PyInit_slib(void) {
#else
#define RETVAL
PyMODINIT_FUNC initslib(void) {
#endif
  int i;
  PyObject *m,*d, *s;
#if PY_VERSION_HEX >= 0x03000000
  m = slib_module = PyModule_Create(&moduledef);
#else
  m = slib_module = Py_InitModule("slib", f2py_module_methods);
#endif
  Py_TYPE(&PyFortran_Type) = &PyType_Type;
  import_array();
  if (PyErr_Occurred())
    {PyErr_SetString(PyExc_ImportError, "can't initialize module slib (failed to import numpy)"); return RETVAL;}
  d = PyModule_GetDict(m);
  s = PyString_FromString("$Revision: $");
  PyDict_SetItemString(d, "__version__", s);
#if PY_VERSION_HEX >= 0x03000000
  s = PyUnicode_FromString(
#else
  s = PyString_FromString(
#endif
    "This module 'slib' is auto-generated with f2py (version:2).\nFunctions:\n"
"  ZADD(A,B,C,N)\n"
".");
  PyDict_SetItemString(d, "__doc__", s);
  slib_error = PyErr_NewException ("slib.error", NULL, NULL);
  Py_DECREF(s);
  for(i=0;f2py_routine_defs[i].name!=NULL;i++)
    PyDict_SetItemString(d, f2py_routine_defs[i].name,PyFortranObject_NewAsAttr(&f2py_routine_defs[i]));

/*eof initf2pywraphooks*/
/*eof initf90modhooks*/

/*eof initcommonhooks*/


#ifdef F2PY_REPORT_ATEXIT
  if (! PyErr_Occurred())
    on_exit(f2py_report_on_exit,(void*)"slib");
#endif

  return RETVAL;
}
#ifdef __cplusplus
}
#endif