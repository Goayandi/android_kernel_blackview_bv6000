#
# Copyright (C) 2015 MediaTek Inc.
#
# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License version 2 as
# published by the Free Software Foundation.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
# GNU General Public License for more details.
#

# In case the platform does NOT support this type of sensors
ccflags-y += -I$(srctree)/drivers/misc/mediatek/hwmon/include

obj-y	+= step_counter.o
obj-$(CONFIG_MTK_LSM6DS3GY)   +=  lsm6ds3_sc.o
obj-$(CONFIG_MTK_MPU6050GY_NEW) += mpu6050_sc/

ifeq ($(CONFIG_MTK_SCP_SENSORHUB_V1),y)
obj-$(CONFIG_MTK_STEPSIGNHUB)		+=	stepsignhub/
endif

ifeq ($(CONFIG_CUSTOM_KERNEL_STEP_COUNTER),"OTHER_VENDOR")
obj-y += other_vendor/
endif
