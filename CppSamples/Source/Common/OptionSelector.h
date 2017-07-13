#pragma once

#include "Plugin.h"
#include "Utility.h"
#include <vector>
#ifdef WIN32
#include <conio.h>
#else
#include <curses.h>
#endif

namespace CppSamples {
    namespace Common {
        /// <summary>
        /// This helper class prints a collection of options and chose a user defined option.
        /// </summary>
        template <class T>
        class OptionSelector {
        public:
            OptionSelector();
            ~OptionSelector() { }

            /// <summary>
            /// The given name and item will be added to the collection.
            /// </summary>
            /// <param name="name">String value of an option to be displayed.</param>
            /// <param name="item">The item to be added to the collection.</param>
            void AddItem(std::string name, T item);

            /// <summary>
            /// Prints a collection of options and chose a user defined one.
            /// </summary>
            /// <param name="result">The selected item will be assigned to this pointer.</param>
            /// <returns>True if user selects a valid option. False otherwise.</returns>
            bool SelectOption(T* result);

            bool ClearScreenAlways; // Clear the screen before printing the options. [Default false].
            std::string Heading; // Heading of the menu
            bool ShowHeaderFooter; // Specify whether to show extra decorations at header and footer. [Default false].
            std::string OptionSeperator; // The seperator between two options
            bool RepeatInput; // Specifies whether to repeat printing of menu untill get a valid input. [Default false].

        private:
            std::vector<std::string> _names; // A collection of names.
            std::vector<T> _items; // A collection of items.
        };

        template <class T>
        OptionSelector<T>::OptionSelector() {
            ClearScreenAlways = false;
            Heading = "";
            ShowHeaderFooter = false;
            OptionSeperator = "\n\t";
            RepeatInput = false;
        }

        /// <summary>
        /// The given name and item will be added to the collection.
        /// </summary>
        /// <param name="name">String value of an option to be displayed.</param>
        /// <param name="item">The item to be added to the collection.</param>
        template <class T>
        void OptionSelector<T>::AddItem(std::string name, T item) {
            _names.push_back(name);
            _items.push_back(item);
        }

        /// <summary>
        /// Prints a collection of options and chose a user defined one.
        /// </summary>
        /// <param name="result">The selected item will be assigned to this pointer.</param>
        /// <returns>True if user selects a valid option. False otherwise.</returns>
        template <class T>
        bool OptionSelector<T>::SelectOption(T* result) {

            bool isInvalidOption = false;
            while (true) {
                if (ClearScreenAlways)
                    Utility::ClearScreen();

                if (ShowHeaderFooter)
                    std::cout << "========================================================" << "\n\t";
                std::cout << Heading;
                if (ShowHeaderFooter)
                    std::cout << "\n" << "========================================================";

                int index = 0;
                int size = _names.size();
                for (; index < size; index++)
                    std::cout << OptionSeperator << (index + 1) << ". " << _names[index];

                if (ShowHeaderFooter)
                    std::cout << "\n========================================================";

                if (isInvalidOption) {
                    std::cout << "\n" << "Invalid option!!!";
                    isInvalidOption = false;
                }

                std::cout << "\n" << "Select your option [1-" << index << "] : ";
                int option = Utility::ReadInt();
                if (option > 0 && option <= index) {
                    *result = _items[option - 1];
                    return true;
                }

                if (!RepeatInput)
                    break;

                isInvalidOption = true;
            }

            return false;
        }
    }
}
