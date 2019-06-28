#ifndef __`$INSTANCE_NAME`_H__
#define __`$INSTANCE_NAME`_H__

#define `$INSTANCE_NAME`_enable()  *((reg8*)`$INSTANCE_NAME`_DataCounter__CONTROL_AUX_CTL_REG) |= 0x20

#endif