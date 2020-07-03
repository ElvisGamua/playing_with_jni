#include <jni.h>
#include <string>
#include "nativeTypeStorage.h"


static jclass StringClass;
InputValues *incomingValue[16];
static int ncount;
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

    ncount=0;
    return JNI_VERSION_1_6;
}




extern "C"
JNIEXPORT jstring JNICALL Java_com_example_gamuatachu_primitivetypesapp_NativeMsClass_getStringType
  (JNIEnv* pEnv, jobject pThis, jint jObjectNum) {

   if((incomingValue[jObjectNum]->getType()).compare("StringType")==0)
   {char *cString=incomingValue[jObjectNum]->getString();
        return pEnv->NewStringUTF(cString);
        } else return NULL;

}

extern "C"
JNIEXPORT void JNICALL Java_com_example_gamuatachu_primitivetypesapp_NativeMsClass_sendStringType
  (JNIEnv* pEnv, jobject pThis, jstring nString, jint countInput) {
     jsize stringLength = pEnv->GetStringUTFLength(nString);
            char * cString = new char[stringLength + 1];
            pEnv->GetStringUTFRegion(nString, 0, stringLength, cString);
                    //  null character for string termination.
                    cString[stringLength] = '\0';
                    incomingValue[countInput] = new InputValues(cString);
}


extern "C"
JNIEXPORT jint JNICALL Java_com_example_gamuatachu_primitivetypesapp_NativeMsClass_getIntegerType
  (JNIEnv* pEnv, jobject pThis,  jint jObjectNum) {


    if((incomingValue[jObjectNum]->getType()).compare("IntegerType")==0)
       {return incomingValue[jObjectNum]->getInteger();

            } else return 0;


}

extern "C"
JNIEXPORT void JNICALL Java_com_example_gamuatachu_primitivetypesapp_NativeMsClass_sendIntegerType
  (JNIEnv* pEnv, jobject pThis,  jint nInteger, jint countInput) {

        incomingValue[countInput] = new InputValues(nInteger);
        //ncount++;

}

//New 14.10
extern "C"
JNIEXPORT jint JNICALL Java_com_example_gamuatachu_primitivetypesapp_NativeMsClass_getBooleanType
  (JNIEnv* pEnv, jobject pThis,  jint jObjectNum) {


    if((incomingValue[jObjectNum]->getType()).compare("BooleanType")==0)
           return incomingValue[jObjectNum]->getBoolean();
           else return 100;
           // } else return NULL;
}
extern "C"
JNIEXPORT void JNICALL Java_com_example_gamuatachu_primitivetypesapp_NativeMsClass_sendBooleanType
  (JNIEnv* pEnv, jobject pThis, jboolean nBoolean, jint countInput) {

     incomingValue[countInput] = new InputValues(nBoolean);

}

extern "C"
JNIEXPORT jbyte JNICALL Java_com_example_gamuatachu_primitivetypesapp_NativeMsClass_getByteType
  (JNIEnv* pEnv, jobject pThis,  jint jObjectNum) {


     if((incomingValue[jObjectNum]->getType()).compare("ByteType")==0)
           {return incomingValue[jObjectNum]->getByte();

                } else return 0;
}

extern "C"
JNIEXPORT void JNICALL Java_com_example_gamuatachu_primitivetypesapp_NativeMsClass_sendByteType
  (JNIEnv* pEnv, jobject pThis,  jbyte nByte, jint countInput) {

     incomingValue[countInput] = new InputValues(nByte);
}

extern "C"
JNIEXPORT jchar JNICALL Java_com_example_gamuatachu_primitivetypesapp_NativeMsClass_getCharType
  (JNIEnv* pEnv, jobject pThis,  jint jObjectNum) {

    if((incomingValue[jObjectNum]->getType()).compare("CharType")==0)
               {return incomingValue[jObjectNum]->getChar();

                    } else return 0;
}

extern "C"
JNIEXPORT void JNICALL Java_com_example_gamuatachu_primitivetypesapp_NativeMsClass_sendCharType
  (JNIEnv* pEnv, jobject pThis,  jchar nChar, jint countInput) {

    incomingValue[countInput] = new InputValues(nChar);
                        //ncount++;
}

extern "C"
JNIEXPORT jdouble JNICALL Java_com_example_gamuatachu_primitivetypesapp_NativeMsClass_getDoubleType
  (JNIEnv* pEnv, jobject pThis,  jint jObjectNum) {

    if((incomingValue[jObjectNum]->getType()).compare("DoubleType")==0)
                   {return incomingValue[jObjectNum]->getDouble();

                        } else return 0.0;
}

extern "C"
JNIEXPORT void JNICALL Java_com_example_gamuatachu_primitivetypesapp_NativeMsClass_sendDoubleType
  (JNIEnv* pEnv, jobject pThis, jdouble nDouble, jint countInput) {

     incomingValue[countInput] = new InputValues(nDouble);
}

extern "C"
JNIEXPORT jfloat JNICALL Java_com_example_gamuatachu_primitivetypesapp_NativeMsClass_getFloatType
  (JNIEnv* pEnv, jobject pThis,  jint jObjectNum) {


     if((incomingValue[jObjectNum]->getType()).compare("FloatType")==0)
                      { return incomingValue[jObjectNum]->getFloat();

                            } else return 0.0f;
}

extern "C"
JNIEXPORT void JNICALL Java_com_example_gamuatachu_primitivetypesapp_NativeMsClass_sendFloatType
  (JNIEnv* pEnv, jobject pThis,  jfloat nFloat, jint countInput) {

    incomingValue[countInput] = new InputValues(nFloat);
}


extern "C"
JNIEXPORT jlong JNICALL Java_com_example_gamuatachu_primitivetypesapp_NativeMsClass_getLongType
  (JNIEnv* pEnv, jobject pThis,  jint jObjectNum) {

    if((incomingValue[jObjectNum]->getType()).compare("LongType")==0)
                           {return incomingValue[jObjectNum]->getLong();

                                } else return 0;
}

extern "C"
JNIEXPORT void JNICALL Java_com_example_gamuatachu_primitivetypesapp_NativeMsClass_sendLongType
  (JNIEnv* pEnv, jobject pThis,  jlong nLong, jint countInput) {

     incomingValue[countInput] = new InputValues(nLong);
}

extern "C"
JNIEXPORT jshort JNICALL Java_com_example_gamuatachu_primitivetypesapp_NativeMsClass_getShortType
  (JNIEnv* pEnv, jobject pThis,  jint jObjectNum) {

     if((incomingValue[jObjectNum]->getType()).compare("ShortType")==0)
                               {return incomingValue[jObjectNum]->getShort();

                                    } else return 0;
}

extern "C"
JNIEXPORT void JNICALL Java_com_example_gamuatachu_primitivetypesapp_NativeMsClass_sendShortType
  (JNIEnv* pEnv, jobject pThis,  jshort nShort, jint countInput) {

     incomingValue[countInput] = new InputValues(nShort);
}


extern "C"
JNIEXPORT void JNICALL Java_com_example_gamuatachu_primitivetypesapp_NativeMsClass_resetNative
  (JNIEnv* pEnv, jobject pThis, jint countInput) {

    //for(int i=0;i<countInput;i++){
     int i=(int)countInput;
    if((incomingValue[i]->getType()).compare("StringType")==0)
     {incomingValue[i]->deleteString();
      delete incomingValue[i];

     }
     else
   // delete incomingValue[i];

   // }

    // for(int i=0;i<countInput;i++){

        //if((incomingValue[i]->getType()).compare("StringType")==0) incomingValue[i]->deleteString();
        delete incomingValue[i];

       // }

}

