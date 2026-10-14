
cmake_minimum_required(VERSION 3.16)

if(NOT DEFINED ENV{VITASDK})
    message(FATAL_ERROR "VITASDK is not set")
endif()

include("$ENV{VITASDK}/share/vita.cmake")

project(Browsers C)

set(VITA_APP_NAME "Browsers")
set(VITA_TITLEID "BROWSR001")
set(VITA_VERSION "01.00")

add_executable(Browsers
    main.c


target_link_libraries(Browsers
    vita2d
    SceCtrl_stub
    SceDisplay_stub
    SceGxm_stub
    SceSysmodule_stub
    ScePgf_stub
    ScePvf_stub
    m
)

)

vita_create_self(eboot.bin Browsers)

vita_create_vpk(Browsers.vpk
    ${VITA_TITLEID}
    eboot.bin
    VERSION ${VITA_VERSION}
    NAME ${VITA_APP_NAME}
)
