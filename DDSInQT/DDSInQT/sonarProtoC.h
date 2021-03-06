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
// d:\ace+dds\ace_wrappers\tao\tao_idl\be\be_codegen.cpp:149

#ifndef _TAO_IDL_SONARPROTOC_8OYA8B_H_
#define _TAO_IDL_SONARPROTOC_8OYA8B_H_

#include /**/ "ace/pre.h"


#include /**/ "ace/config-all.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */


#include "tao/ORB.h"
#include "tao/Basic_Types.h"
#include "tao/Sequence_T.h"
#include "tao/Seq_Var_T.h"
#include "tao/Seq_Out_T.h"
#include "tao/VarOut_T.h"
#include "tao/Arg_Traits_T.h"
#include "tao/Basic_Arguments.h"
#include "tao/Special_Basic_Arguments.h"
#include "tao/Any_Insert_Policy_T.h"
#include "tao/Fixed_Size_Argument_T.h"
#include "tao/Var_Size_Argument_T.h"
#include /**/ "tao/Version.h"
#include /**/ "tao/Versioned_Namespace.h"

#include "tao/StringSeqC.h"

#if TAO_MAJOR_VERSION != 2 || TAO_MINOR_VERSION != 5 || TAO_MICRO_VERSION != 3
#error This file should be regenerated with TAO_IDL
#endif

// TAO_IDL - Generated from
// d:\ace+dds\ace_wrappers\tao\tao_idl\be\be_visitor_sequence\sequence_ch.cpp:99

#if !defined (_OCTETSEQ_CH_)
#define _OCTETSEQ_CH_

class OctetSeq;
typedef ::TAO_FixedSeq_Var_T<OctetSeq> OctetSeq_var;
typedef ::TAO_Seq_Out_T<OctetSeq> OctetSeq_out;


class  OctetSeq
  : public
      ::TAO::unbounded_value_sequence< ::CORBA::Octet>
{
public:
  OctetSeq (void);
  OctetSeq ( ::CORBA::ULong max);
  OctetSeq (
    ::CORBA::ULong max,
    ::CORBA::ULong length,
    ::CORBA::Octet* buffer,
    ::CORBA::Boolean release = false);
  OctetSeq (const OctetSeq &);
  virtual ~OctetSeq (void);
  

  // TAO_IDL - Generated from
  // d:\ace+dds\ace_wrappers\tao\tao_idl\be\be_type.cpp:304

  
  typedef OctetSeq_var _var_type;
  typedef OctetSeq_out _out_type;

  
#if (TAO_NO_COPY_OCTET_SEQUENCES == 1)
  OctetSeq (::CORBA::ULong length, const ACE_Message_Block* mb)
    : ::TAO::unbounded_value_sequence< ::CORBA::Octet> (length, mb) {}
  
#endif /* TAO_NO_COPY_OCTET_SEQUENCE == 1 */
};

#endif /* end #if !defined */

// TAO_IDL - Generated from
// d:\ace+dds\ace_wrappers\tao\tao_idl\be\be_visitor_module\module_ch.cpp:35

namespace org
{

  // TAO_IDL - Generated from
  // d:\ace+dds\ace_wrappers\tao\tao_idl\be\be_visitor_module\module_ch.cpp:35

  namespace omg
  {

    // TAO_IDL - Generated from
    // d:\ace+dds\ace_wrappers\tao\tao_idl\be\be_visitor_module\module_ch.cpp:35

    namespace dds
    {

      // TAO_IDL - Generated from
      // d:\ace+dds\ace_wrappers\tao\tao_idl\be\be_visitor_module\module_ch.cpp:35

      namespace SonarSimu
      {

        // TAO_IDL - Generated from
        // d:\ace+dds\ace_wrappers\tao\tao_idl\be\be_type.cpp:258

        struct SonarProtocol;

        typedef
          ::TAO_Var_Var_T<
              SonarProtocol
            >
          SonarProtocol_var;

        typedef
          ::TAO_Out_T<
              SonarProtocol
            >
          SonarProtocol_out;

        // TAO_IDL - Generated from
        // d:\ace+dds\ace_wrappers\tao\tao_idl\be\be_visitor_structure\structure_ch.cpp:48

        struct  SonarProtocol
        {

          // TAO_IDL - Generated from
          // d:\ace+dds\ace_wrappers\tao\tao_idl\be\be_type.cpp:304

          
          typedef SonarProtocol_var _var_type;
          typedef SonarProtocol_out _out_type;
          
          ::CORBA::Long OctetSeqLength;
          OctetSeq data;
        };

        // TAO_IDL - Generated from
        // d:\ace+dds\ace_wrappers\tao\tao_idl\be\be_type.cpp:258

        struct SonarProtocolII;

        typedef
          ::TAO_Fixed_Var_T<
              SonarProtocolII
            >
          SonarProtocolII_var;

        typedef
          SonarProtocolII &
          SonarProtocolII_out;

        // TAO_IDL - Generated from
        // d:\ace+dds\ace_wrappers\tao\tao_idl\be\be_visitor_structure\structure_ch.cpp:48

        struct  SonarProtocolII
        {

          // TAO_IDL - Generated from
          // d:\ace+dds\ace_wrappers\tao\tao_idl\be\be_type.cpp:304

          
          typedef SonarProtocolII_var _var_type;
          typedef SonarProtocolII_out _out_type;
          
          ::CORBA::Long speed;
          ::CORBA::Long screwNu;
          ::CORBA::Long screwVelocity;
          ::CORBA::Long activeDetectMode;
          ::CORBA::Long traceMode;
          ::CORBA::Long sweepBandNum;
          ::CORBA::Float eclipse;
          ::CORBA::Long sonarX;
          ::CORBA::Long sonarY;
          ::CORBA::Long sonarDepth;
          ::CORBA::Long sonarX2;
          ::CORBA::Long sonarY2;
          ::CORBA::Long sonarDepth2;
          ::CORBA::Long explosionInterval;
          ::CORBA::Long amorVolume;
        };
      
      // TAO_IDL - Generated from
      // d:\ace+dds\ace_wrappers\tao\tao_idl\be\be_visitor_module\module_ch.cpp:64
      
      } // module org::omg::dds::SonarSimu
    
    // TAO_IDL - Generated from
    // d:\ace+dds\ace_wrappers\tao\tao_idl\be\be_visitor_module\module_ch.cpp:64
    
    } // module org::omg::dds
  
  // TAO_IDL - Generated from
  // d:\ace+dds\ace_wrappers\tao\tao_idl\be\be_visitor_module\module_ch.cpp:64
  
  } // module org::omg

// TAO_IDL - Generated from
// d:\ace+dds\ace_wrappers\tao\tao_idl\be\be_visitor_module\module_ch.cpp:64

} // module org

// TAO_IDL - Generated from
// d:\ace+dds\ace_wrappers\tao\tao_idl\be\be_visitor_arg_traits.cpp:66

TAO_BEGIN_VERSIONED_NAMESPACE_DECL


// Arg traits specializations.
namespace TAO
{

  // TAO_IDL - Generated from
  // d:\ace+dds\ace_wrappers\tao\tao_idl\be\be_visitor_arg_traits.cpp:683

  template<>
  class Arg_Traits< ::OctetSeq>
    : public
        Var_Size_Arg_Traits_T<
            ::OctetSeq,
            TAO::Any_Insert_Policy_Noop
          >
  {
  };

  // TAO_IDL - Generated from
  // d:\ace+dds\ace_wrappers\tao\tao_idl\be\be_visitor_arg_traits.cpp:945

  template<>
  class Arg_Traits< ::org::omg::dds::SonarSimu::SonarProtocol>
    : public
        Var_Size_Arg_Traits_T<
            ::org::omg::dds::SonarSimu::SonarProtocol,
            TAO::Any_Insert_Policy_Noop
          >
  {
  };

  // TAO_IDL - Generated from
  // d:\ace+dds\ace_wrappers\tao\tao_idl\be\be_visitor_arg_traits.cpp:945

  template<>
  class Arg_Traits< ::org::omg::dds::SonarSimu::SonarProtocolII>
    : public
        Fixed_Size_Arg_Traits_T<
            ::org::omg::dds::SonarSimu::SonarProtocolII,
            TAO::Any_Insert_Policy_Noop
          >
  {
  };
}

TAO_END_VERSIONED_NAMESPACE_DECL



// TAO_IDL - Generated from
// d:\ace+dds\ace_wrappers\tao\tao_idl\be\be_visitor_traits.cpp:60

TAO_BEGIN_VERSIONED_NAMESPACE_DECL

// Traits specializations.
namespace TAO
{
}
TAO_END_VERSIONED_NAMESPACE_DECL



// TAO_IDL - Generated from
// d:\ace+dds\ace_wrappers\tao\tao_idl\be\be_visitor_sequence\cdr_op_ch.cpp:65

#if !defined _TAO_CDR_OP_OctetSeq_H_
#define _TAO_CDR_OP_OctetSeq_H_
TAO_BEGIN_VERSIONED_NAMESPACE_DECL


 ::CORBA::Boolean operator<< (
    TAO_OutputCDR &strm,
    const OctetSeq &_tao_sequence);
 ::CORBA::Boolean operator>> (
    TAO_InputCDR &strm,
    OctetSeq &_tao_sequence);

TAO_END_VERSIONED_NAMESPACE_DECL



#endif /* _TAO_CDR_OP_OctetSeq_H_ */

// TAO_IDL - Generated from
// d:\ace+dds\ace_wrappers\tao\tao_idl\be\be_visitor_structure\cdr_op_ch.cpp:43


TAO_BEGIN_VERSIONED_NAMESPACE_DECL

 ::CORBA::Boolean operator<< (TAO_OutputCDR &, const org::omg::dds::SonarSimu::SonarProtocol &);
 ::CORBA::Boolean operator>> (TAO_InputCDR &, org::omg::dds::SonarSimu::SonarProtocol &);

TAO_END_VERSIONED_NAMESPACE_DECL



// TAO_IDL - Generated from
// d:\ace+dds\ace_wrappers\tao\tao_idl\be\be_visitor_structure\cdr_op_ch.cpp:43


TAO_BEGIN_VERSIONED_NAMESPACE_DECL

 ::CORBA::Boolean operator<< (TAO_OutputCDR &, const org::omg::dds::SonarSimu::SonarProtocolII &);
 ::CORBA::Boolean operator>> (TAO_InputCDR &, org::omg::dds::SonarSimu::SonarProtocolII &);

TAO_END_VERSIONED_NAMESPACE_DECL



// TAO_IDL - Generated from
// d:\ace+dds\ace_wrappers\tao\tao_idl\be\be_codegen.cpp:1686
#if defined (__ACE_INLINE__)
#include "sonarProtoC.inl"
#endif /* defined INLINE */

#include /**/ "ace/post.h"

#endif /* ifndef */

