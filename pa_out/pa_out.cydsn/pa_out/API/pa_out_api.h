#ifndef __`$INSTANCE_NAME`_H__
#define __`$INSTANCE_NAME`_H__

#ifndef __PA_OUT_DEFINED__
#define __PA_OUT_DEFINED__

#define SEG_0   (SEG_LA | SEG_LB | SEG_LC | SEG_LD | SEG_LE | SEG_LF)
#define SEG_1   (SEG_LB | SEG_LC)
#define SEG_2   (SEG_LA | SEG_LB | SEG_LD | SEG_LE | SEG_LG)
#define SEG_3   (SEG_LA | SEG_LB | SEG_LC | SEG_LD | SEG_LG)
#define SEG_4   (SEG_LB | SEG_LC | SEG_LF | SEG_LG)
#define SEG_5   (SEG_LA | SEG_LC | SEG_LD | SEG_LF | SEG_LG)
#define SEG_6   (SEG_LA | SEG_LC | SEG_LD | SEG_LE | SEG_LF | SEG_LG)
#define SEG_7   (SEG_LA | SEG_LB | SEG_LC | SEG_LF)
#define SEG_8   (SEG_LA | SEG_LB | SEG_LC | SEG_LD | SEG_LE | SEG_LF | SEG_LG)
#define SEG_9   (SEG_LA | SEG_LB | SEG_LC | SEG_LD | SEG_LF | SEG_LG)

#endif

#define `$INSTANCE_NAME`_SetValue(v) CY_SET_REG8(`$INSTANCE_NAME`_dp__A0_REG, v)

#endif