////////////////////////////////////////////////////////////////////////////////
//
//  DistanceConstraint.h
//
////////////////////////////////////////////////////////////////////////////////
// $Id: DistanceConstraint.h,v 1.2 2005-09-16 23:08:11 fgygi Exp $

#ifndef DISTANCECONSTRAINT_H
#define DISTANCECONSTRAINT_H

#include "Constraint.h"
#include <cassert>
#include <cmath> // fabs
class AtomSet;

class DistanceConstraint : public Constraint
{
  string name1_, name2_;
  int    ia1_, ia2_, is1_, is2_;
  double m1_, m2_, m1_inv_, m2_inv_;
  double distance_, velocity_, force_, weight_, tol_;
  
  public:
  
  DistanceConstraint(string name, string name1, string name2,
                     double distance, double velocity, double tolerance):
  name1_(name1), name2_(name2), distance_(distance), 
  velocity_(velocity), tol_(tolerance), m1_(0.0), m2_(0.0)
  {
    name_ = name;
    names_.resize(2);
    names_[0] = name1_;
    names_[1] = name2_;
    force_ = 0.0;
    weight_ = 1.0;
  }
  
  string type(void) const { return "distance"; }
  double value(void) const { return distance_; }
  double velocity(void) const { return velocity_; }
  double force(void) const { return force_; }
  double weight(void) const { return weight_; }
  double tolerance(void) const { return tol_; }
  void set_value(double value)
  {
    distance_ = fabs(value);
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