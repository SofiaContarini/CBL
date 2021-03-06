/********************************************************************
 *  Copyright (C) 2014 by Federico Marulli and Alfonso Veropalumbo  *
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
 *  @file Headers/Lib/Data1D.h
 *
 *  @brief The class Data1D
 *
 *  This file defines the interface of the class Data1D
 *
 *  @authors Federico Marulli, Alfonso Veropalumbo
 *
 *  @authors federico.marulli3@unbo.it, alfonso.veropalumbo@unibo.it
 */

#ifndef __DATA1D__
#define __DATA1D__

#include "Data.h"

namespace cosmobl {

  namespace data {
    
    /**
     *  @class Data1D Data1D.h
     *  "Headers/Lib/Data1D.h"
     *
     *  @brief The class Data1D
     *
     *  This is the base class used to manage 1D data
     */
    class Data1D : public Data
    {
      
    protected:

      /**
       *  @name Data input
       */
      ///@{

      /// ordered x axis points
      vector<double> m_x;

      ///@}
     
      /// number of points along x
      int m_xsize;

    public:

      /**
       *  @name Constructors/destructors
       */
      ///@{

      /**
       *  @brief default constructor
       *  @return object of class Data1D
       */
      Data1D ()
	: Data(DataType::_1D_data_) {}

      /**
       *  @brief constructor of Data1D
       *  @param input_file the input data file
       *  @param skip_nlines the header lines to be skipped
       *  @return object of class Data1D
       */
      Data1D (const string input_file, const int skip_nlines=0)
	: Data(cosmobl::data::DataType::_1D_data_)
	{ read(input_file, skip_nlines); }

      
      /**
       *  @brief constructor of Data1D
       *  @param x vector containing x points 
       *  @param data vector containing data 
       *  @return object of class Data1D
       */
      Data1D (const vector<double> x, const vector<double> data)
	: Data(cosmobl::data::DataType::_1D_data_, data)
	{ set_xx(x); }
      
      /**
       *  @brief Constructor of Data1D
       *  @param x vector containing x points 
       *  @param data vector containing data 
       *  @param error vector containing error on data 
       *  @return object of class Data1D
       */
      Data1D (const vector<double> x, const vector<double> data, const vector<double> error) 
	: Data(cosmobl::data::DataType::_1D_data_, data, error)
	{ set_xx(x); }
      
      /**
       *  @brief Constructor of Data1D
       *  @param x vector containing x points 
       *  @param data vector containing data 
       *  @param covariance vector containing data covariance matrix 
       *  @return object of class Data1D
       */
      Data1D (const vector<double> x, const vector<double> data, const vector<vector<double>> covariance)
	: Data(cosmobl::data::DataType::_1D_data_, data, covariance)
	{ set_xx(x); }
      
      /**
       *  @brief default destructor
       *  @return none
       */
      virtual ~Data1D () = default;

      /**
       *  @brief static factory used to construct objects of class
       *  Data1D
       *  @return a shared pointer to an object of class Data
       */
      shared_ptr<Data> as_factory ();

      ///@}

      /**
       *  @name Member functions used to get the private members
       */
      ///@{

      int xsize () const
      { return m_xsize; }

      /**
       *  @brief get the value of x at the i-th bin
       *  @param i index
       *  @return value of x at the i-th bin
       */
      double xx (const int i) const override { return m_x[i]; }  

      /**
       *  @brief get the x vector
       *  @return the x vector
       */
      vector<double> xx () const override { return m_x; }  
      
      /**
       *  @brief get x values
       *  @param [out] x the x values
       *  @return none
       */
      void xx (vector<double> &x) const { x = m_x; }

      /**
       *  @brief get the independet variable, to be used 
       *  in model computation
       *  @param i index of the extra_info containing
       *  the independent variable
       *  @param j index of the extra_info containing the
       *  independent variable, not used
       *  @return the independent variable
       */
      vector<vector<double>> IndipendentVariable (const int i=-1, const int j=-1) const {(void)i; (void)j; return {m_x};}

      /**
       *  @brief get data for Data1D
       *  @param [out] data vector containing the dataset
       *  @return none
       */
      void data (vector<double> &data) const { data = m_data; }

      /**
       *  @brief get standard deviation for Data1D
       *  @param [out] error vector containing the standard deviation
       *  @return none
       */
      void error (vector<double> &error) const { error = m_error; }

      ///@}

      
      /**
       *  @name Member functions used to set the private members
       */
      ///@{

      /**
       *  @brief set interval variable m_x
       *  @param x vector containing x points
       *  @return none
       */
      void set_xx (const vector<double> x);

      ///@}

      
      /**
       *  @name Member functions for Input/Output 
       */
      ///@{

      /**
       *  @brief read the data
       *  @param input_file input data file
       *  @param skip_nlines the header lines to be skipped
       *  @return none
       */
      void read (const string input_file, const int skip_nlines=0) override;

      /**
       *  @brief write the data
       *  @param dir output directory
       *  @param file output file
       *  @param header text with the variable names to be written at
       *  the first line of the output file
       *  @param precision the float precision
       *  @param rank cpu index (for MPI usage)
       *  @return none
       */
      void write (const string dir, const string file, const string header, const int precision=10, const int rank=0) const override;
      
      /**
       *  @brief write the covariance
       *  @param dir the output directory
       *  @param file the output file
       *  @param precision the float precision
       *  @return none
       */
      void write_covariance (const string dir, const string file, const int precision=10) const override;
      
      ///@}

      /**
       *  @name Member functions for data cut
       */

      ///@{
      
      /**
       * @brief cut the data
       * @param xmin minumum value for the independent variable x
       * @param xmax maximum value for the independent variable x
       * @return pointer to an object of type Data1D
       */
      shared_ptr<Data> cut(const double xmin, const double xmax) const override;

      /**
       * @brief cut the data, for Data1D
       * @param [in] mask vector containing values to be masked
       * @return pointer to an object of type Data1D
       */
      shared_ptr<Data> cut(const vector<bool> mask) const;

      ///@}

    };
    
  }
}

#endif
