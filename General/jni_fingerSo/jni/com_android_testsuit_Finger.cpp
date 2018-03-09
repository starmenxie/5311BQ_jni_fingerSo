/*
 * Copyright (C) 2013 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#define LOG_TAG "Finger"

#include <utils/Log.h>
#include "jni.h"


typedef struct fingerprint_dev {
const char *dev_name;
} fingerprint_dev_t;

fingerprint_dev_t fingerprint_list[] =
{
	{
        .dev_name = "/dev/cs_spi",
	},
	{
        .dev_name = "/dev/blestech_fp",
	}
};

jint query(JNIEnv *env, jobject thiz){
	int i=-1;
	if (!access(fingerprint_list[0].dev_name, F_OK)) {
		i=1;
	}else if((!access(fingerprint_list[1].dev_name, F_OK))){
		i=2;
	}
	return i;
}

static const char *classPathName = "com/android/testsuit/item/finger/Finger";

static JNINativeMethod methods[]= {
	{"query", "()I", (void*)query},
};

static int registerNativeMethods(JNIEnv* env, const char* className,JNINativeMethod* gMethods, int numMethods){
	jclass clazz;
	clazz = env->FindClass(className);
	if (clazz == NULL)
		return JNI_FALSE;
	if (env->RegisterNatives(clazz, gMethods, numMethods)<0)
		return JNI_FALSE;
	return JNI_TRUE;
}

int register_com_android_testsuit_Finger(JNIEnv *env){
	if (!registerNativeMethods(env, classPathName,methods, sizeof(methods)/sizeof(methods[0])))
	{
		return JNI_FALSE;
	}
	return JNI_TRUE;
}
