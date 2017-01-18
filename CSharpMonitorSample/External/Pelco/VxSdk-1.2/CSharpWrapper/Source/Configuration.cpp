/// <summary>
/// Implements the configuration class.
/// </summary>
#include "Configuration.h"

using namespace System::Collections::Generic;

CPPCli::Configuration::Time::Time(VxSdk::IVxConfiguration::Time* vxConfigTime) {
    _configTime = vxConfigTime;
}

CPPCli::Configuration::Time::!Time() {
    _configTime->Delete();
    _configTime = nullptr;
}

CPPCli::Results::Value CPPCli::Configuration::Time::Refresh() {
    return (CPPCli::Results::Value)_configTime->Refresh();
}

CPPCli::Configuration::Node::Node(VxSdk::IVxConfiguration::Node* vxConfigNode) {
    _configNode = vxConfigNode;
}

CPPCli::Configuration::Node::!Node() {
    _configNode->Delete();
    _configNode = nullptr;
}

CPPCli::Results::Value CPPCli::Configuration::Node::Refresh() {
    return (CPPCli::Results::Value)_configNode->Refresh();
}

CPPCli::Configuration::Cluster::Cluster(VxSdk::IVxConfiguration::Cluster* vxConfigCluster) {
    _configCluster = vxConfigCluster;
}

CPPCli::Configuration::Cluster::!Cluster() {
    _configCluster->Delete();
    _configCluster = nullptr;
}

CPPCli::Results::Value CPPCli::Configuration::Cluster::Refresh() {
    return (CPPCli::Results::Value)_configCluster->Refresh();
}

System::Collections::Generic::List<CPPCli::Configuration::Node^>^ CPPCli::Configuration::Cluster::_GetNodeConfigurations() {
    // Create a list of managed node objects
    List<Node^>^ mlist = gcnew List<Node^>();
    // Create a collection of unmanaged node objects
    VxSdk::VxCollection<VxSdk::IVxConfiguration::Node**> nodes;

    // Make the GetNodeConfigurations call, which will return with the total count of nodes, this allows the client to allocate memory.
    VxSdk::VxResult::Value result = _configCluster->GetNodeConfigurations(nodes);
    // Unless there are no nodes on the system, this should return VxSdk::VxResult::kInsufficientSize
    if (result == VxSdk::VxResult::kInsufficientSize) {
        // An array of pointers is allocated using the size returned by the previous GetNodeConfigurations call
        nodes.collection = new VxSdk::IVxConfiguration::Node*[nodes.collectionSize];
        result = _configCluster->GetNodeConfigurations(nodes);
        // The result should now be kOK since we have allocated enough space
        if (result == VxSdk::VxResult::kOK) {
            for (int i = 0; i < nodes.collectionSize; i++)
                mlist->Add(gcnew CPPCli::Configuration::Node(nodes.collection[i]));
        }
        // Remove the memory we previously allocated to the collection
        delete[] nodes.collection;
    }
    return mlist;
}

CPPCli::Configuration::Time^ CPPCli::Configuration::Cluster::_GetTimeConfig() {
    // Get the time config for the cluster
    VxSdk::IVxConfiguration::Time* time = nullptr;
    VxSdk::VxResult::Value result = _configCluster->GetTimeConfig(time);

    // Return the time config if GetTimeConfig was successful
    if (result == VxSdk::VxResult::kOK)
        return gcnew CPPCli::Configuration::Time(time);

    return nullptr;
}

CPPCli::Configuration::Storage::Storage(VxSdk::IVxConfiguration::Storage* vxConfigStorage) {
    _configStorage = vxConfigStorage;
}

CPPCli::Configuration::Storage::!Storage() {
    _configStorage->Delete();
    _configStorage = nullptr;
}

CPPCli::Results::Value CPPCli::Configuration::Storage::Refresh() {
    return (CPPCli::Results::Value)_configStorage->Refresh();
}
