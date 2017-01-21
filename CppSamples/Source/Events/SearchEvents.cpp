#include "stdafx.h"
#include "SearchEvents.h"
#include "Utility.h"
#include <iomanip>

using namespace std;
using namespace VxSdk;
using namespace CppSamples::Common;

// Serachs for events in the current system. User defined filters are used for searching.
Plugin* CppSamples::Events::SearchEvents::Run(DataModel* dataModel) {

    DoSearchEvents(dataModel->VxSystem);

    // Pause for user input before going back to parent menu.
    system("pause");
    // Return reference of parent plugin to move back to parent menu.
    return GetParent();
}

// Serachs for events in the current system. User defined filters are used for searching.
void CppSamples::Events::SearchEvents::DoSearchEvents(IVxSystem* vxSystem) {

    // Read Start Time for search
    cout << "\n\n" << "Enter start time for event search (yyyy-mm-dd hh:mm:ss): ";
    struct tm strtTime = Utility::GetDateAndTimeFromUser();
    string startTimeInUTC = Utility::ConvertLocalTimetoUTC(strtTime);

    // End Time for search
    cout << "\n" << "Enter end time for event search (yyyy-mm-dd hh:mm:ss): ";
    struct tm endTime = Utility::GetDateAndTimeFromUser();
    string endTimeInUTC = Utility::ConvertLocalTimetoUTC(endTime);

    // Start Searching Events
    system("cls");
    cout << "Fetching events from " << startTimeInUTC << " to " << endTimeInUTC << " (UTC).";
    cout << "\n\n";
    VxCollection<IVxEvent**> events = Search(vxSystem, startTimeInUTC, endTimeInUTC);
    if (events.collectionSize > 0) {
        if (events.collectionSize < 500) {
            // Print Events
            PrintEventHeadings();
            for (int i = 0; i < events.collectionSize; i++)
                PrintEventRow(events.collection[i]);
        }

        // Remove the memory allocated to the collection.
        delete[] events.collection;
    }

    cout << "\n";
}

// Search for events with the given parameters.
VxCollection<IVxEvent**> CppSamples::Events::SearchEvents::Search(IVxSystem* vxSystem, string startTime, string endTime) {

    // Create new collection of events to search
    VxCollection<IVxEvent**> events;
    events.filterSize = 2;
    VxCollectionFilter filters[2];
    filters[0].key = VxCollectionFilterItem::kSearchStartTime;
    filters[1].key = VxCollectionFilterItem::kSearchEndTime;
    Utilities::StrCopySafe(filters[0].value, startTime.c_str());
    Utilities::StrCopySafe(filters[1].value, endTime.c_str());
    events.filters = filters;

    // Read the size of collection from system.
    VxResult::Value result = vxSystem->GetEvents(events);
    if (result == VxResult::kInsufficientSize) {
        if (events.collectionSize < 500) {
            // Allocate memory for the requried collection.
            events.collection = new IVxEvent*[events.collectionSize];
            // Read the collection from system.
            vxSystem->GetEvents(events);
        }
        else
            cout << "Found " << events.collectionSize << " events. There are too many to display, please narrow your search.";
    }

    return events;
}

/// <summary>
/// Display a row of event details
/// </summary>
/// <param name="vxEvent">CPPConsole::Event pointer containing the event to display</param>
void CppSamples::Events::SearchEvents::PrintEventRow(IVxEvent* vxEvent) {
    const int eventTimeWidth = 20;
    const int eventStringWidth = 32;
    cout << left << setw(eventTimeWidth) << setfill(' ') << SearchEvents::CovertUTCTimeFormatToString(vxEvent->time);
    cout << left << setw(eventStringWidth) << setfill(' ') << vxEvent->situationType;
    cout << left << setw(eventStringWidth) << setfill(' ') << vxEvent->sourceDeviceId;
    cout << "\n";
}

/// <summary>
/// Display the headings for a table of events
/// </summary>
void CppSamples::Events::SearchEvents::PrintEventHeadings() {
    const int eventTimeWidth = 20;
    const int eventStringWidth = 32;
    cout << "\n--------------------------------------------------\n";
    cout << left << setw(eventTimeWidth) << setfill(' ') << "Time(UTC)";
    cout << left << setw(eventStringWidth) << setfill(' ') << "Situation Type";
    cout << left << setw(eventStringWidth) << setfill(' ') << "Source Device";
    cout << "\n--------------------------------------------------\n";
}

/// <summary>
/// Converts the UTC time format to string format (HH:MM::SS, Day Month)
/// </summary>
/// <param name="utcFormat">time string in UTC format (YYYYmmddTHHMMSSZ)</param>
string CppSamples::Events::SearchEvents::CovertUTCTimeFormatToString(string utcFormat) {
    stringstream dateStream(utcFormat);
    struct tm parseTime;
    //Here parse date and time string value to time structure
    dateStream >> get_time(&parseTime, "%Y-%m-%dT%H:%M:%S");
    char buffer[18];
    strftime(buffer, 18, "%X %x", &parseTime);

    return string(buffer);
}
