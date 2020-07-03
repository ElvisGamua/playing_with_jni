//
// Created by gamuatachu on 8.1.2020.
//

#include "objectType.h"
#include <cstdlib>
#include <cstring>


  jobject InputValues::getLanguage()
   {
    return mLanguage;
   }

   void InputValues::deleteLanguageRef(JNIEnv* pEnv)
      {
        pEnv->DeleteGlobalRef(mLanguage);
      }


InputValues::~InputValues()
  {
  }