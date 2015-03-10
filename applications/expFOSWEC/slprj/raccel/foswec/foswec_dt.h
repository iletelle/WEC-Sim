#include "__cf_foswec.h"
#include "ext_types.h"
static uint_T rtDataTypeSizes [ ] = { sizeof ( real_T ) , sizeof ( real32_T )
, sizeof ( int8_T ) , sizeof ( uint8_T ) , sizeof ( int16_T ) , sizeof (
uint16_T ) , sizeof ( int32_T ) , sizeof ( uint32_T ) , sizeof ( boolean_T )
, sizeof ( fcn_call_T ) , sizeof ( int_T ) , sizeof ( pointer_T ) , sizeof (
action_T ) , 2 * sizeof ( uint32_T ) } ; static const char_T *
rtDataTypeNames [ ] = { "real_T" , "real32_T" , "int8_T" , "uint8_T" ,
"int16_T" , "uint16_T" , "int32_T" , "uint32_T" , "boolean_T" , "fcn_call_T"
, "int_T" , "pointer_T" , "action_T" , "timer_uint32_pair_T" } ; static
DataTypeTransition rtBTransitions [ ] = { { ( char_T * ) ( & rtB . gja4dzl325
[ 0 ] ) , 0 , 0 , 554 } , { ( char_T * ) ( & rtB . ipyob4ujct . jmbenplned [
0 ] ) , 0 , 0 , 6 } , { ( char_T * ) ( & rtB . iluwjccpxx . c0mvqybgil [ 0 ]
) , 0 , 0 , 3 } , { ( char_T * ) ( & rtB . hbwafuhekh . jmbenplned [ 0 ] ) ,
0 , 0 , 6 } , { ( char_T * ) ( & rtB . evtto0adau . c0mvqybgil [ 0 ] ) , 0 ,
0 , 3 } , { ( char_T * ) ( & rtB . arymfxlfvv . jmbenplned [ 0 ] ) , 0 , 0 ,
6 } , { ( char_T * ) ( & rtB . nd0v2sbydt . c0mvqybgil [ 0 ] ) , 0 , 0 , 3 }
, { ( char_T * ) ( & rtDW . okejdpgu1c [ 0 ] ) , 0 , 0 , 39 } , { ( char_T *
) ( & rtDW . pyei4aktas ) , 11 , 0 , 62 } , { ( char_T * ) ( & rtDW .
iie0k52gf2 . Tail [ 0 ] ) , 10 , 0 , 18 } , { ( char_T * ) ( & rtDW .
gl2utjnv03 ) , 2 , 0 , 6 } , { ( char_T * ) ( & rtDW . hmp4wnm12v ) , 8 , 0 ,
4 } , { ( char_T * ) ( & rtDW . ipyob4ujct . cl4bth31oo [ 0 ] ) , 0 , 0 ,
5155 } , { ( char_T * ) ( & rtDW . ipyob4ujct . fazqyerxsu ) , 8 , 0 , 1 } ,
{ ( char_T * ) ( & rtDW . i00ohkzxv2 . oqsczzj035 ) , 2 , 0 , 1 } , { (
char_T * ) ( & rtDW . apfdt1mk1s . cvx5ycrffh ) , 2 , 0 , 1 } , { ( char_T *
) ( & rtDW . ogpjwh504b . ljbrchkhk1 ) , 2 , 0 , 1 } , { ( char_T * ) ( &
rtDW . fmempv5ety . gnrlcinhso ) , 2 , 0 , 1 } , { ( char_T * ) ( & rtDW .
hbwafuhekh . cl4bth31oo [ 0 ] ) , 0 , 0 , 5155 } , { ( char_T * ) ( & rtDW .
hbwafuhekh . fazqyerxsu ) , 8 , 0 , 1 } , { ( char_T * ) ( & rtDW .
a1tdc130d3 . oqsczzj035 ) , 2 , 0 , 1 } , { ( char_T * ) ( & rtDW .
msblmfssu1 . cvx5ycrffh ) , 2 , 0 , 1 } , { ( char_T * ) ( & rtDW .
fkat0ywnxz . ljbrchkhk1 ) , 2 , 0 , 1 } , { ( char_T * ) ( & rtDW .
h5j4mvdijc . gnrlcinhso ) , 2 , 0 , 1 } , { ( char_T * ) ( & rtDW .
arymfxlfvv . cl4bth31oo [ 0 ] ) , 0 , 0 , 5155 } , { ( char_T * ) ( & rtDW .
arymfxlfvv . fazqyerxsu ) , 8 , 0 , 1 } , { ( char_T * ) ( & rtDW .
coaxej2udzm . oqsczzj035 ) , 2 , 0 , 1 } , { ( char_T * ) ( & rtDW .
cnj3cuyx4ul . cvx5ycrffh ) , 2 , 0 , 1 } , { ( char_T * ) ( & rtDW .
h02m5m2hejt . ljbrchkhk1 ) , 2 , 0 , 1 } , { ( char_T * ) ( & rtDW .
fzybd15s0q0 . gnrlcinhso ) , 2 , 0 , 1 } } ; static DataTypeTransitionTable
rtBTransTable = { 30U , rtBTransitions } ; static DataTypeTransition
rtPTransitions [ ] = { { ( char_T * ) ( & rtP . DampingForces_Gain [ 0 ] ) ,
0 , 0 , 111456 } , { ( char_T * ) ( & rtP . apfdt1mk1s . Constant1_Value ) ,
0 , 0 , 6 } , { ( char_T * ) ( & rtP . ogpjwh504b . ExcitationRePart2_Value [
0 ] ) , 0 , 0 , 16 } , { ( char_T * ) ( & rtP . ogpjwh504b . hq5rtzuhum .
CosWaveFunction_Amp ) , 0 , 0 , 8 } , { ( char_T * ) ( & rtP . fmempv5ety .
CosWave_Amp ) , 0 , 0 , 20 } , { ( char_T * ) ( & rtP . msblmfssu1 .
Constant1_Value ) , 0 , 0 , 6 } , { ( char_T * ) ( & rtP . fkat0ywnxz .
ExcitationRePart2_Value [ 0 ] ) , 0 , 0 , 16 } , { ( char_T * ) ( & rtP .
fkat0ywnxz . hq5rtzuhum . CosWaveFunction_Amp ) , 0 , 0 , 8 } , { ( char_T *
) ( & rtP . h5j4mvdijc . CosWave_Amp ) , 0 , 0 , 20 } , { ( char_T * ) ( &
rtP . cnj3cuyx4ul . Constant1_Value ) , 0 , 0 , 6 } , { ( char_T * ) ( & rtP
. h02m5m2hejt . ExcitationRePart2_Value [ 0 ] ) , 0 , 0 , 16 } , { ( char_T *
) ( & rtP . h02m5m2hejt . hq5rtzuhum . CosWaveFunction_Amp ) , 0 , 0 , 8 } ,
{ ( char_T * ) ( & rtP . fzybd15s0q0 . CosWave_Amp ) , 0 , 0 , 20 } } ;
static DataTypeTransitionTable rtPTransTable = { 13U , rtPTransitions } ;
