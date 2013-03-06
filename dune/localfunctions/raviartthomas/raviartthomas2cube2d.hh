// -*- tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 2 -*-
// vi: set et ts=4 sw=2 sts=2:
#ifndef DUNE_LOCALFUNCTIONS_RAVIARTTHOMAS2_CUBE2D_LOCALFINITEELEMENT_HH
#define DUNE_LOCALFUNCTIONS_RAVIARTTHOMAS2_CUBE2D_LOCALFINITEELEMENT_HH

#include <dune/geometry/type.hh>

#include "../common/localfiniteelementtraits.hh"
#include "raviartthomas2cube2d/raviartthomas2cube2dlocalbasis.hh"
#include "raviartthomas2cube2d/raviartthomas2cube2dlocalcoefficients.hh"
#include "raviartthomas2cube2d/raviartthomas2cube2dlocalinterpolation.hh"

namespace Dune
{
  /**
   * \brief Second order Raviart-Thomas shape functions on cubes.
   *
   * \tparam D Type to represent the field in the domain.
   * \tparam R Type to represent the field in the range.
   */
  template<class D, class R>
  class RT2Cube2DLocalFiniteElement
  {

  public:
    typedef LocalFiniteElementTraits<
        RT2Cube2DLocalBasis<D,R>,
        RT2Cube2DLocalCoefficients,
        RT2Cube2DLocalInterpolation<RT2Cube2DLocalBasis<D,R> > > Traits;

    //! \brief Standard constructor
    RT2Cube2DLocalFiniteElement ()
    {
      gt.makeQuadrilateral();
    }

    /**
     * \brief Make set number s, where 0 <= s < 16
     *
     * \param s Edge orientation indicator
     */
    RT2Cube2DLocalFiniteElement (int s) : basis(s), interpolation(s)
    {
      gt.makeQuadrilateral();
    }

    const typename Traits::LocalBasisType& localBasis () const
    {
      return basis;
    }

    const typename Traits::LocalCoefficientsType& localCoefficients () const
    {
      return coefficients;
    }

    const typename Traits::LocalInterpolationType& localInterpolation () const
    {
      return interpolation;
    }

    GeometryType type () const
    {
      return gt;
    }

  private:
    RT2Cube2DLocalBasis<D,R> basis;
    RT2Cube2DLocalCoefficients coefficients;
    RT2Cube2DLocalInterpolation<RT2Cube2DLocalBasis<D,R> > interpolation;
    GeometryType gt;
  };
}
#endif // DUNE_LOCALFUNCTIONS_RAVIARTTHOMAS2_CUBE2D_LOCALFINITEELEMENT_HH