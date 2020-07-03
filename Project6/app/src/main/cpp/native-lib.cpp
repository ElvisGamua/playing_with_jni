#include <jni.h>
#include <string>
#include "informaticsInfo.h"


static jobject gLock;
static jclass StringClass;
static jclass ITDepartmentInfoClass;
static jmethodID MethodPrintStruct;
LecturerInfo* info;


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

    jclass ITDepartmentInfoClassTmp = env->FindClass("com/example/gamuatachu/copyingstructinfo/ITDepartmentInfo");
    if (ITDepartmentInfoClassTmp == NULL) abort();
    ITDepartmentInfoClass = (jclass) env->NewGlobalRef(ITDepartmentInfoClassTmp);
    env->DeleteLocalRef(ITDepartmentInfoClassTmp);


    jclass NativeClass = env->FindClass("com/example/gamuatachu/copyingstructinfo/NativeMsClass");
    if (NativeClass == NULL) abort();
        MethodPrintStruct = env->GetMethodID(NativeClass, "printStruct",
                "(Lcom/example/gamuatachu/copyingstructinfo/ITDepartmentInfo;)V");
        if (MethodPrintStruct == NULL) abort();
        env->DeleteLocalRef(NativeClass);

   return JNI_VERSION_1_6;
}
extern "C"
JNIEXPORT void JNICALL Java_com_example_gamuatachu_copyingstructinfo_NativeMsClass_resetNative
  (JNIEnv* pEnv, jobject pThis) {


 delete info;
}
extern "C"
JNIEXPORT void JNICALL Java_com_example_gamuatachu_copyingstructinfo_NativeMsClass_fillAndGetStructInNative
  (JNIEnv* pEnv, jobject pThis, jobject pDepInfo) {

   info = new LecturerInfo();
    fillInfo(info);



                   jfieldID fid = pEnv->GetFieldID(ITDepartmentInfoClass, "mHeight", "I");
                        if (fid == 0)
                          return;

                       pEnv->SetIntField(pDepInfo, fid, info->mLength);


                 jstring name = pEnv->NewStringUTF(info->mLectKey);

                    fid = pEnv->GetFieldID(ITDepartmentInfoClass,"name","Ljava/lang/String;");
                    pEnv->SetObjectField(pDepInfo,fid,name);


         pEnv->CallVoidMethod(pThis, MethodPrintStruct,
                        pDepInfo);
                        // deleteString(info);
    }

    void fillInfo(LecturerInfo* info) {
         info->mLectKey="Grzergorz";
         info->mLength=190;
    }
/*
void deleteString(StudentInfo* info)
   {
    delete info->mStudKey;
   }

*/


