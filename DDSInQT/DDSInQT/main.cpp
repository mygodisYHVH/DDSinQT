#include "DDSInQT.h"
#include <QtWidgets/QApplication>
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <list>

#include <dds/DdsDcpsInfrastructureC.h>
#include <dds/DdsDcpsPublicationC.h>
#include <dds/DdsDcpsSubscriptionC.h>

#include <dds/DCPS/Marked_Default_Qos.h>
#include <dds/DCPS/Service_Participant.h>
#include <dds/DCPS/WaitSet.h>

#include <dds/DCPS/RTPS/RtpsDiscovery.h>
#include <dds/DCPS/transport/framework/TransportRegistry.h>

#include "dds/DCPS/StaticIncludes.h"
#ifdef ACE_AS_STATIC_LIBS
#include <dds/DCPS/transport/rtps_udp/RtpsUdp.h>
#endif

#include <dds/DCPS/transport/rtps_udp/RtpsUdpInst.h>
#include <dds/DCPS/transport/rtps_udp/RtpsUdpInst_rch.h>

#include <ace/Argv_Type_Converter.h>
#include "SonarModel.h"
DDSInQT *mainWindow;
DDS::DomainParticipant_var participant;
std::string partition;
using namespace OpenDDS::RTPS;
using namespace OpenDDS::DCPS;
int ACE_TMAIN(int argc, ACE_TCHAR *argv[])
{
	QApplication a(argc, argv);
	int retval = -1;
//	try {
		// Initialize DomainParticipantFactory
		DDS::DomainParticipantFactory_var dpf =
			TheParticipantFactoryWithArgs(argc, argv);

		TransportConfig_rch config =
			TransportRegistry::instance()->create_config("rtps_interop_demo");
		TransportInst_rch inst =
			TransportRegistry::instance()->create_inst("the_rtps_transport",
				"rtps_udp");
		RtpsUdpInst_rch rui = static_rchandle_cast<RtpsUdpInst>(inst);
		rui->handshake_timeout_ = 1;

		config->instances_.push_back(inst);
		TransportRegistry::instance()->global_config(config);

		DDS::DomainId_t domain = 0;
		bool multicast = true;
		unsigned int resend = 1;
        std::string  governance, permissions;
		int defaultSize = 0;

		int curr = 1;
		if (argc > 1 && argv[1][0] != ACE_TEXT('-')) {
			domain = ACE_OS::atoi(argv[1]);
			std::cout << "Connecting to domain: " << domain << std::endl;
			++curr;
		}

		RtpsDiscovery_rch disc = make_rch<RtpsDiscovery>("RtpsDiscovery");
		for (; curr < argc; ++curr) {
			if (ACE_OS::strcmp(ACE_TEXT("-u"), argv[curr]) == 0) {
				multicast = false;
				rui->use_multicast_ = false;
				std::cout << "SEDP / user topics on unicast only" << std::endl;
			}
			else if ((ACE_OS::strcmp(ACE_TEXT("-r"), argv[curr]) == 0) &&
				(curr + 1 < argc)) {
				resend = ACE_OS::atoi(argv[++curr]);
				std::cout << "Resend: " << resend << " sec" << std::endl;
			}
			else if ((ACE_OS::strcmp(ACE_TEXT("-pb"), argv[curr]) == 0) &&
				(curr + 1 < argc)) {
				const u_short temp = ACE_OS::atoi(argv[++curr]);
				std::cout << "pb: " << temp << std::endl;
				disc->pb(temp);
			}
			else if ((ACE_OS::strcmp(ACE_TEXT("-dg"), argv[curr]) == 0) &&
				(curr + 1 < argc)) {
				const u_short temp = ACE_OS::atoi(argv[++curr]);
				std::cout << "dg: " << temp << std::endl;
				disc->dg(temp);
			}
			else if ((ACE_OS::strcmp(ACE_TEXT("-pg"), argv[curr]) == 0) &&
				(curr + 1 < argc)) {
				const u_short temp = ACE_OS::atoi(argv[++curr]);
				std::cout << "pg: " << temp << std::endl;
				disc->pg(temp);
			}
			else if ((ACE_OS::strcmp(ACE_TEXT("-d0"), argv[curr]) == 0) &&
				(curr + 1 < argc)) {
				const u_short temp = ACE_OS::atoi(argv[++curr]);
				std::cout << "d0: " << temp << std::endl;
				disc->d0(temp);
			}
			else if ((ACE_OS::strcmp(ACE_TEXT("-d1"), argv[curr]) == 0) &&
				(curr + 1 < argc)) {
				const u_short temp = ACE_OS::atoi(argv[++curr]);
				std::cout << "d1: " << temp << std::endl;
				disc->d1(temp);
			}
			else if ((ACE_OS::strcmp(ACE_TEXT("-dx"), argv[curr]) == 0) &&
				(curr + 1 < argc)) {
				const u_short temp = ACE_OS::atoi(argv[++curr]);
				std::cout << "dx: " << temp << std::endl;
				disc->dx(temp);
			}
			else if ((ACE_OS::strcmp(ACE_TEXT("-partition"), argv[curr]) == 0) &&
				(curr + 1 < argc)) {
				partition = ACE_TEXT_ALWAYS_CHAR(argv[++curr]);
				std::cout << "Partition[0]: " << partition << std::endl;
			}
			else if ((ACE_OS::strcmp(ACE_TEXT("-defaultSize"), argv[curr]) == 0) &&
				(curr + 1 < argc)) {
				defaultSize = ACE_OS::atoi(argv[++curr]);
			}
			else if ((ACE_OS::strcmp(ACE_TEXT("-governance"), argv[curr]) == 0) &&
				(curr + 1 < argc)) {
				governance = ACE_TEXT_ALWAYS_CHAR(argv[++curr]);
			}
			else if ((ACE_OS::strcmp(ACE_TEXT("-permissions"), argv[curr]) == 0) &&
				(curr + 1 < argc)) {
				permissions = ACE_TEXT_ALWAYS_CHAR(argv[++curr]);
			}
			else {
				std::cout << "Ignoring unknown param: " <<
					ACE_TEXT_ALWAYS_CHAR(argv[curr]) << std::endl;
			}
		}

		disc->resend_period(ACE_Time_Value(resend));
		disc->sedp_multicast(multicast);
		TheServiceParticipant->add_discovery(static_rchandle_cast<Discovery>(disc));
		TheServiceParticipant->set_repo_domain(domain, disc->key());
		DDS::DomainParticipantQos dp_qos;
		dpf->get_default_participant_qos(dp_qos);
		// Create DomainParticipant
        participant= NULL;
         participant =
			dpf->create_participant(domain,
				dp_qos,
				0,
				DEFAULT_STATUS_MASK);

		if (!participant) {
			std::cerr << "Could not connect to domain " << std::endl;
			TheServiceParticipant->shutdown();
			return EXIT_FAILURE;
		}
	
		srand(clock());
		ACE_Argv_Type_Converter atc(argc, argv);

		//      Q_INIT_RESOURCE(ishape);
			  // create and show your widgets here
		//      ShapesDialog shapes(participant, partition, defaultSize);
		//SonarModel dlg(participant, partition);
        mainWindow = new DDSInQT(participant, partition);
        mainWindow->show();
#ifdef OPENDDS_SECURITY
		if (TheServiceParticipant->get_security()) {
			shapes.setWindowTitle("OpenDDS Security BETA");
	}
#endif



		// Clean-up!
		/*participant->delete_contained_entities();
		dpf->delete_participant(participant);
		TheServiceParticipant->shutdown();*/
//	}
//	catch (const CORBA::Exception& e) {
//		std::cerr << "Exception in main: " << e << std::endl;
//		retval = -1;
//	}
	
	
	return a.exec();
}
