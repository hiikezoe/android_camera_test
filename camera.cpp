#include <stdio.h>
#include <dlfcn.h>
#include <stdlib.h>

#include <utils/RefBase.h>
#include <CameraHardwareInterface.h>

struct stock_camera_info {
    int facing;
    int mode;
    int orientation;
};

int (*LINK_getNumberOfCameras)(void);
void (*LINK_getCameraInfo)(int cameraId, struct stock_camera_info *info);
android::sp<android::CameraHardwareInterface> (*LINK_openCameraHardware)(int id, int mode, int what);

static void *libcamera;

static int
load_symbols(void)
{
    libcamera = dlopen("libcamera.so", 1);
    *(void**)&LINK_getNumberOfCameras = dlsym(libcamera, "HAL_getNumberOfCameras");
    *(void**)&LINK_getCameraInfo = dlsym(libcamera, "HAL_getCameraInfo");
    *(void**)&LINK_openCameraHardware = dlsym(libcamera, "HAL_openCameraHardware");
    return 0;
}

int
main(int argc, char **argv)
{
    load_symbols();

    int n = LINK_getNumberOfCameras();
    printf("number of cameras = %d\n", n);
    if (n == 0)
        exit(EXIT_FAILURE);

    struct stock_camera_info stock_info;
    LINK_getCameraInfo(0, &stock_info);
    printf("facing = %d, orientation = %d, mode = %d\n",
           stock_info.facing, stock_info.orientation, stock_info.mode);

    int mode = 1;
    int what = 0;
    if (argv[1])
        mode = atoi(argv[1]);
    if (argv[2])
        what = atoi(argv[2]);

    android::sp<android::CameraHardwareInterface> camera;
    camera = LINK_openCameraHardware(0, mode, what);
    if (camera == 0) {
        printf("failed open camera hardware\n");
        dlclose(libcamera);
        return -1;
    }

    printf("------------------------- start preview ------------------------------------------\n");
    camera->startPreview();
    while (true) {
    }
    dlclose(libcamera);

    exit(EXIT_SUCCESS);
}

/*
vi:ts=4:nowrap:ai:expandtab:sw=4
*/
