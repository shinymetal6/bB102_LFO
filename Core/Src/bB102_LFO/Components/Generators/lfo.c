/*
 * oscillators.c
 *
 *  Created on: Dec 26, 2020
 *      Author: fil
 */


#include "main.h"
#include "math.h"

__attribute__ ((aligned (16))) LfoTypeDef	Lfo[NUMLFOS];

void DisableLfo(uint16_t channel, uint16_t midi_note , uint8_t velocity)
{
uint8_t	lfo_number;
	for(lfo_number=0;lfo_number<NUMLFOS;lfo_number++)
	{
		if (( Lfo[lfo_number].midi_note == midi_note ) && ( Lfo[lfo_number].state == OSC_ON ))
		{
			Lfo[lfo_number].state = OSC_GO_OFF;
		}
	}
}

void DisableAllLfo(void)
{
uint8_t	lfo_number;
	for(lfo_number=0;lfo_number<NUMLFOS;lfo_number++)
	{
		Lfo[lfo_number].state = OSC_GO_OFF;
	}
}

void SetDetune(uint16_t lfo_number)
{
float	delta_phase;
float	freq;
	freq = midi_freq[Lfo[lfo_number].midi_note] + Lfo[lfo_number].detune;
	delta_phase = (float )WAVETABLE_SIZE / ((float )SystemParameters.audio_sampling_frequency / freq);
	Lfo[lfo_number].delta_phase = (uint16_t )(delta_phase * (float )INT_PRECISION);
}

void EnableLfo(uint16_t channel, uint16_t midi_note , uint8_t velocity)
{
float	delta_phase;
float	freq;
uint32_t	lfo_number,i;

	lfo_number = 0;
	freq = midi_freq[midi_note] + Lfo[lfo_number].detune;
	delta_phase = (float )WAVETABLE_SIZE / ((float )SystemParameters.audio_sampling_frequency / freq);

	for(i=0 ; i< NUMLFOS; i++)
	{
		Lfo[i].delta_phase = (uint16_t )(delta_phase * (float )INT_PRECISION);
		Lfo[i].current_phase = 0;
		Lfo[i].midi_note = midi_note;
		Lfo[i].current_volume = (velocity << 5) | 0x1f;
		Lfo[i].state = OSC_ON;
		Lfo[i].oscillator_age = 0;
		Lfo[i].adsr_state = OSC_A_STATE;
		switch(SystemFlags.lfo_waves[i])
		{
		case	TRIANGLE : Lfo[i].waveform = TRIANGLE; break;
		case	SQUARE : Lfo[i].waveform = SQUARE; break;
		case	SINE : Lfo[i].waveform = SINE; break;
		default : Lfo[i].waveform = SINE; break;
		}
	}
}

void InitLfos(void)
{
float	delta_phase;
float	freq;
uint16_t	lfo_number;

	for(lfo_number=0;lfo_number<NUMLFOS;lfo_number++)
	{
		Lfo[lfo_number].current_phase = 0.0f;
		Lfo[lfo_number].detune = 0.0f;
		Lfo[lfo_number].state = OSC_OFF;
		Lfo[lfo_number].waveform = SINE;
		Lfo[lfo_number].midi_note = INVALID_MIDI_NOTE;
		Lfo[lfo_number].duty = 127;
		Lfo[lfo_number].volume = 1.0F;
		freq = midi_freq[69] + Lfo[lfo_number].detune;
		delta_phase = (float )WAVETABLE_SIZE / ((float )SystemParameters.audio_sampling_frequency / freq);
		Lfo[lfo_number].delta_phase = (uint16_t )(delta_phase * (float )INT_PRECISION);
	}
	InitLfosTables();
}
