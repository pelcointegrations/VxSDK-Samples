#pragma once
#include "DataSource.h"
#include "NewExport.h"
#include "Situation.h"

namespace CPPConsole {

    /// <summary>
    /// A wrapper class to VxSDK VxSystem
    /// </summary>
    class System {
        public:

            /// <summary>
            /// Constructor
            /// </summary>
            System();

            /// <summary>
            /// Destructor
            /// </summary>
            ~System();

            /// <summary>
            /// Initialize the VxSDK
            /// </summary>
            bool InitializeSdk();

            /// <summary>
            /// Login to system with the given ip, username and password
            /// </summary>
            /// <param name="ip">IP of Vx System </param>
            /// <param name="port"/>Port number where serenity runs (normally 443)</param>
            /// <param name="user">username </param>
            /// <param name="passwd"/> password</param>
            bool Login(const char* ip, int port, const char* user, const char* passwd);

            /// <summary>
            /// Get the datasources associated with this system instance.
            /// Destructor method will deallocate the datasource list allocated here
            /// </summary>
            std::list<DataSource*>* GetDataSources();

            /// <summary>
            /// Get datasources using pagination query
            /// Caller should deallocate the datasource list once done
            /// </summary>
            /// <param name="pageIndex">From datasource</param>
            /// <param name="count"/>number of items to be fetched</param>
            /// <param name="totalItems">totalItems available in server (will be filled in by this method)</param>
            std::list<DataSource*>* GetDataSources(int pageIndex, int count, int& totalItems);

            /// <summary>
            /// Creates a new export in server
            /// </summary>
            /// <param name="newExport">Contains details of export</param>
            Export* CreateExport(NewExport* newExport);

            /// <summary>
            /// Deletes an export from server
            /// </summary>
            /// <param name="exportToDelete">Contains details of export to delete</param>
            bool DeleteExport(Export* exportToDelete);

            /// <summary>
            /// Get all the exports available in this system
            /// Caller should dealloc export list
            /// </summary>
            std::list<Export*>* GetExports();

            /// <summary>
            /// Get the details of a particular export by passing its name and id
            /// </summary>
            /// <param name="expName">Name of export</param>
            /// <param name="id">Id of export</param>
            Export* GetExportDetails(const char* expName, const char* id);

            /// <summary>
            /// Get all the situations available in this system
            /// Caller should dealloc situation list
            /// </summary>
            std::list<Situation*>* GetSituations();
            
            /// <summary>
            /// Subscribe to system events by registering a callback
            /// </summary>
            /// <param name="callBack">This method will get invoked when an event is triggered in server</param>
            bool SubscribeSystemEvents(VxSdk::VxEventCallback callBack);
            
            /// <summary>
            /// UnSubscribe to system events
            /// </summary>
            bool UnSubscribeSystemEvents();

            /// <summary>
            /// Insert a new event in server.
            /// </summary>
            /// <param name="situation">Situation to which event occured</param>
            /// <param name="genDeviceId">Generator device Id</param>
            /// <param name="srcDeviceId">Source device Id</param>
            /// <param name="eventTime">Event time</param>
            bool InjectNewEvent(Situation* situation, std::string genDeviceId, std::string srcDeviceId, std::string eventTime);

            /// <summary>
            /// Add a new situation in server
            /// </summary>
            /// <param name="name">Name of situation</param>
            /// <param name="type">Type of situation</param>
            bool AddNewSituation(const char* name, const char* type);

            /// <summary>
            /// Delete a situation
            /// </summary>
            /// <param name="situationToDelete">Situation instance to delete</param>
            bool DeleteSituation(Situation* situationToDelete);

        private:
            ///pointer to VxSDK system
            VxSdk::IVxSystem* _system;

            ///List holding datasource list
            std::list<DataSource*>* _dataSourceList;
    };
}
