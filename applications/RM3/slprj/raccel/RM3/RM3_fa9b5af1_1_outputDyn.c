#include "__cf_RM3.h"
#include <math.h>
#include <string.h>
#include "pm_std.h"
#include "sm_std.h"
#include "sm_ssci_run_time_errors.h"
PmfMessageId RM3_fa9b5af1_1_outputDyn ( const double * state , const double *
input , const double * inputDot , const double * inputDdot , const double *
discreteState , double * deriv , double * output , int * derivErr ,
NeuDiagnosticManager * neDiagMgr ) { double xx [ 12 ] ; int ii [ 7 ] ; ( void
) inputDot ; ( void ) inputDdot ; ( void ) discreteState ; ( void ) neDiagMgr
; ( void ) derivErr ; xx [ 0 ] = 1.944555e6 ; ii [ 0 ] = 0 ; memcpy ( xx + 2
, xx + 0 , 1 * sizeof ( double ) ) ; memcpy ( ii + 3 , ii + 0 , 1 * sizeof (
int ) ) ; ii [ 2 ] = factorSymmetric ( xx + 2 , 1 , xx + 4 , xx + 3 , ii + 3
, ii + 4 ) ; memcpy ( xx + 4 , xx + 0 , 1 * sizeof ( double ) ) ; ii [ 5 ] =
factorSymmetric ( xx + 4 , 1 , xx + 6 , xx + 5 , ii + 3 , ii + 6 ) ; if ( ii
[ 6 ] != 0 ) * derivErr = 1 ; xx [ 1 ] = ( input [ 2 ] - 1.2e6 * state [ 3 ]
) / xx [ 4 ] ; xx [ 5 ] = 1.2188655e7 ; xx [ 6 ] = xx [ 0 ] / xx [ 4 ] ; xx [
4 ] = xx [ 5 ] - xx [ 0 ] * xx [ 6 ] ; if ( ii [ 4 ] != 0 ) { return
sm_ssci_recordRunTimeError (
"sm:compiler:messages:simulationErrors:DegenerateMass" ,
 "'RM3/Translational PTO  (Local Z)/Translational PCC (Prismatic Joint)' has a degenerate mass distribution on its follower side."
, neDiagMgr ) ; } xx [ 3 ] = xx [ 5 ] - 3.781294148025e12 / xx [ 2 ] ; memcpy
( ii + 3 , ii + 0 , 1 * sizeof ( int ) ) ; ii [ 2 ] = factorSymmetric ( xx +
3 , 1 , xx + 7 , xx + 5 , ii + 3 , ii + 4 ) ; ii [ 1 ] = factorSymmetric ( xx
+ 4 , 1 , xx + 7 , xx + 3 , ii + 3 , ii + 2 ) ; if ( ii [ 2 ] != 0 ) *
derivErr = 1 ; xx [ 3 ] = ( xx [ 0 ] * xx [ 1 ] - input [ 2 ] - input [ 8 ] )
/ xx [ 4 ] ; xx [ 0 ] = - xx [ 3 ] ; xx [ 2 ] = xx [ 1 ] + xx [ 6 ] * xx [ 3
] ; deriv [ 0 ] = state [ 1 ] ; deriv [ 1 ] = xx [ 0 ] ; deriv [ 2 ] = state
[ 3 ] ; deriv [ 3 ] = xx [ 2 ] ; xx [ 1 ] = 20.57 + state [ 2 ] ; xx [ 4 ] =
21.29 ; xx [ 5 ] = state [ 0 ] - xx [ 4 ] ; xx [ 6 ] = input [ 7 ] + input [
1 ] ; xx [ 8 ] = input [ 6 ] + input [ 0 ] ; xx [ 10 ] = 0.0 ; xx [ 11 ] = xx
[ 4 ] - xx [ 1 ] ; output [ 0 ] = xx [ 1 ] * input [ 1 ] - input [ 3 ] -
input [ 9 ] + xx [ 5 ] * xx [ 6 ] ; output [ 1 ] = - ( input [ 10 ] + input [
4 ] + xx [ 1 ] * input [ 0 ] + xx [ 5 ] * xx [ 8 ] ) ; output [ 2 ] = - (
input [ 11 ] + input [ 5 ] ) ; output [ 3 ] = - xx [ 8 ] ; output [ 4 ] = -
xx [ 6 ] ; output [ 5 ] = xx [ 10 ] ; output [ 8 ] = - ( input [ 3 ] + xx [
11 ] * input [ 1 ] ) ; output [ 9 ] = xx [ 11 ] * input [ 0 ] - input [ 4 ] ;
output [ 10 ] = - input [ 5 ] ; output [ 11 ] = - input [ 0 ] ; output [ 12 ]
= - input [ 1 ] ; output [ 13 ] = xx [ 10 ] ; output [ 21 ] = xx [ 10 ] ;
output [ 22 ] = xx [ 10 ] ; output [ 23 ] = xx [ 10 ] ; output [ 30 ] = xx [
10 ] ; output [ 31 ] = xx [ 10 ] ; output [ 32 ] = xx [ 2 ] - xx [ 3 ] ;
output [ 40 ] = xx [ 10 ] ; output [ 41 ] = xx [ 10 ] ; output [ 42 ] = xx [
10 ] ; output [ 49 ] = xx [ 10 ] ; output [ 50 ] = xx [ 10 ] ; output [ 51 ]
= xx [ 0 ] ; return NULL ; }
