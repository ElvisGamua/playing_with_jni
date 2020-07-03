//
// Created by gamuatachu on 18.12.2019.
//
#include <jni.h>
#include <string>
#include<vector>
#ifndef PROJECT2_NATIVEARRAYTYPESSTORAGE_H
#define PROJECT2_NATIVEARRAYTYPESSTORAGE_H

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
};
*/

class InputValues{

private:




    int32_t*  cIntegerArray;
            char**    cStringArray;
             uint8_t*  cBooleanArray;
                int8_t*   cByteArray;
                uint16_t* cCharArray;
                double*    cDoubleArray;
                    float*     cFloatArray;
                    int64_t*   cLongArray;
                    int16_t*   cShortArray;
                    int32_t cLength;
                     string inTypes;
                    // InputValues* inputValuesPtr;


    public:
    InputValues():inTypes("")
        {
         }
    InputValues(int8_t* cByteArray,int32_t cLength):inTypes("ByteArrayType")
    { this->cByteArray=cByteArray;this->cLength=cLength;
        //inputValuesPtr=this;

     }
     InputValues(uint8_t* cBooleanArray,int32_t cLength):inTypes("BooleanArrayType")
         { this->cBooleanArray=cBooleanArray;this->cLength=cLength;
        // inputValuesPtr=this;

          }
    InputValues(uint16_t*  cCharArray,int32_t cLength):inTypes("CharArrayType")
         { this->cCharArray=cCharArray;this->cLength=cLength;
         //inputValuesPtr=this;

          }
     InputValues(double* cDoubleArray,int32_t cLength):inTypes("DoubleArrayType")
              { this->cDoubleArray=cDoubleArray;this->cLength=cLength;
              //inputValuesPtr=this;

               }
     InputValues(float* cFloatArray,int32_t cLength):inTypes("FloatArrayType")
                   { this->cFloatArray=cFloatArray;this->cLength=cLength;
                   //inputValuesPtr=this;

                    }
     InputValues(int32_t* cIntegerArray,int32_t cLength):inTypes("IntegerArrayType")
                        { this->cIntegerArray=cIntegerArray;this->cLength=cLength;
                       // inputValuesPtr=this;


                         }
      InputValues(int64_t* cLongArray,int32_t cLength):inTypes("LongArrayType")
                        { this->cLongArray=cLongArray;this->cLength=cLength;
                        //inputValuesPtr=this;

                         }
      InputValues(int16_t*   cShortArray,int32_t cLength):inTypes("ShortArrayType")
                              { this->cShortArray=cShortArray;
                               this->cLength=cLength;
                              // inputValuesPtr=this;

                               }
       InputValues(char** cStringArray,int32_t cLength):inTypes("StringArrayType")
                                    {
                                  this->cStringArray=cStringArray;
                                  this->cLength=cLength;
                                  //inputValuesPtr=this;

                                     }
       ~InputValues();

     string getType();
     void deleteStringArray();
     void deleteOtherArrays(string);
     uint8_t* getBooleanArray();
     int8_t*    getByteArray();
      uint16_t*  getCharArray();
      double*    getDoubleArray();
      float*     getFloatArray();
      int32_t*   getIntegerArray();
      int64_t*   getLongArray();
         int16_t*   getShortArray();
         char**     getStringArray();
          int32_t getLength();
          //InputValues* getPointerAddr();
};









void throwInvalidTypeException(JNIEnv* pEnv);



#endif //PROJECT2_NATIVEARRAYTYPESSTORAGE_H
