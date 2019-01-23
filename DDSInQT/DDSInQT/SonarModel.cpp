#include "SonarModel.h"
#include <dds/DCPS/Marked_Default_Qos.h>
#include <dds/DdsDcpsInfrastructureC.h>
#include<stdio.h>
using namespace std;
#include "ace/config-all.h"
#include <iostream>  
#include "sonarProtoTypeSupportImpl.h"
#include"sonarProtoTypeSupportC.h"
#include"sonarProtoC.h"
#ifdef ACE_HAS_CPP11
# include <string>
# define TO_STRING std::to_string
#else
# include <boost/lexical_cast.hpp>
# define TO_STRING boost::lexical_cast<std::string>
#endif
#include<time.h>
#define random(x) (rand()%x)

using org::omg::dds::SonarSimu::SonarProtocol;
using org::omg::dds::SonarSimu::SonarProtocolTypeSupport_var;
using org::omg::dds::SonarSimu::SonarProtocolTypeSupportImpl;
using org::omg::dds::SonarSimu::SonarProtocolDataWriter;
using org::omg::dds::SonarSimu::SonarProtocolDataWriter_var;
using org::omg::dds::SonarSimu::SonarProtocolDataReader;
using org::omg::dds::SonarSimu::SonarProtocolDataReader_var;

SonarModel::SonarModel(DDS::DomainParticipant_var participant,
	const std::string& partition)
{
	srand((int)time(0));
	DDS::TopicQos topic_qos;
	participant->get_default_topic_qos(topic_qos);
	topic_qos.history.kind = DDS::KEEP_LAST_HISTORY_QOS;
	topic_qos.history.depth = 100;
	SonarProtocolTypeSupport_var ts =
		new SonarProtocolTypeSupportImpl;
	CORBA::String_var type_name = "sonarSimuPub";
	if (ts->register_type(participant, type_name) != DDS::RETCODE_OK) {
		//        std::cout << "Could not register type " << std::endl;
	}
	char* sig = "aiyawocao";
	DDS::DomainParticipantQos dpq;
	dpq.user_data.value.length(100);

	memcpy(&dpq.user_data.value[0], sig, 11);

	participant->set_qos(dpq);

	simuTopic_ =
		participant->create_topic("sonar",
			type_name,
			topic_qos,
			0,
			OpenDDS::DCPS::DEFAULT_STATUS_MASK);


	

	DDS::PublisherQos pub_qos;
	participant->get_default_publisher_qos(pub_qos);
	if (!partition.empty()) {
		pub_qos.partition.name.length(1);
		pub_qos.partition.name[0] = partition.c_str();
	}
	// Create Publisher
	publisher_ =
		participant->create_publisher(pub_qos,
			0,
			OpenDDS::DCPS::DEFAULT_STATUS_MASK);

	if (!publisher_) {
		cout << "Could not create publisher \n";
	}

	//DDS::SubscriberQos sub_qos;
	//participant->get_default_subscriber_qos(sub_qos);
	//if (!partition.empty()) {
	//	sub_qos.partition.name.length(1);
	//	sub_qos.partition.name[0] = partition.c_str();
	//}
	//// Create Subscriber
	//subscriber_ =
	//	participant->create_subscriber(sub_qos,
	//		0,
	//		OpenDDS::DCPS::DEFAULT_STATUS_MASK);

	//if (!subscriber_) {
	//	//        std::cerr << "Could not create subscriber " << std::endl;
	//}

	SonarProtocol protocol;
	OctetSeq theData;
	theData.length(26);
	protocol.data.length(32);


	

	//protocol.data.allocbuf(39);
	/*double *a,*b,*c,*d;
	a = new double;
	*a = 8;
	b = new double;
	*b = 432;
	c = new double;
	*c = 1023;
	d= new double;
	*d = 4587;*/
	double a, b, c, d;


		//memcpy(&(protocol.data)+8, a+1, 8);
		//memcpy(&(protocol.data)+16, a+2, 8);
		//memcpy(&(protocol.data)+24, a+3, 8);
	//}
	
	//protocol.data.
	protocol.OctetSeqLength = 32;
	
	DDS::DataWriterQos qos_;
	publisher_->get_default_datawriter_qos(qos_);
	qos_.reliability.kind = DDS::BEST_EFFORT_RELIABILITY_QOS;
	qos_.user_data.value.length(100);
	
	memcpy(&qos_.user_data.value[0], sig, 11);

	


	DDS::DataWriter_var writer =
		publisher_->create_datawriter(simuTopic_,
			qos_,
			0,
			OpenDDS::DCPS::DEFAULT_STATUS_MASK);

	if (!writer) {
		//          std::cerr << "Could not create data writer " << std::endl;
	}
	SonarProtocolDataWriter_var dw =
		SonarProtocolDataWriter::_narrow(writer);

	for (int i = 0; i < 5000; i++)
	{
		a = random(1000);
		b = random(1000);
		c = random(1000);
		d = random(1000);
		//memcpy(&theData[0], a,8);
		//memcpy(&theData[7], a+1, 8);
		//memcpy(&theData[15], a+2, 8);
		//memcpy(&theData[23], a+3, 8);
		/*protocol.data = theData;*/
		//memset(&theData[0], 0, 39);
		//for (int i = 0; i < 4; i++)
		//{
		memcpy(&(protocol.data[0]), &a, sizeof(double));
		memcpy(&(protocol.data[0 + sizeof(double) * 1]), &b, sizeof(double));
		memcpy(&(protocol.data[0 + sizeof(double) * 2]), &c, sizeof(double));
		memcpy(&(protocol.data[0 + sizeof(double) * 3]), &d, sizeof(double));
		_sleep(8000);
		//protocol.timestamp = 10000 - i;
		double k, l, m, n;
		k = *(double*)&(protocol.data[0]);
		l = *(double*)(&(protocol.data[0]) + 8);
		m = *(double*)(&(protocol.data[0]) + 16);
		n = *(double*)(&(protocol.data[0]) + 24);
		dw->write(protocol, ::DDS::HANDLE_NIL);
		
		
		cout << "package:"<<i << " and the data is \n k:"<<a<<"\n l:"<<b<<"\n m:"<<c<<"\n n:"<<d<<"\n";
	}
	//delete a, b, c, d;
	// last shot
	//shared_ptr<BouncingShapeDynamics>
	//	dynamics(new BouncingShapeDynamics(x, y, rect, constr, PI / 6, speed,
	//		shape, dw));
	//shared_ptr<Shape>
	//	circle(new Circle(rect, dynamics, pen, brush));
	//shapesWidget->addShape(circle);
}


SonarModel::~SonarModel()
{
}
