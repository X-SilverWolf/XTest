if (${XTEST_SYSTEM_TYPE} MATCHES "Win")
    message(STATUS "Configuring for Windows x64")
    if(MSVC)
        set(XTEST_SYSTEM_LIBS
                ws2_32
                mswsock
                advapi32
                user32
                kernel32
        )
    else()
        set(XTEST_SYSTEM_LIBS
                mingwex
                ws2_32
                mswsock
                advapi32
                user32
                kernel32
        )
    endif()
elseif (${XTEST_SYSTEM_TYPE} MATCHES "Linux")
    set(XTEST_SYSTEM_LIBS
            pthread
            stdc++fs
            stdc++
            m
            dl
            rt
    )
endif ()
set(SYSTEM_LIBS ${XTEST_SYSTEM_LIBS})