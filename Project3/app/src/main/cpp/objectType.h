//
// Created by gamuatachu on 8.1.2020.
//
#include <jni.h>
#include <string>
#ifndef PROJECT3_OBJECTTYPE_H
#define PROJECT3_OBJECTTYPE_H
using namespace std;



extern "C"


class InputValues{

private:

    jobject   mLanguage;
    //string inTypes;


    public:
    InputValues()
        {
         }
    InputValues(jobject mLanguage)
    { this->mLanguage=mLanguage;
     }

      ~InputValues();
     //string getType();
     jobject getLanguage();
     void deleteLanguageRef(JNIEnv*);

};





#endif //PROJECT3_OBJECTTYPE_H
