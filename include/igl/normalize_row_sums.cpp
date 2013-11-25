// This file is part of libigl, a simple c++ geometry processing library.
// 
// Copyright (C) 2013 Alec Jacobson <alecjacobson@gmail.com>
// 
// This Source Code Form is subject to the terms of the Mozilla Public License 
// v. 2.0. If a copy of the MPL was not distributed with this file, You can 
// obtain one at http://mozilla.org/MPL/2.0/.
#include "normalize_row_sums.h"

template <typename DerivedA, typename DerivedB>
IGL_INLINE void igl::normalize_row_sums(
  const Eigen::MatrixBase<DerivedA>& A,
  Eigen::MatrixBase<DerivedB> & B)
{
  // Resize output
  B.derived().resize(A.rows(),A.cols());

  // loop over rows
  for(int i = 0; i < A.rows();i++)
  {
    typename DerivedB::Scalar sum = A.row(i).sum();
    assert(sum != 0);
    B.row(i) = A.row(i).array()/sum;
  }
}
#ifndef IGL_HEADER_ONLY
// Explicit template specialization
template void igl::normalize_row_sums<Eigen::Matrix<double, -1, -1, 0, -1, -1>, Eigen::Matrix<double, -1, -1, 0, -1, -1> >(Eigen::MatrixBase<Eigen::Matrix<double, -1, -1, 0, -1, -1> > const&, Eigen::MatrixBase<Eigen::Matrix<double, -1, -1, 0, -1, -1> >&);
template void igl::normalize_row_sums<Eigen::Matrix<double, -1, 3, 0, -1, 3>, Eigen::Matrix<double, -1, 3, 0, -1, 3> >(Eigen::MatrixBase<Eigen::Matrix<double, -1, 3, 0, -1, 3> > const&, Eigen::MatrixBase<Eigen::Matrix<double, -1, 3, 0, -1, 3> >&);
#endif
