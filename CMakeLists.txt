cmake_minimum_required(VERSION 3.23)
project(Book_Manage_System_QT)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(CMAKE_AUTOUIC_SEARCH_PATHS Sources/Forms/ui)

include_directories(
        ${PROJECT_SOURCE_DIR}/Headers
)

# Windows 用户可以手动指定一下工具链路径为 QT 自带工具链
# set(CMAKE_PREFIX_PATH "D:/QT/6.4.1/mingw_64")

find_package(Qt6 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED
        )


add_executable(Book_Manage_System_QT
        resource.qrc
        Sources/main.cpp
        Sources/Forms/mainMenuWindow.cpp Headers/forms/main_menu_window.hpp
        Sources/Forms/browseBookWindow.cpp Headers/forms/browseBookWindow.hpp
        Sources/Forms/editBookWindow.cpp Headers/forms/editBookWindow.hpp
        Sources/Forms/createBookListWindow.cpp Headers/forms/createBookListWindow.hpp
        Sources/Forms/editListSubWindow.cpp Headers/forms/editListSubWindow.hpp
        Sources/Forms/insertListSubWindow.cpp Headers/forms/insertListSubWindow.hpp
        Sources/Forms/aboutWindow.cpp Headers/forms/about_window.hpp
        Sources/Forms/deduplicateListSubWindow.cpp Headers/forms/deduplicateListSubWindow.hpp
        Sources/Forms/searchBookWindow.cpp Headers/forms/searchBookWindow.hpp
        Sources/Forms/bookAnalysisWindow.cpp Headers/forms/book_analysis_window.hpp
        Sources/Forms/goodNewsWindow.cpp Headers/forms/goodNewsWindow.hpp
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
