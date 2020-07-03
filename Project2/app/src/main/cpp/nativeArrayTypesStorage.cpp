//
// Created by gamuatachu on 18.12.2019.
//

#include "nativeArrayTypesStorage.h"
#include <cstdlib>
#include <cstring>













/*
InputTypes::InputTypes(string input):inputDataType(input) {

}*/

string InputValues::getType()
{
 return this->inTypes;
}

uint8_t* InputValues::getBooleanArray()
{
      return this->cBooleanArray;
 }
int8_t*    InputValues::getByteArray()
{
      return this->cByteArray;
     }
 uint16_t* InputValues::getCharArray()
 {
  return this->cCharArray;
 }
 double* InputValues::getDoubleArray()
 {
  return this->cDoubleArray;
 }
  float* InputValues::getFloatArray()
  {
   return this->cFloatArray;
  }
  int32_t* InputValues:: getIntegerArray()
  {
   return this->cIntegerArray;
  }
  int64_t* InputValues::getLongArray()
  {
   return this->cLongArray;
  }
   int16_t* InputValues::getShortArray()
   {
    return this->cShortArray;
   }
   char** InputValues::getStringArray()
   {
    return this->cStringArray;
   }

 void InputValues::deleteStringArray()
   {
    for (int32_t i = 0; i < this->cLength; ++i) {
                                delete this->cStringArray[i];
                            }
                            delete[] this->cStringArray;
   }

  int32_t InputValues::getLength()
  {
    return this->cLength;
  }




InputValues::~InputValues()
  {
int arrayTypeToInt=-1;
      if(this->inTypes.compare("IntegerArrayType")==0) arrayTypeToInt=0;
        if(this->inTypes.compare("BooleanArrayType")==0) arrayTypeToInt=1;
         if(this->inTypes.compare("ByteArrayType")==0) arrayTypeToInt=2;
          if(this->inTypes.compare("CharArrayType")==0) arrayTypeToInt=3;
           if(this->inTypes.compare("DoubleArrayType")==0) arrayTypeToInt=4;
            if(this->inTypes.compare("FloatArrayType")==0) arrayTypeToInt=5;
            if(this->inTypes.compare("LongArrayType")==0) arrayTypeToInt=6;
             if(this->inTypes.compare("StringArrayType")==0) deleteStringArray();
     switch (arrayTypeToInt) {
              case 0:
                            delete[] cIntegerArray;
                            break;

                            case 1:
                                    delete[] cBooleanArray;
                                    break;
                                case 2:
                                    delete[] cByteArray;
                                    break;
                                case 3:
                                    delete[] cCharArray;
                                    break;
                             case 4:
                                    delete[] cDoubleArray;
                                      break;

                            case 5:
                                    delete[] cFloatArray;
                                        break;


                            case 6:
                                    delete[] cLongArray;
                                        break;
                           default: break;
                        }



  }

