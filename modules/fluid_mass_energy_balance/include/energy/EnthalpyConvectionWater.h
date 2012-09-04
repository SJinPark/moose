/****************************************************************/
/*             DO NOT MODIFY OR REMOVE THIS HEADER              */
/*          FALCON - Fracturing And Liquid CONvection           */
/*                                                              */
/*       (c) pending 2012 Battelle Energy Alliance, LLC         */
/*                   ALL RIGHTS RESERVED                        */
/*                                                              */
/*          Prepared by Battelle Energy Alliance, LLC           */
/*            Under Contract No. DE-AC07-05ID14517              */
/*            With the U. S. Department of Energy               */
/*                                                              */
/*            See COPYRIGHT for full restrictions               */
/****************************************************************/

#ifndef ENTHALPYCONVECTIONWATER
#define ENTHALPYCONVECTIONWATER

#include "Kernel.h"
#include "Material.h"

//Forward Declarations
class EnthalpyConvectionWater;

template<>
InputParameters validParams<EnthalpyConvectionWater>();

class EnthalpyConvectionWater : public Kernel
{
public:

  EnthalpyConvectionWater(const std::string & name, InputParameters parameters);

protected:
  virtual Real computeQpResidual();
  virtual Real computeQpJacobian();
  virtual Real computeQpOffDiagJacobian(unsigned int jvar);
  
    MaterialProperty<Real> & _Dtau_waterDH;
    MaterialProperty<Real> & _Dtau_waterDP;
    MaterialProperty<RealGradient> & _darcy_mass_flux_water;
    MaterialProperty<Real> & _tau_water;
  //std::string _prop_name_enthalpy_water;
  //std::string _prop_name_denthalpy_water_dH_P;
  //std::string _prop_name_denthalpy_water_dP_H;
    MaterialProperty<Real> & _enthalpy_water;           //(added by Kat)
    MaterialProperty<Real> & _denthalpy_waterdH_P;      //(added by Kat)
    MaterialProperty<Real> & _denthalpy_waterdP_H;      //(added by Kat)
    //VariableValue  & _enthalpy_water;                 //(removed by kat)
    //VariableValue & _denthalpy_waterdH_P;             //(removed by Kat)
    //VariableValue & _denthalpy_waterdP_H;             //(removed by Kat)
    unsigned int  _p_var;
    VariableGradient & _grad_p;
  

};
#endif //ENTHALPYCONVECTIONWATER
