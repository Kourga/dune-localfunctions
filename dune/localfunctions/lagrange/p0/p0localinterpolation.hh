// -*- tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 2 -*-
// vi: set et ts=4 sw=2 sts=2:
#ifndef DUNE_P0LOCALINTERPOLATION_HH
#define DUNE_P0LOCALINTERPOLATION_HH

#include <dune/grid/common/genericreferenceelements.hh>


namespace Dune
{

  template<class LB>
  class P0LocalInterpolation
  {
  public:
    P0LocalInterpolation (GeometryType::BasicType basicType, int d) : gt(basicType,d)
    {}

    //! determine coefficients interpolating a given function
    template<typename F, typename C>
    void interpolate (const F& f, std::vector<C>& out) const
    {
      typedef typename LB::Traits::DomainType DomainType;
      typedef typename LB::Traits::RangeType RangeType;
      typedef typename LB::Traits::DomainFieldType DF;
      const int dim=LB::Traits::dimDomain;

      DomainType x = Dune::GenericReferenceElements<DF,dim>::general(gt).position(0,0);
      RangeType y;

      out.resize(1);
      f.evaluate(x,y); out[0] = y;
    }

  private:
    GeometryType gt;
  };

}

#endif