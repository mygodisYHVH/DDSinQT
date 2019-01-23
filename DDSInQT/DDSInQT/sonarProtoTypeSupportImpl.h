/* -*- C++ -*- */
/* Generated by D:\ACE_DDS\OpenDDS-3.13\bin\opendds_idl version 3.13 (ACE version 6.5.3) running on input file sonarProto.idl */
#ifndef OPENDDS_IDL_GENERATED_SONARPROTOTYPESUPPORTIMPL_H_X2EGRC
#define OPENDDS_IDL_GENERATED_SONARPROTOTYPESUPPORTIMPL_H_X2EGRC
#include "sonarProtoC.h"
#include "dds/DCPS/Definitions.h"
#include "dds/DdsDcpsC.h"
#include "dds/DCPS/Serializer.h"
#include "dds/DCPS/TypeSupportImpl.h"
#include "sonarProtoTypeSupportC.h"
#include "tao/StringSeqC.h"


/* Begin MODULE: CORBA */


/* End MODULE: CORBA */


/* Begin MODULE: CORBA */



/* Begin TYPEDEF: StringSeq */


/* End TYPEDEF: StringSeq */

/* End MODULE: CORBA */


/* Begin TYPEDEF: OctetSeq */

OPENDDS_BEGIN_VERSIONED_NAMESPACE_DECL
namespace OpenDDS { namespace DCPS {

void gen_find_size(const OctetSeq& seq, size_t& size, size_t& padding);

bool operator<<(Serializer& strm, const OctetSeq& seq);

bool operator>>(Serializer& strm, OctetSeq& seq);

}  }
OPENDDS_END_VERSIONED_NAMESPACE_DECL

#ifndef OPENDDS_NO_CONTENT_SUBSCRIPTION_PROFILE
OPENDDS_BEGIN_VERSIONED_NAMESPACE_DECL
namespace OpenDDS { namespace DCPS {

bool gen_skip_over(Serializer& ser, OctetSeq*);

}  }
OPENDDS_END_VERSIONED_NAMESPACE_DECL

#endif

/* End TYPEDEF: OctetSeq */


/* Begin MODULE: org */



/* Begin MODULE: omg */



/* Begin MODULE: dds */



/* Begin MODULE: SonarSimu */



/* Begin STRUCT: SonarProtocol */

OPENDDS_BEGIN_VERSIONED_NAMESPACE_DECL
namespace OpenDDS { namespace DCPS {

void gen_find_size(const org::omg::dds::SonarSimu::SonarProtocol& stru, size_t& size, size_t& padding);

bool operator<<(Serializer& strm, const org::omg::dds::SonarSimu::SonarProtocol& stru);

bool operator>>(Serializer& strm, org::omg::dds::SonarSimu::SonarProtocol& stru);

size_t gen_max_marshaled_size(const org::omg::dds::SonarSimu::SonarProtocol& stru, bool align);

size_t gen_max_marshaled_size(KeyOnly<const org::omg::dds::SonarSimu::SonarProtocol> stru, bool align);

void gen_find_size(KeyOnly<const org::omg::dds::SonarSimu::SonarProtocol> stru, size_t& size, size_t& padding);

bool operator<<(Serializer& strm, KeyOnly<const org::omg::dds::SonarSimu::SonarProtocol> stru);

bool operator>>(Serializer& strm, KeyOnly<org::omg::dds::SonarSimu::SonarProtocol> stru);

template <>
struct MarshalTraits<org::omg::dds::SonarSimu::SonarProtocol> {
  static bool gen_is_bounded_size() { return false; }
  static bool gen_is_bounded_key_size() { return true; }
};
}  }
OPENDDS_END_VERSIONED_NAMESPACE_DECL


namespace org {
namespace omg {
namespace dds {
namespace SonarSimu {
// This structure supports use of std::map with a key
// defined by one or more #pragma DCPS_DATA_KEY lines.
struct  SonarProtocol_OpenDDS_KeyLessThan {
  bool operator()(const org::omg::dds::SonarSimu::SonarProtocol&, const org::omg::dds::SonarSimu::SonarProtocol&) const
  {
    // Eith no DCPS_DATA_KEYs, return false
    // to allow use of map with just one entry
    return false;
  }
};
}
}
}
}


namespace org {
namespace omg {
namespace dds {
namespace SonarSimu {
class SonarProtocolTypeSupportImpl;
}
}
}
}

OPENDDS_BEGIN_VERSIONED_NAMESPACE_DECL
namespace OpenDDS { namespace DCPS {
template <>
struct DDSTraits<org::omg::dds::SonarSimu::SonarProtocol> {
  typedef org::omg::dds::SonarSimu::SonarProtocol MessageType;
  typedef org::omg::dds::SonarSimu::SonarProtocolSeq MessageSequenceType;
  typedef org::omg::dds::SonarSimu::SonarProtocolTypeSupport TypeSupportType;
  typedef org::omg::dds::SonarSimu::SonarProtocolTypeSupportImpl TypeSupportTypeImpl;
  typedef org::omg::dds::SonarSimu::SonarProtocolDataWriter DataWriterType;
  typedef org::omg::dds::SonarSimu::SonarProtocolDataReader DataReaderType;
  typedef org::omg::dds::SonarSimu::SonarProtocol_OpenDDS_KeyLessThan LessThanType;

  static const char* type_name () { return "org::omg::dds::SonarSimu::SonarProtocol"; }
  static bool gen_has_key () { return false; }

  static size_t gen_max_marshaled_size(const MessageType& x, bool align) { return ::OpenDDS::DCPS::gen_max_marshaled_size(x, align); }
  static void gen_find_size(const MessageType& arr, size_t& size, size_t& padding) { ::OpenDDS::DCPS::gen_find_size(arr, size, padding); }

  static size_t gen_max_marshaled_size(const OpenDDS::DCPS::KeyOnly<const MessageType>& x, bool align) { return ::OpenDDS::DCPS::gen_max_marshaled_size(x, align); }
  static void gen_find_size(const OpenDDS::DCPS::KeyOnly<const MessageType>& arr, size_t& size, size_t& padding) { ::OpenDDS::DCPS::gen_find_size(arr, size, padding); }
};
}  }
OPENDDS_END_VERSIONED_NAMESPACE_DECL


namespace org {
namespace omg {
namespace dds {
namespace SonarSimu {
class  SonarProtocolTypeSupportImpl
  : public virtual OpenDDS::DCPS::LocalObject<SonarProtocolTypeSupport>
  , public virtual OpenDDS::DCPS::TypeSupportImpl
{
public:
  typedef OpenDDS::DCPS::DDSTraits<SonarProtocol> TraitsType;
  typedef SonarProtocolTypeSupport TypeSupportType;
  typedef SonarProtocolTypeSupport::_var_type _var_type;
  typedef SonarProtocolTypeSupport::_ptr_type _ptr_type;

  SonarProtocolTypeSupportImpl() {}
  virtual ~SonarProtocolTypeSupportImpl() {}

  virtual ::DDS::DataWriter_ptr create_datawriter();
  virtual ::DDS::DataReader_ptr create_datareader();
#ifndef OPENDDS_NO_MULTI_TOPIC
  virtual ::DDS::DataReader_ptr create_multitopic_datareader();
#endif /* !OPENDDS_NO_MULTI_TOPIC */
#ifndef OPENDDS_NO_CONTENT_SUBSCRIPTION_PROFILE
  virtual const OpenDDS::DCPS::MetaStruct& getMetaStructForType();
#endif /* !OPENDDS_NO_CONTENT_SUBSCRIPTION_PROFILE */
  virtual bool has_dcps_key();
  const char* default_type_name() const;
  static SonarProtocolTypeSupport::_ptr_type _narrow(CORBA::Object_ptr obj);
};
}
}
}
}

#ifndef OPENDDS_NO_CONTENT_SUBSCRIPTION_PROFILE
OPENDDS_BEGIN_VERSIONED_NAMESPACE_DECL
namespace OpenDDS { namespace DCPS {

class MetaStruct;

template<typename T>
const MetaStruct& getMetaStruct();

template<>
const MetaStruct& getMetaStruct<org::omg::dds::SonarSimu::SonarProtocol>();
bool gen_skip_over(Serializer& ser, org::omg::dds::SonarSimu::SonarProtocol*);

}  }
OPENDDS_END_VERSIONED_NAMESPACE_DECL

#endif

/* End STRUCT: SonarProtocol */


/* Begin STRUCT: SonarProtocolII */

OPENDDS_BEGIN_VERSIONED_NAMESPACE_DECL
namespace OpenDDS { namespace DCPS {

void gen_find_size(const org::omg::dds::SonarSimu::SonarProtocolII& stru, size_t& size, size_t& padding);

bool operator<<(Serializer& strm, const org::omg::dds::SonarSimu::SonarProtocolII& stru);

bool operator>>(Serializer& strm, org::omg::dds::SonarSimu::SonarProtocolII& stru);

}  }
OPENDDS_END_VERSIONED_NAMESPACE_DECL

#ifndef OPENDDS_NO_CONTENT_SUBSCRIPTION_PROFILE
OPENDDS_BEGIN_VERSIONED_NAMESPACE_DECL
namespace OpenDDS { namespace DCPS {

template<>
const MetaStruct& getMetaStruct<org::omg::dds::SonarSimu::SonarProtocolII>();
bool gen_skip_over(Serializer& ser, org::omg::dds::SonarSimu::SonarProtocolII*);

}  }
OPENDDS_END_VERSIONED_NAMESPACE_DECL

#endif

/* End STRUCT: SonarProtocolII */

/* End MODULE: SonarSimu */

/* End MODULE: dds */

/* End MODULE: omg */

/* End MODULE: org */
#endif /* OPENDDS_IDL_GENERATED_SONARPROTOTYPESUPPORTIMPL_H_X2EGRC */
