/* Include files */

#include <stddef.h>
#include "blas.h"
#include "WECSim_Lib_sfun.h"
#include "c3_7vqb7o7CaUJzbPKhFMyx3F_WECSim_Lib.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "WECSim_Lib_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(sfGlobalDebugInstanceStruct,S);

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static real_T _sfTime_;
static const char * c3_7vqb7o7CaUJzbPKhFMyx3F_debug_family_names[16] = { "tmpT",
  "int2", "tmpF", "kd", "kk", "tmpY", "nargin", "nargout", "check", "v",
  "ZeroVel", "IRKB", "CTTime", "F_FM", "velocity", "kkk" };

/* Function Declarations */
static void initialize_c3_7vqb7o7CaUJzbPKhFMyx3F_WECSim_Lib
  (SFc3_7vqb7o7CaUJzbPKhFMyx3F_WECSim_LibInstanceStruct *chartInstance);
static void initialize_params_c3_7vqb7o7CaUJzbPKhFMyx3F_WECSim_Lib
  (SFc3_7vqb7o7CaUJzbPKhFMyx3F_WECSim_LibInstanceStruct *chartInstance);
static void enable_c3_7vqb7o7CaUJzbPKhFMyx3F_WECSim_Lib
  (SFc3_7vqb7o7CaUJzbPKhFMyx3F_WECSim_LibInstanceStruct *chartInstance);
static void disable_c3_7vqb7o7CaUJzbPKhFMyx3F_WECSim_Lib
  (SFc3_7vqb7o7CaUJzbPKhFMyx3F_WECSim_LibInstanceStruct *chartInstance);
static void c3_7vqb7o7CaUJzbPKhFMyx3F_update_debugger_state_c3_7vqb7o7CaUJzb
  (SFc3_7vqb7o7CaUJzbPKhFMyx3F_WECSim_LibInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c3_7vqb7o7CaUJzbPKhFMyx3F_WECSim_Lib
  (SFc3_7vqb7o7CaUJzbPKhFMyx3F_WECSim_LibInstanceStruct *chartInstance);
static void set_sim_state_c3_7vqb7o7CaUJzbPKhFMyx3F_WECSim_Lib
  (SFc3_7vqb7o7CaUJzbPKhFMyx3F_WECSim_LibInstanceStruct *chartInstance, const
   mxArray *c3_7vqb7o7CaUJzbPKhFMyx3F_st);
static void finalize_c3_7vqb7o7CaUJzbPKhFMyx3F_WECSim_Lib
  (SFc3_7vqb7o7CaUJzbPKhFMyx3F_WECSim_LibInstanceStruct *chartInstance);
static void sf_gateway_c3_7vqb7o7CaUJzbPKhFMyx3F_WECSim_Lib
  (SFc3_7vqb7o7CaUJzbPKhFMyx3F_WECSim_LibInstanceStruct *chartInstance);
static void mdl_start_c3_7vqb7o7CaUJzbPKhFMyx3F_WECSim_Lib
  (SFc3_7vqb7o7CaUJzbPKhFMyx3F_WECSim_LibInstanceStruct *chartInstance);
static void c3_7vqb7o7CaUJzbPKhFMyx3F_chartstep_c3_7vqb7o7CaUJzbPKhFMyx3F_WE
  (SFc3_7vqb7o7CaUJzbPKhFMyx3F_WECSim_LibInstanceStruct *chartInstance);
static void initSimStructsc3_7vqb7o7CaUJzbPKhFMyx3F_WECSim_Lib
  (SFc3_7vqb7o7CaUJzbPKhFMyx3F_WECSim_LibInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T
  c3_7vqb7o7CaUJzbPKhFMyx3F_machineNumber, uint32_T
  c3_7vqb7o7CaUJzbPKhFMyx3F_chartNumber, uint32_T
  c3_7vqb7o7CaUJzbPKhFMyx3F_instanceNumber);
static const mxArray *c3_7vqb7o7CaUJzbPKhFMyx3F_sf_marshallOut(void
  *chartInstanceVoid, void *c3_7vqb7o7CaUJzbPKhFMyx3F_b_inData);
static real_T c3_7vqb7o7CaUJzbPKhFMyx3F_emlrt_marshallIn
  (SFc3_7vqb7o7CaUJzbPKhFMyx3F_WECSim_LibInstanceStruct *chartInstance, const
   mxArray *c3_7vqb7o7CaUJzbPKhFMyx3F_b_kkk, const char_T
   *c3_7vqb7o7CaUJzbPKhFMyx3F_identifier);
static real_T c3_7vqb7o7CaUJzbPKhFMyx3F_b_emlrt_marshallIn
  (SFc3_7vqb7o7CaUJzbPKhFMyx3F_WECSim_LibInstanceStruct *chartInstance, const
   mxArray *c3_7vqb7o7CaUJzbPKhFMyx3F_b_u, const emlrtMsgIdentifier
   *c3_7vqb7o7CaUJzbPKhFMyx3F_parentId);
static void c3_7vqb7o7CaUJzbPKhFMyx3F_sf_marshallIn(void *chartInstanceVoid,
  const mxArray *c3_7vqb7o7CaUJzbPKhFMyx3F_mxArrayInData, const char_T
  *c3_7vqb7o7CaUJzbPKhFMyx3F_varName, void *c3_7vqb7o7CaUJzbPKhFMyx3F_outData);
static const mxArray *c3_7vqb7o7CaUJzbPKhFMyx3F_b_sf_marshallOut(void
  *chartInstanceVoid, void *c3_7vqb7o7CaUJzbPKhFMyx3F_b_inData);
static void c3_7vqb7o7CaUJzbPKhFMyx3F_c_emlrt_marshallIn
  (SFc3_7vqb7o7CaUJzbPKhFMyx3F_WECSim_LibInstanceStruct *chartInstance, const
   mxArray *c3_7vqb7o7CaUJzbPKhFMyx3F_b_velocity, const char_T
   *c3_7vqb7o7CaUJzbPKhFMyx3F_identifier, real_T c3_7vqb7o7CaUJzbPKhFMyx3F_y
   [3606]);
static void c3_7vqb7o7CaUJzbPKhFMyx3F_d_emlrt_marshallIn
  (SFc3_7vqb7o7CaUJzbPKhFMyx3F_WECSim_LibInstanceStruct *chartInstance, const
   mxArray *c3_7vqb7o7CaUJzbPKhFMyx3F_b_u, const emlrtMsgIdentifier
   *c3_7vqb7o7CaUJzbPKhFMyx3F_parentId, real_T c3_7vqb7o7CaUJzbPKhFMyx3F_y[3606]);
static void c3_7vqb7o7CaUJzbPKhFMyx3F_b_sf_marshallIn(void *chartInstanceVoid,
  const mxArray *c3_7vqb7o7CaUJzbPKhFMyx3F_mxArrayInData, const char_T
  *c3_7vqb7o7CaUJzbPKhFMyx3F_varName, void *c3_7vqb7o7CaUJzbPKhFMyx3F_outData);
static const mxArray *c3_7vqb7o7CaUJzbPKhFMyx3F_c_sf_marshallOut(void
  *chartInstanceVoid, void *c3_7vqb7o7CaUJzbPKhFMyx3F_b_inData);
static void c3_7vqb7o7CaUJzbPKhFMyx3F_e_emlrt_marshallIn
  (SFc3_7vqb7o7CaUJzbPKhFMyx3F_WECSim_LibInstanceStruct *chartInstance, const
   mxArray *c3_7vqb7o7CaUJzbPKhFMyx3F_b_F_FM, const char_T
   *c3_7vqb7o7CaUJzbPKhFMyx3F_identifier, real_T c3_7vqb7o7CaUJzbPKhFMyx3F_y[6]);
static void c3_7vqb7o7CaUJzbPKhFMyx3F_f_emlrt_marshallIn
  (SFc3_7vqb7o7CaUJzbPKhFMyx3F_WECSim_LibInstanceStruct *chartInstance, const
   mxArray *c3_7vqb7o7CaUJzbPKhFMyx3F_b_u, const emlrtMsgIdentifier
   *c3_7vqb7o7CaUJzbPKhFMyx3F_parentId, real_T c3_7vqb7o7CaUJzbPKhFMyx3F_y[6]);
static void c3_7vqb7o7CaUJzbPKhFMyx3F_c_sf_marshallIn(void *chartInstanceVoid,
  const mxArray *c3_7vqb7o7CaUJzbPKhFMyx3F_mxArrayInData, const char_T
  *c3_7vqb7o7CaUJzbPKhFMyx3F_varName, void *c3_7vqb7o7CaUJzbPKhFMyx3F_outData);
static const mxArray *c3_7vqb7o7CaUJzbPKhFMyx3F_d_sf_marshallOut(void
  *chartInstanceVoid, void *c3_7vqb7o7CaUJzbPKhFMyx3F_b_inData);
static const mxArray *c3_7vqb7o7CaUJzbPKhFMyx3F_e_sf_marshallOut(void
  *chartInstanceVoid, void *c3_7vqb7o7CaUJzbPKhFMyx3F_b_inData);
static const mxArray *c3_7vqb7o7CaUJzbPKhFMyx3F_f_sf_marshallOut(void
  *chartInstanceVoid, void *c3_7vqb7o7CaUJzbPKhFMyx3F_b_inData);
static const mxArray *c3_7vqb7o7CaUJzbPKhFMyx3F_g_sf_marshallOut(void
  *chartInstanceVoid, void *c3_7vqb7o7CaUJzbPKhFMyx3F_b_inData);
static real_T c3_7vqb7o7CaUJzbPKhFMyx3F_g_emlrt_marshallIn
  (SFc3_7vqb7o7CaUJzbPKhFMyx3F_WECSim_LibInstanceStruct *chartInstance, const
   mxArray *c3_7vqb7o7CaUJzbPKhFMyx3F_b_u, const emlrtMsgIdentifier
   *c3_7vqb7o7CaUJzbPKhFMyx3F_parentId);
static void c3_7vqb7o7CaUJzbPKhFMyx3F_d_sf_marshallIn(void *chartInstanceVoid,
  const mxArray *c3_7vqb7o7CaUJzbPKhFMyx3F_mxArrayInData, const char_T
  *c3_7vqb7o7CaUJzbPKhFMyx3F_varName, void *c3_7vqb7o7CaUJzbPKhFMyx3F_outData);
static void c3_7vqb7o7CaUJzbPKhFMyx3F_h_emlrt_marshallIn
  (SFc3_7vqb7o7CaUJzbPKhFMyx3F_WECSim_LibInstanceStruct *chartInstance, const
   mxArray *c3_7vqb7o7CaUJzbPKhFMyx3F_b_u, const emlrtMsgIdentifier
   *c3_7vqb7o7CaUJzbPKhFMyx3F_parentId, real_T c3_7vqb7o7CaUJzbPKhFMyx3F_y[601]);
static void c3_7vqb7o7CaUJzbPKhFMyx3F_e_sf_marshallIn(void *chartInstanceVoid,
  const mxArray *c3_7vqb7o7CaUJzbPKhFMyx3F_mxArrayInData, const char_T
  *c3_7vqb7o7CaUJzbPKhFMyx3F_varName, void *c3_7vqb7o7CaUJzbPKhFMyx3F_outData);
static const mxArray *c3_7vqb7o7CaUJzbPKhFMyx3F_h_sf_marshallOut(void
  *chartInstanceVoid, void *c3_7vqb7o7CaUJzbPKhFMyx3F_b_inData);
static void c3_7vqb7o7CaUJzbPKhFMyx3F_i_emlrt_marshallIn
  (SFc3_7vqb7o7CaUJzbPKhFMyx3F_WECSim_LibInstanceStruct *chartInstance, const
   mxArray *c3_7vqb7o7CaUJzbPKhFMyx3F_b_u, const emlrtMsgIdentifier
   *c3_7vqb7o7CaUJzbPKhFMyx3F_parentId, real_T c3_7vqb7o7CaUJzbPKhFMyx3F_y[36]);
static void c3_7vqb7o7CaUJzbPKhFMyx3F_f_sf_marshallIn(void *chartInstanceVoid,
  const mxArray *c3_7vqb7o7CaUJzbPKhFMyx3F_mxArrayInData, const char_T
  *c3_7vqb7o7CaUJzbPKhFMyx3F_varName, void *c3_7vqb7o7CaUJzbPKhFMyx3F_outData);
static void c3_7vqb7o7CaUJzbPKhFMyx3F_info_helper(const mxArray
  **c3_7vqb7o7CaUJzbPKhFMyx3F_info);
static const mxArray *c3_7vqb7o7CaUJzbPKhFMyx3F_emlrt_marshallOut(const char
  * c3_7vqb7o7CaUJzbPKhFMyx3F_b_u);
static const mxArray *c3_7vqb7o7CaUJzbPKhFMyx3F_b_emlrt_marshallOut(const
  uint32_T c3_7vqb7o7CaUJzbPKhFMyx3F_b_u);
static real_T c3_7vqb7o7CaUJzbPKhFMyx3F_floor
  (SFc3_7vqb7o7CaUJzbPKhFMyx3F_WECSim_LibInstanceStruct *chartInstance, real_T
   c3_7vqb7o7CaUJzbPKhFMyx3F_x);
static real_T c3_7vqb7o7CaUJzbPKhFMyx3F_abs
  (SFc3_7vqb7o7CaUJzbPKhFMyx3F_WECSim_LibInstanceStruct *chartInstance, real_T
   c3_7vqb7o7CaUJzbPKhFMyx3F_x);
static real_T c3_7vqb7o7CaUJzbPKhFMyx3F_trapz
  (SFc3_7vqb7o7CaUJzbPKhFMyx3F_WECSim_LibInstanceStruct *chartInstance, real_T
   c3_7vqb7o7CaUJzbPKhFMyx3F_x[601], real_T c3_7vqb7o7CaUJzbPKhFMyx3F_y[601]);
static int32_T c3_7vqb7o7CaUJzbPKhFMyx3F_intmin
  (SFc3_7vqb7o7CaUJzbPKhFMyx3F_WECSim_LibInstanceStruct *chartInstance);
static real_T c3_7vqb7o7CaUJzbPKhFMyx3F_sum
  (SFc3_7vqb7o7CaUJzbPKhFMyx3F_WECSim_LibInstanceStruct *chartInstance, real_T
   c3_7vqb7o7CaUJzbPKhFMyx3F_x[6]);
static const mxArray *c3_7vqb7o7CaUJzbPKhFMyx3F_i_sf_marshallOut(void
  *chartInstanceVoid, void *c3_7vqb7o7CaUJzbPKhFMyx3F_b_inData);
static int32_T c3_7vqb7o7CaUJzbPKhFMyx3F_j_emlrt_marshallIn
  (SFc3_7vqb7o7CaUJzbPKhFMyx3F_WECSim_LibInstanceStruct *chartInstance, const
   mxArray *c3_7vqb7o7CaUJzbPKhFMyx3F_b_u, const emlrtMsgIdentifier
   *c3_7vqb7o7CaUJzbPKhFMyx3F_parentId);
static void c3_7vqb7o7CaUJzbPKhFMyx3F_g_sf_marshallIn(void *chartInstanceVoid,
  const mxArray *c3_7vqb7o7CaUJzbPKhFMyx3F_mxArrayInData, const char_T
  *c3_7vqb7o7CaUJzbPKhFMyx3F_varName, void *c3_7vqb7o7CaUJzbPKhFMyx3F_outData);
static uint8_T c3_7vqb7o7CaUJzbPKhFMyx3F_k_emlrt_marshallIn
  (SFc3_7vqb7o7CaUJzbPKhFMyx3F_WECSim_LibInstanceStruct *chartInstance, const
   mxArray *c3_7vqb7o7CaUJzbPKhFMyx3F_b_is_active_c3_7vqb7o7CaUJzbPKhFMyx3F_,
   const char_T *c3_7vqb7o7CaUJzbPKhFMyx3F_identifier);
static uint8_T c3_7vqb7o7CaUJzbPKhFMyx3F_l_emlrt_marshallIn
  (SFc3_7vqb7o7CaUJzbPKhFMyx3F_WECSim_LibInstanceStruct *chartInstance, const
   mxArray *c3_7vqb7o7CaUJzbPKhFMyx3F_b_u, const emlrtMsgIdentifier
   *c3_7vqb7o7CaUJzbPKhFMyx3F_parentId);
static void c3_7vqb7o7CaUJzbPKhFMyx3F_b_floor
  (SFc3_7vqb7o7CaUJzbPKhFMyx3F_WECSim_LibInstanceStruct *chartInstance, real_T
   *c3_7vqb7o7CaUJzbPKhFMyx3F_x);
static void init_dsm_address_info
  (SFc3_7vqb7o7CaUJzbPKhFMyx3F_WECSim_LibInstanceStruct *chartInstance);
static void init_simulink_io_address
  (SFc3_7vqb7o7CaUJzbPKhFMyx3F_WECSim_LibInstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c3_7vqb7o7CaUJzbPKhFMyx3F_WECSim_Lib
  (SFc3_7vqb7o7CaUJzbPKhFMyx3F_WECSim_LibInstanceStruct *chartInstance)
{
  chartInstance->c3_7vqb7o7CaUJzbPKhFMyx3F_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c3_7vqb7o7CaUJzbPKhFMyx3F_velocity_not_empty = false;
  chartInstance->c3_7vqb7o7CaUJzbPKhFMyx3F_kkk_not_empty = false;
  chartInstance->c3_7vqb7o7CaUJzbPKhFMyx3F_is_active_c3_7vqb7o7CaUJzbPKhFMyx3F_WE
    = 0U;
}

static void initialize_params_c3_7vqb7o7CaUJzbPKhFMyx3F_WECSim_Lib
  (SFc3_7vqb7o7CaUJzbPKhFMyx3F_WECSim_LibInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void enable_c3_7vqb7o7CaUJzbPKhFMyx3F_WECSim_Lib
  (SFc3_7vqb7o7CaUJzbPKhFMyx3F_WECSim_LibInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c3_7vqb7o7CaUJzbPKhFMyx3F_WECSim_Lib
  (SFc3_7vqb7o7CaUJzbPKhFMyx3F_WECSim_LibInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c3_7vqb7o7CaUJzbPKhFMyx3F_update_debugger_state_c3_7vqb7o7CaUJzb
  (SFc3_7vqb7o7CaUJzbPKhFMyx3F_WECSim_LibInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c3_7vqb7o7CaUJzbPKhFMyx3F_WECSim_Lib
  (SFc3_7vqb7o7CaUJzbPKhFMyx3F_WECSim_LibInstanceStruct *chartInstance)
{
  const mxArray *c3_7vqb7o7CaUJzbPKhFMyx3F_st;
  const mxArray *c3_7vqb7o7CaUJzbPKhFMyx3F_y = NULL;
  int32_T c3_7vqb7o7CaUJzbPKhFMyx3F_i0;
  real_T c3_7vqb7o7CaUJzbPKhFMyx3F_b_u[6];
  const mxArray *c3_7vqb7o7CaUJzbPKhFMyx3F_b_y = NULL;
  real_T c3_7vqb7o7CaUJzbPKhFMyx3F_hoistedGlobal;
  real_T c3_7vqb7o7CaUJzbPKhFMyx3F_c_u;
  const mxArray *c3_7vqb7o7CaUJzbPKhFMyx3F_c_y = NULL;
  int32_T c3_7vqb7o7CaUJzbPKhFMyx3F_i1;
  real_T c3_7vqb7o7CaUJzbPKhFMyx3F_d_u[3606];
  const mxArray *c3_7vqb7o7CaUJzbPKhFMyx3F_d_y = NULL;
  uint8_T c3_7vqb7o7CaUJzbPKhFMyx3F_b_hoistedGlobal;
  uint8_T c3_7vqb7o7CaUJzbPKhFMyx3F_e_u;
  const mxArray *c3_7vqb7o7CaUJzbPKhFMyx3F_e_y = NULL;
  c3_7vqb7o7CaUJzbPKhFMyx3F_st = NULL;
  c3_7vqb7o7CaUJzbPKhFMyx3F_st = NULL;
  c3_7vqb7o7CaUJzbPKhFMyx3F_y = NULL;
  sf_mex_assign(&c3_7vqb7o7CaUJzbPKhFMyx3F_y, sf_mex_createcellmatrix(4, 1),
                false);
  for (c3_7vqb7o7CaUJzbPKhFMyx3F_i0 = 0; c3_7vqb7o7CaUJzbPKhFMyx3F_i0 < 6;
       c3_7vqb7o7CaUJzbPKhFMyx3F_i0++) {
    c3_7vqb7o7CaUJzbPKhFMyx3F_b_u[c3_7vqb7o7CaUJzbPKhFMyx3F_i0] =
      (*chartInstance->c3_7vqb7o7CaUJzbPKhFMyx3F_F_FM)
      [c3_7vqb7o7CaUJzbPKhFMyx3F_i0];
  }

  c3_7vqb7o7CaUJzbPKhFMyx3F_b_y = NULL;
  sf_mex_assign(&c3_7vqb7o7CaUJzbPKhFMyx3F_b_y, sf_mex_create("y",
    c3_7vqb7o7CaUJzbPKhFMyx3F_b_u, 0, 0U, 1U, 0U, 1, 6), false);
  sf_mex_setcell(c3_7vqb7o7CaUJzbPKhFMyx3F_y, 0, c3_7vqb7o7CaUJzbPKhFMyx3F_b_y);
  c3_7vqb7o7CaUJzbPKhFMyx3F_hoistedGlobal =
    chartInstance->c3_7vqb7o7CaUJzbPKhFMyx3F_kkk;
  c3_7vqb7o7CaUJzbPKhFMyx3F_c_u = c3_7vqb7o7CaUJzbPKhFMyx3F_hoistedGlobal;
  c3_7vqb7o7CaUJzbPKhFMyx3F_c_y = NULL;
  if (!chartInstance->c3_7vqb7o7CaUJzbPKhFMyx3F_kkk_not_empty) {
    sf_mex_assign(&c3_7vqb7o7CaUJzbPKhFMyx3F_c_y, sf_mex_create("y", NULL, 0, 0U,
      1U, 0U, 2, 0, 0), false);
  } else {
    sf_mex_assign(&c3_7vqb7o7CaUJzbPKhFMyx3F_c_y, sf_mex_create("y",
      &c3_7vqb7o7CaUJzbPKhFMyx3F_c_u, 0, 0U, 0U, 0U, 0), false);
  }

  sf_mex_setcell(c3_7vqb7o7CaUJzbPKhFMyx3F_y, 1, c3_7vqb7o7CaUJzbPKhFMyx3F_c_y);
  for (c3_7vqb7o7CaUJzbPKhFMyx3F_i1 = 0; c3_7vqb7o7CaUJzbPKhFMyx3F_i1 < 3606;
       c3_7vqb7o7CaUJzbPKhFMyx3F_i1++) {
    c3_7vqb7o7CaUJzbPKhFMyx3F_d_u[c3_7vqb7o7CaUJzbPKhFMyx3F_i1] =
      chartInstance->
      c3_7vqb7o7CaUJzbPKhFMyx3F_velocity[c3_7vqb7o7CaUJzbPKhFMyx3F_i1];
  }

  c3_7vqb7o7CaUJzbPKhFMyx3F_d_y = NULL;
  if (!chartInstance->c3_7vqb7o7CaUJzbPKhFMyx3F_velocity_not_empty) {
    sf_mex_assign(&c3_7vqb7o7CaUJzbPKhFMyx3F_d_y, sf_mex_create("y", NULL, 0, 0U,
      1U, 0U, 2, 0, 0), false);
  } else {
    sf_mex_assign(&c3_7vqb7o7CaUJzbPKhFMyx3F_d_y, sf_mex_create("y",
      c3_7vqb7o7CaUJzbPKhFMyx3F_d_u, 0, 0U, 1U, 0U, 2, 6, 601), false);
  }

  sf_mex_setcell(c3_7vqb7o7CaUJzbPKhFMyx3F_y, 2, c3_7vqb7o7CaUJzbPKhFMyx3F_d_y);
  c3_7vqb7o7CaUJzbPKhFMyx3F_b_hoistedGlobal =
    chartInstance->c3_7vqb7o7CaUJzbPKhFMyx3F_is_active_c3_7vqb7o7CaUJzbPKhFMyx3F_WE;
  c3_7vqb7o7CaUJzbPKhFMyx3F_e_u = c3_7vqb7o7CaUJzbPKhFMyx3F_b_hoistedGlobal;
  c3_7vqb7o7CaUJzbPKhFMyx3F_e_y = NULL;
  sf_mex_assign(&c3_7vqb7o7CaUJzbPKhFMyx3F_e_y, sf_mex_create("y",
    &c3_7vqb7o7CaUJzbPKhFMyx3F_e_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c3_7vqb7o7CaUJzbPKhFMyx3F_y, 3, c3_7vqb7o7CaUJzbPKhFMyx3F_e_y);
  sf_mex_assign(&c3_7vqb7o7CaUJzbPKhFMyx3F_st, c3_7vqb7o7CaUJzbPKhFMyx3F_y,
                false);
  return c3_7vqb7o7CaUJzbPKhFMyx3F_st;
}

static void set_sim_state_c3_7vqb7o7CaUJzbPKhFMyx3F_WECSim_Lib
  (SFc3_7vqb7o7CaUJzbPKhFMyx3F_WECSim_LibInstanceStruct *chartInstance, const
   mxArray *c3_7vqb7o7CaUJzbPKhFMyx3F_st)
{
  const mxArray *c3_7vqb7o7CaUJzbPKhFMyx3F_b_u;
  real_T c3_7vqb7o7CaUJzbPKhFMyx3F_dv0[6];
  int32_T c3_7vqb7o7CaUJzbPKhFMyx3F_i2;
  real_T c3_7vqb7o7CaUJzbPKhFMyx3F_dv1[3606];
  int32_T c3_7vqb7o7CaUJzbPKhFMyx3F_i3;
  chartInstance->c3_7vqb7o7CaUJzbPKhFMyx3F_doneDoubleBufferReInit = true;
  c3_7vqb7o7CaUJzbPKhFMyx3F_b_u = sf_mex_dup(c3_7vqb7o7CaUJzbPKhFMyx3F_st);
  c3_7vqb7o7CaUJzbPKhFMyx3F_e_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c3_7vqb7o7CaUJzbPKhFMyx3F_b_u, 0)), "F_FM",
    c3_7vqb7o7CaUJzbPKhFMyx3F_dv0);
  for (c3_7vqb7o7CaUJzbPKhFMyx3F_i2 = 0; c3_7vqb7o7CaUJzbPKhFMyx3F_i2 < 6;
       c3_7vqb7o7CaUJzbPKhFMyx3F_i2++) {
    (*chartInstance->c3_7vqb7o7CaUJzbPKhFMyx3F_F_FM)
      [c3_7vqb7o7CaUJzbPKhFMyx3F_i2] =
      c3_7vqb7o7CaUJzbPKhFMyx3F_dv0[c3_7vqb7o7CaUJzbPKhFMyx3F_i2];
  }

  chartInstance->c3_7vqb7o7CaUJzbPKhFMyx3F_kkk =
    c3_7vqb7o7CaUJzbPKhFMyx3F_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c3_7vqb7o7CaUJzbPKhFMyx3F_b_u, 1)), "kkk");
  c3_7vqb7o7CaUJzbPKhFMyx3F_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c3_7vqb7o7CaUJzbPKhFMyx3F_b_u, 2)), "velocity",
    c3_7vqb7o7CaUJzbPKhFMyx3F_dv1);
  for (c3_7vqb7o7CaUJzbPKhFMyx3F_i3 = 0; c3_7vqb7o7CaUJzbPKhFMyx3F_i3 < 3606;
       c3_7vqb7o7CaUJzbPKhFMyx3F_i3++) {
    chartInstance->
      c3_7vqb7o7CaUJzbPKhFMyx3F_velocity[c3_7vqb7o7CaUJzbPKhFMyx3F_i3] =
      c3_7vqb7o7CaUJzbPKhFMyx3F_dv1[c3_7vqb7o7CaUJzbPKhFMyx3F_i3];
  }

  chartInstance->c3_7vqb7o7CaUJzbPKhFMyx3F_is_active_c3_7vqb7o7CaUJzbPKhFMyx3F_WE
    = c3_7vqb7o7CaUJzbPKhFMyx3F_k_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c3_7vqb7o7CaUJzbPKhFMyx3F_b_u, 3)),
    "is_active_c3_7vqb7o7CaUJzbPKhFMyx3F_WECSim_Lib");
  sf_mex_destroy(&c3_7vqb7o7CaUJzbPKhFMyx3F_b_u);
  c3_7vqb7o7CaUJzbPKhFMyx3F_update_debugger_state_c3_7vqb7o7CaUJzb(chartInstance);
  sf_mex_destroy(&c3_7vqb7o7CaUJzbPKhFMyx3F_st);
}

static void finalize_c3_7vqb7o7CaUJzbPKhFMyx3F_WECSim_Lib
  (SFc3_7vqb7o7CaUJzbPKhFMyx3F_WECSim_LibInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void sf_gateway_c3_7vqb7o7CaUJzbPKhFMyx3F_WECSim_Lib
  (SFc3_7vqb7o7CaUJzbPKhFMyx3F_WECSim_LibInstanceStruct *chartInstance)
{
  int32_T c3_7vqb7o7CaUJzbPKhFMyx3F_i4;
  int32_T c3_7vqb7o7CaUJzbPKhFMyx3F_i5;
  int32_T c3_7vqb7o7CaUJzbPKhFMyx3F_i6;
  int32_T c3_7vqb7o7CaUJzbPKhFMyx3F_i7;
  int32_T c3_7vqb7o7CaUJzbPKhFMyx3F_i8;
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 0U,
               chartInstance->c3_7vqb7o7CaUJzbPKhFMyx3F_sfEvent);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c3_7vqb7o7CaUJzbPKhFMyx3F_check, 0U);
  for (c3_7vqb7o7CaUJzbPKhFMyx3F_i4 = 0; c3_7vqb7o7CaUJzbPKhFMyx3F_i4 < 6;
       c3_7vqb7o7CaUJzbPKhFMyx3F_i4++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c3_7vqb7o7CaUJzbPKhFMyx3F_v)
                          [c3_7vqb7o7CaUJzbPKhFMyx3F_i4], 1U);
  }

  chartInstance->c3_7vqb7o7CaUJzbPKhFMyx3F_sfEvent = CALL_EVENT;
  c3_7vqb7o7CaUJzbPKhFMyx3F_chartstep_c3_7vqb7o7CaUJzbPKhFMyx3F_WE(chartInstance);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_WECSim_LibMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
  for (c3_7vqb7o7CaUJzbPKhFMyx3F_i5 = 0; c3_7vqb7o7CaUJzbPKhFMyx3F_i5 < 6;
       c3_7vqb7o7CaUJzbPKhFMyx3F_i5++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c3_7vqb7o7CaUJzbPKhFMyx3F_F_FM)
                          [c3_7vqb7o7CaUJzbPKhFMyx3F_i5], 2U);
  }

  for (c3_7vqb7o7CaUJzbPKhFMyx3F_i6 = 0; c3_7vqb7o7CaUJzbPKhFMyx3F_i6 < 3606;
       c3_7vqb7o7CaUJzbPKhFMyx3F_i6++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c3_7vqb7o7CaUJzbPKhFMyx3F_ZeroVel)
                          [c3_7vqb7o7CaUJzbPKhFMyx3F_i6], 3U);
  }

  for (c3_7vqb7o7CaUJzbPKhFMyx3F_i7 = 0; c3_7vqb7o7CaUJzbPKhFMyx3F_i7 < 43272;
       c3_7vqb7o7CaUJzbPKhFMyx3F_i7++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c3_7vqb7o7CaUJzbPKhFMyx3F_b_IRKB)
                          [c3_7vqb7o7CaUJzbPKhFMyx3F_i7], 4U);
  }

  for (c3_7vqb7o7CaUJzbPKhFMyx3F_i8 = 0; c3_7vqb7o7CaUJzbPKhFMyx3F_i8 < 601;
       c3_7vqb7o7CaUJzbPKhFMyx3F_i8++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c3_7vqb7o7CaUJzbPKhFMyx3F_CTTime)
                          [c3_7vqb7o7CaUJzbPKhFMyx3F_i8], 5U);
  }
}

static void mdl_start_c3_7vqb7o7CaUJzbPKhFMyx3F_WECSim_Lib
  (SFc3_7vqb7o7CaUJzbPKhFMyx3F_WECSim_LibInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c3_7vqb7o7CaUJzbPKhFMyx3F_chartstep_c3_7vqb7o7CaUJzbPKhFMyx3F_WE
  (SFc3_7vqb7o7CaUJzbPKhFMyx3F_WECSim_LibInstanceStruct *chartInstance)
{
  real_T c3_7vqb7o7CaUJzbPKhFMyx3F_hoistedGlobal;
  real_T c3_7vqb7o7CaUJzbPKhFMyx3F_b_check;
  int32_T c3_7vqb7o7CaUJzbPKhFMyx3F_i9;
  real_T c3_7vqb7o7CaUJzbPKhFMyx3F_b_v[6];
  int32_T c3_7vqb7o7CaUJzbPKhFMyx3F_i10;
  real_T c3_7vqb7o7CaUJzbPKhFMyx3F_b_ZeroVel[3606];
  int32_T c3_7vqb7o7CaUJzbPKhFMyx3F_i11;
  int32_T c3_7vqb7o7CaUJzbPKhFMyx3F_i12;
  real_T c3_7vqb7o7CaUJzbPKhFMyx3F_b_CTTime[601];
  uint32_T c3_7vqb7o7CaUJzbPKhFMyx3F_debug_family_var_map[16];
  real_T c3_7vqb7o7CaUJzbPKhFMyx3F_tmpT[6];
  real_T c3_7vqb7o7CaUJzbPKhFMyx3F_int2;
  real_T c3_7vqb7o7CaUJzbPKhFMyx3F_tmpF[36];
  real_T c3_7vqb7o7CaUJzbPKhFMyx3F_kd;
  real_T c3_7vqb7o7CaUJzbPKhFMyx3F_kk;
  real_T c3_7vqb7o7CaUJzbPKhFMyx3F_tmpY[601];
  real_T c3_7vqb7o7CaUJzbPKhFMyx3F_nargin = 5.0;
  real_T c3_7vqb7o7CaUJzbPKhFMyx3F_nargout = 1.0;
  real_T c3_7vqb7o7CaUJzbPKhFMyx3F_b_F_FM[6];
  int32_T c3_7vqb7o7CaUJzbPKhFMyx3F_i13;
  int32_T c3_7vqb7o7CaUJzbPKhFMyx3F_i14;
  real_T c3_7vqb7o7CaUJzbPKhFMyx3F_b_hoistedGlobal;
  real_T c3_7vqb7o7CaUJzbPKhFMyx3F_c_hoistedGlobal;
  real_T c3_7vqb7o7CaUJzbPKhFMyx3F_A;
  real_T c3_7vqb7o7CaUJzbPKhFMyx3F_x;
  real_T c3_7vqb7o7CaUJzbPKhFMyx3F_b_x;
  real_T c3_7vqb7o7CaUJzbPKhFMyx3F_c_x;
  real_T c3_7vqb7o7CaUJzbPKhFMyx3F_y;
  real_T c3_7vqb7o7CaUJzbPKhFMyx3F_d0;
  int32_T c3_7vqb7o7CaUJzbPKhFMyx3F_i15;
  int32_T c3_7vqb7o7CaUJzbPKhFMyx3F_i16;
  int32_T c3_7vqb7o7CaUJzbPKhFMyx3F_i17;
  real_T c3_7vqb7o7CaUJzbPKhFMyx3F_dv2[3600];
  int32_T c3_7vqb7o7CaUJzbPKhFMyx3F_i18;
  int32_T c3_7vqb7o7CaUJzbPKhFMyx3F_i19;
  int32_T c3_7vqb7o7CaUJzbPKhFMyx3F_i20;
  int32_T c3_7vqb7o7CaUJzbPKhFMyx3F_i21;
  int32_T c3_7vqb7o7CaUJzbPKhFMyx3F_i22;
  int32_T c3_7vqb7o7CaUJzbPKhFMyx3F_i23;
  int32_T c3_7vqb7o7CaUJzbPKhFMyx3F_b_kd;
  int32_T c3_7vqb7o7CaUJzbPKhFMyx3F_b_kk;
  int32_T c3_7vqb7o7CaUJzbPKhFMyx3F_c_kk;
  int32_T c3_7vqb7o7CaUJzbPKhFMyx3F_c_kd;
  int32_T c3_7vqb7o7CaUJzbPKhFMyx3F_d_kk;
  int32_T c3_7vqb7o7CaUJzbPKhFMyx3F_i24;
  int32_T c3_7vqb7o7CaUJzbPKhFMyx3F_i25;
  real_T c3_7vqb7o7CaUJzbPKhFMyx3F_c_CTTime[601];
  int32_T c3_7vqb7o7CaUJzbPKhFMyx3F_i26;
  real_T c3_7vqb7o7CaUJzbPKhFMyx3F_b_tmpY[601];
  int32_T c3_7vqb7o7CaUJzbPKhFMyx3F_d_kd;
  int32_T c3_7vqb7o7CaUJzbPKhFMyx3F_i27;
  real_T c3_7vqb7o7CaUJzbPKhFMyx3F_b_tmpF[6];
  int32_T c3_7vqb7o7CaUJzbPKhFMyx3F_i28;
  int32_T c3_7vqb7o7CaUJzbPKhFMyx3F_i29;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 0U,
               chartInstance->c3_7vqb7o7CaUJzbPKhFMyx3F_sfEvent);
  c3_7vqb7o7CaUJzbPKhFMyx3F_hoistedGlobal =
    *chartInstance->c3_7vqb7o7CaUJzbPKhFMyx3F_check;
  c3_7vqb7o7CaUJzbPKhFMyx3F_b_check = c3_7vqb7o7CaUJzbPKhFMyx3F_hoistedGlobal;
  for (c3_7vqb7o7CaUJzbPKhFMyx3F_i9 = 0; c3_7vqb7o7CaUJzbPKhFMyx3F_i9 < 6;
       c3_7vqb7o7CaUJzbPKhFMyx3F_i9++) {
    c3_7vqb7o7CaUJzbPKhFMyx3F_b_v[c3_7vqb7o7CaUJzbPKhFMyx3F_i9] =
      (*chartInstance->c3_7vqb7o7CaUJzbPKhFMyx3F_v)[c3_7vqb7o7CaUJzbPKhFMyx3F_i9];
  }

  for (c3_7vqb7o7CaUJzbPKhFMyx3F_i10 = 0; c3_7vqb7o7CaUJzbPKhFMyx3F_i10 < 3606;
       c3_7vqb7o7CaUJzbPKhFMyx3F_i10++) {
    c3_7vqb7o7CaUJzbPKhFMyx3F_b_ZeroVel[c3_7vqb7o7CaUJzbPKhFMyx3F_i10] =
      (*chartInstance->c3_7vqb7o7CaUJzbPKhFMyx3F_ZeroVel)
      [c3_7vqb7o7CaUJzbPKhFMyx3F_i10];
  }

  for (c3_7vqb7o7CaUJzbPKhFMyx3F_i11 = 0; c3_7vqb7o7CaUJzbPKhFMyx3F_i11 < 43272;
       c3_7vqb7o7CaUJzbPKhFMyx3F_i11++) {
    chartInstance->c3_7vqb7o7CaUJzbPKhFMyx3F_IRKB[c3_7vqb7o7CaUJzbPKhFMyx3F_i11]
      = (*chartInstance->c3_7vqb7o7CaUJzbPKhFMyx3F_b_IRKB)
      [c3_7vqb7o7CaUJzbPKhFMyx3F_i11];
  }

  for (c3_7vqb7o7CaUJzbPKhFMyx3F_i12 = 0; c3_7vqb7o7CaUJzbPKhFMyx3F_i12 < 601;
       c3_7vqb7o7CaUJzbPKhFMyx3F_i12++) {
    c3_7vqb7o7CaUJzbPKhFMyx3F_b_CTTime[c3_7vqb7o7CaUJzbPKhFMyx3F_i12] =
      (*chartInstance->c3_7vqb7o7CaUJzbPKhFMyx3F_CTTime)
      [c3_7vqb7o7CaUJzbPKhFMyx3F_i12];
  }

  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 16U, 16U,
    c3_7vqb7o7CaUJzbPKhFMyx3F_debug_family_names,
    c3_7vqb7o7CaUJzbPKhFMyx3F_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c3_7vqb7o7CaUJzbPKhFMyx3F_tmpT, 0U,
    c3_7vqb7o7CaUJzbPKhFMyx3F_c_sf_marshallOut,
    c3_7vqb7o7CaUJzbPKhFMyx3F_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_7vqb7o7CaUJzbPKhFMyx3F_int2, 1U,
    c3_7vqb7o7CaUJzbPKhFMyx3F_g_sf_marshallOut,
    c3_7vqb7o7CaUJzbPKhFMyx3F_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c3_7vqb7o7CaUJzbPKhFMyx3F_tmpF, 2U,
    c3_7vqb7o7CaUJzbPKhFMyx3F_h_sf_marshallOut,
    c3_7vqb7o7CaUJzbPKhFMyx3F_f_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_7vqb7o7CaUJzbPKhFMyx3F_kd, 3U,
    c3_7vqb7o7CaUJzbPKhFMyx3F_g_sf_marshallOut,
    c3_7vqb7o7CaUJzbPKhFMyx3F_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_7vqb7o7CaUJzbPKhFMyx3F_kk, 4U,
    c3_7vqb7o7CaUJzbPKhFMyx3F_g_sf_marshallOut,
    c3_7vqb7o7CaUJzbPKhFMyx3F_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c3_7vqb7o7CaUJzbPKhFMyx3F_tmpY, 5U,
    c3_7vqb7o7CaUJzbPKhFMyx3F_d_sf_marshallOut,
    c3_7vqb7o7CaUJzbPKhFMyx3F_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_7vqb7o7CaUJzbPKhFMyx3F_nargin, 6U,
    c3_7vqb7o7CaUJzbPKhFMyx3F_g_sf_marshallOut,
    c3_7vqb7o7CaUJzbPKhFMyx3F_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_7vqb7o7CaUJzbPKhFMyx3F_nargout, 7U,
    c3_7vqb7o7CaUJzbPKhFMyx3F_g_sf_marshallOut,
    c3_7vqb7o7CaUJzbPKhFMyx3F_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c3_7vqb7o7CaUJzbPKhFMyx3F_b_check, 8U,
    c3_7vqb7o7CaUJzbPKhFMyx3F_g_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c3_7vqb7o7CaUJzbPKhFMyx3F_b_v, 9U,
    c3_7vqb7o7CaUJzbPKhFMyx3F_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c3_7vqb7o7CaUJzbPKhFMyx3F_b_ZeroVel, 10U,
    c3_7vqb7o7CaUJzbPKhFMyx3F_f_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(chartInstance->c3_7vqb7o7CaUJzbPKhFMyx3F_IRKB, 11U,
    c3_7vqb7o7CaUJzbPKhFMyx3F_e_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c3_7vqb7o7CaUJzbPKhFMyx3F_b_CTTime, 12U,
    c3_7vqb7o7CaUJzbPKhFMyx3F_d_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c3_7vqb7o7CaUJzbPKhFMyx3F_b_F_FM, 13U,
    c3_7vqb7o7CaUJzbPKhFMyx3F_c_sf_marshallOut,
    c3_7vqb7o7CaUJzbPKhFMyx3F_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE
    (chartInstance->c3_7vqb7o7CaUJzbPKhFMyx3F_velocity, 14U,
     c3_7vqb7o7CaUJzbPKhFMyx3F_b_sf_marshallOut,
     c3_7vqb7o7CaUJzbPKhFMyx3F_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE
    (&chartInstance->c3_7vqb7o7CaUJzbPKhFMyx3F_kkk, 15U,
     c3_7vqb7o7CaUJzbPKhFMyx3F_sf_marshallOut,
     c3_7vqb7o7CaUJzbPKhFMyx3F_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c3_7vqb7o7CaUJzbPKhFMyx3F_sfEvent, 4);
  _SFD_EML_CALL(0U, chartInstance->c3_7vqb7o7CaUJzbPKhFMyx3F_sfEvent, 5);
  _SFD_EML_CALL(0U, chartInstance->c3_7vqb7o7CaUJzbPKhFMyx3F_sfEvent, 7);
  if (CV_EML_IF(0, 1, 0, CV_RELATIONAL_EVAL(4U, 0U, 0,
        c3_7vqb7o7CaUJzbPKhFMyx3F_b_check, 10.0, -1, 0U,
        c3_7vqb7o7CaUJzbPKhFMyx3F_b_check == 10.0))) {
    _SFD_EML_CALL(0U, chartInstance->c3_7vqb7o7CaUJzbPKhFMyx3F_sfEvent, 8);
    for (c3_7vqb7o7CaUJzbPKhFMyx3F_i13 = 0; c3_7vqb7o7CaUJzbPKhFMyx3F_i13 < 6;
         c3_7vqb7o7CaUJzbPKhFMyx3F_i13++) {
      c3_7vqb7o7CaUJzbPKhFMyx3F_tmpT[c3_7vqb7o7CaUJzbPKhFMyx3F_i13] = 0.0;
    }
  } else {
    _SFD_EML_CALL(0U, chartInstance->c3_7vqb7o7CaUJzbPKhFMyx3F_sfEvent, 10);
    if (CV_EML_IF(0, 1, 1,
                  !chartInstance->c3_7vqb7o7CaUJzbPKhFMyx3F_velocity_not_empty))
    {
      _SFD_EML_CALL(0U, chartInstance->c3_7vqb7o7CaUJzbPKhFMyx3F_sfEvent, 11);
      for (c3_7vqb7o7CaUJzbPKhFMyx3F_i14 = 0; c3_7vqb7o7CaUJzbPKhFMyx3F_i14 <
           3606; c3_7vqb7o7CaUJzbPKhFMyx3F_i14++) {
        chartInstance->
          c3_7vqb7o7CaUJzbPKhFMyx3F_velocity[c3_7vqb7o7CaUJzbPKhFMyx3F_i14] =
          c3_7vqb7o7CaUJzbPKhFMyx3F_b_ZeroVel[c3_7vqb7o7CaUJzbPKhFMyx3F_i14];
      }

      chartInstance->c3_7vqb7o7CaUJzbPKhFMyx3F_velocity_not_empty = true;
      _SFD_EML_CALL(0U, chartInstance->c3_7vqb7o7CaUJzbPKhFMyx3F_sfEvent, 12);
      chartInstance->c3_7vqb7o7CaUJzbPKhFMyx3F_kkk = 0.0;
      chartInstance->c3_7vqb7o7CaUJzbPKhFMyx3F_kkk_not_empty = true;
    } else {
      _SFD_EML_CALL(0U, chartInstance->c3_7vqb7o7CaUJzbPKhFMyx3F_sfEvent, 14);
      chartInstance->c3_7vqb7o7CaUJzbPKhFMyx3F_kkk++;
      _SFD_EML_CALL(0U, chartInstance->c3_7vqb7o7CaUJzbPKhFMyx3F_sfEvent, 15);
      c3_7vqb7o7CaUJzbPKhFMyx3F_b_hoistedGlobal =
        chartInstance->c3_7vqb7o7CaUJzbPKhFMyx3F_kkk;
      c3_7vqb7o7CaUJzbPKhFMyx3F_c_hoistedGlobal =
        chartInstance->c3_7vqb7o7CaUJzbPKhFMyx3F_kkk;
      c3_7vqb7o7CaUJzbPKhFMyx3F_A = c3_7vqb7o7CaUJzbPKhFMyx3F_c_hoistedGlobal;
      c3_7vqb7o7CaUJzbPKhFMyx3F_x = c3_7vqb7o7CaUJzbPKhFMyx3F_A;
      c3_7vqb7o7CaUJzbPKhFMyx3F_b_x = c3_7vqb7o7CaUJzbPKhFMyx3F_x;
      c3_7vqb7o7CaUJzbPKhFMyx3F_c_x = c3_7vqb7o7CaUJzbPKhFMyx3F_b_x;
      c3_7vqb7o7CaUJzbPKhFMyx3F_y = c3_7vqb7o7CaUJzbPKhFMyx3F_c_x / 5.0;
      c3_7vqb7o7CaUJzbPKhFMyx3F_d0 = c3_7vqb7o7CaUJzbPKhFMyx3F_y;
      c3_7vqb7o7CaUJzbPKhFMyx3F_b_floor(chartInstance,
        &c3_7vqb7o7CaUJzbPKhFMyx3F_d0);
      c3_7vqb7o7CaUJzbPKhFMyx3F_int2 = c3_7vqb7o7CaUJzbPKhFMyx3F_abs
        (chartInstance, (c3_7vqb7o7CaUJzbPKhFMyx3F_b_hoistedGlobal -
                         c3_7vqb7o7CaUJzbPKhFMyx3F_d0 * 5.0) - 1.0);
      _SFD_EML_CALL(0U, chartInstance->c3_7vqb7o7CaUJzbPKhFMyx3F_sfEvent, 16);
      if (CV_EML_IF(0, 1, 2, CV_RELATIONAL_EVAL(4U, 0U, 1,
            c3_7vqb7o7CaUJzbPKhFMyx3F_int2, 1.0E-8, -1, 2U,
            c3_7vqb7o7CaUJzbPKhFMyx3F_int2 < 1.0E-8))) {
        _SFD_EML_CALL(0U, chartInstance->c3_7vqb7o7CaUJzbPKhFMyx3F_sfEvent, 17);
        c3_7vqb7o7CaUJzbPKhFMyx3F_i15 = 0;
        for (c3_7vqb7o7CaUJzbPKhFMyx3F_i16 = 0; c3_7vqb7o7CaUJzbPKhFMyx3F_i16 <
             600; c3_7vqb7o7CaUJzbPKhFMyx3F_i16++) {
          for (c3_7vqb7o7CaUJzbPKhFMyx3F_i17 = 0; c3_7vqb7o7CaUJzbPKhFMyx3F_i17 <
               6; c3_7vqb7o7CaUJzbPKhFMyx3F_i17++) {
            c3_7vqb7o7CaUJzbPKhFMyx3F_dv2[c3_7vqb7o7CaUJzbPKhFMyx3F_i17 +
              c3_7vqb7o7CaUJzbPKhFMyx3F_i15] =
              chartInstance->
              c3_7vqb7o7CaUJzbPKhFMyx3F_velocity[c3_7vqb7o7CaUJzbPKhFMyx3F_i17 +
              c3_7vqb7o7CaUJzbPKhFMyx3F_i15];
          }

          c3_7vqb7o7CaUJzbPKhFMyx3F_i15 += 6;
        }

        c3_7vqb7o7CaUJzbPKhFMyx3F_i18 = 0;
        for (c3_7vqb7o7CaUJzbPKhFMyx3F_i19 = 0; c3_7vqb7o7CaUJzbPKhFMyx3F_i19 <
             600; c3_7vqb7o7CaUJzbPKhFMyx3F_i19++) {
          for (c3_7vqb7o7CaUJzbPKhFMyx3F_i20 = 0; c3_7vqb7o7CaUJzbPKhFMyx3F_i20 <
               6; c3_7vqb7o7CaUJzbPKhFMyx3F_i20++) {
            chartInstance->c3_7vqb7o7CaUJzbPKhFMyx3F_velocity
              [(c3_7vqb7o7CaUJzbPKhFMyx3F_i20 + c3_7vqb7o7CaUJzbPKhFMyx3F_i18) +
              6] = c3_7vqb7o7CaUJzbPKhFMyx3F_dv2[c3_7vqb7o7CaUJzbPKhFMyx3F_i20 +
              c3_7vqb7o7CaUJzbPKhFMyx3F_i18];
          }

          c3_7vqb7o7CaUJzbPKhFMyx3F_i18 += 6;
        }
      }

      _SFD_EML_CALL(0U, chartInstance->c3_7vqb7o7CaUJzbPKhFMyx3F_sfEvent, 19);
      for (c3_7vqb7o7CaUJzbPKhFMyx3F_i21 = 0; c3_7vqb7o7CaUJzbPKhFMyx3F_i21 < 6;
           c3_7vqb7o7CaUJzbPKhFMyx3F_i21++) {
        chartInstance->
          c3_7vqb7o7CaUJzbPKhFMyx3F_velocity[c3_7vqb7o7CaUJzbPKhFMyx3F_i21] =
          c3_7vqb7o7CaUJzbPKhFMyx3F_b_v[c3_7vqb7o7CaUJzbPKhFMyx3F_i21];
      }
    }

    _SFD_EML_CALL(0U, chartInstance->c3_7vqb7o7CaUJzbPKhFMyx3F_sfEvent, 23);
    for (c3_7vqb7o7CaUJzbPKhFMyx3F_i22 = 0; c3_7vqb7o7CaUJzbPKhFMyx3F_i22 < 36;
         c3_7vqb7o7CaUJzbPKhFMyx3F_i22++) {
      c3_7vqb7o7CaUJzbPKhFMyx3F_tmpF[c3_7vqb7o7CaUJzbPKhFMyx3F_i22] = 0.0;
    }

    _SFD_EML_CALL(0U, chartInstance->c3_7vqb7o7CaUJzbPKhFMyx3F_sfEvent, 24);
    for (c3_7vqb7o7CaUJzbPKhFMyx3F_i23 = 0; c3_7vqb7o7CaUJzbPKhFMyx3F_i23 < 6;
         c3_7vqb7o7CaUJzbPKhFMyx3F_i23++) {
      c3_7vqb7o7CaUJzbPKhFMyx3F_tmpT[c3_7vqb7o7CaUJzbPKhFMyx3F_i23] = 0.0;
    }

    _SFD_EML_CALL(0U, chartInstance->c3_7vqb7o7CaUJzbPKhFMyx3F_sfEvent, 25);
    c3_7vqb7o7CaUJzbPKhFMyx3F_kd = 1.0;
    c3_7vqb7o7CaUJzbPKhFMyx3F_b_kd = 0;
    while (c3_7vqb7o7CaUJzbPKhFMyx3F_b_kd < 6) {
      c3_7vqb7o7CaUJzbPKhFMyx3F_kd = 1.0 + (real_T)
        c3_7vqb7o7CaUJzbPKhFMyx3F_b_kd;
      CV_EML_FOR(0, 1, 0, 1);
      _SFD_EML_CALL(0U, chartInstance->c3_7vqb7o7CaUJzbPKhFMyx3F_sfEvent, 26);
      c3_7vqb7o7CaUJzbPKhFMyx3F_kk = 1.0;
      c3_7vqb7o7CaUJzbPKhFMyx3F_b_kk = 0;
      while (c3_7vqb7o7CaUJzbPKhFMyx3F_b_kk < 6) {
        c3_7vqb7o7CaUJzbPKhFMyx3F_kk = 1.0 + (real_T)
          c3_7vqb7o7CaUJzbPKhFMyx3F_b_kk;
        CV_EML_FOR(0, 1, 1, 1);
        _SFD_EML_CALL(0U, chartInstance->c3_7vqb7o7CaUJzbPKhFMyx3F_sfEvent, 27);
        c3_7vqb7o7CaUJzbPKhFMyx3F_c_kk = _SFD_EML_ARRAY_BOUNDS_CHECK("IRKB",
          (int32_T)_SFD_INTEGER_CHECK("kk", c3_7vqb7o7CaUJzbPKhFMyx3F_kk), 1, 12,
          3, 0) - 1;
        c3_7vqb7o7CaUJzbPKhFMyx3F_c_kd = _SFD_EML_ARRAY_BOUNDS_CHECK("IRKB",
          (int32_T)_SFD_INTEGER_CHECK("kd", c3_7vqb7o7CaUJzbPKhFMyx3F_kd), 1, 6,
          2, 0) - 1;
        c3_7vqb7o7CaUJzbPKhFMyx3F_d_kk = _SFD_EML_ARRAY_BOUNDS_CHECK("velocity",
          (int32_T)_SFD_INTEGER_CHECK("kk", c3_7vqb7o7CaUJzbPKhFMyx3F_kk), 1, 6,
          1, 0) - 1;
        for (c3_7vqb7o7CaUJzbPKhFMyx3F_i24 = 0; c3_7vqb7o7CaUJzbPKhFMyx3F_i24 <
             601; c3_7vqb7o7CaUJzbPKhFMyx3F_i24++) {
          c3_7vqb7o7CaUJzbPKhFMyx3F_tmpY[c3_7vqb7o7CaUJzbPKhFMyx3F_i24] =
            chartInstance->c3_7vqb7o7CaUJzbPKhFMyx3F_IRKB
            [(c3_7vqb7o7CaUJzbPKhFMyx3F_i24 + 601 *
              c3_7vqb7o7CaUJzbPKhFMyx3F_c_kd) + 3606 *
            c3_7vqb7o7CaUJzbPKhFMyx3F_c_kk] *
            chartInstance->
            c3_7vqb7o7CaUJzbPKhFMyx3F_velocity[c3_7vqb7o7CaUJzbPKhFMyx3F_d_kk +
            6 * c3_7vqb7o7CaUJzbPKhFMyx3F_i24];
        }

        _SFD_EML_CALL(0U, chartInstance->c3_7vqb7o7CaUJzbPKhFMyx3F_sfEvent, 28);
        for (c3_7vqb7o7CaUJzbPKhFMyx3F_i25 = 0; c3_7vqb7o7CaUJzbPKhFMyx3F_i25 <
             601; c3_7vqb7o7CaUJzbPKhFMyx3F_i25++) {
          c3_7vqb7o7CaUJzbPKhFMyx3F_c_CTTime[c3_7vqb7o7CaUJzbPKhFMyx3F_i25] =
            c3_7vqb7o7CaUJzbPKhFMyx3F_b_CTTime[c3_7vqb7o7CaUJzbPKhFMyx3F_i25];
        }

        for (c3_7vqb7o7CaUJzbPKhFMyx3F_i26 = 0; c3_7vqb7o7CaUJzbPKhFMyx3F_i26 <
             601; c3_7vqb7o7CaUJzbPKhFMyx3F_i26++) {
          c3_7vqb7o7CaUJzbPKhFMyx3F_b_tmpY[c3_7vqb7o7CaUJzbPKhFMyx3F_i26] =
            c3_7vqb7o7CaUJzbPKhFMyx3F_tmpY[c3_7vqb7o7CaUJzbPKhFMyx3F_i26];
        }

        c3_7vqb7o7CaUJzbPKhFMyx3F_tmpF[(_SFD_EML_ARRAY_BOUNDS_CHECK("tmpF",
          (int32_T)_SFD_INTEGER_CHECK("kd", c3_7vqb7o7CaUJzbPKhFMyx3F_kd), 1, 6,
          1, 0) + 6 * (_SFD_EML_ARRAY_BOUNDS_CHECK("tmpF", (int32_T)
          _SFD_INTEGER_CHECK("kk", c3_7vqb7o7CaUJzbPKhFMyx3F_kk), 1, 6, 2, 0) -
                       1)) - 1] = c3_7vqb7o7CaUJzbPKhFMyx3F_trapz(chartInstance,
          c3_7vqb7o7CaUJzbPKhFMyx3F_c_CTTime, c3_7vqb7o7CaUJzbPKhFMyx3F_b_tmpY);
        c3_7vqb7o7CaUJzbPKhFMyx3F_b_kk++;
        _SF_MEX_LISTEN_FOR_CTRL_C(chartInstance->S);
      }

      CV_EML_FOR(0, 1, 1, 0);
      _SFD_EML_CALL(0U, chartInstance->c3_7vqb7o7CaUJzbPKhFMyx3F_sfEvent, 30);
      c3_7vqb7o7CaUJzbPKhFMyx3F_d_kd = _SFD_EML_ARRAY_BOUNDS_CHECK("tmpF",
        (int32_T)_SFD_INTEGER_CHECK("kd", c3_7vqb7o7CaUJzbPKhFMyx3F_kd), 1, 6, 1,
        0) - 1;
      for (c3_7vqb7o7CaUJzbPKhFMyx3F_i27 = 0; c3_7vqb7o7CaUJzbPKhFMyx3F_i27 < 6;
           c3_7vqb7o7CaUJzbPKhFMyx3F_i27++) {
        c3_7vqb7o7CaUJzbPKhFMyx3F_b_tmpF[c3_7vqb7o7CaUJzbPKhFMyx3F_i27] =
          c3_7vqb7o7CaUJzbPKhFMyx3F_tmpF[c3_7vqb7o7CaUJzbPKhFMyx3F_d_kd + 6 *
          c3_7vqb7o7CaUJzbPKhFMyx3F_i27];
      }

      c3_7vqb7o7CaUJzbPKhFMyx3F_tmpT[_SFD_EML_ARRAY_BOUNDS_CHECK("tmpT",
        (int32_T)_SFD_INTEGER_CHECK("kd", c3_7vqb7o7CaUJzbPKhFMyx3F_kd), 1, 6, 1,
        0) - 1] = c3_7vqb7o7CaUJzbPKhFMyx3F_sum(chartInstance,
        c3_7vqb7o7CaUJzbPKhFMyx3F_b_tmpF);
      c3_7vqb7o7CaUJzbPKhFMyx3F_b_kd++;
      _SF_MEX_LISTEN_FOR_CTRL_C(chartInstance->S);
    }

    CV_EML_FOR(0, 1, 0, 0);
  }

  _SFD_EML_CALL(0U, chartInstance->c3_7vqb7o7CaUJzbPKhFMyx3F_sfEvent, 33);
  for (c3_7vqb7o7CaUJzbPKhFMyx3F_i28 = 0; c3_7vqb7o7CaUJzbPKhFMyx3F_i28 < 6;
       c3_7vqb7o7CaUJzbPKhFMyx3F_i28++) {
    c3_7vqb7o7CaUJzbPKhFMyx3F_b_F_FM[c3_7vqb7o7CaUJzbPKhFMyx3F_i28] =
      c3_7vqb7o7CaUJzbPKhFMyx3F_tmpT[c3_7vqb7o7CaUJzbPKhFMyx3F_i28];
  }

  _SFD_EML_CALL(0U, chartInstance->c3_7vqb7o7CaUJzbPKhFMyx3F_sfEvent, -33);
  _SFD_SYMBOL_SCOPE_POP();
  for (c3_7vqb7o7CaUJzbPKhFMyx3F_i29 = 0; c3_7vqb7o7CaUJzbPKhFMyx3F_i29 < 6;
       c3_7vqb7o7CaUJzbPKhFMyx3F_i29++) {
    (*chartInstance->c3_7vqb7o7CaUJzbPKhFMyx3F_F_FM)
      [c3_7vqb7o7CaUJzbPKhFMyx3F_i29] =
      c3_7vqb7o7CaUJzbPKhFMyx3F_b_F_FM[c3_7vqb7o7CaUJzbPKhFMyx3F_i29];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U,
               chartInstance->c3_7vqb7o7CaUJzbPKhFMyx3F_sfEvent);
}

static void initSimStructsc3_7vqb7o7CaUJzbPKhFMyx3F_WECSim_Lib
  (SFc3_7vqb7o7CaUJzbPKhFMyx3F_WECSim_LibInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void init_script_number_translation(uint32_T
  c3_7vqb7o7CaUJzbPKhFMyx3F_machineNumber, uint32_T
  c3_7vqb7o7CaUJzbPKhFMyx3F_chartNumber, uint32_T
  c3_7vqb7o7CaUJzbPKhFMyx3F_instanceNumber)
{
  (void)c3_7vqb7o7CaUJzbPKhFMyx3F_machineNumber;
  (void)c3_7vqb7o7CaUJzbPKhFMyx3F_chartNumber;
  (void)c3_7vqb7o7CaUJzbPKhFMyx3F_instanceNumber;
}

static const mxArray *c3_7vqb7o7CaUJzbPKhFMyx3F_sf_marshallOut(void
  *chartInstanceVoid, void *c3_7vqb7o7CaUJzbPKhFMyx3F_b_inData)
{
  const mxArray *c3_7vqb7o7CaUJzbPKhFMyx3F_mxArrayOutData = NULL;
  real_T c3_7vqb7o7CaUJzbPKhFMyx3F_b_u;
  const mxArray *c3_7vqb7o7CaUJzbPKhFMyx3F_y = NULL;
  SFc3_7vqb7o7CaUJzbPKhFMyx3F_WECSim_LibInstanceStruct *chartInstance;
  chartInstance = (SFc3_7vqb7o7CaUJzbPKhFMyx3F_WECSim_LibInstanceStruct *)
    chartInstanceVoid;
  c3_7vqb7o7CaUJzbPKhFMyx3F_mxArrayOutData = NULL;
  c3_7vqb7o7CaUJzbPKhFMyx3F_b_u = *(real_T *)c3_7vqb7o7CaUJzbPKhFMyx3F_b_inData;
  c3_7vqb7o7CaUJzbPKhFMyx3F_y = NULL;
  if (!chartInstance->c3_7vqb7o7CaUJzbPKhFMyx3F_kkk_not_empty) {
    sf_mex_assign(&c3_7vqb7o7CaUJzbPKhFMyx3F_y, sf_mex_create("y", NULL, 0, 0U,
      1U, 0U, 2, 0, 0), false);
  } else {
    sf_mex_assign(&c3_7vqb7o7CaUJzbPKhFMyx3F_y, sf_mex_create("y",
      &c3_7vqb7o7CaUJzbPKhFMyx3F_b_u, 0, 0U, 0U, 0U, 0), false);
  }

  sf_mex_assign(&c3_7vqb7o7CaUJzbPKhFMyx3F_mxArrayOutData,
                c3_7vqb7o7CaUJzbPKhFMyx3F_y, false);
  return c3_7vqb7o7CaUJzbPKhFMyx3F_mxArrayOutData;
}

static real_T c3_7vqb7o7CaUJzbPKhFMyx3F_emlrt_marshallIn
  (SFc3_7vqb7o7CaUJzbPKhFMyx3F_WECSim_LibInstanceStruct *chartInstance, const
   mxArray *c3_7vqb7o7CaUJzbPKhFMyx3F_b_kkk, const char_T
   *c3_7vqb7o7CaUJzbPKhFMyx3F_identifier)
{
  real_T c3_7vqb7o7CaUJzbPKhFMyx3F_y;
  emlrtMsgIdentifier c3_7vqb7o7CaUJzbPKhFMyx3F_thisId;
  c3_7vqb7o7CaUJzbPKhFMyx3F_thisId.fIdentifier =
    c3_7vqb7o7CaUJzbPKhFMyx3F_identifier;
  c3_7vqb7o7CaUJzbPKhFMyx3F_thisId.fParent = NULL;
  c3_7vqb7o7CaUJzbPKhFMyx3F_y = c3_7vqb7o7CaUJzbPKhFMyx3F_b_emlrt_marshallIn
    (chartInstance, sf_mex_dup(c3_7vqb7o7CaUJzbPKhFMyx3F_b_kkk),
     &c3_7vqb7o7CaUJzbPKhFMyx3F_thisId);
  sf_mex_destroy(&c3_7vqb7o7CaUJzbPKhFMyx3F_b_kkk);
  return c3_7vqb7o7CaUJzbPKhFMyx3F_y;
}

static real_T c3_7vqb7o7CaUJzbPKhFMyx3F_b_emlrt_marshallIn
  (SFc3_7vqb7o7CaUJzbPKhFMyx3F_WECSim_LibInstanceStruct *chartInstance, const
   mxArray *c3_7vqb7o7CaUJzbPKhFMyx3F_b_u, const emlrtMsgIdentifier
   *c3_7vqb7o7CaUJzbPKhFMyx3F_parentId)
{
  real_T c3_7vqb7o7CaUJzbPKhFMyx3F_y;
  real_T c3_7vqb7o7CaUJzbPKhFMyx3F_d1;
  if (mxIsEmpty(c3_7vqb7o7CaUJzbPKhFMyx3F_b_u)) {
    chartInstance->c3_7vqb7o7CaUJzbPKhFMyx3F_kkk_not_empty = false;
  } else {
    chartInstance->c3_7vqb7o7CaUJzbPKhFMyx3F_kkk_not_empty = true;
    sf_mex_import(c3_7vqb7o7CaUJzbPKhFMyx3F_parentId, sf_mex_dup
                  (c3_7vqb7o7CaUJzbPKhFMyx3F_b_u), &c3_7vqb7o7CaUJzbPKhFMyx3F_d1,
                  1, 0, 0U, 0, 0U, 0);
    c3_7vqb7o7CaUJzbPKhFMyx3F_y = c3_7vqb7o7CaUJzbPKhFMyx3F_d1;
  }

  sf_mex_destroy(&c3_7vqb7o7CaUJzbPKhFMyx3F_b_u);
  return c3_7vqb7o7CaUJzbPKhFMyx3F_y;
}

static void c3_7vqb7o7CaUJzbPKhFMyx3F_sf_marshallIn(void *chartInstanceVoid,
  const mxArray *c3_7vqb7o7CaUJzbPKhFMyx3F_mxArrayInData, const char_T
  *c3_7vqb7o7CaUJzbPKhFMyx3F_varName, void *c3_7vqb7o7CaUJzbPKhFMyx3F_outData)
{
  const mxArray *c3_7vqb7o7CaUJzbPKhFMyx3F_b_kkk;
  const char_T *c3_7vqb7o7CaUJzbPKhFMyx3F_identifier;
  emlrtMsgIdentifier c3_7vqb7o7CaUJzbPKhFMyx3F_thisId;
  real_T c3_7vqb7o7CaUJzbPKhFMyx3F_y;
  SFc3_7vqb7o7CaUJzbPKhFMyx3F_WECSim_LibInstanceStruct *chartInstance;
  chartInstance = (SFc3_7vqb7o7CaUJzbPKhFMyx3F_WECSim_LibInstanceStruct *)
    chartInstanceVoid;
  c3_7vqb7o7CaUJzbPKhFMyx3F_b_kkk = sf_mex_dup
    (c3_7vqb7o7CaUJzbPKhFMyx3F_mxArrayInData);
  c3_7vqb7o7CaUJzbPKhFMyx3F_identifier = c3_7vqb7o7CaUJzbPKhFMyx3F_varName;
  c3_7vqb7o7CaUJzbPKhFMyx3F_thisId.fIdentifier =
    c3_7vqb7o7CaUJzbPKhFMyx3F_identifier;
  c3_7vqb7o7CaUJzbPKhFMyx3F_thisId.fParent = NULL;
  c3_7vqb7o7CaUJzbPKhFMyx3F_y = c3_7vqb7o7CaUJzbPKhFMyx3F_b_emlrt_marshallIn
    (chartInstance, sf_mex_dup(c3_7vqb7o7CaUJzbPKhFMyx3F_b_kkk),
     &c3_7vqb7o7CaUJzbPKhFMyx3F_thisId);
  sf_mex_destroy(&c3_7vqb7o7CaUJzbPKhFMyx3F_b_kkk);
  *(real_T *)c3_7vqb7o7CaUJzbPKhFMyx3F_outData = c3_7vqb7o7CaUJzbPKhFMyx3F_y;
  sf_mex_destroy(&c3_7vqb7o7CaUJzbPKhFMyx3F_mxArrayInData);
}

static const mxArray *c3_7vqb7o7CaUJzbPKhFMyx3F_b_sf_marshallOut(void
  *chartInstanceVoid, void *c3_7vqb7o7CaUJzbPKhFMyx3F_b_inData)
{
  const mxArray *c3_7vqb7o7CaUJzbPKhFMyx3F_mxArrayOutData = NULL;
  int32_T c3_7vqb7o7CaUJzbPKhFMyx3F_i30;
  int32_T c3_7vqb7o7CaUJzbPKhFMyx3F_i31;
  int32_T c3_7vqb7o7CaUJzbPKhFMyx3F_i32;
  real_T c3_7vqb7o7CaUJzbPKhFMyx3F_c_inData[3606];
  int32_T c3_7vqb7o7CaUJzbPKhFMyx3F_i33;
  int32_T c3_7vqb7o7CaUJzbPKhFMyx3F_i34;
  int32_T c3_7vqb7o7CaUJzbPKhFMyx3F_i35;
  real_T c3_7vqb7o7CaUJzbPKhFMyx3F_b_u[3606];
  const mxArray *c3_7vqb7o7CaUJzbPKhFMyx3F_y = NULL;
  SFc3_7vqb7o7CaUJzbPKhFMyx3F_WECSim_LibInstanceStruct *chartInstance;
  chartInstance = (SFc3_7vqb7o7CaUJzbPKhFMyx3F_WECSim_LibInstanceStruct *)
    chartInstanceVoid;
  c3_7vqb7o7CaUJzbPKhFMyx3F_mxArrayOutData = NULL;
  c3_7vqb7o7CaUJzbPKhFMyx3F_i30 = 0;
  for (c3_7vqb7o7CaUJzbPKhFMyx3F_i31 = 0; c3_7vqb7o7CaUJzbPKhFMyx3F_i31 < 601;
       c3_7vqb7o7CaUJzbPKhFMyx3F_i31++) {
    for (c3_7vqb7o7CaUJzbPKhFMyx3F_i32 = 0; c3_7vqb7o7CaUJzbPKhFMyx3F_i32 < 6;
         c3_7vqb7o7CaUJzbPKhFMyx3F_i32++) {
      c3_7vqb7o7CaUJzbPKhFMyx3F_c_inData[c3_7vqb7o7CaUJzbPKhFMyx3F_i32 +
        c3_7vqb7o7CaUJzbPKhFMyx3F_i30] = (*(real_T (*)[3606])
        c3_7vqb7o7CaUJzbPKhFMyx3F_b_inData)[c3_7vqb7o7CaUJzbPKhFMyx3F_i32 +
        c3_7vqb7o7CaUJzbPKhFMyx3F_i30];
    }

    c3_7vqb7o7CaUJzbPKhFMyx3F_i30 += 6;
  }

  c3_7vqb7o7CaUJzbPKhFMyx3F_i33 = 0;
  for (c3_7vqb7o7CaUJzbPKhFMyx3F_i34 = 0; c3_7vqb7o7CaUJzbPKhFMyx3F_i34 < 601;
       c3_7vqb7o7CaUJzbPKhFMyx3F_i34++) {
    for (c3_7vqb7o7CaUJzbPKhFMyx3F_i35 = 0; c3_7vqb7o7CaUJzbPKhFMyx3F_i35 < 6;
         c3_7vqb7o7CaUJzbPKhFMyx3F_i35++) {
      c3_7vqb7o7CaUJzbPKhFMyx3F_b_u[c3_7vqb7o7CaUJzbPKhFMyx3F_i35 +
        c3_7vqb7o7CaUJzbPKhFMyx3F_i33] =
        c3_7vqb7o7CaUJzbPKhFMyx3F_c_inData[c3_7vqb7o7CaUJzbPKhFMyx3F_i35 +
        c3_7vqb7o7CaUJzbPKhFMyx3F_i33];
    }

    c3_7vqb7o7CaUJzbPKhFMyx3F_i33 += 6;
  }

  c3_7vqb7o7CaUJzbPKhFMyx3F_y = NULL;
  if (!chartInstance->c3_7vqb7o7CaUJzbPKhFMyx3F_velocity_not_empty) {
    sf_mex_assign(&c3_7vqb7o7CaUJzbPKhFMyx3F_y, sf_mex_create("y", NULL, 0, 0U,
      1U, 0U, 2, 0, 0), false);
  } else {
    sf_mex_assign(&c3_7vqb7o7CaUJzbPKhFMyx3F_y, sf_mex_create("y",
      c3_7vqb7o7CaUJzbPKhFMyx3F_b_u, 0, 0U, 1U, 0U, 2, 6, 601), false);
  }

  sf_mex_assign(&c3_7vqb7o7CaUJzbPKhFMyx3F_mxArrayOutData,
                c3_7vqb7o7CaUJzbPKhFMyx3F_y, false);
  return c3_7vqb7o7CaUJzbPKhFMyx3F_mxArrayOutData;
}

static void c3_7vqb7o7CaUJzbPKhFMyx3F_c_emlrt_marshallIn
  (SFc3_7vqb7o7CaUJzbPKhFMyx3F_WECSim_LibInstanceStruct *chartInstance, const
   mxArray *c3_7vqb7o7CaUJzbPKhFMyx3F_b_velocity, const char_T
   *c3_7vqb7o7CaUJzbPKhFMyx3F_identifier, real_T c3_7vqb7o7CaUJzbPKhFMyx3F_y
   [3606])
{
  emlrtMsgIdentifier c3_7vqb7o7CaUJzbPKhFMyx3F_thisId;
  c3_7vqb7o7CaUJzbPKhFMyx3F_thisId.fIdentifier =
    c3_7vqb7o7CaUJzbPKhFMyx3F_identifier;
  c3_7vqb7o7CaUJzbPKhFMyx3F_thisId.fParent = NULL;
  c3_7vqb7o7CaUJzbPKhFMyx3F_d_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c3_7vqb7o7CaUJzbPKhFMyx3F_b_velocity), &c3_7vqb7o7CaUJzbPKhFMyx3F_thisId,
    c3_7vqb7o7CaUJzbPKhFMyx3F_y);
  sf_mex_destroy(&c3_7vqb7o7CaUJzbPKhFMyx3F_b_velocity);
}

static void c3_7vqb7o7CaUJzbPKhFMyx3F_d_emlrt_marshallIn
  (SFc3_7vqb7o7CaUJzbPKhFMyx3F_WECSim_LibInstanceStruct *chartInstance, const
   mxArray *c3_7vqb7o7CaUJzbPKhFMyx3F_b_u, const emlrtMsgIdentifier
   *c3_7vqb7o7CaUJzbPKhFMyx3F_parentId, real_T c3_7vqb7o7CaUJzbPKhFMyx3F_y[3606])
{
  real_T c3_7vqb7o7CaUJzbPKhFMyx3F_dv3[3606];
  int32_T c3_7vqb7o7CaUJzbPKhFMyx3F_i36;
  if (mxIsEmpty(c3_7vqb7o7CaUJzbPKhFMyx3F_b_u)) {
    chartInstance->c3_7vqb7o7CaUJzbPKhFMyx3F_velocity_not_empty = false;
  } else {
    chartInstance->c3_7vqb7o7CaUJzbPKhFMyx3F_velocity_not_empty = true;
    sf_mex_import(c3_7vqb7o7CaUJzbPKhFMyx3F_parentId, sf_mex_dup
                  (c3_7vqb7o7CaUJzbPKhFMyx3F_b_u), c3_7vqb7o7CaUJzbPKhFMyx3F_dv3,
                  1, 0, 0U, 1, 0U, 2, 6, 601);
    for (c3_7vqb7o7CaUJzbPKhFMyx3F_i36 = 0; c3_7vqb7o7CaUJzbPKhFMyx3F_i36 < 3606;
         c3_7vqb7o7CaUJzbPKhFMyx3F_i36++) {
      c3_7vqb7o7CaUJzbPKhFMyx3F_y[c3_7vqb7o7CaUJzbPKhFMyx3F_i36] =
        c3_7vqb7o7CaUJzbPKhFMyx3F_dv3[c3_7vqb7o7CaUJzbPKhFMyx3F_i36];
    }
  }

  sf_mex_destroy(&c3_7vqb7o7CaUJzbPKhFMyx3F_b_u);
}

static void c3_7vqb7o7CaUJzbPKhFMyx3F_b_sf_marshallIn(void *chartInstanceVoid,
  const mxArray *c3_7vqb7o7CaUJzbPKhFMyx3F_mxArrayInData, const char_T
  *c3_7vqb7o7CaUJzbPKhFMyx3F_varName, void *c3_7vqb7o7CaUJzbPKhFMyx3F_outData)
{
  const mxArray *c3_7vqb7o7CaUJzbPKhFMyx3F_b_velocity;
  const char_T *c3_7vqb7o7CaUJzbPKhFMyx3F_identifier;
  emlrtMsgIdentifier c3_7vqb7o7CaUJzbPKhFMyx3F_thisId;
  real_T c3_7vqb7o7CaUJzbPKhFMyx3F_y[3606];
  int32_T c3_7vqb7o7CaUJzbPKhFMyx3F_i37;
  int32_T c3_7vqb7o7CaUJzbPKhFMyx3F_i38;
  int32_T c3_7vqb7o7CaUJzbPKhFMyx3F_i39;
  SFc3_7vqb7o7CaUJzbPKhFMyx3F_WECSim_LibInstanceStruct *chartInstance;
  chartInstance = (SFc3_7vqb7o7CaUJzbPKhFMyx3F_WECSim_LibInstanceStruct *)
    chartInstanceVoid;
  c3_7vqb7o7CaUJzbPKhFMyx3F_b_velocity = sf_mex_dup
    (c3_7vqb7o7CaUJzbPKhFMyx3F_mxArrayInData);
  c3_7vqb7o7CaUJzbPKhFMyx3F_identifier = c3_7vqb7o7CaUJzbPKhFMyx3F_varName;
  c3_7vqb7o7CaUJzbPKhFMyx3F_thisId.fIdentifier =
    c3_7vqb7o7CaUJzbPKhFMyx3F_identifier;
  c3_7vqb7o7CaUJzbPKhFMyx3F_thisId.fParent = NULL;
  c3_7vqb7o7CaUJzbPKhFMyx3F_d_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c3_7vqb7o7CaUJzbPKhFMyx3F_b_velocity), &c3_7vqb7o7CaUJzbPKhFMyx3F_thisId,
    c3_7vqb7o7CaUJzbPKhFMyx3F_y);
  sf_mex_destroy(&c3_7vqb7o7CaUJzbPKhFMyx3F_b_velocity);
  c3_7vqb7o7CaUJzbPKhFMyx3F_i37 = 0;
  for (c3_7vqb7o7CaUJzbPKhFMyx3F_i38 = 0; c3_7vqb7o7CaUJzbPKhFMyx3F_i38 < 601;
       c3_7vqb7o7CaUJzbPKhFMyx3F_i38++) {
    for (c3_7vqb7o7CaUJzbPKhFMyx3F_i39 = 0; c3_7vqb7o7CaUJzbPKhFMyx3F_i39 < 6;
         c3_7vqb7o7CaUJzbPKhFMyx3F_i39++) {
      (*(real_T (*)[3606])c3_7vqb7o7CaUJzbPKhFMyx3F_outData)
        [c3_7vqb7o7CaUJzbPKhFMyx3F_i39 + c3_7vqb7o7CaUJzbPKhFMyx3F_i37] =
        c3_7vqb7o7CaUJzbPKhFMyx3F_y[c3_7vqb7o7CaUJzbPKhFMyx3F_i39 +
        c3_7vqb7o7CaUJzbPKhFMyx3F_i37];
    }

    c3_7vqb7o7CaUJzbPKhFMyx3F_i37 += 6;
  }

  sf_mex_destroy(&c3_7vqb7o7CaUJzbPKhFMyx3F_mxArrayInData);
}

static const mxArray *c3_7vqb7o7CaUJzbPKhFMyx3F_c_sf_marshallOut(void
  *chartInstanceVoid, void *c3_7vqb7o7CaUJzbPKhFMyx3F_b_inData)
{
  const mxArray *c3_7vqb7o7CaUJzbPKhFMyx3F_mxArrayOutData = NULL;
  int32_T c3_7vqb7o7CaUJzbPKhFMyx3F_i40;
  real_T c3_7vqb7o7CaUJzbPKhFMyx3F_c_inData[6];
  int32_T c3_7vqb7o7CaUJzbPKhFMyx3F_i41;
  real_T c3_7vqb7o7CaUJzbPKhFMyx3F_b_u[6];
  const mxArray *c3_7vqb7o7CaUJzbPKhFMyx3F_y = NULL;
  SFc3_7vqb7o7CaUJzbPKhFMyx3F_WECSim_LibInstanceStruct *chartInstance;
  chartInstance = (SFc3_7vqb7o7CaUJzbPKhFMyx3F_WECSim_LibInstanceStruct *)
    chartInstanceVoid;
  c3_7vqb7o7CaUJzbPKhFMyx3F_mxArrayOutData = NULL;
  for (c3_7vqb7o7CaUJzbPKhFMyx3F_i40 = 0; c3_7vqb7o7CaUJzbPKhFMyx3F_i40 < 6;
       c3_7vqb7o7CaUJzbPKhFMyx3F_i40++) {
    c3_7vqb7o7CaUJzbPKhFMyx3F_c_inData[c3_7vqb7o7CaUJzbPKhFMyx3F_i40] =
      (*(real_T (*)[6])c3_7vqb7o7CaUJzbPKhFMyx3F_b_inData)
      [c3_7vqb7o7CaUJzbPKhFMyx3F_i40];
  }

  for (c3_7vqb7o7CaUJzbPKhFMyx3F_i41 = 0; c3_7vqb7o7CaUJzbPKhFMyx3F_i41 < 6;
       c3_7vqb7o7CaUJzbPKhFMyx3F_i41++) {
    c3_7vqb7o7CaUJzbPKhFMyx3F_b_u[c3_7vqb7o7CaUJzbPKhFMyx3F_i41] =
      c3_7vqb7o7CaUJzbPKhFMyx3F_c_inData[c3_7vqb7o7CaUJzbPKhFMyx3F_i41];
  }

  c3_7vqb7o7CaUJzbPKhFMyx3F_y = NULL;
  sf_mex_assign(&c3_7vqb7o7CaUJzbPKhFMyx3F_y, sf_mex_create("y",
    c3_7vqb7o7CaUJzbPKhFMyx3F_b_u, 0, 0U, 1U, 0U, 1, 6), false);
  sf_mex_assign(&c3_7vqb7o7CaUJzbPKhFMyx3F_mxArrayOutData,
                c3_7vqb7o7CaUJzbPKhFMyx3F_y, false);
  return c3_7vqb7o7CaUJzbPKhFMyx3F_mxArrayOutData;
}

static void c3_7vqb7o7CaUJzbPKhFMyx3F_e_emlrt_marshallIn
  (SFc3_7vqb7o7CaUJzbPKhFMyx3F_WECSim_LibInstanceStruct *chartInstance, const
   mxArray *c3_7vqb7o7CaUJzbPKhFMyx3F_b_F_FM, const char_T
   *c3_7vqb7o7CaUJzbPKhFMyx3F_identifier, real_T c3_7vqb7o7CaUJzbPKhFMyx3F_y[6])
{
  emlrtMsgIdentifier c3_7vqb7o7CaUJzbPKhFMyx3F_thisId;
  c3_7vqb7o7CaUJzbPKhFMyx3F_thisId.fIdentifier =
    c3_7vqb7o7CaUJzbPKhFMyx3F_identifier;
  c3_7vqb7o7CaUJzbPKhFMyx3F_thisId.fParent = NULL;
  c3_7vqb7o7CaUJzbPKhFMyx3F_f_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c3_7vqb7o7CaUJzbPKhFMyx3F_b_F_FM), &c3_7vqb7o7CaUJzbPKhFMyx3F_thisId,
    c3_7vqb7o7CaUJzbPKhFMyx3F_y);
  sf_mex_destroy(&c3_7vqb7o7CaUJzbPKhFMyx3F_b_F_FM);
}

static void c3_7vqb7o7CaUJzbPKhFMyx3F_f_emlrt_marshallIn
  (SFc3_7vqb7o7CaUJzbPKhFMyx3F_WECSim_LibInstanceStruct *chartInstance, const
   mxArray *c3_7vqb7o7CaUJzbPKhFMyx3F_b_u, const emlrtMsgIdentifier
   *c3_7vqb7o7CaUJzbPKhFMyx3F_parentId, real_T c3_7vqb7o7CaUJzbPKhFMyx3F_y[6])
{
  real_T c3_7vqb7o7CaUJzbPKhFMyx3F_dv4[6];
  int32_T c3_7vqb7o7CaUJzbPKhFMyx3F_i42;
  (void)chartInstance;
  sf_mex_import(c3_7vqb7o7CaUJzbPKhFMyx3F_parentId, sf_mex_dup
                (c3_7vqb7o7CaUJzbPKhFMyx3F_b_u), c3_7vqb7o7CaUJzbPKhFMyx3F_dv4,
                1, 0, 0U, 1, 0U, 1, 6);
  for (c3_7vqb7o7CaUJzbPKhFMyx3F_i42 = 0; c3_7vqb7o7CaUJzbPKhFMyx3F_i42 < 6;
       c3_7vqb7o7CaUJzbPKhFMyx3F_i42++) {
    c3_7vqb7o7CaUJzbPKhFMyx3F_y[c3_7vqb7o7CaUJzbPKhFMyx3F_i42] =
      c3_7vqb7o7CaUJzbPKhFMyx3F_dv4[c3_7vqb7o7CaUJzbPKhFMyx3F_i42];
  }

  sf_mex_destroy(&c3_7vqb7o7CaUJzbPKhFMyx3F_b_u);
}

static void c3_7vqb7o7CaUJzbPKhFMyx3F_c_sf_marshallIn(void *chartInstanceVoid,
  const mxArray *c3_7vqb7o7CaUJzbPKhFMyx3F_mxArrayInData, const char_T
  *c3_7vqb7o7CaUJzbPKhFMyx3F_varName, void *c3_7vqb7o7CaUJzbPKhFMyx3F_outData)
{
  const mxArray *c3_7vqb7o7CaUJzbPKhFMyx3F_b_F_FM;
  const char_T *c3_7vqb7o7CaUJzbPKhFMyx3F_identifier;
  emlrtMsgIdentifier c3_7vqb7o7CaUJzbPKhFMyx3F_thisId;
  real_T c3_7vqb7o7CaUJzbPKhFMyx3F_y[6];
  int32_T c3_7vqb7o7CaUJzbPKhFMyx3F_i43;
  SFc3_7vqb7o7CaUJzbPKhFMyx3F_WECSim_LibInstanceStruct *chartInstance;
  chartInstance = (SFc3_7vqb7o7CaUJzbPKhFMyx3F_WECSim_LibInstanceStruct *)
    chartInstanceVoid;
  c3_7vqb7o7CaUJzbPKhFMyx3F_b_F_FM = sf_mex_dup
    (c3_7vqb7o7CaUJzbPKhFMyx3F_mxArrayInData);
  c3_7vqb7o7CaUJzbPKhFMyx3F_identifier = c3_7vqb7o7CaUJzbPKhFMyx3F_varName;
  c3_7vqb7o7CaUJzbPKhFMyx3F_thisId.fIdentifier =
    c3_7vqb7o7CaUJzbPKhFMyx3F_identifier;
  c3_7vqb7o7CaUJzbPKhFMyx3F_thisId.fParent = NULL;
  c3_7vqb7o7CaUJzbPKhFMyx3F_f_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c3_7vqb7o7CaUJzbPKhFMyx3F_b_F_FM), &c3_7vqb7o7CaUJzbPKhFMyx3F_thisId,
    c3_7vqb7o7CaUJzbPKhFMyx3F_y);
  sf_mex_destroy(&c3_7vqb7o7CaUJzbPKhFMyx3F_b_F_FM);
  for (c3_7vqb7o7CaUJzbPKhFMyx3F_i43 = 0; c3_7vqb7o7CaUJzbPKhFMyx3F_i43 < 6;
       c3_7vqb7o7CaUJzbPKhFMyx3F_i43++) {
    (*(real_T (*)[6])c3_7vqb7o7CaUJzbPKhFMyx3F_outData)
      [c3_7vqb7o7CaUJzbPKhFMyx3F_i43] =
      c3_7vqb7o7CaUJzbPKhFMyx3F_y[c3_7vqb7o7CaUJzbPKhFMyx3F_i43];
  }

  sf_mex_destroy(&c3_7vqb7o7CaUJzbPKhFMyx3F_mxArrayInData);
}

static const mxArray *c3_7vqb7o7CaUJzbPKhFMyx3F_d_sf_marshallOut(void
  *chartInstanceVoid, void *c3_7vqb7o7CaUJzbPKhFMyx3F_b_inData)
{
  const mxArray *c3_7vqb7o7CaUJzbPKhFMyx3F_mxArrayOutData = NULL;
  int32_T c3_7vqb7o7CaUJzbPKhFMyx3F_i44;
  real_T c3_7vqb7o7CaUJzbPKhFMyx3F_c_inData[601];
  int32_T c3_7vqb7o7CaUJzbPKhFMyx3F_i45;
  real_T c3_7vqb7o7CaUJzbPKhFMyx3F_b_u[601];
  const mxArray *c3_7vqb7o7CaUJzbPKhFMyx3F_y = NULL;
  SFc3_7vqb7o7CaUJzbPKhFMyx3F_WECSim_LibInstanceStruct *chartInstance;
  chartInstance = (SFc3_7vqb7o7CaUJzbPKhFMyx3F_WECSim_LibInstanceStruct *)
    chartInstanceVoid;
  c3_7vqb7o7CaUJzbPKhFMyx3F_mxArrayOutData = NULL;
  for (c3_7vqb7o7CaUJzbPKhFMyx3F_i44 = 0; c3_7vqb7o7CaUJzbPKhFMyx3F_i44 < 601;
       c3_7vqb7o7CaUJzbPKhFMyx3F_i44++) {
    c3_7vqb7o7CaUJzbPKhFMyx3F_c_inData[c3_7vqb7o7CaUJzbPKhFMyx3F_i44] =
      (*(real_T (*)[601])c3_7vqb7o7CaUJzbPKhFMyx3F_b_inData)
      [c3_7vqb7o7CaUJzbPKhFMyx3F_i44];
  }

  for (c3_7vqb7o7CaUJzbPKhFMyx3F_i45 = 0; c3_7vqb7o7CaUJzbPKhFMyx3F_i45 < 601;
       c3_7vqb7o7CaUJzbPKhFMyx3F_i45++) {
    c3_7vqb7o7CaUJzbPKhFMyx3F_b_u[c3_7vqb7o7CaUJzbPKhFMyx3F_i45] =
      c3_7vqb7o7CaUJzbPKhFMyx3F_c_inData[c3_7vqb7o7CaUJzbPKhFMyx3F_i45];
  }

  c3_7vqb7o7CaUJzbPKhFMyx3F_y = NULL;
  sf_mex_assign(&c3_7vqb7o7CaUJzbPKhFMyx3F_y, sf_mex_create("y",
    c3_7vqb7o7CaUJzbPKhFMyx3F_b_u, 0, 0U, 1U, 0U, 1, 601), false);
  sf_mex_assign(&c3_7vqb7o7CaUJzbPKhFMyx3F_mxArrayOutData,
                c3_7vqb7o7CaUJzbPKhFMyx3F_y, false);
  return c3_7vqb7o7CaUJzbPKhFMyx3F_mxArrayOutData;
}

static const mxArray *c3_7vqb7o7CaUJzbPKhFMyx3F_e_sf_marshallOut(void
  *chartInstanceVoid, void *c3_7vqb7o7CaUJzbPKhFMyx3F_b_inData)
{
  const mxArray *c3_7vqb7o7CaUJzbPKhFMyx3F_mxArrayOutData = NULL;
  int32_T c3_7vqb7o7CaUJzbPKhFMyx3F_i46;
  int32_T c3_7vqb7o7CaUJzbPKhFMyx3F_i47;
  int32_T c3_7vqb7o7CaUJzbPKhFMyx3F_i48;
  int32_T c3_7vqb7o7CaUJzbPKhFMyx3F_i49;
  int32_T c3_7vqb7o7CaUJzbPKhFMyx3F_i50;
  int32_T c3_7vqb7o7CaUJzbPKhFMyx3F_i51;
  int32_T c3_7vqb7o7CaUJzbPKhFMyx3F_i52;
  int32_T c3_7vqb7o7CaUJzbPKhFMyx3F_i53;
  int32_T c3_7vqb7o7CaUJzbPKhFMyx3F_i54;
  int32_T c3_7vqb7o7CaUJzbPKhFMyx3F_i55;
  const mxArray *c3_7vqb7o7CaUJzbPKhFMyx3F_y = NULL;
  SFc3_7vqb7o7CaUJzbPKhFMyx3F_WECSim_LibInstanceStruct *chartInstance;
  chartInstance = (SFc3_7vqb7o7CaUJzbPKhFMyx3F_WECSim_LibInstanceStruct *)
    chartInstanceVoid;
  c3_7vqb7o7CaUJzbPKhFMyx3F_mxArrayOutData = NULL;
  c3_7vqb7o7CaUJzbPKhFMyx3F_i46 = 0;
  for (c3_7vqb7o7CaUJzbPKhFMyx3F_i47 = 0; c3_7vqb7o7CaUJzbPKhFMyx3F_i47 < 12;
       c3_7vqb7o7CaUJzbPKhFMyx3F_i47++) {
    c3_7vqb7o7CaUJzbPKhFMyx3F_i48 = 0;
    for (c3_7vqb7o7CaUJzbPKhFMyx3F_i49 = 0; c3_7vqb7o7CaUJzbPKhFMyx3F_i49 < 6;
         c3_7vqb7o7CaUJzbPKhFMyx3F_i49++) {
      for (c3_7vqb7o7CaUJzbPKhFMyx3F_i50 = 0; c3_7vqb7o7CaUJzbPKhFMyx3F_i50 <
           601; c3_7vqb7o7CaUJzbPKhFMyx3F_i50++) {
        chartInstance->c3_7vqb7o7CaUJzbPKhFMyx3F_inData
          [(c3_7vqb7o7CaUJzbPKhFMyx3F_i50 + c3_7vqb7o7CaUJzbPKhFMyx3F_i48) +
          c3_7vqb7o7CaUJzbPKhFMyx3F_i46] = (*(real_T (*)[43272])
          c3_7vqb7o7CaUJzbPKhFMyx3F_b_inData)[(c3_7vqb7o7CaUJzbPKhFMyx3F_i50 +
          c3_7vqb7o7CaUJzbPKhFMyx3F_i48) + c3_7vqb7o7CaUJzbPKhFMyx3F_i46];
      }

      c3_7vqb7o7CaUJzbPKhFMyx3F_i48 += 601;
    }

    c3_7vqb7o7CaUJzbPKhFMyx3F_i46 += 3606;
  }

  c3_7vqb7o7CaUJzbPKhFMyx3F_i51 = 0;
  for (c3_7vqb7o7CaUJzbPKhFMyx3F_i52 = 0; c3_7vqb7o7CaUJzbPKhFMyx3F_i52 < 12;
       c3_7vqb7o7CaUJzbPKhFMyx3F_i52++) {
    c3_7vqb7o7CaUJzbPKhFMyx3F_i53 = 0;
    for (c3_7vqb7o7CaUJzbPKhFMyx3F_i54 = 0; c3_7vqb7o7CaUJzbPKhFMyx3F_i54 < 6;
         c3_7vqb7o7CaUJzbPKhFMyx3F_i54++) {
      for (c3_7vqb7o7CaUJzbPKhFMyx3F_i55 = 0; c3_7vqb7o7CaUJzbPKhFMyx3F_i55 <
           601; c3_7vqb7o7CaUJzbPKhFMyx3F_i55++) {
        chartInstance->c3_7vqb7o7CaUJzbPKhFMyx3F_u
          [(c3_7vqb7o7CaUJzbPKhFMyx3F_i55 + c3_7vqb7o7CaUJzbPKhFMyx3F_i53) +
          c3_7vqb7o7CaUJzbPKhFMyx3F_i51] =
          chartInstance->c3_7vqb7o7CaUJzbPKhFMyx3F_inData
          [(c3_7vqb7o7CaUJzbPKhFMyx3F_i55 + c3_7vqb7o7CaUJzbPKhFMyx3F_i53) +
          c3_7vqb7o7CaUJzbPKhFMyx3F_i51];
      }

      c3_7vqb7o7CaUJzbPKhFMyx3F_i53 += 601;
    }

    c3_7vqb7o7CaUJzbPKhFMyx3F_i51 += 3606;
  }

  c3_7vqb7o7CaUJzbPKhFMyx3F_y = NULL;
  sf_mex_assign(&c3_7vqb7o7CaUJzbPKhFMyx3F_y, sf_mex_create("y",
    chartInstance->c3_7vqb7o7CaUJzbPKhFMyx3F_u, 0, 0U, 1U, 0U, 3, 601, 6, 12),
                false);
  sf_mex_assign(&c3_7vqb7o7CaUJzbPKhFMyx3F_mxArrayOutData,
                c3_7vqb7o7CaUJzbPKhFMyx3F_y, false);
  return c3_7vqb7o7CaUJzbPKhFMyx3F_mxArrayOutData;
}

static const mxArray *c3_7vqb7o7CaUJzbPKhFMyx3F_f_sf_marshallOut(void
  *chartInstanceVoid, void *c3_7vqb7o7CaUJzbPKhFMyx3F_b_inData)
{
  const mxArray *c3_7vqb7o7CaUJzbPKhFMyx3F_mxArrayOutData = NULL;
  int32_T c3_7vqb7o7CaUJzbPKhFMyx3F_i56;
  int32_T c3_7vqb7o7CaUJzbPKhFMyx3F_i57;
  int32_T c3_7vqb7o7CaUJzbPKhFMyx3F_i58;
  real_T c3_7vqb7o7CaUJzbPKhFMyx3F_c_inData[3606];
  int32_T c3_7vqb7o7CaUJzbPKhFMyx3F_i59;
  int32_T c3_7vqb7o7CaUJzbPKhFMyx3F_i60;
  int32_T c3_7vqb7o7CaUJzbPKhFMyx3F_i61;
  real_T c3_7vqb7o7CaUJzbPKhFMyx3F_b_u[3606];
  const mxArray *c3_7vqb7o7CaUJzbPKhFMyx3F_y = NULL;
  SFc3_7vqb7o7CaUJzbPKhFMyx3F_WECSim_LibInstanceStruct *chartInstance;
  chartInstance = (SFc3_7vqb7o7CaUJzbPKhFMyx3F_WECSim_LibInstanceStruct *)
    chartInstanceVoid;
  c3_7vqb7o7CaUJzbPKhFMyx3F_mxArrayOutData = NULL;
  c3_7vqb7o7CaUJzbPKhFMyx3F_i56 = 0;
  for (c3_7vqb7o7CaUJzbPKhFMyx3F_i57 = 0; c3_7vqb7o7CaUJzbPKhFMyx3F_i57 < 601;
       c3_7vqb7o7CaUJzbPKhFMyx3F_i57++) {
    for (c3_7vqb7o7CaUJzbPKhFMyx3F_i58 = 0; c3_7vqb7o7CaUJzbPKhFMyx3F_i58 < 6;
         c3_7vqb7o7CaUJzbPKhFMyx3F_i58++) {
      c3_7vqb7o7CaUJzbPKhFMyx3F_c_inData[c3_7vqb7o7CaUJzbPKhFMyx3F_i58 +
        c3_7vqb7o7CaUJzbPKhFMyx3F_i56] = (*(real_T (*)[3606])
        c3_7vqb7o7CaUJzbPKhFMyx3F_b_inData)[c3_7vqb7o7CaUJzbPKhFMyx3F_i58 +
        c3_7vqb7o7CaUJzbPKhFMyx3F_i56];
    }

    c3_7vqb7o7CaUJzbPKhFMyx3F_i56 += 6;
  }

  c3_7vqb7o7CaUJzbPKhFMyx3F_i59 = 0;
  for (c3_7vqb7o7CaUJzbPKhFMyx3F_i60 = 0; c3_7vqb7o7CaUJzbPKhFMyx3F_i60 < 601;
       c3_7vqb7o7CaUJzbPKhFMyx3F_i60++) {
    for (c3_7vqb7o7CaUJzbPKhFMyx3F_i61 = 0; c3_7vqb7o7CaUJzbPKhFMyx3F_i61 < 6;
         c3_7vqb7o7CaUJzbPKhFMyx3F_i61++) {
      c3_7vqb7o7CaUJzbPKhFMyx3F_b_u[c3_7vqb7o7CaUJzbPKhFMyx3F_i61 +
        c3_7vqb7o7CaUJzbPKhFMyx3F_i59] =
        c3_7vqb7o7CaUJzbPKhFMyx3F_c_inData[c3_7vqb7o7CaUJzbPKhFMyx3F_i61 +
        c3_7vqb7o7CaUJzbPKhFMyx3F_i59];
    }

    c3_7vqb7o7CaUJzbPKhFMyx3F_i59 += 6;
  }

  c3_7vqb7o7CaUJzbPKhFMyx3F_y = NULL;
  sf_mex_assign(&c3_7vqb7o7CaUJzbPKhFMyx3F_y, sf_mex_create("y",
    c3_7vqb7o7CaUJzbPKhFMyx3F_b_u, 0, 0U, 1U, 0U, 2, 6, 601), false);
  sf_mex_assign(&c3_7vqb7o7CaUJzbPKhFMyx3F_mxArrayOutData,
                c3_7vqb7o7CaUJzbPKhFMyx3F_y, false);
  return c3_7vqb7o7CaUJzbPKhFMyx3F_mxArrayOutData;
}

static const mxArray *c3_7vqb7o7CaUJzbPKhFMyx3F_g_sf_marshallOut(void
  *chartInstanceVoid, void *c3_7vqb7o7CaUJzbPKhFMyx3F_b_inData)
{
  const mxArray *c3_7vqb7o7CaUJzbPKhFMyx3F_mxArrayOutData = NULL;
  real_T c3_7vqb7o7CaUJzbPKhFMyx3F_b_u;
  const mxArray *c3_7vqb7o7CaUJzbPKhFMyx3F_y = NULL;
  SFc3_7vqb7o7CaUJzbPKhFMyx3F_WECSim_LibInstanceStruct *chartInstance;
  chartInstance = (SFc3_7vqb7o7CaUJzbPKhFMyx3F_WECSim_LibInstanceStruct *)
    chartInstanceVoid;
  c3_7vqb7o7CaUJzbPKhFMyx3F_mxArrayOutData = NULL;
  c3_7vqb7o7CaUJzbPKhFMyx3F_b_u = *(real_T *)c3_7vqb7o7CaUJzbPKhFMyx3F_b_inData;
  c3_7vqb7o7CaUJzbPKhFMyx3F_y = NULL;
  sf_mex_assign(&c3_7vqb7o7CaUJzbPKhFMyx3F_y, sf_mex_create("y",
    &c3_7vqb7o7CaUJzbPKhFMyx3F_b_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c3_7vqb7o7CaUJzbPKhFMyx3F_mxArrayOutData,
                c3_7vqb7o7CaUJzbPKhFMyx3F_y, false);
  return c3_7vqb7o7CaUJzbPKhFMyx3F_mxArrayOutData;
}

static real_T c3_7vqb7o7CaUJzbPKhFMyx3F_g_emlrt_marshallIn
  (SFc3_7vqb7o7CaUJzbPKhFMyx3F_WECSim_LibInstanceStruct *chartInstance, const
   mxArray *c3_7vqb7o7CaUJzbPKhFMyx3F_b_u, const emlrtMsgIdentifier
   *c3_7vqb7o7CaUJzbPKhFMyx3F_parentId)
{
  real_T c3_7vqb7o7CaUJzbPKhFMyx3F_y;
  real_T c3_7vqb7o7CaUJzbPKhFMyx3F_d2;
  (void)chartInstance;
  sf_mex_import(c3_7vqb7o7CaUJzbPKhFMyx3F_parentId, sf_mex_dup
                (c3_7vqb7o7CaUJzbPKhFMyx3F_b_u), &c3_7vqb7o7CaUJzbPKhFMyx3F_d2,
                1, 0, 0U, 0, 0U, 0);
  c3_7vqb7o7CaUJzbPKhFMyx3F_y = c3_7vqb7o7CaUJzbPKhFMyx3F_d2;
  sf_mex_destroy(&c3_7vqb7o7CaUJzbPKhFMyx3F_b_u);
  return c3_7vqb7o7CaUJzbPKhFMyx3F_y;
}

static void c3_7vqb7o7CaUJzbPKhFMyx3F_d_sf_marshallIn(void *chartInstanceVoid,
  const mxArray *c3_7vqb7o7CaUJzbPKhFMyx3F_mxArrayInData, const char_T
  *c3_7vqb7o7CaUJzbPKhFMyx3F_varName, void *c3_7vqb7o7CaUJzbPKhFMyx3F_outData)
{
  const mxArray *c3_7vqb7o7CaUJzbPKhFMyx3F_nargout;
  const char_T *c3_7vqb7o7CaUJzbPKhFMyx3F_identifier;
  emlrtMsgIdentifier c3_7vqb7o7CaUJzbPKhFMyx3F_thisId;
  real_T c3_7vqb7o7CaUJzbPKhFMyx3F_y;
  SFc3_7vqb7o7CaUJzbPKhFMyx3F_WECSim_LibInstanceStruct *chartInstance;
  chartInstance = (SFc3_7vqb7o7CaUJzbPKhFMyx3F_WECSim_LibInstanceStruct *)
    chartInstanceVoid;
  c3_7vqb7o7CaUJzbPKhFMyx3F_nargout = sf_mex_dup
    (c3_7vqb7o7CaUJzbPKhFMyx3F_mxArrayInData);
  c3_7vqb7o7CaUJzbPKhFMyx3F_identifier = c3_7vqb7o7CaUJzbPKhFMyx3F_varName;
  c3_7vqb7o7CaUJzbPKhFMyx3F_thisId.fIdentifier =
    c3_7vqb7o7CaUJzbPKhFMyx3F_identifier;
  c3_7vqb7o7CaUJzbPKhFMyx3F_thisId.fParent = NULL;
  c3_7vqb7o7CaUJzbPKhFMyx3F_y = c3_7vqb7o7CaUJzbPKhFMyx3F_g_emlrt_marshallIn
    (chartInstance, sf_mex_dup(c3_7vqb7o7CaUJzbPKhFMyx3F_nargout),
     &c3_7vqb7o7CaUJzbPKhFMyx3F_thisId);
  sf_mex_destroy(&c3_7vqb7o7CaUJzbPKhFMyx3F_nargout);
  *(real_T *)c3_7vqb7o7CaUJzbPKhFMyx3F_outData = c3_7vqb7o7CaUJzbPKhFMyx3F_y;
  sf_mex_destroy(&c3_7vqb7o7CaUJzbPKhFMyx3F_mxArrayInData);
}

static void c3_7vqb7o7CaUJzbPKhFMyx3F_h_emlrt_marshallIn
  (SFc3_7vqb7o7CaUJzbPKhFMyx3F_WECSim_LibInstanceStruct *chartInstance, const
   mxArray *c3_7vqb7o7CaUJzbPKhFMyx3F_b_u, const emlrtMsgIdentifier
   *c3_7vqb7o7CaUJzbPKhFMyx3F_parentId, real_T c3_7vqb7o7CaUJzbPKhFMyx3F_y[601])
{
  real_T c3_7vqb7o7CaUJzbPKhFMyx3F_dv5[601];
  int32_T c3_7vqb7o7CaUJzbPKhFMyx3F_i62;
  (void)chartInstance;
  sf_mex_import(c3_7vqb7o7CaUJzbPKhFMyx3F_parentId, sf_mex_dup
                (c3_7vqb7o7CaUJzbPKhFMyx3F_b_u), c3_7vqb7o7CaUJzbPKhFMyx3F_dv5,
                1, 0, 0U, 1, 0U, 1, 601);
  for (c3_7vqb7o7CaUJzbPKhFMyx3F_i62 = 0; c3_7vqb7o7CaUJzbPKhFMyx3F_i62 < 601;
       c3_7vqb7o7CaUJzbPKhFMyx3F_i62++) {
    c3_7vqb7o7CaUJzbPKhFMyx3F_y[c3_7vqb7o7CaUJzbPKhFMyx3F_i62] =
      c3_7vqb7o7CaUJzbPKhFMyx3F_dv5[c3_7vqb7o7CaUJzbPKhFMyx3F_i62];
  }

  sf_mex_destroy(&c3_7vqb7o7CaUJzbPKhFMyx3F_b_u);
}

static void c3_7vqb7o7CaUJzbPKhFMyx3F_e_sf_marshallIn(void *chartInstanceVoid,
  const mxArray *c3_7vqb7o7CaUJzbPKhFMyx3F_mxArrayInData, const char_T
  *c3_7vqb7o7CaUJzbPKhFMyx3F_varName, void *c3_7vqb7o7CaUJzbPKhFMyx3F_outData)
{
  const mxArray *c3_7vqb7o7CaUJzbPKhFMyx3F_tmpY;
  const char_T *c3_7vqb7o7CaUJzbPKhFMyx3F_identifier;
  emlrtMsgIdentifier c3_7vqb7o7CaUJzbPKhFMyx3F_thisId;
  real_T c3_7vqb7o7CaUJzbPKhFMyx3F_y[601];
  int32_T c3_7vqb7o7CaUJzbPKhFMyx3F_i63;
  SFc3_7vqb7o7CaUJzbPKhFMyx3F_WECSim_LibInstanceStruct *chartInstance;
  chartInstance = (SFc3_7vqb7o7CaUJzbPKhFMyx3F_WECSim_LibInstanceStruct *)
    chartInstanceVoid;
  c3_7vqb7o7CaUJzbPKhFMyx3F_tmpY = sf_mex_dup
    (c3_7vqb7o7CaUJzbPKhFMyx3F_mxArrayInData);
  c3_7vqb7o7CaUJzbPKhFMyx3F_identifier = c3_7vqb7o7CaUJzbPKhFMyx3F_varName;
  c3_7vqb7o7CaUJzbPKhFMyx3F_thisId.fIdentifier =
    c3_7vqb7o7CaUJzbPKhFMyx3F_identifier;
  c3_7vqb7o7CaUJzbPKhFMyx3F_thisId.fParent = NULL;
  c3_7vqb7o7CaUJzbPKhFMyx3F_h_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c3_7vqb7o7CaUJzbPKhFMyx3F_tmpY), &c3_7vqb7o7CaUJzbPKhFMyx3F_thisId,
    c3_7vqb7o7CaUJzbPKhFMyx3F_y);
  sf_mex_destroy(&c3_7vqb7o7CaUJzbPKhFMyx3F_tmpY);
  for (c3_7vqb7o7CaUJzbPKhFMyx3F_i63 = 0; c3_7vqb7o7CaUJzbPKhFMyx3F_i63 < 601;
       c3_7vqb7o7CaUJzbPKhFMyx3F_i63++) {
    (*(real_T (*)[601])c3_7vqb7o7CaUJzbPKhFMyx3F_outData)
      [c3_7vqb7o7CaUJzbPKhFMyx3F_i63] =
      c3_7vqb7o7CaUJzbPKhFMyx3F_y[c3_7vqb7o7CaUJzbPKhFMyx3F_i63];
  }

  sf_mex_destroy(&c3_7vqb7o7CaUJzbPKhFMyx3F_mxArrayInData);
}

static const mxArray *c3_7vqb7o7CaUJzbPKhFMyx3F_h_sf_marshallOut(void
  *chartInstanceVoid, void *c3_7vqb7o7CaUJzbPKhFMyx3F_b_inData)
{
  const mxArray *c3_7vqb7o7CaUJzbPKhFMyx3F_mxArrayOutData = NULL;
  int32_T c3_7vqb7o7CaUJzbPKhFMyx3F_i64;
  int32_T c3_7vqb7o7CaUJzbPKhFMyx3F_i65;
  int32_T c3_7vqb7o7CaUJzbPKhFMyx3F_i66;
  real_T c3_7vqb7o7CaUJzbPKhFMyx3F_c_inData[36];
  int32_T c3_7vqb7o7CaUJzbPKhFMyx3F_i67;
  int32_T c3_7vqb7o7CaUJzbPKhFMyx3F_i68;
  int32_T c3_7vqb7o7CaUJzbPKhFMyx3F_i69;
  real_T c3_7vqb7o7CaUJzbPKhFMyx3F_b_u[36];
  const mxArray *c3_7vqb7o7CaUJzbPKhFMyx3F_y = NULL;
  SFc3_7vqb7o7CaUJzbPKhFMyx3F_WECSim_LibInstanceStruct *chartInstance;
  chartInstance = (SFc3_7vqb7o7CaUJzbPKhFMyx3F_WECSim_LibInstanceStruct *)
    chartInstanceVoid;
  c3_7vqb7o7CaUJzbPKhFMyx3F_mxArrayOutData = NULL;
  c3_7vqb7o7CaUJzbPKhFMyx3F_i64 = 0;
  for (c3_7vqb7o7CaUJzbPKhFMyx3F_i65 = 0; c3_7vqb7o7CaUJzbPKhFMyx3F_i65 < 6;
       c3_7vqb7o7CaUJzbPKhFMyx3F_i65++) {
    for (c3_7vqb7o7CaUJzbPKhFMyx3F_i66 = 0; c3_7vqb7o7CaUJzbPKhFMyx3F_i66 < 6;
         c3_7vqb7o7CaUJzbPKhFMyx3F_i66++) {
      c3_7vqb7o7CaUJzbPKhFMyx3F_c_inData[c3_7vqb7o7CaUJzbPKhFMyx3F_i66 +
        c3_7vqb7o7CaUJzbPKhFMyx3F_i64] = (*(real_T (*)[36])
        c3_7vqb7o7CaUJzbPKhFMyx3F_b_inData)[c3_7vqb7o7CaUJzbPKhFMyx3F_i66 +
        c3_7vqb7o7CaUJzbPKhFMyx3F_i64];
    }

    c3_7vqb7o7CaUJzbPKhFMyx3F_i64 += 6;
  }

  c3_7vqb7o7CaUJzbPKhFMyx3F_i67 = 0;
  for (c3_7vqb7o7CaUJzbPKhFMyx3F_i68 = 0; c3_7vqb7o7CaUJzbPKhFMyx3F_i68 < 6;
       c3_7vqb7o7CaUJzbPKhFMyx3F_i68++) {
    for (c3_7vqb7o7CaUJzbPKhFMyx3F_i69 = 0; c3_7vqb7o7CaUJzbPKhFMyx3F_i69 < 6;
         c3_7vqb7o7CaUJzbPKhFMyx3F_i69++) {
      c3_7vqb7o7CaUJzbPKhFMyx3F_b_u[c3_7vqb7o7CaUJzbPKhFMyx3F_i69 +
        c3_7vqb7o7CaUJzbPKhFMyx3F_i67] =
        c3_7vqb7o7CaUJzbPKhFMyx3F_c_inData[c3_7vqb7o7CaUJzbPKhFMyx3F_i69 +
        c3_7vqb7o7CaUJzbPKhFMyx3F_i67];
    }

    c3_7vqb7o7CaUJzbPKhFMyx3F_i67 += 6;
  }

  c3_7vqb7o7CaUJzbPKhFMyx3F_y = NULL;
  sf_mex_assign(&c3_7vqb7o7CaUJzbPKhFMyx3F_y, sf_mex_create("y",
    c3_7vqb7o7CaUJzbPKhFMyx3F_b_u, 0, 0U, 1U, 0U, 2, 6, 6), false);
  sf_mex_assign(&c3_7vqb7o7CaUJzbPKhFMyx3F_mxArrayOutData,
                c3_7vqb7o7CaUJzbPKhFMyx3F_y, false);
  return c3_7vqb7o7CaUJzbPKhFMyx3F_mxArrayOutData;
}

static void c3_7vqb7o7CaUJzbPKhFMyx3F_i_emlrt_marshallIn
  (SFc3_7vqb7o7CaUJzbPKhFMyx3F_WECSim_LibInstanceStruct *chartInstance, const
   mxArray *c3_7vqb7o7CaUJzbPKhFMyx3F_b_u, const emlrtMsgIdentifier
   *c3_7vqb7o7CaUJzbPKhFMyx3F_parentId, real_T c3_7vqb7o7CaUJzbPKhFMyx3F_y[36])
{
  real_T c3_7vqb7o7CaUJzbPKhFMyx3F_dv6[36];
  int32_T c3_7vqb7o7CaUJzbPKhFMyx3F_i70;
  (void)chartInstance;
  sf_mex_import(c3_7vqb7o7CaUJzbPKhFMyx3F_parentId, sf_mex_dup
                (c3_7vqb7o7CaUJzbPKhFMyx3F_b_u), c3_7vqb7o7CaUJzbPKhFMyx3F_dv6,
                1, 0, 0U, 1, 0U, 2, 6, 6);
  for (c3_7vqb7o7CaUJzbPKhFMyx3F_i70 = 0; c3_7vqb7o7CaUJzbPKhFMyx3F_i70 < 36;
       c3_7vqb7o7CaUJzbPKhFMyx3F_i70++) {
    c3_7vqb7o7CaUJzbPKhFMyx3F_y[c3_7vqb7o7CaUJzbPKhFMyx3F_i70] =
      c3_7vqb7o7CaUJzbPKhFMyx3F_dv6[c3_7vqb7o7CaUJzbPKhFMyx3F_i70];
  }

  sf_mex_destroy(&c3_7vqb7o7CaUJzbPKhFMyx3F_b_u);
}

static void c3_7vqb7o7CaUJzbPKhFMyx3F_f_sf_marshallIn(void *chartInstanceVoid,
  const mxArray *c3_7vqb7o7CaUJzbPKhFMyx3F_mxArrayInData, const char_T
  *c3_7vqb7o7CaUJzbPKhFMyx3F_varName, void *c3_7vqb7o7CaUJzbPKhFMyx3F_outData)
{
  const mxArray *c3_7vqb7o7CaUJzbPKhFMyx3F_tmpF;
  const char_T *c3_7vqb7o7CaUJzbPKhFMyx3F_identifier;
  emlrtMsgIdentifier c3_7vqb7o7CaUJzbPKhFMyx3F_thisId;
  real_T c3_7vqb7o7CaUJzbPKhFMyx3F_y[36];
  int32_T c3_7vqb7o7CaUJzbPKhFMyx3F_i71;
  int32_T c3_7vqb7o7CaUJzbPKhFMyx3F_i72;
  int32_T c3_7vqb7o7CaUJzbPKhFMyx3F_i73;
  SFc3_7vqb7o7CaUJzbPKhFMyx3F_WECSim_LibInstanceStruct *chartInstance;
  chartInstance = (SFc3_7vqb7o7CaUJzbPKhFMyx3F_WECSim_LibInstanceStruct *)
    chartInstanceVoid;
  c3_7vqb7o7CaUJzbPKhFMyx3F_tmpF = sf_mex_dup
    (c3_7vqb7o7CaUJzbPKhFMyx3F_mxArrayInData);
  c3_7vqb7o7CaUJzbPKhFMyx3F_identifier = c3_7vqb7o7CaUJzbPKhFMyx3F_varName;
  c3_7vqb7o7CaUJzbPKhFMyx3F_thisId.fIdentifier =
    c3_7vqb7o7CaUJzbPKhFMyx3F_identifier;
  c3_7vqb7o7CaUJzbPKhFMyx3F_thisId.fParent = NULL;
  c3_7vqb7o7CaUJzbPKhFMyx3F_i_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c3_7vqb7o7CaUJzbPKhFMyx3F_tmpF), &c3_7vqb7o7CaUJzbPKhFMyx3F_thisId,
    c3_7vqb7o7CaUJzbPKhFMyx3F_y);
  sf_mex_destroy(&c3_7vqb7o7CaUJzbPKhFMyx3F_tmpF);
  c3_7vqb7o7CaUJzbPKhFMyx3F_i71 = 0;
  for (c3_7vqb7o7CaUJzbPKhFMyx3F_i72 = 0; c3_7vqb7o7CaUJzbPKhFMyx3F_i72 < 6;
       c3_7vqb7o7CaUJzbPKhFMyx3F_i72++) {
    for (c3_7vqb7o7CaUJzbPKhFMyx3F_i73 = 0; c3_7vqb7o7CaUJzbPKhFMyx3F_i73 < 6;
         c3_7vqb7o7CaUJzbPKhFMyx3F_i73++) {
      (*(real_T (*)[36])c3_7vqb7o7CaUJzbPKhFMyx3F_outData)
        [c3_7vqb7o7CaUJzbPKhFMyx3F_i73 + c3_7vqb7o7CaUJzbPKhFMyx3F_i71] =
        c3_7vqb7o7CaUJzbPKhFMyx3F_y[c3_7vqb7o7CaUJzbPKhFMyx3F_i73 +
        c3_7vqb7o7CaUJzbPKhFMyx3F_i71];
    }

    c3_7vqb7o7CaUJzbPKhFMyx3F_i71 += 6;
  }

  sf_mex_destroy(&c3_7vqb7o7CaUJzbPKhFMyx3F_mxArrayInData);
}

const mxArray
  *sf_c3_7vqb7o7CaUJzbPKhFMyx3F_WECSim_Lib_get_eml_resolved_functions_info(void)
{
  const mxArray *c3_7vqb7o7CaUJzbPKhFMyx3F_nameCaptureInfo = NULL;
  c3_7vqb7o7CaUJzbPKhFMyx3F_nameCaptureInfo = NULL;
  sf_mex_assign(&c3_7vqb7o7CaUJzbPKhFMyx3F_nameCaptureInfo, sf_mex_createstruct(
    "structure", 2, 51, 1), false);
  c3_7vqb7o7CaUJzbPKhFMyx3F_info_helper
    (&c3_7vqb7o7CaUJzbPKhFMyx3F_nameCaptureInfo);
  sf_mex_emlrtNameCapturePostProcessR2012a
    (&c3_7vqb7o7CaUJzbPKhFMyx3F_nameCaptureInfo);
  return c3_7vqb7o7CaUJzbPKhFMyx3F_nameCaptureInfo;
}

static void c3_7vqb7o7CaUJzbPKhFMyx3F_info_helper(const mxArray
  **c3_7vqb7o7CaUJzbPKhFMyx3F_info)
{
  const mxArray *c3_7vqb7o7CaUJzbPKhFMyx3F_rhs0 = NULL;
  const mxArray *c3_7vqb7o7CaUJzbPKhFMyx3F_lhs0 = NULL;
  const mxArray *c3_7vqb7o7CaUJzbPKhFMyx3F_rhs1 = NULL;
  const mxArray *c3_7vqb7o7CaUJzbPKhFMyx3F_lhs1 = NULL;
  const mxArray *c3_7vqb7o7CaUJzbPKhFMyx3F_rhs2 = NULL;
  const mxArray *c3_7vqb7o7CaUJzbPKhFMyx3F_lhs2 = NULL;
  const mxArray *c3_7vqb7o7CaUJzbPKhFMyx3F_rhs3 = NULL;
  const mxArray *c3_7vqb7o7CaUJzbPKhFMyx3F_lhs3 = NULL;
  const mxArray *c3_7vqb7o7CaUJzbPKhFMyx3F_rhs4 = NULL;
  const mxArray *c3_7vqb7o7CaUJzbPKhFMyx3F_lhs4 = NULL;
  const mxArray *c3_7vqb7o7CaUJzbPKhFMyx3F_rhs5 = NULL;
  const mxArray *c3_7vqb7o7CaUJzbPKhFMyx3F_lhs5 = NULL;
  const mxArray *c3_7vqb7o7CaUJzbPKhFMyx3F_rhs6 = NULL;
  const mxArray *c3_7vqb7o7CaUJzbPKhFMyx3F_lhs6 = NULL;
  const mxArray *c3_7vqb7o7CaUJzbPKhFMyx3F_rhs7 = NULL;
  const mxArray *c3_7vqb7o7CaUJzbPKhFMyx3F_lhs7 = NULL;
  const mxArray *c3_7vqb7o7CaUJzbPKhFMyx3F_rhs8 = NULL;
  const mxArray *c3_7vqb7o7CaUJzbPKhFMyx3F_lhs8 = NULL;
  const mxArray *c3_7vqb7o7CaUJzbPKhFMyx3F_rhs9 = NULL;
  const mxArray *c3_7vqb7o7CaUJzbPKhFMyx3F_lhs9 = NULL;
  const mxArray *c3_7vqb7o7CaUJzbPKhFMyx3F_rhs10 = NULL;
  const mxArray *c3_7vqb7o7CaUJzbPKhFMyx3F_lhs10 = NULL;
  const mxArray *c3_7vqb7o7CaUJzbPKhFMyx3F_rhs11 = NULL;
  const mxArray *c3_7vqb7o7CaUJzbPKhFMyx3F_lhs11 = NULL;
  const mxArray *c3_7vqb7o7CaUJzbPKhFMyx3F_rhs12 = NULL;
  const mxArray *c3_7vqb7o7CaUJzbPKhFMyx3F_lhs12 = NULL;
  const mxArray *c3_7vqb7o7CaUJzbPKhFMyx3F_rhs13 = NULL;
  const mxArray *c3_7vqb7o7CaUJzbPKhFMyx3F_lhs13 = NULL;
  const mxArray *c3_7vqb7o7CaUJzbPKhFMyx3F_rhs14 = NULL;
  const mxArray *c3_7vqb7o7CaUJzbPKhFMyx3F_lhs14 = NULL;
  const mxArray *c3_7vqb7o7CaUJzbPKhFMyx3F_rhs15 = NULL;
  const mxArray *c3_7vqb7o7CaUJzbPKhFMyx3F_lhs15 = NULL;
  const mxArray *c3_7vqb7o7CaUJzbPKhFMyx3F_rhs16 = NULL;
  const mxArray *c3_7vqb7o7CaUJzbPKhFMyx3F_lhs16 = NULL;
  const mxArray *c3_7vqb7o7CaUJzbPKhFMyx3F_rhs17 = NULL;
  const mxArray *c3_7vqb7o7CaUJzbPKhFMyx3F_lhs17 = NULL;
  const mxArray *c3_7vqb7o7CaUJzbPKhFMyx3F_rhs18 = NULL;
  const mxArray *c3_7vqb7o7CaUJzbPKhFMyx3F_lhs18 = NULL;
  const mxArray *c3_7vqb7o7CaUJzbPKhFMyx3F_rhs19 = NULL;
  const mxArray *c3_7vqb7o7CaUJzbPKhFMyx3F_lhs19 = NULL;
  const mxArray *c3_7vqb7o7CaUJzbPKhFMyx3F_rhs20 = NULL;
  const mxArray *c3_7vqb7o7CaUJzbPKhFMyx3F_lhs20 = NULL;
  const mxArray *c3_7vqb7o7CaUJzbPKhFMyx3F_rhs21 = NULL;
  const mxArray *c3_7vqb7o7CaUJzbPKhFMyx3F_lhs21 = NULL;
  const mxArray *c3_7vqb7o7CaUJzbPKhFMyx3F_rhs22 = NULL;
  const mxArray *c3_7vqb7o7CaUJzbPKhFMyx3F_lhs22 = NULL;
  const mxArray *c3_7vqb7o7CaUJzbPKhFMyx3F_rhs23 = NULL;
  const mxArray *c3_7vqb7o7CaUJzbPKhFMyx3F_lhs23 = NULL;
  const mxArray *c3_7vqb7o7CaUJzbPKhFMyx3F_rhs24 = NULL;
  const mxArray *c3_7vqb7o7CaUJzbPKhFMyx3F_lhs24 = NULL;
  const mxArray *c3_7vqb7o7CaUJzbPKhFMyx3F_rhs25 = NULL;
  const mxArray *c3_7vqb7o7CaUJzbPKhFMyx3F_lhs25 = NULL;
  const mxArray *c3_7vqb7o7CaUJzbPKhFMyx3F_rhs26 = NULL;
  const mxArray *c3_7vqb7o7CaUJzbPKhFMyx3F_lhs26 = NULL;
  const mxArray *c3_7vqb7o7CaUJzbPKhFMyx3F_rhs27 = NULL;
  const mxArray *c3_7vqb7o7CaUJzbPKhFMyx3F_lhs27 = NULL;
  const mxArray *c3_7vqb7o7CaUJzbPKhFMyx3F_rhs28 = NULL;
  const mxArray *c3_7vqb7o7CaUJzbPKhFMyx3F_lhs28 = NULL;
  const mxArray *c3_7vqb7o7CaUJzbPKhFMyx3F_rhs29 = NULL;
  const mxArray *c3_7vqb7o7CaUJzbPKhFMyx3F_lhs29 = NULL;
  const mxArray *c3_7vqb7o7CaUJzbPKhFMyx3F_rhs30 = NULL;
  const mxArray *c3_7vqb7o7CaUJzbPKhFMyx3F_lhs30 = NULL;
  const mxArray *c3_7vqb7o7CaUJzbPKhFMyx3F_rhs31 = NULL;
  const mxArray *c3_7vqb7o7CaUJzbPKhFMyx3F_lhs31 = NULL;
  const mxArray *c3_7vqb7o7CaUJzbPKhFMyx3F_rhs32 = NULL;
  const mxArray *c3_7vqb7o7CaUJzbPKhFMyx3F_lhs32 = NULL;
  const mxArray *c3_7vqb7o7CaUJzbPKhFMyx3F_rhs33 = NULL;
  const mxArray *c3_7vqb7o7CaUJzbPKhFMyx3F_lhs33 = NULL;
  const mxArray *c3_7vqb7o7CaUJzbPKhFMyx3F_rhs34 = NULL;
  const mxArray *c3_7vqb7o7CaUJzbPKhFMyx3F_lhs34 = NULL;
  const mxArray *c3_7vqb7o7CaUJzbPKhFMyx3F_rhs35 = NULL;
  const mxArray *c3_7vqb7o7CaUJzbPKhFMyx3F_lhs35 = NULL;
  const mxArray *c3_7vqb7o7CaUJzbPKhFMyx3F_rhs36 = NULL;
  const mxArray *c3_7vqb7o7CaUJzbPKhFMyx3F_lhs36 = NULL;
  const mxArray *c3_7vqb7o7CaUJzbPKhFMyx3F_rhs37 = NULL;
  const mxArray *c3_7vqb7o7CaUJzbPKhFMyx3F_lhs37 = NULL;
  const mxArray *c3_7vqb7o7CaUJzbPKhFMyx3F_rhs38 = NULL;
  const mxArray *c3_7vqb7o7CaUJzbPKhFMyx3F_lhs38 = NULL;
  const mxArray *c3_7vqb7o7CaUJzbPKhFMyx3F_rhs39 = NULL;
  const mxArray *c3_7vqb7o7CaUJzbPKhFMyx3F_lhs39 = NULL;
  const mxArray *c3_7vqb7o7CaUJzbPKhFMyx3F_rhs40 = NULL;
  const mxArray *c3_7vqb7o7CaUJzbPKhFMyx3F_lhs40 = NULL;
  const mxArray *c3_7vqb7o7CaUJzbPKhFMyx3F_rhs41 = NULL;
  const mxArray *c3_7vqb7o7CaUJzbPKhFMyx3F_lhs41 = NULL;
  const mxArray *c3_7vqb7o7CaUJzbPKhFMyx3F_rhs42 = NULL;
  const mxArray *c3_7vqb7o7CaUJzbPKhFMyx3F_lhs42 = NULL;
  const mxArray *c3_7vqb7o7CaUJzbPKhFMyx3F_rhs43 = NULL;
  const mxArray *c3_7vqb7o7CaUJzbPKhFMyx3F_lhs43 = NULL;
  const mxArray *c3_7vqb7o7CaUJzbPKhFMyx3F_rhs44 = NULL;
  const mxArray *c3_7vqb7o7CaUJzbPKhFMyx3F_lhs44 = NULL;
  const mxArray *c3_7vqb7o7CaUJzbPKhFMyx3F_rhs45 = NULL;
  const mxArray *c3_7vqb7o7CaUJzbPKhFMyx3F_lhs45 = NULL;
  const mxArray *c3_7vqb7o7CaUJzbPKhFMyx3F_rhs46 = NULL;
  const mxArray *c3_7vqb7o7CaUJzbPKhFMyx3F_lhs46 = NULL;
  const mxArray *c3_7vqb7o7CaUJzbPKhFMyx3F_rhs47 = NULL;
  const mxArray *c3_7vqb7o7CaUJzbPKhFMyx3F_lhs47 = NULL;
  const mxArray *c3_7vqb7o7CaUJzbPKhFMyx3F_rhs48 = NULL;
  const mxArray *c3_7vqb7o7CaUJzbPKhFMyx3F_lhs48 = NULL;
  const mxArray *c3_7vqb7o7CaUJzbPKhFMyx3F_rhs49 = NULL;
  const mxArray *c3_7vqb7o7CaUJzbPKhFMyx3F_lhs49 = NULL;
  const mxArray *c3_7vqb7o7CaUJzbPKhFMyx3F_rhs50 = NULL;
  const mxArray *c3_7vqb7o7CaUJzbPKhFMyx3F_lhs50 = NULL;
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_emlrt_marshallOut(""), "context",
                  "context", 0);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_emlrt_marshallOut("mrdivide"),
                  "name", "name", 0);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_emlrt_marshallOut("double"),
                  "dominantType", "dominantType", 0);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "resolved",
                  "resolved", 0);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_b_emlrt_marshallOut(1410836448U),
                  "fileTimeLo", "fileTimeLo", 0);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_b_emlrt_marshallOut(0U),
                  "fileTimeHi", "fileTimeHi", 0);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_b_emlrt_marshallOut(1370038686U),
                  "mFileTimeLo", "mFileTimeLo", 0);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_b_emlrt_marshallOut(0U),
                  "mFileTimeHi", "mFileTimeHi", 0);
  sf_mex_assign(&c3_7vqb7o7CaUJzbPKhFMyx3F_rhs0, sf_mex_createcellmatrix(0, 1),
                false);
  sf_mex_assign(&c3_7vqb7o7CaUJzbPKhFMyx3F_lhs0, sf_mex_createcellmatrix(0, 1),
                false);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info, sf_mex_duplicatearraysafe
                  (&c3_7vqb7o7CaUJzbPKhFMyx3F_rhs0), "rhs", "rhs", 0);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info, sf_mex_duplicatearraysafe
                  (&c3_7vqb7o7CaUJzbPKhFMyx3F_lhs0), "lhs", "lhs", 0);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "context",
                  "context", 1);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_emlrt_marshallOut(
    "coder.internal.assert"), "name", "name", 1);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_emlrt_marshallOut("char"),
                  "dominantType", "dominantType", 1);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/assert.m"),
                  "resolved", "resolved", 1);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_b_emlrt_marshallOut(1389746574U),
                  "fileTimeLo", "fileTimeLo", 1);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_b_emlrt_marshallOut(0U),
                  "fileTimeHi", "fileTimeHi", 1);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_b_emlrt_marshallOut(0U),
                  "mFileTimeLo", "mFileTimeLo", 1);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_b_emlrt_marshallOut(0U),
                  "mFileTimeHi", "mFileTimeHi", 1);
  sf_mex_assign(&c3_7vqb7o7CaUJzbPKhFMyx3F_rhs1, sf_mex_createcellmatrix(0, 1),
                false);
  sf_mex_assign(&c3_7vqb7o7CaUJzbPKhFMyx3F_lhs1, sf_mex_createcellmatrix(0, 1),
                false);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info, sf_mex_duplicatearraysafe
                  (&c3_7vqb7o7CaUJzbPKhFMyx3F_rhs1), "rhs", "rhs", 1);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info, sf_mex_duplicatearraysafe
                  (&c3_7vqb7o7CaUJzbPKhFMyx3F_lhs1), "lhs", "lhs", 1);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "context",
                  "context", 2);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_emlrt_marshallOut("rdivide"), "name",
                  "name", 2);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_emlrt_marshallOut("double"),
                  "dominantType", "dominantType", 2);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "resolved",
                  "resolved", 2);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_b_emlrt_marshallOut(1363739080U),
                  "fileTimeLo", "fileTimeLo", 2);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_b_emlrt_marshallOut(0U),
                  "fileTimeHi", "fileTimeHi", 2);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_b_emlrt_marshallOut(0U),
                  "mFileTimeLo", "mFileTimeLo", 2);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_b_emlrt_marshallOut(0U),
                  "mFileTimeHi", "mFileTimeHi", 2);
  sf_mex_assign(&c3_7vqb7o7CaUJzbPKhFMyx3F_rhs2, sf_mex_createcellmatrix(0, 1),
                false);
  sf_mex_assign(&c3_7vqb7o7CaUJzbPKhFMyx3F_lhs2, sf_mex_createcellmatrix(0, 1),
                false);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info, sf_mex_duplicatearraysafe
                  (&c3_7vqb7o7CaUJzbPKhFMyx3F_rhs2), "rhs", "rhs", 2);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info, sf_mex_duplicatearraysafe
                  (&c3_7vqb7o7CaUJzbPKhFMyx3F_lhs2), "lhs", "lhs", 2);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 3);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 3);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_emlrt_marshallOut("double"),
                  "dominantType", "dominantType", 3);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 3);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_b_emlrt_marshallOut(1395957056U),
                  "fileTimeLo", "fileTimeLo", 3);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_b_emlrt_marshallOut(0U),
                  "fileTimeHi", "fileTimeHi", 3);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_b_emlrt_marshallOut(0U),
                  "mFileTimeLo", "mFileTimeLo", 3);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_b_emlrt_marshallOut(0U),
                  "mFileTimeHi", "mFileTimeHi", 3);
  sf_mex_assign(&c3_7vqb7o7CaUJzbPKhFMyx3F_rhs3, sf_mex_createcellmatrix(0, 1),
                false);
  sf_mex_assign(&c3_7vqb7o7CaUJzbPKhFMyx3F_lhs3, sf_mex_createcellmatrix(0, 1),
                false);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info, sf_mex_duplicatearraysafe
                  (&c3_7vqb7o7CaUJzbPKhFMyx3F_rhs3), "rhs", "rhs", 3);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info, sf_mex_duplicatearraysafe
                  (&c3_7vqb7o7CaUJzbPKhFMyx3F_lhs3), "lhs", "lhs", 3);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 4);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_emlrt_marshallOut(
    "eml_scalexp_compatible"), "name", "name", 4);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_emlrt_marshallOut("double"),
                  "dominantType", "dominantType", 4);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_compatible.m"),
                  "resolved", "resolved", 4);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_b_emlrt_marshallOut(1286847596U),
                  "fileTimeLo", "fileTimeLo", 4);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_b_emlrt_marshallOut(0U),
                  "fileTimeHi", "fileTimeHi", 4);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_b_emlrt_marshallOut(0U),
                  "mFileTimeLo", "mFileTimeLo", 4);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_b_emlrt_marshallOut(0U),
                  "mFileTimeHi", "mFileTimeHi", 4);
  sf_mex_assign(&c3_7vqb7o7CaUJzbPKhFMyx3F_rhs4, sf_mex_createcellmatrix(0, 1),
                false);
  sf_mex_assign(&c3_7vqb7o7CaUJzbPKhFMyx3F_lhs4, sf_mex_createcellmatrix(0, 1),
                false);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info, sf_mex_duplicatearraysafe
                  (&c3_7vqb7o7CaUJzbPKhFMyx3F_rhs4), "rhs", "rhs", 4);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info, sf_mex_duplicatearraysafe
                  (&c3_7vqb7o7CaUJzbPKhFMyx3F_lhs4), "lhs", "lhs", 4);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 5);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_emlrt_marshallOut("eml_div"), "name",
                  "name", 5);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_emlrt_marshallOut("double"),
                  "dominantType", "dominantType", 5);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m"), "resolved",
                  "resolved", 5);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_b_emlrt_marshallOut(1386452752U),
                  "fileTimeLo", "fileTimeLo", 5);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_b_emlrt_marshallOut(0U),
                  "fileTimeHi", "fileTimeHi", 5);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_b_emlrt_marshallOut(0U),
                  "mFileTimeLo", "mFileTimeLo", 5);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_b_emlrt_marshallOut(0U),
                  "mFileTimeHi", "mFileTimeHi", 5);
  sf_mex_assign(&c3_7vqb7o7CaUJzbPKhFMyx3F_rhs5, sf_mex_createcellmatrix(0, 1),
                false);
  sf_mex_assign(&c3_7vqb7o7CaUJzbPKhFMyx3F_lhs5, sf_mex_createcellmatrix(0, 1),
                false);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info, sf_mex_duplicatearraysafe
                  (&c3_7vqb7o7CaUJzbPKhFMyx3F_rhs5), "rhs", "rhs", 5);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info, sf_mex_duplicatearraysafe
                  (&c3_7vqb7o7CaUJzbPKhFMyx3F_lhs5), "lhs", "lhs", 5);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m"), "context",
                  "context", 6);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_emlrt_marshallOut(
    "coder.internal.div"), "name", "name", 6);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_emlrt_marshallOut("double"),
                  "dominantType", "dominantType", 6);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/div.p"), "resolved",
                  "resolved", 6);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_b_emlrt_marshallOut(1410836570U),
                  "fileTimeLo", "fileTimeLo", 6);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_b_emlrt_marshallOut(0U),
                  "fileTimeHi", "fileTimeHi", 6);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_b_emlrt_marshallOut(0U),
                  "mFileTimeLo", "mFileTimeLo", 6);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_b_emlrt_marshallOut(0U),
                  "mFileTimeHi", "mFileTimeHi", 6);
  sf_mex_assign(&c3_7vqb7o7CaUJzbPKhFMyx3F_rhs6, sf_mex_createcellmatrix(0, 1),
                false);
  sf_mex_assign(&c3_7vqb7o7CaUJzbPKhFMyx3F_lhs6, sf_mex_createcellmatrix(0, 1),
                false);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info, sf_mex_duplicatearraysafe
                  (&c3_7vqb7o7CaUJzbPKhFMyx3F_rhs6), "rhs", "rhs", 6);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info, sf_mex_duplicatearraysafe
                  (&c3_7vqb7o7CaUJzbPKhFMyx3F_lhs6), "lhs", "lhs", 6);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_emlrt_marshallOut(""), "context",
                  "context", 7);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_emlrt_marshallOut("floor"), "name",
                  "name", 7);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_emlrt_marshallOut("double"),
                  "dominantType", "dominantType", 7);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m"), "resolved",
                  "resolved", 7);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_b_emlrt_marshallOut(1363739054U),
                  "fileTimeLo", "fileTimeLo", 7);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_b_emlrt_marshallOut(0U),
                  "fileTimeHi", "fileTimeHi", 7);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_b_emlrt_marshallOut(0U),
                  "mFileTimeLo", "mFileTimeLo", 7);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_b_emlrt_marshallOut(0U),
                  "mFileTimeHi", "mFileTimeHi", 7);
  sf_mex_assign(&c3_7vqb7o7CaUJzbPKhFMyx3F_rhs7, sf_mex_createcellmatrix(0, 1),
                false);
  sf_mex_assign(&c3_7vqb7o7CaUJzbPKhFMyx3F_lhs7, sf_mex_createcellmatrix(0, 1),
                false);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info, sf_mex_duplicatearraysafe
                  (&c3_7vqb7o7CaUJzbPKhFMyx3F_rhs7), "rhs", "rhs", 7);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info, sf_mex_duplicatearraysafe
                  (&c3_7vqb7o7CaUJzbPKhFMyx3F_lhs7), "lhs", "lhs", 7);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m"), "context",
                  "context", 8);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 8);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_emlrt_marshallOut("double"),
                  "dominantType", "dominantType", 8);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 8);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_b_emlrt_marshallOut(1395957056U),
                  "fileTimeLo", "fileTimeLo", 8);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_b_emlrt_marshallOut(0U),
                  "fileTimeHi", "fileTimeHi", 8);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_b_emlrt_marshallOut(0U),
                  "mFileTimeLo", "mFileTimeLo", 8);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_b_emlrt_marshallOut(0U),
                  "mFileTimeHi", "mFileTimeHi", 8);
  sf_mex_assign(&c3_7vqb7o7CaUJzbPKhFMyx3F_rhs8, sf_mex_createcellmatrix(0, 1),
                false);
  sf_mex_assign(&c3_7vqb7o7CaUJzbPKhFMyx3F_lhs8, sf_mex_createcellmatrix(0, 1),
                false);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info, sf_mex_duplicatearraysafe
                  (&c3_7vqb7o7CaUJzbPKhFMyx3F_rhs8), "rhs", "rhs", 8);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info, sf_mex_duplicatearraysafe
                  (&c3_7vqb7o7CaUJzbPKhFMyx3F_lhs8), "lhs", "lhs", 8);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m"), "context",
                  "context", 9);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_emlrt_marshallOut("eml_scalar_floor"),
                  "name", "name", 9);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_emlrt_marshallOut("double"),
                  "dominantType", "dominantType", 9);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_floor.m"),
                  "resolved", "resolved", 9);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_b_emlrt_marshallOut(1286847526U),
                  "fileTimeLo", "fileTimeLo", 9);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_b_emlrt_marshallOut(0U),
                  "fileTimeHi", "fileTimeHi", 9);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_b_emlrt_marshallOut(0U),
                  "mFileTimeLo", "mFileTimeLo", 9);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_b_emlrt_marshallOut(0U),
                  "mFileTimeHi", "mFileTimeHi", 9);
  sf_mex_assign(&c3_7vqb7o7CaUJzbPKhFMyx3F_rhs9, sf_mex_createcellmatrix(0, 1),
                false);
  sf_mex_assign(&c3_7vqb7o7CaUJzbPKhFMyx3F_lhs9, sf_mex_createcellmatrix(0, 1),
                false);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info, sf_mex_duplicatearraysafe
                  (&c3_7vqb7o7CaUJzbPKhFMyx3F_rhs9), "rhs", "rhs", 9);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info, sf_mex_duplicatearraysafe
                  (&c3_7vqb7o7CaUJzbPKhFMyx3F_lhs9), "lhs", "lhs", 9);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_emlrt_marshallOut(""), "context",
                  "context", 10);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_emlrt_marshallOut("abs"), "name",
                  "name", 10);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_emlrt_marshallOut("double"),
                  "dominantType", "dominantType", 10);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m"), "resolved",
                  "resolved", 10);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_b_emlrt_marshallOut(1363739052U),
                  "fileTimeLo", "fileTimeLo", 10);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_b_emlrt_marshallOut(0U),
                  "fileTimeHi", "fileTimeHi", 10);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_b_emlrt_marshallOut(0U),
                  "mFileTimeLo", "mFileTimeLo", 10);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_b_emlrt_marshallOut(0U),
                  "mFileTimeHi", "mFileTimeHi", 10);
  sf_mex_assign(&c3_7vqb7o7CaUJzbPKhFMyx3F_rhs10, sf_mex_createcellmatrix(0, 1),
                false);
  sf_mex_assign(&c3_7vqb7o7CaUJzbPKhFMyx3F_lhs10, sf_mex_createcellmatrix(0, 1),
                false);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info, sf_mex_duplicatearraysafe
                  (&c3_7vqb7o7CaUJzbPKhFMyx3F_rhs10), "rhs", "rhs", 10);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info, sf_mex_duplicatearraysafe
                  (&c3_7vqb7o7CaUJzbPKhFMyx3F_lhs10), "lhs", "lhs", 10);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m"), "context",
                  "context", 11);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 11);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_emlrt_marshallOut("double"),
                  "dominantType", "dominantType", 11);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 11);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_b_emlrt_marshallOut(1395957056U),
                  "fileTimeLo", "fileTimeLo", 11);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_b_emlrt_marshallOut(0U),
                  "fileTimeHi", "fileTimeHi", 11);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_b_emlrt_marshallOut(0U),
                  "mFileTimeLo", "mFileTimeLo", 11);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_b_emlrt_marshallOut(0U),
                  "mFileTimeHi", "mFileTimeHi", 11);
  sf_mex_assign(&c3_7vqb7o7CaUJzbPKhFMyx3F_rhs11, sf_mex_createcellmatrix(0, 1),
                false);
  sf_mex_assign(&c3_7vqb7o7CaUJzbPKhFMyx3F_lhs11, sf_mex_createcellmatrix(0, 1),
                false);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info, sf_mex_duplicatearraysafe
                  (&c3_7vqb7o7CaUJzbPKhFMyx3F_rhs11), "rhs", "rhs", 11);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info, sf_mex_duplicatearraysafe
                  (&c3_7vqb7o7CaUJzbPKhFMyx3F_lhs11), "lhs", "lhs", 11);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m"), "context",
                  "context", 12);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_emlrt_marshallOut("eml_scalar_abs"),
                  "name", "name", 12);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_emlrt_marshallOut("double"),
                  "dominantType", "dominantType", 12);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_abs.m"),
                  "resolved", "resolved", 12);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_b_emlrt_marshallOut(1286847512U),
                  "fileTimeLo", "fileTimeLo", 12);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_b_emlrt_marshallOut(0U),
                  "fileTimeHi", "fileTimeHi", 12);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_b_emlrt_marshallOut(0U),
                  "mFileTimeLo", "mFileTimeLo", 12);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_b_emlrt_marshallOut(0U),
                  "mFileTimeHi", "mFileTimeHi", 12);
  sf_mex_assign(&c3_7vqb7o7CaUJzbPKhFMyx3F_rhs12, sf_mex_createcellmatrix(0, 1),
                false);
  sf_mex_assign(&c3_7vqb7o7CaUJzbPKhFMyx3F_lhs12, sf_mex_createcellmatrix(0, 1),
                false);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info, sf_mex_duplicatearraysafe
                  (&c3_7vqb7o7CaUJzbPKhFMyx3F_rhs12), "rhs", "rhs", 12);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info, sf_mex_duplicatearraysafe
                  (&c3_7vqb7o7CaUJzbPKhFMyx3F_lhs12), "lhs", "lhs", 12);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_emlrt_marshallOut(""), "context",
                  "context", 13);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_emlrt_marshallOut("trapz"), "name",
                  "name", 13);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_emlrt_marshallOut("double"),
                  "dominantType", "dominantType", 13);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/trapz.m"), "resolved",
                  "resolved", 13);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_b_emlrt_marshallOut(1286847500U),
                  "fileTimeLo", "fileTimeLo", 13);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_b_emlrt_marshallOut(0U),
                  "fileTimeHi", "fileTimeHi", 13);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_b_emlrt_marshallOut(0U),
                  "mFileTimeLo", "mFileTimeLo", 13);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_b_emlrt_marshallOut(0U),
                  "mFileTimeHi", "mFileTimeHi", 13);
  sf_mex_assign(&c3_7vqb7o7CaUJzbPKhFMyx3F_rhs13, sf_mex_createcellmatrix(0, 1),
                false);
  sf_mex_assign(&c3_7vqb7o7CaUJzbPKhFMyx3F_lhs13, sf_mex_createcellmatrix(0, 1),
                false);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info, sf_mex_duplicatearraysafe
                  (&c3_7vqb7o7CaUJzbPKhFMyx3F_rhs13), "rhs", "rhs", 13);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info, sf_mex_duplicatearraysafe
                  (&c3_7vqb7o7CaUJzbPKhFMyx3F_lhs13), "lhs", "lhs", 13);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/trapz.m!trapwork"),
                  "context", "context", 14);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_emlrt_marshallOut("eml_scalar_eg"),
                  "name", "name", 14);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_emlrt_marshallOut("double"),
                  "dominantType", "dominantType", 14);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 14);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_b_emlrt_marshallOut(1376009488U),
                  "fileTimeLo", "fileTimeLo", 14);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_b_emlrt_marshallOut(0U),
                  "fileTimeHi", "fileTimeHi", 14);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_b_emlrt_marshallOut(0U),
                  "mFileTimeLo", "mFileTimeLo", 14);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_b_emlrt_marshallOut(0U),
                  "mFileTimeHi", "mFileTimeHi", 14);
  sf_mex_assign(&c3_7vqb7o7CaUJzbPKhFMyx3F_rhs14, sf_mex_createcellmatrix(0, 1),
                false);
  sf_mex_assign(&c3_7vqb7o7CaUJzbPKhFMyx3F_lhs14, sf_mex_createcellmatrix(0, 1),
                false);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info, sf_mex_duplicatearraysafe
                  (&c3_7vqb7o7CaUJzbPKhFMyx3F_rhs14), "rhs", "rhs", 14);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info, sf_mex_duplicatearraysafe
                  (&c3_7vqb7o7CaUJzbPKhFMyx3F_lhs14), "lhs", "lhs", 14);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "context",
                  "context", 15);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_emlrt_marshallOut(
    "coder.internal.scalarEg"), "name", "name", 15);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_emlrt_marshallOut("double"),
                  "dominantType", "dominantType", 15);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scalarEg.p"),
                  "resolved", "resolved", 15);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_b_emlrt_marshallOut(1410836570U),
                  "fileTimeLo", "fileTimeLo", 15);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_b_emlrt_marshallOut(0U),
                  "fileTimeHi", "fileTimeHi", 15);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_b_emlrt_marshallOut(0U),
                  "mFileTimeLo", "mFileTimeLo", 15);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_b_emlrt_marshallOut(0U),
                  "mFileTimeHi", "mFileTimeHi", 15);
  sf_mex_assign(&c3_7vqb7o7CaUJzbPKhFMyx3F_rhs15, sf_mex_createcellmatrix(0, 1),
                false);
  sf_mex_assign(&c3_7vqb7o7CaUJzbPKhFMyx3F_lhs15, sf_mex_createcellmatrix(0, 1),
                false);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info, sf_mex_duplicatearraysafe
                  (&c3_7vqb7o7CaUJzbPKhFMyx3F_rhs15), "rhs", "rhs", 15);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info, sf_mex_duplicatearraysafe
                  (&c3_7vqb7o7CaUJzbPKhFMyx3F_lhs15), "lhs", "lhs", 15);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/trapz.m!trapwork"),
                  "context", "context", 16);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_emlrt_marshallOut(
    "eml_const_nonsingleton_dim"), "name", "name", 16);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_emlrt_marshallOut("double"),
                  "dominantType", "dominantType", 16);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_const_nonsingleton_dim.m"),
                  "resolved", "resolved", 16);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_b_emlrt_marshallOut(1372611216U),
                  "fileTimeLo", "fileTimeLo", 16);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_b_emlrt_marshallOut(0U),
                  "fileTimeHi", "fileTimeHi", 16);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_b_emlrt_marshallOut(0U),
                  "mFileTimeLo", "mFileTimeLo", 16);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_b_emlrt_marshallOut(0U),
                  "mFileTimeHi", "mFileTimeHi", 16);
  sf_mex_assign(&c3_7vqb7o7CaUJzbPKhFMyx3F_rhs16, sf_mex_createcellmatrix(0, 1),
                false);
  sf_mex_assign(&c3_7vqb7o7CaUJzbPKhFMyx3F_lhs16, sf_mex_createcellmatrix(0, 1),
                false);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info, sf_mex_duplicatearraysafe
                  (&c3_7vqb7o7CaUJzbPKhFMyx3F_rhs16), "rhs", "rhs", 16);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info, sf_mex_duplicatearraysafe
                  (&c3_7vqb7o7CaUJzbPKhFMyx3F_lhs16), "lhs", "lhs", 16);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_const_nonsingleton_dim.m"),
                  "context", "context", 17);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_emlrt_marshallOut(
    "coder.internal.constNonSingletonDim"), "name", "name", 17);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_emlrt_marshallOut("double"),
                  "dominantType", "dominantType", 17);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/constNonSingletonDim.m"),
                  "resolved", "resolved", 17);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_b_emlrt_marshallOut(1372611960U),
                  "fileTimeLo", "fileTimeLo", 17);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_b_emlrt_marshallOut(0U),
                  "fileTimeHi", "fileTimeHi", 17);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_b_emlrt_marshallOut(0U),
                  "mFileTimeLo", "mFileTimeLo", 17);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_b_emlrt_marshallOut(0U),
                  "mFileTimeHi", "mFileTimeHi", 17);
  sf_mex_assign(&c3_7vqb7o7CaUJzbPKhFMyx3F_rhs17, sf_mex_createcellmatrix(0, 1),
                false);
  sf_mex_assign(&c3_7vqb7o7CaUJzbPKhFMyx3F_lhs17, sf_mex_createcellmatrix(0, 1),
                false);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info, sf_mex_duplicatearraysafe
                  (&c3_7vqb7o7CaUJzbPKhFMyx3F_rhs17), "rhs", "rhs", 17);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info, sf_mex_duplicatearraysafe
                  (&c3_7vqb7o7CaUJzbPKhFMyx3F_lhs17), "lhs", "lhs", 17);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/trapz.m!trapwork"),
                  "context", "context", 18);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_emlrt_marshallOut("eml_index_class"),
                  "name", "name", 18);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_emlrt_marshallOut(""),
                  "dominantType", "dominantType", 18);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 18);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_b_emlrt_marshallOut(1323199378U),
                  "fileTimeLo", "fileTimeLo", 18);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_b_emlrt_marshallOut(0U),
                  "fileTimeHi", "fileTimeHi", 18);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_b_emlrt_marshallOut(0U),
                  "mFileTimeLo", "mFileTimeLo", 18);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_b_emlrt_marshallOut(0U),
                  "mFileTimeHi", "mFileTimeHi", 18);
  sf_mex_assign(&c3_7vqb7o7CaUJzbPKhFMyx3F_rhs18, sf_mex_createcellmatrix(0, 1),
                false);
  sf_mex_assign(&c3_7vqb7o7CaUJzbPKhFMyx3F_lhs18, sf_mex_createcellmatrix(0, 1),
                false);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info, sf_mex_duplicatearraysafe
                  (&c3_7vqb7o7CaUJzbPKhFMyx3F_rhs18), "rhs", "rhs", 18);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info, sf_mex_duplicatearraysafe
                  (&c3_7vqb7o7CaUJzbPKhFMyx3F_lhs18), "lhs", "lhs", 18);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/trapz.m!trapwork"),
                  "context", "context", 19);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_emlrt_marshallOut(
    "eml_int_forloop_overflow_check"), "name", "name", 19);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_emlrt_marshallOut(""),
                  "dominantType", "dominantType", 19);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m"),
                  "resolved", "resolved", 19);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_b_emlrt_marshallOut(1397286222U),
                  "fileTimeLo", "fileTimeLo", 19);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_b_emlrt_marshallOut(0U),
                  "fileTimeHi", "fileTimeHi", 19);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_b_emlrt_marshallOut(0U),
                  "mFileTimeLo", "mFileTimeLo", 19);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_b_emlrt_marshallOut(0U),
                  "mFileTimeHi", "mFileTimeHi", 19);
  sf_mex_assign(&c3_7vqb7o7CaUJzbPKhFMyx3F_rhs19, sf_mex_createcellmatrix(0, 1),
                false);
  sf_mex_assign(&c3_7vqb7o7CaUJzbPKhFMyx3F_lhs19, sf_mex_createcellmatrix(0, 1),
                false);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info, sf_mex_duplicatearraysafe
                  (&c3_7vqb7o7CaUJzbPKhFMyx3F_rhs19), "rhs", "rhs", 19);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info, sf_mex_duplicatearraysafe
                  (&c3_7vqb7o7CaUJzbPKhFMyx3F_lhs19), "lhs", "lhs", 19);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m!eml_int_forloop_overflow_check_helper"),
                  "context", "context", 20);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_emlrt_marshallOut("isfi"), "name",
                  "name", 20);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_emlrt_marshallOut(
    "coder.internal.indexInt"), "dominantType", "dominantType", 20);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/isfi.m"), "resolved",
                  "resolved", 20);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_b_emlrt_marshallOut(1346539158U),
                  "fileTimeLo", "fileTimeLo", 20);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_b_emlrt_marshallOut(0U),
                  "fileTimeHi", "fileTimeHi", 20);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_b_emlrt_marshallOut(0U),
                  "mFileTimeLo", "mFileTimeLo", 20);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_b_emlrt_marshallOut(0U),
                  "mFileTimeHi", "mFileTimeHi", 20);
  sf_mex_assign(&c3_7vqb7o7CaUJzbPKhFMyx3F_rhs20, sf_mex_createcellmatrix(0, 1),
                false);
  sf_mex_assign(&c3_7vqb7o7CaUJzbPKhFMyx3F_lhs20, sf_mex_createcellmatrix(0, 1),
                false);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info, sf_mex_duplicatearraysafe
                  (&c3_7vqb7o7CaUJzbPKhFMyx3F_rhs20), "rhs", "rhs", 20);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info, sf_mex_duplicatearraysafe
                  (&c3_7vqb7o7CaUJzbPKhFMyx3F_lhs20), "lhs", "lhs", 20);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/isfi.m"), "context",
                  "context", 21);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_emlrt_marshallOut("isnumerictype"),
                  "name", "name", 21);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_emlrt_marshallOut("char"),
                  "dominantType", "dominantType", 21);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/isnumerictype.m"), "resolved",
                  "resolved", 21);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_b_emlrt_marshallOut(1398904398U),
                  "fileTimeLo", "fileTimeLo", 21);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_b_emlrt_marshallOut(0U),
                  "fileTimeHi", "fileTimeHi", 21);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_b_emlrt_marshallOut(0U),
                  "mFileTimeLo", "mFileTimeLo", 21);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_b_emlrt_marshallOut(0U),
                  "mFileTimeHi", "mFileTimeHi", 21);
  sf_mex_assign(&c3_7vqb7o7CaUJzbPKhFMyx3F_rhs21, sf_mex_createcellmatrix(0, 1),
                false);
  sf_mex_assign(&c3_7vqb7o7CaUJzbPKhFMyx3F_lhs21, sf_mex_createcellmatrix(0, 1),
                false);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info, sf_mex_duplicatearraysafe
                  (&c3_7vqb7o7CaUJzbPKhFMyx3F_rhs21), "rhs", "rhs", 21);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info, sf_mex_duplicatearraysafe
                  (&c3_7vqb7o7CaUJzbPKhFMyx3F_lhs21), "lhs", "lhs", 21);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m!eml_int_forloop_overflow_check_helper"),
                  "context", "context", 22);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_emlrt_marshallOut("intmax"), "name",
                  "name", 22);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_emlrt_marshallOut("char"),
                  "dominantType", "dominantType", 22);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m"), "resolved",
                  "resolved", 22);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_b_emlrt_marshallOut(1362290682U),
                  "fileTimeLo", "fileTimeLo", 22);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_b_emlrt_marshallOut(0U),
                  "fileTimeHi", "fileTimeHi", 22);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_b_emlrt_marshallOut(0U),
                  "mFileTimeLo", "mFileTimeLo", 22);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_b_emlrt_marshallOut(0U),
                  "mFileTimeHi", "mFileTimeHi", 22);
  sf_mex_assign(&c3_7vqb7o7CaUJzbPKhFMyx3F_rhs22, sf_mex_createcellmatrix(0, 1),
                false);
  sf_mex_assign(&c3_7vqb7o7CaUJzbPKhFMyx3F_lhs22, sf_mex_createcellmatrix(0, 1),
                false);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info, sf_mex_duplicatearraysafe
                  (&c3_7vqb7o7CaUJzbPKhFMyx3F_rhs22), "rhs", "rhs", 22);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info, sf_mex_duplicatearraysafe
                  (&c3_7vqb7o7CaUJzbPKhFMyx3F_lhs22), "lhs", "lhs", 22);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m"), "context",
                  "context", 23);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_emlrt_marshallOut(
    "eml_switch_helper"), "name", "name", 23);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_emlrt_marshallOut(""),
                  "dominantType", "dominantType", 23);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_switch_helper.m"),
                  "resolved", "resolved", 23);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_b_emlrt_marshallOut(1393359658U),
                  "fileTimeLo", "fileTimeLo", 23);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_b_emlrt_marshallOut(0U),
                  "fileTimeHi", "fileTimeHi", 23);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_b_emlrt_marshallOut(0U),
                  "mFileTimeLo", "mFileTimeLo", 23);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_b_emlrt_marshallOut(0U),
                  "mFileTimeHi", "mFileTimeHi", 23);
  sf_mex_assign(&c3_7vqb7o7CaUJzbPKhFMyx3F_rhs23, sf_mex_createcellmatrix(0, 1),
                false);
  sf_mex_assign(&c3_7vqb7o7CaUJzbPKhFMyx3F_lhs23, sf_mex_createcellmatrix(0, 1),
                false);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info, sf_mex_duplicatearraysafe
                  (&c3_7vqb7o7CaUJzbPKhFMyx3F_rhs23), "rhs", "rhs", 23);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info, sf_mex_duplicatearraysafe
                  (&c3_7vqb7o7CaUJzbPKhFMyx3F_lhs23), "lhs", "lhs", 23);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m!eml_int_forloop_overflow_check_helper"),
                  "context", "context", 24);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_emlrt_marshallOut("intmin"), "name",
                  "name", 24);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_emlrt_marshallOut("char"),
                  "dominantType", "dominantType", 24);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmin.m"), "resolved",
                  "resolved", 24);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_b_emlrt_marshallOut(1362290682U),
                  "fileTimeLo", "fileTimeLo", 24);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_b_emlrt_marshallOut(0U),
                  "fileTimeHi", "fileTimeHi", 24);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_b_emlrt_marshallOut(0U),
                  "mFileTimeLo", "mFileTimeLo", 24);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_b_emlrt_marshallOut(0U),
                  "mFileTimeHi", "mFileTimeHi", 24);
  sf_mex_assign(&c3_7vqb7o7CaUJzbPKhFMyx3F_rhs24, sf_mex_createcellmatrix(0, 1),
                false);
  sf_mex_assign(&c3_7vqb7o7CaUJzbPKhFMyx3F_lhs24, sf_mex_createcellmatrix(0, 1),
                false);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info, sf_mex_duplicatearraysafe
                  (&c3_7vqb7o7CaUJzbPKhFMyx3F_rhs24), "rhs", "rhs", 24);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info, sf_mex_duplicatearraysafe
                  (&c3_7vqb7o7CaUJzbPKhFMyx3F_lhs24), "lhs", "lhs", 24);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmin.m"), "context",
                  "context", 25);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_emlrt_marshallOut(
    "eml_switch_helper"), "name", "name", 25);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_emlrt_marshallOut(""),
                  "dominantType", "dominantType", 25);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_switch_helper.m"),
                  "resolved", "resolved", 25);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_b_emlrt_marshallOut(1393359658U),
                  "fileTimeLo", "fileTimeLo", 25);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_b_emlrt_marshallOut(0U),
                  "fileTimeHi", "fileTimeHi", 25);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_b_emlrt_marshallOut(0U),
                  "mFileTimeLo", "mFileTimeLo", 25);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_b_emlrt_marshallOut(0U),
                  "mFileTimeHi", "mFileTimeHi", 25);
  sf_mex_assign(&c3_7vqb7o7CaUJzbPKhFMyx3F_rhs25, sf_mex_createcellmatrix(0, 1),
                false);
  sf_mex_assign(&c3_7vqb7o7CaUJzbPKhFMyx3F_lhs25, sf_mex_createcellmatrix(0, 1),
                false);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info, sf_mex_duplicatearraysafe
                  (&c3_7vqb7o7CaUJzbPKhFMyx3F_rhs25), "rhs", "rhs", 25);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info, sf_mex_duplicatearraysafe
                  (&c3_7vqb7o7CaUJzbPKhFMyx3F_lhs25), "lhs", "lhs", 25);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/trapz.m!trapwork"),
                  "context", "context", 26);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_emlrt_marshallOut(
    "eml_matrix_vstride"), "name", "name", 26);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_emlrt_marshallOut("double"),
                  "dominantType", "dominantType", 26);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_matrix_vstride.m"),
                  "resolved", "resolved", 26);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_b_emlrt_marshallOut(1360311150U),
                  "fileTimeLo", "fileTimeLo", 26);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_b_emlrt_marshallOut(0U),
                  "fileTimeHi", "fileTimeHi", 26);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_b_emlrt_marshallOut(0U),
                  "mFileTimeLo", "mFileTimeLo", 26);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_b_emlrt_marshallOut(0U),
                  "mFileTimeHi", "mFileTimeHi", 26);
  sf_mex_assign(&c3_7vqb7o7CaUJzbPKhFMyx3F_rhs26, sf_mex_createcellmatrix(0, 1),
                false);
  sf_mex_assign(&c3_7vqb7o7CaUJzbPKhFMyx3F_lhs26, sf_mex_createcellmatrix(0, 1),
                false);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info, sf_mex_duplicatearraysafe
                  (&c3_7vqb7o7CaUJzbPKhFMyx3F_rhs26), "rhs", "rhs", 26);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info, sf_mex_duplicatearraysafe
                  (&c3_7vqb7o7CaUJzbPKhFMyx3F_lhs26), "lhs", "lhs", 26);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_matrix_vstride.m"),
                  "context", "context", 27);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_emlrt_marshallOut(
    "coder.internal.prodsize"), "name", "name", 27);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_emlrt_marshallOut("double"),
                  "dominantType", "dominantType", 27);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/prodsize.m"),
                  "resolved", "resolved", 27);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_b_emlrt_marshallOut(1360311388U),
                  "fileTimeLo", "fileTimeLo", 27);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_b_emlrt_marshallOut(0U),
                  "fileTimeHi", "fileTimeHi", 27);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_b_emlrt_marshallOut(0U),
                  "mFileTimeLo", "mFileTimeLo", 27);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_b_emlrt_marshallOut(0U),
                  "mFileTimeHi", "mFileTimeHi", 27);
  sf_mex_assign(&c3_7vqb7o7CaUJzbPKhFMyx3F_rhs27, sf_mex_createcellmatrix(0, 1),
                false);
  sf_mex_assign(&c3_7vqb7o7CaUJzbPKhFMyx3F_lhs27, sf_mex_createcellmatrix(0, 1),
                false);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info, sf_mex_duplicatearraysafe
                  (&c3_7vqb7o7CaUJzbPKhFMyx3F_rhs27), "rhs", "rhs", 27);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info, sf_mex_duplicatearraysafe
                  (&c3_7vqb7o7CaUJzbPKhFMyx3F_lhs27), "lhs", "lhs", 27);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/trapz.m!trapwork"),
                  "context", "context", 28);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_emlrt_marshallOut(
    "eml_matrix_npages"), "name", "name", 28);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_emlrt_marshallOut("double"),
                  "dominantType", "dominantType", 28);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_matrix_npages.m"),
                  "resolved", "resolved", 28);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_b_emlrt_marshallOut(1360311150U),
                  "fileTimeLo", "fileTimeLo", 28);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_b_emlrt_marshallOut(0U),
                  "fileTimeHi", "fileTimeHi", 28);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_b_emlrt_marshallOut(0U),
                  "mFileTimeLo", "mFileTimeLo", 28);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_b_emlrt_marshallOut(0U),
                  "mFileTimeHi", "mFileTimeHi", 28);
  sf_mex_assign(&c3_7vqb7o7CaUJzbPKhFMyx3F_rhs28, sf_mex_createcellmatrix(0, 1),
                false);
  sf_mex_assign(&c3_7vqb7o7CaUJzbPKhFMyx3F_lhs28, sf_mex_createcellmatrix(0, 1),
                false);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info, sf_mex_duplicatearraysafe
                  (&c3_7vqb7o7CaUJzbPKhFMyx3F_rhs28), "rhs", "rhs", 28);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info, sf_mex_duplicatearraysafe
                  (&c3_7vqb7o7CaUJzbPKhFMyx3F_lhs28), "lhs", "lhs", 28);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_matrix_npages.m"),
                  "context", "context", 29);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_emlrt_marshallOut(
    "coder.internal.prodsize"), "name", "name", 29);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_emlrt_marshallOut("double"),
                  "dominantType", "dominantType", 29);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/prodsize.m"),
                  "resolved", "resolved", 29);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_b_emlrt_marshallOut(1360311388U),
                  "fileTimeLo", "fileTimeLo", 29);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_b_emlrt_marshallOut(0U),
                  "fileTimeHi", "fileTimeHi", 29);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_b_emlrt_marshallOut(0U),
                  "mFileTimeLo", "mFileTimeLo", 29);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_b_emlrt_marshallOut(0U),
                  "mFileTimeHi", "mFileTimeHi", 29);
  sf_mex_assign(&c3_7vqb7o7CaUJzbPKhFMyx3F_rhs29, sf_mex_createcellmatrix(0, 1),
                false);
  sf_mex_assign(&c3_7vqb7o7CaUJzbPKhFMyx3F_lhs29, sf_mex_createcellmatrix(0, 1),
                false);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info, sf_mex_duplicatearraysafe
                  (&c3_7vqb7o7CaUJzbPKhFMyx3F_rhs29), "rhs", "rhs", 29);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info, sf_mex_duplicatearraysafe
                  (&c3_7vqb7o7CaUJzbPKhFMyx3F_lhs29), "lhs", "lhs", 29);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/trapz.m!trapwork"),
                  "context", "context", 30);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_emlrt_marshallOut("eml_index_plus"),
                  "name", "name", 30);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_emlrt_marshallOut("double"),
                  "dominantType", "dominantType", 30);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m"),
                  "resolved", "resolved", 30);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_b_emlrt_marshallOut(1372611216U),
                  "fileTimeLo", "fileTimeLo", 30);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_b_emlrt_marshallOut(0U),
                  "fileTimeHi", "fileTimeHi", 30);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_b_emlrt_marshallOut(0U),
                  "mFileTimeLo", "mFileTimeLo", 30);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_b_emlrt_marshallOut(0U),
                  "mFileTimeHi", "mFileTimeHi", 30);
  sf_mex_assign(&c3_7vqb7o7CaUJzbPKhFMyx3F_rhs30, sf_mex_createcellmatrix(0, 1),
                false);
  sf_mex_assign(&c3_7vqb7o7CaUJzbPKhFMyx3F_lhs30, sf_mex_createcellmatrix(0, 1),
                false);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info, sf_mex_duplicatearraysafe
                  (&c3_7vqb7o7CaUJzbPKhFMyx3F_rhs30), "rhs", "rhs", 30);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info, sf_mex_duplicatearraysafe
                  (&c3_7vqb7o7CaUJzbPKhFMyx3F_lhs30), "lhs", "lhs", 30);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m"), "context",
                  "context", 31);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_emlrt_marshallOut(
    "coder.internal.indexPlus"), "name", "name", 31);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_emlrt_marshallOut("double"),
                  "dominantType", "dominantType", 31);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexPlus.m"),
                  "resolved", "resolved", 31);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_b_emlrt_marshallOut(1372611960U),
                  "fileTimeLo", "fileTimeLo", 31);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_b_emlrt_marshallOut(0U),
                  "fileTimeHi", "fileTimeHi", 31);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_b_emlrt_marshallOut(0U),
                  "mFileTimeLo", "mFileTimeLo", 31);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_b_emlrt_marshallOut(0U),
                  "mFileTimeHi", "mFileTimeHi", 31);
  sf_mex_assign(&c3_7vqb7o7CaUJzbPKhFMyx3F_rhs31, sf_mex_createcellmatrix(0, 1),
                false);
  sf_mex_assign(&c3_7vqb7o7CaUJzbPKhFMyx3F_lhs31, sf_mex_createcellmatrix(0, 1),
                false);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info, sf_mex_duplicatearraysafe
                  (&c3_7vqb7o7CaUJzbPKhFMyx3F_rhs31), "rhs", "rhs", 31);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info, sf_mex_duplicatearraysafe
                  (&c3_7vqb7o7CaUJzbPKhFMyx3F_lhs31), "lhs", "lhs", 31);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/trapz.m!trapwork"),
                  "context", "context", 32);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_emlrt_marshallOut("eml_index_plus"),
                  "name", "name", 32);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_emlrt_marshallOut(
    "coder.internal.indexInt"), "dominantType", "dominantType", 32);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m"),
                  "resolved", "resolved", 32);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_b_emlrt_marshallOut(1372611216U),
                  "fileTimeLo", "fileTimeLo", 32);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_b_emlrt_marshallOut(0U),
                  "fileTimeHi", "fileTimeHi", 32);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_b_emlrt_marshallOut(0U),
                  "mFileTimeLo", "mFileTimeLo", 32);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_b_emlrt_marshallOut(0U),
                  "mFileTimeHi", "mFileTimeHi", 32);
  sf_mex_assign(&c3_7vqb7o7CaUJzbPKhFMyx3F_rhs32, sf_mex_createcellmatrix(0, 1),
                false);
  sf_mex_assign(&c3_7vqb7o7CaUJzbPKhFMyx3F_lhs32, sf_mex_createcellmatrix(0, 1),
                false);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info, sf_mex_duplicatearraysafe
                  (&c3_7vqb7o7CaUJzbPKhFMyx3F_rhs32), "rhs", "rhs", 32);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info, sf_mex_duplicatearraysafe
                  (&c3_7vqb7o7CaUJzbPKhFMyx3F_lhs32), "lhs", "lhs", 32);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m"), "context",
                  "context", 33);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_emlrt_marshallOut(
    "coder.internal.indexPlus"), "name", "name", 33);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_emlrt_marshallOut(
    "coder.internal.indexInt"), "dominantType", "dominantType", 33);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexPlus.m"),
                  "resolved", "resolved", 33);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_b_emlrt_marshallOut(1372611960U),
                  "fileTimeLo", "fileTimeLo", 33);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_b_emlrt_marshallOut(0U),
                  "fileTimeHi", "fileTimeHi", 33);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_b_emlrt_marshallOut(0U),
                  "mFileTimeLo", "mFileTimeLo", 33);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_b_emlrt_marshallOut(0U),
                  "mFileTimeHi", "mFileTimeHi", 33);
  sf_mex_assign(&c3_7vqb7o7CaUJzbPKhFMyx3F_rhs33, sf_mex_createcellmatrix(0, 1),
                false);
  sf_mex_assign(&c3_7vqb7o7CaUJzbPKhFMyx3F_lhs33, sf_mex_createcellmatrix(0, 1),
                false);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info, sf_mex_duplicatearraysafe
                  (&c3_7vqb7o7CaUJzbPKhFMyx3F_rhs33), "rhs", "rhs", 33);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info, sf_mex_duplicatearraysafe
                  (&c3_7vqb7o7CaUJzbPKhFMyx3F_lhs33), "lhs", "lhs", 33);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/trapz.m!trapwork"),
                  "context", "context", 34);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_emlrt_marshallOut("eml_div"), "name",
                  "name", 34);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_emlrt_marshallOut("double"),
                  "dominantType", "dominantType", 34);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m"), "resolved",
                  "resolved", 34);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_b_emlrt_marshallOut(1386452752U),
                  "fileTimeLo", "fileTimeLo", 34);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_b_emlrt_marshallOut(0U),
                  "fileTimeHi", "fileTimeHi", 34);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_b_emlrt_marshallOut(0U),
                  "mFileTimeLo", "mFileTimeLo", 34);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_b_emlrt_marshallOut(0U),
                  "mFileTimeHi", "mFileTimeHi", 34);
  sf_mex_assign(&c3_7vqb7o7CaUJzbPKhFMyx3F_rhs34, sf_mex_createcellmatrix(0, 1),
                false);
  sf_mex_assign(&c3_7vqb7o7CaUJzbPKhFMyx3F_lhs34, sf_mex_createcellmatrix(0, 1),
                false);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info, sf_mex_duplicatearraysafe
                  (&c3_7vqb7o7CaUJzbPKhFMyx3F_rhs34), "rhs", "rhs", 34);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info, sf_mex_duplicatearraysafe
                  (&c3_7vqb7o7CaUJzbPKhFMyx3F_lhs34), "lhs", "lhs", 34);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_emlrt_marshallOut(""), "context",
                  "context", 35);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_emlrt_marshallOut("sum"), "name",
                  "name", 35);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_emlrt_marshallOut("double"),
                  "dominantType", "dominantType", 35);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/sum.m"), "resolved",
                  "resolved", 35);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_b_emlrt_marshallOut(1395955506U),
                  "fileTimeLo", "fileTimeLo", 35);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_b_emlrt_marshallOut(0U),
                  "fileTimeHi", "fileTimeHi", 35);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_b_emlrt_marshallOut(0U),
                  "mFileTimeLo", "mFileTimeLo", 35);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_b_emlrt_marshallOut(0U),
                  "mFileTimeHi", "mFileTimeHi", 35);
  sf_mex_assign(&c3_7vqb7o7CaUJzbPKhFMyx3F_rhs35, sf_mex_createcellmatrix(0, 1),
                false);
  sf_mex_assign(&c3_7vqb7o7CaUJzbPKhFMyx3F_lhs35, sf_mex_createcellmatrix(0, 1),
                false);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info, sf_mex_duplicatearraysafe
                  (&c3_7vqb7o7CaUJzbPKhFMyx3F_rhs35), "rhs", "rhs", 35);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info, sf_mex_duplicatearraysafe
                  (&c3_7vqb7o7CaUJzbPKhFMyx3F_lhs35), "lhs", "lhs", 35);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/sum.m"), "context",
                  "context", 36);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_emlrt_marshallOut(
    "coder.internal.assert"), "name", "name", 36);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_emlrt_marshallOut("char"),
                  "dominantType", "dominantType", 36);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/assert.m"),
                  "resolved", "resolved", 36);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_b_emlrt_marshallOut(1389746574U),
                  "fileTimeLo", "fileTimeLo", 36);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_b_emlrt_marshallOut(0U),
                  "fileTimeHi", "fileTimeHi", 36);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_b_emlrt_marshallOut(0U),
                  "mFileTimeLo", "mFileTimeLo", 36);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_b_emlrt_marshallOut(0U),
                  "mFileTimeHi", "mFileTimeHi", 36);
  sf_mex_assign(&c3_7vqb7o7CaUJzbPKhFMyx3F_rhs36, sf_mex_createcellmatrix(0, 1),
                false);
  sf_mex_assign(&c3_7vqb7o7CaUJzbPKhFMyx3F_lhs36, sf_mex_createcellmatrix(0, 1),
                false);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info, sf_mex_duplicatearraysafe
                  (&c3_7vqb7o7CaUJzbPKhFMyx3F_rhs36), "rhs", "rhs", 36);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info, sf_mex_duplicatearraysafe
                  (&c3_7vqb7o7CaUJzbPKhFMyx3F_lhs36), "lhs", "lhs", 36);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/sum.m"), "context",
                  "context", 37);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_emlrt_marshallOut("sumprod"), "name",
                  "name", 37);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_emlrt_marshallOut("char"),
                  "dominantType", "dominantType", 37);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_emlrt_marshallOut(
    "[ILXPE]$matlabroot$/toolbox/eml/lib/matlab/datafun/private/sumprod.m"),
                  "resolved", "resolved", 37);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_b_emlrt_marshallOut(1395955502U),
                  "fileTimeLo", "fileTimeLo", 37);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_b_emlrt_marshallOut(0U),
                  "fileTimeHi", "fileTimeHi", 37);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_b_emlrt_marshallOut(0U),
                  "mFileTimeLo", "mFileTimeLo", 37);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_b_emlrt_marshallOut(0U),
                  "mFileTimeHi", "mFileTimeHi", 37);
  sf_mex_assign(&c3_7vqb7o7CaUJzbPKhFMyx3F_rhs37, sf_mex_createcellmatrix(0, 1),
                false);
  sf_mex_assign(&c3_7vqb7o7CaUJzbPKhFMyx3F_lhs37, sf_mex_createcellmatrix(0, 1),
                false);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info, sf_mex_duplicatearraysafe
                  (&c3_7vqb7o7CaUJzbPKhFMyx3F_rhs37), "rhs", "rhs", 37);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info, sf_mex_duplicatearraysafe
                  (&c3_7vqb7o7CaUJzbPKhFMyx3F_lhs37), "lhs", "lhs", 37);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_emlrt_marshallOut(
    "[ILXPE]$matlabroot$/toolbox/eml/lib/matlab/datafun/private/sumprod.m"),
                  "context", "context", 38);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_emlrt_marshallOut(
    "coder.internal.assert"), "name", "name", 38);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_emlrt_marshallOut("char"),
                  "dominantType", "dominantType", 38);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/assert.m"),
                  "resolved", "resolved", 38);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_b_emlrt_marshallOut(1389746574U),
                  "fileTimeLo", "fileTimeLo", 38);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_b_emlrt_marshallOut(0U),
                  "fileTimeHi", "fileTimeHi", 38);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_b_emlrt_marshallOut(0U),
                  "mFileTimeLo", "mFileTimeLo", 38);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_b_emlrt_marshallOut(0U),
                  "mFileTimeHi", "mFileTimeHi", 38);
  sf_mex_assign(&c3_7vqb7o7CaUJzbPKhFMyx3F_rhs38, sf_mex_createcellmatrix(0, 1),
                false);
  sf_mex_assign(&c3_7vqb7o7CaUJzbPKhFMyx3F_lhs38, sf_mex_createcellmatrix(0, 1),
                false);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info, sf_mex_duplicatearraysafe
                  (&c3_7vqb7o7CaUJzbPKhFMyx3F_rhs38), "rhs", "rhs", 38);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info, sf_mex_duplicatearraysafe
                  (&c3_7vqb7o7CaUJzbPKhFMyx3F_lhs38), "lhs", "lhs", 38);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_emlrt_marshallOut(
    "[ILXPE]$matlabroot$/toolbox/eml/lib/matlab/datafun/private/sumprod.m"),
                  "context", "context", 39);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 39);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_emlrt_marshallOut("double"),
                  "dominantType", "dominantType", 39);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 39);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_b_emlrt_marshallOut(1395957056U),
                  "fileTimeLo", "fileTimeLo", 39);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_b_emlrt_marshallOut(0U),
                  "fileTimeHi", "fileTimeHi", 39);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_b_emlrt_marshallOut(0U),
                  "mFileTimeLo", "mFileTimeLo", 39);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_b_emlrt_marshallOut(0U),
                  "mFileTimeHi", "mFileTimeHi", 39);
  sf_mex_assign(&c3_7vqb7o7CaUJzbPKhFMyx3F_rhs39, sf_mex_createcellmatrix(0, 1),
                false);
  sf_mex_assign(&c3_7vqb7o7CaUJzbPKhFMyx3F_lhs39, sf_mex_createcellmatrix(0, 1),
                false);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info, sf_mex_duplicatearraysafe
                  (&c3_7vqb7o7CaUJzbPKhFMyx3F_rhs39), "rhs", "rhs", 39);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info, sf_mex_duplicatearraysafe
                  (&c3_7vqb7o7CaUJzbPKhFMyx3F_lhs39), "lhs", "lhs", 39);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_emlrt_marshallOut(
    "[ILXPE]$matlabroot$/toolbox/eml/lib/matlab/datafun/private/sumprod.m"),
                  "context", "context", 40);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_emlrt_marshallOut(
    "process_sumprod_inputs"), "name", "name", 40);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_emlrt_marshallOut("double"),
                  "dominantType", "dominantType", 40);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_emlrt_marshallOut(
    "[ILXPE]$matlabroot$/toolbox/eml/lib/matlab/datafun/private/process_sumprod_inputs.m"),
                  "resolved", "resolved", 40);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_b_emlrt_marshallOut(1395955502U),
                  "fileTimeLo", "fileTimeLo", 40);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_b_emlrt_marshallOut(0U),
                  "fileTimeHi", "fileTimeHi", 40);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_b_emlrt_marshallOut(0U),
                  "mFileTimeLo", "mFileTimeLo", 40);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_b_emlrt_marshallOut(0U),
                  "mFileTimeHi", "mFileTimeHi", 40);
  sf_mex_assign(&c3_7vqb7o7CaUJzbPKhFMyx3F_rhs40, sf_mex_createcellmatrix(0, 1),
                false);
  sf_mex_assign(&c3_7vqb7o7CaUJzbPKhFMyx3F_lhs40, sf_mex_createcellmatrix(0, 1),
                false);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info, sf_mex_duplicatearraysafe
                  (&c3_7vqb7o7CaUJzbPKhFMyx3F_rhs40), "rhs", "rhs", 40);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info, sf_mex_duplicatearraysafe
                  (&c3_7vqb7o7CaUJzbPKhFMyx3F_lhs40), "lhs", "lhs", 40);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_emlrt_marshallOut(
    "[ILXPE]$matlabroot$/toolbox/eml/lib/matlab/datafun/private/process_sumprod_inputs.m"),
                  "context", "context", 41);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_emlrt_marshallOut(
    "coder.internal.narginchk"), "name", "name", 41);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_emlrt_marshallOut(""),
                  "dominantType", "dominantType", 41);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/narginchk.m"),
                  "resolved", "resolved", 41);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_b_emlrt_marshallOut(1363739758U),
                  "fileTimeLo", "fileTimeLo", 41);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_b_emlrt_marshallOut(0U),
                  "fileTimeHi", "fileTimeHi", 41);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_b_emlrt_marshallOut(0U),
                  "mFileTimeLo", "mFileTimeLo", 41);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_b_emlrt_marshallOut(0U),
                  "mFileTimeHi", "mFileTimeHi", 41);
  sf_mex_assign(&c3_7vqb7o7CaUJzbPKhFMyx3F_rhs41, sf_mex_createcellmatrix(0, 1),
                false);
  sf_mex_assign(&c3_7vqb7o7CaUJzbPKhFMyx3F_lhs41, sf_mex_createcellmatrix(0, 1),
                false);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info, sf_mex_duplicatearraysafe
                  (&c3_7vqb7o7CaUJzbPKhFMyx3F_rhs41), "rhs", "rhs", 41);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info, sf_mex_duplicatearraysafe
                  (&c3_7vqb7o7CaUJzbPKhFMyx3F_lhs41), "lhs", "lhs", 41);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/narginchk.m"),
                  "context", "context", 42);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_emlrt_marshallOut("floor"), "name",
                  "name", 42);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_emlrt_marshallOut("double"),
                  "dominantType", "dominantType", 42);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m"), "resolved",
                  "resolved", 42);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_b_emlrt_marshallOut(1363739054U),
                  "fileTimeLo", "fileTimeLo", 42);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_b_emlrt_marshallOut(0U),
                  "fileTimeHi", "fileTimeHi", 42);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_b_emlrt_marshallOut(0U),
                  "mFileTimeLo", "mFileTimeLo", 42);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_b_emlrt_marshallOut(0U),
                  "mFileTimeHi", "mFileTimeHi", 42);
  sf_mex_assign(&c3_7vqb7o7CaUJzbPKhFMyx3F_rhs42, sf_mex_createcellmatrix(0, 1),
                false);
  sf_mex_assign(&c3_7vqb7o7CaUJzbPKhFMyx3F_lhs42, sf_mex_createcellmatrix(0, 1),
                false);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info, sf_mex_duplicatearraysafe
                  (&c3_7vqb7o7CaUJzbPKhFMyx3F_rhs42), "rhs", "rhs", 42);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info, sf_mex_duplicatearraysafe
                  (&c3_7vqb7o7CaUJzbPKhFMyx3F_lhs42), "lhs", "lhs", 42);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/narginchk.m"),
                  "context", "context", 43);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_emlrt_marshallOut(
    "coder.internal.assert"), "name", "name", 43);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_emlrt_marshallOut("char"),
                  "dominantType", "dominantType", 43);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/assert.m"),
                  "resolved", "resolved", 43);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_b_emlrt_marshallOut(1389746574U),
                  "fileTimeLo", "fileTimeLo", 43);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_b_emlrt_marshallOut(0U),
                  "fileTimeHi", "fileTimeHi", 43);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_b_emlrt_marshallOut(0U),
                  "mFileTimeLo", "mFileTimeLo", 43);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_b_emlrt_marshallOut(0U),
                  "mFileTimeHi", "mFileTimeHi", 43);
  sf_mex_assign(&c3_7vqb7o7CaUJzbPKhFMyx3F_rhs43, sf_mex_createcellmatrix(0, 1),
                false);
  sf_mex_assign(&c3_7vqb7o7CaUJzbPKhFMyx3F_lhs43, sf_mex_createcellmatrix(0, 1),
                false);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info, sf_mex_duplicatearraysafe
                  (&c3_7vqb7o7CaUJzbPKhFMyx3F_rhs43), "rhs", "rhs", 43);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info, sf_mex_duplicatearraysafe
                  (&c3_7vqb7o7CaUJzbPKhFMyx3F_lhs43), "lhs", "lhs", 43);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_emlrt_marshallOut(
    "[ILXPE]$matlabroot$/toolbox/eml/lib/matlab/datafun/private/process_sumprod_inputs.m"),
                  "context", "context", 44);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_emlrt_marshallOut(
    "coder.internal.constNonSingletonDim"), "name", "name", 44);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_emlrt_marshallOut("double"),
                  "dominantType", "dominantType", 44);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/constNonSingletonDim.m"),
                  "resolved", "resolved", 44);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_b_emlrt_marshallOut(1372611960U),
                  "fileTimeLo", "fileTimeLo", 44);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_b_emlrt_marshallOut(0U),
                  "fileTimeHi", "fileTimeHi", 44);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_b_emlrt_marshallOut(0U),
                  "mFileTimeLo", "mFileTimeLo", 44);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_b_emlrt_marshallOut(0U),
                  "mFileTimeHi", "mFileTimeHi", 44);
  sf_mex_assign(&c3_7vqb7o7CaUJzbPKhFMyx3F_rhs44, sf_mex_createcellmatrix(0, 1),
                false);
  sf_mex_assign(&c3_7vqb7o7CaUJzbPKhFMyx3F_lhs44, sf_mex_createcellmatrix(0, 1),
                false);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info, sf_mex_duplicatearraysafe
                  (&c3_7vqb7o7CaUJzbPKhFMyx3F_rhs44), "rhs", "rhs", 44);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info, sf_mex_duplicatearraysafe
                  (&c3_7vqb7o7CaUJzbPKhFMyx3F_lhs44), "lhs", "lhs", 44);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_emlrt_marshallOut(
    "[ILXPE]$matlabroot$/toolbox/eml/lib/matlab/datafun/private/process_sumprod_inputs.m"),
                  "context", "context", 45);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_emlrt_marshallOut(
    "coder.internal.assert"), "name", "name", 45);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_emlrt_marshallOut("char"),
                  "dominantType", "dominantType", 45);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/assert.m"),
                  "resolved", "resolved", 45);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_b_emlrt_marshallOut(1389746574U),
                  "fileTimeLo", "fileTimeLo", 45);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_b_emlrt_marshallOut(0U),
                  "fileTimeHi", "fileTimeHi", 45);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_b_emlrt_marshallOut(0U),
                  "mFileTimeLo", "mFileTimeLo", 45);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_b_emlrt_marshallOut(0U),
                  "mFileTimeHi", "mFileTimeHi", 45);
  sf_mex_assign(&c3_7vqb7o7CaUJzbPKhFMyx3F_rhs45, sf_mex_createcellmatrix(0, 1),
                false);
  sf_mex_assign(&c3_7vqb7o7CaUJzbPKhFMyx3F_lhs45, sf_mex_createcellmatrix(0, 1),
                false);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info, sf_mex_duplicatearraysafe
                  (&c3_7vqb7o7CaUJzbPKhFMyx3F_rhs45), "rhs", "rhs", 45);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info, sf_mex_duplicatearraysafe
                  (&c3_7vqb7o7CaUJzbPKhFMyx3F_lhs45), "lhs", "lhs", 45);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_emlrt_marshallOut(
    "[ILXPE]$matlabroot$/toolbox/eml/lib/matlab/datafun/private/process_sumprod_inputs.m"),
                  "context", "context", 46);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_emlrt_marshallOut("eml_scalar_eg"),
                  "name", "name", 46);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_emlrt_marshallOut("double"),
                  "dominantType", "dominantType", 46);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 46);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_b_emlrt_marshallOut(1376009488U),
                  "fileTimeLo", "fileTimeLo", 46);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_b_emlrt_marshallOut(0U),
                  "fileTimeHi", "fileTimeHi", 46);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_b_emlrt_marshallOut(0U),
                  "mFileTimeLo", "mFileTimeLo", 46);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_b_emlrt_marshallOut(0U),
                  "mFileTimeHi", "mFileTimeHi", 46);
  sf_mex_assign(&c3_7vqb7o7CaUJzbPKhFMyx3F_rhs46, sf_mex_createcellmatrix(0, 1),
                false);
  sf_mex_assign(&c3_7vqb7o7CaUJzbPKhFMyx3F_lhs46, sf_mex_createcellmatrix(0, 1),
                false);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info, sf_mex_duplicatearraysafe
                  (&c3_7vqb7o7CaUJzbPKhFMyx3F_rhs46), "rhs", "rhs", 46);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info, sf_mex_duplicatearraysafe
                  (&c3_7vqb7o7CaUJzbPKhFMyx3F_lhs46), "lhs", "lhs", 46);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_emlrt_marshallOut(
    "[ILXPE]$matlabroot$/toolbox/eml/lib/matlab/datafun/private/sumprod.m"),
                  "context", "context", 47);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_emlrt_marshallOut("isequal"), "name",
                  "name", 47);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_emlrt_marshallOut("double"),
                  "dominantType", "dominantType", 47);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isequal.m"), "resolved",
                  "resolved", 47);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_b_emlrt_marshallOut(1286847558U),
                  "fileTimeLo", "fileTimeLo", 47);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_b_emlrt_marshallOut(0U),
                  "fileTimeHi", "fileTimeHi", 47);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_b_emlrt_marshallOut(0U),
                  "mFileTimeLo", "mFileTimeLo", 47);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_b_emlrt_marshallOut(0U),
                  "mFileTimeHi", "mFileTimeHi", 47);
  sf_mex_assign(&c3_7vqb7o7CaUJzbPKhFMyx3F_rhs47, sf_mex_createcellmatrix(0, 1),
                false);
  sf_mex_assign(&c3_7vqb7o7CaUJzbPKhFMyx3F_lhs47, sf_mex_createcellmatrix(0, 1),
                false);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info, sf_mex_duplicatearraysafe
                  (&c3_7vqb7o7CaUJzbPKhFMyx3F_rhs47), "rhs", "rhs", 47);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info, sf_mex_duplicatearraysafe
                  (&c3_7vqb7o7CaUJzbPKhFMyx3F_lhs47), "lhs", "lhs", 47);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isequal.m"), "context",
                  "context", 48);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_emlrt_marshallOut("eml_isequal_core"),
                  "name", "name", 48);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_emlrt_marshallOut("double"),
                  "dominantType", "dominantType", 48);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isequal_core.m"),
                  "resolved", "resolved", 48);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_b_emlrt_marshallOut(1286847586U),
                  "fileTimeLo", "fileTimeLo", 48);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_b_emlrt_marshallOut(0U),
                  "fileTimeHi", "fileTimeHi", 48);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_b_emlrt_marshallOut(0U),
                  "mFileTimeLo", "mFileTimeLo", 48);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_b_emlrt_marshallOut(0U),
                  "mFileTimeHi", "mFileTimeHi", 48);
  sf_mex_assign(&c3_7vqb7o7CaUJzbPKhFMyx3F_rhs48, sf_mex_createcellmatrix(0, 1),
                false);
  sf_mex_assign(&c3_7vqb7o7CaUJzbPKhFMyx3F_lhs48, sf_mex_createcellmatrix(0, 1),
                false);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info, sf_mex_duplicatearraysafe
                  (&c3_7vqb7o7CaUJzbPKhFMyx3F_rhs48), "rhs", "rhs", 48);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info, sf_mex_duplicatearraysafe
                  (&c3_7vqb7o7CaUJzbPKhFMyx3F_lhs48), "lhs", "lhs", 48);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_emlrt_marshallOut(
    "[ILXPE]$matlabroot$/toolbox/eml/lib/matlab/datafun/private/sumprod.m"),
                  "context", "context", 49);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_emlrt_marshallOut(
    "combine_vector_elements"), "name", "name", 49);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_emlrt_marshallOut("function_handle"),
                  "dominantType", "dominantType", 49);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_emlrt_marshallOut(
    "[ILXPE]$matlabroot$/toolbox/eml/lib/matlab/datafun/private/combine_vector_elements.m"),
                  "resolved", "resolved", 49);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_b_emlrt_marshallOut(1395955502U),
                  "fileTimeLo", "fileTimeLo", 49);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_b_emlrt_marshallOut(0U),
                  "fileTimeHi", "fileTimeHi", 49);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_b_emlrt_marshallOut(0U),
                  "mFileTimeLo", "mFileTimeLo", 49);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_b_emlrt_marshallOut(0U),
                  "mFileTimeHi", "mFileTimeHi", 49);
  sf_mex_assign(&c3_7vqb7o7CaUJzbPKhFMyx3F_rhs49, sf_mex_createcellmatrix(0, 1),
                false);
  sf_mex_assign(&c3_7vqb7o7CaUJzbPKhFMyx3F_lhs49, sf_mex_createcellmatrix(0, 1),
                false);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info, sf_mex_duplicatearraysafe
                  (&c3_7vqb7o7CaUJzbPKhFMyx3F_rhs49), "rhs", "rhs", 49);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info, sf_mex_duplicatearraysafe
                  (&c3_7vqb7o7CaUJzbPKhFMyx3F_lhs49), "lhs", "lhs", 49);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_emlrt_marshallOut(
    "[ILXPE]$matlabroot$/toolbox/eml/lib/matlab/datafun/private/combine_vector_elements.m"),
                  "context", "context", 50);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_emlrt_marshallOut(
    "eml_int_forloop_overflow_check"), "name", "name", 50);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_emlrt_marshallOut(""),
                  "dominantType", "dominantType", 50);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m"),
                  "resolved", "resolved", 50);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_b_emlrt_marshallOut(1397286222U),
                  "fileTimeLo", "fileTimeLo", 50);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_b_emlrt_marshallOut(0U),
                  "fileTimeHi", "fileTimeHi", 50);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_b_emlrt_marshallOut(0U),
                  "mFileTimeLo", "mFileTimeLo", 50);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info,
                  c3_7vqb7o7CaUJzbPKhFMyx3F_b_emlrt_marshallOut(0U),
                  "mFileTimeHi", "mFileTimeHi", 50);
  sf_mex_assign(&c3_7vqb7o7CaUJzbPKhFMyx3F_rhs50, sf_mex_createcellmatrix(0, 1),
                false);
  sf_mex_assign(&c3_7vqb7o7CaUJzbPKhFMyx3F_lhs50, sf_mex_createcellmatrix(0, 1),
                false);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info, sf_mex_duplicatearraysafe
                  (&c3_7vqb7o7CaUJzbPKhFMyx3F_rhs50), "rhs", "rhs", 50);
  sf_mex_addfield(*c3_7vqb7o7CaUJzbPKhFMyx3F_info, sf_mex_duplicatearraysafe
                  (&c3_7vqb7o7CaUJzbPKhFMyx3F_lhs50), "lhs", "lhs", 50);
  sf_mex_destroy(&c3_7vqb7o7CaUJzbPKhFMyx3F_rhs0);
  sf_mex_destroy(&c3_7vqb7o7CaUJzbPKhFMyx3F_lhs0);
  sf_mex_destroy(&c3_7vqb7o7CaUJzbPKhFMyx3F_rhs1);
  sf_mex_destroy(&c3_7vqb7o7CaUJzbPKhFMyx3F_lhs1);
  sf_mex_destroy(&c3_7vqb7o7CaUJzbPKhFMyx3F_rhs2);
  sf_mex_destroy(&c3_7vqb7o7CaUJzbPKhFMyx3F_lhs2);
  sf_mex_destroy(&c3_7vqb7o7CaUJzbPKhFMyx3F_rhs3);
  sf_mex_destroy(&c3_7vqb7o7CaUJzbPKhFMyx3F_lhs3);
  sf_mex_destroy(&c3_7vqb7o7CaUJzbPKhFMyx3F_rhs4);
  sf_mex_destroy(&c3_7vqb7o7CaUJzbPKhFMyx3F_lhs4);
  sf_mex_destroy(&c3_7vqb7o7CaUJzbPKhFMyx3F_rhs5);
  sf_mex_destroy(&c3_7vqb7o7CaUJzbPKhFMyx3F_lhs5);
  sf_mex_destroy(&c3_7vqb7o7CaUJzbPKhFMyx3F_rhs6);
  sf_mex_destroy(&c3_7vqb7o7CaUJzbPKhFMyx3F_lhs6);
  sf_mex_destroy(&c3_7vqb7o7CaUJzbPKhFMyx3F_rhs7);
  sf_mex_destroy(&c3_7vqb7o7CaUJzbPKhFMyx3F_lhs7);
  sf_mex_destroy(&c3_7vqb7o7CaUJzbPKhFMyx3F_rhs8);
  sf_mex_destroy(&c3_7vqb7o7CaUJzbPKhFMyx3F_lhs8);
  sf_mex_destroy(&c3_7vqb7o7CaUJzbPKhFMyx3F_rhs9);
  sf_mex_destroy(&c3_7vqb7o7CaUJzbPKhFMyx3F_lhs9);
  sf_mex_destroy(&c3_7vqb7o7CaUJzbPKhFMyx3F_rhs10);
  sf_mex_destroy(&c3_7vqb7o7CaUJzbPKhFMyx3F_lhs10);
  sf_mex_destroy(&c3_7vqb7o7CaUJzbPKhFMyx3F_rhs11);
  sf_mex_destroy(&c3_7vqb7o7CaUJzbPKhFMyx3F_lhs11);
  sf_mex_destroy(&c3_7vqb7o7CaUJzbPKhFMyx3F_rhs12);
  sf_mex_destroy(&c3_7vqb7o7CaUJzbPKhFMyx3F_lhs12);
  sf_mex_destroy(&c3_7vqb7o7CaUJzbPKhFMyx3F_rhs13);
  sf_mex_destroy(&c3_7vqb7o7CaUJzbPKhFMyx3F_lhs13);
  sf_mex_destroy(&c3_7vqb7o7CaUJzbPKhFMyx3F_rhs14);
  sf_mex_destroy(&c3_7vqb7o7CaUJzbPKhFMyx3F_lhs14);
  sf_mex_destroy(&c3_7vqb7o7CaUJzbPKhFMyx3F_rhs15);
  sf_mex_destroy(&c3_7vqb7o7CaUJzbPKhFMyx3F_lhs15);
  sf_mex_destroy(&c3_7vqb7o7CaUJzbPKhFMyx3F_rhs16);
  sf_mex_destroy(&c3_7vqb7o7CaUJzbPKhFMyx3F_lhs16);
  sf_mex_destroy(&c3_7vqb7o7CaUJzbPKhFMyx3F_rhs17);
  sf_mex_destroy(&c3_7vqb7o7CaUJzbPKhFMyx3F_lhs17);
  sf_mex_destroy(&c3_7vqb7o7CaUJzbPKhFMyx3F_rhs18);
  sf_mex_destroy(&c3_7vqb7o7CaUJzbPKhFMyx3F_lhs18);
  sf_mex_destroy(&c3_7vqb7o7CaUJzbPKhFMyx3F_rhs19);
  sf_mex_destroy(&c3_7vqb7o7CaUJzbPKhFMyx3F_lhs19);
  sf_mex_destroy(&c3_7vqb7o7CaUJzbPKhFMyx3F_rhs20);
  sf_mex_destroy(&c3_7vqb7o7CaUJzbPKhFMyx3F_lhs20);
  sf_mex_destroy(&c3_7vqb7o7CaUJzbPKhFMyx3F_rhs21);
  sf_mex_destroy(&c3_7vqb7o7CaUJzbPKhFMyx3F_lhs21);
  sf_mex_destroy(&c3_7vqb7o7CaUJzbPKhFMyx3F_rhs22);
  sf_mex_destroy(&c3_7vqb7o7CaUJzbPKhFMyx3F_lhs22);
  sf_mex_destroy(&c3_7vqb7o7CaUJzbPKhFMyx3F_rhs23);
  sf_mex_destroy(&c3_7vqb7o7CaUJzbPKhFMyx3F_lhs23);
  sf_mex_destroy(&c3_7vqb7o7CaUJzbPKhFMyx3F_rhs24);
  sf_mex_destroy(&c3_7vqb7o7CaUJzbPKhFMyx3F_lhs24);
  sf_mex_destroy(&c3_7vqb7o7CaUJzbPKhFMyx3F_rhs25);
  sf_mex_destroy(&c3_7vqb7o7CaUJzbPKhFMyx3F_lhs25);
  sf_mex_destroy(&c3_7vqb7o7CaUJzbPKhFMyx3F_rhs26);
  sf_mex_destroy(&c3_7vqb7o7CaUJzbPKhFMyx3F_lhs26);
  sf_mex_destroy(&c3_7vqb7o7CaUJzbPKhFMyx3F_rhs27);
  sf_mex_destroy(&c3_7vqb7o7CaUJzbPKhFMyx3F_lhs27);
  sf_mex_destroy(&c3_7vqb7o7CaUJzbPKhFMyx3F_rhs28);
  sf_mex_destroy(&c3_7vqb7o7CaUJzbPKhFMyx3F_lhs28);
  sf_mex_destroy(&c3_7vqb7o7CaUJzbPKhFMyx3F_rhs29);
  sf_mex_destroy(&c3_7vqb7o7CaUJzbPKhFMyx3F_lhs29);
  sf_mex_destroy(&c3_7vqb7o7CaUJzbPKhFMyx3F_rhs30);
  sf_mex_destroy(&c3_7vqb7o7CaUJzbPKhFMyx3F_lhs30);
  sf_mex_destroy(&c3_7vqb7o7CaUJzbPKhFMyx3F_rhs31);
  sf_mex_destroy(&c3_7vqb7o7CaUJzbPKhFMyx3F_lhs31);
  sf_mex_destroy(&c3_7vqb7o7CaUJzbPKhFMyx3F_rhs32);
  sf_mex_destroy(&c3_7vqb7o7CaUJzbPKhFMyx3F_lhs32);
  sf_mex_destroy(&c3_7vqb7o7CaUJzbPKhFMyx3F_rhs33);
  sf_mex_destroy(&c3_7vqb7o7CaUJzbPKhFMyx3F_lhs33);
  sf_mex_destroy(&c3_7vqb7o7CaUJzbPKhFMyx3F_rhs34);
  sf_mex_destroy(&c3_7vqb7o7CaUJzbPKhFMyx3F_lhs34);
  sf_mex_destroy(&c3_7vqb7o7CaUJzbPKhFMyx3F_rhs35);
  sf_mex_destroy(&c3_7vqb7o7CaUJzbPKhFMyx3F_lhs35);
  sf_mex_destroy(&c3_7vqb7o7CaUJzbPKhFMyx3F_rhs36);
  sf_mex_destroy(&c3_7vqb7o7CaUJzbPKhFMyx3F_lhs36);
  sf_mex_destroy(&c3_7vqb7o7CaUJzbPKhFMyx3F_rhs37);
  sf_mex_destroy(&c3_7vqb7o7CaUJzbPKhFMyx3F_lhs37);
  sf_mex_destroy(&c3_7vqb7o7CaUJzbPKhFMyx3F_rhs38);
  sf_mex_destroy(&c3_7vqb7o7CaUJzbPKhFMyx3F_lhs38);
  sf_mex_destroy(&c3_7vqb7o7CaUJzbPKhFMyx3F_rhs39);
  sf_mex_destroy(&c3_7vqb7o7CaUJzbPKhFMyx3F_lhs39);
  sf_mex_destroy(&c3_7vqb7o7CaUJzbPKhFMyx3F_rhs40);
  sf_mex_destroy(&c3_7vqb7o7CaUJzbPKhFMyx3F_lhs40);
  sf_mex_destroy(&c3_7vqb7o7CaUJzbPKhFMyx3F_rhs41);
  sf_mex_destroy(&c3_7vqb7o7CaUJzbPKhFMyx3F_lhs41);
  sf_mex_destroy(&c3_7vqb7o7CaUJzbPKhFMyx3F_rhs42);
  sf_mex_destroy(&c3_7vqb7o7CaUJzbPKhFMyx3F_lhs42);
  sf_mex_destroy(&c3_7vqb7o7CaUJzbPKhFMyx3F_rhs43);
  sf_mex_destroy(&c3_7vqb7o7CaUJzbPKhFMyx3F_lhs43);
  sf_mex_destroy(&c3_7vqb7o7CaUJzbPKhFMyx3F_rhs44);
  sf_mex_destroy(&c3_7vqb7o7CaUJzbPKhFMyx3F_lhs44);
  sf_mex_destroy(&c3_7vqb7o7CaUJzbPKhFMyx3F_rhs45);
  sf_mex_destroy(&c3_7vqb7o7CaUJzbPKhFMyx3F_lhs45);
  sf_mex_destroy(&c3_7vqb7o7CaUJzbPKhFMyx3F_rhs46);
  sf_mex_destroy(&c3_7vqb7o7CaUJzbPKhFMyx3F_lhs46);
  sf_mex_destroy(&c3_7vqb7o7CaUJzbPKhFMyx3F_rhs47);
  sf_mex_destroy(&c3_7vqb7o7CaUJzbPKhFMyx3F_lhs47);
  sf_mex_destroy(&c3_7vqb7o7CaUJzbPKhFMyx3F_rhs48);
  sf_mex_destroy(&c3_7vqb7o7CaUJzbPKhFMyx3F_lhs48);
  sf_mex_destroy(&c3_7vqb7o7CaUJzbPKhFMyx3F_rhs49);
  sf_mex_destroy(&c3_7vqb7o7CaUJzbPKhFMyx3F_lhs49);
  sf_mex_destroy(&c3_7vqb7o7CaUJzbPKhFMyx3F_rhs50);
  sf_mex_destroy(&c3_7vqb7o7CaUJzbPKhFMyx3F_lhs50);
}

static const mxArray *c3_7vqb7o7CaUJzbPKhFMyx3F_emlrt_marshallOut(const char
  * c3_7vqb7o7CaUJzbPKhFMyx3F_b_u)
{
  const mxArray *c3_7vqb7o7CaUJzbPKhFMyx3F_y = NULL;
  c3_7vqb7o7CaUJzbPKhFMyx3F_y = NULL;
  sf_mex_assign(&c3_7vqb7o7CaUJzbPKhFMyx3F_y, sf_mex_create("y",
    c3_7vqb7o7CaUJzbPKhFMyx3F_b_u, 15, 0U, 0U, 0U, 2, 1, strlen
    (c3_7vqb7o7CaUJzbPKhFMyx3F_b_u)), false);
  return c3_7vqb7o7CaUJzbPKhFMyx3F_y;
}

static const mxArray *c3_7vqb7o7CaUJzbPKhFMyx3F_b_emlrt_marshallOut(const
  uint32_T c3_7vqb7o7CaUJzbPKhFMyx3F_b_u)
{
  const mxArray *c3_7vqb7o7CaUJzbPKhFMyx3F_y = NULL;
  c3_7vqb7o7CaUJzbPKhFMyx3F_y = NULL;
  sf_mex_assign(&c3_7vqb7o7CaUJzbPKhFMyx3F_y, sf_mex_create("y",
    &c3_7vqb7o7CaUJzbPKhFMyx3F_b_u, 7, 0U, 0U, 0U, 0), false);
  return c3_7vqb7o7CaUJzbPKhFMyx3F_y;
}

static real_T c3_7vqb7o7CaUJzbPKhFMyx3F_floor
  (SFc3_7vqb7o7CaUJzbPKhFMyx3F_WECSim_LibInstanceStruct *chartInstance, real_T
   c3_7vqb7o7CaUJzbPKhFMyx3F_x)
{
  real_T c3_7vqb7o7CaUJzbPKhFMyx3F_b_x;
  c3_7vqb7o7CaUJzbPKhFMyx3F_b_x = c3_7vqb7o7CaUJzbPKhFMyx3F_x;
  c3_7vqb7o7CaUJzbPKhFMyx3F_b_floor(chartInstance,
    &c3_7vqb7o7CaUJzbPKhFMyx3F_b_x);
  return c3_7vqb7o7CaUJzbPKhFMyx3F_b_x;
}

static real_T c3_7vqb7o7CaUJzbPKhFMyx3F_abs
  (SFc3_7vqb7o7CaUJzbPKhFMyx3F_WECSim_LibInstanceStruct *chartInstance, real_T
   c3_7vqb7o7CaUJzbPKhFMyx3F_x)
{
  real_T c3_7vqb7o7CaUJzbPKhFMyx3F_b_x;
  (void)chartInstance;
  c3_7vqb7o7CaUJzbPKhFMyx3F_b_x = c3_7vqb7o7CaUJzbPKhFMyx3F_x;
  return muDoubleScalarAbs(c3_7vqb7o7CaUJzbPKhFMyx3F_b_x);
}

static real_T c3_7vqb7o7CaUJzbPKhFMyx3F_trapz
  (SFc3_7vqb7o7CaUJzbPKhFMyx3F_WECSim_LibInstanceStruct *chartInstance, real_T
   c3_7vqb7o7CaUJzbPKhFMyx3F_x[601], real_T c3_7vqb7o7CaUJzbPKhFMyx3F_y[601])
{
  int32_T c3_7vqb7o7CaUJzbPKhFMyx3F_i74;
  real_T c3_7vqb7o7CaUJzbPKhFMyx3F_b_x[601];
  int32_T c3_7vqb7o7CaUJzbPKhFMyx3F_i;
  int32_T c3_7vqb7o7CaUJzbPKhFMyx3F_b_i;
  real_T c3_7vqb7o7CaUJzbPKhFMyx3F_s;
  int32_T c3_7vqb7o7CaUJzbPKhFMyx3F_ix;
  int32_T c3_7vqb7o7CaUJzbPKhFMyx3F_iy;
  real_T c3_7vqb7o7CaUJzbPKhFMyx3F_ylast;
  int32_T c3_7vqb7o7CaUJzbPKhFMyx3F_k;
  int32_T c3_7vqb7o7CaUJzbPKhFMyx3F_a;
  int32_T c3_7vqb7o7CaUJzbPKhFMyx3F_b_a;
  int32_T c3_7vqb7o7CaUJzbPKhFMyx3F_c_a;
  int32_T c3_7vqb7o7CaUJzbPKhFMyx3F_d_a;
  real_T c3_7vqb7o7CaUJzbPKhFMyx3F_c_x;
  real_T c3_7vqb7o7CaUJzbPKhFMyx3F_d_x;
  real_T c3_7vqb7o7CaUJzbPKhFMyx3F_b_z;
  for (c3_7vqb7o7CaUJzbPKhFMyx3F_i74 = 0; c3_7vqb7o7CaUJzbPKhFMyx3F_i74 < 601;
       c3_7vqb7o7CaUJzbPKhFMyx3F_i74++) {
    c3_7vqb7o7CaUJzbPKhFMyx3F_b_x[c3_7vqb7o7CaUJzbPKhFMyx3F_i74] =
      c3_7vqb7o7CaUJzbPKhFMyx3F_x[c3_7vqb7o7CaUJzbPKhFMyx3F_i74];
  }

  c3_7vqb7o7CaUJzbPKhFMyx3F_intmin(chartInstance);
  for (c3_7vqb7o7CaUJzbPKhFMyx3F_i = 1; c3_7vqb7o7CaUJzbPKhFMyx3F_i < 601;
       c3_7vqb7o7CaUJzbPKhFMyx3F_i++) {
    c3_7vqb7o7CaUJzbPKhFMyx3F_b_i = c3_7vqb7o7CaUJzbPKhFMyx3F_i;
    c3_7vqb7o7CaUJzbPKhFMyx3F_b_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
      _SFD_INTEGER_CHECK("", (real_T)c3_7vqb7o7CaUJzbPKhFMyx3F_b_i), 1, 601, 1,
      0) - 1] = c3_7vqb7o7CaUJzbPKhFMyx3F_b_x[_SFD_EML_ARRAY_BOUNDS_CHECK("",
      (int32_T)_SFD_INTEGER_CHECK("", (real_T)(c3_7vqb7o7CaUJzbPKhFMyx3F_b_i + 1)),
      1, 601, 1, 0) - 1] -
      c3_7vqb7o7CaUJzbPKhFMyx3F_b_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
      _SFD_INTEGER_CHECK("", (real_T)c3_7vqb7o7CaUJzbPKhFMyx3F_b_i), 1, 601, 1,
      0) - 1];
  }

  c3_7vqb7o7CaUJzbPKhFMyx3F_s = 0.0;
  c3_7vqb7o7CaUJzbPKhFMyx3F_ix = 0;
  c3_7vqb7o7CaUJzbPKhFMyx3F_iy = 1;
  c3_7vqb7o7CaUJzbPKhFMyx3F_ylast = c3_7vqb7o7CaUJzbPKhFMyx3F_y[0];
  for (c3_7vqb7o7CaUJzbPKhFMyx3F_k = 0; c3_7vqb7o7CaUJzbPKhFMyx3F_k < 600;
       c3_7vqb7o7CaUJzbPKhFMyx3F_k++) {
    c3_7vqb7o7CaUJzbPKhFMyx3F_a = c3_7vqb7o7CaUJzbPKhFMyx3F_iy;
    c3_7vqb7o7CaUJzbPKhFMyx3F_b_a = c3_7vqb7o7CaUJzbPKhFMyx3F_a + 1;
    c3_7vqb7o7CaUJzbPKhFMyx3F_iy = c3_7vqb7o7CaUJzbPKhFMyx3F_b_a;
    c3_7vqb7o7CaUJzbPKhFMyx3F_c_a = c3_7vqb7o7CaUJzbPKhFMyx3F_ix;
    c3_7vqb7o7CaUJzbPKhFMyx3F_d_a = c3_7vqb7o7CaUJzbPKhFMyx3F_c_a + 1;
    c3_7vqb7o7CaUJzbPKhFMyx3F_ix = c3_7vqb7o7CaUJzbPKhFMyx3F_d_a;
    c3_7vqb7o7CaUJzbPKhFMyx3F_c_x = c3_7vqb7o7CaUJzbPKhFMyx3F_ylast +
      c3_7vqb7o7CaUJzbPKhFMyx3F_y[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
      _SFD_INTEGER_CHECK("", (real_T)c3_7vqb7o7CaUJzbPKhFMyx3F_iy), 1, 601, 1, 0)
      - 1];
    c3_7vqb7o7CaUJzbPKhFMyx3F_d_x = c3_7vqb7o7CaUJzbPKhFMyx3F_c_x;
    c3_7vqb7o7CaUJzbPKhFMyx3F_b_z = c3_7vqb7o7CaUJzbPKhFMyx3F_d_x / 2.0;
    c3_7vqb7o7CaUJzbPKhFMyx3F_s +=
      c3_7vqb7o7CaUJzbPKhFMyx3F_b_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
      _SFD_INTEGER_CHECK("", (real_T)c3_7vqb7o7CaUJzbPKhFMyx3F_ix), 1, 601, 1, 0)
      - 1] * c3_7vqb7o7CaUJzbPKhFMyx3F_b_z;
    c3_7vqb7o7CaUJzbPKhFMyx3F_ylast =
      c3_7vqb7o7CaUJzbPKhFMyx3F_y[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
      _SFD_INTEGER_CHECK("", (real_T)c3_7vqb7o7CaUJzbPKhFMyx3F_iy), 1, 601, 1, 0)
      - 1];
  }

  return c3_7vqb7o7CaUJzbPKhFMyx3F_s;
}

static int32_T c3_7vqb7o7CaUJzbPKhFMyx3F_intmin
  (SFc3_7vqb7o7CaUJzbPKhFMyx3F_WECSim_LibInstanceStruct *chartInstance)
{
  (void)chartInstance;
  return MIN_int32_T;
}

static real_T c3_7vqb7o7CaUJzbPKhFMyx3F_sum
  (SFc3_7vqb7o7CaUJzbPKhFMyx3F_WECSim_LibInstanceStruct *chartInstance, real_T
   c3_7vqb7o7CaUJzbPKhFMyx3F_x[6])
{
  real_T c3_7vqb7o7CaUJzbPKhFMyx3F_y;
  int32_T c3_7vqb7o7CaUJzbPKhFMyx3F_k;
  int32_T c3_7vqb7o7CaUJzbPKhFMyx3F_b_k;
  c3_7vqb7o7CaUJzbPKhFMyx3F_y = c3_7vqb7o7CaUJzbPKhFMyx3F_x[0];
  c3_7vqb7o7CaUJzbPKhFMyx3F_intmin(chartInstance);
  for (c3_7vqb7o7CaUJzbPKhFMyx3F_k = 2; c3_7vqb7o7CaUJzbPKhFMyx3F_k < 7;
       c3_7vqb7o7CaUJzbPKhFMyx3F_k++) {
    c3_7vqb7o7CaUJzbPKhFMyx3F_b_k = c3_7vqb7o7CaUJzbPKhFMyx3F_k;
    c3_7vqb7o7CaUJzbPKhFMyx3F_y +=
      c3_7vqb7o7CaUJzbPKhFMyx3F_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
      _SFD_INTEGER_CHECK("", (real_T)c3_7vqb7o7CaUJzbPKhFMyx3F_b_k), 1, 6, 1, 0)
      - 1];
  }

  return c3_7vqb7o7CaUJzbPKhFMyx3F_y;
}

static const mxArray *c3_7vqb7o7CaUJzbPKhFMyx3F_i_sf_marshallOut(void
  *chartInstanceVoid, void *c3_7vqb7o7CaUJzbPKhFMyx3F_b_inData)
{
  const mxArray *c3_7vqb7o7CaUJzbPKhFMyx3F_mxArrayOutData = NULL;
  int32_T c3_7vqb7o7CaUJzbPKhFMyx3F_b_u;
  const mxArray *c3_7vqb7o7CaUJzbPKhFMyx3F_y = NULL;
  SFc3_7vqb7o7CaUJzbPKhFMyx3F_WECSim_LibInstanceStruct *chartInstance;
  chartInstance = (SFc3_7vqb7o7CaUJzbPKhFMyx3F_WECSim_LibInstanceStruct *)
    chartInstanceVoid;
  c3_7vqb7o7CaUJzbPKhFMyx3F_mxArrayOutData = NULL;
  c3_7vqb7o7CaUJzbPKhFMyx3F_b_u = *(int32_T *)c3_7vqb7o7CaUJzbPKhFMyx3F_b_inData;
  c3_7vqb7o7CaUJzbPKhFMyx3F_y = NULL;
  sf_mex_assign(&c3_7vqb7o7CaUJzbPKhFMyx3F_y, sf_mex_create("y",
    &c3_7vqb7o7CaUJzbPKhFMyx3F_b_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c3_7vqb7o7CaUJzbPKhFMyx3F_mxArrayOutData,
                c3_7vqb7o7CaUJzbPKhFMyx3F_y, false);
  return c3_7vqb7o7CaUJzbPKhFMyx3F_mxArrayOutData;
}

static int32_T c3_7vqb7o7CaUJzbPKhFMyx3F_j_emlrt_marshallIn
  (SFc3_7vqb7o7CaUJzbPKhFMyx3F_WECSim_LibInstanceStruct *chartInstance, const
   mxArray *c3_7vqb7o7CaUJzbPKhFMyx3F_b_u, const emlrtMsgIdentifier
   *c3_7vqb7o7CaUJzbPKhFMyx3F_parentId)
{
  int32_T c3_7vqb7o7CaUJzbPKhFMyx3F_y;
  int32_T c3_7vqb7o7CaUJzbPKhFMyx3F_i75;
  (void)chartInstance;
  sf_mex_import(c3_7vqb7o7CaUJzbPKhFMyx3F_parentId, sf_mex_dup
                (c3_7vqb7o7CaUJzbPKhFMyx3F_b_u), &c3_7vqb7o7CaUJzbPKhFMyx3F_i75,
                1, 6, 0U, 0, 0U, 0);
  c3_7vqb7o7CaUJzbPKhFMyx3F_y = c3_7vqb7o7CaUJzbPKhFMyx3F_i75;
  sf_mex_destroy(&c3_7vqb7o7CaUJzbPKhFMyx3F_b_u);
  return c3_7vqb7o7CaUJzbPKhFMyx3F_y;
}

static void c3_7vqb7o7CaUJzbPKhFMyx3F_g_sf_marshallIn(void *chartInstanceVoid,
  const mxArray *c3_7vqb7o7CaUJzbPKhFMyx3F_mxArrayInData, const char_T
  *c3_7vqb7o7CaUJzbPKhFMyx3F_varName, void *c3_7vqb7o7CaUJzbPKhFMyx3F_outData)
{
  const mxArray *c3_7vqb7o7CaUJzbPKhFMyx3F_b_sfEvent;
  const char_T *c3_7vqb7o7CaUJzbPKhFMyx3F_identifier;
  emlrtMsgIdentifier c3_7vqb7o7CaUJzbPKhFMyx3F_thisId;
  int32_T c3_7vqb7o7CaUJzbPKhFMyx3F_y;
  SFc3_7vqb7o7CaUJzbPKhFMyx3F_WECSim_LibInstanceStruct *chartInstance;
  chartInstance = (SFc3_7vqb7o7CaUJzbPKhFMyx3F_WECSim_LibInstanceStruct *)
    chartInstanceVoid;
  c3_7vqb7o7CaUJzbPKhFMyx3F_b_sfEvent = sf_mex_dup
    (c3_7vqb7o7CaUJzbPKhFMyx3F_mxArrayInData);
  c3_7vqb7o7CaUJzbPKhFMyx3F_identifier = c3_7vqb7o7CaUJzbPKhFMyx3F_varName;
  c3_7vqb7o7CaUJzbPKhFMyx3F_thisId.fIdentifier =
    c3_7vqb7o7CaUJzbPKhFMyx3F_identifier;
  c3_7vqb7o7CaUJzbPKhFMyx3F_thisId.fParent = NULL;
  c3_7vqb7o7CaUJzbPKhFMyx3F_y = c3_7vqb7o7CaUJzbPKhFMyx3F_j_emlrt_marshallIn
    (chartInstance, sf_mex_dup(c3_7vqb7o7CaUJzbPKhFMyx3F_b_sfEvent),
     &c3_7vqb7o7CaUJzbPKhFMyx3F_thisId);
  sf_mex_destroy(&c3_7vqb7o7CaUJzbPKhFMyx3F_b_sfEvent);
  *(int32_T *)c3_7vqb7o7CaUJzbPKhFMyx3F_outData = c3_7vqb7o7CaUJzbPKhFMyx3F_y;
  sf_mex_destroy(&c3_7vqb7o7CaUJzbPKhFMyx3F_mxArrayInData);
}

static uint8_T c3_7vqb7o7CaUJzbPKhFMyx3F_k_emlrt_marshallIn
  (SFc3_7vqb7o7CaUJzbPKhFMyx3F_WECSim_LibInstanceStruct *chartInstance, const
   mxArray *c3_7vqb7o7CaUJzbPKhFMyx3F_b_is_active_c3_7vqb7o7CaUJzbPKhFMyx3F_,
   const char_T *c3_7vqb7o7CaUJzbPKhFMyx3F_identifier)
{
  uint8_T c3_7vqb7o7CaUJzbPKhFMyx3F_y;
  emlrtMsgIdentifier c3_7vqb7o7CaUJzbPKhFMyx3F_thisId;
  c3_7vqb7o7CaUJzbPKhFMyx3F_thisId.fIdentifier =
    c3_7vqb7o7CaUJzbPKhFMyx3F_identifier;
  c3_7vqb7o7CaUJzbPKhFMyx3F_thisId.fParent = NULL;
  c3_7vqb7o7CaUJzbPKhFMyx3F_y = c3_7vqb7o7CaUJzbPKhFMyx3F_l_emlrt_marshallIn
    (chartInstance, sf_mex_dup
     (c3_7vqb7o7CaUJzbPKhFMyx3F_b_is_active_c3_7vqb7o7CaUJzbPKhFMyx3F_),
     &c3_7vqb7o7CaUJzbPKhFMyx3F_thisId);
  sf_mex_destroy
    (&c3_7vqb7o7CaUJzbPKhFMyx3F_b_is_active_c3_7vqb7o7CaUJzbPKhFMyx3F_);
  return c3_7vqb7o7CaUJzbPKhFMyx3F_y;
}

static uint8_T c3_7vqb7o7CaUJzbPKhFMyx3F_l_emlrt_marshallIn
  (SFc3_7vqb7o7CaUJzbPKhFMyx3F_WECSim_LibInstanceStruct *chartInstance, const
   mxArray *c3_7vqb7o7CaUJzbPKhFMyx3F_b_u, const emlrtMsgIdentifier
   *c3_7vqb7o7CaUJzbPKhFMyx3F_parentId)
{
  uint8_T c3_7vqb7o7CaUJzbPKhFMyx3F_y;
  uint8_T c3_7vqb7o7CaUJzbPKhFMyx3F_u0;
  (void)chartInstance;
  sf_mex_import(c3_7vqb7o7CaUJzbPKhFMyx3F_parentId, sf_mex_dup
                (c3_7vqb7o7CaUJzbPKhFMyx3F_b_u), &c3_7vqb7o7CaUJzbPKhFMyx3F_u0,
                1, 3, 0U, 0, 0U, 0);
  c3_7vqb7o7CaUJzbPKhFMyx3F_y = c3_7vqb7o7CaUJzbPKhFMyx3F_u0;
  sf_mex_destroy(&c3_7vqb7o7CaUJzbPKhFMyx3F_b_u);
  return c3_7vqb7o7CaUJzbPKhFMyx3F_y;
}

static void c3_7vqb7o7CaUJzbPKhFMyx3F_b_floor
  (SFc3_7vqb7o7CaUJzbPKhFMyx3F_WECSim_LibInstanceStruct *chartInstance, real_T
   *c3_7vqb7o7CaUJzbPKhFMyx3F_x)
{
  (void)chartInstance;
  *c3_7vqb7o7CaUJzbPKhFMyx3F_x = muDoubleScalarFloor
    (*c3_7vqb7o7CaUJzbPKhFMyx3F_x);
}

static void init_dsm_address_info
  (SFc3_7vqb7o7CaUJzbPKhFMyx3F_WECSim_LibInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void init_simulink_io_address
  (SFc3_7vqb7o7CaUJzbPKhFMyx3F_WECSim_LibInstanceStruct *chartInstance)
{
  chartInstance->c3_7vqb7o7CaUJzbPKhFMyx3F_check = (real_T *)
    ssGetInputPortSignal_wrapper(chartInstance->S, 0);
  chartInstance->c3_7vqb7o7CaUJzbPKhFMyx3F_v = (real_T (*)[6])
    ssGetInputPortSignal_wrapper(chartInstance->S, 1);
  chartInstance->c3_7vqb7o7CaUJzbPKhFMyx3F_F_FM = (real_T (*)[6])
    ssGetOutputPortSignal_wrapper(chartInstance->S, 1);
  chartInstance->c3_7vqb7o7CaUJzbPKhFMyx3F_ZeroVel = (real_T (*)[3606])
    ssGetInputPortSignal_wrapper(chartInstance->S, 2);
  chartInstance->c3_7vqb7o7CaUJzbPKhFMyx3F_b_IRKB = (real_T (*)[43272])
    ssGetInputPortSignal_wrapper(chartInstance->S, 3);
  chartInstance->c3_7vqb7o7CaUJzbPKhFMyx3F_CTTime = (real_T (*)[601])
    ssGetInputPortSignal_wrapper(chartInstance->S, 4);
}

/* SFunction Glue Code */
#ifdef utFree
#undef utFree
#endif

#ifdef utMalloc
#undef utMalloc
#endif

#ifdef __cplusplus

extern "C" void *utMalloc(size_t size);
extern "C" void utFree(void*);

#else

extern void *utMalloc(size_t size);
extern void utFree(void*);

#endif

void sf_c3_7vqb7o7CaUJzbPKhFMyx3F_WECSim_Lib_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1505736705U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2315517079U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2980440639U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(4248962320U);
}

mxArray* sf_c3_7vqb7o7CaUJzbPKhFMyx3F_WECSim_Lib_get_post_codegen_info(void);
mxArray *sf_c3_7vqb7o7CaUJzbPKhFMyx3F_WECSim_Lib_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals", "postCodegenInfo" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1, 1, sizeof
    (autoinheritanceFields)/sizeof(autoinheritanceFields[0]),
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("qMyw8LVTe9Zu6Ipo9MCaiH");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,5,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(6);
      pr[1] = (double)(1);
      mxSetField(mxData,1,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,1,"type",mxType);
    }

    mxSetField(mxData,1,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(6);
      pr[1] = (double)(601);
      mxSetField(mxData,2,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,2,"type",mxType);
    }

    mxSetField(mxData,2,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,3,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(601);
      pr[1] = (double)(6);
      pr[2] = (double)(12);
      mxSetField(mxData,3,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,3,"type",mxType);
    }

    mxSetField(mxData,3,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(601);
      pr[1] = (double)(1);
      mxSetField(mxData,4,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,4,"type",mxType);
    }

    mxSetField(mxData,4,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxCreateDoubleMatrix(0,0,
                mxREAL));
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,1,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(6);
      pr[1] = (double)(1);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  {
    mxArray* mxPostCodegenInfo =
      sf_c3_7vqb7o7CaUJzbPKhFMyx3F_WECSim_Lib_get_post_codegen_info();
    mxSetField(mxAutoinheritanceInfo,0,"postCodegenInfo",mxPostCodegenInfo);
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c3_7vqb7o7CaUJzbPKhFMyx3F_WECSim_Lib_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c3_7vqb7o7CaUJzbPKhFMyx3F_WECSim_Lib_jit_fallback_info(void)
{
  const char *infoFields[] = { "fallbackType", "fallbackReason",
    "incompatibleSymbol", };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 3, infoFields);
  mxArray *fallbackReason = mxCreateString("feature_off");
  mxArray *incompatibleSymbol = mxCreateString("");
  mxArray *fallbackType = mxCreateString("early");
  mxSetField(mxInfo, 0, infoFields[0], fallbackType);
  mxSetField(mxInfo, 0, infoFields[1], fallbackReason);
  mxSetField(mxInfo, 0, infoFields[2], incompatibleSymbol);
  return mxInfo;
}

mxArray *sf_c3_7vqb7o7CaUJzbPKhFMyx3F_WECSim_Lib_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

mxArray* sf_c3_7vqb7o7CaUJzbPKhFMyx3F_WECSim_Lib_get_post_codegen_info(void)
{
  const char* fieldNames[] = { "exportedFunctionsUsedByThisChart",
    "exportedFunctionsChecksum" };

  mwSize dims[2] = { 1, 1 };

  mxArray* mxPostCodegenInfo = mxCreateStructArray(2, dims, sizeof(fieldNames)/
    sizeof(fieldNames[0]), fieldNames);

  {
    mxArray* mxExportedFunctionsChecksum = mxCreateString("");
    mwSize exp_dims[2] = { 0, 1 };

    mxArray* mxExportedFunctionsUsedByThisChart = mxCreateCellArray(2, exp_dims);
    mxSetField(mxPostCodegenInfo, 0, "exportedFunctionsUsedByThisChart",
               mxExportedFunctionsUsedByThisChart);
    mxSetField(mxPostCodegenInfo, 0, "exportedFunctionsChecksum",
               mxExportedFunctionsChecksum);
  }

  return mxPostCodegenInfo;
}

static const mxArray *sf_get_sim_state_info_c3_7vqb7o7CaUJzbPKhFMyx3F_WECSim_Lib
  (void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x4'type','srcId','name','auxInfo'{{M[1],M[5],T\"F_FM\",},{M[4],M[0],T\"kkk\",S'l','i','p'{{M1x2[129 132],M[0],}}},{M[4],M[0],T\"velocity\",S'l','i','p'{{M1x2[108 116],M[0],}}},{M[8],M[0],T\"is_active_c3_7vqb7o7CaUJzbPKhFMyx3F_WECSim_Lib\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 4, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c3_7vqb7o7CaUJzbPKhFMyx3F_WECSim_Lib_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc3_7vqb7o7CaUJzbPKhFMyx3F_WECSim_LibInstanceStruct *chartInstance;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    chartInstance = (SFc3_7vqb7o7CaUJzbPKhFMyx3F_WECSim_LibInstanceStruct *)
      chartInfo->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _WECSim_LibMachineNumber_,
           3,
           1,
           1,
           0,
           6,
           0,
           0,
           0,
           0,
           0,
           &(chartInstance->chartNumber),
           &(chartInstance->instanceNumber),
           (void *)S);

        /* Each instance must initialize its own list of scripts */
        init_script_number_translation(_WECSim_LibMachineNumber_,
          chartInstance->chartNumber,chartInstance->instanceNumber);
        if (chartAlreadyPresent==0) {
          /* this is the first instance */
          sf_debug_set_chart_disable_implicit_casting
            (sfGlobalDebugInstanceStruct,_WECSim_LibMachineNumber_,
             chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(sfGlobalDebugInstanceStruct,
            _WECSim_LibMachineNumber_,
            chartInstance->chartNumber,
            0,
            0,
            0);
          _SFD_SET_DATA_PROPS(0,1,1,0,"check");
          _SFD_SET_DATA_PROPS(1,1,1,0,"v");
          _SFD_SET_DATA_PROPS(2,2,0,1,"F_FM");
          _SFD_SET_DATA_PROPS(3,1,1,0,"ZeroVel");
          _SFD_SET_DATA_PROPS(4,1,1,0,"IRKB");
          _SFD_SET_DATA_PROPS(5,1,1,0,"CTTime");
          _SFD_STATE_INFO(0,0,2);
          _SFD_CH_SUBSTATE_COUNT(0);
          _SFD_CH_SUBSTATE_DECOMP(0);
        }

        _SFD_CV_INIT_CHART(0,0,0,0);

        {
          _SFD_CV_INIT_STATE(0,0,0,0,0,0,NULL,NULL);
        }

        _SFD_CV_INIT_TRANS(0,0,NULL,NULL,0,NULL);

        /* Initialization of MATLAB Function Model Coverage */
        _SFD_CV_INIT_EML(0,1,1,3,0,0,0,2,0,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,710);
        _SFD_CV_INIT_EML_IF(0,1,0,134,146,170,695);
        _SFD_CV_INIT_EML_IF(0,1,1,179,199,245,440);
        _SFD_CV_INIT_EML_IF(0,1,2,323,341,-1,403);
        _SFD_CV_INIT_EML_FOR(0,1,0,509,520,691);
        _SFD_CV_INIT_EML_FOR(0,1,1,528,539,645);
        _SFD_CV_INIT_EML_RELATIONAL(0,1,0,137,146,-1,0);
        _SFD_CV_INIT_EML_RELATIONAL(0,1,1,326,341,-1,2);
        _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_7vqb7o7CaUJzbPKhFMyx3F_g_sf_marshallOut,
          (MexInFcnForType)NULL);

        {
          unsigned int dimVector[1];
          dimVector[0]= 6;
          _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c3_7vqb7o7CaUJzbPKhFMyx3F_c_sf_marshallOut,
            (MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 6;
          _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c3_7vqb7o7CaUJzbPKhFMyx3F_c_sf_marshallOut,
            (MexInFcnForType)c3_7vqb7o7CaUJzbPKhFMyx3F_c_sf_marshallIn);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 6;
          dimVector[1]= 601;
          _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c3_7vqb7o7CaUJzbPKhFMyx3F_f_sf_marshallOut,
            (MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[3];
          dimVector[0]= 601;
          dimVector[1]= 6;
          dimVector[2]= 12;
          _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,3,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c3_7vqb7o7CaUJzbPKhFMyx3F_e_sf_marshallOut,
            (MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 601;
          _SFD_SET_DATA_COMPILED_PROPS(5,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c3_7vqb7o7CaUJzbPKhFMyx3F_d_sf_marshallOut,
            (MexInFcnForType)NULL);
        }

        _SFD_SET_DATA_VALUE_PTR(0U,
          chartInstance->c3_7vqb7o7CaUJzbPKhFMyx3F_check);
        _SFD_SET_DATA_VALUE_PTR(1U, *chartInstance->c3_7vqb7o7CaUJzbPKhFMyx3F_v);
        _SFD_SET_DATA_VALUE_PTR(2U,
          *chartInstance->c3_7vqb7o7CaUJzbPKhFMyx3F_F_FM);
        _SFD_SET_DATA_VALUE_PTR(3U,
          *chartInstance->c3_7vqb7o7CaUJzbPKhFMyx3F_ZeroVel);
        _SFD_SET_DATA_VALUE_PTR(4U,
          *chartInstance->c3_7vqb7o7CaUJzbPKhFMyx3F_b_IRKB);
        _SFD_SET_DATA_VALUE_PTR(5U,
          *chartInstance->c3_7vqb7o7CaUJzbPKhFMyx3F_CTTime);
      }
    } else {
      sf_debug_reset_current_state_configuration(sfGlobalDebugInstanceStruct,
        _WECSim_LibMachineNumber_,chartInstance->chartNumber,
        chartInstance->instanceNumber);
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "7vqb7o7CaUJzbPKhFMyx3F";
}

static void sf_opaque_initialize_c3_7vqb7o7CaUJzbPKhFMyx3F_WECSim_Lib(void
  *chartInstanceVar)
{
  chart_debug_initialization
    (((SFc3_7vqb7o7CaUJzbPKhFMyx3F_WECSim_LibInstanceStruct*) chartInstanceVar
     )->S,0);
  initialize_params_c3_7vqb7o7CaUJzbPKhFMyx3F_WECSim_Lib
    ((SFc3_7vqb7o7CaUJzbPKhFMyx3F_WECSim_LibInstanceStruct*) chartInstanceVar);
  initialize_c3_7vqb7o7CaUJzbPKhFMyx3F_WECSim_Lib
    ((SFc3_7vqb7o7CaUJzbPKhFMyx3F_WECSim_LibInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c3_7vqb7o7CaUJzbPKhFMyx3F_WECSim_Lib(void
  *chartInstanceVar)
{
  enable_c3_7vqb7o7CaUJzbPKhFMyx3F_WECSim_Lib
    ((SFc3_7vqb7o7CaUJzbPKhFMyx3F_WECSim_LibInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c3_7vqb7o7CaUJzbPKhFMyx3F_WECSim_Lib(void
  *chartInstanceVar)
{
  disable_c3_7vqb7o7CaUJzbPKhFMyx3F_WECSim_Lib
    ((SFc3_7vqb7o7CaUJzbPKhFMyx3F_WECSim_LibInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c3_7vqb7o7CaUJzbPKhFMyx3F_WECSim_Lib(void
  *chartInstanceVar)
{
  sf_gateway_c3_7vqb7o7CaUJzbPKhFMyx3F_WECSim_Lib
    ((SFc3_7vqb7o7CaUJzbPKhFMyx3F_WECSim_LibInstanceStruct*) chartInstanceVar);
}

static const mxArray*
  sf_opaque_get_sim_state_c3_7vqb7o7CaUJzbPKhFMyx3F_WECSim_Lib(SimStruct* S)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  return get_sim_state_c3_7vqb7o7CaUJzbPKhFMyx3F_WECSim_Lib
    ((SFc3_7vqb7o7CaUJzbPKhFMyx3F_WECSim_LibInstanceStruct*)
     chartInfo->chartInstance);        /* raw sim ctx */
}

static void sf_opaque_set_sim_state_c3_7vqb7o7CaUJzbPKhFMyx3F_WECSim_Lib
  (SimStruct* S, const mxArray *st)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  set_sim_state_c3_7vqb7o7CaUJzbPKhFMyx3F_WECSim_Lib
    ((SFc3_7vqb7o7CaUJzbPKhFMyx3F_WECSim_LibInstanceStruct*)
     chartInfo->chartInstance, st);
}

static void sf_opaque_terminate_c3_7vqb7o7CaUJzbPKhFMyx3F_WECSim_Lib(void
  *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc3_7vqb7o7CaUJzbPKhFMyx3F_WECSim_LibInstanceStruct*)
                    chartInstanceVar)->S;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_WECSim_Lib_optimization_info();
    }

    finalize_c3_7vqb7o7CaUJzbPKhFMyx3F_WECSim_Lib
      ((SFc3_7vqb7o7CaUJzbPKhFMyx3F_WECSim_LibInstanceStruct*) chartInstanceVar);
    utFree(chartInstanceVar);
    if (crtInfo != NULL) {
      utFree(crtInfo);
    }

    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc3_7vqb7o7CaUJzbPKhFMyx3F_WECSim_Lib
    ((SFc3_7vqb7o7CaUJzbPKhFMyx3F_WECSim_LibInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c3_7vqb7o7CaUJzbPKhFMyx3F_WECSim_Lib(SimStruct *
  S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    initialize_params_c3_7vqb7o7CaUJzbPKhFMyx3F_WECSim_Lib
      ((SFc3_7vqb7o7CaUJzbPKhFMyx3F_WECSim_LibInstanceStruct*)
       (chartInfo->chartInstance));
  }
}

static void mdlSetWorkWidths_c3_7vqb7o7CaUJzbPKhFMyx3F_WECSim_Lib(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_WECSim_Lib_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,3);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(sf_get_instance_specialization(),
                infoStruct,3,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,3,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(sf_get_instance_specialization(),infoStruct,3);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 3, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 4, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,3,5);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,3,1);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=1; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 5; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,3);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(485299108U));
  ssSetChecksum1(S,(2857184328U));
  ssSetChecksum2(S,(936292758U));
  ssSetChecksum3(S,(2966929046U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c3_7vqb7o7CaUJzbPKhFMyx3F_WECSim_Lib(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c3_7vqb7o7CaUJzbPKhFMyx3F_WECSim_Lib(SimStruct *S)
{
  SFc3_7vqb7o7CaUJzbPKhFMyx3F_WECSim_LibInstanceStruct *chartInstance;
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)utMalloc(sizeof
    (ChartRunTimeInfo));
  chartInstance = (SFc3_7vqb7o7CaUJzbPKhFMyx3F_WECSim_LibInstanceStruct *)
    utMalloc(sizeof(SFc3_7vqb7o7CaUJzbPKhFMyx3F_WECSim_LibInstanceStruct));
  memset(chartInstance, 0, sizeof
         (SFc3_7vqb7o7CaUJzbPKhFMyx3F_WECSim_LibInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c3_7vqb7o7CaUJzbPKhFMyx3F_WECSim_Lib;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c3_7vqb7o7CaUJzbPKhFMyx3F_WECSim_Lib;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c3_7vqb7o7CaUJzbPKhFMyx3F_WECSim_Lib;
  chartInstance->chartInfo.enableChart =
    sf_opaque_enable_c3_7vqb7o7CaUJzbPKhFMyx3F_WECSim_Lib;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c3_7vqb7o7CaUJzbPKhFMyx3F_WECSim_Lib;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c3_7vqb7o7CaUJzbPKhFMyx3F_WECSim_Lib;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c3_7vqb7o7CaUJzbPKhFMyx3F_WECSim_Lib;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c3_7vqb7o7CaUJzbPKhFMyx3F_WECSim_Lib;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c3_7vqb7o7CaUJzbPKhFMyx3F_WECSim_Lib;
  chartInstance->chartInfo.mdlStart =
    mdlStart_c3_7vqb7o7CaUJzbPKhFMyx3F_WECSim_Lib;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c3_7vqb7o7CaUJzbPKhFMyx3F_WECSim_Lib;
  chartInstance->chartInfo.extModeExec = NULL;
  chartInstance->chartInfo.restoreLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.restoreBeforeLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.storeCurrentConfiguration = NULL;
  chartInstance->chartInfo.callAtomicSubchartUserFcn = NULL;
  chartInstance->chartInfo.callAtomicSubchartAutoFcn = NULL;
  chartInstance->chartInfo.debugInstance = sfGlobalDebugInstanceStruct;
  chartInstance->S = S;
  crtInfo->checksum = SF_RUNTIME_INFO_CHECKSUM;
  crtInfo->instanceInfo = (&(chartInstance->chartInfo));
  crtInfo->isJITEnabled = false;
  crtInfo->compiledInfo = NULL;
  ssSetUserData(S,(void *)(crtInfo));  /* register the chart instance with simstruct */
  init_dsm_address_info(chartInstance);
  init_simulink_io_address(chartInstance);
  if (!sim_mode_is_rtw_gen(S)) {
  }

  sf_opaque_init_subchart_simstructs(chartInstance->chartInfo.chartInstance);
  chart_debug_initialization(S,1);
}

void c3_7vqb7o7CaUJzbPKhFMyx3F_WECSim_Lib_method_dispatcher(SimStruct *S, int_T
  method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c3_7vqb7o7CaUJzbPKhFMyx3F_WECSim_Lib(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c3_7vqb7o7CaUJzbPKhFMyx3F_WECSim_Lib(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c3_7vqb7o7CaUJzbPKhFMyx3F_WECSim_Lib(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c3_7vqb7o7CaUJzbPKhFMyx3F_WECSim_Lib_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
