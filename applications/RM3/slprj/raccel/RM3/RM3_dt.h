#include "__cf_RM3.h"
#include "ext_types.h"
static uint_T rtDataTypeSizes [ ] = { sizeof ( real_T ) , sizeof ( real32_T )
, sizeof ( int8_T ) , sizeof ( uint8_T ) , sizeof ( int16_T ) , sizeof (
uint16_T ) , sizeof ( int32_T ) , sizeof ( uint32_T ) , sizeof ( boolean_T )
, sizeof ( fcn_call_T ) , sizeof ( int_T ) , sizeof ( pointer_T ) , sizeof (
action_T ) , 2 * sizeof ( uint32_T ) } ; static const char_T *
rtDataTypeNames [ ] = { "real_T" , "real32_T" , "int8_T" , "uint8_T" ,
"int16_T" , "uint16_T" , "int32_T" , "uint32_T" , "boolean_T" , "fcn_call_T"
, "int_T" , "pointer_T" , "action_T" , "timer_uint32_pair_T" } ; static
DataTypeTransition rtBTransitions [ ] = { { ( char_T * ) ( & rtB . e3kvmjjnay
) , 0 , 0 , 361 } , { ( char_T * ) ( & rtB . gk1vvo5dud . pgkwjiqtkn [ 0 ] )
, 0 , 0 , 3 } , { ( char_T * ) ( & rtB . hxduip3sjb . pgkwjiqtkn [ 0 ] ) , 0
, 0 , 3 } , { ( char_T * ) ( & rtDW . jhsjwq4b1m [ 0 ] ) , 0 , 0 , 7240 } , {
( char_T * ) ( & rtDW . lm3sijg1j1 ) , 11 , 0 , 48 } , { ( char_T * ) ( &
rtDW . anmk1ei3yl . Tail [ 0 ] ) , 10 , 0 , 12 } , { ( char_T * ) ( & rtDW .
bxqmm1o411 ) , 2 , 0 , 4 } , { ( char_T * ) ( & rtDW . fk22kz5jyq ) , 8 , 0 ,
6 } , { ( char_T * ) ( & rtDW . cy14v3kgd2 . dbhao2hevj ) , 2 , 0 , 1 } , { (
char_T * ) ( & rtDW . kw4gz4nylz . ckdn4xd4hz ) , 2 , 0 , 1 } , { ( char_T *
) ( & rtDW . arvvtfsmo3 . ofnp3tiibi ) , 2 , 0 , 1 } , { ( char_T * ) ( &
rtDW . bt1qvoldbv . e2lhwvg4n3 ) , 2 , 0 , 1 } , { ( char_T * ) ( & rtDW .
p14hwlcq5ag . dbhao2hevj ) , 2 , 0 , 1 } , { ( char_T * ) ( & rtDW .
l1kcj50fwey . ckdn4xd4hz ) , 2 , 0 , 1 } , { ( char_T * ) ( & rtDW .
aqx150ksytr . ofnp3tiibi ) , 2 , 0 , 1 } , { ( char_T * ) ( & rtDW .
i0grvgounuc . e2lhwvg4n3 ) , 2 , 0 , 1 } } ; static DataTypeTransitionTable
rtBTransTable = { 16U , rtBTransitions } ; static DataTypeTransition
rtPTransitions [ ] = { { ( char_T * ) ( & rtP . DampingForces_Gain [ 0 ] ) ,
0 , 0 , 73746 } , { ( char_T * ) ( & rtP . kw4gz4nylz . Constant1_Value ) , 0
, 0 , 6 } , { ( char_T * ) ( & rtP . arvvtfsmo3 . ExcitationRePart2_Value [ 0
] ) , 0 , 0 , 16 } , { ( char_T * ) ( & rtP . arvvtfsmo3 . izalnoy5rm .
CosWaveFunction_Amp ) , 0 , 0 , 8 } , { ( char_T * ) ( & rtP . bt1qvoldbv .
CosWave_Amp ) , 0 , 0 , 20 } , { ( char_T * ) ( & rtP . l1kcj50fwey .
Constant1_Value ) , 0 , 0 , 6 } , { ( char_T * ) ( & rtP . aqx150ksytr .
ExcitationRePart2_Value [ 0 ] ) , 0 , 0 , 16 } , { ( char_T * ) ( & rtP .
aqx150ksytr . izalnoy5rm . CosWaveFunction_Amp ) , 0 , 0 , 8 } , { ( char_T *
) ( & rtP . i0grvgounuc . CosWave_Amp ) , 0 , 0 , 20 } } ; static
DataTypeTransitionTable rtPTransTable = { 9U , rtPTransitions } ;
