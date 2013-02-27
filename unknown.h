#ifndef __UNKONWN_H__
#define __UNKONWN_H__

#include "QCamera_Intf.h"

typedef enum {
  CAMSTATS_TYPE,
} camstats_type;

typedef struct mm_camera_buffer {
  uint8_t *ptr;
  int32_t filled_size;
  int size;
  int fd;
  uint32_t offset;
} mm_camera_buffer_t;

typedef enum {
  CAMERA_PARM_PICT_SIZE,
  CAMERA_PARM_ZOOM_RATIO,
  CAMERA_PARM_HISTOGRAM,
  CAMERA_PARM_DIMENSION,
  CAMERA_PARM_FPS,
  CAMERA_PARM_FPS_MODE, /*5*/
  CAMERA_PARM_EFFECT,
  CAMERA_PARM_EXPOSURE_COMPENSATION,
  CAMERA_PARM_EXPOSURE,
  CAMERA_PARM_SHARPNESS,
  CAMERA_PARM_CONTRAST, /*10*/
  CAMERA_PARM_SATURATION,
  CAMERA_PARM_BRIGHTNESS,
  CAMERA_PARM_WHITE_BALANCE,
  CAMERA_PARM_LED_MODE,
  CAMERA_PARM_ANTIBANDING, /*15*/
  CAMERA_PARM_ROLLOFF,
  CAMERA_PARM_CONTINUOUS_AF,
  CAMERA_PARM_FOCUS_RECT,
  CAMERA_PARM_AEC_ROI,
  CAMERA_PARM_AF_ROI, /*20*/
  CAMERA_PARM_HJR,
  CAMERA_PARM_ISO,
  CAMERA_PARM_BL_DETECTION,
  CAMERA_PARM_SNOW_DETECTION,
  CAMERA_PARM_BESTSHOT_MODE, /*25*/
  CAMERA_PARM_ZOOM,
  CAMERA_PARM_VIDEO_DIS,
  CAMERA_PARM_VIDEO_ROT,
  CAMERA_PARM_SCE_FACTOR,
  CAMERA_PARM_FD, /*30*/
  CAMERA_PARM_MODE,
  /* 2nd 32 bits */
  CAMERA_PARM_3D_FRAME_FORMAT,
  CAMERA_PARM_CAMERA_ID,
  CAMERA_PARM_CAMERA_INFO,
  CAMERA_PARM_PREVIEW_SIZE, /*35*/
  CAMERA_PARM_QUERY_FALSH4SNAP,
  CAMERA_PARM_FOCUS_DISTANCES,
  CAMERA_PARM_BUFFER_INFO,
  CAMERA_PARM_JPEG_ROTATION,
  CAMERA_PARM_JPEG_MAINIMG_QUALITY, /* 40 */
  CAMERA_PARM_JPEG_THUMB_QUALITY,
  CAMERA_PARM_ZSL_ENABLE,
  CAMERA_PARM_FOCAL_LENGTH,
  CAMERA_PARM_HORIZONTAL_VIEW_ANGLE,
  CAMERA_PARM_VERTICAL_VIEW_ANGLE, /* 45 */
  CAMERA_PARM_MCE,
  CAMERA_PARM_RESET_LENS_TO_INFINITY,
  CAMERA_PARM_SNAPSHOTDATA,
  CAMERA_PARM_HFR,
  CAMERA_PARM_REDEYE_REDUCTION, /* 50 */
  CAMERA_PARM_WAVELET_DENOISE,
  CAMERA_PARM_3D_DISPLAY_DISTANCE,
  CAMERA_PARM_3D_VIEW_ANGLE,
  CAMERA_PARM_PREVIEW_FORMAT,
  CAMERA_PARM_RDI_FORMAT,
  CAMERA_PARM_HFR_SIZE, /* 55 */
  CAMERA_PARM_3D_EFFECT,
  CAMERA_PARM_3D_MANUAL_CONV_RANGE,
  CAMERA_PARM_3D_MANUAL_CONV_VALUE,
  CAMERA_PARM_ENABLE_3D_MANUAL_CONVERGENCE,
  /* These are new parameters defined here */
  CAMERA_PARM_CH_IMAGE_FMT, /* 60 */       // mm_camera_ch_image_fmt_parm_t
  CAMERA_PARM_OP_MODE,             // camera state, sub state also
  CAMERA_PARM_SHARPNESS_CAP,       //
  CAMERA_PARM_SNAPSHOT_BURST_NUM,  // num shots per snapshot action
  CAMERA_PARM_LIVESHOT_MAIN,       // enable/disable full size live shot
  CAMERA_PARM_MAXZOOM, /* 65 */
  CAMERA_PARM_LUMA_ADAPTATION,     // enable/disable
  CAMERA_PARM_HDR,
  CAMERA_PARM_CROP,
  CAMERA_PARM_MAX_PICTURE_SIZE,
  CAMERA_PARM_MAX_PREVIEW_SIZE, /* 70 */
  CAMERA_PARM_ASD_ENABLE,
  CAMERA_PARM_RECORDING_HINT,
  CAMERA_PARM_CAF_ENABLE,
  CAMERA_PARM_FULL_LIVESHOT,
  CAMERA_PARM_DIS_ENABLE, /* 75 */
  CAMERA_PARM_AEC_LOCK,
  CAMERA_PARM_AWB_LOCK,
  CAMERA_PARM_AF_MTR_AREA,
  CAMERA_PARM_AEC_MTR_AREA,
  CAMERA_PARM_LOW_LIGHT_FOR_ZSL,
  CAMERA_PARM_LOW_POWER_MODE,
  CAMERA_PARM_MAX_HFR_MODE, /* 80 */
  CAMERA_PARM_MAX_VIDEO_SIZE,
  CAMERA_PARM_DEF_PREVIEW_SIZES,
  CAMERA_PARM_DEF_VIDEO_SIZES,
  CAMERA_PARM_DEF_THUMB_SIZES,
  CAMERA_PARM_DEF_HFR_SIZES,
  CAMERA_PARM_PREVIEW_SIZES_CNT,
  CAMERA_PARM_VIDEO_SIZES_CNT,
  CAMERA_PARM_THUMB_SIZES_CNT,
  CAMERA_PARM_HFR_SIZES_CNT,
  CAMERA_PARM_GRALLOC_USAGE,
  CAMERA_PARM_VFE_OUTPUT_ENABLE, //to check whether both oputputs are
  CAMERA_PARM_DEFAULT_PREVIEW_WIDTH,
  CAMERA_PARM_DEFAULT_PREVIEW_HEIGHT,
  CAMERA_PARM_FOCUS_MODE,
  CAMERA_PARM_HFR_FRAME_SKIP,
  CAMERA_PARM_CH_INTERFACE,
  //or single output enabled to differentiate 7x27a with others
  CAMERA_PARM_BESTSHOT_RECONFIGURE,
  CAMERA_PARM_MAX_NUM_FACES_DECT,
  CAMERA_PARM_FPS_RANGE,
  CAMERA_PARM_CID,
  CAMERA_PARM_FRAME_RESOLUTION,
  CAMERA_PARM_RAW_SNAPSHOT_FMT,
  CAMERA_PARM_FACIAL_FEATURE_INFO,
  CAMERA_PARM_CAF_LOCK_CANCEL,
#ifdef FAST_AF
  CAMERA_PARM_CAF_TYPE,
#endif
  CAMERA_PARM_LUX_IDX,
  CAMERA_PARM_GET_AF_STATUS,
  CAMERA_PARM_CHECK_AF_RETRY,
  CAMERA_PARM_LG_CAF_LOCK,
  CAMERA_PARM_INFORM_STARTPRVIEW,
  CAMERA_PARM_MAX
} camera_parm_type_t;

typedef enum {
  MM_CAMERA_SUCCESS,
  MM_CAMERA_ERR_GENERAL,
  MM_CAMERA_ERR_NO_MEMORY,
  MM_CAMERA_ERR_NOT_SUPPORTED,
  MM_CAMERA_ERR_INVALID_INPUT,
  MM_CAMERA_ERR_INVALID_OPERATION,
  MM_CAMERA_ERR_ENCODE,
  MM_CAMERA_ERR_BUFFER_REG,
  MM_CAMERA_ERR_PMEM_ALLOC,
  MM_CAMERA_ERR_CAPTURE_FAILED,
  MM_CAMERA_ERR_CAPTURE_TIMEOUT,
} mm_camera_status_t;

typedef struct {
  mm_camera_status_t (*mm_camera_query_parms) (camera_parm_type_t parm_type,
                                               void **values, uint32_t *count);
  mm_camera_status_t (*mm_camera_set_parm)    (camera_parm_type_t parm_type,
                                               void *value);
  mm_camera_status_t(*mm_camera_get_parm)     (camera_parm_type_t parm_type,
                                               void *value);
  int8_t (*mm_camera_is_supported)            (camera_parm_type_t parm_type);
  int8_t (*mm_camera_is_parm_supported)       (camera_parm_type_t parm_type,
                                               void *sub_parm);
} mm_camera_config;

typedef enum {
  LIVESHOT_SUCCESS,
  LIVESHOT_ENCODE_ERROR,
  LIVESHOT_UNKNOWN_ERROR,
} liveshot_status;

typedef enum {
  SNAPSHOT_DONE,
  SNAPSHOT_FAILED,
  JPEG_ENC_DONE,
  JPEG_ENC_FAILED
} mm_camera_event_type;

typedef struct {
  mm_camera_event_type event_type;
  union {
    msm_frame *yuv_frames;
    mm_camera_buffer_t *encoded_frame;
  } event_data;
} mm_camera_event;

typedef struct {
  void (*preview_frame_cb)  (struct msm_frame *frame);
  void (*on_liveshot_event) (liveshot_status status, uint32_t jpeg_size);
  void (*camstats_cb)       (camstats_type stype, camera_preview_histogram_info *histinfo);
  void (*video_frame_cb)    (struct msm_frame *frame);
  int8_t (*on_event)        (mm_camera_event *event);
  void (*on_error_event)    (camera_error_type err);
} mm_camera_notify;

#endif /* __UNKONWN_H__ */
