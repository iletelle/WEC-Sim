#include "__cf_RM3.h"
#include "rt_logging_mmi.h"
#include "RM3_capi.h"
#include <math.h>
#include "RM3.h"
#include "RM3_private.h"
#include "RM3_dt.h"
const int_T gblNumToFiles = 0 ; const int_T gblNumFrFiles = 0 ; const int_T
gblNumFrWksBlocks = 0 ;
#ifdef RSIM_WITH_SOLVER_MULTITASKING
boolean_T gbl_raccel_isMultitasking = 1 ;
#else
boolean_T gbl_raccel_isMultitasking = 0 ;
#endif
boolean_T gbl_raccel_tid01eq = 1 ; int_T gbl_raccel_NumST = 2 ; const char_T
* gbl_raccel_Version = "8.7 (R2014b) 08-Sep-2014" ; void
raccel_setup_MMIStateLog ( SimStruct * S ) {
#ifdef UseMMIDataLogging
rt_FillStateSigInfoFromMMI ( ssGetRTWLogInfo ( S ) , & ssGetErrorStatus ( S )
) ;
#endif
} static DataMapInfo rt_dataMapInfo ; DataMapInfo * rt_dataMapInfoPtr = &
rt_dataMapInfo ; rtwCAPI_ModelMappingInfo * rt_modelMapInfoPtr = & (
rt_dataMapInfo . mmi ) ; const char * gblSlvrJacPatternFileName =
"slprj\\raccel\\RM3\\RM3_Jpattern.mat" ; const int_T gblNumRootInportBlks = 0
; const int_T gblNumModelInputs = 0 ; extern rtInportTUtable *
gblInportTUtables ; extern const char * gblInportFileName ; const int_T
gblInportDataTypeIdx [ ] = { - 1 } ; const int_T gblInportDims [ ] = { - 1 }
; const int_T gblInportComplex [ ] = { - 1 } ; const int_T
gblInportInterpoFlag [ ] = { - 1 } ; const int_T gblInportContinuous [ ] = {
- 1 } ;
#include "simstruc.h"
#include "fixedpoint.h"
B rtB ; X rtX ; DW rtDW ; static SimStruct model_S ; SimStruct * const rtS =
& model_S ; static real_T aj44waf3ba ( const real_T x [ 6 ] ) ; static real_T
bkodxw3pn1 ( const real_T x [ 601 ] , const real_T y [ 601 ] ) ; static
real_T f1pbdll3kt ( const real_T x [ 6 ] ) ; static real_T ctqhiaiar1 ( const
real_T x [ 601 ] , const real_T y [ 601 ] ) ;
#ifndef __RTW_UTFREE__  
extern void * utMalloc ( size_t ) ;
#endif
void * rt_TDelayCreateBuf ( int_T numBuffer , int_T bufSz , int_T elemSz ) {
return ( ( void * ) utMalloc ( numBuffer * bufSz * elemSz ) ) ; }
#ifndef __RTW_UTFREE__  
extern void * utMalloc ( size_t ) ; extern void utFree ( void * ) ;
#endif
boolean_T rt_TDelayUpdateTailOrGrowBuf ( int_T * bufSzPtr , int_T * tailPtr ,
int_T * headPtr , int_T * lastPtr , real_T tMinusDelay , real_T * * tBufPtr ,
real_T * * uBufPtr , real_T * * xBufPtr , boolean_T isfixedbuf , boolean_T
istransportdelay , int_T * maxNewBufSzPtr ) { int_T testIdx ; int_T tail = *
tailPtr ; int_T bufSz = * bufSzPtr ; real_T * tBuf = * tBufPtr ; real_T *
xBuf = ( NULL ) ; int_T numBuffer = 2 ; if ( istransportdelay ) { numBuffer =
3 ; xBuf = * xBufPtr ; } testIdx = ( tail < ( bufSz - 1 ) ) ? ( tail + 1 ) :
0 ; if ( ( tMinusDelay <= tBuf [ testIdx ] ) && ! isfixedbuf ) { int_T j ;
real_T * tempT ; real_T * tempU ; real_T * tempX = ( NULL ) ; real_T * uBuf =
* uBufPtr ; int_T newBufSz = bufSz + 1024 ; if ( newBufSz > * maxNewBufSzPtr
) { * maxNewBufSzPtr = newBufSz ; } tempU = ( real_T * ) utMalloc ( numBuffer
* newBufSz * sizeof ( real_T ) ) ; if ( tempU == ( NULL ) ) { return ( false
) ; } tempT = tempU + newBufSz ; if ( istransportdelay ) tempX = tempT +
newBufSz ; for ( j = tail ; j < bufSz ; j ++ ) { tempT [ j - tail ] = tBuf [
j ] ; tempU [ j - tail ] = uBuf [ j ] ; if ( istransportdelay ) tempX [ j -
tail ] = xBuf [ j ] ; } for ( j = 0 ; j < tail ; j ++ ) { tempT [ j + bufSz -
tail ] = tBuf [ j ] ; tempU [ j + bufSz - tail ] = uBuf [ j ] ; if (
istransportdelay ) tempX [ j + bufSz - tail ] = xBuf [ j ] ; } if ( * lastPtr
> tail ) { * lastPtr -= tail ; } else { * lastPtr += ( bufSz - tail ) ; } *
tailPtr = 0 ; * headPtr = bufSz ; utFree ( uBuf ) ; * bufSzPtr = newBufSz ; *
tBufPtr = tempT ; * uBufPtr = tempU ; if ( istransportdelay ) * xBufPtr =
tempX ; } else { * tailPtr = testIdx ; } return ( true ) ; } real_T
rt_TDelayInterpolate ( real_T tMinusDelay , real_T tStart , real_T * tBuf ,
real_T * uBuf , int_T bufSz , int_T * lastIdx , int_T oldestIdx , int_T
newIdx , real_T initOutput , boolean_T discrete , boolean_T
minorStepAndTAtLastMajorOutput ) { int_T i ; real_T yout , t1 , t2 , u1 , u2
; if ( ( newIdx == 0 ) && ( oldestIdx == 0 ) && ( tMinusDelay > tStart ) )
return initOutput ; if ( tMinusDelay <= tStart ) return initOutput ; if ( (
tMinusDelay <= tBuf [ oldestIdx ] ) ) { if ( discrete ) { return ( uBuf [
oldestIdx ] ) ; } else { int_T tempIdx = oldestIdx + 1 ; if ( oldestIdx ==
bufSz - 1 ) tempIdx = 0 ; t1 = tBuf [ oldestIdx ] ; t2 = tBuf [ tempIdx ] ;
u1 = uBuf [ oldestIdx ] ; u2 = uBuf [ tempIdx ] ; if ( t2 == t1 ) { if (
tMinusDelay >= t2 ) { yout = u2 ; } else { yout = u1 ; } } else { real_T f1 =
( t2 - tMinusDelay ) / ( t2 - t1 ) ; real_T f2 = 1.0 - f1 ; yout = f1 * u1 +
f2 * u2 ; } return yout ; } } if ( minorStepAndTAtLastMajorOutput ) { if (
newIdx != 0 ) { if ( * lastIdx == newIdx ) { ( * lastIdx ) -- ; } newIdx -- ;
} else { if ( * lastIdx == newIdx ) { * lastIdx = bufSz - 1 ; } newIdx =
bufSz - 1 ; } } i = * lastIdx ; if ( tBuf [ i ] < tMinusDelay ) { while (
tBuf [ i ] < tMinusDelay ) { if ( i == newIdx ) break ; i = ( i < ( bufSz - 1
) ) ? ( i + 1 ) : 0 ; } } else { while ( tBuf [ i ] >= tMinusDelay ) { i = (
i > 0 ) ? i - 1 : ( bufSz - 1 ) ; } i = ( i < ( bufSz - 1 ) ) ? ( i + 1 ) : 0
; } * lastIdx = i ; if ( discrete ) { double tempEps = ( DBL_EPSILON ) *
128.0 ; double localEps = tempEps * muDoubleScalarAbs ( tBuf [ i ] ) ; if (
tempEps > localEps ) { localEps = tempEps ; } localEps = localEps / 2.0 ; if
( tMinusDelay >= ( tBuf [ i ] - localEps ) ) { yout = uBuf [ i ] ; } else {
if ( i == 0 ) { yout = uBuf [ bufSz - 1 ] ; } else { yout = uBuf [ i - 1 ] ;
} } } else { if ( i == 0 ) { t1 = tBuf [ bufSz - 1 ] ; u1 = uBuf [ bufSz - 1
] ; } else { t1 = tBuf [ i - 1 ] ; u1 = uBuf [ i - 1 ] ; } t2 = tBuf [ i ] ;
u2 = uBuf [ i ] ; if ( t2 == t1 ) { if ( tMinusDelay >= t2 ) { yout = u2 ; }
else { yout = u1 ; } } else { real_T f1 = ( t2 - tMinusDelay ) / ( t2 - t1 )
; real_T f2 = 1.0 - f1 ; yout = f1 * u1 + f2 * u2 ; } } return ( yout ) ; }
#ifndef __RTW_UTFREE__  
extern void utFree ( void * ) ;
#endif
void rt_TDelayFreeBuf ( void * buf ) { utFree ( buf ) ; } void gxsouypddm (
const real_T iezpecwadp [ 4 ] , cfnnun40md * localB ) { localB -> pgkwjiqtkn
[ 0 ] = 0.0 ; localB -> pgkwjiqtkn [ 1 ] = 0.0 ; localB -> pgkwjiqtkn [ 2 ] =
0.0 ; localB -> pgkwjiqtkn [ 0 ] = muDoubleScalarAtan2 ( ( iezpecwadp [ 0 ] *
iezpecwadp [ 1 ] + iezpecwadp [ 2 ] * iezpecwadp [ 3 ] ) * 2.0 , 1.0 - (
iezpecwadp [ 1 ] * iezpecwadp [ 1 ] + iezpecwadp [ 2 ] * iezpecwadp [ 2 ] ) *
2.0 ) ; localB -> pgkwjiqtkn [ 1 ] = muDoubleScalarAsin ( ( iezpecwadp [ 0 ]
* iezpecwadp [ 2 ] - iezpecwadp [ 3 ] * iezpecwadp [ 1 ] ) * 2.0 ) ; localB
-> pgkwjiqtkn [ 2 ] = muDoubleScalarAtan2 ( ( iezpecwadp [ 0 ] * iezpecwadp [
3 ] + iezpecwadp [ 1 ] * iezpecwadp [ 2 ] ) * 2.0 , 1.0 - ( iezpecwadp [ 2 ]
* iezpecwadp [ 2 ] + iezpecwadp [ 3 ] * iezpecwadp [ 3 ] ) * 2.0 ) ; } void
i0grvgounu ( SimStruct * const rtS , real_T lunx0omi2s [ 6 ] , jjq30b5cja *
localP ) { real_T cvrrufph4k ; real_T pvjacoh0oy [ 6 ] ; int32_T i ;
cvrrufph4k = muDoubleScalarSin ( localP -> CosWave_Freq * ssGetTaskTime ( rtS
, 0 ) + localP -> CosWave_Phase ) * localP -> CosWave_Amp + localP ->
CosWave_Bias ; for ( i = 0 ; i < 6 ; i ++ ) { pvjacoh0oy [ i ] = cvrrufph4k *
localP -> BEMExcitationRePart_Value [ i ] ; } cvrrufph4k = muDoubleScalarSin
( localP -> SinWave_Freq * ssGetTaskTime ( rtS , 0 ) + localP ->
SinWave_Phase ) * localP -> SinWave_Amp + localP -> SinWave_Bias ; for ( i =
0 ; i < 6 ; i ++ ) { lunx0omi2s [ i ] = pvjacoh0oy [ i ] - cvrrufph4k *
localP -> BEMExcitationImPart1_Value [ i ] ; } } void aqx150ksyt ( real_T
aofffgmldi , real_T mj5fy2ou1h [ 6 ] , dnlp5zegym * localP ) { int32_T
kopcemwuu3 ; real_T o30gacwxxq ; real_T gko14wufze ; real_T odrfholbbx [ 6 ]
; real_T eyehkbba4l ; int32_T i ; for ( kopcemwuu3 = 0 ; kopcemwuu3 < 1 ;
kopcemwuu3 ++ ) { o30gacwxxq = muDoubleScalarSqrt ( localP ->
wavespectrum_Value * localP -> dw1_Value ) ; eyehkbba4l = localP ->
wavefrequency_Value * aofffgmldi + localP -> wavefrequency1_Value ;
gko14wufze = muDoubleScalarSin ( localP -> izalnoy5rm . CosWaveFunction_Freq
* eyehkbba4l + localP -> izalnoy5rm . CosWaveFunction_Phase ) * localP ->
izalnoy5rm . CosWaveFunction_Amp + localP -> izalnoy5rm .
CosWaveFunction_Bias ; eyehkbba4l = ( muDoubleScalarSin ( localP ->
izalnoy5rm . SinWaveFunction_Freq * eyehkbba4l + localP -> izalnoy5rm .
SinWaveFunction_Phase ) * localP -> izalnoy5rm . SinWaveFunction_Amp + localP
-> izalnoy5rm . SinWaveFunction_Bias ) * o30gacwxxq ; for ( i = 0 ; i < 6 ; i
++ ) { odrfholbbx [ i ] = o30gacwxxq * gko14wufze * localP ->
ExcitationRePart2_Value [ i ] - eyehkbba4l * localP ->
ExcitationRePart3_Value [ i ] ; } } for ( i = 0 ; i < 6 ; i ++ ) { mj5fy2ou1h
[ i ] = odrfholbbx [ i ] ; } } void l1kcj50fwe ( SimStruct * const rtS ,
const real_T naqjk0uxfy [ 6 ] , real_T kdrgo1140r [ 6 ] , fd5dgqf4g3 * localP
) { real_T a4op1i4nop ; int32_T i ; a4op1i4nop = ( muDoubleScalarSin ( localP
-> SineWave_Freq * ssGetTaskTime ( rtS , 0 ) + localP -> SineWave_Phase ) *
localP -> SineWave_Amp + localP -> SineWave_Bias ) + localP ->
Constant1_Value ; for ( i = 0 ; i < 6 ; i ++ ) { kdrgo1140r [ i ] =
naqjk0uxfy [ i ] * a4op1i4nop / localP -> Constant_Value ; } } void
p14hwlcq5a ( const real_T ofxuewhucj [ 6 ] , real_T g0binuximz [ 6 ] ) {
int32_T i ; for ( i = 0 ; i < 6 ; i ++ ) { g0binuximz [ i ] = ofxuewhucj [ i
] ; } } static real_T aj44waf3ba ( const real_T x [ 6 ] ) { real_T y ;
int32_T k ; y = x [ 0 ] ; for ( k = 0 ; k < 5 ; k ++ ) { y += x [ k + 1 ] ; }
return y ; } static real_T bkodxw3pn1 ( const real_T x [ 601 ] , const real_T
y [ 601 ] ) { real_T z ; int32_T iy ; int32_T ix ; real_T ylast ; int32_T k ;
memcpy ( & rtB . l0kvxs4qr0 [ 0 ] , & x [ 0 ] , 601U * sizeof ( real_T ) ) ;
for ( ix = 0 ; ix < 600 ; ix ++ ) { rtB . l0kvxs4qr0 [ ix ] = rtB .
l0kvxs4qr0 [ ix + 1 ] - rtB . l0kvxs4qr0 [ ix ] ; } z = 0.0 ; ix = - 1 ; iy =
0 ; ylast = y [ 0 ] ; for ( k = 0 ; k < 600 ; k ++ ) { iy ++ ; ix ++ ; z += (
ylast + y [ iy ] ) / 2.0 * rtB . l0kvxs4qr0 [ ix ] ; ylast = y [ iy ] ; }
return z ; } static real_T f1pbdll3kt ( const real_T x [ 6 ] ) { real_T y ;
int32_T k ; y = x [ 0 ] ; for ( k = 0 ; k < 5 ; k ++ ) { y += x [ k + 1 ] ; }
return y ; } static real_T ctqhiaiar1 ( const real_T x [ 601 ] , const real_T
y [ 601 ] ) { real_T z ; int32_T iy ; int32_T ix ; real_T ylast ; int32_T k ;
memcpy ( & rtB . nfec5adlu5 [ 0 ] , & x [ 0 ] , 601U * sizeof ( real_T ) ) ;
for ( ix = 0 ; ix < 600 ; ix ++ ) { rtB . nfec5adlu5 [ ix ] = rtB .
nfec5adlu5 [ ix + 1 ] - rtB . nfec5adlu5 [ ix ] ; } z = 0.0 ; ix = - 1 ; iy =
0 ; ylast = y [ 0 ] ; for ( k = 0 ; k < 600 ; k ++ ) { iy ++ ; ix ++ ; z += (
ylast + y [ iy ] ) / 2.0 * rtB . nfec5adlu5 [ ix ] ; ylast = y [ iy ] ; }
return z ; } void MdlInitialize ( void ) { boolean_T tmp ; int_T tmp_p ; char
* tmp_e ; tmp = false ; if ( tmp ) { tmp_p = strcmp ( "ode4" ,
ssGetSolverName ( rtS ) ) ; if ( tmp_p != 0 ) { tmp_e =
solver_mismatch_message ( "ode4" , ssGetSolverName ( rtS ) ) ;
ssSetErrorStatus ( rtS , tmp_e ) ; } } rtDW . hfpj0irdgz = false ; rtDW .
ba32jnnpzi = false ; } void MdlStart ( void ) { NeslSimulator * tmp ;
NeuDiagnosticManager * diagnosticManager ; real_T
modelParameters_mSolverTolerance ; real_T modelParameters_mFixedStepSize ;
boolean_T modelParameters_mVariableStepSolver ; NeuDiagnosticTree *
diagnosticTree ; int32_T tmp_p ; char * msg ; NeslSimulationData *
simulationData ; real_T time ; real_T time_p ; real_T time_e ;
NeModelParameters expl_temp ; NeModelParameters expl_temp_p ;
NeModelParameters expl_temp_e ; tmp = nesl_lease_simulator (
"RM3/Global Reference Frame/Solver Configuration" , 0 , 0 ) ; rtDW .
lm3sijg1j1 = ( void * ) tmp ; modelParameters_mVariableStepSolver =
pointer_is_null ( rtDW . lm3sijg1j1 ) ; if (
modelParameters_mVariableStepSolver ) { RM3_fa9b5af1_gateway ( ) ; tmp =
nesl_lease_simulator ( "RM3/Global Reference Frame/Solver Configuration" , 0
, 0 ) ; rtDW . lm3sijg1j1 = ( void * ) tmp ; } simulationData =
nesl_create_simulation_data ( ) ; rtDW . dhyxq0jnh5 = ( void * )
simulationData ; diagnosticManager = rtw_create_diagnostics ( ) ; rtDW .
f4urr54u23 = ( void * ) diagnosticManager ; modelParameters_mSolverTolerance
= 0.001 ; modelParameters_mFixedStepSize = 0.1 ;
modelParameters_mVariableStepSolver = false ; diagnosticManager = (
NeuDiagnosticManager * ) rtDW . f4urr54u23 ; diagnosticTree =
neu_diagnostic_manager_get_initial_tree ( diagnosticManager ) ; expl_temp .
mVariableStepSolver = modelParameters_mVariableStepSolver ; expl_temp .
mUseSimState = false ; expl_temp . mStartTime = 0.0 ; expl_temp . mSolverType
= NE_SOLVER_TYPE_ODE ; expl_temp . mSolverTolerance =
modelParameters_mSolverTolerance ; expl_temp . mLoggingMode =
SSC_LOGGING_NONE ; expl_temp . mLoadInitialState = false ; expl_temp .
mLinTrimCompile = false ; expl_temp . mFixedStepSize =
modelParameters_mFixedStepSize ; tmp_p = nesl_initialize_simulator ( (
NeslSimulator * ) rtDW . lm3sijg1j1 , expl_temp , diagnosticManager ) ; if (
tmp_p != 0 ) { modelParameters_mVariableStepSolver = error_buffer_is_empty (
ssGetErrorStatus ( rtS ) ) ; if ( modelParameters_mVariableStepSolver ) { msg
= rtw_diagnostics_msg ( diagnosticTree ) ; ssSetErrorStatus ( rtS , msg ) ; }
} simulationData = ( NeslSimulationData * ) rtDW . dhyxq0jnh5 ; time = ssGetT
( rtS ) ; simulationData -> mData -> mTime . mN = 1 ; simulationData -> mData
-> mTime . mX = & time ; simulationData -> mData -> mContStates . mN = 4 ;
simulationData -> mData -> mContStates . mX = ( real_T * ) & rtX . kxjirxqmhs
; simulationData -> mData -> mDiscStates . mN = 0 ; simulationData -> mData
-> mDiscStates . mX = NULL ; simulationData -> mData -> mModeVector . mN = 0
; simulationData -> mData -> mModeVector . mX = NULL ;
modelParameters_mVariableStepSolver = false ; simulationData -> mData ->
mFoundZcEvents = modelParameters_mVariableStepSolver ; simulationData ->
mData -> mIsMajorTimeStep = ssIsMajorTimeStep ( rtS ) ;
modelParameters_mVariableStepSolver = ( ssGetMdlInfoPtr ( rtS ) -> mdlFlags .
solverAssertCheck == 1U ) ; simulationData -> mData -> mIsSolverAssertCheck =
modelParameters_mVariableStepSolver ; simulationData -> mData ->
mIsSolverCheckingCIC = false ; modelParameters_mVariableStepSolver =
ssIsSolverComputingJacobian ( rtS ) ; simulationData -> mData ->
mIsComputingJacobian = modelParameters_mVariableStepSolver ; simulationData
-> mData -> mIsSolverRequestingReset = false ; diagnosticManager = (
NeuDiagnosticManager * ) rtDW . f4urr54u23 ; diagnosticTree =
neu_diagnostic_manager_get_initial_tree ( diagnosticManager ) ; tmp_p =
ne_simulator_method ( ( NeslSimulator * ) rtDW . lm3sijg1j1 ,
NESL_SIM_INITIALIZEONCE , simulationData , diagnosticManager ) ; if ( tmp_p
!= 0 ) { modelParameters_mVariableStepSolver = error_buffer_is_empty (
ssGetErrorStatus ( rtS ) ) ; if ( modelParameters_mVariableStepSolver ) { msg
= rtw_diagnostics_msg ( diagnosticTree ) ; ssSetErrorStatus ( rtS , msg ) ; }
} tmp = nesl_lease_simulator (
"RM3/Global Reference Frame/Solver Configuration" , 2 , 1 ) ; rtDW .
agkrcbkdh5 = ( void * ) tmp ; modelParameters_mVariableStepSolver =
pointer_is_null ( rtDW . agkrcbkdh5 ) ; if (
modelParameters_mVariableStepSolver ) { RM3_fa9b5af1_gateway ( ) ; tmp =
nesl_lease_simulator ( "RM3/Global Reference Frame/Solver Configuration" , 2
, 1 ) ; rtDW . agkrcbkdh5 = ( void * ) tmp ; } simulationData =
nesl_create_simulation_data ( ) ; rtDW . njkjfcqdc3 = ( void * )
simulationData ; diagnosticManager = rtw_create_diagnostics ( ) ; rtDW .
kieznzt55p = ( void * ) diagnosticManager ; modelParameters_mSolverTolerance
= 0.001 ; modelParameters_mFixedStepSize = 0.1 ;
modelParameters_mVariableStepSolver = false ; diagnosticManager = (
NeuDiagnosticManager * ) rtDW . kieznzt55p ; diagnosticTree =
neu_diagnostic_manager_get_initial_tree ( diagnosticManager ) ; expl_temp_p .
mVariableStepSolver = modelParameters_mVariableStepSolver ; expl_temp_p .
mUseSimState = false ; expl_temp_p . mStartTime = 0.0 ; expl_temp_p .
mSolverType = NE_SOLVER_TYPE_ODE ; expl_temp_p . mSolverTolerance =
modelParameters_mSolverTolerance ; expl_temp_p . mLoggingMode =
SSC_LOGGING_NONE ; expl_temp_p . mLoadInitialState = false ; expl_temp_p .
mLinTrimCompile = false ; expl_temp_p . mFixedStepSize =
modelParameters_mFixedStepSize ; tmp_p = nesl_initialize_simulator ( (
NeslSimulator * ) rtDW . agkrcbkdh5 , expl_temp_p , diagnosticManager ) ; if
( tmp_p != 0 ) { modelParameters_mVariableStepSolver = error_buffer_is_empty
( ssGetErrorStatus ( rtS ) ) ; if ( modelParameters_mVariableStepSolver ) {
msg = rtw_diagnostics_msg ( diagnosticTree ) ; ssSetErrorStatus ( rtS , msg )
; } } simulationData = ( NeslSimulationData * ) rtDW . njkjfcqdc3 ; time_p =
ssGetT ( rtS ) ; simulationData -> mData -> mTime . mN = 1 ; simulationData
-> mData -> mTime . mX = & time_p ; simulationData -> mData -> mContStates .
mN = 0 ; simulationData -> mData -> mContStates . mX = NULL ; simulationData
-> mData -> mDiscStates . mN = 0 ; simulationData -> mData -> mDiscStates .
mX = NULL ; simulationData -> mData -> mModeVector . mN = 0 ; simulationData
-> mData -> mModeVector . mX = NULL ; modelParameters_mVariableStepSolver =
false ; simulationData -> mData -> mFoundZcEvents =
modelParameters_mVariableStepSolver ; simulationData -> mData ->
mIsMajorTimeStep = ssIsMajorTimeStep ( rtS ) ;
modelParameters_mVariableStepSolver = ( ssGetMdlInfoPtr ( rtS ) -> mdlFlags .
solverAssertCheck == 1U ) ; simulationData -> mData -> mIsSolverAssertCheck =
modelParameters_mVariableStepSolver ; simulationData -> mData ->
mIsSolverCheckingCIC = false ; simulationData -> mData ->
mIsComputingJacobian = false ; simulationData -> mData ->
mIsSolverRequestingReset = false ; diagnosticManager = ( NeuDiagnosticManager
* ) rtDW . kieznzt55p ; diagnosticTree =
neu_diagnostic_manager_get_initial_tree ( diagnosticManager ) ; tmp_p =
ne_simulator_method ( ( NeslSimulator * ) rtDW . agkrcbkdh5 ,
NESL_SIM_INITIALIZEONCE , simulationData , diagnosticManager ) ; if ( tmp_p
!= 0 ) { modelParameters_mVariableStepSolver = error_buffer_is_empty (
ssGetErrorStatus ( rtS ) ) ; if ( modelParameters_mVariableStepSolver ) { msg
= rtw_diagnostics_msg ( diagnosticTree ) ; ssSetErrorStatus ( rtS , msg ) ; }
} { { int_T i1 ; int_T * iw_Tail = & rtDW . anmk1ei3yl . Tail [ 0 ] ; int_T *
iw_Head = & rtDW . anmk1ei3yl . Head [ 0 ] ; int_T * iw_Last = & rtDW .
anmk1ei3yl . Last [ 0 ] ; int_T * iw_CircularBufSize = & rtDW . anmk1ei3yl .
CircularBufSize [ 0 ] ; void * * pw_TUbufferPtrs = & rtDW . aqyccuzu4f .
TUbufferPtrs [ 0 ] ; for ( i1 = 0 ; i1 < 3 ; i1 ++ ) { real_T * pBuffer = (
real_T * ) rt_TDelayCreateBuf ( 2 , 1024 , sizeof ( real_T ) ) ; if ( pBuffer
== ( NULL ) ) { ssSetErrorStatus ( rtS , "tdelay memory allocation error" ) ;
return ; } iw_Tail [ i1 ] = 0 ; iw_Head [ i1 ] = 0 ; iw_Last [ i1 ] = 0 ;
iw_CircularBufSize [ i1 ] = 1024 ; pBuffer [ 0 ] = rtP .
TransportDelay_InitOutput ; pBuffer [ 1024 ] = ssGetT ( rtS ) ;
pw_TUbufferPtrs [ i1 ] = ( void * ) & pBuffer [ 0 ] ; pw_TUbufferPtrs [ i1 +
6 ] = ( void * ) & pBuffer [ 1024 ] ; } iw_Tail = & rtDW . anmk1ei3yl . Tail
[ 3 ] ; iw_Head = & rtDW . anmk1ei3yl . Head [ 3 ] ; iw_Last = & rtDW .
anmk1ei3yl . Last [ 3 ] ; iw_CircularBufSize = & rtDW . anmk1ei3yl .
CircularBufSize [ 3 ] ; pw_TUbufferPtrs = & rtDW . aqyccuzu4f . TUbufferPtrs
[ 3 ] ; for ( i1 = 0 ; i1 < 3 ; i1 ++ ) { real_T * pBuffer = ( real_T * )
rt_TDelayCreateBuf ( 2 , 1024 , sizeof ( real_T ) ) ; if ( pBuffer == ( NULL
) ) { ssSetErrorStatus ( rtS , "tdelay memory allocation error" ) ; return ;
} iw_Tail [ i1 ] = 0 ; iw_Head [ i1 ] = 0 ; iw_Last [ i1 ] = 0 ;
iw_CircularBufSize [ i1 ] = 1024 ; pBuffer [ 0 ] = rtP .
TransportDelay_InitOutput ; pBuffer [ 1024 ] = ssGetT ( rtS ) ;
pw_TUbufferPtrs [ i1 ] = ( void * ) & pBuffer [ 0 ] ; pw_TUbufferPtrs [ i1 +
6 ] = ( void * ) & pBuffer [ 1024 ] ; } } } rtDW . bxqmm1o411 = - 1 ; rtDW .
nofdnsita2 = - 1 ; { { int_T i1 ; int_T * iw_Tail = & rtDW . ke454bg2ir .
Tail [ 0 ] ; int_T * iw_Head = & rtDW . ke454bg2ir . Head [ 0 ] ; int_T *
iw_Last = & rtDW . ke454bg2ir . Last [ 0 ] ; int_T * iw_CircularBufSize = &
rtDW . ke454bg2ir . CircularBufSize [ 0 ] ; void * * pw_TUbufferPtrs = & rtDW
. pj0j1eoun4 . TUbufferPtrs [ 0 ] ; for ( i1 = 0 ; i1 < 3 ; i1 ++ ) { real_T
* pBuffer = ( real_T * ) rt_TDelayCreateBuf ( 2 , 1024 , sizeof ( real_T ) )
; if ( pBuffer == ( NULL ) ) { ssSetErrorStatus ( rtS ,
"tdelay memory allocation error" ) ; return ; } iw_Tail [ i1 ] = 0 ; iw_Head
[ i1 ] = 0 ; iw_Last [ i1 ] = 0 ; iw_CircularBufSize [ i1 ] = 1024 ; pBuffer
[ 0 ] = rtP . TransportDelay_InitOutput_ok1nab0an0 ; pBuffer [ 1024 ] =
ssGetT ( rtS ) ; pw_TUbufferPtrs [ i1 ] = ( void * ) & pBuffer [ 0 ] ;
pw_TUbufferPtrs [ i1 + 6 ] = ( void * ) & pBuffer [ 1024 ] ; } iw_Tail = &
rtDW . ke454bg2ir . Tail [ 3 ] ; iw_Head = & rtDW . ke454bg2ir . Head [ 3 ] ;
iw_Last = & rtDW . ke454bg2ir . Last [ 3 ] ; iw_CircularBufSize = & rtDW .
ke454bg2ir . CircularBufSize [ 3 ] ; pw_TUbufferPtrs = & rtDW . pj0j1eoun4 .
TUbufferPtrs [ 3 ] ; for ( i1 = 0 ; i1 < 3 ; i1 ++ ) { real_T * pBuffer = (
real_T * ) rt_TDelayCreateBuf ( 2 , 1024 , sizeof ( real_T ) ) ; if ( pBuffer
== ( NULL ) ) { ssSetErrorStatus ( rtS , "tdelay memory allocation error" ) ;
return ; } iw_Tail [ i1 ] = 0 ; iw_Head [ i1 ] = 0 ; iw_Last [ i1 ] = 0 ;
iw_CircularBufSize [ i1 ] = 1024 ; pBuffer [ 0 ] = rtP .
TransportDelay_InitOutput_ok1nab0an0 ; pBuffer [ 1024 ] = ssGetT ( rtS ) ;
pw_TUbufferPtrs [ i1 ] = ( void * ) & pBuffer [ 0 ] ; pw_TUbufferPtrs [ i1 +
6 ] = ( void * ) & pBuffer [ 1024 ] ; } } } rtDW . if5tadkli2 = - 1 ; rtDW .
gn2tshspwh = - 1 ; tmp = nesl_lease_simulator (
"RM3/Global Reference Frame/Solver Configuration" , 2 , 0 ) ; rtDW .
grkodaq2kd = ( void * ) tmp ; modelParameters_mVariableStepSolver =
pointer_is_null ( rtDW . grkodaq2kd ) ; if (
modelParameters_mVariableStepSolver ) { RM3_fa9b5af1_gateway ( ) ; tmp =
nesl_lease_simulator ( "RM3/Global Reference Frame/Solver Configuration" , 2
, 0 ) ; rtDW . grkodaq2kd = ( void * ) tmp ; } simulationData =
nesl_create_simulation_data ( ) ; rtDW . hjs5z0ka4j = ( void * )
simulationData ; diagnosticManager = rtw_create_diagnostics ( ) ; rtDW .
hafmpp5qwx = ( void * ) diagnosticManager ; modelParameters_mSolverTolerance
= 0.001 ; modelParameters_mFixedStepSize = 0.1 ;
modelParameters_mVariableStepSolver = false ; diagnosticManager = (
NeuDiagnosticManager * ) rtDW . hafmpp5qwx ; diagnosticTree =
neu_diagnostic_manager_get_initial_tree ( diagnosticManager ) ; expl_temp_e .
mVariableStepSolver = modelParameters_mVariableStepSolver ; expl_temp_e .
mUseSimState = false ; expl_temp_e . mStartTime = 0.0 ; expl_temp_e .
mSolverType = NE_SOLVER_TYPE_ODE ; expl_temp_e . mSolverTolerance =
modelParameters_mSolverTolerance ; expl_temp_e . mLoggingMode =
SSC_LOGGING_NONE ; expl_temp_e . mLoadInitialState = false ; expl_temp_e .
mLinTrimCompile = false ; expl_temp_e . mFixedStepSize =
modelParameters_mFixedStepSize ; tmp_p = nesl_initialize_simulator ( (
NeslSimulator * ) rtDW . grkodaq2kd , expl_temp_e , diagnosticManager ) ; if
( tmp_p != 0 ) { modelParameters_mVariableStepSolver = error_buffer_is_empty
( ssGetErrorStatus ( rtS ) ) ; if ( modelParameters_mVariableStepSolver ) {
msg = rtw_diagnostics_msg ( diagnosticTree ) ; ssSetErrorStatus ( rtS , msg )
; } } simulationData = ( NeslSimulationData * ) rtDW . hjs5z0ka4j ; time_e =
ssGetT ( rtS ) ; simulationData -> mData -> mTime . mN = 1 ; simulationData
-> mData -> mTime . mX = & time_e ; simulationData -> mData -> mContStates .
mN = 0 ; simulationData -> mData -> mContStates . mX = NULL ; simulationData
-> mData -> mDiscStates . mN = 0 ; simulationData -> mData -> mDiscStates .
mX = NULL ; simulationData -> mData -> mModeVector . mN = 0 ; simulationData
-> mData -> mModeVector . mX = NULL ; modelParameters_mVariableStepSolver =
false ; simulationData -> mData -> mFoundZcEvents =
modelParameters_mVariableStepSolver ; simulationData -> mData ->
mIsMajorTimeStep = ssIsMajorTimeStep ( rtS ) ;
modelParameters_mVariableStepSolver = ( ssGetMdlInfoPtr ( rtS ) -> mdlFlags .
solverAssertCheck == 1U ) ; simulationData -> mData -> mIsSolverAssertCheck =
modelParameters_mVariableStepSolver ; simulationData -> mData ->
mIsSolverCheckingCIC = false ; simulationData -> mData ->
mIsComputingJacobian = false ; simulationData -> mData ->
mIsSolverRequestingReset = false ; diagnosticManager = ( NeuDiagnosticManager
* ) rtDW . hafmpp5qwx ; diagnosticTree =
neu_diagnostic_manager_get_initial_tree ( diagnosticManager ) ; tmp_p =
ne_simulator_method ( ( NeslSimulator * ) rtDW . grkodaq2kd ,
NESL_SIM_INITIALIZEONCE , simulationData , diagnosticManager ) ; if ( tmp_p
!= 0 ) { modelParameters_mVariableStepSolver = error_buffer_is_empty (
ssGetErrorStatus ( rtS ) ) ; if ( modelParameters_mVariableStepSolver ) { msg
= rtw_diagnostics_msg ( diagnosticTree ) ; ssSetErrorStatus ( rtS , msg ) ; }
} { static int_T rt_ToWksWidths [ ] = { 6 } ; static int_T
rt_ToWksNumDimensions [ ] = { 1 } ; static int_T rt_ToWksDimensions [ ] = { 6
} ; static boolean_T rt_ToWksIsVarDims [ ] = { 0 } ; static void *
rt_ToWksCurrSigDims [ ] = { ( NULL ) } ; static int_T rt_ToWksCurrSigDimsSize
[ ] = { 4 } ; static BuiltInDTypeId rt_ToWksDataTypeIds [ ] = { SS_DOUBLE } ;
static int_T rt_ToWksComplexSignals [ ] = { 0 } ; static int_T
rt_ToWksFrameData [ ] = { 0 } ; static const char_T * rt_ToWksLabels [ ] = {
"Constraint Forces" } ; static RTWLogSignalInfo rt_ToWksSignalInfo = { 1 ,
rt_ToWksWidths , rt_ToWksNumDimensions , rt_ToWksDimensions ,
rt_ToWksIsVarDims , rt_ToWksCurrSigDims , rt_ToWksCurrSigDimsSize ,
rt_ToWksDataTypeIds , rt_ToWksComplexSignals , rt_ToWksFrameData , {
rt_ToWksLabels } , ( NULL ) , ( NULL ) , ( NULL ) , { ( NULL ) } , { ( NULL )
} , ( NULL ) , ( NULL ) } ; static const char_T rt_ToWksBlockName [ ] =
"RM3/Heave/output" ; rtDW . kmx1camcmy . LoggedData = rt_CreateStructLogVar (
ssGetRTWLogInfo ( rtS ) , ssGetTStart ( rtS ) , ssGetTFinal ( rtS ) , 0.0 , (
& ssGetErrorStatus ( rtS ) ) , "Constraint1_out" , 1 , 0 , 1 , 0.1 , &
rt_ToWksSignalInfo , rt_ToWksBlockName ) ; if ( rtDW . kmx1camcmy .
LoggedData == ( NULL ) ) return ; } { static int_T rt_ToWksWidths [ ] = { 66
} ; static int_T rt_ToWksNumDimensions [ ] = { 1 } ; static int_T
rt_ToWksDimensions [ ] = { 66 } ; static boolean_T rt_ToWksIsVarDims [ ] = {
0 } ; static void * rt_ToWksCurrSigDims [ ] = { ( NULL ) } ; static int_T
rt_ToWksCurrSigDimsSize [ ] = { 4 } ; static BuiltInDTypeId
rt_ToWksDataTypeIds [ ] = { SS_DOUBLE } ; static int_T rt_ToWksComplexSignals
[ ] = { 0 } ; static int_T rt_ToWksFrameData [ ] = { 0 } ; static const
char_T * rt_ToWksLabels [ ] = { "" } ; static RTWLogSignalInfo
rt_ToWksSignalInfo = { 1 , rt_ToWksWidths , rt_ToWksNumDimensions ,
rt_ToWksDimensions , rt_ToWksIsVarDims , rt_ToWksCurrSigDims ,
rt_ToWksCurrSigDimsSize , rt_ToWksDataTypeIds , rt_ToWksComplexSignals ,
rt_ToWksFrameData , { rt_ToWksLabels } , ( NULL ) , ( NULL ) , ( NULL ) , { (
NULL ) } , { ( NULL ) } , ( NULL ) , ( NULL ) } ; static const char_T
rt_ToWksBlockName [ ] = "RM3/Rigid Body/To Workspace" ; rtDW . jzxtw4vtua .
LoggedData = rt_CreateStructLogVar ( ssGetRTWLogInfo ( rtS ) , ssGetTStart (
rtS ) , ssGetTFinal ( rtS ) , 0.0 , ( & ssGetErrorStatus ( rtS ) ) ,
"buoyWAMITa_out" , 1 , 0 , 1 , 0.1 , & rt_ToWksSignalInfo , rt_ToWksBlockName
) ; if ( rtDW . jzxtw4vtua . LoggedData == ( NULL ) ) return ; } { static
int_T rt_ToWksWidths [ ] = { 66 } ; static int_T rt_ToWksNumDimensions [ ] =
{ 1 } ; static int_T rt_ToWksDimensions [ ] = { 66 } ; static boolean_T
rt_ToWksIsVarDims [ ] = { 0 } ; static void * rt_ToWksCurrSigDims [ ] = { (
NULL ) } ; static int_T rt_ToWksCurrSigDimsSize [ ] = { 4 } ; static
BuiltInDTypeId rt_ToWksDataTypeIds [ ] = { SS_DOUBLE } ; static int_T
rt_ToWksComplexSignals [ ] = { 0 } ; static int_T rt_ToWksFrameData [ ] = { 0
} ; static const char_T * rt_ToWksLabels [ ] = { "" } ; static
RTWLogSignalInfo rt_ToWksSignalInfo = { 1 , rt_ToWksWidths ,
rt_ToWksNumDimensions , rt_ToWksDimensions , rt_ToWksIsVarDims ,
rt_ToWksCurrSigDims , rt_ToWksCurrSigDimsSize , rt_ToWksDataTypeIds ,
rt_ToWksComplexSignals , rt_ToWksFrameData , { rt_ToWksLabels } , ( NULL ) ,
( NULL ) , ( NULL ) , { ( NULL ) } , { ( NULL ) } , ( NULL ) , ( NULL ) } ;
static const char_T rt_ToWksBlockName [ ] = "RM3/Rigid Body1/To Workspace" ;
rtDW . ce1jzkjckk . LoggedData = rt_CreateStructLogVar ( ssGetRTWLogInfo (
rtS ) , ssGetTStart ( rtS ) , ssGetTFinal ( rtS ) , 0.0 , ( &
ssGetErrorStatus ( rtS ) ) , "buoyWAMITb_out" , 1 , 0 , 1 , 0.1 , &
rt_ToWksSignalInfo , rt_ToWksBlockName ) ; if ( rtDW . ce1jzkjckk .
LoggedData == ( NULL ) ) return ; } { static int_T rt_ToWksWidths [ ] = { 8 }
; static int_T rt_ToWksNumDimensions [ ] = { 1 } ; static int_T
rt_ToWksDimensions [ ] = { 8 } ; static boolean_T rt_ToWksIsVarDims [ ] = { 0
} ; static void * rt_ToWksCurrSigDims [ ] = { ( NULL ) } ; static int_T
rt_ToWksCurrSigDimsSize [ ] = { 4 } ; static BuiltInDTypeId
rt_ToWksDataTypeIds [ ] = { SS_DOUBLE } ; static int_T rt_ToWksComplexSignals
[ ] = { 0 } ; static int_T rt_ToWksFrameData [ ] = { 0 } ; static const
char_T * rt_ToWksLabels [ ] = { "" } ; static RTWLogSignalInfo
rt_ToWksSignalInfo = { 1 , rt_ToWksWidths , rt_ToWksNumDimensions ,
rt_ToWksDimensions , rt_ToWksIsVarDims , rt_ToWksCurrSigDims ,
rt_ToWksCurrSigDimsSize , rt_ToWksDataTypeIds , rt_ToWksComplexSignals ,
rt_ToWksFrameData , { rt_ToWksLabels } , ( NULL ) , ( NULL ) , ( NULL ) , { (
NULL ) } , { ( NULL ) } , ( NULL ) , ( NULL ) } ; static const char_T
rt_ToWksBlockName [ ] = "RM3/Translational PTO \n(Local Z)/output" ; rtDW .
mmokpjpvho . LoggedData = rt_CreateStructLogVar ( ssGetRTWLogInfo ( rtS ) ,
ssGetTStart ( rtS ) , ssGetTFinal ( rtS ) , 0.0 , ( & ssGetErrorStatus ( rtS
) ) , "PTO1_out" , 1 , 0 , 1 , 0.1 , & rt_ToWksSignalInfo , rt_ToWksBlockName
) ; if ( rtDW . mmokpjpvho . LoggedData == ( NULL ) ) return ; }
MdlInitialize ( ) ; } void MdlOutputs ( int_T tid ) { real_T fky3rqwq4u [ 6 ]
; real_T hvxyz2hiiz [ 6 ] ; real_T dv1wlfujci [ 6 ] ; NeslSimulationData *
simulationData ; real_T time ; boolean_T tmp ; real_T tmp_p [ 48 ] ; int_T
tmp_e [ 13 ] ; NeuDiagnosticManager * diagnosticManager ; NeuDiagnosticTree *
diagnosticTree ; char * msg ; real_T time_p ; real_T tmp_i [ 52 ] ; int_T
tmp_m [ 14 ] ; real_T time_e ; real_T tmp_g [ 52 ] ; int_T tmp_j [ 14 ] ;
real_T tmpF [ 36 ] ; int32_T kk ; real_T eph0oh1i4b [ 6 ] ; real_T iyvfbn10dh
[ 6 ] ; int8_T rtAction ; real_T ojwgfbilnb ; real_T abxnqvdbkl ; real_T
fq2jvssegz [ 6 ] ; int32_T i ; real_T tmpF_p [ 6 ] ; int32_T i_p ; srClearBC
( rtDW . i0grvgounuc . e2lhwvg4n3 ) ; srClearBC ( rtDW . aqx150ksytr .
ofnp3tiibi ) ; srClearBC ( rtDW . l1kcj50fwey . ckdn4xd4hz ) ; srClearBC (
rtDW . p14hwlcq5ag . dbhao2hevj ) ; rtB . e3kvmjjnay = ssGetT ( rtS ) ;
simulationData = ( NeslSimulationData * ) rtDW . dhyxq0jnh5 ; time = ssGetT (
rtS ) ; simulationData -> mData -> mTime . mN = 1 ; simulationData -> mData
-> mTime . mX = & time ; simulationData -> mData -> mContStates . mN = 4 ;
simulationData -> mData -> mContStates . mX = ( real_T * ) & rtX . kxjirxqmhs
; simulationData -> mData -> mDiscStates . mN = 0 ; simulationData -> mData
-> mDiscStates . mX = NULL ; simulationData -> mData -> mModeVector . mN = 0
; simulationData -> mData -> mModeVector . mX = NULL ; tmp = false ;
simulationData -> mData -> mFoundZcEvents = tmp ; simulationData -> mData ->
mIsMajorTimeStep = ssIsMajorTimeStep ( rtS ) ; tmp = ( ssGetMdlInfoPtr ( rtS
) -> mdlFlags . solverAssertCheck == 1U ) ; simulationData -> mData ->
mIsSolverAssertCheck = tmp ; simulationData -> mData -> mIsSolverCheckingCIC
= false ; tmp = ssIsSolverComputingJacobian ( rtS ) ; simulationData -> mData
-> mIsComputingJacobian = tmp ; simulationData -> mData ->
mIsSolverRequestingReset = false ; tmp_e [ 0 ] = 0 ; tmp_p [ 0 ] = rtB .
biiiks5bdq [ 0 ] ; tmp_p [ 1 ] = rtB . biiiks5bdq [ 1 ] ; tmp_p [ 2 ] = rtB .
biiiks5bdq [ 2 ] ; tmp_p [ 3 ] = rtB . biiiks5bdq [ 3 ] ; tmp_e [ 1 ] = 4 ;
tmp_p [ 4 ] = rtB . bweohccgoh [ 0 ] ; tmp_p [ 5 ] = rtB . bweohccgoh [ 1 ] ;
tmp_p [ 6 ] = rtB . bweohccgoh [ 2 ] ; tmp_p [ 7 ] = rtB . bweohccgoh [ 3 ] ;
tmp_e [ 2 ] = 8 ; tmp_p [ 8 ] = rtB . eyb1czk053 [ 0 ] ; tmp_p [ 9 ] = rtB .
eyb1czk053 [ 1 ] ; tmp_p [ 10 ] = rtB . eyb1czk053 [ 2 ] ; tmp_p [ 11 ] = rtB
. eyb1czk053 [ 3 ] ; tmp_e [ 3 ] = 12 ; tmp_p [ 12 ] = rtB . hoyspdnpx3 [ 0 ]
; tmp_p [ 13 ] = rtB . hoyspdnpx3 [ 1 ] ; tmp_p [ 14 ] = rtB . hoyspdnpx3 [ 2
] ; tmp_p [ 15 ] = rtB . hoyspdnpx3 [ 3 ] ; tmp_e [ 4 ] = 16 ; tmp_p [ 16 ] =
rtB . kia00mwvqk [ 0 ] ; tmp_p [ 17 ] = rtB . kia00mwvqk [ 1 ] ; tmp_p [ 18 ]
= rtB . kia00mwvqk [ 2 ] ; tmp_p [ 19 ] = rtB . kia00mwvqk [ 3 ] ; tmp_e [ 5
] = 20 ; tmp_p [ 20 ] = rtB . jr2ghgakgm [ 0 ] ; tmp_p [ 21 ] = rtB .
jr2ghgakgm [ 1 ] ; tmp_p [ 22 ] = rtB . jr2ghgakgm [ 2 ] ; tmp_p [ 23 ] = rtB
. jr2ghgakgm [ 3 ] ; tmp_e [ 6 ] = 24 ; tmp_p [ 24 ] = rtB . mionfsauuc [ 0 ]
; tmp_p [ 25 ] = rtB . mionfsauuc [ 1 ] ; tmp_p [ 26 ] = rtB . mionfsauuc [ 2
] ; tmp_p [ 27 ] = rtB . mionfsauuc [ 3 ] ; tmp_e [ 7 ] = 28 ; tmp_p [ 28 ] =
rtB . lkkej41yzf [ 0 ] ; tmp_p [ 29 ] = rtB . lkkej41yzf [ 1 ] ; tmp_p [ 30 ]
= rtB . lkkej41yzf [ 2 ] ; tmp_p [ 31 ] = rtB . lkkej41yzf [ 3 ] ; tmp_e [ 8
] = 32 ; tmp_p [ 32 ] = rtB . k02keb4tly [ 0 ] ; tmp_p [ 33 ] = rtB .
k02keb4tly [ 1 ] ; tmp_p [ 34 ] = rtB . k02keb4tly [ 2 ] ; tmp_p [ 35 ] = rtB
. k02keb4tly [ 3 ] ; tmp_e [ 9 ] = 36 ; tmp_p [ 36 ] = rtB . hoc2fuxv0g [ 0 ]
; tmp_p [ 37 ] = rtB . hoc2fuxv0g [ 1 ] ; tmp_p [ 38 ] = rtB . hoc2fuxv0g [ 2
] ; tmp_p [ 39 ] = rtB . hoc2fuxv0g [ 3 ] ; tmp_e [ 10 ] = 40 ; tmp_p [ 40 ]
= rtB . gbda5p2r2f [ 0 ] ; tmp_p [ 41 ] = rtB . gbda5p2r2f [ 1 ] ; tmp_p [ 42
] = rtB . gbda5p2r2f [ 2 ] ; tmp_p [ 43 ] = rtB . gbda5p2r2f [ 3 ] ; tmp_e [
11 ] = 44 ; tmp_p [ 44 ] = rtB . j1dwgbinuj [ 0 ] ; tmp_p [ 45 ] = rtB .
j1dwgbinuj [ 1 ] ; tmp_p [ 46 ] = rtB . j1dwgbinuj [ 2 ] ; tmp_p [ 47 ] = rtB
. j1dwgbinuj [ 3 ] ; tmp_e [ 12 ] = 48 ; simulationData -> mData ->
mInputValues . mN = 48 ; simulationData -> mData -> mInputValues . mX = &
tmp_p [ 0 ] ; simulationData -> mData -> mInputOffsets . mN = 13 ;
simulationData -> mData -> mInputOffsets . mX = & tmp_e [ 0 ] ;
simulationData -> mData -> mOutputs . mN = 4 ; simulationData -> mData ->
mOutputs . mX = & rtB . pzk0tdps0y [ 0 ] ; simulationData -> mData ->
mSampleHits . mN = 0 ; simulationData -> mData -> mSampleHits . mX = NULL ;
simulationData -> mData -> mIsFundamentalSampleHit = false ;
diagnosticManager = ( NeuDiagnosticManager * ) rtDW . f4urr54u23 ;
diagnosticTree = neu_diagnostic_manager_get_initial_tree ( diagnosticManager
) ; i = ne_simulator_method ( ( NeslSimulator * ) rtDW . lm3sijg1j1 ,
NESL_SIM_OUTPUTS , simulationData , diagnosticManager ) ; if ( i != 0 ) { tmp
= error_buffer_is_empty ( ssGetErrorStatus ( rtS ) ) ; if ( tmp ) { msg =
rtw_diagnostics_msg ( diagnosticTree ) ; ssSetErrorStatus ( rtS , msg ) ; } }
simulationData = ( NeslSimulationData * ) rtDW . njkjfcqdc3 ; time_p = ssGetT
( rtS ) ; simulationData -> mData -> mTime . mN = 1 ; simulationData -> mData
-> mTime . mX = & time_p ; simulationData -> mData -> mContStates . mN = 0 ;
simulationData -> mData -> mContStates . mX = NULL ; simulationData -> mData
-> mDiscStates . mN = 0 ; simulationData -> mData -> mDiscStates . mX = NULL
; simulationData -> mData -> mModeVector . mN = 0 ; simulationData -> mData
-> mModeVector . mX = NULL ; tmp = false ; simulationData -> mData ->
mFoundZcEvents = tmp ; simulationData -> mData -> mIsMajorTimeStep =
ssIsMajorTimeStep ( rtS ) ; tmp = ( ssGetMdlInfoPtr ( rtS ) -> mdlFlags .
solverAssertCheck == 1U ) ; simulationData -> mData -> mIsSolverAssertCheck =
tmp ; simulationData -> mData -> mIsSolverCheckingCIC = false ;
simulationData -> mData -> mIsComputingJacobian = false ; simulationData ->
mData -> mIsSolverRequestingReset = false ; tmp_m [ 0 ] = 0 ; tmp_i [ 0 ] =
rtB . biiiks5bdq [ 0 ] ; tmp_i [ 1 ] = rtB . biiiks5bdq [ 1 ] ; tmp_i [ 2 ] =
rtB . biiiks5bdq [ 2 ] ; tmp_i [ 3 ] = rtB . biiiks5bdq [ 3 ] ; tmp_m [ 1 ] =
4 ; tmp_i [ 4 ] = rtB . bweohccgoh [ 0 ] ; tmp_i [ 5 ] = rtB . bweohccgoh [ 1
] ; tmp_i [ 6 ] = rtB . bweohccgoh [ 2 ] ; tmp_i [ 7 ] = rtB . bweohccgoh [ 3
] ; tmp_m [ 2 ] = 8 ; tmp_i [ 8 ] = rtB . eyb1czk053 [ 0 ] ; tmp_i [ 9 ] =
rtB . eyb1czk053 [ 1 ] ; tmp_i [ 10 ] = rtB . eyb1czk053 [ 2 ] ; tmp_i [ 11 ]
= rtB . eyb1czk053 [ 3 ] ; tmp_m [ 3 ] = 12 ; tmp_i [ 12 ] = rtB . hoyspdnpx3
[ 0 ] ; tmp_i [ 13 ] = rtB . hoyspdnpx3 [ 1 ] ; tmp_i [ 14 ] = rtB .
hoyspdnpx3 [ 2 ] ; tmp_i [ 15 ] = rtB . hoyspdnpx3 [ 3 ] ; tmp_m [ 4 ] = 16 ;
tmp_i [ 16 ] = rtB . kia00mwvqk [ 0 ] ; tmp_i [ 17 ] = rtB . kia00mwvqk [ 1 ]
; tmp_i [ 18 ] = rtB . kia00mwvqk [ 2 ] ; tmp_i [ 19 ] = rtB . kia00mwvqk [ 3
] ; tmp_m [ 5 ] = 20 ; tmp_i [ 20 ] = rtB . jr2ghgakgm [ 0 ] ; tmp_i [ 21 ] =
rtB . jr2ghgakgm [ 1 ] ; tmp_i [ 22 ] = rtB . jr2ghgakgm [ 2 ] ; tmp_i [ 23 ]
= rtB . jr2ghgakgm [ 3 ] ; tmp_m [ 6 ] = 24 ; tmp_i [ 24 ] = rtB . mionfsauuc
[ 0 ] ; tmp_i [ 25 ] = rtB . mionfsauuc [ 1 ] ; tmp_i [ 26 ] = rtB .
mionfsauuc [ 2 ] ; tmp_i [ 27 ] = rtB . mionfsauuc [ 3 ] ; tmp_m [ 7 ] = 28 ;
tmp_i [ 28 ] = rtB . lkkej41yzf [ 0 ] ; tmp_i [ 29 ] = rtB . lkkej41yzf [ 1 ]
; tmp_i [ 30 ] = rtB . lkkej41yzf [ 2 ] ; tmp_i [ 31 ] = rtB . lkkej41yzf [ 3
] ; tmp_m [ 8 ] = 32 ; tmp_i [ 32 ] = rtB . k02keb4tly [ 0 ] ; tmp_i [ 33 ] =
rtB . k02keb4tly [ 1 ] ; tmp_i [ 34 ] = rtB . k02keb4tly [ 2 ] ; tmp_i [ 35 ]
= rtB . k02keb4tly [ 3 ] ; tmp_m [ 9 ] = 36 ; tmp_i [ 36 ] = rtB . hoc2fuxv0g
[ 0 ] ; tmp_i [ 37 ] = rtB . hoc2fuxv0g [ 1 ] ; tmp_i [ 38 ] = rtB .
hoc2fuxv0g [ 2 ] ; tmp_i [ 39 ] = rtB . hoc2fuxv0g [ 3 ] ; tmp_m [ 10 ] = 40
; tmp_i [ 40 ] = rtB . gbda5p2r2f [ 0 ] ; tmp_i [ 41 ] = rtB . gbda5p2r2f [ 1
] ; tmp_i [ 42 ] = rtB . gbda5p2r2f [ 2 ] ; tmp_i [ 43 ] = rtB . gbda5p2r2f [
3 ] ; tmp_m [ 11 ] = 44 ; tmp_i [ 44 ] = rtB . j1dwgbinuj [ 0 ] ; tmp_i [ 45
] = rtB . j1dwgbinuj [ 1 ] ; tmp_i [ 46 ] = rtB . j1dwgbinuj [ 2 ] ; tmp_i [
47 ] = rtB . j1dwgbinuj [ 3 ] ; tmp_m [ 12 ] = 48 ; tmp_i [ 48 ] = rtB .
pzk0tdps0y [ 0 ] ; tmp_i [ 49 ] = rtB . pzk0tdps0y [ 1 ] ; tmp_i [ 50 ] = rtB
. pzk0tdps0y [ 2 ] ; tmp_i [ 51 ] = rtB . pzk0tdps0y [ 3 ] ; tmp_m [ 13 ] =
52 ; simulationData -> mData -> mInputValues . mN = 52 ; simulationData ->
mData -> mInputValues . mX = & tmp_i [ 0 ] ; simulationData -> mData ->
mInputOffsets . mN = 14 ; simulationData -> mData -> mInputOffsets . mX = &
tmp_m [ 0 ] ; simulationData -> mData -> mOutputs . mN = 28 ; simulationData
-> mData -> mOutputs . mX = & rtB . eygknao1u4 [ 0 ] ; simulationData ->
mData -> mSampleHits . mN = 0 ; simulationData -> mData -> mSampleHits . mX =
NULL ; simulationData -> mData -> mIsFundamentalSampleHit = false ;
diagnosticManager = ( NeuDiagnosticManager * ) rtDW . kieznzt55p ;
diagnosticTree = neu_diagnostic_manager_get_initial_tree ( diagnosticManager
) ; i = ne_simulator_method ( ( NeslSimulator * ) rtDW . agkrcbkdh5 ,
NESL_SIM_OUTPUTS , simulationData , diagnosticManager ) ; if ( i != 0 ) { tmp
= error_buffer_is_empty ( ssGetErrorStatus ( rtS ) ) ; if ( tmp ) { msg =
rtw_diagnostics_msg ( diagnosticTree ) ; ssSetErrorStatus ( rtS , msg ) ; } }
eph0oh1i4b [ 0 ] = rtB . eygknao1u4 [ 12 ] ; eph0oh1i4b [ 1 ] = rtB .
eygknao1u4 [ 13 ] ; eph0oh1i4b [ 2 ] = rtB . eygknao1u4 [ 14 ] ; eph0oh1i4b [
3 ] = rtB . eygknao1u4 [ 6 ] ; eph0oh1i4b [ 4 ] = rtB . eygknao1u4 [ 7 ] ;
eph0oh1i4b [ 5 ] = rtB . eygknao1u4 [ 8 ] ; for ( i_p = 0 ; i_p < 6 ; i_p ++
) { dv1wlfujci [ i_p ] = 0.0 ; for ( i = 0 ; i < 6 ; i ++ ) { dv1wlfujci [
i_p ] += rtP . DampingForces_Gain [ 6 * i + i_p ] * eph0oh1i4b [ i ] ; } }
fq2jvssegz [ 0 ] = rtB . eygknao1u4 [ 12 ] ; fq2jvssegz [ 1 ] = rtB .
eygknao1u4 [ 13 ] ; fq2jvssegz [ 2 ] = rtB . eygknao1u4 [ 14 ] ; fq2jvssegz [
3 ] = rtB . eygknao1u4 [ 6 ] ; fq2jvssegz [ 4 ] = rtB . eygknao1u4 [ 7 ] ;
fq2jvssegz [ 5 ] = rtB . eygknao1u4 [ 8 ] ; if ( rtP . WaveType_Value == 10.0
) { for ( i = 0 ; i < 6 ; i ++ ) { fq2jvssegz [ i ] = 0.0 ; } } else { if ( !
rtDW . hfpj0irdgz ) { memcpy ( & rtDW . ajv5jtlwij [ 0 ] , & rtP .
InitialZeroVelocity_Value [ 0 ] , 3606U * sizeof ( real_T ) ) ; rtDW .
hfpj0irdgz = true ; rtDW . pe4ejkzi2m = 0.0 ; } else { rtDW . pe4ejkzi2m ++ ;
if ( muDoubleScalarAbs ( ( rtDW . pe4ejkzi2m - muDoubleScalarFloor ( rtDW .
pe4ejkzi2m / 5.0 ) * 5.0 ) - 1.0 ) < 1.0E-8 ) { for ( i_p = 0 ; i_p < 600 ;
i_p ++ ) { for ( i = 0 ; i < 6 ; i ++ ) { rtB . b4nvex32ha [ i + 6 * i_p ] =
rtDW . ajv5jtlwij [ 6 * i_p + i ] ; } } for ( i_p = 0 ; i_p < 600 ; i_p ++ )
{ for ( i = 0 ; i < 6 ; i ++ ) { rtDW . ajv5jtlwij [ i + 6 * ( 1 + i_p ) ] =
rtB . b4nvex32ha [ 6 * i_p + i ] ; } } } for ( i_p = 0 ; i_p < 6 ; i_p ++ ) {
rtDW . ajv5jtlwij [ i_p ] = fq2jvssegz [ i_p ] ; } } memset ( & tmpF [ 0 ] ,
0 , 36U * sizeof ( real_T ) ) ; for ( i = 0 ; i < 6 ; i ++ ) { for ( kk = 0 ;
kk < 6 ; kk ++ ) { for ( i_p = 0 ; i_p < 601 ; i_p ++ ) { rtB . imwy3hbauq [
i_p ] = rtP . ImpulseResponseFunctionK_Value [ ( 601 * i + i_p ) + 3606 * kk
] * rtDW . ajv5jtlwij [ 6 * i_p + kk ] ; } tmpF [ i + 6 * kk ] = bkodxw3pn1 (
rtP . Timerelativetothecurrenttimestep_Value , rtB . imwy3hbauq ) ; } for (
i_p = 0 ; i_p < 6 ; i_p ++ ) { tmpF_p [ i_p ] = tmpF [ 6 * i_p + i ] ; }
fq2jvssegz [ i ] = aj44waf3ba ( tmpF_p ) ; } } for ( i = 0 ; i < 6 ; i ++ ) {
rtB . fengm4fmax [ i ] = dv1wlfujci [ i ] + fq2jvssegz [ i ] ; } { real_T * *
uBuffer = ( real_T * * ) & rtDW . aqyccuzu4f . TUbufferPtrs [ 0 ] ; real_T *
* tBuffer = ( real_T * * ) & rtDW . aqyccuzu4f . TUbufferPtrs [ 6 ] ; real_T
simTime = ssGetT ( rtS ) ; real_T tMinusDelay ; { int_T i1 ; real_T * y0 = &
dv1wlfujci [ 0 ] ; int_T * iw_Tail = & rtDW . anmk1ei3yl . Tail [ 0 ] ; int_T
* iw_Head = & rtDW . anmk1ei3yl . Head [ 0 ] ; int_T * iw_Last = & rtDW .
anmk1ei3yl . Last [ 0 ] ; int_T * iw_CircularBufSize = & rtDW . anmk1ei3yl .
CircularBufSize [ 0 ] ; for ( i1 = 0 ; i1 < 3 ; i1 ++ ) { tMinusDelay = ( (
rtP . TransportDelay_Delay > 0.0 ) ? rtP . TransportDelay_Delay : 0.0 ) ;
tMinusDelay = simTime - tMinusDelay ; y0 [ i1 ] = rt_TDelayInterpolate (
tMinusDelay , 0.0 , * tBuffer , * uBuffer , iw_CircularBufSize [ i1 ] , &
iw_Last [ i1 ] , iw_Tail [ i1 ] , iw_Head [ i1 ] , rtP .
TransportDelay_InitOutput , 0 , ( boolean_T ) ( ssIsMinorTimeStep ( rtS ) &&
( ssGetTimeOfLastOutput ( rtS ) == ssGetT ( rtS ) ) ) ) ; tBuffer ++ ;
uBuffer ++ ; } y0 = & dv1wlfujci [ 3 ] ; iw_Tail = & rtDW . anmk1ei3yl . Tail
[ 3 ] ; iw_Head = & rtDW . anmk1ei3yl . Head [ 3 ] ; iw_Last = & rtDW .
anmk1ei3yl . Last [ 3 ] ; iw_CircularBufSize = & rtDW . anmk1ei3yl .
CircularBufSize [ 3 ] ; for ( i1 = 0 ; i1 < 3 ; i1 ++ ) { tMinusDelay = ( (
rtP . TransportDelay_Delay > 0.0 ) ? rtP . TransportDelay_Delay : 0.0 ) ;
tMinusDelay = simTime - tMinusDelay ; y0 [ i1 ] = rt_TDelayInterpolate (
tMinusDelay , 0.0 , * tBuffer , * uBuffer , iw_CircularBufSize [ i1 ] , &
iw_Last [ i1 ] , iw_Tail [ i1 ] , iw_Head [ i1 ] , rtP .
TransportDelay_InitOutput , 0 , ( boolean_T ) ( ssIsMinorTimeStep ( rtS ) &&
( ssGetTimeOfLastOutput ( rtS ) == ssGetT ( rtS ) ) ) ) ; tBuffer ++ ;
uBuffer ++ ; } } } for ( i_p = 0 ; i_p < 6 ; i_p ++ ) { rtB . prqhmb3ipp [
i_p ] = 0.0 ; for ( i = 0 ; i < 6 ; i ++ ) { rtB . prqhmb3ipp [ i_p ] += rtP
. AddedMassForces_Gain [ 6 * i + i_p ] * dv1wlfujci [ i ] ; } } if (
ssIsSampleHit ( rtS , 1 , 0 ) ) { for ( i = 0 ; i < 6 ; i ++ ) { rtB .
hbwwq3eobw [ i ] = rtP . DispforRotation1_Value [ i ] ; } rtB . hbwwq3eobw [
2 ] = rtP . Gravity_Value * rtP . GravityForce_Value - rtP . Density_Value *
rtP . Gravity1_Value * rtP . GravityForce1_Value ; } gxsouypddm ( & rtB .
eygknao1u4 [ 2 ] , & rtB . hxduip3sjb ) ; dv1wlfujci [ 0 ] = rtB . eygknao1u4
[ 9 ] - rtP . CenterofGravity_Value [ 0 ] ; dv1wlfujci [ 1 ] = rtB .
eygknao1u4 [ 10 ] - rtP . CenterofGravity_Value [ 1 ] ; dv1wlfujci [ 2 ] =
rtB . eygknao1u4 [ 11 ] - rtP . CenterofGravity_Value [ 2 ] ; dv1wlfujci [ 3
] = rtB . hxduip3sjb . pgkwjiqtkn [ 0 ] - rtP . DispforRotation_Value [ 0 ] ;
dv1wlfujci [ 4 ] = rtB . hxduip3sjb . pgkwjiqtkn [ 1 ] - rtP .
DispforRotation_Value [ 1 ] ; dv1wlfujci [ 5 ] = rtB . hxduip3sjb .
pgkwjiqtkn [ 2 ] - rtP . DispforRotation_Value [ 2 ] ; for ( i_p = 0 ; i_p <
6 ; i_p ++ ) { ojwgfbilnb = 0.0 ; for ( i = 0 ; i < 6 ; i ++ ) { ojwgfbilnb
+= rtP . RestoringForces_Gain [ 6 * i + i_p ] * dv1wlfujci [ i ] ; } rtB .
lodjazp425 [ i_p ] = rtB . hbwwq3eobw [ i_p ] + ojwgfbilnb ; } for ( i_p = 0
; i_p < 6 ; i_p ++ ) { tmpF_p [ i_p ] = eph0oh1i4b [ i_p ] *
muDoubleScalarAbs ( eph0oh1i4b [ i_p ] ) ; } for ( i_p = 0 ; i_p < 6 ; i_p ++
) { rtB . m1oa4qzzhe [ i_p ] = 0.0 ; for ( i = 0 ; i < 6 ; i ++ ) { rtB .
m1oa4qzzhe [ i_p ] += rtP . ViscousDamping_Gain [ 6 * i + i_p ] * tmpF_p [ i
] ; } rtB . gvkcwsrbjc [ i_p ] = 0.0 ; for ( i = 0 ; i < 6 ; i ++ ) { rtB .
gvkcwsrbjc [ i_p ] += rtP . LinearDamping_Gain [ 6 * i + i_p ] * eph0oh1i4b [
i ] ; } } iyvfbn10dh [ 0 ] = rtB . eygknao1u4 [ 9 ] - rtP .
CenterofGravity_Value_ehagwuwxhi [ 0 ] ; iyvfbn10dh [ 1 ] = rtB . eygknao1u4
[ 10 ] - rtP . CenterofGravity_Value_ehagwuwxhi [ 1 ] ; iyvfbn10dh [ 2 ] =
rtB . eygknao1u4 [ 11 ] - rtP . CenterofGravity_Value_ehagwuwxhi [ 2 ] ;
iyvfbn10dh [ 3 ] = rtB . hxduip3sjb . pgkwjiqtkn [ 0 ] - rtP .
DispforRotation_Value_n4dcoglnve [ 0 ] ; iyvfbn10dh [ 4 ] = rtB . hxduip3sjb
. pgkwjiqtkn [ 1 ] - rtP . DispforRotation_Value_n4dcoglnve [ 1 ] ;
iyvfbn10dh [ 5 ] = rtB . hxduip3sjb . pgkwjiqtkn [ 2 ] - rtP .
DispforRotation_Value_n4dcoglnve [ 2 ] ; for ( i = 0 ; i < 6 ; i ++ ) { rtB .
e25y0jyyb1 [ i ] = ( rtP . MooringStiffness_Gain * iyvfbn10dh [ i ] + rtP .
MooringDamping_Gain * eph0oh1i4b [ i ] ) - rtP . MooringPreTension_Value ; }
if ( ssIsMajorTimeStep ( rtS ) ) { if ( rtP . WaveType_Value_ghmpcbwqgc <
20.0 ) { rtAction = 0 ; } else { rtAction = 1 ; } rtDW . bxqmm1o411 =
rtAction ; } else { rtAction = rtDW . bxqmm1o411 ; } switch ( rtAction ) {
case 0 : i0grvgounu ( rtS , fky3rqwq4u , ( jjq30b5cja * ) & rtP . i0grvgounuc
) ; if ( ssIsMajorTimeStep ( rtS ) ) { srUpdateBC ( rtDW . i0grvgounuc .
e2lhwvg4n3 ) ; } break ; case 1 : aqx150ksyt ( rtB . e3kvmjjnay , fky3rqwq4u
, ( dnlp5zegym * ) & rtP . aqx150ksytr ) ; if ( ssIsMajorTimeStep ( rtS ) ) {
srUpdateBC ( rtDW . aqx150ksytr . ofnp3tiibi ) ; } break ; } if (
ssIsMajorTimeStep ( rtS ) ) { if ( rtB . e3kvmjjnay < rtP .
RampFunctionTime_Value ) { rtAction = 0 ; } else { rtAction = 1 ; } rtDW .
nofdnsita2 = rtAction ; } else { rtAction = rtDW . nofdnsita2 ; } switch (
rtAction ) { case 0 : l1kcj50fwe ( rtS , fky3rqwq4u , rtB . gh1qfaqu5w , (
fd5dgqf4g3 * ) & rtP . l1kcj50fwey ) ; if ( ssIsMajorTimeStep ( rtS ) ) {
srUpdateBC ( rtDW . l1kcj50fwey . ckdn4xd4hz ) ; } break ; case 1 :
p14hwlcq5a ( fky3rqwq4u , rtB . gh1qfaqu5w ) ; if ( ssIsMajorTimeStep ( rtS )
) { srUpdateBC ( rtDW . p14hwlcq5ag . dbhao2hevj ) ; } break ; } for ( i = 0
; i < 6 ; i ++ ) { rtB . oci4zspmmv [ i ] = ( ( ( ( ( rtB . gh1qfaqu5w [ i ]
- rtB . fengm4fmax [ i ] ) - rtB . prqhmb3ipp [ i ] ) - rtB . lodjazp425 [ i
] ) - rtB . m1oa4qzzhe [ i ] ) - rtB . gvkcwsrbjc [ i ] ) - rtB . e25y0jyyb1
[ i ] ; } rtB . biiiks5bdq [ 0 ] = rtB . oci4zspmmv [ 0 ] ; rtB . biiiks5bdq
[ 1 ] = 0.0 ; rtB . biiiks5bdq [ 2 ] = 0.0 ; rtB . biiiks5bdq [ 3 ] = 0.0 ;
rtB . bweohccgoh [ 0 ] = rtB . oci4zspmmv [ 1 ] ; rtB . bweohccgoh [ 1 ] =
0.0 ; rtB . bweohccgoh [ 2 ] = 0.0 ; rtB . bweohccgoh [ 3 ] = 0.0 ; rtB .
eyb1czk053 [ 0 ] = rtB . oci4zspmmv [ 2 ] ; rtB . eyb1czk053 [ 1 ] = 0.0 ;
rtB . eyb1czk053 [ 2 ] = 0.0 ; rtB . eyb1czk053 [ 3 ] = 0.0 ; rtB .
hoyspdnpx3 [ 0 ] = rtB . oci4zspmmv [ 3 ] ; rtB . hoyspdnpx3 [ 1 ] = 0.0 ;
rtB . hoyspdnpx3 [ 2 ] = 0.0 ; rtB . hoyspdnpx3 [ 3 ] = 0.0 ; rtB .
kia00mwvqk [ 0 ] = rtB . oci4zspmmv [ 4 ] ; rtB . kia00mwvqk [ 1 ] = 0.0 ;
rtB . kia00mwvqk [ 2 ] = 0.0 ; rtB . kia00mwvqk [ 3 ] = 0.0 ; rtB .
jr2ghgakgm [ 0 ] = rtB . oci4zspmmv [ 5 ] ; rtB . jr2ghgakgm [ 1 ] = 0.0 ;
rtB . jr2ghgakgm [ 2 ] = 0.0 ; rtB . jr2ghgakgm [ 3 ] = 0.0 ; iyvfbn10dh [ 0
] = rtB . eygknao1u4 [ 25 ] ; iyvfbn10dh [ 1 ] = rtB . eygknao1u4 [ 26 ] ;
iyvfbn10dh [ 2 ] = rtB . eygknao1u4 [ 27 ] ; iyvfbn10dh [ 3 ] = rtB .
eygknao1u4 [ 19 ] ; iyvfbn10dh [ 4 ] = rtB . eygknao1u4 [ 20 ] ; iyvfbn10dh [
5 ] = rtB . eygknao1u4 [ 21 ] ; for ( i_p = 0 ; i_p < 6 ; i_p ++ ) {
dv1wlfujci [ i_p ] = 0.0 ; for ( i = 0 ; i < 6 ; i ++ ) { dv1wlfujci [ i_p ]
+= rtP . DampingForces_Gain_lg5w5letwj [ 6 * i + i_p ] * iyvfbn10dh [ i ] ; }
} fq2jvssegz [ 0 ] = rtB . eygknao1u4 [ 25 ] ; fq2jvssegz [ 1 ] = rtB .
eygknao1u4 [ 26 ] ; fq2jvssegz [ 2 ] = rtB . eygknao1u4 [ 27 ] ; fq2jvssegz [
3 ] = rtB . eygknao1u4 [ 19 ] ; fq2jvssegz [ 4 ] = rtB . eygknao1u4 [ 20 ] ;
fq2jvssegz [ 5 ] = rtB . eygknao1u4 [ 21 ] ; if ( rtP .
WaveType_Value_kmlj0k40q4 == 10.0 ) { for ( i = 0 ; i < 6 ; i ++ ) {
fq2jvssegz [ i ] = 0.0 ; } } else { if ( ! rtDW . ba32jnnpzi ) { memcpy ( &
rtDW . cvt2mfevlv [ 0 ] , & rtP . InitialZeroVelocity_Value_espd2duag2 [ 0 ]
, 3606U * sizeof ( real_T ) ) ; rtDW . ba32jnnpzi = true ; rtDW . nyoeq2soc1
= 0.0 ; } else { rtDW . nyoeq2soc1 ++ ; if ( muDoubleScalarAbs ( ( rtDW .
nyoeq2soc1 - muDoubleScalarFloor ( rtDW . nyoeq2soc1 / 5.0 ) * 5.0 ) - 1.0 )
< 1.0E-8 ) { for ( i_p = 0 ; i_p < 600 ; i_p ++ ) { for ( i = 0 ; i < 6 ; i
++ ) { rtB . b4nvex32ha [ i + 6 * i_p ] = rtDW . cvt2mfevlv [ 6 * i_p + i ] ;
} } for ( i_p = 0 ; i_p < 600 ; i_p ++ ) { for ( i = 0 ; i < 6 ; i ++ ) {
rtDW . cvt2mfevlv [ i + 6 * ( 1 + i_p ) ] = rtB . b4nvex32ha [ 6 * i_p + i ]
; } } } for ( i_p = 0 ; i_p < 6 ; i_p ++ ) { rtDW . cvt2mfevlv [ i_p ] =
fq2jvssegz [ i_p ] ; } } memset ( & tmpF [ 0 ] , 0 , 36U * sizeof ( real_T )
) ; for ( i = 0 ; i < 6 ; i ++ ) { for ( kk = 0 ; kk < 6 ; kk ++ ) { for (
i_p = 0 ; i_p < 601 ; i_p ++ ) { rtB . imwy3hbauq [ i_p ] = rtP .
ImpulseResponseFunctionK_Value_oxs4p44uy4 [ ( 601 * i + i_p ) + 3606 * kk ] *
rtDW . cvt2mfevlv [ 6 * i_p + kk ] ; } tmpF [ i + 6 * kk ] = ctqhiaiar1 ( rtP
. Timerelativetothecurrenttimestep_Value_pdxfuxlbzx , rtB . imwy3hbauq ) ; }
for ( i_p = 0 ; i_p < 6 ; i_p ++ ) { tmpF_p [ i_p ] = tmpF [ 6 * i_p + i ] ;
} fq2jvssegz [ i ] = f1pbdll3kt ( tmpF_p ) ; } } for ( i = 0 ; i < 6 ; i ++ )
{ rtB . emwpmefl5g [ i ] = dv1wlfujci [ i ] + fq2jvssegz [ i ] ; } { real_T *
* uBuffer = ( real_T * * ) & rtDW . pj0j1eoun4 . TUbufferPtrs [ 0 ] ; real_T
* * tBuffer = ( real_T * * ) & rtDW . pj0j1eoun4 . TUbufferPtrs [ 6 ] ;
real_T simTime = ssGetT ( rtS ) ; real_T tMinusDelay ; { int_T i1 ; real_T *
y0 = & dv1wlfujci [ 0 ] ; int_T * iw_Tail = & rtDW . ke454bg2ir . Tail [ 0 ]
; int_T * iw_Head = & rtDW . ke454bg2ir . Head [ 0 ] ; int_T * iw_Last = &
rtDW . ke454bg2ir . Last [ 0 ] ; int_T * iw_CircularBufSize = & rtDW .
ke454bg2ir . CircularBufSize [ 0 ] ; for ( i1 = 0 ; i1 < 3 ; i1 ++ ) {
tMinusDelay = ( ( rtP . TransportDelay_Delay_idbp52hm4z > 0.0 ) ? rtP .
TransportDelay_Delay_idbp52hm4z : 0.0 ) ; tMinusDelay = simTime - tMinusDelay
; y0 [ i1 ] = rt_TDelayInterpolate ( tMinusDelay , 0.0 , * tBuffer , *
uBuffer , iw_CircularBufSize [ i1 ] , & iw_Last [ i1 ] , iw_Tail [ i1 ] ,
iw_Head [ i1 ] , rtP . TransportDelay_InitOutput_ok1nab0an0 , 0 , ( boolean_T
) ( ssIsMinorTimeStep ( rtS ) && ( ssGetTimeOfLastOutput ( rtS ) == ssGetT (
rtS ) ) ) ) ; tBuffer ++ ; uBuffer ++ ; } y0 = & dv1wlfujci [ 3 ] ; iw_Tail =
& rtDW . ke454bg2ir . Tail [ 3 ] ; iw_Head = & rtDW . ke454bg2ir . Head [ 3 ]
; iw_Last = & rtDW . ke454bg2ir . Last [ 3 ] ; iw_CircularBufSize = & rtDW .
ke454bg2ir . CircularBufSize [ 3 ] ; for ( i1 = 0 ; i1 < 3 ; i1 ++ ) {
tMinusDelay = ( ( rtP . TransportDelay_Delay_idbp52hm4z > 0.0 ) ? rtP .
TransportDelay_Delay_idbp52hm4z : 0.0 ) ; tMinusDelay = simTime - tMinusDelay
; y0 [ i1 ] = rt_TDelayInterpolate ( tMinusDelay , 0.0 , * tBuffer , *
uBuffer , iw_CircularBufSize [ i1 ] , & iw_Last [ i1 ] , iw_Tail [ i1 ] ,
iw_Head [ i1 ] , rtP . TransportDelay_InitOutput_ok1nab0an0 , 0 , ( boolean_T
) ( ssIsMinorTimeStep ( rtS ) && ( ssGetTimeOfLastOutput ( rtS ) == ssGetT (
rtS ) ) ) ) ; tBuffer ++ ; uBuffer ++ ; } } } for ( i_p = 0 ; i_p < 6 ; i_p
++ ) { rtB . jqhg2efiao [ i_p ] = 0.0 ; for ( i = 0 ; i < 6 ; i ++ ) { rtB .
jqhg2efiao [ i_p ] += rtP . AddedMassForces_Gain_nn4j25aboc [ 6 * i + i_p ] *
dv1wlfujci [ i ] ; } } if ( ssIsSampleHit ( rtS , 1 , 0 ) ) { for ( i = 0 ; i
< 6 ; i ++ ) { rtB . bsey3hhgmx [ i ] = rtP .
DispforRotation1_Value_bb2prsf5d3 [ i ] ; } rtB . bsey3hhgmx [ 2 ] = rtP .
Gravity_Value_l5d2lookat * rtP . GravityForce_Value_cfqmx3j5kp - rtP .
Density_Value_aih4vdbghl * rtP . Gravity1_Value_mtxwpjdnnl * rtP .
GravityForce1_Value_lk4e3aezgl ; } gxsouypddm ( & rtB . eygknao1u4 [ 15 ] , &
rtB . gk1vvo5dud ) ; dv1wlfujci [ 0 ] = rtB . eygknao1u4 [ 22 ] - rtP .
CenterofGravity_Value_md1kocvst4 [ 0 ] ; dv1wlfujci [ 1 ] = rtB . eygknao1u4
[ 23 ] - rtP . CenterofGravity_Value_md1kocvst4 [ 1 ] ; dv1wlfujci [ 2 ] =
rtB . eygknao1u4 [ 24 ] - rtP . CenterofGravity_Value_md1kocvst4 [ 2 ] ;
dv1wlfujci [ 3 ] = rtB . gk1vvo5dud . pgkwjiqtkn [ 0 ] - rtP .
DispforRotation_Value_e2df3x2zha [ 0 ] ; dv1wlfujci [ 4 ] = rtB . gk1vvo5dud
. pgkwjiqtkn [ 1 ] - rtP . DispforRotation_Value_e2df3x2zha [ 1 ] ;
dv1wlfujci [ 5 ] = rtB . gk1vvo5dud . pgkwjiqtkn [ 2 ] - rtP .
DispforRotation_Value_e2df3x2zha [ 2 ] ; for ( i_p = 0 ; i_p < 6 ; i_p ++ ) {
ojwgfbilnb = 0.0 ; for ( i = 0 ; i < 6 ; i ++ ) { ojwgfbilnb += rtP .
RestoringForces_Gain_gtjxe5fum0 [ 6 * i + i_p ] * dv1wlfujci [ i ] ; } rtB .
dxffftz4xe [ i_p ] = rtB . bsey3hhgmx [ i_p ] + ojwgfbilnb ; } for ( i = 0 ;
i < 6 ; i ++ ) { dv1wlfujci [ i ] = muDoubleScalarAbs ( iyvfbn10dh [ i ] ) ;
dv1wlfujci [ i ] *= iyvfbn10dh [ i ] ; } for ( i_p = 0 ; i_p < 6 ; i_p ++ ) {
rtB . jcjoil1xwx [ i_p ] = 0.0 ; for ( i = 0 ; i < 6 ; i ++ ) { rtB .
jcjoil1xwx [ i_p ] += rtP . ViscousDamping_Gain_muya5lc1kx [ 6 * i + i_p ] *
dv1wlfujci [ i ] ; } rtB . ahbtwvlwht [ i_p ] = 0.0 ; for ( i = 0 ; i < 6 ; i
++ ) { rtB . ahbtwvlwht [ i_p ] += rtP . LinearDamping_Gain_bf1ntj5xm0 [ 6 *
i + i_p ] * iyvfbn10dh [ i ] ; } } dv1wlfujci [ 0 ] = rtB . eygknao1u4 [ 22 ]
- rtP . CenterofGravity_Value_b3htdqbdxy [ 0 ] ; dv1wlfujci [ 1 ] = rtB .
eygknao1u4 [ 23 ] - rtP . CenterofGravity_Value_b3htdqbdxy [ 1 ] ; dv1wlfujci
[ 2 ] = rtB . eygknao1u4 [ 24 ] - rtP . CenterofGravity_Value_b3htdqbdxy [ 2
] ; dv1wlfujci [ 3 ] = rtB . gk1vvo5dud . pgkwjiqtkn [ 0 ] - rtP .
DispforRotation_Value_hu2rwtrpwt [ 0 ] ; dv1wlfujci [ 4 ] = rtB . gk1vvo5dud
. pgkwjiqtkn [ 1 ] - rtP . DispforRotation_Value_hu2rwtrpwt [ 1 ] ;
dv1wlfujci [ 5 ] = rtB . gk1vvo5dud . pgkwjiqtkn [ 2 ] - rtP .
DispforRotation_Value_hu2rwtrpwt [ 2 ] ; for ( i = 0 ; i < 6 ; i ++ ) { rtB .
gxr43wuykr [ i ] = ( rtP . MooringStiffness_Gain_ftpngfcbjw * dv1wlfujci [ i
] + rtP . MooringDamping_Gain_hnfjdm1021 * iyvfbn10dh [ i ] ) - rtP .
MooringPreTension_Value_klqp1nyvd4 ; } if ( ssIsMajorTimeStep ( rtS ) ) { if
( rtP . WaveType_Value_cigtbjvhxd < 20.0 ) { rtAction = 0 ; } else { rtAction
= 1 ; } rtDW . if5tadkli2 = rtAction ; } else { rtAction = rtDW . if5tadkli2
; } switch ( rtAction ) { case 0 : i0grvgounu ( rtS , hvxyz2hiiz , (
jjq30b5cja * ) & rtP . bt1qvoldbv ) ; if ( ssIsMajorTimeStep ( rtS ) ) {
srUpdateBC ( rtDW . bt1qvoldbv . e2lhwvg4n3 ) ; } break ; case 1 : aqx150ksyt
( rtB . e3kvmjjnay , hvxyz2hiiz , ( dnlp5zegym * ) & rtP . arvvtfsmo3 ) ; if
( ssIsMajorTimeStep ( rtS ) ) { srUpdateBC ( rtDW . arvvtfsmo3 . ofnp3tiibi )
; } break ; } if ( ssIsMajorTimeStep ( rtS ) ) { if ( rtB . e3kvmjjnay < rtP
. RampFunctionTime_Value_n3y3wgeehz ) { rtAction = 0 ; } else { rtAction = 1
; } rtDW . gn2tshspwh = rtAction ; } else { rtAction = rtDW . gn2tshspwh ; }
switch ( rtAction ) { case 0 : l1kcj50fwe ( rtS , hvxyz2hiiz , rtB .
fn50r1iv2s , ( fd5dgqf4g3 * ) & rtP . kw4gz4nylz ) ; if ( ssIsMajorTimeStep (
rtS ) ) { srUpdateBC ( rtDW . kw4gz4nylz . ckdn4xd4hz ) ; } break ; case 1 :
p14hwlcq5a ( hvxyz2hiiz , rtB . fn50r1iv2s ) ; if ( ssIsMajorTimeStep ( rtS )
) { srUpdateBC ( rtDW . cy14v3kgd2 . dbhao2hevj ) ; } break ; } for ( i = 0 ;
i < 6 ; i ++ ) { rtB . edbqtdapxx [ i ] = ( ( ( ( ( rtB . fn50r1iv2s [ i ] -
rtB . emwpmefl5g [ i ] ) - rtB . jqhg2efiao [ i ] ) - rtB . dxffftz4xe [ i ]
) - rtB . jcjoil1xwx [ i ] ) - rtB . ahbtwvlwht [ i ] ) - rtB . gxr43wuykr [
i ] ; } rtB . mionfsauuc [ 0 ] = rtB . edbqtdapxx [ 0 ] ; rtB . mionfsauuc [
1 ] = 0.0 ; rtB . mionfsauuc [ 2 ] = 0.0 ; rtB . mionfsauuc [ 3 ] = 0.0 ; rtB
. lkkej41yzf [ 0 ] = rtB . edbqtdapxx [ 1 ] ; rtB . lkkej41yzf [ 1 ] = 0.0 ;
rtB . lkkej41yzf [ 2 ] = 0.0 ; rtB . lkkej41yzf [ 3 ] = 0.0 ; rtB .
k02keb4tly [ 0 ] = rtB . edbqtdapxx [ 2 ] ; rtB . k02keb4tly [ 1 ] = 0.0 ;
rtB . k02keb4tly [ 2 ] = 0.0 ; rtB . k02keb4tly [ 3 ] = 0.0 ; rtB .
hoc2fuxv0g [ 0 ] = rtB . edbqtdapxx [ 3 ] ; rtB . hoc2fuxv0g [ 1 ] = 0.0 ;
rtB . hoc2fuxv0g [ 2 ] = 0.0 ; rtB . hoc2fuxv0g [ 3 ] = 0.0 ; rtB .
gbda5p2r2f [ 0 ] = rtB . edbqtdapxx [ 4 ] ; rtB . gbda5p2r2f [ 1 ] = 0.0 ;
rtB . gbda5p2r2f [ 2 ] = 0.0 ; rtB . gbda5p2r2f [ 3 ] = 0.0 ; rtB .
j1dwgbinuj [ 0 ] = rtB . edbqtdapxx [ 5 ] ; rtB . j1dwgbinuj [ 1 ] = 0.0 ;
rtB . j1dwgbinuj [ 2 ] = 0.0 ; rtB . j1dwgbinuj [ 3 ] = 0.0 ; simulationData
= ( NeslSimulationData * ) rtDW . hjs5z0ka4j ; time_e = ssGetT ( rtS ) ;
simulationData -> mData -> mTime . mN = 1 ; simulationData -> mData -> mTime
. mX = & time_e ; simulationData -> mData -> mContStates . mN = 0 ;
simulationData -> mData -> mContStates . mX = NULL ; simulationData -> mData
-> mDiscStates . mN = 0 ; simulationData -> mData -> mDiscStates . mX = NULL
; simulationData -> mData -> mModeVector . mN = 0 ; simulationData -> mData
-> mModeVector . mX = NULL ; tmp = false ; simulationData -> mData ->
mFoundZcEvents = tmp ; simulationData -> mData -> mIsMajorTimeStep =
ssIsMajorTimeStep ( rtS ) ; tmp = ( ssGetMdlInfoPtr ( rtS ) -> mdlFlags .
solverAssertCheck == 1U ) ; simulationData -> mData -> mIsSolverAssertCheck =
tmp ; simulationData -> mData -> mIsSolverCheckingCIC = false ;
simulationData -> mData -> mIsComputingJacobian = false ; simulationData ->
mData -> mIsSolverRequestingReset = false ; tmp_j [ 0 ] = 0 ; tmp_g [ 0 ] =
rtB . biiiks5bdq [ 0 ] ; tmp_g [ 1 ] = rtB . biiiks5bdq [ 1 ] ; tmp_g [ 2 ] =
rtB . biiiks5bdq [ 2 ] ; tmp_g [ 3 ] = rtB . biiiks5bdq [ 3 ] ; tmp_j [ 1 ] =
4 ; tmp_g [ 4 ] = rtB . bweohccgoh [ 0 ] ; tmp_g [ 5 ] = rtB . bweohccgoh [ 1
] ; tmp_g [ 6 ] = rtB . bweohccgoh [ 2 ] ; tmp_g [ 7 ] = rtB . bweohccgoh [ 3
] ; tmp_j [ 2 ] = 8 ; tmp_g [ 8 ] = rtB . eyb1czk053 [ 0 ] ; tmp_g [ 9 ] =
rtB . eyb1czk053 [ 1 ] ; tmp_g [ 10 ] = rtB . eyb1czk053 [ 2 ] ; tmp_g [ 11 ]
= rtB . eyb1czk053 [ 3 ] ; tmp_j [ 3 ] = 12 ; tmp_g [ 12 ] = rtB . hoyspdnpx3
[ 0 ] ; tmp_g [ 13 ] = rtB . hoyspdnpx3 [ 1 ] ; tmp_g [ 14 ] = rtB .
hoyspdnpx3 [ 2 ] ; tmp_g [ 15 ] = rtB . hoyspdnpx3 [ 3 ] ; tmp_j [ 4 ] = 16 ;
tmp_g [ 16 ] = rtB . kia00mwvqk [ 0 ] ; tmp_g [ 17 ] = rtB . kia00mwvqk [ 1 ]
; tmp_g [ 18 ] = rtB . kia00mwvqk [ 2 ] ; tmp_g [ 19 ] = rtB . kia00mwvqk [ 3
] ; tmp_j [ 5 ] = 20 ; tmp_g [ 20 ] = rtB . jr2ghgakgm [ 0 ] ; tmp_g [ 21 ] =
rtB . jr2ghgakgm [ 1 ] ; tmp_g [ 22 ] = rtB . jr2ghgakgm [ 2 ] ; tmp_g [ 23 ]
= rtB . jr2ghgakgm [ 3 ] ; tmp_j [ 6 ] = 24 ; tmp_g [ 24 ] = rtB . mionfsauuc
[ 0 ] ; tmp_g [ 25 ] = rtB . mionfsauuc [ 1 ] ; tmp_g [ 26 ] = rtB .
mionfsauuc [ 2 ] ; tmp_g [ 27 ] = rtB . mionfsauuc [ 3 ] ; tmp_j [ 7 ] = 28 ;
tmp_g [ 28 ] = rtB . lkkej41yzf [ 0 ] ; tmp_g [ 29 ] = rtB . lkkej41yzf [ 1 ]
; tmp_g [ 30 ] = rtB . lkkej41yzf [ 2 ] ; tmp_g [ 31 ] = rtB . lkkej41yzf [ 3
] ; tmp_j [ 8 ] = 32 ; tmp_g [ 32 ] = rtB . k02keb4tly [ 0 ] ; tmp_g [ 33 ] =
rtB . k02keb4tly [ 1 ] ; tmp_g [ 34 ] = rtB . k02keb4tly [ 2 ] ; tmp_g [ 35 ]
= rtB . k02keb4tly [ 3 ] ; tmp_j [ 9 ] = 36 ; tmp_g [ 36 ] = rtB . hoc2fuxv0g
[ 0 ] ; tmp_g [ 37 ] = rtB . hoc2fuxv0g [ 1 ] ; tmp_g [ 38 ] = rtB .
hoc2fuxv0g [ 2 ] ; tmp_g [ 39 ] = rtB . hoc2fuxv0g [ 3 ] ; tmp_j [ 10 ] = 40
; tmp_g [ 40 ] = rtB . gbda5p2r2f [ 0 ] ; tmp_g [ 41 ] = rtB . gbda5p2r2f [ 1
] ; tmp_g [ 42 ] = rtB . gbda5p2r2f [ 2 ] ; tmp_g [ 43 ] = rtB . gbda5p2r2f [
3 ] ; tmp_j [ 11 ] = 44 ; tmp_g [ 44 ] = rtB . j1dwgbinuj [ 0 ] ; tmp_g [ 45
] = rtB . j1dwgbinuj [ 1 ] ; tmp_g [ 46 ] = rtB . j1dwgbinuj [ 2 ] ; tmp_g [
47 ] = rtB . j1dwgbinuj [ 3 ] ; tmp_j [ 12 ] = 48 ; tmp_g [ 48 ] = rtB .
pzk0tdps0y [ 0 ] ; tmp_g [ 49 ] = rtB . pzk0tdps0y [ 1 ] ; tmp_g [ 50 ] = rtB
. pzk0tdps0y [ 2 ] ; tmp_g [ 51 ] = rtB . pzk0tdps0y [ 3 ] ; tmp_j [ 13 ] =
52 ; simulationData -> mData -> mInputValues . mN = 52 ; simulationData ->
mData -> mInputValues . mX = & tmp_g [ 0 ] ; simulationData -> mData ->
mInputOffsets . mN = 14 ; simulationData -> mData -> mInputOffsets . mX = &
tmp_j [ 0 ] ; simulationData -> mData -> mOutputs . mN = 24 ; simulationData
-> mData -> mOutputs . mX = & rtB . hahanrb1fp [ 0 ] ; simulationData ->
mData -> mSampleHits . mN = 0 ; simulationData -> mData -> mSampleHits . mX =
NULL ; simulationData -> mData -> mIsFundamentalSampleHit = false ;
diagnosticManager = ( NeuDiagnosticManager * ) rtDW . hafmpp5qwx ;
diagnosticTree = neu_diagnostic_manager_get_initial_tree ( diagnosticManager
) ; i = ne_simulator_method ( ( NeslSimulator * ) rtDW . grkodaq2kd ,
NESL_SIM_OUTPUTS , simulationData , diagnosticManager ) ; if ( i != 0 ) { tmp
= error_buffer_is_empty ( ssGetErrorStatus ( rtS ) ) ; if ( tmp ) { msg =
rtw_diagnostics_msg ( diagnosticTree ) ; ssSetErrorStatus ( rtS , msg ) ; } }
if ( ssIsSampleHit ( rtS , 1 , 0 ) ) { rtB . etx2cwdnb4 [ 0 ] = rtB .
hahanrb1fp [ 3 ] ; rtB . etx2cwdnb4 [ 1 ] = rtB . hahanrb1fp [ 4 ] ; rtB .
etx2cwdnb4 [ 2 ] = rtB . hahanrb1fp [ 5 ] ; rtB . etx2cwdnb4 [ 3 ] = rtB .
hahanrb1fp [ 0 ] ; rtB . etx2cwdnb4 [ 4 ] = rtB . hahanrb1fp [ 1 ] ; rtB .
etx2cwdnb4 [ 5 ] = rtB . hahanrb1fp [ 2 ] ; { double locTime = ssGetTaskTime
( rtS , 1 ) ; if ( ssGetLogOutput ( rtS ) ) { rt_UpdateStructLogVar ( (
StructLogVar * ) rtDW . kmx1camcmy . LoggedData , & locTime , & rtB .
etx2cwdnb4 [ 0 ] ) ; } } rtB . o3ytx35x4v [ 0 ] = rtB . eygknao1u4 [ 9 ] ;
rtB . o3ytx35x4v [ 1 ] = rtB . eygknao1u4 [ 10 ] ; rtB . o3ytx35x4v [ 2 ] =
rtB . eygknao1u4 [ 11 ] ; rtB . o3ytx35x4v [ 3 ] = rtB . hxduip3sjb .
pgkwjiqtkn [ 0 ] ; rtB . o3ytx35x4v [ 4 ] = rtB . hxduip3sjb . pgkwjiqtkn [ 1
] ; rtB . o3ytx35x4v [ 5 ] = rtB . hxduip3sjb . pgkwjiqtkn [ 2 ] ; rtB .
o3ytx35x4v [ 6 ] = rtB . eygknao1u4 [ 12 ] ; rtB . o3ytx35x4v [ 7 ] = rtB .
eygknao1u4 [ 13 ] ; rtB . o3ytx35x4v [ 8 ] = rtB . eygknao1u4 [ 14 ] ; rtB .
o3ytx35x4v [ 9 ] = rtB . eygknao1u4 [ 6 ] ; rtB . o3ytx35x4v [ 10 ] = rtB .
eygknao1u4 [ 7 ] ; rtB . o3ytx35x4v [ 11 ] = rtB . eygknao1u4 [ 8 ] ; rtB .
o3ytx35x4v [ 12 ] = rtB . hahanrb1fp [ 15 ] ; rtB . o3ytx35x4v [ 13 ] = rtB .
hahanrb1fp [ 16 ] ; rtB . o3ytx35x4v [ 14 ] = rtB . hahanrb1fp [ 17 ] ; rtB .
o3ytx35x4v [ 15 ] = rtB . hahanrb1fp [ 12 ] ; rtB . o3ytx35x4v [ 16 ] = rtB .
hahanrb1fp [ 13 ] ; rtB . o3ytx35x4v [ 17 ] = rtB . hahanrb1fp [ 14 ] ; for (
i = 0 ; i < 6 ; i ++ ) { rtB . o3ytx35x4v [ i + 18 ] = rtB . oci4zspmmv [ i ]
; } for ( i = 0 ; i < 6 ; i ++ ) { rtB . o3ytx35x4v [ i + 24 ] = rtB .
gh1qfaqu5w [ i ] ; } for ( i = 0 ; i < 6 ; i ++ ) { rtB . o3ytx35x4v [ i + 30
] = rtB . fengm4fmax [ i ] ; } for ( i = 0 ; i < 6 ; i ++ ) { rtB .
o3ytx35x4v [ i + 36 ] = rtB . prqhmb3ipp [ i ] ; } for ( i = 0 ; i < 6 ; i ++
) { rtB . o3ytx35x4v [ i + 42 ] = rtB . lodjazp425 [ i ] ; } for ( i = 0 ; i
< 6 ; i ++ ) { rtB . o3ytx35x4v [ i + 48 ] = rtB . m1oa4qzzhe [ i ] ; } for (
i = 0 ; i < 6 ; i ++ ) { rtB . o3ytx35x4v [ i + 54 ] = rtB . e25y0jyyb1 [ i ]
; } for ( i = 0 ; i < 6 ; i ++ ) { rtB . o3ytx35x4v [ i + 60 ] = rtB .
gvkcwsrbjc [ i ] ; } { double locTime = ssGetTaskTime ( rtS , 1 ) ; if (
ssGetLogOutput ( rtS ) ) { rt_UpdateStructLogVar ( ( StructLogVar * ) rtDW .
jzxtw4vtua . LoggedData , & locTime , & rtB . o3ytx35x4v [ 0 ] ) ; } } rtB .
b13mdyyvoc [ 0 ] = rtB . eygknao1u4 [ 22 ] ; rtB . b13mdyyvoc [ 1 ] = rtB .
eygknao1u4 [ 23 ] ; rtB . b13mdyyvoc [ 2 ] = rtB . eygknao1u4 [ 24 ] ; rtB .
b13mdyyvoc [ 3 ] = rtB . gk1vvo5dud . pgkwjiqtkn [ 0 ] ; rtB . b13mdyyvoc [ 4
] = rtB . gk1vvo5dud . pgkwjiqtkn [ 1 ] ; rtB . b13mdyyvoc [ 5 ] = rtB .
gk1vvo5dud . pgkwjiqtkn [ 2 ] ; rtB . b13mdyyvoc [ 6 ] = rtB . eygknao1u4 [
25 ] ; rtB . b13mdyyvoc [ 7 ] = rtB . eygknao1u4 [ 26 ] ; rtB . b13mdyyvoc [
8 ] = rtB . eygknao1u4 [ 27 ] ; rtB . b13mdyyvoc [ 9 ] = rtB . eygknao1u4 [
19 ] ; rtB . b13mdyyvoc [ 10 ] = rtB . eygknao1u4 [ 20 ] ; rtB . b13mdyyvoc [
11 ] = rtB . eygknao1u4 [ 21 ] ; rtB . b13mdyyvoc [ 12 ] = rtB . hahanrb1fp [
21 ] ; rtB . b13mdyyvoc [ 13 ] = rtB . hahanrb1fp [ 22 ] ; rtB . b13mdyyvoc [
14 ] = rtB . hahanrb1fp [ 23 ] ; rtB . b13mdyyvoc [ 15 ] = rtB . hahanrb1fp [
18 ] ; rtB . b13mdyyvoc [ 16 ] = rtB . hahanrb1fp [ 19 ] ; rtB . b13mdyyvoc [
17 ] = rtB . hahanrb1fp [ 20 ] ; for ( i = 0 ; i < 6 ; i ++ ) { rtB .
b13mdyyvoc [ i + 18 ] = rtB . edbqtdapxx [ i ] ; } for ( i = 0 ; i < 6 ; i ++
) { rtB . b13mdyyvoc [ i + 24 ] = rtB . fn50r1iv2s [ i ] ; } for ( i = 0 ; i
< 6 ; i ++ ) { rtB . b13mdyyvoc [ i + 30 ] = rtB . emwpmefl5g [ i ] ; } for (
i = 0 ; i < 6 ; i ++ ) { rtB . b13mdyyvoc [ i + 36 ] = rtB . jqhg2efiao [ i ]
; } for ( i = 0 ; i < 6 ; i ++ ) { rtB . b13mdyyvoc [ i + 42 ] = rtB .
dxffftz4xe [ i ] ; } for ( i = 0 ; i < 6 ; i ++ ) { rtB . b13mdyyvoc [ i + 48
] = rtB . jcjoil1xwx [ i ] ; } for ( i = 0 ; i < 6 ; i ++ ) { rtB .
b13mdyyvoc [ i + 54 ] = rtB . gxr43wuykr [ i ] ; } for ( i = 0 ; i < 6 ; i ++
) { rtB . b13mdyyvoc [ i + 60 ] = rtB . ahbtwvlwht [ i ] ; } { double locTime
= ssGetTaskTime ( rtS , 1 ) ; if ( ssGetLogOutput ( rtS ) ) {
rt_UpdateStructLogVar ( ( StructLogVar * ) rtDW . ce1jzkjckk . LoggedData , &
locTime , & rtB . b13mdyyvoc [ 0 ] ) ; } } } ojwgfbilnb = rtB . eygknao1u4 [
0 ] * rtP . PCCStiffnessCoefficient_Value ; abxnqvdbkl = rtP .
PCCDampingCoefficient_Value * rtB . eygknao1u4 [ 1 ] ; rtB . lle3duusb5 =
ojwgfbilnb + abxnqvdbkl ; ojwgfbilnb = rtB . eygknao1u4 [ 1 ] * rtB .
eygknao1u4 [ 1 ] ; rtB . mcslv3o4nz = rtP . PCCDampingCoefficient_Value *
ojwgfbilnb ; if ( ssIsSampleHit ( rtS , 1 , 0 ) ) { rtB . ovrdoaeae5 [ 0 ] =
rtB . lle3duusb5 ; rtB . ovrdoaeae5 [ 1 ] = rtB . mcslv3o4nz ; rtB .
ovrdoaeae5 [ 2 ] = rtB . hahanrb1fp [ 9 ] ; rtB . ovrdoaeae5 [ 3 ] = rtB .
hahanrb1fp [ 10 ] ; rtB . ovrdoaeae5 [ 4 ] = rtB . hahanrb1fp [ 11 ] ; rtB .
ovrdoaeae5 [ 5 ] = rtB . hahanrb1fp [ 6 ] ; rtB . ovrdoaeae5 [ 6 ] = rtB .
hahanrb1fp [ 7 ] ; rtB . ovrdoaeae5 [ 7 ] = rtB . hahanrb1fp [ 8 ] ; { double
locTime = ssGetTaskTime ( rtS , 1 ) ; if ( ssGetLogOutput ( rtS ) ) {
rt_UpdateStructLogVar ( ( StructLogVar * ) rtDW . mmokpjpvho . LoggedData , &
locTime , & rtB . ovrdoaeae5 [ 0 ] ) ; } } } UNUSED_PARAMETER ( tid ) ; }
void MdlUpdate ( int_T tid ) { { real_T * * uBuffer = ( real_T * * ) & rtDW .
aqyccuzu4f . TUbufferPtrs [ 0 ] ; real_T * * tBuffer = ( real_T * * ) & rtDW
. aqyccuzu4f . TUbufferPtrs [ 6 ] ; real_T simTime = ssGetT ( rtS ) ; rtDW .
anmk1ei3yl . Head [ 0 ] = ( ( rtDW . anmk1ei3yl . Head [ 0 ] < ( rtDW .
anmk1ei3yl . CircularBufSize [ 0 ] - 1 ) ) ? ( rtDW . anmk1ei3yl . Head [ 0 ]
+ 1 ) : 0 ) ; if ( rtDW . anmk1ei3yl . Head [ 0 ] == rtDW . anmk1ei3yl . Tail
[ 0 ] ) { if ( ! rt_TDelayUpdateTailOrGrowBuf ( & rtDW . anmk1ei3yl .
CircularBufSize [ 0 ] , & rtDW . anmk1ei3yl . Tail [ 0 ] , & rtDW .
anmk1ei3yl . Head [ 0 ] , & rtDW . anmk1ei3yl . Last [ 0 ] , simTime - rtP .
TransportDelay_Delay , tBuffer , uBuffer , ( NULL ) , ( boolean_T ) 0 , false
, & rtDW . anmk1ei3yl . MaxNewBufSize ) ) { ssSetErrorStatus ( rtS ,
"tdelay memory allocation error" ) ; return ; } } ( * tBuffer ++ ) [ rtDW .
anmk1ei3yl . Head [ 0 ] ] = simTime ; ( * uBuffer ++ ) [ rtDW . anmk1ei3yl .
Head [ 0 ] ] = rtB . hahanrb1fp [ 15 ] ; rtDW . anmk1ei3yl . Head [ 1 ] = ( (
rtDW . anmk1ei3yl . Head [ 1 ] < ( rtDW . anmk1ei3yl . CircularBufSize [ 1 ]
- 1 ) ) ? ( rtDW . anmk1ei3yl . Head [ 1 ] + 1 ) : 0 ) ; if ( rtDW .
anmk1ei3yl . Head [ 1 ] == rtDW . anmk1ei3yl . Tail [ 1 ] ) { if ( !
rt_TDelayUpdateTailOrGrowBuf ( & rtDW . anmk1ei3yl . CircularBufSize [ 1 ] ,
& rtDW . anmk1ei3yl . Tail [ 1 ] , & rtDW . anmk1ei3yl . Head [ 1 ] , & rtDW
. anmk1ei3yl . Last [ 1 ] , simTime - rtP . TransportDelay_Delay , tBuffer ,
uBuffer , ( NULL ) , ( boolean_T ) 0 , false , & rtDW . anmk1ei3yl .
MaxNewBufSize ) ) { ssSetErrorStatus ( rtS , "tdelay memory allocation error"
) ; return ; } } ( * tBuffer ++ ) [ rtDW . anmk1ei3yl . Head [ 1 ] ] =
simTime ; ( * uBuffer ++ ) [ rtDW . anmk1ei3yl . Head [ 1 ] ] = rtB .
hahanrb1fp [ 16 ] ; rtDW . anmk1ei3yl . Head [ 2 ] = ( ( rtDW . anmk1ei3yl .
Head [ 2 ] < ( rtDW . anmk1ei3yl . CircularBufSize [ 2 ] - 1 ) ) ? ( rtDW .
anmk1ei3yl . Head [ 2 ] + 1 ) : 0 ) ; if ( rtDW . anmk1ei3yl . Head [ 2 ] ==
rtDW . anmk1ei3yl . Tail [ 2 ] ) { if ( ! rt_TDelayUpdateTailOrGrowBuf ( &
rtDW . anmk1ei3yl . CircularBufSize [ 2 ] , & rtDW . anmk1ei3yl . Tail [ 2 ]
, & rtDW . anmk1ei3yl . Head [ 2 ] , & rtDW . anmk1ei3yl . Last [ 2 ] ,
simTime - rtP . TransportDelay_Delay , tBuffer , uBuffer , ( NULL ) , (
boolean_T ) 0 , false , & rtDW . anmk1ei3yl . MaxNewBufSize ) ) {
ssSetErrorStatus ( rtS , "tdelay memory allocation error" ) ; return ; } } (
* tBuffer ++ ) [ rtDW . anmk1ei3yl . Head [ 2 ] ] = simTime ; ( * uBuffer ++
) [ rtDW . anmk1ei3yl . Head [ 2 ] ] = rtB . hahanrb1fp [ 17 ] ; rtDW .
anmk1ei3yl . Head [ 3 ] = ( ( rtDW . anmk1ei3yl . Head [ 3 ] < ( rtDW .
anmk1ei3yl . CircularBufSize [ 3 ] - 1 ) ) ? ( rtDW . anmk1ei3yl . Head [ 3 ]
+ 1 ) : 0 ) ; if ( rtDW . anmk1ei3yl . Head [ 3 ] == rtDW . anmk1ei3yl . Tail
[ 3 ] ) { if ( ! rt_TDelayUpdateTailOrGrowBuf ( & rtDW . anmk1ei3yl .
CircularBufSize [ 3 ] , & rtDW . anmk1ei3yl . Tail [ 3 ] , & rtDW .
anmk1ei3yl . Head [ 3 ] , & rtDW . anmk1ei3yl . Last [ 3 ] , simTime - rtP .
TransportDelay_Delay , tBuffer , uBuffer , ( NULL ) , ( boolean_T ) 0 , false
, & rtDW . anmk1ei3yl . MaxNewBufSize ) ) { ssSetErrorStatus ( rtS ,
"tdelay memory allocation error" ) ; return ; } } ( * tBuffer ++ ) [ rtDW .
anmk1ei3yl . Head [ 3 ] ] = simTime ; ( * uBuffer ++ ) [ rtDW . anmk1ei3yl .
Head [ 3 ] ] = rtB . hahanrb1fp [ 12 ] ; rtDW . anmk1ei3yl . Head [ 4 ] = ( (
rtDW . anmk1ei3yl . Head [ 4 ] < ( rtDW . anmk1ei3yl . CircularBufSize [ 4 ]
- 1 ) ) ? ( rtDW . anmk1ei3yl . Head [ 4 ] + 1 ) : 0 ) ; if ( rtDW .
anmk1ei3yl . Head [ 4 ] == rtDW . anmk1ei3yl . Tail [ 4 ] ) { if ( !
rt_TDelayUpdateTailOrGrowBuf ( & rtDW . anmk1ei3yl . CircularBufSize [ 4 ] ,
& rtDW . anmk1ei3yl . Tail [ 4 ] , & rtDW . anmk1ei3yl . Head [ 4 ] , & rtDW
. anmk1ei3yl . Last [ 4 ] , simTime - rtP . TransportDelay_Delay , tBuffer ,
uBuffer , ( NULL ) , ( boolean_T ) 0 , false , & rtDW . anmk1ei3yl .
MaxNewBufSize ) ) { ssSetErrorStatus ( rtS , "tdelay memory allocation error"
) ; return ; } } ( * tBuffer ++ ) [ rtDW . anmk1ei3yl . Head [ 4 ] ] =
simTime ; ( * uBuffer ++ ) [ rtDW . anmk1ei3yl . Head [ 4 ] ] = rtB .
hahanrb1fp [ 13 ] ; rtDW . anmk1ei3yl . Head [ 5 ] = ( ( rtDW . anmk1ei3yl .
Head [ 5 ] < ( rtDW . anmk1ei3yl . CircularBufSize [ 5 ] - 1 ) ) ? ( rtDW .
anmk1ei3yl . Head [ 5 ] + 1 ) : 0 ) ; if ( rtDW . anmk1ei3yl . Head [ 5 ] ==
rtDW . anmk1ei3yl . Tail [ 5 ] ) { if ( ! rt_TDelayUpdateTailOrGrowBuf ( &
rtDW . anmk1ei3yl . CircularBufSize [ 5 ] , & rtDW . anmk1ei3yl . Tail [ 5 ]
, & rtDW . anmk1ei3yl . Head [ 5 ] , & rtDW . anmk1ei3yl . Last [ 5 ] ,
simTime - rtP . TransportDelay_Delay , tBuffer , uBuffer , ( NULL ) , (
boolean_T ) 0 , false , & rtDW . anmk1ei3yl . MaxNewBufSize ) ) {
ssSetErrorStatus ( rtS , "tdelay memory allocation error" ) ; return ; } } (
* tBuffer ) [ rtDW . anmk1ei3yl . Head [ 5 ] ] = simTime ; ( * uBuffer ) [
rtDW . anmk1ei3yl . Head [ 5 ] ] = rtB . hahanrb1fp [ 14 ] ; } { real_T * *
uBuffer = ( real_T * * ) & rtDW . pj0j1eoun4 . TUbufferPtrs [ 0 ] ; real_T *
* tBuffer = ( real_T * * ) & rtDW . pj0j1eoun4 . TUbufferPtrs [ 6 ] ; real_T
simTime = ssGetT ( rtS ) ; rtDW . ke454bg2ir . Head [ 0 ] = ( ( rtDW .
ke454bg2ir . Head [ 0 ] < ( rtDW . ke454bg2ir . CircularBufSize [ 0 ] - 1 ) )
? ( rtDW . ke454bg2ir . Head [ 0 ] + 1 ) : 0 ) ; if ( rtDW . ke454bg2ir .
Head [ 0 ] == rtDW . ke454bg2ir . Tail [ 0 ] ) { if ( !
rt_TDelayUpdateTailOrGrowBuf ( & rtDW . ke454bg2ir . CircularBufSize [ 0 ] ,
& rtDW . ke454bg2ir . Tail [ 0 ] , & rtDW . ke454bg2ir . Head [ 0 ] , & rtDW
. ke454bg2ir . Last [ 0 ] , simTime - rtP . TransportDelay_Delay_idbp52hm4z ,
tBuffer , uBuffer , ( NULL ) , ( boolean_T ) 0 , false , & rtDW . ke454bg2ir
. MaxNewBufSize ) ) { ssSetErrorStatus ( rtS ,
"tdelay memory allocation error" ) ; return ; } } ( * tBuffer ++ ) [ rtDW .
ke454bg2ir . Head [ 0 ] ] = simTime ; ( * uBuffer ++ ) [ rtDW . ke454bg2ir .
Head [ 0 ] ] = rtB . hahanrb1fp [ 21 ] ; rtDW . ke454bg2ir . Head [ 1 ] = ( (
rtDW . ke454bg2ir . Head [ 1 ] < ( rtDW . ke454bg2ir . CircularBufSize [ 1 ]
- 1 ) ) ? ( rtDW . ke454bg2ir . Head [ 1 ] + 1 ) : 0 ) ; if ( rtDW .
ke454bg2ir . Head [ 1 ] == rtDW . ke454bg2ir . Tail [ 1 ] ) { if ( !
rt_TDelayUpdateTailOrGrowBuf ( & rtDW . ke454bg2ir . CircularBufSize [ 1 ] ,
& rtDW . ke454bg2ir . Tail [ 1 ] , & rtDW . ke454bg2ir . Head [ 1 ] , & rtDW
. ke454bg2ir . Last [ 1 ] , simTime - rtP . TransportDelay_Delay_idbp52hm4z ,
tBuffer , uBuffer , ( NULL ) , ( boolean_T ) 0 , false , & rtDW . ke454bg2ir
. MaxNewBufSize ) ) { ssSetErrorStatus ( rtS ,
"tdelay memory allocation error" ) ; return ; } } ( * tBuffer ++ ) [ rtDW .
ke454bg2ir . Head [ 1 ] ] = simTime ; ( * uBuffer ++ ) [ rtDW . ke454bg2ir .
Head [ 1 ] ] = rtB . hahanrb1fp [ 22 ] ; rtDW . ke454bg2ir . Head [ 2 ] = ( (
rtDW . ke454bg2ir . Head [ 2 ] < ( rtDW . ke454bg2ir . CircularBufSize [ 2 ]
- 1 ) ) ? ( rtDW . ke454bg2ir . Head [ 2 ] + 1 ) : 0 ) ; if ( rtDW .
ke454bg2ir . Head [ 2 ] == rtDW . ke454bg2ir . Tail [ 2 ] ) { if ( !
rt_TDelayUpdateTailOrGrowBuf ( & rtDW . ke454bg2ir . CircularBufSize [ 2 ] ,
& rtDW . ke454bg2ir . Tail [ 2 ] , & rtDW . ke454bg2ir . Head [ 2 ] , & rtDW
. ke454bg2ir . Last [ 2 ] , simTime - rtP . TransportDelay_Delay_idbp52hm4z ,
tBuffer , uBuffer , ( NULL ) , ( boolean_T ) 0 , false , & rtDW . ke454bg2ir
. MaxNewBufSize ) ) { ssSetErrorStatus ( rtS ,
"tdelay memory allocation error" ) ; return ; } } ( * tBuffer ++ ) [ rtDW .
ke454bg2ir . Head [ 2 ] ] = simTime ; ( * uBuffer ++ ) [ rtDW . ke454bg2ir .
Head [ 2 ] ] = rtB . hahanrb1fp [ 23 ] ; rtDW . ke454bg2ir . Head [ 3 ] = ( (
rtDW . ke454bg2ir . Head [ 3 ] < ( rtDW . ke454bg2ir . CircularBufSize [ 3 ]
- 1 ) ) ? ( rtDW . ke454bg2ir . Head [ 3 ] + 1 ) : 0 ) ; if ( rtDW .
ke454bg2ir . Head [ 3 ] == rtDW . ke454bg2ir . Tail [ 3 ] ) { if ( !
rt_TDelayUpdateTailOrGrowBuf ( & rtDW . ke454bg2ir . CircularBufSize [ 3 ] ,
& rtDW . ke454bg2ir . Tail [ 3 ] , & rtDW . ke454bg2ir . Head [ 3 ] , & rtDW
. ke454bg2ir . Last [ 3 ] , simTime - rtP . TransportDelay_Delay_idbp52hm4z ,
tBuffer , uBuffer , ( NULL ) , ( boolean_T ) 0 , false , & rtDW . ke454bg2ir
. MaxNewBufSize ) ) { ssSetErrorStatus ( rtS ,
"tdelay memory allocation error" ) ; return ; } } ( * tBuffer ++ ) [ rtDW .
ke454bg2ir . Head [ 3 ] ] = simTime ; ( * uBuffer ++ ) [ rtDW . ke454bg2ir .
Head [ 3 ] ] = rtB . hahanrb1fp [ 18 ] ; rtDW . ke454bg2ir . Head [ 4 ] = ( (
rtDW . ke454bg2ir . Head [ 4 ] < ( rtDW . ke454bg2ir . CircularBufSize [ 4 ]
- 1 ) ) ? ( rtDW . ke454bg2ir . Head [ 4 ] + 1 ) : 0 ) ; if ( rtDW .
ke454bg2ir . Head [ 4 ] == rtDW . ke454bg2ir . Tail [ 4 ] ) { if ( !
rt_TDelayUpdateTailOrGrowBuf ( & rtDW . ke454bg2ir . CircularBufSize [ 4 ] ,
& rtDW . ke454bg2ir . Tail [ 4 ] , & rtDW . ke454bg2ir . Head [ 4 ] , & rtDW
. ke454bg2ir . Last [ 4 ] , simTime - rtP . TransportDelay_Delay_idbp52hm4z ,
tBuffer , uBuffer , ( NULL ) , ( boolean_T ) 0 , false , & rtDW . ke454bg2ir
. MaxNewBufSize ) ) { ssSetErrorStatus ( rtS ,
"tdelay memory allocation error" ) ; return ; } } ( * tBuffer ++ ) [ rtDW .
ke454bg2ir . Head [ 4 ] ] = simTime ; ( * uBuffer ++ ) [ rtDW . ke454bg2ir .
Head [ 4 ] ] = rtB . hahanrb1fp [ 19 ] ; rtDW . ke454bg2ir . Head [ 5 ] = ( (
rtDW . ke454bg2ir . Head [ 5 ] < ( rtDW . ke454bg2ir . CircularBufSize [ 5 ]
- 1 ) ) ? ( rtDW . ke454bg2ir . Head [ 5 ] + 1 ) : 0 ) ; if ( rtDW .
ke454bg2ir . Head [ 5 ] == rtDW . ke454bg2ir . Tail [ 5 ] ) { if ( !
rt_TDelayUpdateTailOrGrowBuf ( & rtDW . ke454bg2ir . CircularBufSize [ 5 ] ,
& rtDW . ke454bg2ir . Tail [ 5 ] , & rtDW . ke454bg2ir . Head [ 5 ] , & rtDW
. ke454bg2ir . Last [ 5 ] , simTime - rtP . TransportDelay_Delay_idbp52hm4z ,
tBuffer , uBuffer , ( NULL ) , ( boolean_T ) 0 , false , & rtDW . ke454bg2ir
. MaxNewBufSize ) ) { ssSetErrorStatus ( rtS ,
"tdelay memory allocation error" ) ; return ; } } ( * tBuffer ) [ rtDW .
ke454bg2ir . Head [ 5 ] ] = simTime ; ( * uBuffer ) [ rtDW . ke454bg2ir .
Head [ 5 ] ] = rtB . hahanrb1fp [ 20 ] ; } UNUSED_PARAMETER ( tid ) ; } void
MdlDerivatives ( void ) { NeslSimulationData * simulationData ; real_T time ;
boolean_T tmp ; real_T tmp_p [ 48 ] ; int_T tmp_e [ 13 ] ;
NeuDiagnosticManager * diagnosticManager ; NeuDiagnosticTree * diagnosticTree
; int32_T tmp_i ; char * msg ; XDot * _rtXdot ; _rtXdot = ( ( XDot * )
ssGetdX ( rtS ) ) ; simulationData = ( NeslSimulationData * ) rtDW .
dhyxq0jnh5 ; time = ssGetT ( rtS ) ; simulationData -> mData -> mTime . mN =
1 ; simulationData -> mData -> mTime . mX = & time ; simulationData -> mData
-> mContStates . mN = 4 ; simulationData -> mData -> mContStates . mX = (
real_T * ) & rtX . kxjirxqmhs ; simulationData -> mData -> mDiscStates . mN =
0 ; simulationData -> mData -> mDiscStates . mX = NULL ; simulationData ->
mData -> mModeVector . mN = 0 ; simulationData -> mData -> mModeVector . mX =
NULL ; tmp = false ; simulationData -> mData -> mFoundZcEvents = tmp ;
simulationData -> mData -> mIsMajorTimeStep = ssIsMajorTimeStep ( rtS ) ; tmp
= ( ssGetMdlInfoPtr ( rtS ) -> mdlFlags . solverAssertCheck == 1U ) ;
simulationData -> mData -> mIsSolverAssertCheck = tmp ; simulationData ->
mData -> mIsSolverCheckingCIC = false ; tmp = ssIsSolverComputingJacobian (
rtS ) ; simulationData -> mData -> mIsComputingJacobian = tmp ;
simulationData -> mData -> mIsSolverRequestingReset = false ; tmp_e [ 0 ] = 0
; tmp_p [ 0 ] = rtB . biiiks5bdq [ 0 ] ; tmp_p [ 1 ] = rtB . biiiks5bdq [ 1 ]
; tmp_p [ 2 ] = rtB . biiiks5bdq [ 2 ] ; tmp_p [ 3 ] = rtB . biiiks5bdq [ 3 ]
; tmp_e [ 1 ] = 4 ; tmp_p [ 4 ] = rtB . bweohccgoh [ 0 ] ; tmp_p [ 5 ] = rtB
. bweohccgoh [ 1 ] ; tmp_p [ 6 ] = rtB . bweohccgoh [ 2 ] ; tmp_p [ 7 ] = rtB
. bweohccgoh [ 3 ] ; tmp_e [ 2 ] = 8 ; tmp_p [ 8 ] = rtB . eyb1czk053 [ 0 ] ;
tmp_p [ 9 ] = rtB . eyb1czk053 [ 1 ] ; tmp_p [ 10 ] = rtB . eyb1czk053 [ 2 ]
; tmp_p [ 11 ] = rtB . eyb1czk053 [ 3 ] ; tmp_e [ 3 ] = 12 ; tmp_p [ 12 ] =
rtB . hoyspdnpx3 [ 0 ] ; tmp_p [ 13 ] = rtB . hoyspdnpx3 [ 1 ] ; tmp_p [ 14 ]
= rtB . hoyspdnpx3 [ 2 ] ; tmp_p [ 15 ] = rtB . hoyspdnpx3 [ 3 ] ; tmp_e [ 4
] = 16 ; tmp_p [ 16 ] = rtB . kia00mwvqk [ 0 ] ; tmp_p [ 17 ] = rtB .
kia00mwvqk [ 1 ] ; tmp_p [ 18 ] = rtB . kia00mwvqk [ 2 ] ; tmp_p [ 19 ] = rtB
. kia00mwvqk [ 3 ] ; tmp_e [ 5 ] = 20 ; tmp_p [ 20 ] = rtB . jr2ghgakgm [ 0 ]
; tmp_p [ 21 ] = rtB . jr2ghgakgm [ 1 ] ; tmp_p [ 22 ] = rtB . jr2ghgakgm [ 2
] ; tmp_p [ 23 ] = rtB . jr2ghgakgm [ 3 ] ; tmp_e [ 6 ] = 24 ; tmp_p [ 24 ] =
rtB . mionfsauuc [ 0 ] ; tmp_p [ 25 ] = rtB . mionfsauuc [ 1 ] ; tmp_p [ 26 ]
= rtB . mionfsauuc [ 2 ] ; tmp_p [ 27 ] = rtB . mionfsauuc [ 3 ] ; tmp_e [ 7
] = 28 ; tmp_p [ 28 ] = rtB . lkkej41yzf [ 0 ] ; tmp_p [ 29 ] = rtB .
lkkej41yzf [ 1 ] ; tmp_p [ 30 ] = rtB . lkkej41yzf [ 2 ] ; tmp_p [ 31 ] = rtB
. lkkej41yzf [ 3 ] ; tmp_e [ 8 ] = 32 ; tmp_p [ 32 ] = rtB . k02keb4tly [ 0 ]
; tmp_p [ 33 ] = rtB . k02keb4tly [ 1 ] ; tmp_p [ 34 ] = rtB . k02keb4tly [ 2
] ; tmp_p [ 35 ] = rtB . k02keb4tly [ 3 ] ; tmp_e [ 9 ] = 36 ; tmp_p [ 36 ] =
rtB . hoc2fuxv0g [ 0 ] ; tmp_p [ 37 ] = rtB . hoc2fuxv0g [ 1 ] ; tmp_p [ 38 ]
= rtB . hoc2fuxv0g [ 2 ] ; tmp_p [ 39 ] = rtB . hoc2fuxv0g [ 3 ] ; tmp_e [ 10
] = 40 ; tmp_p [ 40 ] = rtB . gbda5p2r2f [ 0 ] ; tmp_p [ 41 ] = rtB .
gbda5p2r2f [ 1 ] ; tmp_p [ 42 ] = rtB . gbda5p2r2f [ 2 ] ; tmp_p [ 43 ] = rtB
. gbda5p2r2f [ 3 ] ; tmp_e [ 11 ] = 44 ; tmp_p [ 44 ] = rtB . j1dwgbinuj [ 0
] ; tmp_p [ 45 ] = rtB . j1dwgbinuj [ 1 ] ; tmp_p [ 46 ] = rtB . j1dwgbinuj [
2 ] ; tmp_p [ 47 ] = rtB . j1dwgbinuj [ 3 ] ; tmp_e [ 12 ] = 48 ;
simulationData -> mData -> mInputValues . mN = 48 ; simulationData -> mData
-> mInputValues . mX = & tmp_p [ 0 ] ; simulationData -> mData ->
mInputOffsets . mN = 13 ; simulationData -> mData -> mInputOffsets . mX = &
tmp_e [ 0 ] ; simulationData -> mData -> mDx . mN = 4 ; simulationData ->
mData -> mDx . mX = ( real_T * ) & _rtXdot -> kxjirxqmhs ; diagnosticManager
= ( NeuDiagnosticManager * ) rtDW . f4urr54u23 ; diagnosticTree =
neu_diagnostic_manager_get_initial_tree ( diagnosticManager ) ; tmp_i =
ne_simulator_method ( ( NeslSimulator * ) rtDW . lm3sijg1j1 ,
NESL_SIM_DERIVATIVES , simulationData , diagnosticManager ) ; if ( tmp_i != 0
) { tmp = error_buffer_is_empty ( ssGetErrorStatus ( rtS ) ) ; if ( tmp ) {
msg = rtw_diagnostics_msg ( diagnosticTree ) ; ssSetErrorStatus ( rtS , msg )
; } } } void MdlProjection ( void ) { NeslSimulationData * simulationData ;
real_T time ; boolean_T tmp ; real_T tmp_p [ 48 ] ; int_T tmp_e [ 13 ] ;
NeuDiagnosticManager * diagnosticManager ; NeuDiagnosticTree * diagnosticTree
; int32_T tmp_i ; char * msg ; simulationData = ( NeslSimulationData * ) rtDW
. dhyxq0jnh5 ; time = ssGetT ( rtS ) ; simulationData -> mData -> mTime . mN
= 1 ; simulationData -> mData -> mTime . mX = & time ; simulationData ->
mData -> mContStates . mN = 4 ; simulationData -> mData -> mContStates . mX =
( real_T * ) & rtX . kxjirxqmhs ; simulationData -> mData -> mDiscStates . mN
= 0 ; simulationData -> mData -> mDiscStates . mX = NULL ; simulationData ->
mData -> mModeVector . mN = 0 ; simulationData -> mData -> mModeVector . mX =
NULL ; tmp = false ; simulationData -> mData -> mFoundZcEvents = tmp ;
simulationData -> mData -> mIsMajorTimeStep = ssIsMajorTimeStep ( rtS ) ; tmp
= ( ssGetMdlInfoPtr ( rtS ) -> mdlFlags . solverAssertCheck == 1U ) ;
simulationData -> mData -> mIsSolverAssertCheck = tmp ; simulationData ->
mData -> mIsSolverCheckingCIC = false ; tmp = ssIsSolverComputingJacobian (
rtS ) ; simulationData -> mData -> mIsComputingJacobian = tmp ;
simulationData -> mData -> mIsSolverRequestingReset = false ; tmp_e [ 0 ] = 0
; tmp_p [ 0 ] = rtB . biiiks5bdq [ 0 ] ; tmp_p [ 1 ] = rtB . biiiks5bdq [ 1 ]
; tmp_p [ 2 ] = rtB . biiiks5bdq [ 2 ] ; tmp_p [ 3 ] = rtB . biiiks5bdq [ 3 ]
; tmp_e [ 1 ] = 4 ; tmp_p [ 4 ] = rtB . bweohccgoh [ 0 ] ; tmp_p [ 5 ] = rtB
. bweohccgoh [ 1 ] ; tmp_p [ 6 ] = rtB . bweohccgoh [ 2 ] ; tmp_p [ 7 ] = rtB
. bweohccgoh [ 3 ] ; tmp_e [ 2 ] = 8 ; tmp_p [ 8 ] = rtB . eyb1czk053 [ 0 ] ;
tmp_p [ 9 ] = rtB . eyb1czk053 [ 1 ] ; tmp_p [ 10 ] = rtB . eyb1czk053 [ 2 ]
; tmp_p [ 11 ] = rtB . eyb1czk053 [ 3 ] ; tmp_e [ 3 ] = 12 ; tmp_p [ 12 ] =
rtB . hoyspdnpx3 [ 0 ] ; tmp_p [ 13 ] = rtB . hoyspdnpx3 [ 1 ] ; tmp_p [ 14 ]
= rtB . hoyspdnpx3 [ 2 ] ; tmp_p [ 15 ] = rtB . hoyspdnpx3 [ 3 ] ; tmp_e [ 4
] = 16 ; tmp_p [ 16 ] = rtB . kia00mwvqk [ 0 ] ; tmp_p [ 17 ] = rtB .
kia00mwvqk [ 1 ] ; tmp_p [ 18 ] = rtB . kia00mwvqk [ 2 ] ; tmp_p [ 19 ] = rtB
. kia00mwvqk [ 3 ] ; tmp_e [ 5 ] = 20 ; tmp_p [ 20 ] = rtB . jr2ghgakgm [ 0 ]
; tmp_p [ 21 ] = rtB . jr2ghgakgm [ 1 ] ; tmp_p [ 22 ] = rtB . jr2ghgakgm [ 2
] ; tmp_p [ 23 ] = rtB . jr2ghgakgm [ 3 ] ; tmp_e [ 6 ] = 24 ; tmp_p [ 24 ] =
rtB . mionfsauuc [ 0 ] ; tmp_p [ 25 ] = rtB . mionfsauuc [ 1 ] ; tmp_p [ 26 ]
= rtB . mionfsauuc [ 2 ] ; tmp_p [ 27 ] = rtB . mionfsauuc [ 3 ] ; tmp_e [ 7
] = 28 ; tmp_p [ 28 ] = rtB . lkkej41yzf [ 0 ] ; tmp_p [ 29 ] = rtB .
lkkej41yzf [ 1 ] ; tmp_p [ 30 ] = rtB . lkkej41yzf [ 2 ] ; tmp_p [ 31 ] = rtB
. lkkej41yzf [ 3 ] ; tmp_e [ 8 ] = 32 ; tmp_p [ 32 ] = rtB . k02keb4tly [ 0 ]
; tmp_p [ 33 ] = rtB . k02keb4tly [ 1 ] ; tmp_p [ 34 ] = rtB . k02keb4tly [ 2
] ; tmp_p [ 35 ] = rtB . k02keb4tly [ 3 ] ; tmp_e [ 9 ] = 36 ; tmp_p [ 36 ] =
rtB . hoc2fuxv0g [ 0 ] ; tmp_p [ 37 ] = rtB . hoc2fuxv0g [ 1 ] ; tmp_p [ 38 ]
= rtB . hoc2fuxv0g [ 2 ] ; tmp_p [ 39 ] = rtB . hoc2fuxv0g [ 3 ] ; tmp_e [ 10
] = 40 ; tmp_p [ 40 ] = rtB . gbda5p2r2f [ 0 ] ; tmp_p [ 41 ] = rtB .
gbda5p2r2f [ 1 ] ; tmp_p [ 42 ] = rtB . gbda5p2r2f [ 2 ] ; tmp_p [ 43 ] = rtB
. gbda5p2r2f [ 3 ] ; tmp_e [ 11 ] = 44 ; tmp_p [ 44 ] = rtB . j1dwgbinuj [ 0
] ; tmp_p [ 45 ] = rtB . j1dwgbinuj [ 1 ] ; tmp_p [ 46 ] = rtB . j1dwgbinuj [
2 ] ; tmp_p [ 47 ] = rtB . j1dwgbinuj [ 3 ] ; tmp_e [ 12 ] = 48 ;
simulationData -> mData -> mInputValues . mN = 48 ; simulationData -> mData
-> mInputValues . mX = & tmp_p [ 0 ] ; simulationData -> mData ->
mInputOffsets . mN = 13 ; simulationData -> mData -> mInputOffsets . mX = &
tmp_e [ 0 ] ; diagnosticManager = ( NeuDiagnosticManager * ) rtDW .
f4urr54u23 ; diagnosticTree = neu_diagnostic_manager_get_initial_tree (
diagnosticManager ) ; tmp_i = ne_simulator_method ( ( NeslSimulator * ) rtDW
. lm3sijg1j1 , NESL_SIM_PROJECTION , simulationData , diagnosticManager ) ;
if ( tmp_i != 0 ) { tmp = error_buffer_is_empty ( ssGetErrorStatus ( rtS ) )
; if ( tmp ) { msg = rtw_diagnostics_msg ( diagnosticTree ) ;
ssSetErrorStatus ( rtS , msg ) ; } } } void MdlTerminate ( void ) {
neu_destroy_diagnostic_manager ( ( NeuDiagnosticManager * ) rtDW . f4urr54u23
) ; nesl_destroy_simulation_data ( ( NeslSimulationData * ) rtDW . dhyxq0jnh5
) ; nesl_erase_simulator ( "RM3/Global Reference Frame/Solver Configuration"
) ; neu_destroy_diagnostic_manager ( ( NeuDiagnosticManager * ) rtDW .
kieznzt55p ) ; nesl_destroy_simulation_data ( ( NeslSimulationData * ) rtDW .
njkjfcqdc3 ) ; nesl_erase_simulator (
"RM3/Global Reference Frame/Solver Configuration" ) ; { int_T i1 ; void * *
pw_TUbufferPtrs = & rtDW . aqyccuzu4f . TUbufferPtrs [ 0 ] ; for ( i1 = 0 ;
i1 < 3 ; i1 ++ ) { rt_TDelayFreeBuf ( pw_TUbufferPtrs [ i1 ] ) ; }
pw_TUbufferPtrs = & rtDW . aqyccuzu4f . TUbufferPtrs [ 3 ] ; for ( i1 = 0 ;
i1 < 3 ; i1 ++ ) { rt_TDelayFreeBuf ( pw_TUbufferPtrs [ i1 ] ) ; } } { int_T
i1 ; void * * pw_TUbufferPtrs = & rtDW . pj0j1eoun4 . TUbufferPtrs [ 0 ] ;
for ( i1 = 0 ; i1 < 3 ; i1 ++ ) { rt_TDelayFreeBuf ( pw_TUbufferPtrs [ i1 ] )
; } pw_TUbufferPtrs = & rtDW . pj0j1eoun4 . TUbufferPtrs [ 3 ] ; for ( i1 = 0
; i1 < 3 ; i1 ++ ) { rt_TDelayFreeBuf ( pw_TUbufferPtrs [ i1 ] ) ; } }
neu_destroy_diagnostic_manager ( ( NeuDiagnosticManager * ) rtDW . hafmpp5qwx
) ; nesl_destroy_simulation_data ( ( NeslSimulationData * ) rtDW . hjs5z0ka4j
) ; nesl_erase_simulator ( "RM3/Global Reference Frame/Solver Configuration"
) ; } void MdlInitializeSizes ( void ) { ssSetNumContStates ( rtS , 4 ) ;
ssSetNumY ( rtS , 0 ) ; ssSetNumU ( rtS , 0 ) ; ssSetDirectFeedThrough ( rtS
, 0 ) ; ssSetNumSampleTimes ( rtS , 2 ) ; ssSetNumBlocks ( rtS , 253 ) ;
ssSetNumBlockIO ( rtS , 44 ) ; ssSetNumBlockParams ( rtS , 73846 ) ; } void
MdlInitializeSampleTimes ( void ) { ssSetSampleTime ( rtS , 0 , 0.0 ) ;
ssSetSampleTime ( rtS , 1 , 0.1 ) ; ssSetOffsetTime ( rtS , 0 , 0.0 ) ;
ssSetOffsetTime ( rtS , 1 , 0.0 ) ; } void raccel_set_checksum ( SimStruct *
rtS ) { ssSetChecksumVal ( rtS , 0 , 1252914586U ) ; ssSetChecksumVal ( rtS ,
1 , 3362424525U ) ; ssSetChecksumVal ( rtS , 2 , 2296161348U ) ;
ssSetChecksumVal ( rtS , 3 , 934207540U ) ; } SimStruct *
raccel_register_model ( void ) { static struct _ssMdlInfo mdlInfo ; ( void )
memset ( ( char * ) rtS , 0 , sizeof ( SimStruct ) ) ; ( void ) memset ( (
char * ) & mdlInfo , 0 , sizeof ( struct _ssMdlInfo ) ) ; ssSetMdlInfoPtr (
rtS , & mdlInfo ) ; { static time_T mdlPeriod [ NSAMPLE_TIMES ] ; static
time_T mdlOffset [ NSAMPLE_TIMES ] ; static time_T mdlTaskTimes [
NSAMPLE_TIMES ] ; static int_T mdlTsMap [ NSAMPLE_TIMES ] ; static int_T
mdlSampleHits [ NSAMPLE_TIMES ] ; static boolean_T mdlTNextWasAdjustedPtr [
NSAMPLE_TIMES ] ; static int_T mdlPerTaskSampleHits [ NSAMPLE_TIMES *
NSAMPLE_TIMES ] ; static time_T mdlTimeOfNextSampleHit [ NSAMPLE_TIMES ] ; {
int_T i ; for ( i = 0 ; i < NSAMPLE_TIMES ; i ++ ) { mdlPeriod [ i ] = 0.0 ;
mdlOffset [ i ] = 0.0 ; mdlTaskTimes [ i ] = 0.0 ; mdlTsMap [ i ] = i ;
mdlSampleHits [ i ] = 1 ; } } ssSetSampleTimePtr ( rtS , & mdlPeriod [ 0 ] )
; ssSetOffsetTimePtr ( rtS , & mdlOffset [ 0 ] ) ; ssSetSampleTimeTaskIDPtr (
rtS , & mdlTsMap [ 0 ] ) ; ssSetTPtr ( rtS , & mdlTaskTimes [ 0 ] ) ;
ssSetSampleHitPtr ( rtS , & mdlSampleHits [ 0 ] ) ; ssSetTNextWasAdjustedPtr
( rtS , & mdlTNextWasAdjustedPtr [ 0 ] ) ; ssSetPerTaskSampleHitsPtr ( rtS ,
& mdlPerTaskSampleHits [ 0 ] ) ; ssSetTimeOfNextSampleHitPtr ( rtS , &
mdlTimeOfNextSampleHit [ 0 ] ) ; } ssSetSolverMode ( rtS ,
SOLVER_MODE_SINGLETASKING ) ; { ssSetBlockIO ( rtS , ( ( void * ) & rtB ) ) ;
( void ) memset ( ( ( void * ) & rtB ) , 0 , sizeof ( B ) ) ; }
ssSetDefaultParam ( rtS , ( real_T * ) & rtP ) ; { real_T * x = ( real_T * )
& rtX ; ssSetContStates ( rtS , x ) ; ( void ) memset ( ( void * ) x , 0 ,
sizeof ( X ) ) ; } { void * dwork = ( void * ) & rtDW ; ssSetRootDWork ( rtS
, dwork ) ; ( void ) memset ( dwork , 0 , sizeof ( DW ) ) ; } { static
DataTypeTransInfo dtInfo ; ( void ) memset ( ( char_T * ) & dtInfo , 0 ,
sizeof ( dtInfo ) ) ; ssSetModelMappingInfo ( rtS , & dtInfo ) ; dtInfo .
numDataTypes = 14 ; dtInfo . dataTypeSizes = & rtDataTypeSizes [ 0 ] ; dtInfo
. dataTypeNames = & rtDataTypeNames [ 0 ] ; dtInfo . B = & rtBTransTable ;
dtInfo . P = & rtPTransTable ; } RM3_InitializeDataMapInfo ( rtS ) ;
ssSetIsRapidAcceleratorActive ( rtS , true ) ; ssSetRootSS ( rtS , rtS ) ;
ssSetVersion ( rtS , SIMSTRUCT_VERSION_LEVEL2 ) ; ssSetModelName ( rtS ,
"RM3" ) ; ssSetPath ( rtS , "RM3" ) ; ssSetTStart ( rtS , 0.0 ) ; ssSetTFinal
( rtS , 400.0 ) ; ssSetStepSize ( rtS , 0.1 ) ; ssSetFixedStepSize ( rtS ,
0.1 ) ; { static RTWLogInfo rt_DataLoggingInfo ; ssSetRTWLogInfo ( rtS , &
rt_DataLoggingInfo ) ; } { { static int_T rt_LoggedStateWidths [ ] = { 1 , 1
, 1 , 1 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 } ; static int_T
rt_LoggedStateNumDimensions [ ] = { 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1
, 1 , 1 , 1 , 1 , 1 } ; static int_T rt_LoggedStateDimensions [ ] = { 1 , 1 ,
1 , 1 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 } ; static boolean_T
rt_LoggedStateIsVarDims [ ] = { 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0
, 0 , 0 , 0 , 0 } ; static BuiltInDTypeId rt_LoggedStateDataTypeIds [ ] = {
SS_DOUBLE , SS_DOUBLE , SS_DOUBLE , SS_DOUBLE , SS_DOUBLE , SS_DOUBLE ,
SS_DOUBLE , SS_DOUBLE , SS_DOUBLE , SS_DOUBLE , SS_DOUBLE , SS_DOUBLE ,
SS_DOUBLE , SS_DOUBLE , SS_DOUBLE , SS_DOUBLE } ; static int_T
rt_LoggedStateComplexSignals [ ] = { 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 ,
0 , 0 , 0 , 0 , 0 , 0 } ; static const char_T * rt_LoggedStateLabels [ ] = {
"CSTATE" , "CSTATE" , "CSTATE" , "CSTATE" , "discrete" , "discrete" ,
"discrete" , "discrete" , "discrete" , "discrete" , "discrete" , "discrete" ,
"discrete" , "discrete" , "discrete" , "discrete" } ; static const char_T *
rt_LoggedStateBlockNames [ ] = {
"RM3/Heave/Translational Constraint (Prismatic Joint)" ,
"RM3/Heave/Translational Constraint (Prismatic Joint)" ,
"RM3/Translational PTO  (Local Z)/Translational PCC (Prismatic Joint)" ,
"RM3/Translational PTO  (Local Z)/Translational PCC (Prismatic Joint)" ,
"RM3/Global Reference Frame/Solver\nConfiguration/EVAL_KEY/INPUT_1_1_1" ,
"RM3/Global Reference Frame/Solver\nConfiguration/EVAL_KEY/INPUT_1_1_2" ,
"RM3/Global Reference Frame/Solver\nConfiguration/EVAL_KEY/INPUT_1_1_3" ,
"RM3/Global Reference Frame/Solver\nConfiguration/EVAL_KEY/INPUT_2_1_1" ,
"RM3/Global Reference Frame/Solver\nConfiguration/EVAL_KEY/INPUT_2_1_2" ,
"RM3/Global Reference Frame/Solver\nConfiguration/EVAL_KEY/INPUT_2_1_3" ,
"RM3/Global Reference Frame/Solver\nConfiguration/EVAL_KEY/INPUT_3_1_1" ,
"RM3/Global Reference Frame/Solver\nConfiguration/EVAL_KEY/INPUT_3_1_2" ,
"RM3/Global Reference Frame/Solver\nConfiguration/EVAL_KEY/INPUT_3_1_3" ,
"RM3/Global Reference Frame/Solver\nConfiguration/EVAL_KEY/INPUT_4_1_1" ,
"RM3/Global Reference Frame/Solver\nConfiguration/EVAL_KEY/INPUT_4_1_2" ,
"RM3/Global Reference Frame/Solver\nConfiguration/EVAL_KEY/INPUT_4_1_3" } ;
static const char_T * rt_LoggedStateNames [ ] = {
"Heave.Translational_Constraint_Prismatic_Joint.Pz.p" ,
"Heave.Translational_Constraint_Prismatic_Joint.Pz.v" ,
"Translational_PTO_Local_Z.Translational_PCC_Prismatic_Joint.Pz.p" ,
"Translational_PTO_Local_Z.Translational_PCC_Prismatic_Joint.Pz.v" , "" , ""
, "" , "" , "" , "" , "" , "" , "" , "" , "" , "" } ; static boolean_T
rt_LoggedStateCrossMdlRef [ ] = { 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 ,
0 , 0 , 0 , 0 , 0 } ; static RTWLogDataTypeConvert rt_RTWLogDataTypeConvert [
] = { { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 ,
SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE ,
SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0
, 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 ,
0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 ,
SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE ,
SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0
, 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 ,
0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 ,
SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE ,
SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0
, 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 ,
0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } } ; static
RTWLogSignalInfo rt_LoggedStateSignalInfo = { 16 , rt_LoggedStateWidths ,
rt_LoggedStateNumDimensions , rt_LoggedStateDimensions ,
rt_LoggedStateIsVarDims , ( NULL ) , ( NULL ) , rt_LoggedStateDataTypeIds ,
rt_LoggedStateComplexSignals , ( NULL ) , { rt_LoggedStateLabels } , ( NULL )
, ( NULL ) , ( NULL ) , { rt_LoggedStateBlockNames } , { rt_LoggedStateNames
} , rt_LoggedStateCrossMdlRef , rt_RTWLogDataTypeConvert } ; static void *
rt_LoggedStateSignalPtrs [ 16 ] ; rtliSetLogXSignalPtrs ( ssGetRTWLogInfo (
rtS ) , ( LogSignalPtrsType ) rt_LoggedStateSignalPtrs ) ;
rtliSetLogXSignalInfo ( ssGetRTWLogInfo ( rtS ) , & rt_LoggedStateSignalInfo
) ; rt_LoggedStateSignalPtrs [ 0 ] = ( void * ) & rtX . kxjirxqmhs [ 0 ] ;
rt_LoggedStateSignalPtrs [ 1 ] = ( void * ) & rtX . kxjirxqmhs [ 1 ] ;
rt_LoggedStateSignalPtrs [ 2 ] = ( void * ) & rtX . kxjirxqmhs [ 2 ] ;
rt_LoggedStateSignalPtrs [ 3 ] = ( void * ) & rtX . kxjirxqmhs [ 3 ] ;
rt_LoggedStateSignalPtrs [ 4 ] = ( void * ) rtDW . jhsjwq4b1m ;
rt_LoggedStateSignalPtrs [ 5 ] = ( void * ) rtDW . hvjbqhm5oo ;
rt_LoggedStateSignalPtrs [ 6 ] = ( void * ) rtDW . df3rh4z0gd ;
rt_LoggedStateSignalPtrs [ 7 ] = ( void * ) rtDW . owzp013kx2 ;
rt_LoggedStateSignalPtrs [ 8 ] = ( void * ) rtDW . m3h1jcujy4 ;
rt_LoggedStateSignalPtrs [ 9 ] = ( void * ) rtDW . hts5jxxzji ;
rt_LoggedStateSignalPtrs [ 10 ] = ( void * ) rtDW . md4q5iksqt ;
rt_LoggedStateSignalPtrs [ 11 ] = ( void * ) rtDW . mbkovhbhoz ;
rt_LoggedStateSignalPtrs [ 12 ] = ( void * ) rtDW . mfpmp4gwws ;
rt_LoggedStateSignalPtrs [ 13 ] = ( void * ) rtDW . nzqg25m1lg ;
rt_LoggedStateSignalPtrs [ 14 ] = ( void * ) rtDW . l1g0f5hnak ;
rt_LoggedStateSignalPtrs [ 15 ] = ( void * ) rtDW . oqwcwkuk03 ; }
rtliSetLogT ( ssGetRTWLogInfo ( rtS ) , "tout" ) ; rtliSetLogX (
ssGetRTWLogInfo ( rtS ) , "tmp_raccel_xout" ) ; rtliSetLogXFinal (
ssGetRTWLogInfo ( rtS ) , "xFinal" ) ; rtliSetLogVarNameModifier (
ssGetRTWLogInfo ( rtS ) , "none" ) ; rtliSetLogFormat ( ssGetRTWLogInfo ( rtS
) , 2 ) ; rtliSetLogMaxRows ( ssGetRTWLogInfo ( rtS ) , 0 ) ;
rtliSetLogDecimation ( ssGetRTWLogInfo ( rtS ) , 1 ) ; rtliSetLogY (
ssGetRTWLogInfo ( rtS ) , "" ) ; rtliSetLogYSignalInfo ( ssGetRTWLogInfo (
rtS ) , ( NULL ) ) ; rtliSetLogYSignalPtrs ( ssGetRTWLogInfo ( rtS ) , ( NULL
) ) ; } { static struct _ssStatesInfo2 statesInfo2 ; ssSetStatesInfo2 ( rtS ,
& statesInfo2 ) ; } { static ssSolverInfo slvrInfo ; static struct
_ssSFcnModelMethods3 mdlMethods3 ; static struct _ssSFcnModelMethods2
mdlMethods2 ; static boolean_T contStatesDisabled [ 4 ] ; ssSetSolverInfo (
rtS , & slvrInfo ) ; ssSetSolverName ( rtS , "ode4" ) ;
ssSetVariableStepSolver ( rtS , 0 ) ; ssSetSolverConsistencyChecking ( rtS ,
0 ) ; ssSetSolverAdaptiveZcDetection ( rtS , 0 ) ;
ssSetSolverRobustResetMethod ( rtS , 0 ) ; _ssSetSolverUpdateJacobianAtReset
( rtS , true ) ; ssSetSolverStateProjection ( rtS , 1 ) ; ( void ) memset ( (
void * ) & mdlMethods2 , 0 , sizeof ( mdlMethods2 ) ) ; ssSetModelMethods2 (
rtS , & mdlMethods2 ) ; ( void ) memset ( ( void * ) & mdlMethods3 , 0 ,
sizeof ( mdlMethods3 ) ) ; ssSetModelMethods3 ( rtS , & mdlMethods3 ) ;
ssSetModelProjection ( rtS , MdlProjection ) ; ssSetSolverMassMatrixType (
rtS , ( ssMatrixType ) 0 ) ; ssSetSolverMassMatrixNzMax ( rtS , 0 ) ;
ssSetModelOutputs ( rtS , MdlOutputs ) ; ssSetModelLogData ( rtS ,
rt_UpdateTXYLogVars ) ; ssSetModelUpdate ( rtS , MdlUpdate ) ;
ssSetModelDerivatives ( rtS , MdlDerivatives ) ; ssSetTNextTid ( rtS ,
INT_MIN ) ; ssSetTNext ( rtS , rtMinusInf ) ; ssSetSolverNeedsReset ( rtS ) ;
ssSetNumNonsampledZCs ( rtS , 0 ) ; ssSetContStateDisabled ( rtS ,
contStatesDisabled ) ; } ssSetChecksumVal ( rtS , 0 , 1252914586U ) ;
ssSetChecksumVal ( rtS , 1 , 3362424525U ) ; ssSetChecksumVal ( rtS , 2 ,
2296161348U ) ; ssSetChecksumVal ( rtS , 3 , 934207540U ) ; { static const
sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE ; static RTWExtModeInfo
rt_ExtModeInfo ; static const sysRanDType * systemRan [ 17 ] ;
ssSetRTWExtModeInfo ( rtS , & rt_ExtModeInfo ) ;
rteiSetSubSystemActiveVectorAddresses ( & rt_ExtModeInfo , systemRan ) ;
systemRan [ 0 ] = & rtAlwaysEnabled ; systemRan [ 1 ] = & rtAlwaysEnabled ;
systemRan [ 2 ] = ( sysRanDType * ) & rtDW . l1kcj50fwey . ckdn4xd4hz ;
systemRan [ 3 ] = ( sysRanDType * ) & rtDW . aqx150ksytr . ofnp3tiibi ;
systemRan [ 4 ] = ( sysRanDType * ) & rtDW . aqx150ksytr . ofnp3tiibi ;
systemRan [ 5 ] = ( sysRanDType * ) & rtDW . aqx150ksytr . ofnp3tiibi ;
systemRan [ 6 ] = ( sysRanDType * ) & rtDW . p14hwlcq5ag . dbhao2hevj ;
systemRan [ 7 ] = ( sysRanDType * ) & rtDW . i0grvgounuc . e2lhwvg4n3 ;
systemRan [ 8 ] = & rtAlwaysEnabled ; systemRan [ 9 ] = & rtAlwaysEnabled ;
systemRan [ 10 ] = ( sysRanDType * ) & rtDW . kw4gz4nylz . ckdn4xd4hz ;
systemRan [ 11 ] = ( sysRanDType * ) & rtDW . arvvtfsmo3 . ofnp3tiibi ;
systemRan [ 12 ] = ( sysRanDType * ) & rtDW . arvvtfsmo3 . ofnp3tiibi ;
systemRan [ 13 ] = ( sysRanDType * ) & rtDW . arvvtfsmo3 . ofnp3tiibi ;
systemRan [ 14 ] = ( sysRanDType * ) & rtDW . cy14v3kgd2 . dbhao2hevj ;
systemRan [ 15 ] = ( sysRanDType * ) & rtDW . bt1qvoldbv . e2lhwvg4n3 ;
systemRan [ 16 ] = & rtAlwaysEnabled ; rteiSetModelMappingInfoPtr (
ssGetRTWExtModeInfo ( rtS ) , & ssGetModelMappingInfo ( rtS ) ) ;
rteiSetChecksumsPtr ( ssGetRTWExtModeInfo ( rtS ) , ssGetChecksums ( rtS ) )
; rteiSetTPtr ( ssGetRTWExtModeInfo ( rtS ) , ssGetTPtr ( rtS ) ) ; } return
rtS ; }
