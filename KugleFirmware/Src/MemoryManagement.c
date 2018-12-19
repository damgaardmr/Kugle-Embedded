#include "stm32h7xx_hal.h"
#include "stdlib.h"
#include "cmsis_os.h"
#include "FreeRTOS.h"
#include "task.h"
#include "string.h" // for memset
#include <malloc.h>

#define USE_FREERTOS

extern int _sfreertos_heap; // get address to global symbol defined in linker file
extern uint8_t freeRTOSMemoryScheme;

/*void ZeroInitFreeRTOSheap(void);
void * __wrap_malloc (size_t size);
void __wrap_free (void * ptr);*/

/*extern void *__malloc(size_t size);
extern void *__free(void *ptr);*/
extern void *__real_malloc(size_t size);
extern void __real_free(void *ptr);
extern void *__real__malloc_r(size_t size);
extern void __real__free_r(void *ptr);

#if 1
#ifdef USE_FREERTOS
// Very important to include following linker options:
// -Xlinker --wrap=malloc
// -Xlinker --wrap=_malloc_r
// -Xlinker --wrap=free
// -Xlinker --wrap=_free_r
// These will "replace" the calls to malloc with the wrapped functions below, see https://www.cs.cmu.edu/afs/cs/academic/class/15213-s13/www/lectures/12-linking.pdf
// See also: https://github.com/ErichStyger/McuOnEclipse_PEx/blob/master/Drivers/freeRTOS/Source/portable/MemMang/heap_useNewlib.c

/* Defining malloc/free should overwrite the
standard versions provided by the compiler. */
void * __wrap_malloc (size_t size)
{
	if(uxTaskGetNumberOfTasks())
		/* Call the FreeRTOS version of malloc. */
		return pvPortMalloc( size );
	else
		// Call the original C version of malloc
		return __real_malloc( size );
}
void __wrap_free (void * ptr)
{
	if(uxTaskGetNumberOfTasks())
		/* Call the FreeRTOS version of free. */
		vPortFree( ptr );
	else
		// Call the original C version of free
		__real_free( ptr );
}

void * __wrap__malloc_r (size_t size)
{
	return __real__malloc_r( size );
}
void __wrap__free_r (void * ptr)
{
	__real__free_r( ptr );
}

#endif
#endif

void ZeroInitFreeRTOSheap(void)
{
	uint8_t * heapPtr = (uint8_t*)&_sfreertos_heap; // heap is placed at this global symbol address
	freeRTOSMemoryScheme = configUSE_HEAP_SCHEME;
	memset(heapPtr, 0, configTOTAL_HEAP_SIZE);
}

#if 0
// Define the 'new' operator for C++ to use the freeRTOS memory management
// functions. THIS IS NOT OPTIONAL!
//
void * operator new(size_t size)
{
	void * p;

	#ifdef USE_FREERTOS
		if(uxTaskGetNumberOfTasks())
			p = pvPortMalloc(size);
		else
			p = malloc(size);

	#else
			p = malloc(size);
	#endif
	#ifdef __EXCEPTIONS
		if (p==0) // did pvPortMalloc succeed?
		throw std::bad_alloc(); // ANSI/ISO compliant behavior
	#endif
	return p;
}

//
// Define the 'delete' operator for C++ to use the freeRTOS memory management
// functions. THIS IS NOT OPTIONAL!
//
void operator delete(void *p)
{
	#ifdef USE_FREERTOS
		if(uxTaskGetNumberOfTasks())
			vPortFree( p );
		else
			free( p );
	#else
		free( p );
	#endif
	p = NULL;
}
#endif

#if 0
/* Optionally you can override the 'nothrow' versions as well.
This is useful if you want to catch failed allocs with your
own debug code, or keep track of heap usage for example,
rather than just eliminate exceptions.
*/

void* operator new(std::size_t size, const std::nothrow_t&) {
return malloc(size);
}

void* operator new {
return malloc(size);
}

void operator delete(void* ptr, const std::nothrow_t&) {
free(ptr);
}

void operator delete {
free(ptr);
}

#endif