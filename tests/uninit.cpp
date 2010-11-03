// -*-c++-*-
//
//-----------------------------------------------------------------------bl-
//--------------------------------------------------------------------------
//
// MASA - Manufactured Analytical Solutions Abstraction Library
//
// Copyright (C) 2010 The PECOS Development Team
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
// uninit.cpp : program that tests error on uninitialized functions
//
//--------------------------------------------------------------------------
//--------------------------------------------------------------------------

#include <config.h>
#include <masa.h>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <iostream>

using namespace MASA;
using namespace std;

typedef double Scalar;

int main()
{
  Scalar derr;
  int err=0;

  Scalar x=0;
  Scalar y=0;
  Scalar z=0;
  Scalar t=0;
  
  masa_init<Scalar>("masa-test","euler_1d");

  // reroute stdout for regressions: TODO remove when logger mechanism
  // is used inside masa.
  freopen("/dev/null","w",stdout);
  masa_display_param<Scalar>();

  masa_init<Scalar>("masa-test-uninit","masa_uninit");

  // start testing uninitialized functions
  derr = masa_init_param<Scalar>();
  if(derr != 0) 
    err += 1;
  
  // --------------------------------
  // source term(s) -- 1D
  // --------------------------------
  
  derr = masa_eval_t_source<Scalar>(x); 
  if(derr != -1.33) 
    err += 1;

  derr = masa_eval_t_source<Scalar>(x,y);
  if(derr != -1.33) 
    err += 1;

  derr = masa_eval_u_source<Scalar>(x);
  if(derr != -1.33) 
    err += 1;

  derr = masa_eval_v_source<Scalar>(x);  
  if(derr != -1.33) 
    err += 1;

  derr = masa_eval_w_source<Scalar>(x);  
  if(derr != -1.33) 
    err += 1;

  derr = masa_eval_e_source<Scalar>(x);
  if(derr != -1.33) 
    err += 1;

  derr = masa_eval_rho_source<Scalar>(x);
  if(derr != -1.33) 
    err += 1;

  derr = masa_eval_rho_u_source<Scalar>(x,y);
  if(derr != -1.33) 
    err += 1;
  
  derr = masa_eval_t_an<Scalar>(x); 
  if(derr != -1.33) 
    err += 1;

  derr = masa_eval_t_an<Scalar>(x,y);
  if(derr != -1.33) 
    err += 1;

  derr = masa_eval_u_an<Scalar>(x);
  if(derr != -1.33) 
    err += 1;

  derr = masa_eval_v_an<Scalar>(x);
  if(derr != -1.33) 
    err += 1;

  derr = masa_eval_w_an<Scalar>(x);
  if(derr != -1.33) 
    err += 1;

  derr = masa_eval_p_an<Scalar>(x);
  if(derr != -1.33) 
    err += 1;

  derr = masa_eval_rho_an<Scalar>(x);
  if(derr != -1.33) 
    err += 1;  

  derr = masa_eval_1d_grad_u<Scalar>(x);
  if(derr != -1.33) 
    err += 1;  

  derr = masa_eval_1d_grad_v<Scalar>(x);
  if(derr != -1.33) 
    err += 1;  

  derr = masa_eval_1d_grad_w<Scalar>(x);
  if(derr != -1.33) 
    err += 1;  

  derr = masa_eval_1d_grad_p<Scalar>(x);
  if(derr != -1.33) 
    err += 1;  

  derr = masa_eval_1d_grad_rho<Scalar>(x);
  if(derr != -1.33) 
    err += 1;  
  
  // --------------------------------
  // source term(s) -- 2D
  // --------------------------------
  derr = masa_eval_t_source<Scalar>(x,y,z); 
  if(derr != -1.33) 
    err += 1;

  derr = masa_eval_u_source<Scalar>(x,y);
  if(derr != -1.33) 
    err += 1;

  derr = masa_eval_v_source<Scalar>(x,y);
  if(derr != -1.33) 
    err += 1;

  derr = masa_eval_w_source<Scalar>(x,y);
  if(derr != -1.33) 
    err += 1;

  derr = masa_eval_e_source<Scalar>(x,y);
  if(derr != -1.33) 
    err += 1;

  derr = masa_eval_rho_source<Scalar>(x,y);
  if(derr != -1.33) 
    err += 1;
  
  derr = masa_eval_t_an<Scalar>(x,y,z);
  if(derr != -1.33) 
    err += 1;

  derr = masa_eval_u_an<Scalar>(x,y);
  if(derr != -1.33) 
    err += 1;

  derr = masa_eval_v_an<Scalar>(x,y);
  if(derr != -1.33) 
    err += 1;

  derr = masa_eval_w_an<Scalar>(x,y);
  if(derr != -1.33) 
    err += 1;

  derr = masa_eval_p_an<Scalar>(x,y);
  if(derr != -1.33) 
    err += 1;

  derr = masa_eval_rho_an<Scalar>(x,y);
  if(derr != -1.33) 
    err += 1;
  
  // gradient terms

  derr = masa_eval_2d_grad_u<Scalar>(x,y,1);
  if(derr != -1.33) 
    err += 1;

  derr = masa_eval_2d_grad_u<Scalar>(x,y,2);
  if(derr != -1.33) 
    err += 1;

  derr = masa_eval_2d_grad_v<Scalar>(x,y,1);
  if(derr != -1.33) 
    err += 1;

  derr = masa_eval_2d_grad_v<Scalar>(x,y,2);
  if(derr != -1.33) 
    err += 1;

  derr = masa_eval_2d_grad_w<Scalar>(x,y,1);
  if(derr != -1.33) 
    err += 1;

  derr = masa_eval_2d_grad_w<Scalar>(x,y,2);
  if(derr != -1.33) 
    err += 1;

  derr = masa_eval_2d_grad_p<Scalar>(x,y,1);
  if(derr != -1.33) 
    err += 1;

  derr = masa_eval_2d_grad_p<Scalar>(x,y,2);
  if(derr != -1.33) 
    err += 1;

  derr = masa_eval_2d_grad_rho<Scalar>(x,y,1);
  if(derr != -1.33) 
    err += 1;

  derr = masa_eval_2d_grad_rho<Scalar>(x,y,2);
  if(derr != -1.33) 
    err += 1;

  // --------------------------------
  // source term(s) -- 3D
  // --------------------------------

  derr = masa_eval_t_source<Scalar>(x,y,z,t);
  if(derr != -1.33) 
    err += 1;

  derr = masa_eval_u_source<Scalar>(x,y,z);
  if(derr != -1.33) 
    err += 1;

  derr = masa_eval_v_source<Scalar>(x,y,z);
  if(derr != -1.33) 
    err += 1;

  derr = masa_eval_w_source<Scalar>(x,y,z);
  if(derr != -1.33) 
    err += 1;

  derr = masa_eval_e_source<Scalar>(x,y,z);
  if(derr != -1.33) 
    err += 1;

  derr = masa_eval_rho_source<Scalar>(x,y,z);
  if(derr != -1.33) 
    err += 1;

  // gradient terms
  derr = masa_eval_3d_grad_u<Scalar>(x,y,z,1);
  if(derr != -1.33) 
    err += 1;

  derr = masa_eval_3d_grad_u<Scalar>(x,y,z,2);
  if(derr != -1.33) 
    err += 1;

  derr = masa_eval_3d_grad_u<Scalar>(x,y,z,3);
  if(derr != -1.33) 
    err += 1;
  
  derr = masa_eval_3d_grad_v<Scalar>(x,y,z,1);
  if(derr != -1.33) 
    err += 1;

  derr = masa_eval_3d_grad_v<Scalar>(x,y,z,2);
  if(derr != -1.33) 
    err += 1;

  derr = masa_eval_3d_grad_v<Scalar>(x,y,z,3);
  if(derr != -1.33) 
    err += 1;

  derr = masa_eval_3d_grad_w<Scalar>(x,y,z,1);
  if(derr != -1.33) 
    err += 1;

  derr = masa_eval_3d_grad_w<Scalar>(x,y,z,2);
  if(derr != -1.33) 
    err += 1;

  derr = masa_eval_3d_grad_w<Scalar>(x,y,z,3);
  if(derr != -1.33) 
    err += 1;

  derr = masa_eval_3d_grad_p<Scalar>(x,y,z,1);
  if(derr != -1.33) 
    err += 1;

  derr = masa_eval_3d_grad_p<Scalar>(x,y,z,2);
  if(derr != -1.33) 
    err += 1;

  derr = masa_eval_3d_grad_p<Scalar>(x,y,z,3);
  if(derr != -1.33) 
    err += 1;

  derr = masa_eval_3d_grad_rho<Scalar>(x,y,z,1);
  if(derr != -1.33) 
    err += 1;

  derr = masa_eval_3d_grad_rho<Scalar>(x,y,z,2);
  if(derr != -1.33) 
    err += 1;

  derr = masa_eval_3d_grad_rho<Scalar>(x,y,z,3);
  if(derr != -1.33) 
    err += 1;

  // done with gradient
  derr = masa_eval_t_an<Scalar>(x,y,z,t);
  if(derr != -1.33) 
  err += 1;

  derr = masa_eval_u_an<Scalar>(x,y,z);
  if(derr != -1.33) 
    err += 1;

  derr = masa_eval_v_an<Scalar>(x,y,z);
  if(derr != -1.33) 
    err += 1;

  derr = masa_eval_w_an<Scalar>(x,y,z);
  if(derr != -1.33) 
    err += 1;

  derr = masa_eval_p_an<Scalar>(x,y,z);
  if(derr != -1.33) 
    err += 1;

  derr = masa_eval_rho_an<Scalar>(x,y,z);
  if(derr != -1.33) 
    err += 1;

  if(err != 0)
    {
      cout << "MASA ERROR: Default output for virtual function failing\n";
      cout << err << " functions failing.\n";
      exit(1);
    }

  return 0; // steady as she goes

}
