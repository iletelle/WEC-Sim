#include "__cf_foswec.h"
#include <math.h>
#include <string.h>
#include "pm_std.h"
#include "sm_std.h"
#include "sm_ssci_run_time_errors.h"
PmfMessageId foswec_4deb2608_1_outputDyn ( const double * state , const
double * input , const double * inputDot , const double * inputDdot , const
double * discreteState , double * deriv , double * output , int * derivErr ,
NeuDiagnosticManager * neDiagMgr ) { double xx [ 70 ] ; int ii [ 6 ] ; ( void
) inputDot ; ( void ) inputDdot ; ( void ) discreteState ; ( void ) neDiagMgr
; ( void ) derivErr ; xx [ 0 ] = 3.552713678800501e-15 ; xx [ 1 ] = 0.5 ; xx
[ 2 ] = xx [ 1 ] * state [ 0 ] ; xx [ 3 ] = cos ( xx [ 2 ] ) ; xx [ 4 ] = sin
( xx [ 2 ] ) ; xx [ 2 ] = xx [ 4 ] * input [ 0 ] ; xx [ 5 ] = xx [ 4 ] *
input [ 2 ] ; xx [ 7 ] = 2.0 ; xx [ 9 ] = input [ 2 ] - ( xx [ 3 ] * xx [ 2 ]
+ xx [ 5 ] * xx [ 4 ] ) * xx [ 7 ] ; xx [ 6 ] = input [ 4 ] - xx [ 0 ] * xx [
9 ] ; xx [ 10 ] = input [ 0 ] + xx [ 7 ] * ( xx [ 3 ] * xx [ 5 ] - xx [ 2 ] *
xx [ 4 ] ) ; xx [ 2 ] = 9.360000000000001 ; xx [ 5 ] = 7.589466606277583e8 ;
ii [ 0 ] = 0 ; memcpy ( xx + 8 , xx + 5 , 1 * sizeof ( double ) ) ; memcpy (
ii + 3 , ii + 0 , 1 * sizeof ( int ) ) ; ii [ 2 ] = factorSymmetric ( xx + 8
, 1 , xx + 13 , xx + 12 , ii + 3 , ii + 4 ) ; ii [ 2 ] = factorSymmetric ( xx
+ 5 , 1 , xx + 12 , xx + 8 , ii + 3 , ii + 5 ) ; if ( ii [ 5 ] != 0 ) *
derivErr = 1 ; xx [ 8 ] = ( xx [ 6 ] + xx [ 10 ] * xx [ 2 ] ) / xx [ 5 ] ; xx
[ 5 ] = xx [ 1 ] * state [ 2 ] ; xx [ 1 ] = cos ( xx [ 5 ] ) ; xx [ 11 ] =
sin ( xx [ 5 ] ) ; xx [ 5 ] = xx [ 11 ] * input [ 8 ] ; xx [ 12 ] = xx [ 11 ]
* input [ 6 ] ; xx [ 14 ] = input [ 6 ] + xx [ 7 ] * ( xx [ 1 ] * xx [ 5 ] -
xx [ 12 ] * xx [ 11 ] ) ; xx [ 13 ] = 8.881784197001335e-16 ; xx [ 16 ] =
3.552713678800499e-15 ; xx [ 17 ] = input [ 8 ] - ( xx [ 1 ] * xx [ 12 ] + xx
[ 5 ] * xx [ 11 ] ) * xx [ 7 ] ; xx [ 5 ] = xx [ 14 ] * xx [ 13 ] + xx [ 16 ]
* xx [ 17 ] + input [ 10 ] ; xx [ 12 ] = 7.589454010661583e8 ; memcpy ( xx +
18 , xx + 12 , 1 * sizeof ( double ) ) ; memcpy ( ii + 3 , ii + 0 , 1 *
sizeof ( int ) ) ; ii [ 2 ] = factorSymmetric ( xx + 18 , 1 , xx + 20 , xx +
19 , ii + 3 , ii + 4 ) ; ii [ 1 ] = factorSymmetric ( xx + 12 , 1 , xx + 19 ,
xx + 18 , ii + 3 , ii + 2 ) ; if ( ii [ 2 ] != 0 ) * derivErr = 1 ; xx [ 18 ]
= ( xx [ 5 ] + xx [ 14 ] * xx [ 2 ] ) / xx [ 12 ] ; deriv [ 0 ] = state [ 1 ]
; deriv [ 1 ] = - xx [ 8 ] ; deriv [ 2 ] = state [ 3 ] ; deriv [ 3 ] = - xx [
18 ] ; xx [ 12 ] = xx [ 11 ] * input [ 9 ] ; xx [ 15 ] = xx [ 11 ] * input [
11 ] ; xx [ 19 ] = input [ 11 ] - ( xx [ 1 ] * xx [ 12 ] + xx [ 15 ] * xx [
11 ] ) * xx [ 7 ] - xx [ 16 ] * input [ 7 ] ; xx [ 20 ] = xx [ 19 ] * xx [ 11
] ; xx [ 22 ] = input [ 9 ] + xx [ 7 ] * ( xx [ 1 ] * xx [ 15 ] - xx [ 12 ] *
xx [ 11 ] ) - xx [ 13 ] * input [ 7 ] ; xx [ 12 ] = xx [ 11 ] * xx [ 22 ] ;
xx [ 15 ] = 6.1 ; xx [ 24 ] = 9.359999999999999 ; xx [ 25 ] = xx [ 24 ] * xx
[ 11 ] ; xx [ 27 ] = xx [ 15 ] - xx [ 7 ] * xx [ 25 ] * xx [ 11 ] ; xx [ 26 ]
= xx [ 4 ] * input [ 3 ] ; xx [ 29 ] = xx [ 4 ] * input [ 5 ] ; xx [ 31 ] =
xx [ 0 ] * input [ 1 ] + input [ 5 ] - ( xx [ 3 ] * xx [ 26 ] + xx [ 29 ] *
xx [ 4 ] ) * xx [ 7 ] ; xx [ 30 ] = xx [ 31 ] * xx [ 4 ] ; xx [ 32 ] = input
[ 3 ] + xx [ 7 ] * ( xx [ 3 ] * xx [ 29 ] - xx [ 26 ] * xx [ 4 ] ) ; xx [ 26
] = xx [ 32 ] * xx [ 4 ] ; xx [ 29 ] = xx [ 24 ] * xx [ 4 ] ; xx [ 24 ] = xx
[ 15 ] - xx [ 7 ] * xx [ 29 ] * xx [ 4 ] ; xx [ 15 ] = 8.563766840475011e7 *
xx [ 18 ] - xx [ 5 ] ; xx [ 34 ] = 7.685319105e6 ; xx [ 35 ] = xx [ 2 ] * xx
[ 18 ] ; xx [ 37 ] = xx [ 14 ] - xx [ 34 ] * xx [ 35 ] ; xx [ 14 ] = xx [ 37
] * xx [ 11 ] ; xx [ 36 ] = state [ 3 ] * state [ 3 ] ; xx [ 38 ] = xx [ 2 ]
* xx [ 36 ] ; xx [ 40 ] = xx [ 34 ] * xx [ 38 ] + xx [ 17 ] ; xx [ 17 ] = xx
[ 11 ] * xx [ 40 ] ; xx [ 34 ] = xx [ 7 ] * ( xx [ 14 ] * xx [ 11 ] + xx [ 1
] * xx [ 17 ] ) - xx [ 37 ] ; xx [ 39 ] = 20.0 ; xx [ 41 ] = xx [ 39 ] - xx [
7 ] * xx [ 1 ] * xx [ 25 ] ; xx [ 42 ] = xx [ 40 ] + ( xx [ 1 ] * xx [ 14 ] -
xx [ 17 ] * xx [ 11 ] ) * xx [ 7 ] ; xx [ 14 ] = 8.563927840475017e7 * xx [ 8
] - xx [ 6 ] ; xx [ 6 ] = 7.685315105e6 ; xx [ 17 ] = xx [ 2 ] * xx [ 8 ] ;
xx [ 44 ] = xx [ 10 ] - xx [ 6 ] * xx [ 17 ] ; xx [ 10 ] = xx [ 44 ] * xx [ 4
] ; xx [ 45 ] = state [ 1 ] * state [ 1 ] ; xx [ 46 ] = xx [ 2 ] * xx [ 45 ]
; xx [ 48 ] = xx [ 6 ] * xx [ 46 ] + xx [ 9 ] ; xx [ 9 ] = xx [ 4 ] * xx [ 48
] ; xx [ 47 ] = xx [ 7 ] * ( xx [ 10 ] * xx [ 4 ] + xx [ 3 ] * xx [ 9 ] ) -
xx [ 44 ] ; xx [ 6 ] = xx [ 39 ] + xx [ 7 ] * xx [ 3 ] * xx [ 29 ] ; xx [ 49
] = xx [ 48 ] + ( xx [ 3 ] * xx [ 10 ] - xx [ 9 ] * xx [ 4 ] ) * xx [ 7 ] ;
xx [ 9 ] = 0.7071067811865476 ; xx [ 10 ] = xx [ 9 ] * xx [ 3 ] ; xx [ 51 ] =
xx [ 9 ] * xx [ 4 ] ; xx [ 53 ] = xx [ 10 ] ; xx [ 54 ] = xx [ 10 ] ; xx [ 55
] = xx [ 51 ] ; xx [ 56 ] = - xx [ 51 ] ; xx [ 10 ] = 3.26 ; xx [ 51 ] = xx [
10 ] + xx [ 24 ] ; xx [ 52 ] = xx [ 6 ] - xx [ 39 ] ; xx [ 57 ] = xx [ 4 ] *
xx [ 52 ] ; xx [ 59 ] = xx [ 4 ] * xx [ 51 ] ; xx [ 61 ] = xx [ 51 ] + ( xx [
3 ] * xx [ 57 ] - xx [ 59 ] * xx [ 4 ] ) * xx [ 7 ] ; xx [ 51 ] = xx [ 52 ] -
xx [ 7 ] * ( xx [ 3 ] * xx [ 59 ] + xx [ 57 ] * xx [ 4 ] ) ; xx [ 57 ] = - (
xx [ 32 ] - xx [ 61 ] * input [ 1 ] ) ; xx [ 58 ] = xx [ 14 ] - ( xx [ 44 ] *
xx [ 61 ] + xx [ 51 ] * xx [ 48 ] ) ; xx [ 59 ] = xx [ 51 ] * input [ 1 ] -
xx [ 31 ] ; pm_math_quatInverseXform ( xx + 53 , xx + 57 , xx + 60 ) ; xx [
33 ] = 0.0 ; xx [ 57 ] = - xx [ 44 ] ; xx [ 58 ] = - input [ 1 ] ; xx [ 59 ]
= - xx [ 48 ] ; pm_math_quatInverseXform ( xx + 53 , xx + 57 , xx + 62 ) ; xx
[ 44 ] = xx [ 9 ] * xx [ 1 ] ; xx [ 51 ] = xx [ 9 ] * xx [ 11 ] ; xx [ 53 ] =
xx [ 44 ] ; xx [ 54 ] = xx [ 44 ] ; xx [ 55 ] = xx [ 51 ] ; xx [ 56 ] = - xx
[ 51 ] ; xx [ 9 ] = xx [ 10 ] + xx [ 27 ] ; xx [ 10 ] = xx [ 39 ] - xx [ 41 ]
; xx [ 29 ] = xx [ 11 ] * xx [ 10 ] ; xx [ 39 ] = xx [ 11 ] * xx [ 9 ] ; xx [
44 ] = xx [ 9 ] + ( xx [ 1 ] * xx [ 29 ] - xx [ 39 ] * xx [ 11 ] ) * xx [ 7 ]
; xx [ 9 ] = xx [ 10 ] - xx [ 7 ] * ( xx [ 1 ] * xx [ 39 ] + xx [ 29 ] * xx [
11 ] ) ; xx [ 57 ] = - ( xx [ 22 ] - xx [ 44 ] * input [ 7 ] ) ; xx [ 58 ] =
xx [ 15 ] - ( xx [ 37 ] * xx [ 44 ] + xx [ 9 ] * xx [ 40 ] ) ; xx [ 59 ] = xx
[ 9 ] * input [ 7 ] - xx [ 19 ] ; pm_math_quatInverseXform ( xx + 53 , xx +
57 , xx + 65 ) ; xx [ 57 ] = - xx [ 37 ] ; xx [ 58 ] = - input [ 7 ] ; xx [
59 ] = - xx [ 40 ] ; pm_math_quatInverseXform ( xx + 53 , xx + 57 , xx + 67 )
; xx [ 9 ] = xx [ 0 ] * xx [ 45 ] - xx [ 17 ] ; xx [ 10 ] = xx [ 9 ] * xx [ 4
] ; xx [ 17 ] = xx [ 46 ] + xx [ 0 ] * xx [ 8 ] ; xx [ 0 ] = xx [ 4 ] * xx [
17 ] ; xx [ 23 ] = xx [ 13 ] * xx [ 18 ] + xx [ 35 ] + xx [ 16 ] * xx [ 36 ]
; xx [ 29 ] = xx [ 16 ] * xx [ 18 ] - xx [ 38 ] - xx [ 13 ] * xx [ 36 ] ; xx
[ 16 ] = xx [ 11 ] * xx [ 29 ] ; xx [ 36 ] = xx [ 11 ] * xx [ 23 ] ; output [
0 ] = ( xx [ 1 ] * xx [ 20 ] + xx [ 12 ] * xx [ 11 ] ) * xx [ 7 ] - xx [ 22 ]
+ xx [ 27 ] * input [ 7 ] - input [ 15 ] + ( xx [ 3 ] * xx [ 30 ] + xx [ 26 ]
* xx [ 4 ] ) * xx [ 7 ] - xx [ 32 ] + xx [ 24 ] * input [ 1 ] ; output [ 1 ]
= xx [ 15 ] + xx [ 27 ] * xx [ 34 ] + xx [ 41 ] * xx [ 42 ] - input [ 16 ] +
xx [ 14 ] + xx [ 24 ] * xx [ 47 ] - xx [ 6 ] * xx [ 49 ] ; output [ 2 ] = xx
[ 7 ] * ( xx [ 20 ] * xx [ 11 ] - xx [ 1 ] * xx [ 12 ] ) - xx [ 19 ] - xx [
41 ] * input [ 7 ] - input [ 17 ] + xx [ 7 ] * ( xx [ 30 ] * xx [ 4 ] - xx [
3 ] * xx [ 26 ] ) - xx [ 31 ] + xx [ 6 ] * input [ 1 ] ; output [ 3 ] = xx [
34 ] - input [ 12 ] + xx [ 47 ] ; output [ 4 ] = - ( input [ 13 ] + input [ 7
] + input [ 1 ] ) ; output [ 5 ] = - ( xx [ 42 ] + input [ 14 ] + xx [ 49 ] )
; output [ 8 ] = xx [ 60 ] ; output [ 9 ] = xx [ 61 ] ; output [ 10 ] = xx [
33 ] ; output [ 11 ] = xx [ 62 ] ; output [ 12 ] = xx [ 63 ] ; output [ 13 ]
= xx [ 64 ] ; output [ 16 ] = xx [ 65 ] ; output [ 17 ] = xx [ 66 ] ; output
[ 18 ] = xx [ 33 ] ; output [ 19 ] = xx [ 67 ] ; output [ 20 ] = xx [ 68 ] ;
output [ 21 ] = xx [ 69 ] ; output [ 29 ] = xx [ 33 ] ; output [ 30 ] = xx [
8 ] ; output [ 31 ] = xx [ 33 ] ; output [ 38 ] = xx [ 7 ] * ( xx [ 10 ] * xx
[ 4 ] + xx [ 3 ] * xx [ 0 ] ) - xx [ 9 ] ; output [ 39 ] = xx [ 33 ] ; output
[ 40 ] = - ( xx [ 17 ] + ( xx [ 3 ] * xx [ 10 ] - xx [ 0 ] * xx [ 4 ] ) * xx
[ 7 ] ) ; output [ 48 ] = xx [ 33 ] ; output [ 49 ] = xx [ 18 ] ; output [ 50
] = xx [ 33 ] ; output [ 57 ] = xx [ 23 ] - ( xx [ 1 ] * xx [ 16 ] + xx [ 36
] * xx [ 11 ] ) * xx [ 7 ] ; output [ 58 ] = xx [ 33 ] ; output [ 59 ] = xx [
29 ] + xx [ 7 ] * ( xx [ 1 ] * xx [ 36 ] - xx [ 16 ] * xx [ 11 ] ) ; output [
67 ] = xx [ 33 ] ; output [ 68 ] = xx [ 33 ] ; output [ 69 ] = xx [ 33 ] ;
output [ 76 ] = xx [ 33 ] ; output [ 77 ] = xx [ 33 ] ; output [ 78 ] = xx [
33 ] ; return NULL ; }
