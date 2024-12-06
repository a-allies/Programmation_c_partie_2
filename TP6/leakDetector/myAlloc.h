

#ifndef MYALLOC_H
#define MYALLOC_H


/*! \def MAX_FICHIER
* \brief The maximal size of a filename
*/
#define MAX_FICHIER 256

#ifdef MEMCHECK

/*! Macro to override the standart malloc() function
*/
#define malloc(x) myMalloc((x), __FILE__, __FUNCTION__, __LINE__)
/*! Macro to override the standart free() function
*/
#define free(x) myFree((x), __FILE__, __FUNCTION__, __LINE__)

#endif

void* myMalloc(unsigned int size, const char* file, const char * func, int line);
void myFree(void* block, const char* file, const char * func, int line);
int myCheck();
void myGarbageCollector();

#endif
