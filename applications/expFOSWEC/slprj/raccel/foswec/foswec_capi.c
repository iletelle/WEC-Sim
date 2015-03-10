#include "__cf_foswec.h"
#include "rtw_capi.h"
#ifdef HOST_CAPI_BUILD
#include "foswec_capi_host.h"
#define sizeof(s) ((size_t)(0xFFFF))
#undef rt_offsetof
#define rt_offsetof(s,el) ((uint16_T)(0xFFFF))
#define TARGET_CONST
#define TARGET_STRING(s) (s)    
#else
#include "builtin_typeid_types.h"
#include "foswec.h"
#include "foswec_private.h"
#ifdef LIGHT_WEIGHT_CAPI
#define TARGET_CONST                  
#define TARGET_STRING(s)               (NULL)                    
#else
#define TARGET_CONST                   const
#define TARGET_STRING(s)               (s)
#endif
#endif
static const rtwCAPI_Signals rtBlockSignals [ ] = { { 0 , 0 , TARGET_STRING (
"foswec/Flap 1/Sum" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 1 , 0
, TARGET_STRING ( "foswec/Flap 2/Sum" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 ,
0 , 0 } , { 2 , 0 , TARGET_STRING ( "foswec/Global Reference Frame1/Clock" )
, TARGET_STRING ( "" ) , 0 , 0 , 1 , 0 , 0 } , { 3 , 0 , TARGET_STRING (
"foswec/Platform/Sum" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 4 ,
0 , TARGET_STRING ( "foswec/Rotational PTO (Local RY)/Assignment" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 2 , 0 , 0 } , { 5 , 0 , TARGET_STRING (
"foswec/Rotational PTO (Local RY)/Assignment1" ) , TARGET_STRING ( "" ) , 0 ,
0 , 2 , 0 , 0 } , { 6 , 0 , TARGET_STRING (
"foswec/Rotational PTO (Local RY)1/Assignment" ) , TARGET_STRING ( "" ) , 0 ,
0 , 2 , 0 , 0 } , { 7 , 0 , TARGET_STRING (
"foswec/Rotational PTO (Local RY)1/Assignment1" ) , TARGET_STRING ( "" ) , 0
, 0 , 2 , 0 , 0 } , { 8 , 0 , TARGET_STRING (
"foswec/Flap 1/Additional Linear Damping Force Calculation/Linear Damping" )
, TARGET_STRING ( "F_LinearDamping" ) , 0 , 0 , 0 , 0 , 0 } , { 9 , 0 ,
TARGET_STRING (
 "foswec/Flap 1/Hydrostatic Restoring Force Calculation/Add Gravity Force  to Z-Direction"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 10 , 0 , TARGET_STRING (
"foswec/Flap 1/Hydrostatic Restoring Force Calculation/Add1" ) ,
TARGET_STRING ( "F_Restoring" ) , 0 , 0 , 0 , 0 , 0 } , { 11 , 0 ,
TARGET_STRING ( "foswec/Flap 1/Mooring Force Calculation (Map)/sum" ) ,
TARGET_STRING ( "F_Mooring" ) , 0 , 0 , 0 , 0 , 0 } , { 12 , 0 ,
TARGET_STRING (
"foswec/Flap 1/Viscous Damping Force Calculation/Viscous Damping" ) ,
TARGET_STRING ( "F_Viscous" ) , 0 , 0 , 0 , 0 , 0 } , { 13 , 0 ,
TARGET_STRING (
 "foswec/Flap 1/Wave Diffraction and Excitation Force Calculation/Applied Ramp Function"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 14 , 0 , TARGET_STRING (
 "foswec/Flap 1/Wave Diffraction and Excitation Force Calculation/No Ramp Function"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 15 , 0 , TARGET_STRING (
"foswec/Flap 1/Wave Diffraction and Excitation Force Calculation/Merge1" ) ,
TARGET_STRING ( "F_Excitation" ) , 0 , 0 , 0 , 0 , 0 } , { 16 , 8 ,
TARGET_STRING (
"foswec/Flap 1/Wave Radiation Forces Calculation/Fluid Memory" ) ,
TARGET_STRING ( "F_Convolution Integral" ) , 0 , 0 , 0 , 0 , 0 } , { 17 , 0 ,
TARGET_STRING (
"foswec/Flap 1/Wave Radiation Forces Calculation/Added Mass Forces" ) ,
TARGET_STRING ( "F_AddedMass" ) , 0 , 0 , 0 , 0 , 0 } , { 18 , 0 ,
TARGET_STRING (
"foswec/Flap 1/Wave Radiation Forces Calculation/Sum of Elements" ) ,
TARGET_STRING ( "F_RadiationDamping" ) , 0 , 0 , 0 , 0 , 0 } , { 19 , 0 ,
TARGET_STRING (
"foswec/Flap 2/Additional Linear Damping Force Calculation/Linear Damping" )
, TARGET_STRING ( "F_LinearDamping" ) , 0 , 0 , 0 , 0 , 0 } , { 20 , 0 ,
TARGET_STRING (
 "foswec/Flap 2/Hydrostatic Restoring Force Calculation/Add Gravity Force  to Z-Direction"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 21 , 0 , TARGET_STRING (
"foswec/Flap 2/Hydrostatic Restoring Force Calculation/Add1" ) ,
TARGET_STRING ( "F_Restoring" ) , 0 , 0 , 0 , 0 , 0 } , { 22 , 0 ,
TARGET_STRING ( "foswec/Flap 2/Mooring Force Calculation (Map)/sum" ) ,
TARGET_STRING ( "F_Mooring" ) , 0 , 0 , 0 , 0 , 0 } , { 23 , 0 ,
TARGET_STRING (
"foswec/Flap 2/Viscous Damping Force Calculation/Viscous Damping" ) ,
TARGET_STRING ( "F_Viscous" ) , 0 , 0 , 0 , 0 , 0 } , { 24 , 0 ,
TARGET_STRING (
 "foswec/Flap 2/Wave Diffraction and Excitation Force Calculation/Applied Ramp Function"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 25 , 0 , TARGET_STRING (
 "foswec/Flap 2/Wave Diffraction and Excitation Force Calculation/No Ramp Function"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 26 , 0 , TARGET_STRING (
"foswec/Flap 2/Wave Diffraction and Excitation Force Calculation/Merge1" ) ,
TARGET_STRING ( "F_Excitation" ) , 0 , 0 , 0 , 0 , 0 } , { 27 , 16 ,
TARGET_STRING (
"foswec/Flap 2/Wave Radiation Forces Calculation/Fluid Memory" ) ,
TARGET_STRING ( "F_Convolution Integral" ) , 0 , 0 , 0 , 0 , 0 } , { 28 , 0 ,
TARGET_STRING (
"foswec/Flap 2/Wave Radiation Forces Calculation/Added Mass Forces" ) ,
TARGET_STRING ( "F_AddedMass" ) , 0 , 0 , 0 , 0 , 0 } , { 29 , 0 ,
TARGET_STRING (
"foswec/Flap 2/Wave Radiation Forces Calculation/Sum of Elements" ) ,
TARGET_STRING ( "F_RadiationDamping" ) , 0 , 0 , 0 , 0 , 0 } , { 30 , 0 ,
TARGET_STRING (
"foswec/Platform/Additional Linear Damping Force Calculation/Linear Damping"
) , TARGET_STRING ( "F_LinearDamping" ) , 0 , 0 , 0 , 0 , 0 } , { 31 , 0 ,
TARGET_STRING (
 "foswec/Platform/Hydrostatic Restoring Force Calculation/Add Gravity Force  to Z-Direction"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 32 , 0 , TARGET_STRING (
"foswec/Platform/Hydrostatic Restoring Force Calculation/Add1" ) ,
TARGET_STRING ( "F_Restoring" ) , 0 , 0 , 0 , 0 , 0 } , { 33 , 0 ,
TARGET_STRING ( "foswec/Platform/Mooring Force Calculation (Map)/sum" ) ,
TARGET_STRING ( "F_Mooring" ) , 0 , 0 , 0 , 0 , 0 } , { 34 , 0 ,
TARGET_STRING (
"foswec/Platform/Viscous Damping Force Calculation/Viscous Damping" ) ,
TARGET_STRING ( "F_Viscous" ) , 0 , 0 , 0 , 0 , 0 } , { 35 , 0 ,
TARGET_STRING (
 "foswec/Platform/Wave Diffraction and Excitation Force Calculation/Applied Ramp Function"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 36 , 0 , TARGET_STRING (
 "foswec/Platform/Wave Diffraction and Excitation Force Calculation/No Ramp Function"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 37 , 0 , TARGET_STRING (
"foswec/Platform/Wave Diffraction and Excitation Force Calculation/Merge1" )
, TARGET_STRING ( "F_Excitation" ) , 0 , 0 , 0 , 0 , 0 } , { 38 , 24 ,
TARGET_STRING (
"foswec/Platform/Wave Radiation Forces Calculation/Fluid Memory" ) ,
TARGET_STRING ( "F_Convolution Integral" ) , 0 , 0 , 0 , 0 , 0 } , { 39 , 0 ,
TARGET_STRING (
"foswec/Platform/Wave Radiation Forces Calculation/Added Mass Forces" ) ,
TARGET_STRING ( "F_AddedMass" ) , 0 , 0 , 0 , 0 , 0 } , { 40 , 0 ,
TARGET_STRING (
"foswec/Platform/Wave Radiation Forces Calculation/Sum of Elements" ) ,
TARGET_STRING ( "F_RadiationDamping" ) , 0 , 0 , 0 , 0 , 0 } , { 41 , 0 ,
TARGET_STRING (
"foswec/Rotational PTO (Local RY)/ForceAndPower/Calculate Power" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 1 , 0 , 0 } , { 42 , 0 , TARGET_STRING (
"foswec/Rotational PTO (Local RY)/ForceAndPower/Add" ) , TARGET_STRING ( "" )
, 0 , 0 , 1 , 0 , 0 } , { 43 , 0 , TARGET_STRING (
"foswec/Rotational PTO (Local RY)1/ForceAndPower/Calculate Power" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 1 , 0 , 0 } , { 44 , 0 , TARGET_STRING (
"foswec/Rotational PTO (Local RY)1/ForceAndPower/Add" ) , TARGET_STRING ( ""
) , 0 , 0 , 1 , 0 , 0 } , { 45 , 1 , TARGET_STRING (
"foswec/Flap 1/Structure/Motion Sensor: Stucture Response/Angle" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 2 , 0 , 0 } , { 46 , 0 , TARGET_STRING (
 "foswec/Flap 1/Wave Diffraction and Excitation Force Calculation/Applied Ramp Function/Divide"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 47 , 0 , TARGET_STRING (
 "foswec/Flap 1/Wave Diffraction and Excitation Force Calculation/No Ramp Function/In1"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 48 , 9 , TARGET_STRING (
"foswec/Flap 2/Structure/Motion Sensor: Stucture Response/Angle" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 2 , 0 , 0 } , { 49 , 0 , TARGET_STRING (
 "foswec/Flap 2/Wave Diffraction and Excitation Force Calculation/Applied Ramp Function/Divide"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 50 , 0 , TARGET_STRING (
 "foswec/Flap 2/Wave Diffraction and Excitation Force Calculation/No Ramp Function/In1"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 51 , 0 , TARGET_STRING (
"foswec/Global Reference Frame1/Solver Configuration/EVAL_KEY/INPUT_1_1_1" )
, TARGET_STRING ( "" ) , 0 , 0 , 3 , 0 , 0 } , { 52 , 0 , TARGET_STRING (
"foswec/Global Reference Frame1/Solver Configuration/EVAL_KEY/INPUT_1_1_2" )
, TARGET_STRING ( "" ) , 0 , 0 , 3 , 0 , 0 } , { 53 , 0 , TARGET_STRING (
"foswec/Global Reference Frame1/Solver Configuration/EVAL_KEY/INPUT_1_1_3" )
, TARGET_STRING ( "" ) , 0 , 0 , 3 , 0 , 0 } , { 54 , 0 , TARGET_STRING (
"foswec/Global Reference Frame1/Solver Configuration/EVAL_KEY/INPUT_2_1_1" )
, TARGET_STRING ( "" ) , 0 , 0 , 3 , 0 , 0 } , { 55 , 0 , TARGET_STRING (
"foswec/Global Reference Frame1/Solver Configuration/EVAL_KEY/INPUT_2_1_2" )
, TARGET_STRING ( "" ) , 0 , 0 , 3 , 0 , 0 } , { 56 , 0 , TARGET_STRING (
"foswec/Global Reference Frame1/Solver Configuration/EVAL_KEY/INPUT_2_1_3" )
, TARGET_STRING ( "" ) , 0 , 0 , 3 , 0 , 0 } , { 57 , 0 , TARGET_STRING (
"foswec/Global Reference Frame1/Solver Configuration/EVAL_KEY/INPUT_3_1_1" )
, TARGET_STRING ( "" ) , 0 , 0 , 3 , 0 , 0 } , { 58 , 0 , TARGET_STRING (
"foswec/Global Reference Frame1/Solver Configuration/EVAL_KEY/INPUT_3_1_2" )
, TARGET_STRING ( "" ) , 0 , 0 , 3 , 0 , 0 } , { 59 , 0 , TARGET_STRING (
"foswec/Global Reference Frame1/Solver Configuration/EVAL_KEY/INPUT_3_1_3" )
, TARGET_STRING ( "" ) , 0 , 0 , 3 , 0 , 0 } , { 60 , 0 , TARGET_STRING (
"foswec/Global Reference Frame1/Solver Configuration/EVAL_KEY/INPUT_4_1_1" )
, TARGET_STRING ( "" ) , 0 , 0 , 3 , 0 , 0 } , { 61 , 0 , TARGET_STRING (
"foswec/Global Reference Frame1/Solver Configuration/EVAL_KEY/INPUT_4_1_2" )
, TARGET_STRING ( "" ) , 0 , 0 , 3 , 0 , 0 } , { 62 , 0 , TARGET_STRING (
"foswec/Global Reference Frame1/Solver Configuration/EVAL_KEY/INPUT_4_1_3" )
, TARGET_STRING ( "" ) , 0 , 0 , 3 , 0 , 0 } , { 63 , 0 , TARGET_STRING (
"foswec/Global Reference Frame1/Solver Configuration/EVAL_KEY/INPUT_5_1_1" )
, TARGET_STRING ( "" ) , 0 , 0 , 3 , 0 , 0 } , { 64 , 0 , TARGET_STRING (
"foswec/Global Reference Frame1/Solver Configuration/EVAL_KEY/INPUT_5_1_2" )
, TARGET_STRING ( "" ) , 0 , 0 , 3 , 0 , 0 } , { 65 , 0 , TARGET_STRING (
"foswec/Global Reference Frame1/Solver Configuration/EVAL_KEY/INPUT_5_1_3" )
, TARGET_STRING ( "" ) , 0 , 0 , 3 , 0 , 0 } , { 66 , 0 , TARGET_STRING (
"foswec/Global Reference Frame1/Solver Configuration/EVAL_KEY/INPUT_6_1_1" )
, TARGET_STRING ( "" ) , 0 , 0 , 3 , 0 , 0 } , { 67 , 0 , TARGET_STRING (
"foswec/Global Reference Frame1/Solver Configuration/EVAL_KEY/INPUT_6_1_2" )
, TARGET_STRING ( "" ) , 0 , 0 , 3 , 0 , 0 } , { 68 , 0 , TARGET_STRING (
"foswec/Global Reference Frame1/Solver Configuration/EVAL_KEY/INPUT_6_1_3" )
, TARGET_STRING ( "" ) , 0 , 0 , 3 , 0 , 0 } , { 69 , 0 , TARGET_STRING (
"foswec/Global Reference Frame1/Solver Configuration/EVAL_KEY/OUTPUT_1_0" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 4 , 0 , 0 } , { 70 , 0 , TARGET_STRING (
"foswec/Global Reference Frame1/Solver Configuration/EVAL_KEY/OUTPUT_1_1" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 5 , 0 , 0 } , { 71 , 0 , TARGET_STRING (
"foswec/Global Reference Frame1/Solver Configuration/EVAL_KEY/STATE_1" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 3 , 0 , 0 } , { 72 , 17 , TARGET_STRING (
"foswec/Platform/Structure/Motion Sensor: Stucture Response/Angle" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 2 , 0 , 0 } , { 73 , 0 , TARGET_STRING (
 "foswec/Platform/Wave Diffraction and Excitation Force Calculation/Applied Ramp Function/Divide"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 74 , 0 , TARGET_STRING (
 "foswec/Platform/Wave Diffraction and Excitation Force Calculation/No Ramp Function/In1"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 0 , 0 , ( NULL ) , ( NULL
) , 0 , 0 , 0 , 0 , 0 } } ;
#ifndef HOST_CAPI_BUILD
static void * rtDataAddrMap [ ] = { & rtB . b1n5unk4di [ 0 ] , & rtB .
edopdfd1hm [ 0 ] , & rtB . fyev0m4vsa , & rtB . okcf5s1hfi [ 0 ] , & rtB .
euklvqzjnb [ 0 ] , & rtB . pr2wmuatwp [ 0 ] , & rtB . mb24q41lpq [ 0 ] , &
rtB . g5gg5rwfxi [ 0 ] , & rtB . merar43jbg [ 0 ] , & rtB . euxjdg3wyk [ 0 ]
, & rtB . dlr5ya0rha [ 0 ] , & rtB . ihnthpc5j1 [ 0 ] , & rtB . pr41rtecbf [
0 ] , & rtB . dhfvei2wiq [ 0 ] , & rtB . dhfvei2wiq [ 0 ] , & rtB .
dhfvei2wiq [ 0 ] , & rtB . arymfxlfvv . jmbenplned [ 0 ] , & rtB . pnsa2f20mr
[ 0 ] , & rtB . hqtb5p5515 [ 0 ] , & rtB . amxl55ezpx [ 0 ] , & rtB .
o5jrwx140d [ 0 ] , & rtB . ggc0r0fx3g [ 0 ] , & rtB . ihg0r14bhr [ 0 ] , &
rtB . njnofax133 [ 0 ] , & rtB . pj144ebf30 [ 0 ] , & rtB . pj144ebf30 [ 0 ]
, & rtB . pj144ebf30 [ 0 ] , & rtB . hbwafuhekh . jmbenplned [ 0 ] , & rtB .
jcuedl2jnj [ 0 ] , & rtB . b3fkm4fcdn [ 0 ] , & rtB . ialr351o51 [ 0 ] , &
rtB . lkgzajb1kd [ 0 ] , & rtB . muoixesghk [ 0 ] , & rtB . j4t0l5sh1l [ 0 ]
, & rtB . jeu1moqvun [ 0 ] , & rtB . fnesyp43ae [ 0 ] , & rtB . fnesyp43ae [
0 ] , & rtB . fnesyp43ae [ 0 ] , & rtB . ipyob4ujct . jmbenplned [ 0 ] , &
rtB . hdrzhitnck [ 0 ] , & rtB . e0ns1clddv [ 0 ] , & rtB . gdetjhzpld , &
rtB . miwvnyxkwg , & rtB . jcjac2h4yl , & rtB . l2wrpxekcz , & rtB .
nd0v2sbydt . c0mvqybgil [ 0 ] , & rtB . dhfvei2wiq [ 0 ] , & rtB . dhfvei2wiq
[ 0 ] , & rtB . evtto0adau . c0mvqybgil [ 0 ] , & rtB . pj144ebf30 [ 0 ] , &
rtB . pj144ebf30 [ 0 ] , & rtB . p1qklr3iem [ 0 ] , & rtB . dzcyvgjss1 [ 0 ]
, & rtB . kyqswxndxu [ 0 ] , & rtB . os0vmujie2 [ 0 ] , & rtB . f5vdxtzttp [
0 ] , & rtB . ny3ji5snoz [ 0 ] , & rtB . kgii2iaa1l [ 0 ] , & rtB .
jfce0w0ghr [ 0 ] , & rtB . pcf0pfmweo [ 0 ] , & rtB . if52phrmag [ 0 ] , &
rtB . mocddkrpki [ 0 ] , & rtB . kzwkda2ehh [ 0 ] , & rtB . hmeg1w5jim [ 0 ]
, & rtB . nbocq1o42k [ 0 ] , & rtB . d5a52isphm [ 0 ] , & rtB . icy3aei5aw [
0 ] , & rtB . add5kxxow3 [ 0 ] , & rtB . oigl01ewmc [ 0 ] , & rtB .
l5ibfslonp [ 0 ] , & rtB . blpo5iedij [ 0 ] , & rtB . gja4dzl325 [ 0 ] , &
rtB . iluwjccpxx . c0mvqybgil [ 0 ] , & rtB . fnesyp43ae [ 0 ] , & rtB .
fnesyp43ae [ 0 ] , } ; static int32_T * rtVarDimsAddrMap [ ] = { ( NULL ) } ;
#endif
static TARGET_CONST rtwCAPI_DataTypeMap rtDataTypeMap [ ] = { { "double" ,
"real_T" , 0 , 0 , sizeof ( real_T ) , SS_DOUBLE , 0 , 0 } } ;
#ifdef HOST_CAPI_BUILD
#undef sizeof
#endif
static TARGET_CONST rtwCAPI_ElementMap rtElementMap [ ] = { { ( NULL ) , 0 ,
0 , 0 , 0 } , } ; static const rtwCAPI_DimensionMap rtDimensionMap [ ] = { {
rtwCAPI_VECTOR , 0 , 2 , 0 } , { rtwCAPI_SCALAR , 2 , 2 , 0 } , {
rtwCAPI_VECTOR , 4 , 2 , 0 } , { rtwCAPI_VECTOR , 6 , 2 , 0 } , {
rtwCAPI_VECTOR , 8 , 2 , 0 } , { rtwCAPI_VECTOR , 10 , 2 , 0 } } ; static
const uint_T rtDimensionArray [ ] = { 6 , 1 , 1 , 1 , 3 , 1 , 4 , 1 , 36 , 1
, 43 , 1 } ; static const real_T rtcapiStoredFloats [ ] = { 0.0 , 0.07 } ;
static const rtwCAPI_FixPtMap rtFixPtMap [ ] = { { ( NULL ) , ( NULL ) ,
rtwCAPI_FIX_RESERVED , 0 , 0 , 0 } , } ; static const rtwCAPI_SampleTimeMap
rtSampleTimeMap [ ] = { { ( const void * ) & rtcapiStoredFloats [ 0 ] , (
const void * ) & rtcapiStoredFloats [ 0 ] , 0 , 0 } , { ( const void * ) &
rtcapiStoredFloats [ 1 ] , ( const void * ) & rtcapiStoredFloats [ 0 ] , 1 ,
0 } } ; static rtwCAPI_ModelMappingStaticInfo mmiStatic = { { rtBlockSignals
, 75 , ( NULL ) , 0 , ( NULL ) , 0 } , { ( NULL ) , 0 , ( NULL ) , 0 } , { (
NULL ) , 0 } , { rtDataTypeMap , rtDimensionMap , rtFixPtMap , rtElementMap ,
rtSampleTimeMap , rtDimensionArray } , "float" , { 4188621712U , 2115538234U
, 615640652U , 871521442U } , ( NULL ) , 0 } ; const
rtwCAPI_ModelMappingStaticInfo * foswec_GetCAPIStaticMap ( ) { return &
mmiStatic ; }
#ifndef HOST_CAPI_BUILD
void foswec_InitializeDataMapInfo ( SimStruct * const rtS ) {
rtwCAPI_SetVersion ( ( * rt_dataMapInfoPtr ) . mmi , 1 ) ;
rtwCAPI_SetStaticMap ( ( * rt_dataMapInfoPtr ) . mmi , & mmiStatic ) ;
rtwCAPI_SetLoggingStaticMap ( ( * rt_dataMapInfoPtr ) . mmi , ( NULL ) ) ;
rtwCAPI_SetDataAddressMap ( ( * rt_dataMapInfoPtr ) . mmi , rtDataAddrMap ) ;
rtwCAPI_SetVarDimsAddressMap ( ( * rt_dataMapInfoPtr ) . mmi ,
rtVarDimsAddrMap ) ; rtwCAPI_SetInstanceLoggingInfo ( ( * rt_dataMapInfoPtr )
. mmi , ( NULL ) ) ; rtwCAPI_SetChildMMIArray ( ( * rt_dataMapInfoPtr ) . mmi
, ( NULL ) ) ; rtwCAPI_SetChildMMIArrayLen ( ( * rt_dataMapInfoPtr ) . mmi ,
0 ) ; }
#else
#ifdef __cplusplus
extern "C" {
#endif
void foswec_host_InitializeDataMapInfo ( foswec_host_DataMapInfo_T * dataMap
, const char * path ) { rtwCAPI_SetVersion ( dataMap -> mmi , 1 ) ;
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
