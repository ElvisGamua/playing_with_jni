//
// Created by gamuatachu on 3.10.2019.
//
#include <jni.h>
#include <string>
#ifndef PROJECT1_NATIVETYPESTORAGE_H
#define PROJECT1_NATIVETYPESTORAGE_H
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
uint8_t   cBoolean;
    int8_t    cByte;
    uint16_t  cChar;
    double    cDouble;
    float     cFloat;
    int32_t   cInteger;
    int64_t   cLong;
    int16_t   cShort;
    char*     cString;
    string inTypes;


    public:
    InputValues():inTypes("")
        {
         }
    InputValues(int8_t cByte):inTypes("ByteType")
    { this->cByte=cByte;
     }
     InputValues(uint8_t cBoolean):inTypes("BooleanType")
         { this->cBoolean=cBoolean;
          }
    InputValues(uint16_t  cChar):inTypes("CharType")
         { this->cChar=cChar;
          }
     InputValues(double cDouble):inTypes("DoubleType")
              { this->cDouble=cDouble;
               }
     InputValues(float cFloat):inTypes("FloatType")
                   { this->cFloat=cFloat;
                    }
     InputValues(int32_t cInteger):inTypes("IntegerType")
                        { this->cInteger=cInteger;

                         }
      InputValues(int64_t cLong):inTypes("LongType")
                        { this->cLong=cLong;
                         }
      InputValues(int16_t   cShort):inTypes("ShortType")
                              { this->cShort=cShort;
                               }
       InputValues(char* cString):inTypes("StringType")
                                    {
                                  this->cString=cString;
                                     }
     string getType();
     void deleteString();
     uint8_t getBoolean();
     int8_t    getByte();
      uint16_t  getChar();
      double    getDouble();
      float     getFloat();
      int32_t   getInteger();
      int64_t   getLong();
         int16_t   getShort();
         char*     getString();
};








void throwInvalidTypeException(JNIEnv* pEnv);

#endif
