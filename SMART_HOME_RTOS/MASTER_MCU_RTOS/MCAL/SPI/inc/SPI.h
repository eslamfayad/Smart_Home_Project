/*
 * SPI.h
 *
 * Created: 6/18/2021 1:35:35 PM
 *  Author: EslamFayad
 */ 


#ifndef SPI_H_
#define SPI_H_
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "SPI_PRIVATE.h"

#include "DIO_INTERFACE.h"

#define SPI_SS_PORT       	(DIO_PORTB)
#define SPI_SS_CHANNEL		(PIN4)
#define SPI_MOSI_PORT       (DIO_PORTB)
#define SPI_MOSI_CHANNEL	(PIN5)
#define SPI_MISO_PORT       (DIO_PORTB)
#define SPI_MISO_CHANNEL	(PIN6)
#define SPI_SCK_PORT       	(DIO_PORTB)
#define SPI_SCK_CHANNEL		(PIN7)

#define SPI_SCK_FREQ_FCPU_DIV_4			(0<<0)
#define SPI_SCK_FREQ_FCPU_DIV_16		(1<<0)
#define SPI_SCK_FREQ_FCPU_DIV_64		(2<<0)
#define SPI_SCK_FREQ_FCPU_DIV_128		(3<<0)

void Spi_MasterInit(void);
void Spi_SlaveInit(void);
void Spi_MasterWrite(uint_8 data);
uint_8 Spi_MasterRead(void);
uint_8 Spi_MasterTranseve(uint_8 data);
uint_8 Spi_SlaveRead(void);
void Spi_SlaveWrite(uint_8 data);


#endif /* SPI_H_ */