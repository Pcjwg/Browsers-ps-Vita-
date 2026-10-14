
cmake_minimum_required(VERSION 3.16)

project(Browsers C)

if(NOT DEFINED ENV{VITASDK})
    message(FATAL_ERROR "VITASDK is not set")
endif()

include("$ENV{VITASDK}/share/vita.cmake" REQUIRED)

set(VITA_APP_NAME "Browsers")
set(VITA_TITLEID "BROWSERS01")
set(VITA_VERSION "0.03")

add_executable(Browsers
    main.c
)

target_link_libraries(Browsers
    SceCtrl_stub
    SceDisplay_stub
    SceAppUtil_stub
    SceCommonDialog_stub
)

vita_create_self(eboot.bin Browsers)
vita_create_vpk(Browsers.vpk BROWSERS01 eboot.bin
    VERSION ${VITA_VERSION}
    NAME ${VITA_APP_NAME}
)
