/*
 * envelope.c
 *
 *  Created on: Aug 5, 2021
 *      Author: fil
 */

#include "main.h"


__attribute__ ((aligned (4)))	uint16_t	envelope_buffer[ENVELOPE_MAXLEN];
__attribute__ ((aligned (4)))	uint16_t	envelope_out[ENVELOPE_MAXLEN];

void InitEnvelope(void)
{
	uint32_t	i;
	for(i=0;i<ENVELOPE_MAXLEN;i++)
		envelope_buffer[i] = i * 10;
}

void RunEnvelope(uint16_t start , uint16_t end)
{
uint32_t	i;
uint16_t	*buffer_out = &envelope_out[start];
uint16_t	*buffer_in  = &envelope_buffer[start];

	for ( i=0;i<HALF_NUMBER_OF_AUDIO_SAMPLES;i++)
		*buffer_out++ = (uint16_t )((float )*buffer_in++ * ((float )ENV_AMPLITUDE_POTCONTROL / 4096.0F));
}
