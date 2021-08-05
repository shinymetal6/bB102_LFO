/*
 * vca.c
 *
 *  Created on: Jul 30, 2021
 *      Author: fil
 */

#include "main.h"

void Vca( uint16_t *buffer_out,uint16_t *buffer_in)
{
uint32_t	i;
	for ( i=0;i<HALF_NUMBER_OF_AUDIO_SAMPLES;i++)
	{
		*buffer_out++ = (uint16_t )((float )*buffer_in++ * ((float )LFO_VOLUME_POTCONTROL / 4096.0F));
	}
}
