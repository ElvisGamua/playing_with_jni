//
// Created by gamuatachu on 10.1.2020.
//
#include <jni.h>
#include <string>
#ifndef PROJECT4_OBJECTARRAYS_H
#define PROJECT4_OBJECTARRAYS_H

using namespace std;

extern "C"

/*
class InputTypes{
private:
  // char* inputDataType;
   string inputDataType;

   public:
    //InputTypes(char* input);
     InputTypes(string input);
};*/
class InputValues{

private:
    jobject*  mLanguageArray;
     int32_t mLength;
    jobject   mLanguage;
    string inTypes;


    public:
    InputValues()
        {
         }
    InputValues(jobject* mLanguageArray,int32_t mLength)
    { this->mLanguageArray=mLanguageArray;
      this->mLength=mLength;
     }

    ~InputValues();
     string getType();
     jobject* getLanguageArray();
     int32_t getLength();
     void deleteLanguageArrayRef(JNIEnv*,int32_t);

};


#endif //PROJECT4_OBJECTARRAYS_H
