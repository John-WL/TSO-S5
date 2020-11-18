// serviceUsineCAN.h

// creator: Samuel Duclos
// date: 2020-11-16

typedef enum {
    OFF,
    ON,
    WAIT,
    TEST,
    ERROR0,
    ERROR1,
    ERROR2,
    ERROR3
} mode; 

typedef enum {
    NOTHING,
    BLACK,
    ORANGE,
    OTHER
} color; 

typedef enum {
    A,
    B,
    C,
    D
} position; 

typedef enum {
    GRAMS,
    OZ
} unit; 

typedef struct {
    unsigned int mode : 3,
    color : 2, position : 2,
    unit : 1, weight : 8;
} standard; 

 