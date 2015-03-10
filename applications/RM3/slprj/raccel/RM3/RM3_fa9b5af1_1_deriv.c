#include "__cf_RM3.h"
#include <math.h>
#include <string.h>
#include "pm_std.h"
#include "sm_std.h"
#include "sm_ssci_run_time_errors.h"
PmfMessageId RM3_fa9b5af1_1_deriv ( const double * state , const double *
input , const double * inputDot , const double * inputDdot , const double *
discreteState , double * deriv , NeuDiagnosticManager * neDiagMgr ) { double
xx [ 9 ] ; int ii [ 4 ] ; ( void ) inputDot ; ( void ) inputDdot ; ( void )
discreteState ; ( void ) neDiagMgr ; xx [ 0 ] = 1.944555e6 ; memcpy ( xx + 2
, xx + 0 , 1 * sizeof ( double ) ) ; memcpy ( ii + 2 , ii + 0 , 1 * sizeof (
int ) ) ; ii [ 1 ] = factorSymmetric ( xx + 2 , 1 , xx + 4 , xx + 3 , ii + 2
, ii + 3 ) ; if ( ii [ 3 ] != 0 ) { return sm_ssci_recordRunTimeError (
"sm:compiler:messages:simulationErrors:DegenerateMass" ,
 "'RM3/Translational PTO  (Local Z)/Translational PCC (Prismatic Joint)' has a degenerate mass distribution on its follower side."
, neDiagMgr ) ; } xx [ 1 ] = ( input [ 2 ] - 1.2e6 * state [ 3 ] ) / xx [ 2 ]
; xx [ 3 ] = xx [ 0 ] / xx [ 2 ] ; xx [ 5 ] = 1.2188655e7 - xx [ 0 ] * xx [ 3
] ; ii [ 1 ] = factorSymmetric ( xx + 5 , 1 , xx + 7 , xx + 4 , ii + 0 , ii +
2 ) ; if ( ii [ 2 ] != 0 ) { return sm_ssci_recordRunTimeError (
"sm:compiler:messages:simulationErrors:DegenerateMass" ,
 "'RM3/Heave/Translational Constraint (Prismatic Joint)' has a degenerate mass distribution on its follower side."
, neDiagMgr ) ; } xx [ 4 ] = ( xx [ 0 ] * xx [ 1 ] - input [ 2 ] - input [ 8
] ) / xx [ 5 ] ; deriv [ 0 ] = state [ 1 ] ; deriv [ 1 ] = - xx [ 4 ] ; deriv
[ 2 ] = state [ 3 ] ; deriv [ 3 ] = xx [ 1 ] + xx [ 3 ] * xx [ 4 ] ; return
NULL ; }
