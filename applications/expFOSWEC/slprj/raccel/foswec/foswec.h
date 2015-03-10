#include "__cf_foswec.h"
#ifndef RTW_HEADER_foswec_h_
#define RTW_HEADER_foswec_h_
#include <stddef.h>
#include <float.h>
#include <string.h>
#include "rtw_modelmap.h"
#ifndef foswec_COMMON_INCLUDES_
#define foswec_COMMON_INCLUDES_
#include <stdlib.h>
#include "rtwtypes.h"
#include "simstruc.h"
#include "fixedpoint.h"
#include "raccel.h"
#include "rt_logging.h"
#include "dt_info.h"
#include "ext_work.h"
#include "nesl_rtw.h"
#include "foswec_4deb2608_gateway.h"
#endif
#include "foswec_types.h"
#include "multiword_types.h"
#include "mwmathutil.h"
#include "rt_defines.h"
#include "rtGetInf.h"
#include "rt_nonfinite.h"
#define MODEL_NAME foswec
#define NSAMPLE_TIMES (2) 
#define NINPUTS (0)       
#define NOUTPUTS (0)     
#define NBLOCKIO (72) 
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
typedef struct { real_T c0mvqybgil [ 3 ] ; } gwsufvgalb ; typedef struct {
int8_T gnrlcinhso ; } abaglin1js ; typedef struct { int8_T ljbrchkhk1 ; }
cr32exjf2u ; typedef struct { int8_T cvx5ycrffh ; } omu551rm45 ; typedef
struct { int8_T oqsczzj035 ; } bsavqxx5nr ; typedef struct { real_T
fvwzfaxh1r [ 5148 ] ; real_T fti1x5vbt4 [ 859 ] ; real_T dhs4rowpbe [ 859 ] ;
real_T jmbenplned [ 6 ] ; } pcwx03o2bp ; typedef struct { real_T cl4bth31oo [
5154 ] ; real_T n3iy5isn5k ; boolean_T fazqyerxsu ; } freyzphwfw ; typedef
struct { real_T gja4dzl325 [ 4 ] ; real_T blpo5iedij [ 43 ] ; real_T
hqtb5p5515 [ 6 ] ; real_T pnsa2f20mr [ 6 ] ; real_T euxjdg3wyk [ 6 ] ; real_T
dlr5ya0rha [ 6 ] ; real_T pr41rtecbf [ 6 ] ; real_T merar43jbg [ 6 ] ; real_T
ihnthpc5j1 [ 6 ] ; real_T fyev0m4vsa ; real_T dhfvei2wiq [ 6 ] ; real_T
b1n5unk4di [ 6 ] ; real_T p1qklr3iem [ 4 ] ; real_T dzcyvgjss1 [ 4 ] ; real_T
kyqswxndxu [ 4 ] ; real_T os0vmujie2 [ 4 ] ; real_T f5vdxtzttp [ 4 ] ; real_T
ny3ji5snoz [ 4 ] ; real_T b3fkm4fcdn [ 6 ] ; real_T jcuedl2jnj [ 6 ] ; real_T
o5jrwx140d [ 6 ] ; real_T ggc0r0fx3g [ 6 ] ; real_T njnofax133 [ 6 ] ; real_T
amxl55ezpx [ 6 ] ; real_T ihg0r14bhr [ 6 ] ; real_T pj144ebf30 [ 6 ] ; real_T
edopdfd1hm [ 6 ] ; real_T kgii2iaa1l [ 4 ] ; real_T jfce0w0ghr [ 4 ] ; real_T
pcf0pfmweo [ 4 ] ; real_T if52phrmag [ 4 ] ; real_T mocddkrpki [ 4 ] ; real_T
kzwkda2ehh [ 4 ] ; real_T e0ns1clddv [ 6 ] ; real_T hdrzhitnck [ 6 ] ; real_T
lkgzajb1kd [ 6 ] ; real_T muoixesghk [ 6 ] ; real_T jeu1moqvun [ 6 ] ; real_T
ialr351o51 [ 6 ] ; real_T j4t0l5sh1l [ 6 ] ; real_T fnesyp43ae [ 6 ] ; real_T
okcf5s1hfi [ 6 ] ; real_T hmeg1w5jim [ 4 ] ; real_T nbocq1o42k [ 4 ] ; real_T
d5a52isphm [ 4 ] ; real_T icy3aei5aw [ 4 ] ; real_T add5kxxow3 [ 4 ] ; real_T
oigl01ewmc [ 4 ] ; real_T l5ibfslonp [ 36 ] ; real_T ejgnutoxk4 [ 6 ] ;
real_T cdoh40kylx [ 66 ] ; real_T c4gqqn41jy [ 66 ] ; real_T mhluogc5lp [ 66
] ; real_T miwvnyxkwg ; real_T gdetjhzpld ; real_T pr2wmuatwp [ 3 ] ; real_T
euklvqzjnb [ 3 ] ; real_T hflxw2u4c0 [ 8 ] ; real_T l2wrpxekcz ; real_T
jcjac2h4yl ; real_T g5gg5rwfxi [ 3 ] ; real_T mb24q41lpq [ 3 ] ; real_T
kzugd0mwbk [ 8 ] ; pcwx03o2bp ipyob4ujct ; gwsufvgalb iluwjccpxx ; pcwx03o2bp
hbwafuhekh ; gwsufvgalb evtto0adau ; pcwx03o2bp arymfxlfvv ; gwsufvgalb
nd0v2sbydt ; } B ; typedef struct { real_T okejdpgu1c [ 2 ] ; real_T
k4kmsogsl5 [ 2 ] ; real_T ihegmmijy4 [ 2 ] ; real_T ojcm0w354h [ 2 ] ; real_T
e2rajb5jef [ 2 ] ; real_T d1dr20wbil [ 2 ] ; real_T nbmftfajwj [ 2 ] ; real_T
d4bgxhw4kx [ 2 ] ; real_T knlt4i5nhu [ 2 ] ; real_T phzhuqqbqj [ 2 ] ; real_T
dblqjhlznj [ 2 ] ; real_T dwhzhgdlwe [ 2 ] ; real_T g4w5whunn0 [ 2 ] ; real_T
ihejtbnivo [ 2 ] ; real_T kv0fr1ezds [ 2 ] ; real_T jvtm2q20yi [ 2 ] ; real_T
csqplvugez [ 2 ] ; real_T b2ebqtdjfn [ 2 ] ; struct { real_T modelTStart ; }
cqf5illkg4 ; struct { real_T modelTStart ; } l3gqrt0mpz ; struct { real_T
modelTStart ; } m1arggegue ; void * pyei4aktas ; void * lav352kiwz ; void *
gknbsopy3r ; void * k21g4xkqyw ; void * gqikoc3gqq ; void * d3bbzrpbvx ; void
* awgpzntukc ; void * k13qfbrzod ; void * l5glelo31i ; void * iob1f2j3jw ;
struct { void * TUbufferPtrs [ 12 ] ; } ozvltbk2so ; struct { void *
TUbufferPtrs [ 12 ] ; } fv3pugwi2m ; struct { void * TUbufferPtrs [ 12 ] ; }
a1q2j3sqxq ; void * kac3j5zyhm ; void * mzt5dujgnf ; void * hmwzsbnven ; void
* ejbhclilet ; void * fvtzlyem05 ; struct { void * LoggedData ; } facajaxtwh
; struct { void * LoggedData ; } ea2glvbgz2 ; struct { void * LoggedData ; }
fb5d5dwuih ; void * cgg15aa41a ; void * kya05gko0q ; void * hi5y52mclc ; void
* msaqjkzdc4 ; void * itv4lh1itu ; struct { void * LoggedData ; } pztby5tdmg
; struct { void * LoggedData ; } o3l54yb1i3 ; struct { void * LoggedData ; }
lvjvwmkulx ; struct { int_T Tail [ 6 ] ; int_T Head [ 6 ] ; int_T Last [ 6 ]
; int_T CircularBufSize [ 6 ] ; int_T MaxNewBufSize ; } iie0k52gf2 ; struct {
int_T Tail [ 6 ] ; int_T Head [ 6 ] ; int_T Last [ 6 ] ; int_T
CircularBufSize [ 6 ] ; int_T MaxNewBufSize ; } hxf5v0hxfq ; struct { int_T
Tail [ 6 ] ; int_T Head [ 6 ] ; int_T Last [ 6 ] ; int_T CircularBufSize [ 6
] ; int_T MaxNewBufSize ; } nrayhafgyw ; int8_T gl2utjnv03 ; int8_T
mrlpfzs3wn ; int8_T dnkdbkqczp ; int8_T kols4c4dg4 ; int8_T gibqmcfn3a ;
int8_T ob5wky4wsa ; boolean_T hmp4wnm12v ; boolean_T k3vqeab02b ; boolean_T
a50xvoi5cw ; boolean_T bnvulmonk2 ; freyzphwfw ipyob4ujct ; bsavqxx5nr
i00ohkzxv2 ; omu551rm45 apfdt1mk1s ; cr32exjf2u ogpjwh504b ; abaglin1js
fmempv5ety ; freyzphwfw hbwafuhekh ; bsavqxx5nr a1tdc130d3 ; omu551rm45
msblmfssu1 ; cr32exjf2u fkat0ywnxz ; abaglin1js h5j4mvdijc ; freyzphwfw
arymfxlfvv ; bsavqxx5nr coaxej2udzm ; omu551rm45 cnj3cuyx4ul ; cr32exjf2u
h02m5m2hejt ; abaglin1js fzybd15s0q0 ; } DW ; typedef struct { real_T
h5zfgvmg3r [ 4 ] ; } X ; typedef struct { real_T h5zfgvmg3r [ 4 ] ; } XDot ;
typedef struct { boolean_T h5zfgvmg3r [ 4 ] ; } XDis ; typedef struct {
rtwCAPI_ModelMappingInfo mmi ; } DataMapInfo ; struct kwd4b3jpcn_ { real_T
CosWave_Amp ; real_T CosWave_Bias ; real_T CosWave_Freq ; real_T
CosWave_Phase ; real_T BEMExcitationRePart_Value [ 6 ] ; real_T SinWave_Amp ;
real_T SinWave_Bias ; real_T SinWave_Freq ; real_T SinWave_Phase ; real_T
BEMExcitationImPart1_Value [ 6 ] ; } ; struct m1qmim131q_ { real_T
CosWaveFunction_Amp ; real_T CosWaveFunction_Bias ; real_T
CosWaveFunction_Freq ; real_T CosWaveFunction_Phase ; real_T
SinWaveFunction_Amp ; real_T SinWaveFunction_Bias ; real_T
SinWaveFunction_Freq ; real_T SinWaveFunction_Phase ; } ; struct fi0awblwxy_
{ real_T ExcitationRePart2_Value [ 6 ] ; real_T ExcitationRePart3_Value [ 6 ]
; real_T wavespectrum_Value ; real_T wavefrequency_Value ; real_T dw1_Value ;
real_T wavefrequency1_Value ; m1qmim131q hq5rtzuhum ; } ; struct djsc05xhw3_
{ real_T Constant1_Value ; real_T SineWave_Amp ; real_T SineWave_Bias ;
real_T SineWave_Freq ; real_T SineWave_Phase ; real_T Constant_Value ; } ;
struct P_ { real_T DampingForces_Gain [ 36 ] ; real_T WaveType_Value ; real_T
InitialZeroVelocity_Value [ 5154 ] ; real_T ImpulseResponseFunctionK_Value [
30924 ] ; real_T Timerelativetothecurrenttimestep_Value [ 859 ] ; real_T
TransportDelay_Delay ; real_T TransportDelay_InitOutput ; real_T
AddedMassForces_Gain [ 36 ] ; real_T DispforRotation1_Value [ 6 ] ; real_T
Gravity_Value ; real_T GravityForce_Value ; real_T Density_Value ; real_T
Gravity1_Value ; real_T GravityForce1_Value ; real_T CenterofGravity_Value [
3 ] ; real_T DispforRotation_Value [ 3 ] ; real_T RestoringForces_Gain [ 36 ]
; real_T ViscousDamping_Gain [ 36 ] ; real_T LinearDamping_Gain [ 36 ] ;
real_T CenterofGravity_Value_kv4jtzv4sz [ 3 ] ; real_T
DispforRotation_Value_e2awq1sqk5 [ 3 ] ; real_T MooringStiffness_Gain ;
real_T MooringDamping_Gain ; real_T MooringPreTension_Value ; real_T
RampFunctionTime_Value ; real_T WaveType_Value_lnsink2wos ; real_T
DampingForces_Gain_gmglkqwyrk [ 36 ] ; real_T WaveType_Value_brm2lvz52e ;
real_T InitialZeroVelocity_Value_mbg4rllwz5 [ 5154 ] ; real_T
ImpulseResponseFunctionK_Value_fjjrzbclsj [ 30924 ] ; real_T
Timerelativetothecurrenttimestep_Value_jpehs0wqht [ 859 ] ; real_T
TransportDelay_Delay_bp43gzj5e3 ; real_T TransportDelay_InitOutput_ii0y22uej3
; real_T AddedMassForces_Gain_oroqvzk1e4 [ 36 ] ; real_T
DispforRotation1_Value_o3itv5xzx4 [ 6 ] ; real_T Gravity_Value_gftrulwsfn ;
real_T GravityForce_Value_bwfmpxsvsr ; real_T Density_Value_nszowylvmf ;
real_T Gravity1_Value_gkp4y35w4n ; real_T GravityForce1_Value_ipgtikjaun ;
real_T CenterofGravity_Value_moatrz5qxk [ 3 ] ; real_T
DispforRotation_Value_ocikgyapyh [ 3 ] ; real_T
RestoringForces_Gain_cyy4gncipu [ 36 ] ; real_T
ViscousDamping_Gain_k1dk0v0wf1 [ 36 ] ; real_T LinearDamping_Gain_gt4kyc33is
[ 36 ] ; real_T CenterofGravity_Value_idcvji535z [ 3 ] ; real_T
DispforRotation_Value_ftba4kbp25 [ 3 ] ; real_T
MooringStiffness_Gain_l3g4tznmmz ; real_T MooringDamping_Gain_loasej4jiy ;
real_T MooringPreTension_Value_n0e1y4yp2s ; real_T
RampFunctionTime_Value_mg4suvbwbg ; real_T WaveType_Value_jdh1bnnh0l ; real_T
DampingForces_Gain_itl5dvfc3u [ 36 ] ; real_T WaveType_Value_jkynzzqjsn ;
real_T InitialZeroVelocity_Value_gvmd2jy3st [ 5154 ] ; real_T
ImpulseResponseFunctionK_Value_i5uuouboea [ 30924 ] ; real_T
Timerelativetothecurrenttimestep_Value_kvgyp5pq4q [ 859 ] ; real_T
TransportDelay_Delay_foibzxd41j ; real_T TransportDelay_InitOutput_bf1kxbkfem
; real_T AddedMassForces_Gain_icvgvsh5ju [ 36 ] ; real_T
DispforRotation1_Value_dhyoflxvyp [ 6 ] ; real_T Gravity_Value_cx40ikecyz ;
real_T GravityForce_Value_nk3enkxm1g ; real_T Density_Value_cwal0gh0jx ;
real_T Gravity1_Value_jzzrqnwdx1 ; real_T GravityForce1_Value_a3ipdgsubl ;
real_T CenterofGravity_Value_ffrrlkfvt3 [ 3 ] ; real_T
DispforRotation_Value_dwwryftswo [ 3 ] ; real_T
RestoringForces_Gain_pooakzjpnq [ 36 ] ; real_T
ViscousDamping_Gain_ibhby0wcea [ 36 ] ; real_T LinearDamping_Gain_f1vdp50wdd
[ 36 ] ; real_T CenterofGravity_Value_izurzrsyhp [ 3 ] ; real_T
DispforRotation_Value_md2plndz15 [ 3 ] ; real_T
MooringStiffness_Gain_ixw1h4sghu ; real_T MooringDamping_Gain_nkhqr3tbky ;
real_T MooringPreTension_Value_p53dhtwkd4 ; real_T
RampFunctionTime_Value_mnlhvccsmd ; real_T WaveType_Value_cbd1s2tvax ; real_T
Gain3_Gain ; real_T PCCStiffnessCoefficient_Value ; real_T
PCCDampingCoefficient_Value ; real_T Gain2_Gain ; real_T Gain1_Gain ; real_T
Gain_Gain ; real_T Gain3_Gain_nxxgw4dkhx ; real_T
PCCStiffnessCoefficient_Value_bq4hxfosr4 ; real_T
PCCDampingCoefficient_Value_p0lvrll2jb ; real_T Gain2_Gain_kgiq1thyom ;
real_T Gain1_Gain_nupg4bxvwd ; real_T Gain_Gain_crbn4vzgqb ; djsc05xhw3
apfdt1mk1s ; fi0awblwxy ogpjwh504b ; kwd4b3jpcn fmempv5ety ; djsc05xhw3
msblmfssu1 ; fi0awblwxy fkat0ywnxz ; kwd4b3jpcn h5j4mvdijc ; djsc05xhw3
cnj3cuyx4ul ; fi0awblwxy h02m5m2hejt ; kwd4b3jpcn fzybd15s0q0 ; } ; extern P
rtP ; extern const char * RT_MEMORY_ALLOCATION_ERROR ; extern B rtB ; extern
X rtX ; extern DW rtDW ; extern const rtwCAPI_ModelMappingStaticInfo *
foswec_GetCAPIStaticMap ( void ) ; extern SimStruct * const rtS ; extern
const int_T gblNumToFiles ; extern const int_T gblNumFrFiles ; extern const
int_T gblNumFrWksBlocks ; extern rtInportTUtable * gblInportTUtables ; extern
const char * gblInportFileName ; extern const int_T gblNumRootInportBlks ;
extern const int_T gblNumModelInputs ; extern const int_T
gblInportDataTypeIdx [ ] ; extern const int_T gblInportDims [ ] ; extern
const int_T gblInportComplex [ ] ; extern const int_T gblInportInterpoFlag [
] ; extern const int_T gblInportContinuous [ ] ; extern DataMapInfo *
rt_dataMapInfoPtr ; extern rtwCAPI_ModelMappingInfo * rt_modelMapInfoPtr ;
void MdlOutputs ( int_T tid ) ; void MdlUpdate ( int_T tid ) ; void
MdlTerminate ( void ) ; void MdlInitializeSizes ( void ) ; void
MdlInitializeSampleTimes ( void ) ; SimStruct * raccel_register_model ( void
) ;
#endif
