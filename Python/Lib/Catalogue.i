// SWIG Interface to Catalogue

%ignore *::operator[];

%{
#include "Object.h"
#include "RandomObject.h"
#include "Halo.h"
#include "Mock.h"
#include "Galaxy.h"
#include "Cluster.h"
#include "Catalogue.h"
#include "ChainMesh_Catalogue.h"
#include "Void.h"
%}

%include "Object.h"
%include "RandomObject.h"
%include "Halo.h"
%include "Mock.h"
%include "Galaxy.h"
%include "Cluster.h"
%include "Catalogue.h"
%include "ChainMesh_Catalogue.h"
%include "Void.h"

%template(RandomObjVec) vector<cosmobl::catalogue::RandomObject>;
%template(MockVec) vector<cosmobl::catalogue::Mock>;
%template(HaloVec) vector<cosmobl::catalogue::Halo>;
%template(GalaxyVec) vector<cosmobl::catalogue::Galaxy>;
%template(ClusterVec) vector<cosmobl::catalogue::Cluster>;

%template(VarVec) std::vector<enum cosmobl::catalogue::Var>;


%extend cosmobl::catalogue::Catalogue
{  
  %template(add_object) add_object< RandomObject >;
  %template(add_object) add_object< Mock >;
  %template(add_object) add_object< Halo >;
  %template(add_object) add_object< Galaxy >;
  %template(add_object) add_object< Cluster >;
  %template(add_object) add_object< Void >;

  %template(add_objects) add_objects< RandomObject >;
  %template(add_objects) add_objects< Mock >;
  %template(add_objects) add_objects< Halo >;
  %template(add_objects) add_objects< Galaxy >;
  %template(add_objects) add_objects< Cluster >;
  %template(add_objects) add_objects< Void >;
  
  %template(replace_objects) replace_objects< RandomObject >;
  %template(replace_objects) replace_objects< Mock >;
  %template(replace_objects) replace_objects< Halo >;
  %template(replace_objects) replace_objects< Galaxy >;
  %template(replace_objects) replace_objects< Cluster >;
  %template(replace_objects) replace_objects< Void >;

  shared_ptr<cosmobl::catalogue::Object> __getitem__(const size_t i) {
    return (*self)[i];
  }
}
