#include <stdio.h>
#include <stdlib.h>

#include "QualcommCamera.h"
#include "QualcommCameraHardware.h"
#include <utils/RefBase.h>

static void
release_memory(struct camera_memory *mem)
{
    if (mem->data)
        free(mem->data);
    free(mem);
}

static camera_memory_t*
get_memory(int fd, size_t buf_size, uint_t num_bufs, void *user)
{
    void *m = malloc(buf_size * num_bufs);
    if (!m)
        return NULL;

    camera_memory_t *camera_memory;
    camera_memory = (camera_memory_t*)malloc(sizeof(camera_memory_t));
    camera_memory->size = buf_size * num_bufs;
    camera_memory->data = m;
    camera_memory->handle = camera_memory;
    camera_memory->release = release_memory;

    return camera_memory;
}

static void
notify_callback(int32_t msg_type, int32_t ext1, int32_t ext2, void* user)
{
    printf("%s (%d)\n", __PRETTY_FUNCTION__, msg_type);
}

static void
data_callback(int32_t msg_type, const camera_memory_t *data, unsigned int index,
              camera_frame_metadata_t *metadata, void *user)
{
    printf("%s (%d)\n", __PRETTY_FUNCTION__, msg_type);
}

static void
data_timestamp_callback(int64_t timestamp,
                        int32_t msg_type,
                        const camera_memory_t *data, unsigned int index,
                        void *user)
{
    printf("%s (%d)\n", __PRETTY_FUNCTION__, msg_type);
}

int
main(int argc, char **argv)
{
    int n = android::HAL_getNumberOfCameras();
    printf("number of cameras = %d\n", n);
    if (n == 0)
        exit(EXIT_FAILURE);

    struct android::CameraInfo camera_info;
    android::HAL_getCameraInfo(0, &camera_info);
    printf("facing = %d, orientation = %d, mode = %d\n",
           camera_info.facing, camera_info.orientation, camera_info.mode);

    android::QualcommCameraHardware* camera;
    camera = android::HAL_openCameraHardware(0);
    if (camera == 0) {
        printf("failed open camera hardware\n");
        exit(EXIT_FAILURE);
    }

    printf("------------------------- start preview ------------------------------------------\n");
    camera->setCallbacks(notify_callback, data_callback, data_timestamp_callback, get_memory, 0);
    camera->enableMsgType(CAMERA_MSG_COMPRESSED_IMAGE);
    camera->startPreview();
    sleep(2);
    printf("------------------------- take picture ------------------------------------------\n");
    camera->takePicture();
    printf("------------------------- stop preview ------------------------------------------\n");
    camera->stopPreview();

    exit(EXIT_SUCCESS);
}

/*
vi:ts=4:nowrap:ai:expandtab:sw=4
*/
