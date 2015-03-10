#ifndef __c3_7vqb7o7CaUJzbPKhFMyx3F_WECSim_Lib_h__
#define __c3_7vqb7o7CaUJzbPKhFMyx3F_WECSim_Lib_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc3_7vqb7o7CaUJzbPKhFMyx3F_WECSim_LibInstanceStruct
#define typedef_SFc3_7vqb7o7CaUJzbPKhFMyx3F_WECSim_LibInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c3_7vqb7o7CaUJzbPKhFMyx3F_sfEvent;
  boolean_T c3_7vqb7o7CaUJzbPKhFMyx3F_isStable;
  boolean_T c3_7vqb7o7CaUJzbPKhFMyx3F_doneDoubleBufferReInit;
  uint8_T c3_7vqb7o7CaUJzbPKhFMyx3F_is_active_c3_7vqb7o7CaUJzbPKhFMyx3F_WE;
  real_T c3_7vqb7o7CaUJzbPKhFMyx3F_velocity[3606];
  boolean_T c3_7vqb7o7CaUJzbPKhFMyx3F_velocity_not_empty;
  real_T c3_7vqb7o7CaUJzbPKhFMyx3F_kkk;
  boolean_T c3_7vqb7o7CaUJzbPKhFMyx3F_kkk_not_empty;
  real_T c3_7vqb7o7CaUJzbPKhFMyx3F_inData[43272];
  real_T c3_7vqb7o7CaUJzbPKhFMyx3F_u[43272];
  real_T c3_7vqb7o7CaUJzbPKhFMyx3F_IRKB[43272];
  real_T *c3_7vqb7o7CaUJzbPKhFMyx3F_check;
  real_T (*c3_7vqb7o7CaUJzbPKhFMyx3F_v)[6];
  real_T (*c3_7vqb7o7CaUJzbPKhFMyx3F_F_FM)[6];
  real_T (*c3_7vqb7o7CaUJzbPKhFMyx3F_ZeroVel)[3606];
  real_T (*c3_7vqb7o7CaUJzbPKhFMyx3F_b_IRKB)[43272];
  real_T (*c3_7vqb7o7CaUJzbPKhFMyx3F_CTTime)[601];
} SFc3_7vqb7o7CaUJzbPKhFMyx3F_WECSim_LibInstanceStruct;

#endif                                 /*typedef_SFc3_7vqb7o7CaUJzbPKhFMyx3F_WECSim_LibInstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray
  *sf_c3_7vqb7o7CaUJzbPKhFMyx3F_WECSim_Lib_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c3_7vqb7o7CaUJzbPKhFMyx3F_WECSim_Lib_get_check_sum(mxArray *plhs[]);
extern void c3_7vqb7o7CaUJzbPKhFMyx3F_WECSim_Lib_method_dispatcher(SimStruct *S,
  int_T method, void *data);

#endif
