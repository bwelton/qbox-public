////////////////////////////////////////////////////////////////////////////////
//
// PBEFunctional.h
//
////////////////////////////////////////////////////////////////////////////////
// $Id: PBEFunctional.h,v 1.1 2003-01-25 01:23:31 fgygi Exp $

#ifndef PBEFUNCTIONAL_H
#define PBEFUNCTIONAL_H

#include "XCFunctional.h"
#include <vector>
using namespace std;

class PBEFunctional : public XCFunctional
{
  PBEFunctional();
  
  vector<double> _exc, _exc_up, _exc_dn;
  vector<double> _vxc1, _vxc1_up, _vxc1_dn, 
                 _vxc2, _vxc2_upup, _vxc2_updn, _vxc2_dnup, _vxc2_dndn;
  vector<double> _grad_rho[3], _grad_rho_up[3], _grad_rho_dn[3];
  
  void gcor2(double a, double a1, 
    double b1, double b2, double b3,
    double b4, double rtrs, double *gg, double *ggrs);
    
  void excpbe(double rho, double grad, 
    double *exc, double *vxc1, double *vxc2);
    
  void excpbe_sp(double rho_up, double rho_dn, 
    double grad_up, double grad_dn, double grad,  
    double *exc_up, double *exc_dn,
    double *vxc1_up, double *vxc1_dn, double *vxc2_upup, double *vxc2_dndn,
    double *vxc2_updn, double *vxc2_dnup);

  public:
  
  PBEFunctional(vector<vector<double> > &rhoe);
  
  bool isGGA() { return true; };
  string name() { return "PBE"; };
  void setxc(void); 
};
#endif
