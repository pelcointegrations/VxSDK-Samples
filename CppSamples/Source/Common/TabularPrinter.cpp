#include "stdafx.h"
#include "TabularPrinter.h"

using namespace std;
using namespace CppSamples::Common;

/// <summary>
/// Create an instance of Paging class.
/// </summary>
TabularPrinter::TabularPrinter() {
    _columnCount = 0;

    vector<string> vv;
}

/// <summary>
/// Add a column to the table.
/// </summary>
/// <param name="heading">Heading of the column.</param>
/// <param name="width">Width of the column.</param>
/// <param name="isLeftAligned">-1 for Left alignment. 0 for center. 1 for right alignment. [Default is Left Alignment].</param>
void TabularPrinter::AddColumn(string heading, int width, int alignment) {
    _columnCount++;
    ColumnHeading* columnHeading = new ColumnHeading();
    columnHeading->Value = heading;
    columnHeading->Width = width;
    columnHeading->Alignment = alignment;
    _headings.push_back(columnHeading);
}

/// <summary>
/// Add a row to the table.
/// </summary>
void TabularPrinter::AddRow() {
    _rows.push_back(new Row());
}

/// <summary>
/// Add a string value to the current cell in the table and forward the pointer to next cell.
/// </summary>
/// <param name="value">New string value to be added..</param>
void TabularPrinter::AddCellValue(string value) {
    Row *currentRow = _rows.back();

    if ((int)currentRow->Values.size() < _columnCount)
        currentRow->Values.push_back(value);
}

/// <summary>
/// Add a string value to the current cell in the table and forward the pointer to next cell.
/// </summary>
/// <param name="value">New int value to be added..</param>
void TabularPrinter::AddCellValue(int value) {
    AddCellValue(to_string(value));
}

/// <summary>
/// Convert the table to string and return it.
/// </summary>
/// <returns>String value representing the table.</returns>
string TabularPrinter::ToString() {

    string tableValue = GetHeader();
    string line = string(tableValue.size(), '-');
    tableValue = line + "\n" + tableValue + "\n" + line + "\n";

    int rowCount = _rows.size();
    for (int i = 0; i < rowCount; i++)
        tableValue += PrintRow(_rows[i]) + "\n";
    tableValue += line + "\n";
    return tableValue;
}

string TabularPrinter::PrintRow(Row* row) {

    string rowValue = "";
    int colCount = row->Values.size();
    for (int i = 0; i < colCount; i++)
        rowValue += GetAlignedCellValue(row->Values[i], _headings[i]);
    return rowValue;
}

string TabularPrinter::GetAlignedCellValue(string actualValue, ColumnHeading* columnHeading) {

    string alignedCellValue = "";
    int colWidth = columnHeading->Width;
    int currentWidth = actualValue.size();
    if (currentWidth > colWidth)
        alignedCellValue = actualValue.substr(0, colWidth);
    else {
        int spacing = colWidth - currentWidth;
        int alignment = columnHeading->Alignment;
        if (alignment == -1)
            alignedCellValue = actualValue + string(spacing, ' ');
        else if (alignment == 1)
            alignedCellValue = string(spacing, ' ') + actualValue;
        else {
            int left = spacing / 2;
            int right = spacing - left;
            alignedCellValue = string(left, ' ') + actualValue + string(right, ' ');
        }
    }
    return alignedCellValue;
}

string TabularPrinter::GetHeader() {
    string rowValue = "";
    int colCount = _headings.size();
    for (int i = 0; i < colCount; i++)
        rowValue += GetAlignedCellValue(_headings[i]->Value, _headings[i]);
    return rowValue;
}
