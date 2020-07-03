

#include <jni.h>
#include "nativeThread.h"
#include <unistd.h>
#include <pthread.h>
#include <cstdlib>
#include<cmath>


static jclass NativeClassMethods1;
jobject myLock;
ThreadVariables* tv;
static jmethodID MethodOnSetStringBuilder;
static jmethodID MethodOnSetUI;



extern "C"

JNIEXPORT jint JNI_OnLoad(JavaVM* pVM, void* reserved) {
JNIEnv *env;
    if (pVM->GetEnv((void**) &env, JNI_VERSION_1_6) != JNI_OK) {
        abort();
    }



         jclass NativeClassMethods = env->FindClass("com/example/gamuatachu/nativethreads/NativeMsClass");
                             if (NativeClassMethods == NULL) abort();
                  NativeClassMethods1 =(jclass) env->NewGlobalRef(NativeClassMethods);


    return JNI_VERSION_1_6;
}


extern "C"
JNIEXPORT void JNICALL Java_com_example_gamuatachu_nativethreads_NativeMsClass_startNativeThread
  (JNIEnv *pEnv, jobject pThis, jint nInteger) {
    JavaVM* javaVM;

    if (pEnv->GetJavaVM(&javaVM) != JNI_OK) abort();
       myLock = pEnv->NewGlobalRef(pThis);
       startThread(javaVM, nInteger);

}



void  startThread(JavaVM* pJavaVM, jint nInteger) {
         pthread_t  tid;

       tv = new ThreadVariables();
    tv->mJavaVM = pJavaVM;


      tv->mUpperLimit = nInteger;
     pthread_attr_t lAttributes;
    if (pthread_attr_init(&lAttributes)) abort();
    if (pthread_create(&tv->mThread, &lAttributes,
                               runThread, tv)) abort();

}



void* runThread(void* pArgs) {
  ThreadVariables* tv = (ThreadVariables*) pArgs;
    int i=2;
    JavaVM* javaVM = tv->mJavaVM;
    JavaVMAttachArgs javaVMAttachArgs;
    javaVMAttachArgs.version = JNI_VERSION_1_6;
    javaVMAttachArgs.name = "CPlusPlusNativeThread";
    javaVMAttachArgs.group = NULL;


    JNIEnv* env;
    if (javaVM->AttachCurrentThread(&env,
            &javaVMAttachArgs) != JNI_OK) abort();
            tv->pEnv=env;
                   MethodOnSetStringBuilder = env->GetMethodID(NativeClassMethods1, "setStringBuilder",
                                    "(I)V");
                            if (MethodOnSetStringBuilder == NULL) abort();
                            MethodOnSetUI = env->GetMethodID(NativeClassMethods1, "setUI",
                                                                "()V");
                                                        if (MethodOnSetUI == NULL) abort();
    while(i<=tv->mUpperLimit) {


         env->MonitorEnter(myLock);
          if (isPrimeCalculate(i)){
         env->CallVoidMethod(myLock, MethodOnSetStringBuilder,
                                                 i);}
          i++;
          if(i>=tv->mUpperLimit)
          env->CallVoidMethod(myLock, MethodOnSetUI
                                                        );

      env->MonitorExit(myLock);

    }
    javaVM->DetachCurrentThread();
    delete tv;
    pthread_exit(NULL);

}

bool isPrimeCalculate(int i){
  bool isPrime=true;

for (int divisor = 2; divisor <= (int)sqrt(i);
              divisor++)
                {
                    if (i % divisor == 0)    { // If true, number is not prime
                    isPrime = false; // Set isPrime to false
                    break; // Exit the for loop
                                              }
               }
return isPrime;

}
