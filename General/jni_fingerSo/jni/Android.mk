LOCAL_PATH:= $(call my-dir)

include $(CLEAR_VARS)

LOCAL_SRC_FILES := \
    jni_init.cpp \
    com_android_testsuit_Finger.cpp \
	
LOCAL_SHARED_LIBRARIES := \
	liblog \
    libutils
	
LOCAL_CFLAGS := \
    -Wno-unused-parameter \

LOCAL_MODULE := libjni_finger
LOCAL_MODULE_TAGS := optional

include $(BUILD_SHARED_LIBRARY)
