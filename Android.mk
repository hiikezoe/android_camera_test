# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#      http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
LOCAL_PATH:= $(call my-dir)

include $(CLEAR_VARS)

LOCAL_SRC_FILES := camera.cpp

LOCAL_MODULE := camera_test

LOCAL_MODULE_TAGS := optional

LOCAL_SHARED_LIBRARIES := libdl libutils

LOCAL_C_INCLUDES := frameworks/av/services/camera/libcameraservice

include $(BUILD_EXECUTABLE)

DLOPEN_LIBMMCAMERA:=1

include $(CLEAR_VARS)

LOCAL_CFLAGS :=                               \
  -DDLOPEN_LIBMMCAMERA=$(DLOPEN_LIBMMCAMERA)  \
  -DMSM_MAX_CAMERA_SENSORS=1                  \
  -DNUM_PREVIEW_BUFFERS=4

LOCAL_HAL_FILES :=            \
  QualcommCamera.cpp          \
  QualcommCameraHardware.cpp

LOCAL_SRC_FILES := $(LOCAL_HAL_FILES)


LOCAL_C_INCLUDES +=                      \
  hardware/qcom/display/libgralloc       \
  hardware/qcom/display/libgenlock       \
  hardware/qcom/media/libstagefrighthw   \
  device/panasonic/p01d/include/linux


LOCAL_SHARED_LIBRARIES:=  \
  libbinder               \
  libdl                   \
  libcamera_client        \
  liblog                  \
  libcutils

LOCAL_MODULE:= camera.$(TARGET_BOARD_PLATFORM)

LOCAL_MODULE_TAGS := optional

include $(BUILD_EXECUTABLE)
