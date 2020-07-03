#include <jni.h>
#include <string>
#include "objectArrays.h"


static jclass StringClass;
static jclass LanguagesClass;
static jmethodID MethodOnCompareLanguages;
static jobjectArray comparingArray;
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

    jclass LanguagesClassTmp = env->FindClass("com/example/gamuatachu/arrayofobjects/Languages");
    if (LanguagesClassTmp == NULL) abort();
    LanguagesClass = (jclass) env->NewGlobalRef(LanguagesClassTmp);
    env->DeleteLocalRef(LanguagesClassTmp);



     jclass NativeMClass = env->FindClass("com/example/gamuatachu/arrayofobjects/NativeMsClass");
        if (NativeMClass == NULL) abort();

         MethodOnCompareLanguages = env->GetMethodID(NativeMClass, "onObjectCompare",
                        "(Lcom/example/gamuatachu/arrayofobjects/Languages;)V");
                if (MethodOnCompareLanguages == NULL) abort();
                env->DeleteLocalRef(NativeMClass);

    return JNI_VERSION_1_6;
}


extern "C"
JNIEXPORT void JNICALL Java_com_example_gamuatachu_arrayofobjects_NativeMsClass_resetNative
  (JNIEnv* pEnv, jobject pThis, jint jObjectNum) {


if((incomingValue[jObjectNum]->getLanguageArray())!=NULL) incomingValue[jObjectNum]->deleteLanguageArrayRef(pEnv,incomingValue[jObjectNum]->getLength());
  //  if((incomingValue[jObjectNum]->getLanguage())!=NULL) incomingValue[jObjectNum]->deleteLanguageRef(pEnv);
    delete incomingValue[jObjectNum];

}

extern "C"
JNIEXPORT void JNICALL Java_com_example_gamuatachu_arrayofobjects_NativeMsClass_sendLanguageArray
  (JNIEnv* pEnv, jobject pThis,
   jobjectArray pLanguageArray, jint jObjectNum) {

        jsize length = pEnv->GetArrayLength(pLanguageArray);
        jobject* array = new jobject[length];

        for (int32_t i = 0; i < length; ++i) {

            jobject localLanguage = pEnv->GetObjectArrayElement(
                    pLanguageArray, i);

            array[i] = pEnv->NewGlobalRef(localLanguage);
            pEnv->DeleteLocalRef(localLanguage);
        }
        incomingValue[jObjectNum] = new InputValues(array,length);

    }





extern "C"
JNIEXPORT jobjectArray JNICALL
Java_com_example_gamuatachu_arrayofobjects_NativeMsClass_getLanguageArray
  (JNIEnv* pEnv, jobject pThis, jint jObjectNum) {

        if((incomingValue[jObjectNum]->getLanguageArray())!=NULL){
        jobjectArray javaArrayToSend = pEnv->NewObjectArray(incomingValue[jObjectNum]->getLength(),
                LanguagesClass, NULL);

        for (int32_t i = 0; i < incomingValue[jObjectNum]->getLength(); ++i) {
            pEnv->SetObjectArrayElement(javaArrayToSend, i,
                                        incomingValue[jObjectNum]->getLanguageArray()[i]);
        }
        return javaArrayToSend;
    } else {
        return NULL;
    }
}


extern "C"
JNIEXPORT void JNICALL Java_com_example_gamuatachu_arrayofobjects_NativeMsClass_compareObjects
  (JNIEnv* pEnv, jobject pThis, jobjectArray pLanguageArray) {

        jsize length = pEnv->GetArrayLength(pLanguageArray);

                jobject localLanguage1 = pEnv->GetObjectArrayElement(
                                            pLanguageArray, 0);
                for (int32_t i = 0; i < length; ++i) {

                    jobject localLanguage2=NULL;
                     jchar languageValue1;
                      jchar languageValue2;

                            jfieldID fid = pEnv->GetFieldID(LanguagesClass, "intDiff", "I");
                            languageValue1 = pEnv->GetIntField(localLanguage1, fid);
                         if(pEnv->GetObjectArrayElement(pLanguageArray, i)!=NULL)
                                                        {localLanguage2 = pEnv->GetObjectArrayElement(
                                                                                     pLanguageArray, i);
                                                          languageValue2 = pEnv->GetIntField(localLanguage2, fid);
                                                          if((int)languageValue2>=(int)languageValue1)
                                                          localLanguage1=localLanguage2;
                                                          }

               }


         pEnv->CallVoidMethod(pThis, MethodOnCompareLanguages,
                                localLanguage1);
}