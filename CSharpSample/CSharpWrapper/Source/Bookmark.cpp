/// <summary>
/// Implements the bookmark class.
/// </summary>
#include "Bookmark.h"

using namespace System::Collections::Generic;

CPPCli::Bookmark::Bookmark(VxSdk::IVxBookmark* vxBookmark) {
    _bookmark = vxBookmark;
}

CPPCli::Bookmark::!Bookmark() {
    _bookmark->Delete();
    _bookmark = nullptr;
}

CPPCli::DataSource^ CPPCli::Bookmark::_GetDataSource() {
    // Get the data source
    VxSdk::IVxDataSource* dataSource = nullptr;
    VxSdk::VxResult::Value result = _bookmark->GetDataSource(dataSource);

    // Return the data source if GetDataSource was successful
    if (result == VxSdk::VxResult::kOK)
        return gcnew CPPCli::DataSource(dataSource);

    return nullptr;
}
