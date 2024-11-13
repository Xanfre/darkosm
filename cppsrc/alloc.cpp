#include <cstddef>

#include "apiex.hpp"

extern IMalloc *g_alloc;

/* Override default allocator */
void * operator new(size_t size)
{
	return NULL == g_alloc ? NULL : g_alloc->Alloc(size);
}
void * operator new[](size_t size)
{
	return NULL == g_alloc ? NULL : g_alloc->Alloc(size);
}
void operator delete(void *p)
{
	if (NULL != g_alloc && NULL != p && g_alloc->DidAlloc(p))
		g_alloc->Free(p);
}
void operator delete[](void *p)
{
	if (NULL != g_alloc && NULL != p && g_alloc->DidAlloc(p))
		g_alloc->Free(p);
}
#if __cplusplus >= 201402L
void operator delete(void *p, unsigned int)
{
	if (NULL != g_alloc && NULL != p && g_alloc->DidAlloc(p))
		g_alloc->Free(p);
}
void operator delete[](void *p, unsigned int)
{
	if (NULL != g_alloc && NULL != p && g_alloc->DidAlloc(p))
		g_alloc->Free(p);
}
#endif
