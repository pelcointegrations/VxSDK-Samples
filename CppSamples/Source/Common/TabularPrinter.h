#pragma once

#include <vector>

namespace CppSamples {
    namespace Common {

        /// <summary>
        /// This class represents a column heading.
        /// </summary>
        class ColumnHeading {
        public:
            std::string Value; // Heading of the column.
            int Width; // Width of the column.
            int Alignment; // -1 for Left alignment. 0 for center. 1 for right alignment. [Default is Left Alignment].
        };

        /// <summary>
        /// This class represents a row of data in the table.
        /// </summary>
        class Row {
        public:
            std::vector<std::string> Values; // Collection of std::string values in the row.
        };

        /// <summary>
        /// This class helps to print a table data with alignment.
        /// </summary>
        class TabularPrinter {
        public:

            /// <summary>
            /// Create an instance of TabularPrinter class.
            /// </summary>
            TabularPrinter();

            ~TabularPrinter() { }

            /// <summary>
            /// Add a column to the table.
            /// </summary>
            /// <param name="heading">Heading of the column.</param>
            /// <param name="width">Width of the column.</param>
            /// <param name="isLeftAligned">-1 for Left alignment. 0 for center. 1 for right alignment. [Default is Left Alignment].</param>
            void AddColumn(std::string heading, int width, int alignment = -1);

            /// <summary>
            /// Add a row to the table.
            /// </summary>
            void AddRow();

            /// <summary>
            /// Add a std::string value to the current cell in the table and forward the pointer to next cell.
            /// </summary>
            /// <param name="value">New std::string value to be added..</param>
            void AddCellValue(std::string value);

            /// <summary>
            /// Add a std::string value to the current cell in the table and forward the pointer to next cell.
            /// </summary>
            /// <param name="value">New int value to be added..</param>
            void AddCellValue(int value);

            /// <summary>
            /// Convert the table to std::string and return it.
            /// </summary>
            /// <returns>String value representing the table.</returns>
            std::string ToString();

        private:
            int _columnCount;
            std::vector<ColumnHeading*> _headings;
            std::vector<Row*> _rows;

            std::string PrintRow(Row* row);
            static std::string GetAlignedCellValue(std::string actualValue, ColumnHeading* columnHeading);
            std::string GetHeader();
        };
    }
}
