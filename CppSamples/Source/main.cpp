// CppSamples.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Controller.h"
#include "Common/MenuItem.h"
#include "Common/Controller.h"

#include "DataSource/ViewAllDataSource.h"
#include "DataSource/ViewDataSourceByPage.h"
#include "DataSource/ViewDataSourceDetails.h"
#include "LiveStreaming/DataSourceLiveStreaming.h"

#include "Exports/ViewExport.h"
#include "Exports/CreateExport.h"
#include "Exports/DeleteExport.h"
#include "Exports/DownloadExport.h"
#include "Reports/ViewQuickReport.h"

#include "Events/MonitorEvents.h"
#include "Events/SearchEvents.h"
#include "Events/DisplaySituations.h"
#include "Events/AddSituation.h"
#include "Events/DeleteSituation.h"
#include "Events/InjectEvents.h"

#include "Bookmarks/ViewAllBookmarks.h"
#include "Bookmarks/AddBookmark.h"
#include "Bookmarks/DeleteBookmark.h"

#include "Roles/ViewAllRoles.h"
#include "Roles/AddRole.h"
#include "Roles/DeleteRole.h"

#include "Notifications/ViewAllNotifications.h"
#include "Notifications/AddNotification.h"
#include "Notifications/DeleteNotification.h"

#include "Tags/ViewAllTags.h"
#include "Tags/AddTag.h"
#include "Tags/DeleteTag.h"
#include "Tags/MergeTag.h"

#include "Users/ViewAllUsers.h"
#include "Users/AddUser.h"
#include "Users/DeleteUser.h"

#include "Schedules/ViewAllSchedules.h"
#include "Schedules/AddSchedule.h"
#include "Schedules/AddTriggerToSchedule.h"
#include "Schedules/DeleteSchedule.h"

#include "Drawings/ViewAllDrawings.h"
#include "Drawings/AddDrawing.h"
#include "Drawings/DeleteDrawing.h"

#include "DataObjects/ViewAllDataObjects.h"
#include "DataObjects/AddDataObject.h"
#include "DataObjects/DeleteDataObject.h"

#include "Devices/ViewAllDevices.h"

using namespace std;
using namespace CppSamples::Common;

MenuItem* CreateMenuStructure();

int _tmain() {

    // Create menu structure of the application.
    MenuItem* rootMenu = CreateMenuStructure();
    // Create new instance of Controller.
    Controller controller(rootMenu);
    // Start the controller
    controller.Run();
    return 0;
}

// Add a sub menu to the given menu
void AddSubMenu(MenuItem* menu, MenuItem* subMenu) {
    // Add default back menu at the end
    subMenu->AddBackMenu();
    // Add the given sub menu to the menu
    menu->AddChild(subMenu);
}

// This method creates a menu structure of this application and
// return the reference to the root menu.
MenuItem* CreateMenuStructure() {
    // Create new instance of Root menu.
    MenuItem* rootMenu = new MenuItem("Main Menu");
    
    // Data Sources
    // ------------
    MenuItem* dataSourceMenu = new MenuItem("DataSources");
    dataSourceMenu->AddChild(new CppSamples::DataSource::ViewAllDataSource("View all DataSources"));
    dataSourceMenu->AddChild(new CppSamples::DataSource::ViewDataSourceByPage("View DataSources page by page"));
    dataSourceMenu->AddChild(new CppSamples::DataSource::ViewDataSourceDetails("View DataSource details"));
    dataSourceMenu->AddChild(new CppSamples::LiveStreaming::DataSourceLiveStreaming("Live Streaming", false));
    dataSourceMenu->AddChild(new CppSamples::LiveStreaming::DataSourceLiveStreaming("Playback", true));
    AddSubMenu(rootMenu, dataSourceMenu);

    // Export
    // ------
    MenuItem* exportMenu = new MenuItem("Export");
    exportMenu->AddChild(new CppSamples::Exports::ViewExport("View Exports"));
    exportMenu->AddChild(new CppSamples::Exports::CreateExport("Create New Export"));
    exportMenu->AddChild(new CppSamples::Exports::DeleteExport("Delete Export"));
    exportMenu->AddChild(new CppSamples::Exports::DownloadExport("Download Export"));
    exportMenu->AddChild(new CppSamples::Reports::ViewQuickReport("View Quick Report"));
    AddSubMenu(rootMenu, exportMenu);

    // Events
    // ------
    MenuItem* eventsMenu = new MenuItem("Events");
    eventsMenu->AddChild(new CppSamples::Events::MonitorEvents("Monitor Events"));
    eventsMenu->AddChild(new CppSamples::Events::SearchEvents("Search Events"));
    eventsMenu->AddChild(new CppSamples::Events::DisplaySituations("View Situations"));
    eventsMenu->AddChild(new CppSamples::Events::AddSituation("Add New Situation"));
    eventsMenu->AddChild(new CppSamples::Events::DeleteSituation("Delete Situation"));
    eventsMenu->AddChild(new CppSamples::Events::InjectEvents("Inject Events"));
    AddSubMenu(rootMenu, eventsMenu);

    // Bookmarks
    // ---------
    MenuItem* bookmarksMenu = new MenuItem("Bookmarks");
    bookmarksMenu->AddChild(new CppSamples::Bookmarks::ViewAllBookmarks("View All Bookmarks"));
    bookmarksMenu->AddChild(new CppSamples::Bookmarks::AddBookmark("Add Bookmark"));
    bookmarksMenu->AddChild(new CppSamples::Bookmarks::DeleteBookmark("Delete Bookmark"));
    AddSubMenu(rootMenu, bookmarksMenu);

    // Roles
    // -----
    MenuItem* rolesMenu = new MenuItem("Roles");
    rolesMenu->AddChild(new CppSamples::Roles::ViewAllRoles("View All Roles"));
    rolesMenu->AddChild(new CppSamples::Roles::AddRole("Add Role"));
    rolesMenu->AddChild(new CppSamples::Roles::DeleteRole("Delete Role"));
    AddSubMenu(rootMenu, rolesMenu);

    // Notifications
    // -------------
    MenuItem* notificationsMenu = new MenuItem("Notifications");
    notificationsMenu->AddChild(new CppSamples::Notifications::ViewAllNotifications("View All Notifications"));
    notificationsMenu->AddChild(new CppSamples::Notifications::AddNotification("Add Notification"));
    notificationsMenu->AddChild(new CppSamples::Notifications::DeleteNotification("Delete Notification"));
    AddSubMenu(rootMenu, notificationsMenu);

    // Tags
    // ----
    MenuItem* tagsMenu = new MenuItem("Tags");
    tagsMenu->AddChild(new CppSamples::Tags::ViewAllTags("View All Tags"));
    tagsMenu->AddChild(new CppSamples::Tags::AddTag("Add Tag"));
    tagsMenu->AddChild(new CppSamples::Tags::DeleteTag("Delete Tag"));
    tagsMenu->AddChild(new CppSamples::Tags::MergeTag("Merge Two Tags"));
    AddSubMenu(rootMenu, tagsMenu);

    // Users
    // -----
    MenuItem* usersMenu = new MenuItem("Users");
    usersMenu->AddChild(new CppSamples::Users::ViewAllUsers("View All Users"));
    usersMenu->AddChild(new CppSamples::Users::AddUser("Add User"));
    usersMenu->AddChild(new CppSamples::Users::DeleteUser("Delete User"));
    AddSubMenu(rootMenu, usersMenu);

    // Schedules
    // ---------
    MenuItem* schedulesMenu = new MenuItem("Schedules");
    schedulesMenu->AddChild(new CppSamples::Schedules::ViewAllSchedules("View All Schedules"));
    schedulesMenu->AddChild(new CppSamples::Schedules::AddSchedule("Add Schedule"));
    schedulesMenu->AddChild(new CppSamples::Schedules::AddTriggerToSchedule("Add Trigger to Schedule"));
    schedulesMenu->AddChild(new CppSamples::Schedules::DeleteSchedule("Delete Schedule"));
    AddSubMenu(rootMenu, schedulesMenu);

    // Drawings
    // --------
    MenuItem* drawingsMenu = new MenuItem("Drawings");
    drawingsMenu->AddChild(new CppSamples::Drawings::ViewAllDrawings("View All Drawings"));
    drawingsMenu->AddChild(new CppSamples::Drawings::AddDrawing("Add Drawing"));
    drawingsMenu->AddChild(new CppSamples::Drawings::DeleteDrawing("Delete Drawing"));
    AddSubMenu(rootMenu, drawingsMenu);

    // Data Objects
    // ------------
    MenuItem* dataObjectsMenu = new MenuItem("Data Objects");
    dataObjectsMenu->AddChild(new CppSamples::DataObjects::ViewAllDataObjects("View All DataObjects"));
    dataObjectsMenu->AddChild(new CppSamples::DataObjects::AddDataObject("Add DataObject"));
    dataObjectsMenu->AddChild(new CppSamples::DataObjects::DeleteDataObject("Delete DataObject"));
    AddSubMenu(rootMenu, dataObjectsMenu);

    // Devices
    // -------
    MenuItem* devicesMenu = new MenuItem("Devices");
    devicesMenu->AddChild(new CppSamples::Devices::ViewAllDevices("View All Devices"));
    AddSubMenu(rootMenu, devicesMenu);

    // Exit menu
    rootMenu->AddExitMenu();
    return rootMenu;
}
