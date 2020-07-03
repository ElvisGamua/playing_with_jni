#include <jni.h>
#include <string>
#include "nativeArrayTypesStorage.h"



static jclass StringClass;

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




    return JNI_VERSION_1_6;
}




extern "C"
JNIEXPORT void JNICALL Java_com_example_gamuatachu_arraytypes_NativeMsClass_resetNative
  (JNIEnv* pEnv, jobject pThis, jint countInput) {

    /*for(int i=0;i<countInput;i++){

    if((incomingValue[i]->getType()).compare("StringArrayType")==0) incomingValue[i]->deleteStringArray();
     if((incomingValue[i]->getType()).compare("StringArrayType")!=0) incomingValue[i]->deleteOtherArrays(incomingValue[i]->getType());
    } */

    for(int i=0;i<countInput;i++){

        delete incomingValue[i];
        }
}




//Arrays---------------------------------------------------------------------------------------Arrays
extern "C"
JNIEXPORT jintArray JNICALL
Java_com_example_gamuatachu_arraytypes_NativeMsClass_getIntegerArrayType
  (JNIEnv* pEnv, jobject pThis, jint jObjectNum) {


    if((incomingValue[jObjectNum]->getType()).compare("IntegerArrayType")==0)
           {
           jintArray javaArrayToSend = pEnv->NewIntArray(incomingValue[jObjectNum]->getLength());
                   pEnv->SetIntArrayRegion(javaArrayToSend, 0, incomingValue[jObjectNum]->getLength(),
                                           incomingValue[jObjectNum]->getIntegerArray());
           return  javaArrayToSend;

                } else return NULL;



}

extern "C"
JNIEXPORT void JNICALL Java_com_example_gamuatachu_arraytypes_NativeMsClass_sendIntegerArrayType
  (JNIEnv* pEnv, jobject pThis,
   jintArray nIntegerArray, jint countInput) {

     jsize length = pEnv->GetArrayLength(nIntegerArray);
            int32_t* array = new int32_t[length];
            pEnv->GetIntArrayRegion(nIntegerArray, 0, length, array);
             incomingValue[countInput] = new InputValues(array,length);
}

extern "C"
JNIEXPORT jobjectArray JNICALL
Java_com_example_gamuatachu_arraytypes_NativeMsClass_getStringArrayType
  (JNIEnv* pEnv, jobject pThis, jint jObjectNum) {

     if((incomingValue[jObjectNum]->getType()).compare("StringArrayType")==0)
     {
     jobjectArray javaArrayToSend = pEnv->NewObjectArray(incomingValue[jObjectNum]->getLength(),
                     StringClass, NULL);
     for (int32_t i = 0; i < incomingValue[jObjectNum]->getLength(); ++i) {
                 jstring string = pEnv->NewStringUTF(
                         incomingValue[jObjectNum]->getStringArray()[i]);

                 pEnv->SetObjectArrayElement(javaArrayToSend, i, string);

                 pEnv->DeleteLocalRef(string);
             }
     return javaArrayToSend;
     }
     else {
        return NULL;
    }
}

extern "C"
JNIEXPORT void JNICALL Java_com_example_gamuatachu_arraytypes_NativeMsClass_sendStringArrayType
  (JNIEnv* pEnv, jobject pThis,
   jobjectArray nStringArray, jint countInput) {


    jsize length = pEnv->GetArrayLength(nStringArray);
            char** array = new char*[length];

            for (int32_t i = 0; i < length; ++i) {

                jstring string = (jstring)
                             pEnv->GetObjectArrayElement(nStringArray, i);

                jsize stringLength = pEnv->GetStringUTFLength(string);
                array[i] = new char[stringLength + 1];

                pEnv->GetStringUTFRegion(string,0,stringLength, array[i]);

                array[i][stringLength] = '\0';

                pEnv->DeleteLocalRef(string);}
                 incomingValue[countInput] = new InputValues(array,length);
}


extern "C"
JNIEXPORT jbooleanArray JNICALL
Java_com_example_gamuatachu_arraytypes_NativeMsClass_getBooleanArrayType
  (JNIEnv* pEnv, jobject pThis,jint jObjectNum) {


     if((incomingValue[jObjectNum]->getType()).compare("BooleanArrayType")==0)
     {
      jbooleanArray javaArrayToSend =
                      pEnv->NewBooleanArray(incomingValue[jObjectNum]->getLength());
                     pEnv->SetBooleanArrayRegion(javaArrayToSend, 0, incomingValue[jObjectNum]->getLength(),
                                                         incomingValue[jObjectNum]->getBooleanArray());

     return javaArrayToSend;
     }
        else {
                return NULL;
            }
    }


extern "C"
JNIEXPORT void JNICALL Java_com_example_gamuatachu_arraytypes_NativeMsClass_sendBooleanArrayType
  (JNIEnv* pEnv, jobject pThis,
   jbooleanArray nBooleanArray, jint countInput) {

             jsize length = pEnv->GetArrayLength(nBooleanArray);
               uint8_t* array = new uint8_t[length];
                jboolean* arrayTmp = pEnv->GetBooleanArrayElements(
                nBooleanArray, NULL);

             for(int i = 0; i < length; i++) {

                array[i] = (arrayTmp[i] == JNI_TRUE);
               }

                pEnv->ReleaseBooleanArrayElements(nBooleanArray, arrayTmp, 0);

                incomingValue[countInput] = new InputValues(array,length);

}

extern "C"
JNIEXPORT jbyteArray JNICALL
Java_com_example_gamuatachu_arraytypes_NativeMsClass_getByteArrayType
  (JNIEnv* pEnv, jobject pThis, jint jObjectNum) {


     if((incomingValue[jObjectNum]->getType()).compare("ByteArrayType")==0)
               {
               jbyteArray javaArrayToSend = pEnv->NewByteArray(incomingValue[jObjectNum]->getLength());
                       pEnv->SetByteArrayRegion(javaArrayToSend, 0, incomingValue[jObjectNum]->getLength(),
                                               incomingValue[jObjectNum]->getByteArray());
               return  javaArrayToSend;

                    } else return NULL;
}

extern "C"
JNIEXPORT void JNICALL Java_com_example_gamuatachu_arraytypes_NativeMsClass_sendByteArrayType
  (JNIEnv* pEnv, jobject pThis,  jbyteArray nByteArray, jint countInput) {


     jsize length = pEnv->GetArrayLength(nByteArray);
                int8_t* array = new int8_t[length];
                pEnv->GetByteArrayRegion(nByteArray, 0, length, array);
                 incomingValue[countInput] = new InputValues(array,length);
}

extern "C"
JNIEXPORT jcharArray JNICALL Java_com_example_gamuatachu_arraytypes_NativeMsClass_getCharArrayType
  (JNIEnv* pEnv, jobject pThis, jint jObjectNum) {


    if((incomingValue[jObjectNum]->getType()).compare("CharArrayType")==0)
                   {
                   jcharArray javaArrayToSend = pEnv->NewCharArray(incomingValue[jObjectNum]->getLength());
                           pEnv->SetCharArrayRegion(javaArrayToSend, 0, incomingValue[jObjectNum]->getLength(),
                                                   incomingValue[jObjectNum]->getCharArray());
                   return  javaArrayToSend;

                        } else return NULL;
}

extern "C"
JNIEXPORT void JNICALL Java_com_example_gamuatachu_arraytypes_NativeMsClass_sendCharArrayType
  (JNIEnv* pEnv, jobject pThis, jcharArray nCharArray, jint countInput) {


    jsize length = pEnv->GetArrayLength(nCharArray);
                    uint16_t* array = new uint16_t[length];
                    pEnv->GetCharArrayRegion(nCharArray, 0, length, array);
                     incomingValue[countInput] = new InputValues(array,length);
}



extern "C"
JNIEXPORT jfloatArray JNICALL
Java_com_example_gamuatachu_arraytypes_NativeMsClass_getFloatArrayType
  (JNIEnv* pEnv, jobject pThis, jint jObjectNum) {


     if((incomingValue[jObjectNum]->getType()).compare("FloatArrayType")==0)
               {
               jfloatArray javaArrayToSend = pEnv->NewFloatArray(incomingValue[jObjectNum]->getLength());
                       pEnv->SetFloatArrayRegion(javaArrayToSend, 0, incomingValue[jObjectNum]->getLength(),
                                               incomingValue[jObjectNum]->getFloatArray());
               return javaArrayToSend;

                    } else return NULL;
}

extern "C"
JNIEXPORT void JNICALL Java_com_example_gamuatachu_arraytypes_NativeMsClass_sendFloatArrayType
  (JNIEnv* pEnv, jobject pThis,  jfloatArray nFloatArray, jint countInput) {


     jsize length = pEnv->GetArrayLength(nFloatArray);
                float* array = new float[length];
                pEnv->GetFloatArrayRegion(nFloatArray, 0, length, array);
                 incomingValue[countInput] = new InputValues(array,length);
}

//-----------------------------long-------------------------------------------------


extern "C"
JNIEXPORT jlongArray JNICALL
Java_com_example_gamuatachu_arraytypes_NativeMsClass_getLongArrayType
  (JNIEnv* pEnv, jobject pThis, jint jObjectNum) {


     if((incomingValue[jObjectNum]->getType()).compare("LongArrayType")==0)
               {
               jlongArray javaArrayToSend = pEnv->NewLongArray(incomingValue[jObjectNum]->getLength());
                       pEnv->SetLongArrayRegion(javaArrayToSend, 0, incomingValue[jObjectNum]->getLength(),
                                               incomingValue[jObjectNum]->getLongArray());
               return  javaArrayToSend;

                    } else return NULL;
}

extern "C"
JNIEXPORT void JNICALL Java_com_example_gamuatachu_arraytypes_NativeMsClass_sendLongArrayType
  (JNIEnv* pEnv, jobject pThis,  jlongArray nLongArray, jint countInput) {


     jsize length = pEnv->GetArrayLength(nLongArray);
                int64_t* array = new int64_t[length];
                pEnv->GetLongArrayRegion(nLongArray, 0, length, array);
                 incomingValue[countInput] = new InputValues(array,length);
}

//---------------------------Double-----------------------------


extern "C"
JNIEXPORT jdoubleArray JNICALL
Java_com_example_gamuatachu_arraytypes_NativeMsClass_getDoubleArrayType
  (JNIEnv* pEnv, jobject pThis, jint jObjectNum) {


     if((incomingValue[jObjectNum]->getType()).compare("DoubleArrayType")==0)
               {
               jdoubleArray javaArrayToSend = pEnv->NewDoubleArray(incomingValue[jObjectNum]->getLength());
                       pEnv->SetDoubleArrayRegion(javaArrayToSend, 0, incomingValue[jObjectNum]->getLength(),
                                               incomingValue[jObjectNum]->getDoubleArray());
               return  javaArrayToSend;

                    } else return NULL;
}

extern "C"
JNIEXPORT void JNICALL Java_com_example_gamuatachu_arraytypes_NativeMsClass_sendDoubleArrayType
  (JNIEnv* pEnv, jobject pThis,  jdoubleArray nDoubleArray, jint countInput) {


     jsize length = pEnv->GetArrayLength(nDoubleArray);
                double* array = new double[length];
                pEnv->GetDoubleArrayRegion(nDoubleArray, 0, length, array);
                 incomingValue[countInput] = new InputValues(array,length);
}

//---------------------------Short--------------------------------------------



extern "C"
JNIEXPORT jshortArray JNICALL
Java_com_example_gamuatachu_arraytypes_NativeMsClass_getShortArrayType
  (JNIEnv* pEnv, jobject pThis, jint jObjectNum) {


     if((incomingValue[jObjectNum]->getType()).compare("ShortArrayType")==0)
               {
               jshortArray javaArrayToSend = pEnv->NewShortArray(incomingValue[jObjectNum]->getLength());
                       pEnv->SetShortArrayRegion(javaArrayToSend, 0, incomingValue[jObjectNum]->getLength(),
                                               incomingValue[jObjectNum]->getShortArray());
               return  javaArrayToSend;

                    } else return NULL;
}

extern "C"
JNIEXPORT void JNICALL Java_com_example_gamuatachu_arraytypes_NativeMsClass_sendShortArrayType
  (JNIEnv* pEnv, jobject pThis,  jshortArray nShortArray, jint countInput) {


     jsize length = pEnv->GetArrayLength(nShortArray);
                int16_t* array = new int16_t[length];
                pEnv->GetShortArrayRegion(nShortArray, 0, length, array);
                 incomingValue[countInput] = new InputValues(array,length);
}