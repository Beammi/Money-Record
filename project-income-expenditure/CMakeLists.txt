cmake_minimum_required(VERSION 3.5)

project(project-income-expenditure LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# QtCreator supports the following variables for Android, which are identical to qmake Android variables.
# Check https://doc.qt.io/qt/deployment-android.html for more information.
# They need to be set before the find_package( ...) calls below.

#if(ANDROID)
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
#    if (ANDROID_ABI STREQUAL "armeabi-v7a")
#        set(ANDROID_EXTRA_LIBS
#            ${CMAKE_CURRENT_SOURCE_DIR}/path/to/libcrypto.so
#            ${CMAKE_CURRENT_SOURCE_DIR}/path/to/libssl.so)
#    endif()
#endif()

find_package(QT NAMES Qt6 Qt5 COMPONENTS Widgets REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Widgets REQUIRED)

set(PROJECT_SOURCES
        main.cpp
        dialog.cpp
        dialog.h
        dialog.ui
        dialogincome.cpp
        dialogincome.h
        dialogincome.ui
        dialogexpenditure.cpp
        dialogexpenditure.h
        dialogexpenditure.ui
        dialoglogin.cpp
        dialoglogin.h
        dialoglogin.ui
        dialogchangepassword.cpp
        dialogchangepassword.h
        dialogchangepassword.ui
        resources.qrc

)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(project-income-expenditure
        ${PROJECT_SOURCES}
    )
else()
    if(ANDROID)
        add_library(project-income-expenditure SHARED
            ${PROJECT_SOURCES}
        )
    else()
        add_executable(project-income-expenditure
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_link_libraries(project-income-expenditure PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)
