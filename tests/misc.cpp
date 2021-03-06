// -*-c++-*-
//
//-----------------------------------------------------------------------bl-
//--------------------------------------------------------------------------
//
// MASA - Manufactured Analytical Solutions Abstraction Library
//
// Copyright (C) 2010,2011,2012 The PECOS Development Team
//
// This library is free software; you can redistribute it and/or
// modify it under the terms of the Version 2.1 GNU Lesser General
// Public License as published by the Free Software Foundation.
//
// This library is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
// Lesser General Public License for more details.
//
// You should have received a copy of the GNU Lesser General Public
// License along with this library; if not, write to the Free Software
// Foundation, Inc. 51 Franklin Street, Fifth Floor,
// Boston, MA  02110-1301  USA
//
//-----------------------------------------------------------------------el-
// $Author$
// $Id$
//
// misc.cpp : program that tests masa helper functions
//
//--------------------------------------------------------------------------
//--------------------------------------------------------------------------

#include <config.h>
#include <masa.h>
#include <cstdio>
#include <iostream>
#include <string>

using namespace MASA;
using namespace std;

typedef double Real;

int main()
{
  int i,err;
  string str;

  // testing masa_init
  err = masa_init<Real>("euler-test","euler_1d");
  if(err!=0)
    {
      cout << "masa_init FAILED\n";
      return 1;
    }
  
  // test get_dimension
  masa_get_dimension<Real>(&i);
  if(i!=1)
    {
      cout << "masa_get_dimension FAILED";
      return 1;
    }

  // test get_name
  masa_get_name<Real>(&str);  
  if(str.compare("euler_1d") != 0)
    {
      cout << "masa_get_name FAILED";
      return 1;
    }

  // now, test masa_map -- 
  // it should recognize regardless of: 
  // capital letters
  // '-' dashes
  // ' ' whitespace
  err = masa_init<Real>("euler-test-crazy","Eu l-er_2d");
  if(err!=0)
    {
      cout << "MASA_INIT FAILED\n";
      return 1;
    }

  // lets check this gave us the mms we expected:
  masa_get_name<Real>(&str);  
  if(str.compare("euler_2d") != 0)
    {
      cout << "masa_get_name FAILED";
      return 1;
    }

  // reroute stdout for regressions: TODO remove when logger mechanism
  // is used inside masa; these tests currently just verify functions
  // run successfully.

  freopen("/dev/null","w",stdout);

  // test a few other functions
  masa_printid<Real>();
  masa_version_stdout();
  masa_get_numeric_version();

  err = masa_display_param<Real>();

  if(err != 0)
    {
      cout << "MASA_DISPLAY_PARAM FAILED\n";
      return 1;
    }

  return 0; // steady as she goes

}
