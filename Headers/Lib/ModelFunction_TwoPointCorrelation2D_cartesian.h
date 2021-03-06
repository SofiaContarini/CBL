/********************************************************************
 *  Copyright (C) 2016 by Federico Marulli and Alfonso Veropalumbo  *
 *  federico.marulli3@unibo.it                                      *
 *                                                                  *
 *  This program is free software; you can redistribute it and/or   *
 *  modify it under the terms of the GNU General Public License as  *
 *  published by the Free Software Foundation; either version 2 of  *
 *  the License, or (at your option) any later version.             *
 *                                                                  *
 *  This program is distributed in the hope that it will be useful, *
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of  *
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the   *
 *  GNU General Public License for more details.                    *
 *                                                                  *
 *  You should have received a copy of the GNU General Public       *
 *  License along with this program; if not, write to the Free      *
 *  Software Foundation, Inc.,                                      *
 *  59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.       *
 ********************************************************************/

/**
 *  @file Headers/Lib/ModelFunction_TwoPointCorrelation2D_cartesian.h
 *
 *  @brief Functions to model the 2D two-point correlation function in
 *  Cartesian coordinates
 *
 *  This file contains all the prototypes of the functions used to
 *  model the 2D two-point correlation function in Cartesian
 *  coordinates
 *  
 *  @author Federico Marulli, Alfonso Veropalumbo
 *
 *  @author federico.marulli3@unbo.it, alfonso.veropalumbo@unibo.it
 */

#ifndef __MODFUNCTWOP2DCART__
#define __MODFUNCTWOP2DCART__

#include "ModelFunction_TwoPointCorrelation2D.h"


// ============================================================================


namespace cosmobl {

  namespace modelling {

    namespace twopt {
      
      /**
       *  @brief model for the 2D two-point correlation function, in
       *  Cartesian coordinates
       *
       *  the function computes \f$\xi(r_p,\pi)\f$ with the dispersion
       *  model (see e.g. http://arxiv.org/abs/1203.1002)
       *
       *  the model has 5 parameters: 
       *    - the two Alcock-Paczynski parameters
       *      (\f$\alpha_\perp=\frac{D_{\rm A,1}(z)}{D_{\rm A,2}(z)}\f$
       *      and \f$\alpha_\parallel=\frac{H_2(z)}{H_1(z)}\f$)
       *    - \f$f(z)\sigma_8(z)\f$
       *    - \f$b(z)\sigma_8(z)\f$ 
       *    - \f$\sigma_{12}(z)\f$
       *
       *  @param rp the scale perpendicular to the line of sight at
       *  which the model is computed
       *
       *  @param pi the scale parallel to the line of sight at which the
       *  model is computed
       *
       *  @param inputs pointer to the structure that contains all the
       *  data required to implement the dispersion model
       *
       *  @param parameter 5D vector containing the input parameters
       *
       *  @return the 2D two-point correlation function in redshift
       *  space
       */
      vector<vector<double>> xi2D_dispersionModel (const vector<double> rp, const vector<double> pi, const shared_ptr<void> inputs, vector<double> &parameter);
      
    }
  }
}

#endif
