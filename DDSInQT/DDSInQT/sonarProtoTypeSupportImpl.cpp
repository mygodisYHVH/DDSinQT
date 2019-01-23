/* Generated by D:\ACE_DDS\OpenDDS-3.13\bin\opendds_idl version 3.13 (ACE version 6.5.3) running on input file sonarProto.idl */
#include "sonarProtoTypeSupportImpl.h"

#include <cstring>
#include <stdexcept>
#include "dds/CorbaSeq/OctetSeqTypeSupportImpl.h"
#include "dds/DCPS/BuiltInTopicUtils.h"
#include "dds/DCPS/ContentFilteredTopicImpl.h"
#include "dds/DCPS/DataReaderImpl_T.h"
#include "dds/DCPS/DataWriterImpl_T.h"
#include "dds/DCPS/FilterEvaluator.h"
#include "dds/DCPS/MultiTopicDataReader_T.h"
#include "dds/DCPS/PoolAllocator.h"
#include "dds/DCPS/PublicationInstance.h"
#include "dds/DCPS/PublisherImpl.h"
#include "dds/DCPS/Qos_Helper.h"
#include "dds/DCPS/RakeData.h"
#include "dds/DCPS/RakeResults_T.h"
#include "dds/DCPS/ReceivedDataElementList.h"
#include "dds/DCPS/Registered_Data_Types.h"
#include "dds/DCPS/Service_Participant.h"
#include "dds/DCPS/SubscriberImpl.h"
#include "dds/DCPS/Util.h"
#include "dds/DCPS/debug.h"
#include "dds/DdsDcpsDomainC.h"


/* Begin MODULE: CORBA */


/* End MODULE: CORBA */


/* Begin MODULE: CORBA */



/* Begin TYPEDEF: StringSeq */


/* End TYPEDEF: StringSeq */

/* End MODULE: CORBA */


/* Begin TYPEDEF: OctetSeq */

OPENDDS_BEGIN_VERSIONED_NAMESPACE_DECL
namespace OpenDDS { namespace DCPS {

void gen_find_size(const OctetSeq& seq, size_t& size, size_t& padding)
{
  ACE_UNUSED_ARG(seq);
  ACE_UNUSED_ARG(size);
  ACE_UNUSED_ARG(padding);
  find_size_ulong(size, padding);
  if (seq.length() == 0) {
    return;
  }
  size += seq.length() * max_marshaled_size_octet();
}

bool operator<<(Serializer& strm, const OctetSeq& seq)
{
  ACE_UNUSED_ARG(strm);
  ACE_UNUSED_ARG(seq);
  const CORBA::ULong length = seq.length();
  if (!(strm << length)) {
    return false;
  }
  if (length == 0) {
    return true;
  }
  return strm.write_octet_array(seq.get_buffer(), length);
}

bool operator>>(Serializer& strm, OctetSeq& seq)
{
  ACE_UNUSED_ARG(strm);
  ACE_UNUSED_ARG(seq);
  CORBA::ULong length;
  if (!(strm >> length)) {
    return false;
  }
  seq.length(length);
  if (length == 0) {
    return true;
  }
  return strm.read_octet_array(seq.get_buffer(), length);
}

}  }
OPENDDS_END_VERSIONED_NAMESPACE_DECL

#ifndef OPENDDS_NO_CONTENT_SUBSCRIPTION_PROFILE
OPENDDS_BEGIN_VERSIONED_NAMESPACE_DECL
namespace OpenDDS { namespace DCPS {

bool gen_skip_over(Serializer& ser, OctetSeq*)
{
  ACE_UNUSED_ARG(ser);
  ACE_CDR::ULong length;
  if (!(ser >> length)) return false;
  return ser.skip(static_cast<ACE_UINT16>(length), 1);
}

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

void gen_find_size(const org::omg::dds::SonarSimu::SonarProtocol& stru, size_t& size, size_t& padding)
{
  ACE_UNUSED_ARG(stru);
  ACE_UNUSED_ARG(size);
  ACE_UNUSED_ARG(padding);
  if ((size + padding) % 4) {
    padding += 4 - ((size + padding) % 4);
  }
  size += gen_max_marshaled_size(stru.OctetSeqLength);
  gen_find_size(stru.data, size, padding);
}

bool operator<<(Serializer& strm, const org::omg::dds::SonarSimu::SonarProtocol& stru)
{
  ACE_UNUSED_ARG(strm);
  ACE_UNUSED_ARG(stru);
  return (strm << stru.OctetSeqLength)
    && (strm << stru.data);
}

bool operator>>(Serializer& strm, org::omg::dds::SonarSimu::SonarProtocol& stru)
{
  ACE_UNUSED_ARG(strm);
  ACE_UNUSED_ARG(stru);
  return (strm >> stru.OctetSeqLength)
    && (strm >> stru.data);
}

size_t gen_max_marshaled_size(const org::omg::dds::SonarSimu::SonarProtocol& stru, bool align)
{
  ACE_UNUSED_ARG(stru);
  ACE_UNUSED_ARG(align);
  return 0;
}

size_t gen_max_marshaled_size(KeyOnly<const org::omg::dds::SonarSimu::SonarProtocol> stru, bool align)
{
  ACE_UNUSED_ARG(stru);
  ACE_UNUSED_ARG(align);
  return 0;
}

void gen_find_size(KeyOnly<const org::omg::dds::SonarSimu::SonarProtocol> stru, size_t& size, size_t& padding)
{
  ACE_UNUSED_ARG(stru);
  ACE_UNUSED_ARG(size);
  ACE_UNUSED_ARG(padding);
}

bool operator<<(Serializer& strm, KeyOnly<const org::omg::dds::SonarSimu::SonarProtocol> stru)
{
  ACE_UNUSED_ARG(strm);
  ACE_UNUSED_ARG(stru);
  return true;
}

bool operator>>(Serializer& strm, KeyOnly<org::omg::dds::SonarSimu::SonarProtocol> stru)
{
  ACE_UNUSED_ARG(strm);
  ACE_UNUSED_ARG(stru);
  return true;
}

}  }
OPENDDS_END_VERSIONED_NAMESPACE_DECL


namespace org {
namespace omg {
namespace dds {
namespace SonarSimu {
::DDS::DataWriter_ptr SonarProtocolTypeSupportImpl::create_datawriter()
{
  typedef OpenDDS::DCPS::DataWriterImpl_T<SonarProtocol> DataWriterImplType;
  ::DDS::DataWriter_ptr writer_impl = ::DDS::DataWriter::_nil();
  ACE_NEW_NORETURN(writer_impl,
                   DataWriterImplType());
  return writer_impl;
}

::DDS::DataReader_ptr SonarProtocolTypeSupportImpl::create_datareader()
{
  typedef OpenDDS::DCPS::DataReaderImpl_T<SonarProtocol> DataReaderImplType;
  ::DDS::DataReader_ptr reader_impl = ::DDS::DataReader::_nil();
  ACE_NEW_NORETURN(reader_impl,
                   DataReaderImplType());
  return reader_impl;
}

#ifndef OPENDDS_NO_MULTI_TOPIC
::DDS::DataReader_ptr SonarProtocolTypeSupportImpl::create_multitopic_datareader()
{
  typedef OpenDDS::DCPS::DataReaderImpl_T<SonarProtocol> DataReaderImplType;
  typedef OpenDDS::DCPS::MultiTopicDataReader_T<SonarProtocol, DataReaderImplType> MultiTopicDataReaderImplType;
  ::DDS::DataReader_ptr multitopic_reader_impl = ::DDS::DataReader::_nil();
  ACE_NEW_NORETURN(multitopic_reader_impl,
                   MultiTopicDataReaderImplType());
  return multitopic_reader_impl;
}
#endif /* !OPENDDS_NO_MULTI_TOPIC */

#ifndef OPENDDS_NO_CONTENT_SUBSCRIPTION_PROFILE
const OpenDDS::DCPS::MetaStruct& SonarProtocolTypeSupportImpl::getMetaStructForType()
{
  return OpenDDS::DCPS::getMetaStruct<SonarProtocol>();
}
#endif /* !OPENDDS_NO_CONTENT_SUBSCRIPTION_PROFILE */

bool SonarProtocolTypeSupportImpl::has_dcps_key()
{
  return TraitsType::gen_has_key ();
}

const char* SonarProtocolTypeSupportImpl::default_type_name() const
{
  return TraitsType::type_name();
}

SonarProtocolTypeSupport::_ptr_type SonarProtocolTypeSupportImpl::_narrow(CORBA::Object_ptr obj)
{
  return TypeSupportType::_narrow(obj);
}
}
}
}
}

#ifndef OPENDDS_NO_CONTENT_SUBSCRIPTION_PROFILE
OPENDDS_BEGIN_VERSIONED_NAMESPACE_DECL
namespace OpenDDS { namespace DCPS {

template<>
struct MetaStructImpl<org::omg::dds::SonarSimu::SonarProtocol> : MetaStruct {
  typedef org::omg::dds::SonarSimu::SonarProtocol T;

#ifndef OPENDDS_NO_MULTI_TOPIC
  void* allocate() const { return new T; }

  void deallocate(void* stru) const { delete static_cast<T*>(stru); }

  size_t numDcpsKeys() const { return 0; }
#endif /* OPENDDS_NO_MULTI_TOPIC */

  Value getValue(const void* stru, const char* field) const
  {
    const org::omg::dds::SonarSimu::SonarProtocol& typed = *static_cast<const org::omg::dds::SonarSimu::SonarProtocol*>(stru);
    if (std::strcmp(field, "OctetSeqLength") == 0) {
      return typed.OctetSeqLength;
    }
    ACE_UNUSED_ARG(typed);
    throw std::runtime_error("Field " + OPENDDS_STRING(field) + " not found or its type is not supported (in struct org::omg::dds::SonarSimu::SonarProtocol)");
  }

  Value getValue(Serializer& ser, const char* field) const
  {
    if (std::strcmp(field, "OctetSeqLength") == 0) {
      ACE_CDR::Long val;
      if (!(ser >> val)) {
        throw std::runtime_error("Field 'OctetSeqLength' could not be deserialized");
      }
      return val;
    } else {
      if (!ser.skip(1, 4)) {
        throw std::runtime_error("Field 'OctetSeqLength' could not be skipped");
      }
    }
    if (!gen_skip_over(ser, static_cast<OctetSeq*>(0))) {
      throw std::runtime_error("Field " + OPENDDS_STRING(field) + " could not be skipped");
    }
    if (!field[0]) {
      return 0;
    }
    throw std::runtime_error("Field " + OPENDDS_STRING(field) + " not valid for struct org::omg::dds::SonarSimu::SonarProtocol");
  }

  ComparatorBase::Ptr create_qc_comparator(const char* field, ComparatorBase::Ptr next) const
  {
    ACE_UNUSED_ARG(next);
    if (std::strcmp(field, "OctetSeqLength") == 0) {
      return make_field_cmp(&T::OctetSeqLength, next);
    }
    throw std::runtime_error("Field " + OPENDDS_STRING(field) + " not found or its type is not supported (in struct org::omg::dds::SonarSimu::SonarProtocol)");
  }

#ifndef OPENDDS_NO_MULTI_TOPIC
  const char** getFieldNames() const
  {
    static const char* names[] = {"OctetSeqLength", "data", 0};
    return names;
  }

  const void* getRawField(const void* stru, const char* field) const
  {
    if (std::strcmp(field, "OctetSeqLength") == 0) {
      return &static_cast<const T*>(stru)->OctetSeqLength;
    }
    if (std::strcmp(field, "data") == 0) {
      return &static_cast<const T*>(stru)->data;
    }
    throw std::runtime_error("Field " + OPENDDS_STRING(field) + " not found or its type is not supported (in struct org::omg::dds::SonarSimu::SonarProtocol)");
  }

  void assign(void* lhs, const char* field, const void* rhs,
    const char* rhsFieldSpec, const MetaStruct& rhsMeta) const
  {
    ACE_UNUSED_ARG(lhs);
    ACE_UNUSED_ARG(field);
    ACE_UNUSED_ARG(rhs);
    ACE_UNUSED_ARG(rhsFieldSpec);
    ACE_UNUSED_ARG(rhsMeta);
    if (std::strcmp(field, "OctetSeqLength") == 0) {
      static_cast<T*>(lhs)->OctetSeqLength = *static_cast<const CORBA::Long*>(rhsMeta.getRawField(rhs, rhsFieldSpec));
      return;
    }
    if (std::strcmp(field, "data") == 0) {
      static_cast<T*>(lhs)->data = *static_cast<const OctetSeq*>(rhsMeta.getRawField(rhs, rhsFieldSpec));
      return;
    }
    throw std::runtime_error("Field " + OPENDDS_STRING(field) + " not found or its type is not supported (in struct org::omg::dds::SonarSimu::SonarProtocol)");
  }
#endif /* OPENDDS_NO_MULTI_TOPIC */

  bool compare(const void* lhs, const void* rhs, const char* field) const
  {
    ACE_UNUSED_ARG(lhs);
    ACE_UNUSED_ARG(field);
    ACE_UNUSED_ARG(rhs);
    if (std::strcmp(field, "OctetSeqLength") == 0) {
      return static_cast<const T*>(lhs)->OctetSeqLength == static_cast<const T*>(rhs)->OctetSeqLength;
    }
    throw std::runtime_error("Field " + OPENDDS_STRING(field) + " not found or its type is not supported (in struct org::omg::dds::SonarSimu::SonarProtocol)");
  }
};

template<>
const MetaStruct& getMetaStruct<org::omg::dds::SonarSimu::SonarProtocol>()
{
  static MetaStructImpl<org::omg::dds::SonarSimu::SonarProtocol> msi;
  return msi;
}

bool gen_skip_over(Serializer& ser, org::omg::dds::SonarSimu::SonarProtocol*)
{
  ACE_UNUSED_ARG(ser);
  MetaStructImpl<org::omg::dds::SonarSimu::SonarProtocol>().getValue(ser, "");
  return true;
}

}  }
OPENDDS_END_VERSIONED_NAMESPACE_DECL

#endif

/* End STRUCT: SonarProtocol */


/* Begin STRUCT: SonarProtocolII */

OPENDDS_BEGIN_VERSIONED_NAMESPACE_DECL
namespace OpenDDS { namespace DCPS {

void gen_find_size(const org::omg::dds::SonarSimu::SonarProtocolII& stru, size_t& size, size_t& padding)
{
  ACE_UNUSED_ARG(stru);
  ACE_UNUSED_ARG(size);
  ACE_UNUSED_ARG(padding);
  if ((size + padding) % 4) {
    padding += 4 - ((size + padding) % 4);
  }
  size += gen_max_marshaled_size(stru.speed);
  if ((size + padding) % 4) {
    padding += 4 - ((size + padding) % 4);
  }
  size += gen_max_marshaled_size(stru.screwNu);
  if ((size + padding) % 4) {
    padding += 4 - ((size + padding) % 4);
  }
  size += gen_max_marshaled_size(stru.screwVelocity);
  if ((size + padding) % 4) {
    padding += 4 - ((size + padding) % 4);
  }
  size += gen_max_marshaled_size(stru.activeDetectMode);
  if ((size + padding) % 4) {
    padding += 4 - ((size + padding) % 4);
  }
  size += gen_max_marshaled_size(stru.traceMode);
  if ((size + padding) % 4) {
    padding += 4 - ((size + padding) % 4);
  }
  size += gen_max_marshaled_size(stru.sweepBandNum);
  if ((size + padding) % 4) {
    padding += 4 - ((size + padding) % 4);
  }
  size += gen_max_marshaled_size(stru.eclipse);
  if ((size + padding) % 4) {
    padding += 4 - ((size + padding) % 4);
  }
  size += gen_max_marshaled_size(stru.sonarX);
  if ((size + padding) % 4) {
    padding += 4 - ((size + padding) % 4);
  }
  size += gen_max_marshaled_size(stru.sonarY);
  if ((size + padding) % 4) {
    padding += 4 - ((size + padding) % 4);
  }
  size += gen_max_marshaled_size(stru.sonarDepth);
  if ((size + padding) % 4) {
    padding += 4 - ((size + padding) % 4);
  }
  size += gen_max_marshaled_size(stru.sonarX2);
  if ((size + padding) % 4) {
    padding += 4 - ((size + padding) % 4);
  }
  size += gen_max_marshaled_size(stru.sonarY2);
  if ((size + padding) % 4) {
    padding += 4 - ((size + padding) % 4);
  }
  size += gen_max_marshaled_size(stru.sonarDepth2);
  if ((size + padding) % 4) {
    padding += 4 - ((size + padding) % 4);
  }
  size += gen_max_marshaled_size(stru.explosionInterval);
  if ((size + padding) % 4) {
    padding += 4 - ((size + padding) % 4);
  }
  size += gen_max_marshaled_size(stru.amorVolume);
}

bool operator<<(Serializer& strm, const org::omg::dds::SonarSimu::SonarProtocolII& stru)
{
  ACE_UNUSED_ARG(strm);
  ACE_UNUSED_ARG(stru);
  return (strm << stru.speed)
    && (strm << stru.screwNu)
    && (strm << stru.screwVelocity)
    && (strm << stru.activeDetectMode)
    && (strm << stru.traceMode)
    && (strm << stru.sweepBandNum)
    && (strm << stru.eclipse)
    && (strm << stru.sonarX)
    && (strm << stru.sonarY)
    && (strm << stru.sonarDepth)
    && (strm << stru.sonarX2)
    && (strm << stru.sonarY2)
    && (strm << stru.sonarDepth2)
    && (strm << stru.explosionInterval)
    && (strm << stru.amorVolume);
}

bool operator>>(Serializer& strm, org::omg::dds::SonarSimu::SonarProtocolII& stru)
{
  ACE_UNUSED_ARG(strm);
  ACE_UNUSED_ARG(stru);
  return (strm >> stru.speed)
    && (strm >> stru.screwNu)
    && (strm >> stru.screwVelocity)
    && (strm >> stru.activeDetectMode)
    && (strm >> stru.traceMode)
    && (strm >> stru.sweepBandNum)
    && (strm >> stru.eclipse)
    && (strm >> stru.sonarX)
    && (strm >> stru.sonarY)
    && (strm >> stru.sonarDepth)
    && (strm >> stru.sonarX2)
    && (strm >> stru.sonarY2)
    && (strm >> stru.sonarDepth2)
    && (strm >> stru.explosionInterval)
    && (strm >> stru.amorVolume);
}

}  }
OPENDDS_END_VERSIONED_NAMESPACE_DECL

#ifndef OPENDDS_NO_CONTENT_SUBSCRIPTION_PROFILE
OPENDDS_BEGIN_VERSIONED_NAMESPACE_DECL
namespace OpenDDS { namespace DCPS {

template<>
struct MetaStructImpl<org::omg::dds::SonarSimu::SonarProtocolII> : MetaStruct {
  typedef org::omg::dds::SonarSimu::SonarProtocolII T;

#ifndef OPENDDS_NO_MULTI_TOPIC
  void* allocate() const { return new T; }

  void deallocate(void* stru) const { delete static_cast<T*>(stru); }

  size_t numDcpsKeys() const { return 0; }
#endif /* OPENDDS_NO_MULTI_TOPIC */

  Value getValue(const void* stru, const char* field) const
  {
    const org::omg::dds::SonarSimu::SonarProtocolII& typed = *static_cast<const org::omg::dds::SonarSimu::SonarProtocolII*>(stru);
    if (std::strcmp(field, "speed") == 0) {
      return typed.speed;
    }
    if (std::strcmp(field, "screwNu") == 0) {
      return typed.screwNu;
    }
    if (std::strcmp(field, "screwVelocity") == 0) {
      return typed.screwVelocity;
    }
    if (std::strcmp(field, "activeDetectMode") == 0) {
      return typed.activeDetectMode;
    }
    if (std::strcmp(field, "traceMode") == 0) {
      return typed.traceMode;
    }
    if (std::strcmp(field, "sweepBandNum") == 0) {
      return typed.sweepBandNum;
    }
    if (std::strcmp(field, "eclipse") == 0) {
      return typed.eclipse;
    }
    if (std::strcmp(field, "sonarX") == 0) {
      return typed.sonarX;
    }
    if (std::strcmp(field, "sonarY") == 0) {
      return typed.sonarY;
    }
    if (std::strcmp(field, "sonarDepth") == 0) {
      return typed.sonarDepth;
    }
    if (std::strcmp(field, "sonarX2") == 0) {
      return typed.sonarX2;
    }
    if (std::strcmp(field, "sonarY2") == 0) {
      return typed.sonarY2;
    }
    if (std::strcmp(field, "sonarDepth2") == 0) {
      return typed.sonarDepth2;
    }
    if (std::strcmp(field, "explosionInterval") == 0) {
      return typed.explosionInterval;
    }
    if (std::strcmp(field, "amorVolume") == 0) {
      return typed.amorVolume;
    }
    ACE_UNUSED_ARG(typed);
    throw std::runtime_error("Field " + OPENDDS_STRING(field) + " not found or its type is not supported (in struct org::omg::dds::SonarSimu::SonarProtocolII)");
  }

  Value getValue(Serializer& ser, const char* field) const
  {
    if (std::strcmp(field, "speed") == 0) {
      ACE_CDR::Long val;
      if (!(ser >> val)) {
        throw std::runtime_error("Field 'speed' could not be deserialized");
      }
      return val;
    } else {
      if (!ser.skip(1, 4)) {
        throw std::runtime_error("Field 'speed' could not be skipped");
      }
    }
    if (std::strcmp(field, "screwNu") == 0) {
      ACE_CDR::Long val;
      if (!(ser >> val)) {
        throw std::runtime_error("Field 'screwNu' could not be deserialized");
      }
      return val;
    } else {
      if (!ser.skip(1, 4)) {
        throw std::runtime_error("Field 'screwNu' could not be skipped");
      }
    }
    if (std::strcmp(field, "screwVelocity") == 0) {
      ACE_CDR::Long val;
      if (!(ser >> val)) {
        throw std::runtime_error("Field 'screwVelocity' could not be deserialized");
      }
      return val;
    } else {
      if (!ser.skip(1, 4)) {
        throw std::runtime_error("Field 'screwVelocity' could not be skipped");
      }
    }
    if (std::strcmp(field, "activeDetectMode") == 0) {
      ACE_CDR::Long val;
      if (!(ser >> val)) {
        throw std::runtime_error("Field 'activeDetectMode' could not be deserialized");
      }
      return val;
    } else {
      if (!ser.skip(1, 4)) {
        throw std::runtime_error("Field 'activeDetectMode' could not be skipped");
      }
    }
    if (std::strcmp(field, "traceMode") == 0) {
      ACE_CDR::Long val;
      if (!(ser >> val)) {
        throw std::runtime_error("Field 'traceMode' could not be deserialized");
      }
      return val;
    } else {
      if (!ser.skip(1, 4)) {
        throw std::runtime_error("Field 'traceMode' could not be skipped");
      }
    }
    if (std::strcmp(field, "sweepBandNum") == 0) {
      ACE_CDR::Long val;
      if (!(ser >> val)) {
        throw std::runtime_error("Field 'sweepBandNum' could not be deserialized");
      }
      return val;
    } else {
      if (!ser.skip(1, 4)) {
        throw std::runtime_error("Field 'sweepBandNum' could not be skipped");
      }
    }
    if (std::strcmp(field, "eclipse") == 0) {
      ACE_CDR::Float val;
      if (!(ser >> val)) {
        throw std::runtime_error("Field 'eclipse' could not be deserialized");
      }
      return val;
    } else {
      if (!ser.skip(1, 4)) {
        throw std::runtime_error("Field 'eclipse' could not be skipped");
      }
    }
    if (std::strcmp(field, "sonarX") == 0) {
      ACE_CDR::Long val;
      if (!(ser >> val)) {
        throw std::runtime_error("Field 'sonarX' could not be deserialized");
      }
      return val;
    } else {
      if (!ser.skip(1, 4)) {
        throw std::runtime_error("Field 'sonarX' could not be skipped");
      }
    }
    if (std::strcmp(field, "sonarY") == 0) {
      ACE_CDR::Long val;
      if (!(ser >> val)) {
        throw std::runtime_error("Field 'sonarY' could not be deserialized");
      }
      return val;
    } else {
      if (!ser.skip(1, 4)) {
        throw std::runtime_error("Field 'sonarY' could not be skipped");
      }
    }
    if (std::strcmp(field, "sonarDepth") == 0) {
      ACE_CDR::Long val;
      if (!(ser >> val)) {
        throw std::runtime_error("Field 'sonarDepth' could not be deserialized");
      }
      return val;
    } else {
      if (!ser.skip(1, 4)) {
        throw std::runtime_error("Field 'sonarDepth' could not be skipped");
      }
    }
    if (std::strcmp(field, "sonarX2") == 0) {
      ACE_CDR::Long val;
      if (!(ser >> val)) {
        throw std::runtime_error("Field 'sonarX2' could not be deserialized");
      }
      return val;
    } else {
      if (!ser.skip(1, 4)) {
        throw std::runtime_error("Field 'sonarX2' could not be skipped");
      }
    }
    if (std::strcmp(field, "sonarY2") == 0) {
      ACE_CDR::Long val;
      if (!(ser >> val)) {
        throw std::runtime_error("Field 'sonarY2' could not be deserialized");
      }
      return val;
    } else {
      if (!ser.skip(1, 4)) {
        throw std::runtime_error("Field 'sonarY2' could not be skipped");
      }
    }
    if (std::strcmp(field, "sonarDepth2") == 0) {
      ACE_CDR::Long val;
      if (!(ser >> val)) {
        throw std::runtime_error("Field 'sonarDepth2' could not be deserialized");
      }
      return val;
    } else {
      if (!ser.skip(1, 4)) {
        throw std::runtime_error("Field 'sonarDepth2' could not be skipped");
      }
    }
    if (std::strcmp(field, "explosionInterval") == 0) {
      ACE_CDR::Long val;
      if (!(ser >> val)) {
        throw std::runtime_error("Field 'explosionInterval' could not be deserialized");
      }
      return val;
    } else {
      if (!ser.skip(1, 4)) {
        throw std::runtime_error("Field 'explosionInterval' could not be skipped");
      }
    }
    if (std::strcmp(field, "amorVolume") == 0) {
      ACE_CDR::Long val;
      if (!(ser >> val)) {
        throw std::runtime_error("Field 'amorVolume' could not be deserialized");
      }
      return val;
    } else {
      if (!ser.skip(1, 4)) {
        throw std::runtime_error("Field 'amorVolume' could not be skipped");
      }
    }
    if (!field[0]) {
      return 0;
    }
    throw std::runtime_error("Field " + OPENDDS_STRING(field) + " not valid for struct org::omg::dds::SonarSimu::SonarProtocolII");
  }

  ComparatorBase::Ptr create_qc_comparator(const char* field, ComparatorBase::Ptr next) const
  {
    ACE_UNUSED_ARG(next);
    if (std::strcmp(field, "speed") == 0) {
      return make_field_cmp(&T::speed, next);
    }
    if (std::strcmp(field, "screwNu") == 0) {
      return make_field_cmp(&T::screwNu, next);
    }
    if (std::strcmp(field, "screwVelocity") == 0) {
      return make_field_cmp(&T::screwVelocity, next);
    }
    if (std::strcmp(field, "activeDetectMode") == 0) {
      return make_field_cmp(&T::activeDetectMode, next);
    }
    if (std::strcmp(field, "traceMode") == 0) {
      return make_field_cmp(&T::traceMode, next);
    }
    if (std::strcmp(field, "sweepBandNum") == 0) {
      return make_field_cmp(&T::sweepBandNum, next);
    }
    if (std::strcmp(field, "eclipse") == 0) {
      return make_field_cmp(&T::eclipse, next);
    }
    if (std::strcmp(field, "sonarX") == 0) {
      return make_field_cmp(&T::sonarX, next);
    }
    if (std::strcmp(field, "sonarY") == 0) {
      return make_field_cmp(&T::sonarY, next);
    }
    if (std::strcmp(field, "sonarDepth") == 0) {
      return make_field_cmp(&T::sonarDepth, next);
    }
    if (std::strcmp(field, "sonarX2") == 0) {
      return make_field_cmp(&T::sonarX2, next);
    }
    if (std::strcmp(field, "sonarY2") == 0) {
      return make_field_cmp(&T::sonarY2, next);
    }
    if (std::strcmp(field, "sonarDepth2") == 0) {
      return make_field_cmp(&T::sonarDepth2, next);
    }
    if (std::strcmp(field, "explosionInterval") == 0) {
      return make_field_cmp(&T::explosionInterval, next);
    }
    if (std::strcmp(field, "amorVolume") == 0) {
      return make_field_cmp(&T::amorVolume, next);
    }
    throw std::runtime_error("Field " + OPENDDS_STRING(field) + " not found or its type is not supported (in struct org::omg::dds::SonarSimu::SonarProtocolII)");
  }

#ifndef OPENDDS_NO_MULTI_TOPIC
  const char** getFieldNames() const
  {
    static const char* names[] = {"speed", "screwNu", "screwVelocity", "activeDetectMode", "traceMode", "sweepBandNum", "eclipse", "sonarX", "sonarY", "sonarDepth", "sonarX2", "sonarY2", "sonarDepth2", "explosionInterval", "amorVolume", 0};
    return names;
  }

  const void* getRawField(const void* stru, const char* field) const
  {
    if (std::strcmp(field, "speed") == 0) {
      return &static_cast<const T*>(stru)->speed;
    }
    if (std::strcmp(field, "screwNu") == 0) {
      return &static_cast<const T*>(stru)->screwNu;
    }
    if (std::strcmp(field, "screwVelocity") == 0) {
      return &static_cast<const T*>(stru)->screwVelocity;
    }
    if (std::strcmp(field, "activeDetectMode") == 0) {
      return &static_cast<const T*>(stru)->activeDetectMode;
    }
    if (std::strcmp(field, "traceMode") == 0) {
      return &static_cast<const T*>(stru)->traceMode;
    }
    if (std::strcmp(field, "sweepBandNum") == 0) {
      return &static_cast<const T*>(stru)->sweepBandNum;
    }
    if (std::strcmp(field, "eclipse") == 0) {
      return &static_cast<const T*>(stru)->eclipse;
    }
    if (std::strcmp(field, "sonarX") == 0) {
      return &static_cast<const T*>(stru)->sonarX;
    }
    if (std::strcmp(field, "sonarY") == 0) {
      return &static_cast<const T*>(stru)->sonarY;
    }
    if (std::strcmp(field, "sonarDepth") == 0) {
      return &static_cast<const T*>(stru)->sonarDepth;
    }
    if (std::strcmp(field, "sonarX2") == 0) {
      return &static_cast<const T*>(stru)->sonarX2;
    }
    if (std::strcmp(field, "sonarY2") == 0) {
      return &static_cast<const T*>(stru)->sonarY2;
    }
    if (std::strcmp(field, "sonarDepth2") == 0) {
      return &static_cast<const T*>(stru)->sonarDepth2;
    }
    if (std::strcmp(field, "explosionInterval") == 0) {
      return &static_cast<const T*>(stru)->explosionInterval;
    }
    if (std::strcmp(field, "amorVolume") == 0) {
      return &static_cast<const T*>(stru)->amorVolume;
    }
    throw std::runtime_error("Field " + OPENDDS_STRING(field) + " not found or its type is not supported (in struct org::omg::dds::SonarSimu::SonarProtocolII)");
  }

  void assign(void* lhs, const char* field, const void* rhs,
    const char* rhsFieldSpec, const MetaStruct& rhsMeta) const
  {
    ACE_UNUSED_ARG(lhs);
    ACE_UNUSED_ARG(field);
    ACE_UNUSED_ARG(rhs);
    ACE_UNUSED_ARG(rhsFieldSpec);
    ACE_UNUSED_ARG(rhsMeta);
    if (std::strcmp(field, "speed") == 0) {
      static_cast<T*>(lhs)->speed = *static_cast<const CORBA::Long*>(rhsMeta.getRawField(rhs, rhsFieldSpec));
      return;
    }
    if (std::strcmp(field, "screwNu") == 0) {
      static_cast<T*>(lhs)->screwNu = *static_cast<const CORBA::Long*>(rhsMeta.getRawField(rhs, rhsFieldSpec));
      return;
    }
    if (std::strcmp(field, "screwVelocity") == 0) {
      static_cast<T*>(lhs)->screwVelocity = *static_cast<const CORBA::Long*>(rhsMeta.getRawField(rhs, rhsFieldSpec));
      return;
    }
    if (std::strcmp(field, "activeDetectMode") == 0) {
      static_cast<T*>(lhs)->activeDetectMode = *static_cast<const CORBA::Long*>(rhsMeta.getRawField(rhs, rhsFieldSpec));
      return;
    }
    if (std::strcmp(field, "traceMode") == 0) {
      static_cast<T*>(lhs)->traceMode = *static_cast<const CORBA::Long*>(rhsMeta.getRawField(rhs, rhsFieldSpec));
      return;
    }
    if (std::strcmp(field, "sweepBandNum") == 0) {
      static_cast<T*>(lhs)->sweepBandNum = *static_cast<const CORBA::Long*>(rhsMeta.getRawField(rhs, rhsFieldSpec));
      return;
    }
    if (std::strcmp(field, "eclipse") == 0) {
      static_cast<T*>(lhs)->eclipse = *static_cast<const CORBA::Float*>(rhsMeta.getRawField(rhs, rhsFieldSpec));
      return;
    }
    if (std::strcmp(field, "sonarX") == 0) {
      static_cast<T*>(lhs)->sonarX = *static_cast<const CORBA::Long*>(rhsMeta.getRawField(rhs, rhsFieldSpec));
      return;
    }
    if (std::strcmp(field, "sonarY") == 0) {
      static_cast<T*>(lhs)->sonarY = *static_cast<const CORBA::Long*>(rhsMeta.getRawField(rhs, rhsFieldSpec));
      return;
    }
    if (std::strcmp(field, "sonarDepth") == 0) {
      static_cast<T*>(lhs)->sonarDepth = *static_cast<const CORBA::Long*>(rhsMeta.getRawField(rhs, rhsFieldSpec));
      return;
    }
    if (std::strcmp(field, "sonarX2") == 0) {
      static_cast<T*>(lhs)->sonarX2 = *static_cast<const CORBA::Long*>(rhsMeta.getRawField(rhs, rhsFieldSpec));
      return;
    }
    if (std::strcmp(field, "sonarY2") == 0) {
      static_cast<T*>(lhs)->sonarY2 = *static_cast<const CORBA::Long*>(rhsMeta.getRawField(rhs, rhsFieldSpec));
      return;
    }
    if (std::strcmp(field, "sonarDepth2") == 0) {
      static_cast<T*>(lhs)->sonarDepth2 = *static_cast<const CORBA::Long*>(rhsMeta.getRawField(rhs, rhsFieldSpec));
      return;
    }
    if (std::strcmp(field, "explosionInterval") == 0) {
      static_cast<T*>(lhs)->explosionInterval = *static_cast<const CORBA::Long*>(rhsMeta.getRawField(rhs, rhsFieldSpec));
      return;
    }
    if (std::strcmp(field, "amorVolume") == 0) {
      static_cast<T*>(lhs)->amorVolume = *static_cast<const CORBA::Long*>(rhsMeta.getRawField(rhs, rhsFieldSpec));
      return;
    }
    throw std::runtime_error("Field " + OPENDDS_STRING(field) + " not found or its type is not supported (in struct org::omg::dds::SonarSimu::SonarProtocolII)");
  }
#endif /* OPENDDS_NO_MULTI_TOPIC */

  bool compare(const void* lhs, const void* rhs, const char* field) const
  {
    ACE_UNUSED_ARG(lhs);
    ACE_UNUSED_ARG(field);
    ACE_UNUSED_ARG(rhs);
    if (std::strcmp(field, "speed") == 0) {
      return static_cast<const T*>(lhs)->speed == static_cast<const T*>(rhs)->speed;
    }
    if (std::strcmp(field, "screwNu") == 0) {
      return static_cast<const T*>(lhs)->screwNu == static_cast<const T*>(rhs)->screwNu;
    }
    if (std::strcmp(field, "screwVelocity") == 0) {
      return static_cast<const T*>(lhs)->screwVelocity == static_cast<const T*>(rhs)->screwVelocity;
    }
    if (std::strcmp(field, "activeDetectMode") == 0) {
      return static_cast<const T*>(lhs)->activeDetectMode == static_cast<const T*>(rhs)->activeDetectMode;
    }
    if (std::strcmp(field, "traceMode") == 0) {
      return static_cast<const T*>(lhs)->traceMode == static_cast<const T*>(rhs)->traceMode;
    }
    if (std::strcmp(field, "sweepBandNum") == 0) {
      return static_cast<const T*>(lhs)->sweepBandNum == static_cast<const T*>(rhs)->sweepBandNum;
    }
    if (std::strcmp(field, "eclipse") == 0) {
      return static_cast<const T*>(lhs)->eclipse == static_cast<const T*>(rhs)->eclipse;
    }
    if (std::strcmp(field, "sonarX") == 0) {
      return static_cast<const T*>(lhs)->sonarX == static_cast<const T*>(rhs)->sonarX;
    }
    if (std::strcmp(field, "sonarY") == 0) {
      return static_cast<const T*>(lhs)->sonarY == static_cast<const T*>(rhs)->sonarY;
    }
    if (std::strcmp(field, "sonarDepth") == 0) {
      return static_cast<const T*>(lhs)->sonarDepth == static_cast<const T*>(rhs)->sonarDepth;
    }
    if (std::strcmp(field, "sonarX2") == 0) {
      return static_cast<const T*>(lhs)->sonarX2 == static_cast<const T*>(rhs)->sonarX2;
    }
    if (std::strcmp(field, "sonarY2") == 0) {
      return static_cast<const T*>(lhs)->sonarY2 == static_cast<const T*>(rhs)->sonarY2;
    }
    if (std::strcmp(field, "sonarDepth2") == 0) {
      return static_cast<const T*>(lhs)->sonarDepth2 == static_cast<const T*>(rhs)->sonarDepth2;
    }
    if (std::strcmp(field, "explosionInterval") == 0) {
      return static_cast<const T*>(lhs)->explosionInterval == static_cast<const T*>(rhs)->explosionInterval;
    }
    if (std::strcmp(field, "amorVolume") == 0) {
      return static_cast<const T*>(lhs)->amorVolume == static_cast<const T*>(rhs)->amorVolume;
    }
    throw std::runtime_error("Field " + OPENDDS_STRING(field) + " not found or its type is not supported (in struct org::omg::dds::SonarSimu::SonarProtocolII)");
  }
};

template<>
const MetaStruct& getMetaStruct<org::omg::dds::SonarSimu::SonarProtocolII>()
{
  static MetaStructImpl<org::omg::dds::SonarSimu::SonarProtocolII> msi;
  return msi;
}

bool gen_skip_over(Serializer& ser, org::omg::dds::SonarSimu::SonarProtocolII*)
{
  ACE_UNUSED_ARG(ser);
  MetaStructImpl<org::omg::dds::SonarSimu::SonarProtocolII>().getValue(ser, "");
  return true;
}

}  }
OPENDDS_END_VERSIONED_NAMESPACE_DECL

#endif

/* End STRUCT: SonarProtocolII */

/* End MODULE: SonarSimu */

/* End MODULE: dds */

/* End MODULE: omg */

/* End MODULE: org */
