/*
 * Object-Oriented Programming
 * Copyright (C) 2012 Robert Grimm
 * Modifications copyright (C) 2013 Thomas Wies
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * version 2 as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301,
 * USA.
 */

#pragma once

#include <stdint.h>
#include <string>
#include <iostream>

#include "ptr.h"

// ==========================================================================

// To avoid the "static initialization order fiasco", we use functions
// instead of fields/variables for all pointer values that are statically
// initialized.

// See http://www.parashift.com/c++-faq-lite/ctors.html#faq-10.14.

// ==========================================================================

namespace java {
  namespace lang {

    // Forward declarations of data layout and vtables.
    struct __Object;
    struct __Object_VT;

    struct __String;
    struct __String_VT;

    struct __Class;
    struct __Class_VT;

    struct __Byte;
    struct __Byte_VT;

    struct __Short;
    struct __Short_VT;

    struct __Integer;
    struct __Integer_VT;

    struct __Long;
    struct __Long_VT;

    struct __Float;
    struct __Float_VT;

    struct __Double;
    struct __Double_VT;

    struct __Boolean;
    struct __Boolean_VT;

    struct __Character;
    struct __Character_VT;

    // Definition of type names, which are equivalent to Java semantics,
    // i.e., an instance is the address of the object's data layout.
    typedef __rt::Ptr<__Object> Object;
    typedef __rt::Ptr<__Class> Class;
    typedef __rt::Ptr<__String> String;
    typedef __rt::Ptr<__Byte> Byte;
    typedef __rt::Ptr<__Short> Short;
    typedef __rt::Ptr<__Integer> Integer;
    typedef __rt::Ptr<__Long> Long;
    typedef __rt::Ptr<__Float> Float;
    typedef __rt::Ptr<__Double> Double;
    typedef __rt::Ptr<__Boolean> Boolean;
    typedef __rt::Ptr<__Character> Character;
  }
}

// ==========================================================================

namespace __rt {

  // The function returning the canonical null value.
  java::lang::Object null();

  // The template function for the virtual destructor.
  template <typename T>
  void __delete(T* addr) {
    delete addr;
  }

}

// ==========================================================================

namespace java {
  namespace lang {

    // The data layout for java.lang.Object.
    struct __Object {
      __Object_VT* __vptr;

      // The constructor.
      __Object();

      // The initializer (for executing the default constructor of a superclass)
      static __Object* init(__Object*);

      // The methods implemented by java.lang.Object.
      static int32_t hashCode(Object);
      static bool equals(Object, Object);
      static Class getClass(Object);
      static String toString(Object);

      // The function returning the class object representing
      // java.lang.Object.
      static Class __class();

      // The vtable for java.lang.Object.
      static __Object_VT __vtable;
    };

    // The vtable layout for java.lang.Object.
    struct __Object_VT {
      Class __isa;
      void (*__delete)(__Object*);
      int32_t (*hashCode)(Object);
      bool (*equals)(Object, Object);
      Class (*getClass)(Object);
      String (*toString)(Object);

      __Object_VT()
      : __isa(__Object::__class()),
        __delete(&__rt::__delete<__Object>),
        hashCode(&__Object::hashCode),
        equals(&__Object::equals),
        getClass(&__Object::getClass),
        toString(&__Object::toString) {
      }
    };

    // ======================================================================

    // The data layout for java.lang.String.
    struct __String {
      __String_VT* __vptr;
      std::string data;

      // The constructor;
      __String(std::string data);

      // The initializer (for executing the default constructor of a superclass)
      static __String* init(__String*);

      // The methods implemented by java.lang.String.
      static int32_t hashCode(String);
      static bool equals(String, Object);
      static String toString(String);
      static int32_t length(String);
      static char charAt(String, int32_t);

      // The function returning the class object representing
      // java.lang.String.
      static Class __class();

      // The vtable for java.lang.String.
      static __String_VT __vtable;
    };

    std::ostream& operator<<(std::ostream& out, String);

    // The vtable layout for java.lang.String.
    struct __String_VT {
      Class __isa;
      void (*__delete)(__String*);
      int32_t (*hashCode)(String);
      bool (*equals)(String, Object);
      Class (*getClass)(String);
      String (*toString)(String);
      int32_t (*length)(String);
      char (*charAt)(String, int32_t);
      
      __String_VT()
      : __isa(__String::__class()),
        __delete(&__rt::__delete<__String>),
        hashCode(&__String::hashCode),
        equals(&__String::equals),
        getClass((Class(*)(String))&__Object::getClass),
        toString(&__String::toString),
        length(&__String::length),
        charAt(&__String::charAt) {
      }
    };

    // ======================================================================

    // The data layout for java.lang.Class.
    struct __Class {
      __Class_VT* __vptr;
      String name;
      Class parent;
      Class component;
      bool primitive;

      // The constructor.
      __Class(String name,
              Class parent,
              Class component = (Class)__rt::null(),
              bool primitive = false);

      // The initializer (for executing the default constructor of a superclass)
      static __Class* init(__Class*);

      // The instance methods of java.lang.Class.
      static String toString(Class);
      static String getName(Class);
      static Class getSuperclass(Class);
      static bool isPrimitive(Class);
      static bool isArray(Class);
      static Class getComponentType(Class);
      static bool isInstance(Class, Object);

      // The function returning the class object representing
      // java.lang.Class.
      static Class __class();

      // The vtable for java.lang.Class.
      static __Class_VT __vtable;
    };

    // The vtable layout for java.lang.Class.
    struct __Class_VT {
      Class __isa;
      void (*__delete)(__Class*);
      int32_t (*hashCode)(Class);
      bool (*equals)(Class, Object);
      Class (*getClass)(Class);
      String (*toString)(Class);
      String (*getName)(Class);
      Class (*getSuperclass)(Class);
      bool (*isPrimitive)(Class);
      bool (*isArray)(Class);
      Class (*getComponentType)(Class);
      bool (*isInstance)(Class, Object);

      __Class_VT()
      : __isa(__Class::__class()),
        __delete(&__rt::__delete<__Class>),
        hashCode((int32_t(*)(Class))&__Object::hashCode),
        equals((bool(*)(Class,Object))&__Object::equals),
        getClass((Class(*)(Class))&__Object::getClass),
        toString(&__Class::toString),
        getName(&__Class::getName),
        getSuperclass(&__Class::getSuperclass),
        isPrimitive(&__Class::isPrimitive),
        isArray(&__Class::isArray),
        getComponentType(&__Class::getComponentType),
        isInstance(&__Class::isInstance) {
      }
    };

    // ======================================================================

    struct __Byte {
      __Byte_VT* __vptr;
      signed char data;

      // The constructor;
      __Byte(signed char);

      // The initializer (for executing the default constructor of a superclass)
      static __Byte* init(__Byte*);

      // The methods implemented by java.lang.Byte.
      static int32_t hashCode(Byte);
      static bool equals(Byte, Object);
      static String toString(Byte);

      // The vtable for java.lang.Byte.
      static __Byte_VT __vtable;

      // The class instance representing the primitive type byte.
      static Class TYPE();
    };

    // The vtable layout for java.lang.Byte.
    struct __Byte_VT {
      Class __isa;
      void (*__delete)(__Byte*);
      int32_t (*hashCode)(Byte);
      bool (*equals)(Byte, Object);
      Class (*getClass)(Byte);
      String (*toString)(Byte);
      
      __Byte_VT()
      : __isa(__Byte::TYPE()),
        __delete(__rt::__delete<__Byte>),
        hashCode(&__Byte::hashCode),
        equals(&__Byte::equals),
        getClass((Class(*)(Byte))&__Object::getClass),
        toString(&__Byte::toString) {
      }
    };

    struct __Short {
      __Short_VT* __vptr;
      int16_t data;

      // The constructor;
      __Short(int16_t);

      // The initializer (for executing the default constructor of a superclass)
      static __Short* init(__Short*);

      // The methods implemented by java.lang.Short.
      static int32_t hashCode(Short);
      static bool equals(Short, Object);
      static String toString(Short);

      // The vtable for java.lang.Short.
      static __Short_VT __vtable;

      // The class instance representing the primitive type short.
      static Class TYPE();
    };

    // The vtable layout for java.lang.Short.
    struct __Short_VT {
      Class __isa;
      void (*__delete)(__Short*);
      int32_t (*hashCode)(Short);
      bool (*equals)(Short, Object);
      Class (*getClass)(Short);
      String (*toString)(Short);
      
      __Short_VT()
      : __isa(__Short::TYPE()),
        __delete(__rt::__delete<__Short>),
        hashCode(&__Short::hashCode),
        equals(&__Short::equals),
        getClass((Class(*)(Short))&__Object::getClass),
        toString(&__Short::toString) {
      }
    };

    struct __Integer {
      __Integer_VT* __vptr;
      int32_t data;

      // The constructor;
      __Integer(int32_t);

      // The initializer (for executing the default constructor of a superclass)
      static __Integer* init(__Integer*);

      // The methods implemented by java.lang.Integer.
      static int32_t hashCode(Integer);
      static bool equals(Integer, Object);
      static String toString(Integer);

      // The class instance representing the primitive type int.
      static Class TYPE();

      // The vtable for java.lang.Integer.
      static __Integer_VT __vtable;
    };

    // The vtable layout for java.lang.Integer.
    struct __Integer_VT {
      Class __isa;
      void (*__delete)(__Integer*);
      int32_t (*hashCode)(Integer);
      bool (*equals)(Integer, Object);
      Class (*getClass)(Integer);
      String (*toString)(Integer);
      
      __Integer_VT()
      : __isa(__Integer::TYPE()),
        __delete(__rt::__delete<__Integer>),
        hashCode(&__Integer::hashCode),
        equals(&__Integer::equals),
        getClass((Class(*)(Integer))&__Object::getClass),
        toString(&__Integer::toString) {
      }
    };

    struct __Long {
      __Long_VT* __vptr;
      int64_t data;

      // The constructor;
      __Long(int64_t);

      // The initializer (for executing the default constructor of a superclass)
      static __Long* init(__Long*);

      // The methods implemented by java.lang.Long.
      static int32_t hashCode(Long);
      static bool equals(Long, Object);
      static String toString(Long);

      // The vtable for java.lang.Long.
      static __Long_VT __vtable;

      // The class instance representing the primitive type long.
      static Class TYPE();
    };

    // The vtable layout for java.lang.Long.
    struct __Long_VT {
      Class __isa;
      void (*__delete)(__Long*);
      int32_t (*hashCode)(Long);
      bool (*equals)(Long, Object);
      Class (*getClass)(Long);
      String (*toString)(Long);
      
      __Long_VT()
      : __isa(__Long::TYPE()),
        __delete(__rt::__delete<__Long>),
        hashCode(&__Long::hashCode),
        equals(&__Long::equals),
        getClass((Class(*)(Long))&__Object::getClass),
        toString(&__Long::toString) {
      }
    };

    struct __Float {
      __Float_VT* __vptr;
      float data;

      // The constructor;
      __Float(float);

      // The initializer (for executing the default constructor of a superclass)
      static __Float* init(__Float*);

      // The methods implemented by java.lang.Float.
      static int32_t hashCode(Float);
      static bool equals(Float, Object);
      static String toString(Float);

      // The vtable for java.lang.Float.
      static __Float_VT __vtable;

      // The class instance representing the primitive type float.
      static Class TYPE();
    };

    // The vtable layout for java.lang.Float.
    struct __Float_VT {
      Class __isa;
      void (*__delete)(__Float*);
      int32_t (*hashCode)(Float);
      bool (*equals)(Float, Object);
      Class (*getClass)(Float);
      String (*toString)(Float);
      
      __Float_VT()
      : __isa(__Float::TYPE()),
        __delete(__rt::__delete<__Float>),
        hashCode(&__Float::hashCode),
        equals(&__Float::equals),
        getClass((Class(*)(Float))&__Object::getClass),
        toString(&__Float::toString) {
      }
    };

    struct __Double {
      __Double_VT* __vptr;
      double data;

      // The constructor;
      __Double(double);

      // The initializer (for executing the default constructor of a superclass)
      static __Double* init(__Double*);

      // The methods implemented by java.lang.Double.
      static int32_t hashCode(Double);
      static bool equals(Double, Object);
      static String toString(Double);

      // The vtable for java.lang.Double.
      static __Double_VT __vtable;

      // The class instance representing the primitive type double.
      static Class TYPE();
    };

    // The vtable layout for java.lang.Double.
    struct __Double_VT {
      Class __isa;
      void (*__delete)(__Double*);
      int32_t (*hashCode)(Double);
      bool (*equals)(Double, Object);
      Class (*getClass)(Double);
      String (*toString)(Double);
      
      __Double_VT()
      : __isa(__Double::TYPE()),
        __delete(__rt::__delete<__Double>),
        hashCode(&__Double::hashCode),
        equals(&__Double::equals),
        getClass((Class(*)(Double))&__Object::getClass),
        toString(&__Double::toString) {
      }
    };

    struct __Boolean {
      __Boolean_VT* __vptr;
      bool data;

      // The constructor;
      __Boolean(bool);

      // The initializer (for executing the default constructor of a superclass)
      static __Boolean* init(__Boolean*);

      // The methods implemented by java.lang.Boolean.
      static int32_t hashCode(Boolean);
      static bool equals(Boolean, Object);
      static String toString(Boolean);

      // The vtable for java.lang.Boolean.
      static __Boolean_VT __vtable;

      // The class instance representing the primitive type boolean.
      static Class TYPE();
    };

    // The vtable layout for java.lang.Boolean.
    struct __Boolean_VT {
      Class __isa;
      void (*__delete)(__Boolean*);
      int32_t (*hashCode)(Boolean);
      bool (*equals)(Boolean, Object);
      Class (*getClass)(Boolean);
      String (*toString)(Boolean);
      
      __Boolean_VT()
      : __isa(__Boolean::TYPE()),
        __delete(__rt::__delete<__Boolean>),
        hashCode(&__Boolean::hashCode),
        equals(&__Boolean::equals),
        getClass((Class(*)(Boolean))&__Object::getClass),
        toString(&__Boolean::toString) {
      }
    };

    struct __Character {
      __Character_VT* __vptr;
      char data;

      // The constructor;
      __Character(char);

      // The initializer (for executing the default constructor of a superclass)
      static __Character* init(__Character*);

      // The methods implemented by java.lang.Character.
      static int32_t hashCode(Character);
      static bool equals(Character, Object);
      static String toString(Character);

      // The vtable for java.lang.Character.
      static __Character_VT __vtable;

      // The class instance representing the primitive type char.
      static Class TYPE();
    };

    // The vtable layout for java.lang.Character.
    struct __Character_VT {
      Class __isa;
      void (*__delete)(__Character*);
      int32_t (*hashCode)(Character);
      bool (*equals)(Character, Object);
      Class (*getClass)(Character);
      String (*toString)(Character);
      
      __Character_VT()
      : __isa(__Character::TYPE()),
        __delete(__rt::__delete<__Character>),
        hashCode(&__Character::hashCode),
        equals(&__Character::equals),
        getClass((Class(*)(Character))&__Object::getClass),
        toString(&__Character::toString) {
      }
    };
  }
}

namespace __rt {
  // Function for converting a C string literal to a translated
  // Java string.
  inline java::lang::String literal(const char * s) {
    // C++ implicitly converts the C string to a std::string.
    return new java::lang::__String(s);
  }
}
//TODO: Fill out exception messages
namespace java {
  namespace lang {
    // ======================================================================

    // For simplicity, we use C++ inheritance for exceptions and throw
    // them by value.  In other words, the translator does not support
    // user-defined exceptions and simply relies on a few built-in
    // classes.
    class Throwable {
      public:
        String message;

        Throwable()
        {
          message = (String) __rt::null();
        }

        Throwable(String message) : message(message)
        {
        }

        String getMessage()
        {
          return message;
        }

        String toString()
        {
          return __rt::literal("");
        }
    };

    class Exception : public Throwable {
      public:
        String message;

        Exception()
        {
          message = (String) __rt::null();
        }

        Exception(String message) : message(message)
        {
        }

        String toString()
        {
          return __rt::literal("");
        }
    };

    class RuntimeException : public Exception {
      public:
        String message;

        RuntimeException()
        {
          message = (String) __rt::null();
        }

        RuntimeException(String message) : message(message)
        {
        }

        String toString()
        {
          return __rt::literal("");
        }
    };

    class NullPointerException : public RuntimeException {
      public:
        String message;

        NullPointerException()
        {
          message = (String) __rt::null();
        }

        NullPointerException(String message) : message(message)
        {
        }

        String toString()
        {
          return __rt::literal("");
        }
    };

    class NegativeArraySizeException : public RuntimeException {
      public:
        String message;

        NegativeArraySizeException()
        {
          message = (String) __rt::null();
        }

        NegativeArraySizeException(String message) : message(message)
        {
        }

        String toString()
        {
          return __rt::literal("");
        }
    };

    class ArrayStoreException : public RuntimeException {
      public:
        String message;

        ArrayStoreException()
        {
          message = (String) __rt::null();
        }

        ArrayStoreException(String message) : message(message)
        {
        }

        String toString()
        {
          return __rt::literal("");
        }
    };

    class ClassCastException : public RuntimeException {
      public:
        String message;

        ClassCastException()
        {
          message = (String) __rt::null();
        }

        ClassCastException(String message) : message(message)
        {
        }

        String toString()
        {
          return __rt::literal("");
        }
    };

    class IndexOutOfBoundsException : public RuntimeException {
      public:
        String message;

        IndexOutOfBoundsException()
        {
          message = (String) __rt::null();
        }

        IndexOutOfBoundsException(String message) : message(message)
        {
        }

        String toString()
        {
          return __rt::literal("");
        }
    };

    class ArrayIndexOutOfBoundsException : public IndexOutOfBoundsException {
      public:
        String message;

        ArrayIndexOutOfBoundsException()
        {
          message = (String) __rt::null();
        }

        ArrayIndexOutOfBoundsException(String message) : message(message)
        {
        }

        String toString()
        {
          return __rt::literal("");
        }
    };
  }
}

// ==========================================================================

namespace __rt {

  // Forward declarations of data layout and vtable.
  template <typename T>
  struct Array;

  template <typename T>
  struct Array_VT;

  // The data layout for arrays.
  template <typename T>
  struct Array {
    Array_VT<T>* __vptr;
    const int32_t length;
    T* __data;

    // The constructor (defined inline).
    Array(const int32_t length)
      : __vptr(&__vtable), length(length), __data(new T[length]()) {
      if(length < 0)
        throw java::lang::NegativeArraySizeException();
    }

    // The initializer (for executing the default constructor of a superclass)
    static Array<T>* init(Array<T>* __this)
    {
      return __this;
    }

    // The destructor.
    static void __delete(Array* addr) {
      delete[] addr->__data;
      delete addr;
    }

    // Array access.
    T& operator[](int32_t index) {
      if (0 > index || index >= length) {
        throw java::lang::ArrayIndexOutOfBoundsException();
      }
      return __data[index];
    }

    const T& operator[](int32_t index) const {
      if (0 > index || index >= length) {
        throw java::lang::ArrayIndexOutOfBoundsException();
      }
      return __data[index];
    }

    // The function returning the class object representing the array.
    static java::lang::Class __class();

    // The vtable for the array.
    static Array_VT<T> __vtable;
  };

  // The vtable for arrays.
  template <typename T>
  struct Array_VT {
    typedef Ptr<Array<T> > Reference;

    java::lang::Class __isa;
    void (*__delete)(Array<T>*);
    int32_t (*hashCode)(Reference);
    bool (*equals)(Reference, java::lang::Object);
    java::lang::Class (*getClass)(Reference);
    java::lang::String (*toString)(Reference);
    
    Array_VT()
    : __isa(Array<T>::__class()),
      __delete(&Array<T>::__delete),
      hashCode((int32_t(*)(Reference))
               &java::lang::__Object::hashCode),
      equals((bool(*)(Reference,java::lang::Object))
             &java::lang::__Object::equals),
      getClass((java::lang::Class(*)(Reference))
               &java::lang::__Object::getClass),
      toString((java::lang::String(*)(Reference))
               &java::lang::__Object::toString) {
    }
  };

  // The vtable for arrays.  Note that this definition uses the default
  // no-arg constructor.
  template <typename T>
  Array_VT<T> Array<T>::__vtable;

  // But where is the definition of __class()???

  // ========================================================================

  // Template function to check against null values.
  template <typename T>
  void checkNotNull(T object) {
    if (null() == (java::lang::Object) object) {
      throw java::lang::NullPointerException();
    }
  }

  // Template function to check array access is within bounds.
  template <typename T>
  void checkIndex(Array<T>* array, int32_t index) {
    if (0 > index || index >= array->length) {
      throw java::lang::ArrayIndexOutOfBoundsException();
    }
  }

  // Template function to check array stores.
  template <typename T, typename U>
  void checkStore(Array<T>* array, U object) {
    if (null() != (java::lang::Object) object) {
      java::lang::Class t1 = array->__vptr->getClass(array);
      java::lang::Class t2 = t1->__vptr->getComponentType(t1);

      if (! t2->__vptr->isInstance(t2, (java::lang::Object)object)) {
        throw java::lang::ArrayStoreException();
      }
    }
  }

}
