#ifndef __APIEX_H
#define __APIEX_H

/* Standard API */
#include <libosm/api.h>

/* multiparm */
void multiparm_unset(sMultiParm *mp);
void multiparm_set(sMultiParm *mp, eMultiParmType type, const void *val);
void multiparm_setint(sMultiParm *mp, int i);
void multiparm_setfloat(sMultiParm *mp, float f);
void multiparm_setstring(sMultiParm *mp, const char *s);
void multiparm_setvector(sMultiParm *mp, const sVector *v);
void multiparm_setobject(sMultiParm *mp, int o);
int multiparm_compare(const sMultiParm *mp, eMultiParmType type,
	const void *val);
int multiparm_compareint(const sMultiParm *mp, int i);
int multiparm_comparefloat(const sMultiParm *mp, float f);
int multiparm_comparestring(const sMultiParm *mp, const char *s);
int multiparm_comparevector(const sMultiParm *mp, const sVector *v);
int multiparm_compareobject(const sMultiParm *mp, int o);

/* string */
void string_unset(char **s);
void string_set(char **s, const char *val);
char * string_copy(const char *s);
/* NOTE: Strings must be emptied prior to using service routines that require
 * them. Passing a null pointer where a string is expected is an error! */
void string_empty(char **s);
int string_compare(const char *s, const char *val);

#endif
