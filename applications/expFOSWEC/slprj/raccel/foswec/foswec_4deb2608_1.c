#include "__cf_foswec.h"
#include "ne_std.h"
#include "ne_default_allocator.h"
#include "ne_dae.h"
#include "ne_solverparameters.h"
#include "sm_ssci_NeDaePrivateData.h"
NeDae * sm_ssci_constructDae ( NeDaePrivateData * smData ) ; void
foswec_4deb2608_1_NeDaePrivateData_create ( NeDaePrivateData * smData ) ;
void foswec_4deb2608_1_dae ( NeDae * * dae , const NeModelParameters *
modelParams , const NeSolverParameters * solverParams , const NeLinearAlgebra
* linear_algebra_ptr ) { NeAllocator * alloc = ne_default_allocator ( ) ;
NeDaePrivateData * smData = ( NeDaePrivateData * ) alloc -> mCallocFcn (
alloc , sizeof ( NeDaePrivateData ) , 1 ) ; ( void ) modelParams ; ( void )
solverParams ; ( void ) linear_algebra_ptr ;
foswec_4deb2608_1_NeDaePrivateData_create ( smData ) ; * dae =
sm_ssci_constructDae ( smData ) ; }
