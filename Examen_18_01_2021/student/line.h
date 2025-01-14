/*!
* \file line.h
* \brief Declaration of structures and functions for manipulating the metro and bus lines.
* \author kdesnos
*/

#ifndef LINE_H
#define LINE_H

#define MAX_NB_CONNECTIONS 5

/**
 * \brief Structure representing a station of a metro/bus/tram line.
 */
typedef struct Station {
    char *name;               /*!< Name of the station */
    struct Station *next;     /*!< Next station on the line */
    struct Station *previous; /*!< Previous station on the line */
    struct Line *connections[MAX_NB_CONNECTIONS];  /*!< Connections */
} Station;

/**
 * \brief Structure representing a Line of a network.
 */
typedef struct Line {
    char *name;               /*!< Name of the line */
    char *color;              /*!< Color of the line */
    struct Station *head;     /*!< First Station of the line */
    struct Station *current;  /*!< Current Station of the line */
} Line;

/**
 * \brief Enumeration used to move along a line.
 *
 * A forward movement will move to the next Station on the line, and a backward
 * movement to the previous.
 * A movement to the head will move the current Station to the Line head.
 */
typedef enum Direction {
    FORWARD,
    BACKWARD,
    HEAD
} Direction;

/**
 * \brief Initialize the Line.
 *
 * Initialize the line by:<br>
 * - Allocating the needed string an copying the given line name.<br>
 * - Allocating the needed string an copying the given color to it.<br>
 * - Creating a new Station with the given headName (using the createStation() function from line_ref.o).<br>
 * - Setting the line head to this new Station.<br>
 * - Setting the line current station to the head.
 * <br>
 * This function does not allocate memory for the <b>Line</b> structure itself,
 * but only for some of its attributes.
 * Previous attribute values of the Line pointed by the received pointer are ignored.
 *
 * \param[in,out] l the Line to initialize.
 * \param[in] lineName name of the initialized Line.
 * \param[in] color the color code of the Line.
 * \param[in] headName name of the head Station.
 */
void initLine(Line *l, const char *lineName, const char *color, const char *headName);

/**
 * \brief Move the current Station in the given Direction.
 *
 * See Direction comments for more info.
 *
 * \param[in] l the Line on which we move the current Station.
 * \param[in] dir the Direction to use.
 * \return 1 if the move was successful, -1 otherwise.
 */
int moveCurrent(Line *l, Direction dir);

/**
 * \brief Add a new Station at the end of the Line.
 *
 * This function creates and adds a new Station with the given name at
 * the end of the Line, that is, the opposite end to the head.
 *
 * \param[in] l Line to which the Station is added.
 * \param[in] n name of the new Station.
 */
void addStation(Line *l, char *name);

/**
 * \brief Get a Station with the given name.
 *
 * Return the pointer to the Station with the given name on the Line.
 *
 * \param[in] l the Line within which the Station is searched.
 * \param[in] name the name of the searched Station.
 * \return a pointer to the Station if it is found, a NULL pointer otherwise.
 */
Station *getStation(Line *l, char *name);

/**
 * \brief Add a connection to the given Line at the given Station.
 *
 * Add the given Line in the array of connections of the given Station.
 * This function does not add the reciprocal connection in the
 * corresponding Station of Line l.
 *
 * The function does nothing if the given Line is already in the array of
 * connections of the given Station.
 *
 * \param[in,out] s The Station whose array of connections is updated.
 * \param[in] l the Line added to the array of connections.
 * \return the total number of connections of the Station on success,
 *         0 in case the given station was not added to the array,
 *         whatever the cause of failure is.
 */
int addConnection(Station *s, Line *l);

/**
 * \brief Create all connections between the two lines.
 *
 * This method automatically scans the given lines and fills the connections
 * attribute for the Stations appearing in the two Lines, based on their names.
 * Each connection must have its reciprocal.
 *
 * \param[in,out] l0 the first Line whose connections must be updated.
 * \param[in,out] l1 the second Line whose connections must be updated.
 * \return the number of connection pairs created.
 */
int createConnections(Line *l0, Line *l1);

/**
 * \brief Create all connections between all given lines.
 *
 * This function automatically create all the connections between all lines in
 * the given table.
 *
 * \param[in,out] lines array of pointer to the Lines whose connections are created.
 * \param[in] nbLines number of Lines contained in the lines array.
 * \return the total number of connection pairs created.
 */
int createAllConnections(Line *lines[], int nbLines);

/**
 * \brief Print a customizable text file from a network of lines.
 *
 * The purpose of this function is to print in a file a textual representation of a network of Line.
 * The function will print content in the following order:
 * <ol>
 * <li>Header: <code>header</code> string given as a parameter.</li>
 * <li>Iteratively, for each Line <i>l</i> in <code>lines</code>:</li><ol>
 * <li>Line: call to <code>printLine()</code> for <i>l</i>.</li>
 * <li>Stations: call to <code>printStation()</code> for each Station of Line <i>l</i>.</li>
 * </ol>
 * <li>Footer: <code>footer</code> string given as a parameter.</li>
 * </ol>
 *
 * \param[in,out] file Pointer to the file where text will be generated.
 * \param[in] header String to print as a header in the generated file.
 * \param[in] footer String to print as a footer in the generated file.
 * \param[in] printLine Pointer to the function used for printing Line info.
 * \param[in] printStation Pointer to the function used for printing Station info.
 * \param[in] lines Array of pointer to the Lines to print.
 * \param[in] nbLines Number of Lines contained in the lines array.
 */
void genericPrint(FILE* file, const char* header, const char* footer,
                  void (*printLine)(FILE*,Line*), void (*printStation)(FILE*,Line*,Station*),
                  Line *lines[], int nbLines);

/**
 * \brief Function printing Line info in the file.
 *
 * \param file Where the Line info is printed.
 * \param line Line whose info is printed.
 */
void printLineConsole(FILE* file, Line* line);

/**
 * \brief Function printing Station info in the file.
 *
 * \param file Where the Station info is printed.
 * \param line Parent Line of the Station whose info is printed.
 * \param station Station whose info is printed.
 */
void printStationConsole(FILE* file, Line* line, Station* station);
/**
 * \brief Function printing Line info in the file using a DOT format.
 *
 * \param file Where the Line info is printed.
 * \param line Line whose info is printed.
 */
void printLineDot(FILE* file, Line* line);

/**
 * \brief Function printing Station info in the file using a DOT format.
 *
 * \param file Where the Station info is printed.
 * \param line Parent Line of the Station whose info is printed.
 * \param station Station whose info is printed.
 */
void printStationDot(FILE* file, Line* line, Station* station);

/// Header string for DOT files.
extern const char* dotHeader;

/// Footer string for DOT files.
extern const char* dotFooter;

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
 * \brief Print a dot file of the network of Lines.
 *
 * Template for printing the dot file is given in the exam assignment.
 *
 * \param[in] lines the Lines of the network to print in the dot file.
 * \param[in] nbLines number of Lines in the lines array.
 * \param[in] filePath path to the written file.
 */
void printDot(Line *lines[], int nbLines, char *filePath);

#endif
