#include <string.h>

#include <libosm/api.h>

#include "apiex.h"
#include "common.h"

extern IMalloc *g_alloc;

/* multiparm */
void multiparm_unset(sMultiParm *mp)
{
	if (mp->type == kMT_String && COMCALL1(g_alloc, DidAlloc, mp->val.s))
		COMCALL1(g_alloc, Free, mp->val.s);
	else if (mp->type == kMT_Vector && COMCALL1(g_alloc, DidAlloc, mp->val.v))
		COMCALL1(g_alloc, Free, mp->val.v);
	memset(mp, 0, sizeof(sMultiParm));
	mp->type = kMT_Undefined;
}
void multiparm_set(sMultiParm *mp, eMultiParmType type, const void *val)
{
	multiparm_unset(mp);
	switch (type)
	{
		case kMT_Integer:
		case kMT_Object:
			mp->val.i = *((int *) val);
			break;
		case kMT_Float:
			mp->val.i = *((float *) val);
			break;
		case kMT_String:
			mp->val.s = COMCALL1(g_alloc, Alloc,
				strlen(*((const char **) val)) + 1);
			if (NULL != mp->val.s)
				strcpy(mp->val.s, *((const char **) val));
			else
				return;
			break;
		case kMT_Vector:
			if (NULL == mp->val.v)
				mp->val.v = COMCALL1(g_alloc, Alloc, sizeof(sVector));
			if (NULL != mp->val.v)
			{
				sVector *v;

				v = ((sVector *) val);
				mp->val.v->x = v->x;
				mp->val.v->y = v->y;
				mp->val.v->z = v->z;
			}
			else
				return;
			break;
		default:
			multiparm_unset(mp);
			break;
	}
	mp->type = type;
}
void multiparm_setint(sMultiParm *mp, int i)
{
	multiparm_set(mp, kMT_Integer, &i);
}
void multiparm_setfloat(sMultiParm *mp, float f)
{
	multiparm_set(mp, kMT_Float, &f);
}
void multiparm_setstring(sMultiParm *mp, const char *s)
{
	multiparm_set(mp, kMT_String, &s);
}
void multiparm_setvector(sMultiParm *mp, const sVector *v)
{
	multiparm_set(mp, kMT_Vector, v);
}
void multiparm_setobject(sMultiParm *mp, int o)
{
	multiparm_set(mp, kMT_Object, &o);
}
int multiparm_compare(const sMultiParm *mp, eMultiParmType type, const void *val)
{
	if (mp->type != type)
		return 0;
	switch (type)
	{
		case kMT_Integer:
		case kMT_Object:
			return mp->val.i == *((int *) val);
		case kMT_Float:
			return mp->val.f == *((float *) val);
		case kMT_String:
			return (NULL != mp->val.s && NULL != val
				&& !strcmp(mp->val.s, *((const char **) val)));
		case kMT_Vector:
			if (NULL != mp->val.v && NULL != val)
			{
				sVector *v;

				v = ((sVector *) val);

				return mp->val.v->x == v->x
					&& mp->val.v->y == v->y
					&& mp->val.v->z == v->z;
			}
			else
				return 0;
		default:
			return 0;
	}
}
int multiparm_compareint(const sMultiParm *mp, int i)
{
	return multiparm_compare(mp, kMT_Integer, &i);
}
int multiparm_comparefloat(const sMultiParm *mp, float f)
{
	return multiparm_compare(mp, kMT_Float, &f);
}
int multiparm_comparestring(const sMultiParm *mp, const char *s)
{
	return multiparm_compare(mp, kMT_String, &s);
}
int multiparm_comparevector(const sMultiParm *mp, const sVector *v)
{
	return multiparm_compare(mp, kMT_Vector, v);
}
int multiparm_compareobject(const sMultiParm *mp, int o)
{
	return multiparm_compare(mp, kMT_Object, &o);
}

/* string */
void string_unset(char **s)
{
	if (COMCALL1(g_alloc, DidAlloc, *s))
		COMCALL1(g_alloc, Free, *s);
	*s = NULL;
}
void string_set(char **s, const char *val)
{
	*s = string_copy(val);
}
char * string_copy(const char *s)
{
	char *ret;

	ret = COMCALL1(g_alloc, Alloc, strlen(s) + 1);
	if (NULL != ret)
		strcpy(ret, s);

	return ret;
}
void string_empty(char **s)
{
	*s = string_copy("");
}
int string_compare(const char *s, const char *val)
{
	return !strcmp(s, val);
}
