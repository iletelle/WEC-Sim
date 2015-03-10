#include "__cf_foswec.h"
#include <math.h>
#include <string.h>
#include "pm_std.h"
#include "sm_std.h"
#include "sm_ssci_run_time_errors.h"
void foswec_4deb2608_1_resetStateVector ( const void * mech , double * state
) { double xx [ 1 ] ; ( void ) mech ; xx [ 0 ] = 0.0 ; state [ 0 ] = xx [ 0 ]
; state [ 1 ] = xx [ 0 ] ; state [ 2 ] = xx [ 0 ] ; state [ 3 ] = xx [ 0 ] ;
} PmfMessageId foswec_4deb2608_1_initializeTrackedAngleState ( const void *
mech , double * state , void * neDiagMgr0 ) { NeuDiagnosticManager *
neDiagMgr = ( NeuDiagnosticManager * ) neDiagMgr0 ; ( void ) mech ; ( void )
state ; return NULL ; } void foswec_4deb2608_1_computeDiscreteState ( const
void * mech , double * state ) { ( void ) mech ; ( void ) state ; } void
foswec_4deb2608_1_adjustPosition ( const void * mech , const double *
dofDeltas , double * state ) { ( void ) mech ; state [ 0 ] = state [ 0 ] +
dofDeltas [ 0 ] ; state [ 2 ] = state [ 2 ] + dofDeltas [ 1 ] ; } static void
perturbState_1_0 ( double mag , double * state ) { state [ 0 ] = state [ 0 ]
+ mag ; } static void perturbState_1_0v ( double mag , double * state ) {
state [ 0 ] = state [ 0 ] + mag ; state [ 1 ] = state [ 1 ] - 0.875 * mag ; }
static void perturbState_2_0 ( double mag , double * state ) { state [ 2 ] =
state [ 2 ] + mag ; } static void perturbState_2_0v ( double mag , double *
state ) { state [ 2 ] = state [ 2 ] + mag ; state [ 3 ] = state [ 3 ] - 0.875
* mag ; } void foswec_4deb2608_1_perturbState ( const void * mech , size_t
stageIdx , size_t primIdx , double mag , bool doPerturbVelocity , double *
state ) { ( void ) mech ; ( void ) stageIdx ; ( void ) primIdx ; ( void ) mag
; ( void ) doPerturbVelocity ; ( void ) state ; switch ( ( stageIdx * 6 +
primIdx ) * 2 + ( doPerturbVelocity ? 1 : 0 ) ) { case 12 : perturbState_1_0
( mag , state ) ; break ; case 13 : perturbState_1_0v ( mag , state ) ; break
; case 24 : perturbState_2_0 ( mag , state ) ; break ; case 25 :
perturbState_2_0v ( mag , state ) ; break ; } } void
foswec_4deb2608_1_propagateMotion ( const void * mech , const double * state
, double * motionData ) { double xx [ 18 ] ; ( void ) mech ; xx [ 0 ] = 0.0 ;
xx [ 1 ] = 0.5 ; xx [ 2 ] = xx [ 1 ] * state [ 0 ] ; xx [ 3 ] = cos ( xx [ 2
] ) ; xx [ 5 ] = sin ( xx [ 2 ] ) ; xx [ 2 ] = 20.0 ; xx [ 6 ] = 2.0 ; xx [ 7
] = 9.359999999999999 ; xx [ 8 ] = xx [ 7 ] * xx [ 5 ] ; xx [ 10 ] = - ( xx [
2 ] + xx [ 6 ] * xx [ 3 ] * xx [ 8 ] ) ; xx [ 9 ] = 3.26 ; xx [ 11 ] = xx [ 6
] * xx [ 8 ] * xx [ 5 ] - xx [ 7 ] ; xx [ 8 ] = xx [ 1 ] * state [ 2 ] ; xx [
1 ] = cos ( xx [ 8 ] ) ; xx [ 13 ] = sin ( xx [ 8 ] ) ; xx [ 8 ] = xx [ 7 ] *
xx [ 13 ] ; xx [ 14 ] = xx [ 2 ] - xx [ 6 ] * xx [ 1 ] * xx [ 8 ] ; xx [ 15 ]
= xx [ 6 ] * xx [ 8 ] * xx [ 13 ] - xx [ 7 ] ; xx [ 7 ] = 16.0 ; xx [ 17 ] =
9.360000000000001 ; motionData [ 0 ] = - 1.0 ; motionData [ 1 ] = xx [ 0 ] ;
motionData [ 2 ] = xx [ 0 ] ; motionData [ 3 ] = xx [ 0 ] ; motionData [ 4 ]
= xx [ 0 ] ; motionData [ 5 ] = xx [ 0 ] ; motionData [ 6 ] = - 12.74 ;
motionData [ 7 ] = - xx [ 3 ] ; motionData [ 8 ] = xx [ 0 ] ; motionData [ 9
] = xx [ 5 ] ; motionData [ 10 ] = xx [ 0 ] ; motionData [ 11 ] = xx [ 10 ] ;
motionData [ 12 ] = xx [ 0 ] ; motionData [ 13 ] = - ( xx [ 9 ] + xx [ 11 ] )
; motionData [ 14 ] = - xx [ 1 ] ; motionData [ 15 ] = xx [ 0 ] ; motionData
[ 16 ] = xx [ 13 ] ; motionData [ 17 ] = xx [ 0 ] ; motionData [ 18 ] = xx [
14 ] ; motionData [ 19 ] = xx [ 0 ] ; motionData [ 20 ] = - ( xx [ 9 ] + xx [
15 ] ) ; motionData [ 21 ] = xx [ 3 ] ; motionData [ 22 ] = xx [ 0 ] ;
motionData [ 23 ] = - xx [ 5 ] ; motionData [ 24 ] = xx [ 0 ] ; motionData [
25 ] = xx [ 10 ] ; motionData [ 26 ] = xx [ 0 ] ; motionData [ 27 ] = - ( xx
[ 7 ] + xx [ 11 ] ) ; motionData [ 28 ] = xx [ 1 ] ; motionData [ 29 ] = xx [
0 ] ; motionData [ 30 ] = - xx [ 13 ] ; motionData [ 31 ] = xx [ 0 ] ;
motionData [ 32 ] = xx [ 14 ] ; motionData [ 33 ] = xx [ 0 ] ; motionData [
34 ] = - ( xx [ 7 ] + xx [ 15 ] ) ; motionData [ 35 ] = xx [ 0 ] ; motionData
[ 36 ] = xx [ 0 ] ; motionData [ 37 ] = xx [ 0 ] ; motionData [ 38 ] = xx [ 0
] ; motionData [ 39 ] = xx [ 0 ] ; motionData [ 40 ] = xx [ 0 ] ; motionData
[ 41 ] = xx [ 0 ] ; motionData [ 42 ] = - state [ 1 ] ; motionData [ 43 ] =
xx [ 0 ] ; motionData [ 44 ] = - xx [ 17 ] * state [ 1 ] ; motionData [ 45 ]
= xx [ 0 ] ; motionData [ 46 ] = xx [ 0 ] ; motionData [ 47 ] = xx [ 0 ] ;
motionData [ 48 ] = - state [ 3 ] ; motionData [ 49 ] = xx [ 0 ] ; motionData
[ 50 ] = - xx [ 17 ] * state [ 3 ] ; motionData [ 51 ] = xx [ 0 ] ;
motionData [ 52 ] = xx [ 0 ] ; } size_t
foswec_4deb2608_1_computeAssemblyError ( const void * mech , size_t
constraintIdx , const double * state , const double * motionData , double *
error ) { ( void ) mech ; ( void ) state ; ( void ) motionData ; ( void )
error ; ( void ) state ; switch ( constraintIdx ) { } return 0 ; } size_t
foswec_4deb2608_1_computeAssemblyJacobian ( const void * mech , size_t
constraintIdx , bool forVelocitySatisfaction , const double * state , const
double * motionData , double * J ) { ( void ) mech ; ( void ) state ; ( void
) forVelocitySatisfaction ; ( void ) motionData ; ( void ) J ; switch (
constraintIdx ) { } return 0 ; } size_t
foswec_4deb2608_1_computeFullAssemblyJacobian ( const void * mech , const
double * state , const double * motionData , double * J ) { ( void ) mech ; (
void ) state ; ( void ) motionData ; ( void ) J ; return 0 ; } PmfMessageId
foswec_4deb2608_1_convertStateVector ( const void * asmMech , const void *
simMech , const double * asmState , double * simState , void * neDiagMgr0 ) {
NeuDiagnosticManager * neDiagMgr = ( NeuDiagnosticManager * ) neDiagMgr0 ; (
void ) asmMech ; ( void ) simMech ; simState [ 0 ] = asmState [ 0 ] ;
simState [ 1 ] = asmState [ 1 ] ; simState [ 2 ] = asmState [ 2 ] ; simState
[ 3 ] = asmState [ 3 ] ; return NULL ; } void
foswec_4deb2608_1_constructStateVector ( const void * mech , const double *
solverState , const double * u , const double * uDot , double * discreteState
, double * fullState ) { ( void ) mech ; ( void ) u ; ( void ) uDot ; ( void
) discreteState ; fullState [ 0 ] = solverState [ 0 ] ; fullState [ 1 ] =
solverState [ 1 ] ; fullState [ 2 ] = solverState [ 2 ] ; fullState [ 3 ] =
solverState [ 3 ] ; } void foswec_4deb2608_1_extractSolverStateVector ( const
void * mech , const double * fullState , double * solverState ) { ( void )
mech ; solverState [ 0 ] = fullState [ 0 ] ; solverState [ 1 ] = fullState [
1 ] ; solverState [ 2 ] = fullState [ 2 ] ; solverState [ 3 ] = fullState [ 3
] ; } int foswec_4deb2608_1_isPositionViolation ( const void * mech , const
double * state ) { ( void ) mech ; ( void ) state ; return 0 ; } int
foswec_4deb2608_1_isVelocityViolation ( const void * mech , const double *
state ) { ( void ) mech ; ( void ) state ; return 0 ; } PmfMessageId
foswec_4deb2608_1_projectStateSim ( const void * mech , const double * input
, double * state , void * neDiagMgr0 ) { NeuDiagnosticManager * neDiagMgr = (
NeuDiagnosticManager * ) neDiagMgr0 ; ( void ) mech ; ( void ) input ; ( void
) state ; return NULL ; }
