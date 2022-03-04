message(STATUS "BUILD_STEP: ${BUILD_STEP}")

if("${BUILD_STEP}" STREQUAL "patch")
    execute_process(
        COMMAND git apply --check -R "${PATCH_FILE}"
        RESULT_VARIABLE ret
        ERROR_QUIET
    )
    message(STATUS "BUILD_STEP: git apply --check -R "${PATCH_FILE}" exited with ${ret}")
    if(NOT ${ret} EQUAL "0")
        execute_process(COMMAND git apply "${PATCH_FILE}")
    endif()
endif()
