#include "configuration.h"
#include "ui_configuration.h"
#include "DDSInQT.h"
extern DDSInQT *mainWindow;
extern DDS::DomainParticipant_var participant;
extern std::string partition;
#include <dds/DdsDcpsPublicationC.h>
#include <dds/DdsDcpsSubscriptionC.h>
#include<iostream>

using org::omg::dds::SonarSimu::SonarProtocol;
using org::omg::dds::SonarSimu::SonarProtocolTypeSupport_var;
using org::omg::dds::SonarSimu::SonarProtocolTypeSupportImpl;
using org::omg::dds::SonarSimu::SonarProtocolDataWriter;
using org::omg::dds::SonarSimu::SonarProtocolDataWriter_var;
using org::omg::dds::SonarSimu::SonarProtocolDataReader;
using org::omg::dds::SonarSimu::SonarProtocolDataReader_var;
Configuration::Configuration(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Configuration)
{
    ui->setupUi(this);
    if(!mainWindow->memberName.isEmpty())
    {
        ui->localName->setText(mainWindow->memberName);
    }
    if(!mainWindow->topicName.isEmpty())
    {
        ui->newTopicName->setText(mainWindow->topicName);
    }
}

Configuration::~Configuration()
{
    delete ui;
}

void Configuration::on_Refresh_clicked()
{


//    DDS::Subscriber_ptr builtinSubscriber = participant->get_builtin_subscriber();
//        DDS::DataReader_ptr   participantsDR =
//            builtinSubscriber->lookup_datareader("DCPSParticipant");

//    DDS::TopicQos topic_qos;
//        participant->get_default_topic_qos(topic_qos);
//        topic_qos.history.kind = DDS::KEEP_LAST_HISTORY_QOS;
//        topic_qos.history.depth = 100;

//    //	topic_qos.topic_data.value =
//        SonarProtocolTypeSupport_var ts =
//            new SonarProtocolTypeSupportImpl;

//        CORBA::String_var type_name = "sonarSimuPub";
//        if (ts->register_type(participant, type_name) != DDS::RETCODE_OK) {
//            //        std::cout << "Could not register type " << std::endl;
//        }
//    DDS::Topic_var simuTopic_;
//        simuTopic_ =
//            participant->create_topic("sonar",
//                type_name,
//                topic_qos,
//                0,
//                OpenDDS::DCPS::DEFAULT_STATUS_MASK);

    DDS::InstanceHandleSeq topicSeq;

    participant->get_discovered_topics(topicSeq);
    for (int i = 0; i < topicSeq.length(); i++)
    {
        DDS::InstanceHandle_t self;
        self = topicSeq[i];
        DDS::TopicBuiltinTopicData  topic_data;
        DDS::InstanceHandle_t topicHandle;
        participant->get_discovered_topic_data(topic_data, topicHandle);

    }
    DDS::InstanceHandleSeq seq;

    participant->get_discovered_participants(seq);
    while(ui->tableWidget->rowCount()>0)
    {
        ui->tableWidget->removeRow(0);
    }
    for (int i = 0; i < seq.length(); i++)
    {
        DDS::InstanceHandle_t ffd;
        ffd = seq[i];
        DDS::ParticipantBuiltinTopicData par;
        participant->get_discovered_participant_data(par, ffd);
        int df = par.user_data.value.length();
        QByteArray info;
        info.setRawData((char*)par.user_data.value.get_buffer(),df);
//            memcpy(info.data(),);
        QString wocao = info.data();

        QStringList ff = wocao.split("@");
        ui->tableWidget->insertRow(0);
        ui->tableWidget->setRowHeight(0,25);
        QTableWidgetItem *parti,*topic;
        parti = new QTableWidgetItem(ff.at(0));
        topic = new QTableWidgetItem(ff.at(1));
        ui->tableWidget->setItem(0,0,parti);
        ui->tableWidget->setItem(0,1,topic);
         df = 0;
    }
}

void Configuration::on_buttonBox_accepted()
{

}

void Configuration::on_JoinTopic_clicked()
{

    QStringList memberList;//名称+@+话题



    if(ui->tableWidget->currentRow()>=0)
    {
        int row = ui->tableWidget->currentRow();
        QString topic = ui->tableWidget->item(row,1)->text();
        for(int i=0;i<ui->tableWidget->rowCount();i++)
        {
            memberList.append(ui->tableWidget->item(i,0)->text()+"@"+ui->tableWidget->item(i,1)->text());
        }
        QString sig = ui->localName->text();
        if(sig.isEmpty())
        {
            ui->information->moveCursor(QTextCursor::End);
            ui->information->insertPlainText("本地成员不能为空\n");
            return;
        }
        if(memberList.indexOf(sig+"@"+topic)>=0)
        {
            ui->information->moveCursor(QTextCursor::End);
            ui->information->insertPlainText("本地成员不能与已知成员重名\n");
            return;
        }


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

        DDS::DomainParticipantQos dpq;

        sig = sig+"@"+topic;
        dpq.user_data.value.length(sig.length());
        memcpy(&dpq.user_data.value[0], sig.toStdString().data(), sig.length());

        participant->set_qos(dpq);
        mainWindow->simuTopic_ = NULL;
        mainWindow->simuTopic_ =
            participant->create_topic(topic.toStdString().data(),
                type_name,
                topic_qos,
                0,
                OpenDDS::DCPS::DEFAULT_STATUS_MASK);
        if (!mainWindow->simuTopic_) {
            ui->information->moveCursor(QTextCursor::End);
            ui->information->insertPlainText("加入话题"+ui->newTopicName->text()+"失败\n");


        }
        else
        {
            ui->information->moveCursor(QTextCursor::End);
            ui->information->insertPlainText("加入话题"+ui->newTopicName->text()+"成功，本地成员名称："+ui->localName->text()+"\n");
            mainWindow->memberName = ui->localName->text();
            mainWindow->topicName = topic;
        }

        //创建发布者
        DDS::PublisherQos pub_qos;
        participant->get_default_publisher_qos(pub_qos);
        if (!partition.empty()) {
            pub_qos.partition.name.length(1);
            pub_qos.partition.name[0] = partition.c_str();
        }
        // Create Publisher
        mainWindow->publisher_ =
            participant->create_publisher(pub_qos,
                0,
                OpenDDS::DCPS::DEFAULT_STATUS_MASK);


        if (!mainWindow->publisher_) {
            ui->information->moveCursor(QTextCursor::End);
            ui->information->insertPlainText("创建publisher失败\n");
        }
        else
        {
            ui->information->moveCursor(QTextCursor::End);
            ui->information->insertPlainText("创建publisher成功\n");
        }
        //创建写对象
        DDS::DataWriterQos qos_;
        mainWindow->publisher_->get_default_datawriter_qos(qos_);
        qos_.reliability.kind = DDS::BEST_EFFORT_RELIABILITY_QOS;
        qos_.user_data.value.length(100);

        memcpy(&qos_.user_data.value[0], sig.toStdString().data(), 11);


        mainWindow->writer_ =
            mainWindow->publisher_->create_datawriter(mainWindow->simuTopic_,
                qos_,
                0,
                OpenDDS::DCPS::DEFAULT_STATUS_MASK);

        if (!mainWindow->writer_ ) {
                     std::cerr << "Could not create data writer " << std::endl;
        }

        if (!mainWindow->writer_) {
            ui->information->moveCursor(QTextCursor::End);
            ui->information->insertPlainText("创建writer失败\n");
        }
        else
        {
            ui->information->moveCursor(QTextCursor::End);
            ui->information->insertPlainText("创建writer成功\n");
        }
        SonarProtocolDataWriter_var ffdf=SonarProtocolDataWriter::_narrow(mainWindow->writer_);
        mainWindow->dw = ffdf;






        DDS::SubscriberQos sub_qos;
            participant->get_default_subscriber_qos(sub_qos);
            if (!partition.empty()) {
                sub_qos.partition.name.length(1);
                sub_qos.partition.name[0] = partition.c_str();
            }

            // Create Subscriber
            mainWindow->subscriber_ =
                participant->create_subscriber(sub_qos,
                    0,
                    OpenDDS::DCPS::DEFAULT_STATUS_MASK);

            if (!mainWindow->subscriber_) {
                //        std::cerr << "Could not create subscriber " << std::endl;
                int i = 0;
            }

        SonarProtocolDataReader_var dr;

        DDS::DataReaderQos qos_2;
            mainWindow->subscriber_->get_default_datareader_qos(qos_2);

            qos_2.reliability.kind = DDS::BEST_EFFORT_RELIABILITY_QOS;
            DDS::TopicDescription_var topicDesc;
                        topicDesc = DDS::TopicDescription::_duplicate(mainWindow->simuTopic_.in());
            DDS::DataReader_var reader =
                mainWindow->subscriber_->create_datareader(topicDesc,
                    qos_2,
        //			readerQos_.get_qos(),
                    &mainWindow->listener_->ddsListener,//0,
                    OpenDDS::DCPS::DEFAULT_STATUS_MASK);

            if (!reader) {
                //std::cerr << "Could not create data reader " << std::endl;
                int i = 0;
            }

            dr =
                SonarProtocolDataReader::_narrow(reader);
            mainWindow->dr = dr;
    }
}

void Configuration::on_createTopic_clicked()
{
    if(ui->localName->text().isEmpty()||ui->newTopicName->text().isEmpty())
    {
        ui->information->moveCursor(QTextCursor::End);
        ui->information->insertPlainText("信息填写不全，无法创建新话题\n");
    }
    //创建会话
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
    QString sig = ui->localName->text();
    DDS::DomainParticipantQos dpq;

    sig = sig+"@"+ui->newTopicName->text();
    dpq.user_data.value.length(sig.length());
    memcpy(&dpq.user_data.value[0], sig.toStdString().data(), sig.length());

    participant->set_qos(dpq);
    mainWindow->simuTopic_ = NULL;
    mainWindow->simuTopic_ =
        participant->create_topic(ui->newTopicName->text().toStdString().data(),
            type_name,
            topic_qos,
            0,
            OpenDDS::DCPS::DEFAULT_STATUS_MASK);
    if (!mainWindow->simuTopic_) {
        ui->information->moveCursor(QTextCursor::End);
        ui->information->insertPlainText("创建话题"+ui->newTopicName->text()+"失败\n");

    }
    else
    {
        ui->information->moveCursor(QTextCursor::End);
        ui->information->insertPlainText("创建话题"+ui->newTopicName->text()+"成功，本地成员名称："+ui->localName->text()+"\n");
        mainWindow->memberName = ui->localName->text();
        mainWindow->topicName = ui->newTopicName->text();
    }

    //创建发布者
    DDS::PublisherQos pub_qos;
    participant->get_default_publisher_qos(pub_qos);
    if (!partition.empty()) {
        pub_qos.partition.name.length(1);
        pub_qos.partition.name[0] = partition.c_str();
    }
    // Create Publisher
    mainWindow->publisher_ =
        participant->create_publisher(pub_qos,
            0,
            OpenDDS::DCPS::DEFAULT_STATUS_MASK);


    if (!mainWindow->publisher_) {
        ui->information->moveCursor(QTextCursor::End);
        ui->information->insertPlainText("创建publisher失败\n");
    }
    else
    {
        ui->information->moveCursor(QTextCursor::End);
        ui->information->insertPlainText("创建publisher成功\n");
    }
    //创建写对象
    DDS::DataWriterQos qos_;
    mainWindow->publisher_->get_default_datawriter_qos(qos_);
    qos_.reliability.kind = DDS::BEST_EFFORT_RELIABILITY_QOS;
    qos_.user_data.value.length(100);

    memcpy(&qos_.user_data.value[0], sig.toStdString().data(), 11);


    mainWindow->writer_ =
        mainWindow->publisher_->create_datawriter(mainWindow->simuTopic_,
            qos_,
            0,
            OpenDDS::DCPS::DEFAULT_STATUS_MASK);

    if (!mainWindow->writer_ ) {
                 std::cerr << "Could not create data writer " << std::endl;
    }

    if (!mainWindow->writer_) {
        ui->information->moveCursor(QTextCursor::End);
        ui->information->insertPlainText("创建writer失败\n");
    }
    else
    {
        ui->information->moveCursor(QTextCursor::End);
        ui->information->insertPlainText("创建writer成功\n");
    }
    SonarProtocolDataWriter_var ffdf=SonarProtocolDataWriter::_narrow(mainWindow->writer_);
    mainWindow->dw = ffdf;




    DDS::SubscriberQos sub_qos;
        participant->get_default_subscriber_qos(sub_qos);
        if (!partition.empty()) {
            sub_qos.partition.name.length(1);
            sub_qos.partition.name[0] = partition.c_str();
        }

        // Create Subscriber
        mainWindow->subscriber_ =
            participant->create_subscriber(sub_qos,
                0,
                OpenDDS::DCPS::DEFAULT_STATUS_MASK);

        if (!mainWindow->subscriber_) {
            //        std::cerr << "Could not create subscriber " << std::endl;
            int i = 0;
        }

    SonarProtocolDataReader_var dr;

    DDS::DataReaderQos qos_2;
        mainWindow->subscriber_->get_default_datareader_qos(qos_2);

        qos_2.reliability.kind = DDS::BEST_EFFORT_RELIABILITY_QOS;
        DDS::TopicDescription_var topicDesc;
                    topicDesc = DDS::TopicDescription::_duplicate(mainWindow->simuTopic_.in());
        DDS::DataReader_var reader =
            mainWindow->subscriber_->create_datareader(topicDesc,
                qos_2,
    //			readerQos_.get_qos(),
                &mainWindow->listener_->ddsListener,//0,
                OpenDDS::DCPS::DEFAULT_STATUS_MASK);

        if (!reader) {
            //std::cerr << "Could not create data reader " << std::endl;
            int i = 0;
        }

        dr =
            SonarProtocolDataReader::_narrow(reader);
        mainWindow->dr = dr;

}
