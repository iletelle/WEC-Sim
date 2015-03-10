#include "__cf_RM3.h"
#include <math.h>
#include <string.h>
#include "pm_std.h"
#include "sm_std.h"
#include "sm_ssci_run_time_errors.h"
PmfMessageId RM3_fa9b5af1_1_outputKin ( const double * state , const double *
input , const double * inputDot , const double * inputDdot , const double *
discreteState , double * output , NeuDiagnosticManager * neDiagMgr ) { double
xx [ 4 ] ; ( void ) input ; ( void ) inputDot ; ( void ) inputDdot ; ( void )
discreteState ; ( void ) neDiagMgr ; xx [ 0 ] = 0.0 ; xx [ 1 ] = 1.0 ; xx [ 3
] = 0.0 ; output [ 6 ] = state [ 2 ] ; output [ 7 ] = state [ 3 ] ; output [
14 ] = - xx [ 1 ] ; output [ 15 ] = xx [ 3 ] ; output [ 16 ] = xx [ 3 ] ;
output [ 17 ] = xx [ 3 ] ; output [ 18 ] = xx [ 3 ] ; output [ 19 ] = xx [ 3
] ; output [ 20 ] = xx [ 3 ] ; output [ 24 ] = xx [ 3 ] ; output [ 25 ] = xx
[ 3 ] ; output [ 26 ] = state [ 2 ] + state [ 0 ] - 0.7199999999999989 ;
output [ 27 ] = xx [ 3 ] ; output [ 28 ] = xx [ 3 ] ; output [ 29 ] = state [
1 ] + state [ 3 ] ; output [ 33 ] = xx [ 1 ] ; output [ 34 ] = xx [ 3 ] ;
output [ 35 ] = xx [ 3 ] ; output [ 36 ] = xx [ 3 ] ; output [ 37 ] = xx [ 3
] ; output [ 38 ] = xx [ 3 ] ; output [ 39 ] = xx [ 3 ] ; output [ 43 ] = xx
[ 3 ] ; output [ 44 ] = xx [ 3 ] ; output [ 45 ] = state [ 0 ] - 21.29 ;
output [ 46 ] = xx [ 3 ] ; output [ 47 ] = xx [ 3 ] ; output [ 48 ] = state [
1 ] ; return NULL ; }
