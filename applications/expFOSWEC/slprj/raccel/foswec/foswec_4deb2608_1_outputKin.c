#include "__cf_foswec.h"
#include <math.h>
#include <string.h>
#include "pm_std.h"
#include "sm_std.h"
#include "sm_ssci_run_time_errors.h"
PmfMessageId foswec_4deb2608_1_outputKin ( const double * state , const
double * input , const double * inputDot , const double * inputDdot , const
double * discreteState , double * output , NeuDiagnosticManager * neDiagMgr )
{ double xx [ 30 ] ; ( void ) input ; ( void ) inputDot ; ( void ) inputDdot
; ( void ) discreteState ; ( void ) neDiagMgr ; xx [ 0 ] = 0.0 ; xx [ 1 ] =
0.5 ; xx [ 2 ] = xx [ 1 ] * state [ 0 ] ; xx [ 3 ] = cos ( xx [ 2 ] ) ; xx [
5 ] = 0.0 ; xx [ 6 ] = sin ( xx [ 2 ] ) ; xx [ 2 ] = 2.0 ; xx [ 7 ] =
9.359999999999999 ; xx [ 8 ] = xx [ 7 ] * xx [ 6 ] ; xx [ 10 ] =
3.552713678800501e-15 ; xx [ 11 ] = xx [ 10 ] * xx [ 6 ] ; xx [ 13 ] = 20.0 ;
xx [ 15 ] = 9.360000000000001 ; xx [ 16 ] = xx [ 15 ] * state [ 1 ] ; xx [ 17
] = xx [ 10 ] * state [ 1 ] ; xx [ 10 ] = xx [ 17 ] * xx [ 6 ] ; xx [ 18 ] =
xx [ 16 ] * xx [ 6 ] ; xx [ 20 ] = xx [ 1 ] * state [ 2 ] ; xx [ 1 ] = cos (
xx [ 20 ] ) ; xx [ 21 ] = sin ( xx [ 20 ] ) ; xx [ 20 ] = xx [ 7 ] * xx [ 21
] ; xx [ 22 ] = 8.881784197001335e-16 ; xx [ 23 ] = xx [ 22 ] * xx [ 21 ] ;
xx [ 25 ] = 3.552713678800499e-15 ; xx [ 26 ] = xx [ 25 ] * xx [ 21 ] ; xx [
28 ] = xx [ 25 ] * state [ 3 ] ; xx [ 25 ] = xx [ 28 ] * xx [ 21 ] ; xx [ 29
] = xx [ 15 ] * state [ 3 ] + xx [ 22 ] * state [ 3 ] ; xx [ 15 ] = xx [ 21 ]
* xx [ 29 ] ; output [ 6 ] = state [ 0 ] ; output [ 7 ] = state [ 1 ] ;
output [ 14 ] = state [ 2 ] ; output [ 15 ] = state [ 3 ] ; output [ 22 ] = -
xx [ 3 ] ; output [ 23 ] = xx [ 5 ] ; output [ 24 ] = xx [ 6 ] ; output [ 25
] = xx [ 5 ] ; output [ 26 ] = xx [ 5 ] ; output [ 27 ] = - state [ 1 ] ;
output [ 28 ] = xx [ 5 ] ; output [ 32 ] = - ( xx [ 2 ] * xx [ 3 ] * xx [ 8 ]
+ xx [ 2 ] * xx [ 11 ] * xx [ 6 ] + xx [ 13 ] ) ; output [ 33 ] = xx [ 5 ] ;
output [ 34 ] = xx [ 2 ] * xx [ 3 ] * xx [ 11 ] - xx [ 2 ] * xx [ 8 ] * xx [
6 ] - 6.640000000000001 ; output [ 35 ] = - ( xx [ 16 ] + ( xx [ 3 ] * xx [
10 ] - xx [ 18 ] * xx [ 6 ] ) * xx [ 2 ] ) ; output [ 36 ] = xx [ 5 ] ;
output [ 37 ] = xx [ 17 ] - xx [ 2 ] * ( xx [ 3 ] * xx [ 18 ] + xx [ 10 ] *
xx [ 6 ] ) ; output [ 41 ] = - xx [ 1 ] ; output [ 42 ] = xx [ 5 ] ; output [
43 ] = xx [ 21 ] ; output [ 44 ] = xx [ 5 ] ; output [ 45 ] = xx [ 5 ] ;
output [ 46 ] = - state [ 3 ] ; output [ 47 ] = xx [ 5 ] ; output [ 51 ] = xx
[ 13 ] - ( xx [ 2 ] * xx [ 1 ] * xx [ 20 ] + ( xx [ 1 ] * xx [ 23 ] - xx [ 26
] * xx [ 21 ] ) * xx [ 2 ] ) ; output [ 52 ] = xx [ 5 ] ; output [ 53 ] = - (
xx [ 2 ] * ( xx [ 1 ] * xx [ 26 ] + xx [ 23 ] * xx [ 21 ] ) + xx [ 2 ] * xx [
20 ] * xx [ 21 ] + 6.64 ) ; output [ 54 ] = ( xx [ 1 ] * xx [ 25 ] + xx [ 15
] * xx [ 21 ] ) * xx [ 2 ] - xx [ 29 ] ; output [ 55 ] = xx [ 5 ] ; output [
56 ] = xx [ 2 ] * ( xx [ 25 ] * xx [ 21 ] - xx [ 1 ] * xx [ 15 ] ) - xx [ 28
] ; output [ 60 ] = 1.0 ; output [ 61 ] = xx [ 5 ] ; output [ 62 ] = xx [ 5 ]
; output [ 63 ] = xx [ 5 ] ; output [ 64 ] = xx [ 5 ] ; output [ 65 ] = xx [
5 ] ; output [ 66 ] = xx [ 5 ] ; output [ 70 ] = xx [ 5 ] ; output [ 71 ] =
xx [ 5 ] ; output [ 72 ] = - 12.74 ; output [ 73 ] = xx [ 5 ] ; output [ 74 ]
= xx [ 5 ] ; output [ 75 ] = xx [ 5 ] ; return NULL ; }
