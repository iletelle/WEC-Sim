#include "__cf_RM3.h"
#ifndef RTW_HEADER_RM3_h_
#define RTW_HEADER_RM3_h_
#include <stddef.h>
#include <float.h>
#include <string.h>
#include "rtw_modelmap.h"
#ifndef RM3_COMMON_INCLUDES_
#define RM3_COMMON_INCLUDES_
#include <stdlib.h>
#include "rtwtypes.h"
#include "simstruc.h"
#include "fixedpoint.h"
#include "raccel.h"
#include "rt_logging.h"
#include "dt_info.h"
#include "ext_work.h"
#include "nesl_rtw.h"
#include "RM3_fa9b5af1_gateway.h"
#endif
#include "RM3_types.h"
#include "multiword_types.h"
#include "mwmathutil.h"
#include "rt_defines.h"
#include "rtGetInf.h"
#include "rt_nonfinite.h"
#define MODEL_NAME RM3
#define NSAMPLE_TIMES (2) 
#define NINPUTS (0)       
#define NOUTPUTS (0)     
#define NBLOCKIO (44) 
#define NUM_ZC_EVENTS (0) 
#ifndef NCSTATES
#define NCSTATES (4)   
#elif NCSTATES != 4
#error Invalid specification of NCSTATES defined in compiler command
#endif
#ifndef rtmGetDataMapInfo
#define rtmGetDataMapInfo(rtm) (*rt_dataMapInfoPtr)
#endif
#ifndef rtmSetDataMapInfo
#define rtmSetDataMapInfo(rtm, val) (rt_dataMapInfoPtr = &val)
#endif
#ifndef IN_RACCEL_MAIN
#endif
typedef struct { real_T pgkwjiqtkn [ 3 ] ; } cfnnun40md ; typedef struct {
int8_T e2lhwvg4n3 ; } butlgtrn1o ; typedef struct { int8_T ofnp3tiibi ; }
hs2j2p43ts ; typedef struct { int8_T ckdn4xd4hz ; } lghbzftw4s ; typedef
struct { int8_T dbhao2hevj ; } h05eppclcz ; typedef struct { real_T
b4nvex32ha [ 3600 ] ; real_T imwy3hbauq [ 601 ] ; real_T l0kvxs4qr0 [ 601 ] ;
real_T nfec5adlu5 [ 601 ] ; real_T e3kvmjjnay ; real_T pzk0tdps0y [ 4 ] ;
real_T eygknao1u4 [ 28 ] ; real_T fengm4fmax [ 6 ] ; real_T prqhmb3ipp [ 6 ]
; real_T hbwwq3eobw [ 6 ] ; real_T lodjazp425 [ 6 ] ; real_T m1oa4qzzhe [ 6 ]
; real_T gvkcwsrbjc [ 6 ] ; real_T e25y0jyyb1 [ 6 ] ; real_T gh1qfaqu5w [ 6 ]
; real_T oci4zspmmv [ 6 ] ; real_T biiiks5bdq [ 4 ] ; real_T bweohccgoh [ 4 ]
; real_T eyb1czk053 [ 4 ] ; real_T hoyspdnpx3 [ 4 ] ; real_T kia00mwvqk [ 4 ]
; real_T jr2ghgakgm [ 4 ] ; real_T emwpmefl5g [ 6 ] ; real_T jqhg2efiao [ 6 ]
; real_T bsey3hhgmx [ 6 ] ; real_T dxffftz4xe [ 6 ] ; real_T jcjoil1xwx [ 6 ]
; real_T ahbtwvlwht [ 6 ] ; real_T gxr43wuykr [ 6 ] ; real_T fn50r1iv2s [ 6 ]
; real_T edbqtdapxx [ 6 ] ; real_T mionfsauuc [ 4 ] ; real_T lkkej41yzf [ 4 ]
; real_T k02keb4tly [ 4 ] ; real_T hoc2fuxv0g [ 4 ] ; real_T gbda5p2r2f [ 4 ]
; real_T j1dwgbinuj [ 4 ] ; real_T hahanrb1fp [ 24 ] ; real_T etx2cwdnb4 [ 6
] ; real_T o3ytx35x4v [ 66 ] ; real_T b13mdyyvoc [ 66 ] ; real_T lle3duusb5 ;
real_T mcslv3o4nz ; real_T ovrdoaeae5 [ 8 ] ; cfnnun40md gk1vvo5dud ;
cfnnun40md hxduip3sjb ; } B ; typedef struct { real_T jhsjwq4b1m [ 2 ] ;
real_T hvjbqhm5oo [ 2 ] ; real_T df3rh4z0gd [ 2 ] ; real_T owzp013kx2 [ 2 ] ;
real_T m3h1jcujy4 [ 2 ] ; real_T hts5jxxzji [ 2 ] ; real_T md4q5iksqt [ 2 ] ;
real_T mbkovhbhoz [ 2 ] ; real_T mfpmp4gwws [ 2 ] ; real_T nzqg25m1lg [ 2 ] ;
real_T l1g0f5hnak [ 2 ] ; real_T oqwcwkuk03 [ 2 ] ; real_T cvt2mfevlv [ 3606
] ; real_T nyoeq2soc1 ; real_T ajv5jtlwij [ 3606 ] ; real_T pe4ejkzi2m ;
struct { real_T modelTStart ; } nbfng2z4ir ; struct { real_T modelTStart ; }
db2mbofoip ; void * lm3sijg1j1 ; void * dhyxq0jnh5 ; void * f4urr54u23 ; void
* mvbmsho13j ; void * lcyjf3fqb0 ; void * agkrcbkdh5 ; void * njkjfcqdc3 ;
void * kieznzt55p ; void * focflcnmnv ; void * oyfyizkz25 ; struct { void *
TUbufferPtrs [ 12 ] ; } aqyccuzu4f ; struct { void * TUbufferPtrs [ 12 ] ; }
pj0j1eoun4 ; void * dfba0ayog2 ; void * mb1a41sbow ; void * mqwpk5opbx ; void
* ppcwemgz0a ; void * dt3ok1ryhy ; void * grkodaq2kd ; void * hjs5z0ka4j ;
void * hafmpp5qwx ; void * hinmghz5iq ; void * ebufosmij4 ; struct { void *
LoggedData ; } kmx1camcmy ; struct { void * LoggedData ; } jzxtw4vtua ;
struct { void * LoggedData ; } ce1jzkjckk ; struct { void * LoggedData ; }
mmokpjpvho ; struct { int_T Tail [ 6 ] ; int_T Head [ 6 ] ; int_T Last [ 6 ]
; int_T CircularBufSize [ 6 ] ; int_T MaxNewBufSize ; } anmk1ei3yl ; struct {
int_T Tail [ 6 ] ; int_T Head [ 6 ] ; int_T Last [ 6 ] ; int_T
CircularBufSize [ 6 ] ; int_T MaxNewBufSize ; } ke454bg2ir ; int8_T
bxqmm1o411 ; int8_T nofdnsita2 ; int8_T if5tadkli2 ; int8_T gn2tshspwh ;
boolean_T fk22kz5jyq ; boolean_T g5k0jhqbfv ; boolean_T cq0zpszeap ;
boolean_T ks0u35sdaj ; boolean_T ba32jnnpzi ; boolean_T hfpj0irdgz ;
h05eppclcz cy14v3kgd2 ; lghbzftw4s kw4gz4nylz ; hs2j2p43ts arvvtfsmo3 ;
butlgtrn1o bt1qvoldbv ; h05eppclcz p14hwlcq5ag ; lghbzftw4s l1kcj50fwey ;
hs2j2p43ts aqx150ksytr ; butlgtrn1o i0grvgounuc ; } DW ; typedef struct {
real_T kxjirxqmhs [ 4 ] ; } X ; typedef struct { real_T kxjirxqmhs [ 4 ] ; }
XDot ; typedef struct { boolean_T kxjirxqmhs [ 4 ] ; } XDis ; typedef struct
{ rtwCAPI_ModelMappingInfo mmi ; } DataMapInfo ; struct jjq30b5cja_ { real_T
CosWave_Amp ; real_T CosWave_Bias ; real_T CosWave_Freq ; real_T
CosWave_Phase ; real_T BEMExcitationRePart_Value [ 6 ] ; real_T SinWave_Amp ;
real_T SinWave_Bias ; real_T SinWave_Freq ; real_T SinWave_Phase ; real_T
BEMExcitationImPart1_Value [ 6 ] ; } ; struct ojkmqczxmu_ { real_T
CosWaveFunction_Amp ; real_T CosWaveFunction_Bias ; real_T
CosWaveFunction_Freq ; real_T CosWaveFunction_Phase ; real_T
SinWaveFunction_Amp ; real_T SinWaveFunction_Bias ; real_T
SinWaveFunction_Freq ; real_T SinWaveFunction_Phase ; } ; struct dnlp5zegym_
{ real_T ExcitationRePart2_Value [ 6 ] ; real_T ExcitationRePart3_Value [ 6 ]
; real_T wavespectrum_Value ; real_T wavefrequency_Value ; real_T dw1_Value ;
real_T wavefrequency1_Value ; ojkmqczxmu izalnoy5rm ; } ; struct fd5dgqf4g3_
{ real_T Constant1_Value ; real_T SineWave_Amp ; real_T SineWave_Bias ;
real_T SineWave_Freq ; real_T SineWave_Phase ; real_T Constant_Value ; } ;
struct P_ { real_T DampingForces_Gain [ 36 ] ; real_T WaveType_Value ; real_T
InitialZeroVelocity_Value [ 3606 ] ; real_T ImpulseResponseFunctionK_Value [
21636 ] ; real_T Timerelativetothecurrenttimestep_Value [ 601 ] ; real_T
TransportDelay_Delay ; real_T TransportDelay_InitOutput ; real_T
AddedMassForces_Gain [ 36 ] ; real_T DispforRotation1_Value [ 6 ] ; real_T
Gravity_Value ; real_T GravityForce_Value ; real_T Density_Value ; real_T
Gravity1_Value ; real_T GravityForce1_Value ; real_T CenterofGravity_Value [
3 ] ; real_T DispforRotation_Value [ 3 ] ; real_T RestoringForces_Gain [ 36 ]
; real_T ViscousDamping_Gain [ 36 ] ; real_T LinearDamping_Gain [ 36 ] ;
real_T CenterofGravity_Value_ehagwuwxhi [ 3 ] ; real_T
DispforRotation_Value_n4dcoglnve [ 3 ] ; real_T MooringStiffness_Gain ;
real_T MooringDamping_Gain ; real_T MooringPreTension_Value ; real_T
RampFunctionTime_Value ; real_T WaveType_Value_ghmpcbwqgc ; real_T
DampingForces_Gain_lg5w5letwj [ 36 ] ; real_T WaveType_Value_kmlj0k40q4 ;
real_T InitialZeroVelocity_Value_espd2duag2 [ 3606 ] ; real_T
ImpulseResponseFunctionK_Value_oxs4p44uy4 [ 43272 ] ; real_T
Timerelativetothecurrenttimestep_Value_pdxfuxlbzx [ 601 ] ; real_T
TransportDelay_Delay_idbp52hm4z ; real_T TransportDelay_InitOutput_ok1nab0an0
; real_T AddedMassForces_Gain_nn4j25aboc [ 36 ] ; real_T
DispforRotation1_Value_bb2prsf5d3 [ 6 ] ; real_T Gravity_Value_l5d2lookat ;
real_T GravityForce_Value_cfqmx3j5kp ; real_T Density_Value_aih4vdbghl ;
real_T Gravity1_Value_mtxwpjdnnl ; real_T GravityForce1_Value_lk4e3aezgl ;
real_T CenterofGravity_Value_md1kocvst4 [ 3 ] ; real_T
DispforRotation_Value_e2df3x2zha [ 3 ] ; real_T
RestoringForces_Gain_gtjxe5fum0 [ 36 ] ; real_T
ViscousDamping_Gain_muya5lc1kx [ 36 ] ; real_T LinearDamping_Gain_bf1ntj5xm0
[ 36 ] ; real_T CenterofGravity_Value_b3htdqbdxy [ 3 ] ; real_T
DispforRotation_Value_hu2rwtrpwt [ 3 ] ; real_T
MooringStiffness_Gain_ftpngfcbjw ; real_T MooringDamping_Gain_hnfjdm1021 ;
real_T MooringPreTension_Value_klqp1nyvd4 ; real_T
RampFunctionTime_Value_n3y3wgeehz ; real_T WaveType_Value_cigtbjvhxd ; real_T
PCCStiffnessCoefficient_Value ; real_T PCCDampingCoefficient_Value ;
fd5dgqf4g3 kw4gz4nylz ; dnlp5zegym arvvtfsmo3 ; jjq30b5cja bt1qvoldbv ;
fd5dgqf4g3 l1kcj50fwey ; dnlp5zegym aqx150ksytr ; jjq30b5cja i0grvgounuc ; }
; extern P rtP ; extern const char * RT_MEMORY_ALLOCATION_ERROR ; extern B
rtB ; extern X rtX ; extern DW rtDW ; extern const
rtwCAPI_ModelMappingStaticInfo * RM3_GetCAPIStaticMap ( void ) ; extern
SimStruct * const rtS ; extern const int_T gblNumToFiles ; extern const int_T
gblNumFrFiles ; extern const int_T gblNumFrWksBlocks ; extern rtInportTUtable
* gblInportTUtables ; extern const char * gblInportFileName ; extern const
int_T gblNumRootInportBlks ; extern const int_T gblNumModelInputs ; extern
const int_T gblInportDataTypeIdx [ ] ; extern const int_T gblInportDims [ ] ;
extern const int_T gblInportComplex [ ] ; extern const int_T
gblInportInterpoFlag [ ] ; extern const int_T gblInportContinuous [ ] ;
extern DataMapInfo * rt_dataMapInfoPtr ; extern rtwCAPI_ModelMappingInfo *
rt_modelMapInfoPtr ; void MdlOutputs ( int_T tid ) ; void MdlUpdate ( int_T
tid ) ; void MdlTerminate ( void ) ; void MdlInitializeSizes ( void ) ; void
MdlInitializeSampleTimes ( void ) ; SimStruct * raccel_register_model ( void
) ;
#endif
