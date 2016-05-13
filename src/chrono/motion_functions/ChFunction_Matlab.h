// =============================================================================
// PROJECT CHRONO - http://projectchrono.org
//
// Copyright (c) 2014 projectchrono.org
// All right reserved.
//
// Use of this source code is governed by a BSD-style license that can be found
// in the LICENSE file at the top level of the distribution and at
// http://projectchrono.org/license-chrono.txt.
//
// =============================================================================
// Authors: Alessandro Tasora, Radu Serban
// =============================================================================

#ifndef CHFUNCT_MATLAB_H
#define CHFUNCT_MATLAB_H

#include "chrono/motion_functions/ChFunction_Base.h"

namespace chrono {

#define CHF_MATLAB_STRING_LEN 200

/// Matlab function: y = matlab evaluation of function y=f(x)

class ChApi ChFunction_Matlab : public ChFunction {
    CH_RTTI(ChFunction_Matlab, ChFunction);

  private:
    char mat_command[CHF_MATLAB_STRING_LEN];  ///< matlab command

  public:
    ChFunction_Matlab();
    ChFunction_Matlab(const ChFunction_Matlab& other);
    ~ChFunction_Matlab() {}

    /// "Virtual" copy constructor (covariant return type).
    virtual ChFunction_Matlab* Clone() const override { return new ChFunction_Matlab(*this); }

    virtual FunctionType Get_Type() const override { return FUNCT_MATLAB; }

    virtual double Get_y(double x) const override;
    virtual double Get_y_dx(double x) const override;
    virtual double Get_y_dxdx(double x) const override;

    void Set_Command(const char* m_command) { strcpy(mat_command, m_command); }
    const char* Get_Command() const { return mat_command; }


    /// Method to allow serialization of transient data to archives.
    virtual void ArchiveOUT(ChArchiveOut& marchive) override {
        // version number
        marchive.VersionWrite(1);
        // serialize parent class
        ChFunction::ArchiveOUT(marchive);
        // serialize all member data:
        marchive << CHNVP(mat_command);
    }

    /// Method to allow deserialization of transient data from archives.
    virtual void ArchiveIN(ChArchiveIn& marchive) override {
        // version number
        int version = marchive.VersionRead();
        // deserialize parent class
        ChFunction::ArchiveIN(marchive);
        // stream in all member data:
        marchive >> CHNVP(mat_command);
    }
};

}  // end namespace chrono

#endif
