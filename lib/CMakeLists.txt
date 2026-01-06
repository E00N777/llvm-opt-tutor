set(
    LLVM_OPT_TUTOR_PLUGINS
    ToyMem2Reg
)

set(ToyMem2Reg_SOURCES
  ToyMem2Reg.cpp)

foreach(plugin ${LLVM_OPT_TUTOR_PLUGINS})
    add_library(
        ${plugin}
        SHARED
        ${${plugin}_SOURCES})
    target_include_directories(
        ${plugin}
        PRIVATE
        "${CMAKE_CURRENT_SOURCE_DIR}/../include"
    )
    set_target_properties(${plugin} PROPERTIES PREFIX "lib")


endforeach()
