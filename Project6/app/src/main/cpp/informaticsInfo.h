//
// Created by gamuatachu on 6.2.2020.
//
#include <jni.h>
#include <pthread.h>
#ifndef PROJECT6_INFORMATICSINFO_H
#define PROJECT6_INFORMATICSINFO_H

extern "C"
typedef struct {
          char const* mLectKey;
        int32_t mLength;
} LecturerInfo;
void fillInfo(LecturerInfo* pEntry);

#endif //PROJECT6_INFORMATICSINFO_H
