/*
 * SPI.c
 *
 * Created: 6/18/2021 1:35:05 PM
 *  Author: EslamFayad
 */ 
#include "SPI.h"
#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "DIO_PRIVATE.h"
#include "DIO_INTERFACE.h"

void Spi_MasterInit(void)
{
	/*	configure SPI MOSI Pin as output	*/
	DIO_SetPinDirection(SPI_MOSI_PORT, SPI_MOSI_CHANNEL, OUTPUT);
	/*	configure SPI SS Pin as output	*/
	DIO_SetPinDirection(SPI_SS_PORT, SPI_SS_CHANNEL, OUTPUT);
	/*	configure SPI SCK Pin as output	*/
	DIO_SetPinDirection(SPI_SCK_PORT, SPI_SCK_CHANNEL, OUTPUT);
	/*	configure SPI MISO Pin as input	*/
	DIO_SetPinDirection(SPI_MISO_PORT, SPI_MISO_CHANNEL, INPUT);
	/*	initialize SPI SS pin with HIGH (No slave selected) */
	DIO_SetPinValue(SPI_SS_PORT, SPI_SS_CHANNEL, HIGH);
	/*	enable SPI Module	*/
	SET_BIT(SPI_SPCR_REG,SPI_SPE_BIT_NO);
	/*	enable SPI Module in Master mode	*/
	SET_BIT(SPI_SPCR_REG,SPI_MSTR_BIT_NO);
	/*	set SCK frequency by F_CPU/16	*/
	SPI_SPCR_REG|=SPI_SCK_FREQ_FCPU_DIV_16;
}

void Spi_SlaveInit(void)
{
	/*	configure SPI MOSI Pin as input	*/
	DIO_SetPinDirection(SPI_MOSI_PORT, SPI_MOSI_CHANNEL, INPUT);
	/*	configure SPI SS Pin as input	*/
	DIO_SetPinDirection(SPI_SS_PORT, SPI_SS_CHANNEL, INPUT);
	/*	configure SPI SCK Pin as input	*/
	DIO_SetPinDirection(SPI_SCK_PORT, SPI_SCK_CHANNEL, INPUT);
	/*	configure SPI MISO Pin as output	*/
	DIO_SetPinDirection(SPI_MISO_PORT, SPI_MISO_CHANNEL, OUTPUT);
	/*	enable SPI Module	*/
	SET_BIT(SPI_SPCR_REG,SPI_SPE_BIT_NO);
	/*	enable SPI Module in Slave mode	*/
	CLR_BIT(SPI_SPCR_REG,SPI_MSTR_BIT_NO);
}

void Spi_MasterWrite(uint_8 data)
{
	uint_8 loc_flush_byte;
	/*	load SPI data register with a byte to send	*/
	SPI_SPDR_REG = data;
	/*	wait until byte sent	*/
	while(!(GET_BIT(SPI_SPSR_REG,SPI_SPIF_BIT_NO)));
	/*	flush the data register	*/
	loc_flush_byte = SPI_SPDR_REG;
}
uint_8 Spi_MasterRead(void)
{
	uint_8 loc_dummy_byte=0xFF;
	/*	load SPI data register with a byte to send	*/
	SPI_SPDR_REG = loc_dummy_byte;
	/*	wait until byte received	*/
	while(!(GET_BIT(SPI_SPSR_REG,SPI_SPIF_BIT_NO)));
	/*	read the data register	*/
	return SPI_SPDR_REG;
}

uint_8 Spi_MasterTranseve(uint_8 data)
{
	/*	load SPI data register with a byte to send	*/
	SPI_SPDR_REG = data;
	/*	wait until byte sent	*/
	while(!(GET_BIT(SPI_SPSR_REG,SPI_SPIF_BIT_NO)));
	/*	flush the data register	*/
	return SPI_SPDR_REG;
}
uint_8 Spi_SlaveRead(void)
{
	/*	wait until byte received	*/
	while(!(GET_BIT(SPI_SPSR_REG,SPI_SPIF_BIT_NO)));
	/*	read the data register	*/
	return SPI_SPDR_REG;
}

void Spi_SlaveWrite(uint_8 data)
{
	SPI_SPDR_REG = data;
}