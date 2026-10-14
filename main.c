
#include <psp2/kernel/processmgr.h>
#include <psp2/ctrl.h>
#include <psp2/debugScreen.h>

int main(void) {
    sceDebugScreenInit();
    sceCtrlSetSamplingMode(SCE_CTRL_MODE_ANALOG);

    sceDebugScreenPrintf("================================\n");
    sceDebugScreenPrintf("          BROWSERS\n");
    sceDebugScreenPrintf("================================\n");
    sceDebugScreenPrintf("      PS Vita Web Browser\n");
    sceDebugScreenPrintf("          Version 0.3\n");
    sceDebugScreenPrintf("--------------------------------\n\n");
    sceDebugScreenPrintf("  Welcome to Browsers!\n\n");
    sceDebugScreenPrintf("  Screen test successful!\n\n");
    sceDebugScreenPrintf("  Press X to exit\n");

    SceCtrlData pad;

    while (1) {
        sceCtrlPeekBufferPositive(0, &pad, 1);

        if (pad.buttons & SCE_CTRL_CROSS) {
            break;
        }

        sceKernelDelayThread(100000);
    }

    sceKernelExitProcess(0);
    return 0;
}
