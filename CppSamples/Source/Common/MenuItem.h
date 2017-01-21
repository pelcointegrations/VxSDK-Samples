#pragma once

#include "Plugin.h"
#include <vector>

namespace CppSamples {
    namespace Common {

        /// <summary>
        /// MenuItem is a Plugin. It represents a menu.
        /// </summary>
        class MenuItem : public CppSamples::Common::Plugin {
        public:
            MenuItem(const std::string description) : CppSamples::Common::Plugin(description) { }
            ~MenuItem() { }

            /// <summary>
            /// Print all the sub menu under this menu and accept a user input to select submenu to continue.
            /// </summary>
            /// <param name="dataModel">Instance of data model.</param>
            CppSamples::Common::Plugin* Run(CppSamples::Common::DataModel* dataModel) override;

            /// <summary>
            /// A default Back menu will be added as submenu of this.
            /// </summary>
            void AddBackMenu();

            /// <summary>
            /// The given plugin item will be added as submenu of this.
            /// </summary>
            /// <param name="plugin">Instance of Plugin to be added.</param>
            void AddChild(Plugin* plugin);

            /// <summary>
            /// A default Exit menu will be added as submenu of this.
            /// </summary>
            void AddExitMenu();

        private:
            std::vector<Plugin*> _children; // A collection of Plugin represents submenu of this.
        };

        /// <summary>
        /// This class represents a default Back menu
        /// </summary>
        class BackMenu : public CppSamples::Common::Plugin {
        public:
            BackMenu() : Plugin("Back") { }
            ~BackMenu() {}

            /// <summary>
            /// Move the controller to parent menu.
            /// </summary>
            /// <param name="dataModel">Instance of data model.</param>
            /// <returns>Parent of the current menu.</returns>
            Plugin* Run(DataModel* dataModel) override {
                Plugin* parent = GetParent();
                if (parent == nullptr)
                    return nullptr;

                return parent->GetParent();
            }
        };

        /// <summary>
        /// This class represents a default Exit menu
        /// </summary>
        class ExitMenu : public CppSamples::Common::Plugin {
        public:
            ExitMenu() : Plugin("Exit") { }
            ~ExitMenu() {}

            /// <summary>
            /// Exit the application by returning a null reference.
            /// </summary>
            /// <param name="dataModel">Instance of data model.</param>
            /// <returns>Null reference to exit.</returns>
            Plugin* Run(DataModel* dataModel) override {
                return nullptr;
            }
        };
    }
}
