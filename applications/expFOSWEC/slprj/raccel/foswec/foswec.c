#include "__cf_foswec.h"
#include "rt_logging_mmi.h"
#include "foswec_capi.h"
#include <math.h>
#include "foswec.h"
#include "foswec_private.h"
#include "foswec_dt.h"
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
"slprj\\raccel\\foswec\\foswec_Jpattern.mat" ; const int_T
gblNumRootInportBlks = 0 ; const int_T gblNumModelInputs = 0 ; extern
rtInportTUtable * gblInportTUtables ; extern const char * gblInportFileName ;
const int_T gblInportDataTypeIdx [ ] = { - 1 } ; const int_T gblInportDims [
] = { - 1 } ; const int_T gblInportComplex [ ] = { - 1 } ; const int_T
gblInportInterpoFlag [ ] = { - 1 } ; const int_T gblInportContinuous [ ] = {
- 1 } ;
#include "simstruc.h"
#include "fixedpoint.h"
B rtB ; X rtX ; DW rtDW ; static SimStruct model_S ; SimStruct * const rtS =
& model_S ; static real_T bbkbdyp4c1 ( const real_T x [ 6 ] ) ; static real_T
n2gecl3fqg ( const real_T x [ 859 ] , const real_T y [ 859 ] , pcwx03o2bp *
localB ) ;
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
void rt_TDelayFreeBuf ( void * buf ) { utFree ( buf ) ; } void fkj5aod2nj (
const real_T plfojltots [ 4 ] , gwsufvgalb * localB ) { localB -> c0mvqybgil
[ 0 ] = 0.0 ; localB -> c0mvqybgil [ 1 ] = 0.0 ; localB -> c0mvqybgil [ 2 ] =
0.0 ; localB -> c0mvqybgil [ 0 ] = muDoubleScalarAtan2 ( ( plfojltots [ 0 ] *
plfojltots [ 1 ] + plfojltots [ 2 ] * plfojltots [ 3 ] ) * 2.0 , 1.0 - (
plfojltots [ 1 ] * plfojltots [ 1 ] + plfojltots [ 2 ] * plfojltots [ 2 ] ) *
2.0 ) ; localB -> c0mvqybgil [ 1 ] = muDoubleScalarAsin ( ( plfojltots [ 0 ]
* plfojltots [ 2 ] - plfojltots [ 3 ] * plfojltots [ 1 ] ) * 2.0 ) ; localB
-> c0mvqybgil [ 2 ] = muDoubleScalarAtan2 ( ( plfojltots [ 0 ] * plfojltots [
3 ] + plfojltots [ 1 ] * plfojltots [ 2 ] ) * 2.0 , 1.0 - ( plfojltots [ 2 ]
* plfojltots [ 2 ] + plfojltots [ 3 ] * plfojltots [ 3 ] ) * 2.0 ) ; } void
fzybd15s0q ( SimStruct * const rtS , real_T koiwir4gai [ 6 ] , kwd4b3jpcn *
localP ) { real_T nh0ldtczrx ; real_T neul1priul [ 6 ] ; int32_T i ;
nh0ldtczrx = muDoubleScalarSin ( localP -> CosWave_Freq * ssGetTaskTime ( rtS
, 0 ) + localP -> CosWave_Phase ) * localP -> CosWave_Amp + localP ->
CosWave_Bias ; for ( i = 0 ; i < 6 ; i ++ ) { neul1priul [ i ] = nh0ldtczrx *
localP -> BEMExcitationRePart_Value [ i ] ; } nh0ldtczrx = muDoubleScalarSin
( localP -> SinWave_Freq * ssGetTaskTime ( rtS , 0 ) + localP ->
SinWave_Phase ) * localP -> SinWave_Amp + localP -> SinWave_Bias ; for ( i =
0 ; i < 6 ; i ++ ) { koiwir4gai [ i ] = neul1priul [ i ] - nh0ldtczrx *
localP -> BEMExcitationImPart1_Value [ i ] ; } } void h02m5m2hej ( real_T
n120bldjdi , real_T kzququx4c2 [ 6 ] , fi0awblwxy * localP ) { int32_T
nvvgbdx01j ; real_T h4saleqnoy ; real_T no3qzdp5rc ; real_T chqk1tzhv3 [ 6 ]
; real_T cuo2dyq5vc ; int32_T i ; for ( nvvgbdx01j = 0 ; nvvgbdx01j < 1 ;
nvvgbdx01j ++ ) { h4saleqnoy = muDoubleScalarSqrt ( localP ->
wavespectrum_Value * localP -> dw1_Value ) ; cuo2dyq5vc = localP ->
wavefrequency_Value * n120bldjdi + localP -> wavefrequency1_Value ;
no3qzdp5rc = muDoubleScalarSin ( localP -> hq5rtzuhum . CosWaveFunction_Freq
* cuo2dyq5vc + localP -> hq5rtzuhum . CosWaveFunction_Phase ) * localP ->
hq5rtzuhum . CosWaveFunction_Amp + localP -> hq5rtzuhum .
CosWaveFunction_Bias ; cuo2dyq5vc = ( muDoubleScalarSin ( localP ->
hq5rtzuhum . SinWaveFunction_Freq * cuo2dyq5vc + localP -> hq5rtzuhum .
SinWaveFunction_Phase ) * localP -> hq5rtzuhum . SinWaveFunction_Amp + localP
-> hq5rtzuhum . SinWaveFunction_Bias ) * h4saleqnoy ; for ( i = 0 ; i < 6 ; i
++ ) { chqk1tzhv3 [ i ] = h4saleqnoy * no3qzdp5rc * localP ->
ExcitationRePart2_Value [ i ] - cuo2dyq5vc * localP ->
ExcitationRePart3_Value [ i ] ; } } for ( i = 0 ; i < 6 ; i ++ ) { kzququx4c2
[ i ] = chqk1tzhv3 [ i ] ; } } void cnj3cuyx4u ( SimStruct * const rtS ,
const real_T mcvlnmfzmp [ 6 ] , real_T mkr5wqpjmu [ 6 ] , djsc05xhw3 * localP
) { real_T hfkl1bmvda ; int32_T i ; hfkl1bmvda = ( muDoubleScalarSin ( localP
-> SineWave_Freq * ssGetTaskTime ( rtS , 0 ) + localP -> SineWave_Phase ) *
localP -> SineWave_Amp + localP -> SineWave_Bias ) + localP ->
Constant1_Value ; for ( i = 0 ; i < 6 ; i ++ ) { mkr5wqpjmu [ i ] =
mcvlnmfzmp [ i ] * hfkl1bmvda / localP -> Constant_Value ; } } void
coaxej2udz ( const real_T bgymqihm35 [ 6 ] , real_T egf14onhiz [ 6 ] ) {
int32_T i ; for ( i = 0 ; i < 6 ; i ++ ) { egf14onhiz [ i ] = bgymqihm35 [ i
] ; } } static real_T bbkbdyp4c1 ( const real_T x [ 6 ] ) { real_T y ;
int32_T k ; y = x [ 0 ] ; for ( k = 0 ; k < 5 ; k ++ ) { y += x [ k + 1 ] ; }
return y ; } static real_T n2gecl3fqg ( const real_T x [ 859 ] , const real_T
y [ 859 ] , pcwx03o2bp * localB ) { real_T z ; int32_T iy ; int32_T ix ;
real_T ylast ; int32_T k ; memcpy ( & localB -> dhs4rowpbe [ 0 ] , & x [ 0 ]
, 859U * sizeof ( real_T ) ) ; for ( ix = 0 ; ix < 858 ; ix ++ ) { localB ->
dhs4rowpbe [ ix ] = localB -> dhs4rowpbe [ ix + 1 ] - localB -> dhs4rowpbe [
ix ] ; } z = 0.0 ; ix = - 1 ; iy = 0 ; ylast = y [ 0 ] ; for ( k = 0 ; k <
858 ; k ++ ) { iy ++ ; ix ++ ; z += ( ylast + y [ iy ] ) / 2.0 * localB ->
dhs4rowpbe [ ix ] ; ylast = y [ iy ] ; } return z ; } void fa0kyolrm3 (
freyzphwfw * localDW ) { localDW -> fazqyerxsu = false ; } void dkqw3o3vme (
real_T gz5c3crpa2 , const real_T kbzpwjwv4k [ 3 ] , const real_T gwkq3lfppm [
3 ] , const real_T ghx3zoa2yd [ 5154 ] , const real_T ac41v1k1jg [ 30924 ] ,
const real_T ld00sbh52o [ 859 ] , pcwx03o2bp * localB , freyzphwfw * localDW
) { real_T tmpF [ 36 ] ; int32_T kk ; int32_T i ; int32_T i_p ; real_T
kbzpwjwv4k_p [ 6 ] ; if ( gz5c3crpa2 == 10.0 ) { for ( i = 0 ; i < 6 ; i ++ )
{ localB -> jmbenplned [ i ] = 0.0 ; } } else { if ( ! localDW -> fazqyerxsu
) { memcpy ( & localDW -> cl4bth31oo [ 0 ] , & ghx3zoa2yd [ 0 ] , 5154U *
sizeof ( real_T ) ) ; localDW -> fazqyerxsu = true ; localDW -> n3iy5isn5k =
0.0 ; } else { localDW -> n3iy5isn5k ++ ; if ( muDoubleScalarAbs ( ( localDW
-> n3iy5isn5k - muDoubleScalarFloor ( localDW -> n3iy5isn5k / 5.0 ) * 5.0 ) -
1.0 ) < 1.0E-8 ) { for ( i_p = 0 ; i_p < 858 ; i_p ++ ) { for ( i = 0 ; i < 6
; i ++ ) { localB -> fvwzfaxh1r [ i + 6 * i_p ] = localDW -> cl4bth31oo [ 6 *
i_p + i ] ; } } for ( i_p = 0 ; i_p < 858 ; i_p ++ ) { for ( i = 0 ; i < 6 ;
i ++ ) { localDW -> cl4bth31oo [ i + 6 * ( 1 + i_p ) ] = localB -> fvwzfaxh1r
[ 6 * i_p + i ] ; } } } kbzpwjwv4k_p [ 0 ] = kbzpwjwv4k [ 0 ] ; kbzpwjwv4k_p
[ 1 ] = kbzpwjwv4k [ 1 ] ; kbzpwjwv4k_p [ 2 ] = kbzpwjwv4k [ 2 ] ;
kbzpwjwv4k_p [ 3 ] = gwkq3lfppm [ 0 ] ; kbzpwjwv4k_p [ 4 ] = gwkq3lfppm [ 1 ]
; kbzpwjwv4k_p [ 5 ] = gwkq3lfppm [ 2 ] ; for ( i_p = 0 ; i_p < 6 ; i_p ++ )
{ localDW -> cl4bth31oo [ i_p ] = kbzpwjwv4k_p [ i_p ] ; } } memset ( & tmpF
[ 0 ] , 0 , 36U * sizeof ( real_T ) ) ; for ( i = 0 ; i < 6 ; i ++ ) { localB
-> jmbenplned [ i ] = 0.0 ; } for ( i = 0 ; i < 6 ; i ++ ) { for ( kk = 0 ;
kk < 6 ; kk ++ ) { for ( i_p = 0 ; i_p < 859 ; i_p ++ ) { localB ->
fti1x5vbt4 [ i_p ] = ac41v1k1jg [ ( 859 * i + i_p ) + 5154 * kk ] * localDW
-> cl4bth31oo [ 6 * i_p + kk ] ; } tmpF [ i + 6 * kk ] = n2gecl3fqg (
ld00sbh52o , localB -> fti1x5vbt4 , localB ) ; } for ( i_p = 0 ; i_p < 6 ;
i_p ++ ) { kbzpwjwv4k_p [ i_p ] = tmpF [ 6 * i_p + i ] ; } localB ->
jmbenplned [ i ] = bbkbdyp4c1 ( kbzpwjwv4k_p ) ; } } } void MdlInitialize (
void ) { boolean_T tmp ; int_T tmp_p ; char * tmp_e ; tmp = false ; if ( tmp
) { tmp_p = strcmp ( "ode4" , ssGetSolverName ( rtS ) ) ; if ( tmp_p != 0 ) {
tmp_e = solver_mismatch_message ( "ode4" , ssGetSolverName ( rtS ) ) ;
ssSetErrorStatus ( rtS , tmp_e ) ; } } fa0kyolrm3 ( & rtDW . arymfxlfvv ) ;
fa0kyolrm3 ( & rtDW . hbwafuhekh ) ; fa0kyolrm3 ( & rtDW . ipyob4ujct ) ; }
void MdlStart ( void ) { NeslSimulator * tmp ; NeuDiagnosticManager *
diagnosticManager ; real_T modelParameters_mSolverTolerance ; real_T
modelParameters_mFixedStepSize ; boolean_T
modelParameters_mVariableStepSolver ; NeuDiagnosticTree * diagnosticTree ;
int32_T tmp_p ; char * msg ; NeslSimulationData * simulationData ; real_T
time ; real_T time_p ; real_T time_e ; NeModelParameters expl_temp ;
NeModelParameters expl_temp_p ; NeModelParameters expl_temp_e ; tmp =
nesl_lease_simulator ( "foswec/Global Reference Frame1/Solver Configuration"
, 0 , 0 ) ; rtDW . pyei4aktas = ( void * ) tmp ;
modelParameters_mVariableStepSolver = pointer_is_null ( rtDW . pyei4aktas ) ;
if ( modelParameters_mVariableStepSolver ) { foswec_4deb2608_gateway ( ) ;
tmp = nesl_lease_simulator (
"foswec/Global Reference Frame1/Solver Configuration" , 0 , 0 ) ; rtDW .
pyei4aktas = ( void * ) tmp ; } simulationData = nesl_create_simulation_data
( ) ; rtDW . lav352kiwz = ( void * ) simulationData ; diagnosticManager =
rtw_create_diagnostics ( ) ; rtDW . gknbsopy3r = ( void * ) diagnosticManager
; modelParameters_mSolverTolerance = 0.001 ; modelParameters_mFixedStepSize =
0.07 ; modelParameters_mVariableStepSolver = false ; diagnosticManager = (
NeuDiagnosticManager * ) rtDW . gknbsopy3r ; diagnosticTree =
neu_diagnostic_manager_get_initial_tree ( diagnosticManager ) ; expl_temp .
mVariableStepSolver = modelParameters_mVariableStepSolver ; expl_temp .
mUseSimState = false ; expl_temp . mStartTime = 0.0 ; expl_temp . mSolverType
= NE_SOLVER_TYPE_ODE ; expl_temp . mSolverTolerance =
modelParameters_mSolverTolerance ; expl_temp . mLoggingMode =
SSC_LOGGING_NONE ; expl_temp . mLoadInitialState = false ; expl_temp .
mLinTrimCompile = false ; expl_temp . mFixedStepSize =
modelParameters_mFixedStepSize ; tmp_p = nesl_initialize_simulator ( (
NeslSimulator * ) rtDW . pyei4aktas , expl_temp , diagnosticManager ) ; if (
tmp_p != 0 ) { modelParameters_mVariableStepSolver = error_buffer_is_empty (
ssGetErrorStatus ( rtS ) ) ; if ( modelParameters_mVariableStepSolver ) { msg
= rtw_diagnostics_msg ( diagnosticTree ) ; ssSetErrorStatus ( rtS , msg ) ; }
} simulationData = ( NeslSimulationData * ) rtDW . lav352kiwz ; time = ssGetT
( rtS ) ; simulationData -> mData -> mTime . mN = 1 ; simulationData -> mData
-> mTime . mX = & time ; simulationData -> mData -> mContStates . mN = 4 ;
simulationData -> mData -> mContStates . mX = ( real_T * ) & rtX . h5zfgvmg3r
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
NeuDiagnosticManager * ) rtDW . gknbsopy3r ; diagnosticTree =
neu_diagnostic_manager_get_initial_tree ( diagnosticManager ) ; tmp_p =
ne_simulator_method ( ( NeslSimulator * ) rtDW . pyei4aktas ,
NESL_SIM_INITIALIZEONCE , simulationData , diagnosticManager ) ; if ( tmp_p
!= 0 ) { modelParameters_mVariableStepSolver = error_buffer_is_empty (
ssGetErrorStatus ( rtS ) ) ; if ( modelParameters_mVariableStepSolver ) { msg
= rtw_diagnostics_msg ( diagnosticTree ) ; ssSetErrorStatus ( rtS , msg ) ; }
} tmp = nesl_lease_simulator (
"foswec/Global Reference Frame1/Solver Configuration" , 2 , 1 ) ; rtDW .
d3bbzrpbvx = ( void * ) tmp ; modelParameters_mVariableStepSolver =
pointer_is_null ( rtDW . d3bbzrpbvx ) ; if (
modelParameters_mVariableStepSolver ) { foswec_4deb2608_gateway ( ) ; tmp =
nesl_lease_simulator ( "foswec/Global Reference Frame1/Solver Configuration"
, 2 , 1 ) ; rtDW . d3bbzrpbvx = ( void * ) tmp ; } simulationData =
nesl_create_simulation_data ( ) ; rtDW . awgpzntukc = ( void * )
simulationData ; diagnosticManager = rtw_create_diagnostics ( ) ; rtDW .
k13qfbrzod = ( void * ) diagnosticManager ; modelParameters_mSolverTolerance
= 0.001 ; modelParameters_mFixedStepSize = 0.07 ;
modelParameters_mVariableStepSolver = false ; diagnosticManager = (
NeuDiagnosticManager * ) rtDW . k13qfbrzod ; diagnosticTree =
neu_diagnostic_manager_get_initial_tree ( diagnosticManager ) ; expl_temp_p .
mVariableStepSolver = modelParameters_mVariableStepSolver ; expl_temp_p .
mUseSimState = false ; expl_temp_p . mStartTime = 0.0 ; expl_temp_p .
mSolverType = NE_SOLVER_TYPE_ODE ; expl_temp_p . mSolverTolerance =
modelParameters_mSolverTolerance ; expl_temp_p . mLoggingMode =
SSC_LOGGING_NONE ; expl_temp_p . mLoadInitialState = false ; expl_temp_p .
mLinTrimCompile = false ; expl_temp_p . mFixedStepSize =
modelParameters_mFixedStepSize ; tmp_p = nesl_initialize_simulator ( (
NeslSimulator * ) rtDW . d3bbzrpbvx , expl_temp_p , diagnosticManager ) ; if
( tmp_p != 0 ) { modelParameters_mVariableStepSolver = error_buffer_is_empty
( ssGetErrorStatus ( rtS ) ) ; if ( modelParameters_mVariableStepSolver ) {
msg = rtw_diagnostics_msg ( diagnosticTree ) ; ssSetErrorStatus ( rtS , msg )
; } } simulationData = ( NeslSimulationData * ) rtDW . awgpzntukc ; time_p =
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
* ) rtDW . k13qfbrzod ; diagnosticTree =
neu_diagnostic_manager_get_initial_tree ( diagnosticManager ) ; tmp_p =
ne_simulator_method ( ( NeslSimulator * ) rtDW . d3bbzrpbvx ,
NESL_SIM_INITIALIZEONCE , simulationData , diagnosticManager ) ; if ( tmp_p
!= 0 ) { modelParameters_mVariableStepSolver = error_buffer_is_empty (
ssGetErrorStatus ( rtS ) ) ; if ( modelParameters_mVariableStepSolver ) { msg
= rtw_diagnostics_msg ( diagnosticTree ) ; ssSetErrorStatus ( rtS , msg ) ; }
} { { int_T i1 ; int_T * iw_Tail = & rtDW . iie0k52gf2 . Tail [ 0 ] ; int_T *
iw_Head = & rtDW . iie0k52gf2 . Head [ 0 ] ; int_T * iw_Last = & rtDW .
iie0k52gf2 . Last [ 0 ] ; int_T * iw_CircularBufSize = & rtDW . iie0k52gf2 .
CircularBufSize [ 0 ] ; void * * pw_TUbufferPtrs = & rtDW . ozvltbk2so .
TUbufferPtrs [ 0 ] ; for ( i1 = 0 ; i1 < 3 ; i1 ++ ) { real_T * pBuffer = (
real_T * ) rt_TDelayCreateBuf ( 2 , 1024 , sizeof ( real_T ) ) ; if ( pBuffer
== ( NULL ) ) { ssSetErrorStatus ( rtS , "tdelay memory allocation error" ) ;
return ; } iw_Tail [ i1 ] = 0 ; iw_Head [ i1 ] = 0 ; iw_Last [ i1 ] = 0 ;
iw_CircularBufSize [ i1 ] = 1024 ; pBuffer [ 0 ] = rtP .
TransportDelay_InitOutput ; pBuffer [ 1024 ] = ssGetT ( rtS ) ;
pw_TUbufferPtrs [ i1 ] = ( void * ) & pBuffer [ 0 ] ; pw_TUbufferPtrs [ i1 +
6 ] = ( void * ) & pBuffer [ 1024 ] ; } iw_Tail = & rtDW . iie0k52gf2 . Tail
[ 3 ] ; iw_Head = & rtDW . iie0k52gf2 . Head [ 3 ] ; iw_Last = & rtDW .
iie0k52gf2 . Last [ 3 ] ; iw_CircularBufSize = & rtDW . iie0k52gf2 .
CircularBufSize [ 3 ] ; pw_TUbufferPtrs = & rtDW . ozvltbk2so . TUbufferPtrs
[ 3 ] ; for ( i1 = 0 ; i1 < 3 ; i1 ++ ) { real_T * pBuffer = ( real_T * )
rt_TDelayCreateBuf ( 2 , 1024 , sizeof ( real_T ) ) ; if ( pBuffer == ( NULL
) ) { ssSetErrorStatus ( rtS , "tdelay memory allocation error" ) ; return ;
} iw_Tail [ i1 ] = 0 ; iw_Head [ i1 ] = 0 ; iw_Last [ i1 ] = 0 ;
iw_CircularBufSize [ i1 ] = 1024 ; pBuffer [ 0 ] = rtP .
TransportDelay_InitOutput ; pBuffer [ 1024 ] = ssGetT ( rtS ) ;
pw_TUbufferPtrs [ i1 ] = ( void * ) & pBuffer [ 0 ] ; pw_TUbufferPtrs [ i1 +
6 ] = ( void * ) & pBuffer [ 1024 ] ; } } } rtDW . gl2utjnv03 = - 1 ; rtDW .
mrlpfzs3wn = - 1 ; { { int_T i1 ; int_T * iw_Tail = & rtDW . hxf5v0hxfq .
Tail [ 0 ] ; int_T * iw_Head = & rtDW . hxf5v0hxfq . Head [ 0 ] ; int_T *
iw_Last = & rtDW . hxf5v0hxfq . Last [ 0 ] ; int_T * iw_CircularBufSize = &
rtDW . hxf5v0hxfq . CircularBufSize [ 0 ] ; void * * pw_TUbufferPtrs = & rtDW
. fv3pugwi2m . TUbufferPtrs [ 0 ] ; for ( i1 = 0 ; i1 < 3 ; i1 ++ ) { real_T
* pBuffer = ( real_T * ) rt_TDelayCreateBuf ( 2 , 1024 , sizeof ( real_T ) )
; if ( pBuffer == ( NULL ) ) { ssSetErrorStatus ( rtS ,
"tdelay memory allocation error" ) ; return ; } iw_Tail [ i1 ] = 0 ; iw_Head
[ i1 ] = 0 ; iw_Last [ i1 ] = 0 ; iw_CircularBufSize [ i1 ] = 1024 ; pBuffer
[ 0 ] = rtP . TransportDelay_InitOutput_ii0y22uej3 ; pBuffer [ 1024 ] =
ssGetT ( rtS ) ; pw_TUbufferPtrs [ i1 ] = ( void * ) & pBuffer [ 0 ] ;
pw_TUbufferPtrs [ i1 + 6 ] = ( void * ) & pBuffer [ 1024 ] ; } iw_Tail = &
rtDW . hxf5v0hxfq . Tail [ 3 ] ; iw_Head = & rtDW . hxf5v0hxfq . Head [ 3 ] ;
iw_Last = & rtDW . hxf5v0hxfq . Last [ 3 ] ; iw_CircularBufSize = & rtDW .
hxf5v0hxfq . CircularBufSize [ 3 ] ; pw_TUbufferPtrs = & rtDW . fv3pugwi2m .
TUbufferPtrs [ 3 ] ; for ( i1 = 0 ; i1 < 3 ; i1 ++ ) { real_T * pBuffer = (
real_T * ) rt_TDelayCreateBuf ( 2 , 1024 , sizeof ( real_T ) ) ; if ( pBuffer
== ( NULL ) ) { ssSetErrorStatus ( rtS , "tdelay memory allocation error" ) ;
return ; } iw_Tail [ i1 ] = 0 ; iw_Head [ i1 ] = 0 ; iw_Last [ i1 ] = 0 ;
iw_CircularBufSize [ i1 ] = 1024 ; pBuffer [ 0 ] = rtP .
TransportDelay_InitOutput_ii0y22uej3 ; pBuffer [ 1024 ] = ssGetT ( rtS ) ;
pw_TUbufferPtrs [ i1 ] = ( void * ) & pBuffer [ 0 ] ; pw_TUbufferPtrs [ i1 +
6 ] = ( void * ) & pBuffer [ 1024 ] ; } } } rtDW . dnkdbkqczp = - 1 ; rtDW .
kols4c4dg4 = - 1 ; { { int_T i1 ; int_T * iw_Tail = & rtDW . nrayhafgyw .
Tail [ 0 ] ; int_T * iw_Head = & rtDW . nrayhafgyw . Head [ 0 ] ; int_T *
iw_Last = & rtDW . nrayhafgyw . Last [ 0 ] ; int_T * iw_CircularBufSize = &
rtDW . nrayhafgyw . CircularBufSize [ 0 ] ; void * * pw_TUbufferPtrs = & rtDW
. a1q2j3sqxq . TUbufferPtrs [ 0 ] ; for ( i1 = 0 ; i1 < 3 ; i1 ++ ) { real_T
* pBuffer = ( real_T * ) rt_TDelayCreateBuf ( 2 , 1024 , sizeof ( real_T ) )
; if ( pBuffer == ( NULL ) ) { ssSetErrorStatus ( rtS ,
"tdelay memory allocation error" ) ; return ; } iw_Tail [ i1 ] = 0 ; iw_Head
[ i1 ] = 0 ; iw_Last [ i1 ] = 0 ; iw_CircularBufSize [ i1 ] = 1024 ; pBuffer
[ 0 ] = rtP . TransportDelay_InitOutput_bf1kxbkfem ; pBuffer [ 1024 ] =
ssGetT ( rtS ) ; pw_TUbufferPtrs [ i1 ] = ( void * ) & pBuffer [ 0 ] ;
pw_TUbufferPtrs [ i1 + 6 ] = ( void * ) & pBuffer [ 1024 ] ; } iw_Tail = &
rtDW . nrayhafgyw . Tail [ 3 ] ; iw_Head = & rtDW . nrayhafgyw . Head [ 3 ] ;
iw_Last = & rtDW . nrayhafgyw . Last [ 3 ] ; iw_CircularBufSize = & rtDW .
nrayhafgyw . CircularBufSize [ 3 ] ; pw_TUbufferPtrs = & rtDW . a1q2j3sqxq .
TUbufferPtrs [ 3 ] ; for ( i1 = 0 ; i1 < 3 ; i1 ++ ) { real_T * pBuffer = (
real_T * ) rt_TDelayCreateBuf ( 2 , 1024 , sizeof ( real_T ) ) ; if ( pBuffer
== ( NULL ) ) { ssSetErrorStatus ( rtS , "tdelay memory allocation error" ) ;
return ; } iw_Tail [ i1 ] = 0 ; iw_Head [ i1 ] = 0 ; iw_Last [ i1 ] = 0 ;
iw_CircularBufSize [ i1 ] = 1024 ; pBuffer [ 0 ] = rtP .
TransportDelay_InitOutput_bf1kxbkfem ; pBuffer [ 1024 ] = ssGetT ( rtS ) ;
pw_TUbufferPtrs [ i1 ] = ( void * ) & pBuffer [ 0 ] ; pw_TUbufferPtrs [ i1 +
6 ] = ( void * ) & pBuffer [ 1024 ] ; } } } rtDW . gibqmcfn3a = - 1 ; rtDW .
ob5wky4wsa = - 1 ; tmp = nesl_lease_simulator (
"foswec/Global Reference Frame1/Solver Configuration" , 2 , 0 ) ; rtDW .
kac3j5zyhm = ( void * ) tmp ; modelParameters_mVariableStepSolver =
pointer_is_null ( rtDW . kac3j5zyhm ) ; if (
modelParameters_mVariableStepSolver ) { foswec_4deb2608_gateway ( ) ; tmp =
nesl_lease_simulator ( "foswec/Global Reference Frame1/Solver Configuration"
, 2 , 0 ) ; rtDW . kac3j5zyhm = ( void * ) tmp ; } simulationData =
nesl_create_simulation_data ( ) ; rtDW . mzt5dujgnf = ( void * )
simulationData ; diagnosticManager = rtw_create_diagnostics ( ) ; rtDW .
hmwzsbnven = ( void * ) diagnosticManager ; modelParameters_mSolverTolerance
= 0.001 ; modelParameters_mFixedStepSize = 0.07 ;
modelParameters_mVariableStepSolver = false ; diagnosticManager = (
NeuDiagnosticManager * ) rtDW . hmwzsbnven ; diagnosticTree =
neu_diagnostic_manager_get_initial_tree ( diagnosticManager ) ; expl_temp_e .
mVariableStepSolver = modelParameters_mVariableStepSolver ; expl_temp_e .
mUseSimState = false ; expl_temp_e . mStartTime = 0.0 ; expl_temp_e .
mSolverType = NE_SOLVER_TYPE_ODE ; expl_temp_e . mSolverTolerance =
modelParameters_mSolverTolerance ; expl_temp_e . mLoggingMode =
SSC_LOGGING_NONE ; expl_temp_e . mLoadInitialState = false ; expl_temp_e .
mLinTrimCompile = false ; expl_temp_e . mFixedStepSize =
modelParameters_mFixedStepSize ; tmp_p = nesl_initialize_simulator ( (
NeslSimulator * ) rtDW . kac3j5zyhm , expl_temp_e , diagnosticManager ) ; if
( tmp_p != 0 ) { modelParameters_mVariableStepSolver = error_buffer_is_empty
( ssGetErrorStatus ( rtS ) ) ; if ( modelParameters_mVariableStepSolver ) {
msg = rtw_diagnostics_msg ( diagnosticTree ) ; ssSetErrorStatus ( rtS , msg )
; } } simulationData = ( NeslSimulationData * ) rtDW . mzt5dujgnf ; time_e =
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
* ) rtDW . hmwzsbnven ; diagnosticTree =
neu_diagnostic_manager_get_initial_tree ( diagnosticManager ) ; tmp_p =
ne_simulator_method ( ( NeslSimulator * ) rtDW . kac3j5zyhm ,
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
"foswec/Fixed2/output" ; rtDW . facajaxtwh . LoggedData =
rt_CreateStructLogVar ( ssGetRTWLogInfo ( rtS ) , ssGetTStart ( rtS ) ,
ssGetTFinal ( rtS ) , 0.0 , ( & ssGetErrorStatus ( rtS ) ) ,
"platformFixed_out" , 1 , 0 , 1 , 0.07 , & rt_ToWksSignalInfo ,
rt_ToWksBlockName ) ; if ( rtDW . facajaxtwh . LoggedData == ( NULL ) )
return ; } { static int_T rt_ToWksWidths [ ] = { 66 } ; static int_T
rt_ToWksNumDimensions [ ] = { 1 } ; static int_T rt_ToWksDimensions [ ] = {
66 } ; static boolean_T rt_ToWksIsVarDims [ ] = { 0 } ; static void *
rt_ToWksCurrSigDims [ ] = { ( NULL ) } ; static int_T rt_ToWksCurrSigDimsSize
[ ] = { 4 } ; static BuiltInDTypeId rt_ToWksDataTypeIds [ ] = { SS_DOUBLE } ;
static int_T rt_ToWksComplexSignals [ ] = { 0 } ; static int_T
rt_ToWksFrameData [ ] = { 0 } ; static const char_T * rt_ToWksLabels [ ] = {
"" } ; static RTWLogSignalInfo rt_ToWksSignalInfo = { 1 , rt_ToWksWidths ,
rt_ToWksNumDimensions , rt_ToWksDimensions , rt_ToWksIsVarDims ,
rt_ToWksCurrSigDims , rt_ToWksCurrSigDimsSize , rt_ToWksDataTypeIds ,
rt_ToWksComplexSignals , rt_ToWksFrameData , { rt_ToWksLabels } , ( NULL ) ,
( NULL ) , ( NULL ) , { ( NULL ) } , { ( NULL ) } , ( NULL ) , ( NULL ) } ;
static const char_T rt_ToWksBlockName [ ] = "foswec/Flap 1/To Workspace" ;
rtDW . ea2glvbgz2 . LoggedData = rt_CreateStructLogVar ( ssGetRTWLogInfo (
rtS ) , ssGetTStart ( rtS ) , ssGetTFinal ( rtS ) , 0.0 , ( &
ssGetErrorStatus ( rtS ) ) , "flap1_out" , 1 , 0 , 1 , 0.07 , &
rt_ToWksSignalInfo , rt_ToWksBlockName ) ; if ( rtDW . ea2glvbgz2 .
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
rt_ToWksBlockName [ ] = "foswec/Flap 2/To Workspace" ; rtDW . fb5d5dwuih .
LoggedData = rt_CreateStructLogVar ( ssGetRTWLogInfo ( rtS ) , ssGetTStart (
rtS ) , ssGetTFinal ( rtS ) , 0.0 , ( & ssGetErrorStatus ( rtS ) ) ,
"flap2_out" , 1 , 0 , 1 , 0.07 , & rt_ToWksSignalInfo , rt_ToWksBlockName ) ;
if ( rtDW . fb5d5dwuih . LoggedData == ( NULL ) ) return ; } { static int_T
rt_ToWksWidths [ ] = { 66 } ; static int_T rt_ToWksNumDimensions [ ] = { 1 }
; static int_T rt_ToWksDimensions [ ] = { 66 } ; static boolean_T
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
static const char_T rt_ToWksBlockName [ ] = "foswec/Platform/To Workspace" ;
rtDW . pztby5tdmg . LoggedData = rt_CreateStructLogVar ( ssGetRTWLogInfo (
rtS ) , ssGetTStart ( rtS ) , ssGetTFinal ( rtS ) , 0.0 , ( &
ssGetErrorStatus ( rtS ) ) , "frame_out" , 1 , 0 , 1 , 0.07 , &
rt_ToWksSignalInfo , rt_ToWksBlockName ) ; if ( rtDW . pztby5tdmg .
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
rt_ToWksBlockName [ ] = "foswec/Rotational PTO\n(Local RY)/output" ; rtDW .
o3l54yb1i3 . LoggedData = rt_CreateStructLogVar ( ssGetRTWLogInfo ( rtS ) ,
ssGetTStart ( rtS ) , ssGetTFinal ( rtS ) , 0.0 , ( & ssGetErrorStatus ( rtS
) ) , "flap1pitch_out" , 1 , 0 , 1 , 0.07 , & rt_ToWksSignalInfo ,
rt_ToWksBlockName ) ; if ( rtDW . o3l54yb1i3 . LoggedData == ( NULL ) )
return ; } { static int_T rt_ToWksWidths [ ] = { 8 } ; static int_T
rt_ToWksNumDimensions [ ] = { 1 } ; static int_T rt_ToWksDimensions [ ] = { 8
} ; static boolean_T rt_ToWksIsVarDims [ ] = { 0 } ; static void *
rt_ToWksCurrSigDims [ ] = { ( NULL ) } ; static int_T rt_ToWksCurrSigDimsSize
[ ] = { 4 } ; static BuiltInDTypeId rt_ToWksDataTypeIds [ ] = { SS_DOUBLE } ;
static int_T rt_ToWksComplexSignals [ ] = { 0 } ; static int_T
rt_ToWksFrameData [ ] = { 0 } ; static const char_T * rt_ToWksLabels [ ] = {
"" } ; static RTWLogSignalInfo rt_ToWksSignalInfo = { 1 , rt_ToWksWidths ,
rt_ToWksNumDimensions , rt_ToWksDimensions , rt_ToWksIsVarDims ,
rt_ToWksCurrSigDims , rt_ToWksCurrSigDimsSize , rt_ToWksDataTypeIds ,
rt_ToWksComplexSignals , rt_ToWksFrameData , { rt_ToWksLabels } , ( NULL ) ,
( NULL ) , ( NULL ) , { ( NULL ) } , { ( NULL ) } , ( NULL ) , ( NULL ) } ;
static const char_T rt_ToWksBlockName [ ] =
"foswec/Rotational PTO\n(Local RY)1/output" ; rtDW . lvjvwmkulx . LoggedData
= rt_CreateStructLogVar ( ssGetRTWLogInfo ( rtS ) , ssGetTStart ( rtS ) ,
ssGetTFinal ( rtS ) , 0.0 , ( & ssGetErrorStatus ( rtS ) ) , "flap2pitch_out"
, 1 , 0 , 1 , 0.07 , & rt_ToWksSignalInfo , rt_ToWksBlockName ) ; if ( rtDW .
lvjvwmkulx . LoggedData == ( NULL ) ) return ; } MdlInitialize ( ) ; } void
MdlOutputs ( int_T tid ) { real_T bevdjak0ez [ 6 ] ; real_T kmu1g2pi1e [ 6 ]
; real_T acwhwet23h [ 6 ] ; real_T bsoxugrlmu [ 6 ] ; NeslSimulationData *
simulationData ; real_T time ; boolean_T tmp ; real_T tmp_p [ 72 ] ; int_T
tmp_e [ 19 ] ; NeuDiagnosticManager * diagnosticManager ; NeuDiagnosticTree *
diagnosticTree ; char * msg ; real_T time_p ; real_T tmp_i [ 76 ] ; int_T
tmp_m [ 20 ] ; real_T time_e ; real_T tmp_g [ 76 ] ; int_T tmp_j [ 20 ] ;
real_T oltitf3tj2 [ 6 ] ; real_T dbjtalp5d0 [ 6 ] ; int8_T rtAction ; real_T
kdogumg1ub ; real_T mddlqmjh41 ; int32_T i ; real_T iq12q2ugfv [ 6 ] ;
int32_T i_p ; srClearBC ( rtDW . fzybd15s0q0 . gnrlcinhso ) ; srClearBC (
rtDW . h02m5m2hejt . ljbrchkhk1 ) ; srClearBC ( rtDW . cnj3cuyx4ul .
cvx5ycrffh ) ; srClearBC ( rtDW . coaxej2udzm . oqsczzj035 ) ; simulationData
= ( NeslSimulationData * ) rtDW . lav352kiwz ; time = ssGetT ( rtS ) ;
simulationData -> mData -> mTime . mN = 1 ; simulationData -> mData -> mTime
. mX = & time ; simulationData -> mData -> mContStates . mN = 4 ;
simulationData -> mData -> mContStates . mX = ( real_T * ) & rtX . h5zfgvmg3r
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
p1qklr3iem [ 0 ] ; tmp_p [ 1 ] = rtB . p1qklr3iem [ 1 ] ; tmp_p [ 2 ] = rtB .
p1qklr3iem [ 2 ] ; tmp_p [ 3 ] = rtB . p1qklr3iem [ 3 ] ; tmp_e [ 1 ] = 4 ;
tmp_p [ 4 ] = rtB . dzcyvgjss1 [ 0 ] ; tmp_p [ 5 ] = rtB . dzcyvgjss1 [ 1 ] ;
tmp_p [ 6 ] = rtB . dzcyvgjss1 [ 2 ] ; tmp_p [ 7 ] = rtB . dzcyvgjss1 [ 3 ] ;
tmp_e [ 2 ] = 8 ; tmp_p [ 8 ] = rtB . kyqswxndxu [ 0 ] ; tmp_p [ 9 ] = rtB .
kyqswxndxu [ 1 ] ; tmp_p [ 10 ] = rtB . kyqswxndxu [ 2 ] ; tmp_p [ 11 ] = rtB
. kyqswxndxu [ 3 ] ; tmp_e [ 3 ] = 12 ; tmp_p [ 12 ] = rtB . os0vmujie2 [ 0 ]
; tmp_p [ 13 ] = rtB . os0vmujie2 [ 1 ] ; tmp_p [ 14 ] = rtB . os0vmujie2 [ 2
] ; tmp_p [ 15 ] = rtB . os0vmujie2 [ 3 ] ; tmp_e [ 4 ] = 16 ; tmp_p [ 16 ] =
rtB . f5vdxtzttp [ 0 ] ; tmp_p [ 17 ] = rtB . f5vdxtzttp [ 1 ] ; tmp_p [ 18 ]
= rtB . f5vdxtzttp [ 2 ] ; tmp_p [ 19 ] = rtB . f5vdxtzttp [ 3 ] ; tmp_e [ 5
] = 20 ; tmp_p [ 20 ] = rtB . ny3ji5snoz [ 0 ] ; tmp_p [ 21 ] = rtB .
ny3ji5snoz [ 1 ] ; tmp_p [ 22 ] = rtB . ny3ji5snoz [ 2 ] ; tmp_p [ 23 ] = rtB
. ny3ji5snoz [ 3 ] ; tmp_e [ 6 ] = 24 ; tmp_p [ 24 ] = rtB . kgii2iaa1l [ 0 ]
; tmp_p [ 25 ] = rtB . kgii2iaa1l [ 1 ] ; tmp_p [ 26 ] = rtB . kgii2iaa1l [ 2
] ; tmp_p [ 27 ] = rtB . kgii2iaa1l [ 3 ] ; tmp_e [ 7 ] = 28 ; tmp_p [ 28 ] =
rtB . jfce0w0ghr [ 0 ] ; tmp_p [ 29 ] = rtB . jfce0w0ghr [ 1 ] ; tmp_p [ 30 ]
= rtB . jfce0w0ghr [ 2 ] ; tmp_p [ 31 ] = rtB . jfce0w0ghr [ 3 ] ; tmp_e [ 8
] = 32 ; tmp_p [ 32 ] = rtB . pcf0pfmweo [ 0 ] ; tmp_p [ 33 ] = rtB .
pcf0pfmweo [ 1 ] ; tmp_p [ 34 ] = rtB . pcf0pfmweo [ 2 ] ; tmp_p [ 35 ] = rtB
. pcf0pfmweo [ 3 ] ; tmp_e [ 9 ] = 36 ; tmp_p [ 36 ] = rtB . if52phrmag [ 0 ]
; tmp_p [ 37 ] = rtB . if52phrmag [ 1 ] ; tmp_p [ 38 ] = rtB . if52phrmag [ 2
] ; tmp_p [ 39 ] = rtB . if52phrmag [ 3 ] ; tmp_e [ 10 ] = 40 ; tmp_p [ 40 ]
= rtB . mocddkrpki [ 0 ] ; tmp_p [ 41 ] = rtB . mocddkrpki [ 1 ] ; tmp_p [ 42
] = rtB . mocddkrpki [ 2 ] ; tmp_p [ 43 ] = rtB . mocddkrpki [ 3 ] ; tmp_e [
11 ] = 44 ; tmp_p [ 44 ] = rtB . kzwkda2ehh [ 0 ] ; tmp_p [ 45 ] = rtB .
kzwkda2ehh [ 1 ] ; tmp_p [ 46 ] = rtB . kzwkda2ehh [ 2 ] ; tmp_p [ 47 ] = rtB
. kzwkda2ehh [ 3 ] ; tmp_e [ 12 ] = 48 ; tmp_p [ 48 ] = rtB . hmeg1w5jim [ 0
] ; tmp_p [ 49 ] = rtB . hmeg1w5jim [ 1 ] ; tmp_p [ 50 ] = rtB . hmeg1w5jim [
2 ] ; tmp_p [ 51 ] = rtB . hmeg1w5jim [ 3 ] ; tmp_e [ 13 ] = 52 ; tmp_p [ 52
] = rtB . nbocq1o42k [ 0 ] ; tmp_p [ 53 ] = rtB . nbocq1o42k [ 1 ] ; tmp_p [
54 ] = rtB . nbocq1o42k [ 2 ] ; tmp_p [ 55 ] = rtB . nbocq1o42k [ 3 ] ; tmp_e
[ 14 ] = 56 ; tmp_p [ 56 ] = rtB . d5a52isphm [ 0 ] ; tmp_p [ 57 ] = rtB .
d5a52isphm [ 1 ] ; tmp_p [ 58 ] = rtB . d5a52isphm [ 2 ] ; tmp_p [ 59 ] = rtB
. d5a52isphm [ 3 ] ; tmp_e [ 15 ] = 60 ; tmp_p [ 60 ] = rtB . icy3aei5aw [ 0
] ; tmp_p [ 61 ] = rtB . icy3aei5aw [ 1 ] ; tmp_p [ 62 ] = rtB . icy3aei5aw [
2 ] ; tmp_p [ 63 ] = rtB . icy3aei5aw [ 3 ] ; tmp_e [ 16 ] = 64 ; tmp_p [ 64
] = rtB . add5kxxow3 [ 0 ] ; tmp_p [ 65 ] = rtB . add5kxxow3 [ 1 ] ; tmp_p [
66 ] = rtB . add5kxxow3 [ 2 ] ; tmp_p [ 67 ] = rtB . add5kxxow3 [ 3 ] ; tmp_e
[ 17 ] = 68 ; tmp_p [ 68 ] = rtB . oigl01ewmc [ 0 ] ; tmp_p [ 69 ] = rtB .
oigl01ewmc [ 1 ] ; tmp_p [ 70 ] = rtB . oigl01ewmc [ 2 ] ; tmp_p [ 71 ] = rtB
. oigl01ewmc [ 3 ] ; tmp_e [ 18 ] = 72 ; simulationData -> mData ->
mInputValues . mN = 72 ; simulationData -> mData -> mInputValues . mX = &
tmp_p [ 0 ] ; simulationData -> mData -> mInputOffsets . mN = 19 ;
simulationData -> mData -> mInputOffsets . mX = & tmp_e [ 0 ] ;
simulationData -> mData -> mOutputs . mN = 4 ; simulationData -> mData ->
mOutputs . mX = & rtB . gja4dzl325 [ 0 ] ; simulationData -> mData ->
mSampleHits . mN = 0 ; simulationData -> mData -> mSampleHits . mX = NULL ;
simulationData -> mData -> mIsFundamentalSampleHit = false ;
diagnosticManager = ( NeuDiagnosticManager * ) rtDW . gknbsopy3r ;
diagnosticTree = neu_diagnostic_manager_get_initial_tree ( diagnosticManager
) ; i = ne_simulator_method ( ( NeslSimulator * ) rtDW . pyei4aktas ,
NESL_SIM_OUTPUTS , simulationData , diagnosticManager ) ; if ( i != 0 ) { tmp
= error_buffer_is_empty ( ssGetErrorStatus ( rtS ) ) ; if ( tmp ) { msg =
rtw_diagnostics_msg ( diagnosticTree ) ; ssSetErrorStatus ( rtS , msg ) ; } }
simulationData = ( NeslSimulationData * ) rtDW . awgpzntukc ; time_p = ssGetT
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
rtB . p1qklr3iem [ 0 ] ; tmp_i [ 1 ] = rtB . p1qklr3iem [ 1 ] ; tmp_i [ 2 ] =
rtB . p1qklr3iem [ 2 ] ; tmp_i [ 3 ] = rtB . p1qklr3iem [ 3 ] ; tmp_m [ 1 ] =
4 ; tmp_i [ 4 ] = rtB . dzcyvgjss1 [ 0 ] ; tmp_i [ 5 ] = rtB . dzcyvgjss1 [ 1
] ; tmp_i [ 6 ] = rtB . dzcyvgjss1 [ 2 ] ; tmp_i [ 7 ] = rtB . dzcyvgjss1 [ 3
] ; tmp_m [ 2 ] = 8 ; tmp_i [ 8 ] = rtB . kyqswxndxu [ 0 ] ; tmp_i [ 9 ] =
rtB . kyqswxndxu [ 1 ] ; tmp_i [ 10 ] = rtB . kyqswxndxu [ 2 ] ; tmp_i [ 11 ]
= rtB . kyqswxndxu [ 3 ] ; tmp_m [ 3 ] = 12 ; tmp_i [ 12 ] = rtB . os0vmujie2
[ 0 ] ; tmp_i [ 13 ] = rtB . os0vmujie2 [ 1 ] ; tmp_i [ 14 ] = rtB .
os0vmujie2 [ 2 ] ; tmp_i [ 15 ] = rtB . os0vmujie2 [ 3 ] ; tmp_m [ 4 ] = 16 ;
tmp_i [ 16 ] = rtB . f5vdxtzttp [ 0 ] ; tmp_i [ 17 ] = rtB . f5vdxtzttp [ 1 ]
; tmp_i [ 18 ] = rtB . f5vdxtzttp [ 2 ] ; tmp_i [ 19 ] = rtB . f5vdxtzttp [ 3
] ; tmp_m [ 5 ] = 20 ; tmp_i [ 20 ] = rtB . ny3ji5snoz [ 0 ] ; tmp_i [ 21 ] =
rtB . ny3ji5snoz [ 1 ] ; tmp_i [ 22 ] = rtB . ny3ji5snoz [ 2 ] ; tmp_i [ 23 ]
= rtB . ny3ji5snoz [ 3 ] ; tmp_m [ 6 ] = 24 ; tmp_i [ 24 ] = rtB . kgii2iaa1l
[ 0 ] ; tmp_i [ 25 ] = rtB . kgii2iaa1l [ 1 ] ; tmp_i [ 26 ] = rtB .
kgii2iaa1l [ 2 ] ; tmp_i [ 27 ] = rtB . kgii2iaa1l [ 3 ] ; tmp_m [ 7 ] = 28 ;
tmp_i [ 28 ] = rtB . jfce0w0ghr [ 0 ] ; tmp_i [ 29 ] = rtB . jfce0w0ghr [ 1 ]
; tmp_i [ 30 ] = rtB . jfce0w0ghr [ 2 ] ; tmp_i [ 31 ] = rtB . jfce0w0ghr [ 3
] ; tmp_m [ 8 ] = 32 ; tmp_i [ 32 ] = rtB . pcf0pfmweo [ 0 ] ; tmp_i [ 33 ] =
rtB . pcf0pfmweo [ 1 ] ; tmp_i [ 34 ] = rtB . pcf0pfmweo [ 2 ] ; tmp_i [ 35 ]
= rtB . pcf0pfmweo [ 3 ] ; tmp_m [ 9 ] = 36 ; tmp_i [ 36 ] = rtB . if52phrmag
[ 0 ] ; tmp_i [ 37 ] = rtB . if52phrmag [ 1 ] ; tmp_i [ 38 ] = rtB .
if52phrmag [ 2 ] ; tmp_i [ 39 ] = rtB . if52phrmag [ 3 ] ; tmp_m [ 10 ] = 40
; tmp_i [ 40 ] = rtB . mocddkrpki [ 0 ] ; tmp_i [ 41 ] = rtB . mocddkrpki [ 1
] ; tmp_i [ 42 ] = rtB . mocddkrpki [ 2 ] ; tmp_i [ 43 ] = rtB . mocddkrpki [
3 ] ; tmp_m [ 11 ] = 44 ; tmp_i [ 44 ] = rtB . kzwkda2ehh [ 0 ] ; tmp_i [ 45
] = rtB . kzwkda2ehh [ 1 ] ; tmp_i [ 46 ] = rtB . kzwkda2ehh [ 2 ] ; tmp_i [
47 ] = rtB . kzwkda2ehh [ 3 ] ; tmp_m [ 12 ] = 48 ; tmp_i [ 48 ] = rtB .
hmeg1w5jim [ 0 ] ; tmp_i [ 49 ] = rtB . hmeg1w5jim [ 1 ] ; tmp_i [ 50 ] = rtB
. hmeg1w5jim [ 2 ] ; tmp_i [ 51 ] = rtB . hmeg1w5jim [ 3 ] ; tmp_m [ 13 ] =
52 ; tmp_i [ 52 ] = rtB . nbocq1o42k [ 0 ] ; tmp_i [ 53 ] = rtB . nbocq1o42k
[ 1 ] ; tmp_i [ 54 ] = rtB . nbocq1o42k [ 2 ] ; tmp_i [ 55 ] = rtB .
nbocq1o42k [ 3 ] ; tmp_m [ 14 ] = 56 ; tmp_i [ 56 ] = rtB . d5a52isphm [ 0 ]
; tmp_i [ 57 ] = rtB . d5a52isphm [ 1 ] ; tmp_i [ 58 ] = rtB . d5a52isphm [ 2
] ; tmp_i [ 59 ] = rtB . d5a52isphm [ 3 ] ; tmp_m [ 15 ] = 60 ; tmp_i [ 60 ]
= rtB . icy3aei5aw [ 0 ] ; tmp_i [ 61 ] = rtB . icy3aei5aw [ 1 ] ; tmp_i [ 62
] = rtB . icy3aei5aw [ 2 ] ; tmp_i [ 63 ] = rtB . icy3aei5aw [ 3 ] ; tmp_m [
16 ] = 64 ; tmp_i [ 64 ] = rtB . add5kxxow3 [ 0 ] ; tmp_i [ 65 ] = rtB .
add5kxxow3 [ 1 ] ; tmp_i [ 66 ] = rtB . add5kxxow3 [ 2 ] ; tmp_i [ 67 ] = rtB
. add5kxxow3 [ 3 ] ; tmp_m [ 17 ] = 68 ; tmp_i [ 68 ] = rtB . oigl01ewmc [ 0
] ; tmp_i [ 69 ] = rtB . oigl01ewmc [ 1 ] ; tmp_i [ 70 ] = rtB . oigl01ewmc [
2 ] ; tmp_i [ 71 ] = rtB . oigl01ewmc [ 3 ] ; tmp_m [ 18 ] = 72 ; tmp_i [ 72
] = rtB . gja4dzl325 [ 0 ] ; tmp_i [ 73 ] = rtB . gja4dzl325 [ 1 ] ; tmp_i [
74 ] = rtB . gja4dzl325 [ 2 ] ; tmp_i [ 75 ] = rtB . gja4dzl325 [ 3 ] ; tmp_m
[ 19 ] = 76 ; simulationData -> mData -> mInputValues . mN = 76 ;
simulationData -> mData -> mInputValues . mX = & tmp_i [ 0 ] ; simulationData
-> mData -> mInputOffsets . mN = 20 ; simulationData -> mData ->
mInputOffsets . mX = & tmp_m [ 0 ] ; simulationData -> mData -> mOutputs . mN
= 43 ; simulationData -> mData -> mOutputs . mX = & rtB . blpo5iedij [ 0 ] ;
simulationData -> mData -> mSampleHits . mN = 0 ; simulationData -> mData ->
mSampleHits . mX = NULL ; simulationData -> mData -> mIsFundamentalSampleHit
= false ; diagnosticManager = ( NeuDiagnosticManager * ) rtDW . k13qfbrzod ;
diagnosticTree = neu_diagnostic_manager_get_initial_tree ( diagnosticManager
) ; i = ne_simulator_method ( ( NeslSimulator * ) rtDW . d3bbzrpbvx ,
NESL_SIM_OUTPUTS , simulationData , diagnosticManager ) ; if ( i != 0 ) { tmp
= error_buffer_is_empty ( ssGetErrorStatus ( rtS ) ) ; if ( tmp ) { msg =
rtw_diagnostics_msg ( diagnosticTree ) ; ssSetErrorStatus ( rtS , msg ) ; } }
oltitf3tj2 [ 0 ] = rtB . blpo5iedij [ 14 ] ; oltitf3tj2 [ 1 ] = rtB .
blpo5iedij [ 15 ] ; oltitf3tj2 [ 2 ] = rtB . blpo5iedij [ 16 ] ; oltitf3tj2 [
3 ] = rtB . blpo5iedij [ 8 ] ; oltitf3tj2 [ 4 ] = rtB . blpo5iedij [ 9 ] ;
oltitf3tj2 [ 5 ] = rtB . blpo5iedij [ 10 ] ; for ( i = 0 ; i < 6 ; i ++ ) {
bsoxugrlmu [ i ] = 0.0 ; for ( i_p = 0 ; i_p < 6 ; i_p ++ ) { bsoxugrlmu [ i
] += rtP . DampingForces_Gain [ 6 * i_p + i ] * oltitf3tj2 [ i_p ] ; } }
dkqw3o3vme ( rtP . WaveType_Value , & rtB . blpo5iedij [ 14 ] , & rtB .
blpo5iedij [ 8 ] , rtP . InitialZeroVelocity_Value , rtP .
ImpulseResponseFunctionK_Value , rtP . Timerelativetothecurrenttimestep_Value
, & rtB . arymfxlfvv , & rtDW . arymfxlfvv ) ; for ( i = 0 ; i < 6 ; i ++ ) {
rtB . hqtb5p5515 [ i ] = bsoxugrlmu [ i ] + rtB . arymfxlfvv . jmbenplned [ i
] ; } { real_T * * uBuffer = ( real_T * * ) & rtDW . ozvltbk2so .
TUbufferPtrs [ 0 ] ; real_T * * tBuffer = ( real_T * * ) & rtDW . ozvltbk2so
. TUbufferPtrs [ 6 ] ; real_T simTime = ssGetT ( rtS ) ; real_T tMinusDelay ;
{ int_T i1 ; real_T * y0 = & bsoxugrlmu [ 0 ] ; int_T * iw_Tail = & rtDW .
iie0k52gf2 . Tail [ 0 ] ; int_T * iw_Head = & rtDW . iie0k52gf2 . Head [ 0 ]
; int_T * iw_Last = & rtDW . iie0k52gf2 . Last [ 0 ] ; int_T *
iw_CircularBufSize = & rtDW . iie0k52gf2 . CircularBufSize [ 0 ] ; for ( i1 =
0 ; i1 < 3 ; i1 ++ ) { tMinusDelay = ( ( rtP . TransportDelay_Delay > 0.0 ) ?
rtP . TransportDelay_Delay : 0.0 ) ; tMinusDelay = simTime - tMinusDelay ; y0
[ i1 ] = rt_TDelayInterpolate ( tMinusDelay , 0.0 , * tBuffer , * uBuffer ,
iw_CircularBufSize [ i1 ] , & iw_Last [ i1 ] , iw_Tail [ i1 ] , iw_Head [ i1
] , rtP . TransportDelay_InitOutput , 0 , ( boolean_T ) ( ssIsMinorTimeStep (
rtS ) && ( ssGetTimeOfLastOutput ( rtS ) == ssGetT ( rtS ) ) ) ) ; tBuffer ++
; uBuffer ++ ; } y0 = & bsoxugrlmu [ 3 ] ; iw_Tail = & rtDW . iie0k52gf2 .
Tail [ 3 ] ; iw_Head = & rtDW . iie0k52gf2 . Head [ 3 ] ; iw_Last = & rtDW .
iie0k52gf2 . Last [ 3 ] ; iw_CircularBufSize = & rtDW . iie0k52gf2 .
CircularBufSize [ 3 ] ; for ( i1 = 0 ; i1 < 3 ; i1 ++ ) { tMinusDelay = ( (
rtP . TransportDelay_Delay > 0.0 ) ? rtP . TransportDelay_Delay : 0.0 ) ;
tMinusDelay = simTime - tMinusDelay ; y0 [ i1 ] = rt_TDelayInterpolate (
tMinusDelay , 0.0 , * tBuffer , * uBuffer , iw_CircularBufSize [ i1 ] , &
iw_Last [ i1 ] , iw_Tail [ i1 ] , iw_Head [ i1 ] , rtP .
TransportDelay_InitOutput , 0 , ( boolean_T ) ( ssIsMinorTimeStep ( rtS ) &&
( ssGetTimeOfLastOutput ( rtS ) == ssGetT ( rtS ) ) ) ) ; tBuffer ++ ;
uBuffer ++ ; } } } for ( i = 0 ; i < 6 ; i ++ ) { rtB . pnsa2f20mr [ i ] =
0.0 ; for ( i_p = 0 ; i_p < 6 ; i_p ++ ) { rtB . pnsa2f20mr [ i ] += rtP .
AddedMassForces_Gain [ 6 * i_p + i ] * bsoxugrlmu [ i_p ] ; } } if (
ssIsSampleHit ( rtS , 1 , 0 ) ) { for ( i = 0 ; i < 6 ; i ++ ) { rtB .
euxjdg3wyk [ i ] = rtP . DispforRotation1_Value [ i ] ; } rtB . euxjdg3wyk [
2 ] = rtP . Gravity_Value * rtP . GravityForce_Value - rtP . Density_Value *
rtP . Gravity1_Value * rtP . GravityForce1_Value ; } fkj5aod2nj ( & rtB .
blpo5iedij [ 4 ] , & rtB . nd0v2sbydt ) ; bsoxugrlmu [ 0 ] = rtB . blpo5iedij
[ 11 ] - rtP . CenterofGravity_Value [ 0 ] ; bsoxugrlmu [ 1 ] = rtB .
blpo5iedij [ 12 ] - rtP . CenterofGravity_Value [ 1 ] ; bsoxugrlmu [ 2 ] =
rtB . blpo5iedij [ 13 ] - rtP . CenterofGravity_Value [ 2 ] ; bsoxugrlmu [ 3
] = rtB . nd0v2sbydt . c0mvqybgil [ 0 ] - rtP . DispforRotation_Value [ 0 ] ;
bsoxugrlmu [ 4 ] = rtB . nd0v2sbydt . c0mvqybgil [ 1 ] - rtP .
DispforRotation_Value [ 1 ] ; bsoxugrlmu [ 5 ] = rtB . nd0v2sbydt .
c0mvqybgil [ 2 ] - rtP . DispforRotation_Value [ 2 ] ; for ( i = 0 ; i < 6 ;
i ++ ) { kdogumg1ub = 0.0 ; for ( i_p = 0 ; i_p < 6 ; i_p ++ ) { kdogumg1ub
+= rtP . RestoringForces_Gain [ 6 * i_p + i ] * bsoxugrlmu [ i_p ] ; } rtB .
dlr5ya0rha [ i ] = rtB . euxjdg3wyk [ i ] + kdogumg1ub ; } for ( i = 0 ; i <
6 ; i ++ ) { iq12q2ugfv [ i ] = oltitf3tj2 [ i ] * muDoubleScalarAbs (
oltitf3tj2 [ i ] ) ; } for ( i = 0 ; i < 6 ; i ++ ) { rtB . pr41rtecbf [ i ]
= 0.0 ; for ( i_p = 0 ; i_p < 6 ; i_p ++ ) { rtB . pr41rtecbf [ i ] += rtP .
ViscousDamping_Gain [ 6 * i_p + i ] * iq12q2ugfv [ i_p ] ; } rtB . merar43jbg
[ i ] = 0.0 ; for ( i_p = 0 ; i_p < 6 ; i_p ++ ) { rtB . merar43jbg [ i ] +=
rtP . LinearDamping_Gain [ 6 * i_p + i ] * oltitf3tj2 [ i_p ] ; } }
dbjtalp5d0 [ 0 ] = rtB . blpo5iedij [ 11 ] - rtP .
CenterofGravity_Value_kv4jtzv4sz [ 0 ] ; dbjtalp5d0 [ 1 ] = rtB . blpo5iedij
[ 12 ] - rtP . CenterofGravity_Value_kv4jtzv4sz [ 1 ] ; dbjtalp5d0 [ 2 ] =
rtB . blpo5iedij [ 13 ] - rtP . CenterofGravity_Value_kv4jtzv4sz [ 2 ] ;
dbjtalp5d0 [ 3 ] = rtB . nd0v2sbydt . c0mvqybgil [ 0 ] - rtP .
DispforRotation_Value_e2awq1sqk5 [ 0 ] ; dbjtalp5d0 [ 4 ] = rtB . nd0v2sbydt
. c0mvqybgil [ 1 ] - rtP . DispforRotation_Value_e2awq1sqk5 [ 1 ] ;
dbjtalp5d0 [ 5 ] = rtB . nd0v2sbydt . c0mvqybgil [ 2 ] - rtP .
DispforRotation_Value_e2awq1sqk5 [ 2 ] ; for ( i = 0 ; i < 6 ; i ++ ) { rtB .
ihnthpc5j1 [ i ] = ( rtP . MooringStiffness_Gain * dbjtalp5d0 [ i ] + rtP .
MooringDamping_Gain * oltitf3tj2 [ i ] ) - rtP . MooringPreTension_Value ; }
rtB . fyev0m4vsa = ssGetT ( rtS ) ; if ( ssIsMajorTimeStep ( rtS ) ) { if (
rtP . WaveType_Value_lnsink2wos < 20.0 ) { rtAction = 0 ; } else { rtAction =
1 ; } rtDW . gl2utjnv03 = rtAction ; } else { rtAction = rtDW . gl2utjnv03 ;
} switch ( rtAction ) { case 0 : fzybd15s0q ( rtS , bevdjak0ez , ( kwd4b3jpcn
* ) & rtP . fzybd15s0q0 ) ; if ( ssIsMajorTimeStep ( rtS ) ) { srUpdateBC (
rtDW . fzybd15s0q0 . gnrlcinhso ) ; } break ; case 1 : h02m5m2hej ( rtB .
fyev0m4vsa , bevdjak0ez , ( fi0awblwxy * ) & rtP . h02m5m2hejt ) ; if (
ssIsMajorTimeStep ( rtS ) ) { srUpdateBC ( rtDW . h02m5m2hejt . ljbrchkhk1 )
; } break ; } if ( ssIsMajorTimeStep ( rtS ) ) { if ( rtB . fyev0m4vsa < rtP
. RampFunctionTime_Value ) { rtAction = 0 ; } else { rtAction = 1 ; } rtDW .
mrlpfzs3wn = rtAction ; } else { rtAction = rtDW . mrlpfzs3wn ; } switch (
rtAction ) { case 0 : cnj3cuyx4u ( rtS , bevdjak0ez , rtB . dhfvei2wiq , (
djsc05xhw3 * ) & rtP . cnj3cuyx4ul ) ; if ( ssIsMajorTimeStep ( rtS ) ) {
srUpdateBC ( rtDW . cnj3cuyx4ul . cvx5ycrffh ) ; } break ; case 1 :
coaxej2udz ( bevdjak0ez , rtB . dhfvei2wiq ) ; if ( ssIsMajorTimeStep ( rtS )
) { srUpdateBC ( rtDW . coaxej2udzm . oqsczzj035 ) ; } break ; } for ( i = 0
; i < 6 ; i ++ ) { rtB . b1n5unk4di [ i ] = ( ( ( ( ( rtB . dhfvei2wiq [ i ]
- rtB . hqtb5p5515 [ i ] ) - rtB . pnsa2f20mr [ i ] ) - rtB . dlr5ya0rha [ i
] ) - rtB . pr41rtecbf [ i ] ) - rtB . merar43jbg [ i ] ) - rtB . ihnthpc5j1
[ i ] ; } rtB . p1qklr3iem [ 0 ] = rtB . b1n5unk4di [ 0 ] ; rtB . p1qklr3iem
[ 1 ] = 0.0 ; rtB . p1qklr3iem [ 2 ] = 0.0 ; rtB . p1qklr3iem [ 3 ] = 0.0 ;
rtB . dzcyvgjss1 [ 0 ] = rtB . b1n5unk4di [ 1 ] ; rtB . dzcyvgjss1 [ 1 ] =
0.0 ; rtB . dzcyvgjss1 [ 2 ] = 0.0 ; rtB . dzcyvgjss1 [ 3 ] = 0.0 ; rtB .
kyqswxndxu [ 0 ] = rtB . b1n5unk4di [ 2 ] ; rtB . kyqswxndxu [ 1 ] = 0.0 ;
rtB . kyqswxndxu [ 2 ] = 0.0 ; rtB . kyqswxndxu [ 3 ] = 0.0 ; rtB .
os0vmujie2 [ 0 ] = rtB . b1n5unk4di [ 3 ] ; rtB . os0vmujie2 [ 1 ] = 0.0 ;
rtB . os0vmujie2 [ 2 ] = 0.0 ; rtB . os0vmujie2 [ 3 ] = 0.0 ; rtB .
f5vdxtzttp [ 0 ] = rtB . b1n5unk4di [ 4 ] ; rtB . f5vdxtzttp [ 1 ] = 0.0 ;
rtB . f5vdxtzttp [ 2 ] = 0.0 ; rtB . f5vdxtzttp [ 3 ] = 0.0 ; rtB .
ny3ji5snoz [ 0 ] = rtB . b1n5unk4di [ 5 ] ; rtB . ny3ji5snoz [ 1 ] = 0.0 ;
rtB . ny3ji5snoz [ 2 ] = 0.0 ; rtB . ny3ji5snoz [ 3 ] = 0.0 ; dbjtalp5d0 [ 0
] = rtB . blpo5iedij [ 27 ] ; dbjtalp5d0 [ 1 ] = rtB . blpo5iedij [ 28 ] ;
dbjtalp5d0 [ 2 ] = rtB . blpo5iedij [ 29 ] ; dbjtalp5d0 [ 3 ] = rtB .
blpo5iedij [ 21 ] ; dbjtalp5d0 [ 4 ] = rtB . blpo5iedij [ 22 ] ; dbjtalp5d0 [
5 ] = rtB . blpo5iedij [ 23 ] ; for ( i = 0 ; i < 6 ; i ++ ) { bsoxugrlmu [ i
] = 0.0 ; for ( i_p = 0 ; i_p < 6 ; i_p ++ ) { bsoxugrlmu [ i ] += rtP .
DampingForces_Gain_gmglkqwyrk [ 6 * i_p + i ] * dbjtalp5d0 [ i_p ] ; } }
dkqw3o3vme ( rtP . WaveType_Value_brm2lvz52e , & rtB . blpo5iedij [ 27 ] , &
rtB . blpo5iedij [ 21 ] , rtP . InitialZeroVelocity_Value_mbg4rllwz5 , rtP .
ImpulseResponseFunctionK_Value_fjjrzbclsj , rtP .
Timerelativetothecurrenttimestep_Value_jpehs0wqht , & rtB . hbwafuhekh , &
rtDW . hbwafuhekh ) ; for ( i = 0 ; i < 6 ; i ++ ) { rtB . b3fkm4fcdn [ i ] =
bsoxugrlmu [ i ] + rtB . hbwafuhekh . jmbenplned [ i ] ; } { real_T * *
uBuffer = ( real_T * * ) & rtDW . fv3pugwi2m . TUbufferPtrs [ 0 ] ; real_T *
* tBuffer = ( real_T * * ) & rtDW . fv3pugwi2m . TUbufferPtrs [ 6 ] ; real_T
simTime = ssGetT ( rtS ) ; real_T tMinusDelay ; { int_T i1 ; real_T * y0 = &
bsoxugrlmu [ 0 ] ; int_T * iw_Tail = & rtDW . hxf5v0hxfq . Tail [ 0 ] ; int_T
* iw_Head = & rtDW . hxf5v0hxfq . Head [ 0 ] ; int_T * iw_Last = & rtDW .
hxf5v0hxfq . Last [ 0 ] ; int_T * iw_CircularBufSize = & rtDW . hxf5v0hxfq .
CircularBufSize [ 0 ] ; for ( i1 = 0 ; i1 < 3 ; i1 ++ ) { tMinusDelay = ( (
rtP . TransportDelay_Delay_bp43gzj5e3 > 0.0 ) ? rtP .
TransportDelay_Delay_bp43gzj5e3 : 0.0 ) ; tMinusDelay = simTime - tMinusDelay
; y0 [ i1 ] = rt_TDelayInterpolate ( tMinusDelay , 0.0 , * tBuffer , *
uBuffer , iw_CircularBufSize [ i1 ] , & iw_Last [ i1 ] , iw_Tail [ i1 ] ,
iw_Head [ i1 ] , rtP . TransportDelay_InitOutput_ii0y22uej3 , 0 , ( boolean_T
) ( ssIsMinorTimeStep ( rtS ) && ( ssGetTimeOfLastOutput ( rtS ) == ssGetT (
rtS ) ) ) ) ; tBuffer ++ ; uBuffer ++ ; } y0 = & bsoxugrlmu [ 3 ] ; iw_Tail =
& rtDW . hxf5v0hxfq . Tail [ 3 ] ; iw_Head = & rtDW . hxf5v0hxfq . Head [ 3 ]
; iw_Last = & rtDW . hxf5v0hxfq . Last [ 3 ] ; iw_CircularBufSize = & rtDW .
hxf5v0hxfq . CircularBufSize [ 3 ] ; for ( i1 = 0 ; i1 < 3 ; i1 ++ ) {
tMinusDelay = ( ( rtP . TransportDelay_Delay_bp43gzj5e3 > 0.0 ) ? rtP .
TransportDelay_Delay_bp43gzj5e3 : 0.0 ) ; tMinusDelay = simTime - tMinusDelay
; y0 [ i1 ] = rt_TDelayInterpolate ( tMinusDelay , 0.0 , * tBuffer , *
uBuffer , iw_CircularBufSize [ i1 ] , & iw_Last [ i1 ] , iw_Tail [ i1 ] ,
iw_Head [ i1 ] , rtP . TransportDelay_InitOutput_ii0y22uej3 , 0 , ( boolean_T
) ( ssIsMinorTimeStep ( rtS ) && ( ssGetTimeOfLastOutput ( rtS ) == ssGetT (
rtS ) ) ) ) ; tBuffer ++ ; uBuffer ++ ; } } } for ( i = 0 ; i < 6 ; i ++ ) {
rtB . jcuedl2jnj [ i ] = 0.0 ; for ( i_p = 0 ; i_p < 6 ; i_p ++ ) { rtB .
jcuedl2jnj [ i ] += rtP . AddedMassForces_Gain_oroqvzk1e4 [ 6 * i_p + i ] *
bsoxugrlmu [ i_p ] ; } } if ( ssIsSampleHit ( rtS , 1 , 0 ) ) { for ( i = 0 ;
i < 6 ; i ++ ) { rtB . o5jrwx140d [ i ] = rtP .
DispforRotation1_Value_o3itv5xzx4 [ i ] ; } rtB . o5jrwx140d [ 2 ] = rtP .
Gravity_Value_gftrulwsfn * rtP . GravityForce_Value_bwfmpxsvsr - rtP .
Density_Value_nszowylvmf * rtP . Gravity1_Value_gkp4y35w4n * rtP .
GravityForce1_Value_ipgtikjaun ; } fkj5aod2nj ( & rtB . blpo5iedij [ 17 ] , &
rtB . evtto0adau ) ; bsoxugrlmu [ 0 ] = rtB . blpo5iedij [ 24 ] - rtP .
CenterofGravity_Value_moatrz5qxk [ 0 ] ; bsoxugrlmu [ 1 ] = rtB . blpo5iedij
[ 25 ] - rtP . CenterofGravity_Value_moatrz5qxk [ 1 ] ; bsoxugrlmu [ 2 ] =
rtB . blpo5iedij [ 26 ] - rtP . CenterofGravity_Value_moatrz5qxk [ 2 ] ;
bsoxugrlmu [ 3 ] = rtB . evtto0adau . c0mvqybgil [ 0 ] - rtP .
DispforRotation_Value_ocikgyapyh [ 0 ] ; bsoxugrlmu [ 4 ] = rtB . evtto0adau
. c0mvqybgil [ 1 ] - rtP . DispforRotation_Value_ocikgyapyh [ 1 ] ;
bsoxugrlmu [ 5 ] = rtB . evtto0adau . c0mvqybgil [ 2 ] - rtP .
DispforRotation_Value_ocikgyapyh [ 2 ] ; for ( i = 0 ; i < 6 ; i ++ ) {
kdogumg1ub = 0.0 ; for ( i_p = 0 ; i_p < 6 ; i_p ++ ) { kdogumg1ub += rtP .
RestoringForces_Gain_cyy4gncipu [ 6 * i_p + i ] * bsoxugrlmu [ i_p ] ; } rtB
. ggc0r0fx3g [ i ] = rtB . o5jrwx140d [ i ] + kdogumg1ub ; } for ( i = 0 ; i
< 6 ; i ++ ) { bsoxugrlmu [ i ] = muDoubleScalarAbs ( dbjtalp5d0 [ i ] ) ;
bsoxugrlmu [ i ] *= dbjtalp5d0 [ i ] ; } for ( i = 0 ; i < 6 ; i ++ ) { rtB .
njnofax133 [ i ] = 0.0 ; for ( i_p = 0 ; i_p < 6 ; i_p ++ ) { rtB .
njnofax133 [ i ] += rtP . ViscousDamping_Gain_k1dk0v0wf1 [ 6 * i_p + i ] *
bsoxugrlmu [ i_p ] ; } rtB . amxl55ezpx [ i ] = 0.0 ; for ( i_p = 0 ; i_p < 6
; i_p ++ ) { rtB . amxl55ezpx [ i ] += rtP . LinearDamping_Gain_gt4kyc33is [
6 * i_p + i ] * dbjtalp5d0 [ i_p ] ; } } bsoxugrlmu [ 0 ] = rtB . blpo5iedij
[ 24 ] - rtP . CenterofGravity_Value_idcvji535z [ 0 ] ; bsoxugrlmu [ 1 ] =
rtB . blpo5iedij [ 25 ] - rtP . CenterofGravity_Value_idcvji535z [ 1 ] ;
bsoxugrlmu [ 2 ] = rtB . blpo5iedij [ 26 ] - rtP .
CenterofGravity_Value_idcvji535z [ 2 ] ; bsoxugrlmu [ 3 ] = rtB . evtto0adau
. c0mvqybgil [ 0 ] - rtP . DispforRotation_Value_ftba4kbp25 [ 0 ] ;
bsoxugrlmu [ 4 ] = rtB . evtto0adau . c0mvqybgil [ 1 ] - rtP .
DispforRotation_Value_ftba4kbp25 [ 1 ] ; bsoxugrlmu [ 5 ] = rtB . evtto0adau
. c0mvqybgil [ 2 ] - rtP . DispforRotation_Value_ftba4kbp25 [ 2 ] ; for ( i =
0 ; i < 6 ; i ++ ) { rtB . ihg0r14bhr [ i ] = ( rtP .
MooringStiffness_Gain_l3g4tznmmz * bsoxugrlmu [ i ] + rtP .
MooringDamping_Gain_loasej4jiy * dbjtalp5d0 [ i ] ) - rtP .
MooringPreTension_Value_n0e1y4yp2s ; } if ( ssIsMajorTimeStep ( rtS ) ) { if
( rtP . WaveType_Value_jdh1bnnh0l < 20.0 ) { rtAction = 0 ; } else { rtAction
= 1 ; } rtDW . dnkdbkqczp = rtAction ; } else { rtAction = rtDW . dnkdbkqczp
; } switch ( rtAction ) { case 0 : fzybd15s0q ( rtS , kmu1g2pi1e , (
kwd4b3jpcn * ) & rtP . h5j4mvdijc ) ; if ( ssIsMajorTimeStep ( rtS ) ) {
srUpdateBC ( rtDW . h5j4mvdijc . gnrlcinhso ) ; } break ; case 1 : h02m5m2hej
( rtB . fyev0m4vsa , kmu1g2pi1e , ( fi0awblwxy * ) & rtP . fkat0ywnxz ) ; if
( ssIsMajorTimeStep ( rtS ) ) { srUpdateBC ( rtDW . fkat0ywnxz . ljbrchkhk1 )
; } break ; } if ( ssIsMajorTimeStep ( rtS ) ) { if ( rtB . fyev0m4vsa < rtP
. RampFunctionTime_Value_mg4suvbwbg ) { rtAction = 0 ; } else { rtAction = 1
; } rtDW . kols4c4dg4 = rtAction ; } else { rtAction = rtDW . kols4c4dg4 ; }
switch ( rtAction ) { case 0 : cnj3cuyx4u ( rtS , kmu1g2pi1e , rtB .
pj144ebf30 , ( djsc05xhw3 * ) & rtP . msblmfssu1 ) ; if ( ssIsMajorTimeStep (
rtS ) ) { srUpdateBC ( rtDW . msblmfssu1 . cvx5ycrffh ) ; } break ; case 1 :
coaxej2udz ( kmu1g2pi1e , rtB . pj144ebf30 ) ; if ( ssIsMajorTimeStep ( rtS )
) { srUpdateBC ( rtDW . a1tdc130d3 . oqsczzj035 ) ; } break ; } for ( i = 0 ;
i < 6 ; i ++ ) { rtB . edopdfd1hm [ i ] = ( ( ( ( ( rtB . pj144ebf30 [ i ] -
rtB . b3fkm4fcdn [ i ] ) - rtB . jcuedl2jnj [ i ] ) - rtB . ggc0r0fx3g [ i ]
) - rtB . njnofax133 [ i ] ) - rtB . amxl55ezpx [ i ] ) - rtB . ihg0r14bhr [
i ] ; } rtB . kgii2iaa1l [ 0 ] = rtB . edopdfd1hm [ 0 ] ; rtB . kgii2iaa1l [
1 ] = 0.0 ; rtB . kgii2iaa1l [ 2 ] = 0.0 ; rtB . kgii2iaa1l [ 3 ] = 0.0 ; rtB
. jfce0w0ghr [ 0 ] = rtB . edopdfd1hm [ 1 ] ; rtB . jfce0w0ghr [ 1 ] = 0.0 ;
rtB . jfce0w0ghr [ 2 ] = 0.0 ; rtB . jfce0w0ghr [ 3 ] = 0.0 ; rtB .
pcf0pfmweo [ 0 ] = rtB . edopdfd1hm [ 2 ] ; rtB . pcf0pfmweo [ 1 ] = 0.0 ;
rtB . pcf0pfmweo [ 2 ] = 0.0 ; rtB . pcf0pfmweo [ 3 ] = 0.0 ; rtB .
if52phrmag [ 0 ] = rtB . edopdfd1hm [ 3 ] ; rtB . if52phrmag [ 1 ] = 0.0 ;
rtB . if52phrmag [ 2 ] = 0.0 ; rtB . if52phrmag [ 3 ] = 0.0 ; rtB .
mocddkrpki [ 0 ] = rtB . edopdfd1hm [ 4 ] ; rtB . mocddkrpki [ 1 ] = 0.0 ;
rtB . mocddkrpki [ 2 ] = 0.0 ; rtB . mocddkrpki [ 3 ] = 0.0 ; rtB .
kzwkda2ehh [ 0 ] = rtB . edopdfd1hm [ 5 ] ; rtB . kzwkda2ehh [ 1 ] = 0.0 ;
rtB . kzwkda2ehh [ 2 ] = 0.0 ; rtB . kzwkda2ehh [ 3 ] = 0.0 ; dbjtalp5d0 [ 0
] = rtB . blpo5iedij [ 40 ] ; dbjtalp5d0 [ 1 ] = rtB . blpo5iedij [ 41 ] ;
dbjtalp5d0 [ 2 ] = rtB . blpo5iedij [ 42 ] ; dbjtalp5d0 [ 3 ] = rtB .
blpo5iedij [ 34 ] ; dbjtalp5d0 [ 4 ] = rtB . blpo5iedij [ 35 ] ; dbjtalp5d0 [
5 ] = rtB . blpo5iedij [ 36 ] ; for ( i = 0 ; i < 6 ; i ++ ) { bsoxugrlmu [ i
] = 0.0 ; for ( i_p = 0 ; i_p < 6 ; i_p ++ ) { bsoxugrlmu [ i ] += rtP .
DampingForces_Gain_itl5dvfc3u [ 6 * i_p + i ] * dbjtalp5d0 [ i_p ] ; } }
dkqw3o3vme ( rtP . WaveType_Value_jkynzzqjsn , & rtB . blpo5iedij [ 40 ] , &
rtB . blpo5iedij [ 34 ] , rtP . InitialZeroVelocity_Value_gvmd2jy3st , rtP .
ImpulseResponseFunctionK_Value_i5uuouboea , rtP .
Timerelativetothecurrenttimestep_Value_kvgyp5pq4q , & rtB . ipyob4ujct , &
rtDW . ipyob4ujct ) ; for ( i = 0 ; i < 6 ; i ++ ) { rtB . e0ns1clddv [ i ] =
bsoxugrlmu [ i ] + rtB . ipyob4ujct . jmbenplned [ i ] ; } { real_T * *
uBuffer = ( real_T * * ) & rtDW . a1q2j3sqxq . TUbufferPtrs [ 0 ] ; real_T *
* tBuffer = ( real_T * * ) & rtDW . a1q2j3sqxq . TUbufferPtrs [ 6 ] ; real_T
simTime = ssGetT ( rtS ) ; real_T tMinusDelay ; { int_T i1 ; real_T * y0 = &
bsoxugrlmu [ 0 ] ; int_T * iw_Tail = & rtDW . nrayhafgyw . Tail [ 0 ] ; int_T
* iw_Head = & rtDW . nrayhafgyw . Head [ 0 ] ; int_T * iw_Last = & rtDW .
nrayhafgyw . Last [ 0 ] ; int_T * iw_CircularBufSize = & rtDW . nrayhafgyw .
CircularBufSize [ 0 ] ; for ( i1 = 0 ; i1 < 3 ; i1 ++ ) { tMinusDelay = ( (
rtP . TransportDelay_Delay_foibzxd41j > 0.0 ) ? rtP .
TransportDelay_Delay_foibzxd41j : 0.0 ) ; tMinusDelay = simTime - tMinusDelay
; y0 [ i1 ] = rt_TDelayInterpolate ( tMinusDelay , 0.0 , * tBuffer , *
uBuffer , iw_CircularBufSize [ i1 ] , & iw_Last [ i1 ] , iw_Tail [ i1 ] ,
iw_Head [ i1 ] , rtP . TransportDelay_InitOutput_bf1kxbkfem , 0 , ( boolean_T
) ( ssIsMinorTimeStep ( rtS ) && ( ssGetTimeOfLastOutput ( rtS ) == ssGetT (
rtS ) ) ) ) ; tBuffer ++ ; uBuffer ++ ; } y0 = & bsoxugrlmu [ 3 ] ; iw_Tail =
& rtDW . nrayhafgyw . Tail [ 3 ] ; iw_Head = & rtDW . nrayhafgyw . Head [ 3 ]
; iw_Last = & rtDW . nrayhafgyw . Last [ 3 ] ; iw_CircularBufSize = & rtDW .
nrayhafgyw . CircularBufSize [ 3 ] ; for ( i1 = 0 ; i1 < 3 ; i1 ++ ) {
tMinusDelay = ( ( rtP . TransportDelay_Delay_foibzxd41j > 0.0 ) ? rtP .
TransportDelay_Delay_foibzxd41j : 0.0 ) ; tMinusDelay = simTime - tMinusDelay
; y0 [ i1 ] = rt_TDelayInterpolate ( tMinusDelay , 0.0 , * tBuffer , *
uBuffer , iw_CircularBufSize [ i1 ] , & iw_Last [ i1 ] , iw_Tail [ i1 ] ,
iw_Head [ i1 ] , rtP . TransportDelay_InitOutput_bf1kxbkfem , 0 , ( boolean_T
) ( ssIsMinorTimeStep ( rtS ) && ( ssGetTimeOfLastOutput ( rtS ) == ssGetT (
rtS ) ) ) ) ; tBuffer ++ ; uBuffer ++ ; } } } for ( i = 0 ; i < 6 ; i ++ ) {
rtB . hdrzhitnck [ i ] = 0.0 ; for ( i_p = 0 ; i_p < 6 ; i_p ++ ) { rtB .
hdrzhitnck [ i ] += rtP . AddedMassForces_Gain_icvgvsh5ju [ 6 * i_p + i ] *
bsoxugrlmu [ i_p ] ; } } if ( ssIsSampleHit ( rtS , 1 , 0 ) ) { for ( i = 0 ;
i < 6 ; i ++ ) { rtB . lkgzajb1kd [ i ] = rtP .
DispforRotation1_Value_dhyoflxvyp [ i ] ; } rtB . lkgzajb1kd [ 2 ] = rtP .
Gravity_Value_cx40ikecyz * rtP . GravityForce_Value_nk3enkxm1g - rtP .
Density_Value_cwal0gh0jx * rtP . Gravity1_Value_jzzrqnwdx1 * rtP .
GravityForce1_Value_a3ipdgsubl ; } fkj5aod2nj ( & rtB . blpo5iedij [ 30 ] , &
rtB . iluwjccpxx ) ; bsoxugrlmu [ 0 ] = rtB . blpo5iedij [ 37 ] - rtP .
CenterofGravity_Value_ffrrlkfvt3 [ 0 ] ; bsoxugrlmu [ 1 ] = rtB . blpo5iedij
[ 38 ] - rtP . CenterofGravity_Value_ffrrlkfvt3 [ 1 ] ; bsoxugrlmu [ 2 ] =
rtB . blpo5iedij [ 39 ] - rtP . CenterofGravity_Value_ffrrlkfvt3 [ 2 ] ;
bsoxugrlmu [ 3 ] = rtB . iluwjccpxx . c0mvqybgil [ 0 ] - rtP .
DispforRotation_Value_dwwryftswo [ 0 ] ; bsoxugrlmu [ 4 ] = rtB . iluwjccpxx
. c0mvqybgil [ 1 ] - rtP . DispforRotation_Value_dwwryftswo [ 1 ] ;
bsoxugrlmu [ 5 ] = rtB . iluwjccpxx . c0mvqybgil [ 2 ] - rtP .
DispforRotation_Value_dwwryftswo [ 2 ] ; for ( i = 0 ; i < 6 ; i ++ ) {
kdogumg1ub = 0.0 ; for ( i_p = 0 ; i_p < 6 ; i_p ++ ) { kdogumg1ub += rtP .
RestoringForces_Gain_pooakzjpnq [ 6 * i_p + i ] * bsoxugrlmu [ i_p ] ; } rtB
. muoixesghk [ i ] = rtB . lkgzajb1kd [ i ] + kdogumg1ub ; } for ( i = 0 ; i
< 6 ; i ++ ) { bsoxugrlmu [ i ] = muDoubleScalarAbs ( dbjtalp5d0 [ i ] ) ;
bsoxugrlmu [ i ] *= dbjtalp5d0 [ i ] ; } for ( i = 0 ; i < 6 ; i ++ ) { rtB .
jeu1moqvun [ i ] = 0.0 ; for ( i_p = 0 ; i_p < 6 ; i_p ++ ) { rtB .
jeu1moqvun [ i ] += rtP . ViscousDamping_Gain_ibhby0wcea [ 6 * i_p + i ] *
bsoxugrlmu [ i_p ] ; } rtB . ialr351o51 [ i ] = 0.0 ; for ( i_p = 0 ; i_p < 6
; i_p ++ ) { rtB . ialr351o51 [ i ] += rtP . LinearDamping_Gain_f1vdp50wdd [
6 * i_p + i ] * dbjtalp5d0 [ i_p ] ; } } bsoxugrlmu [ 0 ] = rtB . blpo5iedij
[ 37 ] - rtP . CenterofGravity_Value_izurzrsyhp [ 0 ] ; bsoxugrlmu [ 1 ] =
rtB . blpo5iedij [ 38 ] - rtP . CenterofGravity_Value_izurzrsyhp [ 1 ] ;
bsoxugrlmu [ 2 ] = rtB . blpo5iedij [ 39 ] - rtP .
CenterofGravity_Value_izurzrsyhp [ 2 ] ; bsoxugrlmu [ 3 ] = rtB . iluwjccpxx
. c0mvqybgil [ 0 ] - rtP . DispforRotation_Value_md2plndz15 [ 0 ] ;
bsoxugrlmu [ 4 ] = rtB . iluwjccpxx . c0mvqybgil [ 1 ] - rtP .
DispforRotation_Value_md2plndz15 [ 1 ] ; bsoxugrlmu [ 5 ] = rtB . iluwjccpxx
. c0mvqybgil [ 2 ] - rtP . DispforRotation_Value_md2plndz15 [ 2 ] ; for ( i =
0 ; i < 6 ; i ++ ) { rtB . j4t0l5sh1l [ i ] = ( rtP .
MooringStiffness_Gain_ixw1h4sghu * bsoxugrlmu [ i ] + rtP .
MooringDamping_Gain_nkhqr3tbky * dbjtalp5d0 [ i ] ) - rtP .
MooringPreTension_Value_p53dhtwkd4 ; } if ( ssIsMajorTimeStep ( rtS ) ) { if
( rtP . WaveType_Value_cbd1s2tvax < 20.0 ) { rtAction = 0 ; } else { rtAction
= 1 ; } rtDW . gibqmcfn3a = rtAction ; } else { rtAction = rtDW . gibqmcfn3a
; } switch ( rtAction ) { case 0 : fzybd15s0q ( rtS , acwhwet23h , (
kwd4b3jpcn * ) & rtP . fmempv5ety ) ; if ( ssIsMajorTimeStep ( rtS ) ) {
srUpdateBC ( rtDW . fmempv5ety . gnrlcinhso ) ; } break ; case 1 : h02m5m2hej
( rtB . fyev0m4vsa , acwhwet23h , ( fi0awblwxy * ) & rtP . ogpjwh504b ) ; if
( ssIsMajorTimeStep ( rtS ) ) { srUpdateBC ( rtDW . ogpjwh504b . ljbrchkhk1 )
; } break ; } if ( ssIsMajorTimeStep ( rtS ) ) { if ( rtB . fyev0m4vsa < rtP
. RampFunctionTime_Value_mnlhvccsmd ) { rtAction = 0 ; } else { rtAction = 1
; } rtDW . ob5wky4wsa = rtAction ; } else { rtAction = rtDW . ob5wky4wsa ; }
switch ( rtAction ) { case 0 : cnj3cuyx4u ( rtS , acwhwet23h , rtB .
fnesyp43ae , ( djsc05xhw3 * ) & rtP . apfdt1mk1s ) ; if ( ssIsMajorTimeStep (
rtS ) ) { srUpdateBC ( rtDW . apfdt1mk1s . cvx5ycrffh ) ; } break ; case 1 :
coaxej2udz ( acwhwet23h , rtB . fnesyp43ae ) ; if ( ssIsMajorTimeStep ( rtS )
) { srUpdateBC ( rtDW . i00ohkzxv2 . oqsczzj035 ) ; } break ; } for ( i = 0 ;
i < 6 ; i ++ ) { rtB . okcf5s1hfi [ i ] = ( ( ( ( ( rtB . fnesyp43ae [ i ] -
rtB . e0ns1clddv [ i ] ) - rtB . hdrzhitnck [ i ] ) - rtB . muoixesghk [ i ]
) - rtB . jeu1moqvun [ i ] ) - rtB . ialr351o51 [ i ] ) - rtB . j4t0l5sh1l [
i ] ; } rtB . hmeg1w5jim [ 0 ] = rtB . okcf5s1hfi [ 0 ] ; rtB . hmeg1w5jim [
1 ] = 0.0 ; rtB . hmeg1w5jim [ 2 ] = 0.0 ; rtB . hmeg1w5jim [ 3 ] = 0.0 ; rtB
. nbocq1o42k [ 0 ] = rtB . okcf5s1hfi [ 1 ] ; rtB . nbocq1o42k [ 1 ] = 0.0 ;
rtB . nbocq1o42k [ 2 ] = 0.0 ; rtB . nbocq1o42k [ 3 ] = 0.0 ; rtB .
d5a52isphm [ 0 ] = rtB . okcf5s1hfi [ 2 ] ; rtB . d5a52isphm [ 1 ] = 0.0 ;
rtB . d5a52isphm [ 2 ] = 0.0 ; rtB . d5a52isphm [ 3 ] = 0.0 ; rtB .
icy3aei5aw [ 0 ] = rtB . okcf5s1hfi [ 3 ] ; rtB . icy3aei5aw [ 1 ] = 0.0 ;
rtB . icy3aei5aw [ 2 ] = 0.0 ; rtB . icy3aei5aw [ 3 ] = 0.0 ; rtB .
add5kxxow3 [ 0 ] = rtB . okcf5s1hfi [ 4 ] ; rtB . add5kxxow3 [ 1 ] = 0.0 ;
rtB . add5kxxow3 [ 2 ] = 0.0 ; rtB . add5kxxow3 [ 3 ] = 0.0 ; rtB .
oigl01ewmc [ 0 ] = rtB . okcf5s1hfi [ 5 ] ; rtB . oigl01ewmc [ 1 ] = 0.0 ;
rtB . oigl01ewmc [ 2 ] = 0.0 ; rtB . oigl01ewmc [ 3 ] = 0.0 ; simulationData
= ( NeslSimulationData * ) rtDW . mzt5dujgnf ; time_e = ssGetT ( rtS ) ;
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
rtB . p1qklr3iem [ 0 ] ; tmp_g [ 1 ] = rtB . p1qklr3iem [ 1 ] ; tmp_g [ 2 ] =
rtB . p1qklr3iem [ 2 ] ; tmp_g [ 3 ] = rtB . p1qklr3iem [ 3 ] ; tmp_j [ 1 ] =
4 ; tmp_g [ 4 ] = rtB . dzcyvgjss1 [ 0 ] ; tmp_g [ 5 ] = rtB . dzcyvgjss1 [ 1
] ; tmp_g [ 6 ] = rtB . dzcyvgjss1 [ 2 ] ; tmp_g [ 7 ] = rtB . dzcyvgjss1 [ 3
] ; tmp_j [ 2 ] = 8 ; tmp_g [ 8 ] = rtB . kyqswxndxu [ 0 ] ; tmp_g [ 9 ] =
rtB . kyqswxndxu [ 1 ] ; tmp_g [ 10 ] = rtB . kyqswxndxu [ 2 ] ; tmp_g [ 11 ]
= rtB . kyqswxndxu [ 3 ] ; tmp_j [ 3 ] = 12 ; tmp_g [ 12 ] = rtB . os0vmujie2
[ 0 ] ; tmp_g [ 13 ] = rtB . os0vmujie2 [ 1 ] ; tmp_g [ 14 ] = rtB .
os0vmujie2 [ 2 ] ; tmp_g [ 15 ] = rtB . os0vmujie2 [ 3 ] ; tmp_j [ 4 ] = 16 ;
tmp_g [ 16 ] = rtB . f5vdxtzttp [ 0 ] ; tmp_g [ 17 ] = rtB . f5vdxtzttp [ 1 ]
; tmp_g [ 18 ] = rtB . f5vdxtzttp [ 2 ] ; tmp_g [ 19 ] = rtB . f5vdxtzttp [ 3
] ; tmp_j [ 5 ] = 20 ; tmp_g [ 20 ] = rtB . ny3ji5snoz [ 0 ] ; tmp_g [ 21 ] =
rtB . ny3ji5snoz [ 1 ] ; tmp_g [ 22 ] = rtB . ny3ji5snoz [ 2 ] ; tmp_g [ 23 ]
= rtB . ny3ji5snoz [ 3 ] ; tmp_j [ 6 ] = 24 ; tmp_g [ 24 ] = rtB . kgii2iaa1l
[ 0 ] ; tmp_g [ 25 ] = rtB . kgii2iaa1l [ 1 ] ; tmp_g [ 26 ] = rtB .
kgii2iaa1l [ 2 ] ; tmp_g [ 27 ] = rtB . kgii2iaa1l [ 3 ] ; tmp_j [ 7 ] = 28 ;
tmp_g [ 28 ] = rtB . jfce0w0ghr [ 0 ] ; tmp_g [ 29 ] = rtB . jfce0w0ghr [ 1 ]
; tmp_g [ 30 ] = rtB . jfce0w0ghr [ 2 ] ; tmp_g [ 31 ] = rtB . jfce0w0ghr [ 3
] ; tmp_j [ 8 ] = 32 ; tmp_g [ 32 ] = rtB . pcf0pfmweo [ 0 ] ; tmp_g [ 33 ] =
rtB . pcf0pfmweo [ 1 ] ; tmp_g [ 34 ] = rtB . pcf0pfmweo [ 2 ] ; tmp_g [ 35 ]
= rtB . pcf0pfmweo [ 3 ] ; tmp_j [ 9 ] = 36 ; tmp_g [ 36 ] = rtB . if52phrmag
[ 0 ] ; tmp_g [ 37 ] = rtB . if52phrmag [ 1 ] ; tmp_g [ 38 ] = rtB .
if52phrmag [ 2 ] ; tmp_g [ 39 ] = rtB . if52phrmag [ 3 ] ; tmp_j [ 10 ] = 40
; tmp_g [ 40 ] = rtB . mocddkrpki [ 0 ] ; tmp_g [ 41 ] = rtB . mocddkrpki [ 1
] ; tmp_g [ 42 ] = rtB . mocddkrpki [ 2 ] ; tmp_g [ 43 ] = rtB . mocddkrpki [
3 ] ; tmp_j [ 11 ] = 44 ; tmp_g [ 44 ] = rtB . kzwkda2ehh [ 0 ] ; tmp_g [ 45
] = rtB . kzwkda2ehh [ 1 ] ; tmp_g [ 46 ] = rtB . kzwkda2ehh [ 2 ] ; tmp_g [
47 ] = rtB . kzwkda2ehh [ 3 ] ; tmp_j [ 12 ] = 48 ; tmp_g [ 48 ] = rtB .
hmeg1w5jim [ 0 ] ; tmp_g [ 49 ] = rtB . hmeg1w5jim [ 1 ] ; tmp_g [ 50 ] = rtB
. hmeg1w5jim [ 2 ] ; tmp_g [ 51 ] = rtB . hmeg1w5jim [ 3 ] ; tmp_j [ 13 ] =
52 ; tmp_g [ 52 ] = rtB . nbocq1o42k [ 0 ] ; tmp_g [ 53 ] = rtB . nbocq1o42k
[ 1 ] ; tmp_g [ 54 ] = rtB . nbocq1o42k [ 2 ] ; tmp_g [ 55 ] = rtB .
nbocq1o42k [ 3 ] ; tmp_j [ 14 ] = 56 ; tmp_g [ 56 ] = rtB . d5a52isphm [ 0 ]
; tmp_g [ 57 ] = rtB . d5a52isphm [ 1 ] ; tmp_g [ 58 ] = rtB . d5a52isphm [ 2
] ; tmp_g [ 59 ] = rtB . d5a52isphm [ 3 ] ; tmp_j [ 15 ] = 60 ; tmp_g [ 60 ]
= rtB . icy3aei5aw [ 0 ] ; tmp_g [ 61 ] = rtB . icy3aei5aw [ 1 ] ; tmp_g [ 62
] = rtB . icy3aei5aw [ 2 ] ; tmp_g [ 63 ] = rtB . icy3aei5aw [ 3 ] ; tmp_j [
16 ] = 64 ; tmp_g [ 64 ] = rtB . add5kxxow3 [ 0 ] ; tmp_g [ 65 ] = rtB .
add5kxxow3 [ 1 ] ; tmp_g [ 66 ] = rtB . add5kxxow3 [ 2 ] ; tmp_g [ 67 ] = rtB
. add5kxxow3 [ 3 ] ; tmp_j [ 17 ] = 68 ; tmp_g [ 68 ] = rtB . oigl01ewmc [ 0
] ; tmp_g [ 69 ] = rtB . oigl01ewmc [ 1 ] ; tmp_g [ 70 ] = rtB . oigl01ewmc [
2 ] ; tmp_g [ 71 ] = rtB . oigl01ewmc [ 3 ] ; tmp_j [ 18 ] = 72 ; tmp_g [ 72
] = rtB . gja4dzl325 [ 0 ] ; tmp_g [ 73 ] = rtB . gja4dzl325 [ 1 ] ; tmp_g [
74 ] = rtB . gja4dzl325 [ 2 ] ; tmp_g [ 75 ] = rtB . gja4dzl325 [ 3 ] ; tmp_j
[ 19 ] = 76 ; simulationData -> mData -> mInputValues . mN = 76 ;
simulationData -> mData -> mInputValues . mX = & tmp_g [ 0 ] ; simulationData
-> mData -> mInputOffsets . mN = 20 ; simulationData -> mData ->
mInputOffsets . mX = & tmp_j [ 0 ] ; simulationData -> mData -> mOutputs . mN
= 36 ; simulationData -> mData -> mOutputs . mX = & rtB . l5ibfslonp [ 0 ] ;
simulationData -> mData -> mSampleHits . mN = 0 ; simulationData -> mData ->
mSampleHits . mX = NULL ; simulationData -> mData -> mIsFundamentalSampleHit
= false ; diagnosticManager = ( NeuDiagnosticManager * ) rtDW . hmwzsbnven ;
diagnosticTree = neu_diagnostic_manager_get_initial_tree ( diagnosticManager
) ; i = ne_simulator_method ( ( NeslSimulator * ) rtDW . kac3j5zyhm ,
NESL_SIM_OUTPUTS , simulationData , diagnosticManager ) ; if ( i != 0 ) { tmp
= error_buffer_is_empty ( ssGetErrorStatus ( rtS ) ) ; if ( tmp ) { msg =
rtw_diagnostics_msg ( diagnosticTree ) ; ssSetErrorStatus ( rtS , msg ) ; } }
if ( ssIsSampleHit ( rtS , 1 , 0 ) ) { rtB . ejgnutoxk4 [ 0 ] = rtB .
l5ibfslonp [ 3 ] ; rtB . ejgnutoxk4 [ 1 ] = rtB . l5ibfslonp [ 4 ] ; rtB .
ejgnutoxk4 [ 2 ] = rtB . l5ibfslonp [ 5 ] ; rtB . ejgnutoxk4 [ 3 ] = rtB .
l5ibfslonp [ 0 ] ; rtB . ejgnutoxk4 [ 4 ] = rtB . l5ibfslonp [ 1 ] ; rtB .
ejgnutoxk4 [ 5 ] = rtB . l5ibfslonp [ 2 ] ; { double locTime = ssGetTaskTime
( rtS , 1 ) ; if ( ssGetLogOutput ( rtS ) ) { rt_UpdateStructLogVar ( (
StructLogVar * ) rtDW . facajaxtwh . LoggedData , & locTime , & rtB .
ejgnutoxk4 [ 0 ] ) ; } } rtB . cdoh40kylx [ 0 ] = rtB . blpo5iedij [ 11 ] ;
rtB . cdoh40kylx [ 1 ] = rtB . blpo5iedij [ 12 ] ; rtB . cdoh40kylx [ 2 ] =
rtB . blpo5iedij [ 13 ] ; rtB . cdoh40kylx [ 3 ] = rtB . nd0v2sbydt .
c0mvqybgil [ 0 ] ; rtB . cdoh40kylx [ 4 ] = rtB . nd0v2sbydt . c0mvqybgil [ 1
] ; rtB . cdoh40kylx [ 5 ] = rtB . nd0v2sbydt . c0mvqybgil [ 2 ] ; rtB .
cdoh40kylx [ 6 ] = rtB . blpo5iedij [ 14 ] ; rtB . cdoh40kylx [ 7 ] = rtB .
blpo5iedij [ 15 ] ; rtB . cdoh40kylx [ 8 ] = rtB . blpo5iedij [ 16 ] ; rtB .
cdoh40kylx [ 9 ] = rtB . blpo5iedij [ 8 ] ; rtB . cdoh40kylx [ 10 ] = rtB .
blpo5iedij [ 9 ] ; rtB . cdoh40kylx [ 11 ] = rtB . blpo5iedij [ 10 ] ; rtB .
cdoh40kylx [ 12 ] = rtB . l5ibfslonp [ 21 ] ; rtB . cdoh40kylx [ 13 ] = rtB .
l5ibfslonp [ 22 ] ; rtB . cdoh40kylx [ 14 ] = rtB . l5ibfslonp [ 23 ] ; rtB .
cdoh40kylx [ 15 ] = rtB . l5ibfslonp [ 18 ] ; rtB . cdoh40kylx [ 16 ] = rtB .
l5ibfslonp [ 19 ] ; rtB . cdoh40kylx [ 17 ] = rtB . l5ibfslonp [ 20 ] ; for (
i = 0 ; i < 6 ; i ++ ) { rtB . cdoh40kylx [ i + 18 ] = rtB . b1n5unk4di [ i ]
; } for ( i = 0 ; i < 6 ; i ++ ) { rtB . cdoh40kylx [ i + 24 ] = rtB .
dhfvei2wiq [ i ] ; } for ( i = 0 ; i < 6 ; i ++ ) { rtB . cdoh40kylx [ i + 30
] = rtB . hqtb5p5515 [ i ] ; } for ( i = 0 ; i < 6 ; i ++ ) { rtB .
cdoh40kylx [ i + 36 ] = rtB . pnsa2f20mr [ i ] ; } for ( i = 0 ; i < 6 ; i ++
) { rtB . cdoh40kylx [ i + 42 ] = rtB . dlr5ya0rha [ i ] ; } for ( i = 0 ; i
< 6 ; i ++ ) { rtB . cdoh40kylx [ i + 48 ] = rtB . pr41rtecbf [ i ] ; } for (
i = 0 ; i < 6 ; i ++ ) { rtB . cdoh40kylx [ i + 54 ] = rtB . ihnthpc5j1 [ i ]
; } for ( i = 0 ; i < 6 ; i ++ ) { rtB . cdoh40kylx [ i + 60 ] = rtB .
merar43jbg [ i ] ; } { double locTime = ssGetTaskTime ( rtS , 1 ) ; if (
ssGetLogOutput ( rtS ) ) { rt_UpdateStructLogVar ( ( StructLogVar * ) rtDW .
ea2glvbgz2 . LoggedData , & locTime , & rtB . cdoh40kylx [ 0 ] ) ; } } rtB .
c4gqqn41jy [ 0 ] = rtB . blpo5iedij [ 24 ] ; rtB . c4gqqn41jy [ 1 ] = rtB .
blpo5iedij [ 25 ] ; rtB . c4gqqn41jy [ 2 ] = rtB . blpo5iedij [ 26 ] ; rtB .
c4gqqn41jy [ 3 ] = rtB . evtto0adau . c0mvqybgil [ 0 ] ; rtB . c4gqqn41jy [ 4
] = rtB . evtto0adau . c0mvqybgil [ 1 ] ; rtB . c4gqqn41jy [ 5 ] = rtB .
evtto0adau . c0mvqybgil [ 2 ] ; rtB . c4gqqn41jy [ 6 ] = rtB . blpo5iedij [
27 ] ; rtB . c4gqqn41jy [ 7 ] = rtB . blpo5iedij [ 28 ] ; rtB . c4gqqn41jy [
8 ] = rtB . blpo5iedij [ 29 ] ; rtB . c4gqqn41jy [ 9 ] = rtB . blpo5iedij [
21 ] ; rtB . c4gqqn41jy [ 10 ] = rtB . blpo5iedij [ 22 ] ; rtB . c4gqqn41jy [
11 ] = rtB . blpo5iedij [ 23 ] ; rtB . c4gqqn41jy [ 12 ] = rtB . l5ibfslonp [
27 ] ; rtB . c4gqqn41jy [ 13 ] = rtB . l5ibfslonp [ 28 ] ; rtB . c4gqqn41jy [
14 ] = rtB . l5ibfslonp [ 29 ] ; rtB . c4gqqn41jy [ 15 ] = rtB . l5ibfslonp [
24 ] ; rtB . c4gqqn41jy [ 16 ] = rtB . l5ibfslonp [ 25 ] ; rtB . c4gqqn41jy [
17 ] = rtB . l5ibfslonp [ 26 ] ; for ( i = 0 ; i < 6 ; i ++ ) { rtB .
c4gqqn41jy [ i + 18 ] = rtB . edopdfd1hm [ i ] ; } for ( i = 0 ; i < 6 ; i ++
) { rtB . c4gqqn41jy [ i + 24 ] = rtB . pj144ebf30 [ i ] ; } for ( i = 0 ; i
< 6 ; i ++ ) { rtB . c4gqqn41jy [ i + 30 ] = rtB . b3fkm4fcdn [ i ] ; } for (
i = 0 ; i < 6 ; i ++ ) { rtB . c4gqqn41jy [ i + 36 ] = rtB . jcuedl2jnj [ i ]
; } for ( i = 0 ; i < 6 ; i ++ ) { rtB . c4gqqn41jy [ i + 42 ] = rtB .
ggc0r0fx3g [ i ] ; } for ( i = 0 ; i < 6 ; i ++ ) { rtB . c4gqqn41jy [ i + 48
] = rtB . njnofax133 [ i ] ; } for ( i = 0 ; i < 6 ; i ++ ) { rtB .
c4gqqn41jy [ i + 54 ] = rtB . ihg0r14bhr [ i ] ; } for ( i = 0 ; i < 6 ; i ++
) { rtB . c4gqqn41jy [ i + 60 ] = rtB . amxl55ezpx [ i ] ; } { double locTime
= ssGetTaskTime ( rtS , 1 ) ; if ( ssGetLogOutput ( rtS ) ) {
rt_UpdateStructLogVar ( ( StructLogVar * ) rtDW . fb5d5dwuih . LoggedData , &
locTime , & rtB . c4gqqn41jy [ 0 ] ) ; } } rtB . mhluogc5lp [ 0 ] = rtB .
blpo5iedij [ 37 ] ; rtB . mhluogc5lp [ 1 ] = rtB . blpo5iedij [ 38 ] ; rtB .
mhluogc5lp [ 2 ] = rtB . blpo5iedij [ 39 ] ; rtB . mhluogc5lp [ 3 ] = rtB .
iluwjccpxx . c0mvqybgil [ 0 ] ; rtB . mhluogc5lp [ 4 ] = rtB . iluwjccpxx .
c0mvqybgil [ 1 ] ; rtB . mhluogc5lp [ 5 ] = rtB . iluwjccpxx . c0mvqybgil [ 2
] ; rtB . mhluogc5lp [ 6 ] = rtB . blpo5iedij [ 40 ] ; rtB . mhluogc5lp [ 7 ]
= rtB . blpo5iedij [ 41 ] ; rtB . mhluogc5lp [ 8 ] = rtB . blpo5iedij [ 42 ]
; rtB . mhluogc5lp [ 9 ] = rtB . blpo5iedij [ 34 ] ; rtB . mhluogc5lp [ 10 ]
= rtB . blpo5iedij [ 35 ] ; rtB . mhluogc5lp [ 11 ] = rtB . blpo5iedij [ 36 ]
; rtB . mhluogc5lp [ 12 ] = rtB . l5ibfslonp [ 33 ] ; rtB . mhluogc5lp [ 13 ]
= rtB . l5ibfslonp [ 34 ] ; rtB . mhluogc5lp [ 14 ] = rtB . l5ibfslonp [ 35 ]
; rtB . mhluogc5lp [ 15 ] = rtB . l5ibfslonp [ 30 ] ; rtB . mhluogc5lp [ 16 ]
= rtB . l5ibfslonp [ 31 ] ; rtB . mhluogc5lp [ 17 ] = rtB . l5ibfslonp [ 32 ]
; for ( i = 0 ; i < 6 ; i ++ ) { rtB . mhluogc5lp [ i + 18 ] = rtB .
okcf5s1hfi [ i ] ; } for ( i = 0 ; i < 6 ; i ++ ) { rtB . mhluogc5lp [ i + 24
] = rtB . fnesyp43ae [ i ] ; } for ( i = 0 ; i < 6 ; i ++ ) { rtB .
mhluogc5lp [ i + 30 ] = rtB . e0ns1clddv [ i ] ; } for ( i = 0 ; i < 6 ; i ++
) { rtB . mhluogc5lp [ i + 36 ] = rtB . hdrzhitnck [ i ] ; } for ( i = 0 ; i
< 6 ; i ++ ) { rtB . mhluogc5lp [ i + 42 ] = rtB . muoixesghk [ i ] ; } for (
i = 0 ; i < 6 ; i ++ ) { rtB . mhluogc5lp [ i + 48 ] = rtB . jeu1moqvun [ i ]
; } for ( i = 0 ; i < 6 ; i ++ ) { rtB . mhluogc5lp [ i + 54 ] = rtB .
j4t0l5sh1l [ i ] ; } for ( i = 0 ; i < 6 ; i ++ ) { rtB . mhluogc5lp [ i + 60
] = rtB . ialr351o51 [ i ] ; } { double locTime = ssGetTaskTime ( rtS , 1 ) ;
if ( ssGetLogOutput ( rtS ) ) { rt_UpdateStructLogVar ( ( StructLogVar * )
rtDW . pztby5tdmg . LoggedData , & locTime , & rtB . mhluogc5lp [ 0 ] ) ; } }
} kdogumg1ub = rtP . Gain3_Gain * rtB . blpo5iedij [ 0 ] ; mddlqmjh41 = rtP .
Gain2_Gain * rtB . blpo5iedij [ 1 ] ; rtB . miwvnyxkwg = kdogumg1ub * rtP .
PCCStiffnessCoefficient_Value + rtP . PCCDampingCoefficient_Value *
mddlqmjh41 ; rtB . gdetjhzpld = mddlqmjh41 * mddlqmjh41 * rtP .
PCCDampingCoefficient_Value ; rtB . pr2wmuatwp [ 0 ] = rtB . l5ibfslonp [ 9 ]
; rtB . pr2wmuatwp [ 1 ] = rtB . l5ibfslonp [ 11 ] ; rtB . pr2wmuatwp [ 2 ] =
rtB . l5ibfslonp [ 10 ] ; kdogumg1ub = rtP . Gain1_Gain * rtB . l5ibfslonp [
11 ] ; rtB . pr2wmuatwp [ 1 ] = kdogumg1ub ; rtB . euklvqzjnb [ 0 ] = rtB .
l5ibfslonp [ 6 ] ; rtB . euklvqzjnb [ 1 ] = rtB . l5ibfslonp [ 8 ] ; rtB .
euklvqzjnb [ 2 ] = rtB . l5ibfslonp [ 7 ] ; kdogumg1ub = rtP . Gain_Gain *
rtB . l5ibfslonp [ 8 ] ; rtB . euklvqzjnb [ 1 ] = kdogumg1ub ; if (
ssIsSampleHit ( rtS , 1 , 0 ) ) { rtB . hflxw2u4c0 [ 0 ] = rtB . miwvnyxkwg ;
rtB . hflxw2u4c0 [ 1 ] = rtB . gdetjhzpld ; rtB . hflxw2u4c0 [ 2 ] = rtB .
pr2wmuatwp [ 0 ] ; rtB . hflxw2u4c0 [ 3 ] = rtB . pr2wmuatwp [ 1 ] ; rtB .
hflxw2u4c0 [ 4 ] = rtB . pr2wmuatwp [ 2 ] ; rtB . hflxw2u4c0 [ 5 ] = rtB .
euklvqzjnb [ 0 ] ; rtB . hflxw2u4c0 [ 6 ] = rtB . euklvqzjnb [ 1 ] ; rtB .
hflxw2u4c0 [ 7 ] = rtB . euklvqzjnb [ 2 ] ; { double locTime = ssGetTaskTime
( rtS , 1 ) ; if ( ssGetLogOutput ( rtS ) ) { rt_UpdateStructLogVar ( (
StructLogVar * ) rtDW . o3l54yb1i3 . LoggedData , & locTime , & rtB .
hflxw2u4c0 [ 0 ] ) ; } } } kdogumg1ub = rtP . Gain3_Gain_nxxgw4dkhx * rtB .
blpo5iedij [ 2 ] ; mddlqmjh41 = rtP . Gain2_Gain_kgiq1thyom * rtB .
blpo5iedij [ 3 ] ; rtB . l2wrpxekcz = kdogumg1ub * rtP .
PCCStiffnessCoefficient_Value_bq4hxfosr4 + rtP .
PCCDampingCoefficient_Value_p0lvrll2jb * mddlqmjh41 ; rtB . jcjac2h4yl =
mddlqmjh41 * mddlqmjh41 * rtP . PCCDampingCoefficient_Value_p0lvrll2jb ; rtB
. g5gg5rwfxi [ 0 ] = rtB . l5ibfslonp [ 15 ] ; rtB . g5gg5rwfxi [ 1 ] = rtB .
l5ibfslonp [ 17 ] ; rtB . g5gg5rwfxi [ 2 ] = rtB . l5ibfslonp [ 16 ] ;
kdogumg1ub = rtP . Gain1_Gain_nupg4bxvwd * rtB . l5ibfslonp [ 17 ] ; rtB .
g5gg5rwfxi [ 1 ] = kdogumg1ub ; rtB . mb24q41lpq [ 0 ] = rtB . l5ibfslonp [
12 ] ; rtB . mb24q41lpq [ 1 ] = rtB . l5ibfslonp [ 14 ] ; rtB . mb24q41lpq [
2 ] = rtB . l5ibfslonp [ 13 ] ; kdogumg1ub = rtP . Gain_Gain_crbn4vzgqb * rtB
. l5ibfslonp [ 14 ] ; rtB . mb24q41lpq [ 1 ] = kdogumg1ub ; if (
ssIsSampleHit ( rtS , 1 , 0 ) ) { rtB . kzugd0mwbk [ 0 ] = rtB . l2wrpxekcz ;
rtB . kzugd0mwbk [ 1 ] = rtB . jcjac2h4yl ; rtB . kzugd0mwbk [ 2 ] = rtB .
g5gg5rwfxi [ 0 ] ; rtB . kzugd0mwbk [ 3 ] = rtB . g5gg5rwfxi [ 1 ] ; rtB .
kzugd0mwbk [ 4 ] = rtB . g5gg5rwfxi [ 2 ] ; rtB . kzugd0mwbk [ 5 ] = rtB .
mb24q41lpq [ 0 ] ; rtB . kzugd0mwbk [ 6 ] = rtB . mb24q41lpq [ 1 ] ; rtB .
kzugd0mwbk [ 7 ] = rtB . mb24q41lpq [ 2 ] ; { double locTime = ssGetTaskTime
( rtS , 1 ) ; if ( ssGetLogOutput ( rtS ) ) { rt_UpdateStructLogVar ( (
StructLogVar * ) rtDW . lvjvwmkulx . LoggedData , & locTime , & rtB .
kzugd0mwbk [ 0 ] ) ; } } } UNUSED_PARAMETER ( tid ) ; } void MdlUpdate (
int_T tid ) { { real_T * * uBuffer = ( real_T * * ) & rtDW . ozvltbk2so .
TUbufferPtrs [ 0 ] ; real_T * * tBuffer = ( real_T * * ) & rtDW . ozvltbk2so
. TUbufferPtrs [ 6 ] ; real_T simTime = ssGetT ( rtS ) ; rtDW . iie0k52gf2 .
Head [ 0 ] = ( ( rtDW . iie0k52gf2 . Head [ 0 ] < ( rtDW . iie0k52gf2 .
CircularBufSize [ 0 ] - 1 ) ) ? ( rtDW . iie0k52gf2 . Head [ 0 ] + 1 ) : 0 )
; if ( rtDW . iie0k52gf2 . Head [ 0 ] == rtDW . iie0k52gf2 . Tail [ 0 ] ) {
if ( ! rt_TDelayUpdateTailOrGrowBuf ( & rtDW . iie0k52gf2 . CircularBufSize [
0 ] , & rtDW . iie0k52gf2 . Tail [ 0 ] , & rtDW . iie0k52gf2 . Head [ 0 ] , &
rtDW . iie0k52gf2 . Last [ 0 ] , simTime - rtP . TransportDelay_Delay ,
tBuffer , uBuffer , ( NULL ) , ( boolean_T ) 0 , false , & rtDW . iie0k52gf2
. MaxNewBufSize ) ) { ssSetErrorStatus ( rtS ,
"tdelay memory allocation error" ) ; return ; } } ( * tBuffer ++ ) [ rtDW .
iie0k52gf2 . Head [ 0 ] ] = simTime ; ( * uBuffer ++ ) [ rtDW . iie0k52gf2 .
Head [ 0 ] ] = rtB . l5ibfslonp [ 21 ] ; rtDW . iie0k52gf2 . Head [ 1 ] = ( (
rtDW . iie0k52gf2 . Head [ 1 ] < ( rtDW . iie0k52gf2 . CircularBufSize [ 1 ]
- 1 ) ) ? ( rtDW . iie0k52gf2 . Head [ 1 ] + 1 ) : 0 ) ; if ( rtDW .
iie0k52gf2 . Head [ 1 ] == rtDW . iie0k52gf2 . Tail [ 1 ] ) { if ( !
rt_TDelayUpdateTailOrGrowBuf ( & rtDW . iie0k52gf2 . CircularBufSize [ 1 ] ,
& rtDW . iie0k52gf2 . Tail [ 1 ] , & rtDW . iie0k52gf2 . Head [ 1 ] , & rtDW
. iie0k52gf2 . Last [ 1 ] , simTime - rtP . TransportDelay_Delay , tBuffer ,
uBuffer , ( NULL ) , ( boolean_T ) 0 , false , & rtDW . iie0k52gf2 .
MaxNewBufSize ) ) { ssSetErrorStatus ( rtS , "tdelay memory allocation error"
) ; return ; } } ( * tBuffer ++ ) [ rtDW . iie0k52gf2 . Head [ 1 ] ] =
simTime ; ( * uBuffer ++ ) [ rtDW . iie0k52gf2 . Head [ 1 ] ] = rtB .
l5ibfslonp [ 22 ] ; rtDW . iie0k52gf2 . Head [ 2 ] = ( ( rtDW . iie0k52gf2 .
Head [ 2 ] < ( rtDW . iie0k52gf2 . CircularBufSize [ 2 ] - 1 ) ) ? ( rtDW .
iie0k52gf2 . Head [ 2 ] + 1 ) : 0 ) ; if ( rtDW . iie0k52gf2 . Head [ 2 ] ==
rtDW . iie0k52gf2 . Tail [ 2 ] ) { if ( ! rt_TDelayUpdateTailOrGrowBuf ( &
rtDW . iie0k52gf2 . CircularBufSize [ 2 ] , & rtDW . iie0k52gf2 . Tail [ 2 ]
, & rtDW . iie0k52gf2 . Head [ 2 ] , & rtDW . iie0k52gf2 . Last [ 2 ] ,
simTime - rtP . TransportDelay_Delay , tBuffer , uBuffer , ( NULL ) , (
boolean_T ) 0 , false , & rtDW . iie0k52gf2 . MaxNewBufSize ) ) {
ssSetErrorStatus ( rtS , "tdelay memory allocation error" ) ; return ; } } (
* tBuffer ++ ) [ rtDW . iie0k52gf2 . Head [ 2 ] ] = simTime ; ( * uBuffer ++
) [ rtDW . iie0k52gf2 . Head [ 2 ] ] = rtB . l5ibfslonp [ 23 ] ; rtDW .
iie0k52gf2 . Head [ 3 ] = ( ( rtDW . iie0k52gf2 . Head [ 3 ] < ( rtDW .
iie0k52gf2 . CircularBufSize [ 3 ] - 1 ) ) ? ( rtDW . iie0k52gf2 . Head [ 3 ]
+ 1 ) : 0 ) ; if ( rtDW . iie0k52gf2 . Head [ 3 ] == rtDW . iie0k52gf2 . Tail
[ 3 ] ) { if ( ! rt_TDelayUpdateTailOrGrowBuf ( & rtDW . iie0k52gf2 .
CircularBufSize [ 3 ] , & rtDW . iie0k52gf2 . Tail [ 3 ] , & rtDW .
iie0k52gf2 . Head [ 3 ] , & rtDW . iie0k52gf2 . Last [ 3 ] , simTime - rtP .
TransportDelay_Delay , tBuffer , uBuffer , ( NULL ) , ( boolean_T ) 0 , false
, & rtDW . iie0k52gf2 . MaxNewBufSize ) ) { ssSetErrorStatus ( rtS ,
"tdelay memory allocation error" ) ; return ; } } ( * tBuffer ++ ) [ rtDW .
iie0k52gf2 . Head [ 3 ] ] = simTime ; ( * uBuffer ++ ) [ rtDW . iie0k52gf2 .
Head [ 3 ] ] = rtB . l5ibfslonp [ 18 ] ; rtDW . iie0k52gf2 . Head [ 4 ] = ( (
rtDW . iie0k52gf2 . Head [ 4 ] < ( rtDW . iie0k52gf2 . CircularBufSize [ 4 ]
- 1 ) ) ? ( rtDW . iie0k52gf2 . Head [ 4 ] + 1 ) : 0 ) ; if ( rtDW .
iie0k52gf2 . Head [ 4 ] == rtDW . iie0k52gf2 . Tail [ 4 ] ) { if ( !
rt_TDelayUpdateTailOrGrowBuf ( & rtDW . iie0k52gf2 . CircularBufSize [ 4 ] ,
& rtDW . iie0k52gf2 . Tail [ 4 ] , & rtDW . iie0k52gf2 . Head [ 4 ] , & rtDW
. iie0k52gf2 . Last [ 4 ] , simTime - rtP . TransportDelay_Delay , tBuffer ,
uBuffer , ( NULL ) , ( boolean_T ) 0 , false , & rtDW . iie0k52gf2 .
MaxNewBufSize ) ) { ssSetErrorStatus ( rtS , "tdelay memory allocation error"
) ; return ; } } ( * tBuffer ++ ) [ rtDW . iie0k52gf2 . Head [ 4 ] ] =
simTime ; ( * uBuffer ++ ) [ rtDW . iie0k52gf2 . Head [ 4 ] ] = rtB .
l5ibfslonp [ 19 ] ; rtDW . iie0k52gf2 . Head [ 5 ] = ( ( rtDW . iie0k52gf2 .
Head [ 5 ] < ( rtDW . iie0k52gf2 . CircularBufSize [ 5 ] - 1 ) ) ? ( rtDW .
iie0k52gf2 . Head [ 5 ] + 1 ) : 0 ) ; if ( rtDW . iie0k52gf2 . Head [ 5 ] ==
rtDW . iie0k52gf2 . Tail [ 5 ] ) { if ( ! rt_TDelayUpdateTailOrGrowBuf ( &
rtDW . iie0k52gf2 . CircularBufSize [ 5 ] , & rtDW . iie0k52gf2 . Tail [ 5 ]
, & rtDW . iie0k52gf2 . Head [ 5 ] , & rtDW . iie0k52gf2 . Last [ 5 ] ,
simTime - rtP . TransportDelay_Delay , tBuffer , uBuffer , ( NULL ) , (
boolean_T ) 0 , false , & rtDW . iie0k52gf2 . MaxNewBufSize ) ) {
ssSetErrorStatus ( rtS , "tdelay memory allocation error" ) ; return ; } } (
* tBuffer ) [ rtDW . iie0k52gf2 . Head [ 5 ] ] = simTime ; ( * uBuffer ) [
rtDW . iie0k52gf2 . Head [ 5 ] ] = rtB . l5ibfslonp [ 20 ] ; } { real_T * *
uBuffer = ( real_T * * ) & rtDW . fv3pugwi2m . TUbufferPtrs [ 0 ] ; real_T *
* tBuffer = ( real_T * * ) & rtDW . fv3pugwi2m . TUbufferPtrs [ 6 ] ; real_T
simTime = ssGetT ( rtS ) ; rtDW . hxf5v0hxfq . Head [ 0 ] = ( ( rtDW .
hxf5v0hxfq . Head [ 0 ] < ( rtDW . hxf5v0hxfq . CircularBufSize [ 0 ] - 1 ) )
? ( rtDW . hxf5v0hxfq . Head [ 0 ] + 1 ) : 0 ) ; if ( rtDW . hxf5v0hxfq .
Head [ 0 ] == rtDW . hxf5v0hxfq . Tail [ 0 ] ) { if ( !
rt_TDelayUpdateTailOrGrowBuf ( & rtDW . hxf5v0hxfq . CircularBufSize [ 0 ] ,
& rtDW . hxf5v0hxfq . Tail [ 0 ] , & rtDW . hxf5v0hxfq . Head [ 0 ] , & rtDW
. hxf5v0hxfq . Last [ 0 ] , simTime - rtP . TransportDelay_Delay_bp43gzj5e3 ,
tBuffer , uBuffer , ( NULL ) , ( boolean_T ) 0 , false , & rtDW . hxf5v0hxfq
. MaxNewBufSize ) ) { ssSetErrorStatus ( rtS ,
"tdelay memory allocation error" ) ; return ; } } ( * tBuffer ++ ) [ rtDW .
hxf5v0hxfq . Head [ 0 ] ] = simTime ; ( * uBuffer ++ ) [ rtDW . hxf5v0hxfq .
Head [ 0 ] ] = rtB . l5ibfslonp [ 27 ] ; rtDW . hxf5v0hxfq . Head [ 1 ] = ( (
rtDW . hxf5v0hxfq . Head [ 1 ] < ( rtDW . hxf5v0hxfq . CircularBufSize [ 1 ]
- 1 ) ) ? ( rtDW . hxf5v0hxfq . Head [ 1 ] + 1 ) : 0 ) ; if ( rtDW .
hxf5v0hxfq . Head [ 1 ] == rtDW . hxf5v0hxfq . Tail [ 1 ] ) { if ( !
rt_TDelayUpdateTailOrGrowBuf ( & rtDW . hxf5v0hxfq . CircularBufSize [ 1 ] ,
& rtDW . hxf5v0hxfq . Tail [ 1 ] , & rtDW . hxf5v0hxfq . Head [ 1 ] , & rtDW
. hxf5v0hxfq . Last [ 1 ] , simTime - rtP . TransportDelay_Delay_bp43gzj5e3 ,
tBuffer , uBuffer , ( NULL ) , ( boolean_T ) 0 , false , & rtDW . hxf5v0hxfq
. MaxNewBufSize ) ) { ssSetErrorStatus ( rtS ,
"tdelay memory allocation error" ) ; return ; } } ( * tBuffer ++ ) [ rtDW .
hxf5v0hxfq . Head [ 1 ] ] = simTime ; ( * uBuffer ++ ) [ rtDW . hxf5v0hxfq .
Head [ 1 ] ] = rtB . l5ibfslonp [ 28 ] ; rtDW . hxf5v0hxfq . Head [ 2 ] = ( (
rtDW . hxf5v0hxfq . Head [ 2 ] < ( rtDW . hxf5v0hxfq . CircularBufSize [ 2 ]
- 1 ) ) ? ( rtDW . hxf5v0hxfq . Head [ 2 ] + 1 ) : 0 ) ; if ( rtDW .
hxf5v0hxfq . Head [ 2 ] == rtDW . hxf5v0hxfq . Tail [ 2 ] ) { if ( !
rt_TDelayUpdateTailOrGrowBuf ( & rtDW . hxf5v0hxfq . CircularBufSize [ 2 ] ,
& rtDW . hxf5v0hxfq . Tail [ 2 ] , & rtDW . hxf5v0hxfq . Head [ 2 ] , & rtDW
. hxf5v0hxfq . Last [ 2 ] , simTime - rtP . TransportDelay_Delay_bp43gzj5e3 ,
tBuffer , uBuffer , ( NULL ) , ( boolean_T ) 0 , false , & rtDW . hxf5v0hxfq
. MaxNewBufSize ) ) { ssSetErrorStatus ( rtS ,
"tdelay memory allocation error" ) ; return ; } } ( * tBuffer ++ ) [ rtDW .
hxf5v0hxfq . Head [ 2 ] ] = simTime ; ( * uBuffer ++ ) [ rtDW . hxf5v0hxfq .
Head [ 2 ] ] = rtB . l5ibfslonp [ 29 ] ; rtDW . hxf5v0hxfq . Head [ 3 ] = ( (
rtDW . hxf5v0hxfq . Head [ 3 ] < ( rtDW . hxf5v0hxfq . CircularBufSize [ 3 ]
- 1 ) ) ? ( rtDW . hxf5v0hxfq . Head [ 3 ] + 1 ) : 0 ) ; if ( rtDW .
hxf5v0hxfq . Head [ 3 ] == rtDW . hxf5v0hxfq . Tail [ 3 ] ) { if ( !
rt_TDelayUpdateTailOrGrowBuf ( & rtDW . hxf5v0hxfq . CircularBufSize [ 3 ] ,
& rtDW . hxf5v0hxfq . Tail [ 3 ] , & rtDW . hxf5v0hxfq . Head [ 3 ] , & rtDW
. hxf5v0hxfq . Last [ 3 ] , simTime - rtP . TransportDelay_Delay_bp43gzj5e3 ,
tBuffer , uBuffer , ( NULL ) , ( boolean_T ) 0 , false , & rtDW . hxf5v0hxfq
. MaxNewBufSize ) ) { ssSetErrorStatus ( rtS ,
"tdelay memory allocation error" ) ; return ; } } ( * tBuffer ++ ) [ rtDW .
hxf5v0hxfq . Head [ 3 ] ] = simTime ; ( * uBuffer ++ ) [ rtDW . hxf5v0hxfq .
Head [ 3 ] ] = rtB . l5ibfslonp [ 24 ] ; rtDW . hxf5v0hxfq . Head [ 4 ] = ( (
rtDW . hxf5v0hxfq . Head [ 4 ] < ( rtDW . hxf5v0hxfq . CircularBufSize [ 4 ]
- 1 ) ) ? ( rtDW . hxf5v0hxfq . Head [ 4 ] + 1 ) : 0 ) ; if ( rtDW .
hxf5v0hxfq . Head [ 4 ] == rtDW . hxf5v0hxfq . Tail [ 4 ] ) { if ( !
rt_TDelayUpdateTailOrGrowBuf ( & rtDW . hxf5v0hxfq . CircularBufSize [ 4 ] ,
& rtDW . hxf5v0hxfq . Tail [ 4 ] , & rtDW . hxf5v0hxfq . Head [ 4 ] , & rtDW
. hxf5v0hxfq . Last [ 4 ] , simTime - rtP . TransportDelay_Delay_bp43gzj5e3 ,
tBuffer , uBuffer , ( NULL ) , ( boolean_T ) 0 , false , & rtDW . hxf5v0hxfq
. MaxNewBufSize ) ) { ssSetErrorStatus ( rtS ,
"tdelay memory allocation error" ) ; return ; } } ( * tBuffer ++ ) [ rtDW .
hxf5v0hxfq . Head [ 4 ] ] = simTime ; ( * uBuffer ++ ) [ rtDW . hxf5v0hxfq .
Head [ 4 ] ] = rtB . l5ibfslonp [ 25 ] ; rtDW . hxf5v0hxfq . Head [ 5 ] = ( (
rtDW . hxf5v0hxfq . Head [ 5 ] < ( rtDW . hxf5v0hxfq . CircularBufSize [ 5 ]
- 1 ) ) ? ( rtDW . hxf5v0hxfq . Head [ 5 ] + 1 ) : 0 ) ; if ( rtDW .
hxf5v0hxfq . Head [ 5 ] == rtDW . hxf5v0hxfq . Tail [ 5 ] ) { if ( !
rt_TDelayUpdateTailOrGrowBuf ( & rtDW . hxf5v0hxfq . CircularBufSize [ 5 ] ,
& rtDW . hxf5v0hxfq . Tail [ 5 ] , & rtDW . hxf5v0hxfq . Head [ 5 ] , & rtDW
. hxf5v0hxfq . Last [ 5 ] , simTime - rtP . TransportDelay_Delay_bp43gzj5e3 ,
tBuffer , uBuffer , ( NULL ) , ( boolean_T ) 0 , false , & rtDW . hxf5v0hxfq
. MaxNewBufSize ) ) { ssSetErrorStatus ( rtS ,
"tdelay memory allocation error" ) ; return ; } } ( * tBuffer ) [ rtDW .
hxf5v0hxfq . Head [ 5 ] ] = simTime ; ( * uBuffer ) [ rtDW . hxf5v0hxfq .
Head [ 5 ] ] = rtB . l5ibfslonp [ 26 ] ; } { real_T * * uBuffer = ( real_T *
* ) & rtDW . a1q2j3sqxq . TUbufferPtrs [ 0 ] ; real_T * * tBuffer = ( real_T
* * ) & rtDW . a1q2j3sqxq . TUbufferPtrs [ 6 ] ; real_T simTime = ssGetT (
rtS ) ; rtDW . nrayhafgyw . Head [ 0 ] = ( ( rtDW . nrayhafgyw . Head [ 0 ] <
( rtDW . nrayhafgyw . CircularBufSize [ 0 ] - 1 ) ) ? ( rtDW . nrayhafgyw .
Head [ 0 ] + 1 ) : 0 ) ; if ( rtDW . nrayhafgyw . Head [ 0 ] == rtDW .
nrayhafgyw . Tail [ 0 ] ) { if ( ! rt_TDelayUpdateTailOrGrowBuf ( & rtDW .
nrayhafgyw . CircularBufSize [ 0 ] , & rtDW . nrayhafgyw . Tail [ 0 ] , &
rtDW . nrayhafgyw . Head [ 0 ] , & rtDW . nrayhafgyw . Last [ 0 ] , simTime -
rtP . TransportDelay_Delay_foibzxd41j , tBuffer , uBuffer , ( NULL ) , (
boolean_T ) 0 , false , & rtDW . nrayhafgyw . MaxNewBufSize ) ) {
ssSetErrorStatus ( rtS , "tdelay memory allocation error" ) ; return ; } } (
* tBuffer ++ ) [ rtDW . nrayhafgyw . Head [ 0 ] ] = simTime ; ( * uBuffer ++
) [ rtDW . nrayhafgyw . Head [ 0 ] ] = rtB . l5ibfslonp [ 33 ] ; rtDW .
nrayhafgyw . Head [ 1 ] = ( ( rtDW . nrayhafgyw . Head [ 1 ] < ( rtDW .
nrayhafgyw . CircularBufSize [ 1 ] - 1 ) ) ? ( rtDW . nrayhafgyw . Head [ 1 ]
+ 1 ) : 0 ) ; if ( rtDW . nrayhafgyw . Head [ 1 ] == rtDW . nrayhafgyw . Tail
[ 1 ] ) { if ( ! rt_TDelayUpdateTailOrGrowBuf ( & rtDW . nrayhafgyw .
CircularBufSize [ 1 ] , & rtDW . nrayhafgyw . Tail [ 1 ] , & rtDW .
nrayhafgyw . Head [ 1 ] , & rtDW . nrayhafgyw . Last [ 1 ] , simTime - rtP .
TransportDelay_Delay_foibzxd41j , tBuffer , uBuffer , ( NULL ) , ( boolean_T
) 0 , false , & rtDW . nrayhafgyw . MaxNewBufSize ) ) { ssSetErrorStatus (
rtS , "tdelay memory allocation error" ) ; return ; } } ( * tBuffer ++ ) [
rtDW . nrayhafgyw . Head [ 1 ] ] = simTime ; ( * uBuffer ++ ) [ rtDW .
nrayhafgyw . Head [ 1 ] ] = rtB . l5ibfslonp [ 34 ] ; rtDW . nrayhafgyw .
Head [ 2 ] = ( ( rtDW . nrayhafgyw . Head [ 2 ] < ( rtDW . nrayhafgyw .
CircularBufSize [ 2 ] - 1 ) ) ? ( rtDW . nrayhafgyw . Head [ 2 ] + 1 ) : 0 )
; if ( rtDW . nrayhafgyw . Head [ 2 ] == rtDW . nrayhafgyw . Tail [ 2 ] ) {
if ( ! rt_TDelayUpdateTailOrGrowBuf ( & rtDW . nrayhafgyw . CircularBufSize [
2 ] , & rtDW . nrayhafgyw . Tail [ 2 ] , & rtDW . nrayhafgyw . Head [ 2 ] , &
rtDW . nrayhafgyw . Last [ 2 ] , simTime - rtP .
TransportDelay_Delay_foibzxd41j , tBuffer , uBuffer , ( NULL ) , ( boolean_T
) 0 , false , & rtDW . nrayhafgyw . MaxNewBufSize ) ) { ssSetErrorStatus (
rtS , "tdelay memory allocation error" ) ; return ; } } ( * tBuffer ++ ) [
rtDW . nrayhafgyw . Head [ 2 ] ] = simTime ; ( * uBuffer ++ ) [ rtDW .
nrayhafgyw . Head [ 2 ] ] = rtB . l5ibfslonp [ 35 ] ; rtDW . nrayhafgyw .
Head [ 3 ] = ( ( rtDW . nrayhafgyw . Head [ 3 ] < ( rtDW . nrayhafgyw .
CircularBufSize [ 3 ] - 1 ) ) ? ( rtDW . nrayhafgyw . Head [ 3 ] + 1 ) : 0 )
; if ( rtDW . nrayhafgyw . Head [ 3 ] == rtDW . nrayhafgyw . Tail [ 3 ] ) {
if ( ! rt_TDelayUpdateTailOrGrowBuf ( & rtDW . nrayhafgyw . CircularBufSize [
3 ] , & rtDW . nrayhafgyw . Tail [ 3 ] , & rtDW . nrayhafgyw . Head [ 3 ] , &
rtDW . nrayhafgyw . Last [ 3 ] , simTime - rtP .
TransportDelay_Delay_foibzxd41j , tBuffer , uBuffer , ( NULL ) , ( boolean_T
) 0 , false , & rtDW . nrayhafgyw . MaxNewBufSize ) ) { ssSetErrorStatus (
rtS , "tdelay memory allocation error" ) ; return ; } } ( * tBuffer ++ ) [
rtDW . nrayhafgyw . Head [ 3 ] ] = simTime ; ( * uBuffer ++ ) [ rtDW .
nrayhafgyw . Head [ 3 ] ] = rtB . l5ibfslonp [ 30 ] ; rtDW . nrayhafgyw .
Head [ 4 ] = ( ( rtDW . nrayhafgyw . Head [ 4 ] < ( rtDW . nrayhafgyw .
CircularBufSize [ 4 ] - 1 ) ) ? ( rtDW . nrayhafgyw . Head [ 4 ] + 1 ) : 0 )
; if ( rtDW . nrayhafgyw . Head [ 4 ] == rtDW . nrayhafgyw . Tail [ 4 ] ) {
if ( ! rt_TDelayUpdateTailOrGrowBuf ( & rtDW . nrayhafgyw . CircularBufSize [
4 ] , & rtDW . nrayhafgyw . Tail [ 4 ] , & rtDW . nrayhafgyw . Head [ 4 ] , &
rtDW . nrayhafgyw . Last [ 4 ] , simTime - rtP .
TransportDelay_Delay_foibzxd41j , tBuffer , uBuffer , ( NULL ) , ( boolean_T
) 0 , false , & rtDW . nrayhafgyw . MaxNewBufSize ) ) { ssSetErrorStatus (
rtS , "tdelay memory allocation error" ) ; return ; } } ( * tBuffer ++ ) [
rtDW . nrayhafgyw . Head [ 4 ] ] = simTime ; ( * uBuffer ++ ) [ rtDW .
nrayhafgyw . Head [ 4 ] ] = rtB . l5ibfslonp [ 31 ] ; rtDW . nrayhafgyw .
Head [ 5 ] = ( ( rtDW . nrayhafgyw . Head [ 5 ] < ( rtDW . nrayhafgyw .
CircularBufSize [ 5 ] - 1 ) ) ? ( rtDW . nrayhafgyw . Head [ 5 ] + 1 ) : 0 )
; if ( rtDW . nrayhafgyw . Head [ 5 ] == rtDW . nrayhafgyw . Tail [ 5 ] ) {
if ( ! rt_TDelayUpdateTailOrGrowBuf ( & rtDW . nrayhafgyw . CircularBufSize [
5 ] , & rtDW . nrayhafgyw . Tail [ 5 ] , & rtDW . nrayhafgyw . Head [ 5 ] , &
rtDW . nrayhafgyw . Last [ 5 ] , simTime - rtP .
TransportDelay_Delay_foibzxd41j , tBuffer , uBuffer , ( NULL ) , ( boolean_T
) 0 , false , & rtDW . nrayhafgyw . MaxNewBufSize ) ) { ssSetErrorStatus (
rtS , "tdelay memory allocation error" ) ; return ; } } ( * tBuffer ) [ rtDW
. nrayhafgyw . Head [ 5 ] ] = simTime ; ( * uBuffer ) [ rtDW . nrayhafgyw .
Head [ 5 ] ] = rtB . l5ibfslonp [ 32 ] ; } UNUSED_PARAMETER ( tid ) ; } void
MdlDerivatives ( void ) { NeslSimulationData * simulationData ; real_T time ;
boolean_T tmp ; real_T tmp_p [ 72 ] ; int_T tmp_e [ 19 ] ;
NeuDiagnosticManager * diagnosticManager ; NeuDiagnosticTree * diagnosticTree
; int32_T tmp_i ; char * msg ; XDot * _rtXdot ; _rtXdot = ( ( XDot * )
ssGetdX ( rtS ) ) ; simulationData = ( NeslSimulationData * ) rtDW .
lav352kiwz ; time = ssGetT ( rtS ) ; simulationData -> mData -> mTime . mN =
1 ; simulationData -> mData -> mTime . mX = & time ; simulationData -> mData
-> mContStates . mN = 4 ; simulationData -> mData -> mContStates . mX = (
real_T * ) & rtX . h5zfgvmg3r ; simulationData -> mData -> mDiscStates . mN =
0 ; simulationData -> mData -> mDiscStates . mX = NULL ; simulationData ->
mData -> mModeVector . mN = 0 ; simulationData -> mData -> mModeVector . mX =
NULL ; tmp = false ; simulationData -> mData -> mFoundZcEvents = tmp ;
simulationData -> mData -> mIsMajorTimeStep = ssIsMajorTimeStep ( rtS ) ; tmp
= ( ssGetMdlInfoPtr ( rtS ) -> mdlFlags . solverAssertCheck == 1U ) ;
simulationData -> mData -> mIsSolverAssertCheck = tmp ; simulationData ->
mData -> mIsSolverCheckingCIC = false ; tmp = ssIsSolverComputingJacobian (
rtS ) ; simulationData -> mData -> mIsComputingJacobian = tmp ;
simulationData -> mData -> mIsSolverRequestingReset = false ; tmp_e [ 0 ] = 0
; tmp_p [ 0 ] = rtB . p1qklr3iem [ 0 ] ; tmp_p [ 1 ] = rtB . p1qklr3iem [ 1 ]
; tmp_p [ 2 ] = rtB . p1qklr3iem [ 2 ] ; tmp_p [ 3 ] = rtB . p1qklr3iem [ 3 ]
; tmp_e [ 1 ] = 4 ; tmp_p [ 4 ] = rtB . dzcyvgjss1 [ 0 ] ; tmp_p [ 5 ] = rtB
. dzcyvgjss1 [ 1 ] ; tmp_p [ 6 ] = rtB . dzcyvgjss1 [ 2 ] ; tmp_p [ 7 ] = rtB
. dzcyvgjss1 [ 3 ] ; tmp_e [ 2 ] = 8 ; tmp_p [ 8 ] = rtB . kyqswxndxu [ 0 ] ;
tmp_p [ 9 ] = rtB . kyqswxndxu [ 1 ] ; tmp_p [ 10 ] = rtB . kyqswxndxu [ 2 ]
; tmp_p [ 11 ] = rtB . kyqswxndxu [ 3 ] ; tmp_e [ 3 ] = 12 ; tmp_p [ 12 ] =
rtB . os0vmujie2 [ 0 ] ; tmp_p [ 13 ] = rtB . os0vmujie2 [ 1 ] ; tmp_p [ 14 ]
= rtB . os0vmujie2 [ 2 ] ; tmp_p [ 15 ] = rtB . os0vmujie2 [ 3 ] ; tmp_e [ 4
] = 16 ; tmp_p [ 16 ] = rtB . f5vdxtzttp [ 0 ] ; tmp_p [ 17 ] = rtB .
f5vdxtzttp [ 1 ] ; tmp_p [ 18 ] = rtB . f5vdxtzttp [ 2 ] ; tmp_p [ 19 ] = rtB
. f5vdxtzttp [ 3 ] ; tmp_e [ 5 ] = 20 ; tmp_p [ 20 ] = rtB . ny3ji5snoz [ 0 ]
; tmp_p [ 21 ] = rtB . ny3ji5snoz [ 1 ] ; tmp_p [ 22 ] = rtB . ny3ji5snoz [ 2
] ; tmp_p [ 23 ] = rtB . ny3ji5snoz [ 3 ] ; tmp_e [ 6 ] = 24 ; tmp_p [ 24 ] =
rtB . kgii2iaa1l [ 0 ] ; tmp_p [ 25 ] = rtB . kgii2iaa1l [ 1 ] ; tmp_p [ 26 ]
= rtB . kgii2iaa1l [ 2 ] ; tmp_p [ 27 ] = rtB . kgii2iaa1l [ 3 ] ; tmp_e [ 7
] = 28 ; tmp_p [ 28 ] = rtB . jfce0w0ghr [ 0 ] ; tmp_p [ 29 ] = rtB .
jfce0w0ghr [ 1 ] ; tmp_p [ 30 ] = rtB . jfce0w0ghr [ 2 ] ; tmp_p [ 31 ] = rtB
. jfce0w0ghr [ 3 ] ; tmp_e [ 8 ] = 32 ; tmp_p [ 32 ] = rtB . pcf0pfmweo [ 0 ]
; tmp_p [ 33 ] = rtB . pcf0pfmweo [ 1 ] ; tmp_p [ 34 ] = rtB . pcf0pfmweo [ 2
] ; tmp_p [ 35 ] = rtB . pcf0pfmweo [ 3 ] ; tmp_e [ 9 ] = 36 ; tmp_p [ 36 ] =
rtB . if52phrmag [ 0 ] ; tmp_p [ 37 ] = rtB . if52phrmag [ 1 ] ; tmp_p [ 38 ]
= rtB . if52phrmag [ 2 ] ; tmp_p [ 39 ] = rtB . if52phrmag [ 3 ] ; tmp_e [ 10
] = 40 ; tmp_p [ 40 ] = rtB . mocddkrpki [ 0 ] ; tmp_p [ 41 ] = rtB .
mocddkrpki [ 1 ] ; tmp_p [ 42 ] = rtB . mocddkrpki [ 2 ] ; tmp_p [ 43 ] = rtB
. mocddkrpki [ 3 ] ; tmp_e [ 11 ] = 44 ; tmp_p [ 44 ] = rtB . kzwkda2ehh [ 0
] ; tmp_p [ 45 ] = rtB . kzwkda2ehh [ 1 ] ; tmp_p [ 46 ] = rtB . kzwkda2ehh [
2 ] ; tmp_p [ 47 ] = rtB . kzwkda2ehh [ 3 ] ; tmp_e [ 12 ] = 48 ; tmp_p [ 48
] = rtB . hmeg1w5jim [ 0 ] ; tmp_p [ 49 ] = rtB . hmeg1w5jim [ 1 ] ; tmp_p [
50 ] = rtB . hmeg1w5jim [ 2 ] ; tmp_p [ 51 ] = rtB . hmeg1w5jim [ 3 ] ; tmp_e
[ 13 ] = 52 ; tmp_p [ 52 ] = rtB . nbocq1o42k [ 0 ] ; tmp_p [ 53 ] = rtB .
nbocq1o42k [ 1 ] ; tmp_p [ 54 ] = rtB . nbocq1o42k [ 2 ] ; tmp_p [ 55 ] = rtB
. nbocq1o42k [ 3 ] ; tmp_e [ 14 ] = 56 ; tmp_p [ 56 ] = rtB . d5a52isphm [ 0
] ; tmp_p [ 57 ] = rtB . d5a52isphm [ 1 ] ; tmp_p [ 58 ] = rtB . d5a52isphm [
2 ] ; tmp_p [ 59 ] = rtB . d5a52isphm [ 3 ] ; tmp_e [ 15 ] = 60 ; tmp_p [ 60
] = rtB . icy3aei5aw [ 0 ] ; tmp_p [ 61 ] = rtB . icy3aei5aw [ 1 ] ; tmp_p [
62 ] = rtB . icy3aei5aw [ 2 ] ; tmp_p [ 63 ] = rtB . icy3aei5aw [ 3 ] ; tmp_e
[ 16 ] = 64 ; tmp_p [ 64 ] = rtB . add5kxxow3 [ 0 ] ; tmp_p [ 65 ] = rtB .
add5kxxow3 [ 1 ] ; tmp_p [ 66 ] = rtB . add5kxxow3 [ 2 ] ; tmp_p [ 67 ] = rtB
. add5kxxow3 [ 3 ] ; tmp_e [ 17 ] = 68 ; tmp_p [ 68 ] = rtB . oigl01ewmc [ 0
] ; tmp_p [ 69 ] = rtB . oigl01ewmc [ 1 ] ; tmp_p [ 70 ] = rtB . oigl01ewmc [
2 ] ; tmp_p [ 71 ] = rtB . oigl01ewmc [ 3 ] ; tmp_e [ 18 ] = 72 ;
simulationData -> mData -> mInputValues . mN = 72 ; simulationData -> mData
-> mInputValues . mX = & tmp_p [ 0 ] ; simulationData -> mData ->
mInputOffsets . mN = 19 ; simulationData -> mData -> mInputOffsets . mX = &
tmp_e [ 0 ] ; simulationData -> mData -> mDx . mN = 4 ; simulationData ->
mData -> mDx . mX = ( real_T * ) & _rtXdot -> h5zfgvmg3r ; diagnosticManager
= ( NeuDiagnosticManager * ) rtDW . gknbsopy3r ; diagnosticTree =
neu_diagnostic_manager_get_initial_tree ( diagnosticManager ) ; tmp_i =
ne_simulator_method ( ( NeslSimulator * ) rtDW . pyei4aktas ,
NESL_SIM_DERIVATIVES , simulationData , diagnosticManager ) ; if ( tmp_i != 0
) { tmp = error_buffer_is_empty ( ssGetErrorStatus ( rtS ) ) ; if ( tmp ) {
msg = rtw_diagnostics_msg ( diagnosticTree ) ; ssSetErrorStatus ( rtS , msg )
; } } } void MdlProjection ( void ) { NeslSimulationData * simulationData ;
real_T time ; boolean_T tmp ; real_T tmp_p [ 72 ] ; int_T tmp_e [ 19 ] ;
NeuDiagnosticManager * diagnosticManager ; NeuDiagnosticTree * diagnosticTree
; int32_T tmp_i ; char * msg ; simulationData = ( NeslSimulationData * ) rtDW
. lav352kiwz ; time = ssGetT ( rtS ) ; simulationData -> mData -> mTime . mN
= 1 ; simulationData -> mData -> mTime . mX = & time ; simulationData ->
mData -> mContStates . mN = 4 ; simulationData -> mData -> mContStates . mX =
( real_T * ) & rtX . h5zfgvmg3r ; simulationData -> mData -> mDiscStates . mN
= 0 ; simulationData -> mData -> mDiscStates . mX = NULL ; simulationData ->
mData -> mModeVector . mN = 0 ; simulationData -> mData -> mModeVector . mX =
NULL ; tmp = false ; simulationData -> mData -> mFoundZcEvents = tmp ;
simulationData -> mData -> mIsMajorTimeStep = ssIsMajorTimeStep ( rtS ) ; tmp
= ( ssGetMdlInfoPtr ( rtS ) -> mdlFlags . solverAssertCheck == 1U ) ;
simulationData -> mData -> mIsSolverAssertCheck = tmp ; simulationData ->
mData -> mIsSolverCheckingCIC = false ; tmp = ssIsSolverComputingJacobian (
rtS ) ; simulationData -> mData -> mIsComputingJacobian = tmp ;
simulationData -> mData -> mIsSolverRequestingReset = false ; tmp_e [ 0 ] = 0
; tmp_p [ 0 ] = rtB . p1qklr3iem [ 0 ] ; tmp_p [ 1 ] = rtB . p1qklr3iem [ 1 ]
; tmp_p [ 2 ] = rtB . p1qklr3iem [ 2 ] ; tmp_p [ 3 ] = rtB . p1qklr3iem [ 3 ]
; tmp_e [ 1 ] = 4 ; tmp_p [ 4 ] = rtB . dzcyvgjss1 [ 0 ] ; tmp_p [ 5 ] = rtB
. dzcyvgjss1 [ 1 ] ; tmp_p [ 6 ] = rtB . dzcyvgjss1 [ 2 ] ; tmp_p [ 7 ] = rtB
. dzcyvgjss1 [ 3 ] ; tmp_e [ 2 ] = 8 ; tmp_p [ 8 ] = rtB . kyqswxndxu [ 0 ] ;
tmp_p [ 9 ] = rtB . kyqswxndxu [ 1 ] ; tmp_p [ 10 ] = rtB . kyqswxndxu [ 2 ]
; tmp_p [ 11 ] = rtB . kyqswxndxu [ 3 ] ; tmp_e [ 3 ] = 12 ; tmp_p [ 12 ] =
rtB . os0vmujie2 [ 0 ] ; tmp_p [ 13 ] = rtB . os0vmujie2 [ 1 ] ; tmp_p [ 14 ]
= rtB . os0vmujie2 [ 2 ] ; tmp_p [ 15 ] = rtB . os0vmujie2 [ 3 ] ; tmp_e [ 4
] = 16 ; tmp_p [ 16 ] = rtB . f5vdxtzttp [ 0 ] ; tmp_p [ 17 ] = rtB .
f5vdxtzttp [ 1 ] ; tmp_p [ 18 ] = rtB . f5vdxtzttp [ 2 ] ; tmp_p [ 19 ] = rtB
. f5vdxtzttp [ 3 ] ; tmp_e [ 5 ] = 20 ; tmp_p [ 20 ] = rtB . ny3ji5snoz [ 0 ]
; tmp_p [ 21 ] = rtB . ny3ji5snoz [ 1 ] ; tmp_p [ 22 ] = rtB . ny3ji5snoz [ 2
] ; tmp_p [ 23 ] = rtB . ny3ji5snoz [ 3 ] ; tmp_e [ 6 ] = 24 ; tmp_p [ 24 ] =
rtB . kgii2iaa1l [ 0 ] ; tmp_p [ 25 ] = rtB . kgii2iaa1l [ 1 ] ; tmp_p [ 26 ]
= rtB . kgii2iaa1l [ 2 ] ; tmp_p [ 27 ] = rtB . kgii2iaa1l [ 3 ] ; tmp_e [ 7
] = 28 ; tmp_p [ 28 ] = rtB . jfce0w0ghr [ 0 ] ; tmp_p [ 29 ] = rtB .
jfce0w0ghr [ 1 ] ; tmp_p [ 30 ] = rtB . jfce0w0ghr [ 2 ] ; tmp_p [ 31 ] = rtB
. jfce0w0ghr [ 3 ] ; tmp_e [ 8 ] = 32 ; tmp_p [ 32 ] = rtB . pcf0pfmweo [ 0 ]
; tmp_p [ 33 ] = rtB . pcf0pfmweo [ 1 ] ; tmp_p [ 34 ] = rtB . pcf0pfmweo [ 2
] ; tmp_p [ 35 ] = rtB . pcf0pfmweo [ 3 ] ; tmp_e [ 9 ] = 36 ; tmp_p [ 36 ] =
rtB . if52phrmag [ 0 ] ; tmp_p [ 37 ] = rtB . if52phrmag [ 1 ] ; tmp_p [ 38 ]
= rtB . if52phrmag [ 2 ] ; tmp_p [ 39 ] = rtB . if52phrmag [ 3 ] ; tmp_e [ 10
] = 40 ; tmp_p [ 40 ] = rtB . mocddkrpki [ 0 ] ; tmp_p [ 41 ] = rtB .
mocddkrpki [ 1 ] ; tmp_p [ 42 ] = rtB . mocddkrpki [ 2 ] ; tmp_p [ 43 ] = rtB
. mocddkrpki [ 3 ] ; tmp_e [ 11 ] = 44 ; tmp_p [ 44 ] = rtB . kzwkda2ehh [ 0
] ; tmp_p [ 45 ] = rtB . kzwkda2ehh [ 1 ] ; tmp_p [ 46 ] = rtB . kzwkda2ehh [
2 ] ; tmp_p [ 47 ] = rtB . kzwkda2ehh [ 3 ] ; tmp_e [ 12 ] = 48 ; tmp_p [ 48
] = rtB . hmeg1w5jim [ 0 ] ; tmp_p [ 49 ] = rtB . hmeg1w5jim [ 1 ] ; tmp_p [
50 ] = rtB . hmeg1w5jim [ 2 ] ; tmp_p [ 51 ] = rtB . hmeg1w5jim [ 3 ] ; tmp_e
[ 13 ] = 52 ; tmp_p [ 52 ] = rtB . nbocq1o42k [ 0 ] ; tmp_p [ 53 ] = rtB .
nbocq1o42k [ 1 ] ; tmp_p [ 54 ] = rtB . nbocq1o42k [ 2 ] ; tmp_p [ 55 ] = rtB
. nbocq1o42k [ 3 ] ; tmp_e [ 14 ] = 56 ; tmp_p [ 56 ] = rtB . d5a52isphm [ 0
] ; tmp_p [ 57 ] = rtB . d5a52isphm [ 1 ] ; tmp_p [ 58 ] = rtB . d5a52isphm [
2 ] ; tmp_p [ 59 ] = rtB . d5a52isphm [ 3 ] ; tmp_e [ 15 ] = 60 ; tmp_p [ 60
] = rtB . icy3aei5aw [ 0 ] ; tmp_p [ 61 ] = rtB . icy3aei5aw [ 1 ] ; tmp_p [
62 ] = rtB . icy3aei5aw [ 2 ] ; tmp_p [ 63 ] = rtB . icy3aei5aw [ 3 ] ; tmp_e
[ 16 ] = 64 ; tmp_p [ 64 ] = rtB . add5kxxow3 [ 0 ] ; tmp_p [ 65 ] = rtB .
add5kxxow3 [ 1 ] ; tmp_p [ 66 ] = rtB . add5kxxow3 [ 2 ] ; tmp_p [ 67 ] = rtB
. add5kxxow3 [ 3 ] ; tmp_e [ 17 ] = 68 ; tmp_p [ 68 ] = rtB . oigl01ewmc [ 0
] ; tmp_p [ 69 ] = rtB . oigl01ewmc [ 1 ] ; tmp_p [ 70 ] = rtB . oigl01ewmc [
2 ] ; tmp_p [ 71 ] = rtB . oigl01ewmc [ 3 ] ; tmp_e [ 18 ] = 72 ;
simulationData -> mData -> mInputValues . mN = 72 ; simulationData -> mData
-> mInputValues . mX = & tmp_p [ 0 ] ; simulationData -> mData ->
mInputOffsets . mN = 19 ; simulationData -> mData -> mInputOffsets . mX = &
tmp_e [ 0 ] ; diagnosticManager = ( NeuDiagnosticManager * ) rtDW .
gknbsopy3r ; diagnosticTree = neu_diagnostic_manager_get_initial_tree (
diagnosticManager ) ; tmp_i = ne_simulator_method ( ( NeslSimulator * ) rtDW
. pyei4aktas , NESL_SIM_PROJECTION , simulationData , diagnosticManager ) ;
if ( tmp_i != 0 ) { tmp = error_buffer_is_empty ( ssGetErrorStatus ( rtS ) )
; if ( tmp ) { msg = rtw_diagnostics_msg ( diagnosticTree ) ;
ssSetErrorStatus ( rtS , msg ) ; } } } void MdlTerminate ( void ) {
neu_destroy_diagnostic_manager ( ( NeuDiagnosticManager * ) rtDW . gknbsopy3r
) ; nesl_destroy_simulation_data ( ( NeslSimulationData * ) rtDW . lav352kiwz
) ; nesl_erase_simulator (
"foswec/Global Reference Frame1/Solver Configuration" ) ;
neu_destroy_diagnostic_manager ( ( NeuDiagnosticManager * ) rtDW . k13qfbrzod
) ; nesl_destroy_simulation_data ( ( NeslSimulationData * ) rtDW . awgpzntukc
) ; nesl_erase_simulator (
"foswec/Global Reference Frame1/Solver Configuration" ) ; { int_T i1 ; void *
* pw_TUbufferPtrs = & rtDW . ozvltbk2so . TUbufferPtrs [ 0 ] ; for ( i1 = 0 ;
i1 < 3 ; i1 ++ ) { rt_TDelayFreeBuf ( pw_TUbufferPtrs [ i1 ] ) ; }
pw_TUbufferPtrs = & rtDW . ozvltbk2so . TUbufferPtrs [ 3 ] ; for ( i1 = 0 ;
i1 < 3 ; i1 ++ ) { rt_TDelayFreeBuf ( pw_TUbufferPtrs [ i1 ] ) ; } } { int_T
i1 ; void * * pw_TUbufferPtrs = & rtDW . fv3pugwi2m . TUbufferPtrs [ 0 ] ;
for ( i1 = 0 ; i1 < 3 ; i1 ++ ) { rt_TDelayFreeBuf ( pw_TUbufferPtrs [ i1 ] )
; } pw_TUbufferPtrs = & rtDW . fv3pugwi2m . TUbufferPtrs [ 3 ] ; for ( i1 = 0
; i1 < 3 ; i1 ++ ) { rt_TDelayFreeBuf ( pw_TUbufferPtrs [ i1 ] ) ; } } {
int_T i1 ; void * * pw_TUbufferPtrs = & rtDW . a1q2j3sqxq . TUbufferPtrs [ 0
] ; for ( i1 = 0 ; i1 < 3 ; i1 ++ ) { rt_TDelayFreeBuf ( pw_TUbufferPtrs [ i1
] ) ; } pw_TUbufferPtrs = & rtDW . a1q2j3sqxq . TUbufferPtrs [ 3 ] ; for ( i1
= 0 ; i1 < 3 ; i1 ++ ) { rt_TDelayFreeBuf ( pw_TUbufferPtrs [ i1 ] ) ; } }
neu_destroy_diagnostic_manager ( ( NeuDiagnosticManager * ) rtDW . hmwzsbnven
) ; nesl_destroy_simulation_data ( ( NeslSimulationData * ) rtDW . mzt5dujgnf
) ; nesl_erase_simulator (
"foswec/Global Reference Frame1/Solver Configuration" ) ; } void
MdlInitializeSizes ( void ) { ssSetNumContStates ( rtS , 4 ) ; ssSetNumY (
rtS , 0 ) ; ssSetNumU ( rtS , 0 ) ; ssSetDirectFeedThrough ( rtS , 0 ) ;
ssSetNumSampleTimes ( rtS , 2 ) ; ssSetNumBlocks ( rtS , 370 ) ;
ssSetNumBlockIO ( rtS , 72 ) ; ssSetNumBlockParams ( rtS , 111606 ) ; } void
MdlInitializeSampleTimes ( void ) { ssSetSampleTime ( rtS , 0 , 0.0 ) ;
ssSetSampleTime ( rtS , 1 , 0.07 ) ; ssSetOffsetTime ( rtS , 0 , 0.0 ) ;
ssSetOffsetTime ( rtS , 1 , 0.0 ) ; } void raccel_set_checksum ( SimStruct *
rtS ) { ssSetChecksumVal ( rtS , 0 , 4188621712U ) ; ssSetChecksumVal ( rtS ,
1 , 2115538234U ) ; ssSetChecksumVal ( rtS , 2 , 615640652U ) ;
ssSetChecksumVal ( rtS , 3 , 871521442U ) ; } SimStruct *
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
dtInfo . P = & rtPTransTable ; } foswec_InitializeDataMapInfo ( rtS ) ;
ssSetIsRapidAcceleratorActive ( rtS , true ) ; ssSetRootSS ( rtS , rtS ) ;
ssSetVersion ( rtS , SIMSTRUCT_VERSION_LEVEL2 ) ; ssSetModelName ( rtS ,
"foswec" ) ; ssSetPath ( rtS , "foswec" ) ; ssSetTStart ( rtS , 0.0 ) ;
ssSetTFinal ( rtS , 1400.0000000000002 ) ; ssSetStepSize ( rtS , 0.07 ) ;
ssSetFixedStepSize ( rtS , 0.07 ) ; { static RTWLogInfo rt_DataLoggingInfo ;
ssSetRTWLogInfo ( rtS , & rt_DataLoggingInfo ) ; } { { static int_T
rt_LoggedStateWidths [ ] = { 1 , 1 , 1 , 1 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 ,
2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 } ; static int_T
rt_LoggedStateNumDimensions [ ] = { 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1
, 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 } ; static int_T
rt_LoggedStateDimensions [ ] = { 1 , 1 , 1 , 1 , 2 , 2 , 2 , 2 , 2 , 2 , 2 ,
2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 } ; static boolean_T
rt_LoggedStateIsVarDims [ ] = { 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0
, 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 } ; static BuiltInDTypeId
rt_LoggedStateDataTypeIds [ ] = { SS_DOUBLE , SS_DOUBLE , SS_DOUBLE ,
SS_DOUBLE , SS_DOUBLE , SS_DOUBLE , SS_DOUBLE , SS_DOUBLE , SS_DOUBLE ,
SS_DOUBLE , SS_DOUBLE , SS_DOUBLE , SS_DOUBLE , SS_DOUBLE , SS_DOUBLE ,
SS_DOUBLE , SS_DOUBLE , SS_DOUBLE , SS_DOUBLE , SS_DOUBLE , SS_DOUBLE ,
SS_DOUBLE } ; static int_T rt_LoggedStateComplexSignals [ ] = { 0 , 0 , 0 , 0
, 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 } ;
static const char_T * rt_LoggedStateLabels [ ] = { "CSTATE" , "CSTATE" ,
"CSTATE" , "CSTATE" , "discrete" , "discrete" , "discrete" , "discrete" ,
"discrete" , "discrete" , "discrete" , "discrete" , "discrete" , "discrete" ,
"discrete" , "discrete" , "discrete" , "discrete" , "discrete" , "discrete" ,
"discrete" , "discrete" } ; static const char_T * rt_LoggedStateBlockNames [
] = { "foswec/Rotational PTO (Local RY)/Pitch PCC  (Revolute Joint)" ,
"foswec/Rotational PTO (Local RY)/Pitch PCC  (Revolute Joint)" ,
"foswec/Rotational PTO (Local RY)1/Pitch PCC  (Revolute Joint)" ,
"foswec/Rotational PTO (Local RY)1/Pitch PCC  (Revolute Joint)" ,
"foswec/Global Reference Frame1/Solver\nConfiguration/EVAL_KEY/INPUT_1_1_1" ,
"foswec/Global Reference Frame1/Solver\nConfiguration/EVAL_KEY/INPUT_1_1_2" ,
"foswec/Global Reference Frame1/Solver\nConfiguration/EVAL_KEY/INPUT_1_1_3" ,
"foswec/Global Reference Frame1/Solver\nConfiguration/EVAL_KEY/INPUT_2_1_1" ,
"foswec/Global Reference Frame1/Solver\nConfiguration/EVAL_KEY/INPUT_2_1_2" ,
"foswec/Global Reference Frame1/Solver\nConfiguration/EVAL_KEY/INPUT_2_1_3" ,
"foswec/Global Reference Frame1/Solver\nConfiguration/EVAL_KEY/INPUT_3_1_1" ,
"foswec/Global Reference Frame1/Solver\nConfiguration/EVAL_KEY/INPUT_3_1_2" ,
"foswec/Global Reference Frame1/Solver\nConfiguration/EVAL_KEY/INPUT_3_1_3" ,
"foswec/Global Reference Frame1/Solver\nConfiguration/EVAL_KEY/INPUT_4_1_1" ,
"foswec/Global Reference Frame1/Solver\nConfiguration/EVAL_KEY/INPUT_4_1_2" ,
"foswec/Global Reference Frame1/Solver\nConfiguration/EVAL_KEY/INPUT_4_1_3" ,
"foswec/Global Reference Frame1/Solver\nConfiguration/EVAL_KEY/INPUT_5_1_1" ,
"foswec/Global Reference Frame1/Solver\nConfiguration/EVAL_KEY/INPUT_5_1_2" ,
"foswec/Global Reference Frame1/Solver\nConfiguration/EVAL_KEY/INPUT_5_1_3" ,
"foswec/Global Reference Frame1/Solver\nConfiguration/EVAL_KEY/INPUT_6_1_1" ,
"foswec/Global Reference Frame1/Solver\nConfiguration/EVAL_KEY/INPUT_6_1_2" ,
"foswec/Global Reference Frame1/Solver\nConfiguration/EVAL_KEY/INPUT_6_1_3" }
; static const char_T * rt_LoggedStateNames [ ] = {
"Rotational_PTO_Local_RY.Pitch_PCC_Revolute_Joint.Rz.q" ,
"Rotational_PTO_Local_RY.Pitch_PCC_Revolute_Joint.Rz.w" ,
"Rotational_PTO_Local_RY1.Pitch_PCC_Revolute_Joint.Rz.q" ,
"Rotational_PTO_Local_RY1.Pitch_PCC_Revolute_Joint.Rz.w" , "" , "" , "" , ""
, "" , "" , "" , "" , "" , "" , "" , "" , "" , "" , "" , "" , "" , "" } ;
static boolean_T rt_LoggedStateCrossMdlRef [ ] = { 0 , 0 , 0 , 0 , 0 , 0 , 0
, 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 } ; static
RTWLogDataTypeConvert rt_RTWLogDataTypeConvert [ ] = { { 0 , SS_DOUBLE ,
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
0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 ,
SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE ,
SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0
, 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 ,
0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 ,
SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE ,
SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0
, 0 , 1.0 , 0 , 0.0 } } ; static RTWLogSignalInfo rt_LoggedStateSignalInfo =
{ 22 , rt_LoggedStateWidths , rt_LoggedStateNumDimensions ,
rt_LoggedStateDimensions , rt_LoggedStateIsVarDims , ( NULL ) , ( NULL ) ,
rt_LoggedStateDataTypeIds , rt_LoggedStateComplexSignals , ( NULL ) , {
rt_LoggedStateLabels } , ( NULL ) , ( NULL ) , ( NULL ) , {
rt_LoggedStateBlockNames } , { rt_LoggedStateNames } ,
rt_LoggedStateCrossMdlRef , rt_RTWLogDataTypeConvert } ; static void *
rt_LoggedStateSignalPtrs [ 22 ] ; rtliSetLogXSignalPtrs ( ssGetRTWLogInfo (
rtS ) , ( LogSignalPtrsType ) rt_LoggedStateSignalPtrs ) ;
rtliSetLogXSignalInfo ( ssGetRTWLogInfo ( rtS ) , & rt_LoggedStateSignalInfo
) ; rt_LoggedStateSignalPtrs [ 0 ] = ( void * ) & rtX . h5zfgvmg3r [ 0 ] ;
rt_LoggedStateSignalPtrs [ 1 ] = ( void * ) & rtX . h5zfgvmg3r [ 1 ] ;
rt_LoggedStateSignalPtrs [ 2 ] = ( void * ) & rtX . h5zfgvmg3r [ 2 ] ;
rt_LoggedStateSignalPtrs [ 3 ] = ( void * ) & rtX . h5zfgvmg3r [ 3 ] ;
rt_LoggedStateSignalPtrs [ 4 ] = ( void * ) rtDW . okejdpgu1c ;
rt_LoggedStateSignalPtrs [ 5 ] = ( void * ) rtDW . k4kmsogsl5 ;
rt_LoggedStateSignalPtrs [ 6 ] = ( void * ) rtDW . ihegmmijy4 ;
rt_LoggedStateSignalPtrs [ 7 ] = ( void * ) rtDW . ojcm0w354h ;
rt_LoggedStateSignalPtrs [ 8 ] = ( void * ) rtDW . e2rajb5jef ;
rt_LoggedStateSignalPtrs [ 9 ] = ( void * ) rtDW . d1dr20wbil ;
rt_LoggedStateSignalPtrs [ 10 ] = ( void * ) rtDW . nbmftfajwj ;
rt_LoggedStateSignalPtrs [ 11 ] = ( void * ) rtDW . d4bgxhw4kx ;
rt_LoggedStateSignalPtrs [ 12 ] = ( void * ) rtDW . knlt4i5nhu ;
rt_LoggedStateSignalPtrs [ 13 ] = ( void * ) rtDW . phzhuqqbqj ;
rt_LoggedStateSignalPtrs [ 14 ] = ( void * ) rtDW . dblqjhlznj ;
rt_LoggedStateSignalPtrs [ 15 ] = ( void * ) rtDW . dwhzhgdlwe ;
rt_LoggedStateSignalPtrs [ 16 ] = ( void * ) rtDW . g4w5whunn0 ;
rt_LoggedStateSignalPtrs [ 17 ] = ( void * ) rtDW . ihejtbnivo ;
rt_LoggedStateSignalPtrs [ 18 ] = ( void * ) rtDW . kv0fr1ezds ;
rt_LoggedStateSignalPtrs [ 19 ] = ( void * ) rtDW . jvtm2q20yi ;
rt_LoggedStateSignalPtrs [ 20 ] = ( void * ) rtDW . csqplvugez ;
rt_LoggedStateSignalPtrs [ 21 ] = ( void * ) rtDW . b2ebqtdjfn ; }
rtliSetLogT ( ssGetRTWLogInfo ( rtS ) , "tout" ) ; rtliSetLogX (
ssGetRTWLogInfo ( rtS ) , "tmp_raccel_xout" ) ; rtliSetLogXFinal (
ssGetRTWLogInfo ( rtS ) , "xFinal" ) ; rtliSetLogVarNameModifier (
ssGetRTWLogInfo ( rtS ) , "none" ) ; rtliSetLogFormat ( ssGetRTWLogInfo ( rtS
) , 2 ) ; rtliSetLogMaxRows ( ssGetRTWLogInfo ( rtS ) , 1000 ) ;
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
contStatesDisabled ) ; } ssSetChecksumVal ( rtS , 0 , 4188621712U ) ;
ssSetChecksumVal ( rtS , 1 , 2115538234U ) ; ssSetChecksumVal ( rtS , 2 ,
615640652U ) ; ssSetChecksumVal ( rtS , 3 , 871521442U ) ; { static const
sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE ; static RTWExtModeInfo
rt_ExtModeInfo ; static const sysRanDType * systemRan [ 25 ] ;
ssSetRTWExtModeInfo ( rtS , & rt_ExtModeInfo ) ;
rteiSetSubSystemActiveVectorAddresses ( & rt_ExtModeInfo , systemRan ) ;
systemRan [ 0 ] = & rtAlwaysEnabled ; systemRan [ 1 ] = & rtAlwaysEnabled ;
systemRan [ 2 ] = ( sysRanDType * ) & rtDW . cnj3cuyx4ul . cvx5ycrffh ;
systemRan [ 3 ] = ( sysRanDType * ) & rtDW . h02m5m2hejt . ljbrchkhk1 ;
systemRan [ 4 ] = ( sysRanDType * ) & rtDW . h02m5m2hejt . ljbrchkhk1 ;
systemRan [ 5 ] = ( sysRanDType * ) & rtDW . h02m5m2hejt . ljbrchkhk1 ;
systemRan [ 6 ] = ( sysRanDType * ) & rtDW . coaxej2udzm . oqsczzj035 ;
systemRan [ 7 ] = ( sysRanDType * ) & rtDW . fzybd15s0q0 . gnrlcinhso ;
systemRan [ 8 ] = & rtAlwaysEnabled ; systemRan [ 9 ] = & rtAlwaysEnabled ;
systemRan [ 10 ] = ( sysRanDType * ) & rtDW . msblmfssu1 . cvx5ycrffh ;
systemRan [ 11 ] = ( sysRanDType * ) & rtDW . fkat0ywnxz . ljbrchkhk1 ;
systemRan [ 12 ] = ( sysRanDType * ) & rtDW . fkat0ywnxz . ljbrchkhk1 ;
systemRan [ 13 ] = ( sysRanDType * ) & rtDW . fkat0ywnxz . ljbrchkhk1 ;
systemRan [ 14 ] = ( sysRanDType * ) & rtDW . a1tdc130d3 . oqsczzj035 ;
systemRan [ 15 ] = ( sysRanDType * ) & rtDW . h5j4mvdijc . gnrlcinhso ;
systemRan [ 16 ] = & rtAlwaysEnabled ; systemRan [ 17 ] = & rtAlwaysEnabled ;
systemRan [ 18 ] = ( sysRanDType * ) & rtDW . apfdt1mk1s . cvx5ycrffh ;
systemRan [ 19 ] = ( sysRanDType * ) & rtDW . ogpjwh504b . ljbrchkhk1 ;
systemRan [ 20 ] = ( sysRanDType * ) & rtDW . ogpjwh504b . ljbrchkhk1 ;
systemRan [ 21 ] = ( sysRanDType * ) & rtDW . ogpjwh504b . ljbrchkhk1 ;
systemRan [ 22 ] = ( sysRanDType * ) & rtDW . i00ohkzxv2 . oqsczzj035 ;
systemRan [ 23 ] = ( sysRanDType * ) & rtDW . fmempv5ety . gnrlcinhso ;
systemRan [ 24 ] = & rtAlwaysEnabled ; rteiSetModelMappingInfoPtr (
ssGetRTWExtModeInfo ( rtS ) , & ssGetModelMappingInfo ( rtS ) ) ;
rteiSetChecksumsPtr ( ssGetRTWExtModeInfo ( rtS ) , ssGetChecksums ( rtS ) )
; rteiSetTPtr ( ssGetRTWExtModeInfo ( rtS ) , ssGetTPtr ( rtS ) ) ; } return
rtS ; }
