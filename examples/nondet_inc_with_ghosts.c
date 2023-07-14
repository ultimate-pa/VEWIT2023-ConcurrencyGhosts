/*-----------------------------------------------------------------------------
 * nondet_inc_with_ghosts.c - Annotated concurrent program with ghost variables
 *                            for witness validation that non-deterministically
 *                            increments the value of a shared variable
 *-----------------------------------------------------------------------------
 * Author: Frank Schüssele
 *   Date: 2023-07-12
 *---------------------------------------------------------------------------*/

#include <stdlib.h>
#include <pthread.h>

/*-----------------------------------------------------------------------------
 * Ultimate-specific declarations
 *---------------------------------------------------------------------------*/
typedef unsigned long int pthread_t;

/*-----------------------------------------------------------------------------
 * SV-Comp-specific function declarations
 *---------------------------------------------------------------------------*/
extern short __VERIFIER_nondet_short();
extern int   __VERIFIER_nondet_int();
extern void  __VERIFIER_atomic_begin();
extern void  __VERIFIER_atomic_end();

extern void  reach_error();

/*-----------------------------------------------------------------------------
 * Declarations, functions and entry point of concurrent program
 *---------------------------------------------------------------------------*/
int x;
int g = 0;

void* inc()
{
  int n = __VERIFIER_nondet_int();

  while (1) {
    __VERIFIER_atomic_begin();
    int cond = x < n;
    __VERIFIER_atomic_end();
    if (!cond) break;
    __VERIFIER_atomic_begin();
    x++;
    __VERIFIER_atomic_end();
    __VERIFIER_atomic_begin();
    int cond2 = x >= g;
    __VERIFIER_atomic_end();
    if (!cond2) reach_error();
  }

  return 0;
}

int main()
{
  pthread_t tid;

  int val = __VERIFIER_nondet_short();
  pthread_create(&tid, 0, inc, 0);

  __VERIFIER_atomic_begin();
  g = val; x = val;
  __VERIFIER_atomic_end();

  __VERIFIER_atomic_begin();
  int cond = x >= val;
  __VERIFIER_atomic_end();

  if (!cond) reach_error();
  return 0;
}
