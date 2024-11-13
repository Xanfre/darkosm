#ifndef __APIEX_HPP
#define __APIEX_HPP

/* Standard API */
#include <libosm/api.h>

/* Definitions */
#ifdef MultiParm
#undef MultiParm
#endif
#define MultiParm cMultiParm
#ifdef String
#undef String
#endif
#define String cString

/* Classes */
class cMultiParm : public sMultiParm
{
public:
	cMultiParm();
	cMultiParm(int _i);
	cMultiParm(float _f);
	cMultiParm(const char *_s);
	cMultiParm(const sVector& _v);
	cMultiParm(const sMultiParm& m);
	cMultiParm(const cMultiParm& m);
	~cMultiParm();
	const cMultiParm& operator =(int _i);
	const cMultiParm& operator =(float _f);
	const cMultiParm& operator =(const char *_s);
	const cMultiParm& operator =(const sVector& _v);
	const cMultiParm& operator =(const sMultiParm& m);
	const cMultiParm& operator =(const cMultiParm& m);
	operator int() const;
	operator float() const;
	operator const char *() const;
	operator const sVector *() const;
	bool operator ==(int _i) const;
	bool operator ==(float _f) const;
	bool operator ==(const char *_s) const;
	bool operator ==(const sVector& _v) const;
	bool operator ==(const cMultiParm& m) const;

private:
	void Set(int _i);
	void Set(float _f);
	void Set(const char *_s);
	void Set(const sVector& _v);
	void Set(const sMultiParm& m);
	void Set(const cMultiParm& m);
	void Clear();
};

class cString
{
public:
	cString();
	cString(const char *_s);
	cString(const cString &_s);
	~cString();
	operator const char *() const;
	cString& operator =(const cString& _s);
	cString& operator =(const char *_s);
	bool operator ==(const char *_s) const;

private:
	void Copy(const char *_s);
	char *s;
};

#endif
