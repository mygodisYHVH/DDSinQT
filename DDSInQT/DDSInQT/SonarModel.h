#pragma once
#include "sonarProtoTypeSupportC.h"
#include <dds/DdsDcpsPublicationC.h>
#include <dds/DdsDcpsSubscriptionC.h>
class SonarModel
{
public:
	SonarModel(DDS::DomainParticipant_var participant,
		const std::string& partition);
	~SonarModel();

private:
	DDS::Topic_var             simuTopic_;
	DDS::DomainParticipant_var participant_;
	DDS::Publisher_var         publisher_;
	DDS::Subscriber_var        subscriber_;
};

