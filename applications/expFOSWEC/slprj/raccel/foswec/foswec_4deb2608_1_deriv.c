#include "__cf_foswec.h"
#include <math.h>
#include <string.h>
#include "pm_std.h"
#include "sm_std.h"
#include "sm_ssci_run_time_errors.h"
PmfMessageId foswec_4deb2608_1_deriv ( const double * state , const double *
input , const double * inputDot , const double * inputDdot , const double *
discreteState , double * deriv , NeuDiagnosticManager * neDiagMgr ) { double
xx [ 21 ] ; int ii [ 4 ] ; ( void ) inputDot ; ( void ) inputDdot ; ( void )
discreteState ; ( void ) neDiagMgr ; xx [ 0 ] = 0.5 ; xx [ 1 ] = xx [ 0 ] *
state [ 0 ] ; xx [ 2 ] = cos ( xx [ 1 ] ) ; xx [ 3 ] = sin ( xx [ 1 ] ) ; xx
[ 1 ] = xx [ 3 ] * input [ 0 ] ; xx [ 4 ] = xx [ 3 ] * input [ 2 ] ; xx [ 6 ]
= 2.0 ; xx [ 9 ] = 9.360000000000001 ; xx [ 11 ] = 7.589466606277583e8 ;
memcpy ( ii + 2 , ii + 0 , 1 * sizeof ( int ) ) ; ii [ 1 ] = factorSymmetric
( xx + 11 , 1 , xx + 14 , xx + 13 , ii + 2 , ii + 3 ) ; if ( ii [ 3 ] != 0 )
{ return sm_ssci_recordRunTimeError (
"sm:compiler:messages:simulationErrors:DegenerateMass" ,
 "'foswec/Rotational PTO (Local RY)/Pitch PCC  (Revolute Joint)' has a degenerate mass distribution on its follower side."
, neDiagMgr ) ; } xx [ 12 ] = xx [ 0 ] * state [ 2 ] ; xx [ 0 ] = cos ( xx [
12 ] ) ; xx [ 13 ] = sin ( xx [ 12 ] ) ; xx [ 12 ] = xx [ 13 ] * input [ 8 ]
; xx [ 14 ] = xx [ 13 ] * input [ 6 ] ; xx [ 16 ] = input [ 6 ] + xx [ 6 ] *
( xx [ 0 ] * xx [ 12 ] - xx [ 14 ] * xx [ 13 ] ) ; xx [ 15 ] =
7.589454010661583e8 ; ii [ 1 ] = factorSymmetric ( xx + 15 , 1 , xx + 19 , xx
+ 18 , ii + 0 , ii + 2 ) ; if ( ii [ 2 ] != 0 ) { return
sm_ssci_recordRunTimeError (
"sm:compiler:messages:simulationErrors:DegenerateMass" ,
 "'foswec/Rotational PTO (Local RY)1/Pitch PCC  (Revolute Joint)' has a degenerate mass distribution on its follower side."
, neDiagMgr ) ; } deriv [ 0 ] = state [ 1 ] ; deriv [ 1 ] = - ( input [ 4 ] -
3.552713678800501e-15 * ( input [ 2 ] - ( xx [ 2 ] * xx [ 1 ] + xx [ 4 ] * xx
[ 3 ] ) * xx [ 6 ] ) + ( input [ 0 ] + xx [ 6 ] * ( xx [ 2 ] * xx [ 4 ] - xx
[ 1 ] * xx [ 3 ] ) ) * xx [ 9 ] ) / xx [ 11 ] ; deriv [ 2 ] = state [ 3 ] ;
deriv [ 3 ] = - ( xx [ 16 ] * 8.881784197001335e-16 + 3.552713678800499e-15 *
( input [ 8 ] - ( xx [ 0 ] * xx [ 14 ] + xx [ 12 ] * xx [ 13 ] ) * xx [ 6 ] )
+ input [ 10 ] + xx [ 16 ] * xx [ 9 ] ) / xx [ 15 ] ; return NULL ; }
