//
// Created by gamuatachu on 4.2.2020.
//
#include <jni.h>
#include <string>
#ifndef NATIVETHREADS_NATIVETHREAD_H
#define NATIVETHREADS_NATIVETHREAD_H
using namespace std;

typedef struct {
    JNIEnv* pEnv;
    JavaVM* mJavaVM;

    pthread_t mThread;
    int32_t mUpperLimit;
} ThreadVariables;

void startThread(JavaVM* pJavaVM,int nInteger);
void* runThread(void* pArgs);
bool isPrimeCalculate(int i);


#endif //NATIVETHREADS_NATIVETHREAD_H
