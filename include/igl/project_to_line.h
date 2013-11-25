// This file is part of libigl, a simple c++ geometry processing library.
// 
// Copyright (C) 2013 Alec Jacobson <alecjacobson@gmail.com>
// 
// This Source Code Form is subject to the terms of the Mozilla Public License 
// v. 2.0. If a copy of the MPL was not distributed with this file, You can 
// obtain one at http://mozilla.org/MPL/2.0/.
#ifndef IGL_PROJECT_TO_LINE
#define IGL_PROJECT_TO_LINE
#include "igl_inline.h"

namespace igl
{
  // PROJECT_TO_LINES  project points onto vectors, that is find the paramter
  // t for a point p such that proj_p = (y-x).*t, additionally compute the
  // squared distance from p to the line of the vector, such that 
  // |p - proj_p|² = sqr_d
  //
  // [T,sqrD] = project_to_lines(P,S,D)
  //
  // Templates:
  //   MatP matrix template for P, implementing .cols(), .rows()
  //   MatL matrix template for S and D, implementing .size(), .array(), .sum()
  //   Matt matrix template for t 
  //   MatsqrD matrix template for sqrD
  // Inputs:
  //   P  #P by dim list of points to be projected
  //   S  size dim start position of line vector
  //   D  size dim destination position of line vector
  // Outputs:
  //   T  #P by 1 list of parameters
  //   sqrD  #P by 1 list of squared distances
  //
  //
  template <
    typename MatP, 
    typename MatL, 
    typename Matt, 
    typename MatsqrD>
  IGL_INLINE void project_to_line(
    const MatP & P,
    const MatL & S,
    const MatL & D,
    Matt & t,
    MatsqrD & sqrD);
  
  // Same as above but for a single query point
  template <typename Scalar>
  IGL_INLINE void project_to_line(
    const Scalar px,
    const Scalar py,
    const Scalar pz,
    const Scalar sx,
    const Scalar sy,
    const Scalar sz,
    const Scalar dx,
    const Scalar dy,
    const Scalar dz,
    Scalar & projpx,
    Scalar & projpy,
    Scalar & projpz,
    Scalar & t,
    Scalar & sqrd);
  
  // Same as above but for a single query point
  template <typename Scalar>
  IGL_INLINE void project_to_line(
    const Scalar px,
    const Scalar py,
    const Scalar pz,
    const Scalar sx,
    const Scalar sy,
    const Scalar sz,
    const Scalar dx,
    const Scalar dy,
    const Scalar dz,
    Scalar & t,
    Scalar & sqrd);

}

#ifdef IGL_HEADER_ONLY
#  include "project_to_line.cpp"
#endif

#endif
