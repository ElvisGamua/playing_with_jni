//
// Created by gamuatachu on 10.1.2020.
//

#include "objectArrays.h"
#include <cstdlib>
#include <cstring>


   jobject* InputValues::getLanguageArray()
   {
    return mLanguageArray;
   }

   int32_t InputValues::getLength()
     {
       return mLength;
     }

    void InputValues::deleteLanguageArrayRef(JNIEnv* pEnv,int32_t arrayLength)
         {
          for (int32_t i = 0; i < arrayLength; ++i) {
                                     pEnv->DeleteGlobalRef(mLanguageArray[i]);
                                  }
                                  delete[] mLanguageArray;
         }

         InputValues::~InputValues()
           {
           }