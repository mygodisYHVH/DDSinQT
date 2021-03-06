// -*- C++ -*-
/**
 * Code generated by the The ACE ORB (TAO) IDL Compiler v2.5.3
 * TAO and the TAO IDL Compiler have been developed by:
 *       Center for Distributed Object Computing
 *       Washington University
 *       St. Louis, MO
 *       USA
 *       http://www.cs.wustl.edu/~schmidt/doc-center.html
 * and
 *       Distributed Object Computing Laboratory
 *       University of California at Irvine
 *       Irvine, CA
 *       USA
 * and
 *       Institute for Software Integrated Systems
 *       Vanderbilt University
 *       Nashville, TN
 *       USA
 *       http://www.isis.vanderbilt.edu/
 *
 * Information about TAO is available at:
 *     http://www.dre.vanderbilt.edu/~schmidt/TAO.html
 **/

// TAO_IDL - Generated from
// d:\ace+dds\ace_wrappers\tao\tao_idl\be\be_codegen.cpp:451

#ifndef _TAO_IDL_SONARPROTOS_1YWT2D_H_
#define _TAO_IDL_SONARPROTOS_1YWT2D_H_

#include /**/ "ace/pre.h"

#include "sonarProtoC.h"
#include "tao/StringSeqS.h"
#include "tao/PortableServer/Basic_SArguments.h"
#include "tao/PortableServer/Special_Basic_SArguments.h"
#include "tao/PortableServer/Fixed_Size_SArgument_T.h"
#include "tao/PortableServer/Var_Size_SArgument_T.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */


// TAO_IDL - Generated from
// d:\ace+dds\ace_wrappers\tao\tao_idl\be\be_visitor_arg_traits.cpp:66

TAO_BEGIN_VERSIONED_NAMESPACE_DECL


// Arg traits specializations.
namespace TAO
{

  // TAO_IDL - Generated from
  // d:\ace+dds\ace_wrappers\tao\tao_idl\be\be_visitor_arg_traits.cpp:683

  template<>
  class SArg_Traits< ::OctetSeq>
    : public
        Var_Size_SArg_Traits_T<
            ::OctetSeq,
            TAO::Any_Insert_Policy_Noop
          >
  {
  };

  // TAO_IDL - Generated from
  // d:\ace+dds\ace_wrappers\tao\tao_idl\be\be_visitor_arg_traits.cpp:945

  template<>
  class SArg_Traits< ::org::omg::dds::SonarSimu::SonarProtocol>
    : public
        Var_Size_SArg_Traits_T<
            ::org::omg::dds::SonarSimu::SonarProtocol,
            TAO::Any_Insert_Policy_Noop
          >
  {
  };

  // TAO_IDL - Generated from
  // d:\ace+dds\ace_wrappers\tao\tao_idl\be\be_visitor_arg_traits.cpp:945

  template<>
  class SArg_Traits< ::org::omg::dds::SonarSimu::SonarProtocolII>
    : public
        Fixed_Size_SArg_Traits_T<
            ::org::omg::dds::SonarSimu::SonarProtocolII,
            TAO::Any_Insert_Policy_Noop
          >
  {
  };
}

TAO_END_VERSIONED_NAMESPACE_DECL



// TAO_IDL - Generated from
// d:\ace+dds\ace_wrappers\tao\tao_idl\be\be_visitor_module\module_sh.cpp:35

namespace POA_org
{
  

  // TAO_IDL - Generated from
  // d:\ace+dds\ace_wrappers\tao\tao_idl\be\be_visitor_module\module_sh.cpp:35

  namespace omg
  {
    

    // TAO_IDL - Generated from
    // d:\ace+dds\ace_wrappers\tao\tao_idl\be\be_visitor_module\module_sh.cpp:35

    namespace dds
    {
      

      // TAO_IDL - Generated from
      // d:\ace+dds\ace_wrappers\tao\tao_idl\be\be_visitor_module\module_sh.cpp:35

      namespace SonarSimu
      {
        
      
      // TAO_IDL - Generated from
      // d:\ace+dds\ace_wrappers\tao\tao_idl\be\be_visitor_module\module_sh.cpp:66

      } // module org::omg::dds::SonarSimu
    
    // TAO_IDL - Generated from
    // d:\ace+dds\ace_wrappers\tao\tao_idl\be\be_visitor_module\module_sh.cpp:66

    } // module org::omg::dds
  
  // TAO_IDL - Generated from
  // d:\ace+dds\ace_wrappers\tao\tao_idl\be\be_visitor_module\module_sh.cpp:66

  } // module org::omg

// TAO_IDL - Generated from
// d:\ace+dds\ace_wrappers\tao\tao_idl\be\be_visitor_module\module_sh.cpp:66

} // module org

#include /**/ "ace/post.h"

#endif /* ifndef */

