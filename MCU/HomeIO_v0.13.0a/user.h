/******************************************************************************/
/* User Level #define Macros                                                  */
/******************************************************************************/

/* TODO Application specific user parameters used in user.c may go here */

/******************************************************************************/
/* User Function Prototypes                                                   */
/******************************************************************************/

/* TODO User level functions prototypes (i.e. InitApp) go here */

//PUBLIC
void InitApp(void);             /* I/O and Peripheral Initialization        */

//PRIVAT
void InitPort(void);            /* I/O Port Initialization                  */
void InitTimer2(void);          /* Timer 2 Initialization                   */
void InitInterupt(void);        /* Interupt Initialization                  */
void InitUART1(char UART_MODE);
void InitUART2(char UART_MODE);;
void InitOneWire(void);