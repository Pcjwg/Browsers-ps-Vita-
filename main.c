
#include <psp2/ctrl.h>
#include <psp2/kernel/processmgr.h>
#include <vita2d.h>

int main(void) {
    SceCtrlData pad;

    vita2d_init();
    vita2d_set_clear_color(RGBA8(18, 24, 38, 255));

    vita2d_pgf *font = vita2d_load_default_pgf();

    while (1) {
        sceCtrlPeekBufferPositive(0, &pad, 1);

        vita2d_start_drawing();
        vita2d_clear_screen();

        if (font != NULL) {
            vita2d_pgf_draw_text(
                font, 50, 100,
                RGBA8(255, 255, 255, 255),
                1.5f, "BROWSERS"
            );

            vita2d_pgf_draw_text(
                font, 50, 160,
                RGBA8(100, 220, 255, 255),
                1.0f, "PS Vita Browser - Version 0.3"
            );

            vita2d_pgf_draw_text(
                font, 50, 220,
                RGBA8(255, 255, 255, 255),
                1.0f, "Screen test successful!"
            );

            vita2d_pgf_draw_text(
                font, 50, 300,
                RGBA8(255, 220, 100, 255),
                1.0f, "Press X to exit"
            );
        }

        vita2d_end_drawing();
        vita2d_swap_buffers();

        if (pad.buttons & SCE_CTRL_CROSS) {
            break;
        }

        sceKernelDelayThread(100000);
    }

    if (font != NULL) {
        vita2d_free_pgf(font);
    }

    vita2d_fini();
    sceKernelExitProcess(0);
    return 0;
}
