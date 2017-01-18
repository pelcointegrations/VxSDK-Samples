// Declares the configuration class.
#ifndef Configuration_h__
#define Configuration_h__

#include "VxSdk.h"
#include "Utils.h"

namespace CPPCli {

    /// <summary>
    /// The Configuration class represents a device configuration.
    /// </summary>
    public ref class Configuration {
    public:

        /// <summary>
        /// Values that represent the current cluster configuration status.
        /// </summary>
        enum class ConfigStatus {
            /// <summary>An error or unknown value was returned.</summary>
            Unknown,
            /// <summary>The cluster is configured.</summary>
            Configured,
            /// <summary>The cluster is being configured.</summary>
            Configuring,
            /// <summary>Cluster configuration failed.</summary>
            Failed,
            /// <summary>The cluster is unconfigured.</summary>
            Unconfigured
        };

        /// <summary>
        /// The Time class represents a time configuration.
        /// </summary>
        ref class Time {
        public:

            /// <summary>
            /// Constructor.
            /// </summary>
            /// <param name="vxConfigTime">The vx time configuration.</param>
            Time(VxSdk::IVxConfiguration::Time* vxConfigTime);

            /// <summary>
            /// Destructor.
            /// </summary>
            virtual ~Time() {
                this->!Time();
            }

            /// <summary>
            /// Finaliser.
            /// </summary>
            !Time();

            /// <summary>
            /// Refreshes this instances properties.
            /// </summary>
            /// <returns>The <see cref="Results::Value">Result</see> of updating the properties.</returns>
            Results::Value Refresh();

            /// <summary>
            /// Gets a value indicating whether or not the external time server is enabled.
            /// </summary>
            /// <value><c>true</c> if the external time server is enabled, <c>false</c> if disabled.</value>
            property bool IsTimeServerEnabled {
            public:
                bool get() { return _configTime->isTimeServerEnabled; }
            }

            /// <summary>
            /// Gets the current internal system time.
            /// </summary>
            /// <value>The current internal system time.</value>
            property System::DateTime CurrentTime {
            public:
                System::DateTime get() {
                    char time[64];
                    _configTime->GetTime(time);
                    return Utils::ConvertCharToDateTime(time);
                }
            }

            /// <summary>
            /// Gets the host address of the external time server.
            /// </summary>
            /// <value>The external time server host address.</value>
            property System::String^ TimeServerAddress {
            public:
                System::String^ get() { return gcnew System::String(_configTime->timeServerAddress); }
            }

        internal:
            VxSdk::IVxConfiguration::Time* _configTime;
        };

        /// <summary>
        /// The Node class represents an individual host machine (a "node") within a cluster.
        /// </summary>
        ref class Node {
        public:

            /// <summary>
            /// Constructor.
            /// </summary>
            /// <param name="vxConfigNode">The vx node configuration.</param>
            Node(VxSdk::IVxConfiguration::Node* vxConfigNode);

            /// <summary>
            /// Destructor.
            /// </summary>
            virtual ~Node() {
                this->!Node();
            }

            /// <summary>
            /// Finaliser.
            /// </summary>
            !Node();

            /// <summary>
            /// Refreshes this instances properties.
            /// </summary>
            /// <returns>The <see cref="Results::Value">Result</see> of updating the properties.</returns>
            Results::Value Refresh();

            /// <summary>
            /// Gets the host address.
            /// </summary>
            /// <value>The host address.</value>
            property System::String^ HostAddress {
            public:
                System::String^ get() { return gcnew System::String(_configNode->hostAddress); }
            }

            /// <summary>
            /// Gets the current configuration status of this node.
            /// </summary>
            /// <value>The configuration status.</value>
            property ConfigStatus Status {
            public:
                ConfigStatus get() { return (ConfigStatus)_configNode->status; }
            }

        internal:
            VxSdk::IVxConfiguration::Node* _configNode;
        };

        /// <summary>
        /// The Cluster class represents cluster configuration attributes. This representation shall
        /// be identical within a cluster, regardless of the node it was retrieved from.
        /// </summary>
        ref class Cluster {
        public:

            /// <summary>
            /// Constructor.
            /// </summary>
            /// <param name="vxConfigCluster">The vx cluster configuration.</param>
            Cluster(VxSdk::IVxConfiguration::Cluster* vxConfigCluster);

            /// <summary>
            /// Destructor.
            /// </summary>
            virtual ~Cluster() {
                this->!Cluster();
            }

            /// <summary>
            /// Finaliser.
            /// </summary>
            !Cluster();

            /// <summary>
            /// Refreshes this instances properties.
            /// </summary>
            /// <returns>The <see cref="Results::Value">Result</see> of updating the properties.</returns>
            Results::Value Refresh();

            /// <summary>
            /// Gets the configuration for the nodes that the cluster is composed of.
            /// </summary>
            /// <value>A <c>List</c> of node configurations.</value>
            property System::Collections::Generic::List<Node^>^ NodeConfigurations {
            public:
                System::Collections::Generic::List<Node^>^ get() { return _GetNodeConfigurations(); }
            }

            /// <summary>
            /// Gets the time configuration for the cluster.
            /// </summary>
            /// <value>The time configuration.</value>
            property Time^ TimeConfig {
            public:
                Time^ get() { return _GetTimeConfig(); }
            }

            /// <summary>
            /// Gets virtual IP or hostname used for VideoXpert Core devices.
            /// </summary>
            /// <value>The VxCore virtual IP.</value>
            property System::String^ CoreVirtualIp {
            public:
                System::String^ get() { return gcnew System::String(_configCluster->coreVirtualIp); }
            }

            /// <summary>
            /// Gets the default communication method between data sources to Media Gateways and
            /// between Media Gateways to clients.
            /// </summary>
            /// <value>The communication method.</value>
            property System::String^ MediaGatewayTranscast {
            public:
                System::String^ get() { return gcnew System::String(_configCluster->mediaGatewayTranscast); }
            }

            /// <summary>
            /// Gets the virtual IP or hostname used for Media Gateway devices.
            /// </summary>
            /// <value>The Media Gateway virtual IP.</value>
            property System::String^ MediaGatewayVirtualIp {
            public:
                System::String^ get() { return gcnew System::String(_configCluster->mediaGatewayVirtualIp); }
            }

            /// <summary>
            /// Gets the current configuration status description.
            /// </summary>
            /// <value>The status description.</value>
            property System::String^ StatusDescription {
            public:
                System::String^ get() { return gcnew System::String(_configCluster->statusDescription); }
            }

            /// <summary>
            /// Gets the current configuration status code.
            /// </summary>
            /// <value>The status code.</value>
            property int StatusCode {
            public:
                int get() { return _configCluster->statusCode; }
            }

            /// <summary>
            /// Gets the current configuration status of the entire cluster.
            /// </summary>
            /// <value>The configuration status.</value>
            property ConfigStatus Status {
            public:
                ConfigStatus get() { return (ConfigStatus)_configCluster->status; }
            }

        internal:
            VxSdk::IVxConfiguration::Cluster* _configCluster;
            System::Collections::Generic::List<Node^>^ _GetNodeConfigurations();
            Time^ _GetTimeConfig();
        };

        /// <summary>
        /// The Configuration class represents a VxStorage-specific configuration.
        /// </summary>
        ref class Storage {
        public:

            /// <summary>
            /// Constructor.
            /// </summary>
            /// <param name="vxConfigStorage">The vx storage configuration.</param>
            Storage(VxSdk::IVxConfiguration::Storage* vxConfigStorage);

            /// <summary>
            /// Destructor.
            /// </summary>
            virtual ~Storage() {
                this->!Storage();
            }

            /// <summary>
            /// Finaliser.
            /// </summary>
            !Storage();

            /// <summary>
            /// Refreshes this instances properties.
            /// </summary>
            /// <returns>The <see cref="Results::Value">Result</see> of updating the properties.</returns>
            Results::Value Refresh();

            /// <summary>
            /// Gets the retention limit, in hours, on recorded data.
            /// </summary>
            /// <value>The retention limit.</value>
            property int RetentionLimit {
            public:
                int get() { return _configStorage->retentionLimit; }
            }

            /// <summary>
            /// Gets the network communication transmission type preference.
            /// </summary>
            /// <value>The transmission type.</value>
            property System::String^ TransmissionType {
            public:
                System::String^ get() { return gcnew System::String(_configStorage->transmissionType); }
            }

        internal:
            VxSdk::IVxConfiguration::Storage* _configStorage;
        };

        internal:
            Configuration() { };
    };
}
#endif // Configuration_h__
