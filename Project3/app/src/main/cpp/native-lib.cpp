

#include <jni.h>
#include <string>
#include "objectType.h"

static jclass StringClass;
static jclass LanguageClass;
InputValues *incomingValue[16];

extern "C"

JNIEXPORT jint JNI_OnLoad(JavaVM* pVM, void* reserved) {
JNIEnv *env;
    if (pVM->GetEnv((void**) &env, JNI_VERSION_1_6) != JNI_OK) {
        abort();
    }


    jclass StringClassTmp = env->FindClass("java/lang/String");
    if (StringClassTmp == NULL) abort();
    StringClass = (jclass) env->NewGlobalRef(StringClassTmp);
    env->DeleteLocalRef(StringClassTmp);

    jclass LanguageClassTmp = env->FindClass("com/example/gamuatachu/objecttypes/Languages");
    if (LanguageClassTmp == NULL) abort();
    LanguageClass = (jclass) env->NewGlobalRef(LanguageClassTmp);
    env->DeleteLocalRef(LanguageClassTmp);

    return JNI_VERSION_1_6;
}



extern "C"
JNIEXPORT jobject JNICALL Java_com_example_gamuatachu_objecttypes_NativeMsClass_getLanguage
  (JNIEnv* pEnv, jobject pThis, jint jObjectNum) {

    if((incomingValue[jObjectNum]->getLanguage())!=NULL)
           {return incomingValue[jObjectNum]->getLanguage();

                } else return NULL;
}

extern "C"
JNIEXPORT void JNICALL Java_com_example_gamuatachu_objecttypes_NativeMsClass_sendLanguage
  (JNIEnv* pEnv, jobject pThis, jint countInput, jobject pLanguage) {

    jobject newLanguageRef=pEnv->NewGlobalRef(pLanguage);
    incomingValue[countInput] = new InputValues(newLanguageRef);
}

extern "C"
JNIEXPORT void JNICALL Java_com_example_gamuatachu_objecttypes_NativeMsClass_resetNative
  (JNIEnv* pEnv, jobject pThis, jint jObjectNum) {



    if((incomingValue[jObjectNum]->getLanguage())!=NULL) {
    incomingValue[jObjectNum]->deleteLanguageRef(pEnv);
    delete incomingValue[jObjectNum];
    }


}