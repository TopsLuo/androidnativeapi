# For more information about using CMake with Android Studio, read the
# documentation: https://d.android.com/studio/projects/add-native-code.html

# Sets the minimum version of CMake required to build the native library.

cmake_minimum_required(VERSION 3.4.1)

# 设置工程的全路径
set(CWD ${CMAKE_CURRENT_LIST_DIR})

#add_definitions(-DV8_DEPRECATION_WARNINGS -DNO_TCMALLOC -DSAFE_BROWSING_DB_REMOTE -DCHROMIUM_BUILD -DFIELDTRIAL_TESTING_ENABLED -D_GNU_SOURCE -DANDROID -DHAVE_SYS_UIO_H -DANDROID_NDK_VERSION_ROLL=r16_1 -DCR_CLANG_REVISION=\"340925-2\" -D__STDC_CONSTANT_MACROS -D__STDC_FORMAT_MACROS -D__GNU_SOURCE=1 -DCHROMIUM_CXX_TWEAK_INLINES -D_DEBUG -DDYNAMIC_ANNOTATIONS_ENABLED=1 -DWTF_USE_DYNAMIC_ANNOTATIONS=1 -DWEBRTC_ENABLE_PROTOBUF=1 -DWEBRTC_INCLUDE_INTERNAL_AUDIO_DEVICE -DHAVE_SCTP -DUSE_BUILTIN_SW_CODECS -DWEBRTC_ARCH_ARM64 -DWEBRTC_HAS_NEON -DWEBRTC_NON_STATIC_TRACE_EVENT_HANDLERS=1 -DWEBRTC_POSIX -DWEBRTC_LINUX -DWEBRTC_ANDROID -DABSL_ALLOCATOR_NOTHROW=1 -DHAVE_WEBRTC_VIDEO -DHAVE_WEBRTC_VOICE)
add_definitions(-DWEBRTC_POSIX)

include_directories(${CWD}/libs/inc/webrtc)
include_directories(${CWD}/libs/inc/webrtc/third_party/abseil-cpp)
include_directories(${CWD}/libs/inc/webrtc/out/Debug/gen)
include_directories(${CWD}/libs/inc/webrtc/out/Debug/gen/examples/androidnativeapi/generated_jni)

# Creates and names a library, sets it as either STATIC
# or SHARED, and provides the relative paths to its source code.
# You can define multiple libraries, and CMake builds them for you.
# Gradle automatically packages shared libraries with your APK.

add_library( # Sets the name of the library.
             native-lib

             # Sets the library as a shared library.
             SHARED

             # Provides a relative path to your source file(s).
             src/main/cpp/androidcallclient.cc
             src/main/cpp/onload.cc)

# Searches for a specified prebuilt library and stores the path as a
# variable. Because CMake includes system libraries in the search path by
# default, you only need to specify the name of the public NDK library
# you want to add. CMake verifies that the library exists before
# completing its build.

find_library( # Sets the name of the path variable.
              log-lib

              # Specifies the name of the NDK library that
              # you want CMake to locate.
              log )

find_library( # Sets the name of the path variable.
              OpenSLES-lib

              # Specifies the name of the NDK library that
              # you want CMake to locate.
              OpenSLES )

# Specifies libraries CMake should link to your target library. You
# can link multiple libraries, such as libraries you define in this
# build script, prebuilt third-party libraries, or system libraries.

target_link_libraries( # Specifies the target library.
                       native-lib
                       #android
                       ${CWD}/libs/${ANDROID_ABI}/libwebrtc.a
                       ${CWD}/libs/${ANDROID_ABI}/libjingle_peerconnection_so.so

                       # Links the target library to the log library
                       # included in the NDK.
                       ${OpenSLES-lib}
                       ${log-lib}
                       )
