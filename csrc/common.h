#ifndef __COMMON_H
#define __COMMON_H

/* Helper Macros */
#define UNUSED(_x) (void)(_x);
#if (__STDC_VERSION__ >= 202311L) || (!defined(__STRICT_ANSI__) && defined(__GNUC__))
#define COMCALL(_i,_m,...) (_i)->lpVtbl->_m(_i __VA_OPT__(,) __VA_ARGS__)
#endif
/* NOTE: There are no variadic macros in ANSI C, so use discrete macros instead
 * for each number of arguments. */
#define COMCALL0(_i,_m) (_i)->lpVtbl->_m(_i)
#define COMCALL1(_i,_m,_a1) (_i)->lpVtbl->_m(_i, _a1)
#define COMCALL2(_i,_m,_a1,_a2) (_i)->lpVtbl->_m(_i, _a1, _a2)
#define COMCALL3(_i,_m,_a1,_a2,_a3) (_i)->lpVtbl->_m(_i, _a1, _a2, _a3)
#define COMCALL4(_i,_m,_a1,_a2,_a3,_a4) (_i)->lpVtbl->_m(_i, _a1, _a2, _a3, _a4)
#define COMCALL5(_i,_m,_a1,_a2,_a3,_a4,_a5) \
	(_i)->lpVtbl->_m(_i, _a1, _a2, _a3, _a4, _a5)
#define COMCALL6(_i,_m,_a1,_a2,_a3,_a4,_a5,_a6) \
	(_i)->lpVtbl->_m(_i, _a1, _a2, _a3, _a4, _a5, _a6)
#define COMCALL7(_i,_m,_a1,_a2,_a3,_a4,_a5,_a6,_a7) \
	(_i)->lpVtbl->_m(_i, _a1, _a2, _a3, _a4, _a5, _a6, _a7)
#define COMCALL8(_i,_m,_a1,_a2,_a3,_a4,_a5,_a6,_a7,_a8) \
	(_i)->lpVtbl->_m(_i, _a1, _a2, _a3, _a4, _a5, _a6, _a7, _a8)

#endif
