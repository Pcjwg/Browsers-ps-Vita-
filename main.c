
#include <psp2/kernel/processmgr.h>
#include <psp2/ctrl.h>
#include <psp2/display.h>
#include <psp2/apputil.h>
#include <stdio.h>
#include <string.h>

int main(void) {
    sceCtrlSetSamplingMode(SCE_CTRL_MODE_ANALOG);

    printf("\n");
    printf("================================\n");
    printf("          BROWSERS\n");
    printf("================================\n");
    printf("      PS Vita Web Browser\n");
    printf("            Version 0.2\n");
    printf("--------------------------------\n");
    printf("\n");
    printf("  Welcome to Browsers!\n");
    printf("\n");
    printf("  Browser project started.\n");
    printf("\n");
    printf("  Next goals:\n");
    printf("  - Address bar\n");
    printf("  - Open websites\n");
    printf("  - Browse the Internet\n");
    printf("\n");
    printf("================================\n");
    printf("  Press X to exit\n");

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
