/*
 *<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<    STD_TYPES.h    >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 *
 *  Author : Tawfik tamer ibrahim
 *  Layer  : LIB
 *
 */ 

#ifndef STD_TYPES_H_
#define STD_TYPES_H_

/* Boolean Data Type */
typedef unsigned char boolean;

/* Boolean Values */
#ifndef FALSE
#define FALSE       (0u)
#endif
#ifndef TRUE
#define TRUE        (1u)
#endif


typedef enum                 //it should be before functions prototypes
	{
		 NOK,
		 OK,
		 TIMEOUT_STATE,
		 BUSY_STATE,
		 NULL_POINTER
	}ErrorStatus;


typedef enum                
	{
		BUSY,
		IDLE
	}CompilingStatus;



#define LOGIC_HIGH        (1u)
#define LOGIC_LOW         (0u)

#define NULL        ((void*)0)

typedef unsigned char         u8;          /*           0 .. 255              */
typedef signed char           s8;          /*        -128 .. +127             */
typedef unsigned short        u16;         /*           0 .. 65535            */
typedef signed short          s16;         /*      -32768 .. +32767           */
typedef unsigned long         u32;         /*           0 .. 4294967295       */
typedef signed long           s32;         /* -2147483648 .. +2147483647      */
typedef unsigned long long    u64;         /*       0 .. 18446744073709551615  */
typedef signed long long      s64;         /* -9223372036854775808 .. 9223372036854775807 */
typedef float                 f32;
typedef double                f64;

#endif /* STD_TYPE_H_ */
