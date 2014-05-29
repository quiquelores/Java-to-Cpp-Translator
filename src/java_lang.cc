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

#include "java_lang.h"

#include <sstream>

namespace java {
  namespace lang {

    // java.lang.Object()
    __Object::__Object() : __vptr(&__vtable) {
    }

    // The initializer (for executing the default constructor of a superclass)
    __Object* __Object::init(__Object* __this)
    {
      return __this;
    }

    // java.lang.Object.hashCode()
    int32_t __Object::hashCode(Object __this) {
      return (int32_t)(intptr_t)__this.raw();
    }

    // java.lang.Object.equals(Object)
    bool __Object::equals(Object __this, Object other) {
      return __this == other;
    }

    // java.lang.Object.getClass()
    Class __Object::getClass(Object __this) {
      return __this->__vptr->__isa;
    }

    // java.lang.Object.toString()
    String __Object::toString(Object __this) {
      // Class k = this.getClass();
      Class k = __this->__vptr->getClass(__this);

      std::ostringstream sout;
      sout << k->__vptr->getName(k)->data
           << '@' << std::hex << (uintptr_t)__this.raw();
      return new __String(sout.str());
    }

    // Internal accessor for java.lang.Object's class.
    Class __Object::__class() {
      static Class k =
        new __Class(__rt::literal("java.lang.Object"), (Class)__rt::null());
      return k;
    }

    // The vtable for java.lang.Object.  Note that this definition
    // invokes the default no-arg constructor for __Object_VT.
    __Object_VT __Object::__vtable;

    // =======================================================================

    // java.lang.String(<literal>)
    __String::__String(std::string data)
      : __vptr(&__vtable), 
        data(data) {
    }

    // The initializer (for executing the default constructor of a superclass)
    __String* __String::init(__String* __this)
    {
      __Object::init((__Object*) __this);

      return __this;
    }

    // java.lang.String.hashCode()
    int32_t __String::hashCode(String __this) {
      int32_t hash = 0;

      // Use a C++ iterator to access string's characters.
      for (std::string::iterator itr = __this->data.begin();
           itr < __this->data.end();
           itr++) {
        hash = 31 * hash + *itr;
      }

      return hash;
    }

    // java.lang.String.equals()
    bool __String::equals(String __this, Object o) {
      // Make sure object is a string:
      // if (! o instanceof String) return false;
      Class k = __String::__class();
      if (! k->__vptr->isInstance(k, o)) return false;

      // Do the actual comparison.
      String other = (String)o; // Downcast.
      return __this->data.compare(other->data) == 0;
    }

    // java.lang.String.toString()
    String __String::toString(String __this) {
      return __this;
    }

    // java.lang.String.length()
    int32_t __String::length(String __this) {
      return __this->data.length();
    }

    // java.lang.String.charAt()
    char __String::charAt(String __this, int32_t idx) {
      if (0 > idx || idx >= __this->data.length()) {
        throw IndexOutOfBoundsException();
      }

      // Use std::string::operator[] to get character without
      // duplicate range check.
      return __this->data[idx];
    }

    // Internal accessor for java.lang.String's class.
    Class __String::__class() {
      static Class k =
        new __Class(__rt::literal("java.lang.String"), __Object::__class());
      return k;
    }

    std::ostream& operator<<(std::ostream& out, String s) {
      out << s->data;
      return out;
    }

    // The vtable for java.lang.String.  Note that this definition
    // invokes the default no-arg constructor for __String_VT.
    __String_VT __String::__vtable;

    // =======================================================================

    // java.lang.Class(String, Class)
    __Class::__Class(String name, Class parent, Class component, bool primitive)
      : __vptr(&__vtable),
        name(name),
        parent(parent),
        component(component),
        primitive(primitive) {
    }

    // The initializer (for executing the default constructor of a superclass)
    __Class* __Class::init(__Class* __this)
    {
      __Object::init((__Object*) __this);

      return __this;
    }

    // java.lang.Class.toString()
    String __Class::toString(Class __this) {
      if (__this->primitive) {
        return __this->name;
      } else {
        return new __String("class " + __this->name->data);
      }
    }

    // java.lang.Class.getName()
    String __Class::getName(Class __this) {
      return __this->name;
    }

    // java.lang.Class.getSuperclass()
    Class __Class::getSuperclass(Class __this) {
      return __this->parent;
    }

    // java.lang.Class.isPrimitive()
    bool __Class::isPrimitive(Class __this) {
      return __this->primitive;
    }

    // java.lang.Class.isArray()
    bool __Class::isArray(Class __this) {
      return (Class)__rt::null() != __this->component;
    }

    // java.lang.Class.getComponentType()
    Class __Class::getComponentType(Class __this) {
      return __this->component;
    }

    // java.lang.Class.isInstance(Object)
    bool __Class::isInstance(Class __this, Object o) {
      Class k = o->__vptr->getClass(o);

      do {
        if (__this->__vptr->equals(__this, (Object)k)) return true;

        // FIXME: handle covariance of arrays

        k = k->__vptr->getSuperclass(k);
      } while ((Class)__rt::null() != k);

      return false;
    }

    // Internal accessor for java.lang.Class' class.
    Class __Class::__class() {
      static Class k = 
        new __Class(__rt::literal("java.lang.Class"), __Object::__class());
      return k;
    }

    // The vtable for java.lang.Class.  Note that this definition
    // invokes the default no-arg constructor for __Class_VT.
    __Class_VT __Class::__vtable;

    // =======================================================================

    // java.lang.Byte.TYPE
    Class __Byte::TYPE() {
      static Class k =
        new __Class(__rt::literal("byte"), (Class)__rt::null(),
                    (Class)__rt::null(), true);
      return k;
    }

    // java.lang.Byte(<literal>)
    __Byte::__Byte(signed char data)
      : __vptr(&__vtable), 
        data(data) {
    }

    // The initializer (for executing the default constructor of a superclass)
    __Byte* __Byte::init(__Byte* __this)
    {
      return __this;
    }

    // java.lang.Byte.hashCode()
    int32_t __Byte::hashCode(Byte __this) {
      return ((int32_t) __this->data);
    }

    // java.lang.Byte.equals()
    bool __Byte::equals(Byte __this, Object o) {
      // Make sure object is a byte:
      Class k = __Byte::TYPE();
      if (! k->__vptr->isInstance(k, o)) return false;

      // Do the actual comparison.
      Byte other = (Byte)o; // Downcast.
      return __this->data == other->data;
    }

    // java.lang.Byte.toString()
    String __Byte::toString(Byte __this) {
      std::stringstream ss;
      ss << ((int32_t)__this->data);
      return __rt::literal(ss.str().c_str());
    }

    // The vtable for java.lang.Byte.  Note that this definition
    // invokes the default no-arg constructor for __Byte_VT.
    __Byte_VT __Byte::__vtable;

    // =======================================================================

    // java.lang.Short.TYPE
    Class __Short::TYPE() {
      static Class k =
        new __Class(__rt::literal("short"), (Class)__rt::null(),
                    (Class)__rt::null(), true);
      return k;
    }

    // java.lang.Short(<literal>)
    __Short::__Short(short data)
      : __vptr(&__vtable), 
        data(data) {
    }

    // The initializer (for executing the default constructor of a superclass)
    __Short* __Short::init(__Short* __this)
    {
      return __this;
    }

    // java.lang.Short.hashCode()
    int32_t __Short::hashCode(Short __this) {
      return ((int32_t) __this->data);
    }

    // java.lang.Short.equals()
    bool __Short::equals(Short __this, Object o) {
      // Make sure object is a short:
      Class k = __Short::TYPE();
      if (! k->__vptr->isInstance(k, o)) return false;

      // Do the actual comparison.
      Short other = (Short)o; // Downcast.
      return __this->data == other->data;
    }

    // java.lang.Short.toString()
    String __Short::toString(Short __this) {
      std::stringstream ss;
      ss << __this->data;
      return __rt::literal(ss.str().c_str());
    }

    // The vtable for java.lang.Short.  Note that this definition
    // invokes the default no-arg constructor for __Short_VT.
    __Short_VT __Short::__vtable;

    // =======================================================================

    // java.lang.Integer.TYPE
    Class __Integer::TYPE() {
      static Class k =
        new __Class(__rt::literal("int"), (Class)__rt::null(),
                    (Class)__rt::null(), true);
      return k;
    }

    // java.lang.Integer(<literal>)
    __Integer::__Integer(int32_t data)
      : __vptr(&__vtable), 
        data(data) {
    }

    // The initializer (for executing the default constructor of a superclass)
    __Integer* __Integer::init(__Integer* __this)
    {
      return __this;
    }

    // java.lang.Integer.hashCode()
    int32_t __Integer::hashCode(Integer __this) {
      return __this->data;
    }

    // java.lang.Integer.equals()
    bool __Integer::equals(Integer __this, Object o) {
      // Make sure object is an integer:
      Class k = __Integer::TYPE();
      if (! k->__vptr->isInstance(k, o)) return false;

      // Do the actual comparison.
      Integer other = (Integer)o; // Downcast.
      return __this->data == other->data;
    }

    // java.lang.Integer.toString()
    String __Integer::toString(Integer __this) {
      std::stringstream ss;
      ss << __this->data;
      return __rt::literal(ss.str().c_str());
    }

    // The vtable for java.lang.Integer.  Note that this definition
    // invokes the default no-arg constructor for __Integer_VT.
    __Integer_VT __Integer::__vtable;

    // =======================================================================

    // java.lang.Long.TYPE
    Class __Long::TYPE() {
      static Class k =
        new __Class(__rt::literal("long"), (Class)__rt::null(),
                    (Class)__rt::null(), true);
      return k;
    }

    // java.lang.Long(<literal>)
    __Long::__Long(int64_t data)
      : __vptr(&__vtable), 
        data(data) {
    }

    // The initializer (for executing the default constructor of a superclass)
    __Long* __Long::init(__Long* __this)
    {
      return __this;
    }

    // java.lang.Long.hashCode()
    int32_t __Long::hashCode(Long __this) {
      return ((int32_t) (__this->data ^ ((int64_t) (((unsigned int64_t) __this->data) >> 32))));
    }

    // java.lang.Long.equals()
    bool __Long::equals(Long __this, Object o) {
      // Make sure object is a long:
      Class k = __Long::TYPE();
      if (! k->__vptr->isInstance(k, o)) return false;

      // Do the actual comparison.
      Long other = (Long)o; // Downcast.
      return __this->data == other->data;
    }

    // java.lang.Long.toString()
    String __Long::toString(Long __this) {
      std::stringstream ss;
      ss << __this->data;
      return __rt::literal(ss.str().c_str());
    }

    // The vtable for java.lang.Long.  Note that this definition
    // invokes the default no-arg constructor for __Long_VT.
    __Long_VT __Long::__vtable;

    // =======================================================================

    // java.lang.Float.TYPE
    Class __Float::TYPE() {
      static Class k =
        new __Class(__rt::literal("float"), (Class)__rt::null(),
                    (Class)__rt::null(), true);
      return k;
    }

    // java.lang.Float(<literal>)
    __Float::__Float(float data)
      : __vptr(&__vtable), 
        data(data) {
    }

    // The initializer (for executing the default constructor of a superclass)
    __Float* __Float::init(__Float* __this)
    {
      return __this;
    }

    // java.lang.Float.hashCode()
    int32_t __Float::hashCode(Float __this) {
      return __Integer::hashCode(new __Integer(*((int32_t*)(&(__this->data)))));
    }

    // java.lang.Float.equals()
    bool __Float::equals(Float __this, Object o) {
      // Make sure object is a float:
      Class k = __Float::TYPE();
      if (! k->__vptr->isInstance(k, o)) return false;

      // Do the actual comparison.
      Float other = (Float)o; // Downcast.
      return __this->data == other->data;
    }

    // java.lang.Float.toString()
    String __Float::toString(Float __this) {
      std::stringstream ss;
      ss << __this->data;
      return __rt::literal(ss.str().c_str());
    }

    // The vtable for java.lang.Float.  Note that this definition
    // invokes the default no-arg constructor for __Float_VT.
    __Float_VT __Float::__vtable;

    // =======================================================================

    // java.lang.Double.TYPE
    Class __Double::TYPE() {
      static Class k =
        new __Class(__rt::literal("double"), (Class)__rt::null(),
                    (Class)__rt::null(), true);
      return k;
    }

    // java.lang.Double(<literal>)
    __Double::__Double(double data)
      : __vptr(&__vtable), 
        data(data) {
    }

    // The initializer (for executing the default constructor of a superclass)
    __Double* __Double::init(__Double* __this)
    {
      return __this;
    }

    // java.lang.Double.hashCode()
    int32_t __Double::hashCode(Double __this) {
      return __Long::hashCode(new __Long(*((int64_t*)(&(__this->data)))));;
    }

    // java.lang.Double.equals()
    bool __Double::equals(Double __this, Object o) {
      // Make sure object is a double:
      Class k = __Double::TYPE();
      if (! k->__vptr->isInstance(k, o)) return false;

      // Do the actual comparison.
      Double other = (Double)o; // Downcast.
      return __this->data == other->data;
    }

    // java.lang.Double.toString()
    String __Double::toString(Double __this) {
      std::stringstream ss;
      ss << __this->data;
      return __rt::literal(ss.str().c_str());
    }

    // The vtable for java.lang.Double.  Note that this definition
    // invokes the default no-arg constructor for __Double_VT.
    __Double_VT __Double::__vtable;

    // =======================================================================

    // java.lang.Boolean.TYPE
    Class __Boolean::TYPE() {
      static Class k =
        new __Class(__rt::literal("boolean"), (Class)__rt::null(),
                    (Class)__rt::null(), true);
      return k;
    }

    // java.lang.Boolean(<literal>)
    __Boolean::__Boolean(bool data)
      : __vptr(&__vtable), 
        data(data) {
    }

    // The initializer (for executing the default constructor of a superclass)
    __Boolean* __Boolean::init(__Boolean* __this)
    {
      return __this;
    }

    // java.lang.Boolean.hashCode()
    int32_t __Boolean::hashCode(Boolean __this) {
      if(__this->data)
        return 1231;
      else return 1237;
    }

    // java.lang.Boolean.equals()
    bool __Boolean::equals(Boolean __this, Object o) {
      // Make sure object is a boolean:
      Class k = __Boolean::TYPE();
      if (! k->__vptr->isInstance(k, o)) return false;

      // Do the actual comparison.
      Boolean other = (Boolean)o; // Downcast.
      return __this->data == other->data;
    }

    // java.lang.Boolean.toString()
    String __Boolean::toString(Boolean __this) {
      std::stringstream ss;
      ss << __this->data;
      return __rt::literal(ss.str().c_str());
    }

    // The vtable for java.lang.Boolean.  Note that this definition
    // invokes the default no-arg constructor for __Boolean_VT.
    __Boolean_VT __Boolean::__vtable;

    // =======================================================================

    // java.lang.Character.TYPE
    Class __Character::TYPE() {
      static Class k =
        new __Class(__rt::literal("char"), (Class)__rt::null(),
                    (Class)__rt::null(), true);
      return k;
    }

    // java.lang.Character(<literal>)
    __Character::__Character(char data)
      : __vptr(&__vtable), 
        data(data) {
    }

    // The initializer (for executing the default constructor of a superclass)
    __Character* __Character::init(__Character* __this)
    {
      return __this;
    }

    // java.lang.Character.hashCode()
    int32_t __Character::hashCode(Character __this) {
      return ((int32_t) __this->data);
    }

    // java.lang.Character.equals()
    bool __Character::equals(Character __this, Object o) {
      // Make sure object is a char:
      Class k = __Character::TYPE();
      if (! k->__vptr->isInstance(k, o)) return false;

      // Do the actual comparison.
      Character other = (Character)o; // Downcast.
      return __this->data == other->data;
    }

    // java.lang.Character.toString()
    String __Character::toString(Character __this) {
      std::stringstream ss;
      ss << __this->data;
      return __rt::literal(ss.str().c_str());
    }

    // The vtable for java.lang.Character.  Note that this definition
    // invokes the default no-arg constructor for __Character_VT.
    __Character_VT __Character::__vtable;
  }
}

// ===========================================================================

namespace __rt {

  // The function returning the canonical null value.
  java::lang::Object null() {
    static java::lang::Object value(0);
    return value;
  }

  // Template specialization for arrays of ints.
  template<>
  java::lang::Class Array<int32_t>::__class() {
    static java::lang::Class k =
      new java::lang::__Class(literal("[I"),
                              java::lang::__Object::__class(),
                              java::lang::__Integer::TYPE());
    return k;
  }

  // Template specialization for arrays of objects.
  template<>
  java::lang::Class Array<java::lang::Object>::__class() {
    static java::lang::Class k =
      new java::lang::__Class(literal("[Ljava.lang.Object;"),
                              java::lang::__Object::__class(),
                              java::lang::__Object::__class());
    return k;
  }

  // Template specialization for arrays of strings.
  template<>
  java::lang::Class Array<java::lang::String>::__class() {
    static java::lang::Class k =
      new java::lang::__Class(literal("[Ljava.lang.String;"),
                              java::lang::__Object::__class(),
                              java::lang::__String::__class());
    return k;
  }

}
