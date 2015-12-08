#pragma once
#include "NewExportClip.h"
#include <vector>

namespace CPPConsole {

    /// <summary>
    /// Wrapper class for VxSDK VxNewExport
    /// </summary>
    class NewExport {
    public:

        /// <summary>
        /// Constructor - creates a new export
        /// </summary>
        NewExport() {
            _newExport = new VxSdk::VxNewExport();
            _clips = new std::vector<NewExportClip*>();
        }

        /// <summary>
        /// Returns the clips that are added to this new export
        /// </summary>
        std::vector<NewExportClip*>* GetClips() { return _clips; }

        /// <summary>
        /// Add a new clip to this export
        /// </summary>
        void AddClip(NewExportClip* clip) { _clips->push_back(clip); }

        /// <summary>
        /// Set a name for this export
        /// </summary>
        void SetExportName(const char* expName) {
            strncpy_s(_newExport->name, expName, sizeof(_newExport->name));
        }

        /// <summary>
        /// Set a password for this export
        /// </summary>
        void SetExportPassword(const char* expPasswd) {
            strncpy_s(_newExport->password, expPasswd, sizeof(_newExport->password));
        }

        /// <summary>
        /// Set a format for this export
        /// </summary>
        void SetExportFormat(Export::ExportFormat fmt) {
            _newExport->format = static_cast<VxSdk::VxExportFormat::Value>(fmt);
        }

        /// <summary>
        /// Get the format for this export
        /// </summary>
        Export::ExportFormat GetFormat() { return static_cast<Export::ExportFormat>(_newExport->format); }

        /// <summary>
        /// Get the name for this export
        /// </summary>
        const char* GetExportName() { return _newExport->name; }

        /// <summary>
        /// Returns export password
        /// </summary>
        const char* GetExportPassword() { return _newExport->password; }

        /// <summary>
        /// Destructor
        /// </summary>
        ~NewExport() {
            delete _newExport;
            delete _clips;
        }

    private:
        VxSdk::VxNewExport* _newExport;
        std::vector<NewExportClip*>* _clips;
    };
}
