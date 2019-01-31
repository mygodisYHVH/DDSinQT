#include "DDSInQT.h"

#include<stdio.h>
using namespace std;
#include "ace/config-all.h"
#include <iostream>  

#ifdef ACE_HAS_CPP11
# include <string>
#include<QtCore>
# define TO_STRING std::to_string
#else
# include <boost/lexical_cast.hpp>
# define TO_STRING boost::lexical_cast<std::string>
#endif
#include<time.h>
#define random(x) (rand()%x)
#include"configuration.h"
using org::omg::dds::SonarSimu::SonarProtocol;
using org::omg::dds::SonarSimu::SonarProtocolTypeSupport_var;
using org::omg::dds::SonarSimu::SonarProtocolTypeSupportImpl;
using org::omg::dds::SonarSimu::SonarProtocolDataWriter;
using org::omg::dds::SonarSimu::SonarProtocolDataWriter_var;
using org::omg::dds::SonarSimu::SonarProtocolDataReader;
using org::omg::dds::SonarSimu::SonarProtocolDataReader_var;

#include"configuration.h"

DDSInQT::DDSInQT(DDS::DomainParticipant_var participant,
	const std::string& partition, QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
    domainID = participant->get_domain_id();
    participant_ = participant;
	srand((int)time(0));
    topicName = "";
   bool res=false;
   listener_ =  new SubListener;
   res =  connect(listener_,SIGNAL(emitData(QByteArray)),this,SLOT(receiveDataFromDDS(QByteArray)),Qt::QueuedConnection);
    memberName = "";

    //创建会话
//	DDS::TopicQos topic_qos;
//	participant->get_default_topic_qos(topic_qos);
//	topic_qos.history.kind = DDS::KEEP_LAST_HISTORY_QOS;
//	topic_qos.history.depth = 100;
//	SonarProtocolTypeSupport_var ts =
//		new SonarProtocolTypeSupportImpl;
//	CORBA::String_var type_name = "sonarSimuPub";
//	if (ts->register_type(participant, type_name) != DDS::RETCODE_OK) {
//		//        std::cout << "Could not register type " << std::endl;
//	}
//    QString sig = "aiyawocao";
//	DDS::DomainParticipantQos dpq;
//	dpq.user_data.value.length(100);

//    memcpy(&dpq.user_data.value[0], sig.toStdString().data(), 11);

//	participant->set_qos(dpq);

//	simuTopic_ =
//		participant->create_topic("sonar",
//			type_name,
//			topic_qos,
//			0,
//			OpenDDS::DCPS::DEFAULT_STATUS_MASK);

//    //创建发布者
//	DDS::PublisherQos pub_qos;
//	participant->get_default_publisher_qos(pub_qos);
//	if (!partition.empty()) {
//		pub_qos.partition.name.length(1);
//		pub_qos.partition.name[0] = partition.c_str();
//	}
//	// Create Publisher
//	publisher_ =
//		participant->create_publisher(pub_qos,
//			0,
//			OpenDDS::DCPS::DEFAULT_STATUS_MASK);

//	if (!publisher_) {
//		cout << "Could not create publisher \n";
//	}
//    //创建写对象
//    DDS::DataWriterQos qos_;
//    publisher_->get_default_datawriter_qos(qos_);
//    qos_.reliability.kind = DDS::BEST_EFFORT_RELIABILITY_QOS;
//    qos_.user_data.value.length(100);

//    memcpy(&qos_.user_data.value[0], sig.toStdString().data(), 11);




//    DDS::DataWriter_var writer =
//        publisher_->create_datawriter(simuTopic_,
//            qos_,
//            0,
//            OpenDDS::DCPS::DEFAULT_STATUS_MASK);

//    if (!writer) {
//        //          std::cerr << "Could not create data writer " << std::endl;
//    }

    //创建订购者
//    DDS::SubscriberQos sub_qos;
//    participant->get_default_subscriber_qos(sub_qos);
//    if (!partition.empty()) {
//        sub_qos.partition.name.length(1);
//        sub_qos.partition.name[0] = partition.c_str();
//    }
//    subscriber_ =
//        participant->create_subscriber(sub_qos,
//            0,
//            OpenDDS::DCPS::DEFAULT_STATUS_MASK);

//    if (!subscriber_) {
//        //        std::cerr << "Could not create subscriber " << std::endl;
//    }

//    //创建读对象
//    DDS::TopicDescription_var topicDesc;
//    DDS::DataReaderQos Reader_qos_;
//    subscriber_->get_default_datareader_qos(Reader_qos_);

//    qos_.reliability.kind = DDS::BEST_EFFORT_RELIABILITY_QOS;
//    DDS::DataReader_var reader =
//        subscriber_->create_datareader(topicDesc,
//            Reader_qos_,
////			readerQos_.get_qos(),
//            &listener_,//0,
//            OpenDDS::DCPS::DEFAULT_STATUS_MASK);

//    if (!reader) {
//        //std::cerr << "Could not create data reader " << std::endl;
//        int i = 0;
//    }

//    SonarProtocolDataReader_var dr;
//    dr =
//        SonarProtocolDataReader::_narrow(reader);

//    if (!dr) {
//        //std::cerr << "Data reader is not a ShapeTypeDataReader " << std::endl;
//        int i = 0;
//    }

//	SonarProtocol protocol;
//	OctetSeq theData;
//	theData.length(26);
//	protocol.data.length(32);

////protocol.data.
//	protocol.OctetSeqLength = 32;


//	SonarProtocolDataWriter_var dw =
//		SonarProtocolDataWriter::_narrow(writer);


}

void DDSInQT::receiveDataFromDDS(QByteArray data)
{

    QString haha = QString::fromStdString( data.toStdString());
    ui.testEdition->insertPlainText(haha);
}

void DDSInQT::on_toolButton_clicked()
{
	Configuration dlg;
	dlg.exec();
}


void DDSInQT::on_write_clicked()
{
    QString data = ui.textInput->text();
    SonarProtocol protocol;
    protocol.OctetSeqLength = data.length();
    protocol.data.length(data.length());
    memcpy(&protocol.data[0],data.toStdString().data(),data.length());
    DDS::ReturnCode_t res;
    res = dw->write(protocol,::DDS::HANDLE_NIL);
    if(res==0)
    {
        ui.testEdition->insertPlainText("发送成功\n");
    }
}



