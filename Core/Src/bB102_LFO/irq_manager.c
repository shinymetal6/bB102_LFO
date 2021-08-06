/*
 * irq_manager.c
 *
 *  Created on: Jun 29, 2021
 *      Author: fil
 */

#include "main.h"

void get_audio_limits(uint16_t *start,uint16_t *end)
{
	if (( SystemFlags.audio_flags & AUDIO_LFO_HALF_FLAG ) == AUDIO_LFO_HALF_FLAG)
	{
		*start=0;
		*end = HALF_NUMBER_OF_AUDIO_SAMPLES;
	}
	else
	{
		*start=HALF_NUMBER_OF_AUDIO_SAMPLES;
		*end = NUMBER_OF_AUDIO_SAMPLES;
	}
}

void get_envelope_limits(uint16_t *start,uint16_t *end)
{
	if (( SystemFlags.audio_flags & ENVELOPE_LFO_HALF_FLAG ) == ENVELOPE_LFO_HALF_FLAG)
	{
		*start=0;
		*end = HALF_NUMBER_OF_ENVELOPE_SAMPLES;
	}
	else
	{
		*start=HALF_NUMBER_OF_ENVELOPE_SAMPLES;
		*end = ENVELOPE_MAXLEN;
	}
}

void IrqProcessSamples(void)
{
uint16_t	start,end;

	//HAL_GPIO_WritePin(GPIOB, FLAG_Pin, GPIO_PIN_SET);
	get_audio_limits(&start,&end);
	RunLfo(0,HALF_NUMBER_OF_AUDIO_SAMPLES);
	Vca(&signal_out[start],&lfo_buffer[0]);
	UsbMidiCheck();
	//HAL_GPIO_WritePin(GPIOB, FLAG_Pin, GPIO_PIN_RESET);
}


void IrqProcessEnvelope(void)
{
uint16_t	start,end;

	get_envelope_limits(&start,&end);
	RunEnvelope(start,end);
}

void HAL_DAC_ConvHalfCpltCallbackCh1(DAC_HandleTypeDef *hdac)
{
	SystemFlags.audio_flags |= (AUDIO_LFO_HALF_FLAG | AUDIO_LFO_READY_FLAG);
	IrqProcessSamples();
}

void HAL_DAC_ConvCpltCallbackCh1(DAC_HandleTypeDef *hdac)
{
	SystemFlags.audio_flags &= ~AUDIO_LFO_HALF_FLAG;
	SystemFlags.audio_flags |= AUDIO_LFO_READY_FLAG;
	IrqProcessSamples();
}

void HAL_DACEx_ConvHalfCpltCallbackCh2(DAC_HandleTypeDef *hdac)
{
	SystemFlags.audio_flags |= (ENVELOPE_LFO_HALF_FLAG | ENVELOPE_LFO_READY_FLAG);
	SystemFlags.control_flags |= CONTROL_ENVELOPE_FLAG;
	IrqProcessEnvelope();
}

void HAL_DACEx_ConvCpltCallbackCh2(DAC_HandleTypeDef *hdac)
{
	SystemFlags.audio_flags &= ~ENVELOPE_LFO_HALF_FLAG;
	SystemFlags.audio_flags |= ENVELOPE_LFO_READY_FLAG;
	SystemFlags.control_flags |= CONTROL_ENVELOPE_FLAG;
	IrqProcessEnvelope();
}

void SysTimer_callback(void)
{
	SystemFlags.control_flags |= CONTROL_TICK_FLAG;
}

void ADC_callback(void)
{
	SystemFlags.control_flags |= CONTROL_ADC_FLAG;
}

void Envelope_callback(void)
{
	SystemFlags.control_flags |= CONTROL_ENVELOPE_FLAG;
	HAL_GPIO_TogglePin(GPIOB, FLAG_Pin);
}
