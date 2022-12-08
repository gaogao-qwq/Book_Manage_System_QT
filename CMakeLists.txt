cmake_minimum_required(VERSION 3.23)
project(Book_Manage_System_QT)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(CMAKE_PREFIX_PATH "D:/QT/6.4.1/mingw_64")

find_package(Qt6 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED
)

include_directories(
        ${PROJECT_SOURCE_DIR}/include
        ${PROJECT_SOURCE_DIR}/Sources/Headers
)

add_executable(Book_Manage_System_QT
        Sources/main.cpp
        Sources/bookList.cpp
        Sources/convert.cpp
        Sources/mainmenu.cpp Sources/Headers/mainmenu.hpp Sources/Forms/mainmenu.ui
        Sources/browsebook.cpp Sources/Headers/browsebook.hpp Sources/Forms/browsebook.ui
        Sources/editbook.cpp Sources/Headers/editbook.hpp Sources/Forms/editbook.ui
        Sources/createbooklist.cpp Sources/Headers/createbooklist.hpp Sources/Forms/createbooklist.ui
        Sources/editlistsubwindow.cpp Sources/Headers/editlistsubwindow.hpp Sources/Forms/editlistsubwindow.ui
        Sources/insertlistsubwindow.cpp Sources/Headers/insertlistsubwindow.hpp Sources/Forms/insertlistsubwindow.ui
        Sources/aboutwindow.cpp Sources/Headers/aboutwindow.hpp Sources/Forms/aboutwindow.ui
        Sources/deduplicatelistsubwindow.cpp Sources/Headers/deduplicatelistsubwindow.hpp Sources/Forms/deduplicatelistsubwindow.ui
        Sources/searchbook.cpp Sources/Headers/searchbook.hpp Sources/Forms/searchbook.ui
        Sources/bookanalysiswindow.cpp Sources/Headers/bookanalysiswindow.hpp Sources/Forms/bookanalysiswindow.ui
)

target_link_libraries(Book_Manage_System_QT
        Qt::Core
        Qt::Gui
        Qt::Widgets
)

if (WIN32)
    set(DEBUG_SUFFIX)
    if (MSVC AND CMAKE_BUILD_TYPE MATCHES "Debug")
        set(DEBUG_SUFFIX "d")
    endif ()
    set(QT_INSTALL_PATH "${CMAKE_PREFIX_PATH}")
    if (NOT EXISTS "${QT_INSTALL_PATH}/bin")
        set(QT_INSTALL_PATH "${QT_INSTALL_PATH}/..")
        if (NOT EXISTS "${QT_INSTALL_PATH}/bin")
            set(QT_INSTALL_PATH "${QT_INSTALL_PATH}/..")
        endif ()
    endif ()
    if (EXISTS "${QT_INSTALL_PATH}/plugins/platforms/qwindows${DEBUG_SUFFIX}.dll")
        add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E make_directory
                "$<TARGET_FILE_DIR:${PROJECT_NAME}>/plugins/platforms/")
        add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E copy
                "${QT_INSTALL_PATH}/plugins/platforms/qwindows${DEBUG_SUFFIX}.dll"
                "$<TARGET_FILE_DIR:${PROJECT_NAME}>/plugins/platforms/")
    endif ()
    foreach (QT_LIB Core Gui Widgets)
        add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E copy
                "${QT_INSTALL_PATH}/bin/Qt6${QT_LIB}${DEBUG_SUFFIX}.dll"
                "$<TARGET_FILE_DIR:${PROJECT_NAME}>")
    endforeach (QT_LIB)
endif ()
