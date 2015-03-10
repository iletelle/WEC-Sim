#include "__cf_foswec.h"
#ifndef RTW_HEADER_foswec_private_h_
#define RTW_HEADER_foswec_private_h_
#include "rtwtypes.h"
#include "builtin_typeid_types.h"
#include "multiword_types.h"
#if !defined(rt_VALIDATE_MEMORY)
#define rt_VALIDATE_MEMORY(S, ptr)   if(!(ptr)) {\
  ssSetErrorStatus(rtS, RT_MEMORY_ALLOCATION_ERROR);\
  }
#endif
#if !defined(rt_FREE)
#if !defined(_WIN32)
#define rt_FREE(ptr)   if((ptr) != (NULL)) {\
  free((ptr));\
  (ptr) = (NULL);\
  }
#else
#define rt_FREE(ptr)   if((ptr) != (NULL)) {\
  free((void *)(ptr));\
  (ptr) = (NULL);\
  }
#endif
#endif
#ifndef __RTW_UTFREE__
extern void * utMalloc ( size_t ) ; extern void utFree ( void * ) ;
#endif
void * rt_TDelayCreateBuf ( int_T numBuffer , int_T bufSz , int_T elemSz ) ;
boolean_T rt_TDelayUpdateTailOrGrowBuf ( int_T * bufSzPtr , int_T * tailPtr ,
int_T * headPtr , int_T * lastPtr , real_T tMinusDelay , real_T * * tBufPtr ,
real_T * * uBufPtr , real_T * * xBufPtr , boolean_T isfixedbuf , boolean_T
istransportdelay , int_T * maxNewBufSzPtr ) ; real_T rt_TDelayInterpolate (
real_T tMinusDelay , real_T tStart , real_T * tBuf , real_T * uBuf , int_T
bufSz , int_T * lastIdx , int_T oldestIdx , int_T newIdx , real_T initOutput
, boolean_T discrete , boolean_T minorStepAndTAtLastMajorOutput ) ; void
rt_TDelayFreeBuf ( void * buf ) ; extern void fkj5aod2nj ( const real_T
plfojltots [ 4 ] , gwsufvgalb * localB ) ; extern void fzybd15s0q ( SimStruct
* const rtS , real_T koiwir4gai [ 6 ] , kwd4b3jpcn * localP ) ; extern void
h02m5m2hej ( real_T n120bldjdi , real_T kzququx4c2 [ 6 ] , fi0awblwxy *
localP ) ; extern void cnj3cuyx4u ( SimStruct * const rtS , const real_T
mcvlnmfzmp [ 6 ] , real_T mkr5wqpjmu [ 6 ] , djsc05xhw3 * localP ) ; extern
void coaxej2udz ( const real_T bgymqihm35 [ 6 ] , real_T egf14onhiz [ 6 ] ) ;
extern void fa0kyolrm3 ( freyzphwfw * localDW ) ; extern void dkqw3o3vme (
real_T gz5c3crpa2 , const real_T kbzpwjwv4k [ 3 ] , const real_T gwkq3lfppm [
3 ] , const real_T ghx3zoa2yd [ 5154 ] , const real_T ac41v1k1jg [ 30924 ] ,
const real_T ld00sbh52o [ 859 ] , pcwx03o2bp * localB , freyzphwfw * localDW
) ;
#if defined(MULTITASKING)
#error Model (foswec) was built in \SingleTasking solver mode, however the MULTITASKING define is \present. If you have multitasking (e.g. -DMT or -DMULTITASKING) \defined on the Code Generation page of Simulation parameter dialog, please \remove it and on the Solver page, select solver mode \MultiTasking. If the Simulation parameter dialog is configured \correctly, please verify that your template makefile is \configured correctly.
#endif
#endif
