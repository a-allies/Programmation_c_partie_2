/*!
* \file line_ref.h
* \brief Declaration of pre-coded functions and data for the exam.
* \author kdesnos
*/

#include "line.h"

#ifndef LINE_REF_H
#define LINE_REF_H

/**
 * \brief Create a new Station.
 *
 * Create and initialize a Station by:
 * - Allocating it in memory.
 * - Allocating the needed string an copying the given name.
 * - Setting next and previous Stations to NULL pointers.
 * - Set all connections to NULL pointers.
 *
 * \param[in] name The name given to the created Station.
 * \return a pointer to the created Station, a NULL pointer in case of problem.
 */
Station * createStation(const char *name);

/// See initLine()
void initLine_ref(Line *l, const char *lineName, const char *color, const char *headName);

/// See moveCurrent()
int moveCurrent_ref(Line *l, Direction dir);

/// See addStation()
void addStation_ref(Line *l, char *name);

/// See getStation()
Station *getStation_ref(Line *l, char *name);

/// See addConnection
int addConnection_ref(Station *s, Line *l);

/// See createConnections()
int createConnections_ref(Line *l0, Line *l1);

/// See createAllConnections()
int createAllConnections_ref(Line *lines[], int nbLines);

/// See genericPrint()
void genericPrint_ref(FILE* file, const char* header, const char* footer,
                  void (*printLine)(FILE*,Line*), void (*printStation)(FILE*,Line*,Station*),
                  Line *lines[], int nbLines);


/**
 * \brief Print info of a Line in the terminal.
 *
 * The line should be printed as follows in the terminal:
 * <code>
 *  <Line.name>
 *  O - <Station.name> : [Connection 0, ...]
 *  |
 *  O - <Station.name> : [Connection 0, ...]
 *  |
 *  ...
 *  |
 *  O - <Station.name> : [Connection 0, ...]
 * </code>
 *
 * For example, a Line called "Ligne b" with three Stations can produce the
 * following output:
 * <code>
 *  Ligne b
 *  O - Gares : Ligne a, C1
 *  |
 *  O - SaintGermain : C4
 *  |
 *  O - SaintAnne : Ligne a, 51
 * </code>
 *
 * \param[in] l the printed Line.
 */
void printLine(Line *l);

/**
 * \brief Function printing Line info in the file.
 *
 * \param[in,out] file Where the Line info is printed.
 * \param[in] line Line whose info is printed.
 */
void printLineConsole(FILE* file, Line* line);

/**
 * \brief Function printing Station info in the file.
 *
 * \param[int,out] file Where the Station info is printed.
 * \param[in] line Parent Line of the Station whose info is printed.
 * \param[in] station Station whose info is printed.
 */
void printStationConsole(FILE* file, Line* line, Station* station);
/**
 * \brief Function printing Line info in the file using a DOT format.
 *
 * \param[int,out] file Where the Line info is printed.
 * \param[in] line Line whose info is printed.
 */
void printLineDot(FILE* file, Line* line);

/**
 * \brief Function printing Station info in the file using a DOT format.
 *
 * \param[int,out] file Where the Station info is printed.
 * \param[in] line Parent Line of the Station whose info is printed.
 * \param[in] station Station whose info is printed.
 */
void printStationDot(FILE* file, Line* line, Station* station);

/// Header string for DOT files.
extern const char* dotHeader;

/// Footer string for DOT files.
extern const char* dotFooter;

#endif