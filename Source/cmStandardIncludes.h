/*============================================================================
  CMake - Cross Platform Makefile Generator
  Copyright 2000-2009 Kitware, Inc., Insight Software Consortium

  Distributed under the OSI-approved BSD License (the "License");
  see accompanying file Copyright.txt for details.

  This software is distributed WITHOUT ANY WARRANTY; without even the
  implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
  See the License for more information.
============================================================================*/
/**
 * Include header files as a function of the build process, compiler,
 * and operating system.
 */
#ifndef cmStandardIncludes_h
#define cmStandardIncludes_h

#include <cmConfigure.h>

// Provide fixed-size integer types.
#include <cm_kwiml.h>

#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>

// we must have stl with the standard include style
#include <algorithm>
#include <functional>
#include <iterator>
#include <map>
#include <set>
#include <string>
#include <vector>

// include the "c" string header
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#if defined(_MSC_VER)
typedef unsigned short mode_t;
#else
#include <sys/types.h>
#endif

// use this class to shrink the size of symbols in .o files
// std::string is really basic_string<....lots of stuff....>
// when combined with a map or set, the symbols can be > 2000 chars!
#include <cmsys/String.hxx>
// typedef cmsys::String std::string;

/* Poison this operator to avoid common mistakes.  */
extern void operator<<(std::ostream&, const std::ostringstream&);

#include "cmDocumentationEntry.h"
#include "cmCustomCommandLines.h"

// All subclasses of cmCommand or cmCTestGenericHandler should
// invoke this macro.
#define cmTypeMacro(thisClass, superclass)                                    \
  virtual const char* GetNameOfClass() { return #thisClass; }                 \
  typedef superclass Superclass;                                              \
  static bool IsTypeOf(const char* type)                                      \
  {                                                                           \
    if (!strcmp(#thisClass, type)) {                                          \
      return true;                                                            \
    }                                                                         \
    return Superclass::IsTypeOf(type);                                        \
  }                                                                           \
  virtual bool IsA(const char* type) { return thisClass::IsTypeOf(type); }    \
  static thisClass* SafeDownCast(cmObject* c)                                 \
  {                                                                           \
    if (c && c->IsA(#thisClass)) {                                            \
      return static_cast<thisClass*>(c);                                      \
    }                                                                         \
    return 0;                                                                 \
  }                                                                           \
  class cmTypeMacro_UseTrailingSemicolon

enum cmTargetLinkLibraryType
{
  GENERAL_LibraryType,
  DEBUG_LibraryType,
  OPTIMIZED_LibraryType
};

#endif
