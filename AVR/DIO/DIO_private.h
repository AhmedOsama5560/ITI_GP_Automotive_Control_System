#ifndef DIO_PRIVATE_H_
#define DIO_PRIVATE_H_

#define		IO_REGISTER(Addr)		((volatile uint8*)(Addr))


/* Port A IO Registers */
#define		PORT_A_DIR_REG			IO_REGISTER(0x3A)
#define		PORT_A_OUT_REG			IO_REGISTER(0x3B)
#define		PORT_A_IN_REG			IO_REGISTER(0x39)

/* Port B IO Registers */
#define		PORT_B_DIR_REG			IO_REGISTER(0x37)
#define		PORT_B_OUT_REG			IO_REGISTER(0x38)
#define		PORT_B_IN_REG			IO_REGISTER(0x36)

/* Port C IO Registers */
#define		PORT_C_DIR_REG			IO_REGISTER(0x34)
#define		PORT_C_OUT_REG			IO_REGISTER(0x35)
#define		PORT_C_IN_REG			IO_REGISTER(0x33)

/* Port D IO Registers */
#define		PORT_D_DIR_REG			IO_REGISTER(0x31)
#define		PORT_D_OUT_REG			IO_REGISTER(0x32)
#define		PORT_D_IN_REG			IO_REGISTER(0x30)

#endif /* DIO_PRIVATE_H_ */
