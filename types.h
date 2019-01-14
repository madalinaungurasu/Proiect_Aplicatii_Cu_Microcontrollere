/*
 * types.h
 *
 *  Created on: October 26, 2016
 *      Author: Alex Costache
 */
#ifndef SW_TYPES_H_
#define SW_TYPES_H_

/*Typedefs*/

/*Standard types for variables to be used inside the project*/
typedef uint8_t  UI8;
typedef uint16_t UI16;
typedef uint32_t UI32;

typedef enum {
   FALSE = 0u,
   TRUE = 1u
} teBoolType;

typedef enum {
   STD_LOW = 0u,
   STD_HIGH = 1u
} tePinValue;

typedef enum
{
    INVALID = 0u,
    VALID   = 1u
} tValidInfo;

typedef enum
{
    NOT_PRESSED = 0u,
    PRESSED     = 1u
} tBtnState;

/*Global defines*/


/*Global functions*/


#endif /* SW_TYPES_H_ */
