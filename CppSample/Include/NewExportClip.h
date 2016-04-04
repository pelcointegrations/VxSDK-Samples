#include "Export.h"
#include "string.h"

namespace CPPConsole {

    /// <summary>
    /// Wrapper class for VxSDK VxNewExportClip
    /// </summary>
    class NewExportClip {
    public:

        /// <summary>
        /// Constructor - creates a new export clip
        /// </summary>
        NewExportClip() { _newExportClip = new VxSdk::VxNewExportClip(); }

        /// <summary>
        /// Constructor - copies the VxSDK new export clip pointer
        /// </summary>
        /// <param name="newExportClip">The new export clip pointer</param>
        NewExportClip(VxSdk::VxNewExportClip* newExportClip) { _newExportClip = newExportClip; }

        /// <summary>
        /// Returns the id of exported clip's datasource
        /// </summary>
        const char* GetDataSourceId() { return _newExportClip->dataSourceId; }

        /// <summary>
        /// Returns the start time of export clip
        /// </summary>
        const char* GetStartTime() { return _newExportClip->startTime; }

        /// <summary>
        /// Returns the end time of export clip
        /// </summary>
        const char* GetEndTime() { return _newExportClip->endTime; }

        /// <summary>
        /// Set the data source id for export clip
        /// </summary>
        void SetDataSourceId(const char* dataSourceId) {
            strncpy_s(_newExportClip->dataSourceId, dataSourceId, sizeof(_newExportClip->dataSourceId));
        }

        /// <summary>
        /// Set the start time for export clip
        /// </summary>
        void SetStartTime(const char* strtTime) {
            strncpy_s(_newExportClip->startTime, strtTime, sizeof(_newExportClip->startTime));
        }

        /// <summary>
        /// Set the end time for export clip
        /// </summary>
        void SetEndTime(const char* endTime) {
            strncpy_s(_newExportClip->endTime, endTime, sizeof(_newExportClip->endTime));
        }

        /// <summary>
        /// Destructor
        /// </summary>
        ~NewExportClip() { delete _newExportClip; }

    private:
        VxSdk::VxNewExportClip* _newExportClip;
    };
}