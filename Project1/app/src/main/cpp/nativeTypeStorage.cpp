//
// Created by gamuatachu on 7.10.2019.
//

#include "nativeTypeStorage.h"
#include <cstdlib>
#include <cstring>












/*
InputTypes::InputTypes(string input):inputDataType(input) {

}*/

string InputValues::getType()
{
 return inTypes;
}

uint8_t InputValues::getBoolean()
{
      return cBoolean;
 }
int8_t    InputValues::getByte()
{
      return cByte;
     }
 uint16_t InputValues::getChar()
 {
  return cChar;
 }
 double InputValues::getDouble()
 {
  return cDouble;
 }
  float InputValues::getFloat()
  {
   return cFloat;
  }
  int32_t InputValues:: getInteger()
  {
   return cInteger;
  }
  int64_t InputValues::getLong()
  {
   return cLong;
  }
   int16_t InputValues::getShort()
   {
    return cShort;
   }
   char* InputValues::getString()
   {
    return cString;
   }

 void InputValues::deleteString()
   {
    delete cString;
   }