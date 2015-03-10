#include "__cf_RM3.h"
#include "rtw_capi.h"
#ifdef HOST_CAPI_BUILD
#include "RM3_capi_host.h"
#define sizeof(s) ((size_t)(0xFFFF))
#undef rt_offsetof
#define rt_offsetof(s,el) ((uint16_T)(0xFFFF))
#define TARGET_CONST
#define TARGET_STRING(s) (s)    
#else
#include "builtin_typeid_types.h"
#include "RM3.h"
#include "RM3_private.h"
#ifdef LIGHT_WEIGHT_CAPI
#define TARGET_CONST                  
#define TARGET_STRING(s)               (NULL)                    
#else
#define TARGET_CONST                   const
#define TARGET_STRING(s)               (s)
#endif
#endif
static const rtwCAPI_Signals rtBlockSignals [ ] = { { 0 , 0 , TARGET_STRING (
"RM3/Global Reference Frame/Clock" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 ,
0 } , { 1 , 0 , TARGET_STRING ( "RM3/Rigid Body/Sum" ) , TARGET_STRING ( "" )
, 0 , 0 , 1 , 0 , 0 } , { 2 , 0 , TARGET_STRING ( "RM3/Rigid Body1/Sum" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 1 , 0 , 0 } , { 3 , 0 , TARGET_STRING (
"RM3/Rigid Body/Additional Linear Damping Force Calculation/Linear Damping" )
, TARGET_STRING ( "F_LinearDamping" ) , 0 , 0 , 1 , 0 , 0 } , { 4 , 0 ,
TARGET_STRING (
 "RM3/Rigid Body/Hydrostatic Restoring Force Calculation/Add Gravity Force  to Z-Direction"
) , TARGET_STRING ( "" ) , 0 , 0 , 1 , 0 , 1 } , { 5 , 0 , TARGET_STRING (
"RM3/Rigid Body/Hydrostatic Restoring Force Calculation/Add1" ) ,
TARGET_STRING ( "F_Restoring" ) , 0 , 0 , 1 , 0 , 0 } , { 6 , 0 ,
TARGET_STRING ( "RM3/Rigid Body/Mooring Force Calculation (Map)/sum" ) ,
TARGET_STRING ( "F_Mooring" ) , 0 , 0 , 1 , 0 , 0 } , { 7 , 0 , TARGET_STRING
( "RM3/Rigid Body/Viscous Damping Force Calculation/Viscous Damping" ) ,
TARGET_STRING ( "F_Viscous" ) , 0 , 0 , 1 , 0 , 0 } , { 8 , 0 , TARGET_STRING
(
 "RM3/Rigid Body/Wave Diffraction and Excitation Force Calculation/Applied Ramp Function"
) , TARGET_STRING ( "" ) , 0 , 0 , 1 , 0 , 0 } , { 9 , 0 , TARGET_STRING (
 "RM3/Rigid Body/Wave Diffraction and Excitation Force Calculation/No Ramp Function"
) , TARGET_STRING ( "" ) , 0 , 0 , 1 , 0 , 0 } , { 10 , 0 , TARGET_STRING (
"RM3/Rigid Body/Wave Diffraction and Excitation Force Calculation/Merge1" ) ,
TARGET_STRING ( "F_Excitation" ) , 0 , 0 , 1 , 0 , 0 } , { 11 , 0 ,
TARGET_STRING (
"RM3/Rigid Body/Wave Radiation Forces Calculation/Added Mass Forces" ) ,
TARGET_STRING ( "F_AddedMass" ) , 0 , 0 , 1 , 0 , 0 } , { 12 , 0 ,
TARGET_STRING (
"RM3/Rigid Body/Wave Radiation Forces Calculation/Sum of Elements" ) ,
TARGET_STRING ( "F_RadiationDamping" ) , 0 , 0 , 1 , 0 , 0 } , { 13 , 0 ,
TARGET_STRING (
"RM3/Rigid Body1/Additional Linear Damping Force Calculation/Linear Damping"
) , TARGET_STRING ( "F_LinearDamping" ) , 0 , 0 , 1 , 0 , 0 } , { 14 , 0 ,
TARGET_STRING (
 "RM3/Rigid Body1/Hydrostatic Restoring Force Calculation/Add Gravity Force  to Z-Direction"
) , TARGET_STRING ( "" ) , 0 , 0 , 1 , 0 , 1 } , { 15 , 0 , TARGET_STRING (
"RM3/Rigid Body1/Hydrostatic Restoring Force Calculation/Add1" ) ,
TARGET_STRING ( "F_Restoring" ) , 0 , 0 , 1 , 0 , 0 } , { 16 , 0 ,
TARGET_STRING ( "RM3/Rigid Body1/Mooring Force Calculation (Map)/sum" ) ,
TARGET_STRING ( "F_Mooring" ) , 0 , 0 , 1 , 0 , 0 } , { 17 , 0 ,
TARGET_STRING (
"RM3/Rigid Body1/Viscous Damping Force Calculation/Viscous Damping" ) ,
TARGET_STRING ( "F_Viscous" ) , 0 , 0 , 1 , 0 , 0 } , { 18 , 0 ,
TARGET_STRING (
 "RM3/Rigid Body1/Wave Diffraction and Excitation Force Calculation/Applied Ramp Function"
) , TARGET_STRING ( "" ) , 0 , 0 , 1 , 0 , 0 } , { 19 , 0 , TARGET_STRING (
 "RM3/Rigid Body1/Wave Diffraction and Excitation Force Calculation/No Ramp Function"
) , TARGET_STRING ( "" ) , 0 , 0 , 1 , 0 , 0 } , { 20 , 0 , TARGET_STRING (
"RM3/Rigid Body1/Wave Diffraction and Excitation Force Calculation/Merge1" )
, TARGET_STRING ( "F_Excitation" ) , 0 , 0 , 1 , 0 , 0 } , { 21 , 0 ,
TARGET_STRING (
"RM3/Rigid Body1/Wave Radiation Forces Calculation/Added Mass Forces" ) ,
TARGET_STRING ( "F_AddedMass" ) , 0 , 0 , 1 , 0 , 0 } , { 22 , 0 ,
TARGET_STRING (
"RM3/Rigid Body1/Wave Radiation Forces Calculation/Sum of Elements" ) ,
TARGET_STRING ( "F_RadiationDamping" ) , 0 , 0 , 1 , 0 , 0 } , { 23 , 0 ,
TARGET_STRING (
"RM3/Translational PTO  (Local Z)/ForceAndPower/Calculate Power" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 24 , 0 , TARGET_STRING (
"RM3/Translational PTO  (Local Z)/ForceAndPower/Add" ) , TARGET_STRING ( "" )
, 0 , 0 , 0 , 0 , 0 } , { 25 , 0 , TARGET_STRING (
"RM3/Global Reference Frame/Solver Configuration/EVAL_KEY/INPUT_1_1_1" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 2 , 0 , 0 } , { 26 , 0 , TARGET_STRING (
"RM3/Global Reference Frame/Solver Configuration/EVAL_KEY/INPUT_1_1_2" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 2 , 0 , 0 } , { 27 , 0 , TARGET_STRING (
"RM3/Global Reference Frame/Solver Configuration/EVAL_KEY/INPUT_1_1_3" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 2 , 0 , 0 } , { 28 , 0 , TARGET_STRING (
"RM3/Global Reference Frame/Solver Configuration/EVAL_KEY/INPUT_2_1_1" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 2 , 0 , 0 } , { 29 , 0 , TARGET_STRING (
"RM3/Global Reference Frame/Solver Configuration/EVAL_KEY/INPUT_2_1_2" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 2 , 0 , 0 } , { 30 , 0 , TARGET_STRING (
"RM3/Global Reference Frame/Solver Configuration/EVAL_KEY/INPUT_2_1_3" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 2 , 0 , 0 } , { 31 , 0 , TARGET_STRING (
"RM3/Global Reference Frame/Solver Configuration/EVAL_KEY/INPUT_3_1_1" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 2 , 0 , 0 } , { 32 , 0 , TARGET_STRING (
"RM3/Global Reference Frame/Solver Configuration/EVAL_KEY/INPUT_3_1_2" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 2 , 0 , 0 } , { 33 , 0 , TARGET_STRING (
"RM3/Global Reference Frame/Solver Configuration/EVAL_KEY/INPUT_3_1_3" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 2 , 0 , 0 } , { 34 , 0 , TARGET_STRING (
"RM3/Global Reference Frame/Solver Configuration/EVAL_KEY/INPUT_4_1_1" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 2 , 0 , 0 } , { 35 , 0 , TARGET_STRING (
"RM3/Global Reference Frame/Solver Configuration/EVAL_KEY/INPUT_4_1_2" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 2 , 0 , 0 } , { 36 , 0 , TARGET_STRING (
"RM3/Global Reference Frame/Solver Configuration/EVAL_KEY/INPUT_4_1_3" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 2 , 0 , 0 } , { 37 , 0 , TARGET_STRING (
"RM3/Global Reference Frame/Solver Configuration/EVAL_KEY/OUTPUT_1_0" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 3 , 0 , 0 } , { 38 , 0 , TARGET_STRING (
"RM3/Global Reference Frame/Solver Configuration/EVAL_KEY/OUTPUT_1_1" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 4 , 0 , 0 } , { 39 , 0 , TARGET_STRING (
"RM3/Global Reference Frame/Solver Configuration/EVAL_KEY/STATE_1" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 2 , 0 , 0 } , { 40 , 1 , TARGET_STRING (
"RM3/Rigid Body/Structure/Motion Sensor: Stucture Response/Angle" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 5 , 0 , 0 } , { 41 , 0 , TARGET_STRING (
 "RM3/Rigid Body/Wave Diffraction and Excitation Force Calculation/Applied Ramp Function/Divide"
) , TARGET_STRING ( "" ) , 0 , 0 , 1 , 0 , 0 } , { 42 , 0 , TARGET_STRING (
 "RM3/Rigid Body/Wave Diffraction and Excitation Force Calculation/No Ramp Function/In1"
) , TARGET_STRING ( "" ) , 0 , 0 , 1 , 0 , 0 } , { 43 , 9 , TARGET_STRING (
"RM3/Rigid Body1/Structure/Motion Sensor: Stucture Response/Angle" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 5 , 0 , 0 } , { 44 , 0 , TARGET_STRING (
 "RM3/Rigid Body1/Wave Diffraction and Excitation Force Calculation/Applied Ramp Function/Divide"
) , TARGET_STRING ( "" ) , 0 , 0 , 1 , 0 , 0 } , { 45 , 0 , TARGET_STRING (
 "RM3/Rigid Body1/Wave Diffraction and Excitation Force Calculation/No Ramp Function/In1"
) , TARGET_STRING ( "" ) , 0 , 0 , 1 , 0 , 0 } , { 0 , 0 , ( NULL ) , ( NULL
) , 0 , 0 , 0 , 0 , 0 } } ;
#ifndef HOST_CAPI_BUILD
static void * rtDataAddrMap [ ] = { & rtB . e3kvmjjnay , & rtB . oci4zspmmv [
0 ] , & rtB . edbqtdapxx [ 0 ] , & rtB . gvkcwsrbjc [ 0 ] , & rtB .
hbwwq3eobw [ 0 ] , & rtB . lodjazp425 [ 0 ] , & rtB . e25y0jyyb1 [ 0 ] , &
rtB . m1oa4qzzhe [ 0 ] , & rtB . gh1qfaqu5w [ 0 ] , & rtB . gh1qfaqu5w [ 0 ]
, & rtB . gh1qfaqu5w [ 0 ] , & rtB . prqhmb3ipp [ 0 ] , & rtB . fengm4fmax [
0 ] , & rtB . ahbtwvlwht [ 0 ] , & rtB . bsey3hhgmx [ 0 ] , & rtB .
dxffftz4xe [ 0 ] , & rtB . gxr43wuykr [ 0 ] , & rtB . jcjoil1xwx [ 0 ] , &
rtB . fn50r1iv2s [ 0 ] , & rtB . fn50r1iv2s [ 0 ] , & rtB . fn50r1iv2s [ 0 ]
, & rtB . jqhg2efiao [ 0 ] , & rtB . emwpmefl5g [ 0 ] , & rtB . mcslv3o4nz ,
& rtB . lle3duusb5 , & rtB . biiiks5bdq [ 0 ] , & rtB . bweohccgoh [ 0 ] , &
rtB . eyb1czk053 [ 0 ] , & rtB . hoyspdnpx3 [ 0 ] , & rtB . kia00mwvqk [ 0 ]
, & rtB . jr2ghgakgm [ 0 ] , & rtB . mionfsauuc [ 0 ] , & rtB . lkkej41yzf [
0 ] , & rtB . k02keb4tly [ 0 ] , & rtB . hoc2fuxv0g [ 0 ] , & rtB .
gbda5p2r2f [ 0 ] , & rtB . j1dwgbinuj [ 0 ] , & rtB . hahanrb1fp [ 0 ] , &
rtB . eygknao1u4 [ 0 ] , & rtB . pzk0tdps0y [ 0 ] , & rtB . hxduip3sjb .
pgkwjiqtkn [ 0 ] , & rtB . gh1qfaqu5w [ 0 ] , & rtB . gh1qfaqu5w [ 0 ] , &
rtB . gk1vvo5dud . pgkwjiqtkn [ 0 ] , & rtB . fn50r1iv2s [ 0 ] , & rtB .
fn50r1iv2s [ 0 ] , } ; static int32_T * rtVarDimsAddrMap [ ] = { ( NULL ) } ;
#endif
static TARGET_CONST rtwCAPI_DataTypeMap rtDataTypeMap [ ] = { { "double" ,
"real_T" , 0 , 0 , sizeof ( real_T ) , SS_DOUBLE , 0 , 0 } } ;
#ifdef HOST_CAPI_BUILD
#undef sizeof
#endif
static TARGET_CONST rtwCAPI_ElementMap rtElementMap [ ] = { { ( NULL ) , 0 ,
0 , 0 , 0 } , } ; static const rtwCAPI_DimensionMap rtDimensionMap [ ] = { {
rtwCAPI_SCALAR , 0 , 2 , 0 } , { rtwCAPI_VECTOR , 2 , 2 , 0 } , {
rtwCAPI_VECTOR , 4 , 2 , 0 } , { rtwCAPI_VECTOR , 6 , 2 , 0 } , {
rtwCAPI_VECTOR , 8 , 2 , 0 } , { rtwCAPI_VECTOR , 10 , 2 , 0 } } ; static
const uint_T rtDimensionArray [ ] = { 1 , 1 , 6 , 1 , 4 , 1 , 24 , 1 , 28 , 1
, 3 , 1 } ; static const real_T rtcapiStoredFloats [ ] = { 0.0 , 0.1 } ;
static const rtwCAPI_FixPtMap rtFixPtMap [ ] = { { ( NULL ) , ( NULL ) ,
rtwCAPI_FIX_RESERVED , 0 , 0 , 0 } , } ; static const rtwCAPI_SampleTimeMap
rtSampleTimeMap [ ] = { { ( const void * ) & rtcapiStoredFloats [ 0 ] , (
const void * ) & rtcapiStoredFloats [ 0 ] , 0 , 0 } , { ( const void * ) &
rtcapiStoredFloats [ 1 ] , ( const void * ) & rtcapiStoredFloats [ 0 ] , 1 ,
0 } } ; static rtwCAPI_ModelMappingStaticInfo mmiStatic = { { rtBlockSignals
, 46 , ( NULL ) , 0 , ( NULL ) , 0 } , { ( NULL ) , 0 , ( NULL ) , 0 } , { (
NULL ) , 0 } , { rtDataTypeMap , rtDimensionMap , rtFixPtMap , rtElementMap ,
rtSampleTimeMap , rtDimensionArray } , "float" , { 1252914586U , 3362424525U
, 2296161348U , 934207540U } , ( NULL ) , 0 } ; const
rtwCAPI_ModelMappingStaticInfo * RM3_GetCAPIStaticMap ( ) { return &
mmiStatic ; }
#ifndef HOST_CAPI_BUILD
void RM3_InitializeDataMapInfo ( SimStruct * const rtS ) { rtwCAPI_SetVersion
( ( * rt_dataMapInfoPtr ) . mmi , 1 ) ; rtwCAPI_SetStaticMap ( ( *
rt_dataMapInfoPtr ) . mmi , & mmiStatic ) ; rtwCAPI_SetLoggingStaticMap ( ( *
rt_dataMapInfoPtr ) . mmi , ( NULL ) ) ; rtwCAPI_SetDataAddressMap ( ( *
rt_dataMapInfoPtr ) . mmi , rtDataAddrMap ) ; rtwCAPI_SetVarDimsAddressMap (
( * rt_dataMapInfoPtr ) . mmi , rtVarDimsAddrMap ) ;
rtwCAPI_SetInstanceLoggingInfo ( ( * rt_dataMapInfoPtr ) . mmi , ( NULL ) ) ;
rtwCAPI_SetChildMMIArray ( ( * rt_dataMapInfoPtr ) . mmi , ( NULL ) ) ;
rtwCAPI_SetChildMMIArrayLen ( ( * rt_dataMapInfoPtr ) . mmi , 0 ) ; }
#else
#ifdef __cplusplus
extern "C" {
#endif
void RM3_host_InitializeDataMapInfo ( RM3_host_DataMapInfo_T * dataMap ,
const char * path ) { rtwCAPI_SetVersion ( dataMap -> mmi , 1 ) ;
rtwCAPI_SetStaticMap ( dataMap -> mmi , & mmiStatic ) ;
rtwCAPI_SetDataAddressMap ( dataMap -> mmi , NULL ) ;
rtwCAPI_SetVarDimsAddressMap ( dataMap -> mmi , NULL ) ; rtwCAPI_SetPath (
dataMap -> mmi , path ) ; rtwCAPI_SetFullPath ( dataMap -> mmi , NULL ) ;
rtwCAPI_SetChildMMIArray ( dataMap -> mmi , ( NULL ) ) ;
rtwCAPI_SetChildMMIArrayLen ( dataMap -> mmi , 0 ) ; }
#ifdef __cplusplus
}
#endif
#endif
