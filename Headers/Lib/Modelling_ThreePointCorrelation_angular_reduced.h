/********************************************************************
 *  Copyright (C) 2017 by Federico Marulli                          *
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
 *  @file
 *  Headers/Lib/Modelling_ThreePointCorrelation_angular_reduced.h
 *
 *  @brief The class Modelling_ThreePointCorrelation_angular_reduced
 *
 *  This file defines the interface of the class
 *  Modelling_ThreePointCorrelation_angular_reduced, that contains
 *  all the methods to model the reduced three-point correlation
 *  function in angular coordinates
 *
 *  @author Federico Marulli
 *
 *  @author federico.marulli3@unbo.it
 */

#ifndef __MODELLINGTHREEPOINTANGRED__
#define __MODELLINGTHREEPOINTANGRED__


#include "Modelling_ThreePointCorrelation_angular_connected.h"
#include "ModelFunction_ThreePointCorrelation_angular_reduced.h"


// ===================================================================================================


namespace cosmobl {
  
  namespace modelling {
    
    namespace threept {
      
      /**
       *  @class Modelling_ThreePointCorrelation_angular_reduced
       *  Modelling_ThreePointCorrelation_angular_reduced.h
       *  "Headers/Lib/Modelling_ThreePointCorrelation_angular_reduced.h"
       *
       *  @brief The class
       *  Modelling_ThreePointCorrelation_angular_reduced
       *
       *  This file defines the interface of the class
       *  Modelling_ThreePointCorrelation_angular_reduced, that
       *  contains all the methods to model the reduced three-point
       *  correlation function in angular coordinates
       *
       */
      class Modelling_ThreePointCorrelation_angular_reduced : public Modelling_ThreePointCorrelation_angular_connected {

      public:

	/**
	 *  @name Constructors/destructors
	 */
	///@{

	/**
	 *  @brief default constuctor
	 *  @return object of class
	 *  Modelling_ThreePointCorrelation_angular_reduced
	 */
	Modelling_ThreePointCorrelation_angular_reduced () = default;

	/**
	 *  @brief constructor
	 *  
	 *  @param threep the three-point correlation function to model
	 *
	 *  @return object of type
	 *  Modelling_ThreePointCorrelation_angular_reduced
	 */
	Modelling_ThreePointCorrelation_angular_reduced (const shared_ptr<cosmobl::measure::threept::ThreePointCorrelation> threep)
	  : Modelling_ThreePointCorrelation_angular_connected(threep) {}

	/**
	 *  @brief constructor
	 *  
	 *  @param threep_dataset the dataset containing the
	 *  three-point correlation function to model
	 *
	 *  @return object of type
	 *  Modelling_ThreePointCorrelation_angular_reduced
	 */
	Modelling_ThreePointCorrelation_angular_reduced (const shared_ptr<data::Data> threep_dataset)
	  : Modelling_ThreePointCorrelation_angular_connected() { set_data(threep_dataset); }
	
	/**
	 *  @brief default destructor
	 *  @return none
	 */
	~Modelling_ThreePointCorrelation_angular_reduced () = default;
	
	///@}
      
      };
    }
  }
}

#endif
