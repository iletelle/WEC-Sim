#include "__cf_RM3.h"
#include <math.h>
#include <string.h>
#include "pm_std.h"
#include "sm_std.h"
#include "sm_ssci_run_time_errors.h"
void RM3_fa9b5af1_1_resetStateVector ( const void * mech , double * state ) {
double xx [ 1 ] ; ( void ) mech ; xx [ 0 ] = 0.0 ; state [ 0 ] = xx [ 0 ] ;
state [ 1 ] = xx [ 0 ] ; state [ 2 ] = xx [ 0 ] ; state [ 3 ] = xx [ 0 ] ; }
PmfMessageId RM3_fa9b5af1_1_initializeTrackedAngleState ( const void * mech ,
double * state , void * neDiagMgr0 ) { NeuDiagnosticManager * neDiagMgr = (
NeuDiagnosticManager * ) neDiagMgr0 ; ( void ) mech ; ( void ) state ; return
NULL ; } void RM3_fa9b5af1_1_computeDiscreteState ( const void * mech ,
double * state ) { ( void ) mech ; ( void ) state ; } void
RM3_fa9b5af1_1_adjustPosition ( const void * mech , const double * dofDeltas
, double * state ) { ( void ) mech ; state [ 0 ] = state [ 0 ] + dofDeltas [
0 ] ; state [ 2 ] = state [ 2 ] + dofDeltas [ 1 ] ; } static void
perturbState_0_0 ( double mag , double * state ) { state [ 0 ] = state [ 0 ]
+ mag ; } static void perturbState_0_0v ( double mag , double * state ) {
state [ 0 ] = state [ 0 ] + mag ; state [ 1 ] = state [ 1 ] - 0.875 * mag ; }
static void perturbState_1_0 ( double mag , double * state ) { state [ 2 ] =
state [ 2 ] + mag ; } static void perturbState_1_0v ( double mag , double *
state ) { state [ 2 ] = state [ 2 ] + mag ; state [ 3 ] = state [ 3 ] - 0.875
* mag ; } void RM3_fa9b5af1_1_perturbState ( const void * mech , size_t
stageIdx , size_t primIdx , double mag , bool doPerturbVelocity , double *
state ) { ( void ) mech ; ( void ) stageIdx ; ( void ) primIdx ; ( void ) mag
; ( void ) doPerturbVelocity ; ( void ) state ; switch ( ( stageIdx * 6 +
primIdx ) * 2 + ( doPerturbVelocity ? 1 : 0 ) ) { case 0 : perturbState_0_0 (
mag , state ) ; break ; case 1 : perturbState_0_0v ( mag , state ) ; break ;
case 12 : perturbState_1_0 ( mag , state ) ; break ; case 13 :
perturbState_1_0v ( mag , state ) ; break ; } } void
RM3_fa9b5af1_1_propagateMotion ( const void * mech , const double * state ,
double * motionData ) { double xx [ 3 ] ; ( void ) mech ; xx [ 0 ] = 1.0 ; xx
[ 1 ] = - xx [ 0 ] ; xx [ 2 ] = 0.0 ; motionData [ 0 ] = xx [ 1 ] ;
motionData [ 1 ] = xx [ 2 ] ; motionData [ 2 ] = xx [ 2 ] ; motionData [ 3 ]
= xx [ 2 ] ; motionData [ 4 ] = xx [ 2 ] ; motionData [ 5 ] = xx [ 2 ] ;
motionData [ 6 ] = state [ 0 ] - 21.29 ; motionData [ 7 ] = xx [ 1 ] ;
motionData [ 8 ] = xx [ 2 ] ; motionData [ 9 ] = xx [ 2 ] ; motionData [ 10 ]
= xx [ 2 ] ; motionData [ 11 ] = xx [ 2 ] ; motionData [ 12 ] = xx [ 2 ] ;
motionData [ 13 ] = 20.57 + state [ 2 ] ; motionData [ 14 ] = xx [ 0 ] ;
motionData [ 15 ] = xx [ 2 ] ; motionData [ 16 ] = xx [ 2 ] ; motionData [ 17
] = xx [ 2 ] ; motionData [ 18 ] = xx [ 2 ] ; motionData [ 19 ] = xx [ 2 ] ;
motionData [ 20 ] = state [ 2 ] + state [ 0 ] - 0.7199999999999989 ;
motionData [ 21 ] = xx [ 2 ] ; motionData [ 22 ] = xx [ 2 ] ; motionData [ 23
] = xx [ 2 ] ; motionData [ 24 ] = xx [ 2 ] ; motionData [ 25 ] = xx [ 2 ] ;
motionData [ 26 ] = state [ 1 ] ; motionData [ 27 ] = xx [ 2 ] ; motionData [
28 ] = xx [ 2 ] ; motionData [ 29 ] = xx [ 2 ] ; motionData [ 30 ] = xx [ 2 ]
; motionData [ 31 ] = xx [ 2 ] ; motionData [ 32 ] = state [ 1 ] + state [ 3
] ; } size_t RM3_fa9b5af1_1_computeAssemblyError ( const void * mech , size_t
constraintIdx , const double * state , const double * motionData , double *
error ) { ( void ) mech ; ( void ) state ; ( void ) motionData ; ( void )
error ; ( void ) state ; switch ( constraintIdx ) { } return 0 ; } size_t
RM3_fa9b5af1_1_computeAssemblyJacobian ( const void * mech , size_t
constraintIdx , bool forVelocitySatisfaction , const double * state , const
double * motionData , double * J ) { ( void ) mech ; ( void ) state ; ( void
) forVelocitySatisfaction ; ( void ) motionData ; ( void ) J ; switch (
constraintIdx ) { } return 0 ; } size_t
RM3_fa9b5af1_1_computeFullAssemblyJacobian ( const void * mech , const double
* state , const double * motionData , double * J ) { ( void ) mech ; ( void )
state ; ( void ) motionData ; ( void ) J ; return 0 ; } PmfMessageId
RM3_fa9b5af1_1_convertStateVector ( const void * asmMech , const void *
simMech , const double * asmState , double * simState , void * neDiagMgr0 ) {
NeuDiagnosticManager * neDiagMgr = ( NeuDiagnosticManager * ) neDiagMgr0 ; (
void ) asmMech ; ( void ) simMech ; simState [ 0 ] = asmState [ 0 ] ;
simState [ 1 ] = asmState [ 1 ] ; simState [ 2 ] = asmState [ 2 ] ; simState
[ 3 ] = asmState [ 3 ] ; return NULL ; } void
RM3_fa9b5af1_1_constructStateVector ( const void * mech , const double *
solverState , const double * u , const double * uDot , double * discreteState
, double * fullState ) { ( void ) mech ; ( void ) u ; ( void ) uDot ; ( void
) discreteState ; fullState [ 0 ] = solverState [ 0 ] ; fullState [ 1 ] =
solverState [ 1 ] ; fullState [ 2 ] = solverState [ 2 ] ; fullState [ 3 ] =
solverState [ 3 ] ; } void RM3_fa9b5af1_1_extractSolverStateVector ( const
void * mech , const double * fullState , double * solverState ) { ( void )
mech ; solverState [ 0 ] = fullState [ 0 ] ; solverState [ 1 ] = fullState [
1 ] ; solverState [ 2 ] = fullState [ 2 ] ; solverState [ 3 ] = fullState [ 3
] ; } int RM3_fa9b5af1_1_isPositionViolation ( const void * mech , const
double * state ) { ( void ) mech ; ( void ) state ; return 0 ; } int
RM3_fa9b5af1_1_isVelocityViolation ( const void * mech , const double * state
) { ( void ) mech ; ( void ) state ; return 0 ; } PmfMessageId
RM3_fa9b5af1_1_projectStateSim ( const void * mech , const double * input ,
double * state , void * neDiagMgr0 ) { NeuDiagnosticManager * neDiagMgr = (
NeuDiagnosticManager * ) neDiagMgr0 ; ( void ) mech ; ( void ) input ; ( void
) state ; return NULL ; }
