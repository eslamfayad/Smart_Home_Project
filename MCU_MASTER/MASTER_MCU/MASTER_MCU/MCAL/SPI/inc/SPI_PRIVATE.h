/*
 * SPI_PRIVATE.h
 *
 * Created: 6/18/2021 1:35:23 PM
 *  Author: EslamFayad
 */ 


#ifndef SPI_PRIVATE_H_
#define SPI_PRIVATE_H_
#include "STD_TYPES.h"

#define		SPI_SPCR_REG 				*((volatile uint_8*)0x2D)
#define		SPI_SPSR_REG				*((volatile uint_8*)0x2E)
#define		SPI_SPDR_REG				*((volatile uint_8*)0x2F)

#define SPI_SPE_BIT_NO           	(6)
#define SPI_MSTR_BIT_NO				(4)
#define SPI_SPIF_BIT_NO				(7)


#endif /* SPI_PRIVATE_H_ */