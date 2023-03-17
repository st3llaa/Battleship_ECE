// ********************************************************************
// Constants: 
//      ROWS and COLUMNS: The dimensions of the gameboard
//      FLEETSIZE:        The number of different ship types
// ********************************************************************
#define ROWS        6       // Number of rows of the board
#define COLUMNS     8       // Number of columns of the board
#define FLEETSIZE   3       // The maximum number of ships that are
                            // placed on the board


// ********************************************************************
// Structs:
//      Ship:           Stores the information about a ship
//      Coordinate:     Stores (x,y)-coordinates
//      Placement:      Stores information of where to place a ship
// ********************************************************************
typedef struct {
	int length;             // The length of the ship
	char name[20];          // A string with the name of the ship
} Ship;

typedef struct {
    int x;                  // The x-coordinate
    int y;                  // The y-coordinate
} Coordinate;

typedef struct {
    char orientation;       // The orientation of the ship: 'V' or 'H'
    Coordinate coord;       // The coordinate of the bottom-left corner
} Placement;



// ********************************************************************
// This function initializes the array containing the different ships.
//    ships:    Array of type Ship of size FLEETSIZE. The function reads
//              the ships from the file 'ship_info.txt' and places them
//              in this array.
// ********************************************************************
void initialize_ships(Ship ships[]);


// ********************************************************************
// This function provides the placement of one ship by reading it 
// from the file 'ship_placement.txt'. Each time the function is called,
// it reads the next line in the file.
//    placement:    Pointer to struct of type Placement. The function
//                  will put the placement of the ship into the memory
//                  addressed by this pointer.
//    The function returns the index of the ship that is placed (a value
//    between 0 and FLEETSIZE-1), referring to the ships that were
//    initialized by initialize_ships(). A value of -1 significies that 
//    no more ships need to be placed.
// ********************************************************************
int get_placement_one_ship(Placement* placement);


// ********************************************************************
// This function asks the user where to shoot.
//    The function returns the coordinate of the shot. If the x and y
//    values are equal to -1, this signifies the end of the game.
// ********************************************************************
Coordinate ask_shot();


// ********************************************************************
// This function shows the message indicating a shot was successful
//    name:     String with the name of the ship that was hit.
// ********************************************************************
void msg_hit(char* name);


// ********************************************************************
// This function shows the message indicating a shot was not successful
// ********************************************************************
void msg_miss();


// ********************************************************************
// This function shows the message indicating a ship was destroyed
//   message:   String with the message to show. This needs to be 
//              stored in a dynamic arrays as this function will free 
//              the memory. 
// ********************************************************************
void msg_sunk(char* message);


// ********************************************************************
// This function shows the message indicating that the game has ended.
// ********************************************************************
void msg_end();
