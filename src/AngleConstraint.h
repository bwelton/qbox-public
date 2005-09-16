////////////////////////////////////////////////////////////////////////////////
//
//  AngleConstraint.h
//
////////////////////////////////////////////////////////////////////////////////
// $Id: AngleConstraint.h,v 1.2 2005-09-16 23:08:11 fgygi Exp $

#ifndef ANGLECONSTRAINT_H
#define ANGLECONSTRAINT_H

#include "Constraint.h"
#include "D3vector.h"
#include <cassert>
class AtomSet;

class AngleConstraint : public Constraint
{
  string name1_, name2_, name3_;
  int    ia1_, ia2_, ia3_, is1_, is2_, is3_;
  double m1_, m2_, m3_, m1_inv_, m2_inv_, m3_inv_;
  double angle_, velocity_, force_, weight_, tol_;
  double sigma(D3vector a, D3vector b, D3vector c) const;
  void grad_sigma(const D3vector &r1, const D3vector &r2, const D3vector &r3,
                  D3vector &g1, D3vector &g2,D3vector &g3) const;
  double bond_angle(D3vector a, D3vector b, D3vector c) const;
  
  public:
  
  AngleConstraint(string name, string name1, string name2, string name3,
                     double angle, double velocity, double tolerance):
  name1_(name1), name2_(name2), name3_(name3), 
  velocity_(velocity),
  tol_(tolerance), m1_(0.0), m2_(0.0), m3_(0.0)
  { 
    set_value(angle);
    name_ = name;
    names_.resize(3);
    names_[0] = name1_;
    names_[1] = name2_;
    names_[2] = name3_;
    force_ = 0.0;
    weight_ = 1.0;
  }
  
  string type(void) const { return "angle"; }
  double value(void) const { return angle_; }
  double velocity(void) const { return velocity_; }
  double force(void) const { return force_; }
  double weight(void) const { return weight_; }
  double tolerance(void) const { return tol_; }
  void set_value(double value)
  {
    angle_ = value;
    if ( angle_ <   0.0 ) angle_ =   0.0;
    if ( angle_ > 180.0 ) angle_ = 180.0;
  }
  void set_velocity(double velocity)
  {
    velocity_ = velocity;
  }
  
  void setup(const AtomSet& atoms);
  void update(double dt);
  bool enforce_r(const vector<vector<double> > &r0,
                 vector<vector<double> > &rp) const;
  bool enforce_v(const vector<vector<double> > &r0,
                 vector<vector<double> > &v0) const;
  void compute_force(const vector<vector<double> > &r0,
                     const vector<vector<double> > &f);
  ostream& print( ostream& os );
  
};
#endif
