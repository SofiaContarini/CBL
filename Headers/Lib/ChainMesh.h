/********************************************************************
 *  Copyright (C) 2010 by Federico Marulli and Alfonso Veropalumbo  *
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
 *******************************************************************/

/**
 *  @file Headers/Lib/ChainMesh.h
 *
 *  @brief Implementation of the chain-mesh data structure
 *
 *  This file defines the interface of the class ChainMesh, used for
 *  the chain-mesh method
 *
 *  @authors Federico Marulli, Alfonso Veropalumbo
 *
 *  @authors federico.marulli3@unbo.it, alfonso.veropalumbo@unibo.it
 */

#include "Cosmology.h"


#ifndef __CHAINMESH__
#define __CHAINMESH__


namespace cosmobl {

  /**
   *  @brief The namespace of the functions and classes used for the
   *  <B> chain-mesh method </B>
   *  
   *  The \e chainmesh namespace contains all the main functions and
   *  classes of the chain-mesh method used for counting pairs and
   *  triplets
   */
  namespace chainmesh {
  
    /**
     *  @class ChainMesh ChainMesh.h "Headers/Lib/ChainMesh.h"
     *
     *  @brief The class ChainMesh
     *
     *  This class is used to handle objects of type <EM> ChainMesh
     *  </EM>
     */
    class ChainMesh {

    protected:
    
      /// the number of dimension
      int m_nDim;

      /// indexes in the i-th cell
      vector<long> m_cell_to_index;

      /// the size of the cell in unit of the interested quantity
      double m_cell_size;

      /// list of internal use
      vector<long> m_List;
    
      /// array containing the last particle of the chain-mesh in each cell
      vector<long> m_Label;

      /// index list of internal use
      vector<vector<long> > m_List_index;

      /// Min,Max limits of variable(s) used for the chain-mesh
      vector<vector<double> > m_Lim;

      /// Max-Min of variable(s) used for the chain-mesh
      vector<double> m_Delta;

      /// number of cell(s) for variable(s) 
      vector<long> m_nCell;

      /// the list of cell around a generic center
      vector<long> m_search_region;

      /// the total number of cells
      long m_nCell_tot;

      /// the number of non-empty cells
      long m_nCell_NonEmpty;

      /// the total number of non-empty cells
      vector<long> m_NonEmpty_Cells;

    public:
    
      /**
       *  @brief default constructor
       *  @return object of class ChainMesh
       */
      ChainMesh () {}

      /**
       *  @brief constructor 
       *  @param cell_size double storing the cell size
       *  @param nDim the number of dimensions
       *  @return object of class ChainMesh
       */
      ChainMesh (const double cell_size, const long nDim);

      /**
       *  @brief default destructor
       *  @return none
       */
      ~ChainMesh () {}

      /**
       *  @brief function that set parameters for the chain-mesh 
       *  @param cell_size double storing the cell size
       *  @param nDim the number of dimensions
       *  @return none
       */
      void set_par (const double cell_size, const long nDim);

      /**
       *  @brief get the private member ChainMesh::m_nCell_tot
       *  @return total number of cells 
       */
      long nCell() const { return m_nCell_tot; }

      /**
       *  @brief get the private member ChainMesh::m_nCell_NonEmpty
       *  @return number of non-empty cells 
       */
      long nCell_NonEmpty() const { return m_nCell_NonEmpty; }

      /**
       *  @brief get the private member ChainMesh::m_NonEmpty_Cells
       *  @return indexes of non-empty cells 
       */
      vector<long> NonEmpty_Cells() const { return m_NonEmpty_Cells; }
    
      /**
       * @brief get the index of the cell given the object coordinates
       * @param center the object coordinates
       * @return the cell index
       */
      long pos_to_index (const vector<double> center) const;

      /**
       * @brief get the unique index of the cell given the n indices
       * @param indx vector of the indices of the nD space cell
       * @return the cell unique index
       */ 
      long inds_to_index (const vector<long> indx) const;

      /**
       * @brief get the n indices given the unique index
       * @param index the unique index 
       * @param nn the number of cells along the box axis
       * @param indx vector of the indices of the nD space cell
       * @return none
       */  
      void index_to_inds (const long index, const vector<long> nn, vector<long> &indx) const;

      /**
       * @brief create the chain mesh
       * @param data the vector containing the coordinate of the object 
       * @param rMax the maximum radius, to set the interal variable m_search_region
       * @param nMIN minimum number of cells
       * @param nMAX maximum number of cells
       * @return none
       */
      void create_chain_mesh (const vector<vector<double> > data, const double rMax, const long nMIN=0, const long nMAX=300);
  
      /**
       * @brief create the chain mesh
       * @param data the vector containing the coordinate of the object
       * @return none
       */
      void create_chain_mesh_m2 (const vector<vector<double> > data);

      /**
       * @brief set the internal variable m_search_region, the list
       * of cell around a generic center
       * @param r_max the maximum radius
       * @param r_min the minimum radius
       * @return none
       */
      void get_searching_region (const double r_max, const double r_min = -1);

      /**
       * @brief get the indeces of the objects close to a cell
       * @param cell_index the cell index
       * @param ii the minimum index given in output
       * @return vector containing the index of the objects inside the cell
       */
      vector<long> close_objects_cell (const int cell_index, long ii=-1) const; 

      /**
       * @brief get the indeces of the objects close to an object
       * @param center coordinates of an object
       * @param ii the minimum index given in output
       * @return vector containing the index of the objects inside the cell
       */
      vector<long> close_objects (vector<double> center, long ii=-1) const; 

      /**
       * @brief get the index of the object inside a cell
       * @param cell_index the cell index
       * @return vector containing the index of the objects inside the cell
       */
      vector<long> get_list (const long cell_index) const;

    };

    /**
     *  @class ChainMesh1D ChainMesh.h "Headers/Lib/ChainMesh.h"
     *
     *  @brief The class ChainMesh1D
     *
     *  This class is used to handle objects of type <EM> ChainMesh1D
     *  </EM>
     */
    class ChainMesh1D : public ChainMesh
    {
    public:
      /**
       *  @brief default constructor
       *  @return an object of class ChainMesh1D
       */
      ChainMesh1D () {}

      /**
       *  @brief default destructor
       *  @return none
       */
      ~ChainMesh1D () {}

      /**
       *  @brief function that set parameters for the chain-mesh 
       *  @param cell_size double storing the cell size
       *  @param xx the vector with the variable used for the chain-mesh
       *  @param rMAX the maximum separation
       *  @param nMIN the allowed minimum number of chain-mesh cells in each dimension 
       *  @param nMAX the allowed maximum number of chain-mesh cells in each dimension 
       *  @return none
       */
      void set_par (const double cell_size, const vector<double> xx, const double rMAX, const long nMIN=0, const long nMAX=300);

      /**
       *  @brief constructor 
       *  @param cell_size double storing the cell size
       *  @param xx the vector with the variable used for the chain-mesh
       *  @param rMAX the maximum separation
       *  @param nMIN the allowed minimum number of chain-mesh cells in each dimension 
       *  @param nMAX the allowed maximum number of chain-mesh cells in each dimension 
       *  @return object of the class ChainMesh1D
       */
      ChainMesh1D (const double cell_size, const vector<double> xx, const double rMAX, const long nMIN=0, const long nMAX=300);
    };

    /**
     *  @class ChainMesh2D ChainMesh.h "Headers/Lib/ChainMesh.h"
     *
     *  @brief The class ChainMesh2D
     *
     *  This class is used to handle objects of type <EM> ChainMesh2D
     *  </EM>
     */
    class ChainMesh2D : public ChainMesh
    {
    public:
      /**
       *  @brief default constructor
       *  @return object of class ChainMesh1D
       */
      ChainMesh2D () {}

      /**
       *  @brief default destructor
       *  @return none
       */
      ~ChainMesh2D () {}

      /**
       *  @brief function that set parameters for the chain-mesh 
       *  @param cell_size double storing the cell size
       *  @param xx the vector with the first variable used for the chain-mesh
       *  @param yy the vector with the second variable used for the chain-mesh
       *  @param rMAX the maximum separation
       *  @param nMIN the allowed minimum number of chain-mesh cells in each dimension 
       *  @param nMAX the allowed maximum number of chain-mesh cells in each dimension 
       *  @return none
       */
      void set_par (const double cell_size, const vector<double> xx, const vector<double> yy, const double rMAX, const long nMIN=0, const long nMAX=300);

      /**
       *  @brief constructor 
       *  @param cell_size double storing the cell size
       *  @param xx the vector with the first variable used for the chain-mesh
       *  @param yy the vector with the second variable used for the chain-mesh
       *  @param rMAX the maximum separation
       *  @param nMIN the allowed minimum number of chain-mesh cells in each dimension 
       *  @param nMAX the allowed maximum number of chain-mesh cells in each dimension 
       *  @return object of the class ChainMesh2D
       */
      ChainMesh2D (const double cell_size, const vector<double> xx, const vector<double> yy, const double rMAX, const long nMIN=0, const long nMAX=300);
    };

    /**
     *  @class ChainMesh3D ChainMesh.h "Headers/Lib/ChainMesh.h"
     *
     *  @brief The class ChainMesh3D
     *
     *  This class is used to handle objects of type <EM> ChainMesh3D
     *  </EM>
     */
    class ChainMesh3D : public ChainMesh
    {
    public:
    
      /**
       *  @brief default constructor
       *  @return an object of class ChainMesh3D
       */
      ChainMesh3D () {}

      /**
       *  @brief default destructor
       *  @return none
       */
      ~ChainMesh3D () {}

      /**
       *  @brief function that set parameters for the chain-mesh 
       *  @param cell_size double storing the cell size
       *  @param xx the vector with the first variable used for the chain-mesh
       *  @param yy the vector with the second variable used for the chain-mesh
       *  @param zz the vector with the third variable used for the chain-mesh
       *  @param rMAX the maximum separation
       *  @param nMIN the allowed minimum number of chain-mesh cells in each dimension 
       *  @param nMAX the allowed maximum number of chain-mesh cells in each dimension 
       *  @return none
       */
      void set_par (const double cell_size, const vector<double> xx, const vector<double> yy, const vector<double> zz, const double rMAX, const long nMIN=0, const long nMAX=300);

      /**
       *  @brief constructor 
       *  @param cell_size double storing the cell size
       *  @param xx the vector with the first variable used for the chain-mesh
       *  @param yy the vector with the second variable used for the chain-mesh
       *  @param zz the vector with the third variable used for the chain-mesh
       *  @param rMAX the maximum separation
       *  @param nMIN the allowed minimum number of chain-mesh cells in each dimension 
       *  @param nMAX the allowed maximum number of chain-mesh cells in each dimension 
       *  @return object of the class ChainMesh3D
       */
      ChainMesh3D (const double cell_size, const vector<double> xx, const vector<double> yy, const vector<double> zz, const double rMAX, const long nMIN=0, const long nMAX=300);
    };

  }
}

#endif
