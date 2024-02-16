#include "api.hpp"

/* Contants */
#define SCR_NUM 1

/* Script Setup Macros */
#define MAKE_SCR(_n) \
	static IScript * _n##Factory(const char *, int obj) \
	{ \
		return new _n(#_n, obj); \
	}
#define SCR_DESC(_n,_r,_i) \
	g_classes[_i].mod = modname; \
	g_classes[_i].name = #_n; \
	g_classes[_i].base = #_r; \
	g_classes[_i].factory = _n##Factory;
#define SCR_DESC_DEF(_n,_i) SCR_DESC(_n, RootScript, _i)

/* Message Macros */
#define SCR_HANDLE_MSG(_m,_t,_p1,_p2) \
	if (!strcmp(_p1->message, #_m)) \
		return On##_m((_t *) _p1, _p2);
#define SCR_HANDLE_MSG_(_m,_t,_p1,_p2) \
	else SCR_HANDLE_MSG(_m, _t, _p1, _p2)

/* Script Helper Macros */
#define MESSAGE_IS(_m,_s) !strcmp(_m->message, #_s)

/* Script Class */
class cScript : public IScript
{
public:
	cScript(const char *n, int o) { name = n; obj = o; }
	virtual ~cScript() { }
	STDMETHODIMP QueryInterface(REFIID, void **);
	STDMETHODIMP_(unsigned long) AddRef();
	STDMETHODIMP_(unsigned long) Release();
	STDMETHODIMP_(const char*) GetClassName();
	STDMETHODIMP ReceiveMessage(sScrMsg *, sMultiParm *, eScrTraceAction);

private:
	unsigned int count;
	const char *name;
	int obj;
};

/* Derived Scripts */
class TestScript : public cScript
{
public:
	TestScript(const char *n, int o) : cScript(n, o) { };
	STDMETHODIMP ReceiveMessage(sScrMsg *, sMultiParm *, eScrTraceAction);
	long OnSim(sSimMsg *, sMultiParm *);
	long OnBeginScript(sScrMsg *, sMultiParm *);
	long OnTest(sScrMsg *, sMultiParm *);
	long OnFrobWorldEnd(sFrobMsg *, sMultiParm *);
};

/* Prototypes */
void InitScripts(const char *modname);
