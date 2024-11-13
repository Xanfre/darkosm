#include <cstring>

#include "apiex.hpp"

/* cMultiParm */
cMultiParm::cMultiParm()
{
	type = kMT_Undefined;
}
cMultiParm::cMultiParm(int _i)
{
	Set(_i);
}
cMultiParm::cMultiParm(float _f)
{
	Set(_f);
}
cMultiParm::cMultiParm(const char *_s)
{
	Set(_s);
}
cMultiParm::cMultiParm(const sVector& _v)
{
	Set(_v);
}
cMultiParm::cMultiParm(const sMultiParm& m)
{
	Set(m);
}
cMultiParm::cMultiParm(const cMultiParm& m)
{
	Set(m);
}
cMultiParm::~cMultiParm()
{
	Clear();
}
const cMultiParm& cMultiParm::operator =(int _i)
{
	Clear();
	Set(_i);
	return *this;
}
const cMultiParm& cMultiParm::operator =(float _f)
{
	Clear();
	Set(_f);
	return *this;
}
const cMultiParm& cMultiParm::operator =(const char *_s)
{
	Clear();
	Set(_s);
	return *this;
}
const cMultiParm& cMultiParm::operator =(const sVector& _v)
{
	Clear();
	Set(_v);
	return *this;
}
const cMultiParm& cMultiParm::operator =(const sMultiParm& m)
{
	Clear();
	Set(m);
	return *this;
}
const cMultiParm& cMultiParm::operator =(const cMultiParm& m)
{
	Clear();
	Set(m);
	return *this;
}
cMultiParm::operator int() const
{
	return (type == kMT_Integer || type == kMT_Object) ? val.i : 0;
}
cMultiParm::operator float() const
{
	return type == kMT_Float ? val.f : 0.0f;
}
cMultiParm::operator const char *() const
{
	return (type == kMT_String) ? val.s : NULL;
}
cMultiParm::operator const sVector *() const
{
	return (type == kMT_Vector) ? val.v : NULL;
}
bool cMultiParm::operator ==(int _i) const
{
	return (type == kMT_Integer || type == kMT_Object)
		? val.i == _i : false;
}
bool cMultiParm::operator ==(float _f) const
{
	return (type == kMT_Float) ? val.f == _f : false;
}
bool cMultiParm::operator ==(const char *_s) const
{
	return (type == kMT_String && NULL != val.s && NULL != _s)
		? !strcmp(val.s, _s) : false;
}
bool cMultiParm::operator ==(const sVector& _v) const
{
	return (type == kMT_Vector && NULL != val.v)
		? (val.v->x == _v.x && val.v->y == _v.y && val.v->z == _v.z)
		: false;
}
bool cMultiParm::operator ==(const cMultiParm& m) const
{
	if (type != m.type)
		return false;
	switch (type)
	{
		case kMT_Integer:
		case kMT_Object:
			return val.i == m.val.i;
		case kMT_Float:
			return val.f == m.val.f;
		case kMT_String:
			return (NULL != val.s && NULL != m.val.s
				&& !strcmp(val.s, m.val.s));
		case kMT_Vector:
			return (NULL != val.v && NULL != m.val.v
				&& val.v->x == m.val.v->x
				&& val.v->y == m.val.v->y
				&& val.v->z == m.val.v->z);
		default:
			return false;
	}
}
void cMultiParm::Set(int _i)
{
	val.i = _i;
	type = kMT_Integer;
}
void cMultiParm::Set(float _f)
{
	val.f = _f;
	type = kMT_Float;
}
void cMultiParm::Set(const char *_s)
{
	val.s = new char[strlen(_s) + 1];
	if (NULL != val.s)
		strcpy(val.s, _s);
	type = kMT_String;
}
void cMultiParm::Set(const sVector& _v)
{
	val.v = new sVector;
	if (NULL != val.v)
	{
		val.v->x = _v.x;
		val.v->y = _v.y;
		val.v->z = _v.z;
	}
	type = kMT_Vector;
}
void cMultiParm::Set(const sMultiParm& m)
{
	switch (m.type)
	{
		case kMT_Integer:
		case kMT_Object:
			Set(m.val.i);
			break;
		case kMT_Float:
			Set(m.val.f);
			break;
		case kMT_String:
			Set(m.val.s);
			break;
		case kMT_Vector:
			if (NULL != m.val.v)
				Set(*m.val.v);
			else
				Clear();
			break;
		default:
			Clear();
			break;
	}
}
void cMultiParm::Set(const cMultiParm& m)
{
	Set(static_cast<const sMultiParm&>(m));
}
void cMultiParm::Clear()
{
	if (type == kMT_String)
		delete val.s;
	else if (type == kMT_Vector)
		delete val.v;
	type = kMT_Undefined;
}

/* cString */
cString::cString()
{
	s = new char[1];
	if (NULL != s)
		s[0] = '\0';
}
cString::cString(const char *_s)
{
	s = NULL;
	Copy(_s);
}
cString::cString(const cString &_s)
{
	s = NULL;
	Copy(_s);
}
cString::~cString()
{
	delete[] s;
}
cString::operator const char *() const
{
	return s;
}
cString& cString::operator =(const cString& _s)
{
	Copy(_s);
	return *this;
}
cString& cString::operator =(const char *_s)
{
	Copy(_s);
	return *this;
}
bool cString::operator ==(const char *_s) const
{
	return NULL != s && NULL != _s && 0 == strcmp(s, _s);
}
void cString::Copy(const char *_s)
{
	if (NULL == _s)
		_s = "";
	delete[] s;
	s = new char[strlen(_s) + 1];
	if (NULL != s)
		strcpy(s, _s);
}
